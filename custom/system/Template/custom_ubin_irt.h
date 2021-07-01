/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_ubin_irt.h
 *
 * Project:
 * --------
 *   IOT
 *
 * Description:
 * ------------
 *   This file provides symbol offset to access UBIN's symbol array
 *   IRT = Indirect Reference Table
 *
 * Author:
 * -------
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef _CUSTOM_UBIN_IRT_H
#define _CUSTOM_UBIN_IRT_H

typedef enum
{
    /* The position should match to mmiSymbolArray[] */
    UBIN_SYMBOL_IS_NETSRV_AVAIL,  // srv_mode_switch_is_network_service_available()
    UBIN_SYMBOL_GET_GDI_SHOW_FULL_SCREEN_TIME,
    UBIN_SYMBOL_INIT_RESOURCE_VARS,  // InitializeResourceVariables()
    UBIN_SYMBOL_MMI_CHECK_DISPLY,  // MMICheckDiskDisplay()
	UBIN_SYMBOL_MMI_CHECK_DISPLY_BOOTUP,  // MMICheckDiskDisplay_bootup()
    UBIN_SYMBOL_ENTRY_BRT, //(void *)brt_create,
    UBIN_SYMBOL_ENTRY_BT,  //(void *)bt_create,
    UBIN_SYMBOL_ENTRY_MMI, //(void *)mmi_create,
    UBIN_SYMBOL_ENTRY_GDI, //(void *)gdi_create_task,
    UBIN_SYMBOL_ENTRY_GDC, //(void *)gdc_create,
    UBIN_SYMBOL_ENTRY_GDD, //(void *)gdd_create,
    UBIN_SYMBOL_ENTRY_MMI_RELAY, //(void *)app_relay_create,
    UBIN_SYMBOL_ENTRY_APP_THREAD, //(void *)app_task_create,
    UBIN_SYMBOL_CUSTOM_QUERY_UBIN_DUMP_REGION, //(void *)custom_query_ubin_dump_region
    UBIN_SYMBOL_CUSTOM_QUERY_DYNAMIC_DC_ZI_MMIPOOL_REGION,//custom_query_dynamic_DC_ZI_MMIPOOL_region()
    UBIN_SYMBOL_UBIN_REGION_INIT,
    UBIN_SYMBOL_UBIN_BUILD_DATE_TIME,
    UBIN_SYMBOL_ENTRY_LINKIT_TASK, //(void *)vm_task_create,
    UBIN_SYMBOL_ENTRY_SENSOR,  //(void *)SNRSUBSYS_create
    UBIN_SYMBOL_PPG_CONTROL_INIT,  //(void *)ppg_control_init,
    UBIN_SYMBOL_PPG_CONTROL_SET_APP, //(void *)ppg_control_set_app,
    UBIN_SYMBOL_PPG_CONTROL_PROCESS, //(void *)ppg_control_process,
    UBIN_SYMBOL_PPG_CONTROL_GET_VERSION, //(void *)ppg_control_get_version,
    UBIN_SYMBOL_PPG_CONTROL_GET_STATUS,  //(void *)ppg_control_get_status,
    UBIN_SYMBOL_OHRM_INIT,  //(void *)ohrm_init,
    UBIN_SYMBOL_OHRM_PROCESS,  //(void *)ohrm_process,
    UBIN_SYMBOL_OHRM_GET_BPM,  //(void *)ohrm_get_bpm,
    UBIN_SYMBOL_OHRM_GET_TIME,  //(void *)ohrm_get_time,
    UBIN_SYMBOL_OHRM_GET_CONFIDENCE_LEVEL,  //(void *)ohrm_get_confidence_level,
    UBIN_SYMBOL_OHRM_GET_VERSION,  //(void *)ohrm_get_version,
    UBIN_SYMBOL_OHRM_SET_MODE,  //(void *)ohrm_set_mode,

    UBIN_SYMBOL_TOTAL
} ubin_symbol_entry_enum;

typedef enum {
    ENTRY_NULL,
    
    
    
    
    
    
}task_entry_type;

#endif /* _CUSTOM_UBIN_IRT_H */

