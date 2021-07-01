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
 *  PxpAppProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the PXP app when BLE is supported.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef PXPAPP_PROT_H
#define PXPAPP_PROT_H

/****************************************************************************
 * Header
 ****************************************************************************/
#include "MMI_features.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* auto add by kw_check end */


#ifdef __MMI_BLE_PXP_SUPPORT__

#include "PxpAppGprot.h"
#include "TouchScreenGprot_Int.h"


/****************************************************************************
 * define
 ****************************************************************************/
#define SIZE_OF_POPUP_STRING 20

/* This enum is used to define alert callback result. */
typedef enum
{
    MMI_PXP_ALERT_TYPE_NONE,
    MMI_PXP_ALERT_TYPE_DISCONNECTED,
    MMI_PXP_ALERT_TYPE_FIND_DEVICE,
    MMI_PXP_ALERT_TYPE_OUT_IN_RANGE,
    MMI_PXP_ALERT_TYPE_TOTAL_NUM
} mmi_pxp_alert_type_enum;

/* This enum is used to define alert level. */
typedef enum
{
    MMI_PXP_ALERT_LEVEL_NO,
    MMI_PXP_ALERT_LEVEL_MILD,
    MMI_PXP_ALERT_LEVEL_HIGH,
    MMI_PXP_ALERT_LEVEL_TOTAL_NUM
} mmi_pxp_alert_level_enum;

/* This enum is used to define app main context. */
typedef struct
{
    MMI_BOOL is_popuping;   /*is alert popup or not*/
    MMI_BOOL is_alerting;   /*is alerting or not*/
	MMI_BOOL is_config_alert; /*is config pxp or not*/
	U16      image_id;      /*is alert type icon*/
	mmi_pxp_alert_level_enum pxp_lls_alert_level;  /*lls alert level*/
	mmi_pxp_alert_type_enum pxp_alert_type;   /*alert service type*/
} mmi_pxp_app_context_struct;

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_launch
 * DESCRIPTION
 *  launch point of pxpapp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pxpapp_launch_enter_popup(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_grp_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
extern MMI_RET mmi_pxpapp_grp_proc(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_connection_state_cb
 * DESCRIPTION
 *  to notify reporter current connection state
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [state] Profile current connection state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_connection_state_cb(char* bdaddr, int connect_state);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_config_level_alert
 * DESCRIPTION
 *  to notify reporter mmi task link loss alert level config result
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [level] alert level of LLS 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_config_level_alert(char* bdaddr,U8 alert_level );

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_alert_notify_cb
 * DESCRIPTION
 *  to notify reporter mmi task start/stop path loss alert
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [level] alert level of IAS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_alert_notify_cb(char* bdaddr, U8 alert_level);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_lls_config_alert
 * DESCRIPTION
 *  to enable reporter 's  link loss alert
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_lls_config_alert(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_lls_config_alert_disable
 * DESCRIPTION
 *  to disable reporter 's  link loss alert config
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_lls_config_alert_disable(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_entry_notification_screen
 * DESCRIPTION
 *  alert popup of LLS/IAS alert
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_entry_notification_screen(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_exit_notification_screen
 * DESCRIPTION
 *  to close alert popup of LLS/IAS alert
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of profile enable result
 *****************************************************************************/
void mmi_pxpapp_exit_notification_screen(void);
void mmi_pxpapp_exit_notification_screen_proc(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_create_cntx
 * DESCRIPTION
 *  create cntx struct
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of profile enable result
 *****************************************************************************/
void mmi_pxpapp_create_cntx(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_free_cntx
 * DESCRIPTION
 *  free cntx struct
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of profile enable result
 *****************************************************************************/
void mmi_pxpapp_free_cntx(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_pen_up_hdlr
 * DESCRIPTION
 *  handle pen up event
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_pen_up_hdlr(mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_pen_empty_hdlr
 * DESCRIPTION
 *  dummy scrren
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_pen_empty_hdlr(mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_alert_sreen_show
 * DESCRIPTION
 *  to draw screen of  alert
 * PARAMETERS
 *  [evt]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_alert_sreen_show(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_show_button_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_pxpapp_show_button_str(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_show_button_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_pxpapp_show_button_normal(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_pen_down_hdlr
 * DESCRIPTION
 *  dummy scrren
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_pen_down_hdlr(mmi_pen_point_struct pos);
/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_pen_move_hdlr(mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_target_alert_enable
 * DESCRIPTION
 *  Display notification popup and play alarm tone when LLS or ALS come.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_target_alert_enable(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_target_alert_disable
 * DESCRIPTION
 *  to stop alert and light off the screen and stop ringing
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_target_alert_disable(void);

#if 0
/* under construction !*/
#ifdef __MMI_BLE_LOW_POWER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif /*if 0*/
/* under construction !*/
#endif /* __MMI_BLE_LOW_POWER__*/
/* under construction !*/
#endif /*if 0*/



#endif /*__MMI_BLE_PXP_SUPPORT__*/

/* DOM-NOT_FOR_SDK-END */

#endif /* PXPAPP_PROT_H */

