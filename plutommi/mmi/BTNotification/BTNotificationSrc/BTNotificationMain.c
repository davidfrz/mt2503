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

/*******************************************************************************
* Filename:
* ---------
*  BTNotificationMain.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   BT Notification Source File
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "mmi_features.h"
#if (defined(__MMI_BT_NOTIFICATION__) || defined (__MMI_BT_NOTI_SRV__))

#include "BTNotificationGprot.h"
#include "BTNotificationProt.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_btnotification_def.h"
#include "GlobalResDef.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalConstants.h"
#include "MenuCuiGprot.h"
#include "wgui_inline_edit.h"
#include "BTNotiSrvGprot.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "Mmi_rp_srv_bt_noti_def.h"
#include "wgui_categories_ems.h"
#include "btmmiscrgprots.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_ems.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_list.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_UCE.h"
#include "Gsm7BitNationalLang.h"
#include "SmsSrvGprot.h"
#include "UcmGprot.h"
#include "CommonScreens.h"
#include "mmi_rp_app_smsbtunifiedmessage_def.h"
#include "SmsBtMapCSrvGprot.h"
#include "BTMMIScrGprots.h"
#include "wgui_categories_list.h"
#include "SmsAppGprot.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_app_phonebook_def.h"
#include "vmopt.h"
#ifdef __MMI_BLE_TIP_SUPPORT__
#include "TipAppGprot.h"
#endif
#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
#include "mmi_rp_app_scr_locker_def.h"
#endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__

#ifndef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__ 

#if 0//def __MMI_BLE_ANCS_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif // __MMI_BLE_ANCS_SUPPORT__

#endif// /*__MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__ */


#if 0//def __MMI_BLE_ANP_SUPPORT__
/* under construction !*/
#endif  //__MMI_BLE_ANP_SUPPORT__

#ifndef __MTK_TARGET__
#define SRV_BT_NOTIFY_TEST_FSM
#define SRV_BT_NOTIFY_TEST_WITHOUT_SPP
#endif

mmi_bt_notification_cntx_struct g_mmi_bt_notification_cntx = {0};
mmi_bt_notification_option_struct g_mmi_bt_notification_option = {0};
mmi_bt_notification_cntx_struct* g_mmi_bt_notification_cntx_p;


#ifdef __MMI_WEARABLE_DEVICE_SETTING__
extern MMI_BOOL mmi_get_time_autosync_status(void);
#endif  //__MMI_WEARABLE_DEVICE_SETTING__


#endif/*defined(__MMI_BT_NOTIFICATION__) || defined (__MMI_BT_NOTI_SRV__)*/

#ifdef __MMI_BT_NOTIFICATION__

#ifdef __MMI_BT_DIALER_SUPPORT__
#include "BtCmSrvGprot.h"
extern    MMI_BOOL srv_bt_cm_is_headset_connected_ex(void);
#endif

#ifndef __MMI_BT_NOTIFICATION_ENHANCE__
static void mmi_bt_notification_main_show_category(void);
#endif

static void mmi_bt_notification_main_show_entry(MMI_ID parent_id);
static void mmi_bt_notification_show_msg_list(MMI_ID parent_id);

static mmi_ret mmi_bt_notification_main_proc (mmi_event_struct *evt);

U32 mmi_bt_notification_get_linked_dev_list_idx(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 linked_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    linked_num = srv_bt_cm_get_linked_dev_list_idx();
#ifdef __MMI_BT_DIALER_SUPPORT__
    if((linked_num == 1) && (srv_bt_cm_is_headset_connected_ex()))
    {//system just connect headset not connect to SP   
    
       linked_num = 0; 
    }
#endif
    
#if 0//def  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
   //need call new API
   linked_num = srv_bt_cm_get_link_num(SRV_BT_CM_LINK_TYPE_DUAL);

    if((linked_num == 1) && (srv_bt_cm_is_headset_connected_ex()))
    {
        //system just connect headset not connect to SP   
        linked_num = 0; 
    }

#endif


    return linked_num;
}

const srv_bt_cm_dev_struct* mmi_bt_notification_get_linked_dev_info(U32 index_order)
{       
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const srv_bt_cm_dev_struct* linked_dev = NULL;
           
#ifdef  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
    srv_bt_cm_bt_addr* bd_addr = NULL; 
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    linked_dev = srv_bt_cm_get_linked_dev_info(index_order);
    
#ifdef  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
    memset(&g_mmi_bt_notification_cntx.linked_dev_info,0,sizeof(srv_bt_cm_dev_struct));
    //bd_addr = srv_bt_noti_get_bt_device_addr(index_order); 
    bd_addr = srv_bt_noti_get_bt_device_addr_by_conn_index(index_order);    
    if(bd_addr)
    {
        g_mmi_bt_notification_cntx.linked_dev_info.bd_addr.lap = bd_addr->lap;
        g_mmi_bt_notification_cntx.linked_dev_info.bd_addr.uap = bd_addr->uap;
        g_mmi_bt_notification_cntx.linked_dev_info.bd_addr.nap = bd_addr->nap;

        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, linked_dev->bd_addr.lap, linked_dev->bd_addr.uap, linked_dev->bd_addr.nap, 50+index_order);
    }
	linked_dev = &g_mmi_bt_notification_cntx.linked_dev_info;
#endif
    return linked_dev;
}


void mmi_bt_notification__get_dev_ucs2_name(const srv_bt_cm_bt_addr* dev_addr, U32 max_name_len, WCHAR* name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_bt_cm_get_dev_ucs2_name(dev_addr, max_name_len, name_p);

    return;
}

MMI_BOOL mmi_bt_notification_get_read_status(srv_bt_cm_bt_addr *bt_addr, U32 index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_FALSE;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifndef  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
    result = srv_bt_noti_data_get_read_status(bt_addr,index);
#else
    {
        srv_bt_noti_data_msg_node_struct node_ref;

        if(srv_bt_noti_data_listmgr_get_msg_info_ref(index, &node_ref))
        {
            result = srv_bt_noti_data_listmgr_get_read_status(node_ref.noti_id);
        }
    }
#endif

    return result;
}

 MMI_BOOL mmi_bt_notification_set_read_status(srv_bt_cm_bt_addr *bt_addr, U32 index, MMI_BOOL is_read)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     MMI_BOOL  result = MMI_FALSE;  
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
#ifndef  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__     
    result = srv_bt_noti_data_set_read_status(bt_addr,  index, is_read);
#else
    // the index should be noti_id
    result = srv_bt_noti_data_listmgr_set_read_status(index, is_read);
#endif
        
    return result;
}




void mmi_bt_notification_delete_msg(srv_bt_cm_bt_addr *bt_addr, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__ 
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 15);
    srv_bt_noti_data_delete_msg(bt_addr, index);
#else
    {
        srv_bt_noti_data_msg_node_struct node_ref;

    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__    
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 15);            
        srv_bt_noti_data_listmgr_delete_msg(index);
    #else
        if(srv_bt_noti_data_listmgr_get_msg_info_ref(index, &node_ref))
        {        
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 15);            
            srv_bt_noti_data_listmgr_delete_msg(node_ref.noti_id);
        }    
    #endif
    }
#endif

}


U32 mmi_bt_notification_get_msg_num(srv_bt_cm_bt_addr *bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__ 
    msg_num = srv_bt_noti_data_get_msg_num(bt_addr);
#else
    msg_num = srv_bt_noti_data_listmgr_get_msg_num();
#endif

#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    if(msg_num > (SRV_BT_NOTI_MSG_LIST_MAX_NUM * BT_NOTIFY_MAX_CHANNEL))
    {
        msg_num =  SRV_BT_NOTI_MSG_LIST_MAX_NUM * BT_NOTIFY_MAX_CHANNEL;
        MMI_TRACE(MMI_CONN_TRC_G7_BT, 
            TRC_BT_NOTIFICATION_CURRENT_ADDRESS, 
            g_mmi_bt_notification_cntx_p->current_dev, 
            g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, 
            g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, 
            g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 
            3001);
    }
#endif
    
    return msg_num;
}

MMI_BOOL mmi_bt_notification_get_msg_info_ref(srv_bt_cm_bt_addr *bt_addr, 
                                           U32 index, 
                                           srv_bt_noti_data_msg_node_struct *node_ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_FALSE;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifndef  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__     
    result = srv_bt_noti_data_get_msg_info_ref(bt_addr,index, node_ref);
#else    
    result = srv_bt_noti_data_listmgr_get_msg_info_ref(index, node_ref);
#endif
    return result;
}


MMI_BOOL mmi_bt_notification_get_msg_info_ref_by_id(srv_bt_cm_bt_addr *bt_addr, 
                                           U32 noti_id, 
                                           srv_bt_noti_data_msg_node_struct *node_ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_FALSE;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    result = srv_bt_noti_data_listmgr_get_msg_info_ref_by_id(noti_id, node_ref);

    return result;
}

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__

U32 mmi_bt_notification_get_group_num(srv_bt_cm_bt_addr *bt_addr)
{
#ifndef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
    return srv_bt_noti_data_get_group_num(bt_addr);
#else
    return srv_bt_noti_data_listmgr_get_group_num();
#endif
}


MMI_BOOL mmi_bt_notification_get_group_info_ref(srv_bt_cm_bt_addr *bt_addr, 
                                           U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifndef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
    g_mmi_bt_notification_cntx_p->group_list = srv_bt_noti_data_get_group_info_ref(bt_addr, index);
#else
    g_mmi_bt_notification_cntx_p->group_list = srv_bt_noti_data_listmgr_get_group_info_ref(index);
#endif
    
    return MMI_TRUE;
}

MMI_BOOL mmi_bt_notification_get_group_info_ref_by_id(S32 app_id, U8 *group_id, U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
    g_mmi_bt_notification_cntx_p->group_list = srv_bt_noti_data_listmgr_get_group_info_ref_by_id(app_id, group_id, index);
#endif
    
    return MMI_TRUE;
}


MMI_BOOL mmi_bt_notification_get_msg_info_ref_in_group(srv_bt_cm_bt_addr *bt_addr,
                                            S32 cntx_chnl, 
                                            U32 index_in_group, 
                                            srv_bt_noti_data_msg_node_struct *node_ref)
{
    srv_bt_noti_data_get_msg_info_ref_in_group(cntx_chnl, index_in_group, node_ref);
}


srv_bt_noti_data_msg_node_struct* mmi_bt_notification_get_msg_info_in_group(
                                            S32 cntx_chnl, 
                                            U32 index_in_group)
{
    return srv_bt_noti_data_get_msg_info_in_group(cntx_chnl, index_in_group);
}


void mmi_bt_notification_delete_msg_by_group(srv_bt_cm_bt_addr *bt_addr, U32 index)
{   
#ifndef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
    srv_bt_noti_data_delete_msg_by_group(bt_addr, index);
#else
    srv_bt_noti_data_listmgr_delete_msg_by_group(index);
#endif
}


void mmi_bt_notification_action_operate(srv_bt_cm_bt_addr *bt_addr, U32 msg_id, WCHAR *action_id)
{   
#ifndef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
    srv_bt_noti_action_operate(bt_addr, msg_id, action_id);
#else
    srv_bt_noti_data_listmgr_action_operate(msg_id, action_id);
#endif
}

#endif


void mmi_bt_notification_delete_all(srv_bt_cm_bt_addr *bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#ifndef  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__  
    srv_bt_noti_data_delete_all(bt_addr);
#else
    srv_bt_noti_data_listmgr_delete_all();
#endif

    return;
}

MMI_BOOL mmi_bt_notification_block_remote_notification(srv_bt_cm_bt_addr *bt_addr, U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_FALSE;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    result = srv_bt_noti_data_block_remote_notification(bt_addr, app_id);

    return result;
}


MMI_BOOL mmi_bt_notification_check_connection_ext(srv_bt_cm_bt_addr *bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_FALSE;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifndef  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__      
    result = srv_bt_noti_check_connection_ext(bt_addr);
#else
    result = srv_bt_noti_check_connection();
#endif
    return result;
}


MMI_BOOL mmi_bt_notification_check_version(srv_bt_cm_bt_addr *bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_TRUE;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifndef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    result = srv_bt_noti_check_vern(bt_addr);
#endif
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_btnotification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_btnotification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_bt_notification_launch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_bt_notification_launch, KEY_EVENT_UP);
}


static void mmi_bt_notification_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        mmi_bt_notification_delete_msg(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->id);    
    }
    
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_DELETE);
}


static void mmi_bt_notification_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_notification_delete_all(&g_mmi_bt_notification_cntx_p->current_dev_addr);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_DELETE);
}


static void mmi_bt_notification_main_show_empty(WCHAR *device_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_not_ready;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_screen();
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_set_menu_empty_string_by_id(STR_ID_BTNOTIFICATION_NO_NOTIFICATION);
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_cat1032_show(
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        (WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        device_name,
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        0,
        0,
        0,
        (WCHAR*)GetString(STR_GLOBAL_BACK),
        0,
        0,
        NULL,
        NULL,
        NULL,
        0,
        0,   
        0,
        NULL,
        &list_not_ready);
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    
    //remove status icon
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_status_icon_bar_hide_icon(STATUS_ICON_NOTIFICATION);
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
}


#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__

static void mmi_bt_notification_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_group_is_present(GRP_ID_BTNOTIFICATION_APP))
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->current_dev_addr.lap, g_mmi_bt_notification_cntx_p->current_dev_addr.uap, g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 61);
        mmi_bt_dialer_show_popup(GRP_ID_BTNOTIFICATION_APP);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->current_dev_addr.lap, g_mmi_bt_notification_cntx_p->current_dev_addr.uap, g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 62);
        mmi_bt_dialer_show_popup(GRP_ID_BTNOTIFICATION_MAIN);
    }
    
}

#endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__

static void mmi_bt_notification_main_show_disconnect(WCHAR *device_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_not_ready;
    MMI_ID hint_str_id;
    U8 *gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_notification_get_linked_dev_list_idx() == 0)
    {
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        #if defined(__MMI_BT_NOTIFICATION_ENHANCE__) && defined(__MMI_BT_PBAP_CLIENT__)
        hint_str_id = STR_ID_PHB_PBAPC_NOT_CONNECTED;   
        #else
        hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_NEED_USER_CONNECT_WATCH;   
        #endif
        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_NEED_USER_CONNECT;
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    }
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__    
    else if (MMI_FALSE == mmi_bt_notification_check_connection_ext(&g_mmi_bt_notification_cntx_p->current_dev_addr))
    {
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_DISCONNECT_WATCH;
        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_DISCONNECT;
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__;
    }
    else
    {
        hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_VERSION_ERROR;
    }
#else
    else
    {
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_DISCONNECT_WATCH;
        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_DISCONNECT;
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    }
#endif

