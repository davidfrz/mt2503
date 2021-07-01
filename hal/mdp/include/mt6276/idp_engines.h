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
 *    idp_engines.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    idp_engines collects the header files of all MDP HW engines and provides 
 *    a HW initialization function entry point also a power off function.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 07 2011 chrono.wu
 * removed!
 * .
 *
 * 12 06 2010 gellmann.chang
 * removed!
 * .
 *
 * 11 23 2010 gellmann.chang
 * removed!
 * .
 *
 * removed!
 * removed!
 * MT6255 HQA check-in
 *
 * removed!
 * removed!
 * DVT check-in
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __idp_engines_mt6276_h__
#define __idp_engines_mt6276_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)

#include "mt6276\idp_hw\idp_imgdma_rdma0.h"
#if defined (DRV_IDP_MT6276E2_SERIES)
#include "mt6276\idp_hw\idp_imgdma_vdorot.h"
#include "mt6276\idp_hw\idp_imgdma_rgbrot0.h"
#include "mt6276\idp_hw\idp_imgdma_rgbrot1.h"
#else
#include "mt6276\idp_hw\idp_imgdma_rotdma0.h"
#include "mt6276\idp_hw\idp_imgdma_rotdma1.h"
#include "mt6276\idp_hw\idp_imgdma_rotdma2.h"
#endif
#include "mt6276\idp_hw\idp_imgdma_jpgdma.h"
#include "mt6276\idp_hw\idp_imgdma_ovl.h"
#include "mt6276\idp_hw\idp_imgdma_mout0.h"
#include "mt6276\idp_hw\idp_imgdma_mout1.h"
#include "mt6276\idp_hw\idp_imgdma_mout2.h"
#include "mt6276\idp_hw\idp_imgdma_mout3.h"
#include "mt6276\idp_hw\idp_imgproc_ipp.h"
#include "mt6276\idp_hw\idp_resz_brz.h"
#include "mt6276\idp_hw\idp_resz_crz.h"
#include "mt6276\idp_hw\idp_resz_prz.h"
#include "mt6276\idp_hw\idp_resz_vrz.h"


extern idp_imgdma_rdma_struct     rdma_struct;
#if defined (DRV_IDP_MT6276E2_SERIES)
extern idp_imgdma_vdorot_struct   vdorot_struct;
extern idp_imgdma_rgbrot0_struct   rgbrot0_struct;
extern idp_imgdma_rgbrot1_struct   rgbrot1_struct;
#else
extern idp_imgdma_rotdma0_struct   rotdma0_struct;
extern idp_imgdma_rotdma1_struct   rotdma1_struct;
extern idp_imgdma_rotdma2_struct   rotdma2_struct;
#endif
extern idp_imgdma_ovl_struct       ovl_struct;
extern idp_imgdma_jpgdma_struct    jpgdma_struct;
extern idp_imgdma_mout0_struct      mout0_struct;
extern idp_imgdma_mout1_struct      mout1_struct;
extern idp_imgdma_mout2_struct      mout2_struct;
extern idp_imgdma_mout3_struct      mout3_struct;
extern idp_imgproc_ipp_struct      ipp_struct;
extern idp_resz_brz_struct         brz_struct;
extern idp_resz_crz_struct         crz_struct;
extern idp_resz_prz_struct         prz_struct;
extern idp_resz_vrz_struct         vrz_struct;

extern void idp_hw_init(void);
extern void turn_off_idp_power(void);

#endif // #if defined(DRV_IDP_MT6236_SERIES)
#endif // #ifndef __idp_engines_mt6236_h__

