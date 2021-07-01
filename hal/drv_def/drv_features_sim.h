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
 *    drv_features_option.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all driver feature options.
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
 * removed!
 *
 * removed!
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
 * removed!
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_SIM_H__
#define __DRV_FEATURES_SIM_H__

#include "drv_features_chip_select.h"

#if defined(DRV_SIM_6575_SERIES) || defined(DRV_SIM_6256_SERIES) || defined(DRV_SIM_6250_SERIES)
#define DRV_2_SIM_CONTROLLER

/*storage cached transfer support*/
#define SIM_CACHED_SUPPORT

#define SIM_TOUT_REG_V2
#endif

#if defined(DRV_SIM_6575_SERIES) || defined(DRV_SIM_6256_SERIES)
/*76/56/75/73/55 new platform use DMA_Flush, other platform use DMA_Stop */
#define DRV_SIM_DMA_V2
#endif

#if defined(DRV_SIM_6575_SERIES)
#define SIM_NAMING_FROM_0_ADDRESS //MT6575 is naming in SIM0, SIM1,..
#endif

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
#endif

#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
#define SIM_CACHED_SUPPORT
#endif

#if defined(__WRITE_THROUGH_CACHEABLE__)                   
/* under construction !*/
/* under construction !*/
#endif

/**************** SIM ******************/
#if ( (!defined(DRV_SIM_MT6208_SERIES)) && (!defined(DRV_SIM_DMA_6218B)) && (!defined(DRV_SIM_MT6205B_SERIES)))
//#define DRV_SIM_SPEED16
#endif

//#if defined(MT6575) || defined(MT6256) || defined(MT6255) || defined(DRV_SIM_6250_SERIES) || defined(MT6573) || defined(MT6276)
// we use reverse method to list not support platform
#if ( (!defined(MT6236)) && (!defined(MT6235)) && (!defined(MT6235B)) && (!defined(MT6253)) && (!defined(MT6253D)) && (!defined(MT6252)))
#ifdef NO_SLIM_DEF
#define DRV_SIM_HIGH_SPEED
#endif
#endif


#if defined( __SMART_PHONE_MODEM__) && defined(MT6516)
#define DUAL_MCU_SIM_V1
#endif

#ifdef LOW_COST_SUPPORT

#if defined(__LOW_COST_SUPPORT_ULC__)
#define DRV_SIM_DBG_LOW_COST_ULC
#elif defined(__LOW_COST_SUPPORT_COMMON__)
#define DRV_SIM_DBG_LOW_COST_COMMON
#endif

#endif

#ifdef IC_BURNIN_TEST
/*remove following line so that the OLT load of all new chips will include the option*/
//#if defined(MT6268_EVB) || defined(MT6253_EVB) || defined(MT6236) || defined(MT6236B) || defined(MT6253D_EVB)
#define DRV_SIM_BT
#define SIM_DVT_REG_TEST
//#endif

#endif

#define SIM_REMOVE_ATR_ASSERT
#define DRV_SIM_RETRY_3V_ON_PTS_ERROR
#define DRV_SIM_RETRY_18V_ONLY_USIM_ON_PTS_ERROR


#if (defined(MT6235B) || defined(MT6238) || defined(MT6239)|| defined(MT6516) || defined(MT6253T) || defined(MT6253) || defined(MT6268A) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6573) || defined(MT6276) || defined(MT6252) || defined(MT6252H) || defined(MT6251) || defined(MT6256) || defined(MT6255) || defined(DRV_SIM_6250_SERIES) || defined(MT6280))
#define SIM_DRV_MTK_INTERFACE_NUM	2
#elif defined(DRV_2_SIM_CONTROLLER)
#define SIM_DRV_MTK_INTERFACE_NUM	2
#else
#define SIM_DRV_MTK_INTERFACE_NUM	1
#endif

#if defined(MT6276) || defined(MT6573) || defined(MT6256) || defined(MT6253E) || defined(MT6252) || defined(MT6252H) || defined(MT6251)|| defined(MT6236)|| defined(MT6236B) || defined(MT6235) || defined(MT6253) || defined(MT6253D) || defined(MT6255) || defined(DRV_SIM_6250_SERIES) || defined(MT6280)
#define __DRV_SIM_SIMIF_CONTROL_VSIM__
#endif

#if defined(MT6276) || defined(MT6256) || defined(MT6575) || defined(MT6255) || defined(DRV_SIM_6250_SERIES) || defined(MT6280)
/* 76/75/56, TOUT register's unit is 16 etu, other platform is 4 etu */
#define SIM_TOUT_REG_V3
#endif

#define SIM_ACTIVATE_BY_PTS_ERROR

//from now on, we use dcl_sim_interface for all SW load
#define DCL_SIM_INTERFACE
#define __SIM_DRV_MULTI_DRV_ARCH__


#if (defined(MT6276)) || (defined(MT6573) )
/* This flag is only defined for 76/73. It is HW bug. The root cause is that VSIM(1.8V/3V) do not
   output from PMU or SIMIF, but control by another register. This bug is found by violet */
#define DRV_SIM_VSIM2_ISSUE_76_SERIES
#endif

#if defined(MT6276)
#define __DRV_SIM_DMA_TX2RX__
#endif

#ifdef __MEUT__
#define __SIM_DRV_MULTI_DRV_ARCH__
#define DCL_SIM_INTERFACE
#endif


#ifdef __SIM_DRV_MULTI_DRV_ARCH__
#define DRV_SIM_ALL_SOLUTION_BUILT
#endif

/*following definitions are from Gemini+*/
#define	SIM_MT6302_MAX_MT6302		2
#define DRV_SIM_MAX_LOGICAL_INTERFACE	4  //this is the maximum logical SIM interface number, logical interface is the SIM card seen by SIM task

#ifdef __SIM_DRV_SWITCH_MT6306__
#define SIM_DRV_SWITCH_MT6306
#endif

#ifdef __SIM_DRV_SWITCH_MT6302__
#define SIM_DRV_SWITCH_MT6302
#endif

#if defined (DRV_SIM_6250_SERIES)
#define SIM_ENABLE_DIE_TO_DIE_IF
#endif

#if defined(MT6236) || defined(MT6253) || defined(MT6253D) || defined(MT6236B) || defined(MT6235B) || defined(MT6256) || defined(MT6255)|| defined(DRV_SIM_6250_SERIES)
#define SIM_FTA_MT6306_DISABLE_PH_RESISTOR
#endif

#if defined(MT6583) || defined(MT6589) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define LPWR_SLIM
#endif

//#define SIM_DEBUG_INFO 1
#endif /*ifndef __DRV_FEATURES_SIM_H__*/
