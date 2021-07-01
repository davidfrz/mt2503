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
 * BTB.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the source file of BTB
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"

#ifdef __MMI_BT_BTBOX_NOLCD__

#include "kal_trace.h"
#include "MMI_conn_app_trc.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "BtcmSrvGprot.h"
#include "BtconnScr.h"
#include "BTconncfg.h"
#include "A2dpSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "BTMMIA2DPScr.h"
#include "BTMMIScr.h"
#include "BTB.h"
#include "mmi_frm_input_event.h"
#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
#include  "BTMMIAntilostScr.h"
#endif  //__MMI_BT_ANTI_LOST_BY_RSSI__


static btb_context_struct g_btb_context;


#ifdef __MMI_LINE_IN__
extern MMI_BOOL mmi_linein_is_plug_in(void);
#endif  //__MMI_LINE_IN__



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
#endif


void btb_inquiry_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_INQUIRY_DEV, srv_bt_cm_get_linked_dev_list_idx());
    if (srv_bt_cm_get_linked_dev_list_idx() >= __BT_MAX_LINK_NUM__)
    {
		return;
	}

#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
    {
        srv_btsco_inquiry_result_enum result = srv_btsco_inquiry_start_callback(btb_inquiry_dev);
        kal_prompt_trace(MOD_MMI, "[BTB]btb_inquiry_dev, srv_btsco_inquiry_result=%d", result);
    }
#endif  //defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)

#ifdef __MMI_A2DP_SUPPORT__
    av_bt_inquiry_start_callback();
#endif //__MMI_A2DP_SUPPORT__

    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_search(
            SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST,
            BTB_INQUIRY_TIMEOUT_DURATION,
            BTB_INQUIRY_COD,
            MMI_TRUE))
    {
    }
    else
    {
        #ifdef __MMI_A2DP_SUPPORT__
        av_bt_inquiry_stop_callback();
        #endif

        #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
        srv_btsco_inquiry_stop_callback();
        #endif  //defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 event_mask;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if 0
/* under construction !*/
    #ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
/* under construction !*/
    #endif  //__MMI_BT_ANTI_LOST_BY_RSSI__
    #endif
    event_mask = SRV_BT_CM_EVENT_ACTIVATE |
                 SRV_BT_CM_EVENT_DEACTIVATE  |
                 SRV_BT_CM_EVENT_INQUIRY_IND |
                 SRV_BT_CM_EVENT_INQUIRY_COMPLETE |
                 SRV_BT_CM_EVENT_PAIR_IND |
                 SRV_BT_CM_EVENT_BOND_RES|
                 SRV_BT_CM_EVENT_PAIR_RES |
                 SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM |
                 SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY |
                 SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY |
                 SRV_BT_CM_EVENT_CONNECT_RES |
                 SRV_BT_CM_EVENT_DISCONNECT_IND |
                 SRV_BT_CM_EVENT_RELEASE_ALL_CONN |
#if !defined(__MMI_BT_SLIM__)
                 SRV_BT_CM_EVENT_REFRESH_PROFILE |
#endif  // !defined(__MMI_BT_SLIM__)
#ifdef __MMI_BT_AUTHORIZE__
                 SRV_BT_CM_EVENT_SET_AUTHORIZE |
                 SRV_BT_CM_EVENT_UNBLOCK |
#endif  // __MMI_BT_AUTHORIZE__
// #ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
//                  SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE |
// #endif  // __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
#ifdef __MMI_SIMAP_SUPPORT__
                 SRV_BT_CM_EVENT_SET_SIMAP |
#endif  // __MMI_SIMAP_SUPPORT__
#ifdef __BT_AUTO_DETECT_SUPPORT__
                 SRV_BT_CM_EVENT_CHIP_DETECT |
#endif  // __BT_AUTO_DETECT_SUPPORT__
                 SRV_BT_CM_EVENT_MYDEV_DEL |
                 SRV_BT_CM_EVENT_SET_VISIBILITY |
                 SRV_BT_CM_EVENT_SET_NAME |
                 SRV_BT_CM_EVENT_SCO_IND |
                 SRV_BT_CM_EVENT_PANIC_IND |
                 SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME |
                 SRV_BT_CM_EVENT_BEGIN_ACTIVATE |
                 
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
                 SRV_BT_CM_EVENT_FAIL_CONN_TO |
#endif  //__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
                 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;

    g_btb_context.handle = srv_bt_cm_set_notify((srv_bt_cm_notifier)btb_event_notify_handle, event_mask, NULL);
    g_btb_context.flag = 0;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_INIT, g_btb_context.handle);
}