#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    //remove status icon
    wgui_status_icon_bar_hide_icon(STATUS_ICON_NOTIFICATION);
    
    if (mmi_bt_notification_get_linked_dev_list_idx() == 0)
    {        
        wgui_showcategory6333_screen(NULL,
            (UI_string_type)GetString(STR_GLOBAL_CONNECT),
            (UI_string_type)GetString(STR_GLOBAL_CANCEL),
            (UI_string_type)GetString(hint_str_id),
            NULL);
        SetLeftSoftkeyFunction(mmi_bt_notification_connect, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
    else
    {        
        wgui_showcategory6333_screen(NULL,
            (UI_string_type)GetString(STR_GLOBAL_OK),
            NULL,
            (UI_string_type)GetString(hint_str_id),
            NULL);
        SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
#else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_set_menu_empty_string_by_id(hint_str_id);
    wgui_cat1032_show(
        device_name,
        0,
        0,
        0,
        (WCHAR*)GetString(STR_GLOBAL_BACK),
        0,
        0,
        NULL,
        NULL,
        NULL,
        0,
        0,   
        0,
        gui_buffer,
        &list_not_ready);
    wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
}


static void mmi_bt_notification_refresh_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_display_dummy_screen();
    GoBackHistory();
}


#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__

static WCHAR g_bt_notification_icon_path_cache[SRV_BT_NOTI_MSG_LIST_MAX_NUM * BT_NOTIFY_MAX_CHANNEL][BT_NOTIFY_ICON_FILE_NAME_LENTH];

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_msg_list_get_item_async
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index       [IN]
 *  menu_data
 *  num_item
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_bt_notification_msg_list_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 index;
    
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    U8 group_num;
    srv_bt_noti_data_msg_node_struct* node;
    srv_bt_noti_data_listmgr_node_struct* listmgr_node;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body								                          */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; ++i, ++start_index)
    {
        index = start_index;
        memset(&g_mmi_bt_notification_cntx_p->node, 0, sizeof(srv_bt_noti_data_msg_node_struct));
        
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        if (MMI_BT_NOTIFICATION_GROUP_LIST == g_mmi_bt_notification_cntx_p->list_enum)
        {                        
            mmi_bt_notification_get_group_info_ref(&g_mmi_bt_notification_cntx_p->current_dev_addr, 
                                        index);
            listmgr_node = &(g_mmi_bt_notification_cntx_p->group_list->noti_index[0]);
        }
        else
        {            
            mmi_bt_notification_get_group_info_ref(&g_mmi_bt_notification_cntx_p->current_dev_addr, 
                                        g_mmi_bt_notification_cntx_p->group_index);
            listmgr_node = &(g_mmi_bt_notification_cntx_p->group_list->noti_index[index]);
        }
        node = mmi_bt_notification_get_msg_info_in_group(listmgr_node->chnnl_num, 
                                    listmgr_node->node_index); 
        if (node == NULL)
            return -1;        
        memcpy((CHAR*)&(g_mmi_bt_notification_cntx_p->node), (CHAR*)node, sizeof(srv_bt_noti_data_msg_node_struct));
        
    #else
        mmi_bt_notification_get_msg_info_ref(&g_mmi_bt_notification_cntx_p->current_dev_addr, index, &g_mmi_bt_notification_cntx_p->node);
    #endif
    #if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)
        if (g_mmi_bt_notification_cntx_p->node.header.subtype == srv_bt_notify_subtype_sms)
        {
            menu_data[i].image_list[0] = (PU8)GetImage(IMG_MESSAGE_UNREAD);
            menu_data[i].flag_ext = NULL;
        }
        else
    #endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)
        {        
        #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
            if(g_mmi_bt_notification_cntx_p->node.source != SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
        #endif
            {
            #ifndef __BT_NOTI_SRV_ICON_WITH_BUFFER__
                mmi_ucs2ncpy((CHAR*)g_bt_notification_icon_path_cache[start_index], 
                            (CHAR*)g_mmi_bt_notification_cntx_p->node.icon_file_path, 
                            BT_NOTIFY_ICON_FILE_NAME_LENTH-1);
                menu_data[i].image_list[0] = (PU8)g_bt_notification_icon_path_cache[start_index];
            #ifdef __MMI_WEARABLE_DEVICE_NOTI_UI_ENHANCE__
                menu_data[i].item_icon_flags[0] |= UI_MENUITEM_IMAGE_PATH;
            #endif
            #else
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                menu_data[i].image_list[0] = (PU8)node->icon->icon_buffer;
            #else
                menu_data[i].image_list[0] = (PU8)g_mmi_bt_notification_cntx_p->node.icon->icon_buffer;
            #endif
            #ifdef __MMI_WEARABLE_DEVICE_NOTI_UI_ENHANCE__ 
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                menu_data[i].item_icon_len[0] = node->icon->icon_size;
            #else
                menu_data[i].item_icon_len[0] = g_mmi_bt_notification_cntx_p->node.icon->icon_size; 
            #endif 
                menu_data[i].item_icon_flags[0] |= UI_MENUITEM_IMAGE_MEM;
            #endif
            #endif
            }
        }

    #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
        if(g_mmi_bt_notification_cntx_p->node.source == SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
        {       
            menu_data[i].image_list[0] = (PU8)GetImage(IMG_BTNOTIFICATON_ANCS_ICON);            
        #ifdef __MMI_WEARABLE_DEVICE_NOTI_UI_ENHANCE__
            menu_data[i].item_icon_flags[0] = NULL;   
        #endif
        }

    #endif

    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        if (g_mmi_bt_notification_cntx_p->list_enum == MMI_BT_NOTIFICATION_MSG_LIST)
        {            
    	    mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], (S8*) g_mmi_bt_notification_cntx_p->node.page_content[0].title, BT_NOTIFY_SENDER_LENTH -1);
            if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.page_content[0].content) > 1)
            {
    	        mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.page_content[0].content, BT_NOTIFY_SENDER_LENTH -1);
            }
            else
            {
                if ((g_mmi_bt_notification_cntx_p->node.header.subtype == srv_bt_notify_subtype_sms)
                    &&(mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.page_content[0].content) > 0))
                {                              
                    mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.page_content[0].content, BT_NOTIFY_SENDER_LENTH -1);                
                }
            }

            memset((S8*) menu_data[i].item_list[2], 0x00, 20);
            menu_data[i].image_list[1] = NULL;
        }
        else
        {            
            group_num = g_mmi_bt_notification_cntx_p->group_list->noti_num;

            if (group_num > 1)
            {
                if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.sender) > 0)
                {
                    mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], (S8*) g_mmi_bt_notification_cntx_p->node.sender, BT_NOTIFY_SENDER_LENTH -1);
                }
                else if(mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.page_content[0].title) > 0)
                {
                    mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], (S8*) g_mmi_bt_notification_cntx_p->node.page_content[0].title, BT_NOTIFY_SENDER_LENTH -1);
                }  
                else
                {
                    memset((S8*) menu_data[i].item_list[0], 0x00, BT_NOTIFY_SENDER_LENTH -1);
                }    
            }
            else
            {                
            #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
                if(g_mmi_bt_notification_cntx_p->node.source == SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
                {
                    if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.sender) > 0)
                    {
                        mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], (S8*) g_mmi_bt_notification_cntx_p->node.sender, BT_NOTIFY_SENDER_LENTH -1);
                    }     
                    else if(mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.page_content[0].title) > 0)
                    {
                        mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], (S8*) g_mmi_bt_notification_cntx_p->node.page_content[0].title, BT_NOTIFY_SENDER_LENTH -1);
                    }  
                    else
                    {
                        memset((S8*) menu_data[i].item_list[0], 0x00, BT_NOTIFY_SENDER_LENTH -1);
                    }   
                }
                else
            #endif
                {
                    if(mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.page_content[0].title) > 0)
                    {
                        mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], (S8*) g_mmi_bt_notification_cntx_p->node.page_content[0].title, BT_NOTIFY_SENDER_LENTH -1);
                    }
                    else if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.sender) > 0)
                    {
                        mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], (S8*) g_mmi_bt_notification_cntx_p->node.sender, BT_NOTIFY_SENDER_LENTH -1);
                    }       
                    else
                    {
                        memset((S8*) menu_data[i].item_list[0], 0x00, BT_NOTIFY_SENDER_LENTH -1);
                    }   

                }
            }

        #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
            if(g_mmi_bt_notification_cntx_p->node.source == SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
            {
                if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.page_content[0].title) > 0)
                {
        	        mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.page_content[0].title, BT_NOTIFY_SENDER_LENTH -1);
                }
                else if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.page_content[0].content) > 0)
                {
        	        mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.page_content[0].content, BT_NOTIFY_SENDER_LENTH -1);
                }
                else
                {
                    memset((S8*) menu_data[i].item_list[1], 0x00, BT_NOTIFY_SENDER_LENTH -1);
                }
            }
            else 
        #endif   
            {         
                if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.page_content[0].content) > 0)
                {
        	        mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.page_content[0].content, BT_NOTIFY_SENDER_LENTH -1);
                }
                else
                {
                    memset((S8*) menu_data[i].item_list[1], 0x00, BT_NOTIFY_SENDER_LENTH -1);
                }
            }
            
            // show group notification count
            if (group_num > 1)
            {            
                U8 number_buffer[10] = {0};
                kal_wsprintf((WCHAR*)number_buffer, "%d", group_num);            
                mmi_ucs2ncpy((S8*) menu_data[i].item_list[2], (S8*)number_buffer, 10);
            }
            else
            {
                memset((S8*) menu_data[i].item_list[2], 0x00, 20);
                menu_data[i].image_list[1] = NULL;
            }
        
            //mmi_ucs2cat((S8 *) menu_data[i].item_list[1], (S8 *)L"...");
            if (g_mmi_bt_notification_cntx_p->node.is_blocked)
            {
                // show block image
                menu_data[i].image_list[1] = (PU8)GetImage(IMG_BTNOTIFICATON_BLOCK_ICON);
            #ifdef __MMI_WEARABLE_DEVICE_NOTI_UI_ENHANCE__
                menu_data[i].item_icon_flags[1] = NULL; 
            #endif
            }
            else
            {                
                menu_data[i].image_list[1] = NULL;
                menu_data[i].item_icon_flags[1] = NULL; 
            }
        }
    #else
	    mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], (S8*) g_mmi_bt_notification_cntx_p->node.sender, BT_NOTIFY_SENDER_LENTH -1);
        if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.title) > 1)
        {
	        mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.title, BT_NOTIFY_SENDER_LENTH -1);
        }
        else if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.content) > 1)
        {
	        mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.content, BT_NOTIFY_SENDER_LENTH -1);
        }
        else
        {
            #if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)
            if ((g_mmi_bt_notification_cntx_p->node.header.subtype == srv_bt_notify_subtype_sms)
                &&(mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.content) > 0))
            {                              
                mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.content, BT_NOTIFY_SENDER_LENTH -1);                
            }
            else
            #endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)
            {
	            mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.ticker_text, BT_NOTIFY_SENDER_LENTH -1);
            }
        }
        //mmi_ucs2cat((S8 *) menu_data[i].item_list[1], (S8 *)L"...");
    #endif
    }
    
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_msg_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_show_msg_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    if (g_mmi_bt_notification_cntx_p->list_enum == MMI_BT_NOTIFICATION_GROUP_LIST)
    {
        srv_bt_noti_data_listmgr_node_struct* listmgr_node;
        g_mmi_bt_notification_cntx_p->group_index = index;

        mmi_bt_notification_get_group_info_ref(&g_mmi_bt_notification_cntx_p->current_dev_addr,
                                g_mmi_bt_notification_cntx_p->group_index);
        listmgr_node = &(g_mmi_bt_notification_cntx_p->group_list->noti_index[0]);
        mmi_bt_notification_get_msg_info_ref_in_group(&g_mmi_bt_notification_cntx_p->current_dev_addr, 
                            listmgr_node->chnnl_num,
                            listmgr_node->node_index,
                            &g_mmi_bt_notification_cntx_p->node);        
    }
    else
    {
        g_mmi_bt_notification_cntx_p->id = index;   

    #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__  
        {
            srv_bt_noti_data_msg_node_struct node_ref;
            srv_bt_noti_data_listmgr_node_struct* listmgr_node;

            listmgr_node = &(g_mmi_bt_notification_cntx_p->group_list->noti_index[index]);
            if (mmi_bt_notification_get_msg_info_ref_in_group(&g_mmi_bt_notification_cntx_p->current_dev_addr,
                                            listmgr_node->chnnl_num,
                                            listmgr_node->node_index,
                                            &node_ref))
            {
                g_mmi_bt_notification_cntx_p->noti_id = node_ref.noti_id;
                g_mmi_bt_notification_cntx_p->total_page_account = node_ref.page_num; 
                g_mmi_bt_notification_cntx_p->current_page_id = 0;
            }    
        }
    #endif
    }
#else
    g_mmi_bt_notification_cntx_p->id = index;

#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__  
    {
        srv_bt_noti_data_msg_node_struct node_ref;
        
        if(mmi_bt_notification_get_msg_info_ref(NULL,index, &node_ref))
        {
            g_mmi_bt_notification_cntx_p->noti_id = node_ref.noti_id;
        }    
    }
#endif    
#endif
}


static mmi_ret mmi_bt_notification_show_msg_list_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 0);
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            //clear cache
            memset(&g_bt_notification_icon_path_cache, 0, SRV_BT_NOTI_MSG_LIST_MAX_NUM * BT_NOTIFY_MAX_CHANNEL * BT_NOTIFY_ICON_FILE_NAME_LENTH);
            g_mmi_bt_notification_cntx_p->id = 0;
            break;
        
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        case EVT_ID_GROUP_GOBACK:
            if (g_mmi_bt_notification_cntx_p->list_enum == MMI_BT_NOTIFICATION_MSG_LIST)
            {
                g_mmi_bt_notification_cntx_p->list_enum = MMI_BT_NOTIFICATION_GROUP_LIST;
            }
            break;
    #endif
    
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_msg_list_mark_as_read_confirm_proc
 * DESCRIPTION
 *  mark all as readl confirm proc
 *  Functionality:
 * PARAMETERS
 *  mmi_alert_result_evt_struct [IN]                       
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bt_notification_msg_list_mark_as_read_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *confirm_evt = NULL;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(evt);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 1);
    
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            confirm_evt = (mmi_alert_result_evt_struct*)evt;
            switch (confirm_evt->result)
            {
                case MMI_ALERT_CNFM_OK:
                case MMI_ALERT_CNFM_YES:
                {
                    //srv_bt_noti_data_set_all_as_read(&g_mmi_bt_notification_cntx_p->current_dev_addr);
                    mmi_bt_notification_empty();
                    //remove status icon
                    wgui_status_icon_bar_hide_icon(STATUS_ICON_NOTIFICATION);
                    break;
                }
                default:
                break;
            }
        }
    }

    return  MMI_RET_OK;
}


#if defined(__MMI_TOUCH_SCREEN__)

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__

static void mmi_bt_notification_list_long_tap_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch (index)
    {
        case 0:
        {
            if (MMI_BT_NOTIFICATION_MSG_LIST == g_mmi_bt_notification_cntx_p->list_enum)
            {
                if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
                {
                    mmi_bt_notification_delete_msg(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->noti_id);         
                }
            }
            else 
            {
                // delete group
                mmi_bt_notification_delete_msg_by_group(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->group_index);
            }
        }
            break;

        case 1:
        #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
            if(g_mmi_bt_notification_cntx_p->node.source != SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
        #endif
            {
                if (!g_mmi_bt_notification_cntx_p->node.is_blocked) 
                {
                    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
                    {
                        srv_bt_noti_data_block_remote_notification(&g_mmi_bt_notification_cntx_p->node.bt_addr, g_mmi_bt_notification_cntx_p->node.app_id);        
                    }
                }
            }
            break;

        default:
            break;
    }
    
    mmi_bt_notification_get_group_info_ref_by_id(g_mmi_bt_notification_cntx_p->group_list->app_id,
                                    g_mmi_bt_notification_cntx_p->group_list->group_id,
                                    &index);
    
    if ((MMI_BT_NOTIFICATION_MSG_LIST == g_mmi_bt_notification_cntx_p->list_enum) && 
        (g_mmi_bt_notification_cntx_p->group_list == NULL ||
        g_mmi_bt_notification_cntx_p->group_list->noti_num == 0))
    {
        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MSG_LIST);   
    }
    else
    {
        GoBackHistory();  
    }
}


