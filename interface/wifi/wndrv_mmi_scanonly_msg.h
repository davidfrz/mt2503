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
 *============================================================================
 ****************************************************************************/
#ifndef _WNDRV_MMI_SCANONLY_MSG_H
#define _WNDRV_MMI_SCANONLY_MSG_H

#include "kal_general_types.h"

typedef enum
{  
   SCANONLY_SUCCESS = 0,
   
   SCANONLY_INIT_BUSY_IS_INITING= 1,
   SCANONLY_INIT_FAIL__ALREAD_INITED,
   SCANONLY_INIT_FAIL__DRIVER_REASON,
   SCANONLY_INIT_FAIL__UNKOWN,

   SCANONLY_DEINIT_BUSY__IS_DEINITING = 10,
   SCANONLY_DEINIT_FAIL__ALREAD_DEINITED,
   SCANONLY_DEINIT_FAIL__DRIVER_REASON,
   SCANONLY_DEINIT_FAIL__UNKOWN,

   SCANONLY_SCAN_BUSY__IS_SCANNING = 20,
   SCANONLY_SCAN_FAIL__NOT_INITED,
   SCANONLY_SCAN_FAIL__DRIVER_REASON,
   SCANONLY_SCAN_FAIL__UNKOWN,
   
   SCANONLY_STATUS_END
} SCANONLY_STATUS_ENUM;

#define SCANONLY_MAX_SCAN_AP_NUM			30
#define SCANONLY_MAC_ADDRESS_LEN	    	6
#define SCANONLY_SSID_MAX_LEN				32

typedef void (*scanonly_wndrv_mmi_callback_func_ptr) (void * /*user_data*/, void* /*data  out to callerS*/);
typedef void  *scanonly_wndrv_mmi_user_data_ptr;

typedef struct
{
   kal_uint8                           	ref_count;
   kal_uint16                          	msg_len;
   scanonly_wndrv_mmi_callback_func_ptr	init_cb;
   scanonly_wndrv_mmi_user_data_ptr		init_userdata;
} wndrv_mmi_scanonly_init_req_struct;

typedef struct
{
   kal_uint8                           	ref_count;
   kal_uint16                          	msg_len;
   scanonly_wndrv_mmi_callback_func_ptr	init_cb;
   scanonly_wndrv_mmi_user_data_ptr		init_userdata;
   SCANONLY_STATUS_ENUM				   	status;
} wndrv_mmi_scanonly_init_cnf_struct;


typedef struct
{
   kal_uint8                           	ref_count;
   kal_uint16                          	msg_len;
   scanonly_wndrv_mmi_callback_func_ptr	deinit_cb;
   scanonly_wndrv_mmi_user_data_ptr		deinit_userdata;
} wndrv_mmi_scanonly_deinit_req_struct;

typedef struct
{
   kal_uint8                           	ref_count;
   kal_uint16                          	msg_len;
   scanonly_wndrv_mmi_callback_func_ptr	deinit_cb;
   scanonly_wndrv_mmi_user_data_ptr		deinit_userdata;
   SCANONLY_STATUS_ENUM			       	status;
} wndrv_mmi_scanonly_deinit_cnf_struct;


typedef struct
{
   kal_uint8                           	ref_count;
   kal_uint16                         	msg_len;
   kal_uint8							scantype; //0:passive scan, other: active scan
   scanonly_wndrv_mmi_callback_func_ptr	scan_cb;
   scanonly_wndrv_mmi_user_data_ptr		scan_userdata;
} wndrv_mmi_scanonly_scan_req_struct;

typedef struct scanonly_scan_ap_info_struct
{    
  kal_uint8                      		bssid[ SCANONLY_MAC_ADDRESS_LEN ];
  kal_uint8                       		ssid_len;
  kal_uint8                       		ssid [ SCANONLY_SSID_MAX_LEN ];    
  kal_int8                        		rssi;                           
  kal_uint8                       		channel_number;    
} scanonly_scan_ap_info_struct;
typedef struct
{
   kal_uint8                      		ref_count;
   kal_uint16                     		msg_len;
   scanonly_wndrv_mmi_callback_func_ptr	scan_cb;
   scanonly_wndrv_mmi_user_data_ptr		scan_userdata;
   SCANONLY_STATUS_ENUM			  		status;
   kal_uint8                      		scan_ap_num;
   scanonly_scan_ap_info_struct     	scan_ap[ SCANONLY_MAX_SCAN_AP_NUM ];
} wndrv_mmi_scanonly_scan_ind_struct;

#endif /* _WNDRV_MMI_SCANONLY_MSG_H*/