/*****************************************************************************
 * FUNCTION
 *  btb_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_reset_notify(g_btb_context.handle);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_DEINIT, g_btb_context.handle);
}


/*****************************************************************************
 * FUNCTION
 *  btb_power_on
 * DESCRIPTION
 *  This function is BTBox operation after power on
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_power_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_POWER, 1, srv_bt_cm_get_power_status());
    //power on BT
    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF
        #ifdef __MMI_LINE_IN__
         && !mmi_linein_is_plug_in()
        #endif  //__MMI_LINE_IN__
        )
    {
        srv_bt_cm_switch_on();
        mmi_frm_input_event_notify(NOTIFY_ID_BT_POWER_ON, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_power_off
 * DESCRIPTION
 *  This function is BTBox operation before power off
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_power_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_POWER, 0, srv_bt_cm_get_power_status());
    mmi_frm_input_event_notify(NOTIFY_ID_BT_POWER_OFF, NULL);
}

    
/*****************************************************************************
 * FUNCTION
 *  btb_connect_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dev_addr
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_connect_ext(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_CONNECT_EXT,
                    ((dev_addr->nap & 0xff00) >> 8),
                    (dev_addr->nap & 0x00ff),
                    (dev_addr->uap),
                    ((dev_addr->lap & 0xff0000) >> 16),
                    ((dev_addr->lap & 0x00ff00) >> 8),
                    (dev_addr->lap & 0x0000ff),
                    g_btb_context.is_connecting);
    if (!g_btb_context.is_connecting)
    {
        g_btb_context.is_connecting = MMI_TRUE;
        kal_prompt_trace(MOD_MMI, "[BTB]start connecting, %d", g_btb_context.is_connecting);
        mmi_bt_dialer_connect_a2dp_src(dev_addr, NULL);
    }
}

    
/*****************************************************************************
 * FUNCTION
 *  btb_connect_a2dp_src_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dev_addr
 *  conn_type
 *  result
 *  is_connect
 *  is_indicate
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_connect_a2dp_src_cb(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_CONNECT_A2DP_SRC_CB,
                    ((dev_addr->nap & 0xff00) >> 8),
                    (dev_addr->nap & 0x00ff),
                    (dev_addr->uap),
                    ((dev_addr->lap & 0xff0000) >> 16),
                    ((dev_addr->lap & 0x00ff00) >> 8),
                    (dev_addr->lap & 0x0000ff),
                    conn_type, result, is_connect, is_indicate);

    if (is_connect)
    {
        //g_btb_context.is_connecting = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_inquiry_result_notify
 * DESCRIPTION
 *  This function is to handle inquiry result
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_inquiry_result_notify(void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 discoveried_dev_counter = srv_bt_cm_get_searched_dev_num();
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (discoveried_dev_counter > 0 && !srv_bt_cm_is_master() && srv_bt_cm_get_linked_dev_list_idx() < __BT_MAX_LINK_NUM__)
    {
        for (i = 0; i < discoveried_dev_counter; i++)
        {
            srv_bt_cm_dev_struct *discov_dev_p = srv_bt_cm_get_searched_dev_info(i);
            if (discov_dev_p)
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_INQUIRY_NOTIFY, i, discov_dev_p->cod, 
                    ((discov_dev_p->bd_addr.nap & 0xff00) >> 8),
                    (discov_dev_p->bd_addr.nap & 0x00ff),
                    (discov_dev_p->bd_addr.uap),
                    ((discov_dev_p->bd_addr.lap & 0xff0000) >> 16),
                    ((discov_dev_p->bd_addr.lap & 0x00ff00) >> 8),
                    (discov_dev_p->bd_addr.lap & 0x0000ff),
                    srv_bt_cm_is_box_ext(discov_dev_p->cod, discov_dev_p->name), discov_dev_p->name[0], discov_dev_p->name[1], discov_dev_p->name[2], discov_dev_p->name[3]);
                if (srv_bt_cm_is_box_ext(discov_dev_p->cod, (U8*)(discov_dev_p->name)))
                {
                    kal_prompt_trace(MOD_MMI, "[BTB]btb_inquiry_result_notify, it is Box, connecting");
                    srv_bt_cm_search_abort();
                    btb_connect_ext(&discov_dev_p->bd_addr);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_inquiry_complete
 * DESCRIPTION
 *  This function is to handle inquiry complete
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_inquiry_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 discoveried_dev_counter = srv_bt_cm_get_searched_dev_num();
    U8 i = 0;
    srv_bt_cm_inquiry_complete_struct *event = (srv_bt_cm_inquiry_complete_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (discoveried_dev_counter > 0 && !srv_bt_cm_is_master() && srv_bt_cm_get_linked_dev_list_idx() < __BT_MAX_LINK_NUM__)
    {
        for (i = 0; i < discoveried_dev_counter; i++)
        {
            srv_bt_cm_dev_struct *discov_dev_p = srv_bt_cm_get_searched_dev_info(i);
            if (discov_dev_p)
            {
                kal_prompt_trace(MOD_MMI, "[BTB]btb_inquiry_complete, %d,cod=%x,addr=[0x%02x:%02x:%02x:%02x:%02x:%02x],is_box=%d,name=[%x-%x-%x-%x]", i, discov_dev_p->cod,                     
                    ((discov_dev_p->bd_addr.nap & 0xff00) >> 8),
                    (discov_dev_p->bd_addr.nap & 0x00ff),
                    (discov_dev_p->bd_addr.uap),
                    ((discov_dev_p->bd_addr.lap & 0xff0000) >> 16),
                    ((discov_dev_p->bd_addr.lap & 0x00ff00) >> 8),
                    (discov_dev_p->bd_addr.lap & 0x0000ff),
                    srv_bt_cm_is_box_ext(discov_dev_p->cod, discov_dev_p->name), discov_dev_p->name[0], discov_dev_p->name[1], discov_dev_p->name[2], discov_dev_p->name[3]);
                if (srv_bt_cm_is_box_ext(discov_dev_p->cod, (U8*)(discov_dev_p->name)))
                {
                    kal_prompt_trace(MOD_MMI, "[BTB]btb_inquiry_complete, it is Box, connecting");
                    btb_connect_ext(&discov_dev_p->bd_addr);
                }
            }
        }
    }
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_INQUIRY_COMPLETE, discoveried_dev_counter, event->result, event->is_cancelled);
}


/*****************************************************************************
 * FUNCTION
 *  btb_disconnect_ext
 * DESCRIPTION
 *  This function is BTBox disconnect function
 * PARAMETERS
 *  srv_bt_cm_bt_addr* dev_addr
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_disconnect_ext(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_bt_dialor_disconnect((srv_bt_cm_bt_addr*)dev_addr);
}


/*****************************************************************************
 * FUNCTION
 *  btb_turn_on_visibility
 * DESCRIPTION
 *  only slave or idle box can turn on visibility, master will always on unless it has two links.
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void btb_turn_on_visibility(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_bt_cm_get_linked_dev_list_idx() < __BT_MAX_LINK_NUM__) && !srv_bt_cm_is_master() && !srv_bt_cm_is_profile_connecting())
    {
        srv_bt_cm_set_visibility(SRV_BT_CM_VISIBILITY_TEMPORARY_ON);
        mmi_frm_input_event_notify(NOTIFY_ID_BT_VISIBILITY_ON, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_turn_off_visibility
 * DESCRIPTION
 *  master visibility cannot be turn off, it will turn off itself when it has two links.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_turn_off_visibility(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_bt_cm_is_master() || (srv_bt_cm_get_linked_dev_list_idx() >= __BT_MAX_LINK_NUM__))
    {
        srv_bt_cm_set_visibility(SRV_BT_CM_VISIBILITY_OFF);
        mmi_frm_input_event_notify(NOTIFY_ID_BT_VISIBILITY_OFF, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_change_visibility
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_change_visibility(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_OFF)
    {
        btb_turn_on_visibility();
    }
    else
    {
        btb_turn_off_visibility();
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btb_inquiry_dev();
    mmi_frm_input_event_notify(AUD_ID_BT_CONNECTING, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  btb_disconnect
 * DESCRIPTION
 *  disconnect source first.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, source_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_a2dp_quiry_by_role(A2DP_ROLE_SINK, &source_index))
    {
        const srv_bt_cm_dev_struct* dev_p = srv_bt_cm_get_linked_dev_info(source_index);
        if (dev_p)
        {
            btb_disconnect_ext(&dev_p->bd_addr);
        }
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_DISCONNECT, source_index);
    }
    else
    {
        for (i = 0; i < srv_bt_cm_get_linked_dev_list_idx(); i++)
        {
            const srv_bt_cm_dev_struct* dev_p = srv_bt_cm_get_linked_dev_info(i);
            if (dev_p)
            {
                btb_disconnect_ext(&dev_p->bd_addr);
            }
        }
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_DISCONNECT, -1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_connect_success
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_connect_success(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[BTB]btb_connect_success, is_connecting=%d", g_btb_context.is_connecting);
    if (srv_bt_cm_get_linked_dev_list_idx() == 1)
    {
        U8 index = 0;
        MMI_BOOL found = MMI_FALSE;
        
        found = srv_a2dp_quiry_by_role(BT_A2DP_SOURCE, &index);
        if (found && !srv_bt_cm_is_master())
        {
            srv_bt_cm_set_as_master(MMI_TRUE);
        }
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_CONNECT_SUCCESS, found, index);
    }
    
    g_btb_context.is_connecting = MMI_FALSE;
    
    mmi_frm_input_event_notify(NOTIFY_ID_BT_CONNECTED, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  btb_disconnect_success
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void btb_disconnect_success(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 linked_devices = srv_bt_cm_get_linked_dev_list_idx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[BTB]btb_disconnect_ind, linked_devices=%d, is_master=%d", linked_devices, srv_bt_cm_is_master());
    if (linked_devices == 0 && srv_bt_cm_is_master())
    {
        srv_bt_cm_set_as_master(MMI_FALSE);
    }
    mmi_frm_input_event_notify(NOTIFY_ID_BT_DISCONNECTED, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  btb_key_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_key_test(mmi_frm_key_evt_struct *key_evt)
{
    kal_prompt_trace(MOD_MMI, "[BTB]btb_key_test,key[%d,%d],BT status=%d,visibility=%d,linked_devices=%d", key_evt->key_code, key_evt->key_type, srv_bt_cm_get_power_status(), srv_bt_cm_get_visibility(), srv_bt_cm_get_linked_dev_list_idx());
    if (key_evt->key_code == KEY_STAR)
    {
        kal_prompt_trace(MOD_MMI, "[BTB]BT status=%d,visibility=%d,linked_devices=%d", srv_bt_cm_get_power_status(), srv_bt_cm_get_visibility(), srv_bt_cm_get_linked_dev_list_idx());
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_pair_ind
 * DESCRIPTION
 *  This function is to handle pair indicate
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_pair_ind(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_pair_ind_struct *event = (srv_bt_cm_pair_ind_struct *)para;
    //#ifdef __BT_JUST_WORK_SUPPORT__
    kal_uint8 pin_size = 0;
    kal_uint8 *pin_code = NULL;
    //#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_PAIR_IND,
                    ((event->dev_addr.nap & 0xff00) >> 8),
                    (event->dev_addr.nap & 0x00ff),
                    (event->dev_addr.uap),
                    ((event->dev_addr.lap & 0xff0000) >> 16),
                    ((event->dev_addr.lap & 0x00ff00) >> 8),
                    (event->dev_addr.lap & 0x0000ff));
    //#ifdef __BT_JUST_WORK_SUPPORT__
    /*if(Custom_BTPairing_AutoAccept_Support() == KAL_TRUE)
    {
        U8 pin_code_str[10];
        pin_code = Custom_BTPairing_AutoAccept_Pincode(&pin_size);
        memcpy(pin_code_str, pin_code, pin_size+1);
        pin_code_str[pin_size] = 0;
        srv_bt_cm_send_passkey(&event->dev_addr, pin_code_str, MMI_TRUE);
    }*/
    //#endif
}


