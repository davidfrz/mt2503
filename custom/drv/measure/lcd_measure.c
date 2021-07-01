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
*  lcd_measure.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This fie is created to solve HAL High issue on 11BW11.44MP.
*
*  This file is a wrapper of driver layer global variables and should be maintained
*  be the related driver owner because it's bad design that low layer to extern global variable to 
*  upper layer, low layer should provide this wrapper interface, the context of these global variable
*  is also maintained and only can be modified by the related driver layer owner who has the
*  domain knowleage wholly.
*
*  But due to history reasion and a bad design when it born, Driver owner don't want to 
*  take it back to home even after great discussion, but we have to solve the 4N HAL high
*  issue and have to create this file, and just let it dead in the long time in the future.
*
*  This file it not belongs to the creater but really created by the creater, so announce here:
*  NO ONE IS ALLOW TO MODIFY IT UNLESS YOU WANT TO BE THE OWNER OF THIS FILE.
*  
*
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
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/



/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */


/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "kal_general_types.h"
#include "custom_hw_default.h"
#include "lcd_measure.h"

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static const kal_uint8* lcd_measure_info_map[] = 
{
    MainLCD_Contrast_Level_Info,
    MainLCD_Bias_Level_Info,
    MainLCD_Linerate_Level_Info,
    MainLCD_Temp_Level_Info,
#ifdef __MMI_SUBLCD__
    SubLCD_Contrast_Level_Info,
    SubLCD_Bias_Level_Info,
    SubLCD_Linerate_Level_Info,
    SubLCD_Temp_Level_Info
#endif
};

/*----------------------------------------------------------------------------*/
/* Extern Global Variable                                                     */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/



#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
kal_uint8* lcd_measure_get_level_info(lcd_measure_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type >= LCD_MEASURE_TYPE_MAX_ITEM)
        return NULL;
    
    return (kal_uint8*)lcd_measure_info_map[type];
}

kal_uint32 lcd_measure_get_level_info_size(lcd_measure_type_enum type)
{
    switch(type)
    {
        case LCD_MEASURE_TYPE_MAINLCD_CONTRAST:
            return sizeof(MainLCD_Contrast_Level_Info);
            
        case LCD_MEASURE_TYPE_MAINLCD_BIAS:
            return sizeof(MainLCD_Bias_Level_Info);
            
        case LCD_MEASURE_TYPE_MAINLCD_LINERATE:
            return sizeof(MainLCD_Linerate_Level_Info);
            
        case LCD_MEASURE_TYPE_MAINLCD_TEMP:
            return sizeof(MainLCD_Temp_Level_Info);

    #ifdef __MMI_SUBLCD__
        case LCD_MEASURE_TYPE_SUBLCD_CONTRAST:
            return sizeof(SubLCD_Contrast_Level_Info);
            
        case LCD_MEASURE_TYPE_SUBLCD_BIAS:
            return sizeof(SubLCD_Bias_Level_Info);
            
        case LCD_MEASURE_TYPE_SUBLCD_LINERATE:
            return sizeof(SubLCD_Linerate_Level_Info);
            
        case LCD_MEASURE_TYPE_SUBLCD_TEMP:
            return sizeof(SubLCD_Temp_Level_Info);
    #endif
    
        default:
            return 0;
    }
}


#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */





