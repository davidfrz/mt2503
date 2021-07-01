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
 * nvram_data_items.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
 *
 * Author:
 * -------
 * 
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
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT

#define NVRAM_FACTORY_CONFIG

#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_general_types.h"

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "nvram_data_items.h"
#include "nvram_editor_data_item.h"
#include "custom_nvram_config.h"
#include "custom_nvram_sec.h"
#include "custom_nvram_restore.h"
#include "custom_nvram_config.h"

#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
/* under construction !*/
#endif /* __UMTS_RAT__ && __MTK_UL1_FDD__ */

#ifdef __AST_TL1_TDD__
#include "tl1cal_ast.h"
#include "tl1d_custom_rf.h"
#endif // __AST_TL1_TDD__

#include "l1cal.h"

#include "adc_channel.h"

extern void nvram_get_L1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size);
extern void nvram_get_uL1_default_value_to_write(nvram_lid_enum lid, kal_uint8 * buffer, kal_uint16 buffer_size);

/**
 * Steps of defining logical data item:
 * 1> Define LID of new logical data item into `nvram_lid_core_enum' in
 *    nvram_data_items.h
 * 2> Define two constants: SIZE and TOTAL, in nvram_data_items.h
 * 3> Define default value of that new logical data item.
 * 4> Define attributes of that new logical data item into
 *    `logical_data_item_table_core'
 * 5> Change NVRAM_TOTAL_LID_VENDOR in nvram_user_defs.h
 * 6> Add structure defination in nvram_editor_data_item.h
 * 7> Add bit-level description in nvram_editor_data_item.h
 * 8> Change version number CODED_DATA_VERSION in nvram_user_config.c
 *
 * Note that multiple copied attribute DOES NOT support for
 * near fixed logical data items.
 */

/**
 * Step 3:
 * Define necessary default values for each logical data item.
 */

#ifdef __AST_TL1_TDD__
/*Nan Shen:Temp solution for fixing build error*/
extern kal_uint16 const NVRAM_EF_AST_TL1_AFC_DATA_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_PATHLOSS_33_35_37_39_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_PATHLOSS_34_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_TXDAC_33_35_37_39_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_TXDAC_34_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_ABB_CAL_DEFAULT[];
#if !defined(__AST1001__) && !defined(__AST2001__)
extern kal_uint32 const NVRAM_EF_AST_TL1_CAP_DATA_DEFAULT[];
#endif

#ifdef __TDD_RF_CUSTOM_TOOL_SUPPORT__
extern T_TD_CUSTOMIZATION_STRUCT TD_CUST_CONST    NVRAM_EF_AST_TL1_RF_PARAMETER_DEFAULT[]; 
#endif
#endif




#ifdef  __BTMODULE_MT6601__
static kal_uint8 const NVRAM_EF_BTRADIO_MT6601_DEFAULT[] = {
/* BDAddr                       ,  6 */ 0x01,0x66,0x00,0x00,0x00,0x00,
/* ClassOfDevice                ,  3 */ 0x00,0x1F,0x00,
/* LinkKeyType                  ,  1 */ 0x01,
/* UnitKey                      , 16 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* Encryption                   ,  3 */ 0x00,0x02,0x10,
/* PinCodeType                  ,  1 */ 0x00,
/* Voice                        ,  2 */ 0xAC,0x00,
/* Codec                        ,  1 */ 0x23,
/* Radio                        , 30 */ 0x02,0x01,0x7F,0x07,0x07,0x80,0x00,0x0B,0x03,
                                        0x07,
                                        0xFA,0x00,0x32,0x01,0x00,0x03,0xFF,0x16,0x07,0x17,0x01,0x35,0x7F,0x28,0x00,0x00,0x00,0x00,0x00,0x00,
#if defined(__MTK_TARGET__)
/* Sleep                        ,  6 */ 0x03,0x40,0x1F,0x40,0x1F,0x02,
#else
/* Sleep                        ,  6 */ 0x00,0x40,0x1F,0x00,0x00,0x02,
#endif
/* MainOscillatorInfo           ,  5 */ 0x01,0x01,0x14,0x0A,0x08,
/* LPOInfo                      ,  4 */ 0x01,0x04,0xFA,0x0A,
/* AFH                          ,  9 */ 0x40,0x06,0x40,0x06,0x40,0x1F,0x01,0x08,0x04,
/* PTA                          , 49 */ 0x01,0x14,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
                                        0x41,0x14,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
                                        0x21,0x14,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
                                        0x00,0x00,0x00,0x00,0x00,
                                        0xA4,0x04,0x80,0x01,0x3F,0x02,0x38,0x04,
                                        0xDC,0x0A,0x00,0x00,0xFF,0x00,0x00,0x01,0x01,
/* WDT                          ,  2 */ 0xFF,0x00,
/* Debug                        ,  1 */ 0x80,
/* UART                         ,  2 */ 0x0B,0x00
};
#endif /* __BTMODULE_MT6601__*/