/*****************************************************************************
 * FUNCTION
 *  btb_pair_res
 * DESCRIPTION
 *  This function is to handle pair response
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_pair_res(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_pair_res_struct *event = (srv_bt_cm_pair_res_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_PAIR_RES, event->result,
                    ((event->dev_addr.nap & 0xff00) >> 8),
                    (event->dev_addr.nap & 0x00ff),
                    (event->dev_addr.uap),
                    ((event->dev_addr.lap & 0xff0000) >> 16),
                    ((event->dev_addr.lap & 0x00ff00) >> 8),
                    (event->dev_addr.lap & 0x0000ff));
}


/*****************************************************************************
 * FUNCTION
 *  btb_connect_res
 * DESCRIPTION
 *  This function is to handle connect response
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_connect_res(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_conn_res_struct *event = (srv_bt_cm_conn_res_struct *)para;
    U32 linked_devices = srv_bt_cm_get_linked_dev_list_idx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_CONNECT_RES, event->result, event->profile_id,
                    ((event->dev_addr->nap & 0xff00) >> 8),
                    (event->dev_addr->nap & 0x00ff),
                    (event->dev_addr->uap),
                    ((event->dev_addr->lap & 0xff0000) >> 16),
                    ((event->dev_addr->lap & 0x00ff00) >> 8),
                    (event->dev_addr->lap & 0x0000ff));
    if (linked_devices == 2)
    {
        //slave cannot connect to SP
        if (!srv_bt_cm_is_master() && !srv_bt_cm_is_box((const srv_bt_cm_bt_addr*)event->dev_addr))
        {
            kal_prompt_trace(MOD_MMI, "[BTB]slave cannot connect to SP");
            btb_disconnect_ext((const srv_bt_cm_bt_addr*)event->dev_addr);
        }
    }
    else if (!srv_bt_cm_is_box((const srv_bt_cm_bt_addr*)event->dev_addr) && !srv_bt_cm_is_master())
    {
        //the first one connect to SP will be master
        kal_prompt_trace(MOD_MMI, "[BTB]the first one connect to SP will be master");
        srv_bt_cm_set_as_master(MMI_TRUE);
    }

    btb_connect_success();
    
    //visibility will be turn off when link is full
    if (linked_devices >= __BT_MAX_LINK_NUM__)
    {
        kal_prompt_trace(MOD_MMI, "[BTB]visibility will be turn off when link is full");
        btb_turn_off_visibility();
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_disconnect_ind
 * DESCRIPTION
 *  This function is to handle disconnect indicate
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void btb_disconnect_ind(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_disconnect_ind_struct *event = (srv_bt_cm_disconnect_ind_struct *)para;
    U32 linked_devices = srv_bt_cm_get_linked_dev_list_idx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_DISCONNECT_IND, event->profile_id,
                    ((event->dev_addr->nap & 0xff00) >> 8),
                    (event->dev_addr->nap & 0x00ff),
                    (event->dev_addr->uap),
                    ((event->dev_addr->lap & 0xff0000) >> 16),
                    ((event->dev_addr->lap & 0x00ff00) >> 8),
                    (event->dev_addr->lap & 0x0000ff));
    kal_prompt_trace(MOD_MMI, "[BTB]btb_disconnect_ind, linked_devices=%d, is_master=%d", linked_devices, srv_bt_cm_is_master());
    if (linked_devices == 0 && srv_bt_cm_is_master())
    {
        srv_bt_cm_set_as_master(MMI_FALSE);
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
#ifdef __MMI_BT_AUDIO_SUPPORT__
/* under construction !*/
#ifdef __MMI_A2DP_SUPPORT__
/* under construction !*/
#endif  //__MMI_A2DP_SUPPORT__
/* under construction !*/
/* under construction !*/
#else  //__MMI_BT_AUDIO_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  //__MMI_BT_AUDIO_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_A2DP_SUPPORT__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
/* under construction !*/
            #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_A2DP_SUPPORT__)
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_BT_DIALER_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_A2DP_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/*****************************************************************************
 * FUNCTION
 *  btb_pair_res
 * DESCRIPTION
 *  This function is to handle pair res
 * PARAMETERS
 *  para
 *
 * RETURNS
 *  void
 *****************************************************************************/
