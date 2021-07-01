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
 *
 * Filename:
 * ---------
 *   m12190.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Initialize RF components
 *
 * Author:
 * -------
 * -------
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *******************************************************************************/

#include "l1d_cid.h"
#include "l1d_reg.h"
#include "l1d_custom_rf.h"
#include "l1d_rf.h"
#include "l1d_data.h"
#include "m12190.h"
#include "m12193.h"
#include "m12197.h"
#include "stack_config.h"
#include "nvram_interface.h"

/*---------------------------------------------------------------------------*/

sRFSETTING  l1d_rf;   // BB -> RF
sRFSETTING2 l1d_rf2;  // RF only

/*---------------------------------------------------------------------------*/

/*----------------------------------------*/
/* RFSpecialCoef Calibration data         */
/*----------------------------------------*/
sRFSpecialCoef RFSpecialCoef;

/*----------------------------------------*/
/* VCXO Linear Compensation parameters    */
/*----------------------------------------*/
#define  ONE                 0x1000 /*Used to reduce fix point divided error*/
#define  PHI_Factor          32
#define  RATIO_20_DIV_21     3901   /*(20*0x1000+21/2)/21 used to reduce frequency offset 5%*/
#define  RATIO_21_DIV_20     4301   /*(21*0x1000+20/2)/20 used to increase Invert slope 5%*/
#define  RATIO_4_DIV_5       3277   /*(4*0x1000+5/2)/5 */
#define  RATIO_5_DIV_4       5120   /*(5*0x1000+4/2)/4 */
#define  ROUND_FIX_DIV(c,d)  (((c)+(1<<((d)-1)))>>(d))

#if IS_VCXO_LC_SUPPORT
unsigned char XO_LC_Flags = XO_LC_ENABLED;
XO_LC_PARAMS  XO_LC_TableParams;
extern signed int afc_inv_slope;
extern signed short int afc_dac_default;
extern signed short int onek_hz_dac;
#else
unsigned char XO_LC_Flags = XO_LC_DISABLED;
#endif

static signed short weight_section_end_idx[5];
static signed short weight_section_end_idx_EPSK[5];

#ifndef GSM_ERR_DET_ID
#define  GSM_ERR_DET_ID          9  //<--temp use, each rf should define this in l1d_custom_rf.h
#endif

CONST unsigned char gsm_err_det_id = GSM_ERR_DET_ID;
/*---------------------------------------------------------------------------*/

static void L1D_RF_Set_SLEEP_SPI( void )
{
#if IS_BT_CO_CLOCK_HW_SUPPORT && IS_BT_COCLOCK_SUPPORT
   #if IS_RF_AD6548 || IS_RF_AD6546
   unsigned short d16;
   d16  = HW_READ( APB_CON );
   d16 |= (unsigned short)(0xD010);
   HW_WRITE( APB_CON, d16 );

   d16  = HW_READ( SLEEP_SPI );
   d16 &= ~0x007F;
      #if IS_RF_AD6546
   d16 |= (XO_CapID<<0);
      #elif IS_RF_AD6548
   d16 |= (XO_CapID<<1);
      #endif
   HW_WRITE( SLEEP_SPI, d16 );
   #endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*----------------------------------------*/
/* TX Power Control Functions             */
/*----------------------------------------*/
#if IS_TX_POWER_CONTROL_SUPPORT
/* for the purpose of "TXPC in META" to backup and restore the calibrated data */
unsigned char is_calibrated_backup = 0;
   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
unsigned char TXADC_Data_LSB_Backup[4][16];
unsigned char TXADC_Data_MSB_Backup[4][8];
      #if IS_EPSK_TX_SUPPORT
unsigned char TXADC_Data_LSB_Backup_EPSK[4][16];
unsigned char TXADC_Data_MSB_Backup_EPSK[4][8];
      #endif
   #endif

/* define 8 temperature sections */
short TEMP_IDX[8] = { -10, 5, 20 ,35 ,45 ,55 ,60, 65 };
#endif

#if IS_TX_POWER_CONTROL_SUPPORT
   #if IS_RF_TX_POWER_CONTROL_SUPPORT
   #else
sTXPC_TEMPDATA TEMP_DAC;
sTXPC_TEMPDATA GSM850_TXTEMP_Data;
sTXPC_TEMPDATA GSM_TXTEMP_Data;
sTXPC_TEMPDATA DCS_TXTEMP_Data;
sTXPC_TEMPDATA PCS_TXTEMP_Data;

sTXPC_TEMPDATA* TXTEMP_Data[] =
{
   &TEMP_DAC,                    /* use this field to store themistor DAC  */
   &GSM850_TXTEMP_Data,          /* FrequencyBand850                */
   &GSM_TXTEMP_Data,             /* FrequencyBand900                */
   &DCS_TXTEMP_Data,             /* FrequencyBand1800               */
   &PCS_TXTEMP_Data,             /* FrequencyBand1900               */
};
      #if IS_EPSK_TX_SUPPORT
sTXPC_TEMPDATA GSM850_TXTEMP_Data_EPSK;
sTXPC_TEMPDATA GSM_TXTEMP_Data_EPSK;
sTXPC_TEMPDATA DCS_TXTEMP_Data_EPSK;
sTXPC_TEMPDATA PCS_TXTEMP_Data_EPSK;

sTXPC_TEMPDATA* TXTEMP_Data_EPSK[] =
{
   0,                             /* FrequencyBand400 (not support)  */
   &GSM850_TXTEMP_Data_EPSK,      /* FrequencyBand850                */
   &GSM_TXTEMP_Data_EPSK,         /* FrequencyBand900                */
   &DCS_TXTEMP_Data_EPSK,         /* FrequencyBand1800               */
   &PCS_TXTEMP_Data_EPSK,         /* FrequencyBand1900               */
};
      #endif
      #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
/* The following variables are not defined in the custom folder of AD6546 */
sTXPC_ADCDATA GSM850_TXADC_Data;
sTXPC_ADCDATA GSM_TXADC_Data;
sTXPC_ADCDATA DCS_TXADC_Data;
sTXPC_ADCDATA PCS_TXADC_Data;

sTXPC_ADCDATA* TXADC_Data[] =
{
   0,                            /* FrequencyBand400 (not support)  */
   &GSM850_TXADC_Data,           /* FrequencyBand850                */
   &GSM_TXADC_Data,              /* FrequencyBand900                */
   &DCS_TXADC_Data,              /* FrequencyBand1800               */
   &PCS_TXADC_Data,              /* FrequencyBand1900               */
};
         #if IS_EPSK_TX_SUPPORT
sTXPC_ADCDATA GSM850_TXADC_Data_EPSK;
sTXPC_ADCDATA GSM_TXADC_Data_EPSK;
sTXPC_ADCDATA DCS_TXADC_Data_EPSK;
sTXPC_ADCDATA PCS_TXADC_Data_EPSK;

sTXPC_ADCDATA* TXADC_Data_EPSK[] =
{
   0,                            /* FrequencyBand400 (not support)  */
   &GSM850_TXADC_Data_EPSK,      /* FrequencyBand850                */
   &GSM_TXADC_Data_EPSK,         /* FrequencyBand900                */
   &DCS_TXADC_Data_EPSK,         /* FrequencyBand1800               */
   &PCS_TXADC_Data_EPSK,         /* FrequencyBand1900               */
};
         #endif   /* IS_EPSK_TX_SUPPORT */
      #endif      /* IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT */
   #endif         /* IS_RF_TX_POWER_CONTROL_SUPPORT */
#endif            /* IS_TX_POWER_CONTROL_SUPPORT */

#if IS_TXPC_CL_AUXADC_SUPPORT
void L1D_RF_TXPC_CL_AUXADC_PowerOn( void )
{
   if( l1d_rf.txpc_type == TXPC_AUXADC_CLOSED_TYPE )
   {
   #if IS_CHIP_MT6256
      HW_WRITE( PDN_CLR1,    0x0800 );    /* AUXADC dedicated power switch for 2G TX power measurement     */
   #elif IS_CHIP_MT6276
      HW_WRITE( MCU_CG_CLR2, 0x0080 );    /* AUXADC 2G general power switch                                */
                                          /* AUXADC 2GTX dedicated power switch (MCU_CG_CLR3[0]) is not ready yet. */
                                          /* Use general switch instead                                     */
   #endif
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_AUXADC_PowerOff( void )
{
   if( l1d_rf.txpc_type == TXPC_AUXADC_CLOSED_TYPE )
   {
   #if IS_CHIP_MT6256
      HW_WRITE( PDN_SET1,    0x0800 );    /* AUXADC dedicated power switch for 2G TX power measurement     */
   #elif IS_CHIP_MT6276
//    HW_WRITE( MCU_CG_SET2, 0x0080 );    /* AUXADC 2G general power switch                                */
                                          /* AUXADC 2GTX dedicated power switch (MCU_CG_CLR3[0]) is not ready yet.  */
                                          /* Do not turn off general switch to avoid disturbing ADC driver */
   #endif
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_TX_POWER_CONTROL_SUPPORT
void L1D_RF_Init_TXPC_Data( void )
{
   /* 1. Set power control type */
   if( closed_loop_txpc_type == 1 )
   {  l1d_rf.txpc_type = TXPC_AUXADC_CLOSED_TYPE;  }
   else if( closed_loop_txpc_type == 2 )
   {  l1d_rf.txpc_type = TXPC_BSI_CLOSED_TYPE;     }
   else
   {  if( open_loop_txpc_type == 1 )
      {  l1d_rf.txpc_type = TXPC_AUXADC_OPEN_TYPE; }
      else if( open_loop_txpc_type == 2 )
      {  l1d_rf.txpc_type = TXPC_BSI_OPEN_TYPE;    }
      else
      {  l1d_rf.txpc_type = TXPC_NO_CONTROL_TYPE;  }
   }

   #if IS_RF_TX_POWER_CONTROL_SUPPORT
   #else
   l1d_rf.txpc_type = TXPC_NO_CONTROL_TYPE;  /* RF doesn't need SW TXPC */
   #endif

   /* 2. Set operating mode */
   if( L1D_CheckIfMetaMode() )   /* Meta Mode */
   {  l1d_rf.txpc_mode = TXPC_META_MODE;
   }
   else                          /* Normal Mode */
   {  if( (open_loop_txpc_type>0) && (is_txpc_calibrated&0x1) )
      {  l1d_rf.txpc_mode = TXPC_NORMAL_MODE;   }  /* open loop */
      else if( (closed_loop_txpc_type>0) && (is_txpc_calibrated&(0x2)) )
      {  l1d_rf.txpc_mode = TXPC_NORMAL_MODE;   }  /* closed loop */
      else
      {  l1d_rf.txpc_mode = TXPC_SAMPLE_MODE;   }  /* Switch off TXPC if TXPC is not calibrated */
   }

   l1d_rf.is_txpc_in_meta = 0;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

static void L1D_RF_Init_AUXADC( void )
{
#if IS_TXPC_CL_AUXADC_SUPPORT
   if( l1d_rf.txpc_type == TXPC_AUXADC_CLOSED_TYPE )
   {  L1D_RF_TXPC_CL_AUXADC_POWERON();
      HW_WRITE( AUX_2GTX_CH, TXPC_AUXADC_VDET_PORT );
      /* Bit[11] in AUXADC_CON3 enables the power warm-up period to ensure power stability before the SAR process takes place. */
      /* This bit should always be 0 as it is de-featured.                                                                     */
      HW_WRITE( AUXADC_CON3, HW_READ(AUXADC_CON3)&(~0x0800) );
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* TC gain compensation */
#if IS_BAND_COMP_TC_GAIN_SUPPORT
   #if IS_TEMP_COMP_TC_GAIN_SUPPORT

short TC_GAIN_SLOPE_TABLE[FrequencyBandCount][TEMP_SECTION_NUM - 1] = {0};
   
const char TC_GAIN_TABLE[FrequencyBandCount][TEMP_SECTION_NUM] = 
{ 
      #if IS_RF_MT6260RF
      /*LT, NT, HT*/ /* RF_MT6260RF */
      { 0,  0,  0},  /* GSM400  */
      {70, 61, 52},  /* GSM850  */
      {62, 55, 45},  /* GSM900  */
      {60, 52, 40},  /* DCS1800 */
      {48, 38, 31}   /* PCS1900 */
      #elif IS_RF_MT6250RF
      /*LT, NT, HT*/ /* RF_MT6250RF */
      { 0,  0,  0},  /* GSM400 */
      {51, 34, 30},  /* GSM850 */
      {41, 26, 24},  /* GSM900 */
      {45, 29, 26},  /* DCS1800 */
      {36, 23, 22}   /* PCS1900 */
      #else
      /*LT, NT, HT*/ /* RF_MT6256RF */
      { 0,  0,  0},  /* GSM400 */
      {16, 10,  7},  /* GSM850 */
      {14,  8,  5},  /* GSM900 */
      {16, 10,  7},  /* DCS1800 */
      {12,  7,  5}   /* PCS1900 */
      #endif
};
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void L1D_RF_Init_TC_Gain_Slope( void )
{
   int band;
   for( band = FrequencyBand400; band < FrequencyBandCount; band++ )
   {
      TC_GAIN_SLOPE_TABLE[band][LOW_TEMP_IND]    = TC_GAIN_SLOPE( TC_GAIN_LOW_TEMP   , TC_GAIN_NORMAL_TEMP, TC_GAIN_TABLE[band][LOW_TEMP_IND],    TC_GAIN_TABLE[band][NORMAL_TEMP_IND]);
      TC_GAIN_SLOPE_TABLE[band][NORMAL_TEMP_IND] = TC_GAIN_SLOPE( TC_GAIN_NORMAL_TEMP, TC_GAIN_HIGH_TEMP  , TC_GAIN_TABLE[band][NORMAL_TEMP_IND], TC_GAIN_TABLE[band][HIGH_TEMP_IND]);
   }
}   
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */   

   #if IS_RF_MT6250RF || IS_RF_MT6260RF
/* Evaluate RF thermo ADC code offset value for each chip by reading C_adc from EFUE. */
/* Call this function at L1D_RF_PowerOn */
void L1D_RF_THADC_Set_Code_Offset( void )
{
   /*----------------------------------------------*/
   /* For MT6260                                   */
   /* temp * 57 = [ C_adc - (24 + C_ost) ] * 225   */
   /* For MT6250                                   */
   /* temp * 11 = [ C_adc - (18 + C_ost) ] * 40    */
   /*----------------------------------------------*/
   /* C_adc: RF thermo ADC code                    */
   /* C_ost: RF thermo ADC code offset             */
   /*----------------------------------------------*/
   /* Let temp as 25 Celsius degree                */
   /* For MT6260                                   */
   /* C_ost =  C_adc - 91/3                        */
   /* For MT6250                                   */
   /* C_ost =  C_adc - 199/8                       */
   /*----------------------------------------------*/
   int is_efue_ready;
   int c_adc, c_ost;   /* DEC_FORM: in format of S24.8 */
   unsigned int d32;

   /* Get C_adc from EFUE. */
   d32 = HW_READ(EFUE_HW_RES0);
   d32 &= EFUE_TEMP_CODE_CW_MASK;
   d32 >>= EFUE_TEMP_CODE_LSB;

   /* Check if C_adc from EFUE is reasonable. (1~63) */
      #if IS_RF_MT6260RF
   d32 &= 0x3F;
      #endif
   is_efue_ready = ((d32 > 0) && (d32 < 64)) ? 1 : 0 ;

   if( is_efue_ready )
   {
      c_adc = DEC_FORM(d32);
      #if IS_RF_MT6260RF
      c_ost = c_adc - (DEC_FORM(91)/3);
      #elif IS_RF_MT6250RF
      c_ost = c_adc - (DEC_FORM(199)>>3);
      #else
      c_ost = 0; 
      #endif
   }
   else /* If C_adc in EFUE is not ready, set C_ost as 0. */
   {  c_ost = 0;  }

   l1d_rf.thermo_adc_code_offset = (short)c_ost;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Initialize l1d_rf.thermo_adc_code and l1d_rf.k_cal */
/* Set arfcn 994 and let RF enter standby mode --> 40us --> warmup mode --> 190us --> readback CW255 --> 20us --> sleep mode */
/* Call this function in L1D_RF_PowerOn */
void L1D_RF_THADC_KCAL_Init( void )
{
   long          cw1, cw2;
   unsigned long cw255_readback;

   L1D_RF_GetTxPLLSetting( FrequencyBand900, 994, &cw1, &cw2 );
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,30), (unsigned long)cw2 );    /* CW2  : set mode = standby */
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x39, (POR_CW57&0xFE000) | (l1d_rf.AFC_data&0x1FFF)) ); /* CW57 : set AFC DAC */
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x04, POR_CW4) ); /* CW4  : optimize performance by band */
   WAIT_TIME_QB( 44 );                                      /* wait at least 40 us */
   IMM_SEND_BSI( SCTRL_IMOD(0,30), (unsigned long)cw1 );    /* CW1: set PLL, RF will enter warmup state */
   WAIT_TIME_QB( 206 );                                     /* wait at least 190 us */
   IMM_RECEIVE_BSI( 0, 0xFF, 0, &(cw255_readback) );        /* read back CW255 */
   WAIT_TIME_QB( 22 );                                      /* wait at least 20 us */
   IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_IDLE );            /* CW2: set mode = sleep mode */
   IMM_MODE_END( );

   if( cw255_readback != 0x44444 )
   {
     l1d_rf.thermo_adc_code = (short)(cw255_readback & 0x3F);
     #if IS_KCAL_COMP_TC_GAIN_SUPPORT
     l1d_rf.k_cal           = (short)((cw255_readback>>22) & 0x3FF);
     #endif
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Get temperature info from thermo sensor in RF by reading RF CW */
static int L1D_RF_THADC_GetTemperatureInfo( void )
{
   /*-------------------------------------------------*/
   /* For MT6260                                      */
   /* temp * 57 = [ C_adc - (24 + C_ost) ] * 225      */
   /* For MT6250                                      */
   /* temp * 11 = [ C_adc - (18 + C_ost) ] * 40       */
   /*-------------------------------------------------*/
   /* C_adc: RF thermo ADC code                       */
   /* C_ost: RF thermo ADC code offset                */
   /*-------------------------------------------------*/

   int temp, adc_code, is_cadc_ready;
   int c_adc, c_ost;  /* DEC_FORM: in format of S24.8 */

   /* Check if C_adc value from CW255 is reasonable. (0~63) */
   adc_code      = l1d_rf.thermo_adc_code;
   is_cadc_ready = ( (adc_code >= 0) && (adc_code < 64)) ? 1 : 0;

   /* Evaluate temperature value */
   if( is_cadc_ready )      
   {  
      c_adc = DEC_FORM(adc_code);
      c_ost = l1d_rf.thermo_adc_code_offset;
      #if IS_RF_MT6260RF
      temp  = ((c_adc - (DEC_FORM(24) + c_ost)) * 225) / 57;
      #elif IS_RF_MT6250RF
      temp  = ((c_adc - (DEC_FORM(18) + c_ost)) * 40) / 11;
      #else
      temp = DEC_FORM(25);
      #endif
   }
   else
   {  temp = DEC_FORM(25); }

   return temp;
}
      #endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static int L1D_RF_TC_Gain_Get_Temperature( void )
{
   int temperature;
 
   /* Get temperature info */
      #if IS_RF_MT6250RF || IS_RF_MT6260RF
   /* Get temperature info from thermo sensor in RF by reading RF CW */
   temperature = L1D_RF_THADC_GetTemperatureInfo();
      #elif IS_RF_MT6256RF && IS_TX_POWER_CONTROL_SUPPORT
   /* Get temperature info from thermo sensor in RF by reading RF CW */
   temperature = DEC_FORM( L1D_RF_TXPC_GetTemperatureInfo(2) );
      #else
   /* default: 25 Celsius degree */
   temperature = DEC_FORM( 25 );
      #endif

   /* Limit temperature value region */
   if ( temperature > TC_GAIN_HIGH_TEMP )
   {  temperature = TC_GAIN_HIGH_TEMP;  }
   else if ( temperature < TC_GAIN_LOW_TEMP )
   {  temperature = TC_GAIN_LOW_TEMP;  }
   
   return temperature;
 }      
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */ 

      #if IS_KCAL_COMP_TC_GAIN_SUPPORT
/* Evaluate RF K_cal/K_cal_nom ratio value for each chip. */
/* Call this function at L1D_RF_PowerOn */
void L1D_RF_KCAL_Get_Kcal_Comp_Value( void )
{
   int temp_idx, is_kcal_ready;
   int kcal_nom, temperature, temp_base, kcal_slope;  /* DEC_FORM: in form of S24.8 */
   int kcal;                                          /* in form of S16.16 */

   /* Check if K_cal value from CW255 is reasonable. (0~1023) */
   is_kcal_ready = ( (l1d_rf.k_cal >= 0) && (l1d_rf.k_cal < 1024)) ? 1 : 0;

   /* Evalute K_cal_nom value by temperature */
   if( is_kcal_ready )
   {  short KCAL_SLOPE_TABLE[TEMP_SECTION_NUM - 1] = {0};
         #if IS_RF_MT6260RF
      const short KCAL_TABLE[TEMP_SECTION_NUM] = { 234,  225,  217 }; /*LT, NT, HT*/
         #elif IS_RF_MT6250RF 
      const short KCAL_TABLE[TEMP_SECTION_NUM] = { 190,  181,  169 }; /*LT, NT, HT*/
         #endif
   
      /* Evaluate the slope of KCAL_TABLE. */
      KCAL_SLOPE_TABLE[LOW_TEMP_IND]    = TC_GAIN_SLOPE( TC_GAIN_LOW_TEMP   , TC_GAIN_NORMAL_TEMP, KCAL_TABLE[LOW_TEMP_IND]   , KCAL_TABLE[NORMAL_TEMP_IND]);
      KCAL_SLOPE_TABLE[NORMAL_TEMP_IND] = TC_GAIN_SLOPE( TC_GAIN_NORMAL_TEMP, TC_GAIN_HIGH_TEMP  , KCAL_TABLE[NORMAL_TEMP_IND], KCAL_TABLE[HIGH_TEMP_IND]  );

      /* Get temperature info */
      temperature = L1D_RF_TC_Gain_Get_Temperature();

      /* Calculate nomial K_cal value */
      temp_idx  = ( temperature >= TC_GAIN_NORMAL_TEMP ) ? NORMAL_TEMP_IND : LOW_TEMP_IND;
      temp_base = ( temperature >= TC_GAIN_NORMAL_TEMP ) ? TC_GAIN_NORMAL_TEMP : TC_GAIN_LOW_TEMP;

      kcal_slope = KCAL_SLOPE_TABLE[temp_idx];
      kcal_nom   = DEC_FORM_INV(kcal_slope * (temperature - temp_base)) + DEC_FORM(KCAL_TABLE[temp_idx]);
   }

   /* Store the ratio of (K_cal)/(K_cal_nom) */
   if( is_kcal_ready && kcal_nom )
   {  kcal = DEC_FORM(DEC_FORM(l1d_rf.k_cal));
      l1d_rf.k_cal_comp = kcal / kcal_nom;
   }
   else
   {  l1d_rf.k_cal_comp = DEC_FORM(1);  }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static int L1D_RF_KCAL_Get_Kcal_Comp_TC_Gain( int opt_tc_gain )
{
   int real_tc_gain;  /* DEC_FORM: in format of S24.8 */
   /*-------------------------------------------------------------------------------*/
   /* (15 + 3.75 * opt_tc_gain) * (K_cal) = (15 + 3.75 * real_tc_gain) *(K_cal_nom) */
   /*-------------------------------------------------------------------------------*/
   /* (60 +   15 * opt_tc_gain) * (K_cal) = (60 +   15 * real_tc_gain) *(K_cal_nom) */
   /*-------------------------------------------------------------------------------*/  
   int k_cal_comp;  /* DEC_FORM: in format of S24.8 */
   int left_term;   /* DEC_FORM: in format of S24.8 */

   /* k_cal_comp = (K_cal) / (K_cal_nom) */
   k_cal_comp = l1d_rf.k_cal_comp;

   //TH_Yeh: check if overflow may happen
   left_term = DEC_FORM_INV( (DEC_FORM(60) + 15 * opt_tc_gain) * k_cal_comp );
   real_tc_gain = (left_term - DEC_FORM(60)) / 15; 

   return real_tc_gain;
}
      #endif  /* IS_KCAL_COMP_TC_GAIN_SUPPORT */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static short L1D_RF_Get_TC_Gain( void )
{
   int temp_idx;
   int tc_gain_dec, temperature, temp_base, tc_gain_slope; /* DEC_FORM: in format of S24.8 */
   static char  tc_last_band = FrequencyBandCount;         /* initial as an invalid band */
   static short tc_gain;   
   static short tc_last_temperature;                       /* in format of S8.8 */

   /* Get temperature info */
   temperature = L1D_RF_TC_Gain_Get_Temperature();

   /* Calculate temperature compensation (TC) gain */
   if ( (temperature != tc_last_temperature) || (l1d_rf.band != tc_last_band) )
   {
      tc_last_temperature = (short)temperature;
      tc_last_band = l1d_rf.band;

      temp_idx = ( temperature >= TC_GAIN_NORMAL_TEMP ) ? NORMAL_TEMP_IND : LOW_TEMP_IND;
      temp_base = ( temperature >= TC_GAIN_NORMAL_TEMP ) ? TC_GAIN_NORMAL_TEMP : TC_GAIN_LOW_TEMP;

      tc_gain_slope = TC_GAIN_SLOPE_TABLE[l1d_rf.band][temp_idx];
      tc_gain_dec = DEC_FORM_INV(tc_gain_slope * (temperature - temp_base)) + 
                    DEC_FORM(TC_GAIN_TABLE[l1d_rf.band][temp_idx]);

         #if IS_KCAL_COMP_TC_GAIN_SUPPORT
      /* Compensate TC gain by K_cal parameter */
      tc_gain_dec = L1D_RF_KCAL_Get_Kcal_Comp_TC_Gain( tc_gain_dec );
         #endif

      /* Transform tc_gain to integer form by finding the closest integer. */
      tc_gain = DEC_FORM_INV( (tc_gain_dec+(DEC_FORM(1)>>1)) );
   }

   /* Limit tc_gain region */
   if( tc_gain > TC_GAIN_MASK )
   {  tc_gain = TC_GAIN_MASK;  }
   else if( tc_gain < 0 )
   {  tc_gain = 0;  }

   return tc_gain;
}
   #else /* IS_TEMP_COMP_TC_GAIN_SUPPORT */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const char TC_GAIN_TABLE[FrequencyBandCount] = 
{      /* RF_MT6255RF */
   0,  /* GSM400 */
   8,  /* GSM850 */
   6,  /* GSM900 */
   8,  /* DCS1800 */
   5   /* PCS1900 */
};
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static short L1D_RF_Get_TC_Gain( void )
{
   return (TC_GAIN_TABLE[l1d_rf.band] & TC_GAIN_MASK);
}

   #endif /* IS_TEMP_COMP_TC_GAIN_SUPPORT */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned long L1D_RF_Get_TC_Gain_CW( void )
{
   #if IS_RF_MT6260RF
   //Composte CW at m12195.c ,just return TC Gain.
   return L1D_RF_Get_TC_Gain();
   #else //IS_RF_MT6250RF || IS_RF_MT6256RF
   unsigned long cw = TC_GAIN_CW;

   cw &= ~TC_GAIN_CW_MASK;
   cw |= (L1D_RF_Get_TC_Gain() << TC_GAIN_CW_LSB);
   return cw;
   #endif
}
#endif  /* IS_BAND_COMP_TC_GAIN_SUPPORT */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void L1D_RF_Init_Data( void )
{
   l1d_rf.cwin_idx      = 0;
/* l1d_rf.band          = 0; */
/* l1d_rf.rtxwin_idx    = 0; */
   l1d_rf.cur_slot      = 0;
   l1d_rf.cur_slot_n    = 0;
   l1d_rf.rx_slots      = 0;
   l1d_rf.tx_slots      = 0;
   l1d_rf.apc_dc_offset = 0;
   l1d_rf.bat_volt      = 1;
   l1d_rf.bat_temp      = 1;
   l1d_rf.egsm_disable  = IS_EGSM900_DISABLE;
/* l1d.is_init          = 0; */
#if IS_DYNAMIC_MACRO_SUPPORT
   l1d_rf2.is_wakeup    = 0;
#endif
#if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
   l1d_rf.is_power_on_stage_1   = 0;
   l1d_rf.is_power_on_stage_2   = 0;
   l1d_rf.power_on_stage2_enter = 0;
   l1d_rf.power_on_stage2_leave = 0;
#endif
#if IS_RF_MT6256RF
   #if IS_EPSK_TX_SUPPORT
   l1d_rf2.tx_power_sel = 0;
   #endif
   l1d_rf2.r_cal        = L1D_RF_Get_BT_Rcal();
#endif
#if IS_OBB_DETECTION_SUPPORT
   l1d_rf.if_change     = 1;
   l1d_rf.obb_arfcn     = -1;
#endif

#if IS_HEADROOM_DETECTION_SUPPORT ||       \
    IS_INBAND_BLOCKER_DETECTION_SUPPORT || \
    IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
   l1d_rf.blk_flag      = 0;
#endif


#if IS_TEMP_COMP_TC_GAIN_SUPPORT
   #if IS_RF_MT6250RF || IS_RF_MT6260RF
   l1d_rf.thermo_adc_code        = 0; /* range: 0 ~ 63 (6-bits) */
   l1d_rf.thermo_adc_code_offset = 0; /* in form of S8.8        */
   #endif
   #if IS_KCAL_COMP_TC_GAIN_SUPPORT
   l1d_rf.k_cal                  = 0; /* range: 0~ 1023 (10-bits) */
   l1d_rf.k_cal_comp             = 0; /* in form of S8.8          */
                                      /* k_cal_comp = (k_cal_nom)/(k_cal) */
   #endif
#endif

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
   l1d_rf.dcxo_lpm      = 0;
   l1d_rf.is_lock_dcxo  = 0;
#endif
/* l1d.bb_tx_autocal    = 0; */
   l1d_rf.AFC_data      = PSI_EE;
/* l1d_rf.RFN_data      = 0; */
/* l1d_rf.IFN_data      = 0; */
/* l1d_rf.AGC_data      = 0; */
#if IS_RF_AD6546
   l1d_rf.handle_tx_dcm = 1;
#else
   l1d_rf.handle_tx_dcm = 0;
#endif

#if IS_DCXO_SUPPORT_CHIP && IS_AFC_EVENT_SUPPORT_CHIP
   #if IS_AFC_EVENT_ENABLE
   l1d_rf.is_afc_event_enable = 1;
   #else
   l1d_rf.is_afc_event_enable = 0;
   #endif
   #if IS_AFC_TRIGGER_BSI_SUPPORT
   l1d_rf.is_afc_trigger_bsi  = 1;
   #else
   l1d_rf.is_afc_trigger_bsi  = 0;
   #endif
#endif

#if IS_BT_COCLOCK_SUPPORT
   #if IS_RF_AD6548 || IS_RF_AD6546
   l1d_rf.gpio_modeswitch = 1;
   #else
   l1d_rf.gpio_modeswitch = 0;
   #endif
#else
   l1d_rf.gpio_modeswitch = 0;
#endif

#if IS_BBTXRX_CHIP_DESIGN_VER_2
   l1d_rf.rx_dc_i              = 0;
   l1d_rf.rx_dc_q              = 0;
   l1d_rf.cal_band             = 0;
   #if IS_RF_RX_DCOC_SUPPORT
   l1d_rf.is_rf_rxdcoc_support = 1;
   #else
   l1d_rf.is_rf_rxdcoc_support = 0;
   #endif
   #if IS_RF_TX_CALIBRATION_SUPPORT
   l1d_rf.is_rf_txiqmm_support = 1;
   #else
   l1d_rf.is_rf_txiqmm_support = 0;
   #endif
#endif

#if IS_WIFI_ADAPTIVE_POWER_CONTROL_SUPPORT
   l1d_rf.wifi_low_pwr_flag   = 0;
   l1d_rf.rx_power_flag       = 0;
#endif
#if IS_RF_VCO_DOO_OFF || IS_RF_VCO_PARTIAL_DOO_ON || IS_WIFI_ADAPTIVE_POWER_CONTROL_SUPPORT
   l1d_rf2.dedicated_flag      = 0;
#endif
#if IS_RF_VCO_DOO_OFF || IS_RF_VCO_PARTIAL_DOO_ON
   l1d_rf2.rx_pm_flag          = 0;
   l1d_rf2.tx_1st_cwin_idx     = 0;
#endif

#if IS_RF_MT6162
   l1d_rf2.is_2g_on            = 0;
   l1d_rf2.lpfcap              = 0;
   l1d_rf2.is_rx_cal           = 0;
   l1d_rf2.is_tx_cal           = 0;
   l1d_rf2.is_isotpol          = 0;
   l1d_rf2.is_integer          = 0;
   l1d_rf2.rx_dc_offset        = 0;
   l1d_rf2.is_fix_rf1828       = 0;
   #if IS_RF_RX_DCOC_SUPPORT
   L1D_RF_RXDCOffset_Init();
   l1d_rf2.rx_dac_to_voltage_i = 0;
   l1d_rf2.rx_dac_to_voltage_q = 0;
   #endif
   #if IS_RF_TX_CALIBRATION_SUPPORT
   L1D_RF_TXIQMM_Init();
   #endif
#endif

#if IS_DECREASE_RF_TX_MAX_POWER_SUPPORT
   l1d_rf.tx_power_decrement   = 0;
#endif

   L1D_RF_INIT_TXPC_DATA();
#if IS_TEMP_COMP_TC_GAIN_SUPPORT
   L1D_RF_Init_TC_Gain_Slope();
#endif

#if IS_DCS_NB_WB_SWITCH_SUPPORT
   L1D_RF_Init_DCS_NB_WB_Switch();
#endif

#if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
   L1D_RF_Init_TX_Notch_Switch();
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void L1D_RF_Init_GPIO( void )
{
#if MT6261_BSI_DEBUG
   {  
      HW_WRITE( MODEM_DBG_SEL ,(HW_READ(MODEM_DBG_SEL)|0x0009) );   //DBG_SEL=9 (BSI)
      HW_WRITE( DEBUG_MODED0  , 0x2000 );                           //RG_DEBUG_MODE0 | (1<<13)

      // (GPIO12_M , GPIO13_M , GPIO15_M)
      HW_WRITE( GPIO_MODE1    ,(HW_READ( GPIO_MODE1 )|0x70770000));
      // (GPIO18_M , GPIO19_M , GPIO20_M)
      HW_WRITE( GPIO_MODE2    ,(HW_READ( GPIO_MODE2 )|0x00077700));
   }
#endif

#if !defined(L1_SIM) && !defined(__CUST_NEW__)
   unsigned short d16,d16and,d16or,i;
   d16    = 0;
   d16and = 0;
   d16or  = 0;

   #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   for(i=0; i<FrequencyBandCount; i++)
   {
      d16|=PDATA_TABLE[i][RF_RX][0];         /* PR1   */
      d16|=PDATA_TABLE[i][RF_RX][1];         /* PR2   */
      d16|=PDATA_TABLE[i][RF_RX][2];         /* PR2B  */
      d16|=PDATA_TABLE[i][RF_RX][3];         /* PR3   */
      d16|=PDATA_TABLE[i][RF_RX][4];         /* PR3A  */
      d16|=PDATA_TABLE[i][RF_TX][0];         /* PT1   */
      d16|=PDATA_TABLE[i][RF_TX][1];         /* PT2   */
      d16|=PDATA_TABLE[i][RF_TX][2];         /* PT2B  */
      d16|=PDATA_TABLE[i][RF_TX][3];         /* PT3   */
      d16|=PDATA_TABLE[i][RF_TX][4];         /* PT3A  */
      d16|=PDATA_TABLE3[i][RF_RX][0];        /* PR2M1 */
      d16|=PDATA_TABLE3[i][RF_RX][1];        /* PR2M2 */
      d16|=PDATA_TABLE3[i][RF_RX][2];        /* PR2M3 */
      d16|=PDATA_TABLE3[i][RF_TX][0];        /* PT2M1 */
      d16|=PDATA_TABLE3[i][RF_TX][1];        /* PT2M3 */
      d16|=PDATA_TABLE3[i][RF_TX][2];        /* PT2M3 */
      d16|=PDATA_TABLE3[i][RF_TX_8G][0];     /* PT2M1 */
      d16|=PDATA_TABLE3[i][RF_TX_8G][1];     /* PT2M2 */
      d16|=PDATA_TABLE3[i][RF_TX_8G][2];     /* PT2M3 */

      d16|=PDATA_GMSK;
      d16|=PDATA_8PSK;
   }
   #else
   for(i=0; i<FrequencyBandCount; i++)
   {
      d16|=PDATA_TABLE[i][RF_RX][0];         /* PR1   */
      d16|=PDATA_TABLE[i][RF_RX][1];         /* PR2   */
      d16|=PDATA_TABLE[i][RF_RX][2];         /* PR3   */
      d16|=PDATA_TABLE[i][RF_TX][0];         /* PT1   */
      d16|=PDATA_TABLE[i][RF_TX][1];         /* PT2   */
      d16|=PDATA_TABLE[i][RF_TX][2];         /* PT3   */
      #if IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ d16|=PDATA_TABLE2[i][RF_RX][0];  /* PR2M1 */
/*MT6218~*/ d16|=PDATA_TABLE2[i][RF_RX][1];  /* PR2M2 */
/*MT6218~*/ d16|=PDATA_TABLE2[i][RF_TX][0];  /* PT2B  */
      #endif
   }
   #endif

   #if IS_CHIP_MT6208
   /*MT6208*/ #ifndef __CUST_NEW__
   /*MT6208*/ /* All GPIO config is set by L1D in MT6208 */
   /*MT6208*/ /* config GPIO_MODE2[3:2]=1 to set GPIO9=BSI_CS1 */
   /*MT6208*/ HW_WRITE( GPIO_MODE1, 0x00AA );
   /*MT6208*/ HW_WRITE( GPIO_MODE2, 0x0004 );
   /*MT6208*/ HW_WRITE( GPIO_MODE3, 0x4001 );
   /*MT6208*/
   /*MT6208*/ d16 = HW_READ( GPIO_DIR );
   /*MT6208*/ d16 &= ~0x020F;
   /*MT6208*/ d16 |=  0xFFF9;
   /*MT6208*/ HW_WRITE( GPIO_DIR, d16 );
   /*MT6208*/ #endif /* __CUST_NEW__*/
   /*MT6208*/
   /*MT6208*/ d16 = HW_READ( PDN_CON1 );
   /*MT6208*/ d16 &= ~0x0004;
   /*MT6208*/ HW_WRITE( PDN_CON1, d16 );
   /*MT6208*/
   /*MT6208*/ /*--------------------------------*/
   /*MT6208*/ /* Turn on RF Main Power -- PSAVE */
   /*MT6208*/ /*--------------------------------*/
   /*MT6208*/ {void L1D_GPO_WriteIO(char ,char );
   /*MT6208*/ #ifdef __CUST_NEW__
   /*MT6208*/ extern const char gpio_rf_control2_pin;
   /*MT6208*/ L1D_GPO_WriteIO( 1, gpio_rf_control2_pin); /* ( val, bit ) */
   /*MT6208*/ #else
   /*MT6208*/ L1D_GPO_WriteIO( 1, 1 ); /* ( val, bit ) */
   /*MT6208*/ #endif
   /*MT6208*/ }
   #endif

   #if IS_CHIP_MT6205
   /*MT6205*/ /* if needed to config GPIO_MODE1[9:8]=1 to set GPIO4=BPI_BUS4 */
   /*MT6205*/ /* if needed to config GPIO_MODE1[B:A]=1 to set GPIO5=BPI_BUS5 */
   /*MT6205*/ /* if needed to config GPIO_MODE1[D:C]=1 to set GPIO6=BPI_BUS6 */
   /*MT6205*/ /* if needed to config GPIO_MODE1[F:E]=1 to set GPIO7=BPI_BUS7 */
   /*MT6205*/
   /*MT6205*/ #ifndef __CUST_NEW__
   /*MT6205*/ for(i=4; i<8; i++)             /* only check BPI4~7 */
   /*MT6205*/ {
   /*MT6205*/    if(d16>>i & 0x0001)         /* if this BPI needed */
   /*MT6205*/    {
   /*MT6205*/      d16and |= 0x0003<<(i*2);  /* only set this needed pin as BPI */
   /*MT6205*/      d16or  |= 0x0001<<(i*2);
   /*MT6205*/    }
   /*MT6205*/ }
   /*MT6205*/
   /*MT6205*/ d16 = HW_READ( GPIO_MODE1 );
   /*MT6205*/ d16 &= ~d16and;
   /*MT6205*/ d16 |=  d16or;
   /*MT6205*/ HW_WRITE( GPIO_MODE1, d16 );
   /*MT6205*/
   /*MT6205*/ #if IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6205*/ #endif
   /*MT6205*/
   /*MT6205*/ #if IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D || IS_RF_MT6139B || IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B || IS_RF_MT6139E || IS_RF_MT6140D
   /*MT6205*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6205*//*MT6119C*/ /* config GPIO_MODE1[F:E]=0 to set GPIO7=GPO7 */
   /*MT6205*//*MT6119C*/ d16 = HW_READ( GPIO_MODE1 );
   /*MT6205*//*MT6119C*/ d16 &= ~0xC000;
   /*MT6205*//*MT6119C*/ HW_WRITE( GPIO_MODE1, d16 );
   /*MT6205*//*MT6119C*/ d16 = HW_READ( GPIO_DIR1 );
   /*MT6205*//*MT6119C*/ d16 |=  0x0080;
   /*MT6205*//*MT6119C*/ HW_WRITE( GPIO_DIR1, d16 );
   /*MT6205*/     #endif
   /*MT6205*/ #endif
   /*MT6205*/ #endif /* __CUST_NEW__ */
   #endif

   #if IS_CHIP_MT6218A
   /*MT6218A*/ /* if needed to config GPIO_MODE2[1:0]=1 to set GPIO8=BPI_BUS7 */
   /*MT6218A*/ /* if needed to config GPIO_MODE2[3:2]=1 to set GPIO9=BPI_BUS8 */
   /*MT6218A*/ /* if needed to config GPIO_MODE2[5:4]=1 to set GPIOA=BPI_BUS9 */
   /*MT6218A*/
   /*MT6218A*/ #ifndef __CUST_NEW__
   /*MT6218A*/ for(i=7; i<10; i++)                /* only check BPI7~9 */
   /*MT6218A*/ {
   /*MT6218A*/    if(d16>>i & 0x0001)             /* if this BPI needed */
   /*MT6218A*/    {
   /*MT6218A*/      d16and |= 0x0003<<((i-7)*2);  /* only set this needed pin as BPI */
   /*MT6218A*/      d16or  |= 0x0001<<((i-7)*2);
   /*MT6218A*/    }
   /*MT6218A*/ }
   /*MT6218A*/
   /*MT6218A*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6218A*/ d16 &= ~d16and;
   /*MT6218A*/ d16 |=  d16or;
   /*MT6218A*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6218A*/
   /*MT6218A*/ #if IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6218A*/ #endif
   /*MT6218A*/
   /*MT6218A*/ #if IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D || IS_RF_MT6139B || IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B
   /*MT6218A*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6218A*//*MT6119C*/ /* config GPIO_MODE2[5:4]=0 to set GPIOA=GPOA */
   /*MT6218A*//*MT6119C*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6218A*//*MT6119C*/ d16 &= ~0x0030;
   /*MT6218A*//*MT6119C*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6218A*//*MT6119C*/ d16 = HW_READ( GPIO_DIR1 );
   /*MT6218A*//*MT6119C*/ d16 |=  0x0400;
   /*MT6218A*//*MT6119C*/ HW_WRITE( GPIO_DIR1, d16 );
   /*MT6218A*/     #endif
   /*MT6218A*/ #endif
   /*MT6218A*/ #endif /* __CUST_NEW__ */
   #endif

   #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
   /*MT6218B~*/ /* if needed to config GPIO_MODE2[5:4]=1 to set GPIOA=BPI_BUS6 */
   /*MT6218B~*/ /* if needed to config GPIO_MODE2[7:6]=1 to set GPIOB=BPI_BUS7 */
   /*MT6218B~*/ /* if needed to config GPIO_MODE2[9:8]=1 to set GPIOC=BPI_BUS8 */
   /*MT6218B~*/ /* if needed to config GPIO_MODE2[11:10]=1 to set GPIOD=BPI_BUS9 */
   /*MT6218B~*/
   /*MT6218B~*/ #ifndef __CUST_NEW__
   /*MT6218B~*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6218B~*/ {
   /*MT6218B~*/    if(d16>>i & 0x0001)             /* if this BPI needed */
   /*MT6218B~*/    {
   /*MT6218B~*/      d16and |= 0x0003<<((i-4)*2);  /* only set this needed pin as BPI */
   /*MT6218B~*/      d16or  |= 0x0001<<((i-4)*2);
   /*MT6218B~*/    }
   /*MT6218B~*/ }
   /*MT6218B~*/
   /*MT6218B~*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6218B~*/ d16 &= ~d16and;
   /*MT6218B~*/ d16 |=  d16or;
   /*MT6218B~*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6218B~*/
   /*MT6218B~*/ #if IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6218B~*/ #endif
   /*MT6218B~*/
   /*MT6218B~*/ #if IS_RF_SKY74117
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6218B~*/ #endif
   /*MT6218B~*/
   /*MT6218B~*/  #if IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D || IS_RF_MT6139B || IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B
   /*MT6218B~*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6218B~*//*MT6119C*/ /* config GPIO_MODE2[11:10]=0 to set GPIOD=GPOD */
   /*MT6218B~*//*MT6119C*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6218B~*//*MT6119C*/ d16 &= ~0x0C00;
   /*MT6218B~*//*MT6119C*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6218B~*//*MT6119C*/ d16 = HW_READ( GPIO_DIR1 );
   /*MT6218B~*//*MT6119C*/ d16 |=  0x2000;
   /*MT6218B~*//*MT6119C*/ HW_WRITE( GPIO_DIR1, d16 );
   /*MT6218B~*/     #endif
   /*MT6218B~*/ #endif
   /*MT6218B~*/ #endif /* __CUST_NEW__ */
   #endif

   #if IS_CHIP_MT6228
   /*MT6228~*/ /* if needed to config GPIO_MODE3[1:0]=1 to set GPIOA=BPI_BUS6 */
   /*MT6228~*/ /* if needed to config GPIO_MODE3[3:2]=1 to set GPIOB=BPI_BUS7 */
   /*MT6228~*/ /* if needed to config GPIO_MODE3[5:4]=1 to set GPIOC=BPI_BUS8 */
   /*MT6228~*/ /* if needed to config GPIO_MODE3[7:6]=1 to set GPIOD=BPI_BUS9 */
   /*MT6228~*/
   /*MT6228~*/ #ifndef __CUST_NEW__
   /*MT6228~*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6228~*/ {
   /*MT6228~*/    if(d16>>i & 0x0001)             /* if this BPI needed */
   /*MT6228~*/    {
   /*MT6228~*/      d16and |= 0x0003<<((i-6)*2);  /* only set this needed pin as BPI */
   /*MT6228~*/      d16or  |= 0x0001<<((i-6)*2);
   /*MT6228~*/    }
   /*MT6228~*/ }
   /*MT6228~*/
   /*MT6228~*/ d16 = HW_READ( GPIO_MODE3 );
   /*MT6228~*/ d16 &= ~d16and;
   /*MT6228~*/ d16 |=  d16or;
   /*MT6228~*/ HW_WRITE( GPIO_MODE3, d16 );
   /*MT6228~*/
   /*MT6228~*/ #if IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6228~*/ #endif
   /*MT6228~*/
   /*MT6228~*/ #if IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D || IS_RF_MT6139B || IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B
   /*MT6228~*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6228~*//*MT6119C*/ /* config GPIO_MODE2[11:10]=0 to set GPIOD=GPOD */
   /*MT6228~*//*MT6119C*/ d16 = HW_READ( GPIO_MODE3 );
   /*MT6228~*//*MT6119C*/ d16 &= ~0x00C0;
   /*MT6228~*//*MT6119C*/ HW_WRITE( GPIO_MODE3, d16 );
   /*MT6228~*//*MT6119C*/ d16 = HW_READ( GPIO_DIR2 );
   /*MT6228~*//*MT6119C*/ d16 |=  0x0008;
   /*MT6228~*//*MT6119C*/ HW_WRITE( GPIO_DIR2, d16 );
   /*MT6228~*/     #endif
   /*MT6228~*/ #endif
   /*MT6228~*/ #endif /* __CUST_NEW__ */
   #endif

   #if IS_CHIP_MT6225_AND_LATTER_VERSION
   /*MT6225~*/ /* if needed to config GPIO_MODE4[3:2]=1 to set GPIO25=BPI_BUS6 */
   /*MT6225~*/ /* if needed to config GPIO_MODE4[5:4]=1 to set GPIO26=BPI_BUS7 */
   /*MT6225~*/ /* if needed to config GPIO_MODE4[7:6]=1 to set GPIO27=BPI_BUS8 */
   /*MT6225~*/ /* if needed to config GPIO_MODE4[9:8]=1 to set GPIO28=BPI_BUS9 */
   /*MT6225~*/
   /*MT6225~*/ #ifndef __CUST_NEW__
   /*MT6225~*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6225~*/ {
   /*MT6225~*/    if(d16>>i & 0x0001)             /* if this BPI needed */
   /*MT6225~*/    {
   /*MT6225~*/      d16and |= 0x0003<<((i-5)*2);  /* only set this needed pin as BPI */
   /*MT6225~*/      d16or  |= 0x0001<<((i-5)*2);
   /*MT6225~*/    }
   /*MT6225~*/ }
   /*MT6225~*/
   /*MT6225~*/ d16 = HW_READ( GPIO_MODE4 );
   /*MT6225~*/ d16 &= ~d16and;
   /*MT6225~*/ d16 |=  d16or;
   /*MT6225~*/ HW_WRITE( GPIO_MODE4, d16 );
   /*MT6225~*/
   /*MT6225~*/ #if IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6225~*/ #endif
   /*MT6225~*/
   /*MT6225~*/ #if IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D || IS_RF_MT6139B || IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B
   /*MT6225~*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6225~*//*MT6119C*/ /* config GPIO_MODE4[9:8]=0 to set GPIO28=GPO28 */
   /*MT6225~*//*MT6119C*/ d16 = HW_READ( GPIO_MODE4 );
   /*MT6225~*//*MT6119C*/ d16 &= ~0x0300;
   /*MT6225~*//*MT6119C*/ HW_WRITE( GPIO_MODE4, d16 );
   /*MT6225~*//*MT6119C*/ d16 = HW_READ( GPIO_DIR2 );
   /*MT6225~*//*MT6119C*/ d16 |=  0x1000;
   /*MT6225~*//*MT6119C*/ HW_WRITE( GPIO_DIR2, d16 );
   /*MT6225~*/    #endif
   /*MT6225~*/ #endif
   /*MT6225~*/ #endif /* __CUST_NEW__ */
   #endif

   #if IS_CHIP_MT6229||IS_CHIP_MT6268T
   /*MT6229~*/ /* if needed to config GPIO_MODE2[5:4]=1 to set GPIOA=BPI_BUS6 */
   /*MT6229~*/ /* if needed to config GPIO_MODE2[7:6]=1 to set GPIOB=BPI_BUS7 */
   /*MT6229~*/ /* if needed to config GPIO_MODE2[9:8]=1 to set GPIOC=BPI_BUS8 */
   /*MT6229~*/ /* if needed to config GPIO_MODE2[11:10]=1 to set GPIOD=BPI_BUS9 */
   /*MT6229~*/
   /*MT6229~*/ #ifndef __CUST_NEW__
   /*MT6229~*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6229~*/ {
   /*MT6229~*/    if(d16>>i & 0x0001)             /* if this BPI needed */
   /*MT6229~*/    {
   /*MT6229~*/      d16and |= 0x0003<<((i-6)*2);  /* only set this needed pin as BPI */
   /*MT6229~*/      d16or  |= 0x0001<<((i-6)*2);
   /*MT6229~*/    }
   /*MT6229~*/ }
   /*MT6229~*/
   /*MT6229~*/ d16 = HW_READ( GPIO_MODE3 );
   /*MT6229~*/ d16 &= ~d16and;
   /*MT6229~*/ d16 |=  d16or;
   /*MT6229~*/ HW_WRITE( GPIO_MODE3, d16 );
   /*MT6229~*/
   /*MT6229~*/ #if IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D || IS_RF_MT6139B || IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B
   /*MT6229~*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6229~*//*MT6119C*/ /* config GPIO_MODE2[11:10]=0 to set GPIOD=GPOD */
   /*MT6229~*//*MT6119C*/ d16 = HW_READ( GPIO_MODE3 );
   /*MT6229~*//*MT6119C*/ d16 &= ~0x00C0;
   /*MT6229~*//*MT6119C*/ HW_WRITE( GPIO_MODE3, d16 );
   /*MT6229~*//*MT6119C*/ d16 = HW_READ( GPIO_DIR2 );
   /*MT6229~*//*MT6119C*/ d16 |=  0x0008;
   /*MT6229~*//*MT6119C*/ HW_WRITE( GPIO_DIR2, d16 );
   /*MT6229~*/     #endif
   /*MT6229~*/ #endif
   /*MT6229~*/ #endif /* __CUST_NEW__ */
   /*MT6229~*/
   #endif

   #if IS_CHIP_MT6223
   /*MT6223~*/ /* if needed to config GPIO_MODE3[ 9: 8]=1 to set GPIO20=BPI_BUS6 */
   /*MT6223~*/ /* if needed to config GPIO_MODE3[11:10]=1 to set GPIO21=BPI_BUS7 */
   /*MT6223~*/ /* if needed to config GPIO_MODE3[13:12]=1 to set GPIO22=BPI_BUS8 */
   /*MT6223~*/ /* if needed to config GPIO_MODE3[15:14]=1 to set GPIO23=BPI_BUS9 */
   /*MT6223~*/
   /*MT6223~*/ #ifndef __CUST_NEW__
   /*MT6223~*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6223~*/ {
   /*MT6223~*/    if( (d16>>i) & 0x0001)          /* if this BPI needed */
   /*MT6223~*/    {
   /*MT6223~*/      d16and |= 0x0003<<((i-2)*2);  /* only set this needed pin as BPI */
   /*MT6223~*/      d16or  |= 0x0001<<((i-2)*2);
   /*MT6223~*/    }
   /*MT6223~*/ }
   /*MT6223~*/
   /*MT6223~*/ d16 = HW_READ( GPIO_MODE3 );
   /*MT6223~*/ d16 &= ~d16and;
   /*MT6223~*/ d16 |=  d16or;
   /*MT6223~*/ HW_WRITE( GPIO_MODE3, d16 );
   /*MT6223~*/
   /*MT6223~*/ #if IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D || IS_RF_MT6139B || IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B
   /*MT6223~*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6223~*/       /* config GPIO_MODE3[15:14]=0 to set GPIO23(BPI9) as GPIO function */
   /*MT6223~*/       d16 = HW_READ( GPIO_MODE3 );
   /*MT6223~*/       d16 &= ~0xC000;
   /*MT6223~*/       HW_WRITE( GPIO_MODE3, d16 );
   /*MT6223~*/       /* config GPIO_DIR2[7]=1 to set GPIO23 as output */
   /*MT6223~*/       d16 = HW_READ( GPIO_DIR2 );
   /*MT6223~*/       d16 |=  0x0080;
   /*MT6223~*/       HW_WRITE( GPIO_DIR2, d16 );
   /*MT6223~*/    #endif /* End of "RFVCO_SW_CONTROL" */
   /*MT6223~*/ #endif
   /*MT6223~*/ #endif /* __CUST_NEW__ */
   /*MT6223~*/
   #endif

   #if IS_CHIP_MT6238
   /*MT6238*/ /* if needed to config GPIO_MODE2[ 5: 4]=1 to set GPIO10=BPI_BUS6 */
   /*MT6238*/ /* if needed to config GPIO_MODE2[ 7: 6]=1 to set GPIO11=BPI_BUS7 */
   /*MT6238*/ /* if needed to config GPIO_MODE2[ 9: 8]=1 to set GPIO12=BPI_BUS8 */
   /*MT6238*/ /* if needed to config GPIO_MODE2[11:10]=1 to set GPIO13=BPI_BUS9 */
   /*MT6238*/
   /*MT6238*/ #ifndef __CUST_NEW__
   /*MT6238*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6238*/ {
   /*MT6238*/    if( (d16>>i) & 0x0001)          /* if this BPI needed */
   /*MT6238*/    {
   /*MT6238*/      d16and |= 0x0003<<((i-4)*2);  /* only set this needed pin as BPI */
   /*MT6238*/      d16or  |= 0x0001<<((i-4)*2);
   /*MT6238*/    }
   /*MT6238*/ }
   /*MT6238*/
   /*MT6238*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6238*/ d16 &= ~d16and;
   /*MT6238*/ d16 |=  d16or;
   /*MT6238*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6238*/
   /*MT6238*/ #if IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D || IS_RF_MT6139B || IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B
   /*MT6238*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6238*/       /* config GPIO_MODE2[11:10]=0 to set GPIO13(BPI9) as GPIO function */
   /*MT6238*/       d16 = HW_READ( GPIO_MODE2 );
   /*MT6238*/       d16 &= ~0x0C00;
   /*MT6238*/       HW_WRITE( GPIO_MODE2, d16 );
   /*MT6238*/       /* config GPIO_DIR1[13]=1 to set GPIO13 as output */
   /*MT6238*/       d16  = HW_READ( GPIO_DIR1 );
   /*MT6238*/       d16 |=  0x2000;
   /*MT6238*/       HW_WRITE( GPIO_DIR1, d16 );
   /*MT6238*/    #endif /* End of "RFVCO_SW_CONTROL" */
   /*MT6238*/ #endif
   /*MT6238*/ #endif /* __CUST_NEW__ */
   /*MT6238*/
   #endif

   #if IS_SMARTPHONE_CHIP_TK6516_AND_LATTER_VERSION
   /*TK6516*/ /* if needed to config GPIO_MODE1[ 1: 0]=1 to set GPIO00=BPI_BUS6 */
   /*TK6516*/ /* if needed to config GPIO_MODE1[ 3: 2]=1 to set GPIO01=BPI_BUS7 */
   /*TK6516*/ /* if needed to config GPIO_MODE1[ 5: 4]=1 to set GPIO02=BPI_BUS8 */
   /*TK6516*/ /* if needed to config GPIO_MODE1[ 7: 6]=1 to set GPIO03=BPI_BUS9 */
   /*TK6516*/
      #ifndef __CUST_NEW__
   /*TK6516*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*TK6516*/ {
   /*TK6516*/    if( (d16>>i) & 0x0001)          /* if this BPI needed */
   /*TK6516*/    {
   /*TK6516*/       d16and |= 0x0003<<((i-6)*2); /* only set this needed pin as BPI */
   /*TK6516*/       d16or  |= 0x0001<<((i-6)*2);
   /*TK6516*/    }
   /*TK6516*/ }
   /*TK6516*/
   /*TK6516*/ d16 = HW_READ( GPIO_MODE1 );
   /*TK6516*/ d16 &= ~d16and;
   /*TK6516*/ d16 |=  d16or;
   /*TK6516*/ HW_WRITE( GPIO_MODE1, d16 );
   /*TK6516*/
         #if IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D || IS_RF_MT6139B || IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B
            #ifndef RFVCO_SW_CONTROL /* HW control */
   /*TK6516*/ /* config GPIO_MODE1[ 7: 6]=0 to set GPIO03(BPI9) as GPIO function */
   /*TK6516*/ d16 = HW_READ( GPIO_MODE1 );
   /*TK6516*/ d16 &= ~0x00C0;
   /*TK6516*/ HW_WRITE( GPIO_MODE1, d16 );
   /*TK6516*/ /* config GPIO_DIR1[03]=1 to set GPIO03 as output */
   /*TK6516*/ d16  = HW_READ( GPIO_DIR1 );
   /*TK6516*/ d16 |=  0x0008;
   /*TK6516*/ HW_WRITE( GPIO_DIR1, d16 );
            #endif /* End of "RFVCO_SW_CONTROL" */
         #endif
      #endif /* __CUST_NEW__ */
   /*TK6516*/
   #endif

   #if IS_CHIP_MT6268
   /*MT6268*/ /* if needed to config GPIO_MODE1[ 1: 0]=01 to set GPIO00=BPI_BUS0 */
   /*MT6268*/ /* if needed to config GPIO_MODE1[ 3: 2]=01 to set GPIO01=BPI_BUS1 */
   /*MT6268*/ /* if needed to config GPIO_MODE1[ 5: 4]=01 to set GPIO02=BPI_BUS2 */
   /*MT6268*/ /* if needed to config GPIO_MODE1[ 7: 6]=01 to set GPIO03=BPI_BUS3 */
   /*MT6268*/ /* if needed to config GPIO_MODE1[ 9: 8]=01 to set GPIO04=BPI_BUS9 */
   /*MT6268*/ /* if needed to config GPIO_MODE1[11:10]=01 to set GPIO05=BPI_BUS10*/
   /*MT6268*/

      #ifndef __CUST_NEW__
   /*MT6268*/ for(i=0; i<6; i++)
   /*MT6268*/ {
   /*MT6268*/    if( i<4 ) /* check BPI0~3 */
   /*MT6268*/    {
   /*MT6268*/       if( (d16>>i) & 0x0001)      /* if this BPI needed */
   /*MT6268*/       {
   /*MT6268*/          d16and |= 0x0003<<(i*2); /* only set this needed pin as BPI */
   /*MT6268*/          d16or  |= 0x0001<<(i*2);
   /*MT6268*/       }
   /*MT6268*/    }
   /*MT6268*/    else /* check BPI9~10 */
   /*MT6268*/    {
   /*MT6268*/       if( (d16>>(i+5)) & 0x0001)  /* if this BPI needed */
   /*MT6268*/       {
   /*MT6268*/          d16and |= 0x0003<<(i*2); /* only set this needed pin as BPI */
   /*MT6268*/          d16or  |= 0x0001<<(i*2);
   /*MT6268*/       }
   /*MT6268*/    }
   /*MT6268*/ }
   /*MT6268*/
   /*MT6268*/ d16 = HW_READ( GPIO_MODE1 );
   /*MT6268*/ d16 &= ~d16and;
   /*MT6268*/ d16 |=  d16or;
   /*MT6268*/ HW_WRITE( GPIO_MODE1, d16 );
   /*MT6268*/
   /*MT6268*/
   /*MT6268*/ /*BPI3,16,17*/
   /*MT6268*/ d16 = HW_READ(GPIO_MODE1);
   /*MT6268*/ d16 &= 0x0f3f;
   /*MT6268*/ d16 |= 0x5040;
   /*MT6268*/ HW_WRITE( GPIO_MODE1, d16 );
   /*MT6268*/ /*BPI18,19,BSI1*/
   /*MT6268*/ d16 = HW_READ(GPIO_MODE2);
   /*MT6268*/ d16 &= 0xc030;
   /*MT6268*/ d16 |= 0x1545;
   /*MT6268*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6268*/
         #if IS_CHIP_MT6268A
   /*MT6268*/ /*PASEL to PMIC*/
   /*MT6268*/ d16 = HW_READ(GPIO_MODE5);
   /*MT6268*/ d16 &= 0xCFFF;
   /*MT6268*/ d16 |= 0x1000;
   /*MT6268*/ HW_WRITE( GPIO_MODE5, d16 );
   /*MT6268*/
   /*MT6268*/ /*vm0 and vm1*/
   /*MT6268*/ d16 = HW_READ(GPIO_MODEA);
   /*MT6268*/ d16 &= 0x0FFF;
   /*MT6268*/ d16 |= 0xF000;
   /*MT6268*/ HW_WRITE( GPIO_MODEA, d16 );
         #else
   /*MT6268*/ /*PASEL to PMIC*/
   /*MT6268*/ d16 = HW_READ(GPIO_MODE6);
   /*MT6268*/ d16 &= 0xFFCF;
   /*MT6268*/ d16 |= 0x0015;
   /*MT6268*/ HW_WRITE( GPIO_MODE6, d16 );
   /*MT6268*/
   /*MT6268*/ /*vm0 and vm1*/
   /*MT6268*/ d16 = HW_READ(GPIO_MODE8);
   /*MT6268*/ d16 &= 0xC3FF;
   /*MT6268*/ d16 |= 0x3C00;
   /*MT6268*/ HW_WRITE( GPIO_MODE8, d16 );
         #endif
      #endif /* __CUST_NEW__ */
   /*MT6268*/
   #endif

   #if IS_CHIP_MT6252
   /* There is no need for MT6252 to configure GPIO. */
   #elif IS_CHIP_MT6253
   /*MT6253*/   /* if needed to config GPIO_MODE2[11:10]=1 to set GPIO13=BPI_BUS9 */
   /*MT6253*/
   /*MT6253*/   #ifndef __CUST_NEW__
   /*MT6253*/   /* only check BPI9 */
   /*MT6253*/   if( (d16>>9) & 0x0001)          /* if this BPI needed */
   /*MT6253*/   {
   /*MT6253*/      d16and |= 0x0003<<((11-4)*2);/* only set this needed pin as BPI */
   /*MT6253*/      d16or  |= 0x0001<<((11-4)*2);
   /*MT6253*/   }
   /*MT6253*/   d16 = HW_READ( GPIO_MODE3 );
   /*MT6253*/   d16 &= ~d16and;
   /*MT6253*/   d16 |=  d16or;
   /*MT6253*/   HW_WRITE( GPIO_MODE3, d16 );
   /*MT6253*/   #endif /* __CUST_NEW__ */
   #endif

   #if IS_CHIP_MT6236
   /*MT6236*/ /* if needed to config GPIO_MODE1[ 1: 0]=1 to set GPIO10=BPI_BUS0 */
   /*MT6236*/ /* if needed to config GPIO_MODE1[ 3: 2]=1 to set GPIO10=BPI_BUS1 */
   /*MT6236*/ /* if needed to config GPIO_MODE1[ 5: 4]=1 to set GPIO10=BPI_BUS2 */
   /*MT6236*/ /* if needed to config GPIO_MODE1[ 7: 6]=1 to set GPIO10=BPI_BUS3 */
   /*MT6236*/ /* if needed to config GPIO_MODE1[ 9: 8]=1 to set GPIO10=BPI_BUS4 */
   /*MT6236*/ /* if needed to config GPIO_MODE1[11:10]=1 to set GPIO10=BPI_BUS5 */
   /*MT6236*/ /* if needed to config GPIO_MODE1[13:12]=1 to set GPIO10=BPI_BUS6 */
   /*MT6236*/ /* if needed to config GPIO_MODE1[15:14]=1 to set GPIO11=BPI_BUS7 */
   /*MT6236*/ /* if needed to config GPIO_MODE2[ 1: 0]=1 to set GPIO12=BPI_BUS8 */
   /*MT6236*/ /* if needed to config GPIO_MODE2[ 3: 2]=1 to set GPIO13=BPI_BUS9 */
   /*MT6236*/
   /*MT6236*/ #ifndef __CUST_NEW__
   /*MT6236*/ for(i=0; i<8; i++)                /* check BPI0~7 */
   /*MT6236*/ {
   /*MT6236*/    if( (d16>>i) & 0x0001)          /* if this BPI needed */
   /*MT6236*/    {
   /*MT6236*/      d16and |= 0x0003<<(i*2);  /* only set this needed pin as BPI */
   /*MT6236*/      d16or  |= 0x0001<<(i*2);
   /*MT6236*/    }
   /*MT6236*/ }
   /*MT6236*/ {
   /*MT6236*/    unsigned short d16_temp;
   /*MT6236*/    d16_temp = HW_READ( GPIO_MODE1 );
   /*MT6236*/    d16_temp &= ~d16and;
   /*MT6236*/    d16_temp |=  d16or;
   /*MT6236*/    HW_WRITE( GPIO_MODE1, d16_temp );
   /*MT6236*/ }
   /*MT6236*/ d16and = 0;
   /*MT6236*/ d16or  = 0;
   /*MT6236*/
   /*MT6236*/ for(i=8; i<10; i++)                /* check BPI8~9 */
   /*MT6236*/ {
   /*MT6236*/    if( (d16>>i) & 0x0001)          /* if this BPI needed */
   /*MT6236*/    {
   /*MT6236*/      d16and |= 0x0003<<((i-8)*2);  /* only set this needed pin as BPI */
   /*MT6236*/      d16or  |= 0x0001<<((i-8)*2);
   /*MT6236*/    }
   /*MT6236*/ }
   /*MT6236*/
   /*MT6236*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6236*/ d16 &= ~d16and;
   /*MT6236*/ d16 |=  d16or;
   /*MT6236*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6236*/ #endif /* __CUST_NEW__ */
   /*MT6236*/
   #endif

   #if IS_CHIP_MT6256
   /*MT6256*/ /* MT6256 has only 5 BPI pins                                    */
   /*MT6256*/ /* if needed to config GPIO_MODE1[ 3: 0]=1 to set GPIO0=BPI_BUS0 */
   /*MT6256*/ /* if needed to config GPIO_MODE1[ 7: 4]=1 to set GPIO1=BPI_BUS1 */
   /*MT6256*/ /* if needed to config GPIO_MODE1[11: 8]=1 to set GPIO2=BPI_BUS2 */
   /*MT6256*/ /* if needed to config GPIO_MODE1[15:12]=1 to set GPIO3=BPI_BUS3 */
   /*MT6256*/ /* if needed to config GPIO_MODE2[ 3: 0]=1 to set GPIO4=BPI_BUS4 */
   /*MT6256*/
   /*MT6256*/   #ifndef __CUST_NEW__
   /*MT6256*/   for(i=0; i<4; i++)                 /* check BPI0~3 */
   /*MT6256*/   {
   /*MT6256*/      if( (d16>>i) & 0x0001)          /* if this BPI needed */
   /*MT6256*/      {
   /*MT6256*/         d16and |= 0x000F<<(i*4);     /* only set this needed pin as BPI */
   /*MT6256*/         d16or  |= 0x0001<<(i*4);
   /*MT6256*/      }
   /*MT6256*/   }
   /*MT6256*/   {
   /*MT6256*/      unsigned short d16_temp;
   /*MT6256*/      #if IS_CHIP_MT6256_S00
   /*MT6256*/      d16_temp = HW_READ( GPIO_MODE1 );
   /*MT6256*/      d16_temp &= ~d16and;
   /*MT6256*/      d16_temp |=  d16or;
   /*MT6256*/      HW_WRITE( GPIO_MODE1, d16_temp );
   /*MT6256*/      #else
   /*MT6256*/      d16_temp = HW_READ( GPIO_MODE25 );
   /*MT6256*/      d16_temp &= ~d16and;
   /*MT6256*/      d16_temp |=  d16or;
   /*MT6256*/      HW_WRITE( GPIO_MODE25, d16_temp );
   /*MT6256*/      #endif
   /*MT6256*/   }
   /*MT6256*/
   /*MT6256*/   d16and = 0;
   /*MT6256*/   d16or  = 0;
   /*MT6256*/
   /*MT6256*/   i=4;                              /* check BPI4 */
   /*MT6256*/   if( (d16>>i) & 0x0001)            /* if this BPI needed */
   /*MT6256*/   {
   /*MT6256*/      d16and |= 0x000F<<((i-4)*4);   /* only set this needed pin as BPI */
   /*MT6256*/      d16or  |= 0x0001<<((i-4)*4);
   /*MT6256*/   }
   /*MT6256*/
   /*MT6256*/      #if IS_CHIP_MT6256_S00
   /*MT6256*/   d16 = HW_READ( GPIO_MODE2 );
   /*MT6256*/   d16 &= ~d16and;
   /*MT6256*/   d16 |=  d16or;
   /*MT6256*/   HW_WRITE( GPIO_MODE2, d16 );
   /*MT6256*/      #else
   /*MT6256*/   d16 = HW_READ( GPIO_MODE26 );
   /*MT6256*/   d16 &= ~d16and;
   /*MT6256*/   d16 |=  d16or;
   /*MT6256*/   HW_WRITE( GPIO_MODE26, d16 );
   /*MT6256*/      #endif
   /*MT6256*/   #endif /* __CUST_NEW__ */
   #endif

   #if IS_CHIP_MT6251
   /*MT6251*/   /* if needed to config GPIO_MODE1[ 3: 0]=1 to set GPIO0=BPI_BUS0 */
   /*MT6251*/   /* if needed to config GPIO_MODE1[ 7: 4]=1 to set GPIO1=BPI_BUS1 */
   /*MT6251*/   /* if needed to config GPIO_MODE1[11: 8]=1 to set GPIO2=BPI_BUS2 */
   /*MT6251*/   /* if needed to config GPIO_MODE1[15:12]=1 to set GPIO3=BPI_BUS3 */
   /*MT6251*/
   /*MT6251*/   #ifndef __CUST_NEW__
   /*MT6251*/   for(i=0; i<4; i++)                 /* check BPI0~3 */
   /*MT6251*/   {
   /*MT6251*/      if( (d16>>i) & 0x0001)          /* if this BPI needed */
   /*MT6251*/      {
   /*MT6251*/         d16and |= 0x000F<<(i*4);     /* only set this needed pin as BPI */
   /*MT6251*/         d16or  |= 0x0001<<(i*4);
   /*MT6251*/      }
   /*MT6251*/   }
   /*MT6251*/   d16 = HW_READ( GPIO_MODE1 );
   /*MT6251*/   d16 &= ~d16and;
   /*MT6251*/   d16 |=  d16or;
   /*MT6251*/   HW_WRITE( GPIO_MODE1, d16 );
   /*MT6251*/
   /*MT6251*/   #endif /* __CUST_NEW__ */
   #endif

   #if IS_CHIP_MT6255 || IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
   /*MT6255~*/  #ifndef __CUST_NEW__
   /*MT6255~*/  (void)d16and;  (void)d16or;
   /*MT6255~*/  #endif /* __CUST_NEW__ */
   #endif

   #if IS_CHIP_MT6276
   /*MT6276*/ /* if needed to config GPIO_MODE1[ 5: 3]=001 to set GPIO06=BPI_BUS09 */
   /*MT6276*/ /* if needed to config GPIO_MODE1[ 8: 6]=001 to set GPIO07=BPI_BUS06 */
   /*MT6276*/ /* if needed to config GPIO_MODE1[11: 9]=001 to set GPIO08=BPI_BUS07 */
   /*MT6276*/
   /*MT6276*/ #ifndef __CUST_NEW__
   /*MT6276*/
   /*MT6276*/ for(i=6; i<10; i++)   /* check BPI6,7,9 for GPIO_MODE1 */
   /*MT6276*/ {
   /*MT6276*/    if( i<8 )          /* check BPI6~7 */
   /*MT6276*/    {
   /*MT6276*/       if( (d16>>i)&0x0001 )           /* if this BPI needed */
   /*MT6276*/       {
   /*MT6276*/          d16and |= 0x0007<<((i-4)*3); /* only set this needed pin as BPI */
   /*MT6276*/          d16or  |= 0x0001<<((i-4)*3);
   /*MT6276*/       }
   /*MT6276*/    }
   /*MT6276*/    else if(i==9)      /* check BPI9 */
   /*MT6276*/    {
   /*MT6276*/       if( (d16>>i)&0x0001 )           /* if this BPI needed */
   /*MT6276*/       {
   /*MT6276*/          d16and |= 0x0007<<((i-8)*3); /* only set this needed pin as BPI */
   /*MT6276*/          d16or  |= 0x0001<<((i-8)*3);
   /*MT6276*/       }
   /*MT6276*/    }
   /*MT6276*/ }
   /*MT6276*/
   /*MT6276*/ /* if needed to config GPIO_MODE2[ 2: 0]=001 to set GPIO10=BPI_BUS08 */
   /*MT6276*/ if( (d16>>8)&0x0001 ) /* check BPI8 for GPIO_MODE2 */
   /*MT6276*/ {
   /*MT6276*/    d16 = HW_READ(GPIO_MODE2);
   /*MT6276*/    d16 &= 0xFFF8;
   /*MT6276*/    d16 |= 0x0001;
   /*MT6276*/    HW_WRITE( GPIO_MODE2, d16 );
   /*MT6276*/ }
   /*MT6276*/
   /*MT6276*/ /* Config GPIO_MODE1[ 2: 0]=001 to set GPIO05=BPI_BUS13 */
   /*MT6276*/ /* Config GPIO_MODE1[14:12]=001 to set GPIO09=BPI_BUS14 */
   /*MT6276*/ d16and |= 0x7007;
   /*MT6276*/ d16or  |= 0x1001;
   /*MT6276*/
   /*MT6276*/ d16  = HW_READ( GPIO_MODE1 );
   /*MT6276*/ d16 &= ~d16and;
   /*MT6276*/ d16 |=  d16or;
   /*MT6276*/ HW_WRITE( GPIO_MODE1, d16 );
   /*MT6276*/
   /*MT6276*/ #endif /* __CUST_NEW__ */
   /*MT6276*/
   #endif

   #if IS_CHIP_MT6573
   /*MT6573*/ /* if needed to config GPIO_MODE2[ 8: 6]=001 to set GPIO12=BPI_BUS00 */
   /*MT6573*/ /* if needed to config GPIO_MODE2[11: 9]=001 to set GPIO13=BPI_BUS01 */
   /*MT6573*/ /* if needed to config GPIO_MODE2[14:12]=001 to set GPIO14=BPI_BUS02 */
   /*MT6573*/ /* if needed to config GPIO_MODE3[ 2: 0]=001 to set GPIO15=BPI_BUS03 */
   /*MT6573*/ /* if needed to config GPIO_MODE3[ 5: 3]=001 to set GPIO16=BPI_BUS04 */
   /*MT6573*/ /* if needed to config GPIO_MODE3[ 8: 6]=001 to set GPIO17=BPI_BUS05 */
   /*MT6573*/ /* if needed to config GPIO_MODE3[11: 9]=001 to set GPIO18=BPI_BUS06 */
   /*MT6573*/ /* if needed to config GPIO_MODE3[14:12]=001 to set GPIO19=BPI_BUS07 */
   /*MT6573*/ /* if needed to config GPIO_MODE4[ 2: 0]=001 to set GPIO20=BPI_BUS09 */
   /*MT6573*/
   /*MT6573*/ #ifndef __CUST_NEW__
   /*MT6573*/
   /*MT6573*/ for(i=0; i<3; i++)   /* check BPI0~2 for GPIO_MODE2 */
   /*MT6573*/ {
   /*MT6573*/    if( (d16>>i)&0x0001 )           /* if this BPI needed */
   /*MT6573*/    {
   /*MT6573*/       d16and |= 0x0007<<((i+2)*3); /* only set this needed pin as BPI */
   /*MT6573*/       d16or  |= 0x0001<<((i+2)*3);
   /*MT6573*/    }
   /*MT6573*/ }
   /*MT6573*/
   /*MT6573*/ {  unsigned short d16_temp;
   /*MT6573*/    d16_temp = HW_READ( GPIO_MODE2 );
   /*MT6573*/    d16_temp &= ~d16and;
   /*MT6573*/    d16_temp |=  d16or;
   /*MT6573*/    HW_WRITE( GPIO_MODE2, d16_temp );
   /*MT6573*/ }
   /*MT6573*/
   /*MT6573*/ d16and = 0;
   /*MT6573*/ d16or  = 0;
   /*MT6573*/
   /*MT6573*/ for(i=3; i<8; i++)   /* check BPI3~7 for GPIO_MODE3 */
   /*MT6573*/ {
   /*MT6573*/    if( (d16>>i)&0x0001 )           /* if this BPI needed */
   /*MT6573*/    {
   /*MT6573*/       d16and |= 0x0007<<((i-3)*3); /* only set this needed pin as BPI */
   /*MT6573*/       d16or  |= 0x0001<<((i-3)*3);
   /*MT6573*/    }
   /*MT6573*/ }
   /*MT6573*/
   /*MT6573*/ {  unsigned short d16_temp;
   /*MT6573*/    d16_temp = HW_READ( GPIO_MODE3 );
   /*MT6573*/    d16_temp &= ~d16and;
   /*MT6573*/    d16_temp |=  d16or;
   /*MT6573*/    HW_WRITE( GPIO_MODE3, d16_temp );
   /*MT6573*/ }
   /*MT6573*/
   /*MT6573*/ /* if needed to config GPIO_MODE5[ 5: 3]=001 to set GPIO26=BPI_BUS08 */
   /*MT6573*/ if( (d16>>8)&0x0001 )           /* if this BPI needed */
   /*MT6573*/ {
   /*MT6573*/    unsigned short d16_temp;
   /*MT6573*/    d16_temp = HW_READ( GPIO_MODE5 );
   /*MT6573*/    d16_temp &= ~0x0038;
   /*MT6573*/    d16_temp |=  0x0008;
   /*MT6573*/    HW_WRITE( GPIO_MODE5, d16_temp );
   /*MT6573*/ }
   /*MT6573*/
   /*MT6573*/ /* if needed to config GPIO_MODE4[ 2: 0]=001 to set GPIO20=BPI_BUS09 */
   /*MT6573*/ if( (d16>>9)&0x0001 )           /* if this BPI needed */
   /*MT6573*/ {
   /*MT6573*/    unsigned short d16_temp;
   /*MT6573*/    d16_temp = HW_READ( GPIO_MODE4 );
   /*MT6573*/    d16_temp &= ~0x0007;
   /*MT6573*/    d16_temp |=  0x0001;
   /*MT6573*/    HW_WRITE( GPIO_MODE4, d16_temp );
   /*MT6573*/ }
   /*MT6573*/
   /*MT6573*/ /* if needed to config GPIO_MODE4[ 5: 3]=001 to set GPIO21=BPI_BUS10 */
   /*MT6573*/ /* if needed to config GPIO_MODE4[ 8: 6]=001 to set GPIO22=BPI_BUS11 */
   /*MT6573*/ /* if needed to config GPIO_MODE4[11: 9]=001 to set GPIO23=BPI_BUS12 */
   /*MT6573*/ /* if needed to config GPIO_MODE4[14:12]=001 to set GPIO24=BPI_BUS13 */
   /*MT6573*/ d16and = 0x7FF8;
   /*MT6573*/ d16or  = 0x1248;
   /*MT6573*/
   /*MT6573*/ d16  = HW_READ( GPIO_MODE4 );
   /*MT6573*/ d16 &= ~d16and;
   /*MT6573*/ d16 |=  d16or;
   /*MT6573*/ HW_WRITE( GPIO_MODE5, d16 );
   /*MT6573*/
   /*MT6573*/ /* if needed to config GPIO_MODE5[ 2: 0]=001 to set GPIO25=BPI_BUS14 */
   /*MT6573*/
   /*MT6573*/ d16and = 0x0007;
   /*MT6573*/ d16or  = 0x0001;
   /*MT6573*/
   /*MT6573*/ d16  = HW_READ( GPIO_MODE5 );
   /*MT6573*/ d16 &= ~d16and;
   /*MT6573*/ d16 |=  d16or;
   /*MT6573*/ HW_WRITE( GPIO_MODE5, d16 );
   /*MT6573*/ #endif /* __CUST_NEW__ */
   /*MT6573*/
   #endif

   #if IS_CHIP_MT6575
   /*MT6575*/ /* if needed to config GPIO_MODE1[ 5: 3]=001 to set GPIO06=BPI_BUS09 */
   /*MT6575*/ /* if needed to config GPIO_MODE1[ 8: 6]=001 to set GPIO07=BPI_BUS06 */
   /*MT6575*/ /* if needed to config GPIO_MODE1[11: 9]=001 to set GPIO08=BPI_BUS07 */
   /*MT6575*/
   /*MT6575*/ #ifndef __CUST_NEW__
   /*MT6575*/
   /*MT6575*/ for(i=6; i<10; i++)   /* check BPI6,7,9 for GPIO_MODE1 */
   /*MT6575*/ {
   /*MT6575*/    if( i<8 )          /* check BPI6~7 */
   /*MT6575*/    {
   /*MT6575*/       if( (d16>>i)&0x0001 )           /* if this BPI needed */
   /*MT6575*/       {
   /*MT6575*/          d16and |= 0x0007<<((i-4)*3); /* only set this needed pin as BPI */
   /*MT6575*/          d16or  |= 0x0001<<((i-4)*3);
   /*MT6575*/       }
   /*MT6575*/    }
   /*MT6575*/    else if(i==9)      /* check BPI9 */
   /*MT6575*/    {
   /*MT6575*/       if( (d16>>i)&0x0001 )           /* if this BPI needed */
   /*MT6575*/       {
   /*MT6575*/          d16and |= 0x0007<<((i-8)*3); /* only set this needed pin as BPI */
   /*MT6575*/          d16or  |= 0x0001<<((i-8)*3);
   /*MT6575*/       }
   /*MT6575*/    }
   /*MT6575*/ }
   /*MT6575*/
   /*MT6575*/ /* if needed to config GPIO_MODE2[ 2: 0]=001 to set GPIO10=BPI_BUS08 */
   /*MT6575*/ if( (d16>>8)&0x0001 ) /* check BPI8 for GPIO_MODE2 */
   /*MT6575*/ {
   /*MT6575*/    d16 = HW_READ(GPIO_MODE2);
   /*MT6575*/    d16 &= 0xFFF8;
   /*MT6575*/    d16 |= 0x0001;
   /*MT6575*/    HW_WRITE( GPIO_MODE2, d16 );
   /*MT6575*/ }
   /*MT6575*/
   /*MT6575*/ /* Config GPIO_MODE1[ 2: 0]=001 to set GPIO05=BPI_BUS13 */
   /*MT6575*/ /* Config GPIO_MODE1[14:12]=001 to set GPIO09=BPI_BUS14 */
   /*MT6575*/ d16and |= 0x7007;
   /*MT6575*/ d16or  |= 0x1001;
   /*MT6575*/
   /*MT6575*/ d16  = HW_READ( GPIO_MODE1 );
   /*MT6575*/ d16 &= ~d16and;
   /*MT6575*/ d16 |=  d16or;
   /*MT6575*/ HW_WRITE( GPIO_MODE1, d16 );
   /*MT6575*/
   /*MT6575*/ #endif /* __CUST_NEW__ */
   /*MT6575*/
   #endif
#endif
#if IS_CHIP_MT6573
   #if IS_RF_MT6162
   /*MT6573*/ /* ensure GPIO 27~30 is configured as BSI1 function mode */
   /*MT6573*/ {  unsigned short d16;
   /*MT6573*/    d16  = HW_READ( GPIO_MODE5 ) & ~0x7FC0;
   /*MT6573*/    d16 |= 0x1240;
   /*MT6573*/    HW_WRITE( GPIO_MODE5, d16 );
   /*MT6573*/    d16  = HW_READ( GPIO_MODE6 ) & ~0x0007;
   /*MT6573*/    d16 |= 0x1;
   /*MT6573*/    HW_WRITE( GPIO_MODE6, d16 );
   /*MT6573*/ }
   #else
   /*MT6573*/ /* ensure GPIO 31~34 is configured as BSI0 function mode */
   /*MT6573*/ {  unsigned short d16;
   /*MT6573*/    d16  = HW_READ( GPIO_MODE6 ) & ~0x7FF8;
   /*MT6573*/    d16 |= 0x1248;
   /*MT6573*/    HW_WRITE( GPIO_MODE6, d16 );
   /*MT6573*/ }
   #endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_CHIP_MT6276
#define L1D_INIT_BSI_DRIVING()   HW_WRITE( ACIF_CON0, HW_READ(ACIF_CON0)&(~0x0007) )
#else
#define L1D_INIT_BSI_DRIVING()
#endif

static void L1D_RF_Init_BSI( void )
{  int i;
   unsigned short d16;

   L1D_INIT_BSI_DRIVING();                           /* init BSI driving strength */
   L1D_PowerOn_BSI();                                /* power on BSI */

#if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
   d16  = HW_READ( BSI_IO_CON );
   d16 &= ~0x0100;                                   /* clear RESET_MODE */
   HW_WRITE( BSI_IO_CON, d16 );

   for(i=0; i<BSI_DATA_COUNT; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
   HW_WRITE( GSM_BSI_ACTUPT, BSI_ACTUPT_ALL );       /* Update all active buffer */
   HW_WRITE( BSI_CON,    SCTRL_MAIN );               /* Initialize BSI_CON */

   #if IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
   d16  = HW_READ( BSI_IDLE_CNT ) & (~(0xF));
   d16 |= IDLE_CNT;
   HW_WRITE( BSI_IDLE_CNT, d16 );
   #else
   d16  = HW_READ( BSI_IDLE_CNT );                   /* 2G,3G share the same registers*/
   d16 &= ~(0xF<<(4*(BSI_PORT_SELECT&0x1)));
   d16 |= IDLE_CNT<<(4*(BSI_PORT_SELECT&0x1));
   HW_WRITE( BSI_IDLE_CNT, d16 );
   #endif

   d16  = HW_READ( GSM_BSI_TXDATA_CON );
   #if IS_CHIP_MT6260 || IS_CHIP_MT6261
   d16 &= ~0x6001;
   d16 |=  0x2001;                                   /* RW_BIT[14]=0, DATA_BIT[13]=1, EN[0]=1 */
   #elif IS_CHIP_MT6250
   d16 &= ~0x6301;
   d16 |=  0x2001;                                   /* RW_BIT[14]=0, DATA_BIT[13]=1, EN[0]=1 */
   #elif IS_RF_MT6162
   d16 |=  0x2041;                                   /* RW_BIT=0, DATA_BIT=1, OH_MODE=1, EN=1 */
   #else
   d16 &= ~0x0001;                                   /* EN=0 */
   #endif
   HW_WRITE( GSM_BSI_TXDATA_CON, d16 );

   #if IS_AFC_TRIGGER_BSI_SUPPORT
      #if IS_RF_MT6162
   HW_WRITE( AFC_BSI_SHIFT, AFC_SHIFT_PART );        /* AFC_CW[31:0] = ( (AFC_DATA[12:0]<<AFC_SHIFT_PART) & AFC_MASK_PART ) | AFC_VALUE_PART */
   HW_WRITE( AFC_MASK,      AFC_MASK_PART  );
   HW_WRITE( AFC_VALUE,     AFC_VALUE_PART );
   HW_WRITE( AFC_BSI_CON,   AFC_CON_PART   );
      #endif
   #endif

   #if IS_CHIP_MT6260 || IS_CHIP_MT6261
   // disable BSI read-back
   HW_BSI_RDBACK_EN( 0 );
   BSIread.event_timing = TQ_BSI_READ_TIME;
   #elif IS_CHIP_MT6250
   // disable BSI read-back
   HW_BSI_RDBACK_EN( 0 );
   BSIread.event_timing = TQ_BSI_READ_TIME;

   if( L1D_Check_SW_SecVersion() )
   {
      // set bit[8] to 1 to invert the BSI clock polarity for MT6250 E1
      d16  = HW_READ( ACFG_PIN_DINV0 );
      d16 &= ~0x0100;
      d16 |=  0x0100;
      HW_WRITE( ACFG_PIN_DINV0, d16 );
   }
   #endif

#else
   d16 = HW_READ( BSI_CON );
   d16 &= (unsigned short)(~0x0100);                 /* clear BSI write buffer */
   HW_WRITE( BSI_CON , d16 );

   #if IS_CHIP_MT6268T || IS_CHIP_MT6268 || IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION || IS_CHIP_MT6252
   for(i=0; i<BSI_DATA_COUNT; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
   #elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   for(i=0; i<40; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
   for(i=0; i<BSI_DATA_COUNT-40; i++)
   {  HW_WRITE( BSI_Dn_CON_2(i), SCTRL_RESERVED );   /* set BSI ID = reserved */
   }
   #else
   for(i=0; i<BSI_DATA_COUNT; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
   #endif

   d16 |= (unsigned short)(0x0100);                  /* clear BSI active buffer */
   HW_WRITE( BSI_CON , d16 );

   #if IS_CHIP_MT6268T || IS_CHIP_MT6268 || IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION || IS_CHIP_MT6252
   for(i=0; i<BSI_DATA_COUNT; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
   #elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   for(i=0; i<40; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
   for(i=0; i<BSI_DATA_COUNT-40; i++)
   {  HW_WRITE( BSI_Dn_CON_2(i), SCTRL_RESERVED );   /* set BSI ID = reserved */
   }
   #else
   for(i=0; i<BSI_DATA_COUNT; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
   #endif

   HW_WRITE( BSI_CON, SCTRL_MAIN );                  /* Initialize BSI_CON */

   #if IS_CHIP_MT6252
   HW_WRITE( BSI_PAIR_NUM, 0x0020 );                 /* set BSI pair number */
   #elif IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
   HW_WRITE( BSI_PAIR_NUM, BSI_DATA_COUNT );         /* set BSI pair number */
   #elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   HW_WRITE( BSI_PAIR_NUM, 0x002c );                 /* set BSI pair number */
   #endif

   #if IS_RF_MT6256RF || IS_RF_MT6251RF || IS_RF_MT6255RF
   // Readback_BSI_Disable
   HW_BSI_RDBACK_EN( 0 );
   BSIread.event_timing = TQ_BSI_READ_TIME;
   #endif

   L1D_RF_Set_SLEEP_SPI();
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Init_BPI( void )
{
#if IS_AST_B2S_SUPPORT
   HW_WRITE( BPI_AST,     0x0281         );  // turn on AST mode, set AFC shift and BPI shift
   HW_WRITE( BPI_AX_SEL,  GSM_ERR_DET_ID );  // set a chosen BPI pin to connect to RF_conflict pin
   HW_WRITE( BPI_AST_CON, 0x3A1          );  // set AFC/BPI data lengh

   HW_WRITE( BPI_MASK,    0x3FFFFFFF     );  // set BPI MASK
   HW_WRITE( BPI_VALUE,   0x0F000000     );  // set BPI Value

   HW_WRITE( AFC_MASK,    0x1FFF         );  // set AFC MASK
   HW_WRITE( AFC_VALUE,   0x0E100000     );  // set AFC Value
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_65NM_CHIP_BSI_BPI_PWN
void L1D_RF_Init_BSI_BPI( void )
{  L1D_RF_Init_BSI();
   L1D_RF_Init_BPI();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif


void L1D_RF_InitEmptyRampData( int rf_band, int is_epsk )
{
#if defined(__SLIM_CALIBRATION_DATA__)
   sRAMPDATA* p;
   const sRAMPDATA_DEFAULT* p_d;
   unsigned char *dst, *src;
   unsigned short *dst_s;
   int i,j;

   #if IS_EPSK_TX_SUPPORT
   if( is_epsk )
   {
      p   = RampData_EPSK[rf_band];
      p_d = &RampData_Default_EPSK;
   }
   else
   #endif
   {
      p   = RampData[rf_band];
      p_d = &RampData_Default;
   }

   /*Ramp table is empty. Need init*/

   if( p->power[8] == 0 )
   {
      /*Init lowest power & power level*/
      dst = (unsigned char*)(p);
      src = (unsigned char*)(p_d);
      for( i = 0; i<(sizeof(RampData_Default.lowest_power) + sizeof(RampData_Default.power)); i++ )
      {  *dst++ = *src++;  }
      if( rf_band < FrequencyBand1800 )
      { p->lowest_power |= 0x5; }
      else
      { p->lowest_power &= ~0x7; }


      /*Init ramping profile*/
      for( i = 0; i<sizeof(p->ramp)/sizeof(RampData_Default.ramp); i++ )
      {
         dst = (unsigned char*)(&p->ramp[i] );
         src = (unsigned char*)(&p_d->ramp );
         for( j = 0; j<sizeof(RampData_Default.ramp); j++ )
         {  *dst++ = *src++;  }
      }

      /*Init sub-band weight*/
      /*dst = (unsigned char*)(&p->arfcn_weight );
      src = (unsigned char*)(&p_d->arfcn_weight );
      for( i = 0; i<sizeof(RampData_Default.arfcn_weight); i++ )
      {  *dst++ = *src++;  }*/

      switch( rf_band )
      {
         case FrequencyBand850:
         { i = 251; break; }
         case FrequencyBand900:
         { i = 1023; break; }
         case FrequencyBand1800:
         { i = 885; break; }
         case FrequencyBand1900:
         { i = 810; break; }
         default:
         { break; }
      }
      p->arfcn_weight[0].max_arfcn = i;
      p->arfcn_weight[0].mid_level = 21;
   #if IS_RF_MT6162 && IS_BSI_CLOSED_LOOP_TXPC_ON
       if( is_epsk )
       {  p->arfcn_weight[0].hi_weight = ((0)+(1<<12));  }
       else
   #endif
       {  p->arfcn_weight[0].hi_weight = WEIGHT(1.000);  }

      p->arfcn_weight[0].low_weight= WEIGHT(1.000);
      p->arfcn_weight[1].max_arfcn = TABLE_END;

      /*Init battery weight*/
      dst_s = (unsigned short*)(&p->battery_compensate );
      for( i = 0; i < (sizeof(p->battery_compensate)/sizeof(short)); i++ )
      {  *dst_s++ = WEIGHT(1.000);  }
   }
#endif
   (void)(is_epsk);(void)(rf_band);
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_InitEmptyInterRampData( void *inter_ramp )
{
#if defined(__SLIM_CALIBRATION_DATA__)
   int i;
   unsigned char *p;
   p = (unsigned char*) inter_ramp;
   if( *p == 0 )
   {
      for( i = 0; i < sizeof(sMIDRAMPDATA); i++ )
      {  *p++ = 255;  }
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void L1D_RF_Init_APC( void )
{  int  i;
   HW_WRITE(APC_CON, 0x0000);
   for(i=0; i<FrequencyBandCount; i++)
   {  L1D_RF_InitRampTable( i );
   }

   #if IS_CHIP_MT6573
   HW_WRITE( WR_PATH0, HW_READ(WR_PATH0)|0x0800 );
   #elif IS_CHIP_MT6575
   HW_WRITE( WR_PATH0, HW_READ(WR_PATH0)|0x2000 );
   #endif

   #if IS_CHIP_MT6250
   {  unsigned short  d16;
      d16 = HW_READ( ABB_DD_WR_PATH0);
      HW_WRITE( ABB_DD_WR_PATH0, d16 | 0x3000 );
      WAIT_TIME_QB(2);
      HW_WRITE( ABB_DD_WR_PATH0, d16 & (~0x3000) );
   }
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void L1D_RF_Init_AFC( void )
{
#if IS_AST_B2S_SUPPORT
/* do nothing */
#elif IS_AFC_EVENT_SUPPORT_CHIP
   #if IS_CHIP_MT6208
/*MT6208*/  HW_WRITE( IDN_SEL, 0x0003 );     /* to slove the AFC bug of H/W, don't let this register be zero */
   #endif

   HW_WRITE( AFC_CON, AFC_EVENT_TRIGGER );
   #if IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6205~*/ HW_WRITE( AFC_PUPER, TQ_AFC_CHARGE_IN_IDLE );
   #endif

   #if IS_CHIP_MT6573
   HW_WRITE( WR_PATH0, HW_READ(WR_PATH0)|0x0200 );
   #elif IS_CHIP_MT6575
   HW_WRITE( WR_PATH0, HW_READ(WR_PATH0)|0x0400 );
   #endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void L1D_RF_Init_DLUL( void )
{
   HW_WRITE( TDMA_BDLCON , bdlcon_data  );
   HW_WRITE( TDMA_BULCON1, bulcon1_data );
   HW_WRITE( TDMA_BULCON2, bulcon2_data );
   HW_WRITE( TDMA_DTXCON , 0x0000       );
#if IS_TDMA_AD_DA_WINDOW_SUPPORT
   HW_WRITE( TDMA_BDLCON2, bdlcon2_data );
   HW_WRITE( TDMA_BULCON3, bulcon3_data );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void L1D_RF_Init_BFE( void )
{  BFERXSET  bferxset;
   BFETXSET  bfetxset;

#if IS_CHIP_MT6270A
   HW_WRITE( AC_ODS_CON, 0x0001 );
#endif

#if IS_CHIP_MT6276_S00 // For MT6276E1, ADC MUX SW workaround
   {
      // Switch ADC MUX to UL Pads (2G mode), and ADC MUX will be controlled by 3G SW
      unsigned short d16 = HW_READ(BBRX_CON0);
      d16 &= ~0x0300;
      d16 |=  0x0100;
      HW_WRITE(BBRX_CON0, d16);
   }
#endif

#if IS_CHIP_MT6276_S01 // For MT6276E2, BBTX DAC SW workaround
   {
      unsigned short d16 = HW_READ(BBTX_CON5);
      d16 &= ~0x0030;
      d16 |=  0x0420; // switch to default 2G mode
      HW_WRITE(BBTX_CON5, d16);
   }
#elif IS_CHIP_MT6575_S00 // E1 leakage workaround for non-FDD usage
   #if !(defined __UMTS_FDD_MODE__)
   {
      HW_WRITE(BBTX_CON5, HW_READ(BBTX_CON5)&~0x0010);
   }
   #endif
#endif

// Set HW control mode for some BBTX/BBRX registers
#if IS_CHIP_MT6276_S00 || IS_CHIP_MT6573
   {
      unsigned short d16 = HW_READ(AUDIO_CON10);
      d16 &= ~0x7000;
      d16 |=  0x6000;
      HW_WRITE(AUDIO_CON10, d16);
   }
#elif IS_CHIP_MT6276 // MT6276E2
   {
      unsigned short d16 = HW_READ(BBRX_CON3);
      d16 |= 0x0002;
      HW_WRITE(BBRX_CON3, d16);
   }
#elif IS_CHIP_MT6575
   {
      unsigned short d16 = HW_READ(BBRX_CON3);
      d16 |= 0x0010;
      HW_WRITE(BBRX_CON3, d16);
   }
#endif

#if IS_CHIP_MT6573
   {  // Copy from UL1D_ABB_Init() for 2G only projects
      unsigned short d16 = HW_READ(WR_PATH0);
      d16 |= 0x8000;
      HW_WRITE(WR_PATH0, d16);
   }
#endif

#if IS_CHIP_MT6575
   { // turn on BBTX LDO common control enable
      HW_WRITE(BBTX_CON13, 0x1F);
   }
#endif

   /* for OH only */
   L1D_ABB_Set_ADCMUX_DLPad();

#if IS_CHIP_MT6256 || IS_CHIP_MT6251
   /* setting for different analog chip: C63216 or D63216 */
   /*TBD*/
#endif

   HW_READ_BFERXSET( bferxset );

#if IS_DLIF_CHIP
   #if IS_CHIP_MT6260 || IS_CHIP_MT6261
   bferxset.field.lpbk_en       = 0;
   bferxset.field.rx_rst_en     = 0;
   bferxset.field.rx_iq_swp     = bbrx_iq_swap;
   bferxset.field.rx_dc_notch_en= 1;
   bferxset.field.rx_rpt_en     = 0;

// RX_TIME_CON0
   bferxset.field.rx_dcoc_str_nb= RX_DCOC_STR_NB;
   bferxset.field.rx_null_str_nb= RX_NULL_STR_NB;
// RX_TIME_CON1
   bferxset.field.rx_ircmpn_sw  = RX_IRCMPN_SW;
// RX_TIME_CON2
   bferxset.field.rx_dcoc_str   = RX_DCOC_STR;
   bferxset.field.rx_null_str   = RX_NULL_STR;

   #elif IS_CHIP_MT6255
   bferxset.field.lpbk_en           = 0;
   bferxset.field.rx_iq_swp         = bbrx_iq_swap;
   bferxset.field.write_rx_dm_by_sw = 0;
   bferxset.field.rx_dc_notch_en    = 1;
   bferxset.field.rx_rst_en         = 0;
   bferxset.field.rx_rpt_en         = 0;

   bferxset.field.rx_null_str       = RX_NULL_STR;
   bferxset.field.rx_dcoc_str       = RX_DCOC_STR;

   bferxset.field.rx_ircmpn_sw      = RX_IRCMPN_SW;   
   #elif IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
   /*BFE RX init*/
   bferxset.field.lpbk_en       = 0;
   bferxset.field.rx_rst_en     = 0;
   bferxset.field.rx_iq_swp     = bbrx_iq_swap;
   bferxset.field.rx_bypass     = 0;
   bferxset.field.rx_rpt_en     = 0;

   bferxset.field.itd_lock      = 0;
   bferxset.field.itd_frc       = 0;
   bferxset.field.itd_sel       = 0;
   bferxset.field.idma_sel      = 0;
   bferxset.field.itd_immdt     = 0;
   bferxset.field.thr_itd       = THR_ITD_DEFAULT;
// HW_WRITE( RX_CON3, RX_CON3_DEFAULT );

   bferxset.field.p2x_scale     = P2X_SCALE_DEFAULT;
// HW_WRITE( IREST_CON0, P2X_SCALE_DEFAULT );

   bferxset.field.bfe_sor       = 0;

   bferxset.field.fir3_mon_len  = 0;
   #else
   bferxset.field.lpbk_en       = 0;
   bferxset.field.rx_rst_en     = 0;
   bferxset.field.rx_iq_swp     = bbrx_iq_swap;
   bferxset.field.rx_dc_notch_en= 1;
   bferxset.field.rx_rpt_en     = 0;

// HW_WRITE( RX_TIME_CON0, RX_TIME_CON0_DEFAULT );
   bferxset.field.rx_dcoc_str   = RX_DCOC_STR;
   bferxset.field.rx_null_str   = RX_NULL_STR;
// HW_WRITE( RX_TIME_CON1, RX_TIME_CON1_DEFAULT );
   bferxset.field.rx_ircmpn_sw  = RX_IRCMPN_SW;
   #endif
#elif IS_BBTXRX_CHIP_DESIGN_VER_2
   bferxset.field.swap          = bbrx_iq_swap;
   bferxset.field.blpen         = 0;
   bferxset.field.ph_roen_w     = 0;
   bferxset.field.ph_roen_n     = 0;
   bferxset.field.igainsel      = 0;
   bferxset.field.pwrshftno     = 0;
   bferxset.field.firtpno       = 21;
   bferxset.field.RXID_PWR_OFF  = 17;
   bferxset.field.RXID_PWR_PER  = 135;
   bferxset.field.ST_A_NCOF_SEL = 0;
   bferxset.field.ST_B_NCOF_SEL = 2;
   bferxset.field.ST_B_WCOF_SEL = 3;
#else
   bferxset.field.swap          = bbrx_iq_swap;
   bferxset.field.gain          = bbrx_gain_double;
   bferxset.field.isel          = 0;
   bferxset.field.qsel          = 0;
   bferxset.field.calbias       = 0;
   bferxset.field.blpen         = 0;
   #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
   bferxset.field.ph_roen_w     = 0;
   bferxset.field.ph_roen_n     = 0;
   bferxset.field.igainsel      = 0;
   bferxset.field.pwrshftno     = 0;
   bferxset.field.firtpno       = 21;
   bferxset.field.dithdis       = 1; /*1: Turn off Dither figure*/
   bferxset.field.RXID_PWR_OFF  = 17;
   bferxset.field.RXID_PWR_PER  = 135;
   bferxset.field.ST_A_NCOF_SEL = 0;
   bferxset.field.ST_B_NCOF_SEL = 2;
   bferxset.field.ST_B_WCOF_SEL = 3;
   #elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   bferxset.field.ph_roen_w     = 0;
   bferxset.field.ph_roen_n     = 0;
   bferxset.field.igainsel      = 0;
   bferxset.field.pwrshftno     = 0;
   bferxset.field.firtpno       = 21;
   bferxset.field.RXID_PWR_OFF  = 17;
   bferxset.field.RXID_PWR_PER  = 135;
   bferxset.field.ST_A_NCOF_SEL = 0;
   bferxset.field.ST_B_NCOF_SEL = 2;
   bferxset.field.ST_B_WCOF_SEL = 3;
   #endif
#endif

   HW_WRITE_BFERXSET( bferxset );

   HW_READ_BFETXSET( bfetxset );

#if IS_CHIP_MT6252
   bfetxset.field.mdbyp         = 0;
   bfetxset.field.sgen          = 0;
   bfetxset.field.iqswap        = bbtx_iq_swap;
   bfetxset.field.phsel         = bbtx_phsel;
   bfetxset.field.offi          = bbtx_offset_i;
   bfetxset.field.offq          = bbtx_offset_q;
#elif IS_DLIF_CHIP
   #if IS_CHIP_MT6255
   bfetxset.field.all_10_gen    = 0;
   bfetxset.field.bcien         = 0; /* disable cipher */

   bfetxset.field.tx_cnt_tgt    = TX_CNT_TGT_DEFAULT;
   #elif IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
   bfetxset.field.mdsel         = 0;
   bfetxset.field.all_10_gen    = 0;
   bfetxset.field.ramp_zero     = 0; /*8psk ramp*/
   bfetxset.field.bcien         = 0; /* disable cipher */

   bfetxset.field.tx_cnt_tgt    = TX_CNT_TGT_DEFAULT;
   bfetxset.field.pm_dly        = PM_DLY_DEFAULT;
// HW_WRITE( TX_CON1, TX_CON1_DEFAULT );

   bfetxset.field.pwr_sel0      = 0;
   bfetxset.field.pwr_sel1      = 0;
   bfetxset.field.pwr_sel2      = 0;
   bfetxset.field.pwr_sel3      = 0;
   bfetxset.field.tx_cnt_tgt_sw = TX_CNT_TGT_SW_DEFAULT;
   #elif IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
   bfetxset.field.all_10_gen    = 0;
   bfetxset.field.bcien         = 0; /* disable cipher */

   bfetxset.field.tx_cnt_tgt    = TX_CNT_TGT_DEFAULT;
   #else
   bfetxset.field.mdsel         = 0;
   bfetxset.field.all_10_gen    = 0;
   bfetxset.field.bcien         = 0; /* disable cipher */

   bfetxset.field.tx_cnt_tgt    = TX_CNT_TGT_DEFAULT;
   bfetxset.field.pm_dly        = PM_DLY_DEFAULT;
// HW_WRITE( TX_CON1, TX_CON1_DEFAULT );

   bfetxset.field.tx_cnt_tgt_sw = TX_CNT_TGT_SW_DEFAULT;

   bfetxset.field.pwr_sel0      = 0;
   bfetxset.field.pwr_sel1      = 0;
   bfetxset.field.pwr_sel2      = 0;
   bfetxset.field.pwr_sel3      = 0;
   #endif
// HW_WRITE( TX_PWR, TX_PWR_DEFAULT );
#elif IS_BBTXRX_CHIP_DESIGN_VER_2
   bfetxset.field.iqswap        = bbtx_iq_swap;
   bfetxset.field.cmv           = bbtx_common_mode_voltage;
   bfetxset.field.offi          = bbtx_offset_i;
   bfetxset.field.offq          = bbtx_offset_q;
   bfetxset.field.mdbyp         = 0;
   bfetxset.field.sgen          = 0;
   bfetxset.field.gain_comp     = bbtx_gain_comp;
   bfetxset.field.iqgain_sel    = bbtx_iqgain_sel;
   bfetxset.field.phseli        = bbtx_phseli;
   bfetxset.field.phselq        = bbtx_phselq;
   bfetxset.field.rpsel         = bbtx_rpsel;
   bfetxset.field.inten         = bbtx_inten;
   bfetxset.field.sw_qbcnt      = bbtx_sw_qbcnt;
   bfetxset.field.epsk_dtap_sym = bbtx_epsk_dtap_sym;
#else
   bfetxset.field.trimi         = bbtx_trim_i;
   bfetxset.field.trimq         = bbtx_trim_q;
   bfetxset.field.offi          = bbtx_offset_i;
   bfetxset.field.offq          = bbtx_offset_q;
   bfetxset.field.calbias       = bbtx_calbias;
   bfetxset.field.iqswap        = bbtx_iq_swap;
   bfetxset.field.cmv           = bbtx_common_mode_voltage;
   bfetxset.field.gain          = bbtx_gain;
   bfetxset.field.calrcsel      = bbtx_calrcsel;
   #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223 || IS_CHIP_MT6253
   bfetxset.field.phsel         = bbtx_phsel;
   bfetxset.field.mdbyp         = 0;
   bfetxset.field.sgen          = 0;
   bfetxset.field.dccoarsei     = bbtx_dccoarse_i;
   bfetxset.field.dccoarseq     = bbtx_dccoarse_q;
   #elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION && !IS_CHIP_MT6253
   bfetxset.field.phsel         = bbtx_phsel;
   bfetxset.field.rpsel         = bbtx_rpsel;
   bfetxset.field.inten         = bbtx_inten;
   bfetxset.field.mdbyp         = 0;
   bfetxset.field.sgen          = 0;
   bfetxset.field.sw_qbcnt      = bbtx_sw_qbcnt;
      #if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
   bfetxset.field.dccoarsei     = bbtx_dccoarse_i;
   bfetxset.field.dccoarseq     = bbtx_dccoarse_q;
      #endif
   #endif

   #if IS_CHIP_MT6227
   bfetxset.field.iqswap_onfly  = bbtx_iqswap_onfly;
   #endif
#endif

   HW_WRITE_BFETXSET( bfetxset );

#if IS_DLIF_CHIP
   // do not need to do this
#else
   HW_WRITE( BFE_CON, 0x0000 );  /* disable cipher */
#endif

/* setting for different analog chip: C63216 or D63216 */
#if IS_BBTXRX_CHIP_DESIGN_VER_2 || IS_DLIF_CHIP
   // do not need to do this
#elif IS_CHIP_MT6228 || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   {  unsigned short d16;
      d16 = HW_READ( ACIF_AC_HW_VER );
      if (d16 == 0x8C01)       //C63216
      {  d16 = HW_READ( AFC_AC_CON );
         d16 &= 0xFFF0;
         HW_WRITE( AFC_AC_CON, d16 );
      }
      else if (d16 == 0x8D00)  //D63216
      {  d16 = HW_READ( AFC_AC_CON );
         d16 &= 0xFFF0;
         HW_WRITE( AFC_AC_CON, d16 );
      }
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Init_FIR( void )
{  int  i;
   const short *d16p;
   long  addr;

   addr = (long)RX_FIR_COEF(0);
   d16p = FIR_COEF;
   for( i=*d16p++; i!=0; i-- )
   {  HW_WRITE( (APBADDR)addr, *d16p );
      addr += 4;
      d16p++;
   }

#if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   addr = (long)RX_NBFIR_COEF(0);
   d16p = NB_FIR_COEF;
   for(i=*d16p++; i!=0; i-- )
   {  HW_WRITE( (APBADDR)addr, *d16p );
      addr += 4;
      d16p++;
   }
#endif

#if IS_DLIF_CHIP
   #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
   HW_WRITE( RX_NB_REG, NB_FIR_4DC_NORMAL_IFSEL0 );
   HW_WRITE( RX_WB_REG, WB_FIR_4DC_NORMAL_IFSEL0 );
   #endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION || IS_CHIP_MT6225_AND_LATTER_VERSION
void L1D_RF_init_FIR_SwitchNB( int wider )
{  int  i;
   const short *d16p;
   long  addr;

   if(wider == 1)
      d16p = NB_FIR_COEF_WIDER;
   else
      d16p = NB_FIR_COEF;

   addr = (long)RX_NBFIR_COEF(0);
   for(i=*d16p++; i!=0; i-- )
   {  HW_WRITE( (APBADDR)addr, *d16p );
      addr += 4;
      d16p++;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_DLIF_CHIP
void L1D_RF_Set_FB_FIR( void )
{  int  i;
   const short *d16p;
   long  addr;

   addr = (long)RX_FIR_COEF(0);   //0020h
   d16p = WIDE_FB_FIR_COEF;
   for( i = *d16p++; i != 0; i-- )
   {  HW_WRITE( (APBADDR)addr, *d16p );
      addr += 4;
      d16p++;
   }

   addr = (long)RX_NBFIR_COEF(0); //0070h
   d16p = NARROW_FB_FIR_COEF;
   for( i = *d16p++; i != 0; i-- )
   {  HW_WRITE( (APBADDR)addr, *d16p );
      addr += 4;
      d16p++;
   }
      #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
   /* Set FIR DC scaling*/
   if( l1d_rf.change==0 ) /*IF = +170k*/
   {  HW_WRITE( RX_NB_REG, NB_FIR_4DC_FB_POWRON_IFSEL0 );
      HW_WRITE( RX_WB_REG, WB_FIR_4DC_FB_POWRON_IFSEL0 );
   }
   else                   /*IF = -170k*/
   {  HW_WRITE( RX_NB_REG, NB_FIR_4DC_FB_POWRON_IFSEL1 );
      HW_WRITE( RX_WB_REG, WB_FIR_4DC_FB_POWRON_IFSEL1 );
   }
      #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
   #else /* !IS_DLIF_CHIP */
void L1D_RF_Set_FB_FIR( void )
{  int  i;
   const short *d16p;
   long  addr;

   addr = (long)RX_FIR_COEF(0);   //0020h
   d16p = WIDE_FB_FIR_COEF;
   for( i=*d16p++; i!=0; i-- )
   {  HW_WRITE( (APBADDR)addr, *d16p );
      addr += 4;
      d16p++;
   }

   addr = (long)RX_NBFIR_COEF(0); //0070h
   d16p = NARROW_FB_FIR_COEF;
   for(i=*d16p++; i!=0; i-- )
   {  HW_WRITE( (APBADDR)addr, *d16p );
      addr += 4;
      d16p++;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
   #endif
#endif

static void L1D_RF_Init_ChipOptimizeSetting( void )
{
#ifndef  L1_SIM
   #if IS_CHIP_MT6205A
/*MT6205A*/ {  unsigned short  d16;
/*MT6205A*/    d16 = HW_READ(RX_CON);
/*MT6205A*/    d16 &= ~0x001F;
/*MT6205A*/    d16 |= 0x0008;
/*MT6205A*/    HW_WRITE( RX_CON, d16 );
/*MT6205A*/    d16 = HW_READ(AFC_CALIBIAS);
/*MT6205A*/    d16 &= ~0x001F;
/*MT6205A*/    d16 |= 0x000F;
/*MT6205A*/    HW_WRITE( AFC_CALIBIAS, d16 );
/*MT6205A*/ }
   #endif

   #if IS_CHIP_MT6205B
/*MT6205B*/ {  unsigned short  d16;
/*MT6205B*/    d16 = HW_READ(RX_CON);
/*MT6205B*/    d16 &= ~0x001F;
/*MT6205B*/    d16 |= 0x0007;
/*MT6205B*/    HW_WRITE( RX_CON, d16 );
/*MT6205B*/    d16 = HW_READ(AFC_CALIBIAS);
/*MT6205B*/    d16 &= ~0x001F;
/*MT6205B*/    d16 |= 0x0006;
/*MT6205B*/    HW_WRITE( AFC_CALIBIAS, d16 );
/*MT6205B*/    d16 = HW_READ(TX_CFG);  /* appending bits enable, setting this bit to 1 In order to             */
/*MT6205B*/    d16 |= 0x0080;          /* let GMSK modulation only out DC(not sinewace) after Frame Enable on. */
/*MT6205B*/    HW_WRITE( TX_CFG, d16 );
/*MT6205B*/ }
   #endif

   #if IS_CHIP_MT6218B
      #if !IS_CHIP_MT6218B_AN2DN
         #if !IS_CHIP_MT6218B_EN
/*MT6218B_FN~*/ {  unsigned short  d16;
/*MT6218B_FN~*/    d16 = HW_READ(AFC_CALIBIAS);
/*MT6218B_FN~*/    d16 &= ~0x001F;
/*MT6218B_FN~*/    d16 |= 0x000F;
/*MT6218B_FN~*/    HW_WRITE( AFC_CALIBIAS, d16 );
/*MT6218B_FN~*/ }
         #endif
      #endif
   #endif

   #if IS_CHIP_MT6219
      #if !IS_CHIP_MT6219_AV
/*MT6219BV~*/ {  unsigned short  d16;
/*MT6219BV~*/    d16 = HW_READ(AFC_CALIBIAS);
/*MT6219BV~*/    d16 &= ~0x001F;
/*MT6219BV~*/    d16 |= 0x000F;
/*MT6219BV~*/    HW_WRITE( AFC_CALIBIAS, d16 );
/*MT6219BV~*/ }
      #endif
   #endif

   #if IS_CHIP_MT6229
/*MT6229~*/ {  unsigned short  d16;
/*MT6229~*/    d16 = HW_READ(AFC_CALIBIAS);
/*MT6229~*/    d16 &= ~0x001F;
/*MT6229~*/    d16 |= 0x000F;
/*MT6229~*/    HW_WRITE( AFC_CALIBIAS, d16 );
/*MT6229~*/ }
   #endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Init_SpecialCoef( void )
{
#if IS_MPLL_FH_SUPPORT || IS_MT6276E1_TEMP_MPLL_FH_SUPPORT
   /* borrowed for mpll_fh chip, should not have rf rx_coff */
   RFSpecialCoef.rx.mpll_fh.fixed_mpll_clk    = 0;
   RFSpecialCoef.rx.mpll_fh.mpll_freq_idx     = 0;
#endif

#if IS_SPLL_FH_SUPPORT
   /* borrowed for spll_fh chip, should not have rf rx_coff */
   RFSpecialCoef.rx.mpll_fh.fixed_mpll_clk    = 0;
   RFSpecialCoef.rx.mpll_fh.mpll_freq_idx     = 0;
#endif

#if IS_MD2G_LOGGER_SUPPORT
   /* borrowed for 2g logger chip, should not have rf rx_coff */

   RFSpecialCoef.rx.md2g_log.is_md2g_log_on   = 0;

#endif

#if IS_RF_MT6139B || IS_RF_MT6139C  || IS_RF_MT6140A || IS_RF_MT6140B
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif IS_RF_MT6139E
   {
      extern unsigned char dcs_tx_gain_setting;
      extern unsigned char pcs_tx_gain_setting;
      extern unsigned long CW11_RF[5];

      if     (dcs_tx_gain_setting == 1)
         CW11_RF[3]=0x0B4D7FB; /* TXDIVGC:00; TXMODGAIN: 010 (0.5dB and 40kHz) */
      else if(dcs_tx_gain_setting == 2)
         CW11_RF[3]=0x0B4E7FB; /* TXDIVGC:00; TXMODGAIN: 100 (1.5dB and 40kHz) */
      else
         CW11_RF[3]=0x1B4E7FB; /* TXDIVGC:01; TXMODGAIN: 100                   */

      if     (pcs_tx_gain_setting == 1)
         CW11_RF[4]=0x0B4D7FB; /* TXDIVGC:00; TXMODGAIN: 010 (0.5dB and 40kHz) */
      else if(pcs_tx_gain_setting == 2)
         CW11_RF[4]=0x0B4E7FB; /* TXDIVGC:00; TXMODGAIN: 100 (1.5dB and 40kHz) */
      else
         CW11_RF[4]=0x1B4E7FB; /* TXDIVGC:01; TXMODGAIN: 100                   */
   }
#elif IS_RF_MT6140D

   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[0].pcl_index=6;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[0].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[1].pcl_index=8;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[1].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[2].pcl_index=10;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[2].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[3].pcl_index=12;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[3].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[4].pcl_index=14;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[4].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[5].pcl_index=16;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[5].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[6].pcl_index=18;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[6].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[7].pcl_index=19;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[7].pa_vbias=7;

   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[0].pcl_index=6;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[0].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[1].pcl_index=8;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[1].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[2].pcl_index=10;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[2].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[3].pcl_index=12;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[3].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[4].pcl_index=14;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[4].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[5].pcl_index=16;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[5].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[6].pcl_index=18;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[6].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[7].pcl_index=19;
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[7].pa_vbias=7;

   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[0].pcl_index=2;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[0].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[1].pcl_index=4;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[1].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[2].pcl_index=6;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[2].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[3].pcl_index=8;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[3].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[4].pcl_index=10;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[4].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[5].pcl_index=12;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[5].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[6].pcl_index=14;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[6].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[7].pcl_index=15;
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[7].pa_vbias=7;

   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[0].pcl_index=2;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[0].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[1].pcl_index=4;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[1].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[2].pcl_index=6;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[2].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[3].pcl_index=8;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[3].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[4].pcl_index=10;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[4].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[5].pcl_index=12;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[5].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[6].pcl_index=14;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[6].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[7].pcl_index=15;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[7].pa_vbias=7;
#elif IS_RF_MT6162
   {  int i;

      for( i = 0; i < 16; i++ )
      {
         RFSpecialCoef.rx.mt6162_gain_rf.gain_rf_table[0].map[i] = TX_GAINRF_MAPPING[0][i];
         RFSpecialCoef.rx.mt6162_gain_rf.gain_rf_table[1].map[i] = TX_GAINRF_MAPPING[1][i];
         RFSpecialCoef.rx.mt6162_gain_rf.gain_rf_table[2].map[i] = TX_GAINRF_MAPPING[2][i];
         RFSpecialCoef.rx.mt6162_gain_rf.gain_rf_table[3].map[i] = TX_GAINRF_MAPPING[3][i];
      }

      for( i = 0; i < 8; i++ )
      {
         RFSpecialCoef.tx.mt6162tx.data.GSM850_pa_vbias[i].pcl_index  = i*2 + 7;
         RFSpecialCoef.tx.mt6162tx.data.GSM850_pa_vbias[i].pa_vbias   = 4; /* pcl_index[i-1]< PCL <= pcl_index[i], assign PA_Vbias[i]*184+APC_DC_OFFSET into APC_DAC*/

         RFSpecialCoef.tx.mt6162tx.data.GSM900_pa_vbias[i].pcl_index  = i*2 + 7;
         RFSpecialCoef.tx.mt6162tx.data.GSM900_pa_vbias[i].pa_vbias   = 4;

         RFSpecialCoef.tx.mt6162tx.data.DCS1800_pa_vbias[i].pcl_index = i*2 + 2;
         RFSpecialCoef.tx.mt6162tx.data.DCS1800_pa_vbias[i].pa_vbias  = 4;

         RFSpecialCoef.tx.mt6162tx.data.PCS1900_pa_vbias[i].pcl_index = i*2 + 2;
         RFSpecialCoef.tx.mt6162tx.data.PCS1900_pa_vbias[i].pa_vbias  = 4;
      }
   }
#elif IS_RF_MT6256RF

   {  int i;

      for( i = 0; i < 8; i++ )
      {
         // pcl_index[i-1]< PCL <= pcl_index[i], assign PA_Vbias[i]*128 into APC_DAC
         RFSpecialCoef.tx.mt6256tx.data.GSM850_pa_vbias[i].pcl_index  = i*2 + 7;
         RFSpecialCoef.tx.mt6256tx.data.GSM850_pa_vbias[i].pa_vbias   = 5;
         RFSpecialCoef.tx.mt6256tx.data.GSM900_pa_vbias[i].pcl_index  = i*2 + 7;
         RFSpecialCoef.tx.mt6256tx.data.GSM900_pa_vbias[i].pa_vbias   = 5;
         RFSpecialCoef.tx.mt6256tx.data.DCS1800_pa_vbias[i].pcl_index = i*2 + 2;
         RFSpecialCoef.tx.mt6256tx.data.DCS1800_pa_vbias[i].pa_vbias  = 5;
         RFSpecialCoef.tx.mt6256tx.data.PCS1900_pa_vbias[i].pcl_index = i*2 + 2;
         RFSpecialCoef.tx.mt6256tx.data.PCS1900_pa_vbias[i].pa_vbias  = 5;
      }
   }

#elif IS_RF_CMOSEDGE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif IS_RF_SKY74117 || IS_RF_SKY74400
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif IS_RF_SKY74045
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif IS_RF_BRIGHT5P
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif IS_RF_AD6546

   RFSpecialCoef.tx.ad6546tx.CalData[0].REFDET_SLOPE_SKEW= 0x00;  /*GSM850*/
   RFSpecialCoef.tx.ad6546tx.CalData[0].AM_FB_DAC= 0x00;          /*GSM850*/
   RFSpecialCoef.tx.ad6546tx.CalData[1].REFDET_SLOPE_SKEW= 0x00;  /*GSM900*/
   RFSpecialCoef.tx.ad6546tx.CalData[1].AM_FB_DAC= 0x00;          /*GSM900*/
   RFSpecialCoef.tx.ad6546tx.CalData[2].REFDET_SLOPE_SKEW= 0x00;  /*DCS1800*/
   RFSpecialCoef.tx.ad6546tx.CalData[2].AM_FB_DAC= 0x00;          /*DCS1800*/
   RFSpecialCoef.tx.ad6546tx.CalData[3].REFDET_SLOPE_SKEW= 0x00;  /*PCS1900*/
   RFSpecialCoef.tx.ad6546tx.CalData[3].AM_FB_DAC= 0x00;          /*PCS1900*/

   #if IS_HW_DISABLE_EPSK_TX_SUPPORT
   RFSpecialCoef.tx.ad6546tx.CalData[0].AM_FB_DAC= 0x08;          /*GSM850*/
   RFSpecialCoef.tx.ad6546tx.CalData[1].AM_FB_DAC= 0x08;          /*GSM900*/
   RFSpecialCoef.tx.ad6546tx.CalData[2].AM_FB_DAC= 0x08;          /*DCS1800*/
   RFSpecialCoef.tx.ad6546tx.CalData[3].AM_FB_DAC= 0x08;          /*PCS1900*/
   RFSpecialCoef.tx.ad6546tx.Reg8_default[0] = 0x00800008;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[1] = 0x00800008;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[2] = 0x00800008;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[3] = 0x00800008;
   #elif defined(QB_ASM_TQM7M5008)
   RFSpecialCoef.tx.ad6546tx.Reg8_default[0] = 0x00009808;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[1] = 0x00009808;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[2] = 0x00009608;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[3] = 0x00009608;
   #elif defined(FEM_SKY77523)
   RFSpecialCoef.tx.ad6546tx.Reg8_default[0] = 0x00009C08;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[1] = 0x00009C08;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[2] = 0x00009688;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[3] = 0x00009708;
   #else
   RFSpecialCoef.tx.ad6546tx.Reg8_default[0] = 0x00009808;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[1] = 0x00009808;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[2] = 0x00009688;
   RFSpecialCoef.tx.ad6546tx.Reg8_default[3] = 0x00009688;
   #endif

   RFSpecialCoef.tx.ad6546tx.AMLoopDelta.MID_DELTA_APC_CAP    =  0;
   RFSpecialCoef.tx.ad6546tx.AMLoopDelta.MID_DELTA_SLOPE_SKEW = -2;
   RFSpecialCoef.tx.ad6546tx.AMLoopDelta.MID_GAMA_THRESHOLD   = 11;
   RFSpecialCoef.tx.ad6546tx.AMLoopDelta.LOW_DELTA_APC_CAP    =  0;
   RFSpecialCoef.tx.ad6546tx.AMLoopDelta.LOW_DELTA_SLOPE_SKEW = -7;
   RFSpecialCoef.tx.ad6546tx.AMLoopDelta.LOW_GAMA_THRESHOLD   = 15;

#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

extern void L1D_RF_Custom_Table_Update_V2( void );
extern void  nvram_init_L1_RF_customInputData(void);
kal_bool nvram_special_service(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    nvram_init_L1_RF_customInputData();
    L1D_RF_Custom_Table_Update_V2( );    
    {
#ifdef __MTK_TARGET__
  #ifndef NVRAM_NOT_PRESENT
       extern void L1T_InitCalibrationData( void );
       L1T_InitCalibrationData();
  #endif
#endif
    }

    return KAL_FALSE;

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

nvram_read_callback_entry l1_callback[] =
{
    {nvram_special_service, NULL, MOD_NIL, 0xFF, KAL_FALSE},
};
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Init( void )
{
   nvram_register_read_req(l1_callback);
   
   L1D_RF_Init_Data();
   L1D_RF_Init_GPIO();
   L1D_RF_Init_BSI();
   L1D_RF_Init_BPI();
   L1D_RF_Init_APC();
   L1D_RF_Init_AFC();
   L1D_RF_Init_DLUL();
   L1D_RF_Init_BFE();
   L1D_RF_Init_FIR();
   L1D_RF_Init_AUXADC();
   L1D_RF_Init_ChipOptimizeSetting();
   L1D_RF_Init_SpecialCoef();

   l1d_rf.is_init = 1;
   L1D_RF_PowerOn();
   l1d_rf.is_init = 0;
   l1d_rf.bb_tx_autocal = 0;

#if IS_CHIP_MT6205B || IS_CHIP_MT6218A
   #if !IS_RF_AERO   /* apply bb_tx_autocal for All RF except AERO */
//    #if !IS_RF_AERO1PLUS
   l1d_rf.bb_tx_autocal = 1;
//    #endif
   #endif
#endif

#if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   l1d_rf.bb_tx_autocal = 1;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetFixGainEnable( unsigned char enable )
{
   /* For 74137 to pass 14.18.5 */
#if IS_RF_SKY74137
/* under construction !*/
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetPathLossTable( int rf_band, void *table )
{  unsigned char *src, *dst;
   int  n;

   src = (unsigned char*)table;
   dst = (unsigned char*)(AGC_PATHLOSS_TABLE[rf_band]);
   if(dst==0)  return;
   for( n=sizeof(sAGCGAINOFFSET)*PLTABLE_SIZE; n>0; n--)
   {  *dst++ = *src++;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetLnaPathLossTable( sLNAPATHLOSS_L1CAL *table )
{  /* for the RX LNA middle/low modes use */
#if IS_RF_MT6162
   unsigned char *src, *dst;
   int  i, n;

   for( i=0; i<FrequencyBandCount; i++ )
   {
      src = (unsigned char*)table->lnaPathLoss[i];
      dst = (unsigned char*)(LNA_PATHLOSS_TABLE[i]);
      if( dst!=0 )
      {
         for( n=sizeof(sLNAGAINOFFSET)*PLTABLE_SIZE; n>0; n--)
         {  *dst++ = *src++;  }
      }
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_GetLnaPathLossTable( sLNAPATHLOSS_L1CAL *table )
{  /* for the RX LNA middle/low modes use */
#if IS_RF_MT6162
   unsigned char *src, *dst;
   int  i, n;

   for( i=0; i<FrequencyBandCount; i++ )
   {
      dst = (unsigned char*)table->lnaPathLoss[i];
      src = (unsigned char*)(LNA_PATHLOSS_TABLE[i]);
      if( dst!=0 )
      {
         for( n=sizeof(sLNAGAINOFFSET)*PLTABLE_SIZE; n>0; n--)
         {  *dst++ = *src++;  }
      }
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_CheckFHC( char is_fhc )
{  /* for the RX LNA path loss calibration use */
#if IS_RF_MT6162
   l1d_rf2.is_fhc = is_fhc;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetRampApcLevel( int rf_band, int power_in_dBm, int apc_dac )
{
   sRAMPDATA *ramp;
   int        idx;

   ramp = RampData[rf_band];
   idx = (power_in_dBm-LOWEST_TX_POWER[rf_band])/2;
   ramp->power[idx] = apc_dac;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_EPSK_TX_SUPPORT
/*EPSK*/ void L1D_RF_SetRampApcLevelEPSK( int rf_band, int power_in_dBm, int apc_dac )
/*EPSK*/ {
/*EPSK*/    sRAMPDATA *ramp;
/*EPSK*/    int        idx;
/*EPSK*/
/*EPSK*/    ramp = RampData_EPSK[rf_band];
/*EPSK*/    idx = (power_in_dBm-LOWEST_TX_POWER[rf_band])/2;
/*EPSK*/    ramp->power[idx] = apc_dac;
/*EPSK*/ }
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_FHC_SUPPORT
/*
short L1D_RF_GetAFCDacTRxOffset( int rf_band )
{
   return (short)(RampData[rf_band]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level);
}
*/

void L1D_RF_GetAFCDacTRxOffset( short *afcdactrxoffset )
{
   int i;
   for (i=0; i<FrequencyBandCount; i++)
   {
      afcdactrxoffset[i] = (short)(RampData[i]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level);
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetAFCDacTRxOffset( short *afcdactrxoffset )
{
   int i;
   for (i=0; i<FrequencyBandCount; i++)
   {
      RampData[i]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level = (unsigned short)afcdactrxoffset[i];

      {
   #if IS_VCXO_LC_TRXOFFSET_COMPENSATE_SUPPORT
         extern  short AFC_TRx_Offset[5];
         extern  short AFC_Default_TRx_Offset[5];
   #else
         extern  short AFC_Dac_TRx_Offset[5];
      #if IS_RF_MT6162
         extern  short AFC_TRx_Offset[5];
         extern  short AFC_Default_TRx_Offset[5];
      #endif
   #endif

   #if defined(AFC_VCXO)
      #if IS_VCXO_LC_TRXOFFSET_COMPENSATE_SUPPORT
/*VCXO*/    AFC_TRx_Offset[i] = (short)(RampData[i]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level)+AFC_Default_TRx_Offset[i];
      #else
/*VCXO*/    AFC_Dac_TRx_Offset[i] = (short)(RampData[i]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level);
      #endif
   #else
/*VCTCXO*/  AFC_Dac_TRx_Offset[i] = 0;
   #endif
      }
   #if IS_RF_MT6162
      {  /* for OthelloH, we set the TRx offset directly in the TX synthesizer in stead of AFC_DAC */
         AFC_Dac_TRx_Offset[i] = 0;
         AFC_TRx_Offset[i]     = (short)(RampData[i]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level+AFC_Default_TRx_Offset[i]);
      }
   #endif
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

void L1D_RF_GetPGAGain( unsigned short tx_power )
{
#if IS_FHC_SUPPORT && IS_EPSK_TX_GAIN_CONTROL_SUPPORT
   if( l1d_rf.fhc_proc==FHC_PROC_UTS_DAC )
   {
      if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot) & 0x1 )  /*EPSK*/
      {  l1d_rf2.fhc_PGA_gain = tx_power;
      }
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetRampTable( int rf_band, void *table )
{  unsigned char *src, *dst;
   int  n;

   src = (unsigned char*)table;
   dst = (unsigned char*)(RampData[rf_band]);

   if(dst==0)  return;

   for( n=sizeof(sRAMPDATA); n>0; n--)
   {  *dst++ = *src++;
   }
   L1D_RF_InitRampTable( rf_band );
#if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
   L1D_RF_TXPC_CL_BackUpSubband( rf_band, 0 );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_EPSK_TX_SUPPORT
/*EPSK*/ void L1D_RF_SetRampTableEPSK( int rf_band, void *table )
/*EPSK*/ {  unsigned char *src, *dst;
/*EPSK*/    int  n;
/*EPSK*/
/*EPSK*/    src = (unsigned char*)table;
/*EPSK*/    dst = (unsigned char*)(RampData_EPSK[rf_band]);
/*EPSK*/
/*EPSK*/    if(dst==0)  return;
/*EPSK*/
/*EPSK*/    for( n=sizeof(sRAMPDATA); n>0; n--)
/*EPSK*/    {  *dst++ = *src++;
/*EPSK*/    }
/*EPSK*/    L1D_RF_InitRampTableEPSK( rf_band );
   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
/*EPSK*/    L1D_RF_TXPC_CL_BackUpSubband( rf_band, 1 );
   #endif
/*EPSK*/ }
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

void L1D_RF_InitRampTable( int rf_band )
{  int  n;
   sARFCN_SECTION *arfcn_weight_ptr;

   if( RampData[rf_band]==0 )  return;

   arfcn_weight_ptr = &(RampData[rf_band]->arfcn_weight[0]);
   for(n=ARFCN_SECTION_NUM-1; n>=0; n--)
   {  if(arfcn_weight_ptr->max_arfcn<0) break;
      arfcn_weight_ptr++;
   }
   weight_section_end_idx[rf_band] = (ARFCN_SECTION_NUM-1)-n-1;

   l1d_rf.apc_dc_offset = (RampData[rf_band]->lowest_power>>8)&0x0000FFFF;
   /*  RampData[rf_band]->lowest_power &= 0x000000FF;  */

   /*shine*/
   /* (short)RampData[rf_band]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level  */
   /* is stored the afc dac offset data for TX              */
   {  extern  short AFC_Dac_TRx_Offset[5];
#if defined(AFC_VCXO)
   #if IS_VCXO_LC_TRXOFFSET_COMPENSATE_SUPPORT
/*VCXO*/    AFC_TRx_Offset[rf_band] = (short)(RampData[rf_band]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level)+AFC_Default_TRx_Offset[rf_band];
   #else
/*VCXO*/    AFC_Dac_TRx_Offset[rf_band] = (short)(RampData[rf_band]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level);
   #endif
#else
/*VCTCXO*/  AFC_Dac_TRx_Offset[rf_band] = 0;
#endif
   }
#if IS_RF_MT6162
   {  /* for OthelloH, we set the TRx offset directly in the TX synthesizer in stead of AFC_DAC */
      AFC_Dac_TRx_Offset[rf_band] = 0;
      AFC_TRx_Offset[rf_band]     = (short)(RampData[rf_band]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level+AFC_Default_TRx_Offset[rf_band]);
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_EPSK_TX_SUPPORT
/*EPSK*/ void L1D_RF_InitRampTableEPSK( int rf_band )
/*EPSK*/ {
/*EPSK*/    int  n;
/*EPSK*/    sARFCN_SECTION *arfcn_weight_ptr;
/*EPSK*/
/*EPSK*/    if( RampData_EPSK[rf_band]==0 )  return;
/*EPSK*/
/*EPSK*/    arfcn_weight_ptr = &(RampData_EPSK[rf_band]->arfcn_weight[0]);
/*EPSK*/    for(n=ARFCN_SECTION_NUM-1; n>=0; n--)
/*EPSK*/    {  if(arfcn_weight_ptr->max_arfcn<0) break;
/*EPSK*/       arfcn_weight_ptr++;
/*EPSK*/    }
/*EPSK*/    weight_section_end_idx_EPSK[rf_band] = (ARFCN_SECTION_NUM-1)-n-1;
/*EPSK*/ }
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

void L1D_RF_SetInterSlotRampTable( int rf_band, void *table )
{
#if IS_GPRS || IS_MULTISLOT_TX_SUPPORT
/*GPRS*/ unsigned char *src, *dst;
/*GPRS*/ int  n;
/*GPRS*/
/*GPRS*/ src = (unsigned char*)table;
/*GPRS*/ dst = (unsigned char*)(InterRampData[rf_band]);
/*GPRS*/
/*GPRS*/ if(dst==0)  return;
/*GPRS*/
/*GPRS*/ for( n=16; n>0; n--)
/*GPRS*/ {  *dst++ = *src++;
/*GPRS*/ }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_EPSK_TX_SUPPORT
void L1D_RF_EPSK_SetInterSlotRampTable( int rf_band, int _8G_mode, void *table )
{
   #if IS_GPRS
/*GPRS*/ unsigned char *src, *dst;
/*GPRS*/ int  n;
/*GPRS*/
/*GPRS*/ src = (unsigned char*)table;
/*GPRS*/ dst = (unsigned char*)(*(EPSK_InterRampData[rf_band])[_8G_mode]);
/*GPRS*/
/*GPRS*/ if(dst==0)  return;
/*GPRS*/
/*GPRS*/ for( n=16; n>0; n--)
/*GPRS*/ {   *dst++ = *src++;
/*GPRS*/ }
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_RF_TX_CALIBRATION_SUPPORT || IS_RF_RX_DCOC_SUPPORT
#define L1D_GCMACHINE_STOP()
#else
#define L1D_GCMACHINE_STOP() L1D_GCMachine_Stop()
#endif

void L1D_RF_SetBBTXParameters( void *table )
{  unsigned char *src, *dst;
   int  n;

   src = (unsigned char*)table;
   dst = (unsigned char*)(&BBTXParameters);

   for( n=sizeof(sBBTXParameters); n>0; n--)
   {  *dst++ = *src++;
   }

   /*************************************************************
    Note That BBTXParameters is same with the settings
    on the BFE register only when the bbtx_isCalibrated == 0xBF.
    Else, the settings on the BFE register is set from the GCM.
    *************************************************************/
   if( BBTXParameters.bbtx_isCalibrated == 0xBF )
      L1D_GCMACHINE_STOP();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetCrystalCap( int cap_no )
{
//#ifdef   AFC_SC
#if 1  // because it has no effect when use VCTCXO, so enable this activity
/*SC*/XO_CapID = cap_no;
/*SC*/L1D_RF_PowerOn();
      L1D_RF_Set_SLEEP_SPI();
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetCrystalCap_Value( int cap_no )
{
//#ifdef   AFC_SC
#if 1  // because it has no effect when use VCTCXO, so enable this activity
/*SC*/XO_CapID = cap_no;
/*SC*///L1D_RF_PowerOn();
      L1D_RF_Set_SLEEP_SPI();
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetCrystalDac( short dacValue )
{
   l1d_rf.AFC_data = dacValue;
   L1D_RF_PowerOn();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetCrystalDac_Value( short dacValue )
{
   l1d_rf.AFC_data = dacValue;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int  L1D_RF_GetCrystalCapRange( void )
{
#ifdef AFC_VCXO
   return CRYSTAL_CAPID_RANGE;
#else
   return 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int  L1D_RF_GetWCalMode( void )
{
#if IS_W_CANCELLATION_SUPPORT

   #if IS_CHIP_MT6251
   return ZERO_POINT_SIXTEEN_SUBBAND;
   #elif IS_CHIP_MT6256 || IS_CHIP_MT6255
   return FOUR_POINT_FOUR_SUBBAND;
   #else
   return ONE_POINT_SIXTEEN_SUBBAND;
   #endif

#else
   return ZERO_POINT_SIXTEEN_SUBBAND;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetCrystalAFCData( void *table )
{
#ifdef AFC_SC
/*SC*/ unsigned char *src, *dst;
/*SC*/ int  n;
/*SC*/
/*SC*/ src = (unsigned char*)table;
/*SC*/ dst = (unsigned char*)(XO_SlopeAreaData);
/*SC*/ for( n=sizeof(XO_SLOPE_AREA_DATA)*XO_SlopeArea_Num; n>0; n--)
/*SC*/ {  *dst++ = *src++;
/*SC*/ }
/*SC*/ {  void  XO_Initialize( void );
/*SC*/    XO_Initialize();
/*SC*/ }
#endif

#if IS_VCXO_LC_SUPPORT
/*LC*/ unsigned char *src, *dst;
/*LC*/ int  n;
/*LC*/
/*LC*/ src = (unsigned char*)table;
/*LC*/ dst = (unsigned char*)(XO_SlopeAreaData);
/*LC*/ for( n=sizeof(XO_SLOPE_AREA_DATA)*XO_SlopeArea_Num; n>0; n--)
/*LC*/    *dst++ = *src++;
/*LC*/
/*LC*/ /*Initialize AFC look-up table*/
/*LC*/ XO_LC_Initialize();
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// Interface for determining the calibration of this item is capable/mandatory or not
unsigned short  L1D_RF_GetCalSets( FAC_CAL_ITEM item )
{
   unsigned short setting = FMC_NULL_SETTING;

   switch( item )
   {
/*CAP ID*/ // CAP ID calibration
/*CAP ID*/ case FMC_CAP_ID:
/*CAP ID*/ {
/*CAP ID*/ #ifdef AFC_VCXO
/*CAP ID*/    setting = FMC_CAPABLE|FMC_MANDATORY;
/*CAP ID*/ #else
/*CAP ID*/    setting = FMC_NULL_SETTING;          // TCVCXO (no need to do CAPID calibration)
/*CAP ID*/ #endif
/*CAP ID*/    break;
/*CAP ID*/ }

/*TRX OF*/ // TRX offset calibration
/*TRX OF*/ case FMC_TRX_OFFSET:
/*TRX OF*/ {
/*TRX OF*/ #if IS_RF_MT6139B || IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B || IS_RF_MT6139E || IS_RF_MT6140C || IS_RF_MT6140D || IS_RF_CMOSEDGE
/*TRX OF*/    setting = FMC_CAPABLE|FMC_MANDATORY;
/*TRX OF*/ #elif IS_RF_MTKSOC1 || IS_RF_MT6252RF
/*TRX OF*/    setting = FMC_NULL_SETTING;
/*TRX OF*/ #else
/*TRX OF*/    setting = FMC_CAPABLE;
/*TRX OF*/ #endif
/*TRX OF*/    break;
/*TRX OF*/ }

/*TX IQ*/  // TX IQ calibration
/*TX IQ*/  case FMC_TX_IQ:
/*TX IQ*/  {
/*TX IQ*/  #if IS_DLIF_CHIP || IS_RF_MT6162
/*TX IQ*/     setting = FMC_NULL_SETTING;
/*TX IQ*/  #elif IS_SOC_CHIP
/*TX IQ*/     setting = FMC_CAPABLE;
/*TX IQ*/  #else
/*TX IQ*/     setting = FMC_CAPABLE|FMC_MANDATORY;
/*TX IQ*/  #endif
/*TX IQ*/     break;
/*TX IQ*/  }

/*MT6546*/ // OE calibration
/*MT6546*/ case FMC_OE_ITEM:
/*MT6546*/ {
/*MT6546*/ #if IS_RF_AD6546
/*MT6546*/    setting = FMC_CAPABLE|FMC_MANDATORY;
/*MT6546*/ #endif
/*MT6546*/    break;
/*MT6546*/ }

/*W COEF*/ // W coefficient calibration
/*W COEF*/ case FMC_W_COEF:
/*W COEF*/ {
/*W COEF*/ #if IS_RF_MT6251RF || IS_RF_MT6256RF || IS_RF_MT6255RF || IS_RF_MT6250RF || IS_RF_MT6260RF || IS_RF_MT6261RF
/*W COEF*/    setting = FMC_CAPABLE|FMC_MANDATORY;
/*W COEF*/ #endif
/*W COEF*/    break;
/*W COEF*/ }

/*TX PC*/  // TX power control calibration
/*TX PC*/  case FMC_TX_PC:
/*TX PC*/  {
/*TX PC*/  #if IS_TX_POWER_CONTROL_SUPPORT
/*TX PC*/     if( closed_loop_txpc_type>0 || open_loop_txpc_type>0 )
/*TX PC*/     {  setting = FMC_CAPABLE|FMC_MANDATORY;  }
/*TX PC*/  #endif
/*TX PC*/     break;
/*TX PC*/  }

/*TX PC*/  // TX power control temperature calibration
/*TX PC*/  case FMC_TX_PC_TEMP:
/*TX PC*/  {
/*TX PC*/  #if IS_TX_POWER_CONTROL_SUPPORT
/*TX PC*/     if( temp_adc_cal_type>0 )
/*TX PC*/     {  setting = FMC_CAPABLE|FMC_MANDATORY;  }
/*TX PC*/  #endif
/*TX PC*/     break;
/*TX PC*/  }

/*DTS EN*/ // FHC DTS gain mode combine calibration
/*DTS EN*/ case FMC_DTS_GAIN_CMB:
/*DTS EN*/ {
/*DTS EN*/ #if IS_RF_MT6280RF || IS_RF_MT6167 || (IS_RF_MT6163&&IS_CHIP_MT6583_MD2) || IS_CHIP_MT6260 || IS_CHIP_MT6261
/*DTS EN*/    setting = FMC_CAPABLE|FMC_MANDATORY;
/*DTS EN*/ #endif
/*DTS EN*/    break;
/*DTS EN*/ }

/*UTS EN*/ // FHC UTS TX band combine calibration
/*UTS EN*/ case FMC_UTS_BAND_CMB:
/*UTS EN*/ {
/*UTS EN*/ #if IS_RF_MT6280RF || IS_RF_MT6167 || (IS_RF_MT6163&&IS_CHIP_MT6583_MD2) || IS_CHIP_MT6260 || IS_CHIP_MT6261
/*UTS EN*/    setting = FMC_CAPABLE|FMC_MANDATORY;
/*UTS EN*/ #endif
/*UTS EN*/    break;
/*UTS EN*/ }
   }
   return setting;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetRFSpecialCoef( void *table )
{
   unsigned char *src, *dst;
   int  n;

   src = (unsigned char*)table;
   dst = (unsigned char*)(&RFSpecialCoef);
   for( n=sizeof(sRFSpecialCoef); n>0; n--)
   {  *dst++ = *src++;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned long L1D_RF_GetID( void )
{
#if IS_RF_BRIGHT2
/* under construction !*/
#endif

#if IS_RF_BRIGHT4
/* under construction !*/
#endif

#if IS_RF_BRIGHT5P
/* under construction !*/
#endif

#if IS_RF_AERO
/* under construction !*/
#endif

#if IS_RF_AERO1PLUS
/* under construction !*/
#endif

#if IS_RF_POLARIS1
/* under construction !*/
#endif

#if IS_RF_SKY74045
/* under construction !*/
#endif

#if IS_RF_SKY74117
/* under construction !*/
#endif

#if IS_RF_SKY74400
/* under construction !*/
#endif

#if IS_RF_MT6119C
/* under construction !*/
#endif

#if IS_RF_MT6129D
    return RF_ID_MT6129D;
#endif

#if IS_RF_MT6139B
/* under construction !*/
#endif

#if IS_RF_MT6139C
/* under construction !*/
#endif

#if IS_RF_MT6139E
    return RF_ID_MT6139E;
#endif
#if IS_RF_MT6140A
/* under construction !*/
#endif

#if IS_RF_MT6140B
/* under construction !*/
#endif

#if IS_RF_MT6140C
/* under construction !*/
#endif

#if IS_RF_MT6140D
    return RF_ID_MT6140D;
#endif

#if IS_RF_CMOSEDGE
/* under construction !*/
#endif

#if IS_RF_MTKSOC1 || IS_RF_MTKSOC1T
    return RF_ID_MTKSOC1;
#endif

#if IS_RF_MT6252RF
    return RF_ID_MT6252RF;
#endif

#if IS_RF_MT6256RF
    return RF_ID_MT6256RF;
#endif

#if IS_RF_MT6255RF
    return RF_ID_MT6255RF;
#endif

#if IS_RF_MT6250RF
    return RF_ID_MT6250RF;
#endif

#if IS_RF_MT6251RF
    return RF_ID_MT6251RF;
#endif

#if IS_RF_MT6260RF
    return RF_ID_MT6260RF;
#endif

#if IS_RF_MT6261RF
   return RF_ID_MT6261RF;
#endif

#if IS_RF_AERO2
/* under construction !*/
#endif

#if IS_RF_SKY74137
/* under construction !*/
#endif

#if IS_RF_GRF6201
/* under construction !*/
#endif

#if IS_RF_IRFS3001
/* under construction !*/
#endif

#if IS_RF_AD6548
    return RF_ID_AD6548;
#endif

#if IS_RF_AD6546
    return RF_ID_AD6546;
#endif

#if IS_RF_MT6162
    return RF_ID_MT6162;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetImmediateBSI( unsigned long bsidata )
{
#if IS_COSIM_ON_L1SIM_SUPPORT
/* use the MT6167's setting here, but need to check it if new chip is implemented */
                IMM_MODE_BEGIN( IMMMASK_ALL );
                IMM_SEND_BSI( SCTRL_IMOD(0,30), bsidata);
                IMM_MODE_END(  );
#else
#if IS_RF_MT6139B
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if IS_RF_MT6139C || IS_RF_MT6139E || IS_RF_MT6140A || IS_RF_MT6140B || IS_RF_MT6140C || IS_RF_MT6140D || IS_RF_CMOSEDGE || IS_RF_MTKSOC1 || IS_RF_MTKSOC1T
 /*MT6139C&MT6140A*/    IMM_MODE_BEGIN( IMMMASK_ALL );
 /*MT6139C&MT6140A*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), bsidata );
 /*MT6139C&MT6140A*/    IMM_MODE_END(  );
#endif
#if IS_RF_MT6252RF
 /*MT6252RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
 /*MT6252RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), bsidata );
 /*MT6252RF*/    IMM_MODE_END(  );
#endif
#if IS_RF_MT6256RF || IS_RF_MT6251RF || IS_RF_MT6255RF
 /*MT6256RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
 /*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,(1+8+20)), bsidata );
 /*MT6256RF*/    IMM_MODE_END();
#endif
#if IS_RF_MT6250RF || IS_RF_MT6260RF  || IS_RF_MT6261RF
 /*MT6250RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
 /*MT6250RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), bsidata );
 /*MT6250RF*/    IMM_MODE_END();
#endif
#if IS_RF_SKY74117
/* under construction !*/
 /*SKY74117*/    #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
 /*SKY74117*/    #else
/* under construction !*/
 /*SKY74117*/    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if IS_RF_SKY74400
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if IS_RF_BRIGHT5P
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if IS_RF_MT6162
 /*MT6162*/      if( IS_AFC_TRIGGER_BSI() )
 /*MT6162*/      {  IMM_MODE_BEGIN( IMMMASK_BSI|IMMMASK_BPI );  }
 /*MT6162*/      else
 /*MT6162*/      {  IMM_MODE_BEGIN( IMMMASK_ALL );              }
 /*MT6162*/      IMM_SEND_BSI( SCTRL_IMOD(0,30), bsidata);
 /*MT6162*/      IMM_MODE_END(  );
#endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_GetImmediateBSI( unsigned long bsi_addr, unsigned long *bsi_data )
{
#if IS_RF_MT6139B
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B || IS_RF_MT6140C
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_CMOSEDGE || IS_RF_MTKSOC1 || IS_RF_MTKSOC1T
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_RECEIVE_BSI(SCTRL_IMOD(0,6), bsi_addr ,SCTRL_IMOD(0,20), bsi_data);
   IMM_MODE_END(  );
#endif

#if IS_RF_MT6252RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_RECEIVE_BSI(SCTRL_IMOD(0,9), bsi_addr ,SCTRL_IMOD(0,20), bsi_data);
   IMM_MODE_END(  );
#endif

#if IS_RF_MT6256RF || IS_RF_MT6251RF || IS_RF_MT6255RF || IS_RF_MT6250RF || IS_RF_MT6260RF  || IS_RF_MT6261RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_RECEIVE_BSI( 0, bsi_addr, 0, bsi_data );
   IMM_MODE_END(  );
#endif

#if IS_RF_MT6162
   if( IS_AFC_TRIGGER_BSI() )
   {  IMM_MODE_BEGIN( IMMMASK_BSI|IMMMASK_BPI );  }
   else
   {  IMM_MODE_BEGIN( IMMMASK_ALL );              }
   IMM_RECEIVE_BSI(SCTRL_IMOD(0,10), bsi_addr ,SCTRL_IMOD(0,20), bsi_data);
   IMM_MODE_END(  );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*===============================================================================================*/

void WAIT_TIME_QB( short time_qb )
{
#ifndef  L1_SIM
   unsigned short  last_qb, cur_qb;
   short  qb_diff, qb_remain;


   qb_remain = time_qb;
   last_qb = HW_READ( TDMA_TQCNT );
   while( qb_remain>0 )
   {  cur_qb = HW_READ( TDMA_TQCNT );
      qb_diff = cur_qb-last_qb;
      qb_remain -= (qb_diff<0) ? 1 : qb_diff;
      last_qb = cur_qb;
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_DCXO_SUPPORT_CHIP
extern unsigned int L1D_Get_UST_Current_Time( void );
void WAIT_TIME_US( unsigned int time_us )
{
   #ifndef  L1_SIM
   unsigned int  last_us, cur_us;
   int  us_diff, us_remain;


   us_remain = time_us;
   last_us = L1D_Get_UST_Current_Time();
   while( us_remain>0 )
   {  cur_us = L1D_Get_UST_Current_Time();
      us_diff = cur_us-last_us;
      us_remain -= (us_diff<0) ? 1 : us_diff;
      last_us = cur_us;
   }
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

static void IMM_MODE_AFC_BEGIN( void )
{
#if IS_AFC_EVENT_ENABLE
   HW_WRITE( AFC_DAT(0), l1d_rf.AFC_data );
   HW_WRITE( AFC_CON   , AFC_FORCE_POWER_ON );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void IMM_MODE_AFC_END( void )
{
#if IS_AFC_EVENT_ENABLE
   if( IS_AFC_TRIGGER_BSI() )
   {  /* set AFC back to the event-triggered mode */
      HW_WRITE( AFC_CON, AFC_EVENT_TRIGGER );
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifdef __CUST_NEW__
   #ifndef  L1_SIM
      #if IS_CHIP_MT6205
         #if IS_RF_AERO || IS_RF_AERO1PLUS || IS_RF_AERO2
/* under construction !*/
         #endif
      #endif
   #endif
#endif /*__CUST_NEW__*/

static void IMM_MODE_BPI_BEGIN( void )
{
   L1D_SET_BPI_IMM_MODE_BEGIN();
#ifndef  L1_SIM
   #if IS_CHIP_MT6205
      #if IS_RF_AERO || IS_RF_AERO1PLUS || IS_RF_AERO2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6205*//*AERO*/    #ifndef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6205*//*AERO*/    #else /*__CUST_NEW__*/
/* under construction !*/
/* under construction !*/
/*MT6205*//*AERO*/    #endif /*__CUST_NEW__*/
/* under construction !*/
      #endif
   #endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void IMM_MODE_BPI_END( void )
{
   L1D_SET_BPI_IMM_MODE_END();
#if IS_CHIP_MT6268T || IS_CHIP_MT6268H || IS_CHIP_MT6268 || IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
   HW_WRITE( BPI_ENA , 0xFFFFFFFF );
   HW_WRITE( BPI_ENA1, 0x03FF );
#elif IS_CHIP_MT6256_S00
   HW_WRITE( BPI_ENA , 0xFFFF );
   HW_WRITE( BPI_ENA1, 0xFFFF );
   HW_WRITE( BPI_ENA2, 0x03FF );
#elif IS_CHIP_MT6256
   HW_WRITE( BPI_ENA , 0xFFFF );
   HW_WRITE( BPI_ENA1, 0x3FFF );
#elif IS_CHIP_MT6252 || IS_CHIP_MT6255 || IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
   HW_WRITE( BPI_ENA , 0xFFFF );
   HW_WRITE( BPI_ENA1, 0x001F );
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   HW_WRITE( BPI_ENA , 0xFFFF );
   HW_WRITE( BPI_ENA1, 0xFFFF );
   HW_WRITE( BPI_ENA2, 0x03FF );
#elif IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION
   HW_WRITE( BPI_ENA , 0xFFFF );
   HW_WRITE( BPI_ENA1, 0x03FF );
#elif IS_CHIP_MT6217 || IS_CHIP_MT6218 || IS_CHIP_MT6219 || IS_CHIP_MT6228
   HW_WRITE( BPI_ENA , 0xFFFF );
   HW_WRITE( BPI_ENA1, 0x003F );
#else
   HW_WRITE( BPI_ENA , 0xFFFF );
#endif

#ifndef  L1_SIM
   #if IS_CHIP_MT6205
      #if IS_RF_AERO || IS_RF_AERO1PLUS || IS_RF_AERO2
/* under construction !*/
/*MT6205*//*AERO*/ #ifndef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6205*//*AERO*/ #else /*__CUST_NEW__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6205*//*AERO*/ #endif /*__CUST_NEW__*/
      #endif
   #endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void IMM_MODE_BSI_BEGIN( void )
{
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void IMM_MODE_BSI_END( void )
{
   HW_WRITE( BSI_CON,  SCTRL_MAIN );
#if IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
   #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
   HW_WRITE( BSI_ENA , 0xFFFF );
   HW_WRITE( BSI_ENA1, 0xFFFF );
   HW_WRITE( BSI_ENA2, 0x000F );
   #elif IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
   HW_WRITE( BSI_ENA , 0x001FFFFF );
   #else
   HW_WRITE( BSI_ENA , 0xFFFF );
   HW_WRITE( BSI_ENA1, 0x001F );
   #endif
#elif IS_CHIP_MT6268H || IS_CHIP_MT6268T_DMAC
   HW_WRITE( BSI_ENA,  0xFFFFFFFF );
   HW_WRITE( BSI_ENA1, 0x0000000F );
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
   #if IS_CHIP_MT6270A_E1 || IS_CHIP_MT6276_S00 || IS_CHIP_MT6573
   HW_WRITE( BSI_ENA,  0xFFFFFFFF ); // MT6270A E1, MT6276E1, MT6573E1 and MT6573E2 is 36
   HW_WRITE( BSI_ENA1, 0x0000000F );
   #else
   HW_WRITE( BSI_ENA,  0xFFFFFFFF ); // MT6270A E2, MT6276E2 is 42
   HW_WRITE( BSI_ENA1, 0x000003FF );
   #endif
#elif IS_CHIP_MT6268T || IS_CHIP_MT6268
   HW_WRITE( BSI_ENA,  0x000FFFFF );
#elif IS_CHIP_MT6252
   HW_WRITE( BSI_ENA,  0xFFFF );
   HW_WRITE( BSI_ENA1, 0x001F );
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   HW_WRITE( BSI_ENA,  0xFFFF );
   HW_WRITE( BSI_ENA1, 0x000F );
#else
   HW_WRITE( BSI_ENA,  0xFFFF );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void IMM_MODE_BEGIN( unsigned short imm_mask )
{
#if IS_SMARTPHONE_CHIP_TK6516_AND_LATTER_VERSION
/*MT6516*/   unsigned short pdn_con2 = 0x0000;
/*MT6516*/
/*MT6516*/   if( imm_mask&IMMMASK_AFC )
/*MT6516*/   {  IMM_MODE_AFC_BEGIN();
/*MT6516*/      pdn_con2 |= 0x0020;         /* power on AFC  */
/*MT6516*/   #if IS_CHIP_MT6516
/*MT6516*/      HW_WRITE( PDN_CLR2, pdn_con2 );
/*MT6516*/      HW_WRITE( PDN_CLR4, pdn_con2 );
/*MT6516*/      pdn_con2  = 0x0000;
/*MT6516*/   #endif
/*MT6516*/   }
/*MT6516*/
/*MT6516*/   if( imm_mask&IMMMASK_BPI )
/*MT6516*/   {  IMM_MODE_BPI_BEGIN();
/*MT6516*/      pdn_con2 |= 0x0010;         /* power on BPI  */
/*MT6516*/   }
/*MT6516*/
/*MT6516*/   if( imm_mask&IMMMASK_BSI )
/*MT6516*/   {  IMM_MODE_BSI_BEGIN();
/*MT6516*/      pdn_con2 |= 0x0008;         /* power on BSI  */
/*MT6516*/   }
/*MT6516*/
/*MT6516*/   #if IS_CHIP_MT6516
/*MT6516*/   HW_WRITE( MD2G_PDN_CLR2, pdn_con2 );
/*MT6516*/   HW_WRITE( MD2G_PDN_CLR4, pdn_con2 );
/*MT6516*/   #else
/*MT6516*/   HW_WRITE( PDN_CLR2, pdn_con2 );
/*MT6516*/   HW_WRITE( PDN_CLR4, pdn_con2 );
/*MT6516*/   #endif
/*MT6516*/
#elif IS_CHIP_MT6573 || IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
/*MT6573*/   unsigned short pdn_con2 = 0x0000;
/*MT6573*/
/*MT6573*/   if( imm_mask&IMMMASK_AFC )
/*MT6573*/   {  IMM_MODE_AFC_BEGIN();
/*MT6573*/   #if IS_AST_B2S_SUPPORT
/*MT6573*/      // do nothing
/*MT6573*/   #else
/*MT6573*/      pdn_con2 |= PDN_CON_AFC;    /* power on AFC  */
/*MT6573*/   #endif
/*MT6573*/   }
/*MT6573*/
/*MT6573*/   if( imm_mask&IMMMASK_BPI )
/*MT6573*/   {  IMM_MODE_BPI_BEGIN();
/*MT6573*/      pdn_con2 |= PDN_CON_BPI;    /* power on BPI  */
/*MT6573*/   }
/*MT6573*/
/*MT6573*/   if( imm_mask&IMMMASK_BSI )
/*MT6573*/   {  IMM_MODE_BSI_BEGIN();
/*MT6573*/      pdn_con2 |= PDN_CON_BSI;    /* power on BSI  */
/*MT6573*/   }
/*MT6573*/
/*MT6573*/   HW_WRITE( PDN_CLR2, pdn_con2 );
/*MT6573*/   HW_WRITE( PDN_CLR4, pdn_con2 );
/*MT6573*/
#elif IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
/*MT6238~*/   unsigned short pdn_con2 = 0x0000;
/*MT6238~*/
/*MT6238~*/   if( imm_mask&IMMMASK_AFC )
/*MT6238~*/   {  IMM_MODE_AFC_BEGIN();
/*MT6238~*/   #if IS_AST_B2S_SUPPORT
/*MT6238~*/      // do nothing
/*MT6238~*/   #elif IS_AFC_EVENT_ENABLE
/*MT6238~*/      pdn_con2 |= 0x0010;         /* power on AFC  */
/*MT6238~*/      #if IS_CHIP_MT6236
/*MT6238~*/      HW_WRITE( PDN_CLR2, pdn_con2 );
/*MT6238~*/      HW_WRITE( PDN_CLR4, pdn_con2 );
/*MT6238~*/      pdn_con2  = 0x0000;
/*MT6238~*/      #endif
/*MT6238~*/   #else
/*MT6238~*/      // do nothing
/*MT6238~*/   #endif
/*MT6238~*/   }
/*MT6238~*/
/*MT6238~*/   if( imm_mask&IMMMASK_BPI )
/*MT6238~*/   {  IMM_MODE_BPI_BEGIN();
/*MT6238~*/      pdn_con2 |= 0x0008;         /* power on BPI  */
/*MT6238~*/   }
/*MT6238~*/
/*MT6238~*/   if( imm_mask&IMMMASK_BSI )
/*MT6238~*/   {  IMM_MODE_BSI_BEGIN();
/*MT6238~*/      pdn_con2 |= 0x0004;         /* power on BSI  */
/*MT6238~*/   }
/*MT6238~*/
/*MT6238~*/   #if IS_CHIP_MT6236 || IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
/*MT6238~*/   HW_WRITE( MD2G_PDN_CLR2, pdn_con2 );
/*MT6238~*/   HW_WRITE( MD2G_PDN_CLR4, pdn_con2 );
/*MT6238~*/   #else
/*MT6238~*/   HW_WRITE( PDN_CLR2, pdn_con2 );
/*MT6238~*/   HW_WRITE( PDN_CLR4, pdn_con2 );
/*MT6238~*/   #endif
/*MT6238~*/
#else
/*else*/   unsigned short pdn_con2 = HW_READ( PDN_CON2 );
/*else*/
/*else*/   if( imm_mask&IMMMASK_AFC )
/*else*/   {  IMM_MODE_AFC_BEGIN();
/*else*/      pdn_con2 &= ~0x0010;      /* power on AFC  */
/*else*/   }
/*else*/
/*else*/   if( imm_mask&IMMMASK_BPI )
/*else*/   {  IMM_MODE_BPI_BEGIN();
/*else*/      pdn_con2 &= ~0x0008;      /* power on BPI  */
/*else*/   }
/*else*/
/*else*/   if( imm_mask&IMMMASK_BSI )
/*else*/   {  IMM_MODE_BSI_BEGIN();
/*else*/      pdn_con2 &= ~0x0004;      /* power on BSI  */
/*else*/   }
/*else*/
/*else*//* pdn_con2 &= ~0x0001;  */     /* power on TDMA */
/*else*/   HW_WRITE( PDN_CON2, pdn_con2 );
/*else*/   #if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*else*//*MT6218*/   HW_WRITE( PDN_CON4, pdn_con2 );
/*else*/   #endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void IMM_MODE_END( void )
{
   IMM_MODE_BSI_END();
   IMM_MODE_BPI_END();
   IMM_MODE_AFC_END();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void IMM_SEND_BPI( unsigned short data )
{
#ifndef  L1_SIM
   #if IS_CHIP_MT6205
      #if IS_RF_AERO || IS_RF_AERO1PLUS || IS_RF_AERO2
/* under construction !*/
   /*MT6205*//*AERO*/ #ifndef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6205*//*AERO*/ #else /*__CUST_NEW__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6205*//*AERO*/ #endif /*__CUST_NEW__*/
      #endif
   #endif
#endif

#if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218*/  HW_WRITE( BPI_DATIMM, data );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void IMM_SEND_BSI( unsigned short ctrl, unsigned long data )
{
   volatile long  addr;

   HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN );
   addr = (long)BSI_Dn_CON(0);
   HW_WRITE( (APBADDR)addr, ctrl );  addr += 4;
   HW_WRITE_BSI_DATA( addr, data );
   HW_DUMMY_READ_BSI_DATA( addr );

#if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
   HW_WRITE( GSM_BSI_ACTUPT, 0x8000 );
   HW_DUMMY_READ_BSI_DATA( addr );
#endif
   HW_WRITE( BSI_CON, SCTRL_IMOD_SEND );
   WAIT_TIME_QB( IMM_BSI_WAIT_TIME_QB );
   while( IS_BSI_IMM_SEND_COMPLETE==0x0 );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void IMM_UPDATE_BSI_BEGIN( void )
{
#if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
   // no need to do this
#else
   HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void IMM_UPDATE_BSI_END( void )
{
#if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
   HW_WRITE( GSM_BSI_ACTUPT, BSI_ACTUPT_ALL ); /* Update all active buffer */
#else
   HW_WRITE( BSI_CON, SCTRL_MAIN );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static const sARFCN_SECTION* WeightARFCN_BinarySearch( int arfcn, int rf_band, const sARFCN_SECTION *weight, short mod_type )
{
   signed short left_arfcn_idx, mid_arfcn_idx, right_arfcn_idx;

   left_arfcn_idx = 0;
   right_arfcn_idx = (mod_type == 0)? weight_section_end_idx[rf_band] : weight_section_end_idx_EPSK[rf_band];

   if(weight_section_end_idx[rf_band]<0)  // no entry, not found
   {  return 0;  }
   else
   {
      while( left_arfcn_idx < right_arfcn_idx )
      {
         mid_arfcn_idx = (left_arfcn_idx + (right_arfcn_idx)) >> 1;
         if(arfcn <= weight[mid_arfcn_idx].max_arfcn)
         {  right_arfcn_idx = mid_arfcn_idx;  }
         else
         {  left_arfcn_idx = mid_arfcn_idx+1;  }  // left+1 so that the next region can be covered with mid=(left+right)>>1
      }
      return &weight[right_arfcn_idx];
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int L1D_FH_Is_MPLL_Free_Run_On( void )
{
   return IS_MPLLFH_FREE_RUN_ON;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
   #if IS_EPSK_TX_SUPPORT && IS_EPSK_TX_GAIN_CONTROL_SUPPORT
static short L1D_RF_TXPC_OL_RecordAndUpdateGain( const short dac_ori, unsigned char rf_band, short slot )
{
   const sTXPC_SETUP   *p_setup = &l1d_rf.txpc.setup;
   const short          temp_now = l1d_rf.txpc.ol_db.temperature;
         short          left_2_right_dac = p_setup->power_dac_right - p_setup->power_dac_left;
         short          ratio = 0;
         short          temp_diff_2dB = (rf_band < FrequencyBand1800) ? (txpc_epsk_tp_slope_lb<<1) : (txpc_epsk_tp_slope_hb<<1);

   if( (l1d_rf.txpc_type == TXPC_NO_CONTROL_TYPE   ) ||
       (l1d_rf.txpc_type == TXPC_AUXADC_CLOSED_TYPE) ||
       (l1d_rf.txpc_type == TXPC_BSI_CLOSED_TYPE   ) ||
       (l1d_rf.txpc_mode != TXPC_NORMAL_MODE       ) )
      return dac_ori;

   if( temp_diff_2dB == 0 ) /* txpc_epsk_tp_slope_lb/hb abnormal. Directly return default TX gain DAC */
   {
      l1d_rf.txpc_trc.ratio = 0;
      return dac_ori;
   }

   /* If no power control, output EPSK power is lower than original at high temperature, and higher at low temperature. */
   ratio = (((temp_now - ref_temperature)<<TXPC_DB_RES) + (temp_diff_2dB>>1)) / temp_diff_2dB;

   l1d_rf.txpc_trc.ratio = ratio;

      #if IS_RF_MT6162
   (void)left_2_right_dac;
   return L1D_RF_TXPC_COMPUTE_DAC_EPSK( dac_ori, slot, ratio, 0                );
      #else
   return L1D_RF_TXPC_COMPUTE_DAC_EPSK( dac_ori, slot, ratio, left_2_right_dac );
      #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
   #endif
#endif /* IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT */

#if IS_TX_POWER_CONTROL_SUPPORT
   #if IS_CHIP_MT6256
unsigned long cw138_readback;
   #endif
short L1D_RF_TXPC_GetTxGainSetting( unsigned char is_gain_rf, unsigned char slot_idx )
{
   #if IS_RF_MT6162 || (IS_RF_MT6256RF && IS_EPSK_TX_SUPPORT)
   unsigned short gain         = l1d_rf2.tx_gain_setting[slot_idx];
            short return_value = 0;

      #if IS_RF_MT6162
   return_value = is_gain_rf ? ((gain>>10)&0xF) : (gain&0x3FF);
      #elif IS_RF_MT6256RF && IS_EPSK_TX_SUPPORT
   if( is_gain_rf )
   {  return_value = l1d_rf2.is_alt_bb_gain ? (gain>>2)-1 : (gain>>2);     }
   else
   {  return_value = l1d_rf2.is_alt_bb_gain ? (gain&0x3)+4 : (gain&0x3);   }
      #endif

   return return_value;
   #else
   (void)is_gain_rf;
   (void)slot_idx;
   return 0;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

short L1D_RF_TXPC_GetTemperatureInfo( unsigned char info_idx )
{
   sTXPC_TEMP_INFO *p_temp_info = &l1d_rf.txpc.temp_info;

   if( info_idx==0 )
   {  return p_temp_info->adc;    }
   else if( info_idx==1 )
   {  return p_temp_info->idx;    }
   else
   {  return p_temp_info->value;  }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_Get_Temp_ADC( sTEMPERATURE_ADC_L1CAL *buff )
{  /* For NVRAM to get L1 Default values for 1st boot-up */
   int i;

   for( i=0; i<8; i++ )
   {  buff->data[i] = TXTEMP_Data[0]->data[i];  }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_Set_Temp_ADC( sTEMPERATURE_ADC_L1CAL *temp_adc )
{  /* For L1D to get NVRAM calibration data at boot-up */
   int i;

   for( i=0; i<8; i++ )
   {  TXTEMP_Data[0]->data[i] = temp_adc->data[i];  }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

short L1D_RF_TXPC_CheckTransitionMode( void )
{
   short return_mode = 0;
   if( (l1d_rf.txpc_mode==TXPC_TRANS_TO_META_MODE) || (l1d_rf.txpc_mode==TXPC_TRANS_TO_NORMAL_MODE) )
   {  return_mode = 1;  }
   return return_mode;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned char L1D_RF_TXPC_IS_CAL( void )
{
   return is_calibrated_backup;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

   #if IS_CHIP_MT6256
unsigned short L1D_RF_TXPC_GetTemperatureInfoFromBSI( void )
{
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x8A, 0x81170) ); /* CW138, D[17]=0b                                           */
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x02, 0x54000) ); /* CW2, TRX[1:0]=10b(TX mode), MODE[2:0]=010b(stand-by mode) */
   WAIT_TIME_QB( QB_ST0 - QB_ST1 );                         /* wait for the timing between ST0 and ST1                   */
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, 0xC0000) ); /* CW1, warm-up mode                                         */
   WAIT_TIME_QB( 350 );
   IMM_RECEIVE_BSI( 0, 0x8A, 0, &(cw138_readback) );        /* read back the temperature information                     */
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x02, 0x10000) );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x8A, 0xA1170) ); /* CW138, D[17]=1b                                           */
   IMM_MODE_END( );

   return (unsigned short) (cw138_readback&0xFFF);
}
   #endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
static short L1D_RF_TXPC_CL_RecordAndUpdateDAC( const short dac_ori, unsigned char rf_band, short arfcn, short slot, char is_EPSK )
{
   const sTXPC_ADCDATA    *p_adc;
   const sTXPC_CL_DB_DATA *p_db_data = &l1d_rf.txpc.cl_db.data[0];
         sTXPC_SETUP      *p_setup   = &l1d_rf.txpc.setup;
         unsigned short    adc_left, adc_right, db_idx;
         short             left_2_target_dac, left_2_right_dac, ratio;

   if( (l1d_rf.txpc_type == TXPC_NO_CONTROL_TYPE ) ||
       (l1d_rf.txpc_type == TXPC_AUXADC_OPEN_TYPE) ||
       (l1d_rf.txpc_type == TXPC_BSI_OPEN_TYPE   ) ||
       (l1d_rf.txpc_mode != TXPC_NORMAL_MODE     ) )
      return dac_ori;

   /* --------- Record TX setup --------- */
   #if IS_EPSK_TX_SUPPORT
   if( is_EPSK == 1 )  /* this slot is epsk */
   {  p_adc = TXADC_Data_EPSK[(int)rf_band];
   }
   else           /* this slot is gmsk */
   #endif
   {  p_adc = TXADC_Data[(int)rf_band];
   }

   #if IS_RF_MT6162
   if( is_EPSK )
   {  adc_right = p_adc->data[p_setup->power_idx_right];
      adc_left  = adc_right - TXPC_RF_ADC_SLOPE*2;
      p_setup->adc_interval[slot] = adc_right - adc_left;
      p_setup->target_adc[slot] = adc_right - p_setup->power_dac_target * (TXPC_RF_ADC_SLOPE>>3);
      left_2_right_dac = 0;
   }
   else
   #endif
   {  /* Do not apply TXPC to GMSK because of OH HW issues during GMSK power read-back */
      /* set adc_interval to 1 to avoid divide-by-zero problem */
      if( L1D_RF_TXPC_CL_Check_OHGMSK()==1 )
      {
         p_setup->adc_interval[slot] = 1;
         return dac_ori;
      }
      else
      {
         adc_right = p_adc->data[p_setup->power_idx_right  ];
         adc_left  = p_adc->data[p_setup->power_idx_right-1];

         /* Compensate adc left/right here if considering sub-band weight & bat/temp weight */

         if( adc_left == adc_right )
         {  p_setup->adc_interval[slot] = 1; } /* Avoid divide-by-zero problem */
         else
         {  p_setup->adc_interval[slot] = adc_right - adc_left;   }

         left_2_target_dac = p_setup->power_dac_target - p_setup->power_dac_left;
         left_2_right_dac  = p_setup->power_dac_right  - p_setup->power_dac_left;

         if( left_2_right_dac == 0 )
         {
            /* According to computation results from L1D_RF_TXPC_RecordParam(),
               this only happens when all TX PCL abnormally have identical DACs.
               Return dac_ori to avoid divide-by-zero & strange output power. */
            p_setup->target_adc[slot] = (short)adc_left;
            return dac_ori;
         }

         p_setup->target_adc[slot] = (short)(adc_left + p_setup->adc_interval[slot] * left_2_target_dac / left_2_right_dac);
      }
   }
   /* --------- Compute New DAC --------- */

   for( db_idx = 0; db_idx < TXPC_DB_NUM; db_idx++, p_db_data++ )
   {  if( p_db_data->arfcn == arfcn )
         break;
   }

   if( db_idx != TXPC_DB_NUM )
   {  /* DB has previous compensation record on this ARFCN */

   #if IS_EPSK_TX_SUPPORT
      if( is_EPSK == 1 )
      {  /* EPSK */
         ratio = p_db_data->dac_offset_ratio_E[slot];
         return L1D_RF_TXPC_COMPUTE_DAC_EPSK( dac_ori, slot, ratio, left_2_right_dac );
      }
      else
   #endif
      {  /* GMSK */
         ratio = p_db_data->dac_offset_ratio_G[slot];
         return L1D_RF_TXPC_ComputeVAPC_DAC( dac_ori, ratio, left_2_right_dac );
      }
      /* To avoid incorrect power compensation due to target TX power change */
      // ratio = (p_setup->target_adc[slot] == l1d_rf.txpc.cl_compute.target_adc[slot])? ratio : (ratio>>1);
   }
   else
   {  return dac_ori;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_GetAllADC( sTXPC_L1CAL *buff, char is_EPSK )
{  /* For NVRAM to get L1 Default values for 1st boot-up (detector target value by PCL) */
   const signed char *p_src;
         signed char *p_dst;
   int i, n;

   for( i = 0; i < FrequencyBandCount; i++ )
   {
   #if IS_EPSK_TX_SUPPORT
      if( is_EPSK == 1 )
      {  p_src = (signed char*)TXADC_Data_EPSK[i];
      }
      else
   #endif
      {  p_src = (signed char*)TXADC_Data[i];
         (void)is_EPSK;
      }

      if( p_src != 0 )
      {  p_dst = (signed char*)(&buff->adc[i]);

         for( n = sizeof(sTXPC_ADCDATA); n > 0; n-- )
         {  *p_dst++ = *p_src++;
         }
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_GetAllTEMP( sTXPC_L1CAL *buff, char is_EPSK )
{  /* For NVRAM to get L1 Default values for 1st boot-up (detector temperature compensation value) */
   const signed char *p_src;
         signed char *p_dst;
   int i, n;

   /* start from Band850 */
   for( i = 1; i < FrequencyBandCount; i++ )
   {
   #if IS_EPSK_TX_SUPPORT
      if( is_EPSK == 1 )
      {  p_src = (signed char*)TXTEMP_Data_EPSK[i];
      }
      else
   #endif
      {  p_src = (signed char*)TXTEMP_Data[i];
         (void)is_EPSK;
      }

      if( p_src != 0 )
      {  p_dst = (signed char*)(&buff->temp[i]);

         for( n = sizeof(sTXPC_TEMPDATA); n > 0; n-- )
         {  *p_dst++ = *p_src++;
         }
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void  L1D_RF_TXPC_CL_GetSubband( int rf_band, unsigned short *buff, char is_EPSK )
{  /* For NVRAM to get L1 Default values for 1st boot-up (detector sub-band compensation value) */
   const sRAMPDATA      *band;
   int n;

   #if IS_EPSK_TX_SUPPORT
   if( is_EPSK == 1 )
   {  band = RampData_EPSK[rf_band];
   }
   else
   #endif
   {  band = RampData[rf_band];
      (void)is_EPSK;
   }

   if( band != 0 )
   {
      for( n = 0; n < ARFCN_SECTION_NUM-1; n++ )
      {  *buff++ = band->arfcn_weight[n].hi_weight;  }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_SetAllCalADC( sTXPC_L1CAL *calibrated, char is_EPSK )
{  /* For L1D to get NVRAM calibration data at boot-up (detector target value by PCL) */
   const signed char *p_src;
         signed char *p_dst;
   int i, n;

   for( i = 0; i < FrequencyBandCount; i++ )
   {
   #if IS_EPSK_TX_SUPPORT
      if( is_EPSK == 1 )
      {  p_dst = (signed char*)TXADC_Data_EPSK[i];
      }
      else
   #endif
      {  p_dst = (signed char*)TXADC_Data[i];
         (void)is_EPSK;
      }

      if( p_dst != 0 )
      {  p_src = (signed char*)(&calibrated->adc[i]);

         for( n = sizeof(sTXPC_ADCDATA); n > 0; n-- )
         {  *p_dst++ = *p_src++;
         }
      }
   }
   /* back up data for TXPC in META */
   is_calibrated_backup = calibrated->is_calibrated;
   L1D_RF_TXPC_CL_BackupAllCalADC();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned short L1D_RF_TXPC_CL_GetOneADC( int rf_band, int power_in_dBm, char is_EPSK )
{
   int idx = (power_in_dBm - LOWEST_TX_POWER[rf_band])/2;

   #if IS_EPSK_TX_SUPPORT
   if( is_EPSK == 1 )
   {  return TXADC_Data_EPSK[rf_band]->data[idx];  }
   else
   #endif
   {  return TXADC_Data[rf_band]->data[idx];       }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_SetAllCalTEMP( sTXPC_L1CAL *calibrated, char is_EPSK )
{  /* For L1D to get NVRAM calibration data at boot-up (detector temperature compensation value) */
   const signed char *p_src;
         signed char *p_dst;
   int i, n;

   /* start from Band850 */
   for( i = 1; i < FrequencyBandCount; i++ )
   {
   #if IS_EPSK_TX_SUPPORT
      if( is_EPSK == 1 )
      {  p_dst = (signed char*)TXTEMP_Data_EPSK[i];
      }
      else
   #endif
      {  p_dst = (signed char*)TXTEMP_Data[i];
         (void)is_EPSK;
      }

      if( p_dst != 0 )
      {  p_src = (signed char*)(&calibrated->temp[i]);

         for( n = sizeof(sTXPC_TEMPDATA); n > 0; n-- )
         {  *p_dst++ = *p_src++;
         }
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned char L1D_RF_TXPC_CL_Check_OHGMSK( void )
{
   unsigned char return_value = 0;
   #if IS_RF_MT6162
   /* if the GMSK detector does not work, return 1; otherwise, return 0 */
//   if( L1D_RF_Get6162Version() == 1 )
   {  return_value = 1;  }
   #endif
   return return_value;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_Update_TXADC_Subband_Data( unsigned short read_back_data, short arfcn, char rf_band, unsigned char mod_type )
{
   sRAMPDATA *band;
   signed short left_arfcn_idx, mid_arfcn_idx, right_arfcn_idx;

   left_arfcn_idx = 0;
   right_arfcn_idx = (mod_type == 0) ? weight_section_end_idx[rf_band] : weight_section_end_idx_EPSK[rf_band];

   #if IS_EPSK_TX_SUPPORT
   if( mod_type )
   {  band = RampData_EPSK[rf_band];  }
   else
   #endif
   {
      if( L1D_RF_TXPC_CL_Check_OHGMSK()==1 )
      {  return;  }
      else
      {  band = RampData[rf_band];  }
   }

   if(weight_section_end_idx[rf_band]<0)  // no entry, not found
   {  return;  }
   else
   {
      while( left_arfcn_idx < right_arfcn_idx )
      {
         mid_arfcn_idx = (left_arfcn_idx + (right_arfcn_idx)) >> 1;
         if(arfcn <= band->arfcn_weight[mid_arfcn_idx].max_arfcn)
         {  right_arfcn_idx = mid_arfcn_idx;  }
         else
         {  left_arfcn_idx = mid_arfcn_idx+1;  }  // left+1 so that the next region can be covered with mid=(left+right)>>1
      }
      band->arfcn_weight[right_arfcn_idx].hi_weight = read_back_data;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned short L1D_RF_TXPC_CL_GetDetReadBack( unsigned char is_compensated, unsigned short slot_idx )
{
   short return_value = 0;
   #if IS_RF_MT6162
   return_value = (is_compensated) ? (l1d_rf2.compensated_read_back[slot_idx]) : (l1d_rf2.real_read_back[slot_idx]);
   #endif
   return return_value;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

short L1D_TXPC_CL_Detector_Subband_Compensation( unsigned char mod_type )
{
   short detector_compensation = 0;
   unsigned short   n;
   const sRAMPDATA *band;
   static const sARFCN_SECTION   *weight;   /* Must be static since chips before M6229 will only query if IS_1ST_TX_SLOT */
          const sTXPC_CL_COMPUTE *p_compute = &l1d_rf.txpc.cl_compute;

   /* Should enter this function ONLY when l1d_rf.txpc_mode == TXPC_NORMAL_MODE */

   if( (l1d_rf.txpc_type == TXPC_BSI_CLOSED_TYPE   ) ||
       (l1d_rf.txpc_type == TXPC_AUXADC_CLOSED_TYPE) ) /* detector sub-band compensation */
   {
   #if IS_EPSK_TX_SUPPORT
      if( mod_type )
      {
         band = RampData_EPSK[(int)p_compute->rf_band];
         weight = WeightARFCN_BinarySearch( (p_compute->arfcn&0x3FF), p_compute->rf_band , band->arfcn_weight, 1 );
      }
      else
   #endif
      {
         (void)mod_type;
         if( L1D_RF_TXPC_CL_Check_OHGMSK()==1 )
         {  weight = 0;  }
         else
         {
            band = RampData[(int)p_compute->rf_band];
            weight = WeightARFCN_BinarySearch( (p_compute->arfcn&0x3FF), p_compute->rf_band , band->arfcn_weight, 0 );
         }
      }

      if( weight )
      {
         n = weight->hi_weight;
         detector_compensation = (signed short) (n-(1<<TXPC_CL_DET_RES));
      }
      else /* no entry, not found */
      {  detector_compensation = 0;  }
   }
   l1d_rf.txpc_trc.subband_compensation = detector_compensation;

   return detector_compensation;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

short L1D_TXPC_CL_Detector_Temperature_Compensation( unsigned char mod_type )
{
   short detector_compensation = 0;
   short temp_idx = l1d_rf.txpc.temp_info.idx;
   static const sTXPC_TEMPDATA   *p_temp;
          const sTXPC_CL_COMPUTE *p_compute = &l1d_rf.txpc.cl_compute;

   /* Should enter this function ONLY when l1d_rf.txpc_mode == TXPC_NORMAL_MODE */

   if( (l1d_rf.txpc_type == TXPC_BSI_CLOSED_TYPE   ) ||
       (l1d_rf.txpc_type == TXPC_AUXADC_CLOSED_TYPE) ) /* detector temperature compensation */
   {
   #if IS_EPSK_TX_SUPPORT
      if( mod_type )
      {  p_temp = TXTEMP_Data_EPSK[(int)p_compute->rf_band];   }
      else
   #endif
      {
         (void)mod_type;
         if( L1D_RF_TXPC_CL_Check_OHGMSK()==1 )
         {  p_temp = 0;                                     }
         else
         {  p_temp = TXTEMP_Data[(int)p_compute->rf_band];  }
      }

      if( p_temp ) /* p_temp->data[l1d_rf.txpc.temp_info.idx] : detector value at current temperature */
      {            /* p_temp->data[2]                         : detector value at normal temperature  */
         if( temp_idx == 0 )
            detector_compensation = (signed short)( p_temp->data[0] + (p_temp->data[1]-p_temp->data[0])*(L1D_RF_TXPC_GetTemperatureInfo(2)-TEMP_IDX[0])/(TEMP_IDX[1]-TEMP_IDX[0]) );
         else
            detector_compensation = (signed short)( p_temp->data[temp_idx-1] + (p_temp->data[temp_idx]-p_temp->data[temp_idx-1])*(L1D_RF_TXPC_GetTemperatureInfo(2)-TEMP_IDX[temp_idx-1])/(TEMP_IDX[temp_idx]-TEMP_IDX[temp_idx-1]) );
         detector_compensation -= p_temp->data[2];
         /*********************************************************************************************
          detector_compensation - p_temp->data[temp_idx-1]   current_temperature - TEMP_IDX[temp_idx-1]
         ------------------------------------------------- = ------------------------------------------
         p_temp->data[temp_idx] - p_temp->data[temp_idx-1]    TEMP_IDX[temp_idx] - TEMP_IDX[temp_idx-1]
         *********************************************************************************************/
      }
      else /* no entry, not found */
      {
         detector_compensation = 0;
      }
   }
   l1d_rf.txpc_trc.temperature_compensation = detector_compensation;

   return detector_compensation;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_Read_RF_Power( long *sample_array, unsigned char tx_slot, unsigned char mod_type )
{
   #if IS_RF_MT6162
   signed short i;
   signed short n = 0;
   unsigned char is_epsk = 0;


   for( i=0; i<TXPC_SLOT_MAX; i++ )
   {
      if( ((tx_slot>>i)&0x1) )
      {
         is_epsk = (mod_type>>i) & 0x1;
         L1D_RF_GetImmediateBSI( TX_GAIN_READ_ADDRESS[n], &read_back );
         l1d_rf2.real_read_back[i] = (unsigned short)(read_back&0xFFF);
         if( l1d_rf.txpc_mode == TXPC_NORMAL_MODE )
         {  /* we need to compensate the detector read-back value ONLY in the normal mode */
            read_back -= ( L1D_TXPC_CL_Detector_Subband_Compensation( is_epsk ) +
                           L1D_TXPC_CL_Detector_Temperature_Compensation( is_epsk ) );
         }
         l1d_rf2.compensated_read_back[i] = (unsigned short)(read_back&0xFFF);
         sample_array[i] = (long)((read_back&0xFFF)<<TXPC_RD_ADC_RES); /* gain_rf(dB) = (gainrf_read(DAC)-2560)/32 */
         n++;
      }
   }
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_BackUpSubband( int rf_band, char is_EPSK )
{
   sRAMPDATA *band;
   int n;

   if( (l1d_rf.txpc_type==TXPC_AUXADC_CLOSED_TYPE) || (l1d_rf.txpc_type==TXPC_BSI_CLOSED_TYPE) )
   {  /* back up the subband data in the TXPC closed type only */
   #if IS_EPSK_TX_SUPPORT
      if( is_EPSK == 1 )
      {  band = RampData_EPSK[rf_band];  }
      else
   #endif
      {
         if( L1D_RF_TXPC_CL_Check_OHGMSK() == 1 )
         {  return;  }
         else
         {
            band = RampData[rf_band];
            (void)is_EPSK;
         }
      }
      if( band != 0 )
      {
         for( n = 0; n < ARFCN_SECTION_NUM-1; n++ )
         {  band->arfcn_weight[n].low_weight = band->arfcn_weight[n].hi_weight;  }
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_RestoreSubband( void )
{
   sRAMPDATA *band;
   int n, rf_band;

   if( (l1d_rf.txpc_type==TXPC_AUXADC_CLOSED_TYPE) || (l1d_rf.txpc_type==TXPC_BSI_CLOSED_TYPE) )
   {  /* restore the subband data in the TXPC closed type only */
      for( rf_band = 1; rf_band < FrequencyBandCount; rf_band++ )
      {
         if( L1D_RF_TXPC_CL_Check_OHGMSK() == 0 )
         {
            band = RampData[rf_band];
            for( n = 0; n < ARFCN_SECTION_NUM-1; n++ )
            {  band->arfcn_weight[n].hi_weight = band->arfcn_weight[n].low_weight;  }
         }
   #if IS_EPSK_TX_SUPPORT
         band = RampData_EPSK[rf_band];
         for( n = 0; n < ARFCN_SECTION_NUM-1; n++ )
         {  band->arfcn_weight[n].hi_weight = band->arfcn_weight[n].low_weight;  }
   #endif
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_BackupAllCalADC( void )
{
   int i, j;

   if( (l1d_rf.txpc_type==TXPC_AUXADC_CLOSED_TYPE) || (l1d_rf.txpc_type==TXPC_BSI_CLOSED_TYPE) )
   {  /* back up the ADC data in the TXPC closed type only */
      for( i = 1; i < FrequencyBandCount; i++ )
      {
         for( j = 0; j < 16; j++ )
         {
            TXADC_Data_LSB_Backup[i-1][j] = (unsigned char) (TXADC_Data[i]->data[j] & 0xFF);
            if( (j&0x1) == 0 )
            {  TXADC_Data_MSB_Backup[i-1][j/2] = (unsigned char) ( ((TXADC_Data[i]->data[j+1]&0xF00)>>4) | ((TXADC_Data[i]->data[j]&0xF00)>>8) );  }
         }
   #if IS_EPSK_TX_SUPPORT
         for( j = 0; j < 16; j++ )
         {
            TXADC_Data_LSB_Backup_EPSK[i-1][j] = (unsigned char) (TXADC_Data_EPSK[i]->data[j] & 0xFF);
            if( (j&0x1) == 0 )
            {  TXADC_Data_MSB_Backup_EPSK[i-1][j/2] = (unsigned char) ( ((TXADC_Data_EPSK[i]->data[j+1]&0xF00)>>4) | ((TXADC_Data_EPSK[i]->data[j]&0xF00)>>8) );  }
         }
   #endif
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXPC_CL_RestoreAllCalADC( void )
{
   unsigned char lsb_data, msb_data;
   int i, j;

   if( (l1d_rf.txpc_type==TXPC_AUXADC_CLOSED_TYPE) || (l1d_rf.txpc_type==TXPC_BSI_CLOSED_TYPE) )
   {  /* restore the ADC data in the TXPC closed type only */
      for( i = 1; i < FrequencyBandCount; i++ )
      {
         for( j = 0; j < 16; j++ )
         {
            lsb_data = TXADC_Data_LSB_Backup[i-1][j];
            msb_data = ((j&0x1)==0) ? (TXADC_Data_MSB_Backup[i-1][j/2]&0x0F) : ((TXADC_Data_MSB_Backup[i-1][j/2]&0xF0)>>4);
            TXADC_Data[i]->data[j] = (unsigned short) ((msb_data<<8) | (lsb_data));
         }
   #if IS_EPSK_TX_SUPPORT
         for( j = 0; j < 16; j++ )
         {
            lsb_data = TXADC_Data_LSB_Backup_EPSK[i-1][j];
            msb_data = ((j&0x1)==0) ? (TXADC_Data_MSB_Backup_EPSK[i-1][j/2]&0x0F) : ((TXADC_Data_MSB_Backup_EPSK[i-1][j/2]&0xF0)>>4);
            TXADC_Data_EPSK[i]->data[j] = (unsigned short) ((msb_data<<8) | (lsb_data));
         }
   #endif
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif /* IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT */

#if IS_TX_POWER_CONTROL_SUPPORT
void L1D_RF_TXPC_RecordParam( unsigned char scenario, const sRAMPDATA* band, unsigned short weight, short temp_idx, char is_rollback, short target_dac )
{
   sTXPC_SETUP *p_setup    = &l1d_rf.txpc.setup;
   short        temp_right = (temp_idx == 0)? 1 : temp_idx;

   if( (l1d_rf.txpc_type == TXPC_NO_CONTROL_TYPE)  ||
       (l1d_rf.txpc_mode != TXPC_NORMAL_MODE)      )
       return;

   switch( scenario )
   {
      case 0: /* L1D_RF_GetSData_ST2      */
      case 1: /* L1D_RF_SetTxPowerLevel   */
      {
         p_setup->power_dac_target = target_dac;

         if( is_rollback == 1 )
         {  break; } /* For non-zero rollback_dac, already got idx & left/right dac in L1D_RF_PowerRollback() */

         /* No break for zero-rollback_dac case to set idx & left/right dac */
      }
      case 2: /* L1D_RF_PowerRollback     */
      {
         for( ; temp_right > 1; temp_right-- )
         {  /* In order to get the biggest index such that band->power[index] != band->power[index-1] */
            if( band->power[temp_right] != band->power[temp_right-1] )
               break;
         }

         p_setup->power_idx_right = temp_right;
         p_setup->power_dac_right = (short)((band->power[temp_right  ] * weight)>>14);
         p_setup->power_dac_left  = (short)((band->power[temp_right-1] * weight)>>14);
         break;   /* Will run into case 1 latter to set p_setup->power_dac_target */
      }
   #if IS_RF_MT6162
      case 3: /* EPSK, L1D_RF_PowerRollback */
      {
         p_setup->power_idx_right  = temp_idx;
         p_setup->power_dac_target = target_dac; /* borrow this var. to store roll-back power: n/8 dB */
         break;
      }
   #endif
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

short L1D_RF_TXPC_RecUpdateAPCDAC( const short dac_ori, unsigned char rf_band, short arfcn, short slot, char is_EPSK )
{
   switch( l1d_rf.txpc_type )
   {
   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
      case TXPC_AUXADC_CLOSED_TYPE:
      case TXPC_BSI_CLOSED_TYPE:
      {
      #if IS_EPSK_TX_GAIN_CONTROL_SUPPORT
         if( is_EPSK == 1 )
         {  return dac_ori;   }
         else
         {  return L1D_RF_TXPC_CL_RecordAndUpdateDAC( dac_ori, rf_band, arfcn, slot, is_EPSK ); }
      #else
         return L1D_RF_TXPC_CL_RecordAndUpdateDAC( dac_ori, rf_band, arfcn, slot, is_EPSK );
      #endif
      }
   #endif
      default:
      {  (void)rf_band; (void)arfcn; (void)slot; (void)is_EPSK;
         break;
      }
   }
   return dac_ori;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

short L1D_RF_TXPC_ComputeVAPC_DAC( const short dac_ori, short ratio, short dac_diff )
{  /* dac_diff: approximated APC DAC increment needed for increasing 2 dBm of TX power */
   short dac_offset  = (short)((ratio*dac_diff + TXPC_DB_ROUNDING) >> TXPC_DB_RES);
   short dac_new     = dac_ori + dac_offset;

   if( dac_new > 1023 )
      dac_new = 1023;
   else if( dac_new < 0 )
      dac_new = 0;

   return dac_new;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

   #if IS_EPSK_TX_SUPPORT
      #if IS_EPSK_TX_GAIN_CONTROL_SUPPORT
static short L1D_RF_TXPC_RecUpdateGain( const short dac_ori, unsigned char rf_band, short arfcn, short slot )
{
   switch( l1d_rf.txpc_type )
   {
         #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
      case TXPC_AUXADC_CLOSED_TYPE:
      case TXPC_BSI_CLOSED_TYPE:
      {
         return L1D_RF_TXPC_CL_RecordAndUpdateDAC( dac_ori, rf_band, arfcn, slot, 1 );
      }
         #endif
         #if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
      case TXPC_BSI_OPEN_TYPE:
      case TXPC_AUXADC_OPEN_TYPE:
      {
         return L1D_RF_TXPC_OL_RecordAndUpdateGain( dac_ori, rf_band, slot );
      }
         #endif
      default:
      {  return dac_ori;   }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      #endif   /* IS_EPSK_TX_GAIN_CONTROL_SUPPORT */
      #if IS_RF_MT6256RF
short L1D_RF_TXPC_ComputePGA_GAIN( const short gain_ori, short slot, short ratio, short gain_diff )
{
   static unsigned char last_gain_reverse_rf[TXPC_SLOT_MAX] = { 99, 99, 99, 99 };

   long  gain_offset  = (long)(ratio * gain_diff);
   short gain_new     = gain_ori + (short)((gain_offset + TXPC_DB_ROUNDING) >> TXPC_DB_RES);
   short gain_reverse = 291 - gain_new;    // 291=72*4+3, max. EPSK APC DAC for MT6256
   short delta_bb_gain;

   if( gain_reverse > 291 )
      gain_reverse = 291;
   else if( gain_reverse < 0 )
      gain_reverse = 0;

         #if IS_CHIP_MT6256_S00
   (void)last_gain_reverse_rf[0];
   (void)delta_bb_gain;
   l1d_rf2.is_alt_bb_gain = 0;
         #else
   delta_bb_gain = gain_reverse - (short)(last_gain_reverse_rf[slot] << 2);

   /* Record into l1d_rf2.is_alt_bb_gain whether BB PGA gain 4~7 is used */
   if( delta_bb_gain >= 0 && delta_bb_gain <= TXPC_BB_PGA_GAIN_MAX )
   {  /* Prefer setting RF PGA gain to the same value as in the previous frame */
      l1d_rf2.is_alt_bb_gain = (delta_bb_gain>3) ? 1 : 0;
   }
   else if( (gain_reverse>>2) > 0 )
   {  /* Changing RF PGA gain is inevitable.
         Prefer setting BB PGA gain to 2~5 instead of to 0, 1, 6, or 7
         in order to reduce chances of changing RF PGA gain in the following TXPC tracking */
      l1d_rf2.is_alt_bb_gain = ((gain_reverse&0x3)<2) ? 1 : 0;
   }
   else /* RF PGA gain == 0 */
   {
      l1d_rf2.is_alt_bb_gain = 0;
   }
         #endif

   L1D_Setup_BB_TxPower( gain_reverse, l1d_rf2.is_alt_bb_gain );

   last_gain_reverse_rf[slot] = l1d_rf2.is_alt_bb_gain ? ((gain_reverse>>2)-1) : (gain_reverse>>2);
//   l1d_rf2.tx_gain_setting[slot] = (unsigned short)gain_reverse;  /* For trace output */

   return (291 - gain_reverse);  // return un-reversed gain
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      #elif IS_RF_MT6162
short L1D_RF_TXPC_Compute_OH_PA_GAIN( const short dac_ori, short ratio )
{
   short dac_offset = (short)((ratio*TXPC_RF_PA_GAIN_SLOPE*2 + TXPC_DB_ROUNDING) >> TXPC_DB_RES);

   return (dac_ori + dac_offset);
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      #endif/* IS_RF_MT6256RF */
   #endif   /* IS_EPSK_TX_SUPPORT */
   #if IS_RF_MT6162 || IS_RF_MT6256RF 
void L1D_RF_GetRFTemperatureIdxAndValue( short temp_dac )
{  /* calculate the temperature information */
   short temp_idx, temp_value, i;
   short idx_home, idx_away;
   unsigned short  TEMP_DAC[8];
   sTXPC_TEMP_INFO *p_temp_info = &l1d_rf.txpc.temp_info;

   for( i=0; i<8; i++ )
      #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
/* under construction !*/
      #else
   {  TEMP_DAC[i] = TXTEMP_Data[0]->data[i];  }
      #endif

      #if IS_RF_MT6162
   if(temp_dac>=TEMP_DAC[3])
   {  if(temp_dac>=TEMP_DAC[1])
      {  if(temp_dac>=TEMP_DAC[0])
            temp_idx = 0;
         else
            temp_idx = 1;
      }
      else
      {  if(temp_dac>=TEMP_DAC[2])
            temp_idx = 2;
         else
            temp_idx = 3;
      }
   }
   else
   {  if(temp_dac>=TEMP_DAC[5])
      {  if(temp_dac>=TEMP_DAC[4])
            temp_idx = 4;
         else
            temp_idx = 5;
      }
      else
      {  if(temp_dac>=TEMP_DAC[6])
            temp_idx = 6;
         else
            temp_idx = 7;
      }
   }
      #endif

      #if IS_RF_MT6256RF
   if(temp_dac<=TEMP_DAC[3])
   {  if(temp_dac<=TEMP_DAC[1])
      {  if(temp_dac<=TEMP_DAC[0])
            temp_idx = 0;
         else
            temp_idx = 1;
      }
      else
      {  if(temp_dac<=TEMP_DAC[2])
            temp_idx = 2;
         else
            temp_idx = 3;
      }
   }
   else
   {  if(temp_dac<=TEMP_DAC[5])
      {  if(temp_dac<=TEMP_DAC[4])
            temp_idx = 4;
         else
            temp_idx = 5;
      }
      else
      {  if(temp_dac<=TEMP_DAC[6])
            temp_idx = 6;
         else
            temp_idx = 7;
      }
   }
      #endif

   if( temp_idx==0 )
   {
      idx_away = 0;
      idx_home = 1;
   }
   else if( temp_idx==7 )
   {
      idx_away = 7;
      idx_home = 6;
   }
   else
   {
      idx_away = temp_idx-1;
      idx_home = temp_idx;
   }

   if( TEMP_DAC[idx_away]==TEMP_DAC[idx_home] )
   {
      /* TEMP_DAC[] from NVRAM abnormal. Don't do interpolation to avoid divide-by-zero! */
      if( TEMP_DAC[temp_idx]==TEMP_DAC[TEMP_IDX_DEFAULT] )
      {  temp_idx = TEMP_IDX_DEFAULT;  } /* Set temperature to default 20oC */

      temp_value = TEMP_IDX[temp_idx];
   }
   else
   {  temp_value = TEMP_IDX[temp_idx]+(TEMP_IDX[idx_away]-TEMP_IDX[idx_home])*(temp_dac-TEMP_DAC[temp_idx])/(TEMP_DAC[idx_away]-TEMP_DAC[idx_home]);  }

   /************************************************************************************
             temp_value - TEMP_IDX[temp_idx]               temp_dac - TEMP_DAC[temp_idx]
   ----------------------------------------- = -----------------------------------------
   TEMP_IDX[temp_idx-1] - TEMP_IDX[temp_idx]   TEMP_DAC[temp_idx-1] - TEMP_DAC[temp_idx]
   *************************************************************************************/

   p_temp_info->adc   = temp_dac;
   p_temp_info->idx   = temp_idx;
   p_temp_info->value = temp_value;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
   #endif /* IS_RF_MT6162 || IS_RF_MT6256RF */
#endif      /* IS_TX_POWER_CONTROL_SUPPORT */

/*===============================================================================*/
/* short  L1D_RF_SetTxPowerLevel( int rf_band, int arfcn, short power_dbm )      */
/*===============================================================================*/
/* rf_band   : RF Band. (3:GSM, 4:DCS, 5:PCS)                                    */
/* arfcn     : ARFCN number                                                      */
/* power_dbm : Request TX power level in dBm                                     */
/* mod_type  : 0:GMSK 1:EPSK                                                     */
/* return    : Txpower level in DAC value                                        */
/* ----------------------------------------------------------------------------- */

short L1D_RF_SetTxPowerLevel( int rf_band, int arfcn, short power_dbm, short mod_type )
{  static char  lowest_dbm;
   static const sRAMPDATA*  band;
   static short apc_dcoffset_threshold = 0;
   static short apc_dcoffset_low = 0;
   static short apc_dcoffset_high = 0;
   static short first_apc_dcoffset = 0;
   short cur_apc_dcoffset;
   static const sARFCN_SECTION* weight;  // Must be static since chips before M6229 will only query if IS_1ST_TX_SLOT
   short  power_dac;
   unsigned short n;
#if IS_GPRS
   short  rollback_dac;
#endif

#if IS_FHC_SUPPORT
   if( l1d_rf.fhc_proc==FHC_PROC_UTS_DAC )
   {
      if (IS_1ST_TX_SLOT())
      {
         first_apc_dcoffset = (l1d_rf.fhc_high_apc_dcoffset & 0x3FF);
         l1d_rf.apc_dc_offset = first_apc_dcoffset;
         HW_WRITE( APC_OFFSET, first_apc_dcoffset );
      }
   #if IS_EPSK_TX_GAIN_CONTROL_SUPPORT
      if( mod_type )
      {
//       l1d_rf2.fhc_PGA_gain = (unsigned short)power_dbm;  /* for MT6256 TX PGA gain  */
         power_dac = L1D_RF_GetTxPAVBias();                /* set PA Vbias for MT6256 */
      }
      else
   #endif
      {  power_dac = power_dbm;  }

      if(power_dac > 1023)  /* saturation to 10 bit DAC max. */
      {  power_dac = 1023; }

      return power_dac;
   }
#endif

   if( IS_1ST_TX_SLOT() )
   {
      band = RampData[(int)rf_band];
      lowest_dbm = LOWEST_TX_POWER[(int)rf_band];
      // apply the 1'st burst DC offset for whole frame
      apc_dcoffset_threshold = band->lowest_power&0xFF;
      apc_dcoffset_high = ((band->lowest_power)>>8)&0x3FF;
      apc_dcoffset_low = ((band->lowest_power)>>18)&0x3FF;
      if(power_dbm<apc_dcoffset_threshold)
         first_apc_dcoffset = apc_dcoffset_low;
      else
         first_apc_dcoffset = apc_dcoffset_high;
      l1d_rf.apc_dc_offset = first_apc_dcoffset;
      HW_WRITE( APC_OFFSET, first_apc_dcoffset );

#if !IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
      weight = WeightARFCN_BinarySearch(arfcn, rf_band, band->arfcn_weight, mod_type);
#endif
   } /* to simplify the code, we look-up table each burst depends on its modulation type */

#if IS_EPSK_TX_GAIN_CONTROL_SUPPORT
   if( mod_type )
   {  return L1D_RF_GetTxPAVBias();  }
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_EPSK_TX_SUPPORT
   if( mod_type )
   {  band = RampData_EPSK[(int)rf_band];  }
   else
   #endif
   {  band = RampData[(int)rf_band];       }
   weight = WeightARFCN_BinarySearch(arfcn, rf_band, band->arfcn_weight, mod_type);
#endif

   if( weight )
      n = (power_dbm > weight->mid_level) ? weight->hi_weight : weight->low_weight;
   else // no entry, not found
      n = WEIGHT(1.0);

#if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
   if( (l1d_rf.txpc_type == TXPC_BSI_CLOSED_TYPE)    ||
       (l1d_rf.txpc_type == TXPC_AUXADC_CLOSED_TYPE) )
   {
      if( L1D_RF_TXPC_CL_Check_OHGMSK()==1 )
      {} /* Use original TX power sub-band weighting for compensation */
      else
      {  n = WEIGHT(1.0);  }  /* Do not use weight from WeightARFCN_BinarySearch,
                                 because in TXPC_CL, weight stores "power detector" sub-band compensation */
   }
#endif

   power_dac = (short)((band->power[(power_dbm-lowest_dbm)/2]*n)>>14);  /* power : dBm --> DAC */

#if IS_GPRS
   // power rollback
   rollback_dac = L1D_RF_PowerRollback( power_dbm, rf_band, n, mod_type);
   // end : power rollback
   power_dac -= rollback_dac;
   L1D_RF_TXPC_RECORD_PARAM( 1 /*scenario*/, band, n, (power_dbm - lowest_dbm)/2, (rollback_dac!=0)?1:0, power_dac );
#else
   L1D_RF_TXPC_RECORD_PARAM( 1 /*scenario*/, band, n, (power_dbm - lowest_dbm)/2, 0,                     power_dac );
#endif

   if( !L1D_CheckIfMetaMode() )
#if IS_TX_POWER_CONTROL_SUPPORT && IS_RF_MT6162
   {  power_dac = (short)((power_dac*band->battery_compensate[1][(int)(l1d_rf.txpc.temp_info.idx/3)])>>14); }
#else
   {  power_dac = (short)((power_dac*band->battery_compensate[l1d_rf.bat_volt][l1d_rf.bat_temp])>>14);      }
#endif

   if(power_dbm<apc_dcoffset_threshold)
      cur_apc_dcoffset = apc_dcoffset_low;
   else
      cur_apc_dcoffset = apc_dcoffset_high;

   // compensate the difference of H/L DC offset
   power_dac -= (first_apc_dcoffset-cur_apc_dcoffset);

   if(power_dac > 1023)  /* saturation to 10 bit DAC max. */
   {  power_dac = 1023;  }

   return  power_dac;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_EPSK_TX_SUPPORT
short L1D_RF_SetInterslotPowerLevel( int rf_band, int arfcn, short mod_type )
{
   const sRAMPDATA      *band;
   const sARFCN_SECTION *weight;
   short power_dac, interslot_lowest_dac;
   int   n;

   if( mod_type )
   {  band = RampData_EPSK[(int)rf_band];  }
   else
   {  band = RampData[(int)rf_band];       }
   /* Get ARFCN section */
   weight = WeightARFCN_BinarySearch(arfcn, rf_band, band->arfcn_weight, mod_type);

   if(weight)
      n = weight->low_weight;
   else // no entry, not found
      n = WEIGHT(1.0);

   band = RampData_EPSK[(int)rf_band];
   interslot_lowest_dac = ((band->lowest_power)>>18)&0xFF;

   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
   if( (l1d_rf.txpc_type == TXPC_BSI_CLOSED_TYPE)    ||
       (l1d_rf.txpc_type == TXPC_AUXADC_CLOSED_TYPE) )
   {
      if( L1D_RF_TXPC_CL_Check_OHGMSK()==1 )
      {} /* Use original TX power sub-band weighting for compensation */
      else
      {  n = WEIGHT(1.0);  } /* Do not use weight from WeightARFCN_BinarySearch,
                                because in TXPC_CL, weight stores "power detector" sub-band compensation */
   }
   #endif

   power_dac = (short)((interslot_lowest_dac*n)>>14); /* DAC for gprs_offset */

   if( !L1D_CheckIfMetaMode() )
#if IS_TX_POWER_CONTROL_SUPPORT && IS_RF_MT6162
   {  power_dac = (short)((power_dac*band->battery_compensate[1][(int)(l1d_rf.txpc.temp_info.idx/3)])>>14); }
#else
   {  power_dac = (short)((power_dac*band->battery_compensate[l1d_rf.bat_volt][l1d_rf.bat_temp])>>14);      } //battery compensate
#endif

   if(power_dac > 1023)  /* saturation to 10 bit DAC max. */
   {  power_dac = 1023; }

   return power_dac;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

void  L1D_RF_SetTxPower( short *tx_power )
{
#if IS_EPSK_TX_SUPPORT || IS_RF_MT6162
   int i;

   for( i=0; i<4; i++ )
   {  l1d_rf2.tx_power[i] = (unsigned char)tx_power[i];  }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_RF_CMOSEDGE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/*-----------------------------------------------------------*/
/* To adjust TX_BUF_TS depending on QB_ST2B                  */
/*-----------------------------------------------------------*/
/* qb_st2           is QB_ST2/QB_ST2B timing                 */
/* (timing_bound-1) is the max valid value of QB_ST2/QB_ST2B */
/*-----------------------------------------------------------*/
unsigned long L1D_RF_SetTX_BSI_CW( short qb_st2, short timing_bound )
{
#if IS_SET_TX_BSI_CW_NEEDED
   unsigned long bsi_cw;
   char i = 0;

   while( qb_st2 < (timing_bound - i * QB_TX_BUF_TS_STEP) )
   {  i++;
   }

   #if IS_CHIP_MT6261
   bsi_cw = BSI_CW( 0x80, (POR_CW128&0xFFFF0)|((16-i)&0xF) );  //CW128 for MT6261
   #elif IS_CHIP_MT6260
   bsi_cw = BSI_CW( 0x80, (POR_CW128&0xFFFF0)|((16-i)&0xF) );  //CW128 for MT6260
   #elif IS_CHIP_MT6250
   bsi_cw = BSI_CW( 0x80, (POR_CW128&0xFFFF0)|((16-i)&0xF) );  //CW128 for MT6250
   #elif IS_CHIP_MT6256_S00
   bsi_cw = BSI_CW( 0x88, 0x00100|(l1d_rf2.r_cal & 0xF)|(((0xF-i)&0xF)<<11) );  //CW136 for MT6256
   #elif IS_CHIP_MT6256
   bsi_cw = BSI_CW( 0x88, 0x00000|(((0xF-i)&0xF)<<11) );  //CW136 for MT6256
   #elif IS_CHIP_MT6255
   bsi_cw = BSI_CW( 0x84, 0x00FE0|(((0xF-i)&0xF)<<1)  );  //CW132 for MT6255
   #elif IS_CHIP_MT6251
   bsi_cw = BSI_CW( 0x84, 0x06FE0|(((0xF-i)&0xF)<<1)  );  //CW132 for MT6251
   #else
   #error "Please set TX BSI CW for the new chip." 
   #endif
   return bsi_cw;
#else
   return 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_RF_MT6256RF
   #if IS_EPSK_TX_SUPPORT
void L1D_Setup_BB_TxPower( unsigned short reversed_PGA_gain, unsigned char alt_bb_gain )
{
      #if IS_CHIP_MT6256_S00
   (void)alt_bb_gain;

   l1d_rf2.tx_power_sel &= ~( 0x3 << (l1d_rf.cur_slot*2) );
   l1d_rf2.tx_power_sel |=  ( (reversed_PGA_gain & 0x3) << (l1d_rf.cur_slot*2) );
      #else
   unsigned short bb_gain = reversed_PGA_gain & 0x3;

   if( alt_bb_gain )
   {  bb_gain += 4;  }

   l1d_rf2.tx_power_sel &= ~( 0xF << (l1d_rf.cur_slot*4) );
   l1d_rf2.tx_power_sel |=  ( bb_gain << (l1d_rf.cur_slot*4) );
      #endif

   HW_WRITE( TX_PWR, l1d_rf2.tx_power_sel );
}
   #endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned long  L1D_RF_GetSData_ST2( void )
{
   unsigned  long         cw133;
   const     sRAMPDATA*   band_epsk;

   #if IS_CHIP_MT6256_S00
   cw133 = BSI_CW( 0x85, 0x48000|((l1d_rf2.r_cal&0xF)<<3) );
   #elif IS_CHIP_MT6256
   cw133 = BSI_CW( 0x85, 0x48000|((l1d_rf2.r_cal&0xF)<<4)|(l1d_rf2.r_cal&0xF) );
   #endif

   #if IS_EPSK_TX_SUPPORT
   band_epsk = RampData_EPSK[l1d_rf.band];

   if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot) & 0x1 )
   {  /*EPSK TX*/
      int              n             = WEIGHT(1.0);
      int              power_idx;
      unsigned  char   power_dbm     = l1d_rf2.tx_power[l1d_rf.cur_slot];
      unsigned  char   lowest_dbm    = LOWEST_TX_POWER[l1d_rf.band];
      unsigned  short  weighted_PGA_gain, reversed_PGA_gain, RF_PGA_gain;
      static    const  sARFCN_SECTION*  weight;    // Must be static since chips before M6229 will only query if IS_1ST_TX_SLOT
      short            rollback_gain = 0;

      cw133 |= (0x1<<18);  //TX_G8SEL[D18]=1

      #if IS_FHC_SUPPORT && IS_EPSK_TX_GAIN_CONTROL_SUPPORT
      if( l1d_rf.fhc_proc==FHC_PROC_UTS_DAC )
      {
         weighted_PGA_gain = l1d_rf2.fhc_PGA_gain;
         l1d_rf2.fhc_PGA_gain = 0;
      }
      else
      #endif
      {
         /*EPSK TX power*/
         if( power_dbm > (lowest_dbm+2*15) )
         {  power_dbm = lowest_dbm+2*15;  }
         else if( power_dbm < lowest_dbm )
         {  power_dbm = lowest_dbm;  }

         power_idx = (int)((power_dbm-lowest_dbm)/2);

      #if IS_TX_POWER_CONTROL_SUPPORT
         if( l1d_rf.txpc_type == TXPC_AUXADC_CLOSED_TYPE )
         {  /* sub-band compensation is replacd by power detector compensation */
            n = WEIGHT(1.0);
            weighted_PGA_gain = band_epsk->power[power_idx];
         }
         else
      #endif
         {  /* original sub-band compensation */
            weight = WeightARFCN_BinarySearch((l1d_rf2.arfcn&0x3FF), l1d_rf.band , band_epsk->arfcn_weight, 1);
            if( weight )
            {  n = (power_dbm > weight->mid_level) ? weight->hi_weight : weight->low_weight;  }
            else // no entry, not found
            {  n = WEIGHT(1.0);  }
            weighted_PGA_gain = (unsigned short)( ( band_epsk->power[power_idx]*n )>>14 );
         }

         /*TX power rollback start*/
         rollback_gain = L1D_RF_PowerRollback( power_dbm, l1d_rf.band, n, 1);
         weighted_PGA_gain -= rollback_gain;
         /*TX power rollback end*/
      }

      reversed_PGA_gain = (weighted_PGA_gain > 291) ? 0 : (291 - weighted_PGA_gain);  //291=72*4+3, max. EPSK APC DAC for MT6256

      /* write BB PGA gain to BFE register */
      L1D_Setup_BB_TxPower( reversed_PGA_gain, 0 );
      l1d_rf2.is_alt_bb_gain = 0;

      #if IS_TX_POWER_CONTROL_SUPPORT
      {  short arfcn = (short)((l1d_rf.band == FrequencyBand1900)? (l1d_rf2.arfcn | 0x400) : l1d_rf2.arfcn);

         L1D_RF_TXPC_RECORD_PARAM( 0 /*scenario*/, band_epsk, (unsigned short)n, (short)(power_dbm - lowest_dbm)/2, (rollback_gain!=0)?1:0, (short)weighted_PGA_gain );

         /* L1D_RF_TXPC_RecUpdateGain() 1. sets new TX power compensated BB gain into TX_PWR
                                        2. modifies l1d_rf2.is_alt_bb_gain */
         weighted_PGA_gain = (unsigned short)L1D_RF_TXPC_RecUpdateGain( (unsigned short)weighted_PGA_gain, l1d_rf.band, arfcn, (short)l1d_rf.cur_slot );
         reversed_PGA_gain = 291 - weighted_PGA_gain;
         L1D_RF_TXPC_CL_RECORD_PWR_IDX( (power_dbm-lowest_dbm)/2, (short)l1d_rf.cur_slot );
      }
      #endif

      l1d_rf2.tx_gain_setting[l1d_rf.cur_slot] = reversed_PGA_gain; /* For trace output */
      RF_PGA_gain = l1d_rf2.is_alt_bb_gain ? (reversed_PGA_gain>>2)-1 : (reversed_PGA_gain>>2);
      cw133 = (cw133 & ~(0x7f<<8)) | ( (RF_PGA_gain & 0x7f)<<8 );     //TX_RFPGA_GC[D14:D8]
   }
   else //GMSK TX
   #endif
   {  cw133 = cw133 & ~(0x1<<18); //TX_G8SEL[D18]=0
      (void)band_epsk;
   }

   return cw133;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

/*===============================================================================*/
/* short  L1D_RF_GetRxPathLoss( int rf_band, int arfcn, short request_gain )     */
/*===============================================================================*/
/* rf_band      : RF Band. (3:GSM, 4:DCS, 5:PCS)                                 */
/* arfcn        : ARFCN number                                                   */
/* request_gain : Request Gain. the unit is 0.125 dBm                            */
/* return       : The path loss . the unit is 0.125 dBm.                         */
/* ----------------------------------------------------------------------------- */

short L1D_RF_GetRxPathLoss( int rf_band, int arfcn, short request_gain )
{  const  sAGCGAINOFFSET *ofs_ptr;
   short  loss_gain;

   /* Get ARFCN section */
   ofs_ptr = AGC_PATHLOSS_TABLE[rf_band];
   while( ofs_ptr->max_arfcn>=0 )
   {  if((arfcn)<=ofs_ptr->max_arfcn)
      {  break;
      }
      ofs_ptr++;
   }
   loss_gain = ofs_ptr->gain_offset;
   return( loss_gain );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*===============================================================================*/
/* void  L1D_RF_NotifyBatteryVoltage( int  micro_volt )                          */
/*===============================================================================*/
/* micro_volt : The battery voltage with unit 0.0000001V                         */
/* ----------------------------------------------------------------------------- */
/* PS: The measurement period T and average sample n are set in l1d_custom_rf.h  */
/*     #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME( T )        */
/*     #define    BAT_VOLTAGE_AVERAGE_COUNT            n                         */
/* ----------------------------------------------------------------------------- */

void L1D_RF_NotifyBatteryVoltage( int micro_volt )
{
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*===============================================================================*/
/* Crystal solution parameter definition                                         */
/*===============================================================================*/

#ifndef  Custom_RF_XO_CapID
long XO_CapID = 31;
#else
long XO_CapID = Custom_RF_XO_CapID;
#endif

/*===============================================================================*/
/* TX control parameter definition                                               */
/*===============================================================================*/

signed short pdata_gmsk = PDATA_GMSK;
signed short pdata_8psk = PDATA_8PSK;

/*===============================================================================*/
/* void  L1D_RF_NotifyBatteryTemperature( int  mili_degree )                     */
/*===============================================================================*/
/* mili_degree : The battery temperature with unit 0.001 degree centigrade       */
/* ----------------------------------------------------------------------------- */
/* PS: The measurement period T and average sample n are set in l1d_custom_rf.h  */
/*     #define    BAT_TEMPERATURE_SAMPLE_PERIOD            SECONDS2FRAME( T )    */
/*     #define    BAT_TEMPERATURE_AVERAGE_COUNT            n                     */
/* ----------------------------------------------------------------------------- */

void L1D_RF_NotifyBatteryTemperature( int mili_degree )
{
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_NotifyRFTemperature( int temp_adc )
{
#if IS_TX_POWER_CONTROL_SUPPORT
   #if IS_RF_MT6162
   short data_part = (short)(temp_adc&0xFFF);

   l1d_rf.txpc.temp_info.adc = data_part;
   L1D_RF_GetRFTemperatureIdxAndValue( data_part );
   #endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned char L1D_RF_IS_GetRFTemperatureFromADC( void )
{  /* decide if we need to get the temperature information from AUXADC */
   /* if YES, we should return 1 to register a ADC channel             */
#if IS_TXPC_OL_AUXADC_SUPPORT
   return 1;
#else
   return 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_RF_MT6162
/* ------------------------------------------------------------------------- */
/* MT6162                                                                    */
/* ------------------------------------------------------------------------- */

/* RDATA_CS_VAL	Describe CS value of RD process in RDATA state */
/* 0	CS configure as low in RDATA state                         */
/* 1	CS configure as high in RDATA state                        */
#define BSI_RDCS_CON_RDATA_CS_VAL    0

#define BSI_RDCON_IMMRD_EVENT        0 /* 0: not trigger, 1: trigger immediate readback */
#define BSI_RDCON_IMMRD_IMM          1
#define BSI_RDCON_ENHW_ON            1 /* 1: HW read back function enable 0:OFF         */
#define BSI_RDCON_ENHW_OFF           0
//#define BSI_RDCON_LATCH_POL        0 /* 0: latch data at rising edge                  */
#define BSI_RDCON_RD_MODE_IMM        0 /* 0: SW imm mode, 1: TDMA mode                  */
#define BSI_RDCON_RD_MODE_EVENT      1
#define BSI_RDCON_RDATA_LEN         20 /* data length                                   */
#define BSI_RDCON_TRANS_CLKON        1 /* 0: no transition; 1: clk on                   */
#define BSI_RDCON_TRANS_LEN          1 /* Transiton state length                        */
//#define BSI_RDCON_CLK_POL          1 /* 1: inverted clock polarity                    */
//#define BSI_RDCON_CLK_SPD          1 /* 0, 1, 2 or 3: 52/2,4,6,8 Mhz                  */


/*      WADDR_CLK_SPD          RD_CLK_SPD */
/* 0 -->122.88/ 2=61.44  MHz   reserved   */
/* 1 -->122.88/ 4=30.72  MHz              */
/* 2 -->122.88/ 6=20.48  MHz              */
/* 3 -->122.88/ 8=15.36  MHz              */
/* 4 -->122.88/12=10.24  MHz              */
/* 5 -->122.88/16= 7.68  MHz              */
/* 6 -->122.88/24= 5.12  MHz              */
/* 7 -->122.88/32= 3.84  MHz              */
#define BSI_RDADDR_CON_WADDR_CLK_SPD 0
#define BSI_RDCON_RD_CLK_SPD         2

#define BSI_RDADDR_CON_CS            0
#define BSI_RDADDR_CON_CLK_POL       1
#define BSI_RDADDR_CON_LEN          10
#define BSI_READ_TIME                1 /* Wait 1*2Qbit, at least 6T(61.44MHz)+11T(20.48MHz) = 635ns(~0.688Qbit) is needed for OH */

   #if IS_CHIP_MT6276_S00 || IS_CHIP_MT6573 /* for 6276E1 and 6573 */
#define BSI_RDCON_IMMRD_SETTING (((BSI_RDCON_IMMRD_IMM  &0x1)<<19)|((BSI_RDCON_ENHW_ON      &0x1) <<15)|\
	                             ( (BSI_RDCON_RD_MODE_IMM&0x1)<<14)|(((BSI_RDCON_RDATA_LEN-1)&0x1F)<< 9)|\
	                             ( (BSI_RDCON_TRANS_CLKON&0x1)<< 8)|((BSI_RDCON_TRANS_LEN    &0x7) << 5)|\
	                             (  BSI_RDCON_RD_CLK_SPD &0x7     ))
   #elif IS_CHIP_MT6276_S01 || IS_CHIP_MT6575 /* for 6276E2 and 6575 */
#define BSI_RDCON_IMMRD_SETTING (((BSI_RDCON_IMMRD_IMM  &0x1)<<19)|((BSI_RDCON_ENHW_ON      &0x1) <<15)|\
	                             ( (BSI_RDCON_RD_MODE_IMM&0x1)<<14)|(((BSI_RDCON_RDATA_LEN-1)&0x3F)<< 8)|\
	                             ( (BSI_RDCON_TRANS_CLKON&0x1)<< 7)|((BSI_RDCON_TRANS_LEN    &0xF) << 3)|\
	                             (  BSI_RDCON_RD_CLK_SPD &0x7     ))
   #else
#error "please review new chip BSI read function for MT6162!"
   #endif

#define BSI_RDADDR_CON_MAIN     (((BSI_RDADDR_CON_CS     &0x1)<<15)|(((BSI_RDADDR_CON_LEN-1)      &0x1F)<<8)|\
	                             ((BSI_PORTB_SELECT      &0x1)<< 7)|((BSI_RDADDR_CON_WADDR_CLK_SPD&0x7 )<<3)|\
	                             ((BSI_RDADDR_CON_CLK_POL&0x3)<< 1))
#define BSI_RDCS_CON_MAIN       0//((BSI_RDCS_CON_RDATA_CS_VAL&0x1)<<15)|(((1<<BSI_RDCON_TRANS_LEN)-1)&0x3FFF)

#define BSI_STORE_READBACK_DATA( is_ok, p ) { p = (is_ok) ? (HW_READ(BSI_RDDAT)&0xFFFFF) : ( 0xAAAAA ); }


void IMM_RECEIVE_BSI( unsigned short ADD_Ctrl, unsigned long ADD, unsigned short DATA_Ctrl, unsigned long *DATA )
{
   unsigned long bsi_rdaddr_backup;
   unsigned long bsi_rdaddr_con_backup;
   unsigned long bsi_rdcs_con_backup;
   unsigned long bsi_rdcon_backup;
   int           count_down = BSI_READ_TIME;
   int           is_ready   = 0;

   (void)ADD_Ctrl; (void)DATA_Ctrl;                   /* do nothing */

   bsi_rdaddr_backup     = HW_READ( BSI_RDADDR     ); /* Backup original settings */
   bsi_rdaddr_con_backup = HW_READ( BSI_RDADDR_CON );
   bsi_rdcs_con_backup   = HW_READ( BSI_RDCS_CON   );
   bsi_rdcon_backup      = HW_READ( BSI_RDCON      );

   *DATA = 0;

   HW_WRITE( BSI_RDADDR, ((0x1)<<8)|(ADD&0xFF)   );
   HW_WRITE( BSI_RDADDR_CON, BSI_RDADDR_CON_MAIN );
   HW_WRITE( BSI_RDCS_CON, BSI_RDCS_CON_MAIN     );

   #if IS_CHIP_MT6276_S00 || IS_CHIP_MT6573 /* for 6276E1 and 6573 */
   HW_WRITE( BSI_RDDAT, 0x0                      ); /* Clear Ready bit before triggering immediate read back event */
   #else /* for 6276E2 */
   HW_WRITE( BSI_RDDAT_H, 0x0                    ); /* Clear Ready bit before triggering immediate read back event */
   #endif
   HW_WRITE( BSI_RDCON, BSI_RDCON_IMMRD_SETTING  );

   /*Wait for readback ready*/
   while( count_down > 0 )
   {
      WAIT_TIME_QB(2);
   #if IS_CHIP_MT6276_S00 || IS_CHIP_MT6573 /* for 6276E1 and 6573 */
      is_ready = ( HW_READ(BSI_RDDAT)&0x80000000   );
   #else /* for 6276E2 */
      is_ready = ( HW_READ(BSI_RDDAT_H)&0x80000000 );
   #endif
      if( is_ready )
         break;
      count_down--;
      LET_SIM_TIME_RUN_A_BIT();
   }

   /*Store RF readback data*/
   BSI_STORE_READBACK_DATA( is_ready, *DATA );

   /*Restore original setting*/
   #if IS_COSIM_ON_L1SIM_SUPPORT
   /* do not restore in the modem sim; otherwise, the settings can not be checked */
   #else
   HW_WRITE( BSI_RDADDR,      bsi_rdaddr_backup             );
   HW_WRITE( BSI_RDADDR_CON, (bsi_rdaddr_con_backup&0xFFFF) );
   HW_WRITE( BSI_RDCS_CON,   (bsi_rdcs_con_backup&0xFFFF)   );
   HW_WRITE( BSI_RDCON,       bsi_rdcon_backup              );
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#elif IS_RF_MT6250RF || IS_RF_MT6260RF || IS_RF_MT6261RF
/* ------------------------------------------------------------------------- */
/* MT6250RF                                                                  */
/* ------------------------------------------------------------------------- */
/* Immediate BSI control                                                     */

#define BSI_RDCON_IMMRD_EVENT    0      /* 0: not trigger, 1: trigger immediate readback */
#define BSI_RDCON_IMMRD_IMM      1
#define BSI_RDCON_ENHW_ON        1      /* 1: HW read back function enable, 0:OFF        */
#define BSI_RDCON_ENHW_OFF       0
#define BSI_RDCON_RD_MODE_IMM    0      /* 0: SW imm mode, 1: TDMA mode                  */
#define BSI_RDCON_RD_MODE_EVENT  1
#define BSI_RDCON_RDATA_LEN     32      /* read back data length                         */
#define BSI_RDCON_TRANS_CLKON    0      /* 0: no transition                              */
#define BSI_RDCON_TRANS_LEN      0      /* transiton state length                        */
#define BSI_RDCON_CLK_SPD        3      /* 3: 130/8 MHz                                  */

#define BSI_RDCON_IMMRD_SETTING ((BSI_RDCON_IMMRD_IMM    << 19) | (BSI_RDCON_ENHW_ON      << 15) | (BSI_RDCON_RD_MODE_IMM   << 14) | \
                                ((BSI_RDCON_RDATA_LEN+1) <<  8) | (BSI_RDCON_TRANS_CLKON  <<  7) | \
                                 (BSI_RDCON_TRANS_LEN    <<  3) | (BSI_RDCON_CLK_SPD))
#define BSI_RDCON_EVENT_SETTING ((BSI_RDCON_IMMRD_EVENT  << 19) | (BSI_RDCON_ENHW_ON      << 15) | (BSI_RDCON_RD_MODE_EVENT << 14) | \
                                ((BSI_RDCON_RDATA_LEN+1) <<  8) | (BSI_RDCON_TRANS_CLKON  <<  7) | \
                                 (BSI_RDCON_TRANS_LEN    <<  3) | (BSI_RDCON_CLK_SPD))
#define BSI_RDCON_CLOSE_SETTING  (BSI_RDCON_ENHW_OFF     << 15)

/* -------------------------------------- */
/*       WADDR_CLK_SPD        RD_CLK_SPD  */
/* -------------------------------------- */
/* 0 --> 130/ 2 = 65    MHz   reserved    */
/* 1 --> 130/ 4 = 32.5  MHz               */
/* 2 --> 130/ 6 = 21.67 MHz               */
/* 3 --> 130/ 8 = 16.25 MHz               */
/* 4 --> 130/12 = 10.83 MHz               */
/* 5 --> 130/16 =  8.13 MHz               */
/* 6 --> 130/24 =  5.42 MHz               */
/* 7 --> 130/32 =  4.06 MHz               */
/* -------------------------------------- */
#define BSI_RDADDR_CON_CLK_SPD  0
#define BSI_RDADDR_CON_LEN      10      /* BSI addr length                        */
#define BSI_RDADDR_CON_CLK_POL  BSI_CLK_POL

#define BSI_RDADDR_CON_SETTING  (((BSI_RDADDR_CON_LEN-1) << 8) | (BSI_RDADDR_CON_CLK_SPD << 3) | (BSI_RDADDR_CON_CLK_POL << 1))

#define BSI_READ_TIME           25      /* Wait 25*2 Qb                           */
#define BSI_NOT_READBACK_DATA   0x44444 /* ((1 << BSI_RDCON_RDATA_LEN) | 0x44444) */

#define BSI_STORE_READBACK_DATA( is_ok, p ) { p = (is_ok) ? HW_READ( BSI_RDDAT ) : BSI_NOT_READBACK_DATA; }

sBSIread BSIread;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void IMM_RECEIVE_BSI( unsigned short ADD_Ctrl, unsigned long ADD, unsigned short DATA_Ctrl, unsigned long *DATA )
{
   unsigned long bsi_rdcon_backup;
   unsigned long bsi_rdaddr_con_backup;
   unsigned long bsi_rdaddr_backup;
   int           count_down = BSI_READ_TIME;
   int           is_ready   = 0;

   (void)ADD_Ctrl; (void)DATA_Ctrl; // do nothing

   /*Backup original setting*/
   bsi_rdaddr_con_backup = HW_READ( BSI_RDADDR_CON );
   bsi_rdcon_backup      = HW_READ( BSI_RDCON      );
   bsi_rdaddr_backup     = HW_READ( BSI_RDADDR     );

   /*Clear Ready bit before triggering immediate read back event*/
   HW_WRITE( BSI_RDCON, (HW_READ( BSI_RDCON ) & (~0x80000000)) );

   HW_WRITE( BSI_RDADDR_CON, BSI_RDADDR_CON_SETTING );

   /*Set readback addr*/
   HW_WRITE( BSI_RDADDR, ((0x1)<<8)|(ADD&0xFF) );

   /*Trigger HW read back active*/
   HW_WRITE( BSI_RDCON, BSI_RDCON_IMMRD_SETTING );

   /*Wait for readback ready*/
   while( count_down > 0 )
   {
      WAIT_TIME_QB(2);
      is_ready = HW_READ( BSI_RDCON ) & 0x80000000;
      if( is_ready )
         break;
      count_down--;
   }

   /*Store RF readback data*/
   BSI_STORE_READBACK_DATA( is_ready, *DATA );

   /*Restore original setting*/
   #if IS_COSIM_ON_L1SIM_SUPPORT
   #else
   HW_WRITE(BSI_RDADDR_CON, bsi_rdaddr_con_backup );
   HW_WRITE(BSI_RDCON     , bsi_rdcon_backup      );
   HW_WRITE(BSI_RDADDR    , bsi_rdaddr_backup     );
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* This function is only called in the end of window setup @ CT1. */
void L1D_RF_Readback_BSI_Set_Event( void* data )
{
   sBSIread* p;
   p = (sBSIread*)data;

   #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT || IS_TEMP_COMP_TC_GAIN_SUPPORT
   {
      int       rx_slots, rx_mask, event_timing, slot_idx, i;
      int       bitmap2idx[9] = { 0, 1, 2, 0, 3, 0, 0, 0, 4};
      
      /*Evaluate the TQ count which be 100QB before the last RX win*/
      rx_slots     = (l1d_rf.rx_slots) & 0xF;
      event_timing = TQ_BSI_READ_TIME;
   
      for( rx_mask = 0x8; rx_mask != 0; rx_mask >>= 1 )
      {  if( rx_slots & rx_mask ) break;  }
   
      slot_idx = bitmap2idx[rx_mask];
   
      for( i = 1; i < slot_idx; i++) 
      {  event_timing += 625;  }
      p->event_timing = (unsigned short)event_timing;
   }
   #endif

   /*Set TDMA timer*/
   HW_WRITE( TDMA_RD_BSI0, p->event_timing );

   /*Enable HW read back TDMA event mode*/
   HW_WRITE( BSI_RDCON, BSI_RDCON_EVENT_SETTING );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Readback_BSI_Set_Address( void* data )
{
   sBSIread* p;
   p = (sBSIread*)data;

   HW_WRITE( BSI_RDADDR_CON, BSI_RDADDR_CON_SETTING );

   /*Set readback addr*/
   HW_WRITE( BSI_RDADDR, ((0x1)<<8)|(p->ADD&0xFF)   );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Readback_BSI_GetData( unsigned short ADD, unsigned long *DATA )
{
   unsigned long read_addr, bsi_rdaddr;

   bsi_rdaddr = HW_READ( BSI_RDADDR );

   /*Get real read addr*/
   read_addr  = bsi_rdaddr & 0xFF;

   /*Store RF readback data*/
   BSI_STORE_READBACK_DATA( (read_addr == ADD), *DATA );
   BSIread.flag |=  BSI_GET_READBACK_DATA ;
   BSIread.ADD_pair = ADD;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#elif IS_RF_MT6256RF || IS_RF_MT6251RF || IS_RF_MT6255RF
/* ------------------------------------------------------------------------- */
/* MT6256RF, MT6251RF, MT6255RF                                              */
/* ------------------------------------------------------------------------- */

/*Immediate BSI control*/
#define BSI_RDCON_IMMRD_EVENT    0      /* 0: not trigger, 1: trigger immediate readback   */
#define BSI_RDCON_IMMRD_IMM      1
#define BSI_RDCON_ENHW_ON        1      /* 1: HW read back function enable 0:OFF           */
#define BSI_RDCON_ENHW_OFF       0
#define BSI_RDCON_LATCH_POL      0      /* 0: latch data at rising edge                    */
#define BSI_RDCON_RD_MODE_IMM    0      /* 0: SW imm mode, 1: TDMA mode                    */
#define BSI_RDCON_RD_MODE_EVENT  1
#define BSI_RDCON_RDATA_LEN     20      /* data length                                     */
#define BSI_RDCON_TRANS_CLKON    0      /* 0: no transition                                */
#define BSI_RDCON_TRANS_LEN      1      /* Transiton state length                          */
#define BSI_RDCON_CLK_POL        1      /* 1: inverted clock polarity                      */
#define BSI_RDCON_CLK_SPD        1      /* 0, 1, 2 or 3: 52/2,4,6,8 Mhz                    */

#define BSI_RDCON_IMMRD_SETTING ((BSI_RDCON_IMMRD_IMM     << 19) | (BSI_RDCON_ENHW_ON   << 15) | (BSI_RDCON_LATCH_POL   << 14) | \
                                 (BSI_RDCON_RD_MODE_IMM   << 13) | (BSI_RDCON_RDATA_LEN <<  8) | (BSI_RDCON_TRANS_CLKON <<  7) | \
                                 (BSI_RDCON_TRANS_LEN     <<  4) | (BSI_RDCON_CLK_POL   <<  2) | (BSI_RDCON_CLK_SPD))
#define BSI_RDCON_EVENT_SETTING ((BSI_RDCON_IMMRD_EVENT   << 19) | (BSI_RDCON_ENHW_ON   << 15) | (BSI_RDCON_LATCH_POL   << 14) | \
                                 (BSI_RDCON_RD_MODE_EVENT << 13) | (BSI_RDCON_RDATA_LEN <<  8) | (BSI_RDCON_TRANS_CLKON <<  7) | \
                                 (BSI_RDCON_TRANS_LEN     <<  4) | (BSI_RDCON_CLK_POL   <<  2) | (BSI_RDCON_CLK_SPD))
#define BSI_RDCON_CLOSE_SETTING  (BSI_RDCON_ENHW_OFF      << 15)
#define BSI_ADDR_LEN             8     /* BSI addr length */
#define BSI_ADDR_READ_BIT        1
#define BSI_RDCON_READADDR(n)   ((BSI_ADDR_READ_BIT << (BSI_ADDR_LEN+16)) | (BSI_ADDR_LEN << 1) | ((n) << 16))
#define BSI_READ_TIME           25     /* Wait 25*2 Qb*/
#define BSI_NOT_READBACK_DATA   ((1 << BSI_RDCON_RDATA_LEN) | 0x44444)

#define BSI_STORE_READBACK_DATA( is_ok, p ) { p = (is_ok) ? HW_READ( BSI_RDDAT ) : BSI_NOT_READBACK_DATA; }

sBSIread BSIread;

void IMM_RECEIVE_BSI( unsigned short ADD_Ctrl, unsigned long ADD, unsigned short DATA_Ctrl, unsigned long *DATA )
{
   unsigned long bsi_rdcon_backup;
   unsigned long bsi_rdaddr_con_backup;
   int           count_down = BSI_READ_TIME;
   int           is_ready   = 0;

   (void)ADD_Ctrl; (void)DATA_Ctrl; // do nothing
   /*Backup original setting*/
   bsi_rdaddr_con_backup = HW_READ( BSI_RDADDR_CON );
   bsi_rdcon_backup      = HW_READ( BSI_RDCON      );

   /*Set readback addr*/
   HW_WRITE( BSI_RDADDR_CON, BSI_RDCON_READADDR( ADD ) );

   /*Trigger HW read back active*/
   HW_WRITE( BSI_RDCON, BSI_RDCON_IMMRD_SETTING );

   /*Wait for readback ready*/
   while( count_down > 0 )
   {
      WAIT_TIME_QB(2);
      is_ready = HW_READ( BSI_RDADDR_CON ) & 0x1;
      if( is_ready )
         break;
      count_down--;
   }

   /*Store RF readback data*/
   BSI_STORE_READBACK_DATA( is_ready, *DATA );

   /*Restore original setting*/
   HW_WRITE(BSI_RDADDR_CON, bsi_rdaddr_con_backup );
   HW_WRITE(BSI_RDCON     , bsi_rdcon_backup      );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Readback_BSI_Set_Event( void* data )
{
   sBSIread* p;
   p = (sBSIread*)data;
   /*Set TDMA timer*/
   HW_WRITE( TDMA_RD_BSI0, p->event_timing );

   /*Enable HW read back TDMA event mode*/
   HW_WRITE( BSI_RDCON, BSI_RDCON_EVENT_SETTING );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Readback_BSI_Set_Address( void* data )
{
   sBSIread* p;
   p = (sBSIread*)data;

   /*Set readback addr*/
   HW_WRITE( BSI_RDADDR_CON, BSI_RDCON_READADDR( p->ADD ) );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Readback_BSI_GetData( unsigned short ADD, unsigned long *DATA )
{
   unsigned long read_addr, bsi_rdaddr_con;

   bsi_rdaddr_con = HW_READ( BSI_RDADDR_CON );

   /*Get real read addr*/
   read_addr = (bsi_rdaddr_con >> 16) & ((1 << BSI_ADDR_LEN) - 1);

   // Does get BSI data ?
   if( bsi_rdaddr_con & (0x1) )
   {  /*Store RF readback data*/
      BSI_STORE_READBACK_DATA( (read_addr == ADD), *DATA );
      /*Clear ready bit*/
      HW_WRITE( BSI_RDADDR_CON, bsi_rdaddr_con & (~0x1) );
      BSIread.flag |=  BSI_GET_READBACK_DATA ;
      BSIread.ADD_pair = ADD;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#elif IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B || IS_RF_MT6140C || IS_RF_CMOSEDGE || IS_RF_MTKSOC1 || IS_RF_MTKSOC1T || IS_RF_MT6252RF
   #if IS_CHIP_MT6227_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  HW_BSI_DOUT_CTRL(clk, cs, data) (*(BSI_DOUT) = ((clk&0x1)|((cs<<1)&0x2)|((data<<2)&0x4)))
#define  GPIO_BSI_DIN_PORT   1 /* Use GPIO1 as BSI DATA input port       */
#define  GPIO_BSI_DIN_MODE   1 /* mode 1 : BSI RF calibration data input */
#define  GPIO_BSI_DIN_DIR    0 /* input                                  */

void IMM_RECEIVE_BSI( unsigned short ADD_Ctrl, unsigned long ADD, unsigned short DATA_Ctrl, unsigned long *DATA )
{
      #if !IS_SMARTPHONE_CHIP_TK6516_AND_LATTER_VERSION && !IS_SOC_CHIP
   unsigned short saved_data[2];
   void L1D_GPIO_InitIO(char, char);
   void L1D_GPIO_ModeSetup(kal_uint16, kal_uint16);
   extern char L1D_GPIO_ReturnMode(char);
   extern char L1D_GPIO_ReturnDir(char);
      #endif
   short  tx_bit_cnt, rx_bit_cnt, n;
   unsigned long  rx_data;

   tx_bit_cnt = ((ADD_Ctrl>>8)&0x7F)+1;
   rx_bit_cnt = ((DATA_Ctrl>>8)&0x7F)+1;
   rx_data  = 0;

      // TK6516 BSI_CS1_GPIO & BSI_DIN_GPIO are in AP side, we cannot do it directly
      #if !IS_SMARTPHONE_CHIP_TK6516_AND_LATTER_VERSION  && !IS_SOC_CHIP
   // set GPIO_MODE
   saved_data[0] =L1D_GPIO_ReturnMode(GPIO_BSI_DIN_PORT);
   L1D_GPIO_ModeSetup(GPIO_BSI_DIN_PORT, GPIO_BSI_DIN_MODE);
   // set GPIO_DIR as input
         #ifndef __CUST_NEW__
   saved_data[1] =L1D_GPIO_ReturnDir(GPIO_BSI_DIN_PORT);
   L1D_GPIO_InitIO(GPIO_BSI_DIN_DIR, GPIO_BSI_DIN_PORT);
         #endif /*__CUST_NEW__ */
   // BSI IO mode control register
      #endif

      #if IS_RF_MTKSOC1T || IS_RF_MTKSOC1 || IS_RF_MT6252RF
   HW_WRITE( BSI_IO_CON, 0x1); //SW control
      #elif IS_RF_MT6140B || IS_RF_MT6140C || IS_RF_MT6140D || IS_RF_CMOSEDGE
   HW_WRITE( BSI_IO_CON, 0x3); //MJ 3-wire BSI SW control
      #else
   HW_WRITE( BSI_IO_CON, 0x7); //MJ 4-wire BSI SW control
      #endif

      #if IS_RF_CMOSEDGE || IS_RF_MTKSOC1T || IS_RF_MTKSOC1
   ADD|=0x20L; //read bit
      #elif IS_RF_MT6252RF
   ADD|=0x100L; //read bit
      #endif

      #if IS_RF_CMOSEDGE || IS_RF_MTKSOC1T || IS_RF_MTKSOC1 || IS_RF_MT6252RF
   // Initial BSI DOUT
   HW_BSI_DOUT_CTRL(0, 0, 0); /*input: CLK, CS, DATA */
   /* BSI TX begin: Send AUXOUT command */
   for( n=tx_bit_cnt-1; n>=0; n--)
   {
      static unsigned short BSI_DOUT_DATA;
      BSI_DOUT_DATA=(ADD>>n)&0x0001;
      HW_BSI_DOUT_CTRL(0, 1, BSI_DOUT_DATA); /*input: CLK, CS, DATA */
      HW_BSI_DOUT_CTRL(1, 1, BSI_DOUT_DATA); /*input: CLK, CS, DATA */
   }
   HW_BSI_DOUT_CTRL(0, 1, 0); /*input: CLK, CS, DATA */

      #else
   // Initial BSI DOUT
   HW_BSI_DOUT_CTRL(0, 0, 0); /*input: CLK, CS, DATA */
   /* BSI TX begin: Send AUXOUT command */
   for( n=tx_bit_cnt-1; n>=0; n--)
   {
      static unsigned short BSI_DOUT_DATA;
      BSI_DOUT_DATA=(ADD>>n)&0x0001;
      HW_BSI_DOUT_CTRL(0, 0, BSI_DOUT_DATA); /*input: CLK, CS, DATA */
      HW_BSI_DOUT_CTRL(1, 0, BSI_DOUT_DATA); /*input: CLK, CS, DATA */
   }
   HW_BSI_DOUT_CTRL(0, 1, 0); /*input: CLK, CS, DATA */
      #endif

      #if IS_RF_MT6140B || IS_RF_MT6140C || IS_RF_MT6140D || IS_RF_CMOSEDGE || IS_RF_MTKSOC1T || IS_RF_MTKSOC1
   HW_WRITE( BSI_IO_CON, 0x1); //MJ 3-wire BSI read back control
      #endif

      #if IS_RF_CMOSEDGE || IS_RF_MTKSOC1T || IS_RF_MTKSOC1 || IS_RF_MT6252RF
   WAIT_TIME_QB(3);
   /* BSI TX end: Send AUXOUT command */
   /* BSI RX begin: Receive AUXOUT DATA */
   for( n=rx_bit_cnt; n>=0; n--)
   {
      HW_BSI_DOUT_CTRL(1, 0, 0); /*input: CLK, CS, DATA */
      WAIT_TIME_QB(3);
      //latch AUXOUT Data
      if( HW_READ(BSI_DINT) & 0x1 )  // DAT=1
         rx_data |= 1;
      rx_data <<=1;
      HW_BSI_DOUT_CTRL(0, 0, 0); /*input: CLK, CS, DATA */
   }
   /* BSI RX end: Receive AUXOUT DATA */
   HW_BSI_DOUT_CTRL(0, 0, 0); /*input: CLK, CS, DATA */
   WAIT_TIME_QB(3);

      #else
   WAIT_TIME_QB(3);
   /* BSI TX end: Send AUXOUT command */
   /* BSI RX begin: Receive AUXOUT DATA */
   for( n=rx_bit_cnt; n>=0; n--)
   {
      HW_BSI_DOUT_CTRL(0, 1, 0); /*input: CLK, CS, DATA */
      WAIT_TIME_QB(3);
      //latch AUXOUT Data
      if( HW_READ(BSI_DINT) & 0x1 )  // DAT=1
         rx_data |= 1;
      rx_data <<=1;
      HW_BSI_DOUT_CTRL(1, 1, 0); /*input: CLK, CS, DATA */
   }
   /* BSI RX end: Receive AUXOUT DATA */
   HW_BSI_DOUT_CTRL(0, 1, 0); /*input: CLK, CS, DATA */
   WAIT_TIME_QB(3);
   HW_BSI_DOUT_CTRL(0, 0, 0); /*input: CLK, CS, DATA */
      #endif

      // TK6516 BSI_CS1_GPIO & BSI_DIN_GPIO are in AP side, we cannot do it directly
      #if !IS_SMARTPHONE_CHIP_TK6516_AND_LATTER_VERSION && !IS_SOC_CHIP
   L1D_GPIO_ModeSetup(GPIO_BSI_DIN_PORT, saved_data[0]);
         #ifndef __CUST_NEW__
   L1D_GPIO_InitIO(saved_data[1] , GPIO_BSI_DIN_PORT);
         #endif /*__CUST_NEW__ */
      #endif

   // BSI IO mode control register
   HW_WRITE( BSI_IO_CON, 0x2);  //BSI return HW control
   *DATA = rx_data>>1;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

   #elif IS_CHIP_MT6205_AND_LATTER_VERSION
      #ifdef __CUST_NEW__
extern const char gpio_rf_control2_pin;
#define  GPIO_BSI_DIN_PORT   gpio_rf_control2_pin /* Use GPIO as BSI DATA input port */
      #else /* __CUST_NEW__ */
#define  GPIO_BSI_DIN_PORT   1 /* Use GPIO1 as BSI DATA input port */
      #endif /* __CUST_NEW__ */
#define  GPIO_BSI_DIN_MODE   0 /* mode 0 : GPIO                    */
#define  GPIO_BSI_DIN_DIR    0 /* input                            */

      #if IS_CHIP_MT6205
         #ifdef __CUST_NEW__
extern const char gpio_rf_control3_pin;
#define  GPIO_BSI_CLK_PORT   gpio_rf_control3_pin /* Use GPIO as BSI CLK output port*/
         #else /* __CUST_NEW__ */
#define  GPIO_BSI_CLK_PORT  6 /* Use GPIO6(BPI6) as BSI CLK output port*/
         #endif /* __CUST_NEW__ */

#define  GPIO_BSI_CLK_MODE   0 /* mode 0 : GPIO                    */
#define  GPIO_BSI_CLK_DIR    1 /* output                           */

      #else /* IS_CHIP_MT6205 */

         #ifdef __CUST_NEW__
extern const char gpio_rf_control3_pin;
#define  GPIO_BSI_CLK_PORT   gpio_rf_control3_pin /* Use GPIO as BSI CLK output port*/
         #else /* __CUST_NEW__ */
#define  GPIO_BSI_CLK_PORT  10 /* Use GPIO10(BPI6) as BSI CLK output port*/
         #endif /* __CUST_NEW__ */

#define  GPIO_BSI_CLK_MODE   0 /* mode 0 : GPIO                    */
#define  GPIO_BSI_CLK_DIR    1 /* output                           */

      #endif /* IS_CHIP_MT6205 */

void IMM_RECEIVE_BSI( unsigned short ADD_Ctrl, unsigned long ADD, unsigned short DATA_Ctrl, unsigned long *DATA )
{
   unsigned short saved_data[4];
   short  n, rx_bit_cnt;
   unsigned long  rx_data;
   void L1D_GPIO_InitIO(char, char);
   extern char L1D_GPIO_ReadIO(char);
   void L1D_GPIO_WriteIO(char, char);
   void L1D_GPIO_ModeSetup(kal_uint16, kal_uint16);
   extern char L1D_GPIO_ReturnMode(char);
   extern char L1D_GPIO_ReturnDir(char);

   rx_bit_cnt = ((DATA_Ctrl>>8)&0x7F)+1;
   rx_data  = 0;

   // set GPIO_MODE as BSI read back CLK
   saved_data[0] =L1D_GPIO_ReturnMode(GPIO_BSI_CLK_PORT);
   L1D_GPIO_ModeSetup(GPIO_BSI_DIN_PORT, GPIO_BSI_CLK_MODE);
   // set GPIO_DIR as input to avoid interfering with BSI CLK
   saved_data[1] =L1D_GPIO_ReturnDir(GPIO_BSI_CLK_PORT);
   L1D_GPIO_InitIO(~GPIO_BSI_CLK_DIR, GPIO_BSI_CLK_PORT);
   // set GPIO_MODE as BSI read back DATA_IN
   saved_data[2] =L1D_GPIO_ReturnMode(GPIO_BSI_DIN_PORT);
   L1D_GPIO_ModeSetup(GPIO_BSI_DIN_PORT, GPIO_BSI_DIN_MODE);
   // set GPIO_DIR as input
   saved_data[3] =L1D_GPIO_ReturnDir(GPIO_BSI_DIN_PORT);
   L1D_GPIO_InitIO(GPIO_BSI_DIN_DIR, GPIO_BSI_DIN_PORT);

   {  volatile unsigned long  addr;
      HW_WRITE( BSI_CON, SCTRL_IMOD_RX_MAIN );
      addr = (long)BSI_Dn_CON(0);
      HW_WRITE( (APBADDR)addr, ADD_Ctrl );  addr += 4;
      HW_WRITE_BSI_DATA( addr, ADD );
      HW_WRITE( BSI_CON, SCTRL_IMOD_RX_SEND );  // send AUXOUT commend
      WAIT_TIME_QB(64);
   }
   L1D_GPIO_InitIO(GPIO_BSI_CLK_DIR, GPIO_BSI_CLK_PORT);// set GPIO_DIR as output to generate BSI read back CLK

   L1D_GPIO_WriteIO(0, GPIO_BSI_CLK_PORT);   // set GPIO_CLK_DOUT = 0
   for( n=rx_bit_cnt; n>=0; n--)
   {
      L1D_GPIO_WriteIO(1, GPIO_BSI_CLK_PORT);    // set GPIO_CLK_DOUT = 1
      //latch AUXOUT Data
      if( L1D_GPIO_ReadIO(GPIO_BSI_DIN_PORT) & 0x1 )  // DAT=1
         rx_data |= 1;
      rx_data <<=1;
      L1D_GPIO_WriteIO(0, GPIO_BSI_CLK_PORT);   // set GPIO_CLK_DOUT = 0
   }
   rx_data >>=1;
   L1D_GPIO_ModeSetup(GPIO_BSI_DIN_PORT, saved_data[0] );
   L1D_GPIO_InitIO(  saved_data[1] , GPIO_BSI_CLK_PORT);
   L1D_GPIO_ModeSetup(GPIO_BSI_DIN_PORT, saved_data[2] );
   L1D_GPIO_InitIO(saved_data[3] , GPIO_BSI_DIN_PORT);
   *DATA = rx_data;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

   #endif
#endif /*IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B  || IS_RF_MT6140C || IS_RF_CMOSEDGE || IS_RF_MTKSOC1 || IS_RF_MTKSOC1T || IS_RF_MT6252RF*/

/*===============================================================================================*/

void L1D_RF_TXIQ_Dynamic_Swap( void )
{
#if BBTX_IQSWAP_ONFLY //BBTx has double buffer design for TXIQSWAP
   l1d_rf.d2c_txiqswap = 0;
#elif IS_RF_SKY74117 || IS_RF_SKY74400
/* under construction !*/
#else
   l1d_rf.d2c_txiqswap = 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_BFE_SetTxIQSwap( void )
{
#if IS_DLIF_CHIP
   // do nothing
#else
   BFETXSET  bfetxset;
   HW_READ_BFETXSET( bfetxset );

   if(l1d_rf.inj)
      bfetxset.field.iqswap = 1;
   else
      bfetxset.field.iqswap = 0;

   HW_WRITE_BFETXSET( bfetxset );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_BBTXRX_CHIP_DESIGN_VER_2

#define HW_WRITE_TX_PH( data )                             \
{  APBADDR _reg = TX_PH(0);                                \
   HW_WRITE( _reg, data );   _reg += 2;                    \
   HW_WRITE( _reg, data );   _reg += 2;                    \
   HW_WRITE( _reg, data );   _reg += 2;                    \
   HW_WRITE( _reg, data );   _reg += 2;                    \
   HW_WRITE( _reg, data );   _reg += 2;                    \
   HW_WRITE( _reg, data );                                 \
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#define HW_WRITE_TX_GAIN( data )                           \
{  unsigned short _data;                                   \
   APBADDR _reg = TX_GAIN(0);                              \
   _data = ( data & 0x00FF )|( data<<8 );                  \
   HW_WRITE( _reg, _data );   _reg += 2;                   \
   HW_WRITE( _reg, _data );   _reg += 2;                   \
   HW_WRITE( _reg, _data );                                \
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#define HW_WRITE_TX_OFF( data )                            \
{  APBADDR _reg = TX_OFFSET(0);                            \
   HW_WRITE( _reg, data );   _reg += 2;                    \
   HW_WRITE( _reg, data );   _reg += 2;                    \
   HW_WRITE( _reg, data );   _reg += 2;                    \
   HW_WRITE( _reg, data );   _reg += 2;                    \
   HW_WRITE( _reg, data );   _reg += 2;                    \
   HW_WRITE( _reg, data );                                 \
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_BFE_SET_TX_CON( int idx, void *_set )
{
   BFETXCON *bfetxcon = (BFETXCON *)_set;
   APBADDR        reg = TX_GAIN( ((idx>>1)&0x3) );
   unsigned short d16 = HW_READ( reg );

   d16 &= ~(0xFF                     << (idx&0x1)*8);
   d16 |=  (bfetxcon->field2.tx_gain << (idx&0x1)*8);
   HW_WRITE( reg, d16 );
   HW_WRITE( TX_PH(idx),     bfetxcon->field2.tx_ph  );
   HW_WRITE( TX_OFFSET(idx), bfetxcon->field2.tx_off );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#endif

void L1D_BFE_GET_RxRegisters( void *_set )
{
   BFERXSET *set = (BFERXSET *)_set;
#if IS_DLIF_CHIP
   #if IS_CHIP_MT6255
/*MT6255*/         {
/*MT6255*/            set->data[0] = HW_READ( RX_CON0 );
/*MT6255*/            set->data[1] = HW_READ( RX_TIME_CON0 );
/*MT6255*/            set->data[2] = HW_READ( RX_TIME_CON1 );
/*MT6255*/         }
   #elif IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
/*MT6256E1,MT6251*/{
/*MT6256E1,MT6251*/   set->data[0] = HW_READ( RX_CON0 );
/*MT6256E1,MT6251*/   set->data[1] = HW_READ( RX_CON3 );
/*MT6256E1,MT6251*/   set->data[2] = HW_READ( IREST_CON0 );
/*MT6256E1,MT6251*/   set->data[3] = HW_READ( BFE_CON1 );
/*MT6256E1,MT6251*/   set->data[4] = HW_READ( RX_MON );
/*MT6256E1,MT6251*/}
   #elif IS_CHIP_MT6260 || IS_CHIP_MT6261
/*MT6260*/         {
/*MT6260*/            set->data[0] = HW_READ( RX_CON0 );
/*MT6260*/            set->data[1] = HW_READ( RX_TIME_CON0 );
/*MT6260*/            set->data[2] = HW_READ( RX_TIME_CON1 );
/*MT6260*/            set->data[3] = HW_READ( RX_TIME_CON2 );
/*MT6260*/         }
   #elif IS_CHIP_MT6250
/*MT6250*/         {
/*MT6250*/            set->data[0] = HW_READ( RX_CON0 );
/*MT6250*/            set->data[1] = HW_READ( RX_TIME_CON0 );
/*MT6250*/            set->data[2] = HW_READ( RX_TIME_CON1 );
/*MT6250*/         }
   #else
/*MT6256E2~*/      {
/*MT6256E2~*/         set->data[0] = HW_READ( RX_CON0 );
/*MT6256E2~*/         set->data[1] = HW_READ( RX_TIME_CON0 );
/*MT6256E2~*/         set->data[2] = HW_READ( RX_TIME_CON1 );
/*MT6256E2~*/         set->data[3] = HW_READ( RX_MON );
/*MT6256E2~*/      }
   #endif
#elif IS_CHIP_MT6227
/*MT6227*/         {
/*MT6227*/            set->data[0] = HW_READ( RX_CFG );
/*MT6227*/            set->data[1] = HW_READ( RX_CON );
/*MT6227*/            set->data[2] = HW_READ( BBRX_AC_CON );
/*MT6227*/         }
#elif IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223 || IS_CHIP_MT6253
/*MT6223,MT6225~*/ {
/*MT6223,MT6225~*/    set->data[0] = HW_READ( RX_CFG );
/*MT6223,MT6225~*/    set->data[1] = HW_READ( RX_CON );
/*MT6223,MT6225~*/    set->data[2] = HW_READ( BBRX_AC_CON );
/*MT6223,MT6225~*/    set->data[3] = HW_READ( RX_PM_CON   );
/*MT6223,MT6225~*/    set->data[4] = HW_READ( RX_FIR_CSID_CON );
/*MT6223,MT6225~*/ }
#elif IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/        {
/*MT6218~*/           set->data[0] = HW_READ( RX_CFG );
/*MT6218~*/           set->data[1] = HW_READ( RX_CON );
/*MT6218~*/           set->data[2] = HW_READ( BBRX_AC_CON );
/*MT6218~*/        }
#elif IS_BBTXRX_CHIP_DESIGN_VER_2
/*MT6276~*/        {
/*MT6276~*/           set->data[0] = HW_READ( RX_CFG );
/*MT6276~*/           set->data[1] = HW_READ( RX_CON );
/*MT6276~*/           set->data[2] = HW_READ( RX_CON1 );
/*MT6276~*/           set->data[3] = HW_READ( RX_PM_CON );
/*MT6276~*/           set->data[4] = HW_READ( RX_FIR_CSID_CON );
/*MT6276~*/        }
#elif IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
/*MT6238~*/        {
/*MT6238~*/           set->data[0] = HW_READ( RX_CFG );
/*MT6238~*/           set->data[1] = HW_READ( RX_CON );
/*MT6238~*/           set->data[2] = HW_READ( BBRX_AC_CON );
/*MT6238~*/           set->data[3] = HW_READ( RX_PM_CON   );
/*MT6238~*/           set->data[4] = HW_READ( RX_FIR_CSID_CON );
/*MT6238~*/        }
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION && !IS_CHIP_MT6223 && !IS_CHIP_MT6238 && !IS_CHIP_MT6253
/*MT6229~*/        {
/*MT6229~*/           set->data[0] = HW_READ( RX_CFG );
/*MT6229~*/           set->data[1] = HW_READ( RX_CON );
/*MT6229~*/           set->data[2] = HW_READ( BBRX_AC_CON );
/*MT6229~*/           set->data[3] = HW_READ( RX_PM_CON   );
/*MT6229~*/           set->data[4] = HW_READ( RX_FIR_CSID_CON );
/*MT6229~*/        }
#else
/*OTHERS*/         {
/*OTHERS*/            set->data[0] = HW_READ( RX_CFG );
/*OTHERS*/            set->data[1] = HW_READ( RX_CON );
/*OTHERS*/         }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_BFE_SET_RxRegisters( void *_set )
{
   BFERXSET *set = (BFERXSET *)_set;
#if IS_DLIF_CHIP
   #if IS_CHIP_MT6255
/*MT6255*/         {
/*MT6255*/            HW_WRITE( RX_CON0        , set->data[0] );
/*MT6255*/            HW_WRITE( RX_TIME_CON0   , set->data[1] );
/*MT6255*/            HW_WRITE( RX_TIME_CON1   , set->data[2] );
/*MT6255*/         }
   #elif IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
/*MT6256E1,MT6251*/{
/*MT6256E1,MT6251*/   HW_WRITE( RX_CON0        , set->data[0] );
/*MT6256E1,MT6251*/   HW_WRITE( RX_CON3        , set->data[1] );
/*MT6256E1,MT6251*/   HW_WRITE( IREST_CON0     , set->data[2] );
/*MT6256E1,MT6251*/   HW_WRITE( BFE_CON1       , set->data[3] );
/*MT6256E1,MT6251*/   HW_WRITE( RX_MON         , set->data[4] );
/*MT6256E1,MT6251*/}
   #elif IS_CHIP_MT6260 || IS_CHIP_MT6261
/*MT6260*/         {
/*MT6260*/            HW_WRITE( RX_CON0        , set->data[0] );
/*MT6260*/            HW_WRITE( RX_TIME_CON0   , set->data[1] );
/*MT6260*/            HW_WRITE( RX_TIME_CON1   , set->data[2] );
/*MT6260*/            HW_WRITE( RX_TIME_CON2   , set->data[3] );
/*MT6260*/         }
   #elif IS_CHIP_MT6250
/*MT6250*/         {
/*MT6250*/            HW_WRITE( RX_CON0        , set->data[0] );
/*MT6250*/            HW_WRITE( RX_TIME_CON0   , set->data[1] );
/*MT6250*/            HW_WRITE( RX_TIME_CON1   , set->data[2] );
/*MT6250*/         }
   #else
/*MT6256E2~*/      {
/*MT6256E2~*/         HW_WRITE( RX_CON0        , set->data[0] );
/*MT6256E2~*/         HW_WRITE( RX_TIME_CON0   , set->data[1] );
/*MT6256E2~*/         HW_WRITE( RX_TIME_CON1   , set->data[2] );
/*MT6256E2~*/         HW_WRITE( RX_MON         , set->data[3] );
/*MT6256E2~*/      }
   #endif
#elif IS_CHIP_MT6227
/*MT6227*/         {
/*MT6227*/            HW_WRITE( RX_CFG         , set->data[0] );
/*MT6227*/            HW_WRITE( RX_CON         , set->data[1] );
/*MT6227*/            HW_WRITE( BBRX_AC_CON    , set->data[2] );
/*MT6227*/         }
#elif IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223 || IS_CHIP_MT6253
/*MT6223,MT6225~*/ {
/*MT6223,MT6225~*/    HW_WRITE( RX_CFG         , set->data[0] );
/*MT6223,MT6225~*/    HW_WRITE( RX_CON         , set->data[1] );
/*MT6223,MT6225~*/    HW_WRITE( BBRX_AC_CON    , set->data[2] );
/*MT6223,MT6225~*/    HW_WRITE( RX_PM_CON      , set->data[3] );
/*MT6223,MT6225~*/    HW_WRITE( RX_FIR_CSID_CON, set->data[4] );
/*MT6223,MT6225~*/ }
#elif IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/        {
/*MT6218~*/           HW_WRITE( RX_CFG         , set->data[0] );
/*MT6218~*/           HW_WRITE( RX_CON         , set->data[1] );
/*MT6218~*/           HW_WRITE( BBRX_AC_CON    , set->data[2] );
/*MT6218~*/        }
#elif IS_BBTXRX_CHIP_DESIGN_VER_2
/*MT6276~*/        {
/*MT6276~*/           HW_WRITE( RX_CFG         , set->data[0] );
/*MT6276~*/           HW_WRITE( RX_CON         , set->data[1] );
/*MT6276~*/           HW_WRITE( RX_CON1        , set->data[2] );
/*MT6276~*/           HW_WRITE( RX_PM_CON      , set->data[3] );
/*MT6276~*/           HW_WRITE( RX_FIR_CSID_CON, set->data[4] );
/*MT6276~*/        }
#elif IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
/*MT6238~*/        {
/*MT6238~*/           HW_WRITE( RX_CFG         , set->data[0] );
/*MT6238~*/           HW_WRITE( RX_CON         , set->data[1] );
/*MT6238~*/           HW_WRITE( BBRX_AC_CON    , set->data[2] );
/*MT6238~*/           HW_WRITE( RX_PM_CON      , set->data[3] );
/*MT6238~*/           HW_WRITE( RX_FIR_CSID_CON, set->data[4] );
/*MT6238~*/        }
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION && !IS_CHIP_MT6223 && !IS_CHIP_MT6238 && !IS_CHIP_MT6253
/*MT6229~*/        {
/*MT6229~*/           HW_WRITE( RX_CFG         , set->data[0] );
/*MT6229~*/           HW_WRITE( RX_CON         , set->data[1] );
/*MT6229~*/           HW_WRITE( BBRX_AC_CON    , set->data[2] );
/*MT6229~*/           HW_WRITE( RX_PM_CON      , set->data[3] );
/*MT6229~*/           HW_WRITE( RX_FIR_CSID_CON, set->data[4] );
/*MT6229~*/        }
#else
/*OTHERS*/         {
/*OTHERS*/            HW_WRITE( RX_CFG         , set->data[0] );
/*OTHERS*/            HW_WRITE( RX_CON         , set->data[1] );
/*OTHERS*/         }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_BFE_GET_TxRegisters( void *_set )
{
   BFETXSET *set = (BFETXSET *)_set;
#if IS_DLIF_CHIP
   #if IS_CHIP_MT6255
/*MT6255*/         {
/*MT6255*/            set->data[0] = HW_READ( TX_CON0 );
/*MT6255*/            set->data[1] = HW_READ( TX_CON1 );
/*MT6255*/         }
   #elif IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
/*MT6256E1,MT6251*/{
/*MT6256E1,MT6251*/   set->data[0] = HW_READ( TX_CON0 );
/*MT6256E1,MT6251*/   set->data[1] = HW_READ( TX_CON1 );
/*MT6256E1,MT6251*/   set->data[2] = HW_READ( TX_PWR  );
/*MT6256E1,MT6251*/}
   #elif IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
/*MT6250*/         {
/*MT6250*/            set->data[0] = HW_READ( TX_CON0 );
/*MT6250*/            set->data[1] = HW_READ( TX_CON1 );
/*MT6250*/         }
   #else
/*MT6256E2~*/      {
/*MT6256E2~*/         set->data[0] = HW_READ( TX_CON0 );
/*MT6256E2~*/         set->data[1] = HW_READ( TX_CON1 );
/*MT6256E2~*/         set->data[2] = HW_READ( TX_CON2 );
/*MT6256E2~*/         set->data[3] = HW_READ( TX_PWR  );
/*MT6256E2~*/      }
   #endif
#elif IS_CHIP_MT6227
/*MT6227*/         {
/*MT6227*/            set->data[0] = HW_READ( TX_CFG );
/*MT6227*/            set->data[1] = HW_READ( TX_CON );
/*MT6227*/            set->data[2] = HW_READ( TX_OFF );
/*MT6227*/            set->data[3] = HW_READ( BBTX_AC_CON0 );
/*MT6227*/            set->data[4] = HW_READ( BBTX_AC_CON1 );
/*MT6227*/         }
#elif IS_CHIP_MT6252
/*MT6252*/         {
/*MT6252*/            set->data[0] = HW_READ( TX_CFG );
/*MT6252*/            set->data[1] = HW_READ( TX_CON );
/*MT6252*/            set->data[2] = HW_READ( TX_OFF );
/*MT6252*/         // phsel: 1's complement -> 2's before read out
/*MT6252*/            if(set->field.phsel & ((unsigned char)1<<(3-1)))
/*MT6252*/               set->field.phsel++;
/*MT6252*/         }
#elif IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223 || IS_CHIP_MT6253
/*MT6223,MT6225~*/ {
/*MT6223,MT6225~*/    set->data[0] = HW_READ( TX_CFG );
/*MT6223,MT6225~*/    set->data[1] = HW_READ( TX_CON );
/*MT6223,MT6225~*/    set->data[2] = HW_READ( TX_OFF );
/*MT6223,MT6225~*/    set->data[3] = HW_READ( BBTX_AC_CON0 );
/*MT6223,MT6225~*/    set->data[4] = HW_READ( BBTX_AC_CON1 );
/*MT6223,MT6225~*/    set->data[5] = HW_READ( BBTX_AC_CON2 );
/*MT6223,MT6225~*/ // phsel: 1's complement -> 2's before read out
/*MT6223,MT6225~*/    if(set->field.phsel & ((unsigned char)1<<(3-1)))
/*MT6223,MT6225~*/       set->field.phsel++;
/*MT6223,MT6225~*/ }
#elif IS_CHIP_MT6218_AND_LATTER_VERSION
   #if defined(MT6228)
/*MT6228*/         {
/*MT6228*/            set->data[0] = HW_READ( TX_CFG );
      #if ( defined(MT6228_S00) ||  defined(MT6228_S01) )
/*MT6228_S00&01*/     set->data[1] = HW_READ( TX_CON );
      #else
/*MT6228_S02~*/       set->data[1] = HW_READ( TX_CON ) & 0xFFFE;
/*MT6228_S02~*/       set->data[1]|= ((HW_READ( TDMA_EVTENA(1) )&0x80)>>7)&0x1;
      #endif
/*MT6228*/            set->data[2] = HW_READ( TX_OFF );
/*MT6228*/            set->data[3] = HW_READ( BBTX_AC_CON0 );
/*MT6228*/            set->data[4] = HW_READ( BBTX_AC_CON1 );
/*MT6228*/         }
   #else
/*MT6218~*/        {
/*MT6218~*/           set->data[0] = HW_READ( TX_CFG );
/*MT6218~*/           set->data[1] = HW_READ( TX_CON );
/*MT6218~*/           set->data[2] = HW_READ( TX_OFF );
/*MT6218~*/           set->data[3] = HW_READ( BBTX_AC_CON0 );
/*MT6218~*/           set->data[4] = HW_READ( BBTX_AC_CON1 );
/*MT6218~*/        }
   #endif
#elif IS_BBTXRX_CHIP_DESIGN_VER_2
/*MT6276~*/        {
/*MT6276~*/           set->data[0] = HW_READ( TX_CFG   );
/*MT6276~*/           set->data[1] = HW_READ( TX_CFG1  );
/*MT6276~*/           set->data[2] = HW_READ( TX_CON   );
/*MT6276~*/           set->data[3] = HW_READ( TX_CON1  );
/*MT6276~*/           set->data[4] = HW_READ( TX_PH(0) );
/*MT6276~*/           set->data[5] = HW_READ( TX_GAIN(0)   );
/*MT6276~*/           set->data[6] = HW_READ( TX_OFFSET(0) );
   #if IS_CHIP_MT6575
/*MT6575 */           set->data[7] = HW_READ( BBTX_CON5    ) & 0x2000 ? 0x0000 : 0x1000; // only read CMV
   #else
/*MT6276~*/           set->data[7] = HW_READ( BBTX_CON5    ) & 0x3000; // only read CMV
   #endif
/*MT6276~*/        }
#elif IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
   #if IS_CHIP_MT6268
/*MT6268~*/        {
/*MT6268~*/           set->data[0] = HW_READ( TX_CFG );
/*MT6268~*/           set->data[1] = HW_READ( TX_CON );
/*MT6268~*/           set->data[2] = HW_READ( TX_OFF );
/*MT6268~*/           set->data[3] = HW_READ( BBTX_AC_CON0 );
/*MT6268~*/           set->data[4] = HW_READ( BBTX_AC_CON1 );
/*MT6268~*/           set->data[5] = HW_READ( BBTX_AC_CON2 );
/*MT6268~*/           set->data[6] = HW_READ( BBTX_AC_CON3 );
/*MT6268~*/           set->data[7] = HW_READ( BBTX_AC_CON4 );
/*MT6268~*/        // phsel: 1's complement -> 2's before read out
/*MT6268~*/           if(set->field.phsel & ((unsigned char)1<<(4-1)))
/*MT6268~*/              set->field.phsel++;
/*MT6268~*/           if (set->field.offi & ((signed char)1<<(6-1)))
/*MT6268~*/              set->field.offi = -( set->field.offi - ((signed char)1<<6));
/*MT6268~*/           else
/*MT6268~*/              set->field.offi = -( set->field.offi - ((signed char)0));
/*MT6268~*/           if (set->field.offq & ((signed char)1<<(6-1)))
/*MT6268~*/              set->field.offq = -( set->field.offq - ((signed char)1<<6));
/*MT6268~*/           else
/*MT6268~*/              set->field.offq = -( set->field.offq - ((signed char)0));
/*MT6268~*/        }
   #elif IS_CHIP_MT6516 || IS_CHIP_MT6236
/*MT6516~*/        {
/*MT6516~*/           set->data[0] = HW_READ( TX_CFG );
/*MT6516~*/           set->data[1] = HW_READ( TX_CON );
/*MT6516~*/           set->data[2] = HW_READ( TX_OFF );
/*MT6516~*/           set->data[3] = HW_READ( BBTX_AC_CON0 );
/*MT6516~*/           set->data[4] = HW_READ( BBTX_AC_CON1 );
/*MT6516~*/           set->data[5] = HW_READ( BBTX_AC_CON2 );
/*MT6516~*/        // phsel: 1's complement -> 2's before read out
/*MT6516~*/           if(set->field.phsel & ((unsigned char)1<<(4-1)))
/*MT6516~*/              set->field.phsel++;
/*MT6516~*/           if (set->field.offi & ((signed char)1<<(6-1)))
/*MT6516~*/              set->field.offi = -( set->field.offi - ((signed char)1<<6));
/*MT6516~*/           else
/*MT6516~*/              set->field.offi = -( set->field.offi - ((signed char)0));
/*MT6516~*/           if (set->field.offq & ((signed char)1<<(6-1)))
/*MT6516~*/              set->field.offq = -( set->field.offq - ((signed char)1<<6));
/*MT6516~*/           else
/*MT6516~*/              set->field.offq = -( set->field.offq - ((signed char)0));
/*MT6516~*/        }
   #else
/*MT6238~*/        {
/*MT6238~*/           set->data[0] = HW_READ( TX_CFG );
/*MT6238~*/           set->data[1] = HW_READ( TX_CON );
/*MT6238~*/           set->data[2] = HW_READ( TX_OFF );
/*MT6238~*/           set->data[3] = HW_READ( BBTX_AC_CON0 );
/*MT6238~*/           set->data[4] = HW_READ( BBTX_AC_CON1 );
/*MT6238~*/           set->data[5] = HW_READ( BBTX_AC_CON2 );
/*MT6238~*/        // phsel: 1's complement -> 2's before read out
/*MT6238~*/           if(set->field.phsel & ((unsigned char)1<<(4-1)))
/*MT6238~*/              set->field.phsel++;
/*MT6238~*/        }
   #endif
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION && !IS_CHIP_MT6223 && !IS_CHIP_MT6238 && !IS_CHIP_MT6253
/*MT6229_S00*/     {
/*MT6229_S00*/        set->data[0] = HW_READ( TX_CFG );
   #if IS_CHIP_MT6229_S00 || IS_CHIP_MT6268T
/*MT6229_S00*/        set->data[1] = HW_READ( TX_CON );
   #else
/*MT6229_S01*/        set->data[1] = HW_READ( TX_CON ) & 0xFFFE;
/*MT6229_S01*/        set->data[1]|= ((HW_READ( TDMA_EVTENA(1) )&0x80)>>7)&0x1;
   #endif
/*MT6229_S00*/        set->data[2] = HW_READ( TX_OFF );
/*MT6229_S00*/        set->data[3] = HW_READ( BBTX_AC_CON0 );
/*MT6229_S00*/        set->data[4] = HW_READ( BBTX_AC_CON1 );
/*MT6229_S00*/     // phsel: 1's complement -> 2's before read out
/*MT6229_S00*/        if(set->field.phsel & ((unsigned char)1<<(3-1)))
/*MT6229_S00*/           set->field.phsel++;
/*MT6229_S00*/     }
#else
/*OTHERS*/         {
/*OTHERS*/            set->data[0] = HW_READ( TX_CFG );
/*OTHERS*/            set->data[1] = HW_READ( TX_CON );
/*OTHERS*/            set->data[2] = HW_READ( TX_OFFI );
/*OTHERS*/            set->data[3] = HW_READ( TX_OFFQ );
/*OTHERS*/         }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_BFE_SET_TxRegisters( void *_set )
{
   BFETXSET *set = (BFETXSET *)_set;

#if defined(L1D_TEST) && !IS_DLIF_CHIP
   set->field.iqswap = 0;
#endif

#if IS_DLIF_CHIP
   #if IS_CHIP_MT6255
/*MT6255*/         {  HW_WRITE( TX_CON0     , set->data[0] );
/*MT6255*/            HW_WRITE( TX_CON1     , set->data[1] );
/*MT6255*/         }
   #elif IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
/*MT6256E1,MT6251*/{  HW_WRITE( TX_CON0     , set->data[0] );
/*MT6256E1,MT6251*/   HW_WRITE( TX_CON1     , set->data[1] );
/*MT6256E1,MT6251*/   HW_WRITE( TX_PWR      , set->data[2] );
/*MT6256E1,MT6251*/}
   #elif IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
/*MT6250*/         {  HW_WRITE( TX_CON0     , set->data[0] );
/*MT6250*/            HW_WRITE( TX_CON1     , set->data[1] );
/*MT6250*/         }
   #else
/*MT6256E2~*/      {  HW_WRITE( TX_CON0     , set->data[0] );
/*MT6256E2~*/         HW_WRITE( TX_CON1     , set->data[1] );
/*MT6256E2~*/         HW_WRITE( TX_CON2     , set->data[2] );
/*MT6256E2~*/         HW_WRITE( TX_PWR      , set->data[3] );
/*MT6256E2~*/      }
   #endif
#elif IS_CHIP_MT6227
/*MT6227*/         {  HW_WRITE( TX_CFG      , set->data[0] );
/*MT6227*/            HW_WRITE( TX_CON      , set->data[1] );
/*MT6227*/            HW_WRITE( TX_OFF      , set->data[2] );
/*MT6227*/            HW_WRITE( BBTX_AC_CON0, set->data[3] );
/*MT6227*/            HW_WRITE( BBTX_AC_CON1, set->data[4] );
/*MT6227*/         }
#elif IS_CHIP_MT6252
/*MT6252*/         // phsel: 2's complement -> 1's before write in
/*MT6252*/         {  if(set->field.phsel & ((unsigned char)1<<(3-1)))
/*MT6252*/               set->field.phsel--;
/*MT6252*/            HW_WRITE( TX_CFG      , set->data[0] );
/*MT6252*/            HW_WRITE( TX_CON      , set->data[1] );
/*MT6252*/            HW_WRITE( TX_OFF      , set->data[2] );
/*MT6252*/         }
#elif IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223 || IS_CHIP_MT6253
/*MT6223,MT6225~*/ // phsel: 2's complement -> 1's before write in
/*MT6223,MT6225~*/ {  if(set->field.phsel & ((unsigned char)1<<(3-1)))
/*MT6223,MT6225~*/       set->field.phsel--;
/*MT6223,MT6225~*/    HW_WRITE( TX_CFG      , set->data[0] );
/*MT6223,MT6225~*/    HW_WRITE( TX_CON      , set->data[1] );
/*MT6223,MT6225~*/    HW_WRITE( TX_OFF      , set->data[2] );
/*MT6223,MT6225~*/    HW_WRITE( BBTX_AC_CON0, set->data[3] );
/*MT6223,MT6225~*/    HW_WRITE( BBTX_AC_CON1, set->data[4] );
/*MT6223,MT6225~*/    HW_WRITE( BBTX_AC_CON2, set->data[5] );
/*MT6223,MT6225~*/ }
#elif IS_CHIP_MT6218_AND_LATTER_VERSION
   #if defined(MT6228)
/*MT6228_S00&01*/  {  HW_WRITE( TX_CFG      , set->data[0] );
/*MT6228_S00&01*/     HW_WRITE( TX_CON      , set->data[1] );
      #if ( defined(MT6228_S00) || defined(MT6228_S01) )
      #else
/*MT6228_S02~*/       HW_WRITE( TDMA_EVTENA(1),
/*MT6228_S02~*/     ( HW_READ( TDMA_EVTENA(1) )&0xFF7F)|(( set->data[1]<<7)&0x0080));
      #endif
/*MT6228_S00&01*/     HW_WRITE( TX_OFF      , set->data[2] );
/*MT6228_S00&01*/     HW_WRITE( BBTX_AC_CON0, set->data[3] );
/*MT6228_S00&01*/     HW_WRITE( BBTX_AC_CON1, set->data[4] );
/*MT6228_S00&01*/  }
   #else
/*MT6218~*/        {  HW_WRITE( TX_CFG      , set->data[0] );
/*MT6218~*/           HW_WRITE( TX_CON      , set->data[1] );
/*MT6218~*/           HW_WRITE( TX_OFF      , set->data[2] );
/*MT6218~*/           HW_WRITE( BBTX_AC_CON0, set->data[3] );
/*MT6218~*/           HW_WRITE( BBTX_AC_CON1, set->data[4] );
/*MT6218~*/        }
   #endif
#elif IS_BBTXRX_CHIP_DESIGN_VER_2
/*MT6276~*/        {  unsigned short d16 = HW_READ( BBTX_CON5 ) & (~0x3000);
   #if IS_CHIP_MT6575
/*MT6575 */                          d16|= ((~set->field.cmv)&0x1) << 13;
/*MT6575 */                          d16|= 0x000C; // set TX low power mode
   #else
/*MT6276~*/                          d16|= set->field.cmv << 12;
   #endif
/*MT6276~*/           HW_WRITE( BBTX_CON5   , d16          ); // only write CMV
/*MT6276~*/           HW_WRITE( TX_CFG      , set->data[0] );
/*MT6276~*/           HW_WRITE( TX_CFG1     , set->data[1] );
/*MT6276~*/           HW_WRITE( TX_CON      , set->data[2] );
/*MT6276~*/           HW_WRITE( TX_CON1     , set->data[3] );
/*MT6276~*/           HW_WRITE_TX_PH(         set->data[4] );
/*MT6276~*/           HW_WRITE_TX_GAIN(       set->data[5] );
/*MT6276~*/           HW_WRITE_TX_OFF(        set->data[6] );
/*MT6276~*/        }
#elif IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
   #if IS_CHIP_MT6268
/*MT6268~*/        // phsel: 2's complement -> 1's before write in
/*MT6268~*/        {  signed char TxOffsetI=set->field.offi;
/*MT6268~*/           signed char TxOffsetQ=set->field.offq;
/*MT6268~*/           if(set->field.phsel & ((unsigned char)1<<(4-1)))
/*MT6268~*/              set->field.phsel--;
/*MT6268~*/           if (set->field.offi & ((signed char)1<<(6-1)))
/*MT6268~*/              set->field.offi = -( set->field.offi - ((signed char)1<<6));
/*MT6268~*/           else
/*MT6268~*/              set->field.offi = -( set->field.offi - ((signed char)0));
/*MT6268~*/           if (set->field.offq & ((signed char)1<<(6-1)))
/*MT6268~*/              set->field.offq = -( set->field.offq - ((signed char)1<<6));
/*MT6268~*/           else
/*MT6268~*/              set->field.offq = -( set->field.offq - ((signed char)0));
/*MT6268~*/           HW_WRITE( TX_CFG      , set->data[0] );
/*MT6268~*/           HW_WRITE( TX_CON      , set->data[1] );
/*MT6268~*/           HW_WRITE( TX_OFF      , set->data[2] );
/*MT6268~*/           HW_WRITE( BBTX_AC_CON0, set->data[3] );
/*MT6268~*/           HW_WRITE( BBTX_AC_CON1, set->data[4] );
/*MT6268~*/           HW_WRITE( BBTX_AC_CON2, set->data[5] );
/*MT6268~*/           HW_WRITE( BBTX_AC_CON3, set->data[6] );
/*MT6268~*/           HW_WRITE( BBTX_AC_CON4, set->data[7] );
/*MT6268~*/           set->field.offi=TxOffsetI;
/*MT6268~*/           set->field.offq=TxOffsetQ;
/*MT6268~*/        }
   #elif IS_CHIP_MT6516 || IS_CHIP_MT6236
/*MT6516~*/        // phsel: 2's complement -> 1's before write in
/*MT6516~*/        {  signed char TxOffsetI=set->field.offi;
/*MT6516~*/           signed char TxOffsetQ=set->field.offq;
/*MT6516~*/           if(set->field.phsel & ((unsigned char)1<<(4-1)))
/*MT6516~*/              set->field.phsel--;
/*MT6516~*/           if (set->field.offi & ((signed char)1<<(6-1)))
/*MT6516~*/              set->field.offi = -( set->field.offi - ((signed char)1<<6));
/*MT6516~*/           else
/*MT6516~*/              set->field.offi = -( set->field.offi - ((signed char)0));
/*MT6516~*/           if (set->field.offq & ((signed char)1<<(6-1)))
/*MT6516~*/              set->field.offq = -( set->field.offq - ((signed char)1<<6));
/*MT6516~*/           else
/*MT6516~*/              set->field.offq = -( set->field.offq - ((signed char)0));
/*MT6516~*/           HW_WRITE( TX_CFG      , set->data[0] );
/*MT6516~*/           HW_WRITE( TX_CON      , set->data[1] );
/*MT6516~*/           HW_WRITE( TX_OFF      , set->data[2] );
/*MT6516~*/           HW_WRITE( BBTX_AC_CON0, set->data[3] );
/*MT6516~*/           HW_WRITE( BBTX_AC_CON1, set->data[4] );
/*MT6516~*/           HW_WRITE( BBTX_AC_CON2, set->data[5] );
/*MT6516~*/           set->field.offi=TxOffsetI;
/*MT6516~*/           set->field.offq=TxOffsetQ;
/*MT6516~*/        }
   #else
/*MT6238~*/        // phsel: 2's complement -> 1's before write in
/*MT6238~*/        {  if(set->field.phsel & ((unsigned char)1<<(4-1)))
/*MT6238~*/              set->field.phsel--;
/*MT6238~*/           HW_WRITE( TX_CFG      , set->data[0] );
/*MT6238~*/           HW_WRITE( TX_CON      , set->data[1] );
/*MT6238~*/           HW_WRITE( TX_OFF      , set->data[2] );
/*MT6238~*/           HW_WRITE( BBTX_AC_CON0, set->data[3] );
/*MT6238~*/           HW_WRITE( BBTX_AC_CON1, set->data[4] );
/*MT6238~*/           HW_WRITE( BBTX_AC_CON2, set->data[5] );
/*MT6238~*/        }
   #endif
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION && !IS_CHIP_MT6223 && !IS_CHIP_MT6238 && !IS_CHIP_MT6253 && !IS_CHIP_MT6256 && !IS_CHIP_MT6251 && !IS_CHIP_MT6255 && !IS_CHIP_MT6250 && !IS_CHIP_MT6260 && !IS_CHIP_MT6261
/*MT6229_S00*/     // phsel: 2's complement -> 1's before write in
/*MT6229_S00*/     {  if(set->field.phsel & ((unsigned char)1<<(3-1)))
/*MT6229_S00*/           set->field.phsel--;
/*MT6229_S00*/        HW_WRITE( TX_CFG      , set->data[0] );
/*MT6229_S00*/        HW_WRITE( TX_CON      , set->data[1] );
   #if IS_CHIP_MT6229_S00 || IS_CHIP_MT6268T
   #else
/*MT6229_S01*/        HW_WRITE( TDMA_EVTENA(1),
/*MT6229_S01*/      ( HW_READ( TDMA_EVTENA(1) )&0xFF7F)|(( set->data[1]<<7)&0x0080));
   #endif
/*MT6229_S00*/        HW_WRITE( TX_OFF      , set->data[2] );
/*MT6229_S00*/        HW_WRITE( BBTX_AC_CON0, set->data[3] );
/*MT6229_S00*/        HW_WRITE( BBTX_AC_CON1, set->data[4] );
/*MT6229_S00*/     }
#else
/*OTHERS*/         {  HW_WRITE( TX_CFG , set->data[0] );
/*OTHERS*/            HW_WRITE( TX_CON , set->data[1] );
/*OTHERS*/            HW_WRITE( TX_OFFI, set->data[2] );
/*OTHERS*/            HW_WRITE( TX_OFFQ, set->data[3] );
/*OTHERS*/         }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define IQSWAP_BIT   0x0001
#else
#define IQSWAP_BIT   0x0200
#endif

void L1D_BFE_SET_TxIQSwapRegister( int is_swap )
{
#if defined(L1D_TEST)   // For L1D_TEST, always turn off IQSWAP
   (void)is_swap;
#elif IS_DLIF_CHIP
   (void)is_swap;
#else
   unsigned short d16;

   d16 = HW_READ( TX_CON );
   if( is_swap )
      d16 |=  IQSWAP_BIT;
   else
      d16 &= ~IQSWAP_BIT;
   HW_WRITE( TX_CON, d16 );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
void L1D_RF_TXIQ_Dynamic_Config( void )
{
   #if IS_RF_MT6140B || IS_RF_MT6140C || IS_RF_MT6140D || IS_RF_CMOSEDGE || IS_RF_MTKSOC1T || IS_RF_MTKSOC1 || IS_RF_MT6252RF
   l1d_rf.d2c_txiqconfig = 1;
   #else
   l1d_rf.d2c_txiqconfig = 0;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_DLIF_CHIP
void L1D_BFE_SetTxIQ_Config( void )
{
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
void L1D_BFE_SetTxIQ_Config( void )
{
   BFETXSET  bfetxset;

   HW_READ_BFETXSET( bfetxset );

   if(l1d_rf.band<=2) //Low band
   {
   #if IS_CHIP_MT6252
      bfetxset.field.offi       = BBTXParameters.bbtx_offsetI;
      bfetxset.field.offq       = BBTXParameters.bbtx_offsetQ;
      bfetxset.field.phsel      = BBTXParameters.bbtx_phsel;
   #elif IS_BBTXRX_CHIP_DESIGN_VER_2
      bfetxset.field.cmv        = BBTXParameters.bbtx_common_mode_voltage;
      bfetxset.field.offi       = DC_OFFSET_TO_OFFSET( BBTXParameters.bbtx_offsetI, BBTXParameters.bbtx_dccoarseI );
      bfetxset.field.offq       = DC_OFFSET_TO_OFFSET( BBTXParameters.bbtx_offsetQ, BBTXParameters.bbtx_dccoarseQ );
      bfetxset.field.gain_comp  = TRIM_IQ_TO_GAIN_COMP( BBTXParameters.bbtx_trimI, BBTXParameters.bbtx_trimQ );
      bfetxset.field.iqgain_sel = TRIM_IQ_TO_GAIN_SEL( BBTXParameters.bbtx_trimI, BBTXParameters.bbtx_trimQ );
      bfetxset.field.phseli     = PHASE_COMP_TO_PHSEL_I( BBTXParameters.bbtx_phsel );
      bfetxset.field.phselq     = PHASE_COMP_TO_PHSEL_Q( BBTXParameters.bbtx_phsel );
   #else
      bfetxset.field.trimi      = BBTXParameters.bbtx_trimI;
      bfetxset.field.trimq      = BBTXParameters.bbtx_trimQ;
      bfetxset.field.offi       = BBTXParameters.bbtx_offsetI;
      bfetxset.field.offq       = BBTXParameters.bbtx_offsetQ;
      bfetxset.field.gain       = BBTXParameters.bbtx_gain;
      bfetxset.field.cmv        = BBTXParameters.bbtx_common_mode_voltage;
      bfetxset.field.calrcsel   = BBTXParameters.bbtx_calrcsel;
      bfetxset.field.phsel      = BBTXParameters.bbtx_phsel;
      #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION // 23 may use MT6140D
      bfetxset.field.dccoarsei  = BBTXParameters.bbtx_dccoarseI;
      bfetxset.field.dccoarseq  = BBTXParameters.bbtx_dccoarseQ;
      #endif
   #endif
   }
   else   //High band
   {
   #if IS_CHIP_MT6252
      bfetxset.field.offi       = BBTXParameters.bbtx_offsetI_h;
      bfetxset.field.offq       = BBTXParameters.bbtx_offsetQ_h;
      bfetxset.field.phsel      = BBTXParameters.bbtx_phsel_h;
   #elif IS_BBTXRX_CHIP_DESIGN_VER_2
      bfetxset.field.cmv        = BBTXParameters.bbtx_common_mode_voltage_h;
      bfetxset.field.offi       = DC_OFFSET_TO_OFFSET( BBTXParameters.bbtx_offsetI_h, BBTXParameters.bbtx_dccoarseI_h );
      bfetxset.field.offq       = DC_OFFSET_TO_OFFSET( BBTXParameters.bbtx_offsetQ_h, BBTXParameters.bbtx_dccoarseQ_h );
      bfetxset.field.gain_comp  = TRIM_IQ_TO_GAIN_COMP( BBTXParameters.bbtx_trimI_h, BBTXParameters.bbtx_trimQ_h );
      bfetxset.field.iqgain_sel = TRIM_IQ_TO_GAIN_SEL( BBTXParameters.bbtx_trimI_h, BBTXParameters.bbtx_trimQ_h );
      bfetxset.field.phseli     = PHASE_COMP_TO_PHSEL_I( BBTXParameters.bbtx_phsel_h );
      bfetxset.field.phselq     = PHASE_COMP_TO_PHSEL_Q( BBTXParameters.bbtx_phsel_h );
   #else
      bfetxset.field.trimi      = BBTXParameters.bbtx_trimI_h;
      bfetxset.field.trimq      = BBTXParameters.bbtx_trimQ_h;
      bfetxset.field.offi       = BBTXParameters.bbtx_offsetI_h;
      bfetxset.field.offq       = BBTXParameters.bbtx_offsetQ_h;
      bfetxset.field.gain       = BBTXParameters.bbtx_gain_h;
      bfetxset.field.cmv        = BBTXParameters.bbtx_common_mode_voltage_h;
      bfetxset.field.calrcsel   = BBTXParameters.bbtx_calrcsel_h;
      bfetxset.field.phsel      = BBTXParameters.bbtx_phsel_h;
      #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION // 23 may use MT6140D
      bfetxset.field.dccoarsei  = BBTXParameters.bbtx_dccoarseI_h;
      bfetxset.field.dccoarseq  = BBTXParameters.bbtx_dccoarseQ_h;
      #endif
   #endif
   }

   HW_WRITE_BFETXSET( bfetxset );
   l1d_rf.old_band=l1d_rf.band;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_RF_MTKSOC1T || IS_RF_MTKSOC1 || IS_RF_MT6252RF
void L1D_SetTxIQSwap_NO_PCS1900( void )
{
   BFETXSET  bfetxset;

   HW_READ_BFETXSET( bfetxset );

   if(l1d_rf.band == FrequencyBand1900)
      bfetxset.field.iqswap = ~(BBTX_IQ_SWAP) & 0x1; // TX don't swap high side down mixing
   else
      bfetxset.field.iqswap =  (BBTX_IQ_SWAP) & 0x1;

   HW_WRITE_BFETXSET( bfetxset );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

void L1D_AFCDAC_On( void )
{
#if IS_AST_B2S_SUPPORT
   /* do nothing */
#elif IS_AFC_EVENT_ENABLE
   #if defined(AFC_VCXO)
   unsigned short d16;
      #if IS_RF_AD6548 || IS_RF_AD6546
         #if !( IS_BT_CO_CLOCK_HW_SUPPORT && IS_BT_COCLOCK_SUPPORT )
   L1D_RF_CAP_Set();
         #endif
      #endif

   if( !IS_AFC_TRIGGER_BSI() )
   {
      HW_WRITE( AFC_PUPER, TQ_Afc_ChargeInIdle );
      d16  = HW_READ( AFC_CON );
      d16 |= AFC_FORCE_POWER_ON;
      HW_WRITE( AFC_CON, d16 );
   }
   #endif
#endif
   L1D_AfterSleep();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_AFCDAC_Off( void )
{
#if IS_AST_B2S_SUPPORT
   /* do nothing */
#elif IS_AFC_EVENT_ENABLE
   #if defined(AFC_VCXO)
   unsigned short d16;

   d16 = HW_READ( AFC_CON );
   d16 &= ~AFC_FORCE_POWER_ON;
   HW_WRITE( AFC_CON, d16 );
   HW_WRITE( AFC_PUPER, 0 );           /* For AFC SW power down bit PDN_CON2[4]/PDN_CON4[4] is malfunction */
                                       /* This HW bug is fixed in MT6227 and MT6225 */
      #if IS_RF_AD6548 || IS_RF_AD6546
         #if !( IS_BT_CO_CLOCK_HW_SUPPORT && IS_BT_COCLOCK_SUPPORT )
   L1D_RF_CAP_Clear();
         #endif
      #endif
   #endif

   #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__) // MTK 3G
/* under construction !*/
      #if IS_CHIP_MT6268A
/* under construction !*/
      #endif
   #endif
#endif
   L1D_BeforeSleep();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned long L1D_RF_GetITC_PCL( void ) /* For META 2 range PCL calibration*/
{
#if IS_EPSK_TX_SUPPORT
   #if IS_RF_MT6140D
   extern unsigned short LB_CW_High_Idx;
   extern unsigned short HB_CW_High_Idx;
   return (((15-HB_CW_High_Idx) <<16)|(19-LB_CW_High_Idx));
   #else
   return 0xFFFFFFFF;
   #endif
#else //add a return value for removing compile warning.
   return 0xFFFFFFFF;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*=======================================================================================================*/
/* short  L1D_RF_GetTxPAVBias_TxITC(  unsigned short lb_cw_high_idx, unsigned short hb_cw_high_idx )     */
/*=======================================================================================================*/
/* lb_cw_high_idx      : Low  band PCL switch point                                                      */
/* hb_cw_high_idx      : High band PCL switch point                                                      */
/* return              : PA Vbias                                                                        */
/* ----------------------------------------------------------------------------------------------------- */

unsigned short L1D_RF_GetTxPAVBias_TxITC( unsigned short lb_cw_high_idx, unsigned short hb_cw_high_idx )
{
#if IS_EPSK_TX_SUPPORT
   #if IS_RF_MT6140D
   const  pa_vbias *ofs_ptr;
   unsigned short   pcl2idx;
   unsigned char    pa_vbias, is_new_cw;
   unsigned short   idx;
      #if IS_FHC_SUPPORT
   if( l1d_rf.fhc_proc == FHC_PROC_UTS_DAC )
   {
      pa_vbias = l1d_rf.fhc_vbias[l1d_rf.cur_slot];
      is_new_cw = l1d_rf.fhc_is_low_pcl[l1d_rf.cur_slot];
   }
   else
      #endif
   {
      idx = (l1d_rf2.tx_power[l1d_rf.cur_slot]-LOWEST_TX_POWER[l1d_rf.band])/2;
      /* Get PCL index section */
      if(l1d_rf.band>2)
      {
         ofs_ptr = (l1d_rf.band==3)? RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias : RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias;
         is_new_cw=(idx<hb_cw_high_idx)? 1:0;
         pcl2idx=15;
      }
      else
      {
         ofs_ptr = (l1d_rf.band==1)?RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias : RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias;
         is_new_cw=(idx<lb_cw_high_idx)? 1:0;
         pcl2idx=19;
      }

      while( (ofs_ptr->pcl_index>=0))
      {  if((idx)>=(pcl2idx-ofs_ptr->pcl_index))
         {  break;
         }
         ofs_ptr++;
      }
      pa_vbias = ofs_ptr->pa_vbias;
   }
   return( (pa_vbias&0x7)|((is_new_cw)&0x1)<<4 );
   #else
   return 0;
   #endif //IS_RF_MT6140D
#else
   return 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

short L1D_RF_GetTxPAVBias( void )
{
#if IS_EPSK_TX_SUPPORT
   #if IS_RF_MT6162
   pa_vbias *ofs_ptr;
   unsigned short   idx;
   int i, size;

   if( l1d_rf.band <= FrequencyBand900 )
      idx = 19-(l1d_rf2.tx_power[l1d_rf.cur_slot_n]-LOWEST_TX_POWER[l1d_rf.band])/2;
   else
      idx = 15-(l1d_rf2.tx_power[l1d_rf.cur_slot_n]-LOWEST_TX_POWER[l1d_rf.band])/2;

   switch( l1d_rf.band )
   {
      case FrequencyBand850:
         ofs_ptr = RFSpecialCoef.tx.mt6162tx.data.GSM850_pa_vbias;
         size = sizeof(RFSpecialCoef.tx.mt6162tx.data.GSM850_pa_vbias) / sizeof(pa_vbias);
         break;
      case FrequencyBand900:
         ofs_ptr = RFSpecialCoef.tx.mt6162tx.data.GSM900_pa_vbias;
         size = sizeof(RFSpecialCoef.tx.mt6162tx.data.GSM900_pa_vbias) / sizeof(pa_vbias);
         break;
      case FrequencyBand1800:
         ofs_ptr = RFSpecialCoef.tx.mt6162tx.data.DCS1800_pa_vbias;
         size = sizeof(RFSpecialCoef.tx.mt6162tx.data.DCS1800_pa_vbias) / sizeof(pa_vbias);
         break;
      case FrequencyBand1900:
      default:
         ofs_ptr = RFSpecialCoef.tx.mt6162tx.data.PCS1900_pa_vbias;
         size = sizeof(RFSpecialCoef.tx.mt6162tx.data.PCS1900_pa_vbias) / sizeof(pa_vbias);
   }
   for( i = 0; i < size-1; i++)
   {  if( idx <= ofs_ptr[i].pcl_index )
      {
         return ofs_ptr[i].pa_vbias*96; /* targeted APC_DAC(512) = 96*pa_vbias+APC_DC_OFFSET(128) */
      }
   }
   return ofs_ptr[size-1].pa_vbias*96;  /* targeted APC_DAC(512) = 96*pa_vbias+APC_DC_OFFSET(128) */

   #elif IS_RF_MT6256RF
   pa_vbias *ofs_ptr;
   unsigned short   idx;
   int i, size;

   if( l1d_rf.band <= FrequencyBand900 )
   {  idx = 19-(l1d_rf2.tx_power[l1d_rf.cur_slot_n]-LOWEST_TX_POWER[l1d_rf.band])/2;  }
   else
   {  idx = 15-(l1d_rf2.tx_power[l1d_rf.cur_slot_n]-LOWEST_TX_POWER[l1d_rf.band])/2;  }

   switch( l1d_rf.band )
   {
      case FrequencyBand850:
         ofs_ptr = RFSpecialCoef.tx.mt6256tx.data.GSM850_pa_vbias;
         size = sizeof(RFSpecialCoef.tx.mt6256tx.data.GSM850_pa_vbias) / sizeof(pa_vbias);
         break;
      case FrequencyBand900:
         ofs_ptr = RFSpecialCoef.tx.mt6256tx.data.GSM900_pa_vbias;
         size = sizeof(RFSpecialCoef.tx.mt6256tx.data.GSM900_pa_vbias) / sizeof(pa_vbias);
         break;
      case FrequencyBand1800:
         ofs_ptr = RFSpecialCoef.tx.mt6256tx.data.DCS1800_pa_vbias;
         size = sizeof(RFSpecialCoef.tx.mt6256tx.data.DCS1800_pa_vbias) / sizeof(pa_vbias);
         break;
      case FrequencyBand1900:
      default:
         ofs_ptr = RFSpecialCoef.tx.mt6256tx.data.PCS1900_pa_vbias;
         size = sizeof(RFSpecialCoef.tx.mt6256tx.data.PCS1900_pa_vbias) / sizeof(pa_vbias);
   }

   for( i = 0; i < size-1; i++)
   {  if( idx <= ofs_ptr[i].pcl_index )
      {  return ofs_ptr[i].pa_vbias*128; /* APC_DAC = pa_vbias*4*/  }
   }
   return ofs_ptr[size-1].pa_vbias*128; /* APC_DAC = pa_vbias*4*/

   #else
   return 0;
   #endif /*IS_RF_MT6256RF*/
#else
   return 0;
#endif /*IS_EPSK_TX_SUPPORT*/
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*=======================================================================================================*/
/* AMR QI fine tune  for RF chip                                                                         */
/*=======================================================================================================*/
#if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/* For SAIC AMR QI testing FTA14.10.3 and 14.10.4, could be fine tuned by PIX   */
#elif IS_CHIP_MT6227_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_RF_MT6129D
unsigned short  AMR_QI_FINE_TUNE = 233;
   #else
unsigned short  AMR_QI_FINE_TUNE = 256;
   #endif
#endif

/* ----------------------------------------------------------------------------------------------------- */

#if IS_RF_AD6546  // VIto for AD6546 Register8 calculation
/*AD6546*/  unsigned int AM_Loop_Calculate( void )
/*AD6546*/  {
/*AD6546*/  #if IS_EPSK_TX_SUPPORT
/*AD6546*/     int gama_level, slope_skew_value;
/*AD6546*/     signed char APC_CAP_DELTA, SLOPE_SKEW_DELTA;
/*AD6546*/     ad6546tx_reg8 Reg8;
/*AD6546*/
/*AD6546*/     Reg8.RegData = RFSpecialCoef.tx.ad6546tx.Reg8_default[l1d_rf.band -1];  // read default value (VGA_SLOPE is included)
/*AD6546*/     Reg8.AM_LOOP.AM_FB_DAC= RFSpecialCoef.tx.ad6546tx.CalData[l1d_rf.band -1].AM_FB_DAC;  // read calibrated AM_FB_DAC
/*AD6546*/     Reg8.AM_LOOP.REFDET_SLOPE_SKEW=  RFSpecialCoef.tx.ad6546tx.CalData[l1d_rf.band -1].REFDET_SLOPE_SKEW; // sign bit x -4 + normal bits value
/*AD6546*/
/*AD6546*/     if (((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)&&(l1d_rf.band > 2)) // Vito calculate APC_CAP & SLOPE delta for highband
/*AD6546*/     {
/*AD6546*/        gama_level = 15 - ((l1d_rf2.tx_power[l1d_rf.cur_slot]-LOWEST_TX_POWER[l1d_rf.band])/2);
/*AD6546*/        if (gama_level >= RFSpecialCoef.tx.ad6546tx.AMLoopDelta.MID_GAMA_THRESHOLD)  // delta for gama level > 8
/*AD6546*/        {
/*AD6546*/           slope_skew_value = Reg8.AM_LOOP.REFDET_SLOPE_SKEW; // sign bit x -4 + normal bits value // read calibrated SLOPE_SKEW if lowband
/*AD6546*/
/*AD6546*/           if ( slope_skew_value >= 8 )
/*AD6546*/              slope_skew_value = ( slope_skew_value & 0x7 ) - 4 ;
/*AD6546*/
/*AD6546*/           if (gama_level >= RFSpecialCoef.tx.ad6546tx.AMLoopDelta.LOW_GAMA_THRESHOLD)  //  delta for gama level > 12
/*AD6546*/           {
/*AD6546*/              APC_CAP_DELTA = RFSpecialCoef.tx.ad6546tx.AMLoopDelta.LOW_DELTA_APC_CAP;
/*AD6546*/              SLOPE_SKEW_DELTA = RFSpecialCoef.tx.ad6546tx.AMLoopDelta.LOW_DELTA_SLOPE_SKEW;
/*AD6546*/           }
/*AD6546*/           else
/*AD6546*/           {
/*AD6546*/              APC_CAP_DELTA = RFSpecialCoef.tx.ad6546tx.AMLoopDelta.MID_DELTA_APC_CAP;
/*AD6546*/              SLOPE_SKEW_DELTA = RFSpecialCoef.tx.ad6546tx.AMLoopDelta.MID_DELTA_SLOPE_SKEW;
/*AD6546*/           }
/*AD6546*/
/*AD6546*/           Reg8.AM_LOOP.POLAR_APC_CAP = (Reg8.AM_LOOP.POLAR_APC_CAP + APC_CAP_DELTA)>0x1F? 0x1F : (Reg8.AM_LOOP.POLAR_APC_CAP + APC_CAP_DELTA);// POLAR_APC_CAP
/*AD6546*/           slope_skew_value = ((slope_skew_value + SLOPE_SKEW_DELTA)<-4)? -4 : (slope_skew_value + SLOPE_SKEW_DELTA);
/*AD6546*/           if (slope_skew_value<0)
/*AD6546*/              Reg8.AM_LOOP.REFDET_SLOPE_SKEW = ( 0x8 |((slope_skew_value+4)&0x7) );  // REFDET_SLOPE_SKEW
/*AD6546*/           else
/*AD6546*/              Reg8.AM_LOOP.REFDET_SLOPE_SKEW = slope_skew_value;
/*AD6546*/        }
/*AD6546*/     }
/*AD6546*/     return Reg8.RegData;
/*AD6546*/  #else
/*AD6546*/     return RFSpecialCoef.tx.ad6546tx.Reg8_default[l1d_rf.band -1];
/*AD6546*/  #endif
/*AD6546*/  }
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

/*=======================================================================================================*/
/*  AFC linear compensation mechanism                                                                    */
/*=======================================================================================================*/

void XO_LC_Initialize( void )
{
#if IS_VCXO_LC_SUPPORT
   unsigned char *src, *dst;
   int  n;
   XO_SLOPE_AREA_DATA  *Curr_area, *Start_area, *End_area;

   Start_area=&(XO_SlopeAreaData[0]);
   End_area  =&(XO_SlopeAreaData[XO_SlopeArea_Num]);
   Curr_area =&(XO_SlopeAreaData[0]);

   /*Find Zero freq point as initial value*/
   while( Curr_area != End_area )
   {
      if( Curr_area->min_freq < 0 )
      {
         Curr_area--;
         XO_LC_TableParams.curr_idx= Curr_area - Start_area;
         break;
      }
      Curr_area++;
   }

   /*Find table ending point*/
   while( Curr_area != End_area )
   {
      if( ((Curr_area+1)->min_dac == -1) || (Curr_area == (End_area-1)) )
      {
         XO_LC_TableParams.first_element = Start_area;
         XO_LC_TableParams.last_element = Curr_area;
         break;
      }
      Curr_area++;
   }

   /*Check if Look-up table abnormal or not*/
   if( Curr_area == End_area )
   {
      XO_SET_FLAG(XO_LC_Flags, XO_LC_INIT_FAIL);
      return;
   }

   /*For Crystal ege effect, reduce 5% of AFC S-cuve first*/
   Curr_area = XO_LC_TableParams.first_element;
   End_area = XO_LC_TableParams.last_element+1;
   while( Curr_area != End_area )
   {
      Curr_area->min_freq = (Curr_area->min_freq)*RATIO_20_DIV_21 >> 7;
      Curr_area++;
   }

   {
      /* Backup the initial value of XO_SlopeAreaData for the following restore action */
      src = (unsigned char*)(XO_SlopeAreaData);
      dst = (unsigned char*)(XO_SlopeAreaData_ori);
      for( n=sizeof(XO_SLOPE_AREA_DATA)*XO_SlopeArea_Num; n>0; n--)
         *dst++ = *src++;
   }

   /*Initial related global variable for FB AFC*/
   afc_inv_slope = XO_LC_GetCurrentPhi_est();
   afc_dac_default = XO_LC_CalculateNewDacNBSB(0, 0);
   onek_hz_dac = (signed short int)((1200*afc_inv_slope)/ONE);

   #ifdef  __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif

#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void XO_LC_TuneAFCTable( signed int Ratio_ind )
{
#if IS_VCXO_LC_SUPPORT
   XO_SLOPE_AREA_DATA  *Curr_element, *table_end;
   signed int RATIO_FREQ = Ratio_ind > 0 ? RATIO_4_DIV_5 : RATIO_5_DIV_4;

   /*For Crystal ege effect, further adjust AFC S-cuve*/
   Curr_element = XO_LC_TableParams.first_element;
   table_end    = XO_LC_TableParams.last_element+1;
   while( Curr_element != table_end )
   {
      Curr_element->min_freq = (Curr_element->min_freq/PHI_Factor)*RATIO_FREQ >> 7;
      Curr_element++;
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

signed short int XO_LC_CalculateNewDacNBSB( signed int Current_Freq, signed short int Servingstarted )
{
#if IS_VCXO_LC_SUPPORT
   XO_SLOPE_AREA_DATA *target, *table_start, *table_end;
   signed int x, y, Inv_slope;

   table_start = XO_LC_TableParams.first_element;
   table_end = XO_LC_TableParams.last_element-1;
   target = table_start+XO_LC_TableParams.curr_idx;

   /*clipping frequency offset*/
   if ( Current_Freq > table_start->min_freq )
   {  Current_Freq = table_start->min_freq;
   }
   else if ( Current_Freq < (table_end+1)->min_freq )
   {  Current_Freq =(table_end+1)->min_freq;
   }

   /*Start Searching new DAC by current absulte frequency offset*/
   if( target->min_freq < Current_Freq )
   {
      while (!(( target->min_freq >= Current_Freq) && ((target+1)->min_freq < Current_Freq)) && (target != table_start))
      {
         target--;
      }
   }
   else
   {
      while (!(( target->min_freq >= Current_Freq) && ((target+1)->min_freq < Current_Freq)) && (target != table_end))
      {
         target++;
      }
   }

   /*Update initial index if it is serving cell for fasting next searching*/
   if( Servingstarted )
   {
      XO_LC_TableParams.curr_idx = target - table_start;
   }

   y= target->min_freq - (target+1)->min_freq;
   x= (target+1)->min_dac - target->min_dac;
   Inv_slope= ((x*0x10000+y/2)/y);

   return target->min_dac+(Inv_slope*(target->min_freq-Current_Freq))/0x10000;

#else
   return 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

signed int XO_LC_InitialPhiFactor( signed short int DacValue )
{
#if IS_VCXO_LC_SUPPORT
   XO_SLOPE_AREA_DATA  *target, *table_start, *table_end;
   signed int x, y, slope;

   table_start = XO_LC_TableParams.first_element;
   table_end = XO_LC_TableParams.last_element-1;
   target = table_start+XO_LC_TableParams.curr_idx;

   if( target->min_dac > DacValue )
   {
      while (!(( target->min_dac <= DacValue) && ((target+1)->min_dac > DacValue)) && (target != table_start))
      {
         target--;
      }
   }
   else
   {
      while (!(( target->min_dac <= DacValue) && ((target+1)->min_dac > DacValue)) && (target != table_end))
      {
         target++;
      }
   }

   y= target->min_freq - (target+1)->min_freq;
   x= (target+1)->min_dac - target->min_dac;
   slope= ((y*0x100+x/2)/x);

   return target->min_freq + (slope*( target->min_dac - DacValue ))/0x100;
#else
   return 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

signed int XO_LC_GetCurrentPhi_est( void )
{
#if IS_VCXO_LC_SUPPORT
   XO_SLOPE_AREA_DATA  *target = XO_LC_TableParams.first_element + XO_LC_TableParams.curr_idx;
   signed int x, y, Inv_slope;

   y= target->min_freq - (target+1)->min_freq;
   x= (target+1)->min_dac - target->min_dac;
   Inv_slope= ((x*0x20000+y/2)/y);

   return Inv_slope;
#else
   return 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static unsigned char L1D_RF_RefineTxMaxPowerDecrement( int tx_slot_cnt )
{
#if IS_DECREASE_RF_TX_MAX_POWER_SUPPORT
   if( IS_RF_TX_MAX_POWER_DECREASED() )
   {
      /* Unit of multi_slot_decre & l1d_rf.tx_power_decrement: 1/8 dB */
      unsigned char multi_slot_decre;

      switch( tx_slot_cnt )
      {
         case 1:
         {  multi_slot_decre =  0;  /* decrease 0 more dB */
            break;
         }
         case 2:
         {  multi_slot_decre = 24;  /* decrease 3 more dB */
            break;
         }
         case 3:
         {  multi_slot_decre = 38;  /* decrease 4.75 more dB */
            break;
         }
         case 4:
         {  multi_slot_decre = 48;  /* decrease 6 more dB */
            break;
         }
         case 5:
         {  multi_slot_decre = 56;  /* decrease 7 more dB */
            break;
         }
         default:
         {  return 0;  }
      }
      return l1d_rf.tx_power_decrement + multi_slot_decre;
   }
   else
#endif
   {  return 0;  }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*=======================================================================================================*/
/*  L1D_RF_PowerRollback                                                                                 */
/*=======================================================================================================*/
/*
Account:
   This function will rollback power for multislots. You can set reduced power value (dB, positive)
   to the number of multislots separately (2,3,4). Then, you will get power DAC value (positive) should be
   reduced by interpolation method. This function works on each PCL except min PCL.

Input :
   power_dbm: TX power. i.e. power_dbm = 30
   rf_band:   used band. i.e. GSM900 = 2
   Weight:    now used weight value. i.e. high_weight, low_weight

Output:
   Power DAC value should be reduced (positive)
*/
#if IS_GPRS
short L1D_RF_PowerRollback( short power_dbm, int rf_band, unsigned short weight, short mod_type)
{
   short  left_idx, right_idx, power_idx,max_power_idx, max_power = 0, i = 0;
   int  rollback_db = 0, decrement_db = 0;
   static const sRAMPDATA*  band;
   static char  lowest_dbm;
   short  result;
   sTX_POWER_ROLLBACK* tx_power_rollback = 0;

/* This function is only active at max power, LB max power is 33 dBm, HB max power is 30 dBm */
// if( (rf_band <= 2 && power_dbm != 33) || (rf_band > 2 && power_dbm != 30) )
//    return 0;

// Find MAX power level index GMSK(LB33 dbm, HB30dBm), 8PSK(LB 27dbm, HB 26dBm)
   if(mod_type == 0)
   {/*GMSK*/
      if(rf_band <= FrequencyBand900)
      {/*LB*/
         max_power = GMSK_LB_MAX_POWER;
      }
      else
      {/*HB*/
         max_power = GMSK_HB_MAX_POWER;
      }
      tx_power_rollback = tx_power_rollback_gmsk[rf_band];
      band = RampData[rf_band];
   }
   #if IS_EPSK_TX_SUPPORT /*need to modify with tx_power_rollback_epsk*/
   else
   {/*EPSK*/
      if(rf_band <= FrequencyBand900)
      {/*LB*/
         max_power = EPSK_LB_MAX_POWER;
      }
      else
      {/*HB*/
         max_power = EPSK_HB_MAX_POWER;
      }
      tx_power_rollback = tx_power_rollback_epsk[rf_band];
      band = RampData_EPSK[rf_band];
   }
   #endif

   if( max_power==0 || tx_power_rollback==0 )
   {  /*Chuwei: mod_type error or memory corruption*/
      return 0;
   }

   lowest_dbm = LOWEST_TX_POWER[(int)rf_band];
   max_power_idx = (max_power-lowest_dbm)/2;
   power_idx = (power_dbm-lowest_dbm)/2;

   /*If exceed array "band->power" range, return 0 */
   if( power_idx <= 0 )
      return 0;

   /*choose rollback value by # of TX slots*/
   i  = (l1d_rf.tx_slots)    & 0x1;
   i += (l1d_rf.tx_slots>>1) & 0x1;
   i += (l1d_rf.tx_slots>>2) & 0x1;
   i += (l1d_rf.tx_slots>>3) & 0x1;
   i += (l1d_rf.tx_slots>>4) & 0x1;
   switch (i)
   {
      case 2:
         rollback_db = tx_power_rollback->rollback_2t;
         break;
      case 3:
         rollback_db = tx_power_rollback->rollback_3t;
         break;
      case 4:
         rollback_db = tx_power_rollback->rollback_4t;
         break;
      case 5:
         rollback_db = tx_power_rollback->rollback_5t;
         break;
      default:
      {
         if( IS_RF_TX_MAX_POWER_DECREASED() )
         {  rollback_db = 0;  }
         else
         {  return 0;  }
      }
   }

   /*Check the request of TX max power decrement from upper layers*/
   decrement_db = L1D_RF_RefineTxMaxPowerDecrement( i );

   /*Determine final rollback value*/
   rollback_db = decrement_db>rollback_db ? decrement_db : rollback_db;

   /*decrease rollback value for lower power*/
   rollback_db = rollback_db-(max_power_idx-power_idx)*F2I_Resolution*2;

   if( rollback_db <= 0 ) return 0;

   /* Interpolation interval */
   //rollback_db = ROUNDSHORT((rollback_db_f * f2I_Resolution));
   right_idx = power_idx-rollback_db/(2*F2I_Resolution);
   left_idx = right_idx-1;

#if IS_RF_MT6162
   if( mod_type ) /* EPSK */
   {  (void)left_idx;
      L1D_RF_TXPC_RECORD_PARAM( 3, band, weight, power_idx, 1, rollback_db /*roll-back n/8 dB*/ );
      result = (short)( (rollback_db<<5)/F2I_Resolution ); /* rollback_db is 1/8 dB per DAC, but PCL_DAC in OH is 1/32 dB per DAC */
   }
   else           /* GMSK */
#endif
   {  L1D_RF_TXPC_RECORD_PARAM( 2, band, weight, right_idx, 1, -1 /*target DAC unknown*/ );

      // power_dac = (short)((band->power[(power_dbm-lowest_dbm)/2]*n)>>14);  /* power : dBm --> DAC */
      // Rollback value (DAC) : interpolation part + PCL part  /* power : dBm --> DAC */
      result = (short)(  ( (band->power[right_idx] - band->power[left_idx])*( rollback_db-(power_idx - right_idx)* 2 * F2I_Resolution )*weight )>>14  )/(2*F2I_Resolution)+(  ( (band->power[power_idx] - band->power[right_idx])*weight )>>14  );
   }
   return result;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetTxPowerRollbackData( int rf_band, void *table )
{  signed char *src, *dst;
   int  n;

   src = (signed char*)table;
   dst = (signed char*)(tx_power_rollback_gmsk[rf_band]);

   if(dst==0)  return;

   for( n=sizeof(sTX_POWER_ROLLBACK); n>0; n--)
   {  *dst++ = *src++;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

   #if IS_EGPRS
void L1D_RF_SetTxPowerRollbackData_EPSK( int rf_band, void *table )
{  signed char *src, *dst;
   int  n;

   src = (signed char*)table;
   dst = (signed char*)(tx_power_rollback_epsk[rf_band]);

   if(dst==0)  return;

   for( n=sizeof(sTX_POWER_ROLLBACK); n>0; n--)
   {  *dst++ = *src++;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
   #endif

#endif

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
int CLoad_FreqOffset = CUSTOM_CLOAD_FREQ_OFFSET;

char L1D_RF_Check_32K_XO_Status( void )
{
   return l1d_ext_32k_exist;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetCLoadFreqOffset( int *freq_offset )
{
   extern void L1D_SetDCXOFreqLPM(int);
   #if IS_RF_MT6260RF
   /* Compensate CLoad_FreqOffset since MT6260 LPM's 32K Clk is 19ppm faster than FPM's */
   int offsetSign = (*freq_offset) >= 0 ? 1 : -1;
   CLoad_FreqOffset = (*freq_offset)+17100+(((*freq_offset)*20+(offsetSign*(1<<19)))>>20);     
   #else
   CLoad_FreqOffset = *freq_offset;
   #endif
   L1D_SetDCXOFreqLPM( CLoad_FreqOffset );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_GetCLoadFreqOffset( int *buff )
{
   *buff = CLoad_FreqOffset;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_GetDFCFreqOffset( int *freq_offset )
{
   extern int   afc_Phi_est;
   extern short locked_DacValue;
   extern short current_DacValue;

   if( l1d_rf.is_lock_dcxo )
   {
      short dacOffset = locked_DacValue - current_DacValue;

      if( afc_Phi_est != 0 )
      {  *freq_offset = dacOffset*0x1000 / afc_Phi_est;  }
      else
      {  *freq_offset = 0;  }
   }
   else
   {  *freq_offset = 0;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_GetAfcDacFreqOffset( int *freq_offset )
{
   extern int   afc_Phi_est;
   extern short current_DacValue;
   extern short locked_DacValue;
   extern short afc_dac_default_ori;

   if( afc_Phi_est != 0 )
   {
      short dacOffset = 0;

      if( l1d_rf.is_lock_dcxo )
      {  dacOffset = locked_DacValue - current_DacValue;      }  //DFC freq. offset
      else
      {  dacOffset = afc_dac_default_ori - current_DacValue;  }  //CAFC freq. offset

      *freq_offset = dacOffset*0x1000 / afc_Phi_est;
   }
   else
   {  *freq_offset = 0;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Set_DCXO_LPM_Divider( unsigned int dcxo_frac )
{
   #if IS_RF_MT6261RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW( 62  , ((dcxo_frac&0xFFF)<<8)|0x1F ) );  //CW62: Set DCXO LPM divider
   IMM_MODE_END( );
   #elif IS_RF_MT6250RF || IS_RF_MT6260RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW( 0x3E, ((dcxo_frac&0xFFF)<<8)|0xFF ) );  //CW62: Set DCXO LPM divider
   IMM_MODE_END( );
   #elif IS_RF_MT6255RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW( 0x4A, ((dcxo_frac&0xFFF)<<8)|0xFF ) );  //CW74: Set DCXO LPM divider
   IMM_MODE_END( );
   #else
   #error "Please implement L1D_RF_Set_DCXO_LPM_Divider() for removing external 32K"
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Set_DCXO_FPM_Divider( unsigned int dcxo_frac )
{
   #if IS_RF_MT6261RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW( 63  , (POR_CW63&0xFF000)|(dcxo_frac&0xFFF) ) );  //CW63: Set DCXO FPM divider
   IMM_MODE_END( );
   #elif IS_RF_MT6260RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW( 0x3F, (POR_CW63&0xFF000)|(dcxo_frac&0xFFF) ) );  //CW63: Set DCXO FPM divider
   IMM_MODE_END( );
   #elif IS_RF_MT6250RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW( 0x3F, dcxo_frac&0xFFF ) );  //CW63: Set DCXO FPM divider
   IMM_MODE_END( );
   #elif IS_RF_MT6255RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW( 0x4B, dcxo_frac&0xFFF ) );  //CW75: Set DCXO FPM divider
   IMM_MODE_END( );
   #else
   #error "Please implement L1D_RF_Set_DCXO_FPM_Divider() for removing external 32K"
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT || IS_NORMAL_MODE_CAPID_CAL_SUPPORT
void L1D_RF_IMM_Set_CapID( long capid )
{
   #if IS_RF_MT6261RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   /* CW56: Set Cap ID value                          */
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(56, (POR_CW56&0xFFFE0) | (capid&CRYSTAL_CAPID_RANGE)) );
   IMM_MODE_END( );
   #elif IS_RF_MT6260RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   /* CW56: Set Cap ID value                          */
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x38, (POR_CW56&0xFFF00) | (capid&0xFF)) );
   IMM_MODE_END( );
   #elif IS_RF_MT6250RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   /* CW13: Turn on digital clock by setting GLOBAL_CK_EN = 1  */
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0D, POR_CW13 | 0x00200) );
   /* CW56: Set Cap ID value                          */
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x38, (POR_CW56&0xFFF00) | (capid&0xFF)) );

   if( !L1D_Check_SW_SecVersion() )
   {  /* CW13: Turn off digital clock by setting GLOBAL_CK_EN = 0 */
      //Do not turn off clock to solve the problem of missing TX bursts when frequency hopping is enabled for E1
      //IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0D, POR_CW13 & (~0x00200)) );
   }

   IMM_MODE_END( );
   #elif IS_RF_MT6255RF
   unsigned long cw132 = L1D_RF_SetTX_BSI_CW( QB_ST2B, 150 );  // MT6255RF enters TX mode in ST2B

   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), cw132|(0x1<<18)            );  //CW132: Enable to force to set Cap ID in RX/TX mode
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW( 0x38, capid&0xFF ) );  //CW56:  Set Cap ID value
   IMM_SEND_BSI( SCTRL_IMOD(0,29), cw132|(0x0<<18)            );  //CW132: Disable to force to set Cap ID in RX/TX mode
   IMM_MODE_END( );
   #else
   #error "Please implement L1D_RF_IMM_Set_CapID() for removing external 32K"
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

unsigned short L1D_RF_Check_DCXO_LPM( void )
{
#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
   unsigned short afc_data = (l1d_rf.dcxo_lpm == 1) ? 0x1FFF : l1d_rf.AFC_data;

   return afc_data;
#else
   return l1d_rf.AFC_data;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Set_DCXO_Power_Mode( char mode )
{
#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
   static char dcxo_mode = DCXO_NONE;

   if( mode == 0 )  //DCXO LPM
   {
      if( dcxo_mode != DCXO_LPM )
      {
         dcxo_mode = DCXO_LPM;
         L1D_RF_IMM_Set_CapID( CRYSTAL_CAPID_RANGE );
      }
   }
   else if( mode == 1 )  //DCXO FPM
   {
      if( dcxo_mode != DCXO_FPM )
      {
         dcxo_mode = DCXO_FPM;
         L1D_RF_IMM_Set_CapID( XO_CapID );
      }
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_UpdateAFCDac( unsigned short afc_data )
{
#if IS_RF_MT6260RF
   unsigned long cw57_readback;
#endif

#if IS_AST_B2S_SUPPORT
   /* do nothing */
#elif IS_SOC_CHIP
   #if IS_RF_MTKSOC1T || IS_RF_MTKSOC1
   IMM_MODE_BEGIN( IMMMASK_ALL );
   // update the AFC DAC based on the freq err of FB
   IMM_SEND_BSI( SCTRL_IMOD(0,26), (afc_data&0x1FFF)|0x0300000 );
   WAIT_TIME_QB(23); //Delay 20us
   IMM_MODE_END( );
   #elif IS_RF_MT6261RF   
   IMM_MODE_BEGIN( IMMMASK_ALL );
   /* CW57: Set AFC DAC value                                  */   
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(57, (POR_CW57&0xFE000) | (afc_data&0x1FFF)) );
   IMM_MODE_END( );
   #elif IS_RF_MT6260RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   /* CW57: Set AFC DAC value                                  */   
   IMM_RECEIVE_BSI( 0, 0x39, 0, &(cw57_readback) );
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x39, (cw57_readback&0xFE000) | (afc_data&0x1FFF)) );
   IMM_MODE_END( );
   #elif IS_RF_MT6250RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   /* CW13: Turn on digital clock by setting GLOBAL_CK_EN = 1  */
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0D, POR_CW13 | 0x00200) );
   /* CW57: Set AFC DAC value                                  */   
   IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x39, (POR_CW57&0xFE000) | (afc_data&0x1FFF)) );

   if( !L1D_Check_SW_SecVersion() )
   {  /* CW13: Turn off digital clock by setting GLOBAL_CK_EN = 0 */
      //Do not turn off clock to solve the problem of missing TX bursts when frequency hopping is enabled for E1
      //IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0D, POR_CW13 & (~0x00200)) );
   }

   IMM_MODE_END( );
   #elif IS_RF_MT6252RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   // update the AFC DAC based on the freq err of FB
      #if IS_CHIP_MT6252_S00
   IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0D00200 );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), (afc_data&0x1FFF)|0x3900000 );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0D00000 );
      #else
   IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0D00300 );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), (afc_data&0x1FFF)|0x3900000 );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0D00100 );
      #endif
   IMM_MODE_END( );
   #elif IS_RF_MT6256RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   // update the AFC DAC based on the freq err of FB
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW( 0x84, 0x188D8 ) );  //CW132: Enable to force to set AFC DAC in RX/TX mode
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW( 0x39, afc_data&0x1FFF ) );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW( 0x84, 0x088D8 ) );  //CW132: Disable to force to set AFC DAC in RX/TX mode
   IMM_MODE_END( );
   #elif IS_RF_MT6255RF
   unsigned long cw132 = L1D_RF_SetTX_BSI_CW( QB_ST2B, 150 );  // MT6255RF enters TX mode in ST2B

   IMM_MODE_BEGIN( IMMMASK_ALL );
   // update the AFC DAC based on the freq err of FB
   IMM_SEND_BSI( SCTRL_IMOD(0,29), cw132|(0x1<<18) );          //CW132: Enable to force to set AFC DAC in RX/TX mode
   IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW( 0x39, afc_data&0x1FFF ) );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), cw132|(0x0<<18) );          //CW132: Disable to force to set AFC DAC in RX/TX mode
   IMM_MODE_END( );
   #elif IS_RF_MT6251RF
   IMM_MODE_BEGIN( IMMMASK_ALL );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x8426FFA );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), (afc_data&0x1FFF)|0x3900000 );
   IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x8406FFA );
   IMM_MODE_END( );
   #else
#error "Please implement L1D_RF_UpdateAFCDac() for SOC chips"
   #endif
#elif IS_MT6162_DCXO_SUPPORT
   IMM_MODE_BEGIN( IMMMASK_ALL );
   /* update the AFC DAC based on the freq err of FB */
   IMM_SEND_BSI( SCTRL_IMOD(0,30), (afc_data&0x1FFF)|0x0E100000 );
   IMM_MODE_END( );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Run in CTIRQ2 */
void L1D_RF_SetStandbyMode( void )
{
#if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
   if( l1d_rf2.dedicated_flag&SC_NON_IDLE )
   {
      //check if there is RX/PM window to open or not. If no, send a immediate BSI to let RF enter stand-by mode
      /* Remove settings below to prevent abnormal high TXFE on RF SX integer channels.
      if( ( l1d_rf2.rx_pm_flag == 0 ) )
      {
   #if IS_RF_MT6251RF || IS_RF_MT6256RF
         IMM_MODE_BEGIN( IMMMASK_ALL );
         IMM_SEND_BSI( SCTRL_IMOD(0,29), l1d_rf.IFN_data | 0x0244000 );
         IMM_MODE_END( );
   #endif
      }*/

   #if IS_RF_VCO_PARTIAL_DOO_ON
      if( IS_2_TX_CWIN() )
      {
         char ori_cwin_idx;
         //if the next frame has 2 CWINs for TX windows, change ST3 of first TX CWIN to let RF enter standby mode
         ori_cwin_idx = l1d_rf.cwin_idx;
         l1d_rf.cwin_idx = l1d_rf2.tx_1st_cwin_idx;
         l1d_rf2.dedicated_flag |= SC_DEDICATED_2TX;
         IMM_UPDATE_BSI_BEGIN();
         L1D_RF_SetSData_ST3();
         IMM_UPDATE_BSI_END();
         l1d_rf2.dedicated_flag &= ~SC_DEDICATED_2TX;
         l1d_rf.cwin_idx = ori_cwin_idx;
      }
   #endif
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Access_Dedicated_Mode_Start( char mode_flag )
{
   (void)(mode_flag);
#if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF || IS_WIFI_ADAPTIVE_POWER_CONTROL_SUPPORT
   l1d_rf2.dedicated_flag |= mode_flag;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Access_Dedicated_Mode_End( char mode_flag )
{
   (void)(mode_flag);
#if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF || IS_WIFI_ADAPTIVE_POWER_CONTROL_SUPPORT
   l1d_rf2.dedicated_flag &= ~mode_flag;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Check_RTX_PM( unsigned char rx_slots, int pm_count, char tx_cwin_idx, unsigned short is_fsi_win )
{
   (void)(rx_slots);
   (void)(pm_count);
   (void)(tx_cwin_idx);
#if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
   //for PARTIAL_DOO_ON/DOO_OFF, rf need to know if there are RX/PM windows to open or not in the next frame
   l1d_rf2.rx_pm_flag = ( rx_slots !=0 || pm_count != 0 || is_fsi_win != 0 ) ? 1 : 0;
   l1d_rf2.tx_1st_cwin_idx = tx_cwin_idx;  //to record the 1st TX cwin idx for replace ST3 data usage
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_CHIP_MT6223
unsigned short L1D_BT_Co_Clock_EINT_Setting( void )
{  char port = (BT_Co_Clock_GPIO_PORT)&0x7F;
   unsigned short setting = 0;

   switch( port )
   {
      case 42: case 43:
      {  setting = 1;
         break;
      }
      case 26: case 27: case 28:
      {  setting = 2;
         break;
      }
   }
   return setting;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_RF_MT6256RF
unsigned char L1D_RF_Get_BT_Rcal( void )
{
   unsigned char  r_cal=8; //default value

   #if IS_BT_R_CAL_SUPPORT
   extern unsigned char  Brt_SingleArm_R_Calibration( void );
   r_cal = Brt_SingleArm_R_Calibration() & 0xF;
   #endif

   return r_cal;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

void L1D_RF_CAPID_Update( void )
{
#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT
   if(l1_rf_table.is_data_update)
   {
      XO_CapID=l1_rf_table.XO_CapID;
   }
#elif IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
   if(l1d_rf_custom_input_data.is_data_update)
   {
      XO_CapID=l1d_rf_custom_input_data.RF_Others_Variable.xXO_CapID;
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_BBTXParameter_Update( void )
{
#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT
   if(l1_rf_table.is_data_update)
   {
      BBTXParameters.bbrx_gsm850_gsm900_swap   = l1_rf_table.xGSM850_GSM900_SWAP;
      BBTXParameters.bbrx_dcs1800_pcs1900_swap = l1_rf_table.xDCS1800_PCS1900_SWAP;
      BBTXParameters.apc_bat_low_voltage       = l1_rf_table.xBAT_LOW_VOLTAGE;
      BBTXParameters.apc_bat_high_voltage      = l1_rf_table.xBAT_HIGH_VOLTAGE;
      BBTXParameters.apc_bat_low_temperature   = l1_rf_table.xBAT_LOW_TEMPERATURE;
      BBTXParameters.apc_bat_high_temperature  = l1_rf_table.xBAT_HIGH_TEMPERATURE;
   }
#elif IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
   if(l1d_rf_custom_input_data.is_data_update)
   {
      BBTXParameters.bbrx_gsm850_gsm900_swap   = l1d_rf_custom_input_data.RF_Others_Variable.xGSM850_GSM900_SWAP;
      BBTXParameters.bbrx_dcs1800_pcs1900_swap = l1d_rf_custom_input_data.RF_Others_Variable.xDCS1800_PCS1900_SWAP;
      BBTXParameters.apc_bat_low_voltage       = VOLT2UVOLT(l1d_rf_custom_input_data.RF_APC_Compensate_Variable.xBAT_LOW_VOLTAGE)/10;
      BBTXParameters.apc_bat_high_voltage      = VOLT2UVOLT(l1d_rf_custom_input_data.RF_APC_Compensate_Variable.xBAT_HIGH_VOLTAGE)/10;
      BBTXParameters.apc_bat_low_temperature   = TEMP2MTEMP(l1d_rf_custom_input_data.RF_APC_Compensate_Variable.xBAT_LOW_TEMPERATURE);
      BBTXParameters.apc_bat_high_temperature  = TEMP2MTEMP(l1d_rf_custom_input_data.RF_APC_Compensate_Variable.xBAT_HIGH_TEMPERATURE);
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT /* for MT6516 only */
void L1D_RF_Custom_Table_Update( void )
{
   int i,j,k;
   for(i=1;i<5;i++)
   {
      for(j=0;j<2;j++)
      {
         for(k=0;k<5;k++)
         {
            PDATA_TABLE[i][j][k]=l1_rf_table.xPDATA_TABLE[i][j][k];
         }
      }
   }
   for(i=1;i<5;i++)
   {
      for(j=0;j<3;j++)
      {
         for(k=0;k<3;k++)
         {
            PDATA_TABLE3[i][j][k]=l1_rf_table.xPDATA_TABLE3[i][j][k];
         }
      }
   }
   for(i=0;i<8;i++)
   {
      RX_START_TQ_TABLE[i]=l1_rf_table.xRX_START_TQ_TABLE[i];
   }
   for(i=0;i<5;i++)
   {
      RX_END_TQ_TABLE[i]=l1_rf_table.xRX_END_TQ_TABLE[i];
   }
   #if IS_GPRS
   for(i=0;i<3;i++)
   {
      RX_MIDDLE_TQ_TABLE[i]=l1_rf_table.xRX_MIDDLE_TQ_TABLE[i];
   }
   for(i=0;i<2;i++)
   {
      RX_MIDDLE_TQ_TABLE2[i]=l1_rf_table.xRX_MIDDLE_TQ_TABLE2[i];
   }
   #endif
   for(i=0;i<8;i++)
   {
      TX_START_TQ_TABLE[i]=l1_rf_table.xTX_START_TQ_TABLE[i];
   }
   for(i=0;i<1;i++)
   {
      TX_START_TQ_TABLE2[i]=l1_rf_table.xTX_START_TQ_TABLE2[i];
   }
   for(i=0;i<1;i++)
   {
      TX_START_TQ_TABLE3[i]=l1_rf_table.xTX_START_TQ_TABLE3[i];
   }
   for(i=0;i<6;i++)
   {
      TX_END_TQ_TABLE[i]=l1_rf_table.xTX_END_TQ_TABLE[i];
   }
   #if IS_GPRS || IS_MULTISLOT_TX_SUPPORT
   for(i=0;i<4;i++)
   {
      TX_MIDDLE_TQ_TABLE[i]=l1_rf_table.xTX_MIDDLE_TQ_TABLE[i];
   }
      #if IS_EPSK_TX_SUPPORT
   for(i=0;i<2;i++)
   {
      for(j=0;j<4;j++)
      {
         TX_MIDDLE_TQ_TABLE2[i][j]=l1_rf_table.xTX_MIDDLE_TQ_TABLE2[i][j];
      }
   }
      #endif
   #endif
   PM_START_TQ_TABLE[6]=l1_rf_table.xPM_START_TQ_TABLE[6];

   for(i=0;i<10;i++)
   {
      PM_TQ_TABLE[i]=l1_rf_table.xPM_TQ_TABLE[i];
   }
   #if L1D_PM_ENHANCE
   for(i=0;i<10;i++)
   {
      PM_IN_IDLE_TQ_TABLE[i]=l1_rf_table.xPM_IN_IDLE_TQ_TABLE[i];
   }
      #if L1D_PM_1R7PM
   for(i=0;i<10;i++)
   {
      PM_1R7PM_TQ_TABLE[i]=l1_rf_table.xPM_1R7PM_TQ_TABLE[i];
   }
      #endif
   #endif
   for(i=0;i<7;i++)
   {
      FSWIN_STOP_DATA_TABLE[i]=l1_rf_table.xFSWIN_STOP_DATA_TABLE[i];
   }

   //txios_pcl_tab
   #if  IS_RF_MT6140D
   for(i=0;i<2;i++)
   {
      for(j=0;j<2;j++)
      {
         for(k=1;k<5;k++)
         {
            TXCW[i][j][k]=TXCW[i][j][k]&0xFE3FFFF|(l1_rf_table.xtxios_pcl_tab[i][j][k]<<18);
            TXCW[i][j][k]=TXCW[i][j][k]&0xFFFFF0F|(l1_rf_table.xtxitc_pcl_tab[i][j][k]<<4 );
            TXCW[i][j][k]=TXCW[i][j][k]&0xFFE3FFF|(l1_rf_table.xtxmod_gc_tab[i][j][k]<<14 );
         }
      }
   }
   #endif
   pdata_gmsk = l1_rf_table.xPDATA_GMSK;
   pdata_8psk = l1_rf_table.xPDATA_8PSK;

   apc_bat_voltage_period                   = l1_rf_table.xBAT_VOLTAGE_SAMPLE_PERIOD;
   apc_bat_voltage_count                    = l1_rf_table.xBAT_VOLTAGE_AVERAGE_COUNT;
   apc_bat_temperature_period               = l1_rf_table.xBAT_TEMPERATURE_SAMPLE_PERIOD;
   apc_bat_temperature_count                = l1_rf_table.xBAT_TEMPERATURE_AVERAGE_COUNT;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#if IS_RF_MT6162
extern CONST unsigned long  SDATA_RX_BAND[5];
       CONST unsigned char  CLK_EN_TABLE[3] = {  CLK1_EN, CLK2_EN, CLK3_EN  };
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
void L1D_RF_Custom_BPI_Table_Update(void)
{
   sRF_BPI_VARIABLE *p=&l1d_rf_custom_input_data.RF_BPI_Variable;

   #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   /* FrequencyBand850  */
   PDATA_TABLE[1][0][0]=p->xPDATA_GSM850_PR1;
   PDATA_TABLE[1][0][1]=p->xPDATA_GSM850_PR2;
   PDATA_TABLE[1][0][2]=p->xPDATA_GSM850_PR2B;
   PDATA_TABLE[1][0][3]=p->xPDATA_GSM850_PR3;
   PDATA_TABLE[1][0][4]=p->xPDATA_GSM850_PR3A;
   PDATA_TABLE[1][1][0]=p->xPDATA_GSM850_PT1;
   PDATA_TABLE[1][1][1]=p->xPDATA_GSM850_PT2;
   PDATA_TABLE[1][1][2]=p->xPDATA_GSM850_PT2B;
   PDATA_TABLE[1][1][3]=p->xPDATA_GSM850_PT3;
   PDATA_TABLE[1][1][4]=p->xPDATA_GSM850_PT3A;
   /* FrequencyBand900  */
   PDATA_TABLE[2][0][0]=p->xPDATA_GSM_PR1;
   PDATA_TABLE[2][0][1]=p->xPDATA_GSM_PR2;
   PDATA_TABLE[2][0][2]=p->xPDATA_GSM_PR2B;
   PDATA_TABLE[2][0][3]=p->xPDATA_GSM_PR3;
   PDATA_TABLE[2][0][4]=p->xPDATA_GSM_PR3A;
   PDATA_TABLE[2][1][0]=p->xPDATA_GSM_PT1;
   PDATA_TABLE[2][1][1]=p->xPDATA_GSM_PT2;
   PDATA_TABLE[2][1][2]=p->xPDATA_GSM_PT2B;
   PDATA_TABLE[2][1][3]=p->xPDATA_GSM_PT3;
   PDATA_TABLE[2][1][4]=p->xPDATA_GSM_PT3A;
   /* FrequencyBand1800 */
   PDATA_TABLE[3][0][0]=p->xPDATA_DCS_PR1;
   PDATA_TABLE[3][0][1]=p->xPDATA_DCS_PR2;
   PDATA_TABLE[3][0][2]=p->xPDATA_DCS_PR2B;
   PDATA_TABLE[3][0][3]=p->xPDATA_DCS_PR3;
   PDATA_TABLE[3][0][4]=p->xPDATA_DCS_PR3A;
   PDATA_TABLE[3][1][0]=p->xPDATA_DCS_PT1;
   PDATA_TABLE[3][1][1]=p->xPDATA_DCS_PT2;
   PDATA_TABLE[3][1][2]=p->xPDATA_DCS_PT2B;
   PDATA_TABLE[3][1][3]=p->xPDATA_DCS_PT3;
   PDATA_TABLE[3][1][4]=p->xPDATA_DCS_PT3A;
   /* FrequencyBand1900 */
   PDATA_TABLE[4][0][0]=p->xPDATA_PCS_PR1;
   PDATA_TABLE[4][0][1]=p->xPDATA_PCS_PR2;
   PDATA_TABLE[4][0][2]=p->xPDATA_PCS_PR2B;
   PDATA_TABLE[4][0][3]=p->xPDATA_PCS_PR3;
   PDATA_TABLE[4][0][4]=p->xPDATA_PCS_PR3A;
   PDATA_TABLE[4][1][0]=p->xPDATA_PCS_PT1;
   PDATA_TABLE[4][1][1]=p->xPDATA_PCS_PT2;
   PDATA_TABLE[4][1][2]=p->xPDATA_PCS_PT2B;
   PDATA_TABLE[4][1][3]=p->xPDATA_PCS_PT3;
   PDATA_TABLE[4][1][4]=p->xPDATA_PCS_PT3A;

   /* FrequencyBand850  */
   PDATA_TABLE3[1][0][0]=p->xPDATA_GSM850_PR2M1;
   PDATA_TABLE3[1][0][1]=p->xPDATA_GSM850_PR2M2;
   PDATA_TABLE3[1][0][2]=p->xPDATA_GSM850_PR2M3;
   PDATA_TABLE3[1][1][0]=p->xPDATA_GSM850_PT2M1_G8;
   PDATA_TABLE3[1][1][1]=p->xPDATA_GSM850_PT2M2_G8;
   PDATA_TABLE3[1][1][2]=p->xPDATA_GSM850_PT2M3_G8;
   PDATA_TABLE3[1][2][0]=p->xPDATA_GSM850_PT2M1_8G;
   PDATA_TABLE3[1][2][1]=p->xPDATA_GSM850_PT2M2_8G;
   PDATA_TABLE3[1][2][2]=p->xPDATA_GSM850_PT2M3_8G;
   /* FrequencyBand900  */
   PDATA_TABLE3[2][0][0]=p->xPDATA_GSM_PR2M1;
   PDATA_TABLE3[2][0][1]=p->xPDATA_GSM_PR2M2;
   PDATA_TABLE3[2][0][2]=p->xPDATA_GSM_PR2M3;
   PDATA_TABLE3[2][1][0]=p->xPDATA_GSM_PT2M1_G8;
   PDATA_TABLE3[2][1][1]=p->xPDATA_GSM_PT2M2_G8;
   PDATA_TABLE3[2][1][2]=p->xPDATA_GSM_PT2M3_G8;
   PDATA_TABLE3[2][2][0]=p->xPDATA_GSM_PT2M1_8G;
   PDATA_TABLE3[2][2][1]=p->xPDATA_GSM_PT2M2_8G;
   PDATA_TABLE3[2][2][2]=p->xPDATA_GSM_PT2M3_8G;
   /* FrequencyBand1800 */
   PDATA_TABLE3[3][0][0]=p->xPDATA_DCS_PR2M1;
   PDATA_TABLE3[3][0][1]=p->xPDATA_DCS_PR2M2;
   PDATA_TABLE3[3][0][2]=p->xPDATA_DCS_PR2M3;
   PDATA_TABLE3[3][1][0]=p->xPDATA_DCS_PT2M1_G8;
   PDATA_TABLE3[3][1][1]=p->xPDATA_DCS_PT2M2_G8;
   PDATA_TABLE3[3][1][2]=p->xPDATA_DCS_PT2M3_G8;
   PDATA_TABLE3[3][2][0]=p->xPDATA_DCS_PT2M1_8G;
   PDATA_TABLE3[3][2][1]=p->xPDATA_DCS_PT2M2_8G;
   PDATA_TABLE3[3][2][2]=p->xPDATA_DCS_PT2M3_8G;
   /* FrequencyBand1900 */
   PDATA_TABLE3[4][0][0]=p->xPDATA_PCS_PR2M1;
   PDATA_TABLE3[4][0][1]=p->xPDATA_PCS_PR2M2;
   PDATA_TABLE3[4][0][2]=p->xPDATA_PCS_PR2M3;
   PDATA_TABLE3[4][1][0]=p->xPDATA_PCS_PT2M1_G8;
   PDATA_TABLE3[4][1][1]=p->xPDATA_PCS_PT2M2_G8;
   PDATA_TABLE3[4][1][2]=p->xPDATA_PCS_PT2M3_G8;
   PDATA_TABLE3[4][2][0]=p->xPDATA_PCS_PT2M1_8G;
   PDATA_TABLE3[4][2][1]=p->xPDATA_PCS_PT2M2_8G;
   PDATA_TABLE3[4][2][2]=p->xPDATA_PCS_PT2M3_8G;

   pdata_gmsk = p->xPDATA_GMSK;
   pdata_8psk = p->xPDATA_8PSK;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_Timing_Table_Update(void)
{
   signed short xTQ_SR0;
   signed short xTQ_SR1;
   signed short xTQ_SR2;
   signed short xTQ_SR2M;
   signed short xTQ_SR3;
   signed short xTQ_PR1;
   signed short xTQ_PR2;
   signed short xTQ_PR2M1;
   signed short xTQ_PR2M2;
   signed short xTQ_PR3;
   signed short xTQ_PR3A;
   signed short xTQ_ST0;
   signed short xTQ_ST1;
   signed short xTQ_ST2;
   signed short xTQ_ST3;
   signed short xTQ_PT1;
   signed short xTQ_PT2;
   signed short xTQ_PT2B;
   signed short xTQ_PT3;
   //signed short xTQ_PT3A;
   signed short xTQ_APCON;
   signed short xTQ_APCMID;
   signed short xTQ_APCOFF;
   signed short xTQ_BDLON;
   signed short xTQ_BDLOFF;
   signed short xTQ_BULON;
   signed short xTQ_BULOFF;
   signed short xTQ_AFC2_2_BOFF;

   signed short xTQ_PR2B;
   signed short xTQ_PT2M1_G8;
   signed short xTQ_PT2M2_G8;
   signed short xTQ_PT2M3_G8;
   signed short xTQ_PT2M1_8G;
   signed short xTQ_PT2M2_8G;
   signed short xTQ_PT2M3_8G;
   signed short xTQ_ST2B;
   signed short xTQ_ST2M_G8;
   signed short xTQ_ST2M_8G;
   signed short xQR_BOFF_2_IDLE;

   sRF_TIMING_VARIABLE *t=&l1d_rf_custom_input_data.RF_Timing_Variable;

   xTQ_SR0                    =    (t->xQB_SR0-QB_RON_2_FSYNC);
   xTQ_SR1                    =    (t->xQB_SR1-QB_RON_2_FSYNC);
   xTQ_SR2                    =    (t->xQB_SR2-QB_RON_2_FSYNC);
   xTQ_SR2M                   =    (t->xQB_SR2M-QB_RON_2_FSYNC);
   xTQ_SR3                    =    (t->xQB_SR3-QB_FSYNC_2_ROFF);
   xTQ_PR1                    =    (t->xQB_PR1-QB_RON_2_FSYNC);
   xTQ_PR2                    =    (t->xQB_PR2-QB_RON_2_FSYNC);
   xTQ_PR2M1                  =    (t->xQB_PR2M1-QB_RON_2_FSYNC);
   xTQ_PR2M2                  =    (t->xQB_PR2M2-QB_RON_2_FSYNC);
   xTQ_PR3                    =    (t->xQB_PR3-QB_FSYNC_2_ROFF);
   xTQ_PR3A                   =    (t->xQB_PR3A-QB_FSYNC_2_ROFF);
   xTQ_ST0                    =    (t->xQB_ST0-QB_TON_2_FSYNC);
   xTQ_ST1                    =    (t->xQB_ST1-QB_TON_2_FSYNC);
   xTQ_ST2                    =    (t->xQB_ST2-QB_TON_2_FSYNC);
   xTQ_ST3                    =    (t->xQB_ST3-QB_FSYNC_2_TOFF);
   xTQ_PT1                    =    (t->xQB_PT1-QB_TON_2_FSYNC);
   xTQ_PT2                    =    (t->xQB_PT2-QB_TON_2_FSYNC);
   xTQ_PT2B                   =    (t->xQB_PT2B-QB_TON_2_FSYNC);
   xTQ_PT3                    =    (t->xQB_PT3-QB_FSYNC_2_TOFF);
   //xTQ_PT3A                   =    (t->xQB_PT3A-QB_FSYNC_2_TOFF);
   xTQ_APCON                  =    (t->xQB_APCON-QB_TON_2_FSYNC);
   xTQ_APCMID                 =    (t->xQB_APCMID-QB_TON_2_FSYNC);
   xTQ_APCOFF                 =    (t->xQB_APCOFF-QB_FSYNC_2_TOFF);
   xTQ_BDLON                  =    (QB_RX_FENA_2_FSYNC-QB_RON_2_FSYNC+QB_RX_ADEN_2_FENA);
   xTQ_BDLOFF                 =    (-QB_FSYNC_2_ROFF);
   xTQ_BULON                  =    (QB_TX_FENA_2_FSYNC-QB_TON_2_FSYNC+QB_TX_DAEN_2_FENA);
   xTQ_BULOFF                 =    (-QB_FSYNC_2_TOFF);
   xTQ_AFC2_2_BOFF            =    (xTQ_BULOFF+QB_TX_FSYNC_2_FENA);
   xTQ_PR2B                   =    (t->xQB_PR2B-QB_RON_2_FSYNC);
   xTQ_PT2M1_G8               =    (t->xQB_PT2M1_G8-QB_TON_2_FSYNC);
   xTQ_PT2M2_G8               =    (t->xQB_PT2M2_G8-QB_TON_2_FSYNC);
   xTQ_PT2M3_G8               =    (t->xQB_PT2M3_G8-QB_TON_2_FSYNC);
   xTQ_PT2M1_8G               =    (t->xQB_PT2M1_8G-QB_TON_2_FSYNC);
   xTQ_PT2M2_8G               =    (t->xQB_PT2M2_8G-QB_TON_2_FSYNC);
   xTQ_PT2M3_8G               =    (t->xQB_PT2M3_8G-QB_TON_2_FSYNC);
   xTQ_ST2B                   =    (t->xQB_ST2B-QB_TON_2_FSYNC);
   xTQ_ST2M_G8                =    (t->xQB_ST2M_G8-QB_TON_2_FSYNC);
   xTQ_ST2M_8G                =    (t->xQB_ST2M_8G-QB_TON_2_FSYNC);

   if ( (xTQ_PR3A>xTQ_SR3) && (xTQ_PR3A>xTQ_PR3) )
      xQR_BOFF_2_IDLE       =         xTQ_PR3A;
   else if(( xTQ_PR3>xTQ_SR3) && (xTQ_PR3>xTQ_PR3A))
      xQR_BOFF_2_IDLE    =            xTQ_PR3;
   else
      xQR_BOFF_2_IDLE      =          xTQ_SR3;

   #if IS_BSI_SX0_SUPPORT
   RTX_START_TQ_TABLE[0]=  -xTQ_SR0;
   RTX_START_TQ_TABLE[1]=  -xTQ_ST0;
   if( t->xQB_SR0 != (-10000) )
      TQ_FBWin_Start_Offset = (xTQ_SR0+TQ_SBWIN_DSP_EXTEND1+TQ_BURST_HEAD_GUARD);  /* 216 QB  */
   else
      TQ_FBWin_Start_Offset = (xTQ_SR1+TQ_SBWIN_DSP_EXTEND1+TQ_BURST_HEAD_GUARD);  /* 216 QB  */
   #else
   TQ_FBWin_Start_Offset = (xTQ_SR1+TQ_SBWIN_DSP_EXTEND1+TQ_BURST_HEAD_GUARD);  /* 216 QB  */
   #endif

   #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   RX_START_TQ_TABLE[0]      = -xTQ_SR1;
   RX_START_TQ_TABLE[1]      = -xTQ_PR1;
   RX_START_TQ_TABLE[2]      = -xTQ_PR2;
   RX_START_TQ_TABLE[3]      = -xTQ_PR2B;
   RX_START_TQ_TABLE[4]      = -xTQ_SR2;
   RX_START_TQ_TABLE[5]      = -xTQ_BDLON;
   RX_START_TQ_TABLE[6]      =  TQ_MAXIMUM;
   RX_START_TQ_TABLE[7]      = -TQ_AFC_READY_RX;

   RX_END_TQ_TABLE[0]        =  xTQ_SR3;
   RX_END_TQ_TABLE[1]        =  xTQ_PR3;
   RX_END_TQ_TABLE[2]        =  xTQ_PR3A;
   RX_END_TQ_TABLE[3]        =  xTQ_BDLOFF;
   RX_END_TQ_TABLE[4]        =  TQ_MAXIMUM;
   #endif
   #if IS_GPRS
   RX_MIDDLE_TQ_TABLE[0]     = +xTQ_BDLOFF;
   RX_MIDDLE_TQ_TABLE[1]     = -xTQ_BDLON;
   RX_MIDDLE_TQ_TABLE[2]     = -xTQ_SR2M;
      #if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   RX_MIDDLE_TQ_TABLE2[0]    = -xTQ_PR2M1;
   RX_MIDDLE_TQ_TABLE2[1]    = -xTQ_PR2M2;
      #endif
   #endif

   TX_START_TQ_TABLE[0]      = -TQ_AFC_READY;
   TX_START_TQ_TABLE[1]      = -xTQ_ST1;
   TX_START_TQ_TABLE[2]      = -xTQ_PT1;
   TX_START_TQ_TABLE[3]      = -xTQ_PT2;
   TX_START_TQ_TABLE[4]      = -xTQ_APCON;
   TX_START_TQ_TABLE[5]      = -xTQ_APCON;
   TX_START_TQ_TABLE[6]      = -xTQ_BULON;
   TX_START_TQ_TABLE[7]      = -xTQ_ST2;

   #if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   TX_START_TQ_TABLE2[0]     = -xTQ_PT2B;
   #endif

   #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   TX_START_TQ_TABLE3[0]     = -xTQ_ST2B;
   #endif

   TX_END_TQ_TABLE[0]        =xTQ_AFC2_2_BOFF;
   TX_END_TQ_TABLE[1]        =xTQ_ST3;
   TX_END_TQ_TABLE[2]        =xTQ_PT3;
   TX_END_TQ_TABLE[3]        =xTQ_BULOFF;
   TX_END_TQ_TABLE[4]        =xTQ_APCOFF;
   TX_END_TQ_TABLE[5]        =xTQ_APCOFF;

   #if IS_GPRS || IS_MULTISLOT_TX_SUPPORT
   TX_MIDDLE_TQ_TABLE[0]     =+xTQ_BULOFF;
   TX_MIDDLE_TQ_TABLE[1]     =-xTQ_BULON;
   TX_MIDDLE_TQ_TABLE[2]     =-xTQ_APCMID;
   TX_MIDDLE_TQ_TABLE[3]     =-xTQ_APCMID;
      #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   TX_MIDDLE_TQ_TABLE2[0][0] =-xTQ_ST2M_G8;
   TX_MIDDLE_TQ_TABLE2[0][1] =-xTQ_PT2M1_G8;
   TX_MIDDLE_TQ_TABLE2[0][2] =-xTQ_PT2M2_G8;
   TX_MIDDLE_TQ_TABLE2[0][3] =-xTQ_PT2M3_G8;

   TX_MIDDLE_TQ_TABLE2[1][0] =-xTQ_ST2M_8G;
   TX_MIDDLE_TQ_TABLE2[1][1] =-xTQ_PT2M1_8G;
   TX_MIDDLE_TQ_TABLE2[1][2] =-xTQ_PT2M2_8G;
   TX_MIDDLE_TQ_TABLE2[1][3] =-xTQ_PT2M3_8G;
      #endif
   #endif
   PM_START_TQ_TABLE[6]=TQ_VALIDATE-1-TQ_SHORT_PMWIN_LEN-xQR_BOFF_2_IDLE;

   #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   PM_TQ_TABLE[0]           = -xTQ_SR1;
   PM_TQ_TABLE[1]           = -xTQ_PR1;
   PM_TQ_TABLE[2]           = -xTQ_PR2;
   PM_TQ_TABLE[3]           = -xTQ_PR2B;
   PM_TQ_TABLE[4]           = TQ_SHORT_PMWIN_LEN+xTQ_SR3;
   PM_TQ_TABLE[5]           = TQ_SHORT_PMWIN_LEN+xTQ_PR3;
   PM_TQ_TABLE[6]           = TQ_SHORT_PMWIN_LEN+xTQ_PR3A;
   PM_TQ_TABLE[7]           = -xTQ_SR2;
   PM_TQ_TABLE[8]           = -xTQ_BDLON;
   PM_TQ_TABLE[9]           = TQ_SHORT_PMWIN_LEN+xTQ_BDLOFF;
      #if L1D_PM_ENHANCE
   PM_IN_IDLE_TQ_TABLE[0]   = -xTQ_SR1;
   PM_IN_IDLE_TQ_TABLE[1]   = -xTQ_PR1;
   PM_IN_IDLE_TQ_TABLE[2]   = -xTQ_PR2;
   PM_IN_IDLE_TQ_TABLE[3]   = -xTQ_PR2B;
   PM_IN_IDLE_TQ_TABLE[4]   = TQ_SHORT_PMWIN_LEN_IN_IDLE+xTQ_SR3;
   PM_IN_IDLE_TQ_TABLE[5]   = TQ_SHORT_PMWIN_LEN_IN_IDLE+xTQ_PR3;
   PM_IN_IDLE_TQ_TABLE[6]   = TQ_SHORT_PMWIN_LEN_IN_IDLE+xTQ_PR3A;
   PM_IN_IDLE_TQ_TABLE[7]   = -xTQ_SR2;
   PM_IN_IDLE_TQ_TABLE[8]   = -xTQ_BDLON;
   PM_IN_IDLE_TQ_TABLE[9]   = TQ_SHORT_PMWIN_LEN_IN_IDLE+xTQ_BDLOFF;
         #if L1D_PM_1R7PM
   PM_1R7PM_TQ_TABLE[0]     = -xTQ_SR1;
   PM_1R7PM_TQ_TABLE[1]     = -xTQ_PR1;
   PM_1R7PM_TQ_TABLE[2]     = -xTQ_PR2;
   PM_1R7PM_TQ_TABLE[3]     = -xTQ_PR2B;
   PM_1R7PM_TQ_TABLE[4]     = TQ_1R7PM_PMWIN_LEN_IN_IDLE+xTQ_SR3;
   PM_1R7PM_TQ_TABLE[5]     = TQ_1R7PM_PMWIN_LEN_IN_IDLE+xTQ_PR3;
   PM_1R7PM_TQ_TABLE[6]     = TQ_1R7PM_PMWIN_LEN_IN_IDLE+xTQ_PR3A;
   PM_1R7PM_TQ_TABLE[7]     = -xTQ_SR2;
   PM_1R7PM_TQ_TABLE[8]     = -xTQ_BDLON;
   PM_1R7PM_TQ_TABLE[9]     = TQ_1R7PM_PMWIN_LEN_IN_IDLE+xTQ_BDLOFF;
         #endif
   FSWIN_STOP_DATA_TABLE[0] = TQ_FSWIN_STOP_FSYNC+xTQ_SR3;
   FSWIN_STOP_DATA_TABLE[1] = TQ_FSWIN_STOP_FSYNC+xTQ_PR3;
   FSWIN_STOP_DATA_TABLE[2] = TQ_FSWIN_STOP_FSYNC+xTQ_PR3A;
   FSWIN_STOP_DATA_TABLE[3] = TQ_MAXIMUM;
   FSWIN_STOP_DATA_TABLE[4] = TQ_FSWIN_STOP_FSYNC+TQ_BDLOFF,
   FSWIN_STOP_DATA_TABLE[5] = l1d_rf_custom_input_data.RF_BPI_Variable.xPDATA_IDLE;
   FSWIN_STOP_DATA_TABLE[6] = l1d_rf_custom_input_data.RF_BPI_Variable.xPDATA_IDLE;
      #endif
   #endif

   #if IS_TDD_DUAL_MODE_SUPPORT
   TD_DM_PM_TQ_TABLE[0] =-xTQ_SR1;
   TD_DM_PM_TQ_TABLE[1] =-xTQ_PR1;
   TD_DM_PM_TQ_TABLE[2] =-xTQ_PR2;
   TD_DM_PM_TQ_TABLE[3] =-xTQ_PR2B;
   TD_DM_PM_TQ_TABLE[4] =TQ_1R7PM_PMWIN_LEN_IN_IDLE+xTQ_SR3;
   TD_DM_PM_TQ_TABLE[5] =TQ_1R7PM_PMWIN_LEN_IN_IDLE+xTQ_PR3;
   TD_DM_PM_TQ_TABLE[6] =TQ_1R7PM_PMWIN_LEN_IN_IDLE+xTQ_PR3A;
   TD_DM_PM_TQ_TABLE[7] =-xTQ_SR2;
   TD_DM_PM_TQ_TABLE[8] =-xTQ_BDLON;
   TD_DM_PM_TQ_TABLE[9] =TQ_1R7PM_PMWIN_LEN_IN_IDLE+xTQ_BDLOFF;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_APC_Compensate_Update(void)
{
   apc_bat_voltage_period                   = SECONDS2FRAME( l1d_rf_custom_input_data.RF_APC_Compensate_Variable.xBAT_VOLTAGE_SAMPLE_PERIOD );
   apc_bat_voltage_count                    = l1d_rf_custom_input_data.RF_APC_Compensate_Variable.xBAT_VOLTAGE_AVERAGE_COUNT;
   apc_bat_temperature_period               = SECONDS2FRAME( l1d_rf_custom_input_data.RF_APC_Compensate_Variable.xBAT_TEMPERATURE_SAMPLE_PERIOD );
   apc_bat_temperature_count                = l1d_rf_custom_input_data.RF_APC_Compensate_Variable.xBAT_TEMPERATURE_AVERAGE_COUNT;
   apc_rf_temperature_period                = SECONDS2FRAME( l1d_rf_custom_input_data.RF_APC_Compensate_Variable.xRF_TEMPERATURE_SAMPLE_PERIOD);
   apc_rf_temperature_count                 = l1d_rf_custom_input_data.RF_APC_Compensate_Variable.xRF_TEMPERATURE_AVERAGE_COUNT;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_TX_PCL_Table_Update(void)
{
   #if  IS_RF_MT6140D
   //TXCW[i][j][k]= TXCW[i][j][k]&0xFE3FFFF|(l1_rf_table.xtxios_pcl_tab[i][j][k]<<18);

   sRF_PCL_VARIABLE *p=&l1d_rf_custom_input_data.RF_PCL_Varaible;
   sRF_ITC_PCL_VARIABLE *p1=&l1d_rf_custom_input_data.RF_ITC_PCL_Variable;
   sRF_LBMOD_GC_VARIABLE *p3=&l1d_rf_custom_input_data.RF_Lbmod_GC_Variable;
   sRF_HBMOD_GC_VARIABLE *p2=&l1d_rf_custom_input_data.RF_Hbmod_GC_Variable;

   TXCW[0][0][1]= TXCW[0][0][1]&0xFE3FFFF|(p->txios_highpcl_850_GMSK<<18);
   TXCW[0][0][2]= TXCW[0][0][2]&0xFE3FFFF|(p->txios_highpcl_900_GMSK<<18);
   TXCW[0][0][3]= TXCW[0][0][3]&0xFE3FFFF|(p->txios_highpcl_DCS_GMSK<<18);
   TXCW[0][0][4]= TXCW[0][0][4]&0xFE3FFFF|(p->txios_highpcl_PCS_GMSK<<18);

   TXCW[0][1][1]= TXCW[0][1][1]&0xFE3FFFF|(p->txios_highpcl_850_EPSK<<18);
   TXCW[0][1][2]= TXCW[0][1][2]&0xFE3FFFF|(p->txios_highpcl_900_EPSK<<18);
   TXCW[0][1][3]= TXCW[0][1][3]&0xFE3FFFF|(p->txios_highpcl_DCS_EPSK<<18);
   TXCW[0][1][4]= TXCW[0][1][4]&0xFE3FFFF|(p->txios_highpcl_PCS_EPSK<<18);

   TXCW[1][0][1]= TXCW[1][0][1]&0xFE3FFFF|(p->txios_lowpcl_850_GMSK<<18);
   TXCW[1][0][2]= TXCW[1][0][2]&0xFE3FFFF|(p->txios_lowpcl_900_GMSK<<18);
   TXCW[1][0][3]= TXCW[1][0][3]&0xFE3FFFF|(p->txios_lowpcl_DCS_GMSK<<18);
   TXCW[1][0][4]= TXCW[1][0][4]&0xFE3FFFF|(p->txios_lowpcl_PCS_GMSK<<18);

   TXCW[1][1][1]= TXCW[1][1][1]&0xFE3FFFF|(p->txios_lowpcl_850_EPSK<<18);
   TXCW[1][1][2]= TXCW[1][1][2]&0xFE3FFFF|(p->txios_lowpcl_900_EPSK<<18);
   TXCW[1][1][3]= TXCW[1][1][3]&0xFE3FFFF|(p->txios_lowpcl_DCS_EPSK<<18);
   TXCW[1][1][4]= TXCW[1][1][4]&0xFE3FFFF|(p->txios_lowpcl_PCS_EPSK<<18);

   // TXCW[i][j][k]=TXCW[i][j][k]&0xFFFFF0F|(l1_rf_table.xtxitc_pcl_tab[i][j][k]<<4 );

   TXCW[0][0][1]=TXCW[0][0][1]&0xFFFFF0F|( p1->txitc_highpcl_850_GMSK<<4);
   TXCW[0][0][2]=TXCW[0][0][2]&0xFFFFF0F|( p1->txitc_highpcl_900_GMSK<<4);
   TXCW[0][0][3]=TXCW[0][0][3]&0xFFFFF0F|( p1->txitc_highpcl_DCS_GMSK<<4);
   TXCW[0][0][4]=TXCW[0][0][4]&0xFFFFF0F|( p1->txitc_highpcl_PCS_GMSK<<4);

   TXCW[0][1][1]=TXCW[0][1][1]&0xFFFFF0F|( p1->txitc_highpcl_850_EPSK<<4);
   TXCW[0][1][2]=TXCW[0][1][2]&0xFFFFF0F|( p1->txitc_highpcl_900_EPSK<<4);
   TXCW[0][1][3]=TXCW[0][1][3]&0xFFFFF0F|( p1->txitc_highpcl_DCS_EPSK<<4);
   TXCW[0][1][4]=TXCW[0][1][4]&0xFFFFF0F|( p1->txitc_highpcl_PCS_EPSK<<4);

   TXCW[1][0][1]=TXCW[1][0][1]&0xFFFFF0F|( p1->txitc_lowpcl_850_GMSK<<4);
   TXCW[1][0][2]=TXCW[1][0][2]&0xFFFFF0F|( p1->txitc_lowpcl_900_GMSK<<4);
   TXCW[1][0][3]=TXCW[1][0][3]&0xFFFFF0F|( p1->txitc_lowpcl_DCS_GMSK<<4);
   TXCW[1][0][4]=TXCW[1][0][4]&0xFFFFF0F|( p1->txitc_lowpcl_PCS_GMSK<<4);

   TXCW[1][1][1]=TXCW[1][1][1]&0xFFFFF0F|( p1->txitc_lowpcl_850_EPSK<<4);
   TXCW[1][1][2]=TXCW[1][1][2]&0xFFFFF0F|( p1->txitc_lowpcl_900_EPSK<<4);
   TXCW[1][1][3]=TXCW[1][1][3]&0xFFFFF0F|( p1->txitc_lowpcl_DCS_EPSK<<4);
   TXCW[1][1][4]=TXCW[1][1][4]&0xFFFFF0F|( p1->txitc_lowpcl_PCS_EPSK<<4);

   //TXCW[i][j][k]=TXCW[i][j][k]&0xFFE3FFF|(l1_rf_table.xtxmod_gc_tab[i][j][k]<<14 );

   TXCW[0][0][1]=TXCW[0][0][1] &0xFFE3FFF|(((p2->hbmod_gc_highpcl_850_GMSK<<1)+p3->lbmod_gc_highpcl_850_GMSK)<<14);
   TXCW[0][0][2]=TXCW[0][0][2] &0xFFE3FFF|(((p2->hbmod_gc_highpcl_900_GMSK<<1)+p3->lbmod_gc_highpcl_900_GMSK)<<14);
   TXCW[0][0][3]=TXCW[0][0][3] &0xFFE3FFF|(((p2->hbmod_gc_highpcl_DCS_GMSK<<1)+p3->lbmod_gc_highpcl_DCS_GMSK)<<14);
   TXCW[0][0][4]=TXCW[0][0][4] &0xFFE3FFF|(((p2->hbmod_gc_highpcl_PCS_GMSK<<1)+p3->lbmod_gc_highpcl_PCS_GMSK)<<14);

   TXCW[0][1][1]=TXCW[0][1][1] &0xFFE3FFF|(((p2->hbmod_gc_highpcl_850_EPSK<<1)+p3->lbmod_gc_highpcl_850_EPSK)<<14);
   TXCW[0][1][2]=TXCW[0][1][2] &0xFFE3FFF|(((p2->hbmod_gc_highpcl_900_EPSK<<1)+p3->lbmod_gc_highpcl_900_EPSK)<<14);
   TXCW[0][1][3]=TXCW[0][1][3] &0xFFE3FFF|(((p2->hbmod_gc_highpcl_DCS_EPSK<<1)+p3->lbmod_gc_highpcl_DCS_EPSK)<<14);
   TXCW[0][1][4]=TXCW[0][1][4] &0xFFE3FFF|(((p2->hbmod_gc_highpcl_PCS_EPSK<<1)+p3->lbmod_gc_highpcl_PCS_EPSK)<<14);

   TXCW[1][0][1]=TXCW[1][0][1] &0xFFE3FFF|(((p2->hbmod_gc_lowpcl_850_GMSK<<1) +p3->lbmod_gc_lowpcl_850_GMSK )<<14);
   TXCW[1][0][2]=TXCW[1][0][2] &0xFFE3FFF|(((p2->hbmod_gc_lowpcl_900_GMSK<<1) +p3->lbmod_gc_lowpcl_900_GMSK )<<14);
   TXCW[1][0][3]=TXCW[1][0][3] &0xFFE3FFF|(((p2->hbmod_gc_lowpcl_DCS_GMSK<<1) +p3->lbmod_gc_lowpcl_DCS_GMSK )<<14);
   TXCW[1][0][4]=TXCW[1][0][4] &0xFFE3FFF|(((p2->hbmod_gc_lowpcl_PCS_GMSK<<1) +p3->lbmod_gc_lowpcl_PCS_GMSK )<<14);

   TXCW[1][1][1]=TXCW[1][1][1] &0xFFE3FFF|(((p2->hbmod_gc_lowpcl_850_EPSK<<1) +p3->lbmod_gc_lowpcl_850_EPSK )<<14);
   TXCW[1][1][2]=TXCW[1][1][2] &0xFFE3FFF|(((p2->hbmod_gc_lowpcl_900_EPSK<<1) +p3->lbmod_gc_lowpcl_900_EPSK )<<14);
   TXCW[1][1][3]=TXCW[1][1][3] &0xFFE3FFF|(((p2->hbmod_gc_lowpcl_DCS_EPSK<<1) +p3->lbmod_gc_lowpcl_DCS_EPSK )<<14);
   TXCW[1][1][4]=TXCW[1][1][4] &0xFFE3FFF|(((p2->hbmod_gc_lowpcl_PCS_EPSK<<1) +p3->lbmod_gc_lowpcl_PCS_EPSK )<<14);
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_TX_Power_Control_Table_Update(void)
{
   #if IS_TX_POWER_CONTROL_SUPPORT
   sRF_TX_POWERFEEDBACK_VARIABLE *p=&l1d_rf_custom_input_data.RF_TX_PowerFeedback_Variable;

   closed_loop_txpc_type = p->xCLOSED_LOOP_TXPC_TYPE;

      #if IS_TXPC_CL_AUXADC_SUPPORT
   TQ_TxSampleOffsetGMSK = p->xQB_TX_SAMPLE_OFFSET_GMSK;
         #if IS_EPSK_TX_SUPPORT
   TQ_TxSampleOffsetEPSK = p->xQB_TX_SAMPLE_OFFSET_EPSK;
         #endif
      #endif

      #if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
         #if IS_CHIP_MT6256
   txpc_epsk_tp_slope_lb = p->xTXPC_EPSK_TP_SLOPE_LB;
   txpc_epsk_tp_slope_hb = p->xTXPC_EPSK_TP_SLOPE_HB;
         #elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
   txpc_epsk_tp_slope_lb = p->xTXPC_EPSK_TP_SLOPE_LB;
   txpc_epsk_tp_slope_hb = p->xTXPC_EPSK_TP_SLOPE_HB;
         #endif
      #endif
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_RF_RX_Band_Update( void )
{
   #if IS_RF_MT6162
   sRF_RX_BAND_VARIABLE *p=&l1d_rf_custom_input_data.RF_RX_Band_Variable;
   SDATA_RX_BAND[1] = (SDATA_RX_BAND[1]&0xFFFFFFF0)|(p->xGSM850_PATH_SEL&0xF);
   SDATA_RX_BAND[2] = (SDATA_RX_BAND[2]&0xFFFFFFF0)|(p->xGSM_PATH_SEL   &0xF);
   SDATA_RX_BAND[3] = (SDATA_RX_BAND[3]&0xFFFFFFF0)|(p->xDCS_PATH_SEL   &0xF);
   SDATA_RX_BAND[4] = (SDATA_RX_BAND[4]&0xFFFFFFF0)|(p->xPCS_PATH_SEL   &0xF);
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_Others_Update( void )
{
   sRF_OTHERS_VARIABLE *p=&l1d_rf_custom_input_data.RF_Others_Variable;
   gsm_err_det_id      =p->xGSM_ERR_DET_ID;
   l1d_rf.egsm_disable =p->xEGSM_DISABLE;
   TxPropagationDelay  =p->xTX_PROPAGATION_DELAY;
   #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT
   TQ_EPSK_TX_delay    =p->xTQ_EPSK_TX_DELAY;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_AFC_Tracking_Update( void )
{
   extern unsigned char  crystal_rxgap_afc_prediction ;
   extern unsigned short afc_prediction_interval;
   extern unsigned char  afc_prediction_decaying_factor;
   sRF_AFC_TRACKING_VARIABLE *p=&l1d_rf_custom_input_data.RF_AFC_Tracking_Variable;
   //extern
   crystal_rxgap_afc_prediction  =p->xAFC_PREDICTION_ON;
   afc_prediction_interval       =p->xAFC_PREDICTION_INTERVAL;
   afc_prediction_decaying_factor=p->xAFC_PREDICTION_DECAYING_FACTOR;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_RF_CLK_Buffer_Variable_Update( void )
{
   #if IS_RF_MT6162
   sRF_CLK_BUFFER_VARIABLE *p=&l1d_rf_custom_input_data.RF_CLK_Buffer_Variable;
   CLK_EN_TABLE[0] = p->xCLK1_EN;
   CLK_EN_TABLE[1] = p->xCLK2_EN;
   CLK_EN_TABLE[2] = p->xCLK3_EN;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_CLK_Buffer_Variable_Reset( void )
{
   #if IS_RF_MT6162
   L1D_RF_PowerOn();
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif /* IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2 */

void L1D_RF_Custom_Table_Update_V2( void )
{
#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
   if(l1d_rf_custom_input_data.is_data_update)
   {
      L1D_RF_Custom_Table_Update_V2_No_Check();
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_Table_Update_V2_No_Check( void )
{
#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
   L1D_RF_Custom_BPI_DefaultValue_Handler();
   L1D_RF_Custom_Timing_DefaultValue_Handler();
   L1D_RF_Custom_BPI_Table_Update();
   L1D_RF_Custom_Timing_Table_Update();

   L1D_RF_Custom_APC_Compensate_DefaultValue_Handler();
   L1D_RF_Custom_APC_Compensate_Update();

   L1D_RF_Custom_TX_PCL_DefaultValue_Handler();
   L1D_RF_Custom_TX_PCL_Table_Update();

   L1D_RF_Custom_TX_Power_Control_DefaultValue_Handler();
   L1D_RF_Custom_TX_Power_Control_Table_Update();

   L1D_RF_Custom_RF_RX_Band_DefaultValue_Handler();
   L1D_RF_Custom_RF_RX_Band_Update();

   L1D_RF_Custom_Others_DefaultValue_Handler();
   L1D_RF_Custom_Others_Update();

   L1D_RF_Custom_AFC_Tracking_DefaultValue_Handler();
   L1D_RF_Custom_AFC_Tracking_Update();

   L1D_RF_Custom_RF_CLK_Buffer_Variable_DefaultValue_Handler();
   L1D_RF_Custom_RF_CLK_Buffer_Variable_Update();
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_RF_MT6251RF
void L1D_RF_OBB_trace_setting( void )
{
   if( !( BSIread.flag & BSI_READBACK_ENABLE ) )
   {  BSIread.flag |= BSI_READBACK_ENABLE;
      if( l1d_rf.band < FrequencyBand1800 )
      {  BSI_READ_INDICATE_ADDR(99); }
      else
      {  BSI_READ_INDICATE_ADDR(98); }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

void L1D_RF_SetWakeUpFlag( void )
{
#if IS_DYNAMIC_MACRO_SUPPORT
   l1d_rf2.is_wakeup = 1;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_ClearWakeUpFlag( void )
{
#if IS_DYNAMIC_MACRO_SUPPORT
   l1d_rf2.is_wakeup = 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Set_PowerOn( unsigned char is_stage1, unsigned char is_stage2 )
{
#if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
   l1d_rf.is_power_on_stage_1 = is_stage1;
   l1d_rf.is_power_on_stage_2 = is_stage2;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned char L1D_RF_Get_PowerOn_Stage( unsigned char stage_idx )
{
   unsigned char return_status = 0;
#if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
   if( stage_idx==1 )
   {  return_status = l1d_rf.is_power_on_stage_1;  }
   else if( stage_idx==2 )
   {  return_status = l1d_rf.is_power_on_stage_2;  }
#endif
   return return_status;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_CHIP_MT6276 || IS_CHIP_MT6573 || IS_CHIP_MT6575
// Include for HAL activity, but HAL is done after RHR...
#include "dcl.h"

void L1D_PMU_VRF18Setting( char vrf18on )
{
   DCL_HANDLE handle;
   PMU_CTRL_LDO_BUCK_SET_EN val;

   if( L1D_PMU_IS_FIX_VRF1828SETTING() )
      vrf18on = KAL_TRUE; /* workaround for BT EVM performace due to VRF18/28 change (keep VRF18/28 always ON) */

   #if IS_CHIP_MT6276_S00
   vrf18on    = KAL_TRUE; /* Vrf18 can be turned on ONLY and can not be turned off */
   #endif
   val.enable = vrf18on ? KAL_TRUE : KAL_FALSE;
   val.mod    = VRF18;
   handle     = DclPMU_Open( DCL_PMU, FLAGS_NONE );
   DclPMU_Control( handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val );
   DclPMU_Close( handle );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_PMU_VRF28Setting( char vrf28on )
{
   #if IS_CHIP_MT6276_S00
   /* Vrf28 is not workable in MT6276E1 */
   #else
   DCL_HANDLE handle;
   PMU_CTRL_LDO_BUCK_SET_EN val;

   if( L1D_PMU_IS_FIX_VRF1828SETTING() )
      vrf28on = KAL_TRUE; /* workaround for BT EVM performace due to VRF18/28 change (keep VRF18/28 always ON) */

   val.enable = vrf28on ? KAL_TRUE : KAL_FALSE;
   val.mod    = VRF;
   handle     = DclPMU_Open( DCL_PMU, FLAGS_NONE );
   DclPMU_Control( handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val );
   DclPMU_Close( handle );
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

void L1D_ABB_Set_ADCMUX_DLPad( void )
{
#if IS_RF_MT6162 && ( IS_CHIP_MT6276 || IS_CHIP_MT6573 || IS_CHIP_MT6575 )
   unsigned short d16;

   /* Set DL_INPUT_SEL_MODE to SW control mode */
   #if IS_CHIP_MT6573
   d16 = HW_READ(PMIC_RESERVE_CON0);
   d16 |= 0x0002;
   HW_WRITE(PMIC_RESERVE_CON0, d16);

   #elif IS_CHIP_MT6276_S01
   d16 = HW_READ(BBRX_CON3);
   d16 |=  0x0001;
   HW_WRITE(BBRX_CON3, d16);

   #elif IS_CHIP_MT6575
   d16  = HW_READ(BBRX_CON3);
   d16 &= ~0x0003;
   d16 |=  0x0002;
   HW_WRITE(BBRX_CON3, d16);
   #endif

   /* Switch ADC MUX to DL Pads (OH uses the same path as O3)*/
   d16 = HW_READ(BBRX_CON0);
   d16 &= ~0x0300;
   HW_WRITE(BBRX_CON0, d16);
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*===============================================================================*/
/* for OthelloH                                                                  */
/*===============================================================================*/
#if IS_RF_MT6162
#define RX_GAIN_LNA_0              0x08300300L
#define RX_GAIN_TEST_DISABLE       0x09031000L
#define CW08_TXIQMMCAL             0x00826464L /* set PLL to type2 in the calibration */
#define CW08_INIT                  0x00826424L

#define POWER_BB                    346 /* 1.35*256, S(8,8) */
#define GAIN_PA                    7936 /*   31*256, S(8,8) */
#define GAIN_PBBOFS               -2304 /*   -9*256, S(8,8) */
#define GAIN_CPL_LB               -8896 /*  -34.75*256, S(8,8) */
#define GAIN_CPL_HB               -8381 /*  -32.74*256, S(8,8) */
#define DCOFFSET_MAX                127 /* (800-6.25)mV => convert to OH DAC value: 127 ((800-6.25)/6.25=127) */
#define DCOFFSET_CLIPPING_THRESHOLD  63 /* (400-6.25)mV => convert to OH DAC value:  63 ((400-6.25)/6.25= 63) */
#define TQ_DELAY_RX_IN_TXIQMM        94
#define TQ_DELAY_TX_IN_TXIQMM        70
   #if IS_CHIP_MT6276_S00 || IS_CHIP_MT6573_S00
#define TX_DC_COMP_THRESHOLD        127 /* for 6276E1 and 6573E1, BFE DAC : -127~127 */
   #else
#define TX_DC_COMP_THRESHOLD        114 /* for 6276E2 and 6573E2, BFE DAC : -114~114 */
   #endif
#define TX_PHASE_COMP_THRESHOLD      27 /* BFE DAC :  -27~27  */
   #if IS_CHIP_MT6575
#define TX_GAIN_COMP_THRESHOLD       62 /* BFE DAC :  -62~62  */
   #else
#define TX_GAIN_COMP_THRESHOLD       29 /* BFE DAC :  -29~29  */
   #endif
#define UNITY_ONE                 32768 /* 1 => cahnge to U(1,15)*/
#define RAD_2_DEG                 58670 /* 180/pi = 57.296... => change to U(6,10) */
#define DEG_2_BFEDAC              36571 /* 1/0.112 = 8.929... => change to U(4,12) (1 BFEDAC is equal to 0.112 degree) */
#define K_BB                        179 /* gain_bb_1000/(gain_bb_300-gain_bb_1000), in U(5,11) (linear value) */
#define K_RF                       1790 /* gain_bb_1000, in U(1,15) (linear value) */
   #if IS_CHIP_MT6276_S00 || IS_CHIP_MT6573_S00
#define VOLT_2_DCDAC               3629 /* for 6276E1 and 6573E1, 127(DAC) <=> 35(mv); 127/(0.035) = 3629 */
   #else
#define VOLT_2_DCDAC               2000 /* for 6276E2 and 6573E2, 114(DAC) <=> 57(mv); 114/(0.057) = 2000 */
   #endif

unsigned char TX_GAINRF_MAPPING[4][16] =
{
   /* GSM850 */
   /* PCL 19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4 */
   {       6, 6, 6, 5, 5, 5, 5, 4, 4, 3, 3, 3, 3, 3, 3, 3 },
   /* GSM900 */
   /* PCL 19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4 */
   {       6, 6, 6, 5, 5, 5, 5, 4, 4, 3, 3, 3, 3, 3, 3, 3 },
   /* DCS1800 */
   /* PCL 15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 */
   {       6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 4, 4, 3, 3, 3, 3 },
   /* PCS1900 */
   /* PCL 15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 */
   {       6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 4, 4, 3, 3, 3, 3 },
};

signed short BBGAIN_DECODE_TABLE[14][2] =
{
   { 0, -7},
   { 0, -4},
   { 0, -1},
   { 0,  2},
   { 0,  5},
   { 6,  2},
   { 6,  5},
   { 6,  8},
   {12,  5},
   {12,  8},
   {12, 11},
   {18,  8},
   {18, 11},
   {18, 14},
};

unsigned long read_back;
unsigned long TX_GAIN_READ_ADDRESS[5] = {  0xBB, 0xBC, 0xBD, 0xBE, 0xBF  };
unsigned long RECORD_DATA[4];

   #if IS_RF_RX_DCOC_SUPPORT
const signed int G_PGA_TABLE[8] =
{
    /* 6415*10^(G_pga/20) @ different PGA gain */
    2865, /* @ gain = -7dB,  2865.475244 */
    4047, /* @ gain = -4dB,  4047.591365 */
    5717, /* @ gain = -1dB,  5717.374768 */
    8076, /* @ gain =  2dB,  8076.006517 */
   11407, /* @ gain =  5dB, 11407.66242  */
   16113, /* @ gain =  8dB, 16113.75146  */
   22761, /* @ gain = 11dB, 22761.27892  */
   32151, /* @ gain = 14dB, 32151.16104  */
};
   #endif

   #if IS_RF_TX_CALIBRATION_SUPPORT
const sTX_GAIN_BB_MAPPING TX_GAIN_BB_TABLE[17] =
{
   {    0,  1026 }, /* gain_bb_inverse = 10^(-((6-(gain_bb_dac/32))/20))*2^11 */
   {   64,  1292 },
   {  128,  1627 },
   {  192,  2048 },
   {  256,  2578 },
   {  320,  3246 },
   {  384,  4086 },
   {  448,  5144 },
   {  512,  6476 },
   {  576,  8153 },
   {  640, 10264 },
   {  704, 12922 },
   {  768, 16268 },
   {  832, 20480 },
   {  896, 25783 },
   {  960, 32459 },
   { 1024, 40863 },
};
   #endif

#endif

#if IS_BBTXRX_CHIP_DESIGN_VER_2
void L1D_RF_IMM_SEND_BSI( char type )
{
   #if IS_RF_MT6162
   IMM_MODE_BEGIN( IMMMASK_BSI );
   switch( type )
   {
      case RX_LNA_0:
         IMM_SEND_BSI( SCTRL_IMOD(0,30), RX_GAIN_LNA_0 ); /* set Gain_LNA = -7dB */
         break;
      case RX_TEST_DISABLE:
         /* disable Rx Gain control overwrites (0x90, RX_GAIN_TEST), RXGAIN_OW_EN[8]=0 */
         IMM_SEND_BSI( SCTRL_IMOD(0,30), RX_GAIN_TEST_DISABLE );
         break;
      case PLL_TYPE2_SWITCH:
         /* set PLL to Type2 for the TXIQMM calibration */
         IMM_SEND_BSI( SCTRL_IMOD(0,30), CW08_TXIQMMCAL );
         break;
      case PLL_TYPE1_SWITCH:
         /* set PLL to Type1 for the normal operation */
         IMM_SEND_BSI( SCTRL_IMOD(0,30), CW08_INIT );
         break;
   }
   IMM_MODE_END();
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_GetData( unsigned long data, char idx )
{
   #if IS_RF_RX_DCOC_SUPPORT
   RECORD_DATA[idx] = data;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Get_RXDCOffset( FrequencyBand band, signed short idx )
{
   #if IS_RF_RX_DCOC_SUPPORT
   signed short dc_i, dc_q;

   /*               *6.25                    */
   /* DCoffset_DAC  <===>            Voltage */
   /*    -127~+127  <===>  -793.75~+793.75mV */

   if( idx==4 )
   {
      dc_i = l1d_rf.rx_dc_i;
      dc_q = l1d_rf.rx_dc_q;
      l1d_rf2.rx_dac_to_voltage_i = (signed short) ( (dc_i*2000)/(G_PGA_TABLE[4]) );
      l1d_rf2.rx_dac_to_voltage_q = (signed short) ( (dc_q*2000)/(G_PGA_TABLE[4]) );
   }
   else
   {
      /* get results of previous BURST from DSP */
      dc_i = -l1d_rf.rx_dc_i;
      dc_q = -l1d_rf.rx_dc_q;
      dc_i = (signed short) ( (dc_i*2000*8)/(l1d_rf2.rx_dac_to_voltage_i*G_PGA_TABLE[4]) );
                    /* (rx_I_offset*2000*8)/(l1d_rf2.rx_dac_to_voltage_i)*(6415*10^(G_pga/20)); */
      dc_q = (signed short) ( (dc_q*2000*8)/(l1d_rf2.rx_dac_to_voltage_q*G_PGA_TABLE[4]) );
                    /* (rx_Q_offset*2000*8)/(l1d_rf2.rx_dac_to_voltage_q)*(6415*10^(G_pga/20)); */
                    /* multiplying 8 is because rx_dac_to_voltage_i/q is stored in the S(4,3) format */

      /* clip the DC offset measurement result and multiply scale factor */
      /* the range of compensation DAC value is -127~+127 */
      if( dc_i > DCOFFSET_MAX )
         l1d_rf2.rx_dc_offset_i[band-1][idx] = (signed short) (  DCOFFSET_MAX<<ALPHA_FILTER_SCALE );
      else if( dc_i < -DCOFFSET_MAX )
         l1d_rf2.rx_dc_offset_i[band-1][idx] = (signed short) (-(DCOFFSET_MAX<<ALPHA_FILTER_SCALE));
      else
         l1d_rf2.rx_dc_offset_i[band-1][idx] = (signed short) (dc_i<<ALPHA_FILTER_SCALE);

      if( dc_q > DCOFFSET_MAX )
         l1d_rf2.rx_dc_offset_q[band-1][idx] = (signed short) (  DCOFFSET_MAX<<ALPHA_FILTER_SCALE );
      else if( dc_q < -DCOFFSET_MAX )
         l1d_rf2.rx_dc_offset_q[band-1][idx] = (signed short) (-(DCOFFSET_MAX<<ALPHA_FILTER_SCALE));
      else
         l1d_rf2.rx_dc_offset_q[band-1][idx] = (signed short) (dc_q<<ALPHA_FILTER_SCALE);
   }
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* for OH, on-the-fly RX DCOffset Calibration */
void L1D_RF_Update_DCoffset( unsigned char slot, FrequencyBand band, unsigned long gain_setting )
{
   #if IS_RF_RX_DCOC_SUPPORT
   /* Voltage  <==>  ADC_value */
   /*  2000mV  <==>       6415 */

   /*               *6.25                    */
   /* DCoffset_DAC  <===>            Voltage */
   /*    -127~+127  <===>  -793.75~+793.75mV */
   /*     -63~ +63  <===>  -393.75~+393.75mV */

   signed short rx_I_offset, rx_Q_offset;
   signed short bbgain_setting;
   signed short G_biquad, G_pga;
   signed short rx_I_offset_DAC, rx_Q_offset_DAC;
   signed short rx_I_offset_DAC_temp, rx_Q_offset_DAC_temp;

   bbgain_setting = gain_setting&0xF;
   G_biquad = BBGAIN_DECODE_TABLE[bbgain_setting][0];
   G_pga    = BBGAIN_DECODE_TABLE[bbgain_setting][1];
   rx_I_offset = (signed short)( (-l1d_rf.rx_dc_i*2000*8)/(l1d_rf2.rx_dac_to_voltage_i*G_PGA_TABLE[(G_pga+7)/3]) );
                                  /* (rx_I_offset*2000*8)/(l1d_rf2.rx_dac_to_voltage_i)*(6514*10^(G_pga/20)); */
   rx_Q_offset = (signed short)( (-l1d_rf.rx_dc_q*2000*8)/(l1d_rf2.rx_dac_to_voltage_q*G_PGA_TABLE[(G_pga+7)/3]) );
                                  /* (rx_Q_offset*2000*8)/(l1d_rf2.rx_dac_to_voltage_q)*(6514*10^(G_pga/20)); */
                                  /* multiplying 8 is because rx_dac_to_voltage_i/q is stored in the S(4,3) format */
   /* clip the DC offset measurement result and multiply scale factor */
   if( rx_I_offset > DCOFFSET_CLIPPING_THRESHOLD )
      rx_I_offset_DAC = (DCOFFSET_CLIPPING_THRESHOLD<<ALPHA_FILTER_SCALE);
   else if( rx_I_offset < -DCOFFSET_CLIPPING_THRESHOLD )
      rx_I_offset_DAC = (-(DCOFFSET_CLIPPING_THRESHOLD<<ALPHA_FILTER_SCALE));
   else
      rx_I_offset_DAC =(rx_I_offset<<ALPHA_FILTER_SCALE);

   if( rx_Q_offset > DCOFFSET_CLIPPING_THRESHOLD )
      rx_Q_offset_DAC = (DCOFFSET_CLIPPING_THRESHOLD<<ALPHA_FILTER_SCALE);
   else if( rx_Q_offset < -DCOFFSET_CLIPPING_THRESHOLD )
      rx_Q_offset_DAC = (-(DCOFFSET_CLIPPING_THRESHOLD<<ALPHA_FILTER_SCALE));
   else
      rx_Q_offset_DAC = (rx_Q_offset<<ALPHA_FILTER_SCALE);


   rx_I_offset_DAC_temp = l1d_rf2.rx_dc_offset_i[band-1][G_biquad/6];
   rx_Q_offset_DAC_temp = l1d_rf2.rx_dc_offset_q[band-1][G_biquad/6];

   /* use the alpha filter to do the calculation */
   if( ALPHA_FILTER_COEFF == 0 )
   {
      rx_I_offset_DAC_temp += rx_I_offset_DAC;
      rx_Q_offset_DAC_temp += rx_Q_offset_DAC;
   }
   else
   {
      if( rx_I_offset_DAC > 0 )
         rx_I_offset_DAC_temp += (  ( rx_I_offset_DAC+(1<<(ALPHA_FILTER_COEFF-1)))>>ALPHA_FILTER_COEFF  );
      else
         rx_I_offset_DAC_temp += (-((-rx_I_offset_DAC+(1<<(ALPHA_FILTER_COEFF-1)))>>ALPHA_FILTER_COEFF));
      if( rx_Q_offset_DAC > 0 )
         rx_Q_offset_DAC_temp += (  ( rx_Q_offset_DAC+(1<<(ALPHA_FILTER_COEFF-1)))>>ALPHA_FILTER_COEFF  );
      else
         rx_Q_offset_DAC_temp += (-((-rx_Q_offset_DAC+(1<<(ALPHA_FILTER_COEFF-1)))>>ALPHA_FILTER_COEFF));
   }

   /* clip the DC offset calculation result */
   /* the range of compensation DAC value is (-127~+127)*(scale factor) */
   if( rx_I_offset_DAC_temp > DCOFFSET_MAX<<ALPHA_FILTER_SCALE )
      l1d_rf2.rx_dc_offset_i[band-1][G_biquad/6] = ( DCOFFSET_MAX<<ALPHA_FILTER_SCALE);
   else if( rx_I_offset_DAC_temp < -(DCOFFSET_MAX<<ALPHA_FILTER_SCALE) )
      l1d_rf2.rx_dc_offset_i[band-1][G_biquad/6] = (-(DCOFFSET_MAX<<ALPHA_FILTER_SCALE));
   else
      l1d_rf2.rx_dc_offset_i[band-1][G_biquad/6] = rx_I_offset_DAC_temp;

   if( rx_Q_offset_DAC_temp > DCOFFSET_MAX<<ALPHA_FILTER_SCALE )
      l1d_rf2.rx_dc_offset_q[band-1][G_biquad/6] = ( DCOFFSET_MAX<<ALPHA_FILTER_SCALE);
   else if( rx_Q_offset_DAC_temp < -(DCOFFSET_MAX<<ALPHA_FILTER_SCALE) )
      l1d_rf2.rx_dc_offset_q[band-1][G_biquad/6] = (-(DCOFFSET_MAX<<ALPHA_FILTER_SCALE));
   else
      l1d_rf2.rx_dc_offset_q[band-1][G_biquad/6] = rx_Q_offset_DAC_temp;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int L1D_RF_SetRXDelayInTXIQMM( int tq_cnt )
{
   int return_tq_cnt = tq_cnt;
   #if IS_RF_TX_CALIBRATION_SUPPORT
   if( L1D_RF_TXIQMM_Check() )
   {  return_tq_cnt = TQ_SLOT0_BEGIN+TQ_DELAY_RX_IN_TXIQMM;  }
   #endif
   return return_tq_cnt;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int L1D_RF_SetTXDelayInTXIQMM( int tq_cnt )
{
   int return_tq_cnt = tq_cnt;
   #if IS_RF_TX_CALIBRATION_SUPPORT
   if( L1D_RF_TXIQMM_Check() )
   {  return_tq_cnt = TQ_SLOT0_BEGIN+TQ_DELAY_TX_IN_TXIQMM;  }
   #endif
   return return_tq_cnt;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Calibration_Start( void )
{
   #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
   l1d_rf.cal_band  = 1; /* start from FrequencyBand850 */
   #else
   l1d_rf.cal_band  = 0;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_RXDCOC_Start( void )
{
   #if IS_RF_RX_DCOC_SUPPORT
   l1d_rf2.is_rx_cal = 1;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_RXDCOC_End( void )
{
   #if IS_RF_RX_DCOC_SUPPORT
   l1d_rf2.is_rx_cal = 0;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

char L1D_RF_RXDCOC_Check( void )
{
   char return_value = 0;
   #if IS_RF_RX_DCOC_SUPPORT
   return_value = l1d_rf2.is_rx_cal;
   #endif
   return return_value;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXIQMM_Start( char tx_cal )
{
   #if IS_RF_TX_CALIBRATION_SUPPORT
   l1d_rf2.is_tx_cal = tx_cal;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_TXIQMM_End( void )
{
   #if IS_RF_TX_CALIBRATION_SUPPORT
   l1d_rf2.is_tx_cal = 0;
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

char L1D_RF_TXIQMM_Check( void )
{
   char return_value = 0;
   #if IS_RF_TX_CALIBRATION_SUPPORT
   return_value = l1d_rf2.is_tx_cal;
   #endif
   return return_value;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Get_TXIQMM_Results_DCBB( short dc_i_1, short dc_i_2, short dc_q_1, short dc_q_2 )
{
   #if IS_RF_TX_CALIBRATION_SUPPORT
   l1d_rf2.tx_dc_bb_i[l1d_rf.cal_band-1] = ( dc_i_1-(((dc_i_2-dc_i_1)*K_BB)>>11) ); /* calculate DC_BB */
   l1d_rf2.tx_dc_bb_q[l1d_rf.cal_band-1] = ( dc_q_1-(((dc_q_2-dc_q_1)*K_BB)>>11) ); /* >>11 */
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Get_TXIQMM_Results( short g, short phi, short dc_i, short dc_q, unsigned char idx )
{
   #if IS_RF_TX_CALIBRATION_SUPPORT
   l1d_rf2.tx_gain_error[l1d_rf.cal_band-1][idx-2]  = g;
   l1d_rf2.tx_phase_error[l1d_rf.cal_band-1][idx-2] = phi;
   l1d_rf2.tx_dc_rf_i[l1d_rf.cal_band-1][idx-2] = ( ((dc_i-l1d_rf2.tx_dc_bb_i[l1d_rf.cal_band-1])*K_RF)>>15 ); /* calculate DC_RF_3 */
   l1d_rf2.tx_dc_rf_q[l1d_rf.cal_band-1][idx-2] = ( ((dc_q-l1d_rf2.tx_dc_bb_q[l1d_rf.cal_band-1])*K_RF)>>15 ); /* >>15 */
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Set_BULON( void )
{
   #if IS_RF_TX_CALIBRATION_SUPPORT
   unsigned short d16;

   /* set BTXEN to BTXFS setup up time in quarter bit unit */
   /* set 97h to DAC_ON[15:8] in TDMA_BULCON1 (151Qbits) QB_TX_FENA_2_FSYNC (152) */
   d16 = HW_READ(TDMA_BULCON1);
   d16 &= ~0xFF00;
   d16 |=  0x9800;
   HW_WRITE(TDMA_BULCON1, d16);

   /* set when the TX compensation action starts after TX_EN */
   /* set 96h to BFE_TXCOMP_HYS[15:8] in TDMA_BULCON2 (150Qbits) QB_TX_FENA_2_FSYNC (152) */
   d16 = HW_READ(TDMA_BULCON2);
   d16 &= ~0xFF00;
   d16 |=  0x9600;
   HW_WRITE(TDMA_BULCON2, d16);
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Recover_BULON( void )
{
   #if IS_RF_TX_CALIBRATION_SUPPORT
   L1D_RF_Init_DLUL();
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif /* IS_BBTXRX_CHIP_DESIGN_VER_2 */

#if IS_RF_MT6162
char L1D_RF_Get6162Version( void )
{
   char return_version = 0;
   if( (l1d_rf2.mt6162_rfid==RF_MT6162_ID_REV0_0A)||(l1d_rf2.mt6162_rfid==RF_MT6162_ID_REV0_0B)||(l1d_rf2.mt6162_rfid==RF_MT6162_ID_REV0_1A)||(l1d_rf2.mt6162_rfid==RF_MT6162_ID_REV0_1B) )
   {  return_version = 1;  } /* E1 version */
   else
   {  return_version = 2;  } /* E2 version */
   return return_version;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

char L1D_RF_CheckDMPower( void )
{
   return (l1d_rf2.is_2g_on&0x1); /* use bit[0] to indicate the 2G state */
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned long L1D_RF_GetClockControl( void )
{
   unsigned long return_clock = 0xE20020F|(CLK_EN_TABLE[2]<<12)|(CLK_EN_TABLE[1]<<11)|(CLK_EN_TABLE[0]<<10);
   return return_clock;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned long L1D_RF_SetTxGainWrite( unsigned short mod_type, char slot_idx, signed short tx_power, FrequencyBand rf_band )
{
   signed short     gain_det;
   signed short     gain_rf = 0;
   signed short     gain_bb = 0;
   signed short     gain_cpl;
   signed short     power_dbm = tx_power;
   signed short     power_dbm_oh = tx_power;
   signed short     lowest_dbm = LOWEST_TX_POWER[(int)rf_band];
   unsigned long    tx_gain_write;
   #if IS_EPSK_TX_SUPPORT
   signed short     power_idx, rollback_gain;
   unsigned short   lb_or_hb = (rf_band<=FrequencyBand900) ? 0 : 1;
   unsigned short   weighted_PA_gain;
   unsigned short   n = WEIGHT(1.0);
   const sRAMPDATA *band;
   static   const   sARFCN_SECTION*  weight;    // Must be static since chips before M6229 will only query if IS_1ST_TX_SLOT
   #endif

   if( power_dbm > (lowest_dbm+2*15) )
   {  power_dbm = lowest_dbm+2*15;  }
   else if( power_dbm < lowest_dbm )
   {  power_dbm = lowest_dbm;  }

   #if IS_EPSK_TX_SUPPORT
   if( (mod_type>>slot_idx)&0x1 )
   {  /* 8psk */
      band = RampData_EPSK[(int)rf_band];
      if( lb_or_hb )
         power_dbm_oh = ( power_dbm > 26 ) ? 26 : power_dbm; //High band
      else
         power_dbm_oh = ( power_dbm > 27 ) ? 27 : power_dbm; //Low band

      #if IS_TX_POWER_CONTROL_SUPPORT
      if( l1d_rf.txpc_type==TXPC_BSI_CLOSED_TYPE )
      {  /* detector sub-band compensation */
         power_idx = (power_dbm-lowest_dbm)/2;
         weighted_PA_gain = (unsigned short)(band->power[power_idx]);
      }
      else
      #endif
      {  /* TX power sub-band compensation */
         weight = WeightARFCN_BinarySearch((l1d_rf2.arfcn&0x3FF), l1d_rf.band , band->arfcn_weight, 1);
         if( weight )
         {  n = (power_dbm > weight->mid_level) ? weight->hi_weight : weight->low_weight;  }
         else // no entry, not found
         {  n = WEIGHT(1.0);  }
         power_idx = (power_dbm-lowest_dbm)/2;
         weighted_PA_gain = (unsigned short)( ( band->power[power_idx]*n )>>14 );
      }

      /*TX power rollback start*/
      rollback_gain = L1D_RF_PowerRollback( power_dbm, l1d_rf.band, n, 1);
      weighted_PA_gain -= rollback_gain;
      /*TX power rollback end*/

      #if IS_TX_POWER_CONTROL_SUPPORT
      {  short arfcn = (short)((rf_band==FrequencyBand1900)? (l1d_rf2.arfcn|0x400) : l1d_rf2.arfcn);
         if( rollback_gain == 0 )
         {  L1D_RF_TXPC_RECORD_PARAM( 3, band, (unsigned short)n, power_idx, 0, 0 );   }
         weighted_PA_gain = (unsigned short)L1D_RF_TXPC_RecUpdateGain( weighted_PA_gain, rf_band, arfcn, (short)slot_idx );
      }
      #endif

      gain_cpl = (rf_band<=FrequencyBand900) ? GAIN_CPL_LB : GAIN_CPL_HB;
      gain_rf = (signed short) (RFSpecialCoef.rx.mt6162_gain_rf.gain_rf_table[rf_band-1].map[power_idx]);
      gain_bb = (signed short)( 1023-weighted_PA_gain );
      /* the range of gain_bb is 0~1023 (10bits) */
      if( gain_bb < 0 ) gain_bb = 0;
      else if( gain_bb > 1023 ) gain_bb = 1023;

      gain_det = ( (GAIN_PBBOFS)-(gain_cpl)-((power_dbm_oh<<8)-POWER_BB) )>>8;
   }
   else
   #endif
   {  /* GMSK: Only for calculate gain_det */
      power_dbm_oh = power_dbm;
      gain_cpl = (rf_band<=FrequencyBand900) ? GAIN_CPL_LB : GAIN_CPL_HB;
      gain_rf  = 0xF; /* Although we do not use gain_rf and gain_bb in the GMSK mode, we set them to the minimum value */
      gain_bb  = 0x3FF;
      gain_det = ( (GAIN_PBBOFS)+(POWER_BB)-(power_dbm_oh<<8)+(-gain_cpl) )>>8; //{  g_det = (-9)+(2.97)-(power_dbm)+(-1)-(-38);  }  /* (G_pbbofs)+(P_bb)-(P_ant)+(G_pref_attn)-(G_attn_gsm) */
   }

   gain_det = ( gain_det < 3 ) ? (0) : (gain_det/3-1);
   gain_det = ( gain_det >= 10 ) ? (10) : (gain_det);

   tx_gain_write = ( (gain_det&0xF)<<16 ) | ( (gain_rf&0xF)<<12 ) | ( (gain_bb&0x3FF)<<2 );
   #if IS_TX_POWER_CONTROL_SUPPORT
   l1d_rf2.tx_gain_setting[slot_idx] = ( ((gain_rf&0xF)<<10) | (gain_bb&0x3FF) );
   #endif

   return tx_gain_write;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

   #if IS_RF_RX_DCOC_SUPPORT
void L1D_RF_RXDCOffset_Init( void )
{
   signed int band, gain;

   for( band=0; band<4; band++ )
   {  for( gain=0; gain<4; gain++ )
      {  l1d_rf2.rx_dc_offset_i[band][gain] = 0;
         l1d_rf2.rx_dc_offset_q[band][gain] = 0;
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
   #endif

   #if IS_RF_TX_CALIBRATION_SUPPORT
void L1D_RF_TXIQMM_Init( void )
{
   signed int band, gain;

   for( band=0; band<4; band++ )
   {
      l1d_rf2.tx_dc_bb_i[band] = 0;
      l1d_rf2.tx_dc_bb_q[band] = 0;
      for( gain=0; gain<4; gain++ )
      {
         l1d_rf2.tx_gain_error[band][gain] = 0;
         l1d_rf2.tx_phase_error[band][gain] = 0;
         l1d_rf2.tx_dc_rf_i[band][gain] = 0;
         l1d_rf2.tx_dc_rf_q[band][gain] = 0;
      }
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_SetEPSKTxIQ( signed short slot_idx, unsigned long tx_gain_write )
{
   signed short   band = (signed short)l1d_rf.band;
   signed short   dc_corr_i, dc_corr_q;
   signed short   gain_rf;
   signed short   gain_bb;
   signed long    gain, iqgain_sel, phseli, phselq;
   unsigned short gain_bb_inverse;
   BFETXCON       bfetxcon;

   gain_rf = (tx_gain_write>>12)&0xF;
   gain_bb = (tx_gain_write>> 2)&0x3FF;
   gain_bb_inverse = TX_GAIN_BB_TABLE[(gain_bb>>6)].gain_bb_inverse + (((TX_GAIN_BB_TABLE[(gain_bb>>6)+1].gain_bb_inverse-TX_GAIN_BB_TABLE[(gain_bb>>6)].gain_bb_inverse)*(gain_bb-TX_GAIN_BB_TABLE[(gain_bb>>6)].gain_bb_dac))>>6); /* >>6 */

   dc_corr_i = -( (VOLT_2_DCDAC*(l1d_rf2.tx_dc_bb_i[band-1]+((l1d_rf2.tx_dc_rf_i[band-1][gain_rf-3]*gain_bb_inverse)>>11)))>>15 );
   dc_corr_q = -( (VOLT_2_DCDAC*(l1d_rf2.tx_dc_bb_q[band-1]+((l1d_rf2.tx_dc_rf_q[band-1][gain_rf-3]*gain_bb_inverse)>>11)))>>15 );

   if( l1d_rf2.tx_gain_error[band-1][gain_rf-3]>0 ) /* I is greater than Q */
   {  iqgain_sel = 0; /* choose I to compensate */
      gain = UNITY_ONE+(-2)*l1d_rf2.tx_gain_error[band-1][gain_rf-3];
      gain = ( ((gain-UNITY_ONE)>>6)+1 );
   }
   else /* Q is greater than I */
   {  iqgain_sel = 1; /* choose Q to compensate */
      gain = UNITY_ONE+2*l1d_rf2.tx_gain_error[band-1][gain_rf-3];
      gain = ( ((gain-UNITY_ONE)>>6)+1 );
   }

   if( l1d_rf2.tx_phase_error[band-1][gain_rf-3]>0 )
   {
      phselq = ( ((l1d_rf2.tx_phase_error[band-1][gain_rf-3])*RAD_2_DEG)>>15 );
      phselq = ( (phselq*DEG_2_BFEDAC)>>22 );
      phseli = phselq;
   }
   else
   {
      phseli = ( ((-l1d_rf2.tx_phase_error[band-1][gain_rf-3])*RAD_2_DEG)>>15 );
      phseli = -( (phseli*DEG_2_BFEDAC)>>22 );
      phselq = phseli;
   }

   if( gain<-TX_GAIN_COMP_THRESHOLD    ) gain   = -TX_GAIN_COMP_THRESHOLD;
   if( phseli> TX_PHASE_COMP_THRESHOLD ) phseli =  TX_PHASE_COMP_THRESHOLD;
   if( phseli<-TX_PHASE_COMP_THRESHOLD ) phseli = -TX_PHASE_COMP_THRESHOLD;
   if( phselq> TX_PHASE_COMP_THRESHOLD ) phselq =  TX_PHASE_COMP_THRESHOLD;
   if( phselq<-TX_PHASE_COMP_THRESHOLD ) phselq = -TX_PHASE_COMP_THRESHOLD;
   if( dc_corr_i> TX_DC_COMP_THRESHOLD ) dc_corr_i =  TX_DC_COMP_THRESHOLD;
   if( dc_corr_i<-TX_DC_COMP_THRESHOLD ) dc_corr_i = -TX_DC_COMP_THRESHOLD;
   if( dc_corr_q> TX_DC_COMP_THRESHOLD ) dc_corr_q =  TX_DC_COMP_THRESHOLD;
   if( dc_corr_q<-TX_DC_COMP_THRESHOLD ) dc_corr_q = -TX_DC_COMP_THRESHOLD;

   /* set l1d_rf2.tx_gain_error[gain_rf-3], l1d_rf2.tx_phase_error[gain_rf-3], dc_corr_i, and dc_corr_q to different slot_idx */
   bfetxcon.field1.gain_comp  = (signed short)(gain);
   bfetxcon.field1.iqgain_sel = (signed short)(iqgain_sel);
   bfetxcon.field1.phseli     = (signed short)(phseli);
   bfetxcon.field1.phselq     = (signed short)(phselq);
   bfetxcon.field1.offi       = dc_corr_i;
   bfetxcon.field1.offq       = dc_corr_q;
   L1D_BFE_SET_TX_CON( slot_idx, &bfetxcon );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
   #endif /* end IS_RF_TX_CALIBRATION_SUPPORT */
#endif /* IS_RF_MT6162 */

#if IS_DCXO_SUPPORT_CHIP
extern void L1D_DCXO_Trace( unsigned short idx, unsigned long var1, unsigned long var2 );
   #if IS_RF_MT6162 && defined(AFC_VCXO)
void L1D_RF_IMM_SEND_DCXO_BSI( unsigned short afc_dac )
{
   volatile long addr;
   char idx;

   IMM_MODE_BEGIN( IMMMASK_BSI );
   HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN );
   for( idx=0; idx<2; idx++ )
   {
      addr = (long)BSI_Dn_CON(idx);
      HW_WRITE( (APBADDR)addr, SCTRL_IMOD(0,30) );  addr += 4;
      if( idx==0 )
      {  HW_WRITE_BSI_DATA( addr, (XO_CapID&0xFF)|0x0E000000 );  }
      else
      {  HW_WRITE_BSI_DATA( addr, afc_dac|0x0E100000 );          }
      HW_DUMMY_READ_BSI_DATA( addr );
      #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
      HW_WRITE( GSM_BSI_ACTUPT, 0x8000|(idx&0xF) );
      HW_DUMMY_READ_BSI_DATA( addr );
      #endif
   }
   HW_WRITE( BSI_CON, SCTRL_IMOD_SEND );
   WAIT_TIME_US( 6 );

   for( idx=0; idx<2; idx++ )
   {
      addr = (long)BSI_Dn_CON(idx);
      HW_WRITE( (APBADDR)addr, SCTRL_RESERVED );  addr += 4;
      HW_WRITE_BSI_DATA( addr, 0 );
   }
   IMM_MODE_BSI_END();
}
   #endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_DCXO_WAKEUP_RESEND( void )
{
   #if IS_RF_MT6162 && defined(AFC_VCXO)
   unsigned short afc_dac = 0;

   if( !IS_USE_AFC() || IS_AFC_TRIGGER_BSI() )
   {
      #if IS_FDD_DUAL_MODE_SUPPORT
      if( IS_AFC_TRIGGER_BSI() )
      {
         afc_dac = HW_READ( AFC_FINAL_DAC );
         L1D_DCXO_Trace( (unsigned short)(60000+XO_CapID), (HW_READ(AFC_UMTS_CON)&0x1), afc_dac );
      }
      else if ( !IS_USE_AFC() )
      #endif
      {
         afc_dac = l1d_rf.AFC_data;
         L1D_DCXO_Trace( (unsigned short)(60000+XO_CapID), 2, afc_dac );
      }

      L1D_RF_IMM_SEND_DCXO_BSI( afc_dac );
   }
   #endif
}
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned char L1D_RF_IS_MT6162_DCXO( void )
{
#if IS_RF_MT6162 && defined(AFC_VCXO)
   return 1;
#else
   return 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_PMU_FIX_VRF1828SETTING( unsigned char is_fixed )
{  /* called by BT at the BT test mode */
#if IS_RF_MT6162
   l1d_rf2.is_fix_rf1828 = is_fixed;
   if( is_fixed )
   {
      L1D_PMU_VRF18Setting( 1 );
      L1D_PMU_VRF28Setting( 1 );
   }
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned char L1D_PMU_IS_FIX_VRF1828SETTING( void )
{
#if IS_RF_MT6162
   return l1d_rf2.is_fix_rf1828;
#else
   return 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned char L1D_Check_BPI_Data( void )
{
#if IS_RF_MT6162
   unsigned short bpi = 0;
   unsigned short i;

   for( i=1; i<FrequencyBandCount; i++ )
   {
      bpi |= PDATA_TABLE[i][RF_RX][3]; /* PR3  */
      bpi |= PDATA_TABLE[i][RF_RX][4]; /* PR3A */
      bpi |= PDATA_TABLE[i][RF_TX][3]; /* PT3  */
      bpi |= PDATA_TABLE[i][RF_TX][4]; /* PT3A */
   }

   if( bpi & (1<<gsm_err_det_id) )
      return 1; /* assert if BPI bit[9] is ONE on PR3/PR3A/PT3/PT3A */
   else
      return 0;
#else
   return 0;
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned long L1D_GetBandSupport( void )
{
   /* For partial-source load, L1D only supports BAND_SUPPORT setting downgrade in project make file.
      Abnormal BAND_SUPPORT setting upgrade would cause link errors in this function */

   unsigned long band_support = 0;

   #ifdef __GSM450__
   {  extern FrequencyBand l1d_support_band400;
      band_support |= 1<<l1d_support_band400;
   }
   #endif

   #ifdef __GSM850__
   {  extern FrequencyBand l1d_support_band850;
      band_support |= 1<<l1d_support_band850;
   }
   #endif

   #if defined(__PGSM900__)||defined(__EGSM900__)||defined(__RGSM900__)
   {  extern FrequencyBand l1d_support_band900;
      band_support |= 1<<l1d_support_band900;
   }
   #endif

   #ifdef __DCS1800__
   {  extern FrequencyBand l1d_support_band1800;
      band_support |= 1<<l1d_support_band1800;
   }
   #endif

   #ifdef __PCS1900__
   {  extern FrequencyBand l1d_support_band1900;
      band_support |= 1<<l1d_support_band1900;
   }
   #endif

   return band_support;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned short L1D_Get_EPSK_TX_Support( void )
{
   unsigned short is_epsk_tx_support = 0;

   #if IS_EPSK_TX_SUPPORT && !IS_EPSK_TX_NOT_SUPPORT_RF
   is_epsk_tx_support = 1;
   #endif

   return is_epsk_tx_support;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned short L1D_GetPsEpskTxStatus( void )
{
   unsigned short is_ps_epsk_tx_disable = 0;

   #if IS_PS_EPSK_TX_DISABLE
   is_ps_epsk_tx_disable = 1;
   #endif

   return is_ps_epsk_tx_disable;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

unsigned short L1D_Get_TCVCXO_Support( void )
{
   unsigned short is_tcvcxo_support = 1;

   #ifdef AFC_VCXO
   is_tcvcxo_support = 0;
   #endif

   return is_tcvcxo_support;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#if IS_WIFI_ADAPTIVE_POWER_CONTROL_SUPPORT
short L1D_GET_RX_PWR_THRES_ORI( void )
{
   return DEGRADE_PWR_THRES_ORI;
}
short L1D_GET_RX_PWR_THRES_HYS( void )
{
   return DEGRADE_PWR_THRES_HYS;
}
#endif

char L1D_INFORM_WIFI_DEGRADE_POWER( void )
{
   char is_needed = 0;
#if IS_WIFI_ADAPTIVE_POWER_CONTROL_SUPPORT
   /* When 2G is in dedicated mode, in high band, and rx_power_flag is raised,
      L1D will inform WiFi of decreasing power */
   l1d_rf.wifi_low_pwr_flag = ((( l1d_rf2.dedicated_flag & SC_DEDICATED ) > 0) &&
                               (  l1d_rf.rx_power_flag == 1                  ) && 
                               (  l1d_rf.band >= FrequencyBand1800           )    );
   is_needed = l1d_rf.wifi_low_pwr_flag;
#endif
   return is_needed;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_BSI_V2_SUPPORT
unsigned long L1D_RF_TX_BSI_ENA( unsigned short win )
{
                           /* ST1 */      /* ST2 */      /* ST3 */
   unsigned long bsi_ena = BSIEN(win,0) | BSIEN_X(win) | BSIEN(win,1);

   #if IS_BSI_SX0_SUPPORT
   bsi_ena |= BSIEN(win,-1);   /* ST0 */
   #endif

   return bsi_ena;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_BPI_V2_SUPPORT
unsigned long L1D_RF_TX_BPI_ENA( unsigned short win )
{
            /* PT1 */      /* PT2 */      /* PT2B */     /* PT3 */
   return ( BPIEN(win,0) | BPIEN(win,1) | BPIEN(win,2) | BPIEN(1,3) );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_NORMAL_MODE_CAPID_CAL_SUPPORT
void L1D_RF_Capid_Cal_Mode( char cal_mode )
{
   l1d_rf.capid_cal_en = cal_mode;
}

long L1D_RF_Capid_Query( void )
{
   return XO_CapID;
}
#endif

#if IS_DCS_NB_WB_SWITCH_SUPPORT
void L1D_RF_Init_DCS_NB_WB_Switch( void )
{
   #if IS_DCS_NB_WB_SWITCH_ON
   l1d_rf2.is_dcs_nb_wb_switch_on = 1;
   #else
   l1d_rf2.is_dcs_nb_wb_switch_on = 0;
   #endif
}

char L1D_RF_IS_DCS_NB_WB_Switch( void )
{
   return l1d_rf2.is_dcs_nb_wb_switch_on;
}

char L1D_RF_IS_DCS_Change_to_NB( void )
{
   char is_change = 0;
   extern void L1D_RF_Info_Trace( unsigned short idx, long v1, long v2 );

   #if IS_RF_MT6261RF
   is_change = ( (l1d_rf2.is_dcs_nb_wb_switch_on) && (l1d_rf.band==FrequencyBand1800) && ((l1d_rf.arfcn&0x03FF)<=DCS_NB_ARFCN) ) ? 1 : 0;
   #endif

   if( is_change == 1 )
   {  L1D_RF_Info_Trace( 18039, l1d_rf.band, (l1d_rf.arfcn&0x03FF) );  }

   return is_change;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_DSDA_PROVIDE_RX_STATUS_TO_LTE_SUPPORT
void L1D_RF_Set_GPIO( unsigned char is_rx_win_on )
{
   #if IS_DSDA_PROVIDE_RX_STATUS_TO_LTE_ENABLE
   extern void L1D_GPIO_ModeSetup( kal_uint16 pin, kal_uint16 conf_dada );
   extern void L1D_GPIO_InitIO( char direction, char port );
   extern void L1D_GPIO_WriteIO( char data, char port );

   // Set GGE2LTE_WRITEOUT_PIN to the GPIO mode (000b)
   L1D_GPIO_ModeSetup( GGE2LTE_WRITEOUT_PIN, 0 );

   // Set GGE2LTE_WRITEOUT_PIN to the output direction (0: input; 1: output)
   L1D_GPIO_InitIO( 1, GGE2LTE_WRITEOUT_PIN );

   // Set the GGE2LTE_WRITEOUT_PIN output value
   L1D_GPIO_WriteIO( is_rx_win_on, GGE2LTE_WRITEOUT_PIN );
   #endif
}

char L1D_RF_Provide_Rx_Statue_To_LTE_Enable( void )
{
   char is_enable = 0;

   #if IS_DSDA_PROVIDE_RX_STATUS_TO_LTE_ENABLE
   is_enable = 1;
   #endif

   return is_enable;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
char L1D_RF_IS_TDD_GSM_TX_Overlap( void )
{
   char is_overlap = 0;

   #if IS_CHIP_MT6261
   if(L1D_CheckIfMetaMode())
      is_overlap = 0;
   else
      is_overlap = L1D_RF_Get_GPIO();
   #else
#error "please check how to get the RX status from TDD"
   #endif

   return is_overlap;
}

void L1D_RF_Init_TX_Notch_Switch( void )
{
   l1d_rf2.is_tx_notch_switch_on = 0;
}

char L1D_RF_IS_DCS_Change_to_TX_Notch( void )
{
   char is_change  = 0;
   char is_overlap = L1D_RF_IS_TDD_GSM_TX_Overlap();
   extern void L1D_RF_Info_Trace( unsigned short idx, long v1, long v2 );

   is_change = ( (l1d_rf.band==FrequencyBand1800) && ( is_overlap || l1d_rf2.is_tx_notch_switch_on ) ) ? 1 : 0;

   if( is_change == 1 )
   {  L1D_RF_Info_Trace( 18040, l1d_rf2.is_tx_notch_switch_on, is_overlap );  }

   return is_change;
}

char L1D_RF_Get_GPIO( void )
{
   char gpio_value = 0;

   #if IS_DSDA_DCS_TX_NOTCH_SWITCH_ENABLE
   extern void L1D_GPIO_ModeSetup( kal_uint16 pin, kal_uint16 conf_dada );
   extern void L1D_GPIO_InitIO( char direction, char port );
   extern char L1D_GPIO_ReadIO_Fast( char );
   //extern void L1D_RF_Info_Trace( unsigned short idx, long v1, long v2 );

   // Set DT_COEXIST_READBACK_PIN to the GPIO mode (000b)
   L1D_GPIO_ModeSetup( DT_COEXIST_READBACK_PIN, 0 );

   // Set DT_COEXIST_READBACK_PIN to the input direction (0: input; 1: output)
   L1D_GPIO_InitIO( 0, DT_COEXIST_READBACK_PIN );

   // Get the DT_COEXIST_READBACK_PIN input value
   gpio_value = L1D_GPIO_ReadIO_Fast( DT_COEXIST_READBACK_PIN );

   //L1D_RF_Info_Trace( 3243, gpio_value, DT_COEXIST_READBACK_PIN );
   #endif

   return gpio_value;
}

char L1D_RF_Tx_Notch_Switch_Enable( void )
{
   char is_enable = 0;

   #if IS_DSDA_DCS_TX_NOTCH_SWITCH_ENABLE
   is_enable = 1;
   #endif

   return is_enable;
}
#endif

/* API for meta DCS 2nd path TX power check */ 
void L1D_RF_Set_TX_Notch_Path( kal_uint8 notch_en )
{
#if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
   #if IS_DSDA_DCS_TX_NOTCH_SWITCH_ENABLE
   l1d_rf2.is_tx_notch_switch_on = notch_en;
   #else
   l1d_rf2.is_tx_notch_switch_on = 0;
   #endif
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