#ifdef  __BTMODULE_MT6611__
static kal_uint8 const NVRAM_EF_BTRADIO_MT6611_DEFAULT[] = {
/* BDAddr                       ,  6 */ 0x11,0x66,0x00,0x00,0x00,0x00,
/* Radio Cap Id                 ,  1 */ 0x40,
/* LinkKeyType                  ,  1 */ 0x01,
/* UnitKey                      , 16 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* Encryption                   ,  3 */ 0x00,0x02,0x10,
/* PinCodeType                  ,  1 */ 0x00,
/* Voice                        ,  2 */ 0x60,0x00,
/* Codec                        ,  1 */ 0x23,
/* Radio                        , 6 */ 0x07,0x80,0x00,0x06,0x03,0x07,
#if defined(__MTK_TARGET__)
/* Sleep                        ,  7 */ 0x03,0x40,0x1F,0x40,0x1F,0x00,0x04,
#else
/* Sleep                        ,  7 */ 0x00,0x40,0x1F,0x00,0x00,0x00,0x04,
#endif
/* Reserved                      ,  2 */0x80,0x00,
};
#endif /* __BTMODULE_MT6611__*/


//#if  defined(__BTMODULE_MT6612__) || defined(__BTMODULE_MT6616__) || defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__) || defined(__BTMODULE_MT6236__) || defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6276__)
#if defined(__BTMTK__)
//6612-6616-6622-6626-6236-6256-6276-6255-6250---
#if !defined(__BTMODULE_RFMD3500__) && !defined(__BTMODULE_MT6601__) && !defined(__BTMODULE_MT6611__)
static kal_uint8 const NVRAM_EF_BTRADIO_MTK_BT_CHIP_DEFAULT[] = {
/* BDAddr                       ,  6 */ 0x00,0x66,0x00,0x00,0x00,0x00,
/* Radio Cap Id                 ,  1 */ 0xFF,
/* LinkKeyType                  ,  1 */ 0x01,
/* UnitKey                      , 16 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* Encryption                   ,  3 */ 0x00,0x02,0x10,
/* PinCodeType                  ,  1 */ 0x00,
/* Voice                        ,  2 */ 0x60,0x00,
/* Codec                        ,  1 */ 0x23,
/* Radio                        ,  6 */ 0x07,0x80,0x00,0x06,0x07,0x07,
#if defined(__MTK_TARGET__)
/* Sleep                        ,  7 */ 0x03,0x40,0x1F,0x40,0x1F,0x00,0x04,
#else
/* Sleep                        ,  7 */ 0x00,0x40,0x1F,0x00,0x00,0x00,0x04,
#endif
/* Reserved                     ,  2 */0x80,0x00,
#if  defined(__BTMODULE_MT6626__) && defined(__PHONE__)
/* ECLK_SEL                     ,  1 */0x01,
#else
/* ECLK_SEL                     ,  1 */0x00,
#endif
};
#endif

#endif