static void mmi_bt_notification_list_long_tap_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_id str_id;
    WCHAR* pop_str, *str;
   
    U8 *gui_buffer = NULL;    
    U8 *nStr3ItemListstring[3];
    U8 *nStr2ItemListstring[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    nStr3ItemListstring[0] = GetString(STR_ID_BTNOTIFICATION_APPLICATION_OPTION_DELETE);
    nStr3ItemListstring[1] = GetString(STR_ID_BTNOTIFICATION_APPLICATION_OPTION_BLOCK);
    nStr3ItemListstring[2] = GetString(STR_GLOBAL_CANCEL);

    nStr2ItemListstring[0] = GetString(STR_ID_BTNOTIFICATION_APPLICATION_OPTION_DELETE);
    nStr2ItemListstring[1] = GetString(STR_GLOBAL_CANCEL);
    
#ifdef __MMI_WEARABLE_DEVICE_NOTI_UI_ENHANCE__
    set_cat353_no_title(MMI_TRUE);
#endif
    
#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
    if(g_mmi_bt_notification_cntx_p->node.source != SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
    {
        if (g_mmi_bt_notification_cntx_p->node.is_blocked)
        {
            ShowCategory353Screen_ext(
                NULL,
                NULL,                
                (U8*)GetString(STR_GLOBAL_VIEW),
                NULL,
                (U8*)GetString(IMG_GLOBAL_BACK),
                NULL,
                2,
                (U8 **)nStr2ItemListstring,
                NULL,
                NULL,
                LIST_MENU,
                0,
                gui_buffer);
        }
        else
        {
            ShowCategory353Screen_ext(
                NULL,
                NULL,                
                (U8*)GetString(STR_GLOBAL_VIEW),
                NULL,
                (U8*)GetString(IMG_GLOBAL_BACK),
                NULL,
                3,
                (U8 **)nStr3ItemListstring,
                NULL,
                NULL,
                LIST_MENU,
                0,
                gui_buffer);
        }
    }
    else
    {
        ShowCategory353Screen_ext(
            NULL,
            NULL,            
            (U8*)GetString(STR_GLOBAL_VIEW),
            NULL,
            (U8*)GetString(IMG_GLOBAL_BACK),
            NULL,
            2,
            (U8 **)nStr2ItemListstring,
            NULL,
            NULL,
            LIST_MENU,
            0,
            gui_buffer);
    }
#else
    if (g_mmi_bt_notification_cntx_p->node.is_blocked)
    {
        ShowCategory353Screen_ext(
            NULL,
            NULL,
            (U8*)GetString(STR_GLOBAL_VIEW),
            NULL,
            (U8*)GetString(IMG_GLOBAL_BACK),
            NULL,
            2,
            (U8 **)nStr2ItemListstring,
            NULL,
            NULL,
            LIST_MENU,
            0,
            gui_buffer);
    }
    else
    {
        ShowCategory353Screen_ext(
            NULL,
            NULL,
            (U8*)GetString(STR_GLOBAL_VIEW),
            NULL,
            (U8*)GetString(IMG_GLOBAL_BACK),
            NULL,
            3,
            (U8 **)nStr3ItemListstring,
            NULL,
            NULL,
            LIST_MENU,
            0,
            gui_buffer);
    }
#endif
    
    SetLeftSoftkeyFunction(mmi_bt_notification_list_long_tap_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_notification_list_long_tap_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


static mmi_ret mmi_bt_notification_list_long_tap_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 7);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_list_long_tap_show();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_msg_list_long_tap_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_msg_list_long_tap_hdlr(mmi_pen_point_struct pos)
{
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_FORWARD;

        if (g_mmi_bt_notification_cntx_p->list_enum == MMI_BT_NOTIFICATION_GROUP_LIST)
        {
            mmi_frm_group_create_ex(
                            GRP_ID_BTNOTIFICATION_GROUP_LIST,
                            GRP_ID_BTNOTIFICATION_GROUP_LIST_LONG_TAP,
                            mmi_bt_notification_list_long_tap_proc,
                            NULL,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
            
            mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_GROUP_LIST_LONG_TAP, 
                SCR_ID_BTNOTIFICATION_GROUP_LIST_LONG_TAP, 
                mmi_bt_notification_list_long_tap_proc,
                NULL);
        }
        else
        {
            mmi_frm_group_create_ex(
                            GRP_ID_BTNOTIFICATION_MSG_LIST,
                            GRP_ID_BTNOTIFICATION_MSG_LIST_LONG_TAP,
                            mmi_bt_notification_list_long_tap_proc,
                            NULL,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
            
            mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_MSG_LIST_LONG_TAP, 
                SCR_ID_BTNOTIFICATION_MSG_LIST_LONG_TAP, 
                mmi_bt_notification_list_long_tap_proc,
                NULL);
        }
    }
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_property;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_confirm_property_init(&confirm_property, CNFM_TYPE_YESNO);
    confirm_property.callback = (mmi_proc_func)mmi_bt_notification_msg_list_mark_as_read_confirm_proc;
    confirm_property.parent_id  = GRP_ID_BTNOTIFICATION_MSG_LIST;
    //confirm_property.f_auto_question_mark = MMI_TRUE;
    
    g_mmi_bt_notification_cntx_p->set_all_as_read_id = mmi_confirm_display_ext(
                                                            STR_ID_BTNOTIFICATION_MARK_ALL_AS_READ,
                                                            MMI_EVENT_QUERY,
                                                            &confirm_property);
#endif
}

#endif  //defined(__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_delete_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_delete_read(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 total = mmi_bt_notification_get_msg_num(&g_mmi_bt_notification_cntx_p->current_dev_addr);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = total-1; i >= 0; i--)
    {
        if (mmi_bt_notification_get_read_status(&g_mmi_bt_notification_cntx_p->current_dev_addr, i))
        {
            mmi_bt_notification_delete_msg(&g_mmi_bt_notification_cntx_p->current_dev_addr, i);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_main_show_entry_from_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_main_show_entry_from_msg_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__ 
    if (g_mmi_bt_notification_cntx_p->list_enum == MMI_BT_NOTIFICATION_GROUP_LIST)
    {        
        if (g_mmi_bt_notification_cntx_p->group_list->noti_num == 1)
        {                      
            if (!mmi_bt_notification_get_msg_info_ref_in_group(&g_mmi_bt_notification_cntx_p->current_dev_addr, 
                                    g_mmi_bt_notification_cntx_p->group_list->noti_index[0].chnnl_num, 
                                    g_mmi_bt_notification_cntx_p->group_list->noti_index[0].node_index, 
                                    &g_mmi_bt_notification_cntx_p->node))
            {
                return;           
            }
            
            g_mmi_bt_notification_cntx_p->noti_id = g_mmi_bt_notification_cntx_p->node.noti_id;
            memset(&g_mmi_bt_notification_cntx_p->node, 0, sizeof(srv_bt_noti_data_msg_node_struct));
            g_mmi_bt_notification_cntx_p->current_page_id = 0;
            mmi_bt_notification_main_show_entry(GRP_ID_BTNOTIFICATION_GROUP_LIST);
        }
        else
        {
            g_mmi_bt_notification_cntx_p->list_enum = MMI_BT_NOTIFICATION_MSG_LIST;
           
            mmi_bt_notification_show_msg_list(GRP_ID_BTNOTIFICATION_GROUP_LIST);
        }
    }
    else
#endif
    {   
        mmi_bt_notification_main_show_entry(GRP_ID_BTNOTIFICATION_MSG_LIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_show_msg_list(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    //S32 total = 0;
    const srv_bt_cm_dev_struct* dev_p = NULL;
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    WCHAR title[30] = {0};
    #endif
	#ifdef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    WCHAR device_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = L"BT Device";
	#else  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    WCHAR device_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = {0};
	#endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    //S32 cat_err = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, 
        g_mmi_bt_notification_cntx_p->current_dev, 
        g_mmi_bt_notification_cntx_p->current_dev_addr.lap, 
        g_mmi_bt_notification_cntx_p->current_dev_addr.uap, 
        g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 
        0);

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__   
    if (g_mmi_bt_notification_cntx_p->list_enum == MMI_BT_NOTIFICATION_GROUP_LIST)
    {
        mmi_frm_group_create_ex(
            parent_id, 
            GRP_ID_BTNOTIFICATION_GROUP_LIST, 
            mmi_bt_notification_show_msg_list_proc, 
            NULL, 
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        
        mmi_frm_scrn_enter(GRP_ID_BTNOTIFICATION_GROUP_LIST, 
            SCR_ID_BTNOTIFICATION_GROUP_LIST, 
            NULL, 
            mmi_bt_notification_show_msg_list, 
            MMI_FRM_UNKNOW_SCRN);        
    }
    else      
#endif
    {
        mmi_frm_group_create_ex(
            parent_id, 
            GRP_ID_BTNOTIFICATION_MSG_LIST, 
            mmi_bt_notification_show_msg_list_proc, 
            NULL, 
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        
        mmi_frm_scrn_enter(GRP_ID_BTNOTIFICATION_MSG_LIST, 
            SCR_ID_BTNOTIFICATION_MSG_LIST, 
            NULL, 
            mmi_bt_notification_show_msg_list, 
            MMI_FRM_UNKNOW_SCRN);
    }
    
#ifndef SRV_BT_NOTIFY_TEST_WITHOUT_SPP    
    //dev_p = mmi_bt_notification_get_linked_dev_info(g_mmi_bt_notification_cntx_p->current_dev);
    //memcpy((void*)&g_mmi_bt_notification_cntx_p->current_dev_addr, (void*)&dev_p->bd_addr, sizeof(srv_bt_cm_bt_addr));
    
    mmi_bt_notification__get_dev_ucs2_name(
        &(g_mmi_bt_notification_cntx_p->current_dev_addr),
        SRV_BT_CM_BD_UCS2_NAME_LEN,
        device_name);
    
    if (mmi_bt_notification_get_linked_dev_list_idx() == 0)
    {
        mmi_bt_notification_main_show_disconnect((WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME));
        return;
    }
    else if (MMI_FALSE == mmi_bt_notification_check_connection_ext(&g_mmi_bt_notification_cntx_p->current_dev_addr))
    {
        mmi_bt_notification_main_show_disconnect(device_name);  
        return;
    }
    else if (MMI_FALSE == mmi_bt_notification_check_version(&g_mmi_bt_notification_cntx_p->current_dev_addr))
    {
        mmi_bt_notification_main_show_disconnect((WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME));
        return;
    }
    
#endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP

#ifndef __MMI_BT_NOTIFICATION_ENHANCE__
    mmi_bt_notification_delete_read();
#endif /* __MMI_BT_NOTIFICATION_ENHANCE__ */

    g_mmi_bt_notification_cntx_p->total = mmi_bt_notification_get_msg_num(&g_mmi_bt_notification_cntx_p->current_dev_addr);
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    g_mmi_bt_notification_cntx_p->group_total_num = mmi_bt_notification_get_group_num(&g_mmi_bt_notification_cntx_p->current_dev_addr);
#endif
    
    if (g_mmi_bt_notification_cntx_p->total == 0
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        || g_mmi_bt_notification_cntx_p->group_total_num == 0
    #endif
        )
    {
        mmi_bt_notification_main_show_empty(device_name);
    }
    else
    {
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        if (g_mmi_bt_notification_cntx_p->list_enum == MMI_BT_NOTIFICATION_GROUP_LIST)
        {
            guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BTNOTIFICATION_GROUP_LIST, SCR_ID_BTNOTIFICATION_GROUP_LIST);
        }
        else 
    #endif
        {
            guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BTNOTIFICATION_MSG_LIST, SCR_ID_BTNOTIFICATION_MSG_LIST);
        }
    
        if (guiBuffer != NULL)
        {
            list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;
            g_mmi_bt_notification_cntx_p->id = hist->highlighted_item;

            #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
            if(g_mmi_bt_notification_cntx_p->id >= g_mmi_bt_notification_cntx_p->total)
            {
                g_mmi_bt_notification_cntx_p->id = 0;
            }
            #endif            
        }

        /* register highligh handler */
        RegisterHighlightHandler(mmi_bt_notification_show_msg_list_highlight_hdlr);
        
        wgui_cat_set_list_menu_empty_lable((UI_string_type)get_string(STR_GLOBAL_EMPTY));

    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    #ifdef __MMI_WEARABLE_DEVICE_NOTI_UI_ENHANCE__
        swatch_set_twoline_list_type(WGUI_SWATCH_TWOLINE_LIST_TYPE2);
    #endif
        if (g_mmi_bt_notification_cntx_p->list_enum == MMI_BT_NOTIFICATION_MSG_LIST)
        {
            mmi_bt_notification_get_group_info_ref(&g_mmi_bt_notification_cntx_p->current_dev_addr, 
                                        g_mmi_bt_notification_cntx_p->group_index);            
            mmi_ucs2cpy((CHAR*)title, (const CHAR*)g_mmi_bt_notification_cntx_p->group_list->sender);
            g_mmi_bt_notification_cntx_p->total = g_mmi_bt_notification_cntx_p->group_list->noti_num;

            if (!mmi_bt_notification_get_msg_info_ref_in_group(&g_mmi_bt_notification_cntx_p->current_dev_addr, 
                                    g_mmi_bt_notification_cntx_p->group_list->noti_index[0].chnnl_num, 
                                    g_mmi_bt_notification_cntx_p->group_list->noti_index[0].node_index, 
                                    &g_mmi_bt_notification_cntx_p->node))
            {
                return;           
            }
            
            g_mmi_bt_notification_cntx_p->noti_id = g_mmi_bt_notification_cntx_p->node.noti_id;
            if (g_mmi_bt_notification_cntx_p->node.is_blocked)
            {
                mmi_ucs2cat((CHAR*)title, (const CHAR*)GetString(STR_ID_BTNOTIFICATION_LIST_BLOCKED));
            }
            
            wgui_swatch_two_line_menu_list_screen(
                 (U8*)title,
                 NULL,
                 STR_GLOBAL_VIEW,
                 IMG_BTNOTIFICATON_LIST_ICON,
                 STR_GLOBAL_BACK,
                 g_mmi_bt_notification_cntx_p->total,
                 mmi_bt_notification_msg_list_get_item_async,
                 g_mmi_bt_notification_cntx_p->id,
                 guiBuffer);
        }
        else  
        {            
            wgui_swatch_two_line_menu_list_screen(
                 (PU8)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
                 NULL,
                 STR_GLOBAL_VIEW,
                 IMG_BTNOTIFICATON_LIST_ICON,
                 STR_GLOBAL_BACK,
                 g_mmi_bt_notification_cntx_p->group_total_num,
                 mmi_bt_notification_msg_list_get_item_async,
                 g_mmi_bt_notification_cntx_p->group_index,
                 guiBuffer);            
        }
    #else  
        wgui_swatch_two_line_menu_list_screen(
             (PU8)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
             NULL,
             STR_GLOBAL_VIEW,
             IMG_BTNOTIFICATON_LIST_ICON,
             STR_GLOBAL_BACK,
             g_mmi_bt_notification_cntx_p->total,
             mmi_bt_notification_msg_list_get_item_async,
             g_mmi_bt_notification_cntx_p->id,
             guiBuffer);
    #endif
    
        /* register LSK, RSK hanlders */
        SetLeftSoftkeyFunction(mmi_bt_notification_main_show_entry_from_msg_list, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_notification_main_show_entry_from_msg_list, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        #if defined(__MMI_TOUCH_SCREEN__)
        SetLeftSoftkeyFunction(mmi_bt_notification_msg_list_long_tap_hdlr, KEY_EVENT_LONG_PRESS);
        #endif  //defined(__MMI_TOUCH_SCREEN__)
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_msg_list_from_dev_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_show_msg_list_from_dev_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_notification_show_msg_list(GRP_ID_BTNOTIFICATION_APP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_mre_install_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_mre_install_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
#ifdef __MMI_BT_NOTIFICATION_WRISTBAND_FOR_ONLY_INSTALL_POPUP__

    ShowCategory165Screen(
          0,
          0,
          0,
          0, 
          (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL_SHORT),
          IMG_GLOBAL_LOADING,
          gui_buffer);

#else
    
    ShowCategory165Screen(
        0,
        0,
        0,
        0, 
        (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL),
        IMG_GLOBAL_LOADING,
        gui_buffer);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_mre_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_bt_notification_mre_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 2);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:

            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_NOTIFY);
            #endif
            
            mmi_bt_notification_mre_install_show();
            break;

        case EVT_ID_SCRN_INACTIVE:            
            
            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_NOTIFY);
            #endif
                        
            break;

        case EVT_ID_SCRN_DEINIT:
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_mre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scen_id
 *  arg
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_bt_notification_mre_entry(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_BTNOTIFICATION_MRE,
        mmi_bt_notification_mre_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_MRE, 
        SCR_ID_BTNOTIFICATION_MRE, 
        mmi_bt_notification_mre_proc,
        NULL);

    return MMI_TRUE;
}

#endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_dev_list_get_item_async
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index       [IN]
 *  menu_data
 *  num_item
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_bt_notification_dev_list_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body								                          */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; ++i, ++start_index)
    {
        const srv_bt_cm_dev_struct* dev_p = mmi_bt_notification_get_linked_dev_info(i);
        if (dev_p != NULL)
        {
            mmi_bt_notification__get_dev_ucs2_name(
                &(dev_p->bd_addr),
                SRV_BT_CM_BD_UCS2_NAME_LEN,
                menu_data[i].item_list[0]);
            
            //menu_data[i].image_list[0] = (PU8)mmi_bt_get_device_image(dev_p->cod);
        }
        else
        {
            kal_wsprintf((WCHAR*)menu_data[i].item_list[0], "BT Device %d", i+1);
            //menu_data[i].image_list[0] = (PU8)mmi_bt_get_device_image(NULL);
        }
    }
    
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_dev_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_show_dev_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_notification_cntx_p->current_dev = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_main_show_entry_from_dev_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_main_show_entry_from_dev_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_notification_main_show_entry(GRP_ID_BTNOTIFICATION_APP);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_dev_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_show_dev_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    #ifdef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    S32 total = 2;
    #else  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    S32 total = mmi_bt_notification_get_linked_dev_list_idx();
    #endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    S32 cat_err = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    #ifndef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    if (mmi_bt_notification_get_linked_dev_list_idx() == 0)
    {
        mmi_bt_notification_main_show_disconnect((WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME));
        return;
    }
    else if (mmi_bt_notification_get_linked_dev_list_idx() == 1)
    {
        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_APP);
        return;
    }
    #endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BTNOTIFICATION_APP, SCR_ID_BTNOTIFICATION_DEV_LIST);

    if (guiBuffer != NULL)
    {
        list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;
        g_mmi_bt_notification_cntx_p->current_dev = hist->highlighted_item;
    }
    
    /* register highligh handler */
    RegisterHighlightHandler(mmi_bt_notification_show_dev_list_highlight_hdlr);
    

    #ifdef __MMI_BT_DIALER_SUPPORT__
    wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
    #endif
    
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NO_ICON);
    
    wgui_cat1032_show(
        get_string(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
        NULL,
        get_string(STR_GLOBAL_OK),
        get_image(IMG_GLOBAL_OK),
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        total,
        mmi_bt_notification_dev_list_get_item_async,
        NULL,
        g_mmi_bt_notification_cntx_p->current_dev,
        NULL,    
        NULL, /* to calculate the coordinate offset of string */
        NULL,
        guiBuffer,
        &cat_err);

    wgui_restore_list_menu_slim_style();

    if (total > 0)
    {
        /* register LSK, RSK hanlders */
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        SetLeftSoftkeyFunction(mmi_bt_notification_show_msg_list_from_dev_list, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_notification_show_msg_list_from_dev_list, KEY_EVENT_UP);
        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        SetLeftSoftkeyFunction(mmi_bt_notification_main_show_entry_from_dev_list, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_notification_main_show_entry_from_dev_list, KEY_EVENT_UP);
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);  
}


static mmi_ret mmi_bt_notification_launch_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 3);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_show_dev_list();
            break;

        case EVT_ID_SCRN_GOBACK:
            break;

        case EVT_ID_GROUP_DEINIT:
            g_mmi_bt_notification_cntx_p->current_dev = 0;
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void mmi_bt_notification_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    srv_bt_noti_data_listmgr_set_all_as_read();

    //remove status icon
    wgui_status_icon_bar_hide_icon(STATUS_ICON_NOTIFICATION);
#endif
    
    if (g_mmi_bt_notification_cntx_p->launch_from_popup)
    {
        U8 i = 0;
        U32 device_num = mmi_bt_notification_get_linked_dev_list_idx();
        const srv_bt_cm_dev_struct* dev_p = NULL;

        //correct the index, cause the bt addr is form event in popup
        for (i = 0; i < device_num; i++)
        {
            dev_p = mmi_bt_notification_get_linked_dev_info(i);
            if (g_mmi_bt_notification_cntx_p->popup_dev_addr.lap == dev_p->bd_addr.lap &&
                g_mmi_bt_notification_cntx_p->popup_dev_addr.uap == dev_p->bd_addr.uap &&
                g_mmi_bt_notification_cntx_p->popup_dev_addr.nap == dev_p->bd_addr.nap)
            {
                g_mmi_bt_notification_cntx_p->current_dev = i;
            }
        }
        //memset(g_mmi_bt_notification_cntx_p->popup_dev_addr, 0, sizeof(srv_bt_cm_bt_addr));
        mmi_bt_notification_main_show_entry(GRP_ID_ROOT);
    }
    else
    {
    #ifndef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__      

    #if 0//def __MMI_BLE_ANCS_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_BLE_ANCS_SUPPORT__ */
    #endif 

        {
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__   
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MSG_LIST);
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_GROUP_LIST);
        #endif
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        
            mmi_frm_group_create_ex(GRP_ID_ROOT,
                GRP_ID_BTNOTIFICATION_APP,
                mmi_bt_notification_launch_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);

        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            g_mmi_bt_notification_cntx_p->list_enum = MMI_BT_NOTIFICATION_GROUP_LIST;
        #endif
            mmi_bt_notification_show_msg_list(GRP_ID_BTNOTIFICATION_APP);
        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
            if (mmi_bt_notification_get_linked_dev_list_idx() == 1)
            {//direct enter list or main category when it is just one device linked
                mmi_bt_notification_main_show_entry(GRP_ID_BTNOTIFICATION_APP);
            }
            else
            {
                mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_APP, 
                    SCR_ID_BTNOTIFICATION_DEV_LIST, 
                    mmi_bt_notification_launch_proc,
                    NULL);
            }
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        }
    }
    g_mmi_bt_notification_cntx_p->launch_from_popup = MMI_FALSE;
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


