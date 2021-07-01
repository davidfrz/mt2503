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
 * phb_main.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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

#ifndef _PHB_MAIN_H
#define _PHB_MAIN_H

#include "kal_release.h"
#include "kal_general_types.h"
#include "phb_defs.h"
#include "app_ltlcom.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */

#include "phb_config.h"

extern kal_uint8 free_bitmap_NVRAM_PHB[];
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
extern kal_uint8 free_bitmap_ADN[PHB_SIM_NUM][PHB_MAX_PBR_ENTRIES][FREE_BITMAP_ADN_BYTES];
#else
extern kal_uint8 free_bitmap_ADN[PHB_SIM_NUM][FREE_BITMAP_ADN_BYTES];
#endif
extern kal_uint8 free_bitmap_FDN[PHB_SIM_NUM][FREE_BITMAP_FDN_BYTES];
extern kal_uint8 free_bitmap_BDN[PHB_SIM_NUM][FREE_BITMAP_BDN_BYTES];
extern kal_uint8 free_bitmap_MSISDN[PHB_SIM_NUM][FREE_BITMAP_MSISDN_BYTES];
extern kal_uint8 free_bitmap_EXT1[PHB_SIM_NUM][FREE_BITMAP_EXT1_BYTES];
extern kal_uint8 free_bitmap_EXT2[PHB_SIM_NUM][FREE_BITMAP_EXT2_BYTES];
extern kal_uint8 free_bitmap_EXT4[PHB_SIM_NUM][FREE_BITMAP_EXT4_BYTES];

#ifdef __PHB_USIM_SUPPORT__
extern kal_uint8 free_bitmap_EXT5[PHB_SIM_NUM][FREE_BITMAP_EXT5_BYTES];
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
extern kal_uint8 free_bitmap_TYPE2_FILE[PHB_SIM_NUM][PHB_TYPE2_BITMAP_COUNT][FREE_BITMAP_TYPE2_FILE_BYTES];
extern kal_uint8 free_bitmap_AAS[PHB_SIM_NUM][FREE_BITMAP_AAS_BYTES];
extern kal_uint8 free_bitmap_GAS[PHB_SIM_NUM][FREE_BITMAP_GAS_BYTES];
#endif 
#endif

/* This function prototype is the sublayer entry function. */
extern void phb_main(ilm_struct *ilm_ptr);
extern kal_bool phb_init(void);
extern kal_bool phb_reset(void);
extern kal_bool phb_reset_for_init(void);
extern kal_bool phb_deinit(void);

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_MAIN_H */ 