#ifdef __BCM_SUPPORT__
#if defined(PLUTO_MMI) && defined(__LOW_COST_SUPPORT_COMMON__) // SLIM:memory reduction
static kal_uint8 const NVRAM_EF_SRV_BT_CM_DEFAULT[] = {
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 'M',  'T',  'K',  'B',
'T',  'D',  'E',  'V',  'I',  'C',  'E',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#else
static kal_uint8 const NVRAM_EF_SRV_BT_CM_DEFAULT[] = {
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 'M',  'T',  'K',  'B',
'T',  'D',  'E',  'V',  'I',  'C',  'E',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
#endif  // SLIM:memory reduction


static kal_uint8 const NVRAM_EF_SRV_BT_CM_SYS_DEFAULT[] = {
    0xf0, 0x00, 0x00, 0x00,
    'M',  'T',  'K',  'B',
    'T',  'D',  'E',  'V',
    'I',  'C',  'E',  0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};
#endif  /* __BCM_SUPPORT__ */


#if defined(__WIFI_SUPPORT__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)

#include "wndrv_cal.h"
#include "wifi_common_config.h"
extern wndrv_cal_mac_addr_struct wndrv_default_mac_addr;

#if defined(WIFI_BB_MT5911)
    #if defined( WIFI_RF_AL2236 )
extern const wndrv_cal_txpwr_2400M_struct wndrv_default_txpwr_2400M;
   #else
extern const wndrv_cal_txpwr_2400M_struct wndrv_default_txpwr_2400M;
    #endif
//20081110 add by saker for MT5921 support
#elif defined(WIFI_BB_MT5921) || defined(MT5931)
extern const wndrv_cal_txpwr_2400M_struct wndrv_default_txpwr_2400M;
#endif

extern const wndrv_cal_txpwr_5000M_struct wndrv_default_txpwr_5000M;

extern const wndrv_cal_dac_dc_offset_struct wndrv_default_dac_dc_offset;

extern const wndrv_cal_tx_ALC_2400M_struct wndrv_default_tx_ALC_pwr;

extern const wndrv_cal_ALC_Slope_2400M_struct wndrv_default_ALC_Slope;

extern const wndrv_cal_txpwr_cal_free_flow_struct wndrv_default_TPCFF;

extern const wndrv_cal_setting_trim_thermo_struct wndrv_cal_setting_trim_thermo;

#endif


/**
 * Step 4:
 * The logical data item table.
 * Note:
 * Each logical data item must be:
 * 1> Size must be EVEN
 * 2> Size of default value must be equal to the logical data item's size.
 *
 * The last LID in the MT reign now is MT1k
 */

ltable_entry_struct logical_data_item_table_factory[] =
{

    
#ifdef __SMART_PHONE_MODEM__
    {
        NVRAM_EF_IMPT_COUNTER_LID,
        NVRAM_EF_IMPT_COUNTER_TOTAL,
        NVRAM_EF_IMPT_COUNTER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_IMPORTANT_L4,
        NVRAM_ATTR_AVERAGE,
        "MP0D",
        VER(NVRAM_EF_IMPT_COUNTER_LID)
    },
#endif
        
    {
        NVRAM_EF_L1_AGCPATHLOSS_LID,
        NVRAM_EF_L1_AGCPATHLOSS_TOTAL,
        NVRAM_EF_L1_AGCPATHLOSS_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT05",
        VER(NVRAM_EF_L1_AGCPATHLOSS_LID)
    },

#ifdef __GSM850__
    {
        NVRAM_EF_L1_RAMPTABLE_GSM850_LID,
        NVRAM_EF_L1_RAMPTABLE_GSM850_TOTAL,
        NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT06",
        VER(NVRAM_EF_L1_RAMPTABLE_GSM850_LID)
    },
#endif

#ifdef __EGSM900__
    {
        NVRAM_EF_L1_RAMPTABLE_GSM900_LID,
        NVRAM_EF_L1_RAMPTABLE_GSM900_TOTAL,
        NVRAM_EF_L1_RAMPTABLE_GSM900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT07",
        VER(NVRAM_EF_L1_RAMPTABLE_GSM900_LID)
    },
#endif

#ifdef __DCS1800__
    {
        NVRAM_EF_L1_RAMPTABLE_DCS1800_LID,
        NVRAM_EF_L1_RAMPTABLE_DCS1800_TOTAL,
        NVRAM_EF_L1_RAMPTABLE_DCS1800_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT08",
        VER(NVRAM_EF_L1_RAMPTABLE_DCS1800_LID)
    },
#endif

#ifdef __PCS1900__
    {
        NVRAM_EF_L1_RAMPTABLE_PCS1900_LID,
        NVRAM_EF_L1_RAMPTABLE_PCS1900_TOTAL,
        NVRAM_EF_L1_RAMPTABLE_PCS1900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT09",
        VER(NVRAM_EF_L1_RAMPTABLE_PCS1900_LID)
    },
#endif

#if defined(__EPSK_TX__)
#ifdef __GSM850__
    {
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID,
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_TOTAL,
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0A",
        VER(NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID)
    },
#endif

#ifdef __EGSM900__
    {
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID,
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_TOTAL,
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0B",
        VER(NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID)
    },
#endif

#ifdef __DCS1800__
    {
        NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID,
        NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_TOTAL,
        NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0C",
        VER(NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID)
    },
#endif

#ifdef __PCS1900__
    {
        NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID,
        NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_TOTAL,
        NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0D",
        VER(NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID)
    },
#endif

#ifdef __GSM850__
    {
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_TOTAL,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0E",
        VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID)
    },
#endif

#ifdef __EGSM900__
    {
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_TOTAL,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0F",
        VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID)
    },
#endif

#ifdef __DCS1800__
    {
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_TOTAL,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0G",
        VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID)
    },