static void mmi_bt_notification_popup_launch_app()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
    g_mmi_bt_notification_cntx_p->launch_from_popup = MMI_TRUE;
    mmi_bt_notification_launch();
}


#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__  

static void mmi_bt_notification_popup_view_check()
{
    srv_bt_noti_data_msg_node_struct node_ref;
    
    if(mmi_bt_notification_get_msg_info_ref(NULL, 0, &node_ref))
    {
        g_mmi_bt_notification_cntx_p->noti_id = node_ref.noti_id;
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        //if (!mmi_frm_group_is_present(GRP_ID_BTNOTIFICATION_GROUP_LIST))
        g_mmi_bt_notification_cntx_p->noti_id = srv_bt_noti_data_listmgr_get_latest_unread_noti_id();

        g_mmi_bt_notification_cntx_p->total_page_account = 0; ////// todo
        g_mmi_bt_notification_cntx_p->current_page_id = 0;
    #endif
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 11);            
    }    
}
#endif


static void mmi_bt_notification_popup_view()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //gdi_lcd_freeze(TRUE);
    gdi_layer_lock_frame_buffer();
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);

#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__  
    mmi_bt_notification_popup_view_check();
#endif    

    mmi_bt_notification_popup_launch_app();

    //gdi_lcd_freeze(gdi_freeze);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
static void mmi_bt_notification_pupop_right_key_hdlr();
#endif

static void mmi_bt_notification_popup_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_data_msg_node_struct *data_node;
    applib_time_struct create_time;
    WCHAR  time[20];
    WCHAR* timestamp_buffer;
    WCHAR* sms_title_buffer;
    U32 timestamp; 
    WCHAR* text_buffer;
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    MMI_BOOL from_same_app = MMI_TRUE;
    U32 total = 0;
    U32 unread_total = 0;
    WCHAR *sender;
    S16 i, app_id = -1;
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_buffer = (WCHAR*)&g_mmi_bt_notification_cntx_p->category_text_buffer;
    memset(text_buffer, 0, sizeof(WCHAR) * (BT_NOTIFY_CONTENT_LENTH + BT_NOTIFY_TICKER_TEXT_LENTH + 2));
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 1);

    //show status icon
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_status_icon_bar_show_icon(STATUS_ICON_NOTIFICATION);
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    
    #if 0//def __MMI_BLE_ANP_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif  //__MMI_BLE_ANP_SUPPORT__
    {        
        memset(&g_mmi_bt_notification_cntx_p->node, 0, sizeof(srv_bt_noti_data_msg_node_struct));
        
    #ifndef __MMI_BT_NOTIFICATION_ENHANCE__
        if(!mmi_bt_notification_get_msg_info_ref(&g_mmi_bt_notification_cntx_p->popup_dev_addr, 0, &g_mmi_bt_notification_cntx_p->node))
    #else
        if(!mmi_bt_notification_get_msg_info_ref_by_id(&g_mmi_bt_notification_cntx_p->popup_dev_addr, 
            srv_bt_noti_data_listmgr_get_latest_unread_noti_id(), 
            &g_mmi_bt_notification_cntx_p->node))
    #endif
        {
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
            return;
        }
        
        data_node = &g_mmi_bt_notification_cntx_p->node;

        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    #ifndef __MMI_BT_NOTIFICATION_ENHANCE__
        mmi_bt_notification_delete_read();
    #else
        unread_total = srv_bt_noti_data_listmgr_get_unread_num();
    #endif /* __MMI_BT_NOTIFICATION_ENHANCE__ */
    
        total = mmi_bt_notification_get_msg_num(&g_mmi_bt_notification_cntx_p->popup_dev_addr);

    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        if (unread_total > 1)    
    #else
        if (total > 1)    
    #endif /* __MMI_BT_NOTIFICATION_ENHANCE__ */
 
        {
            for (i = 0; i < total; i++)
            {
                srv_bt_noti_data_msg_node_struct node;
                if (mmi_bt_notification_get_msg_info_ref(&g_mmi_bt_notification_cntx_p->popup_dev_addr, i, &node)
                #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                    && (node.is_read == MMI_FALSE)
                #endif
                )
                {
                    if (app_id == -1)
                    {
                        sender = node.sender;
                        app_id = node.app_id;
                    }
                    else if (node.app_id != app_id)
                    {
                        from_same_app = MMI_FALSE;
                        break;
                    }
                    #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
                    else if (node.source == SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
                    {
                        from_same_app = MMI_FALSE;
                        break;
                    }
                    #endif       
                }
            }
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            kal_wsprintf((WCHAR*)text_buffer, "%d %w", unread_total, GetString(STR_ID_BTNOTIFICATION_NOTIFY_SUFFIX));
        #else
            kal_wsprintf((WCHAR*)text_buffer, "%d %w", total, GetString(STR_ID_BTNOTIFICATION_NOTIFY_SUFFIX));
        #endif /* __MMI_BT_NOTIFICATION_ENHANCE__ */
        }
        else
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        {
            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            if (srv_bt_notify_subtype_sms == data_node->header.subtype)
            {
                text_buffer = mmi_wcscpy(text_buffer, (PU16) (GetString(STR_ID_BTNOTIFICATION_APPLICATION_FROM)));   

                mmi_ucs2cat((PS8) text_buffer, (const PS8) (L" "));  
                
                if(data_node->sender[0] != 0)
                {
                    mmi_ucs2cat((PS8) text_buffer, (const PS8) data_node->sender);    
                }
                else
                {
                    mmi_ucs2cat((PS8) text_buffer, (const PS8) data_node->send_number);    
                }    
                mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));    
            } 
            #endif
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
            if(g_mmi_bt_notification_cntx_p->node.source == SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
            {
                if (data_node->page_content[0].title[0] != 0)
                {
                    text_buffer = mmi_wcscpy((WCHAR*) text_buffer, (const WCHAR*) data_node->page_content[0].title);
                    mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
                }
            }
        #endif
            if (data_node->page_content != NULL && data_node->page_content[0].content[0] != 0)
            {
                mmi_ucs2cat((PS8) text_buffer, (const PS8) data_node->page_content[0].content);          
            }
            #else
            if (data_node->content[0] != 0)
            {
                mmi_ucs2cat((PS8) text_buffer, (const PS8) data_node->content);          
            }
            mmi_ucs2cat((PS8) text_buffer, (const PS8) data_node->ticker_text);
            #endif
        }

        //timestamp
        timestamp_buffer = OslMalloc(sizeof(WCHAR) * 60);
        memset(timestamp_buffer, 0, sizeof(WCHAR) * 60);
        timestamp = applib_dt_sec_utc_to_local(data_node->timestamp); 
        applib_dt_utc_sec_2_mytime(timestamp, &create_time, MMI_FALSE); 
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        //kal_wsprintf((WCHAR*)timestamp_buffer, "%04d-%02d-%02d %02d:%02d:%02d", create_time.nYear, create_time.nMonth, create_time.nDay, create_time.nHour, create_time.nMin, create_time.nSec);
        memset(time,0,sizeof(WCHAR)*20);
        time_string((MYTIME*) & create_time, (UI_string_type)time, DT_IDLE_SCREEN);
        mmi_ucs2cat((PS8)timestamp_buffer, (const PS8)time);
        if(time[7]==0x4D)//M
        {//12-hour 
            WCHAR  time_sec[4];
            kal_wsprintf((WCHAR*)timestamp_buffer, "%04d.%02d.%02d ", create_time.nYear, create_time.nMonth,create_time.nDay);
            
            kal_wsprintf((WCHAR*)time_sec, "%02d",  create_time.nSec);
            
            time[10]= time[7];
            time[9]= time[6];
            time[5]= 0x3A; // :    
            time[8]= 0x20; // 
            time[6]= time_sec[0];
            time[7]= time_sec[1];
            mmi_ucs2cat((PS8)timestamp_buffer, (const PS8)time); 
        }
        else
        {//24-hour
            kal_wsprintf((WCHAR*)timestamp_buffer, "%04d.%02d.%02d %02d:%02d:%02d", create_time.nYear, create_time.nMonth, 
                                                                                 create_time.nDay, create_time.nHour,
                                                                                 create_time.nMin, create_time.nSec);     
        }
        
        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        date_string((MYTIME*) & create_time, (UI_string_type)time, DT_IDLE_SCREEN);
        mmi_ucs2cat((PS8) timestamp_buffer, (const PS8) time);
        mmi_ucs2cat((PS8) timestamp_buffer, (const PS8) (L" "));
        time_string((MYTIME*) & create_time, (UI_string_type)time, DT_IDLE_SCREEN);
        mmi_ucs2cat((PS8)timestamp_buffer, (const PS8)time);
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__

        //show category
        #if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)
        if (srv_bt_notify_subtype_sms == data_node->header.subtype)
        {
            sms_title_buffer = OslMalloc(sizeof(WCHAR) * (100)); 
            memset(sms_title_buffer, 0, sizeof(WCHAR) * (100));    
            sms_title_buffer = mmi_wcscpy(sms_title_buffer, (WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_FROM));  
            mmi_ucs2cat((PS8)sms_title_buffer, (const PS8)(L" "));   
            mmi_ucs2cat((PS8)sms_title_buffer, (const PS8)data_node->sender);
            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            wgui_showcategory6333_screen(
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__            
                (unread_total == 1 || from_same_app) ? (UI_string_type)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS) : (UI_string_type)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
            #else
                (total == 1 || from_same_app) ? (UI_string_type)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS) : (UI_string_type)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
            #endif
                (UI_string_type)GetString(STR_GLOBAL_VIEW),
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_DISMISS), 
            #else
                (UI_string_type)GetString(STR_GLOBAL_CANCEL), 
            #endif
                (UI_string_type)text_buffer,
                (UI_string_type)timestamp_buffer);
            #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
            wgui_showcategory632_screen(
                (UI_string_type)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS),
                (UI_string_type)sms_title_buffer,
                (UI_string_type)GetString(STR_GLOBAL_VIEW),
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_DISMISS), 
            #else
                (UI_string_type)GetString(STR_GLOBAL_CANCEL), 
            #endif
                (UI_string_type)text_buffer,
                (UI_string_type)timestamp_buffer);
            #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
            OslMfree(sms_title_buffer);
        }
        else
        #endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)
        {
            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            wgui_showcategory6333_screen(
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                (unread_total == 1 || from_same_app) ? (UI_string_type)data_node->sender : (UI_string_type)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
            #else            
                (total == 1 || from_same_app) ? (UI_string_type)data_node->sender : (UI_string_type)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
            #endif
                (UI_string_type)GetString(STR_GLOBAL_VIEW),
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_DISMISS), 
            #else
                (UI_string_type)GetString(STR_GLOBAL_CANCEL), 
            #endif
                (UI_string_type)text_buffer,
                (UI_string_type)timestamp_buffer);
            #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
            if (data_node->title != NULL)
            {
                wgui_showcategory632_screen(
                    (UI_string_type)data_node->sender,
                    (UI_string_type)data_node->title,
                    (UI_string_type)GetString(STR_GLOBAL_VIEW),
                #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                    (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_DISMISS), 
                #else
                    (UI_string_type)GetString(STR_GLOBAL_CANCEL), 
                #endif
                    (UI_string_type)text_buffer,
                    (UI_string_type)timestamp_buffer);
            }
            else
            {
                wgui_showcategory632_screen(
                    (UI_string_type)data_node->sender,
                     NULL,
                    (UI_string_type)GetString(STR_GLOBAL_VIEW),
                #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                    (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_DISMISS), 
                #else
                    (UI_string_type)GetString(STR_GLOBAL_CANCEL), 
                #endif        
                    (UI_string_type)text_buffer,
                    (UI_string_type)timestamp_buffer);
            }
            #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        }
        
        OslMfree(timestamp_buffer);
    
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        if (unread_total > 1)
        #else
        if (total > 1)
        #endif
        {
            SetLeftSoftkeyFunction(mmi_bt_notification_launch, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_bt_notification_launch, KEY_EVENT_UP);
        }
        else
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        {
            SetLeftSoftkeyFunction(mmi_bt_notification_popup_view, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_bt_notification_popup_view, KEY_EVENT_UP);
        }
    }

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    SetRightSoftkeyFunction(mmi_bt_notification_pupop_right_key_hdlr, KEY_EVENT_UP);
#else
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


static mmi_ret mmi_bt_notification_popup_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 4);
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            break;
            
        case EVT_ID_SCRN_ACTIVE:
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_NOTIFY);
        #endif            
            mmi_bt_notification_popup_show();
            break;

        case EVT_ID_SCRN_INACTIVE: 
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_NOTIFY);
        #endif            
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static MMI_BOOL mmi_bt_notification_popup_entry(mmi_scenario_id id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_BTNOTIFICATION_POPUP,
            mmi_bt_notification_popup_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_POPUP, 
        SCR_ID_BTNOTIFICATION_POPUP, 
        mmi_bt_notification_popup_proc,
        NULL);

    return MMI_TRUE;
}


#if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)

static void mmi_bt_notification_entry_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 process_image_id; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_frm_scrn_enter(
            GRP_ID_BTNOTIFICATION_EDIT,
            SCR_ID_BTNOTIFICATION_PROCESSING,
            NULL,
            mmi_bt_notification_entry_processing,
            MMI_FRM_FULL_SCRN))
    {
        process_image_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    #endif

        /*do not set title and title icon, otherwise processing screen will be a full screen*/
        ShowCategory8Screen(
            0,
            0,
            0,
            0,
            g_mmi_bt_notification_cntx_p->process_body_StrId,
            0,
            g_mmi_bt_notification_cntx_p->process_rsk_StrId,
            process_image_id,
            NULL);


        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
}


static void mmi_bt_notification_pre_entry_processing(U16 bodyStrId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_notification_cntx_p->process_body_StrId = bodyStrId;
    g_mmi_bt_notification_cntx_p->process_rsk_StrId = rskStrId;
}


static mmi_ret mmi_bt_notification_editor_opt_select_hdlr(mmi_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = (cui_menu_event_struct*)menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cui_menu_evt->highlighted_menu_id)
    {
		case MENU_ID_BTNOTIFICATION_EDITOR_SEND:
        {	
            MMI_BOOL result;
            
            mmi_bt_notification_pre_entry_processing(STR_GLOBAL_SENDING, NULL);
			result = srv_bt_noti_data_reply_remote_sms(&g_mmi_bt_notification_cntx_p->current_dev_addr,
                (WCHAR *)g_mmi_bt_notification_cntx_p->option_struct->send_number, 
                (WCHAR *)g_mmi_bt_notification_cntx_p->option_struct->content);
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_EDIT);
            if (result)
            {
                mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_SUCCESS, (WCHAR *)GetString(STR_GLOBAL_SENT));
            }
            else
            {
                mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_GLOBAL_FAILED));
            }
            break;
        }
    }
    if(cui_menu_is_menu_event(menu_evt->evt_id))
    {
        wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, GRP_ID_BTNOTIFICATION_EDIT);
    }
    return MMI_RET_OK;
}


static void mmi_bt_notification_menu_cui_entry_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cui_menu_is_menu_event(menu_evt->evt_id))
    {
        wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, GRP_ID_BTNOTIFICATION_EDIT);
    }
}


static mmi_ret mmi_bt_notification_send_sms_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 5);
	switch (menu_evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_bt_notification_menu_cui_entry_hdlr(evt);
            break;
        }
		case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_bt_notification_editor_opt_select_hdlr(evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
    }
    return MMI_RET_OK;
}


static void mmi_bt_notification_sms_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_bt_notification_pre_entry_processing(STR_GLOBAL_SENDING, NULL);
	result = srv_bt_noti_data_reply_remote_sms(&g_mmi_bt_notification_cntx_p->current_dev_addr,
        (WCHAR *)g_mmi_bt_notification_cntx_p->option_struct->send_number, 
        (WCHAR *)g_mmi_bt_notification_cntx_p->option_struct->content);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_EDIT);
    if (result)
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_SUCCESS, (WCHAR *)GetString(STR_GLOBAL_SENT));
    }
    else
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_GLOBAL_FAILED));
    }
}


static void mmi_bt_notification_entry_editor_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                    GRP_ID_BTNOTIFICATION_EDIT,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_OPTION,
                    MENU_ID_BTNOTIFICATION_EDITOR_OPT,
                    MMI_FALSE,
                    NULL);

    cui_menu_set_default_title_image_by_id(menu_cui_gid, IMG_SMS_ENTRY_SCRN_CAPTION);

    cui_menu_run(menu_cui_gid);
}


