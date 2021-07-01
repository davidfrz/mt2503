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
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "kal_general_types.h"
#include "syscomp_config.h"
#include "MMI_features.h"

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
extern void InitializeResourceVariables(void);
extern void MMICheckDiskDisplay(void);
extern void MMICheckDiskDisplay_bootup(void);

/****************************************************************************
 * Define
 ****************************************************************************/


/****************************************************************************
 * Global context
 ****************************************************************************/

const void* mmiSymbolArray[] =
{
#if defined(__MMI_TELEPHONY_SUPPORT__)
    (void *)srv_mode_switch_is_network_service_available,
#else
    (void *)0,
#endif
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    (void *)MMIGetGDIShowFullScreenTime,
#else
    (void *)0,
#endif
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    (void *)InitializeResourceVariables,
#else
    (void *)0,
#endif
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    (void *)MMICheckDiskDisplay,
#else
    (void *)0,
#endif
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(__IOT__)
    (void *)MMICheckDiskDisplay_bootup,
#else
	(void *)0,
#endif
#if defined(__BRT_SUPPORT__)
    (void *)brt_create,
#else
    (void *)0,
#endif
#if defined(__BTMTK__)
    (void *)bt_create,
#else
    (void *)0,
#endif
#if !defined(WISDOM_MMI)
    (void *)mmi_create,
#else
/* under construction !*/
#endif
#if defined(__LCD_SUPPORT__) && !defined(__FWUI_NOT_PRESENT__) && (defined(PLUTO_MMI) || defined(COSMOS_MMI))
    (void *)gdi_create_task,
#else
    (void *)0,
#endif
#if defined(__LCD_SUPPORT__) && !defined(__FWUI_NOT_PRESENT__) && defined(PLUTO_MMI)
    (void *)gdc_create,
    (void *)gdd_create,
#else
    (void *)0,
    (void *)0,
#endif
#ifdef __MULTI_THREAD_SUPPORT__
    (void *)app_relay_create,
    (void *)app_task_create,
#else
    (void *)0,
    (void *)0,
#endif

    (void *)0
};

/****************************************************************************
 * Function
 ****************************************************************************/