#endif

#ifdef __PCS1900__
    {
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_TOTAL,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0H",
        VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID)
    },
#endif

#endif/*__EPSK_TX__*/
    {
        NVRAM_EF_L1_AFCDATA_LID,
        NVRAM_EF_L1_AFCDATA_TOTAL,
        NVRAM_EF_L1_AFCDATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0I",
        VER(NVRAM_EF_L1_AFCDATA_LID)
    },
    
    {
        NVRAM_EF_L1_TXIQ_LID,
        NVRAM_EF_L1_TXIQ_TOTAL,
        NVRAM_EF_L1_TXIQ_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
        "MT0J",
        VER(NVRAM_EF_L1_TXIQ_LID)
    },
    
    {
        NVRAM_EF_L1_RFSPECIALCOEF_LID,
        NVRAM_EF_L1_RFSPECIALCOEF_TOTAL,
        NVRAM_EF_L1_RFSPECIALCOEF_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
        "MT0K",
        VER(NVRAM_EF_L1_RFSPECIALCOEF_LID)
    },

#ifdef __GSM850__
    {
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_TOTAL,
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0L",
        VER(NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID)
    },
#endif

#ifdef __EGSM900__
    {
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_TOTAL,
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0M",
        VER(NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID)
    },
#endif

#ifdef __DCS1800__
    {
        NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_TOTAL,
        NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0N",
        VER(NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID)
    },
#endif

#ifdef __PCS1900__
    {
        NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_TOTAL,
        NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0O",
        VER(NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID)
    },
#endif
    
    {
        NVRAM_EF_L1_CRYSTAL_AFCDATA_LID,
        NVRAM_EF_L1_CRYSTAL_AFCDATA_TOTAL,
        NVRAM_EF_L1_CRYSTAL_AFCDATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0P",
        VER(NVRAM_EF_L1_CRYSTAL_AFCDATA_LID)
    },
    
    {
        NVRAM_EF_L1_CRYSTAL_CAPDATA_LID,
        NVRAM_EF_L1_CRYSTAL_CAPDATA_TOTAL,
        NVRAM_EF_L1_CRYSTAL_CAPDATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0Q",
        VER(NVRAM_EF_L1_CRYSTAL_CAPDATA_LID)
    },

#if defined(__PS_SERVICE__)
    {
        NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_LID,
        NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_TOTAL,
        NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0R",
        VER(NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_LID)
    },

#if defined(__EGPRS_MODE__)
    {
        NVRAM_EF_L1_EPSK_TX_POWER_ROLLBACK_TABLE_LID,
        NVRAM_EF_L1_EPSK_TX_POWER_ROLLBACK_TABLE_TOTAL,
        NVRAM_EF_L1_EPSK_TX_POWER_ROLLBACK_TABLE_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0S",
        VER(NVRAM_EF_L1_EPSK_TX_POWER_ROLLBACK_TABLE_LID)
    },