static mmi_ret mmi_bt_notification_editor_scrn_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, param->evt_id, 6);
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            #ifdef __MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__
            g_mmi_bt_notification_cntx_p->is_in_composer = MMI_FALSE;
            if (g_mmi_bt_notification_cntx_p->need_popup)
            {
                mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
                
                mmi_frm_nmgr_notify_by_app(
                    MMI_SCENARIO_ID_BT_NOTIFY,
                    MMI_EVENT_BT_NOTIFY,
                    mmi_bt_notification_popup_entry,
                    &g_mmi_bt_notification_cntx_p->refresh_cntx);
                
                g_mmi_bt_notification_cntx_p->need_popup = MMI_FALSE;
            }
            #endif  //__MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK; 
}


static void mmi_bt_notification_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_BTNOTIFICATION_EDIT, 
        SCR_ID_BTNOTIFICATION_EDIT, 
        NULL, 
        mmi_bt_notification_entry_editor, 
        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BTNOTIFICATION_EDIT, SCR_ID_BTNOTIFICATION_EDIT);

        wgui_uce_initialize_editor(
            (U8 *)(g_mmi_bt_notification_cntx_p->option_struct)->content,
            (MMI_BT_NOTIFICATION_SMS_MAX_NUMBER / ENCODING_LENGTH),
            1,
            1,
            (U8)(MMI_BT_NOTIFICATION_SMS_MAX_NUMBER / ENCODING_LENGTH - 1),
            mmi_sms_editor_get_message_size_callback,
            mmi_sms_editor_text_change_callback,
            mmi_sms_editor_display_type_callback,
            mmi_sms_editor_remaining_char_count,
            mmi_sms_editor_segment_count,
            NULL,
            NULL);
        
        mmi_sms_update_editor_info((CHAR*)(g_mmi_bt_notification_cntx_p->option_struct)->content);
        ShowCategory280Screen(
            STR_ID_SMS_BT_MESSAGE_MENUENTRY,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_SMS_COMMON_NOIMAGE,
            WGUI_UCE_MSG_TYPE_SMS,
            IMM_INPUT_TYPE_SENTENCE,
            NULL,
            NULL,
            gui_buffer);
        
        SetCategory280RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

        SetLeftSoftkeyFunction(mmi_bt_notification_entry_editor_options, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_bt_notification_sms_send, KEY_EVENT_UP);
              
        mmi_frm_scrn_set_leave_proc(
            GRP_ID_BTNOTIFICATION_EDIT,
            SCR_ID_BTNOTIFICATION_EDIT,
            mmi_bt_notification_editor_scrn_leave_proc);
    }
}


static void mmi_bt_notification_send_sms(WCHAR *phone_number, WCHAR *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_EDIT);
    memset((g_mmi_bt_notification_cntx_p->option_struct)->send_number, 0, BT_NOTIFY_NUMBER_LENTH * ENCODING_LENGTH + 1);
    memset((g_mmi_bt_notification_cntx_p->option_struct)->content, 0, BT_NOTIFY_SEND_SMS_CONTENT_LENTH * ENCODING_LENGTH + 1);
    if (phone_number != NULL)
    {
        memcpy((g_mmi_bt_notification_cntx_p->option_struct)->send_number, 
            phone_number, 
            mmi_wcslen(phone_number)*ENCODING_LENGTH + 1);
    }
    if (content != NULL)
    {
        memcpy((g_mmi_bt_notification_cntx_p->option_struct)->content, 
            content, 
            mmi_wcslen(content)*ENCODING_LENGTH + 1);
    }
    
    mmi_frm_group_create_ex(
                    GRP_ID_BTNOTIFICATION_OPTION,
                    GRP_ID_BTNOTIFICATION_EDIT,
                    mmi_bt_notification_send_sms_proc,
                    NULL,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_bt_notification_entry_editor();
    #ifdef __MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__
    g_mmi_bt_notification_cntx_p->is_in_composer = MMI_TRUE;
    #endif  //__MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__

}


static void mmi_bt_notification_main_option_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_REPLY;
        mmi_bt_notification_send_sms(g_mmi_bt_notification_cntx_p->node.send_number, NULL);
    }
}


static void mmi_bt_notification_main_option_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_FORWARD;
    }
}


static void mmi_bt_notification_main_option_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_CALL;
        

        if ((g_mmi_bt_notification_cntx_p->node.send_number[0] != '\0') || (g_mmi_bt_notification_cntx_p->node.send_number[1] != '\0'))
        {
            mmi_ucm_init_call_para(&param);
        
            param.dial_type = SRV_UCM_CALL_TYPE_ALL;
            param.ucs2_num_uri = (U16 *)g_mmi_bt_notification_cntx_p->node.send_number;
        
            mmi_ucm_call_launch(0, &param);
        }
        else
        {
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_GLOBAL_FAILED));
        }
    }
}

#endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)


static void mmi_bt_notification_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef  __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
    result = mmi_bt_notification_block_remote_notification(&g_mmi_bt_notification_cntx_p->node.bt_addr, g_mmi_bt_notification_cntx_p->node.app_id);
#else
    result = mmi_bt_notification_block_remote_notification(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->node.app_id);
#endif
    if (result)
    {
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_BT_NOTIFY_SYS, (WCHAR *)GetString(STR_ID_BTNOTIFICATION_POPUP_BLOCKED));
        #else 
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_SUCCESS, (WCHAR *)GetString(STR_ID_BTNOTIFICATION_POPUP_BLOCKED));
        #endif        
    }
    else
    {
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_BT_NOTIFY_SYS, (WCHAR *)GetString(STR_GLOBAL_FAILED));
        #else 
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_GLOBAL_FAILED));
        #endif        
    }
    
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_BLOCK);
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
}


static void mmi_bt_notification_block_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_id str_id;
    WCHAR* pop_str, *str;
   
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__    
    {
        if(!mmi_bt_notification_get_msg_info_ref_by_id(&g_mmi_bt_notification_cntx_p->current_dev_addr, 
                                                        g_mmi_bt_notification_cntx_p->noti_id, 
                                                        &g_mmi_bt_notification_cntx_p->node))
        {//if the item had been deleted should goback 
            
                mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN); 
                
                MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->current_dev_addr.lap, g_mmi_bt_notification_cntx_p->current_dev_addr.uap, g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 10);
                return;            
        }
    }    
#endif


    str_id = STR_ID_BTNOTIFICATION_APPLICATION_BLOCK_NOTIFY;
    str = (WCHAR *)GetString(str_id);
    pop_str = (WCHAR *)OslMalloc((mmi_wcslen(str) + BT_NOTIFY_SENDER_LENTH + 2 + 1) * ENCODING_LENGTH);// 2 is '\n' and '?'
    memcpy (pop_str, str, (mmi_wcslen(str) + 1) * ENCODING_LENGTH);
    mmi_wcscat(pop_str, L"\n");
    mmi_wcscat(pop_str, g_mmi_bt_notification_cntx_p->node.sender);
    mmi_wcscat(pop_str, L"?");
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_showcategory6333_screen(
        NULL,
        (UI_string_type)GetString(STR_GLOBAL_YES),
        (UI_string_type)GetString(STR_GLOBAL_NO),
        pop_str,
        NULL);
    #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    ShowCategory165Screen(
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        pop_str,
        IMG_GLOBAL_L1,
        gui_buffer);
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__

    SetLeftSoftkeyFunction(mmi_bt_notification_block, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_notification_block, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    OslMfree(pop_str);
}


static mmi_ret mmi_bt_notification_block_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 7);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_block_show();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static void mmi_bt_notification_main_option_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_FORWARD;

        mmi_frm_group_create_ex(
                        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
                        GRP_ID_BTNOTIFICATION_MAIN,
                        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
                        GRP_ID_BTNOTIFICATION_OPTION,
                        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
                        GRP_ID_BTNOTIFICATION_BLOCK,
                        mmi_bt_notification_block_proc,
                        NULL,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
        
        mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_BLOCK, 
            SCR_ID_BTNOTIFICATION_BLOCK, 
            mmi_bt_notification_block_proc,
            NULL);
    }
}


static void mmi_bt_notification_mre_result_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    ShowCategory165Screen(
        STR_GLOBAL_OK,
        0,
        NULL,
        0,
        (UI_string_type) GetString(g_mmi_bt_notification_cntx_p->result_id),
        IMG_GLOBAL_L1,
        gui_buffer);    

    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

static mmi_ret mmi_bt_notification_mre_result_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_mre_result_show();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

static void mmi_bt_notification_mre_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_BTNOTIFICATION_MRE_RESULT,
        mmi_bt_notification_mre_result_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_MRE_RESULT, 
        SCR_ID_BTNOTIFICATION_MRE_RESULT, 
        mmi_bt_notification_mre_result_proc,
        NULL);
}

#if !defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)

static void mmi_bt_notification_delete_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_id str_id;

    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (MMI_BT_NOTIFICATION_OPTION_DELETE == g_mmi_bt_notification_cntx_p->option_struct->option_enum)
        str_id = STR_ID_BTNOTIFICATION_APPLICATION_DELETE;
    else
        str_id = STR_ID_BTNOTIFICATION_APPLICATION_EMPTY;

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (UI_string_type) GetString(str_id),
        IMG_GLOBAL_L1,
        gui_buffer);
    

    if (MMI_BT_NOTIFICATION_OPTION_DELETE == g_mmi_bt_notification_cntx_p->option_struct->option_enum)
    {
        SetLeftSoftkeyFunction(mmi_bt_notification_delete, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_notification_delete, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_bt_notification_empty, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_notification_empty, KEY_EVENT_UP);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


static mmi_ret mmi_bt_notification_delete_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 8);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_delete_show();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static void mmi_bt_notification_main_option_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_DELETE;
        
        mmi_frm_group_create_ex(
                        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
                        GRP_ID_BTNOTIFICATION_MAIN,
                        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
                        GRP_ID_BTNOTIFICATION_OPTION,
                        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
                        GRP_ID_BTNOTIFICATION_DELETE,
                        mmi_bt_notification_delete_proc,
                        NULL,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);

        mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_DELETE, 
            SCR_ID_BTNOTIFICATION_MAIN_DELETE, 
            mmi_bt_notification_delete_proc,
            NULL);
    }
}


static void mmi_bt_notification_main_option_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_EMPTY;
        mmi_frm_group_create_ex(
                        GRP_ID_BTNOTIFICATION_OPTION,
                        GRP_ID_BTNOTIFICATION_DELETE,
                        mmi_bt_notification_delete_proc,
                        NULL,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);

        mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_DELETE, 
            SCR_ID_BTNOTIFICATION_MAIN_DELETE, 
            mmi_bt_notification_delete_proc,
            NULL);
    }
}


static mmi_ret mmi_bt_notification_main_option_select(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                 */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    
    switch (menu_evt->highlighted_menu_id)
    {
        #if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_REPLY:
            mmi_bt_notification_main_option_reply();
            break;
            
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_FORWARD:
            mmi_bt_notification_main_option_forward();
            break;
            
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_CALL:
            mmi_bt_notification_main_option_call();
            break;
        #endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_BLOCK:
            mmi_bt_notification_main_option_block();
            break;
            
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_DELETE:
            mmi_bt_notification_main_option_delete();
            break;
            
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_EMPTY:
            mmi_bt_notification_main_option_empty();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static mmi_ret mmi_bt_notification_main_option_entry(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                 */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;

    #if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)
    if (srv_bt_notify_subtype_sms == g_mmi_bt_notification_cntx_p->node.header.subtype)
    {
        if (!(g_mmi_bt_notification_cntx_p->option_struct)->is_sender_valid)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_REPLY, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_CALL, MMI_TRUE);
        }
            
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_BLOCK, MMI_TRUE);
    }
    else
    #endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_REPLY, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_FORWARD, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_CALL, MMI_TRUE);
    }

    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_FORWARD, MMI_TRUE);    
    return MMI_RET_OK;
}


static mmi_ret mmi_bt_notification_main_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    MMI_ID ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                 */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 9);
    menu_evt = (cui_menu_event_struct *)evt;
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            ret = mmi_bt_notification_main_option_entry(evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            ret = mmi_bt_notification_main_option_select(evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }
    return ret;
}


static void mmi_bt_notification_main_show_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID option_menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                 */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
            GRP_ID_BTNOTIFICATION_MAIN, 
            GRP_ID_BTNOTIFICATION_OPTION, 
            mmi_bt_notification_main_option_proc, 
            NULL);
    mmi_frm_group_enter(GRP_ID_BTNOTIFICATION_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    option_menu_id = cui_menu_create(
                            GRP_ID_BTNOTIFICATION_OPTION, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_OPTION, 
                            MENU_ID_BTNOTIFICATION_APPLICATION_OPT, 
                            MMI_FALSE, 
                            NULL);    
    cui_menu_set_default_title(option_menu_id,
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
        NULL
        );
    cui_menu_run(option_menu_id);
}


static void mmi_bt_notification_main_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_notification_cntx_p->total = mmi_bt_notification_get_msg_num(&g_mmi_bt_notification_cntx_p->current_dev_addr);
    if (g_mmi_bt_notification_cntx_p->total == 0 || g_mmi_bt_notification_cntx_p->id >= g_mmi_bt_notification_cntx_p->total)
    {
        return;
    }

    #if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)
    if (srv_bt_notify_subtype_sms == g_mmi_bt_notification_cntx_p->node.header.subtype)
    {
        if ((g_mmi_bt_notification_cntx_p->option_struct)->is_sender_valid)
        {
            mmi_bt_notification_main_option_reply();
        }
        else
        {
            mmi_bt_notification_main_option_delete();
        }
    }
    else
    #endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)
    {
        mmi_bt_notification_main_option_delete();
    }
}

#endif  //!defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)


static void mmi_bt_notification_main_left_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->id > 0)
        g_mmi_bt_notification_cntx_p->id--;
    else
        g_mmi_bt_notification_cntx_p->id = g_mmi_bt_notification_cntx_p->total - 1;

#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__  
    {
        srv_bt_noti_data_msg_node_struct node_ref;
        if(mmi_bt_notification_get_msg_info_ref(NULL, g_mmi_bt_notification_cntx_p->id, &node_ref))
        {
            g_mmi_bt_notification_cntx_p->noti_id = node_ref.noti_id;
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            g_mmi_bt_notification_cntx_p->total_page_account = 0; ////// todo
            g_mmi_bt_notification_cntx_p->current_page_id = 0;
        #endif
        }    
    }
#endif    

    
    mmi_bt_notification_main_show_category();
}


static void mmi_bt_notification_main_right_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total - 1)
        g_mmi_bt_notification_cntx_p->id++;
    else
        g_mmi_bt_notification_cntx_p->id = 0;

#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__  
    {
        srv_bt_noti_data_msg_node_struct node_ref;
        if(mmi_bt_notification_get_msg_info_ref(NULL, g_mmi_bt_notification_cntx_p->id, &node_ref))
        {
            g_mmi_bt_notification_cntx_p->noti_id = node_ref.noti_id;
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            g_mmi_bt_notification_cntx_p->total_page_account = 0; ////// todo
            g_mmi_bt_notification_cntx_p->current_page_id = 0;
        #endif
        }     
    }
#endif    

    
    mmi_bt_notification_main_show_category();
}


void mmi_bt_notification_main_show_category_check_newline(U8* string)
{
    S32 len = 0;
    U16 *str_p = NULL;

    len = mmi_wcslen((WCHAR*)string);
    str_p = (U16*)string;
    
    for(len ;len > 0 ;len--)
    {

        if(str_p[len - 1] == 0x0A)
        {
            str_p[len - 1] = 0;           
        }
        else
        {
           break;         
        }

    }
}

#if (defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)) || (defined __MMI_BT_NOTIFICATION_ENHANCE__)
static WCHAR time_buff[100];
#endif

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
static void mmi_bt_notification_main_show_category_page(void);

static void mmi_bt_notification_pupop_right_key_hdlr()
{  
    srv_bt_noti_data_listmgr_set_all_as_read();
    
    wgui_status_icon_bar_hide_icon(STATUS_ICON_NOTIFICATION);
        
    mmi_frm_scrn_close_active_id();    
}

     
static void mmi_bt_notification_main_page_show_entry()
{
    g_mmi_bt_notification_cntx_p->main_page_screen_id += 1;
    
    mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_MAIN, 
        g_mmi_bt_notification_cntx_p->main_page_screen_id, 
        mmi_bt_notification_main_proc,
        g_mmi_bt_notification_cntx_p);
}


static mmi_ret mmi_bt_notification_main_page_left_hdlr(mmi_event_struct *evt)
{    
    MMI_ID group_id, screen_id;
    
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    if (GRP_ID_BTNOTIFICATION_MAIN == group_id)
    {
        // update page id
        if (g_mmi_bt_notification_cntx_p->current_page_id < g_mmi_bt_notification_cntx_p->total_page_account)
        {
            g_mmi_bt_notification_cntx_p->current_page_id += 1;

            // update category                    
        #ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__
            wgui_BTcat145_set_page_mode_sse_no_change_footer(MMI_TRUE);
        #endif
            mmi_bt_notification_main_page_show_entry();
        }
    }

    return MMI_RET_OK;
}


static mmi_ret mmi_bt_notification_main_page_right_hdlr(mmi_event_struct *evt)
{    
    MMI_ID group_id, screen_id;
    
    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

    if (GRP_ID_BTNOTIFICATION_MAIN == group_id)
    {                
    #ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__
        wgui_BTcat145_set_page_mode_sse_no_change_footer(MMI_TRUE);
    #endif
    }

    return MMI_RET_OK;
}


