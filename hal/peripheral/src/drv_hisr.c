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
 *	drv_hisr.c
 *
 * Project:
 * --------
 *		ALL
 *
 * Description:
 * ------------
 *   This file is intends for driver HISR management.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drv_comm.h"
#include "hisr_config.h"
#include "drv_hisr.h"


#ifdef  __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
/* under construction !*/
#endif

kal_hisrid drv_hisr;
kal_uint32 drv_hisr_status1;
kal_uint32 drv_hisr_status2;

void DRV_ERROR_HISR(void);
DRV_HISR_STRUCT DRV_HISR_TABLE[MAX_DRV_HISR_DEVICE];
/*lint -e552*/
DRV_HISR_ID     DRV_CURRENT_HISR;
/*lint +e552*/	

#ifdef  __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

void DRV_ERROR_HISR(void)
{
   ASSERT(0);
}

void DRV_Register_HISR(DRV_HISR_ID hisr_id, VOID_FUNCTION hisr_func)
{
   DRV_HISR_TABLE[hisr_id].hisr_func = hisr_func;
}

// For fix 35 MGM platform over 60 q-bit issue
#pragma arm section code = "INTERNCODE"

void DRV_HISR(void)
{
   kal_uint16 index;
   kal_uint32 savedMask;
#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
#endif

   if (drv_hisr_status1 != 0)
      index = 0;
   else if (drv_hisr_status2 != 0)
      index = 32;
   else
      return;

   while(index<(kal_uint16)MAX_DRV_HISR_DEVICE)
   {
      kal_bool bit_mask;
      kal_uint32 index_shift;
      
      bit_mask = KAL_FALSE;
      if (index < 32)
      {
         index_shift = ((kal_uint32)1) << index;
         if (drv_hisr_status1 & index_shift)
            bit_mask = KAL_TRUE;
      }
      else
      {
         index_shift = ((kal_uint32)1) << (index-32);
         if (drv_hisr_status2 & index_shift)
            bit_mask = KAL_TRUE;
      }
      if (bit_mask == KAL_TRUE)
      {
         DRV_HISR_STRUCT *hisr_pointer;

         hisr_pointer = DRV_HISR_TABLE+index;
         ASSERT(hisr_pointer->hisr_count!=0);
/*lint -e552*/
         DRV_CURRENT_HISR = (DRV_HISR_ID)index;
/*lint +e552*/	
         savedMask = SaveAndSetIRQMask();
#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
/* under construction !*/
#endif
         hisr_pointer->hisr_count--;
         if (hisr_pointer->hisr_count == 0)
         {
            if (index < 32)
            {
               drv_hisr_status1 &= (~index_shift);
               if (drv_hisr_status1 == 0)
                  index = 31;
            }
            else
            {
               drv_hisr_status2 &= (~index_shift);
               if (drv_hisr_status2 == 0)
                  index = MAX_DRV_HISR_DEVICE;
            }
         }
         RestoreIRQMask(savedMask);
         
#ifdef  __MTK_INTERNAL__         
/* under construction !*/
#endif   
      
         hisr_pointer->hisr_func();
         
#ifdef  __MTK_INTERNAL__         
/* under construction !*/
#endif    
     
         DRV_CURRENT_HISR = DRV_UNKNOWN_HISR_ID;
      }//if (bit_mask == KAL_TRUE)
      index++;
   } //while(index<(kal_uint16)MAX_DRV_HISR_DEVICE)
}

// For fix 35 MGM platform over 60 q-bit issue
#pragma arm section code

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void drv_hisr_init(void)
{
   kal_uint32 index;
   ASSERT(MAX_DRV_HISR_DEVICE <= (DRV_HISR_ID)64);
   for(index=0;index<(kal_uint32)MAX_DRV_HISR_DEVICE;index++)
   {
      DRV_HISR_TABLE[index].hisr_func = DRV_ERROR_HISR;
      DRV_HISR_TABLE[index].hisr_count = 0;
   }
   if (drv_hisr == NULL)
   {
      drv_hisr = kal_init_hisr(DRVHISR);
   }
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

#if !defined(__FUE__) && !defined(__UBL__)

void drv_active_hisr(DRV_HISR_ID id)
{
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
	
	if ((id) < 32)
	   drv_hisr_status1 |= (((kal_uint32)1)<<(((kal_uint32)(id)) & 0x1f));
	else
	   drv_hisr_status2 |= (((kal_uint32)1)<<(((kal_uint32)((id)-32)) & 0x1f));
	
	DRV_HISR_TABLE[id].hisr_count++;
	
	RestoreIRQMask(savedMask);
	kal_activate_hisr(drv_hisr);
}
#endif