#endif /* defined(__EGPRS_MODE__) */
#endif /*defined(__PS_SERVICE__) */

#if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
    {
        NVRAM_EF_L1_GMSK_TXPC_LID,
        NVRAM_EF_L1_GMSK_TXPC_TOTAL,
        NVRAM_EF_L1_GMSK_TXPC_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0T",
        VER(NVRAM_EF_L1_GMSK_TXPC_LID)
    },
#if defined(__EPSK_TX__)
    {
        NVRAM_EF_L1_EPSK_TXPC_LID,
        NVRAM_EF_L1_EPSK_TXPC_TOTAL,
        NVRAM_EF_L1_EPSK_TXPC_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0U",
        VER(NVRAM_EF_L1_EPSK_TXPC_LID)
    },
#endif /* defined(__EPSK_TX__) */
#endif /* defined(__2G_TX_POWER_CONTROL_SUPPORT__) */

#if defined(__MULTI_LNA_MODE_CALIBRATION_SUPPORT__)
    {
        NVRAM_EF_L1_LNAPATHLOSS_LID,
        NVRAM_EF_L1_LNAPATHLOSS_TOTAL,
        NVRAM_EF_L1_LNAPATHLOSS_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0V",
        VER(NVRAM_EF_L1_LNAPATHLOSS_LID)
    },
#endif

#if defined(__F32_XOSC_REMOVAL_SUPPORT__)
    {
        NVRAM_EF_L1_CLOAD_FREQ_OFFSET_LID,
        NVRAM_EF_L1_CLOAD_FREQ_OFFSET_TOTAL,
        NVRAM_EF_L1_CLOAD_FREQ_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT1V",
        VER(NVRAM_EF_L1_CLOAD_FREQ_OFFSET_LID),
    },
#endif

#if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
#if !defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__)
    {
        NVRAM_EF_L1_TEMPERATURE_ADC_LID,
        NVRAM_EF_L1_TEMPERATURE_ADC_TOTAL,
        NVRAM_EF_L1_TEMPERATURE_ADC_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT1U",
        VER(NVRAM_EF_L1_TEMPERATURE_ADC_LID)
    },
#endif /* !defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__) */
#endif /* defined(__2G_TX_POWER_CONTROL_SUPPORT__) */

#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
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
/* under construction !*/
#if defined (__UL1_HS_PLATFORM__)
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
/* under construction !*/
/* under construction !*/
#endif // #if defined (__UL1_HS_PLATFORM__)
#endif /* __UMTS_RAT__ && __MTK_UL1_FDD__*/
    
#ifdef  __BTMODULE_MT6601__
    {
        NVRAM_EF_BTRADIO_MT6601_LID,
        NVRAM_EF_BTRADIO_MT6601_TOTAL,
        NVRAM_EF_BTRADIO_MT6601_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BTRADIO_MT6601_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE,
        "MT1H",
        VER(NVRAM_EF_BTRADIO_MT6601_LID)
    },
#endif

#ifdef  __BTMODULE_MT6611__
    {
        NVRAM_EF_BTRADIO_MT6611_LID,
        NVRAM_EF_BTRADIO_MT6611_TOTAL,
        NVRAM_EF_BTRADIO_MT6611_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BTRADIO_MT6611_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE,
        "MT1I",
        VER(NVRAM_EF_BTRADIO_MT6611_LID)
    },
#endif