static void mmi_bt_notification_main_action_delete(void)
{
    U32 index;
    
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        mmi_bt_notification_delete_msg(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->noti_id);         
    }
        
    mmi_bt_notification_get_group_info_ref_by_id(g_mmi_bt_notification_cntx_p->group_list->app_id,
                                    g_mmi_bt_notification_cntx_p->group_list->group_id,
                                    &index);
    if ((MMI_BT_NOTIFICATION_MSG_LIST == g_mmi_bt_notification_cntx_p->list_enum) && 
            (g_mmi_bt_notification_cntx_p->group_list == NULL ||
            g_mmi_bt_notification_cntx_p->group_list->noti_num == 0))
        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MSG_LIST);   
    else    
        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
}


static void mmi_bt_notification_main_action_block(void)
{
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        srv_bt_noti_data_block_remote_notification(&g_mmi_bt_notification_cntx_p->node.bt_addr, g_mmi_bt_notification_cntx_p->node.app_id);        
    }
    
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);    
}


static void mmi_bt_notification_main_action_operate0(void)
{
    mmi_bt_notification_action_operate(&g_mmi_bt_notification_cntx_p->current_dev_addr,
                               g_mmi_bt_notification_cntx_p->noti_id, 
                               g_mmi_bt_notification_cntx_p->node.noti_action[0].action_id);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
}


static void mmi_bt_notification_main_action_operate1(void)
{
    mmi_bt_notification_action_operate(&g_mmi_bt_notification_cntx_p->current_dev_addr,
                               g_mmi_bt_notification_cntx_p->noti_id, 
                               g_mmi_bt_notification_cntx_p->node.noti_action[1].action_id);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
}


static void mmi_bt_notification_main_action_operate2(void)
{
    mmi_bt_notification_action_operate(&g_mmi_bt_notification_cntx_p->current_dev_addr,
                               g_mmi_bt_notification_cntx_p->noti_id, 
                               g_mmi_bt_notification_cntx_p->node.noti_action[2].action_id);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
}


static void mmi_bt_notification_main_action_operate3(void)
{
    mmi_bt_notification_action_operate(&g_mmi_bt_notification_cntx_p->current_dev_addr,
                               g_mmi_bt_notification_cntx_p->noti_id, 
                               g_mmi_bt_notification_cntx_p->node.noti_action[3].action_id);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
}


static void mmi_bt_notification_main_action_operate4(void)
{
    mmi_bt_notification_action_operate(&g_mmi_bt_notification_cntx_p->current_dev_addr,
                               g_mmi_bt_notification_cntx_p->noti_id, 
                               g_mmi_bt_notification_cntx_p->node.noti_action[4].action_id);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
}


typedef void (*action_operate_handler) (void);


action_operate_handler mmi_bt_notification_main_action_operate_handler[5] = 
{
    mmi_bt_notification_main_action_operate0,
    mmi_bt_notification_main_action_operate1,
    mmi_bt_notification_main_action_operate2,
    mmi_bt_notification_main_action_operate3,
    mmi_bt_notification_main_action_operate4
};


static void mmi_bt_notification_main_set_action_handler()
{
#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__
    U8 i = 0;

#ifndef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
    if (g_mmi_bt_notification_cntx_p->node.is_blocked)
        wgui_BTcat145_set_footer_area_show_button_count(g_mmi_bt_notification_cntx_p->node.action_num + 1);
    else
        wgui_BTcat145_set_footer_area_show_button_count(g_mmi_bt_notification_cntx_p->node.action_num + 2);
#else  
    if (g_mmi_bt_notification_cntx_p->node.source != SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
    {
        if (g_mmi_bt_notification_cntx_p->node.is_blocked)
            wgui_BTcat145_set_footer_area_show_button_count(g_mmi_bt_notification_cntx_p->node.action_num + 1);
        else
            wgui_BTcat145_set_footer_area_show_button_count(g_mmi_bt_notification_cntx_p->node.action_num + 2);
    }
    else
    {        
        wgui_BTcat145_set_footer_area_show_button_count(g_mmi_bt_notification_cntx_p->node.action_num + 1);
    }
#endif
      
    for(i = 0; i < g_mmi_bt_notification_cntx_p->node.action_num; i++)
    {        
        wgui_BTcat145_set_footer_area_show_button_lable(g_mmi_bt_notification_cntx_p->node.noti_action[i].action_name, i);  
        wgui_BTcat145_footer_area_register_controlled_callback(mmi_bt_notification_main_action_operate_handler[i], i); 
    }
    
    wgui_BTcat145_set_footer_area_show_button_lable(get_string(STR_ID_BTNOTIFICATION_APPLICATION_OPTION_DELETE),g_mmi_bt_notification_cntx_p->node.action_num);  
    wgui_BTcat145_footer_area_register_controlled_callback(mmi_bt_notification_main_action_delete, g_mmi_bt_notification_cntx_p->node.action_num); 

#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
    if (g_mmi_bt_notification_cntx_p->node.source != SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
#endif
    {
        if (!g_mmi_bt_notification_cntx_p->node.is_blocked)
        {
            wgui_BTcat145_set_footer_area_show_button_lable(get_string(STR_ID_BTNOTIFICATION_APPLICATION_OPTION_BLOCK),g_mmi_bt_notification_cntx_p->node.action_num + 1);  
            wgui_BTcat145_footer_area_register_controlled_callback(mmi_bt_notification_main_action_block, g_mmi_bt_notification_cntx_p->node.action_num + 1); 
        }
    }
#endif
}


static void mmi_bt_notification_main_show_first_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    srv_bt_noti_data_msg_node_struct * node_data;
    srv_bt_noti_page_content_struct* page_data;
    U8* icon_buffer;  //type
    WCHAR* text_buffer;   //txt
    applib_time_struct create_time;
    WCHAR  time[40];
    WCHAR* time_buffer;
    U32 timestamp;
    U16  message_icon_id = IMG_MESSAGE_UNREAD;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    clear_screen();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();      

    node_data = &g_mmi_bt_notification_cntx_p->node;
    page_data = node_data->page_content;
    MMI_ASSERT(node_data);
    //MMI_ASSERT(page_data);

    if (page_data == NULL)
        return;

#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__
    wgui_BTcat145_set_page_mode_data(g_mmi_bt_notification_cntx_p->total_page_account + 1,
                    g_mmi_bt_notification_cntx_p->current_page_id,
                    MMI_BT145_PAGE_MODE_APP_NAME_AND_CONTENT_TEXT_AND_NO_BUTTON);
#endif

    //image
    if (srv_bt_notify_subtype_sms == node_data->header.subtype)
    {
        set_cat145_show_image_finish();
        set_cat145_show_image_data_finish();
        icon_buffer = (U8*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS);
    }
    else
    {
#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
       if(g_mmi_bt_notification_cntx_p->node.source != SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
#endif
        {
            //icon
        #ifdef __BT_NOTI_SRV_ICON_WITH_BUFFER__
            set_cat145_show_image_finish();
            set_cat145_show_image_file_data((U8*)node_data->icon->icon_buffer, GDI_IMAGE_TYPE_JPG, (S32)node_data->icon->icon_size);
        #else
            set_cat145_show_image_data_finish();
            set_cat145_show_image_file_path((U8*)node_data->icon_file_path);
        #endif
            //icon_buffer = (U8*)node_data->sender;
            icon_buffer = (U8*)page_data->title;
        }
    }

    //title + context + ticker_text + time
    text_buffer = (WCHAR*)&g_mmi_bt_notification_cntx_p->category_text_buffer;
    memset(text_buffer, 0, sizeof(WCHAR) * (BT_NOTIFY_CONTENT_LENTH + 100));
    
#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
    if(g_mmi_bt_notification_cntx_p->node.source == SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
    {
        if (page_data->title[0] != 0)
        {
            text_buffer = mmi_wcscpy((WCHAR*) text_buffer, (const WCHAR*) page_data->title);
            mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
        }
    }
#endif
    
    if (srv_bt_notify_subtype_sms == node_data->header.subtype)
    {
        text_buffer = mmi_wcscpy(text_buffer, (PU16) (GetString(STR_ID_BTNOTIFICATION_APPLICATION_FROM)));   
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L" "));
        if(node_data->sender[0] != 0)
        {
            mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->sender);    
        }
        else
        {
            mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->send_number);    
        }
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));          
        mmi_ucs2cat((PS8) text_buffer, (const PS8) page_data->content);   
    }
    else
    {
        if (page_data->content[0] != 0)
        {
            mmi_ucs2cat((PS8) text_buffer, (const PS8) page_data->content);
            mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
        }          
    }
    timestamp = applib_dt_sec_utc_to_local(node_data->timestamp);
    applib_dt_utc_sec_2_mytime(timestamp, &create_time, MMI_FALSE);
    date_string((MYTIME*) & create_time, time, DT_IDLE_SCREEN);
    kal_wsprintf((WCHAR*)time, "%04d.%02d.%02d ", create_time.nYear, create_time.nMonth,create_time.nDay);

    time_buffer = &time_buff[0];
    memset(time_buffer,0,sizeof(WCHAR)*100);
    mmi_ucs2cpy((PS8) time_buffer, (const PS8)time);   
    mmi_ucs2cat((PS8) time_buffer, (const PS8) (L" "));
    time_string((MYTIME*) & create_time, time, DT_IDLE_SCREEN);
    mmi_ucs2cat((PS8) time_buffer, (const PS8)time); 
    
        
    //show category
#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
    if(g_mmi_bt_notification_cntx_p->node.source == SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
    {
        set_cat145_show_image_finish();
        set_cat145_show_image_data_finish();
        icon_buffer = (U8*)node_data->sender;
        //icon_buffer = (U8*)page_data->title;
        message_icon_id = IMG_BTNOTIFICATON_ANCS_ICON;
        if (srv_bt_notify_subtype_sms == node_data->header.subtype)
        {
            icon_buffer = (U8*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS);
        }
    }
#endif

#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__
    mmi_bt_notification_main_show_category_check_newline((U8*)text_buffer);

    ShowBTNotiCategory145Screen_WEARABLE_DEVICE(
        NULL,//(U8*)(page_data->title[0] == 0 ? NULL : page_data->title),
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        message_icon_id,
        (U8*)icon_buffer,
        (U8*)text_buffer,
        NULL,
        gui_buffer,
        (U8*)time_buffer); 
#endif 

    // register touch handler       
	mmi_frm_cb_reg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_bt_notification_main_page_right_hdlr, NULL);
	mmi_frm_cb_reg_event(EVT_ID_WEARABLE_DEVICE_MOVE_LEFT, mmi_bt_notification_main_page_left_hdlr, NULL);
}


static void mmi_bt_notification_main_show_action_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    srv_bt_noti_data_msg_node_struct * node_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    clear_screen();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();   
    //set_cat145_show_image_finish();

    node_data = &g_mmi_bt_notification_cntx_p->node;
    MMI_ASSERT(node_data);    
    
#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__
    wgui_BTcat145_set_page_mode_data(g_mmi_bt_notification_cntx_p->total_page_account + 1,
                    g_mmi_bt_notification_cntx_p->current_page_id,
                    MMI_BT145_PAGE_MODE_ONLY_BUTTON);
    
    mmi_bt_notification_main_set_action_handler();

    ShowBTNotiCategory145Screen_WEARABLE_DEVICE(
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        gui_buffer,
        NULL); 
#endif

    // register touch handler    
	mmi_frm_cb_reg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_bt_notification_main_page_right_hdlr, NULL);
	mmi_frm_cb_reg_event(EVT_ID_WEARABLE_DEVICE_MOVE_LEFT, mmi_bt_notification_main_page_left_hdlr, NULL); 
}


static void mmi_bt_notification_main_show_other_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    srv_bt_noti_data_msg_node_struct * node_data;
    srv_bt_noti_page_content_struct* page_data;
    U8* icon_buffer;  //type
    WCHAR* text_buffer;
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    clear_screen();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();   
    //set_cat145_show_image_finish();   

    node_data = &g_mmi_bt_notification_cntx_p->node;
    page_data = node_data->page_content->next;
    i = 1;
    while(i < g_mmi_bt_notification_cntx_p->current_page_id)
    {
        page_data = page_data->next;
        i++;
    }
    
    MMI_ASSERT(node_data);
    MMI_ASSERT(page_data);
    
#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__

    if (page_data->title[0] == 0)
    {
        wgui_BTcat145_set_page_mode_data(g_mmi_bt_notification_cntx_p->total_page_account + 1,
                    g_mmi_bt_notification_cntx_p->current_page_id,
                    MMI_BT145_PAGE_MODE_ONLY_CONTENT_TEXT);
    }
    else
    {
        wgui_BTcat145_set_page_mode_data(g_mmi_bt_notification_cntx_p->total_page_account + 1,
                    g_mmi_bt_notification_cntx_p->current_page_id,
                    MMI_BT145_PAGE_MODE_APP_NAME_AND_CONTENT_TEXT_AND_NO_BUTTON);
    }
#endif
    
    if (srv_bt_notify_subtype_sms == node_data->header.subtype)
    {
        icon_buffer = (U8*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS);
    }
    else
    {
        icon_buffer = (U8*)page_data->title;
    }
    
    text_buffer = (WCHAR*)&g_mmi_bt_notification_cntx_p->category_text_buffer;
    memset(text_buffer, 0, sizeof(WCHAR) * (BT_NOTIFY_CONTENT_LENTH + 100));

    if (srv_bt_notify_subtype_sms == node_data->header.subtype)
    {
        text_buffer = mmi_wcscpy(text_buffer, (PU16) (GetString(STR_ID_BTNOTIFICATION_APPLICATION_FROM)));   
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L" "));
        if(node_data->sender[0] != 0)
        {
            mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->sender);    
        }
        else
        {
            mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->send_number);    
        }
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));          
        mmi_ucs2cat((PS8) text_buffer, (const PS8) page_data->content);   
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));              
    }
    else
    {
        if (page_data->content[0] != 0)
        {
            mmi_ucs2cat((PS8) text_buffer, (const PS8) page_data->content);
            mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
        }          
    }

    mmi_bt_notification_main_show_category_check_newline((U8*)text_buffer);

    mmi_bt_notification_main_show_category_check_newline((U8*)text_buffer);
    
#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__
    ShowBTNotiCategory145Screen_WEARABLE_DEVICE(
        NULL,//(U8*)(page_data->title[0] == 0 ? NULL : page_data->title),
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        (U8*)icon_buffer,
        (U8*)text_buffer,
        NULL,
        gui_buffer,
        NULL);  
#endif

    // register touch handler    
	mmi_frm_cb_reg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_bt_notification_main_page_right_hdlr, NULL);
	mmi_frm_cb_reg_event(EVT_ID_WEARABLE_DEVICE_MOVE_LEFT, mmi_bt_notification_main_page_left_hdlr, NULL);
}


static void mmi_bt_notification_main_show_category_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#ifdef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    WCHAR device_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = L"BT Device";
	#else  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    WCHAR device_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = {0};
	#endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MSG_LIST_LONG_TAP);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_GROUP_LIST_LONG_TAP);
    
    #ifndef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    mmi_bt_notification__get_dev_ucs2_name(
        &(g_mmi_bt_notification_cntx_p->current_dev_addr),
        SRV_BT_CM_BD_UCS2_NAME_LEN,
        device_name);

    if (mmi_bt_notification_get_linked_dev_list_idx() == 0)
    {
        mmi_bt_notification_main_show_disconnect((WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME));
        return;
    }
    else if (MMI_FALSE == mmi_bt_notification_check_connection_ext(&g_mmi_bt_notification_cntx_p->current_dev_addr))
    {
        mmi_bt_notification_main_show_disconnect(device_name);
        return;
    }
    else if (MMI_FALSE == mmi_bt_notification_check_version(&g_mmi_bt_notification_cntx_p->current_dev_addr))
    {
        mmi_bt_notification_main_show_disconnect((WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME));
        return;
    }
    #endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP

    g_mmi_bt_notification_cntx_p->total = mmi_bt_notification_get_msg_num(&g_mmi_bt_notification_cntx_p->current_dev_addr);

    if (g_mmi_bt_notification_cntx_p->total == 0)
    {
        g_mmi_bt_notification_cntx_p->id = 0;
        mmi_bt_notification_main_show_empty(device_name);
        return;
    }

    if (g_mmi_bt_notification_cntx_p->id >= g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->id = (g_mmi_bt_notification_cntx_p->total - 1);
    }    
    
    if(!mmi_bt_notification_get_msg_info_ref_by_id(&g_mmi_bt_notification_cntx_p->current_dev_addr, 
                                                    g_mmi_bt_notification_cntx_p->noti_id, 
                                                    &g_mmi_bt_notification_cntx_p->node))
    {
        // the item had been deleted        
        {
            //should goback 
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN); 
            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, 
                g_mmi_bt_notification_cntx_p->current_dev_addr.lap, g_mmi_bt_notification_cntx_p->current_dev_addr.uap,
                                                                   g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 9);
            return;
        }
    }
    
    g_mmi_bt_notification_cntx_p->total_page_account = g_mmi_bt_notification_cntx_p->node.page_num;
        
#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__
    wgui_BTcat145_set_page_mode_sse_no_change_footer(MMI_TRUE);
