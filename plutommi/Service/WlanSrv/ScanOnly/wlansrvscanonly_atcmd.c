/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  WlanSrvAtCmd.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __WIFI_SCAN_ONLY_AT_CMD__

#include "mmi2l4c_scanonly_struct.h"
#include "wlansrvscanonly.h"

//#include "MMI_conn_app_trc.h"
#include "MMI_trc_int.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "MMI_conn_app_trc.h"



static void srv_wlan_scan_only_send_set_mode_cnf(void *user_data, SCANONLY_STATUS_ENUM state)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_scan_only_set_mode_cnf_struct *set_mode_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_FUNC, WLAN_SO_AT_TRC_SET_MODE_CNF, state);
	
    set_mode_cnf = (mmi_l4c_scan_only_set_mode_cnf_struct*)OslConstructDataPtr(sizeof(mmi_l4c_scan_only_set_mode_cnf_struct));
    if (user_data)
	{
		set_mode_cnf->src_id = *((kal_uint8*)user_data);
	}
    set_mode_cnf->result = state;
    
    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_L4C_SCAN_ONLY_SET_MODE_CNF, (oslParaType*)set_mode_cnf, NULL);	

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_scan_only_init_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data      [IN]
 *  res         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wlan_scan_only_init_callback(void *user_data, wlan_init_cnf_struct *cnf)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_FUNC, WLAN_SO_AT_TRC_INIT_CB);
	
	srv_wlan_scan_only_send_set_mode_cnf(user_data, cnf->state);
	if (user_data)
	{
		OslMfree((kal_uint8*)user_data);
	}

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_scan_only_deinit_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data      [IN]
 *  res         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wlan_scan_only_deinit_callback(void *user_data, wlan_deinit_cnf_struct *cnf)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_FUNC, WLAN_SO_AT_TRC_DEINIT_CB);
	
	srv_wlan_scan_only_send_set_mode_cnf(user_data, cnf->state);
	if (user_data)
	{
		OslMfree((kal_uint8*)user_data);
	}

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_scan_only_set_mode_hdl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param      [IN]
 *  mod_id         [IN]
 *  ilm         [IN]
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
static void srv_wlan_scan_only_set_mode_hdl(void *local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_scan_only_set_mode_req_struct *req_info = (mmi_l4c_scan_only_set_mode_req_struct *)local_param;
	wlan_result_enum ret = WLAN_RESULT_FAIL;
	SCANONLY_STATUS_ENUM state = SCANONLY_INIT_FAIL__UNKOWN;
	kal_uint8 *src_id_ptr = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_FUNC, WLAN_SO_AT_TRC_SET_MODE_HDL);
	
	if (req_info)
	{
		src_id_ptr = OslMalloc(sizeof(kal_uint8));
		*src_id_ptr = req_info->src_id;
		
	    switch (req_info->mode)
	    {
	        case MMI_L4C_SCAN_ONLY_MODE_STA:
			{
				wlan_init_req_struct init_req = {0};
				ret = wlan_init(&init_req, srv_wlan_scan_only_init_callback, src_id_ptr);
		        break;
	    	}
	        case MMI_L4C_SCAN_ONLY_MODE_OFF:
			{
				wlan_deinit_req_struct deinit_req = {0};
				ret = wlan_deinit(&deinit_req, srv_wlan_scan_only_deinit_callback, src_id_ptr);
				break;
			}
				
	        default:
	            break;
	    }
	}	

	if (WLAN_RESULT_FAIL == ret)
	{
		if (MMI_L4C_SCAN_ONLY_MODE_OFF == req_info->mode)
		{
			state = SCANONLY_DEINIT_FAIL__UNKOWN;
		}
			
		srv_wlan_scan_only_send_set_mode_cnf(&req_info->src_id, state);

		if (src_id_ptr)
		{
			OslMfree((kal_uint8*)src_id_ptr);
		}
	}
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_scan_only_scan_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_id      [IN]
 *  user_data      [IN]
 *  scan_res         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wlan_scan_only_scan_callback(void *user_data, wlan_scan_cnf_struct *cnf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_scan_only_scan_cnf_struct *cnf_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_FUNC, WLAN_SO_AT_TRC_SCAN_CB);
	
    // APs scaned are returned.    
    cnf_info = (mmi_l4c_scan_only_scan_cnf_struct*)OslConstructDataPtr(sizeof(mmi_l4c_scan_only_scan_cnf_struct));
    cnf_info->result = cnf->status;
    cnf_info->src_id = *((kal_uint8*)user_data);   
    cnf_info->ap_num = cnf->scan_ap_num;

    if (cnf_info->ap_num > SCANONLY_MAX_SCAN_AP_NUM)
    {
        cnf_info->ap_num = SCANONLY_MAX_SCAN_AP_NUM;
    }

	memcpy(cnf_info->result_info, cnf->scan_ap, sizeof(scanonly_scan_ap_info_struct)*cnf_info->ap_num);    
    
    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_L4C_SCAN_ONLY_SCAN_CNF, (oslParaType*)cnf_info, NULL);

	OslMfree((kal_uint8*)user_data);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_scan_only_scan_hdl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_param      [IN]
 *  mod_id         [IN]
 *  ilm         [IN]
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
static void srv_wlan_scan_only_scan_hdl(void *local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_scan_only_scan_req_struct *req_info = (mmi_l4c_scan_only_scan_req_struct *)local_param;
    kal_uint8 *src_id_ptr = NULL;
	wlan_result_enum ret = WLAN_RESULT_FAIL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_FUNC, WLAN_SO_AT_TRC_SCAN_HDL);
	
    // Only when STA is on, can scan be done.
    if (req_info)
	{
		wlan_scan_req_struct req = {0};
		req.scan_type = req_info->scan_type;
		
		src_id_ptr = OslMalloc(sizeof(kal_uint8));
		*src_id_ptr = req_info->src_id;
		
		ret = wlan_scan(&req, srv_wlan_scan_only_scan_callback, src_id_ptr);
	}
	
    if (WLAN_RESULT_FAIL == ret)
	{
		mmi_l4c_scan_only_scan_cnf_struct *cnf_info = (mmi_l4c_scan_only_scan_cnf_struct*)OslConstructDataPtr(sizeof(mmi_l4c_scan_only_scan_cnf_struct)); 
		cnf_info->result = SCANONLY_SCAN_FAIL__UNKOWN;
	    cnf_info->src_id = req_info->src_id;
	    cnf_info->ap_num = 0;
		memset(cnf_info->result_info, 0, sizeof(cnf_info->result_info));
		mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_L4C_SCAN_ONLY_SCAN_CNF, (oslParaType*)cnf_info, NULL);
		if (src_id_ptr)
		{
			OslMfree((kal_uint8*)src_id_ptr);
		}
	}
	
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_scan_only_init
 * DESCRIPTION
 *  register handler when bootup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wlan_scan_only_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_FUNC, WLAN_SO_AT_TRC_INIT);	
    
    SetProtocolEventHandler(srv_wlan_scan_only_set_mode_hdl, MSG_ID_MMI_L4C_SCAN_ONLY_SET_MODE_REQ);
	SetProtocolEventHandler(srv_wlan_scan_only_scan_hdl, MSG_ID_MMI_L4C_SCAN_ONLY_SCAN_REQ);
}

#endif /* __WIFI_SCAN_ONLY_AT_CMD__ */