#if defined(__WIFI_SUPPORT__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)
    {
        NVRAM_EF_WNDRV_MAC_ADDRESS_LID,
        NVRAM_EF_WNDRV_MAC_ADDRESS_TOTAL,
        NVRAM_EF_WNDRV_MAC_ADDRESS_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_mac_addr),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1M",
        VER(NVRAM_EF_WNDRV_MAC_ADDRESS_LID)
    },
    
    {
        NVRAM_EF_WNDRV_TX_POWER_2400M_LID,
        NVRAM_EF_WNDRV_TX_POWER_2400M_TOTAL,
        NVRAM_EF_WNDRV_TX_POWER_2400M_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_txpwr_2400M),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1N",
        VER(NVRAM_EF_WNDRV_TX_POWER_2400M_LID)
    },
    
    {
        NVRAM_EF_WNDRV_TX_POWER_5000M_LID,
        NVRAM_EF_WNDRV_TX_POWER_5000M_TOTAL,
        NVRAM_EF_WNDRV_TX_POWER_5000M_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_txpwr_5000M),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1O",
        VER(NVRAM_EF_WNDRV_TX_POWER_5000M_LID)
    },
    
    {
        NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID,
        NVRAM_EF_WNDRV_DAC_DC_OFFSET_TOTAL,
        NVRAM_EF_WNDRV_DAC_DC_OFFSET_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_dac_dc_offset),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1P",
        VER(NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID)
    },
    
    {
        NVRAM_EF_WNDRV_TX_ALC_POWER_LID,
        NVRAM_EF_WNDRV_TX_ALC_POWER_TOTAL,
        NVRAM_EF_WNDRV_TX_ALC_POWER_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_tx_ALC_pwr),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1Q",
        VER(NVRAM_EF_WNDRV_TX_ALC_POWER_LID)
    },
    
    {
        NVRAM_EF_WNDRV_EXT_SETTING_TRIMVAL_THERMOVAL_LID,
        NVRAM_EF_WNDRV_EXT_SETTING_TRIMVAL_THERMOVAL_TOTAL,
        NVRAM_EF_WNDRV_EXT_SETTING_TRIMVAL_THERMOVAL_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_cal_setting_trim_thermo),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1R",
        VER(NVRAM_EF_WNDRV_EXT_SETTING_TRIMVAL_THERMOVAL_LID)
    },
    
    {
        NVRAM_EF_WNDRV_ALC_SLOPE_LID,
        NVRAM_EF_WNDRV_ALC_SLOPE_TOTAL,
        NVRAM_EF_WNDRV_ALC_SLOPE_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_ALC_Slope),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1S",
        VER(NVRAM_EF_WNDRV_ALC_SLOPE_LID)
    },
//CYLEN: ??    
    {
        NVRAM_EF_WNDRV_TPCFF_LID,
        NVRAM_EF_WNDRV_TPCFF_TOTAL,
        NVRAM_EF_WNDRV_TPCFF_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_TPCFF),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT1T",
        VER(NVRAM_EF_WNDRV_TPCFF_LID)
    },
#endif /*__WIFI_SUPPORT__*/

#ifdef __AST_TL1_TDD__
    {
        NVRAM_EF_AST_TL1_TEMP_DAC_LID,
        NVRAM_EF_AST_TL1_TEMP_DAC_TOTAL,
        NVRAM_EF_AST_TL1_TEMP_DAC_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2A",
        VER(NVRAM_EF_AST_TL1_TEMP_DAC_LID)
    },
    
    {
        NVRAM_EF_AST_TL1_AFC_DATA_LID,
        NVRAM_EF_AST_TL1_AFC_DATA_TOTAL,
        NVRAM_EF_AST_TL1_AFC_DATA_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_AFC_DATA_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2B",
        VER(NVRAM_EF_AST_TL1_AFC_DATA_LID)
    },

    {
        NVRAM_EF_AST_TL1_PATHLOSS_BAND33_35_37_39_LID,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_PATHLOSS_33_35_37_39_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2C",
        VER(NVRAM_EF_AST_TL1_PATHLOSS_BAND33_35_37_39_LID)
    },

    {
        NVRAM_EF_AST_TL1_PATHLOSS_BAND34_LID,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_PATHLOSS_34_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2D",
        VER(NVRAM_EF_AST_TL1_PATHLOSS_BAND34_LID)
    },

    {
        NVRAM_EF_AST_TL1_PATHLOSS_BAND36_LID,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2E",
        VER(NVRAM_EF_AST_TL1_PATHLOSS_BAND36_LID)
    },

    {
        NVRAM_EF_AST_TL1_PATHLOSS_BAND38_LID,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2F",
        VER(NVRAM_EF_AST_TL1_PATHLOSS_BAND38_LID)
    },

    {
        NVRAM_EF_AST_TL1_PATHLOSS_BAND40_LID,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2G",
        VER(NVRAM_EF_AST_TL1_PATHLOSS_BAND40_LID)
    },

    {
        NVRAM_EF_AST_TL1_TXDAC_BAND33_35_37_39_LID,
        NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_TXDAC_33_35_37_39_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2H",
        VER(NVRAM_EF_AST_TL1_TXDAC_BAND33_35_37_39_LID)
    },

     {
        NVRAM_EF_AST_TL1_TXDAC_BAND34_LID,
        NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_TXDAC_34_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2I",
        VER(NVRAM_EF_AST_TL1_TXDAC_BAND34_LID)
    },
    
    {
        NVRAM_EF_AST_TL1_TXDAC_BAND36_LID,
        NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2J",
        VER(NVRAM_EF_AST_TL1_TXDAC_BAND36_LID)
    },
    
    {
        NVRAM_EF_AST_TL1_TXDAC_BAND38_LID,
        NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2K",
        VER(NVRAM_EF_AST_TL1_TXDAC_BAND38_LID)
    },
    
    {
        NVRAM_EF_AST_TL1_TXDAC_BAND40_LID,
        NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2L",
        VER(NVRAM_EF_AST_TL1_TXDAC_BAND40_LID)
    },