void btb_event_notify_handle(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_EVENT_NOTIFY, event);
    switch (event)
    {
        case SRV_BT_CM_EVENT_ACTIVATE:
            //btb_power_switch_on_complete(para);
            break;

        case SRV_BT_CM_EVENT_DEACTIVATE:
            //btb_power_switch_off_complete(para);
            break;

        case SRV_BT_CM_EVENT_INQUIRY_IND:
            btb_inquiry_result_notify(para);
            break;

        case SRV_BT_CM_EVENT_INQUIRY_COMPLETE:
            btb_inquiry_complete(para);
            break;

        case SRV_BT_CM_EVENT_PAIR_IND:
            btb_pair_ind(para);
            break;

        case SRV_BT_CM_EVENT_PAIR_RES:
            btb_pair_res(para);
            break;

        case SRV_BT_CM_EVENT_BOND_RES:
            //btb_bond_result(para);
            break;
            
        case SRV_BT_CM_EVENT_CONNECT_RES:
            btb_connect_res(para);
            break;

        case SRV_BT_CM_EVENT_DISCONNECT_IND:
            btb_disconnect_ind(para);
            break;

        case SRV_BT_CM_EVENT_RELEASE_ALL_CONN:
            break;

        case SRV_BT_CM_EVENT_SET_VISIBILITY:
            break;

        case SRV_BT_CM_EVENT_SET_NAME:
            break;

        case SRV_BT_CM_EVENT_SCO_IND:
            break;

        case SRV_BT_CM_EVENT_PANIC_IND:
            //btb_panic_ind_pre_process();
            break;

        case SRV_BT_CM_EVENT_BEGIN_ACTIVATE:
            break;
            
        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
            break;

        case SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM:
            break;
            
        case SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY:
            break;
            
        case SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY:
            break;
            
#if !defined(__MMI_BT_SLIM__)
        case SRV_BT_CM_EVENT_REFRESH_PROFILE:
            break;
#endif  // !defined(__MMI_BT_SLIM__)

#ifdef __MMI_BT_AUTHORIZE__
        case SRV_BT_CM_EVENT_SET_AUTHORIZE:
            break;
            
        case SRV_BT_CM_EVENT_UNBLOCK:
            break;
#endif  // __MMI_BT_AUTHORIZE__

// #ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
//           case SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE:
            break;
// #endif  //__MMI_BT_LIMITED_DISCOVERY_SUPPORT__

#ifdef __MMI_SIMAP_SUPPORT__
        case SRV_BT_CM_EVENT_SET_SIMAP:
            break;
#endif  // __MMI_SIMAP_SUPPORT__

#ifdef __BT_AUTO_DETECT_SUPPORT__
        case SRV_BT_CM_EVENT_CHIP_DETECT:
            break;
#endif  // __BT_AUTO_DETECT_SUPPORT__
        case SRV_BT_CM_EVENT_MYDEV_DEL:
            break;
            
        case SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME:
            break;
            
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        case SRV_BT_CM_EVENT_FAIL_CONN_TO:
            break;
#endif  //__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    }
}


/*****************************************************************************
 * FUNCTION
 *  btb_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret btb_event_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BTB_EVENT_HDLR, event->evt_id);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_COMPLETED:
            btb_power_on();
            break;
            
        case EVT_ID_SRV_SHUTDOWN_NORMAL_START:
            btb_power_off();
            break;
            
        case EVT_ID_BTB_CHANGE_VISIBILITY:
            btb_change_visibility();
            break;
            
        case EVT_ID_BTB_CONNECT:
            btb_connect();
            break;
            
        case EVT_ID_BTB_DISCONNECT:
            btb_disconnect();
            break;
            
        case EVT_ID_PRE_KEY_EVT_ROUTING:
            btb_key_test((mmi_frm_key_evt_struct*)event);
            break;
        default:
            break;
    }

    return MMI_RET_OK;
}

#endif  //__MMI_BT_BTBOX_NOLCD__