#endif

    //show page category
    if (g_mmi_bt_notification_cntx_p->current_page_id == 0)
        mmi_bt_notification_main_show_first_page();
    else if(g_mmi_bt_notification_cntx_p->current_page_id == g_mmi_bt_notification_cntx_p->total_page_account)
        mmi_bt_notification_main_show_action_page();
    else
        mmi_bt_notification_main_show_other_page();
    
    
    g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
    if ( g_mmi_bt_notification_cntx_p->node.header.subtype == srv_bt_notify_subtype_sms)
    {
        MMI_BOOL is_number_valid = MMI_FALSE;
        
    #ifdef __MMI_BT_MAP_CLIENT__
        is_number_valid = srv_sms_btmapc_check_ucs2_number((char *)g_mmi_bt_notification_cntx_p->node.send_number);
    #endif
        
        if (!is_number_valid || 
            ((g_mmi_bt_notification_cntx_p->node.send_number[0] == '\0') && 
            (g_mmi_bt_notification_cntx_p->node.send_number[1] == '\0')))
        {
            (g_mmi_bt_notification_cntx_p->option_struct)->is_sender_valid = MMI_FALSE;
        }
        else
        {
            (g_mmi_bt_notification_cntx_p->option_struct)->is_sender_valid = MMI_TRUE;
        }
    }  
}

#else


static void mmi_bt_notification_main_show_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    srv_bt_noti_data_msg_node_struct * node_data;
    U8* icon_buffer;  //type
    WCHAR* text_buffer;   //txt
    applib_time_struct create_time;
    WCHAR  time[40];
    #if defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    WCHAR* time_buffer;
    #else  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    WCHAR* number_buffer;  //"9/10"
    #endif  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    U32 timestamp;
	#ifdef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    WCHAR device_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = L"BT Device";
	#else  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    WCHAR device_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = {0};
	#endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP

    U16  message_icon_id = IMG_MESSAGE_UNREAD;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->current_dev_addr.lap, g_mmi_bt_notification_cntx_p->current_dev_addr.uap, g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 2);

    #ifndef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    mmi_bt_notification__get_dev_ucs2_name(
        &(g_mmi_bt_notification_cntx_p->current_dev_addr),
        SRV_BT_CM_BD_UCS2_NAME_LEN,
        device_name);

    if (mmi_bt_notification_get_linked_dev_list_idx() == 0)
    {
        mmi_bt_notification_main_show_disconnect((WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME));
        return;
    }
    else if (MMI_FALSE == mmi_bt_notification_check_connection_ext(&g_mmi_bt_notification_cntx_p->current_dev_addr))
    {
        mmi_bt_notification_main_show_disconnect(device_name);
        return;
    }
    #endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP

    g_mmi_bt_notification_cntx_p->total = mmi_bt_notification_get_msg_num(&g_mmi_bt_notification_cntx_p->current_dev_addr);

    if (g_mmi_bt_notification_cntx_p->total == 0)
    {
        g_mmi_bt_notification_cntx_p->id = 0;
        mmi_bt_notification_main_show_empty(device_name);
        return;
    }
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    else if (g_mmi_bt_notification_cntx_p->total == 1)
    {
        //remove status icon
        wgui_status_icon_bar_hide_icon(STATUS_ICON_NOTIFICATION);
    }
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    
    clear_screen();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (g_mmi_bt_notification_cntx_p->id >= g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->id = (g_mmi_bt_notification_cntx_p->total - 1);
    }
    memset(&g_mmi_bt_notification_cntx_p->node, 0, sizeof(srv_bt_noti_data_msg_node_struct));
    
#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__   
    if(!mmi_bt_notification_get_msg_info_ref_by_id(&g_mmi_bt_notification_cntx_p->current_dev_addr, 
                                                    g_mmi_bt_notification_cntx_p->noti_id, 
                                                    &g_mmi_bt_notification_cntx_p->node))
    {// the item had been deleted
        
        {//should goback 
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN); 
            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, 
                g_mmi_bt_notification_cntx_p->current_dev_addr.lap, g_mmi_bt_notification_cntx_p->current_dev_addr.uap,
                                                                   g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 9);
            return;
        }
    }
#else
    mmi_bt_notification_get_msg_info_ref(&g_mmi_bt_notification_cntx_p->current_dev_addr,  
                                           g_mmi_bt_notification_cntx_p->id, &g_mmi_bt_notification_cntx_p->node);
#endif

    #if !defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) || !defined(__MMI_TOUCH_SCREEN__)
    //number
    number_buffer = OslMalloc(sizeof(WCHAR) * 10);
    kal_wsprintf(number_buffer, "%d/%d", 
        g_mmi_bt_notification_cntx_p->id + 1, 
        g_mmi_bt_notification_cntx_p->total);
    set_cat145_show_number((U8*)number_buffer);
    #endif  //!defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) || !defined(__MMI_TOUCH_SCREEN__)
    

    node_data = &g_mmi_bt_notification_cntx_p->node;
    MMI_ASSERT(node_data);

#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    //mark as read
    if(!gui_buffer)
    {// if it is first enter ,need set read status 
#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__ 
        mmi_bt_notification_set_read_status(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->noti_id, MMI_TRUE);
#else
        mmi_bt_notification_set_read_status(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->id, MMI_TRUE);
#endif
    }    
#endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__

    //image
    #if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)
    if (srv_bt_notify_subtype_sms == node_data->header.subtype)
    {
        set_cat145_show_image_finish();
        set_cat145_show_image_data_finish();
        icon_buffer = (U8*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS);

        #if defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_BTcat145_footer_area_set_no_show_button(MMI_TRUE);
        #endif
    }
    else
    #endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)
    {
#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
       if(g_mmi_bt_notification_cntx_p->node.source != SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
#endif
        {
    #ifndef __BT_NOTI_SRV_ICON_WITH_BUFFER__
        set_cat145_show_image_file_path((U8*)node_data->icon_file_path);
    #endif
        //icon
        icon_buffer = (U8*)node_data->sender;
        }
    }

    //title + context + ticker_text + time
    text_buffer = (WCHAR*)&g_mmi_bt_notification_cntx_p->category_text_buffer;
    memset(text_buffer, 0, sizeof(WCHAR) * (BT_NOTIFY_CONTENT_LENTH + 100));
    #if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)
    if (srv_bt_notify_subtype_sms == node_data->header.subtype)
    {
        text_buffer = mmi_wcscpy(text_buffer, (PU16) (GetString(STR_ID_BTNOTIFICATION_APPLICATION_FROM)));   
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L" "));          
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        if(node_data->sender[0] != 0)
        {
            mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->sender);    
        }
        else
        {
            mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->send_number);    
        }
        #else                
        mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->sender);    
        #endif
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));          
        mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->content);   
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));             
        mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->ticker_text); 
    }
    else
    #endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)
    {
        #if !defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
        if (node_data->title[0] != 0)
        {
            text_buffer = mmi_wcscpy(text_buffer, (PU16)node_data->title);
            mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
        }
        #endif  //!defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
        if (node_data->content[0] != 0)
        {
            mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->content);
            mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
        }          
        mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->ticker_text);
    }
    //mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
    timestamp = applib_dt_sec_utc_to_local(node_data->timestamp);
    applib_dt_utc_sec_2_mytime(timestamp, &create_time, MMI_FALSE);
    date_string((MYTIME*) & create_time, time, DT_IDLE_SCREEN);
    #if defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    //time_buffer = OslMalloc(sizeof(WCHAR) * 100);
    kal_wsprintf((WCHAR*)time, "%04d.%02d.%02d ", create_time.nYear, create_time.nMonth,create_time.nDay);
    time_buffer = &time_buff[0];
    memset(time_buffer,0,sizeof(WCHAR)*100);
    mmi_ucs2cpy((PS8) time_buffer, (const PS8)time);   
    mmi_ucs2cat((PS8) time_buffer, (const PS8) (L" "));
    time_string((MYTIME*) & create_time, time, DT_IDLE_SCREEN);
    mmi_ucs2cat((PS8) time_buffer, (const PS8)time); 
    #else  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
    mmi_ucs2cat((PS8) text_buffer, (const PS8)time);
    mmi_ucs2cat((PS8) text_buffer, (const PS8) (L" "));
    time_string((MYTIME*) & create_time, time, DT_IDLE_SCREEN);
    mmi_ucs2cat((PS8) text_buffer, (const PS8)time);
    #endif  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
        
    //show category
    #if defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)

#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
    if(g_mmi_bt_notification_cntx_p->node.source == SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
    {
        set_cat145_show_image_finish();
        wgui_BTcat145_footer_area_set_no_show_button(MMI_TRUE);
        icon_buffer = (U8*)node_data->sender;
        message_icon_id = IMG_BTNOTIFICATON_ANCS_ICON;
        #if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)
        if (srv_bt_notify_subtype_sms == node_data->header.subtype)
        {
            icon_buffer = (U8*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS);
        }
        #endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)        
    }
#endif
    wgui_BTcat145_footer_area_register_controlled_callback(mmi_bt_notification_main_option_block, 0);

    mmi_bt_notification_main_show_category_check_newline((U8*)text_buffer);
    
    ShowBTNotiCategory145Screen_WEARABLE_DEVICE(
        (U8*)(node_data->title[0] == 0 ? NULL : node_data->title),
        NULL,
        STR_ID_BTNOTIFICATION_APPLICATION_OPTION_BLOCK,
        NULL,
        NULL,
        NULL,
        message_icon_id,
        (U8*)icon_buffer,
        (U8*)text_buffer,
        NULL,
        gui_buffer,
        (U8*)time_buffer);
    #else  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    ShowBTNotiCategory145Screen(
        (U8 *)device_name,
        0,
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        message_icon_id,
        (U8*)icon_buffer,
        (U8*)text_buffer,
        0,
        gui_buffer);
    #endif  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)

    g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
    #if !defined(__MMI_BT_NOTIFICATION_NO_SMS__)
    if ( g_mmi_bt_notification_cntx_p->node.header.subtype == srv_bt_notify_subtype_sms)
    {
        MMI_BOOL is_number_valid = MMI_FALSE;
        
        #ifdef __MMI_BT_MAP_CLIENT__
        is_number_valid = srv_sms_btmapc_check_ucs2_number((char *)g_mmi_bt_notification_cntx_p->node.send_number);
        #endif
        
        if (!is_number_valid || 
            ((g_mmi_bt_notification_cntx_p->node.send_number[0] == '\0') && 
            (g_mmi_bt_notification_cntx_p->node.send_number[1] == '\0')))
        {
            (g_mmi_bt_notification_cntx_p->option_struct)->is_sender_valid = MMI_FALSE;
        }
        else
        {
            (g_mmi_bt_notification_cntx_p->option_struct)->is_sender_valid = MMI_TRUE;
        }
    }
    #endif  //!defined(__MMI_BT_NOTIFICATION_NO_SMS__)

    #if !defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
    SetLeftSoftkeyFunction(mmi_bt_notification_main_show_option, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_notification_main_csk_hdlr, KEY_EVENT_UP);
    #endif  //!defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);   
    SetKeyHandler(mmi_bt_notification_main_left_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_notification_main_right_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    #if defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    //OslMfree(time_buffer);
    #else  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    OslMfree(number_buffer);
    #endif  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
}
#endif

static mmi_ret mmi_bt_notification_main_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 10);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__        
            mmi_bt_notification_main_show_category_page();
        #else
            mmi_bt_notification_main_show_category();
        #endif
            break;

        case EVT_ID_SCRN_GOBACK:
            break;

        case EVT_ID_SCRN_DEINIT:
            
            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            //mark as read
               // srv_bt_noti_data_set_read_status(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->id, MMI_TRUE);
            #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
            
            set_cat145_show_number_finish();

        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            // update page id
            if (g_mmi_bt_notification_cntx_p->current_page_id > 0) 
            {
                g_mmi_bt_notification_cntx_p->current_page_id -= 1;  
            }   
            
            mmi_frm_cb_dereg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_bt_notification_main_page_right_hdlr, NULL);
            mmi_frm_cb_dereg_event(EVT_ID_WEARABLE_DEVICE_MOVE_LEFT, mmi_bt_notification_main_page_left_hdlr, NULL);        
        #endif
            
            break;

        case EVT_ID_GROUP_DEINIT:
            #if !defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
            g_mmi_bt_notification_cntx_p->id = 0;
            #endif  //!defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static void mmi_bt_notification_main_show_entry(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->current_dev_addr.lap, g_mmi_bt_notification_cntx_p->current_dev_addr.uap, g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 3);
    
    mmi_frm_group_create_ex(parent_id,
                            GRP_ID_BTNOTIFICATION_MAIN,
                            mmi_bt_notification_main_proc,
                            g_mmi_bt_notification_cntx_p,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_MAIN, 
        SCR_ID_BTNOTIFICATION_MAIN, 
        mmi_bt_notification_main_proc,
        g_mmi_bt_notification_cntx_p);
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    g_mmi_bt_notification_cntx_p->main_page_screen_id = 1;
#endif
}


static void mmi_bt_notification_sync_time()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_sync_event_struct *sync_time = &g_mmi_bt_notification_cntx_p->sync_time_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sync_time->call_back(&sync_time->bt_addr, sync_time->time, sync_time->time_zone, MMI_TRUE);
    
    g_mmi_bt_notification_cntx_p->synced = MMI_TRUE;

    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_SYNC_TIME);

#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_BT_NOTIFY_SYS, (WCHAR *)GetString(STR_ID_BTNOTIFICATION_POPUP_SYNCED));
#else 
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_SUCCESS, (WCHAR *)GetString(STR_ID_BTNOTIFICATION_POPUP_SYNCED));
#endif        

}


static void mmi_bt_notification_sync_time_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory165Screen(
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_SYNC_TIME),
        IMG_GLOBAL_L1,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_bt_notification_sync_time, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_notification_sync_time, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_END, KEY_EVENT_DOWN);
}


static mmi_ret mmi_bt_notification_sync_time_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 11);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_NOTIFY);
            #endif
            mmi_bt_notification_sync_time_show();
            break;
        case EVT_ID_SCRN_INACTIVE:            

            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_NOTIFY);
            #endif
            
            break;
            
        case EVT_ID_GROUP_DEINIT:
            if (!g_mmi_bt_notification_cntx_p->synced)
            {
                srv_bt_noti_sync_event_struct *sync_time = &g_mmi_bt_notification_cntx_p->sync_time_cntx;
                sync_time->call_back(&sync_time->bt_addr, sync_time->time, sync_time->time_zone, MMI_FALSE);
                g_mmi_bt_notification_cntx_p->synced = MMI_TRUE;
            }
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static MMI_BOOL mmi_bt_notification_sync_time_entry(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
                GRP_ID_ROOT,
                GRP_ID_BTNOTIFICATION_SYNC_TIME,
                mmi_bt_notification_sync_time_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_SYNC_TIME, 
        SCR_ID_BTNOTIFICATION_SYNC_TIME, 
        mmi_bt_notification_sync_time_proc,
        NULL);

    return MMI_TRUE;
}

#endif /* __MMI_BT_NOTIFICATION__ */


#if (defined(__MMI_BT_NOTIFICATION__) || defined (__MMI_BT_NOTI_SRV__))

void mmi_bt_notification_init()   // add in bootup
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_notification_cntx.id = 0;
    g_mmi_bt_notification_cntx.total = 0;
    g_mmi_bt_notification_cntx.current_dev = 0;
    g_mmi_bt_notification_cntx_p = &g_mmi_bt_notification_cntx;
    g_mmi_bt_notification_cntx_p->option_struct = &g_mmi_bt_notification_option;
    g_mmi_bt_notification_cntx_p->synced = MMI_TRUE;

#ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP__
    g_mmi_bt_notification_cntx.noti_id = 0;
#endif

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    g_mmi_bt_notification_cntx_p->current_page_id = 0;
    g_mmi_bt_notification_cntx_p->total_page_account = 0;
#endif
    
}


mmi_ret mmi_bt_notification_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 12);
#ifdef __MMI_BT_NOTIFICATION__
    mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_BT_NOTIFY,
        mmi_bt_notification_mre_entry,
        NULL);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MRE);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_DELETE);
#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    if((evt->evt_id == EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE)
        ||(evt->evt_id == EVT_ID_SRV_BT_NOTI_REFRESH))
#endif                 
    {
    #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
        if(!mmi_bt_notification_get_msg_info_ref_by_id(&g_mmi_bt_notification_cntx_p->current_dev_addr, 
                                                            g_mmi_bt_notification_cntx_p->noti_id, 
                                                            &g_mmi_bt_notification_cntx_p->node))
    #endif//when the item had been deleted
        {
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_BLOCK);
        }     
    }