//CYLEN??    
    {
        NVRAM_EF_AST_TL1_ABB_CAL_LID,
        NVRAM_EF_AST_TL1_ABB_CAL_TOTAL,
        NVRAM_EF_AST_TL1_ABB_CAL_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_ABB_CAL_DEFAULT),
        NVRAM_CATEGORY_USER, /// this is auto calibrated in first time mcu power on (or the data loss case), don't need backup & restore
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2P", // be very careful, MT2M, MT2N, MT2O is used by RF calibration history in MAUI, 10A branch
        VER(NVRAM_EF_AST_TL1_ABB_CAL_LID)
    },
#endif // __AST_TL1_TDD__
// RF Calibration history NVRAM items
#ifdef __TC01__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __TC01__ */



    {
        NVRAM_EF_BARCODE_NUM_LID,
        NVRAM_EF_BARCODE_NUM_TOTAL,
        NVRAM_EF_BARCODE_NUM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        "MP09", /* keep the file prefix as the same with legacy branches in BKRS/sw upgrade */
        VER(NVRAM_EF_BARCODE_NUM_LID)
    },
    
    {
        NVRAM_EF_CAL_FLAG_LID,
        NVRAM_EF_CAL_FLAG_TOTAL,
        NVRAM_EF_CAL_FLAG_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MPA2", /* keep the file prefix as the same with legacy branches in BKRS/sw upgrade */
        VER(NVRAM_EF_CAL_FLAG_LID)
    },
    
    {
        NVRAM_EF_CAL_DATA_CHECK_LID,
        NVRAM_EF_CAL_DATA_CHECK_TOTAL,
        NVRAM_EF_CAL_DATA_CHECK_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MPA8", /* keep the file prefix as the same with legacy branches in BKRS/sw upgrade */
        VER(NVRAM_EF_CAL_DATA_CHECK_LID)
    },


    {
        NVRAM_EF_IMEI_IMEISV_LID,
        NVRAM_EF_IMEI_IMEISV_TOTAL,
        NVRAM_EF_IMEI_IMEISV_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
    #ifdef __SECURITY_OTP__
        NVRAM_CATEGORY_OTP | NVRAM_CATEGORY_IMPORTANT,
    #elif defined(__NVRAM_CUSTOM_DISK__)
        NVRAM_CATEGORY_CUSTOM_DISK,
    #else
        NVRAM_CATEGORY_IMPORTANT,
    #endif

    #if defined(__SECURITY_OTP__) || defined(__NVRAM_CUSTOM_DISK__)
        NVRAM_ATTR_AVERAGE,
    #else
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL,
    #endif
        "MP0B",
        VER(NVRAM_EF_IMEI_IMEISV_LID)
    },

    {
        NVRAM_EF_SML_LID,
        NVRAM_EF_SML_TOTAL,
        NVRAM_EF_SML_SIZE,
        NVRAM_SECUPACK(&NVRAM_EF_SML_DEFAULT),
    #ifdef __SMART_PHONE_MODEM__
        NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT_L4,
    #elif defined(__CUSTOMER_TC01_DISK__) && !defined(WISDOM_MMI)
        NVRAM_CATEGORY_SECUPACK,
    #else
        NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT,
    #endif
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        "MP33",
        VER(NVRAM_EF_SML_LID)
    },

