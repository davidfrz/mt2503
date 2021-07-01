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
 *  FmpAppGprot.h
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
 * removed!
 * removed!
 * removed!
 *
  *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SOGP_ADP_SRV_GPROT_H
#define SOGP_ADP_SRV_GPROT_H

/****************************************************************************
 * Header
 ****************************************************************************/
#include "MMI_features.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* auto add by kw_check end */
//#include "FmplSrv.h"

				 
//#ifdef __MMI_SRV_BT_SOGPS_PROFILE__


typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;
	MMI_BOOL result;
	srv_bt_cm_bt_addr bt_addr;	
}srv_sogps_adp_connect_ind_struct;

typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;	
	MMI_BOOL result;
    srv_bt_cm_bt_addr bt_addr;
}srv_sogps_adp_disconnect_ind_struct;

typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;	
	MMI_BOOL result;
	srv_bt_cm_bt_addr bt_addr;	
}srv_sogps_adp_ready_to_read_ind_struct;

typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;	
	MMI_BOOL result;
	srv_bt_cm_bt_addr bt_addr;	
}srv_sogps_adp_ready_to_write_ind_struct;

typedef enum
{
	CONNECT_DEVICE_TYPE_NONE,
	CONNECT_DEVICE_TYPE_ANDROID,
	CONNECT_DEVICE_TYPE_IOS
}CONN_DEV_TYPE_ENUM;


U32 srv_sogps_adp_read(U32 conn_id, void* buf, U32 size);

//U32 srv_sogps_adp_write_ext(U32 conn_id, void* buf, U32 len, S32 *err_code);
S32 srv_sogps_adp_write_ext(U32 conn_id, srv_bt_cm_bt_addr* bt_addr, void* buf, U32 len, S32 *err_code);

void srv_sogps_adp_write_remote_device_type(CONN_DEV_TYPE_ENUM dev_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_to_init
 * DESCRIPTION
 *  This function is to rigister fmp profile servers CBs
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_on_init_sogps(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_to_deinit
 * DESCRIPTION
 *  This function is to derigister fmp profile servers CBs
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_on_deinit_sogps(void);

//#endif /*__MMI_SRV_BT_SOGPS_PROFILE__ */

/* DOM-NOT_FOR_SDK-END */

#endif /* SOGP_ADP_SRV_GPROT_H */