#if !defined(__MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__)
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_EDIT);
#endif  //!defined(__MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__)
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_OPTION);
    if (evt->evt_id != EVT_ID_SRV_BT_NOTI_REFRESH)               
    {
    #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
        if (evt->evt_id != EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE)
    #endif
        {
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
        }
    #ifdef __MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__
        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_EDIT);
    #endif  //__MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__
    }
    
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE:
        {
            srv_bt_noti_connect_status_change_notify_struct *status_change_notify = (srv_bt_noti_connect_status_change_notify_struct*)evt;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, status_change_notify->bt_addr.lap, status_change_notify->bt_addr.uap, status_change_notify->bt_addr.nap, 10+status_change_notify->is_connected);

        #ifdef __MMI_BT_NOTIFICATION_WRISTBAND_FOR_ONLY_INSTALL_POPUP__
            break;
        #endif
            if (status_change_notify->is_connected)
            {//spp connected
                MMI_ID group_id, screen_id;

                mmi_frm_get_active_scrn_id(&group_id, &screen_id);

            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__            
                memcpy((void*)&g_mmi_bt_notification_cntx_p->current_dev_addr, (void*)&status_change_notify->bt_addr, sizeof(srv_bt_cm_bt_addr));
            #endif
                
                if(( mmi_frm_group_get_active_id() == GRP_ID_BTNOTIFICATION_MSG_LIST) 
                    &&(screen_id == SCR_ID_BTNOTIFICATION_MSG_LIST))
                {
                    mmi_bt_notification_refresh_screen();
                }
            }
            else
            {//spp disconnected
                srv_bt_noti_sync_event_struct *sync_time = &g_mmi_bt_notification_cntx_p->sync_time_cntx;
                
                MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, status_change_notify->bt_addr.lap, status_change_notify->bt_addr.uap, status_change_notify->bt_addr.nap, 10+status_change_notify->is_connected);

            #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
                if(mmi_bt_notification_check_connection_ext(NULL))
                {
                    break;
                }
            #endif
                
                if (sync_time == NULL || (status_change_notify->bt_addr.lap == sync_time->bt_addr.lap &&
                        status_change_notify->bt_addr.uap == sync_time->bt_addr.uap &&
                        status_change_notify->bt_addr.nap == sync_time->bt_addr.nap))
                {//forbid to call sync while spp disconnect
                    g_mmi_bt_notification_cntx_p->synced = MMI_TRUE;
                    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_SYNC_TIME);
                }

            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
                //remove status icon
                wgui_status_icon_bar_hide_icon(STATUS_ICON_NOTIFICATION);
                    
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__                    
                mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MSG_LIST_LONG_TAP);
                mmi_frm_group_close(GRP_ID_BTNOTIFICATION_GROUP_LIST_LONG_TAP);

                if (mmi_frm_group_is_present(GRP_ID_BTNOTIFICATION_GROUP_LIST))
                    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);

                mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MSG_LIST);
            #endif
            #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__

                if ((g_mmi_bt_notification_cntx_p->popup_dev_addr.lap == status_change_notify->bt_addr.lap &&
                        g_mmi_bt_notification_cntx_p->popup_dev_addr.uap == status_change_notify->bt_addr.uap &&
                        g_mmi_bt_notification_cntx_p->popup_dev_addr.nap == status_change_notify->bt_addr.nap)                        

                #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
                    ||(!mmi_bt_notification_check_connection_ext(NULL))
                #endif
                    )  
                {//only close the popup has the same BT address
                    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
                #ifdef __MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__
                    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_EDIT);
                #endif  //__MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__
                }
                
                if( (!mmi_bt_notification_check_connection_ext(&status_change_notify->bt_addr) &&
                    (mmi_frm_group_get_active_id() == GRP_ID_BTNOTIFICATION_MAIN || mmi_frm_group_is_present(GRP_ID_BTNOTIFICATION_MSG_LIST)) &&
                    status_change_notify->bt_addr.lap == g_mmi_bt_notification_cntx_p->current_dev_addr.lap &&
                    status_change_notify->bt_addr.uap == g_mmi_bt_notification_cntx_p->current_dev_addr.uap &&
                    status_change_notify->bt_addr.nap == g_mmi_bt_notification_cntx_p->current_dev_addr.nap)

                #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
                    ||(!mmi_bt_notification_check_connection_ext(NULL) &&
                    (mmi_frm_group_get_active_id() == GRP_ID_BTNOTIFICATION_MAIN || mmi_frm_group_is_present(GRP_ID_BTNOTIFICATION_MSG_LIST)))
                #endif
                    )
                {
                    if (mmi_bt_notification_get_linked_dev_list_idx() == 0 && mmi_frm_scrn_is_present(GRP_ID_BTNOTIFICATION_APP, SCR_ID_BTNOTIFICATION_DEV_LIST, MMI_FRM_NODE_ALL_FLAG))
                    {
                        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
                        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MSG_LIST);
                    }
                    if (mmi_frm_group_get_active_id() != GRP_ID_BTNOTIFICATION_MSG_LIST && mmi_frm_group_is_present(GRP_ID_BTNOTIFICATION_MSG_LIST))
                    {
                        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
                    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
                        mmi_frm_group_close(g_mmi_bt_notification_cntx_p->set_all_as_read_id);
                    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
                    }
                
                    mmi_bt_notification_refresh_screen();
                }
                else if (mmi_bt_notification_get_linked_dev_list_idx() == 0)
                {
                    if (mmi_frm_scrn_get_active_id() == SCR_ID_BTNOTIFICATION_DEV_LIST)
                    {
                        mmi_bt_notification_refresh_screen();
                    }
                }
            }
            break;
        }
        case EVT_ID_SRV_BT_NOTI_REFRESH:
        {
            srv_bt_noti_refresh_evt_struct* refresh_evt = (srv_bt_noti_refresh_evt_struct*)evt;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, refresh_evt->bt_addr.lap, refresh_evt->bt_addr.uap, refresh_evt->bt_addr.nap, 20+refresh_evt->refresh_type);
                    
    #ifndef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            if (MMI_FALSE == mmi_bt_notification_check_version(&g_mmi_bt_notification_cntx_p->current_dev_addr))
            {
                break;
            }
        #endif
    #endif

        #ifdef __MMI_BT_NOTIFICATION_WRISTBAND_FOR_ONLY_INSTALL_POPUP__
            break;
        #endif

            if(!refresh_evt->is_listmgr)  //  ???????
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 16);
            
                break;
            }

            if (SRV_BT_NOTIFY_REFRESH_NEW == refresh_evt->refresh_type)
            {
            #ifdef __MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__
                g_mmi_bt_notification_cntx_p->need_popup = MMI_FALSE;
                if (g_mmi_bt_notification_cntx_p->is_in_composer)
                {
                    memcpy(&g_mmi_bt_notification_cntx_p->refresh_cntx, refresh_evt, sizeof(srv_bt_noti_refresh_evt_struct));
                    g_mmi_bt_notification_cntx_p->need_popup = MMI_TRUE;
                }
                else
            #endif  //__MMI_BT_NOTIFICATION_NO_POPUP_IN_COMPOSE__
                {   
                    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
                #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
                    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
                #endif                    
                    memcpy((void*)&g_mmi_bt_notification_cntx_p->popup_dev_addr, (void*)&refresh_evt->bt_addr, sizeof(srv_bt_cm_bt_addr));
                                       
                    mmi_frm_nmgr_notify_by_app(
                        MMI_SCENARIO_ID_BT_NOTIFY,
                        MMI_EVENT_BT_NOTIFY,
                        mmi_bt_notification_popup_entry,
                        NULL);
                }
                MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 4);
            }
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            else if (SRV_BT_NOTIFY_REFRESH_UPDATE == refresh_evt->refresh_type)
            {
                MMI_ID group_id, screen_id;

                mmi_frm_get_active_scrn_id(&group_id, &screen_id);
                if ((mmi_frm_group_get_active_id() != GRP_ID_BTNOTIFICATION_POPUP) 
                                 || (screen_id != SCR_ID_BTNOTIFICATION_POPUP))
                {         
                    mmi_frm_nmgr_notify_by_app(
                        MMI_SCENARIO_ID_BT_NOTIFY,
                        MMI_EVENT_BT_NOTIFY,
                        mmi_bt_notification_popup_entry,
                        NULL);
                }
            }
            #endif
            #ifdef __MMI_BT_NOTIFICATION_FOR_DOGP_ANCS_SPP_WEARABLE__
            else
            {
                if ((SRV_BT_NOTIFY_REFRESH_DEL == refresh_evt->refresh_type)
                  && (srv_bt_notify_refresh_reason_from_service == refresh_evt->refresh_reason))
                {// delete from bottom request
                    MMI_ID group_id, screen_id;

                    if (srv_bt_noti_data_listmgr_get_unread_num() == 0)
                    {
                        wgui_status_icon_bar_hide_icon(STATUS_ICON_NOTIFICATION);
                    }                        

                    mmi_frm_get_active_scrn_id(&group_id, &screen_id);

                    // in current screen in popup                                                   
                    if (( mmi_frm_group_get_active_id() == GRP_ID_BTNOTIFICATION_POPUP) 
                                     &&(screen_id == SCR_ID_BTNOTIFICATION_POPUP))
                    {
                        g_mmi_bt_notification_cntx_p->total = mmi_bt_notification_get_msg_num(&g_mmi_bt_notification_cntx_p->current_dev_addr);

                    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                        if (srv_bt_noti_data_listmgr_get_unread_num())
                    #else
                        if (g_mmi_bt_notification_cntx_p->total)
                    #endif
                        {
                            mmi_bt_notification_refresh_screen();
                            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 5);
                        }
                        else
                        {
                            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
                            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 6);
                        }
                    }    
                    else if (mmi_frm_group_get_active_id() == GRP_ID_BTNOTIFICATION_MAIN)
                    {// in detail information 's screen or it's  popup screen
                        if (refresh_evt->noti_id == g_mmi_bt_notification_cntx_p->noti_id)//delete item which is viewing item
                        {
                            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
                            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 7);
                        } 
                    }
                    else if (mmi_frm_group_get_active_id() == GRP_ID_BTNOTIFICATION_MSG_LIST
                    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                        || mmi_frm_group_get_active_id() == GRP_ID_BTNOTIFICATION_GROUP_LIST
                    #endif
                        )
                    {// in detail information 's screen or it's  popup screen
                        if (screen_id == SCR_ID_BTNOTIFICATION_MSG_LIST
                        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                            || screen_id == SCR_ID_BTNOTIFICATION_GROUP_LIST
                        #endif
                            )
                        {
                            mmi_bt_notification_refresh_screen();
                            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, 
                                g_mmi_bt_notification_cntx_p->current_dev, 
                                g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, 
                                g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, 
                                g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 
                                8);
                        }

                    }

                }
                
            }
            #endif
            break;
        }
        case EVT_ID_SRV_BT_NOTI_SYNC_DEV:
        {
            srv_bt_noti_sync_event_struct* sync_evt = (srv_bt_noti_sync_event_struct*)evt;
            
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_SYNC_TIME);

            memcpy(&g_mmi_bt_notification_cntx_p->sync_time_cntx, sync_evt, sizeof(srv_bt_noti_sync_event_struct));

            g_mmi_bt_notification_cntx_p->synced = MMI_FALSE;

        #ifdef __MMI_BT_NOTIFICATION_WRISTBAND_FOR_ONLY_INSTALL_POPUP__
        #ifdef __MMI_BLE_TIP_SUPPORT__
            sync_evt->call_back(&sync_evt->bt_addr, sync_evt->time, sync_evt->time_zone, mmi_tipc_allow_sync_time());
        #else
            sync_evt->call_back(&sync_evt->bt_addr, sync_evt->time, sync_evt->time_zone, MMI_TRUE);
        #endif
            break;
        #else            
        #ifdef __MMI_WEARABLE_DEVICE_SETTING__
            if (mmi_get_time_autosync_status())
            {
                MMI_ID group_id, screen_id;
            #ifdef __MMI_BLE_TIP_SUPPORT__
                sync_evt->call_back(&sync_evt->bt_addr, sync_evt->time, sync_evt->time_zone, mmi_tipc_allow_sync_time());
            #else
                sync_evt->call_back(&sync_evt->bt_addr, sync_evt->time, sync_evt->time_zone, MMI_TRUE);
           #endif
                mmi_frm_get_active_scrn_id(&group_id, &screen_id);
                                
                if(( mmi_frm_group_get_active_id() == GRP_ID_BTNOTIFICATION_MSG_LIST) 
                    &&(screen_id == SCR_ID_BTNOTIFICATION_MSG_LIST))
                {
                    mmi_bt_notification_refresh_screen();
                }    
            }
            else
        #endif  //__MMI_WEARABLE_DEVICE_SETTING__
            {
            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
                if (!g_mmi_bt_notification_cntx_p->synced)
                {
                    sync_evt->call_back(&sync_evt->bt_addr, sync_evt->time, sync_evt->time_zone, MMI_TRUE);
                    g_mmi_bt_notification_cntx_p->synced = MMI_TRUE;
                }

            #else
                    mmi_frm_nmgr_notify_by_app(
                        MMI_SCENARIO_ID_BT_NOTIFY,
                        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
                        MMI_EVENT_BT_NOTIFY_SYS2,
                        #else 
                        MMI_EVENT_BT_NOTIFY,
                        #endif                    
                        mmi_bt_notification_sync_time_entry,
                        NULL);
            #endif        
            }

            break;
        #endif                
        }
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
        {
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_SYNC_TIME);
            //return MMI_RET_DONT_CARE;
            break;
        }
        case EVT_ID_SRV_BT_NOTI_MRE_INSTALL_NOTIFY:
        {
            srv_bt_noti_mre_install_event_notify_struct *mre_install = (srv_bt_noti_mre_install_event_notify_struct *)evt;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_MRE, mre_install->ret_code, mre_install->err_code);

            if (MRE_SYS_MEMPOOL_SIZE == 0) {
                break;
            }

            if (mre_install->ret_code == SRV_BT_NOTI_MRE_INSTALL_START)
            {
                mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MRE_RESULT);
                
                mmi_frm_nmgr_notify_by_app(
                    MMI_SCENARIO_ID_BT_NOTIFY,
                    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
                    MMI_EVENT_BT_NOTIFY_SYS2,
                    #else 
                    MMI_EVENT_BT_NOTIFY,
                    #endif                    
                    mmi_bt_notification_mre_entry,
                    NULL);
            }
            else
            {
                mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MRE);
                // if not create group GRP_ID_BTNOTIFICATION_MRE ,need cancel it with nmgr API
                mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_BT_NOTIFY, mmi_bt_notification_mre_entry, NULL);

                switch (mre_install->ret_code)
                {
                    case SRV_BT_NOTI_MRE_INSTALL_SUCCESS:
                    case SRV_BT_NOTI_MRE_UNINSTALL_SUCCESS:
                    {
                    #ifdef __MMI_BT_NOTIFICATION_WRISTBAND_FOR_ONLY_INSTALL_POPUP__
                        MMI_STR_ID hint_str_id = mre_install->ret_code == SRV_BT_NOTI_MRE_INSTALL_SUCCESS ? 
                           STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL_SUCCESS_SHORT : STR_ID_BTNOTIFICATION_POPUP_MRE_UNINSTALL_SUCCESS_SHORT;
                    #else
                        MMI_STR_ID hint_str_id = mre_install->ret_code == SRV_BT_NOTI_MRE_INSTALL_SUCCESS ? 
                            STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL_SUCCESS : STR_ID_BTNOTIFICATION_POPUP_MRE_UNINSTALL_SUCCESS;
                    #endif  
                    
                    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
                        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY ,MMI_EVENT_BT_NOTIFY_SYS, (WCHAR *)GetString(hint_str_id));
                    #else 
                        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY ,MMI_EVENT_SUCCESS, (WCHAR *)GetString(hint_str_id));
                    #endif                    
                        
                        break;
                    }

                    case SRV_BT_NOTI_MRE_INSTALL_FAIL:                   
                    case SRV_BT_NOTI_MRE_UNINSTALL_FAIL:
                    {
                        MMI_STR_ID hint_str_id;
                        if (mre_install->ret_code == SRV_BT_NOTI_MRE_UNINSTALL_FAIL)
                        {
                        #ifdef __MMI_BT_NOTIFICATION_WRISTBAND_FOR_ONLY_INSTALL_POPUP__                        
                            hint_str_id = STR_ID_BTNOTIFICATION_POPUP_MRE_UNINSTALL_FAIL_SHORT;
                        #else
                            hint_str_id = STR_ID_BTNOTIFICATION_POPUP_MRE_UNINSTALL_FAIL;
                        #endif                            
                        }
                        else
                        {
                            switch (mre_install->err_code)
                            {
                                case SRV_BT_NOTIFY_RET_FILE_NOT_EXIST:
                                case SRV_BT_NOTIFY_RET_FILE_INTEGRITY_ERROR:
                                {
                                    hint_str_id = STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL_FAIL_FOR_LOW_QUOTA;
                                    break;
                                }
                                
                                default:
                                {
                                    hint_str_id = STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL_FAIL_FOR_INTERNAL_ERR;
                                    break;
                                }
                            }

                        #ifdef __MMI_BT_NOTIFICATION_WRISTBAND_FOR_ONLY_INSTALL_POPUP__ 
                            hint_str_id = STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL_FAIL_SHORT;
                        #endif

                            
                        }

                    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
                        g_mmi_bt_notification_cntx_p->result_id = hint_str_id;
                
                        mmi_frm_nmgr_notify_by_app(
                            MMI_SCENARIO_ID_BT_NOTIFY,
                            MMI_EVENT_BT_NOTIFY,
                            mmi_bt_notification_mre_result,
                            NULL);
                    #else 
                        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY ,MMI_EVENT_FAILURE, (WCHAR *)GetString(hint_str_id));
                    #endif

                        break;
                    }
                }
            }

            break;
        }
        #endif /*__MMI_BT_NOTIFICATION_FOR_WEARABLE__*/
        #if 0//def __MMI_BLE_ANP_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif  //__MMI_BLE_ANP_SUPPORT__
        default:
        {
            return MMI_RET_OK;
        }
    }
	#elif defined(__MMI_BT_NOTI_SRV__)
	switch(evt->evt_id)
	{
		case EVT_ID_SRV_BT_NOTI_SYNC_DEV:
		{
			srv_bt_noti_sync_event_struct* sync_evt = (srv_bt_noti_sync_event_struct*)evt;
			srv_bt_noti_sync_event_struct *sync_time = &g_mmi_bt_notification_cntx_p->sync_time_cntx;
			
			memcpy(&g_mmi_bt_notification_cntx_p->sync_time_cntx, sync_evt, sizeof(srv_bt_noti_sync_event_struct));
			
		    sync_time->call_back(&(sync_time->bt_addr), sync_time->time, sync_time->time_zone, MMI_FALSE);
			break;
		}
	}
	
	#endif/*__MMI_BT_NOTI_SRV__*/
    return MMI_RET_OK;
}

#endif/*defined(__MMI_BT_NOTIFICATION__) || defined (__MMI_BT_NOTI_SRV__)*/