#ifdef __SMART_PHONE_MODEM__
    {
        NVRAM_EF_SIM_LOCK_LID,
        NVRAM_EF_SIM_LOCK_TOTAL,
        NVRAM_EF_SIM_LOCK_SIZE,
        NVRAM_SECUPACK(&NVRAM_EF_SML_DEFAULT),
        NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT,
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        "MP6T",
        VER(NVRAM_EF_SIM_LOCK_LID)
    },
#endif


//#if defined(__BTMODULE_MT6612__) || defined(__BTMODULE_MT6616__) || defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__) || defined(__BTMODULE_MT6236__) || defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6276__)
#if defined(__BTMTK__)
	//6612-6616-6622-6626-6236-6256-6276-6255-6250---
#if !defined(__BTMODULE_RFMD3500__) && !defined(__BTMODULE_MT6601__) && !defined(__BTMODULE_MT6611__)
    {
        NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID,
        NVRAM_EF_BTRADIO_MTK_BT_CHIP_TOTAL,
        NVRAM_EF_BTRADIO_MTK_BT_CHIP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BTRADIO_MTK_BT_CHIP_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE,
        "MT6Y",
        VER(NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID)
    },
#endif
#endif
#if defined(__AST_TL1_TDD__)
#if !defined(__AST1001__) && !defined(__AST2001__)
    {
        NVRAM_EF_AST_TL1_CAP_DATA_LID,
        NVRAM_EF_AST_TL1_CAP_DATA_TOTAL,
        NVRAM_EF_AST_TL1_CAP_DATA_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_CAP_DATA_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT6Z",
        VER(NVRAM_EF_AST_TL1_CAP_DATA_LID)
    },
#endif // #if !defined(__AST1001__) && !defined(__AST2001__)
#endif // #if defined(__AST_TL1_TDD__)

#ifdef __BCM_SUPPORT__
    {
        NVRAM_EF_BT_INFO_LID,
        NVRAM_EF_BT_INFO_TOTAL,
        NVRAM_EF_BT_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_BT_CM_DEFAULT), //NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP25",
        VER(NVRAM_EF_BT_INFO_LID)
    },

    {
        NVRAM_EF_BT_DEV_LIST_LID,
        NVRAM_EF_BT_DEV_LIST_TOTAL,
        NVRAM_EF_BT_DEV_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP26",
        VER(NVRAM_EF_BT_DEV_LIST_LID)
    },

    {
        NVRAM_EF_BT_DEV_LIST_INDEX_LID,
        NVRAM_EF_BT_DEV_LIST_INDEX_TOTAL,
        NVRAM_EF_BT_DEV_LIST_INDEX_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP27",
        VER(NVRAM_EF_BT_DEV_LIST_INDEX_LID)
    },

    {
        NVRAM_EF_BT_SYS_INFO_LID,
        NVRAM_EF_BT_INFO_TOTAL,
        NVRAM_EF_BT_SYS_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_BT_CM_SYS_DEFAULT), //NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP29",
        VER(NVRAM_EF_BT_SYS_INFO_LID)
    },

#endif/*__BCM_SUPPORT__*/
{
        NVRAM_EF_DCC_SENSOR_LK_LID,
        NVRAM_EF_DCC_SENSOR_LK_TOTAL,
        NVRAM_EF_DCC_SENSOR_LK_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_MSP,
        "TRLK",
        VER(NVRAM_EF_DCC_SENSOR_LK_LID)
    },

{
        NVRAM_EF_DCC_SENSOR_SRV_LID,
        NVRAM_EF_DCC_SENSOR_SRV_TOTAL,
        NVRAM_EF_DCC_SENSOR_SRV_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_MSP,
        "TRSV",
        VER(NVRAM_EF_DCC_SENSOR_SRV_LID)
    },
};

#endif /* NVRAM_NOT_PRESENT */
