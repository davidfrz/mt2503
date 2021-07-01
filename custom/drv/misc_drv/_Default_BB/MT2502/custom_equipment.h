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
 *   custom_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the custom task index and module index configuration.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_EQUIPMENT_H
#define _CUSTOM_EQUIPMENT_H

#include "kal_general_types.h"

//#define RED_LED_SUPPORT    /* if hardware support red LED, then define it, otherwise mark it. */
//#define GREEN_LED_SUPPORT    /* if hardware support green LED, then define it, otherwise mark it. */
//#define BLUE_LED_SUPPORT    /* if hardware support blue LED, then define it, otherwise mark it. */

#if !defined(RED_LED_SUPPORT) && !defined(GREEN_LED_SUPPORT) && !defined(BLUE_LED_SUPPORT)
#define HARDWARE_LED_NOT_SUPPORT
#endif

#define VBAT_HIT_COUNT_BOUND  3
#define VBAT_GROWUP_PENALTY  (30 /*mA*/ * 1000 )

// MTK_BEGIN Lisen added
#define LCD_CLAM_CLOSE_HALFLITE_TO_OFF_TIME 15000
#define LCD_CLAM_OPEN_HALFLITE_TO_OFF_TIME 15000
// MTK_END

#define GPIO_OFF  0x0
#define GPIO_ON    0x1

typedef struct _GPIO_MAP_ENTRY {
   unsigned char vaild;
   unsigned char port;
   const unsigned char *netname;
   const unsigned char *netname2;
} GPIO_MAP_ENTRY;

#ifndef __CUST_NEW__
typedef enum {
   GPIO_PORT_0 = 0x0,
   GPIO_PORT_1,
   GPIO_PORT_2,
   GPIO_PORT_3,
   GPIO_PORT_4,
   GPIO_PORT_5,
   GPIO_PORT_6,
   GPIO_PORT_7,
   GPIO_PORT_8,
   GPIO_PORT_9,
   GPIO_PORT_10,
   GPIO_PORT_11,
   GPIO_PORT_12,
   GPIO_PORT_13,
   GPIO_PORT_14,
   GPIO_PORT_15,
   GPIO_PORT_16,
   GPIO_PORT_17,
   GPIO_PORT_18,
   GPIO_PORT_19,
   GPIO_PORT_20,
   GPO_PORT_0,
   GPO_PORT_1,
   GPO_PORT_2,

   /* shound NOT modify this value*/
   GPIO_PORT_MAX
} GPIO_PORT_ENUM;


typedef enum {
   GPIO_LABEL_LED_LCD = 0x0,
   GPIO_LABEL_DEV_LED_KEY,
   GPIO_LABEL_DEV_LED_STATUS,
   GPIO_LABEL_DEV_VIBRATOR,
   GPIO_LABELID_4,
   GPIO_LABELID_5,
   GPIO_LABELID_6,
   GPIO_LABELID_7,
   GPIO_LABELID_8,
   GPIO_LABELID_9,
   GPIO_LABELID_11,
   GPIO_LABELID_10,
   GPIO_LABELID_12,
   GPIO_LABELID_13,
   GPIO_LABELID_14,
   GPIO_LABELID_15,
   GPIO_LABELID_16,
   GPIO_LABELID_17,
   GPIO_LABELID_18,
   GPIO_LABELID_19,
   GPIO_LABELID_20,
   GPO_LABELID_0,
   GPO_LABELID_1,
   GPO_LABELID_2,

   /* shound NOT modify this value*/
   GPIO_LABELID_MAX
} GPIO_LABELID_ENUM;


typedef enum {

   EINT_LABELID_0 = 0x0,
   EINT_LABELID_1,
   EINT_LABELID_2,
   EINT_LABELID_3,
   EINT_LABELID_4,

   EINT_LABELID_MAX = EINT_LABELID_4
   
} EINT_LABELID_ENUM;

typedef enum {

   ADC_LABELID_0 = 0x0,
   ADC_LABELID_1,
   ADC_LABELID_2,
   ADC_LABELID_3,
   ADC_LABELID_4,

   ADC_LABELID_MAX = ADC_LABELID_4
   
} ADC_LABELID_ENUM;

#else /* __CUST_NEW__ */

extern const kal_uint8 GPIO_LABELID_MAX;
extern const kal_uint8 EINT_LABELID_MAX;
extern const kal_uint8 ADC_LABELID_MAX;
extern kal_uint8 EmGpioIdxMenu2Tbl[];

#endif /* __CUST_NEW__ */

extern GPIO_MAP_ENTRY gpio_map_tbl[];
extern GPIO_MAP_ENTRY eint_map_tbl[];
extern GPIO_MAP_ENTRY adc_map_tbl[];

#if (0)
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
#endif /* #if 0*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern kal_uint8 custom_cfg_outward_gpio_port
(
 kal_uint8  gpio_device_id /* gpio_device_enum */
 );

extern kal_bool custom_cfg_gpio_set_level
   (
   kal_uint8 gpio_dev_type, /* gpio_device_enum */
   kal_uint8 gpio_dev_level 
   );


extern kal_uint8 custom_cfg_vbat_level_convert
(
 kal_int32  vbat
 );

extern kal_uint8 custom_cfg_vbat_level_regulator
(
 kal_uint32 measure_voltage, 
 kal_uint8 *last_level, 
 kal_uint8 *disp_level, 
 kal_uint8 *hit_count 
 );

extern void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty);

extern void custom_stop_flashlight(void);

#endif /* _CUSTOM_EQUIPMENT_H */


