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
 *  gpio_measure.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 * removed!
 * removed!
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

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "kal_general_types.h"
#include "custom_equipment.h"
#include "device.h"
#include "gpio_measure.h"

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

/*----------------------------------------------------------------------------*/
/* Extern Global Variable                                                     */
/*----------------------------------------------------------------------------*/
#ifdef __CUST_NEW__
 extern const kal_uint8 GPIO_LABELID_MAX;
#endif
 extern GPIO_MAP_ENTRY gpio_map_tbl[];
 
 /*----------------------------------------------------------------------------*/
 /* End                                                                        */
 /*----------------------------------------------------------------------------*/



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
 kal_int32 gpio_measure_get_total_num(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
    return GPIO_LABELID_MAX;
 }

 
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
 kal_bool gpio_measure_get_item_by_idx(kal_uint32 idx, gpio_measure_map_entry_struct * entry)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     GPIO_MAP_ENTRY * tbl_entry;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
    if (idx >= GPIO_LABELID_MAX ||!entry)
        return KAL_FALSE;

    tbl_entry = &gpio_map_tbl[idx];
    
    entry->is_vaild = tbl_entry->vaild != GPIO_INVALID ? KAL_TRUE : KAL_FALSE;
    entry->port = tbl_entry->port;
    entry->name = tbl_entry->netname;
    return KAL_TRUE;
 }




