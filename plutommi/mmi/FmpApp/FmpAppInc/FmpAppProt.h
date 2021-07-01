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
 *  FmpAppProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the SAP of the FMP.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef FMPAPP_PROT_H
#define FMPAPP_PROT_H

/****************************************************************************
 * Header
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

					 
#ifdef __MMI_BLE_FMP_SUPPORT__

#include "FmpAppGprot.h"
#include "TouchScreenGprot_Int.h"

/****************************************************************************
 * Global and Structure
 ****************************************************************************/
typedef struct
{
	mmi_id parent_grp_id;
	char* rbd_addr;           /*remote device addr*/
}mmi_fmpapp_context_struct;

/****************************************************************************
 * Function
 ****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_create_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_create_context(void);
 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_free_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_free_context(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_show_button_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_fmpapp_show_button_str(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_show_button_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_fmpapp_show_button_normal(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_show_stop_button_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_fmpapp_show_stop_button_str(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_show_stop_button_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_fmpapp_show_stop_button_normal(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_down_hdlr_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_down_hdlr_normal(mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_move_hdlr_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_move_hdlr_normal(mmi_pen_point_struct pos);


/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_empty_hdlr_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_empty_hdlr_normal(mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_up_hdlr_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_up_hdlr_normal(mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_exit_normal_screen
 * DESCRIPTION
 *  screen of "start find device" 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_exit_normal_screen(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_entry_normal_screen
 * DESCRIPTION
 *  screen of "start find device" 
 * PARAMETERS
 *  [grp]parent's group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_entry_normal_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_normal_sreen_show
 * DESCRIPTION
 *  to draw screen of "start find device" 
 * PARAMETERS
 *  [evt]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_normal_sreen_show(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_locator_connect_state
 * DESCRIPTION
 * to notify mmi task current connection state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_locator_connect_state(char* rbd_addr, int connect_state);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_locator_config_level_cb
 * DESCRIPTION
 * to notify mmi task alert level config result
 * PARAMETERS
 *  [addr] Remote bt device addr
 *  [service_type] IAS_SERVICE_TYPE
 *  [config_result] false(fail) or true(success)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_locator_alert_notify_cb(char* addr,int alert_result);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_up_hdlr_finding
 * DESCRIPTION
 *  handle pen up event
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_up_hdlr_finding(mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_down_hdlr_finding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_down_hdlr_finding(mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_move_hdlr_finding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_move_hdlr_finding(mmi_pen_point_struct pos);


/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_key_up_hdlr_finding
 * DESCRIPTION
 *  handle key up event
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_key_up_hdlr_finding(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_empty_hdlr_finding
 * DESCRIPTION
 *  dummy screen
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_empty_hdlr_finding(mmi_pen_point_struct pos);


/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_entry_finding_screen
 * DESCRIPTION
 *  screen of "stop find device" 
 * PARAMETERS
 *  [grp]parent's group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_entry_finding_screen(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_exit_finding_screen
 * DESCRIPTION
 *  exit screen of "stop find device" 
 * PARAMETERS
 *  [grp]parent's group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_exit_finding_screen(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_finding_sreen_show
 * DESCRIPTION
 *  to draw screen of "stop find device" 
 * PARAMETERS
 *  [evt]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_finding_sreen_show(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_stop_clicked_cb
 * DESCRIPTION
 * callback function of  clicking Start key in screen of "stop find device" 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_stop_clicked_cb(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_target_connect_state
 * DESCRIPTION
 *  to notify mmi task current connection state
 * PARAMETERS
 *  [bdaddr] Remote bluetooth device addr
 *  [connect_state] profile current connection state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_target_connect_state(char* bdaddr, int connect_state);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_alert_notify_cb
 * DESCRIPTION
 *  to notify mmi task start/stop alert
 * PARAMETERS
 *  [bdaddr] Remote bluetooth device addr
 *  [connect_state] profile current connection state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_target_alert_notify_cb(char* bdaddr,U8 alert_level);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_target_alert_enable
 * DESCRIPTION
 *  to start alert and light up the screen and ringing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_target_alert_enable(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_target_alert_enable
 * DESCRIPTION
 *  to stop alert and light off the screen and stop ringing
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_target_alert_disable(void);

#endif /*__MMI_BLE_FMP_SUPPORT__*/
/* DOM-NOT_FOR_SDK-END */

#endif /* FMPAPP_PROT_H */

