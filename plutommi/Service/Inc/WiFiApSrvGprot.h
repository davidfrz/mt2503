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
 *  WiFiApSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * Wi-Fi ap mode service global prototype header.
 *
 * Author:
 * -------
 *    
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
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifdef __IOT__
#ifndef __WIFI_AP_SRV_GPROT_H__
#define __WIFI_AP_SRV_GPROT_H__

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMIDataType.h"

/****************************************************************************
* Define
*****************************************************************************/
#define SRV_CONFIG_AP_MODE_MAX_SSID_LEN       (32 + 1)
#define SRV_CONFIG_AP_MODE_MAX_PSK_LEN        (63 + 1)

/* AP mode status enum */
typedef enum
{
    SRV_APMODE_OK              = 0,           /* activate success */
    SRV_APMODE_UNKNOWN_ERROR     = -999,      
    SRV_APMODE_FAILED, 
    SRV_APMODE_CANCELLED,
    SRV_APMODE_BUSY
} srv_apmode_reslut;

/* custom apmode config enum */
typedef enum
{
    SRV_CONFIG_APMODE_PARA_AUTH_MODE    = 0x00000001, /* AP mode */
    SRV_CONFIG_APMODE_PARA_SSID         = 0x00000002, /* AP mode */
    SRV_CONFIG_APMODE_PARA_PSK          = 0x00000004, /* AP mode */
    
    SRV_CONFIG_APMODE_PARA_ALL          = SRV_CONFIG_APMODE_PARA_AUTH_MODE |
                                          SRV_CONFIG_APMODE_PARA_SSID |  
                                          SRV_CONFIG_APMODE_PARA_PSK, /*All parameter */
    /* add */
} srv_apmode_config_para_enum;

/****************************************************************************
* Structure
*****************************************************************************/
typedef struct 
{
    /* AP mode info */    
    kal_uint16 auth_mode;
    kal_int8 ssid[SRV_CONFIG_AP_MODE_MAX_SSID_LEN];
    kal_int8 psk[SRV_CONFIG_AP_MODE_MAX_PSK_LEN];

    /* add */
}srv_apmode_config_struct; /* must same as nvram_ef_apmode_config_struct */

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_apmode_switch_cb_funcptr_type
 * DESCRIPTION
 *  ap mode service callback function type which notify app the switching result.
 * PARAMETERS
 *  result:             [IN] Operation result
 *  user_data:          [IN] User data
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_apmode_switch_cb_funcptr_type)(
                S32 result,  // srv_apmode_result
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_apmode_is_on
 * DESCRIPTION
 *  Function of checking ap mode is activated.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: Ap mode is activated
 *  MMI_FALSE: Ap mode is not activated (maybe on switching)
 *****************************************************************************/
extern MMI_BOOL srv_apmode_is_on(void);


/*****************************************************************************
 * FUNCTION
 *  srv_apmode_switch_on
 * DESCRIPTION
 *  Function for application to switch on ap mode.
 * PARAMETERS
 *  funcptr:            [IN] Callback function pointer
 *  user_data:          [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_apmode_switch_on(
                srv_apmode_switch_cb_funcptr_type funcptr,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_apmode_switch_off
 * DESCRIPTION
 *  Function for application to switch off ap mode.
 * PARAMETERS
 *  funcptr:            [IN] Callback function pointer
 *  user_data:          [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_apmode_switch_off(
                srv_apmode_switch_cb_funcptr_type funcptr,
                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_apmode_config_set_para
 * DESCRIPTION
 *  Function for application to set parameter.
 * PARAMETERS
 *  para:            [IN] configure data
 *  flag:            [IN] which data need to set
 * RETURNS
 *  MMI_TRUE: set parameter success
 *  MMI_FALSE: set parameter fail
 *****************************************************************************/
extern MMI_BOOL srv_apmode_config_set_para(
                    srv_apmode_config_struct *para, 
                    srv_apmode_config_para_enum flag);


/*****************************************************************************
 * FUNCTION
 *  srv_apmode_config_get_para
 * DESCRIPTION
 *  Function for application to get parameter.
 * PARAMETERS
 *  para:             [OUT] return configure data to Application
 * RETURNS
 *  MMI_TRUE: get parameter success
 *  MMI_FALSE: get parameter fail
 *****************************************************************************/
extern MMI_BOOL srv_apmode_config_get_para(
                    srv_apmode_config_struct *para);

#endif /* __WIFI_AP_SRV_GPROT_H__ */
#endif /* __IOT__ */
