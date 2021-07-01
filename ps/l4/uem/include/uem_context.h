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
 * uem_context.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for UEM module data.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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

#ifndef _UEM_CONTEXT_H
#define _UEM_CONTEXT_H

#include "kal_general_types.h"
#include "nvram_editor_data_item.h"
#include "dcl.h"

/***************************************************************************** 
* Enable function 
*****************************************************************************/
#ifndef _VOICE_MEMO
// #define  _VOICE_MEMO
#endif 

#ifndef _PMIC_FUNC
// #define  _PMIC_FUNC
#endif 

#ifndef _UEM_DEBUG
// #define _UEM_DEBUG
#endif 

/***************************************************************************** 
* UEM Debug Usage
*****************************************************************************/
#ifdef _UEM_DEBUG

#define UEM_DEBUG_LEN         50

#define UEM_FN_ENTRY_LOG( X, Y )
#define UEM_FN_EXIT_LOG( X, Y )

#define UEM_FUNC_ENTRY( X )   kal_print(X)
#define UEM_FUNC_ENTRY_P1(X, I1)                            \
   {                                                        \
      kal_uint8   temp_string[UEM_DEBUG_LEN];               \
      kal_sprintf((kal_char *)temp_string, X, I1);          \
      kal_print((kal_char *)temp_string);                   \
   }
#define UEM_FUNC_ENTRY_P2(X, I1, I2)                                          \
   {                                                                          \
      kal_uint8   temp_string[UEM_DEBUG_LEN];                                 \
      kal_sprintf((kal_char *)temp_string, (const kal_char *)X, I1, I2);      \
      kal_print((kal_char *)temp_string);                                     \
   }
#define UEM_FUNC_ENTRY_P3(X, I1, I2, I3)                                      \
   {                                                                          \
      kal_uint8   temp_string[UEM_DEBUG_LEN];                                 \
      kal_sprintf((kal_char *)temp_string, (const kal_char *)X, I1, I2, I3);  \
      kal_print((kal_char *)temp_string);                                     \
   }
#else /* _UEM_DEBUG */ 
#define UEM_FN_ENTRY_LOG( X, Y )
#define UEM_FN_EXIT_LOG( X, Y )
#define UEM_FUNC_ENTRY( X )
#define UEM_FUNC_ENTRY_P1(X, I1)
#define UEM_FUNC_ENTRY_P2(X, I1, I2)
#define UEM_FUNC_ENTRY_P3(X, I1, I2, I3)
#endif /* _UEM_DEBUG */ 

/***************************************************************************** 
* UEM Context
*****************************************************************************/
typedef enum
{
    UEM_STATE_UNINIT,
    UEM_STATE_INIT,
    UEM_STATE_NOTIFY_POWER_ON,
    UEM_STATE_STARTUP,
    UEM_STATE_READY
} uem_status_enum;

/* Note: the flag (variable) type is kal_uint8, be careful UEM_ACCESSORY_TYPE_MAX > 8 */
typedef enum
{
    UEM_ACCESSORY_TYPE_NONE = 0,
    UEM_ACCESSORY_TYPE_CHARGER,
    UEM_ACCESSORY_TYPE_USB_CHARGER,
    UEM_ACCESSORY_TYPE_USB,
    UEM_ACCESSORY_TYPE_TVOUT,
    UEM_ACCESSORY_TYPE_CLAM,    
    UEM_ACCESSORY_TYPE_MAX
} uem_accessory_status_enum;

#if defined(__SMART_PHONE_MODEM__)
typedef enum {
    UEM_CCCI_EM_REQ_GET_SLEEP_MODE  = 0 ,
    UEM_CCCI_EM_REQ_SET_SLEEP_MODE ,
    UEM_CCCI_EM_REQ_GET_DCM_MODE , 
    UEM_CCCI_EM_REQ_SET_DCM_MODE , 
    UEM_CCCI_EM_REQ_GET_MEMDUMP ,
    UEM_CCCI_EM_REQ_SET_MEMDUMP ,
    UEM_CCCI_EM_REQ_GET_UART,
    UEM_CCCI_EM_REQ_SET_UART,
    UEM_CCCI_EM_REQ_POWER_SCAN_REQ
} UEM_CCCI_EM_REQ_EVENT_TYPE;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 buff_id;
    kal_uint32 reserved;
} uem_ccci_em_req_struct;
#endif /* __SMART_PHONE_MODEM__ */

typedef enum {
    UEM_CCCI_EM_UART_PORT_READ  = 0 ,
    UEM_CCCI_EM_UART_PORT_WRITE
} UEM_CCCI_EM_UART_PORT_ACT_TYPE;


typedef struct
{
    kal_uint8 status;
    kal_uint32 volt;
    double adc;
    kal_uint8 disp_level;
    kal_uint8 last_level;
    kal_uint8 hit_count;
} uem_bmt_struct;

typedef struct
{
    uem_status_enum state;
    kal_uint16 func_id;          /* for classify read/write nvram record */
    kal_uint8 cause_id;         /* ref: nvram_io_errno_enum */
    uem_bmt_struct bmt_status;
    kal_uint8 power_on_mode;
    kal_uint8 ext_dev_status;   /* ext_device_enum */
    kal_uint8 src_id;
    kal_uint8 incall_state;
    DCL_HANDLE adc_sche_id;      /* adc schedual id */
#if defined(__CLASSAB_VOLUME_PROTECTION__) || defined(__CLASSK_CP_SUPPORT__)
    DCL_HANDLE adc_med_sche_id;  /* for MED voltage check*/
#endif

#ifdef __USB_ENABLE__
    kal_uint8 usb_msg_src_id;
#endif 

    kal_uint8 acc_prev_state;   /* accessory in/out */
    kal_uint8 acc_latest_state; /* accessory prev in/out */
    kal_uint8 acc_progress;     /* accessory progress */

#ifndef PLUTO_MMI
    kal_uint8 usb_out_suspend;
#endif

    uem_context_rmi_struct rmi_data;
    uem_context_manufacture_struct manufacture_data;

    kal_bool is_usb_charing;   /* usb is charing flag */
    
    kal_bool is_charing;   /* is charing flag */
    kal_bool is_charing_complete;  
    kal_bool clam_status;  
#ifdef __CLASSK_CP_SUPPORT__
    kal_bool aud_vol_flag;
#endif
} uem_context_struct;

extern uem_context_struct *g_uem_cntx_p;

#endif /* _UEM_CONTEXT_H */ /* uem_context.h */

