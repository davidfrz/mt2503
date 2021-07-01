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
 *   MMISymbolArray.c
 *
 * Project:
 * --------
 *   IOT
 *
 * Description:
 * ------------
 *   MMI symbol used by main bin
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "kal_general_types.h"
#include "syscomp_config.h"
#include "MMI_features.h"
#include "custom_ubconfig.h"

#if defined(__HOTKNOT_SUPPORT__) && defined(__MTK_TARGET__)
#include "BtcmSrvGprot.h"
#endif

#if defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
#include "ohrm.h"
#include "ppg_control.h"
extern void sensor_ubin_region_init(void);
#endif

/*****************************************************************************
* Extern Function
*****************************************************************************/

extern kal_bool srv_mode_switch_is_network_service_available(void);
extern kal_uint32 MMIGetGDIShowFullScreenTime(void);
extern kal_bool brt_create(comptask_handler_struct **handle);
extern kal_bool bt_create(comptask_handler_struct **handle);
extern kal_bool gdc_create(comptask_handler_struct **handle);
extern kal_bool mmi_create(comptask_handler_struct **handle);
extern kal_bool gdi_create_task(comptask_handler_struct **handle);
extern kal_bool gdd_create(comptask_handler_struct **handle);
extern kal_bool app_relay_create(comptask_handler_struct **handle);
extern kal_bool app_task_create(comptask_handler_struct **handle);
extern kal_bool vm_task_create(comptask_handler_struct **handle);
extern void InitializeResourceVariables(void);
extern void MMICheckDiskDisplay(void);
extern void MMICheckDiskDisplay_bootup(void);
extern kal_char* ubin_build_date_time(void);
#if defined(__HOTKNOT_SUPPORT__) && defined(__MTK_TARGET__)
extern srv_bt_cm_dev_struct* srv_bt_cm_get_host_dev_info(void);
#endif
#ifdef __MTK_TARGET__
#if !defined (__UPDATE_BINARY_FILE_DUMMY_BUILD__)
extern kal_uint32 custom_query_dynamic_DC_ZI_MMIPOOL_region_internal(EXTSRAM_REGION_INFO_T* region);
extern kal_uint32 custom_query_ubin_dump_region_internal(EXTSRAM_REGION_INFO_T* region);
#endif
extern void INT_InitRegions_for_ubin(void);
#endif

/****************************************************************************
 * Define
 ****************************************************************************/


/****************************************************************************
 * Global context
 ****************************************************************************/

#pragma arm section code = "MMISYMBOLARRAY_ROCODE", rodata = "MMISYMBOLARRAY_RODATA"


const void* const mmiSymbolArray[] =
{
#if defined(__MMI_TELEPHONY_SUPPORT__)
    (void *)srv_mode_switch_is_network_service_available,
#else
    (void *)0,
#endif

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)MMIGetGDIShowFullScreenTime,
#else
    (void *)0,
#endif

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)InitializeResourceVariables,
#else
    (void *)0,
#endif

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)MMICheckDiskDisplay,
#else
    (void *)0,
#endif

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(__IOT__) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__) && defined(__ZIMAGE_SUPPORT__)
    (void *)MMICheckDiskDisplay_bootup,
#else
	(void *)0,
#endif

#if defined(__BRT_SUPPORT__) && !defined(__UPDATE_PKG_MMI_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)brt_create,
#else
    (void *)0,
#endif

#if defined(__BTMTK__) && !defined(__UPDATE_PKG_MMI_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)bt_create,
#else
    (void *)0,
#endif

#if !defined(WISDOM_MMI) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)mmi_create,
#else
    (void *)0,
#endif

#if defined(__LCD_SUPPORT__) && !defined(__FWUI_NOT_PRESENT__) && (defined(PLUTO_MMI) || defined(COSMOS_MMI)) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)gdi_create_task,
#else
    (void *)0,
#endif

#if defined(__LCD_SUPPORT__) && !defined(__FWUI_NOT_PRESENT__) && defined(PLUTO_MMI) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)gdc_create,
    (void *)gdd_create,
#else
    (void *)0,
    (void *)0,
#endif

#if defined(__MULTI_THREAD_SUPPORT__) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)app_relay_create,
    (void *)app_task_create,
#else
    (void *)0,
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__)
    #if !defined (__UPDATE_BINARY_FILE_DUMMY_BUILD__)
        (void *)custom_query_ubin_dump_region_internal,
        (void *)custom_query_dynamic_DC_ZI_MMIPOOL_region_internal,
    #else
        (void *)0,
        (void *)0,
    #endif
	  (void *)INT_InitRegions_for_ubin,
#else
	(void *)0,
	(void *)0,
	(void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__)
    (void *)ubin_build_date_time,
#else    
    (void *)0,
#endif

#ifdef __LINKIT_HIGH_PRIORITY_TASK_SUPPORT__
	(void *)vm_task_create,
#else
	(void *)0,
#endif

/* separate bin FOTA for sensor algorithm,  <begin> */
#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)sensor_ubin_region_init,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ppg_control_init,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ppg_control_set_app,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ppg_control_process,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ppg_control_get_version,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ppg_control_get_status,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ohrm_init,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ohrm_process,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ohrm_get_bpm,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ohrm_get_time,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ohrm_get_confidence_level,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)ohrm_get_version,
#else
    (void *)0,
#endif

#if defined(__MTK_TARGET__) && defined(__UPDATE_BINARY_FILE__) && defined(__UPDATE_PKG_SENSOR_ONLY__)
    (void *)0, // ohrm_set_mode, not defined in sensor_algo
#else
    (void *)0,
#endif
/* separate bin FOTA for sensor algorithm,  <end> */


#if defined(__HOTKNOT_SUPPORT__) && defined(__MTK_TARGET__)
	(void *) srv_bt_cm_get_host_dev_info,
#else
	(void *)0,
#endif

    (void *)0
};
#pragma arm section code,rodata

/****************************************************************************
 * Function UBIN_mmi_symbol_DummyReference
 ****************************************************************************/
kal_uint32 UBIN_mmi_symbol_DummyReference()
{
	kal_uint32 size = 0;
	size += (kal_uint32)(&mmiSymbolArray);
	return size;
}

