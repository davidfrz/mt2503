/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * Bmi.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file intends for defining the data and functions structures used in BMI application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 /*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2003
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * bmi.h
 *
 * Project:
 * --------
 * MT6208
 *
 * Description:
 * ------------
 * This file intends for define the data and functions structures used in 
 *  bmi.c
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef _MMI_BMI_H
#define _MMI_BMI_H
//#include "BmiResDef.h"
/* 
 * Define
 */
#define BMI_MAX_DIGITS  5
/* 
 * Typedef 
 */

typedef enum
{
    ENUM_GENDER = 0,
    ENUM_HEIGHT_CAPTION,
    ENUM_HEIGHT,
    ENUM_WEIGHT_CAPTION,
    ENUM_WEIGHT,
    ENUM_INLINE_TOTAL
} BMI_INLINE_ITEM_ENUM;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
void mmi_bmi_pre_entry_welcome_screen(void);

#endif /* _MMI_BMI_H */ // #ifndef _MMI_BMI_H

