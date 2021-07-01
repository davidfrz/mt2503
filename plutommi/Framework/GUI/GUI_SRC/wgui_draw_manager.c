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
/* **** Copy Right Note ********* 
 * Copyright Notice
 * (c) PMT.
 * All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 *******************************************************************************
 * Filename:
 * ---------
 * wgui_draw_manager.c
 *
 * Project:
 * --------
 * PDG2
 *
 * Description:
 * ------------
 * Draws the category screens on the basis of the static coordinates specified
 * at Complile Time.
 * Author:
 * -------
 * -------
 *==============================================================================
 * HISTORY
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
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*  Include: MMI header file */
#include "MMI_features.h"

#include "CustDataRes.h"
#include "wgui_ems.h"
#include "wgui_softkeys.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_virtual_keyboard.h"
#endif 



#ifdef __MMI_SCREEN_ROTATE__
#include "ScreenRotationGprot.h"
#endif 

#include "ProfilingEngine.h"

#ifdef __MMI_SWFLASH__
#include "mdi_datatype.h"
#include "mdi_swflash.h"
#include "swflashGprot.h"
#include "mmi_phnset_dispchar.h"
#endif 
/*RHR Add*/
#include "wgui_draw_manager_int.h"
#include "gdi_const.h"
#include "gdi_features.h"
#include "gdi_datatype.h"
#include "MMIDataType.h"
#include "CustThemesRes.h"
#include "gui_data_types.h"
#include "gui_windows.h"
#include "GlobalConstants.h"
#include "gui_buttons.h"
#include "wgui_categories_list.h"
#include "gui_panel.h"
#include "gui.h"
#include "wgui_categories_stopwatch.h"
#include "PixcomFontEngine.h"
#include "wgui.h"
#include "wgui_inputs.h"
#include "kal_general_types.h"
#include "gdi_include.h"
#include "gui_effect_oem.h"
#include "wgui_touch_screen.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "FontRes.h"
#include "gui_themes.h"
#include "mmi_rp_app_uiframework_def.h"
#include "gui_config.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menus.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_ems.h"
#include "wgui_include.h"
#include "wgui_title.h"
#include "gui_title_pre_oem.h"
#include "gui_menu_shortcut.h"
#include "gui_switch.h"
#include "gui_fixed_menuitems.h"
#include "ImeGprot.h"
#include "gui_virtual_keyboard_language_type.h"
#include "gui_virtual_keyboard.h"
#include "wgui_inline_edit.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "string.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_enum.h"
#include "gui_inputs.h"
#include "gui_scrollbars.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_idlescreen.h"
#include "Unicodexdcl.h"
#include "MMI_fw_trc.h"
#include "mmi_fw_trc.h"
#include "kal_trace.h"
#include "mmi_frm_at_util_gprot.h"
#include "gdi_2d_engine.h"

#ifndef __OPTR_NONE__
#include "operator_gui.h"
#endif
#include "wgui_categories_inputs.h"
#include "stack_config.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_asyncdynamic_menus.h"
#ifdef __MMI_SUBLCD__
#include "wgui_categories_sublcd.h"
#endif

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/************************************************************/
/* Currently, we keep two context for MainLCD and SubLCD    */
/* In the future, we may have more than 2 LCDs              */
/* More context data would be needed in the future          */
/************************************************************/
#ifdef __GDI_MEMORY_PROFILE_2__
    #undef __DM_SLIM_USE_MULTIPLE_LAYERS__
    #define __DM_SLIM_USE_MULTIPLE_LAYERS__
#else
    #undef __DM_SLIM_USE_MULTIPLE_LAYERS__
#endif

/* Start of Draw Manager MainLCD Context */

/* DM internal context */
static dm_cntx_struct g_dm_cntx;
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
static dm_scr_bg_cntx_struct g_dm_scr_bg_cntx;
#endif

/* DM components */

/* -Layers */
#ifndef __GDI_MEMORY_PROFILE_2__
static U16 new_layer_x = 0;
static U16 new_layer_y = 0;
#endif /* __GDI_MEMORY_PROFILE_2__ */

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
/* Currently used layers in Draw Manager */
static GDI_HANDLE dm_layers[GDI_LAYER_TOTAL_LAYER_COUNT];

/* Total currently used layers in Draw Manager */
static U16 dm_layers_count = 0;
#endif
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
static S32 dm_wallpaper_layer_idx = -1;
#endif
#endif
/* -Strings */
static dm_string_data_struct dm_string_array[DM_MAX_STRINGS];
static S32 dm_string_count = 0;

/* -Images */
static dm_image_data_struct dm_image_array[DM_MAX_IMAGES];
static S32 dm_image_count = 0;

/* -Background fillers */
static UI_filled_area *dm_back_fill_array[DM_MAX_FILL_AREAS];
static S32 dm_back_fill_count = 0;

/* -Rectangles */
static dm_rectangle_data_struct dm_rectangle_array[DM_MAX_RECTANGLES];
static S32 dm_rectangle_count = 0;

/* -Lines */
static color dm_line_array[DM_MAX_LINES];
static S32 dm_line_count = 0;

/* -Scrolling Text objects */
static scrolling_text dm_scroll_text[DM_MAX_SCROLL_TEXT];
static U8 dm_scroll_text_buf[DM_MAX_SCROLL_TEXT][MAX_SUB_MENU_SIZE];
static S32 dm_scroll_text_count = 0;
static scrolling_text *dm_current_scroll_text = NULL;

/* -slide controls */
S32 dm_slide_control_count = 0;

/* -buttons */
static icontext_button dm_button_array[DM_MAX_BUTTONS];
static S32 dm_button_count = 0;


#if defined(__MMI_TOUCH_SCREEN__)
static FuncPtr dm_button_func_ptrs[DM_MAX_BUTTONS][MAX_KEY_TYPE];
#endif

/* -percentage bar */
static dm_percentage_bar_struct dm_percentage_bar_array[DM_MAX_PERCENTAGE_BAR];
static S32 dm_percentage_bar_count = 0;

#if (defined(__MMI_SEARCH_WEB__) || defined(__MMI_HIDD_SUPPORT__))
/* -Panel */
static gui_panel_struct dm_panel_array[DM_MAX_PANEL];
static S32 dm_panel_count = 0;
#endif

/* -pop background */
static dm_coordinates dm_popupbg_coordinate = {0};
static dm_coordinates dm_popupbg_clip_coordinate = {0};
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
static GDI_HANDLE dm_popupfg_layer = GDI_NULL_HANDLE;
static GDI_HANDLE dm_popupbg_layer = GDI_NULL_HANDLE;
#endif
/* -others */
static dm_previous_control_coordinates_struct prev_control_coordinates;
static dm_aligned_area_data_struct dm_aligned_area_data;
static FuncPtr dm_show_vkpad_callback = UI_dummy_function;

#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
/* wallpaper animation update before-blt callback */
static FuncPtr dm_wallpaper_anim_update_callback = UI_dummy_function;
#endif

/* End of MainLCD context */

/* DM SubLCD context stat */
#ifdef __MMI_SUBLCD__

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
/* -Layers */
static GDI_HANDLE dm_layers_sub[GDI_LAYER_TOTAL_LAYER_COUNT];
static U16 dm_layers_count_sub = 0;
#endif

/* -Strings */
static dm_string_data_struct dm_string_array_sub[DM_MAX_SUBLCD_STRINGS];
static S32 dm_string_count_sub = 0;

/* -Images */
static dm_image_data_struct dm_image_array_sub[DM_MAX_SUBLCD_IMAGES];
static S32 dm_image_count_sub = 0;

#endif /* __MMI_SUBLCD__ */ 
/* End of SubLCD context */

/***************************************************************************** 
 * Static Function
 *****************************************************************************/
#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
static void dm_wallpaper_anim_before_blt_callback(GDI_RESULT return_code);
#endif
#if defined(DM_NEW_POPUPBG_METHOD)
static void dm_popupbg_anim_draw_before_callback(GDI_RESULT return_code);
#endif
static void dummy_anim_before_blt_callback(GDI_RESULT return_code);

/***************************************************************************** 
* Global Variable
*****************************************************************************/
dm_data_struct g_dm_data;
dm_data_struct g_dm_sublcd_data;
UI_filled_area  *old_bg_filler = NULL;  /* remember the old filler to compare with new filler for lazy free */
U8 old_bg_opacity = 0;
U16 old_image_id = 0;
S8 *old_image_name = NULL;

gdi_color user_scr_bg_color = 0;

void (*dm_backup_exit_category_function) (void);

#ifdef __MMI_SUBLCD__
void (*dm_sub_backup_exit_category_function) (void);
#endif 

void (*dm_category_controlled_area_callback) (dm_coordinates *coordinate);
void (*dm_category_controlled_area2_callback) (dm_coordinates *coordinate);

#ifdef __MMI_SUBLCD__
void (*dm_sub_category_controlled_area_callback) (dm_coordinates *coordinate);
#endif 
/***************************************************************************** 
* Global Function
*****************************************************************************/
S16 *dm_get_coordinates(S16 *UICtrlAccessPtr_p, dm_coordinates *dm_coordinate_info);
static MMI_BOOL dm_verify_coordinates(dm_coordinates *dm_coordinate_info);
#define DM_RETURN_IF_INVALID_COORD(x) if(!dm_verify_coordinates(x)) return 0;
    
/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
#ifdef __MMI_STOPWATCH__
extern wtchSkinResStruct wtch_pos;
extern S32 stop_watch_x, stop_watch_y, stop_watch_width;
#endif /* __MMI_STOPWATCH__ */ 
#ifdef UI_EMS_SUPPORT
extern S32 wgui_EMS_inputbox_information_bar_height;
#endif
extern U16 on_idle_screen;
extern const U8 dm_base_control_set[];
extern const S16 dm_base_control_set_coordinates[];
extern icontext_button MMI_softkeys[];
//extern BOOL r2lMMIFlag;

extern MMI_ID_TYPE idle_screen_wallpaper_ID;
extern S8 *idle_screen_wallpaper_name;

extern stFontAttribute wgui_dialer_box_f1;

extern UI_filled_area wgui_pop_up_dialog_background;
extern gdi_handle wgui_layer_1;

#ifndef __MTK_TARGET__
/* MTE */
extern void mmi_mte_mmi_notify_screen_switch(void);
extern void mmi_mte_init(void);
#endif /* __MTK_TARGET__ */

#ifdef DM_NEW_POPUPBG_METHOD
extern S32 gdi_anim_get_current_frame_number(gdi_handle serial_handle);
#endif

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void (*redraw_current_inline_item) (void);
extern S32 dm_get_coordinate_sets_count(void);
extern S32 dm_get_control_sets_count(void);
extern U8 *dm_get_base_control_set(void);
extern S16 *dm_get_base_coordinate_set(void);
extern U8 *dm_get_base_control_set2(void);
extern S16 *dm_get_base_coordinate_set2(void);
#if defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
extern U8 *dm_get_base_control_set_submenu(void);
extern S16 *dm_get_base_coordinate_set_submenu(void);
#endif /* defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */
#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
extern U8 *dm_get_base_control_set_common(void);
extern S16 *dm_get_base_coordinate_set_common(void);
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */

#ifdef __MMI_SUBLCD__
#ifdef __MMI_SUB_WALLPAPER__
extern gdi_handle wgui_sublcd_wallpaper_layer(void);
#endif
#endif

extern void set_calendar_control_background_limits(S32 y1, S32 y2);
extern void set_button_bar_height(S32 height);
extern void wgui_reset_calendar_params(S32 x, S32 y, S32 n_columns, S32 n_rows, S32 cell_width, S32 cell_height);
extern void wgui_show_calendar(void);
extern void ChangeCategory82Title1(U8 *title);
extern void ChangeCategory82Title2(U8 *title);
extern void ChangeCategory82Title3(U8 *title);
extern void UI_cross_hatch_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);
extern MMI_BOOL get_singleline_inputbox_display_status(void);
extern MMI_BOOL is_multiline_inputbox_in_view_mode(void);
#ifdef UI_EMS_SUPPORT
extern MMI_BOOL is_EMS_inputbox_in_view_mode(void);
#endif
#ifdef __MMI_CLNDR_EVENT_INFO__
extern void ChangeCategory82Title1Month(U8 *title);
#endif 
#ifdef __MMI_STOPWATCH__
extern void get_stop_watch_history(U16 history_ID, U8 *history_buffer);
#endif 

extern void wgui_redraw_singleline_input_information_bar(void);

static MMI_BOOL dm_is_need_change_scr_bg(void);
static void dm_get_aligned_area_element_height(U8 *control_set_ptr, dm_coordinates dm_aligned_area_info, S32 *total_element_height, S32 *is_multiline, U8 *number_of_items);


/*****************************************************************************
 * FUNCTION
 *  dm_init
 * DESCRIPTION
 *  initialize variables used in draw manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;
    gdi_handle main_base_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    for (idx = 0; idx < GDI_LAYER_TOTAL_LAYER_COUNT; idx++)
    {
        dm_layers[idx] = GDI_ERROR_HANDLE;
    }
#endif
    /* Draw Manager context */
    g_dm_cntx.redraw_screen_main = NORMAL_EXIT;
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    g_dm_cntx.redraw_scr_bg_flag = 1;
    g_dm_cntx.redraw_scr_directly = MMI_FALSE;
#endif
    g_dm_cntx.lock_redraw_main = 0;
    g_dm_cntx.exit_full_screen_on_exit = 0;
    g_dm_cntx.is_context_reset = 1;
#ifdef __MMI_SUBLCD__
    g_dm_cntx.redraw_screen_sub = NORMAL_EXIT;
    g_dm_cntx.lock_redraw_sub = 0;
#endif /* __MMI_SUBLCD__ */ 

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    /* Draw Manager Screen Background Layer Context */
    g_dm_scr_bg_cntx.layer_handle = GDI_ERROR_HANDLE;
    g_dm_scr_bg_cntx.image_id = 0;
    g_dm_scr_bg_cntx.image_name = NULL;
    g_dm_scr_bg_cntx.offset_x = -1;
    g_dm_scr_bg_cntx.offset_y = -1;
    /* Full opacity provides better user experiences */
    g_dm_scr_bg_cntx.layer_opacity = 255;
    g_dm_scr_bg_cntx.flags = 0;
    g_dm_scr_bg_cntx.is_used = 0;
    g_dm_scr_bg_cntx.scr_bg_layer_exist = MMI_FALSE;
#endif

    /* Reset all images */
    for (idx = 0; idx < dm_image_count; idx++)
    {
        dm_image_array[idx].back_fill = NULL;
        dm_image_array[idx].image = NULL;
        dm_image_array[idx].name = NULL;
        if (dm_image_array[idx].image_handle != GDI_ERROR_HANDLE)
        {
            gdi_image_stop_animation(dm_image_array[idx].image_handle);
            dm_image_array[idx].image_handle = GDI_ERROR_HANDLE;
        }
        dm_image_array[idx].blt_before_callback_ptr = dummy_anim_before_blt_callback;
        dm_image_array[idx].image_size = 0;
        dm_image_array[idx].dyn_prop_flag = DM_IMAGE_WITH_HEADER;
        dm_image_array[idx].image_type = GDI_IMAGE_TYPE_INVALID;
    }
    dm_image_count = 0;

    dm_string_count = 0;
    dm_back_fill_count = 0;
    dm_rectangle_count = 0;
    dm_line_count = 0;
    dm_slide_control_count = 0;
    dm_scroll_text_count = 0;
    dm_current_scroll_text = NULL;
    dm_button_count = 0;

#ifdef __MMI_SUBLCD__
    /* Reset all images */
    for (idx = 0; idx < dm_image_count_sub; idx++)
    {
        dm_image_array_sub[idx].back_fill = NULL;
        dm_image_array_sub[idx].image = NULL;
        dm_image_array_sub[idx].name = NULL;
        if (dm_image_array_sub[idx].image_handle != GDI_ERROR_HANDLE)
        {
            gdi_image_stop_animation(dm_image_array_sub[idx].image_handle);
            dm_image_array_sub[idx].image_handle = GDI_ERROR_HANDLE;
        }
        dm_image_array_sub[idx].blt_before_callback_ptr = dummy_anim_before_blt_callback;
        dm_image_array_sub[idx].image_size = 0;
        dm_image_array_sub[idx].dyn_prop_flag = DM_IMAGE_WITH_HEADER;
        dm_image_array_sub[idx].image_type = GDI_IMAGE_TYPE_INVALID;
    }
    dm_image_count_sub = 0;
    dm_string_count_sub = 0;
#endif /* __MMI_SUBLCD__ */ 

    /* set default ABM source layer to the main base layer */
    gdi_layer_get_base_handle(&main_base_layer);
    gdi_set_alpha_blending_source_layer(main_base_layer);
    
    /* small screen flatten default on */
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    dm_enable_small_screen_flatten();        
#endif
    /* init gui effect */
#ifdef __MMI_UI_EFFECT_ENGINE__
    gui_effect_create();
#endif /* __MMI_UI_EFFECT_ENGINE__ */


#ifndef __MTK_TARGET__
    /* MTE initialization */
    mmi_mte_init();
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  dm_verify_coordinates
 * DESCRIPTION
 *  Check coordinates.
 * PARAMETERS
 *  dm_coordinate_info
 * RETURNS
 *  False, if coordinates check is incorrect.
 *****************************************************************************/
static MMI_BOOL dm_verify_coordinates(dm_coordinates *dm_coordinate_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dm_coordinate_info->s16X == -1 || dm_coordinate_info->s16Y == -1 ||
        dm_coordinate_info->s16Width == -1 || dm_coordinate_info->s16Height == -1)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
/*****************************************************************************
 * FUNCTION
 *  dm_wallpaper_free_callback
 * DESCRIPTION
 *  Set scr layer to GDI_ERROR_HANDLE, when lazy free action.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void dm_wallpaper_free_callback(gdi_handle handle)
{
    U8 idx = 0;
    int i;
    for (idx = 0; idx < GDI_LAYER_TOTAL_LAYER_COUNT; idx++)
    {
        if (dm_layers[idx] == handle)
        {
            if (dm_layers[idx] == g_dm_scr_bg_cntx.layer_handle)
            {
                g_dm_scr_bg_cntx.layer_handle = GDI_ERROR_HANDLE;
                for (i = idx; i < GDI_LAYER_TOTAL_LAYER_COUNT-1; i++)
                {
                    /* remove scr bg layer. */
                    dm_layers[i] = dm_layers[i+1];
                }
                dm_layers[i] = GDI_ERROR_HANDLE;
                dm_layers_count--;
                if(dm_wallpaper_layer_idx > 0)
                {
                    dm_wallpaper_layer_idx --;
                }
                break;
            }
            else if(idx == dm_wallpaper_layer_idx)
            {
                dm_wallpaper_layer_idx = -1;
                for (i = idx; i < GDI_LAYER_TOTAL_LAYER_COUNT-1; i++)
                {
                    /* remove wallpaper layer. */
                    dm_layers[i] = dm_layers[i+1];
                }
                dm_layers[i] = GDI_ERROR_HANDLE;
                dm_layers_count--;
                break;
            }
        }
    }
}
#endif
#endif


/*****************************************************************************
 * FUNCTION
 *  dm_reset_context
 * DESCRIPTION
 *  reset variables used in draw manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_WGUI_TRC_DM_SCREEN_INFO2, g_dm_data.s32CatId, g_dm_cntx.redraw_screen_main); 
    
    if (g_dm_cntx.is_context_reset == MMI_FALSE)
    {
        U8 idx = 0;
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
        U16 dm_new_layers_count = 0;
#endif
        /* Reset screen background layer */
        dm_set_scr_bg_redraw(MMI_TRUE);
        
        if (g_dm_data.s32flags & DM_SET_NEW_LAYER_ACTIVE)
        {
            gdi_layer_restore_base_active();
        }

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
        /* Reset Layer information */
        /* MainLCD */
        if (!(g_dm_data.s32flags & DM_SUB_LCD_CONTEXT))
        {
            dm_new_layers_count = dm_layers_count;
            for (idx = 0; idx < dm_layers_count; idx++)
            {
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
                if (dm_layers[idx] != g_dm_scr_bg_cntx.layer_handle && 
                        (dm_layers[idx] != GDI_ERROR_HANDLE))
#else
                if (dm_layers[idx] != g_dm_scr_bg_cntx.layer_handle && 
                        (dm_layers[idx] != GDI_ERROR_HANDLE && idx != dm_wallpaper_layer_idx))
#endif
                {
                    if (dm_layers[idx] != GDI_LAYER_MAIN_BASE_LAYER_HANDLE && dm_layers[idx] != wgui_layer_1
                        && dm_layers[idx] != GDI_ERROR_HANDLE && dm_layers[idx] != GDI_LAYER_EMPTY_HANDLE && (!dm_is_fixed_layer_mode_enabled()))
                    {
                        gdi_layer_free(dm_layers[idx]);
                    }
                    if (!dm_is_fixed_layer_mode_enabled())
                    {
                        dm_layers[idx] = GDI_ERROR_HANDLE;
                        dm_new_layers_count--;
                    }
                }
#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
                else
                {
                    if (dm_layers[idx] != GDI_LAYER_MAIN_BASE_LAYER_HANDLE && dm_layers[idx] != wgui_layer_1
                        && dm_layers[idx] != GDI_ERROR_HANDLE && dm_layers[idx] != GDI_LAYER_EMPTY_HANDLE)
                    {
                        /* lazy free this layer, mean just free it when new layer created */
                        gdi_layer_lazy_free(dm_layers[idx], dm_wallpaper_free_callback);
                    }
                }
#endif
            }
            dm_layers_count = dm_new_layers_count;
        }
#endif
        if (g_dm_cntx.redraw_screen_main == REDRAW_2_SHOW)
        {
            return;
        }

        /* Reset all images */
        for (idx = 0; idx < dm_image_count; idx++)
        {
            dm_image_array[idx].back_fill = NULL;
            dm_image_array[idx].image = NULL;
            dm_image_array[idx].name = NULL;
            if (dm_image_array[idx].image_handle != GDI_ERROR_HANDLE)
            {
                gdi_image_stop_animation(dm_image_array[idx].image_handle);
                dm_image_array[idx].image_handle = GDI_ERROR_HANDLE;
            }
            dm_image_array[idx].blt_before_callback_ptr = dummy_anim_before_blt_callback;
            dm_image_array[idx].image_size = 0;
            dm_image_array[idx].dyn_prop_flag = DM_IMAGE_WITH_HEADER;
            dm_image_array[idx].image_type = GDI_IMAGE_TYPE_INVALID;
        }

        for (idx = 0; idx < dm_scroll_text_count; idx++)
        {
            gui_scrolling_text_stop(&(dm_scroll_text[idx]));
            dm_scroll_text_buf[idx][0] = dm_scroll_text_buf[idx][1] = 0;
        }
        dm_image_count = 0;

        dm_string_count = 0;
        dm_back_fill_count = 0;
        dm_rectangle_count = 0;
        dm_line_count = 0;
        dm_slide_control_count = 0;
        dm_scroll_text_count = 0;
        dm_current_scroll_text = NULL;
        dm_button_count = 0;
        dm_percentage_bar_count = 0;
#if (defined(__MMI_SEARCH_WEB__) || defined(__MMI_HIDD_SUPPORT__))
        dm_panel_count = 0;
#endif

        /* Reset before-BLT callback.
         * This is for misuse of callback of static image. */
        gdi_anim_set_blt_before_callback(dummy_anim_before_blt_callback);
#if defined(__MMI_ALPHA_BLENDING__) && defined(__MMI_SWFLASH__)
        mdi_swflash_register_blt_callback(NULL, NULL);
#endif
        /* Reset default pen handlers */
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_reset_category_screen_control_pen_handler();
        wgui_reset_image_control_pen_handler();
    #endif /* __MMI_TOUCH_SCREEN__ */ 

        dm_reset_category_controlled_callback();
        dm_reset_button_functions();

        /* Can be removed -start */
        dm_reset_title_coordinates();
        dm_reset_fixed_list_coordinates();
        dm_reset_inline_fixed_list_coordinates();
        dm_reset_lsk_coordinates();
        dm_reset_rsk_coordinates();
        dm_reset_csk_coordinates();
        dm_reset_button_bar_coordinates();
        /* Can be removed -end */

        dm_show_vkpad_callback = NULL;
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    #ifdef __MMI_SCREEN_ROTATE__
        /* Reset the background image set by rotated screen */
        if (mmi_frm_is_screen_width_height_swapped())
        {
            g_dm_scr_bg_cntx.image_id = 0;
            g_dm_scr_bg_cntx.image_name = NULL;
        }
    #endif /* __MMI_SCREEN_ROTATE__ */ 
        g_dm_scr_bg_cntx.is_used = 0;
        g_dm_scr_bg_cntx.scr_bg_layer_exist = MMI_FALSE;
#endif
        g_dm_data.s32CatId = 0;
        g_dm_data.s32flags = 0;
        g_dm_data.s32ScrId = 0;

        /* Leo start 20050830 */
        ExitCategoryFunction = MMI_dummy_function;
        RedrawCategoryFunction = MMI_dummy_function;
        GetCategoryHistory = dummy_get_history;
        GetCategoryHistorySize = dummy_get_history_size;
        /* Leo end 20050830 */
        g_dm_cntx.is_context_reset = MMI_TRUE;
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
        g_dm_cntx.redraw_scr_directly = MMI_FALSE;
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_reset_context_ext
 * DESCRIPTION
 *  reset variables used in draw manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_context_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  dm_reset_sublcd_context
 * DESCRIPTION
 *  reset variables used in draw manager for sublcd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_sublcd_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0;
    gdi_handle sub_handle;
    gdi_handle act_lcd_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gdi_lcd_get_active(&act_lcd_handle);
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_base_handle(&sub_handle);
    gdi_lcd_set_active(act_lcd_handle);
    
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_WGUI_TRC_DM_SUB_STATUS, g_dm_cntx.redraw_screen_sub); 
    
    for (idx = 0; idx < dm_layers_count_sub; idx++)
    {
        if (dm_layers_sub[idx] != (sub_handle))
        {
            gdi_layer_free(dm_layers_sub[idx]);
        }
        dm_layers_sub[idx] = GDI_ERROR_HANDLE;
    }
    dm_layers_count_sub = 0;

    /* Reset all images */
    for (idx = 0; idx < dm_image_count_sub; idx++)
    {
        dm_image_array_sub[idx].back_fill = NULL;
        dm_image_array_sub[idx].image = NULL;
        dm_image_array_sub[idx].name = NULL;
        if (dm_image_array_sub[idx].image_handle != GDI_ERROR_HANDLE)
        {
            gdi_image_stop_animation(dm_image_array_sub[idx].image_handle);
            dm_image_array_sub[idx].image_handle = GDI_ERROR_HANDLE;
        }
        dm_image_array_sub[idx].blt_before_callback_ptr = dummy_anim_before_blt_callback;
        dm_image_array_sub[idx].image_size = 0;
        dm_image_array_sub[idx].dyn_prop_flag = DM_IMAGE_WITH_HEADER;
        dm_image_array_sub[idx].image_type = GDI_IMAGE_TYPE_INVALID;
    }
    dm_image_count_sub = 0;
    dm_string_count_sub = 0;
    dm_reset_sub_category_controlled_callback();
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  dm_get_image_count
 * DESCRIPTION
 *  Used to get currently used image controls
 * PARAMETERS
 *  void
 * RETURNS
 *  U16      number of image countrol used currently
 *****************************************************************************/
U16 dm_get_image_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dm_image_count;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_button_count
 * DESCRIPTION
 *  Used to get currently used button controls
 * PARAMETERS
 *  void
 * RETURNS
 *  U16      number of button countrol used currently
 *****************************************************************************/
U16 dm_get_button_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dm_button_count;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
icontext_button *dm_get_button(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < DM_MAX_BUTTONS);

    return &dm_button_array[index];
}

/* Leo end 20050722 */


/*****************************************************************************
 * FUNCTION
 *  dm_get_font
 * DESCRIPTION
 *  Used to return the font poointer depending on the font enum value read from
 *  coordinate set
 * PARAMETERS
 *  font        [IN]        Font enum value
 * RETURNS
 *  returns font pointer
 *****************************************************************************/
UI_font_type dm_get_font(S16 font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (font)
    {
        case SMALL_FONT:
            return (&MMI_small_font);
        case MEDIUM_FONT:
            return (&MMI_medium_font);
        case LARGE_FONT:
            return (&MMI_large_font);
        case SUBLCD_FONT:
            return (&MMI_sublcd_font);
        case DIALER_FONT:
            return (&wgui_dialer_box_f1);
        default:
            return (&MMI_default_font);
    }
}


/*****************************************************************************
 * FUNCTION
 *  setup_previous_control
 * DESCRIPTION
 *  Set ups the coordinates for previous control.
 * PARAMETERS
 *  dm_coordinate_info      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void setup_previous_control(dm_coordinates *dm_coordinate_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_control_coordinates.coordinate.s16X = dm_coordinate_info->s16X;
    prev_control_coordinates.coordinate.s16Y = dm_coordinate_info->s16Y;
    prev_control_coordinates.coordinate.s16Height = dm_coordinate_info->s16Height;
    prev_control_coordinates.coordinate.s16Width = dm_coordinate_info->s16Width;
    prev_control_coordinates.s16X2 =
        prev_control_coordinates.coordinate.s16X + prev_control_coordinates.coordinate.s16Width - 1;
    prev_control_coordinates.s16Y2 =
        prev_control_coordinates.coordinate.s16Y + prev_control_coordinates.coordinate.s16Height - 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_exit_category_function
 * DESCRIPTION
 *  Common exit function for draw manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_exit_category_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DISPLAY_TYPE_COLOR__
    U16 old_on_idle_screen = on_idle_screen;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_WGUI_TRC_DM_SCREEN_INFO1, g_dm_data.s32CatId, g_dm_cntx.redraw_screen_main); 
    
    switch (g_dm_cntx.redraw_screen_main)
    {
            /* normal case */
        case NORMAL_REDRAW:
        case REDRAW_2_REDRAW:
            if (dm_backup_exit_category_function)
            {
                dm_backup_exit_category_function();
            }
            g_dm_cntx.redraw_screen_main = NORMAL_EXIT;
            break;

        case REDRAW_2_SHOW:
            break;

        default:
            MMI_ASSERT(0);
    }
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
#ifdef GDI_USING_LAYER_ROTATE
    //W06.04 Replace functions for GDI LCD Rotate
    if (gdi_lcd_get_rotate() == GDI_LCD_LAYER_ROTATE_0)
#endif /* GDI_USING_LAYER_ROTATE */ 
    {
#ifdef __MMI_DISPLAY_TYPE_COLOR__
        if (!dm_is_fixed_layer_mode_enabled())
        {
            
            if (g_dm_cntx.enable_small_screen_flatten == DM_SMALL_SCREEN_FLATTEN_FORCE_ON ||
                g_dm_cntx.enable_small_screen_flatten == DM_SMALL_SCREEN_FLATTEN_ON)
            {
                if (dm_layers[0] != GDI_ERROR_HANDLE || dm_layers[1] != GDI_ERROR_HANDLE || dm_layers[2] != GDI_ERROR_HANDLE ||
                    dm_layers[3] != GDI_ERROR_HANDLE)
                {
                    /* if scr_bg exist, then dm_layers[0] will not be blt, modified for lazy free */
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
                    if (!wgui_is_wallpaper_on_bottom() && 
                            old_on_idle_screen == 0 && 
                            (dm_layers[0] == g_dm_scr_bg_cntx.layer_handle))
#else
                    if (!wgui_is_wallpaper_on_bottom() && 
                            old_on_idle_screen == 0 && 
                            (dm_layers[0] == g_dm_scr_bg_cntx.layer_handle || dm_wallpaper_layer_idx == 0))
#endif
                    {
                        gdi_layer_flatten_to_base(dm_layers[1], dm_layers[2], dm_layers[3], GDI_ERROR_HANDLE);
                    }
                    else
                    {
                        gdi_layer_flatten_to_base(dm_layers[0], dm_layers[1], dm_layers[2], dm_layers[3]);
                    }
                }
            }
        }
#endif
        /* small screen flatten default on */
        dm_enable_small_screen_flatten();        
    }
#endif

    dm_reset_context();

    if (g_dm_cntx.exit_full_screen_on_exit)
    {
        g_dm_cntx.exit_full_screen_on_exit = MMI_FALSE;
        leave_full_screen();
    }

    if (wgui_is_wallpaper_on_bottom())
    {
        gOnFullScreen = MMI_LEAVE_BG_ON_BOTTOM_SCREEN;
        wgui_reset_wallpaper_on_bottom();   /* support wallpaper on bottom */
    }
}   /* end of dm_exit_category_function */

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  dm_sub_exit_category_function
 * DESCRIPTION
 *  Common exit function for draw manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_sub_exit_category_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_WGUI_TRC_DM_SUB_STATUS, g_dm_cntx.redraw_screen_sub);
    
    if (g_dm_sublcd_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        switch (g_dm_cntx.redraw_screen_sub)
        {
                /* normal case */
            case NORMAL_REDRAW:
            case REDRAW_2_REDRAW:
                if (dm_sub_backup_exit_category_function)
                {
                    dm_sub_backup_exit_category_function();
                }
                g_dm_cntx.redraw_screen_sub = NORMAL_EXIT;
                break;

            case REDRAW_2_SHOW:
                break;

            default:
                MMI_ASSERT(0);
        }
    }
    dm_reset_sublcd_context();
    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;

}

#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  dm_backup_current_category_exit_function
 * DESCRIPTION
 *  Save current exit function and set ExitCategoryFunction to dm_exit_category_function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_backup_current_category_exit_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_backup_exit_category_function = ExitCategoryFunction;
    ExitCategoryFunction = dm_exit_category_function;
}   /* end of dm_backup_current_category_exit_function */

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  dm_sub_backup_current_category_exit_function
 * DESCRIPTION
 *  Save current exit function and set ExitCategoryFunction to dm_exit_category_function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_sub_backup_current_category_exit_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_sub_backup_exit_category_function = SUBLCD_ExitCategoryFunction;
    SUBLCD_ExitCategoryFunction = dm_sub_exit_category_function;
}   /* end of dm_backup_current_category_exit_function */
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  dm_setup_category_functions
 * DESCRIPTION
 *  This function sets up the common-used functions for the Draw Manager
 * PARAMETERS
 *  redraw_function                 [IN]        
 *  get_history_function            [IN]        
 *  get_history_size_function       [IN]        
 *  dm_data(?)                      [IN]        Which contains the Draw Manager Information
 * RETURNS
 *  void
 *****************************************************************************/
void dm_setup_category_functions(
        FuncPtr redraw_function,
        U8 *(*get_history_function) (U8 *buffer),
        S32(*get_history_size_function) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RedrawCategoryFunction = redraw_function;
    GetCategoryHistory = get_history_function;
    GetCategoryHistorySize = get_history_size_function;
}

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  dm_sublcd_setup_data
 * DESCRIPTION
 *  This function sets up the information for the Sublcd Draw Manager
 * PARAMETERS
 *  dm_data     [IN]        Which contains the Draw Manager Information
 * RETURNS
 *  void
 *****************************************************************************/
void dm_sublcd_setup_data(dm_data_struct *dm_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_WGUI_TRC_DM_SUB_STATUS, g_dm_cntx.redraw_screen_sub); 
    
    g_dm_sublcd_data.s32CatId = dm_data->s32CatId;
    g_dm_sublcd_data.s32ScrId = dm_data->s32ScrId;
    g_dm_sublcd_data.s32flags = dm_data->s32flags;
    dm_sub_backup_current_category_exit_function();
    if (g_dm_sublcd_data.s32CatId == 0 && g_dm_sublcd_data.s32ScrId == 0 && g_dm_sublcd_data.s32flags == 0)
    {
        return;
    }

    if (g_dm_sublcd_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        /* Normal procedure */
        if (g_dm_cntx.redraw_screen_sub == NORMAL_EXIT)
        {
            g_dm_cntx.redraw_screen_sub = NORMAL_SHOW;
        }

        /* from redraw screen */
        else if (g_dm_cntx.redraw_screen_sub == NORMAL_REDRAW)
        {
            g_dm_cntx.redraw_screen_sub = NORMAL_REDRAW;
            /* MMI_ASSERT (0); */
        }

        /* from show screen */
        //              else if ( g_dm_cntx.redraw_screen_sub == NORMAL_SHOW )
        //                      MMI_ASSERT (0);
    }
}   /* end of dm_setup_data */


/*****************************************************************************
 * FUNCTION
 *  dm_sublcd_redraw_category_screen
 * DESCRIPTION
 *  This function redraws the Sublcd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_sublcd_redraw_category_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct g_dm_data_temp_struct;
    gdi_handle old_abm_src_layer_handle;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    gdi_handle sub_handle;
#ifdef __MMI_SUB_WALLPAPER__
    gdi_handle abm_layer;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_WGUI_TRC_DM_SUB_STATUS, g_dm_cntx.redraw_screen_sub); 
    
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    g_dm_data_temp_struct = g_dm_data;
    g_dm_data = g_dm_sublcd_data;
    g_dm_data.s32flags |= DM_SUB_LCD_CONTEXT;
    gdi_get_alpha_blending_source_layer(&old_abm_src_layer_handle);
#ifdef __MMI_SUB_WALLPAPER__
    abm_layer = wgui_sublcd_wallpaper_layer();
    if(abm_layer != GDI_ERROR_HANDLE)
    {
        gdi_set_alpha_blending_source_layer(abm_layer);
    }
    else
    {
        gdi_layer_get_base_handle(&sub_handle);
        gdi_set_alpha_blending_source_layer(sub_handle);
    }
#else
    gdi_layer_get_base_handle(&sub_handle);
    gdi_set_alpha_blending_source_layer(sub_handle);
#endif
    dm_redraw_category_screen();
    g_dm_data = g_dm_data_temp_struct;
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
    gdi_set_alpha_blending_source_layer(old_abm_src_layer_handle);
}   /* end of dm_setup_data */
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  dm_is_activated
 * DESCRIPTION
 *  Check whether the current
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL dm_is_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_data.s32CatId == 0)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_data
 * DESCRIPTION
 *  This function sets up the information for the Draw Manager
 * PARAMETERS
 *  dm_data     [IN]        Which contains the Draw Manager Information
 * RETURNS
 *  void
 *****************************************************************************/
void dm_setup_data(dm_data_struct *dm_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dm_data.s32CatId = dm_data->s32CatId;
    g_dm_data.s32ScrId = dm_data->s32ScrId;
    #ifdef __MMI_WEARABLE_DEVICE__
	#if  defined(__MMI_MAINLCD_128X128__)
	g_dm_data.s32flags = dm_data->s32flags | DM_NO_SOFTKEY;
	#else
    g_dm_data.s32flags = dm_data->s32flags | DM_NO_SOFTKEY | DM_NO_STATUS_BAR;
	if (MMI_TRUE == wgui_get_screen_is_show_softkey())
	{
		g_dm_data.s32flags |= DM_SHOW_SWATCH_SOFTKEY;
	}
	wgui_reset_screen_show_softkey();
	#endif /*__MMI_MAINLCD_128X128__*/
    #else  //__MMI_WEARABLE_DEVICE__
    g_dm_data.s32flags = dm_data->s32flags;
    #endif  //__MMI_WEARABLE_DEVICE__

    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_WGUI_TRC_DM_SCREEN_INFO, g_dm_data.s32CatId, g_dm_cntx.redraw_screen_main);
    
#ifdef __MMI_SUBLCD__
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_WGUI_TRC_DM_SUB_STATUS, g_dm_cntx.redraw_screen_sub);
#endif

    dm_backup_current_category_exit_function();

    if (g_dm_data.s32CatId == 0 && g_dm_data.s32ScrId == 0 && g_dm_data.s32flags == 0)
    {
        return;
    }

    /* initialize background in drawmanager */
    gdi_layer_set_background(GDI_COLOR_WHITE);

    /* Normal procedure */
    if (g_dm_cntx.redraw_screen_main == NORMAL_EXIT)
    {
        g_dm_cntx.redraw_screen_main = NORMAL_SHOW;
    }

    /* from redraw screen */
    else if (g_dm_cntx.redraw_screen_main == NORMAL_REDRAW)
    {
        g_dm_cntx.redraw_screen_main = REDRAW_2_SHOW;
        dm_reset_context();
        g_dm_cntx.redraw_screen_main = NORMAL_SHOW;
        /* MMI_ASSERT (0); */
    }

    /* from show screen */
    else if (g_dm_cntx.redraw_screen_main == NORMAL_SHOW)
    {
        ;
    }
    /* MMI_ASSERT (0); */

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
#ifdef __MMI_SCREEN_ROTATE__

    if (mmi_frm_is_screen_width_height_swapped())
    {
        /* Close status icon (but not entry_full_screen()) */
        close_title_status_icon();
        g_dm_cntx.exit_full_screen_on_exit = MMI_TRUE;
        /* Set screen background */
        g_dm_data.s32flags |= DM_CLEAR_SCREEN_BACKGROUND;

        if (!(g_dm_data.s32flags & DM_USER_DEFINE_ROTATE_BG_IMG) && current_MMI_theme->rotated_bkg_filler == NULL)
        {
            /* Keep draw manager opacity context unchanged */
            if (dm_check_control_exist(g_dm_data.s32CatId, DM_SCR_BG))
            {
                dm_set_scr_bg_image_no_draw(IMG_SCREEN_ROTATE_BACKGROUND, NULL, -1, -1, g_dm_scr_bg_cntx.layer_opacity);
            }
            else
            {
                dm_set_scr_bg_image(IMG_SCREEN_ROTATE_BACKGROUND, NULL, -1, -1, g_dm_scr_bg_cntx.layer_opacity);
            }
        }
    }
#endif /* __MMI_SCREEN_ROTATE__ */ 
#endif
}   /* end of dm_setup_data */


/*****************************************************************************
 * FUNCTION
 *  dm_search_coordinate_set
 * DESCRIPTION
 *  This function is used to search (binary search) the coordinate set corresponding to the passed Screen Id.
 * PARAMETERS
 *  ScrId           [IN]        
 *  s32ScrId(?)     [IN]        Screen Id corresponding to which coordinate set is to be obtained.
 * RETURNS
 *  void
 *****************************************************************************/
S16 *dm_search_coordinate_set(S32 ScrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 StartIndex = 0;
    S32 EndIndex = dm_get_coordinate_sets_count();
    S32 count = EndIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (EndIndex >= StartIndex)
    {
        S32 MiddleIndex = (EndIndex + StartIndex) >> 1;
        if(MiddleIndex >= count)
            break;
        if (g_screenid_coordinate_sets_map[MiddleIndex].screen_id == ScrId)
        {
            return g_screenid_coordinate_sets_map[MiddleIndex].coordinate_set_p;
        }
        else if (g_screenid_coordinate_sets_map[MiddleIndex].screen_id > ScrId)
        {
            EndIndex = MiddleIndex - 1;
        }
        else
        {
            StartIndex = MiddleIndex + 1;
        }
    }
    return NULL;
}   /* end of dm_search_coordinate_set */


/*****************************************************************************
 * FUNCTION
 *  dm_search_control_set
 * DESCRIPTION
 *  get control set address by category id
 * PARAMETERS
 *  category_id                     [IN]        Id of category screen
 *  default_coordinate_set_p        [IN]        
 * RETURNS
 *  U8 address of corresponding control set
 *****************************************************************************/
U8 *dm_search_control_set(S32 category_id, S16 **default_coordinate_set_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 min = 0, max = 0, mid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_ASSERT(category_id); */
    if (category_id == 0)
    {
        return NULL;
    }

    max = dm_get_control_sets_count();
    /* set max as max number of records */
    min = 0;
    *default_coordinate_set_p = NULL;
    while (min <= max)
    {
        mid = (max + min) >> 1;
        if (g_categories_controls_map[mid].category_id == (U16) category_id)
        {
        #ifdef __MMI_SCREEN_ROTATE__
            MMI_DBG_ASSERT(!mmi_frm_is_screen_width_height_swapped() ||
                           g_categories_controls_map[mid].rotated_coordinate_set_p);
            if (mmi_frm_is_screen_width_height_swapped() && g_categories_controls_map[mid].rotated_coordinate_set_p)
            {
                *default_coordinate_set_p = g_categories_controls_map[mid].rotated_coordinate_set_p;
            }
            else
            {
                *default_coordinate_set_p = g_categories_controls_map[mid].default_coordinate_set_p;
            }
        #else /* __MMI_SCREEN_ROTATE__ */ 
            *default_coordinate_set_p = g_categories_controls_map[mid].default_coordinate_set_p;
        #endif /* __MMI_SCREEN_ROTATE__ */ 
            return g_categories_controls_map[mid].control_set_p;
        }
        else if (g_categories_controls_map[mid].category_id > (U16) category_id)
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    MMI_ASSERT(0);
    return NULL;
}   /* end of dm_search_control_set */


/*****************************************************************************
 * FUNCTION
 *  dm_setup_base_layer
 * DESCRIPTION
 *  This function is used setup the base layer
 * PARAMETERS
 *  void
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_base_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd_handle);
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE && !(g_dm_data.s32flags & DM_SUB_LCD_CONTEXT))
    {
        MMI_ASSERT(0);
    }
    
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    if (!dm_is_fixed_layer_mode_enabled())
    {
#ifdef __MMI_SUBLCD__
    if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        gdi_layer_get_base_handle(&dm_layers_sub[dm_layers_count_sub++]);
    }
    else
#endif /* __MMI_SUBLCD__ */ 
        gdi_layer_get_base_handle(&dm_layers[dm_layers_count++]);
    }
#endif
    
    gdi_layer_restore_base_active();
    /* not to set source key when sublcd is b/w */
#if (defined __MMI_SUBLCD__) && (!defined __MMI_SUBLCD_COLOR__)
    if ( act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE )
    {
        gdi_layer_set_source_key(FALSE,0);
    }
    else
    {
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    }
#else
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
#endif

#ifndef __GDI_MEMORY_PROFILE_2__
    new_layer_x = 0;
    new_layer_y = 0;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    return 1;
}


#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
/*****************************************************************************
 * FUNCTION
 *  dm_setup_new_layer
 * DESCRIPTION
 *  This function is used setup a new layer
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_new_layer(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_layer_info;
    gdi_result ret;
    GDI_HANDLE dm_new_layers;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_multi_layer_enable();
#endif 

    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_layer_info);
    /* need to take care in REDRAW_2_REDRAW */
    if (g_dm_cntx.redraw_screen_main == REDRAW_2_REDRAW)
    {
        return 1;
    }

    if (dm_layer_info.s16X == -1 && dm_layer_info.s16Y == -1 && dm_layer_info.s16Width == -1 &&
        dm_layer_info.s16Height == -1)
    {
        return 1;
    }

#ifdef __GDI_MEMORY_PROFILE_2__ /* Multi-layer enable */

#ifdef __MMI_SUBLCD__

    if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        ret = gdi_layer_create(
                dm_layer_info.s16X,
                dm_layer_info.s16Y,
                dm_layer_info.s16Width,
                dm_layer_info.s16Height,
                &dm_layers_sub[dm_layers_count_sub]);
        MMI_ASSERT(ret >= 0);
        gdi_layer_set_active(dm_layers_sub[dm_layers_count_sub]);
        dm_layers_count_sub++;
    }
    else
#endif /* __MMI_SUBLCD__ */ 

    {
#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
        if (dm_layer_info.Flags & DM_NEW_LAYER_24)
        {
            ret = gdi_layer_create_cf(
                    GDI_COLOR_FORMAT_24,
                    dm_layer_info.s16X,
                    dm_layer_info.s16Y,
                    dm_layer_info.s16Width,
                    dm_layer_info.s16Height,
                    &dm_new_layers);
        }
        else
#endif /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */
        {
            ret = gdi_layer_create(
                    dm_layer_info.s16X,
                    dm_layer_info.s16Y,
                    dm_layer_info.s16Width,
                    dm_layer_info.s16Height,
                    &dm_new_layers);
        }
        MMI_ASSERT(ret >= 0);
        dm_layers[dm_layers_count] = dm_new_layers;
        gdi_layer_set_active(dm_layers[dm_layers_count]);
        dm_layers_count++;
    }
    /* 072706 source key Start */
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT); /* source key color could be customized later */
    if (dm_layer_info.Flags & DM_NEW_LAYER_WITH_COLOR)
    {
        gdi_layer_clear(GDI_COLOR_WHITE);
    }
    else
    {
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    }
    /* 072706 source key End */

    if (g_dm_data.s32flags & DM_SET_AS_ABM_LAYER)
    {
        gdi_set_alpha_blending_source_layer(dm_new_layers);
    }
    
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    new_layer_x = (U16) dm_layer_info.s16X;
    new_layer_y = (U16) dm_layer_info.s16Y;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    return 1;
}
#endif


#if ENABLE_CIRCULAR_3D_MENU
/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_circular_menu
 * DESCRIPTION
 *  This function is used setup the circular menu based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_circular_menu(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_3D_circular_menu_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_3D_circular_menu_info);
    DM_RETURN_IF_INVALID_COORD(&dm_3D_circular_menu_info);

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        move_circular_3d_menu(dm_3D_circular_menu_info.s16X, dm_3D_circular_menu_info.s16Y);
        resize_circular_3d_menu(dm_3D_circular_menu_info.s16Width, dm_3D_circular_menu_info.s16Height);
    }
    show_circular_3d_menu();
    return 1;
}

#endif /* ENABLE_CIRCULAR_3D_MENU */


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_fixed_list
 * DESCRIPTION
 *  This function is used setup the fixed list based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_fixed_list(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_fixed_list_info;
    MMI_BOOL resized = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_fixed_list_info);
    DM_RETURN_IF_INVALID_COORD(&dm_fixed_list_info);
#ifdef __MMI_WEARABLE_DEVICE_UI_ENHANCE__
	if (g_dm_data.s32flags & DM_SHOW_SWATCH_SOFTKEY)//show softkey
	{
		resize_fixed_icontext_menuitems(0, 49);
	}
#endif /*__MMI_WEARABLE_DEVICE_UI_ENHANCE__*/

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        if (dm_fixed_list_info.Flags & DM_CATEGORY_CONTROL_COORDINATES)
        {
            show_fixed_list();
        }
        else
        {
            move_fixed_list(dm_fixed_list_info.s16X, dm_fixed_list_info.s16Y);
            if (dm_fixed_list_info.s16Width != MMI_fixed_list_menu.width ||
                dm_fixed_list_info.s16Height != MMI_fixed_list_menu.height)
            {
                resized = MMI_TRUE;
            }
            resize_fixed_list(dm_fixed_list_info.s16Width, dm_fixed_list_info.s16Height);
            if (resized == MMI_TRUE)
            {
                fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
            }
            show_fixed_list();
        }
    }
    else
    {
        show_fixed_list();
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_dynamic_list
 * DESCRIPTION
 *  This function is used setup the dynamic list based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_dynamic_list(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_dynamic_list_info;
    
    /* Leo change 0705 start */
    MMI_BOOL resized = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_dynamic_list_info);
    DM_RETURN_IF_INVALID_COORD(&dm_dynamic_list_info);

    if ((g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW) &&
       !(dm_dynamic_list_info.Flags & DM_CATEGORY_CONTROL_COORDINATES))
    {
        move_fixed_list(dm_dynamic_list_info.s16X, dm_dynamic_list_info.s16Y);

        if (dm_dynamic_list_info.s16Width != MMI_fixed_list_menu.width ||
            dm_dynamic_list_info.s16Height != MMI_fixed_list_menu.height)
        {
            resized = MMI_TRUE;
        }
        resize_fixed_list(dm_dynamic_list_info.s16Width, dm_dynamic_list_info.s16Height - wgui_inputs_get_current_imui_height(MMI_EDITOR_SINGLE_LINE_INPU_BOX));

        if (resized == MMI_TRUE)
        {
            dynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
        }
        /* Leo change 0705 end */
    }
    show_dynamic_list();
    return 1;
}


#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_dynamic_matrix
 * DESCRIPTION
 *  This function is used setup the dynamic matrx based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_dynamic_matrix(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_matrix_menu_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_matrix_menu_info);
    DM_RETURN_IF_INVALID_COORD(&dm_matrix_menu_info);

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        move_fixed_matrix(dm_matrix_menu_info.s16X, dm_matrix_menu_info.s16Y);
        resize_fixed_matrix(dm_matrix_menu_info.s16Width, dm_matrix_menu_info.s16Height);
    }
    show_dynamic_matrix();
    return 1;
}
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_asyncdynamic_list
 * DESCRIPTION
 *  This function is used setup the asyncdynamic list based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_asyncdynamic_list(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_dynamic_list_info;
    
    /* Leo change 0705 start */
    MMI_BOOL resized = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_dynamic_list_info);
    DM_RETURN_IF_INVALID_COORD(&dm_dynamic_list_info);


    if ((g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW) &&
       !(dm_dynamic_list_info.Flags & DM_CATEGORY_CONTROL_COORDINATES))
    {
        move_fixed_list(dm_dynamic_list_info.s16X, dm_dynamic_list_info.s16Y);

        if (dm_dynamic_list_info.s16Width != MMI_fixed_list_menu.width ||
            dm_dynamic_list_info.s16Height != MMI_fixed_list_menu.height)
        {
            resized = MMI_TRUE;
        }
        resize_fixed_list(dm_dynamic_list_info.s16Width, dm_dynamic_list_info.s16Height);

        if (resized == MMI_TRUE)
        {
            asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
        }
        /* Leo change 0705 end */
    }

    show_asyncdynamic_list();
    return 1;
}


#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_asyncdynamic_matrix
 * DESCRIPTION
 *  This function is used setup the asyncdynamic matrx based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_asyncdynamic_matrix(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_matrix_menu_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_matrix_menu_info);
    DM_RETURN_IF_INVALID_COORD(&dm_matrix_menu_info);

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        move_fixed_matrix(dm_matrix_menu_info.s16X, dm_matrix_menu_info.s16Y);
        resize_fixed_matrix(dm_matrix_menu_info.s16Width, dm_matrix_menu_info.s16Height);
    }
    show_asyncdynamic_matrix();
    return 1;
}
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_matrix_menu
 * DESCRIPTION
 *  This function is used setup the matrix menu based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_matrix_menu(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_matrix_menu_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_matrix_menu_info);
    DM_RETURN_IF_INVALID_COORD(&dm_matrix_menu_info);

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        move_fixed_matrix(dm_matrix_menu_info.s16X, dm_matrix_menu_info.s16Y);
        if (fixed_matrix_auto_disable_scrollbar())
        {
            reset_fixed_matrix_col_rows();
        }
        resize_fixed_matrix(dm_matrix_menu_info.s16Width, dm_matrix_menu_info.s16Height);
    }
    show_fixed_matrix();
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_multiline_inputbox
 * DESCRIPTION
 *  This function is used setup the multiline inputbox based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_cat_scr_info         [?]             
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_multiline_inputbox(S16 **UICtrlAccessPtr_p, dm_cat_scr_info_struct *dm_cat_scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_multiline_inputbox_info;
    S32 vk_height = wgui_inputs_get_current_imui_height(MMI_EDITOR_MULTILINE_INPUT_BOX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_multiline_inputbox_info);

    if (!get_multiline_inputbox_display_status())
    {
        return 0;
    }

    DM_RETURN_IF_INVALID_COORD(&dm_multiline_inputbox_info);

#if defined(__MMI_FTE_SUPPORT__)
    if (vk_height > MMI_BUTTON_BAR_HEIGHT)
    {
        vk_height -= MMI_BUTTON_BAR_HEIGHT;
#ifdef __MMI_ICON_BAR_SUPPORT__
        if(MMI_TRUE == wgui_icon_bar_is_created())
        {
            vk_height -= MMI_ICON_BAR_HEIGHT;
        }
#endif		
    }
#endif

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        if (dm_multiline_inputbox_info.Flags & DM_FIXED_MULTILINE_INPUTBOX_HEIGHT)
        {
            S32 w = 0, h = 0;

            resize_multiline_inputbox_fit(
                dm_multiline_inputbox_info.s16Width,
                dm_multiline_inputbox_info.s16Height,
                &w,
                &h);
        }
        if (!dm_aligned_area_data.is_in_aligned_area)
        {
            if (wgui_inputbox_information_flag && (!(g_dm_data.s32flags & DM_SINGLE_LINE_INPUT_BOX_WITH_INFORMATION_BAR)))
            {
            #ifdef __MMI_SMALL_EDIT_SCREEN__
                /* START VIJAY PMT 20051202 */
                if (whether_no_small_screen())
                {
                    wgui_setup_input_information(
                        dm_multiline_inputbox_info.s16X + 1,
                        dm_multiline_inputbox_info.s16Y,
                        dm_multiline_inputbox_info.s16Width - 2,
                        wgui_inputbox_information_bar_height);
                }
                else
            #endif /* __MMI_SMALL_EDIT_SCREEN__ */ 
                    /* END VIJAY PMT 20051202 */
                    wgui_setup_input_information(
                        dm_multiline_inputbox_info.s16X,
                        dm_multiline_inputbox_info.s16Y,
                        dm_multiline_inputbox_info.s16Width,
                        wgui_inputbox_information_bar_height);

                move_multiline_inputbox(
                    dm_multiline_inputbox_info.s16X,
                    dm_multiline_inputbox_info.s16Y + wgui_inputbox_information_bar_height);
                //Currently this is assuming that Multitap is always being shown whenever multiline
                //inputbox is shown, so this needs to be FIXED and appropriates condition needs to be checked here.
                if (!is_multiline_inputbox_in_view_mode())
                {
                    if (dm_multiline_inputbox_info.Flags & DM_FIXED_MULTILINE_INPUTBOX_HEIGHT)
                    {
                        dm_multiline_inputbox_info.s16Height = get_multiline_inputbox_height();
                    }
                    resize_multiline_inputbox(
                        dm_multiline_inputbox_info.s16Width,
                        dm_multiline_inputbox_info.s16Height - wgui_inputbox_information_bar_height - vk_height);
                    dm_update_multitap_coordinates(&dm_multiline_inputbox_info, dm_cat_scr_info);
                }
                else
                {
                    if (dm_multiline_inputbox_info.Flags & DM_FIXED_MULTILINE_INPUTBOX_HEIGHT)
                    {
                        dm_multiline_inputbox_info.s16Height = get_multiline_inputbox_height();
                    }
                    resize_multiline_inputbox(
                        dm_multiline_inputbox_info.s16Width,
                        dm_multiline_inputbox_info.s16Height - wgui_inputbox_information_bar_height - vk_height);
                }
            }
            else
            {

                move_multiline_inputbox(dm_multiline_inputbox_info.s16X, dm_multiline_inputbox_info.s16Y);
                if (!is_multiline_inputbox_in_view_mode())
                {
                    if (dm_multiline_inputbox_info.Flags & DM_FIXED_MULTILINE_INPUTBOX_HEIGHT)
                    {
                        dm_multiline_inputbox_info.s16Height = get_multiline_inputbox_height();
                    }
                    resize_multiline_inputbox(
                        dm_multiline_inputbox_info.s16Width,
                        dm_multiline_inputbox_info.s16Height - vk_height);
                    dm_update_multitap_coordinates(&dm_multiline_inputbox_info, dm_cat_scr_info);
                }
                else
                {
                    if (dm_multiline_inputbox_info.Flags & DM_FIXED_MULTILINE_INPUTBOX_HEIGHT)
                    {
                        dm_multiline_inputbox_info.s16Height = get_multiline_inputbox_height();
                    }
                    resize_multiline_inputbox(
                        dm_multiline_inputbox_info.s16Width,
                        dm_multiline_inputbox_info.s16Height - vk_height);
                }
            }
            setup_previous_control(&dm_multiline_inputbox_info);

        }       /* ( ! dm_aligned_area_data.is_in_aligned_area ) */
        else    /* ( dm_aligned_area_data.is_in_aligned_area ) */
        {
            dm_aligned_area_data.s16Y += dm_aligned_area_data.y_space;
            move_multiline_inputbox(dm_aligned_area_data.s16X, dm_aligned_area_data.s16Y);
            dm_aligned_area_data.s16Y += get_multiline_inputbox_height();
        }   /* ( dm_aligned_area_data.is_in_aligned_area ) */
    }
    else if (dm_aligned_area_data.is_in_aligned_area)
    {
        dm_aligned_area_data.s16Y += dm_aligned_area_data.y_space;
        dm_aligned_area_data.s16Y += get_multiline_inputbox_height();
    }

    if (dm_multiline_inputbox_info.Flags & (!(g_dm_data.s32flags & DM_SINGLE_LINE_INPUT_BOX_WITH_INFORMATION_BAR)))
    {
        show_multiline_inputbox();
    }
    else
    {
        wgui_show_inputbox();
    }    
    return 1;
}


#ifdef UI_EMS_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_ems_inputbox
 * DESCRIPTION
 *  This function is used setup the EMS inputbox based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_cat_scr_info         [?]             
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_ems_inputbox(S16 **UICtrlAccessPtr_p, dm_cat_scr_info_struct *dm_cat_scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_multiline_inputbox_info;
    S32 vk_height = wgui_inputs_get_current_imui_height(MMI_EDITOR_EMS_INPUT_BOX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_multiline_inputbox_info);
    DM_RETURN_IF_INVALID_COORD(&dm_multiline_inputbox_info);

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        if (!dm_aligned_area_data.is_in_aligned_area)
        {
            if (wgui_inputbox_information_flag)
            {
                wgui_EMS_setup_input_information(
                    dm_multiline_inputbox_info.s16X,
                    dm_multiline_inputbox_info.s16Y,
                    dm_multiline_inputbox_info.s16Width,
                    wgui_EMS_inputbox_information_bar_height);
                move_EMS_inputbox(
                    dm_multiline_inputbox_info.s16X,
                    dm_multiline_inputbox_info.s16Y + wgui_EMS_inputbox_information_bar_height);
                //Currently this is assuming that Multitap is always being shown whenever multiline
                //inputbox is shown, so this needs to be FIXED and appropriates condition needs to be checked here.
                if (!is_EMS_inputbox_in_view_mode())
                {
                    if (g_dm_data.s32flags & DM_FIXED_MULTILINE_INPUTBOX_HEIGHT)
                    {
                        resize_EMS_inputbox(
                            dm_multiline_inputbox_info.s16Width,
                            get_multiline_inputbox_height() - wgui_inputbox_information_bar_height - vk_height);
                    }
                    else
                    {
                        resize_EMS_inputbox(
                            dm_multiline_inputbox_info.s16Width,
                            dm_multiline_inputbox_info.s16Height - wgui_inputbox_information_bar_height - vk_height);
                    }
                    dm_update_multitap_coordinates(&dm_multiline_inputbox_info, dm_cat_scr_info);
                }
                else
                {
                    if (g_dm_data.s32flags & DM_FIXED_MULTILINE_INPUTBOX_HEIGHT)
                    {
                        resize_EMS_inputbox(
                            dm_multiline_inputbox_info.s16Width,
                            get_multiline_inputbox_height() - wgui_inputbox_information_bar_height - vk_height);
                    }
                    else
                    {
                        resize_EMS_inputbox(
                            dm_multiline_inputbox_info.s16Width,
                            dm_multiline_inputbox_info.s16Height - wgui_inputbox_information_bar_height - vk_height);
                    }
                }
            }
            else
            {

                move_EMS_inputbox(dm_multiline_inputbox_info.s16X, dm_multiline_inputbox_info.s16Y);
                if (!is_EMS_inputbox_in_view_mode())
                {
                    if (g_dm_data.s32flags & DM_FIXED_MULTILINE_INPUTBOX_HEIGHT)
                    {
                        resize_EMS_inputbox(dm_multiline_inputbox_info.s16Width, get_multiline_inputbox_height() -vk_height);
                    }
                    else
                    {
                        resize_EMS_inputbox(dm_multiline_inputbox_info.s16Width, dm_multiline_inputbox_info.s16Height - vk_height);
                    }
                    dm_update_multitap_coordinates(&dm_multiline_inputbox_info, dm_cat_scr_info);
                }
                else
                {
                    if (g_dm_data.s32flags & DM_FIXED_MULTILINE_INPUTBOX_HEIGHT)
                    {
                        resize_EMS_inputbox(dm_multiline_inputbox_info.s16Width, get_multiline_inputbox_height() - vk_height);
                    }
                    else
                    {
                        resize_EMS_inputbox(dm_multiline_inputbox_info.s16Width, dm_multiline_inputbox_info.s16Height - vk_height);
                    }
                }
            }
        }       /* ( ! dm_aligned_area_data.is_in_aligned_area ) */
        else    /* ( dm_aligned_area_data.is_in_aligned_area ) */
        {
            dm_aligned_area_data.s16Y += dm_aligned_area_data.y_space;
            move_EMS_inputbox(dm_aligned_area_data.s16X, dm_aligned_area_data.s16Y);
            dm_aligned_area_data.s16Y += get_multiline_inputbox_height();
        }   /* ( dm_aligned_area_data.is_in_aligned_area ) */
    }
    /* category5_hide_multitap(); */
    /* W05.38 Display Information Bar no matter REDRAW_2_REDRAW or not */
    if (wgui_inputbox_information_flag)
    {
        wgui_EMS_redraw_input_information_bar();
    }
    show_EMS_inputbox();
    return 1;
}
#endif /* UI_EMS_SUPPORT */


#ifdef __MMI_EDITOR_DIALER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_dialer_inputbox
 * DESCRIPTION
 *  This function is used setup the dialer inputbox based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_dialer_inputbox(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_dialer_inputbox_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_dialer_inputbox_info);
    DM_RETURN_IF_INVALID_COORD(&dm_dialer_inputbox_info);

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        move_dialer_inputbox(dm_dialer_inputbox_info.s16X, dm_dialer_inputbox_info.s16Y);
        resize_dialer_inputbox(dm_dialer_inputbox_info.s16Width, dm_dialer_inputbox_info.s16Height);
    }
    show_dialer_inputbox();
    return 1;
}
#endif


#if 1//def __MMI_EDITOR_SINGLINE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_singleline_inputbox
 * DESCRIPTION
 *  This function is used setup the singleline inputbox based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_singleline_inputbox(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_singleline_inputbox_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_singleline_inputbox_info);
    DM_RETURN_IF_INVALID_COORD(&dm_singleline_inputbox_info);

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        if (!dm_aligned_area_data.is_in_aligned_area)
        {
            move_singleline_inputbox(dm_singleline_inputbox_info.s16X, dm_singleline_inputbox_info.s16Y);
            if (dm_singleline_inputbox_info.Flags & DM_SINGLE_LINE_INPUTBOX_SPECIFIC_HEIGHT)
            {
                resize_singleline_inputbox(dm_singleline_inputbox_info.s16Width, dm_singleline_inputbox_info.s16Height);
            }
        }
        else
        {
            dm_aligned_area_data.s16Y += dm_aligned_area_data.y_space;
            move_singleline_inputbox(dm_aligned_area_data.s16X, dm_aligned_area_data.s16Y);
            dm_aligned_area_data.s16Y += MMI_singleline_inputbox_height;
        }
    }
    /* information bar with single line inputbox */
    if (wgui_inputbox_information_flag && (g_dm_data.s32flags & DM_SINGLE_LINE_INPUT_BOX_WITH_INFORMATION_BAR))
    {
        wgui_redraw_singleline_input_information_bar();         
    }    
    show_singleline_inputbox();
    return 1;
}
#endif


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_softkey
 * DESCRIPTION
 *  This function is used setup the right softkey based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_softkey(U8 soft_key, S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_icontext_button_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_icontext_button_info);
    DM_RETURN_IF_INVALID_COORD(&dm_icontext_button_info);

    if(soft_key == DM_LSK)
    {
        if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
        {
            move_softkey(dm_icontext_button_info.s16X, dm_icontext_button_info.s16Y, MMI_LEFT_SOFTKEY);
            resize_left_softkey(dm_icontext_button_info.s16Width, dm_icontext_button_info.s16Height);
        }
        show_left_softkey();
    }
    else
    {
        if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
        {
            move_softkey(dm_icontext_button_info.s16X, dm_icontext_button_info.s16Y, MMI_RIGHT_SOFTKEY);
            resize_right_softkey(dm_icontext_button_info.s16Width, dm_icontext_button_info.s16Height);
        }
        show_right_softkey();
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_title
 * DESCRIPTION
 *  This function is used setup the title bar  based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_title(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_title_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_title_info);
    if (dm_title_info.s16X == -1 || dm_title_info.s16Y == -1 ||
        dm_title_info.s16Width == -1 || dm_title_info.s16Height == -1)
    {
        wgui_title_set_menu_shortcut_handler_display(MMI_TRUE);
        //MMI_title_string = NULL;
        //MMI_title_icon = NULL;
        return 0;
    }
    if ((g_dm_data.s32flags & DM_NO_TITLE))
    {
        return 0;
    }

    if (dm_title_info.Flags & DM_TITLE_SET_THICK)
    {
        wgui_title_set_thick(MMI_TRUE);
    }
    else
    {
        wgui_title_set_thick(MMI_FALSE);
    }

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        move_title(dm_title_info.s16X, dm_title_info.s16Y);
        resize_title(dm_title_info.s16Width, dm_title_info.s16Height);
        /* START VIJAY PMT 20050930 */
        move_menu_shortcut_handler(MMI_title_x + MMI_title_width - MMI_menu_shortcut_box.width, MMI_title_y);   /* PMT MANISH 20050707 */
        /* END VIJAY PMT 20050930 */

    }

	#if defined(__MMI_WEARABLE_DEVICE__) && (defined(__MMI_MAINLCD_240X240__)||defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_320X320__))
	g_dm_data.s32flags = g_dm_data.s32flags | DM_LEFT_ALIGN_TITLE;
	#endif /*defined(__MMI_WEARABLE_DEVICE__) && defined(__MMI_MAINLCD_240X240__)*/
    if (g_dm_data.s32flags & DM_LEFT_ALIGN_TITLE)
    {
        draw_title_left_align();
    }
    else if (g_dm_data.s32flags & DM_SCROLL_TITLE)
    {
        setup_scrolling_title();
        draw_scrolling_title();
    }
    else
    {
        draw_title();
    }
    return 1;
}


#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_horizontal_tab_bar
 * DESCRIPTION
 *  This function is used setup the horizontal tab bar based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_horizontal_tab_bar(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_htab_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_htab_info);

#ifdef __MMI_TAB_BARS_SUPPORT__
    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        wgui_move_horizontal_tab_bar(dm_htab_info.s16X, dm_htab_info.s16Y);
    }
    wgui_show_horizontal_tab_bar();
#endif
    return 1;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_category_controlled_area
 * DESCRIPTION
 *  This function is used setup the category controlled area based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_category_controlled_area(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_category_controlled_area_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_category_controlled_area_info);
    DM_RETURN_IF_INVALID_COORD(&dm_category_controlled_area_info);

#ifdef __MMI_SUBLCD__
    if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        if (dm_sub_category_controlled_area_callback)
        {
            (*dm_sub_category_controlled_area_callback) (&dm_category_controlled_area_info);
        }
    }
    else
#endif /* __MMI_SUBLCD__ */ 
    {
        if (dm_category_controlled_area_callback)
        {
            (*dm_category_controlled_area_callback) (&dm_category_controlled_area_info);
        }
    }
    setup_previous_control(&dm_category_controlled_area_info);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_category_controlled_area2
 * DESCRIPTION
 *  This function is used setup the category controlled area2 based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_category_controlled_area2(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_category_controlled_area_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_category_controlled_area_info);
    DM_RETURN_IF_INVALID_COORD(&dm_category_controlled_area_info);

    if (dm_category_controlled_area2_callback)
    {
        (*dm_category_controlled_area2_callback) (&dm_category_controlled_area_info);
    }

    setup_previous_control(&dm_category_controlled_area_info);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_status_icons
 * DESCRIPTION
 *  This function is used setup the status icons based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_status_icons(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_status_info_struct dm_status_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_status_icon_bar_coordinates(*UICtrlAccessPtr_p, &dm_status_info);

    if (dm_status_info.x == -1 || dm_status_info.y == -1 ||
        dm_status_info.x1 == -1 || dm_status_info.y1 == -1 || dm_status_info.x2 == -1 || dm_status_info.y2 == -1)
    {
        return 0;
    }
    if ((g_dm_data.s32flags & DM_NO_STATUS_BAR))
    {
        return 0;
    }

#ifdef __MMI_SUBLCD__
    if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        SUBLCD_screens_show_status_icons();
    }
    else
#endif /* __MMI_SUBLCD__ */ 
    {
#if ((defined(__MMI_WEARABLE_DEVICE__) && defined(__MMI_MAINLCD_128X128__)) || \
	(!defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)))
        if ((g_dm_data.s32flags & DM_SPECIFIC_HIDE_STATUS_BAR))
        {
            wgui_status_icon_bar_update();
        }
        else
        {
            show_title_status_icon();
        }
#else /* !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) */
        wgui_status_icon_bar_update();
#endif /* !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) */
    }
    return 1;
}


#ifdef __MMI_WEARABLE_DEVICE__

MMI_BOOL dm_swatch_ajust_softkey_coordinates(dm_buttonbar_info_struct *dm_buttonbar_info)
{
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((MMI_softkeys[MMI_LEFT_SOFTKEY].text == NULL) && (MMI_softkeys[MMI_RIGHT_SOFTKEY].text == NULL))
	{
		return MMI_FALSE;
	}
	else if (MMI_softkeys[MMI_LEFT_SOFTKEY].text == NULL || MMI_softkeys[MMI_RIGHT_SOFTKEY].text == NULL)
	{
		dm_buttonbar_info->button_width = dm_buttonbar_info->coordinate.s16Width;
	}
	
	if (g_dm_cntx.redraw_screen_main == REDRAW_2_REDRAW)	
	{
		move_softkey(dm_buttonbar_info->coordinate.s16X, dm_buttonbar_info->coordinate.s16Y, MMI_LEFT_SOFTKEY);
        resize_softkey(dm_buttonbar_info->button_width, dm_buttonbar_info->coordinate.s16Height, MMI_LEFT_SOFTKEY);
		move_softkey(
                dm_buttonbar_info->coordinate.s16X + dm_buttonbar_info->coordinate.s16Width - dm_buttonbar_info->button_width,
                dm_buttonbar_info->coordinate.s16Y,
                MMI_RIGHT_SOFTKEY);
        resize_softkey(dm_buttonbar_info->button_width, dm_buttonbar_info->coordinate.s16Height, MMI_RIGHT_SOFTKEY);
	}

	return MMI_TRUE;
}


#endif /*__MMI_WEARABLE_DEVICE__*/
/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_button_bar
 * DESCRIPTION
 *  This function is used setup the button bar based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_button_bar(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_buttonbar_info_struct dm_buttonbar_info;
    S32 tool_bar_height = 0;

	#ifndef __MMI_WEARABLE_DEVICE_UI_ENHANCE__
	color line_color;
	line_color.r = 61;
	line_color.g = 107;
	line_color.b = 120;
	#endif //__MMI_WEARABLE_DEVICE__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        tool_bar_height = MMI_ICON_BAR_HEIGHT;
    }
#endif
#endif
    *UICtrlAccessPtr_p = dm_get_button_bar_coordinates(*UICtrlAccessPtr_p, &dm_buttonbar_info);

    if (dm_buttonbar_info.coordinate.s16X == -1 || dm_buttonbar_info.coordinate.s16Y == -1 ||
        dm_buttonbar_info.coordinate.s16Width == -1 || dm_buttonbar_info.coordinate.s16Height == -1 ||
        dm_buttonbar_info.button_width == -1)
    {
        return 0;
    }

	#ifdef __MMI_WEARABLE_DEVICE__
	if (g_dm_data.s32flags & DM_NO_SOFTKEY)
		if (!(g_dm_data.s32flags & DM_SHOW_SWATCH_SOFTKEY))
	#else
    if (g_dm_data.s32flags & DM_NO_SOFTKEY)
	#endif
    {
        return 0;
    }

	#ifdef __MMI_WEARABLE_DEVICE__


	if (MMI_FALSE == dm_swatch_ajust_softkey_coordinates(&dm_buttonbar_info)) //don't need show softkey
	{
		return;
	}
	MMI_softkey_height = dm_buttonbar_info.coordinate.s16Height - tool_bar_height;
	//draw line
	#ifndef __MMI_WEARABLE_DEVICE_UI_ENHANCE__
	gui_line(dm_buttonbar_info.coordinate.s16X, dm_buttonbar_info.coordinate.s16Y - 1, \
		dm_buttonbar_info.coordinate.s16X + dm_buttonbar_info.coordinate.s16Width - 1,\
		dm_buttonbar_info.coordinate.s16Y - 1, line_color);
	#endif /*__MMI_WEARABLE_DEVICE_UI_ENHANCE__*/
	
	#endif /*__MMI_WEARABLE_DEVICE__*/
    if (g_dm_cntx.redraw_screen_main == REDRAW_2_REDRAW)
    {
        if (!(dm_buttonbar_info.coordinate.Flags & DM_BUTTON_DISABLE_BACKGROUND))
        {
            show_softkey_background();
            draw_arrow_indication(
                (S8) (dm_buttonbar_info.coordinate.Flags & DM_BUTTON_BAR_LEFT_ARROW),
                (S8) (dm_buttonbar_info.coordinate.Flags & DM_BUTTON_BAR_RIGHT_ARROW),
                (S8) (dm_buttonbar_info.coordinate.Flags & DM_BUTTON_BAR_UP_ARROW),
                (S8) (dm_buttonbar_info.coordinate.Flags & DM_BUTTON_BAR_DOWN_ARROW));
        }

		#ifdef __MMI_WEARABLE_DEVICE__
		if (!(g_dm_data.s32flags & DM_NO_SOFTKEY) || (g_dm_data.s32flags & DM_SHOW_SWATCH_SOFTKEY))
		#else
        if (!(g_dm_data.s32flags & DM_NO_SOFTKEY))
		#endif
        {
            show_softkey(MMI_LEFT_SOFTKEY);
            show_softkey(MMI_RIGHT_SOFTKEY);
            show_softkey(MMI_CENTER_SOFTKEY);
#ifdef __MMI_ICON_BAR_SUPPORT__
        #if defined(__MMI_FTE_SUPPORT__)
        if(MMI_TRUE == wgui_icon_bar_is_created())
        {
            wgui_icon_bar_update();
        }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/		
        }
		#ifdef __MMI_WEARABLE_DEVICE__
		MMI_softkey_height = 0;
		#endif //_MMI_WEARABLE_DEVICE__
        return 1;
    }

    gui_reset_clip();

    set_button_bar_height(dm_buttonbar_info.coordinate.s16Height - tool_bar_height);

    if (!(dm_buttonbar_info.coordinate.Flags & DM_BUTTON_DISABLE_BACKGROUND))
    {
        show_softkey_background();
        draw_arrow_indication(
            (S8) (dm_buttonbar_info.coordinate.Flags & DM_BUTTON_BAR_LEFT_ARROW),
            (S8) (dm_buttonbar_info.coordinate.Flags & DM_BUTTON_BAR_RIGHT_ARROW),
            (S8) (dm_buttonbar_info.coordinate.Flags & DM_BUTTON_BAR_UP_ARROW),
            (S8) (dm_buttonbar_info.coordinate.Flags & DM_BUTTON_BAR_DOWN_ARROW));
    }

	//add by xl
	#ifdef __MMI_WEARABLE_DEVICE__
    if (!(g_dm_data.s32flags & DM_NO_SOFTKEY) || (g_dm_data.s32flags & DM_SHOW_SWATCH_SOFTKEY))
	#else
    if (!(g_dm_data.s32flags & DM_NO_SOFTKEY))
	#endif //_MMI_WEARABLE_DEVICE__
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            /* Vertical softkey bar aligned to right  */
            /* FIXME. replace fixed value MMI_ROTATED_SOFTKEY_HEIGHT */
            set_softkey_flags_on(UI_BUTTON_RIGHT_ALIGN, MMI_LEFT_SOFTKEY);
            set_softkey_flags_off(UI_BUTTON_LEFT_ALIGN, MMI_LEFT_SOFTKEY);
            move_softkey(
                dm_buttonbar_info.coordinate.s16X,
                dm_buttonbar_info.coordinate.s16Y + dm_buttonbar_info.coordinate.s16Height - MMI_ROTATED_SOFTKEY_HEIGHT,
                MMI_LEFT_SOFTKEY);
            resize_softkey(dm_buttonbar_info.button_width, MMI_ROTATED_SOFTKEY_HEIGHT, MMI_LEFT_SOFTKEY);
            show_softkey(MMI_LEFT_SOFTKEY);

            move_softkey(dm_buttonbar_info.coordinate.s16X, dm_buttonbar_info.coordinate.s16Y, MMI_RIGHT_SOFTKEY);
            resize_softkey(dm_buttonbar_info.button_width, MMI_ROTATED_SOFTKEY_HEIGHT, MMI_RIGHT_SOFTKEY);
            show_softkey(MMI_RIGHT_SOFTKEY);

            set_softkey_flags_on(UI_BUTTON_RIGHT_ALIGN, MMI_CENTER_SOFTKEY);
            set_softkey_flags_off(UI_BUTTON_LEFT_ALIGN, MMI_CENTER_SOFTKEY);
            set_softkey_flags_off(UI_BUTTON_CENTER_ICON_X, MMI_CENTER_SOFTKEY);
            move_softkey(
                dm_buttonbar_info.coordinate.s16X,
                dm_buttonbar_info.coordinate.s16Y + MMI_ROTATED_SOFTKEY_HEIGHT + ((dm_buttonbar_info.coordinate.s16Height - MMI_ROTATED_SOFTKEY_HEIGHT * 3) >> 1),
                MMI_CENTER_SOFTKEY);
            resize_softkey(dm_buttonbar_info.button_width, MMI_ROTATED_SOFTKEY_HEIGHT, MMI_CENTER_SOFTKEY);
            show_softkey(MMI_CENTER_SOFTKEY);
        }
        else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
        {
            move_softkey(dm_buttonbar_info.coordinate.s16X, dm_buttonbar_info.coordinate.s16Y + tool_bar_height, MMI_LEFT_SOFTKEY);
            resize_softkey(dm_buttonbar_info.button_width, dm_buttonbar_info.coordinate.s16Height - tool_bar_height, MMI_LEFT_SOFTKEY);
            show_softkey(MMI_LEFT_SOFTKEY);

            move_softkey(
                dm_buttonbar_info.coordinate.s16X + dm_buttonbar_info.coordinate.s16Width - dm_buttonbar_info.button_width,
                dm_buttonbar_info.coordinate.s16Y + tool_bar_height,
                MMI_RIGHT_SOFTKEY);
            resize_softkey(dm_buttonbar_info.button_width, dm_buttonbar_info.coordinate.s16Height - tool_bar_height, MMI_RIGHT_SOFTKEY);
            show_softkey(MMI_RIGHT_SOFTKEY);
            move_softkey(
                dm_buttonbar_info.coordinate.s16X + dm_buttonbar_info.button_width + ((dm_buttonbar_info.coordinate.s16Width - (dm_buttonbar_info.button_width * 2) - MMI_CENTER_SOFTKEY_WIDTH) >> 1),
                dm_buttonbar_info.coordinate.s16Y + tool_bar_height,
                MMI_CENTER_SOFTKEY);
            resize_softkey(MMI_CENTER_SOFTKEY_WIDTH, dm_buttonbar_info.coordinate.s16Height - tool_bar_height, MMI_CENTER_SOFTKEY);
            show_softkey(MMI_CENTER_SOFTKEY);

#ifdef __MMI_ICON_BAR_SUPPORT__
        #if defined(__MMI_FTE_SUPPORT__)
            if(MMI_TRUE == wgui_icon_bar_is_created())
            {
                wgui_icon_bar_move(0, UI_device_height - MMI_softkey_height - tool_bar_height);
                wgui_icon_bar_resize(UI_device_width, tool_bar_height);
                wgui_icon_bar_show();
            }
        #endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/		
        }
    }
	#ifdef __MMI_WEARABLE_DEVICE__
	MMI_softkey_height = 0;
	#endif //_MMI_WEARABLE_DEVICE__
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_inline_item
 * DESCRIPTION
 *  This function is used setup the inline items based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_inline_item(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_inline_fixed_list_info;
    fixed_icontext_menuitem *menuitem_p;
    S32 imui_height = wgui_inputs_get_current_imui_height(MMI_EDITOR_INLINE_INPUT_BOX);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_inline_fixed_list_info);
    DM_RETURN_IF_INVALID_COORD(&dm_inline_fixed_list_info);

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        gui_set_font(&MMI_medium_font);
        MMI_fixed_icontext_menuitem.text_font = &MMI_medium_font;
        MMI_fixed_text_menuitem.text_font = &MMI_medium_font;

        move_fixed_list(dm_inline_fixed_list_info.s16X, dm_inline_fixed_list_info.s16Y);
    #ifdef __MMI_FTE_SUPPORT__         
        if (imui_height)
        {
            resize_fixed_list(MMI_fixed_list_menu.width, UI_device_height - MMI_fixed_list_menu.y - imui_height);
        }
#ifdef __MMI_ICON_BAR_SUPPORT__
        else if(wgui_icon_bar_is_created())
        {
            resize_fixed_list(dm_inline_fixed_list_info.s16Width , dm_inline_fixed_list_info.s16Height - MMI_ICON_BAR_HEIGHT);
        }  
#endif		
        else
    #endif    
        {
            resize_fixed_list(dm_inline_fixed_list_info.s16Width, dm_inline_fixed_list_info.s16Height - imui_height);
        }
        /* W06.05 Do not draw fixed list in category57 because of virtual keyboard */
        if ((g_dm_data.s32flags & DM_SHOW_VKPAD))
        {
        #if defined(__MMI_TOUCH_SCREEN__)
            mmi_imc_set_inline_editor_full_height(dm_inline_fixed_list_info.s16Height);
        #endif
        #if defined(__MMI_VIRTUAL_KEYBOARD__)
            #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
            if ((GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY != MMI_virtual_keyboard.lang_type)
            #else
            if ((GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY != g_wgui_virtual_keyboard_lang_type)
            #endif
                && (!((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)))
            {
                /* W06.07 Locate highlighted item after resizing fixed list menu */
                gui_fixed_list_menu_locate_highlighted_item(&MMI_fixed_list_menu);
                /* W06.10 Make sure that the inline multi line edit is the first display item */
                if ((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
                {
                    MMI_fixed_list_menu.first_displayed_item = MMI_fixed_list_menu.highlighted_item;
                }
            }
        #endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */ 
        }

        menuitem_p = (fixed_icontext_menuitem*) MMI_fixed_list_menu.common_item_data;

        /* menuitem_p->width = dm_inline_fixed_list_info.s16Width; */
        gui_set_fixed_list_menu_common_item_data(&MMI_fixed_list_menu, menuitem_p);
        move_fixed_list(dm_inline_fixed_list_info.s16X, dm_inline_fixed_list_info.s16Y);
    }

    show_fixed_list();
    redraw_current_inline_item();
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_base_control_set
 * DESCRIPTION
 *  This function is used setup the base control set based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  _UICtrlAccessPtr            [IN]            
 *  UICtrlAccessPtr_p(?)        [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_base_control_set(S16 **_UICtrlAccessPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *control_set_ptr;
    U8 u8CtrlCt = 0;
    U8 u8NoOfUICtrls = 0;
    S16 *UICtrlAccessPtr_p = NULL;

#ifdef __MMI_SCREEN_ROTATE__
    MMI_BOOL popup_in_rotated_screen = MMI_FALSE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    /*
     * 1. Draw a border around title and content area. 
     * 2. Clear content area because some category screen (e.g. 66) does not clear it.
     *
     * As a result, the content area will be white instead of background transparency.
     *
     * If a category screen do not want to use standard MMI_ROTATED_{CONTENT|TITLE}_{X|Y}, 
     * it should not contain DM_BASE_CONTROL_SET1 in its control set.
     */
    if (mmi_frm_is_screen_width_height_swapped())
    {
        popup_in_rotated_screen = dm_check_control_exist(g_dm_data.s32CatId, DM_POPUP_BACKGROUND);
        if (!popup_in_rotated_screen && /* Prevent to erase popup background here */
            !(g_dm_data.s32flags & DM_NO_TITLE))
        {
            gui_push_clip();
            gui_reset_clip();
            gui_fill_rectangle(
                MMI_ROTATED_TITLE_X - 1,
                MMI_ROTATED_TITLE_Y - 1,
                MMI_ROTATED_TITLE_X + MMI_ROTATED_TITLE_WIDTH,
                MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT + MMI_ROTATED_CONTENT_HEIGHT,
                gui_color(255, 255, 255));
            gui_pop_clip();
        }
    }
#endif /* __MMI_SCREEN_ROTATE__ */ 

    control_set_ptr = dm_get_base_control_set();
    UICtrlAccessPtr_p = dm_get_base_coordinate_set();
    u8NoOfUICtrls = control_set_ptr[0];
    for (u8CtrlCt = 1; u8CtrlCt <= u8NoOfUICtrls; u8CtrlCt++)
    {
        switch (control_set_ptr[u8CtrlCt])
        {
            case DM_TITLE1:
            {
                dm_setup_and_draw_title(&UICtrlAccessPtr_p);
                break;
            }
            case DM_STATUS_BAR1:
            {
                dm_setup_and_draw_status_icons(&UICtrlAccessPtr_p);
                break;
            }
            case DM_BUTTON_BAR1:
            {
                dm_setup_and_draw_button_bar(&UICtrlAccessPtr_p);
                break;
            }
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
            case DM_SCR_BG:
            {
                /* 
                 * In current design, DM_SCR_BG is included in base control set 
                 * by default when screen is rotated because there are undrawn
                 * areas around the title and content area and it looks bad 
                 * without full-screen background.
                 */
                if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
                {
                    dm_setup_and_draw_scr_bg(&UICtrlAccessPtr_p);
                }
                break;
            }
#endif
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_base_control_set2
 * DESCRIPTION
 *  This function is used setup the base control set 2 based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  _UICtrlAccessPtr            [IN]            
 *  UICtrlAccessPtr_p(?)        [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_base_control_set2(S16 **_UICtrlAccessPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *control_set_ptr;
    U8 u8CtrlCt = 0;
    U8 u8NoOfUICtrls = 0;
    S16 *UICtrlAccessPtr_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_set_ptr = dm_get_base_control_set2();
    UICtrlAccessPtr_p = dm_get_base_coordinate_set2();
    u8NoOfUICtrls = control_set_ptr[0];
    for (u8CtrlCt = 1; u8CtrlCt <= u8NoOfUICtrls; u8CtrlCt++)
    {
        switch (control_set_ptr[u8CtrlCt])
        {
            case DM_STATUS_BAR1:
            {
                dm_setup_and_draw_status_icons(&UICtrlAccessPtr_p);
                break;
            }
            case DM_BUTTON_BAR1:
            {
                dm_setup_and_draw_button_bar(&UICtrlAccessPtr_p);
                break;
            }
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
            case DM_SCR_BG:
            {
                dm_setup_and_draw_scr_bg(&UICtrlAccessPtr_p);
            }
#endif
        }
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_base_control_set_submenu
 * DESCRIPTION
 *  This function is used setup the base control set submenu based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  _UICtrlAccessPtr            [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_base_control_set_submenu(S16 **_UICtrlAccessPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
    U8 *control_set_ptr;
    U8 u8CtrlCt = 0;
    U8 u8NoOfUICtrls = 0;
    S16 *UICtrlAccessPtr_p = NULL;
#endif /* !defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
    return dm_setup_and_draw_base_control_set(_UICtrlAccessPtr);
#else /* !defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        return dm_setup_and_draw_base_control_set(_UICtrlAccessPtr);
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        control_set_ptr = (U8*)dm_get_base_control_set_submenu();
        UICtrlAccessPtr_p = (S16*)dm_get_base_coordinate_set_submenu();
        u8NoOfUICtrls = control_set_ptr[0];
        for (u8CtrlCt = 1; u8CtrlCt <= u8NoOfUICtrls; u8CtrlCt++)
        {
            switch (control_set_ptr[u8CtrlCt])
            {
                case DM_TITLE1:
                    {
                        dm_setup_and_draw_title(&UICtrlAccessPtr_p);
                        break;
                    }
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
                case DM_STATUS_BAR1:
                    {
                        dm_setup_and_draw_status_icons(&UICtrlAccessPtr_p);
                        break;
                    }
#endif /* GUI_SUBMENU_SHOW_STATUS_ICON */
                case DM_BUTTON_BAR1:
                    {
                        dm_setup_and_draw_button_bar(&UICtrlAccessPtr_p);
                        break;
                    }
            }
        }

        return 1;
    }
#endif /* !defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_base_control_set_common
 * DESCRIPTION
 *  This function is used setup the base control set submenu based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  _UICtrlAccessPtr            [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_base_control_set_common(S16 **_UICtrlAccessPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
    U8 *control_set_ptr;
    U8 u8CtrlCt = 0;
    U8 u8NoOfUICtrls = 0;
    S16 *UICtrlAccessPtr_p = NULL;
#endif /* !defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(GUI_COMMON_USE_SPECIFIC_STYLE)
    return dm_setup_and_draw_base_control_set(_UICtrlAccessPtr);
#else /* !defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        return dm_setup_and_draw_base_control_set(_UICtrlAccessPtr);
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        control_set_ptr = (U8*)dm_get_base_control_set_common();
        UICtrlAccessPtr_p = (S16*)dm_get_base_coordinate_set_common();
        u8NoOfUICtrls = control_set_ptr[0];
        for (u8CtrlCt = 1; u8CtrlCt <= u8NoOfUICtrls; u8CtrlCt++)
        {
            switch (control_set_ptr[u8CtrlCt])
            {
                case DM_TITLE1:
                    {
                        dm_setup_and_draw_title(&UICtrlAccessPtr_p);
                        break;
                    }
#ifdef GUI_COMMON_SHOW_STATUS_ICON
                case DM_STATUS_BAR1:
                    {
                        dm_setup_and_draw_status_icons(&UICtrlAccessPtr_p);
                        break;
                    }
#endif /* GUI_COMMON_SHOW_STATUS_ICON */
                case DM_BUTTON_BAR1:
                    {
                        dm_setup_and_draw_button_bar(&UICtrlAccessPtr_p);
                        break;
                    }
            }
        }

        return 1;
    }
#endif /* !defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_string
 * DESCRIPTION
 *  This function is used setup the string area set based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_string(S16 **UICtrlAccessPtr_p, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_string_info;
    S32 string_width, string_height;
    dm_string_data_struct *dm_string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        if (index >= dm_string_count_sub)
            return 0;
        dm_string = &dm_string_array_sub[index];
    }
    else
#endif /* __MMI_SUBLCD__ */ 
    {
        if (index >= dm_string_count)
            return 0;
        dm_string = &dm_string_array[index];
    }

    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_string_info);
    DM_RETURN_IF_INVALID_COORD(&dm_string_info);


    gui_measure_string(dm_string->string, &string_width, &string_height);

    if (dm_string->string == NULL || (string_width == 0 && string_height == 0))
    {
        return 0;
    }

    if (dm_string_info.s16Height == DM_CALCULATED_HEIGHT)
    {
        /* 060706 menstral Start */
        if ( dm_string_info.Flags & DM_STRING_BORDERED )
        {
            dm_string_info.s16Height=string_height+2;
        }
        else
        {
            dm_string_info.s16Height=string_height;
        }
        /* 060706 menstral End*/
        if (dm_string_info.Flags & DM_PREVIOUS_CONTROL_END_Y_OFFSET_HEIGHT)
        {
            dm_string_info.s16Y -= dm_string_info.s16Height;
        }
    }
    if (dm_string_info.s16Width == DM_CALCULATED_WIDTH)
    {
        dm_string_info.s16Width = string_width + 1;
        if (dm_string_info.Flags & DM_PREVIOUS_CONTROL_END_X_OFFSET_WIDTH)
        {
            dm_string_info.s16X -= dm_string_info.s16Width;
        }
    }

    gui_push_text_clip();
    gui_push_clip();

    if (!dm_aligned_area_data.is_in_aligned_area)
    {
        gui_set_clip(
            dm_string_info.s16X,
            dm_string_info.s16Y,
            dm_string_info.s16X + dm_string_info.s16Width - 1,
            dm_string_info.s16Y + dm_string_info.s16Height - 1);
        if (dm_string_info.Flags & DM_BACK_FILL)
        {
            gui_draw_filled_area(
                dm_string_info.s16X,
                dm_string_info.s16Y,
                dm_string_info.s16X + dm_string_info.s16Width - 1,
                dm_string_info.s16Y + dm_string_info.s16Height - 1,
                &(dm_string->back_fill));
        }

        gui_set_font(dm_string->font);
        gui_measure_string(dm_string->string, &string_width, &string_height);
        /* Align the string on x asis as per the flag */
        if (string_width < dm_string_info.s16Width)
        {
            if (dm_string_info.Flags & DM_CENTRE_ALIGN_X)
            {
                dm_string_info.s16X += (dm_string_info.s16Width - string_width) >> 1;
            }
            else if (dm_string_info.Flags & DM_RIGHT_ALIGN_X)
            {
                dm_string_info.s16X += (dm_string_info.s16Width - string_width);
            }
        }
        /* Align the string on y asis as per the flag */
        if (string_height < dm_string_info.s16Height)
        {
            if (dm_string_info.Flags & DM_CENTER_ALIGN_Y)
            {
                dm_string_info.s16Y += (dm_string_info.s16Height - string_height) >> 1;
            }
            else if (dm_string_info.Flags & DM_BOTTOM_ALIGN_Y)
            {
                dm_string_info.s16Y += (dm_string_info.s16Height - string_height);
            }
        }

        setup_previous_control(&dm_string_info);

        gui_set_text_clip(
            dm_string_info.s16X,
            dm_string_info.s16Y,
            dm_string_info.s16X + dm_string_info.s16Width - 1,
            dm_string_info.s16Y + dm_string_info.s16Height - 1);
        /* Add the string width to string x in case of right to left MMI. */
        if (mmi_fe_get_r2l_state())
        {
            if(string_width < dm_string_info.s16Width)
            {
                dm_string_info.s16X += (string_width - 1) ;
            }
            else
            {
                dm_string_info.s16X += (dm_string_info.s16Width - 1);

            }
        }
        gui_set_text_color(dm_string->text_color);
        //gui_move_text_cursor(dm_string_info.s16X, dm_string_info.s16Y);
        if (dm_string_info.Flags & DM_STRING_BORDERED)
        {
            gui_move_text_cursor(dm_string_info.s16X, dm_string_info.s16Y+1);
            gui_set_text_border_color(dm_string->border_color);
            /* if(! (g_dm_data.s32flags & DM_NO_STRING) ) */
            /* 072106 dm string Start */
            gui_set_line_height(string_height);

            if (string_width > dm_string_info.s16Width)
            {
                gui_print_truncated_borderd_text(dm_string_info.s16X, dm_string_info.s16Y+1, dm_string_info.s16Width, dm_string->string);
            }
            else
            {
                gui_print_bordered_text(dm_string->string);
            }
            /* 072106 dm string End */
        }
        else
        {
            /* if(! (g_dm_data.s32flags & DM_NO_STRING) ) */
            gui_move_text_cursor(dm_string_info.s16X, dm_string_info.s16Y);
            gui_set_line_height(string_height);

            /* 072106 dm string Start */
            if (string_width > dm_string_info.s16Width)
            {
                gui_print_truncated_text(dm_string_info.s16X, dm_string_info.s16Y, dm_string_info.s16Width, dm_string->string);
            }
            else
            {
                gui_print_text(dm_string->string);
            }
            /* 072106 dm string End */
        }
        gui_pop_text_clip();
        gui_pop_clip();
        return 1;
    }
    else
    {
        gui_set_font(dm_string->font);
        gui_measure_string(dm_string->string, &string_width, &string_height);

        dm_string_info.s16X = dm_aligned_area_data.s16X;
        dm_string_info.s16Y = dm_aligned_area_data.s16Y;
        gui_set_clip(
            dm_aligned_area_data.s16X,
            dm_aligned_area_data.s16Y,
            dm_aligned_area_data.s16X + dm_aligned_area_data.s16width - 1,
            dm_aligned_area_data.s16Y + dm_aligned_area_data.s16height - 1);

        /* We should make sure background filler is not NULL. */
        if ((dm_string_info.Flags & DM_BACK_FILL) && (&(dm_string->back_fill) != NULL))
        {
            gui_draw_filled_area(
                dm_aligned_area_data.s16X,
                dm_aligned_area_data.s16X,
                dm_aligned_area_data.s16X + dm_aligned_area_data.s16width - 1,
                dm_aligned_area_data.s16Y + dm_aligned_area_data.s16height - 1,
                &(dm_string->back_fill));
        }

        /* Align the string on x asis as per the flag */
        if (string_width < dm_aligned_area_data.s16width)
        {
            if (dm_string_info.Flags & DM_CENTRE_ALIGN_X)
            {
                dm_string_info.s16X += (dm_aligned_area_data.s16width - string_width) >> 1;
            }
            else if (dm_string_info.Flags & DM_RIGHT_ALIGN_X)
            {
                dm_string_info.s16X += (dm_aligned_area_data.s16width - string_width);
            }
        }
        /* Align the string on y asis as per the flag */
        if (string_height < dm_string_info.s16Height)
        {
            if (dm_string_info.Flags & DM_CENTER_ALIGN_Y)
            {
                dm_string_info.s16Y += (dm_string_info.s16Height - string_height) >> 1;
            }
            else if (dm_string_info.Flags & DM_BOTTOM_ALIGN_Y)
            {
                dm_string_info.s16Y += (dm_string_info.s16Height - string_height);
            }
        }
        dm_string_info.s16Y += dm_aligned_area_data.y_space;    /* 101805 pin Calvin */
        gui_set_text_clip(
            dm_string_info.s16X,
            dm_string_info.s16Y,
            dm_string_info.s16X + dm_string_info.s16Width - 1,
            dm_string_info.s16Y + dm_string_info.s16Height - 1);
        /* Add the string width to string x in case of right to left MMI. */
        if (mmi_fe_get_r2l_state())
        {
            dm_string_info.s16X += string_width + 1;
        }
        gui_set_text_color(dm_string->text_color);
        /* dm_string_info.s16Y+=dm_aligned_area_data.y_space; */
        dm_aligned_area_data.s16Y = dm_string_info.s16Y;
        gui_move_text_cursor(dm_string_info.s16X, dm_string_info.s16Y);
        gui_set_line_height(string_height);
        if (dm_string_info.Flags & DM_STRING_BORDERED)
        {
            gui_set_text_border_color(dm_string->border_color);
            /* if(! (g_dm_data.s32flags & DM_NO_STRING) ) */
            /* 072106 dm string Start */
            if (string_width > dm_string_info.s16Width)
            {
                gui_print_truncated_borderd_text(dm_string_info.s16X, dm_string_info.s16Y, dm_string_info.s16Width, dm_string->string);
            }
            else
            {
                gui_print_bordered_text(dm_string->string);
            }
            /* 072106 dm string End */
        }
        else
        {
            /* if(! (g_dm_data.s32flags & DM_NO_STRING) ) */
            /* 072106 dm string Start */
            if (string_width > dm_string_info.s16Width)
            {
                gui_print_truncated_text(dm_string_info.s16X, dm_string_info.s16Y, dm_string_info.s16Width, dm_string->string);
            }
            else
            {
                gui_print_text(dm_string->string);
            }
            /* 072106 dm string End */
        }
        gui_pop_text_clip();
        gui_pop_clip();
        dm_aligned_area_data.s16Y += string_height;
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_image
 * DESCRIPTION
 *  This function is used setup the image area set based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_image(S16 **UICtrlAccessPtr_p, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_image_info;
    S32 image_width, image_height;
    dm_image_data_struct *dm_image;
    PU8 active_layer_buffer, image_buffer;
    S32 layer_width, layer_height, mini_width, mini_height, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        dm_image = &dm_image_array_sub[index];
    }
    else
#endif /* __MMI_SUBLCD__ */ 
        dm_image = &dm_image_array[index];

    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_image_info);
    DM_RETURN_IF_INVALID_COORD(&dm_image_info);

#ifdef __MMI_FTE_SUPPORT__
    if(dm_image->dyn_prop_flag & DM_IMAGE_WITHOUT_HEADER)
    {
        gdi_image_get_dimension_mem(dm_image->image_type, dm_image->image, dm_image->image_size, &image_width, &image_height);
    }
    else if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
    {
        gui_measure_image(dm_image->image, &image_width, &image_height);
    }
#else
    if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
    {
        gui_measure_image(dm_image->image, &image_width, &image_height);
    }
#endif
    else
    {
        /* RAW IMAGE DATA processing */
        image_width = dm_image->width;
        image_height = dm_image->height;
    }

    if ((dm_image->image == NULL && dm_image->name == NULL) || (image_width == 0 && image_height == 0))
    {
        return 0;
    }

    if (dm_image_info.s16Height == DM_CALCULATED_HEIGHT)
    {
        dm_image_info.s16Height = image_height;
        if (dm_image_info.Flags & DM_PREVIOUS_CONTROL_END_Y_OFFSET_HEIGHT)
        {
            dm_image_info.s16Y -= dm_image_info.s16Height;
        }
    }
    if (dm_image_info.s16Width == DM_CALCULATED_WIDTH)
    {
        dm_image_info.s16Width = image_width;
        if (dm_image_info.Flags & DM_PREVIOUS_CONTROL_END_X_OFFSET_WIDTH)
        {
            dm_image_info.s16X -= dm_image_info.s16Width;
        }
    }

    if (!dm_aligned_area_data.is_in_aligned_area)
    {

        gui_push_clip();
        gui_set_clip(
            dm_image_info.s16X,
            dm_image_info.s16Y,
            dm_image_info.s16X + dm_image_info.s16Width - 1,
            dm_image_info.s16Y + dm_image_info.s16Height - 1);

        gdi_anim_set_blt_before_callback(dm_image->blt_before_callback_ptr);

#if defined(DM_NEW_POPUPBG_METHOD)
        if (dm_check_control_exist(g_dm_data.s32CatId, DM_POPUP_BACKGROUND))
        {
            U16 img_type = GDI_IMAGE_TYPE_INVALID;

            if (dm_image->name != NULL) 
            {
                img_type = gdi_image_get_type_from_file((S8*)dm_image->name);
            }
            else
            {
                if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
                {
                    img_type = gdi_image_get_buf_type(dm_image->image);
                }
#ifdef __MMI_FTE_SUPPORT__
                else if(dm_image->dyn_prop_flag & DM_IMAGE_WITHOUT_HEADER)
                {
                    img_type = dm_image->image_type;
                }
#endif
            }
            if ((img_type != GDI_IMAGE_TYPE_GIF) && (img_type != GDI_IMAGE_TYPE_GIF_FILE) && (img_type != GDI_IMAGE_TYPE_AB2) && (img_type != GDI_IMAGE_TYPE_AB2_FILE))
            {
                dm_popupbg_set_clip(&dm_image_info);
                gdi_anim_set_draw_before_callback(dm_popupbg_anim_draw_before_callback);
            }
        }
#endif /* defined(DM_NEW_POPUPBG_METHOD) */

        /* We should make sure background filler is not NULL */
        if ((dm_image_info.Flags & DM_BACK_FILL) && (&dm_image->back_fill != NULL))
        {
            gui_draw_filled_area(
                dm_image_info.s16X,
                dm_image_info.s16Y,
                dm_image_info.s16X + dm_image_info.s16Width - 1,
                dm_image_info.s16Y + dm_image_info.s16Height - 1,
                dm_image->back_fill);
        }

        if (dm_image->name != NULL) /* from file */
        {
            gdi_image_get_dimension_file((S8*) dm_image->name, &image_width, &image_height);
        }
        else    /* from resource */
        {
#ifdef __MMI_FTE_SUPPORT__
            if(dm_image->dyn_prop_flag & DM_IMAGE_WITHOUT_HEADER)
            {
                gdi_image_get_dimension_mem(dm_image->image_type, dm_image->image, dm_image->image_size, &image_width, &image_height);
            }
            else if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#else
            if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#endif
            {
                gdi_image_get_dimension(dm_image->image, &image_width, &image_height);
            }
            else
            {
                /* RAW IMAGE DATA processing */
                image_width = dm_image->width;
                image_height = dm_image->height;
            }
        }

        if ((dm_image_info.Flags & DM_RESIZE_IMAGE) && ((image_width > dm_image_info.s16Width) || (image_height > dm_image_info.s16Height)))
        {
            /* Draw file and need resize image */
            S32 resized_offset_x;
            S32 resized_offset_y;
            S32 resized_width;
            S32 resized_height;

            /* clear gdi working buffer */
            gdi_image_clear_work_buffer();
            
            gdi_image_util_fit_bbox(
                dm_image_info.s16Width,
                dm_image_info.s16Height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);  

            dm_image_info.s16X += resized_offset_x;
            dm_image_info.s16Y += resized_offset_y;
            dm_image_info.s16Width = resized_width;
            dm_image_info.s16Height = resized_height;
            
            setup_previous_control(&dm_image_info);

            if (dm_image->image_handle != GDI_ERROR_HANDLE)
            {
                gdi_image_stop_animation(dm_image->image_handle);
            }

            if (dm_image->name != NULL) /* from file */
            {
                gdi_image_draw_animation_resized_file(
                    dm_image_info.s16X,
                    dm_image_info.s16Y,
                    resized_width,
                    resized_height,
                    (PS8) dm_image->name,
                    &(dm_image->image_handle));
            }
            else if (dm_image->image != NULL)   /* from resource */
            {
#ifdef __MMI_FTE_SUPPORT__
                if(dm_image->dyn_prop_flag & DM_IMAGE_WITHOUT_HEADER)
                {
                    gdi_image_draw_resized_mem_blend2layers(
                        dm_image_info.s16X,
                        dm_image_info.s16Y,
                        resized_width,
                        resized_height,
                        dm_image->image,
                        dm_image->image_type,
                        dm_image->image_size);
                }
                else if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#else
                if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#endif
                {
                    gdi_image_draw_animation_resized(
                        dm_image_info.s16X,
                        dm_image_info.s16Y,
                        resized_width,
                        resized_height,
                        dm_image->image,
                        &(dm_image->image_handle));
                }
            }

            dm_image->x = dm_image_info.s16X;
            dm_image->y = dm_image_info.s16Y;
            dm_image->width = resized_width;
            dm_image->height = resized_height;

            gdi_anim_set_blt_before_callback(dummy_anim_before_blt_callback);

            gui_pop_clip();
            return 1;
        }

        /* Align the image on x asis as per the flag */
        /* 062106 cat129 Start */
        if (dm_image_info.Flags & DM_CENTRE_ALIGN_X || dm_image_info.Flags & DM_RIGHT_ALIGN_X)
        {
            if (image_width < dm_image_info.s16Width)
            {
                if (dm_image_info.Flags & DM_CENTRE_ALIGN_X)
                {
                    dm_image_info.s16X += (dm_image_info.s16Width - image_width) >> 1;
                }
                else if (dm_image_info.Flags & DM_RIGHT_ALIGN_X)
                {
                    dm_image_info.s16X += (dm_image_info.s16Width - image_width);
                }
            }
        }
        else if (dm_image_info.Flags & DM_FORCE_CENTRE_ALIGN_X)
        {
            dm_image_info.s16X+=(dm_image_info.s16Width-image_width)>>1;
        }

        /* Align the image on y asis as per the flag */
        if (dm_image_info.Flags & DM_CENTER_ALIGN_Y || dm_image_info.Flags & DM_BOTTOM_ALIGN_Y)
        {
            if (image_height < dm_image_info.s16Height)
            {
                if (dm_image_info.Flags & DM_CENTER_ALIGN_Y)
                {
                    dm_image_info.s16Y += (dm_image_info.s16Height - image_height) >> 1;
                }
                else if (dm_image_info.Flags & DM_BOTTOM_ALIGN_Y)
                {
                    dm_image_info.s16Y += (dm_image_info.s16Height - image_height);
                }
            }
        }
        else if (dm_image_info.Flags & DM_FORCE_CENTER_ALIGN_Y)
        {
            dm_image_info.s16Y+=(dm_image_info.s16Height-image_height)>>1;
        }
        /* 062106 cat129 Start */

        setup_previous_control(&dm_image_info);

        if (dm_image->image_handle != GDI_ERROR_HANDLE)
        {
            gdi_image_stop_animation(dm_image->image_handle);
        }

        if (dm_image->name != NULL) /* from file */
        {
            gdi_image_draw_animation_file(
                dm_image_info.s16X,
                dm_image_info.s16Y,
                (S8*) dm_image->name,
                &(dm_image->image_handle));
        }
        else if (dm_image->image != NULL)   /* from resource */
        {
#ifdef __MMI_FTE_SUPPORT__
            if(dm_image->dyn_prop_flag & DM_IMAGE_WITHOUT_HEADER)
            {
                gdi_image_draw_mem_blend2layers(
                    dm_image_info.s16X,
                    dm_image_info.s16Y,
                    dm_image->image,
                    dm_image->image_type,
                    dm_image->image_size);
            }
            else if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#else
            if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#endif
            {
                gdi_image_draw_animation(
                    dm_image_info.s16X,
                    dm_image_info.s16Y,
                    dm_image->image,
                    &(dm_image->image_handle));
            }
            else
            {
                /* RAW IMAGE DATA processing */
                gdi_layer_get_buffer_ptr(&active_layer_buffer);
                gdi_layer_get_dimension(&layer_width, &layer_height);
                image_buffer = dm_image->image;
                
                mini_width = (image_width + dm_image_info.s16X) > layer_width? (layer_width - dm_image_info.s16X) : image_width;
                mini_height = (image_height + dm_image_info.s16Y) > layer_height? (layer_height - dm_image_info.s16Y) : image_height;

                active_layer_buffer +=  dm_image_info.s16X * 2;

                for(i = 0; i < mini_height; i++)
                {
                    memcpy(active_layer_buffer, image_buffer, mini_width * 2);
                    image_buffer += image_width * 2;
                    active_layer_buffer += layer_width * 2;
                }
                
            }
        }

        dm_image->x = dm_image_info.s16X;
        dm_image->y = dm_image_info.s16Y;
        dm_image->width = image_width;
        dm_image->height = image_height;

        gdi_anim_set_blt_before_callback(dummy_anim_before_blt_callback);

        gui_pop_clip();
        return 1;
    }
    else
    {
        S32 image_width = 0, image_height = 0;
        S32 x = 0, y = 0;
#if defined(DM_NEW_POPUPBG_METHOD)
        MMI_BOOL is_redraw_popup_bg = MMI_FALSE;
#endif
        gui_push_clip();
        gui_set_clip(
            dm_aligned_area_data.s16X,
            dm_aligned_area_data.s16Y,
            dm_aligned_area_data.s16X + dm_aligned_area_data.s16width - 1,
            dm_aligned_area_data.s16Y + dm_aligned_area_data.s16height - 1);

        gdi_anim_set_blt_before_callback(dm_image->blt_before_callback_ptr);

#if defined(DM_NEW_POPUPBG_METHOD)
        if (dm_check_control_exist(g_dm_data.s32CatId, DM_POPUP_BACKGROUND))
        {
            U16 img_type = GDI_IMAGE_TYPE_INVALID;

            if (dm_image->name != NULL) 
            {
                img_type = gdi_image_get_type_from_file((S8*)dm_image->name);
            }
            else
            {
                if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
                {
                    img_type = gdi_image_get_buf_type(dm_image->image);
                }
#ifdef __MMI_FTE_SUPPORT__
                else if(dm_image->dyn_prop_flag & DM_IMAGE_WITHOUT_HEADER)
                {
                    img_type = dm_image->image_type;
                }
#endif
            }
            if ((img_type != GDI_IMAGE_TYPE_GIF) && (img_type != GDI_IMAGE_TYPE_GIF_FILE)  && (img_type != GDI_IMAGE_TYPE_AB2) && (img_type != GDI_IMAGE_TYPE_AB2_FILE))
            {
                is_redraw_popup_bg = MMI_TRUE;
                dm_popupbg_set_clip((dm_coordinates*)&dm_aligned_area_data);
                gdi_anim_set_draw_before_callback(dm_popupbg_anim_draw_before_callback);
            }
        }
#endif /* defined(DM_NEW_POPUPBG_METHOD) */

        dm_aligned_area_data.s16Y += dm_aligned_area_data.y_space;

        if (dm_image->name != NULL) /* from file */
        {
            gdi_image_get_dimension_file((S8*) dm_image->name, &image_width, &image_height);
            if (dm_aligned_area_data.s16width > image_width)
            {
                x = dm_aligned_area_data.s16X + ((dm_aligned_area_data.s16width - image_width) >> 1);
                y = dm_aligned_area_data.s16Y;
                gdi_image_draw_animation_file(x, y, (S8*) dm_image->name, &(dm_image->image_handle));
            }
            else
            {
                x = dm_aligned_area_data.s16X + ((dm_aligned_area_data.s16width - image_width) >> 1);
                y = dm_aligned_area_data.s16Y;
                gdi_image_draw_animation_file(x, y, (S8*) dm_image->name, &(dm_image->image_handle));
            }
        }
        else if (dm_image->image != NULL)   /* from resource */
        {
#ifdef __MMI_FTE_SUPPORT__
            if(dm_image->dyn_prop_flag & DM_IMAGE_WITHOUT_HEADER)
            {
                gdi_image_get_dimension_mem(dm_image->image_type, dm_image->image, dm_image->image_size, &image_width, &image_height);
            }
            else if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#else
            if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#endif
            {
                gdi_image_get_dimension(dm_image->image, &image_width, &image_height);
            }
            else
            {
                /* RAW IMAGE DATA processing */
                image_width = dm_image->width;
                image_height = dm_image->height;
            }
            
            if (dm_aligned_area_data.s16width > image_width)
            {
                x = dm_aligned_area_data.s16X + ((dm_aligned_area_data.s16width - image_width) >> 1);
                y = dm_aligned_area_data.s16Y;
            }
            else
            {
                x = dm_aligned_area_data.s16X + ((dm_aligned_area_data.s16width - image_width) >> 1);
                y = dm_aligned_area_data.s16Y;
            }
            if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
            {
                gdi_image_draw_animation(x, y, (U8*) dm_image->image, &(dm_image->image_handle));
            }
#ifdef __MMI_FTE_SUPPORT__
            else if(dm_image->dyn_prop_flag & DM_IMAGE_WITHOUT_HEADER)
            {
                gdi_image_draw_mem_blend2layers(x, y, (U8*) dm_image->image, dm_image->image_type, dm_image->image_size);
            }
#endif
            else
            {
                /* RAW IMAGE DATA processing */
                gdi_layer_get_buffer_ptr(&active_layer_buffer);
                gdi_layer_get_dimension(&layer_width, &layer_height);
                image_buffer = dm_image->image;
                
                mini_width = (image_width + x) > layer_width? (layer_width - x) : image_width;
                mini_height = (image_height + y) > layer_height? (layer_height - y) : image_height;

                active_layer_buffer +=  x * 2;

                for(i = 0; i < mini_height; i++)
                {
                    memcpy(active_layer_buffer, image_buffer, mini_width * 2);
                    image_buffer += image_width * 2;
                    active_layer_buffer += layer_width * 2;
                }
            }
        }
        dm_image->x = x;
        dm_image->y = y;
        dm_image->width = image_width;
        dm_image->height = image_height;

        // TODO: revise redundent codes
#if defined(DM_NEW_POPUPBG_METHOD)
        if (is_redraw_popup_bg)
        {
            dm_coordinates popup_clip = {0};

            popup_clip.s16X = (S16)x;
            popup_clip.s16Y = (S16)y;
            popup_clip.s16Width = (S16)(image_width);
            popup_clip.s16Height = (S16)(image_height);
            dm_popupbg_set_clip((dm_coordinates*)&popup_clip);
        }
#endif /* defined(DM_NEW_POPUPBG_METHOD) */

        dm_aligned_area_data.s16Y += (S16) image_height;

        gdi_anim_set_blt_before_callback(dummy_anim_before_blt_callback);

        gui_pop_clip();
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_button
 * DESCRIPTION
 *  This function is used setup the icon button based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            Index of icon button array
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_button(S16 **UICtrlAccessPtr_p, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates button_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &button_info);
    DM_RETURN_IF_INVALID_COORD(&button_info);

    if (dm_get_button_count() == 0)
    {
        return 0;
    }

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        button_info.s16X,
        button_info.s16Y,
        button_info.s16X + button_info.s16Width - 1,
        button_info.s16Y + button_info.s16Height - 1);

    if (dm_button_array[index].x == -1 || dm_button_array[index].y == -1)
    {
        gui_move_icontext_button(&dm_button_array[index], button_info.s16X, button_info.s16Y);
    }

    if (dm_button_array[index].width == -1 || dm_button_array[index].height == -1)
    {
        gui_resize_icontext_button(&dm_button_array[index], button_info.s16Width, button_info.s16Height);
    }
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_overwirte_pen_response_area(
        &dm_button_array[index], 
        button_info.s16X, 
        button_info.s16Y, 
        button_info.s16X + button_info.s16Width -1,
        button_info.s16Y + button_info.s16Height -1);
#endif /* __MMI_TOUCH_SCREEN__ */
    gui_show_icontext_button(&dm_button_array[index]);

    gdi_layer_pop_clip();

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_back_fill_area
 * DESCRIPTION
 *  This function is used setup the back fill area set based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_back_fill_area(S16 **UICtrlAccessPtr_p, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_back_fill_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_back_fill_info);
    DM_RETURN_IF_INVALID_COORD(&dm_back_fill_info);

    gui_push_clip();
    gui_set_clip(
        dm_back_fill_info.s16X,
        dm_back_fill_info.s16Y,
        dm_back_fill_info.s16X + dm_back_fill_info.s16Width - 1,
        dm_back_fill_info.s16Y + dm_back_fill_info.s16Height - 1);

    gui_draw_filled_area(
        dm_back_fill_info.s16X,
        dm_back_fill_info.s16Y,
        dm_back_fill_info.s16X + dm_back_fill_info.s16Width - 1,
        dm_back_fill_info.s16Y + dm_back_fill_info.s16Height - 1,
        dm_back_fill_array[index]);

    gui_pop_clip();

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_rectangle
 * DESCRIPTION
 *  This function is used setup the rectangle based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_rectangle(S16 **UICtrlAccessPtr_p, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_rectangle_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_rectangle_info);
    DM_RETURN_IF_INVALID_COORD(&dm_rectangle_info);

    gui_push_clip();
    gui_set_clip(
        dm_rectangle_info.s16X,
        dm_rectangle_info.s16Y,
        dm_rectangle_info.s16X + dm_rectangle_info.s16Width - 1,
        dm_rectangle_info.s16Y + dm_rectangle_info.s16Height - 1);
    /* START VIJAY PMT 20050930 */
    if (dm_rectangle_array[index].fill_rectangle == DM_RECTANGLE_FILL_GRAYSCALE)
    {
        gui_greyscale_rectangle(
            dm_rectangle_info.s16X,
            dm_rectangle_info.s16Y,
            dm_rectangle_info.s16X + dm_rectangle_info.s16Width - 1,
            dm_rectangle_info.s16Y + dm_rectangle_info.s16Height - 1,
            MMI_BG_GREYSCALE_VALUE,
            MMI_BG_GREYSCALE_BLACK_VALUE);
    }
    else if (dm_rectangle_array[index].fill_rectangle == DM_RECTANGLE_FILL_COLOR)
        /* END VIJAY PMT 20050930 */
    {
        gui_fill_rectangle(
            dm_rectangle_info.s16X,
            dm_rectangle_info.s16Y,
            dm_rectangle_info.s16X + dm_rectangle_info.s16Width - 1,
            dm_rectangle_info.s16Y + dm_rectangle_info.s16Height - 1,
            dm_rectangle_array[index].line_color);
    }
    else
    {
        gui_draw_rectangle(
            dm_rectangle_info.s16X,
            dm_rectangle_info.s16Y,
            dm_rectangle_info.s16X + dm_rectangle_info.s16Width - 1,
            dm_rectangle_info.s16Y + dm_rectangle_info.s16Height - 1,
            dm_rectangle_array[index].line_color);
    }

    gui_pop_clip();

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_line
 * DESCRIPTION
 *  This function is used setup the line based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_line(S16 **UICtrlAccessPtr_p, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_line_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_line_info);
    DM_RETURN_IF_INVALID_COORD(&dm_line_info);

    gui_push_clip();
    gui_set_clip(
        dm_line_info.s16X,
        dm_line_info.s16Y,
        dm_line_info.s16X + dm_line_info.s16Width - 1,
        dm_line_info.s16Y + dm_line_info.s16Height - 1);

    gui_line(
        dm_line_info.s16X,
        dm_line_info.s16Y,
        dm_line_info.s16X + dm_line_info.s16Width - 1,
        dm_line_info.s16Y + dm_line_info.s16Height - 1,
        dm_line_array[index]);

    gui_pop_clip();
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_popupbg_set_clip
 * DESCRIPTION
 *  This function is used to set the clip region of the pop-up background
 * PARAMETERS
 *  clip_region     [IN] clip region
 * RETURNS
 *  void
 *****************************************************************************/
void dm_popupbg_set_clip(dm_coordinates *clip_region)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&dm_popupbg_clip_coordinate, clip_region, sizeof(dm_coordinates));
}


/*****************************************************************************
 * FUNCTION
 *  dm_redraw_popup_background
 * DESCRIPTION
 *  This function is used to draw the pop-up background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_redraw_popup_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 current_popup_bg = NULL;
#if (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__))
    UI_filled_area current_popup_filler;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    gdi_set_alpha_blending_source_layer(dm_popupbg_layer);
    gdi_layer_push_and_set_active(dm_popupfg_layer);
#endif
    /* If do not use bg image, then save current image and set image to NULL */
    if (dm_popupbg_coordinate.Flags & DM_POPUP_BACKGROUND_NOT_USE_IMAGE)
    {
        current_popup_bg = wgui_pop_up_dialog_background.b;
        wgui_pop_up_dialog_background.b = NULL;
    }
#if (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__))
    else if(dm_popupbg_coordinate.s16Height == MMI_POP_UP_DIALOG_FULL_HEIGHT)
    {
        current_popup_filler = wgui_pop_up_dialog_background;
        if(current_MMI_theme->popup_full_height_screen_bg_filler != NULL)
            wgui_pop_up_dialog_background = *current_MMI_theme->popup_full_height_screen_bg_filler;
    }
#endif

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        dm_popupbg_clip_coordinate.s16X,
        dm_popupbg_clip_coordinate.s16Y,
        dm_popupbg_clip_coordinate.s16X + dm_popupbg_clip_coordinate.s16Width - 1,
        dm_popupbg_clip_coordinate.s16Y + dm_popupbg_clip_coordinate.s16Height - 1);

    wgui_draw_pop_up_screen_background(
        dm_popupbg_coordinate.s16X,
        dm_popupbg_coordinate.s16Y,
        dm_popupbg_coordinate.s16X + dm_popupbg_coordinate.s16Width - 1,
        dm_popupbg_coordinate.s16Y + dm_popupbg_coordinate.s16Height - 1,
        &wgui_pop_up_dialog_background);//huking

    gdi_layer_pop_clip();
    
    /* Reset popup background image. */
    if (dm_popupbg_coordinate.Flags & DM_POPUP_BACKGROUND_NOT_USE_IMAGE)
    {
        wgui_pop_up_dialog_background.b = current_popup_bg;
    }
#if (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__))
    else if(dm_popupbg_coordinate.s16Height == MMI_POP_UP_DIALOG_FULL_HEIGHT)
    {
        wgui_pop_up_dialog_background = current_popup_filler;

    }
#endif
    
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    gdi_set_alpha_blending_source_layer(dm_popupfg_layer);    /* for following drawing image usage */
    gdi_layer_pop_and_restore_active();
#endif
}


#if defined(DM_NEW_POPUPBG_METHOD)
/*****************************************************************************
 * FUNCTION
 *  dm_redraw_popup_background
 * DESCRIPTION
 *  This function is used to draw the pop-up background
 * PARAMETERS
 *  return_code [IN]    unused
 * RETURNS
 *  void
 *****************************************************************************/
static void dm_popupbg_anim_draw_before_callback(GDI_RESULT return_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_redraw_popup_background();
}


/*****************************************************************************
 * FUNCTION
 *  dm_redraw_popup_foreground
 * DESCRIPTION
 *  This function is used to draw the pop-up foreground,
 *  including, pop-up bk image, image, multiline, scrolling text, etc.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_redraw_popup_foreground(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates popup_clip = {0};
    S16 *DeafultCoordinateSet_p = NULL;
    U8 *control_set_ptr;
    S32 u8CtrlCt = 0, u8NoOfUICtrls = 0, i = 0;
    PU8 active_layer_buffer, image_buffer;
    S32 layer_width, layer_height, mini_width, mini_height, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!dm_check_control_exist(g_dm_data.s32CatId, DM_POPUP_BACKGROUND))
    {
        return;
    }

    /* redraw pop-up background image */
    popup_clip.s16X = 0;
    popup_clip.s16Y = 0;
    popup_clip.s16Width = UI_device_width;
    popup_clip.s16Height = UI_device_height;    
    dm_popupbg_set_clip(&popup_clip);
    dm_redraw_popup_background();

    /* redraw foreground objects */
    control_set_ptr = dm_search_control_set(g_dm_data.s32CatId, &DeafultCoordinateSet_p);
    u8NoOfUICtrls = control_set_ptr[0];
    for (u8CtrlCt=1 ; u8CtrlCt<=u8NoOfUICtrls ; u8CtrlCt++)
    {
        switch (control_set_ptr[u8CtrlCt])
        {
            case DM_IMAGE:
                {
                    dm_image_data_struct *dm_image;
                    dm_coordinates image_clip;

                    for (i = 0; i < dm_image_count; i++)
                    {
                        dm_image = &dm_image_array[i];

                        image_clip.s16X = dm_image->x;
                        image_clip.s16Y = dm_image->y;
                        image_clip.s16Width = dm_image->width;
                        image_clip.s16Height = dm_image->height;
                        dm_popupbg_set_clip(&image_clip);

                        if (dm_image->image_handle != GDI_ERROR_HANDLE)
                        {                                 
                            S32 current_frame_index, i;

                            current_frame_index = gdi_anim_get_current_frame_number(dm_image->image_handle);
                            gdi_image_stop_animation(dm_image->image_handle);                           

                            for (i = 0; i < current_frame_index; i++)
                            {
                                gdi_anim_draw_resized_frames(dm_image->x, dm_image->y, dm_image->width, dm_image->height, dm_image->image, &(dm_image->image_handle), i);
                                gdi_image_stop_animation(dm_image->image_handle);
                            }

                            gdi_anim_draw_resized_frames(dm_image->x, dm_image->y, dm_image->width, dm_image->height, dm_image->image, &(dm_image->image_handle), current_frame_index);
                            
                            continue;
                        }

                        if (dm_image->name != NULL)
                        {
                            gdi_image_draw_animation_resized_file(
                                dm_image->x, dm_image->y, dm_image->width, dm_image->height,
                                (PS8)dm_image->name, &(dm_image->image_handle));
                        }
                        else
                        {
#ifdef __MMI_FTE_SUPPORT__
                            if(dm_image->dyn_prop_flag & DM_IMAGE_WITHOUT_HEADER)
                            {
                                gdi_image_draw_resized_mem_blend2layers(
                                    dm_image->x, 
                                    dm_image->y,
                                    dm_image->width, 
                                    dm_image->height,
                                    dm_image->image,
                                    dm_image->image_type,
                                    dm_image->image_size);
                            }
                            else if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#else
                            if(dm_image->dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#endif
                            {
                                gdi_image_draw_animation_resized(
                                    dm_image->x, dm_image->y, dm_image->width, dm_image->height,
                                    dm_image->image, &(dm_image->image_handle));
                            }
                            else
                            {
                                /* RAW IMAGE DATA processing */
                                gdi_layer_get_buffer_ptr(&active_layer_buffer);
                                gdi_layer_get_dimension(&layer_width, &layer_height);
                                image_buffer = dm_image->image;
                
                                mini_width = (dm_image->width + dm_image->x) > layer_width? (layer_width - dm_image->x) : dm_image->width;
                                mini_height = (dm_image->height + dm_image->y) > layer_height? (layer_height - dm_image->y) : dm_image->height;

                                active_layer_buffer +=  dm_image->x * 2;

                                for(j = 0; j < mini_height; j++)
                                {   
                                    memcpy(active_layer_buffer, image_buffer, mini_width * 2);
                                    image_buffer += dm_image->width * 2;
                                    active_layer_buffer += layer_width * 2;
                                } 
                            }
                        }
                    }
                }
                break;

            case DM_MULTILINE_INPUTBOX1:
                show_multiline_inputbox();
                break;

#if 1//def __MMI_EDITOR_SINGLINE_SUPPORT__
            case DM_SINGLELINE_INPUTBOX1:
                show_singleline_inputbox();
                break;
#endif
            case DM_SCROLL_TEXT:
                gui_scrolling_text_stop(dm_current_scroll_text);
                gui_show_scrolling_text(dm_current_scroll_text);
                break;

            case DM_CATEGORY_CONTROLLED_AREA:
                {
                    dm_coordinates coordinate;

                    dm_get_control_coordinates_from_category(
                        g_dm_data.s32ScrId, g_dm_data.s32CatId, DM_CATEGORY_CONTROLLED_AREA, -1, &coordinate);
                    if (dm_category_controlled_area_callback)
                    {
                        (*dm_category_controlled_area_callback) (&coordinate);
                    }
                }
                break;

            case DM_BUTTON_BAR1:
            {
                dm_coordinates coordinate;

                dm_get_control_coordinates_from_category(g_dm_data.s32ScrId, g_dm_data.s32CatId, DM_BUTTON_BAR1, -1, &coordinate);

                if (!(coordinate.Flags & DM_BUTTON_DISABLE_BACKGROUND))
                {
                    show_softkey_background();
                    draw_arrow_indication(
                        (S8)(coordinate.Flags & DM_BUTTON_BAR_LEFT_ARROW),
                        (S8)(coordinate.Flags & DM_BUTTON_BAR_RIGHT_ARROW),
                        (S8)(coordinate.Flags & DM_BUTTON_BAR_UP_ARROW),
                        (S8)(coordinate.Flags & DM_BUTTON_BAR_DOWN_ARROW));
                }
    
                show_softkey(MMI_LEFT_SOFTKEY);
                show_softkey(MMI_RIGHT_SOFTKEY);
                show_softkey(MMI_CENTER_SOFTKEY);
            }
                break;

            default:
                break;
        }
    }
}
#endif /* defined(DM_NEW_POPUPBG_METHOD) */


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_popup_background
 * DESCRIPTION
 *  This function is used setup the popup background based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_popup_background(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_popup_background_info;
    GDI_HANDLE act_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_popup_background_info);
#ifdef __MMI_FTE_SUPPORT__
    if(dm_popup_background_info.Flags & DM_POPUP_BACKGROUND_FOR_FTE)
    {
        S32 h;
        U8 *control_set_ptr = NULL;
        S16 *DeafultCoordinateSet_p = NULL;
        S32 total_element_height = 0;
        S32 is_multiline = 0;
        U8 number_of_items = 0;
        dm_coordinates temp_dm_popup_background_info;

        temp_dm_popup_background_info = dm_popup_background_info;
        temp_dm_popup_background_info.s16Width = WGUI_POPUP_FTE_AREA_WIDTH; /* compute right text height */
        control_set_ptr = dm_search_control_set((U16) g_dm_data.s32CatId, &DeafultCoordinateSet_p);
        dm_get_aligned_area_element_height(control_set_ptr, temp_dm_popup_background_info, &total_element_height, &is_multiline, &number_of_items);
 
        if (total_element_height > MMI_POP_UP_DIALOG_FULL_HEIGHT)
        {
            total_element_height = MMI_POP_UP_DIALOG_FULL_HEIGHT;
        }
        h = total_element_height + WGUI_POPUP_FTE_AREA_TOP_SPACE + 2*WGUI_POPUP_FTE_AREA_SPACE + WGUI_POPUP_FTE_AREA_BOTTOM_SPACE;
        if( h < WGUI_POPUP_FTE_AREA_MIN_HEIGHT)
        {
            h = WGUI_POPUP_FTE_AREA_MIN_HEIGHT;
        }
        dm_popup_background_info.s16X = 0;
        dm_popup_background_info.s16Y = MAIN_LCD_DEVICE_HEIGHT - h - MMI_BUTTON_BAR_HEIGHT;
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
        if(MMI_TRUE == wgui_icon_bar_is_created())
        {
            dm_popup_background_info.s16Y -= MMI_ICON_BAR_HEIGHT;
        }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /*__MMI_ICON_BAR_SUPPORT__*/
        dm_popup_background_info.s16Width = MAIN_LCD_DEVICE_WIDTH;
        dm_popup_background_info.s16Height = h;
    }
#endif
    memcpy(&dm_popupbg_coordinate, &dm_popup_background_info, sizeof(dm_coordinates));
    dm_popupbg_set_clip(&dm_popup_background_info);

    if (dm_popup_background_info.s16X == -1 || dm_popup_background_info.s16Y == -1 ||
        dm_popup_background_info.s16Width == -1 || dm_popup_background_info.s16Height == -1)
    {
        return 0;
    }

    if (g_dm_data.s32flags & DM_NO_POPUP_BACKGROUND)
    {
        return 0;
    }

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    /* set foreground & background layer */
#if defined(DM_NEW_POPUPBG_METHOD)
    gdi_layer_get_active(&act_layer);
    if (dm_check_control_exist(g_dm_data.s32CatId, DM_SCR_BG) &&
        g_dm_scr_bg_cntx.layer_handle != GDI_ERROR_HANDLE)
    {
        /* Popup background with full screen background */
        dm_popupbg_layer = g_dm_scr_bg_cntx.layer_handle;
        old_bg_filler = NULL;
    }
    else if (dm_check_control_exist(g_dm_data.s32CatId, DM_NEW_LAYER_START))
    {
        /* set default ABM source layer to the main base layer */
        gdi_layer_get_base_handle(&dm_popupbg_layer);
    }
    else
    {
        dm_popupbg_layer = act_layer;
    }
    dm_popupfg_layer = act_layer;

    /* set alpha blending source layer for components */
    wgui_status_icon_bar_set_alpha_blend_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        dm_popupbg_layer);
    wgui_title_set_alpha_layer(dm_popupbg_layer);
#if defined(__MMI_MAINLCD_320X480__)
#if defined(__MMI_SCREEN_ROTATE__)
    if (mmi_frm_is_screen_width_height_swapped())
    {
        wgui_softkey_set_abm_layer(dm_popupbg_layer);
    }
    else
#endif /* defined(__MMI_SCREEN_ROTATE__) */
    {
        /* cat223 has pop-up background, but softkey did not draw on pop-up backgorund image */
        if (g_dm_data.s32CatId == MMI_CATEGORY223_ID)
        {
            wgui_softkey_set_abm_layer(dm_popupbg_layer);
        }
        else
        {
            wgui_softkey_set_abm_layer(dm_popupfg_layer);
        }
    }
#else /* defined(__MMI_MAINLCD_320X480__) */
    wgui_softkey_set_abm_layer(dm_popupbg_layer);
#endif /* defined(__MMI_MAINLCD_320X480__) */
#else /* defined(DM_NEW_POPUPBG_METHOD) */
    if (dm_check_control_exist(g_dm_data.s32CatId, DM_SCR_BG) &&
        g_dm_scr_bg_cntx.layer_handle != GDI_ERROR_HANDLE)
    {
        /* Popup background with full screen background */
        dm_popupfg_layer = dm_popupbg_layer = g_dm_scr_bg_cntx.layer_handle;
        old_bg_filler = NULL;
    }
    else
    {
        /* set default ABM source layer to the main base layer */
        gdi_layer_get_base_handle(&act_layer);
        dm_popupfg_layer = dm_popupbg_layer = act_layer;
    }
#endif /* defined(DM_NEW_POPUPBG_METHOD) */

    /* draw gray / image / etc. background */
    gdi_layer_push_and_set_active(dm_popupbg_layer);
#endif

#ifdef __MMI_SCREEN_ROTATE__
    /*
     * When non-rotated -> rotated:
     * 
     * We do not keep the display content of the previous screen because
     * the layer data is in different format (i.e. screen width/pitch).
     *
     * (Note: for rotated->non-rotated case, please see mmi_frm_reset_screen_rotation())
     */
    if (mmi_frm_is_screen_width_height_swapped())
    {
        /* Use transparent color to see through background layer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    
        /* Use a fullscreen background:
         * 
         * When screen is rotated, we will use DM_SCR_BG in base control set.
         *
         * However, popup category screens may not have DM_BASE_CONTROL_SET1.
         * As a result, we need to setup screen background manually here.
         */
        /*
         *  we draw bg when rotated.
         */
        if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
        {
            /* [TODO] we cannot use dm_setup_and_draw_scr_bg() here because
             * some apps like Camera may draw popup category screen without 
             * freeing GDI layer. 
             * Because there is no DM_BASE_CONTROL_SET1, we do not need to care
             * about softkey redrawing */

            /* We will try to draw current_MMI_theme->rotated_bkg_filler first ,
             * if it NULL, we will draw bg from resource.*/
            if (current_MMI_theme->rotated_bkg_filler != NULL)
            {
                gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->rotated_bkg_filler);
            }
            else
            {
                gdi_image_draw_id(0, 0, IMG_SCREEN_ROTATE_BACKGROUND);
            }
        }
    }
    else if (mmi_frm_get_previous_screen_rotate() != mmi_frm_get_screen_rotate() 
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
                && !dm_check_control_exist(g_dm_data.s32CatId, DM_SCR_BG)
#endif
            )
    {
        /* 
         * When rotated -> non-rotated, we need to clear the background because we cannot not preserve 
         * the screen display content. 
         *
         * Fill transparent color to be the same as softkey background (if softkey is present)
         */

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
        if (!dm_check_control_exist(g_dm_data.s32CatId, DM_SCR_BG))
#endif
        {
            gdi_layer_clear(GDI_COLOR_BLACK);
        }
        
        if (dm_popup_background_info.Flags & DM_POPUP_BACKGROUND_HATCH_FILL)
        {
            color c = {200, 200, 200, 100};
            UI_cross_hatch_fill_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, c);
            entry_full_screen();
            g_dm_cntx.exit_full_screen_on_exit = MMI_TRUE;
        }
        else if (dm_popup_background_info.Flags & DM_POPUP_BACKGROUND_GREYSCALE)     
        {
            gui_greyscale_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, MMI_BG_GREYSCALE_VALUE, MMI_BG_GREYSCALE_BLACK_VALUE);    
        }
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */ 
#ifdef __MMI_FTE_SUPPORT__
    if (dm_popup_background_info.Flags & DM_POPUP_BACKGROUND_HATCH_FILL)
    {
        color c = {200, 200, 200, 100};
        UI_cross_hatch_fill_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, c);
        entry_full_screen();
        g_dm_cntx.exit_full_screen_on_exit = MMI_TRUE;
    }
    else if (dm_popup_background_info.Flags & DM_POPUP_BACKGROUND_GREYSCALE)     /* 072505 Calvin added: After 6228, it should support alpha channel */
    {
        gui_greyscale_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, MMI_BG_GREYSCALE_VALUE, MMI_BG_GREYSCALE_BLACK_VALUE);     /* 102605 greyscale Calvin modified */
    }
#else
    if (dm_popup_background_info.Flags & DM_POPUP_BACKGROUND_GREYSCALE)     /* 072505 Calvin added: After 6228, it should support alpha channel */
    {
        gui_greyscale_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, MMI_BG_GREYSCALE_VALUE, MMI_BG_GREYSCALE_BLACK_VALUE);     /* 102605 greyscale Calvin modified */
    }
#endif
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    gdi_layer_pop_and_restore_active();
#endif
    /* draw pop-up background image */
    dm_redraw_popup_background();

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_scroll_text
 * DESCRIPTION
 *  This function is used setup the popup background based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_scroll_text(S16 **UICtrlAccessPtr_p, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_scroll_text_info;
    S32 width = 0, height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_scroll_text_info);
    DM_RETURN_IF_INVALID_COORD(&dm_scroll_text_info);


    if (dm_scroll_text_buf[index][0] == 0 && dm_scroll_text_buf[index][1] == 0)
    {
        return 0;
    }
    if (index >= dm_scroll_text_count)
    {
        return 0;
    }

    dm_current_scroll_text = &dm_scroll_text[index];
    if (dm_scroll_text_info.Flags & DM_SCROLL_TEXT_CENTRE_ALIGN_X)
        if (dm_current_scroll_text->text_width >= dm_scroll_text_info.s16Width)
        {
            dm_current_scroll_text->x = (S32) dm_scroll_text_info.s16X;
            dm_current_scroll_text->width = (S32) dm_scroll_text_info.s16Width;
        }
        else
        {
            dm_current_scroll_text->x =
                (S32) dm_scroll_text_info.s16X + ((dm_scroll_text_info.s16Width - dm_current_scroll_text->width) >> 1);
        }
    else
    {
        dm_current_scroll_text->x = (S32) dm_scroll_text_info.s16X;
        dm_current_scroll_text->width = (S32) dm_scroll_text_info.s16Width;
    }

    if (dm_scroll_text_info.Flags & DM_SCROLL_TEXT_CENTER_ALIGN_Y)
    {
        dm_current_scroll_text->y =
            (S32) (dm_scroll_text_info.s16Y + ((dm_scroll_text_info.s16Height - dm_current_scroll_text->height) >> 1));
    }
    else
    {
        dm_current_scroll_text->y = (S32) dm_scroll_text_info.s16Y;
    }

    //dm_current_scroll_text->width = (S32) dm_scroll_text_info.s16Width;
    if (dm_scroll_text_info.Flags & DM_SCROLL_TEXT_USE_FONT_HEIGHT)
    {
        /* pre-set the font, maybe this should be passed from category */
        gui_set_font(&MMI_medium_font);
        gui_measure_string(dm_current_scroll_text->text, &width, &height);
        dm_current_scroll_text->height = height;
        dm_scroll_text_info.s16Height = height;
    }
    else
    {
        dm_current_scroll_text->height = (S32) dm_scroll_text_info.s16Height;
    }
    setup_previous_control(&dm_scroll_text_info);
    gui_show_scrolling_text(dm_current_scroll_text);
    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  dm_get_popup_bg_coordinate
 * DESCRIPTION
 *  This function is used to get popup background coordinate.
 * PARAMETERS
 *  dm_popup_background_info  [IN/OUT]    popup background info
 * RETURNS
 *  void
 *****************************************************************************/
void dm_get_popup_bg_coordinate(dm_coordinates *dm_popup_background_info)
{
    *dm_popup_background_info = dm_popupbg_coordinate;
}

/*****************************************************************************
 * FUNCTION
 *  dm_get_aligned_area_element_height
 * DESCRIPTION
 *  This function is used to get element height in aligned area.
 * PARAMETERS
 *  control_set_ptr       [IN]        control set pointer
 *  dm_aligned_area_info  [IN]        aligned area default coordinate.
 *  total_element_height  [IN/OUT]    total element height.
 *  is_multiline          [IN/OUT]    multiline exist or not.
 *  number_of_items       [IN/OUT]    total element number.
 * RETURNS
 *  void
 *****************************************************************************/
static void dm_get_aligned_area_element_height(
                                U8 *control_set_ptr, 
                                dm_coordinates dm_aligned_area_info, 
                                S32 *total_element_height, 
                                S32 *is_multiline, 
                                U8 *number_of_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 1;
    S32 element_height = 0, element_width = 0;
    S32 image_count = 0, string_count = 0;
    U8 number_of_elements = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get Number of elements in aligned area */
    while (control_set_ptr[i - 1] != DM_ALIGNED_AREA_START) /* find the start of aligned area */
    {
        i++;
        if (control_set_ptr[i - 1] == DM_IMAGE)
        {
            image_count++;  /* skip those images not in aligned area. */
        }
        if (control_set_ptr[i - 1] == DM_STRING)
        {
            string_count++; /* skip those strings not in aligned area. */
        }
        MMI_ASSERT(i < 20); /* avoid infinite while loop. */
    }
    /* Assume all is vertically arranged, horizontally center alignment */
    while (control_set_ptr[i] != DM_ALIGNED_AREA_END)   /* start to calculate number of items and its' height */
    {
        MMI_ASSERT(i < 20); /* avoid infinite while loop. */
        switch (control_set_ptr[i])
        {
#if 1//def __MMI_EDITOR_SINGLINE_SUPPORT__
            case DM_SINGLELINE_INPUTBOX1:
                if (get_singleline_inputbox_display_status())
                {
                    resize_singleline_inputbox(dm_aligned_area_info.s16Width, MMI_singleline_inputbox_height);
                    number_of_elements++;
                    element_width = dm_aligned_area_info.s16Width;
                    element_height = MMI_singleline_inputbox_height;
                }
                else
                {
                    element_width = 0;
                    element_height = 0;
                }
                break;
#endif
            case DM_MULTILINE_INPUTBOX1:
                *is_multiline = 1;
                if (get_multiline_inputbox_display_status())
                {
                    resize_multiline_inputbox_fit(
                        dm_aligned_area_info.s16Width,
                        dm_aligned_area_info.s16Height,
                        &element_width,
                        &element_height);
                    number_of_elements++;
                }
                else
                {
                    element_width = 0;
                    element_height = 0;
                }
                break;
            case DM_IMAGE:
                if (dm_image_array[image_count].image != NULL)  /* from resource */
                {
                
#ifdef __MMI_FTE_SUPPORT__
                    if(dm_image_array[image_count].dyn_prop_flag & DM_IMAGE_WITHOUT_HEADER)
                    {
                        gdi_image_get_dimension_mem(
                            dm_image_array[image_count].image_type, 
                            dm_image_array[image_count].image, 
                            dm_image_array[image_count].image_size, 
                            &element_width, 
                            &element_height);
                        image_count++;
                    }
                    else if(dm_image_array[image_count].dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#else
                    if(dm_image_array[image_count].dyn_prop_flag & DM_IMAGE_WITH_HEADER)
#endif
                    {
                        gdi_image_get_dimension(dm_image_array[image_count++].image, &element_width, &element_height);
                    }
                    else
                    {
                        element_width = dm_image_array[image_count].width;
                        element_height = dm_image_array[image_count].height;
                    }

                    number_of_elements++;
                }
                else if (dm_image_array[image_count].name != NULL)      /* from file */
                {
                    gdi_image_get_dimension_file(
                        (S8*) dm_image_array[image_count++].name,
                        &element_width,
                        &element_height);
                    number_of_elements++;
                }
                else    /* empty image. */
                {
                    element_width = 0;
                    element_height = 0;
                    image_count++;
                }

                break;
            case DM_STRING:
                if (dm_string_array[string_count].string != NULL)
                {
                    gui_measure_string(dm_string_array[string_count++].string, &element_width, &element_height);
                    number_of_elements++;
                }
                else
                {
                    element_width = 0;
                    element_height = 0;
                    string_count++;
                }
                break;
            case DM_SLIDE_CONTROL:
                break;
            case DM_MATRIX_MENU1:
                break;
            default:
                MMI_ASSERT(0);  /* support above controls ONLY */
        }
        *total_element_height += element_height;
        i++;
    }
    *number_of_items = number_of_elements;
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_aligned_area
 * DESCRIPTION
 *  This function is used setup the aligned area based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  control_set_ptr         [?]             
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_aligned_area(S16 **UICtrlAccessPtr_p, U8 *control_set_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_aligned_area_info;
    U8 number_of_elements = 0;
    S32 total_element_height = 0;//, element_height = 0, element_width = 0;
    //S32 image_count = 0, string_count = 0;
    S32 is_multiline = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get aligned area range and flags */
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_aligned_area_info);
    dm_aligned_area_data.s16X = dm_aligned_area_info.s16X;
    dm_aligned_area_data.s16Y = dm_aligned_area_info.s16Y;
    dm_aligned_area_data.Flags = dm_aligned_area_info.Flags;
    dm_aligned_area_data.s16width = dm_aligned_area_info.s16Width;//MAIN_LCD_DEVICE_WIDTH - 2*WGUI_POPUP_FTE_AREA_X;//dm_aligned_area_info.s16Width;
    dm_aligned_area_data.s16height = dm_aligned_area_info.s16Height;

    dm_get_aligned_area_element_height(control_set_ptr, dm_aligned_area_info, &total_element_height, &is_multiline, &number_of_elements);

    if (dm_aligned_area_data.Flags & DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM)
    {
        if (total_element_height <= dm_aligned_area_info.s16Height)
        {
            dm_aligned_area_data.s16Y += ((dm_aligned_area_info.s16Height - total_element_height) >> 1);
            dm_aligned_area_data.s16height -= ((dm_aligned_area_info.s16Height - total_element_height) >> 1);
            dm_aligned_area_data.y_space = 0;
        }
        else
        {
            if(is_multiline)
            {
                if (dm_aligned_area_data.Flags & DM_ALLIGNED_AREA_MULTILINE_SCROLL_IF_REQUIRED)
                {
                    S32 h;

                    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
                    h = dm_aligned_area_info.s16Height - (total_element_height - MMI_multiline_inputbox.height);
                    resize_multiline_inputbox(MMI_multiline_inputbox.width, h - 1);
                    MMI_multiline_inputbox.edit_width =
                        MMI_multiline_inputbox.width - MMI_multiline_inputbox.vbar.width - 2;
                    SetKeyDownHandler(multiline_inputbox_previous_line, KEY_UP_ARROW);
                    SetKeyDownHandler(multiline_inputbox_next_line, KEY_DOWN_ARROW);
                }
                else
                {
                    S32 h = dm_aligned_area_info.s16Height - (total_element_height - MMI_multiline_inputbox.height);
                    resize_multiline_inputbox(MMI_multiline_inputbox.width, h);
                }
            }
        }
    }
#ifdef __MMI_FTE_SUPPORT__
    else if (dm_aligned_area_data.Flags & DM_ALLIGNED_AREA_FOR_POPUP_FTE)
    {
        S32 h;

        if (total_element_height > MMI_POP_UP_DIALOG_FULL_HEIGHT)
        {
            S32 h1;

            h1 = MMI_POP_UP_DIALOG_FULL_HEIGHT - (total_element_height - MMI_multiline_inputbox.height);
            if (is_multiline)
            {
                if (dm_aligned_area_data.Flags & DM_ALLIGNED_AREA_MULTILINE_SCROLL_IF_REQUIRED)
                {
                    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR; 
                    resize_multiline_inputbox(MMI_multiline_inputbox.width, h1 - 1);
                    MMI_multiline_inputbox.edit_width =
                        MMI_multiline_inputbox.width - MMI_multiline_inputbox.vbar.width - 2;
                    SetKeyDownHandler(multiline_inputbox_previous_line, KEY_UP_ARROW);
                    SetKeyDownHandler(multiline_inputbox_next_line, KEY_DOWN_ARROW);
                }
                else
                {
                    resize_multiline_inputbox(MMI_multiline_inputbox.width, h1);
                }
            }
            
            total_element_height = MMI_POP_UP_DIALOG_FULL_HEIGHT;
        }
        h = total_element_height + 2*WGUI_POPUP_FTE_AREA_SPACE;

        dm_aligned_area_data.s16X = WGUI_POPUP_FTE_AREA_X;
        if((h + WGUI_POPUP_FTE_AREA_TOP_SPACE + WGUI_POPUP_FTE_AREA_BOTTOM_SPACE) < WGUI_POPUP_FTE_AREA_MIN_HEIGHT)
        {
            h = WGUI_POPUP_FTE_AREA_MIN_HEIGHT;
            dm_aligned_area_data.s16Y = MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - h + (h - total_element_height)/2;
        }
        else
        {
            dm_aligned_area_data.s16Y = MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - h  - WGUI_POPUP_FTE_AREA_BOTTOM_SPACE + WGUI_POPUP_FTE_AREA_SPACE;
        }
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)        
        if(MMI_TRUE == wgui_icon_bar_is_created())
        {
            dm_aligned_area_data.s16Y -= MMI_ICON_BAR_HEIGHT;
        }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /*__MMI_ICON_BAR_SUPPORT__*/
        dm_aligned_area_data.y_space = 0;

        dm_aligned_area_data.s16width = MAIN_LCD_DEVICE_WIDTH - 2*WGUI_POPUP_FTE_AREA_X;
        dm_aligned_area_data.s16height = h;
    }
#endif
    else
    {
        U16 left_space = (dm_aligned_area_info.s16Height <= total_element_height) ? 0 : (dm_aligned_area_info.s16Height - total_element_height);

        dm_aligned_area_data.y_space =
            left_space/*(dm_aligned_area_info.s16Height - total_element_height)*/ / (number_of_elements + 1);
    }
    dm_aligned_area_data.x_space = 0;
    return 1;
}   /* end of dm_setup_and_draw_aligned_area */


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_slide_control
 * DESCRIPTION
 *  This function is used setup the slide control based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_slide_control(S16 **UICtrlAccessPtr_p, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_slide_control_info;
    slide_control *previous_current_slide_control = MMI_current_slide_control;
    S32 value_width = 0;
    S32 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get aligned area range and flags */
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_slide_control_info);
    DM_RETURN_IF_INVALID_COORD(&dm_slide_control_info);

    if (dm_slide_control_info.Flags & DM_SLIDE_CONTROL_VALUE_POS_NONE)
    {
        MMI_slide_control[index].flags = GUI_SLIDE_CONTROL_VALUE_POS_NONE;
    }
    else if (dm_slide_control_info.Flags & DM_SLIDE_CONTROL_VALUE_POS_HEAD)
    {
        MMI_slide_control[index].flags = GUI_SLIDE_CONTROL_VALUE_POS_HEAD;
    }
    else if (dm_slide_control_info.Flags & DM_SLIDE_CONTROL_VALUE_POS_TAIL)
    {
        MMI_slide_control[index].flags = GUI_SLIDE_CONTROL_VALUE_POS_TAIL;
    }
    else if (dm_slide_control_info.Flags & DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE)
    {
        MMI_slide_control[index].flags = GUI_SLIDE_CONTROL_VALUE_POS_NEXT_LINE;
    }

    if (g_dm_cntx.redraw_screen_main != REDRAW_2_REDRAW)
    {
        for (idx = 0; idx < dm_slide_control_count; idx++)
        {
            if (MMI_slide_control[idx].value_string_width > value_width)
            {
                value_width = MMI_slide_control[idx].value_string_width;
            }
        }

        /* if ( dm_slide_control_info.Flags&DM_CENTRE_ALIGN_X) */
        switch (MMI_slide_control[index].flags)
        {
            case GUI_SLIDE_CONTROL_VALUE_POS_HEAD:
                dm_slide_control_info.s16X +=
                    ((dm_slide_control_info.s16Width - MMI_slide_control[index].bg_image_width - value_width) >> 1) +
                    value_width;
                MMI_slide_control[index].value_string_gap =
                    (value_width - MMI_slide_control[index].value_string_width) >> 1;
                break;

            case GUI_SLIDE_CONTROL_VALUE_POS_TAIL:
                dm_slide_control_info.s16X +=
                    (dm_slide_control_info.s16Width - MMI_slide_control[index].bg_image_width - value_width) >> 1;
                MMI_slide_control[index].value_string_gap =
                    (value_width - MMI_slide_control[index].value_string_width) >> 1;
                break;

            case GUI_SLIDE_CONTROL_VALUE_POS_NEXT_LINE:
                dm_slide_control_info.s16X +=
                    (dm_slide_control_info.s16Width - MMI_slide_control[index].bg_image_width) >> 1;
                MMI_slide_control[index].value_string_gap = 0;
                break;

            case GUI_SLIDE_CONTROL_VALUE_POS_NONE:
                break;

            default:
                break;
        }
        /* if ( MMI_slide_control[index].flags == GUI_SLIDE_CONTROL_VALUE_POS_TAIL ) */

        dm_slide_control_info.s16Height = MMI_slide_control[index].bg_image_height;
        setup_previous_control(&dm_slide_control_info);
        move_slide_control_value(&MMI_slide_control[index], dm_slide_control_info.s16X, dm_slide_control_info.s16Y);
    }

    MMI_current_slide_control = &MMI_slide_control[index];
    wgui_show_slide_control();
    if ((MMI_current_slide_control == previous_current_slide_control) && (dm_get_slide_control_count() > 1))
    {
        wgui_show_slide_control_focus();
    }
    MMI_current_slide_control = previous_current_slide_control;

    return 1;
}   /* end of dm_setup_and_draw_slide_control */


#ifdef __MMI_STOPWATCH__
/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_typical_stopwatch
 * DESCRIPTION
 *  This function is used setup the typical stopwatch based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_typical_stopwatch(S16 **UICtrlAccessPtr_p)
{
#ifdef __MMI_STOPWATCH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_typical_stopwatch_info_struct dm_typical_stopwatch_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_typical_stopwatch_coordinates(*UICtrlAccessPtr_p, &dm_typical_stopwatch_info);
    if (dm_typical_stopwatch_info.coordinate.s16X == -1 || dm_typical_stopwatch_info.coordinate.s16Y == -1 ||
        dm_typical_stopwatch_info.coordinate.s16Width == -1 || dm_typical_stopwatch_info.coordinate.s16Height == -1)
    {
        return 0;
    }

    wtch_pos.typ_timer.x = dm_typical_stopwatch_info.typ_timer_x;
    wtch_pos.typ_timer.y = dm_typical_stopwatch_info.typ_timer_y;
    wtch_pos.typ_milsec.x = dm_typical_stopwatch_info.typ_milsec_x;
    wtch_pos.typ_milsec.y = dm_typical_stopwatch_info.typ_milsec_y;
    /* wtch_pos.typ_history_height = dm_typical_stopwatch_info.typ_history_height; */
    move_fixed_list(dm_typical_stopwatch_info.coordinate.s16X, dm_typical_stopwatch_info.coordinate.s16Y);
    resize_fixed_list(dm_typical_stopwatch_info.coordinate.s16Width, dm_typical_stopwatch_info.typ_history_height);
    /* stop_watch_x = (dm_typical_stopwatch_info.coordinate.s16Width >> 1) - (stop_watch_width >> 1); */
    /* stop_watch_y = dm_typical_stopwatch_info.coordinate.s16Y + MMI_fixed_list_menu.height; */
    show_typical_stop_watch();
    return 1;
#else /* __MMI_STOPWATCH__ */ 
    return 0;
#endif /* __MMI_STOPWATCH__ */ 
}   /* end of dm_setup_and_draw_typical_stopwatch */


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_nway_stopwatch
 * DESCRIPTION
 *  This function is used setup the N Way stopwatch based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_nway_stopwatch(S16 **UICtrlAccessPtr_p)
{
#ifdef __MMI_STOPWATCH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_nway_stopwatch_info_struct dm_nway_stopwatch_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_nway_stopwatch_coordinates(*UICtrlAccessPtr_p, &dm_nway_stopwatch_info);
    if (dm_nway_stopwatch_info.coordinate.s16X == -1 || dm_nway_stopwatch_info.coordinate.s16Y == -1 ||
        dm_nway_stopwatch_info.coordinate.s16Width == -1 || dm_nway_stopwatch_info.coordinate.s16Height == -1)
    {
        return 0;
    }

    wtch_pos.nWay_maintimer_start.x = dm_nway_stopwatch_info.nway_main_timer_x1;
    wtch_pos.nWay_maintimer_start.y = dm_nway_stopwatch_info.nway_main_timer_y1;
    wtch_pos.nWay_maintimer_end.x = dm_nway_stopwatch_info.nway_main_timer_x2;
    wtch_pos.nWay_maintimer_end.y = dm_nway_stopwatch_info.nway_main_timer_y2;

    wtch_pos.nWay_dialog_start.x = dm_nway_stopwatch_info.nway_dialog_x1;
    wtch_pos.nWay_dialog_start.y = dm_nway_stopwatch_info.nway_dialog_y1;
    wtch_pos.nWay_dialog_end.x = dm_nway_stopwatch_info.nway_dialog_x2;
    wtch_pos.nWay_dialog_end.y = dm_nway_stopwatch_info.nway_dialog_y2;

    wtch_pos.separator_height = dm_nway_stopwatch_info.separator_height;

    show_nway_stop_watch();
    old_bg_filler = NULL;
    return 1;
#else /* __MMI_STOPWATCH__ */ 
    return 0;
#endif /* __MMI_STOPWATCH__ */ 
}   /* dm_get_nway_stopwatch_coordinates */
#endif

/*****************************************************************************
 * FUNCTION
 *  dm_get_wallpaper_layer
 * DESCRIPTION
 *  This function is used to get the layer handle of wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
GDI_HANDLE dm_get_wallpaper_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
    return GDI_ERROR_HANDLE;
#else
    return (dm_wallpaper_layer_idx != -1) ? (dm_layers[dm_wallpaper_layer_idx]) : (GDI_ERROR_HANDLE);
#endif
#else
    return GDI_ERROR_HANDLE;
#endif
}


#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
/*****************************************************************************
 * FUNCTION
 *  dm_draw_wallpaper_dummy_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result       [IN]       
 * RETURNS
 *  void
 *****************************************************************************/
void dm_draw_wallpaper_dummy_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_wallpaper
 * DESCRIPTION
 *  This function is used setup wallpaper based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_wallpaper(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_wallpaper_info;
    GDI_HANDLE dm_new_layers;
#ifdef __GDI_MEMORY_PROFILE_2__
    #if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
    MMI_BOOL layer_created = MMI_FALSE;
    #endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_wallpaper_info);
    DM_RETURN_IF_INVALID_COORD(&dm_wallpaper_info);

    gdi_anim_set_blt_before_callback(dm_wallpaper_anim_before_blt_callback);
     
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    if ((g_dm_cntx.redraw_screen_main == REDRAW_2_REDRAW) && (dm_wallpaper_layer_idx != -1))
    {
        gdi_set_alpha_blending_source_layer(dm_layers[dm_wallpaper_layer_idx]);
    
        gdi_layer_push_and_set_active(dm_layers[dm_wallpaper_layer_idx]);
    #if defined(__PLUTO_MMI_PACKAGE__) 
        draw_wallpaper();
    #endif
        gdi_layer_pop_and_restore_active();
    }
    else
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        gdi_layer_multi_layer_enable();
        if (dm_wallpaper_layer_idx == -1)
        {
    #if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
            /* hack for temp solution, to be removed once AB2 images for scr_bg are ready */
            if (idle_screen_wallpaper_ID != 0)  
            {
                if (mmi_phnset_check_themeid_wallpaper(idle_screen_wallpaper_ID))
                {
                    gdi_layer_create(
                        dm_wallpaper_info.s16X,
                        dm_wallpaper_info.s16Y,
                        dm_wallpaper_info.s16Width,
                        dm_wallpaper_info.s16Height,
                        &dm_new_layers);
                    layer_created = MMI_TRUE;
                    
                }
            }
            if(layer_created == MMI_FALSE)
            {
                gdi_layer_create_cf(
                    GDI_COLOR_FORMAT_24,
                    dm_wallpaper_info.s16X,
                    dm_wallpaper_info.s16Y,
                    dm_wallpaper_info.s16Width,
                    dm_wallpaper_info.s16Height,
                    &dm_new_layers);
            }
    #else /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */
            gdi_layer_create(
                dm_wallpaper_info.s16X,
                dm_wallpaper_info.s16Y,
                dm_wallpaper_info.s16Width,
                dm_wallpaper_info.s16Height,
                &dm_new_layers);
    #endif /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */
            if (g_dm_scr_bg_cntx.layer_handle != GDI_ERROR_HANDLE)
            {
                gdi_layer_free(g_dm_scr_bg_cntx.layer_handle);
            }
            dm_layers[dm_layers_count] = dm_new_layers;
            gdi_layer_set_active(dm_layers[dm_layers_count++]);
            dm_wallpaper_layer_idx = dm_layers_count - 1;
        }
        else
        {
            gdi_layer_set_active(dm_layers[dm_wallpaper_layer_idx]);
        }
        /* gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT); */
        gdi_layer_clear(gdi_layer_get_background());
        old_bg_filler = NULL;

        if (dm_wallpaper_layer_idx != -1)
        {        
            gdi_set_alpha_blending_source_layer(dm_layers[dm_wallpaper_layer_idx]);
        }

    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    #if defined(__PLUTO_MMI_PACKAGE__) 
        draw_wallpaper();
    #endif
    }
#else
    #if defined(__PLUTO_MMI_PACKAGE__) 
        draw_wallpaper();
    #endif
#endif
    gdi_anim_set_blt_before_callback(dm_draw_wallpaper_dummy_callback);
    return 1;

}   /* dm_get_nway_stopwatch_coordinates */
#endif


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_percentage_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN]        
 *  count                   [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 dm_setup_and_draw_percentage_bar(S16 **UICtrlAccessPtr_p, S32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_percentage_bar_info;
    dm_percentage_bar_struct *act_bar = &dm_percentage_bar_array[count];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_percentage_bar_info);
    DM_RETURN_IF_INVALID_COORD(&dm_percentage_bar_info);


    act_bar->x = dm_percentage_bar_info.s16X;
    act_bar->y = dm_percentage_bar_info.s16Y;
    act_bar->width = dm_percentage_bar_info.s16Width;
    act_bar->height = dm_percentage_bar_info.s16Height;

    dm_redraw_percentage_bar(count);

    return 1;
}


#if (defined(__MMI_SEARCH_WEB__) || defined(__MMI_HIDD_SUPPORT__))
/* 121106 HID Start */
/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_panel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN]        
 *  count                   [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 dm_setup_and_draw_panel(S16 **UICtrlAccessPtr_p, S32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_panel_info;
    gui_panel_struct *act_panel = &dm_panel_array[count];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_panel_info);
    DM_RETURN_IF_INVALID_COORD(&dm_panel_info);

    act_panel->x = dm_panel_info.s16X;
    act_panel->y = dm_panel_info.s16Y;
    act_panel->width = dm_panel_info.s16Width;
    act_panel->height = dm_panel_info.s16Height;

    gui_panel_show(act_panel);

    return 1;
}
/* 121106 HID End */
#endif

#ifdef __MMI_CALENDAR__ 
S32 dm_setup_and_draw_calendar(S16 **UICtrlAccessPtr_p)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates dm_calendar_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_calendar_show();
    *UICtrlAccessPtr_p = dm_get_coordinates(*UICtrlAccessPtr_p, &dm_calendar_info);
    return 1;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  dm_get_current_scr_bg_filler
 * DESCRIPTION
 *  This function is used to get current filler by category ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
UI_filled_area* dm_get_current_scr_bg_filler(void)
{
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        return (current_MMI_theme->rotated_bkg_filler);
    }
#endif    
    if (g_dm_data.s32CatId == MMI_CATEGORY14_LIST_ID ||
        g_dm_data.s32CatId == MMI_CATEGORY14_MATRIX_ID ||
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        g_dm_data.s32CatId == MMI_CATEGORY414_ID)
    {
        /*In Main Screen*/
        return (current_MMI_theme->main_menu_bkg_filler);
    }
    else if (g_dm_data.s32CatId == MMI_CATEGORY306_ID ||
             g_dm_data.s32CatId == MMI_CATEGORY307_ID)
    {
        /* In Multimedia screen */
        return (current_MMI_theme->special_screen_bkg_filler);
    }    
    else
    {
        /* Others */
        return (current_MMI_theme->sub_menu_bkg_filler);
    }
}


#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
/*****************************************************************************
 * FUNCTION
 *  dm_draw_scr_bg_image
 * DESCRIPTION
 *  This function is used to draw scr bg image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_draw_scr_bg_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area  *bg_image_filler;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check Theme file */
    bg_image_filler = dm_get_current_scr_bg_filler();

    gdi_layer_push_and_set_active(g_dm_scr_bg_cntx.layer_handle);

    gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, gdi_layer_get_background());
    
    if (g_dm_scr_bg_cntx.is_used == 0)
    {
        gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, bg_image_filler);
    }
    else if (g_dm_scr_bg_cntx.offset_x == -1 && g_dm_scr_bg_cntx.offset_y == -1)
    {
        S32 img_w, img_h;

        if (g_dm_scr_bg_cntx.image_id != 0)
        {
            /* from resource */
            gdi_image_get_dimension_id(g_dm_scr_bg_cntx.image_id, &img_w, &img_h);
        }
        else
        {
            /* from file */
            gdi_image_get_dimension_file(g_dm_scr_bg_cntx.image_name, &img_w, &img_h);
        }
        /* the image is too large to fit the screen */
        if (img_w > UI_device_width || img_h > UI_device_height)
        {
            S32 resized_offset_x, resized_offset_y;
            S32 resized_width, resized_height;
            
            gdi_image_util_fit_bbox(
                UI_device_width,
                UI_device_height,
                img_w,
                img_h,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);
            
            if (g_dm_scr_bg_cntx.image_id != 0)
            {
                gdi_image_draw_resized(
                    resized_offset_x,
                    resized_offset_y,
                    resized_width,
                    resized_height,
                    get_image(g_dm_scr_bg_cntx.image_id));
            }
            else
            {
                gdi_image_draw_resized_file(
                    resized_offset_x,
                    resized_offset_y,
                    resized_width,
                    resized_height,
                    (S8*) g_dm_scr_bg_cntx.image_name);
            }
        }
        else
        {
            S32 offset_x = (UI_device_width - img_w) >> 1;
            S32 offset_y = (UI_device_height - img_h) >> 1;
            
            if (g_dm_scr_bg_cntx.image_id != 0)
            {
                gdi_image_draw_id(offset_x, offset_y, g_dm_scr_bg_cntx.image_id);
            }
            else
            {
                gdi_image_draw_file(offset_x, offset_y, g_dm_scr_bg_cntx.image_name);
            }
        }
    }
    else
    {
        if (g_dm_scr_bg_cntx.image_id != 0) /* from resource */
        {
            gdi_image_draw_id(g_dm_scr_bg_cntx.offset_x, g_dm_scr_bg_cntx.offset_y, g_dm_scr_bg_cntx.image_id);
        }
        else /* from file */
        {
            gdi_image_draw_file(g_dm_scr_bg_cntx.offset_x, g_dm_scr_bg_cntx.offset_y, g_dm_scr_bg_cntx.image_name);
        }
    }


#if defined(__MMI_WALLPAPER_ON_BOTTOM__) && defined(__MMI_ALPHA_BLENDING__)
    /* 
     * Flatten the scr bg layer when its opacity is not 255.
     *
     * The scr bg layer is the source layer of alpha blending. If the hardware
     * opacity is used, the alpha blending result will be wrong since
     * the scr bg layer is INTACT, i.e., without the background color.
     *
     * MAIN BASE LAYER                      high    alpha blending target layer
     *       |                               ^
     * SCR BG LAYER                          |      alpha blending source layer
     *       |                               |
     * SCR BG LAYER BACKGROUND COLOR        lowest  (This is not a layer!)
     */
    if (g_dm_scr_bg_cntx.layer_opacity != 255)
    {
        if (!dm_is_fixed_layer_mode_enabled())
           gdi_layer_flatten(g_dm_scr_bg_cntx.layer_handle, 0, 0, 0);
        /* disable opacity since the scr bg layer is already flattened */
        gdi_layer_set_opacity(FALSE, 255);
    }
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) && defined(__MMI_ALPHA_BLENDING__) */

   gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  dm_set_scr_bg_image
 * DESCRIPTION
 *  This function is used to set image id or image name of scr bg image
 * PARAMETERS
 *  image_id        [IN]        Id of the image
 *  file_name       [IN]        File name of the image
 *  x               [IN]        
 *  y               [IN]        
 *  opacity         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dm_set_scr_bg_image(U16 image_id, S8 *file_name, S32 x, S32 y, U8 opacity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 092005 Wallpaper Setting Calvin */
    if (image_id != 0 && file_name == NULL)
    {
        g_dm_scr_bg_cntx.image_id = image_id;
        g_dm_scr_bg_cntx.image_name = NULL;
    }
    else if (image_id == 0 && file_name != NULL)
    {
        g_dm_scr_bg_cntx.image_id = 0;
        g_dm_scr_bg_cntx.image_name = file_name;
    }
    else
    {
        MMI_ASSERT(0);
    }

    g_dm_scr_bg_cntx.offset_x = x;
    g_dm_scr_bg_cntx.offset_y = y;
    g_dm_scr_bg_cntx.layer_opacity = opacity;   /* 070505 Calvin added */
    g_dm_scr_bg_cntx.is_used = 1;

    /* 070505 Calvin moved */
    /* if g_dm_scr_bg_cntx.1scr_bg_layer does not exist */
    if (g_dm_scr_bg_cntx.layer_handle == GDI_ERROR_HANDLE)
    {
        return;
    }
    /* 070505 Calvin end */

    if (dm_is_need_change_scr_bg() && g_dm_scr_bg_cntx.layer_handle != NULL)
    {
        gdi_layer_push_and_set_active(g_dm_scr_bg_cntx.layer_handle);
        gdi_layer_set_opacity(TRUE, g_dm_scr_bg_cntx.layer_opacity);        /* 070505 Calvin added */
        gdi_layer_clear(GDI_COLOR_WHITE);
        /* Start to draw the background */
        dm_draw_scr_bg_image();
        /* End of drawing the background */
        gdi_layer_pop_and_restore_active();
    }
}

/* 100405 dm_set_scr_bg_image_no_draw Calvin Start */


/*****************************************************************************
 * FUNCTION
 *  dm_set_scr_bg_image_no_draw
 * DESCRIPTION
 *  This function is used to set image id or image name of scr bg image
 * PARAMETERS
 *  image_id        [IN]        Id of the image
 *  file_name       [IN]        File name of the image
 *  x               [IN]        
 *  y               [IN]        
 *  opacity         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dm_set_scr_bg_image_no_draw(U16 image_id, S8 *file_name, S32 x, S32 y, U8 opacity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_id != 0 && file_name == NULL)
    {
        g_dm_scr_bg_cntx.image_id = image_id;
        g_dm_scr_bg_cntx.image_name = NULL;
    }
    else if (image_id == 0 && file_name != NULL)
    {
        g_dm_scr_bg_cntx.image_id = 0;
        g_dm_scr_bg_cntx.image_name = file_name;
    }
    else
    {
        MMI_ASSERT(0);
    }

    g_dm_scr_bg_cntx.offset_x = x;
    g_dm_scr_bg_cntx.offset_y = y;
    g_dm_scr_bg_cntx.layer_opacity = opacity;   /* 070505 Calvin added */
    g_dm_scr_bg_cntx.is_used = 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_set_scr_bg_lite_color
 * DESCRIPTION
 *  This function is used to set user lite color
 * PARAMETERS
 *  lite_color        [IN]        color to fill scr bg
 * RETURNS
 *  void
 *****************************************************************************/
void dm_set_scr_bg_lite_color(gdi_color lite_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_scr_bg_color = lite_color;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_scr_bg_image
 * DESCRIPTION
 *  This function is used to get image id or image name of scr bg image
 * PARAMETERS
 *  image_id        [IN/OUT]        Id of the image
 *  file_name       [IN/OUT]        File name of the image
 *  x               [?]             
 *  y               [?]             
 *  opacity         [?]             
 * RETURNS
 *  void
 *****************************************************************************/
/* Leo add 0701 */
void dm_get_scr_bg_image(U16 *image_id, S8 **file_name, S32 *x, S32 *y, U8 *opacity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_scr_bg_cntx.image_id == 0 && g_dm_scr_bg_cntx.image_name == NULL)
    {
        if (idle_screen_wallpaper_ID == 0)
        {
            g_dm_scr_bg_cntx.image_name = idle_screen_wallpaper_name;
        }
        else
        {
            g_dm_scr_bg_cntx.image_id = idle_screen_wallpaper_ID;
        }
    }

    *image_id = g_dm_scr_bg_cntx.image_id;
    *file_name = g_dm_scr_bg_cntx.image_name;
    *x = g_dm_scr_bg_cntx.offset_x;
    *y = g_dm_scr_bg_cntx.offset_y;
    *opacity = g_dm_scr_bg_cntx.layer_opacity;
}


/*****************************************************************************
 * FUNCTION
 *  dm_set_scr_bg_redraw
 * DESCRIPTION
 *  An API for application to set the flag g_dm_cntx.redraw_scr_bg_flag
 * PARAMETERS
 *  status      [IN]        The new value of dm_draw_scr_bg_flag.
 * RETURNS
 *  void
 *****************************************************************************/
void dm_set_scr_bg_redraw(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_cntx.redraw_scr_bg_flag == MMI_FALSE && status == MMI_TRUE)        /* should clear g_dm_scr_bg_cntx.1scr_bg_layer */
    {
        g_dm_cntx.redraw_scr_bg_flag = status;
        g_dm_cntx.redraw_scr_directly = status;
    }
    else if (g_dm_cntx.redraw_scr_bg_flag == MMI_TRUE && status == MMI_FALSE)
    {
        /* SHOULD NOT HAPPEN */
        g_dm_cntx.redraw_scr_bg_flag = status;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_set_scr_bg_opacity
 * DESCRIPTION
 *  This function is used to set opacity of scr_bg layer
 * PARAMETERS
 *  opacity     [IN]        Opacity of layer
 * RETURNS
 *  void
 *****************************************************************************/
void dm_set_scr_bg_opacity(U8 opacity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dm_scr_bg_cntx.layer_opacity = opacity;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_scr_bg_opacity
 * DESCRIPTION
 *  This function is used to get opacity of scr_bg layer
 * PARAMETERS
 *  opacity     [IN/OUT]        Opacity of layer
 * RETURNS
 *  void
 *****************************************************************************/
void dm_get_scr_bg_opacity(U8 *opacity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *opacity = g_dm_scr_bg_cntx.layer_opacity;
}

/* 082906 scr_bg Start */
/*****************************************************************************
 * FUNCTION
 *  dm_set_scr_bg_flag
 * DESCRIPTION
 *  This function is used to set display flags of scr_bg layer
 * PARAMETERS
 *  flags     [IN]        display flags
 * RETURNS
 *  void
 *****************************************************************************/
void dm_set_scr_bg_flag(S32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dm_scr_bg_cntx.flags = flags;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_scr_bg_flag
 * DESCRIPTION
 *  This function is used to get display flags of scr_bg layer
 * PARAMETERS
 *  flags     [IN/OUT]        display flags
 * RETURNS
 *  void
 *****************************************************************************/
void dm_get_scr_bg_flag(S32 *flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *flags = g_dm_scr_bg_cntx.flags;
}
/* 082906 scr_bg End */


/*****************************************************************************
 * FUNCTION
 *  dm_get_scr_bg_layer
 * DESCRIPTION
 *  This function is used to get the layer handle of scr bg image
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
GDI_HANDLE dm_get_scr_bg_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_is_wallpaper_on_bottom())
    {
        return g_dm_scr_bg_cntx.layer_handle;
    }
    else
    {
        return GDI_ERROR_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_is_need_change_scr_bg
 * DESCRIPTION
 *  This function is used to check if need to create new layer and redraw scr BG
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL is need redraw scrbg
 *****************************************************************************/
static MMI_BOOL dm_is_need_change_scr_bg(void)
{
    UI_filled_area  *bg_new_filler;

    if (g_dm_cntx.redraw_scr_directly == MMI_TRUE)
    {
        if (g_dm_scr_bg_cntx.is_used == 1)
        {
            old_bg_filler = NULL;
        }
        else
        {
            old_bg_filler = dm_get_current_scr_bg_filler();
        }
        old_bg_opacity = g_dm_scr_bg_cntx.layer_opacity;
        return MMI_FALSE;
    }

    if (old_bg_opacity != g_dm_scr_bg_cntx.layer_opacity)
    {
        /* Opacity different */
        if (old_bg_opacity != 255)
        {
            old_bg_opacity = g_dm_scr_bg_cntx.layer_opacity;
            if (g_dm_scr_bg_cntx.is_used == 1)
            {
                old_bg_filler = NULL;
            }
            else
            {
                old_bg_filler = dm_get_current_scr_bg_filler();
            }
            /* if draw theme background, then clear non-theme bg ID&filename */
            old_image_id = 0;
            old_image_name = NULL;
            return MMI_TRUE;
        }
        else
        {
            /* Opacity not same, but from 255 to others, do not need redraw */
        }
    }
    else
    {
        /* Opacity same do not need  hardware opacity */
        gdi_layer_set_opacity(FALSE, 255);
    }

    if (g_dm_scr_bg_cntx.is_used == 1)
    {
        /* Do not draw theme background */
        old_bg_filler = NULL;
        if (g_dm_scr_bg_cntx.image_id != 0) /* from resource */
        {
            if (old_image_id == g_dm_scr_bg_cntx.image_id)
            {
                /* same imageID, do not redraw */
                return MMI_FALSE;
            }
            else
            {
                old_image_id = g_dm_scr_bg_cntx.image_id;
                return MMI_TRUE;
            }
        }
        else if (g_dm_scr_bg_cntx.image_name != 0) /* from file */
        {
            if (old_image_name == NULL)
            {
                old_image_name = g_dm_scr_bg_cntx.image_name;
                return MMI_TRUE;
            }
            
            if (mmi_ucs2cmp(g_dm_scr_bg_cntx.image_name, old_image_name) == 0)
            {
                /* same image filename, do not redraw */
                return MMI_FALSE;
            }
            else
            {
                old_image_name = g_dm_scr_bg_cntx.image_name;
                return MMI_TRUE;
            }
        }
        return MMI_TRUE;
    }

    /* if draw theme background, then clear non-theme bg ID&filename */
    old_image_id = 0;
    old_image_name = NULL;
    
    if (old_bg_filler == NULL)
    {
        /* if IDLE change to other or last scrbg is imageID or imageName. */
        old_bg_filler = dm_get_current_scr_bg_filler();
        return MMI_TRUE;
    }
    else
    {
        if (g_dm_data.s32CatId == MMI_CATEGORY33_ID)
        {
            /* In Idle */
            ///TODO: after setting modified, need add idle screen.
            return MMI_TRUE;
        }
        else if (g_dm_data.s32flags & DM_LITE_DISP_WALLPAPER || g_dm_data.s32flags & DM_LITE_DISP_WALLPAPER_USER_COLOR)
        {
            /* draw lite display background */
            return MMI_TRUE;
         }
        else
        {
            /*In Main menu or others*/
            bg_new_filler = dm_get_current_scr_bg_filler();

            if (memcmp(bg_new_filler, old_bg_filler, sizeof(UI_filled_area)) != 0)
            {
                /* filler different */
                old_bg_filler = bg_new_filler;
                return MMI_TRUE;
            }
            
            if (bg_new_filler->b != NULL && old_bg_filler->b != NULL)
            {
                if (memcmp(bg_new_filler->b, old_bg_filler->b, 20) == 0)
                {
                    /* Image in filler are same */
                    old_bg_filler = bg_new_filler;
                    return MMI_FALSE;
                }
                else
                {
                    old_bg_filler = bg_new_filler;
                    return MMI_TRUE;
                }
            }
            else
            {
                /* Image in filler are NULL */
                old_bg_filler = bg_new_filler;
                return MMI_TRUE;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_scr_bg
 * DESCRIPTION
 *  This function is used setup screen background layer and draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_scr_bg(S16 **UICtrlAccessPtr_p)
{
    /* Currently coordinate set is not needed. The input UICtrlAccessPtr_p is just for future use. */
#ifdef __GDI_MEMORY_PROFILE_2__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    U8 is_new_layer = 0;
    U8 layer_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dm_is_fixed_layer_mode_enabled())
    {
        dm_set_scr_bg_redraw(MMI_FALSE);
    }

    g_dm_scr_bg_cntx.scr_bg_layer_exist = MMI_TRUE;
    
    if (g_dm_cntx.redraw_scr_bg_flag == MMI_TRUE)
    {
        if (dm_is_need_change_scr_bg() || g_dm_scr_bg_cntx.layer_handle == GDI_ERROR_HANDLE)
        {
            /* There is no free layer can be used for background */
            MMI_ASSERT(dm_layers_count < GDI_LAYER_TOTAL_LAYER_COUNT);

            gdi_layer_multi_layer_enable();
            if (g_dm_scr_bg_cntx.layer_handle != GDI_ERROR_HANDLE)
            {
                gdi_layer_free(g_dm_scr_bg_cntx.layer_handle);
            }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */
            ret = gdi_layer_create(0, 0, UI_device_width, UI_device_height, &g_dm_scr_bg_cntx.layer_handle);
#endif /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */

            /* Create layer fail */
            /* MMI_ASSERT (ret>0); */
            if (ret < 0)
            {
                return 0;
            }
#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
            if (dm_get_wallpaper_layer() != GDI_ERROR_HANDLE)
            {
                gdi_layer_free(dm_get_wallpaper_layer());
            }
#endif
            is_new_layer = 1;
        }

        if (g_dm_scr_bg_cntx.layer_handle != GDI_ERROR_HANDLE)
        {
            gdi_set_alpha_blending_source_layer(g_dm_scr_bg_cntx.layer_handle);
        }

        gdi_layer_push_and_set_active(g_dm_scr_bg_cntx.layer_handle);
    #ifdef __MMI_SCREEN_ROTATE__
        /* gdi_layer_set_rotate(gdi_layer_get_base_layer_rotation()); */
    #endif 
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

        if (g_dm_scr_bg_cntx.image_id == 0 && g_dm_scr_bg_cntx.image_name == NULL)
        {
            if (idle_screen_wallpaper_ID == 0)
            {
                g_dm_scr_bg_cntx.image_name = idle_screen_wallpaper_name;
            }
            else
            {
                g_dm_scr_bg_cntx.image_id = idle_screen_wallpaper_ID;
            }
        }

        if (old_bg_opacity != g_dm_scr_bg_cntx.layer_opacity || is_new_layer == 1 || g_dm_cntx.redraw_scr_directly == MMI_TRUE)
        {
    #ifdef __MMI_SCREEN_ROTATE__
            /* Tricky: ignore current scr bg opacity value to be compatible with
               dm_setup_and_draw_popup_background() */
            if (mmi_frm_is_screen_width_height_swapped())
            {
                gdi_layer_set_opacity(TRUE, (U8)current_MMI_theme->bg_opacity_full);    
            }
            else
            {
                gdi_layer_set_opacity(TRUE, (U8)g_dm_scr_bg_cntx.layer_opacity);        
            }
    #else /* __MMI_SCREEN_ROTATE__ */
            gdi_layer_set_opacity(TRUE, g_dm_scr_bg_cntx.layer_opacity);
    #endif /* __MMI_SCREEN_ROTATE__ */
        }

        if (g_dm_cntx.redraw_scr_directly == MMI_TRUE || (g_dm_cntx.redraw_scr_directly == MMI_FALSE && is_new_layer == 1))
        {

            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            
            /* Start to draw the background */
            if (g_dm_data.s32flags & DM_LITE_DISP_WALLPAPER)
            {
                /* draw lite display background */
                gdi_draw_solid_rect(
                    0,
                    0,
                    UI_device_width - 1,
                    UI_device_height - 1,
                    gdi_act_color_from_rgb(0xFF, current_MMI_theme->lite_disp_scr_bg_color->r, current_MMI_theme->lite_disp_scr_bg_color->g, current_MMI_theme->lite_disp_scr_bg_color->b));
                /* Need redraw scrBG next screen */
                old_bg_filler = NULL;
            }
            else if (g_dm_data.s32flags & DM_LITE_DISP_WALLPAPER_USER_COLOR)
            {
                /* draw lite display background */
                gdi_draw_solid_rect(
                    0,
                    0,
                    UI_device_width - 1,
                    UI_device_height - 1,
                    user_scr_bg_color);
                /* Need redraw scrBG next screen */
                old_bg_filler = NULL;
            }
            else
            {
                /*In Main menu or others*/
                dm_draw_scr_bg_image();
            }
            /* End of drawing the background */
            g_dm_cntx.redraw_scr_directly = MMI_FALSE;
        }
        else
        {
#if defined(__MMI_WALLPAPER_ON_BOTTOM__) && defined(__MMI_ALPHA_BLENDING__)
            /* 
             * When opacity from 255 to others, we do not draw background image, but we must
             * flatten the scr bg layer.
             *
             * The scr bg layer is the source layer of alpha blending. If the hardware
             * opacity is used, the alpha blending result will be wrong since
             * the scr bg layer is INTACT, i.e., without the background color.
             *
             * MAIN BASE LAYER                      high    alpha blending target layer
             *       |                               ^
             * SCR BG LAYER                          |      alpha blending source layer
             *       |                               |
             * SCR BG LAYER BACKGROUND COLOR        lowest  (This is not a layer!)
             */
            if (g_dm_scr_bg_cntx.layer_opacity != 255 && old_bg_opacity != g_dm_scr_bg_cntx.layer_opacity)
            {
                old_bg_opacity = g_dm_scr_bg_cntx.layer_opacity;
                if (!dm_is_fixed_layer_mode_enabled())   
                {             
                    gdi_layer_flatten(g_dm_scr_bg_cntx.layer_handle, 0, 0, 0);
                }

                /* disable opacity since the scr bg layer is already flattened */
                gdi_layer_set_opacity(FALSE, 255);
            }
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) && defined(__MMI_ALPHA_BLENDING__) */
        }

        if ((g_dm_data.s32flags & DM_SCR_BG_NO_CACHE))
        {
            /* do not cache scr_bg, this layer will be free after exiting screen */
            old_bg_filler = NULL;
        }
        
        gdi_layer_pop_and_restore_active();
        
        if (is_new_layer == 1)
        {
            /* set scr_bg layer to be the most buttom layer, and shift other layers */
            for (layer_idx = dm_layers_count ; layer_idx > 0 ; layer_idx--)
            {
                dm_layers[layer_idx ] = dm_layers[layer_idx - 1];
            }
            dm_layers[0] = g_dm_scr_bg_cntx.layer_handle;
            dm_layers_count++;
        }
        /* Once scr_bg is drawn, there is no need to redraw again, except the flag is turned on */
        g_dm_cntx.redraw_scr_bg_flag = MMI_FALSE;
    }

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
#endif 
    old_bg_opacity = g_dm_scr_bg_cntx.layer_opacity;
    return 1;
    
#else /* __GDI_MEMORY_PROFILE_2__ */ 

	#if defined(__MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__)
		gui_one_layer_draw_filled_bg_area_start();
	#endif /*__MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__*/  
    return 0;

#endif /* __GDI_MEMORY_PROFILE_2__ */ 

}   /* dm_setup_and_draw_scr_bg */
#else


/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_scr_bg
 * DESCRIPTION
 *  This function is used setup screen background layer and draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 dm_setup_and_draw_scr_bg(S16 **UICtrlAccessPtr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__)
		gui_one_layer_draw_filled_bg_area_start();
	#endif /*__MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__*/  
    return 0;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  dm_register_vkpad_callback
 * DESCRIPTION
 *  This function is to register dm_show_vkpad_callback
 * PARAMETERS
 *  f       [IN]        Function pointer to do changes before show virtual keypad.
 * RETURNS
 *  void
 *****************************************************************************/
void dm_register_vkpad_callback(FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_show_vkpad_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  dm_register_wallpaper_anim_before_blt_callback
 * DESCRIPTION
 *  Register the update callback function of the wallpaper animation.
 *  This is mainly for ALPHA BLENDING images.
 * PARAMETERS
 *  f       [IN]    Function pointer to be called before the wallpaper animation is blitted.
 * RETURNS
 *  void
 *****************************************************************************/
void dm_register_wallpaper_anim_update_callback(FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
    dm_wallpaper_anim_update_callback = f;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dummy_anim_before_blt_callback
 * DESCRIPTION
 *  Before blt callback function of the dummy wallpaper animation.
 * PARAMETERS
 *  ret       [IN]  Return code of gdi image draw
 * RETURNS
 *  void
 *****************************************************************************/
static void dummy_anim_before_blt_callback(GDI_RESULT return_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
/*****************************************************************************
 * FUNCTION
 *  dm_wallpaper_anim_before_blt_callback
 * DESCRIPTION
 *  Before blt callback function of the wallpaper animation.
 * PARAMETERS
 *  ret       [IN]  Return code of gdi image draw
 * RETURNS
 *  void
 *****************************************************************************/
static void dm_wallpaper_anim_before_blt_callback(GDI_RESULT return_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Lock the frame buffer to prevent dm_wallpaper_anim_update_callback() 
     * from bltting. Since the anim will blt the updated rect later, we do not 
     * and cannot not allow dm_wallpaper_anim_update_callback() to blt (will flicker).
     */
    gdi_layer_lock_frame_buffer();
    
    dm_wallpaper_anim_update_callback();
    
    gdi_layer_unlock_frame_buffer();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  dm_check_control_exist
 * DESCRIPTION
 *  This function is to register dm_show_vkpad_callback
 * PARAMETERS
 *  category_id     [IN]        
 *  control_id      [IN]        
 *  f(?)            [IN]        Function pointer to do changes before show virtual keypad.
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL dm_check_control_exist(S32 category_id, mmi_dm_control_ids_enum control_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *control_set = NULL;
    S16 *coorindate_set = NULL;
    S32 i, num_control = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_set = dm_search_control_set((U16) category_id, &coorindate_set);
    if (!control_set)
    {
        return MMI_FALSE;
    }

    num_control = (S32) control_set[0];

    for (i = 1; i <= num_control; i++)
    {
        if (control_set[i] == (U8) control_id)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dm_redraw_category_screen
 * DESCRIPTION
 *  This function is the actual Draw Manager, which is used by all categories to draw themselves.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_redraw_category_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 u8CtrlCt = 0;
    S32 u8NoOfUICtrls = 0;
    S16 *UICtrlAccessPtr_p = NULL, *DeafultCoordinateSet_p = NULL;
    dm_cat_scr_info_struct dm_cat_scr_info;
    wgui_status_icon_bar_enum idx = WGUI_STATUS_ICON_BAR_H_BAR;
    U8 *control_set_ptr = NULL;
    S32 string_count = 0, image_count = 0, back_fill_count = 0, rectangle_count = 0, line_count =
        0, slide_control_count = 0;
    S32 button_count = 0;
    S32 scroll_text_count = 0;
    S32 percentage_bar_count = 0;
#if (defined(__MMI_SEARCH_WEB__) || defined(__MMI_HIDD_SUPPORT__))
    S32 panel_count = 0;
#endif
    dm_redraw_state_enum redraw_type = NORMAL_EXIT;
#ifdef __MMI_SUBLCD__
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
#endif
    gdi_handle temp_layer_ptr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_WGUI_TRC_DM_REDRAW, g_dm_cntx.redraw_screen_main, g_dm_data.s32CatId);
    
#ifdef __MMI_SUBLCD__
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_WGUI_TRC_DM_SUB_STATUS, g_dm_cntx.redraw_screen_sub);
    if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        if (g_dm_cntx.lock_redraw_sub == MMI_TRUE)
        {
            return;
        }
        g_dm_cntx.lock_redraw_sub = MMI_TRUE;

        switch (g_dm_cntx.redraw_screen_sub)
        {
                /* from new screen */
            case NORMAL_SHOW:
                g_dm_cntx.redraw_screen_sub = NORMAL_REDRAW;
                redraw_type = NORMAL_REDRAW;
                break;

                /* from show categoryscreen without exit screen */
            case REDRAW_2_SHOW:
                MMI_ASSERT(0);
                break;

                /* from redraw screen */
            case REDRAW_2_REDRAW:
                redraw_type = REDRAW_2_REDRAW;
                break;

            case NORMAL_REDRAW:
                g_dm_cntx.redraw_screen_sub = REDRAW_2_REDRAW;
                redraw_type = REDRAW_2_REDRAW;
                break;
        }

    }
    else
#endif /* __MMI_SUBLCD__ */ 
    {
        if (g_dm_cntx.lock_redraw_main == MMI_TRUE)
        {
            return;
        }
        g_dm_cntx.lock_redraw_main = MMI_TRUE;

        switch (g_dm_cntx.redraw_screen_main)
        {
                /* from new screen */
            case NORMAL_SHOW:
                g_dm_cntx.redraw_screen_main = NORMAL_REDRAW;
                redraw_type = NORMAL_REDRAW;
                break;

                /* from show categoryscreen without exit screen */
            case REDRAW_2_SHOW:
                /*
                 * dm_reset_context();
                 * g_dm_cntx.redraw_screen_main = NORMAL_REDRAW;
                 * redraw_type=NORMAL_REDRAW;
                 */
                MMI_ASSERT(0);
                break;

                /* from redraw screen */
            case REDRAW_2_REDRAW:
                redraw_type = REDRAW_2_REDRAW;
                break;

            case NORMAL_REDRAW:
                g_dm_cntx.redraw_screen_main = REDRAW_2_REDRAW;
                redraw_type = REDRAW_2_REDRAW;
                break;
        }
    }

    /* setup the screen switch effect */
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    if(!(g_dm_data.s32flags & DM_SUB_LCD_CONTEXT))
    gui_screen_switch_effect_setup(g_dm_data.s32CatId, g_dm_data.s32flags, g_dm_cntx.redraw_screen_main);
#endif

    g_dm_cntx.is_context_reset = MMI_FALSE;

    memset((void*)&prev_control_coordinates, 0, sizeof(prev_control_coordinates));

    control_set_ptr = dm_search_control_set((U16) g_dm_data.s32CatId, &DeafultCoordinateSet_p);

    /* First element in Category-Controls map specifies the number of controls */
    u8NoOfUICtrls = control_set_ptr[0];

    UICtrlAccessPtr_p = dm_search_coordinate_set(g_dm_data.s32ScrId);
    if (UICtrlAccessPtr_p == NULL)
    {
        UICtrlAccessPtr_p = DeafultCoordinateSet_p;
    }

   /*************************************************************************
   If dm_search_coordinate_set returns NULL, then there must be Default Coordinate Set.
   *************************************************************************/
    MMI_ASSERT(UICtrlAccessPtr_p != NULL);

#ifdef __MMI_INTERACTIVE_PROFILNG__
#ifdef __MMI_SUBLCD__
    if (!(g_dm_data.s32flags & DM_SUB_LCD_CONTEXT))
#endif
    {
        mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_SCREEN);
    }
#endif /* __MMI_INTERACTIVE_PROFILNG__ */

    gdi_layer_lock_frame_buffer();

    /* Get category screen size */
    /* Some category screens size are not the same as lcd size */
    UICtrlAccessPtr_p = dm_get_cat_scr_coordinates(UICtrlAccessPtr_p, &dm_cat_scr_info);
    /* Set clip according to category screen size */

    /* Assume active layer is base layer for mainlcd or sublcd */
#ifdef __MMI_SUBLCD__
    if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        gdi_handle sub_handle;
        gdi_handle act_lcd_handle;
        gdi_lcd_get_active(&act_lcd_handle);
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_layer_get_base_handle(&sub_handle);
        gdi_lcd_set_active(act_lcd_handle);
        gdi_layer_set_active(sub_handle);
    }
    else
#endif /* __MMI_SUBLCD__ */ 
        gdi_layer_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    /* This might be an issue */

    gui_set_clip(dm_cat_scr_info.x1, dm_cat_scr_info.y1, dm_cat_scr_info.x2, dm_cat_scr_info.y2);
    gdi_layer_get_active(&temp_layer_ptr); 
    if (g_dm_data.s32flags & DM_CLEAR_SCREEN_BACKGROUND)
    {
    #ifdef GDI_USING_LAYER
        //gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_TRANSPARENT);
        gdi_2d_fill_rect_to_act_layer(
            temp_layer_ptr,
            0,
            0,
            UI_device_width,
            UI_device_height,
            255, 
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
            GDI_COLOR_BLACK,
#else
            GDI_COLOR_TRANSPARENT,
#endif
            0,
            NULL);
    #else
        //gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_WHITE);
        gdi_2d_fill_rect_to_act_layer(
            temp_layer_ptr,
            0,
            0,
            UI_device_width,
            UI_device_height,
            255, 
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
            GDI_COLOR_BLACK,
#else
            GDI_COLOR_WHITE,
#endif
            0,
            NULL);
    #endif
    }
    else if (g_dm_data.s32flags & DM_CLEAR_SCREEN_BACKGROUND_COLOR)
    {
        //gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_WHITE/*gdi_layer_get_background()*/);
        gdi_2d_fill_rect_to_act_layer(
            temp_layer_ptr,
            0,
            0,
            UI_device_width,
            UI_device_height,
            255, 
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
            GDI_COLOR_BLACK,
#else
            GDI_COLOR_WHITE,
#endif
            0,
            NULL);
    }

    mmi_frm_dss_defer_dump_string(MMI_FALSE);

#ifdef __MMI_SUBLCD__
    if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        gdi_lcd_get_active(&act_lcd);
        if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
        {
            UI_set_sub_LCD_graphics_context();
        }    
    #ifdef __MMI_SUBLCD_COLOR__
        if (!(g_dm_data.s32flags & DM_SUB_LCD_TRANSPARENT_BG))
        {
            wgui_status_icon_bar_show_sublcd_background(0, 0, (UI_device_width - 1), (UI_device_height - 1), MMI_FALSE);
        }
    #else /* __MMI_SUBLCD_COLOR__ */ 
        //gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_WHITE);
        gdi_layer_get_active(&temp_layer_ptr); 
        gdi_2d_fill_rect_to_act_layer(
            temp_layer_ptr,
            0,
            0,
            UI_device_width,
            UI_device_height,
            255, 
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
            GDI_COLOR_BLACK,
#else
            GDI_COLOR_WHITE,
#endif
            0,
            NULL);
    #endif /* __MMI_SUBLCD_COLOR__ */ 
    #if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (0) */ 
    }
#endif /* __MMI_SUBLCD__ */ 

    for (u8CtrlCt = 1; u8CtrlCt <= u8NoOfUICtrls; u8CtrlCt++)
    {
        switch (control_set_ptr[u8CtrlCt])
        {
            case DM_BASE_LAYER_START:
            {
                if (redraw_type != REDRAW_2_REDRAW)
                {
                    dm_setup_base_layer();
                }
                break;
            }

            case DM_NEW_LAYER_START:
            {
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
                dm_setup_new_layer(&UICtrlAccessPtr_p);
#else
				dm_coordinates dm_layer_info;
				UICtrlAccessPtr_p = dm_get_coordinates(UICtrlAccessPtr_p, &dm_layer_info);
#endif//
                break;
            }
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
            case DM_NEW_LAYER_END:  /* Just for Test, should be BASE_CONTROL_SET */
            {
                break;
            }
#endif            
            case DM_SCR_BG:
            {
                /* 070505 Calvin Start */
            #ifdef __MMI_WALLPAPER_ON_BOTTOM__
                dm_setup_and_draw_scr_bg(&UICtrlAccessPtr_p);
            #endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 
                break;
                /* 070505 Calvin Start */
            }

        #if ENABLE_CIRCULAR_3D_MENU                        
            case DM_CIRCULAR_MENU1:
            {
                dm_setup_and_draw_circular_menu(&UICtrlAccessPtr_p);
                break;
            }
        #endif /* ENABLE_CIRCULAR_3D_MENU */
        
            case DM_LIST1:
            {
                dm_setup_and_draw_fixed_list(&UICtrlAccessPtr_p);
                break;
            }
            case DM_DYNAMIC_LIST1:
            {
                dm_setup_and_draw_dynamic_list(&UICtrlAccessPtr_p);
                break;
            }
#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
            case DM_DYNAMIC_MATRIX1:
            {
                dm_setup_and_draw_dynamic_matrix(&UICtrlAccessPtr_p);
                break;
            }
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
            case DM_ASYNCDYNAMIC_LIST1:
            {
                dm_setup_and_draw_asyncdynamic_list(&UICtrlAccessPtr_p);
                break;
            }
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__       
            case DM_ASYNCDYNAMIC_MATRIX1:
            {
                dm_setup_and_draw_asyncdynamic_matrix(&UICtrlAccessPtr_p);
                break;
            }
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */            
            case DM_MATRIX_MENU1:
            {
                dm_setup_and_draw_matrix_menu(&UICtrlAccessPtr_p);
                break;
            }
            case DM_MULTILINE_INPUTBOX1:
            {
                dm_setup_and_draw_multiline_inputbox(&UICtrlAccessPtr_p, &dm_cat_scr_info);
                break;
            }
#ifdef UI_EMS_SUPPORT
            case DM_EMS_INPUTBOX1:
            {
                dm_setup_and_draw_ems_inputbox(&UICtrlAccessPtr_p, &dm_cat_scr_info);
                break;
            }
#endif /* UI_EMS_SUPPORT */
#ifdef __MMI_EDITOR_DIALER_SUPPORT__
            case DM_DIALER_INPUT_BOX1:
            {
                dm_setup_and_draw_dialer_inputbox(&UICtrlAccessPtr_p);
                break;
            }
#endif
#if 1//def __MMI_EDITOR_SINGLINE_SUPPORT__
            case DM_SINGLELINE_INPUTBOX1:
            {
                dm_setup_and_draw_singleline_inputbox(&UICtrlAccessPtr_p);
                break;
            }
#endif
            case DM_LSK:
            case DM_RSK:
            {
                dm_setup_and_draw_softkey(control_set_ptr[u8CtrlCt], &UICtrlAccessPtr_p);
                break;
            }
            case DM_BUTTON:
            {
                dm_setup_and_draw_button(&UICtrlAccessPtr_p, button_count++);
                break;
            }
            case DM_TITLE1:
            {
                dm_setup_and_draw_title(&UICtrlAccessPtr_p);
                break;
            }
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
            case DM_HORIZONTAL_TAB_BAR:
            {
                dm_setup_and_draw_horizontal_tab_bar(&UICtrlAccessPtr_p);
                break;
            }
#endif
            case DM_CATEGORY_CONTROLLED_AREA:
            {
                dm_setup_and_draw_category_controlled_area(&UICtrlAccessPtr_p);
                break;
            }
            case DM_CATEGORY_CONTROLLED_AREA2:
            {
                dm_setup_and_draw_category_controlled_area2(&UICtrlAccessPtr_p);
                break;
            }
            case DM_STATUS_BAR1:
            {
                dm_setup_and_draw_status_icons(&UICtrlAccessPtr_p);
                break;
            }
            case DM_BUTTON_BAR1:
            {
                dm_setup_and_draw_button_bar(&UICtrlAccessPtr_p);
                break;
            }
            case DM_INLINE_FIXED_LIST1:
            {
                dm_setup_and_draw_inline_item(&UICtrlAccessPtr_p);
                break;
            }
            case DM_BASE_CONTROL_SET1:
            {
                dm_setup_and_draw_base_control_set(&UICtrlAccessPtr_p);
                break;
            }
            case DM_BASE_CONTROL_SET2:
            {
                dm_setup_and_draw_base_control_set2(&UICtrlAccessPtr_p);
                break;
            }
            case DM_BASE_CONTROL_SET_SUBMENU:
            {
                dm_setup_and_draw_base_control_set_submenu(&UICtrlAccessPtr_p);
                break;
            }
            case DM_BASE_CONTROL_SET_COMMON:
            {
                dm_setup_and_draw_base_control_set_common(&UICtrlAccessPtr_p);
                break;
            }
            case DM_STRING:
            {
                dm_setup_and_draw_string(&UICtrlAccessPtr_p, string_count++);
                break;
            }
            case DM_IMAGE:
            {
                dm_setup_and_draw_image(&UICtrlAccessPtr_p, image_count++);
                break;
            }
            case DM_ALIGNED_AREA_START:
            {
                dm_aligned_area_data.is_in_aligned_area = MMI_TRUE;
                dm_setup_and_draw_aligned_area(&UICtrlAccessPtr_p, control_set_ptr);
                break;
            }
            case DM_ALIGNED_AREA_END:
            {
                memset(&dm_aligned_area_data, 0, sizeof(dm_aligned_area_data));
                dm_aligned_area_data.is_in_aligned_area = MMI_FALSE;
                break;
            }
            case DM_DATE_TIME_DISPLAY:
            {
            #ifdef __MMI_SUBLCD__
                if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
                    if (redraw_type == REDRAW_2_REDRAW)
                    {
                        update_sublcd_dt_display();
                    }
                    else
                    {
                        show_sub_LCD_dt_display();
                    }
                else
            #endif /* __MMI_SUBLCD__ */ 
                if (redraw_type == REDRAW_2_REDRAW)
                {
                    update_mainlcd_dt_display();
                }
                else
                {
                    show_main_LCD_dt_display();
                }
                break;
            }
            case DM_BACK_FILL_AREA:
            {
                dm_setup_and_draw_back_fill_area(&UICtrlAccessPtr_p, back_fill_count++);
                break;
            }
            case DM_RECTANGLE:
            {
                dm_setup_and_draw_rectangle(&UICtrlAccessPtr_p, rectangle_count++);
                break;
            }
            case DM_LINE:
            {
                dm_setup_and_draw_line(&UICtrlAccessPtr_p, line_count++);
                break;
            }
            case DM_SLIDE_CONTROL:
            {
                dm_setup_and_draw_slide_control(&UICtrlAccessPtr_p, slide_control_count++);
                break;
            }
            case DM_POPUP_BACKGROUND:
            {
                dm_setup_and_draw_popup_background(&UICtrlAccessPtr_p);
                break;
            }
#ifdef __MMI_STOPWATCH__
            case DM_TYPICAL_STOPWATCH:
            {
                dm_setup_and_draw_typical_stopwatch(&UICtrlAccessPtr_p);
                break;
            }
            case DM_NWAY_STOPWATCH:
            {
                dm_setup_and_draw_nway_stopwatch(&UICtrlAccessPtr_p);
                break;
            }
#endif
#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
            case DM_WALL_PAPER:
            {
                dm_setup_and_draw_wallpaper(&UICtrlAccessPtr_p);
                break;
            }
#endif
            case DM_SCROLL_TEXT:
            {
                dm_setup_and_draw_scroll_text(&UICtrlAccessPtr_p, scroll_text_count++);
                break;
            }
            case DM_PERCENTAGE_BAR:
            {
                dm_setup_and_draw_percentage_bar(&UICtrlAccessPtr_p, percentage_bar_count++);
                break;
            }
#if (defined(__MMI_SEARCH_WEB__) || defined(__MMI_HIDD_SUPPORT__))
            case DM_PANEL:
            {
                dm_setup_and_draw_panel(&UICtrlAccessPtr_p, panel_count++);
                break;
            }
#endif

#ifdef __MMI_CALENDAR__ 
            case DM_CALENDAR:
            {
                dm_setup_and_draw_calendar(&UICtrlAccessPtr_p);
                break;
            }
#endif
        }
    }
#ifndef __GDI_MEMORY_PROFILE_2__
    new_layer_x = 0;
    new_layer_y = 0;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* if virtual keypad show flag is set, show the virtual keypad */
    if (g_dm_data.s32flags & DM_SHOW_VKPAD)
    {
        if (dm_show_vkpad_callback != NULL)
        {
            dm_show_vkpad_callback();
        }
        /* wgui_show_virtual_keyboard(); */
    }
#ifdef __MMI_SUBLCD__
    if (g_dm_data.s32flags & DM_SUB_LCD_CONTEXT)
    {
        if (g_dm_data.s32flags & DM_SUB_LCD_ROTATE_180)
        {
            gui_rotate_180_sublcd();
        }

        gdi_layer_unlock_frame_buffer();
        if (!(g_dm_data.s32flags & DM_NO_BLT))
        {
            gdi_layer_blt(
                dm_layers_sub[0],
                dm_layers_sub[1],
                dm_layers_sub[2],
                dm_layers_sub[3],
                dm_cat_scr_info.x1,
                dm_cat_scr_info.y1,
                dm_cat_scr_info.x2,
                dm_cat_scr_info.y2);
        }
        else
        {
            gdi_layer_set_blt_layer(dm_layers_sub[0], dm_layers_sub[1], dm_layers_sub[2], dm_layers_sub[3]);
        }
        
        if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
        {
            UI_set_main_LCD_graphics_context();
        }
        
        g_dm_cntx.lock_redraw_sub = MMI_FALSE;
        return;
    }
#endif /* __MMI_SUBLCD__ */ 
    if (!(g_dm_data.s32flags & DM_SET_NEW_LAYER_ACTIVE))
    {
        /* New layer is top layer, common_control_set has drawn on this layer, so do not set base layer to active. */
        gdi_layer_restore_base_active();
    }

    gdi_layer_unlock_frame_buffer();

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
    if (!(g_dm_data.s32flags & DM_NO_BLT))
    {
        /* if scr_bg not exist, then dm_layers[0] will not be blt, modified for lazy free */
        if (g_dm_scr_bg_cntx.scr_bg_layer_exist == MMI_TRUE || 
            on_idle_screen == 1 || 
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
            (g_dm_scr_bg_cntx.scr_bg_layer_exist == MMI_FALSE && 
                on_idle_screen == 0 && 
                dm_layers[0] != g_dm_scr_bg_cntx.layer_handle)
#else
            (g_dm_scr_bg_cntx.scr_bg_layer_exist == MMI_FALSE && 
                on_idle_screen == 0 && 
                dm_layers[0] != g_dm_scr_bg_cntx.layer_handle && 
                dm_wallpaper_layer_idx != 0)
#endif
            )
        {
            gdi_layer_blt(
                dm_layers[0],
                dm_layers[1],
                dm_layers[2],
                dm_layers[3],
                dm_cat_scr_info.x1,
                dm_cat_scr_info.y1,
                dm_cat_scr_info.x2 - dm_cat_scr_info.x1 - 1,
                dm_cat_scr_info.y2 - dm_cat_scr_info.y1 - 1);
            
        }
        else
        {
            gdi_layer_blt(
                dm_layers[1],
                dm_layers[2],
                dm_layers[3],
                GDI_ERROR_HANDLE,
                dm_cat_scr_info.x1,
                dm_cat_scr_info.y1,
                dm_cat_scr_info.x2 - dm_cat_scr_info.x1 - 1,
                dm_cat_scr_info.y2 - dm_cat_scr_info.y1 - 1);
        }
    }
    else
    {
        /* if scr_bg not exist, then dm_layers[0] will not be blt, modified for lazy free */
        if (g_dm_scr_bg_cntx.scr_bg_layer_exist == MMI_TRUE || 
                on_idle_screen == 1 || 
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
                (g_dm_scr_bg_cntx.scr_bg_layer_exist == MMI_FALSE && 
                    on_idle_screen == 0 && 
                    dm_layers[0] != g_dm_scr_bg_cntx.layer_handle)
#else
                (g_dm_scr_bg_cntx.scr_bg_layer_exist == MMI_FALSE && 
                    on_idle_screen == 0 && 
                    dm_layers[0] != g_dm_scr_bg_cntx.layer_handle && 
                    dm_wallpaper_layer_idx != 0)
#endif
            )
        {
            gdi_layer_set_blt_layer(dm_layers[0], dm_layers[1], dm_layers[2], dm_layers[3]);
        }
        else
        {
            gdi_layer_set_blt_layer(dm_layers[1], dm_layers[2], dm_layers[3], GDI_ERROR_HANDLE);
        }
    }
#else
    if (!(g_dm_data.s32flags & DM_NO_BLT))
    {
        if (1)
        {
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);//Sidd
        }
    }
 #endif
    /* 061506 double buffer Start */
    for (idx = WGUI_STATUS_ICON_BAR_H_BAR; idx < WGUI_STATUS_ICON_BAR_TOTAL_BAR; idx++)
    {
        if(wgui_status_icon_bar_whether_double_buffer(idx))
        {
            gdi_layer_push_and_set_active((gdi_handle)wgui_status_icon_bar_get_target_layer(idx));
            gdi_layer_toggle_double();
            gdi_layer_copy_double();//070306 copy double
            gdi_layer_pop_and_restore_active();
        }
    }
    /* 061506 double buffer Start */

    mmi_frm_dss_defer_dump_string(MMI_TRUE);

    g_dm_cntx.lock_redraw_main = (U8)MMI_FALSE;

    /* run screen switch effect */
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_screen_switch_effect_run();
#endif

#ifdef __MMI_INTERACTIVE_PROFILNG__
#ifdef __MMI_SUBLCD__
    if (!(g_dm_data.s32flags & DM_SUB_LCD_CONTEXT))
#endif
    {
        mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_SCREEN);
    }
#endif /* __MMI_INTERACTIVE_PROFILNG__ */
    
#ifndef __MTK_TARGET__    
    /* notify MTE there is a screen switch */
    mmi_mte_mmi_notify_screen_switch();
#endif /* __MTK_TARGET__ */
}   /* end of dm_redraw_category_screen */


/* Get Coordinate Set for different components */
/*****************************************************************************
 * FUNCTION
 *  dm_get_coordinates
 * DESCRIPTION
 *  To get coordinates for any control.
 * PARAMETERS
 *  UICtrlAccessPtr_p       [?]     
 *  dm_coordinate_info      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S16 *dm_get_coordinates(S16 *UICtrlAccessPtr_p, dm_coordinates *dm_coordinate_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tool_bar_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        tool_bar_height = MMI_ICON_BAR_HEIGHT;
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    if (*UICtrlAccessPtr_p == DM_DUMMY_COORDINATE)
    {
        dm_coordinate_info->s16X = 0;
        dm_coordinate_info->s16Y = 0;
        dm_coordinate_info->s16Width = 0;
        dm_coordinate_info->s16Height = 0;
        dm_coordinate_info->Flags = DM_NO_FLAGS;
        UICtrlAccessPtr_p++;
    }
    else if (*UICtrlAccessPtr_p == DM_NULL_COORDINATE)
    {
        dm_coordinate_info->s16X = -1;
        dm_coordinate_info->s16Y = -1;
        dm_coordinate_info->s16Width = -1;
        dm_coordinate_info->s16Height = -1;
        dm_coordinate_info->Flags = DM_NO_FLAGS;
        UICtrlAccessPtr_p++;
    }
    else if (*UICtrlAccessPtr_p == DM_FULL_SCREEN_COORDINATE_FLAG || *UICtrlAccessPtr_p == DM_FULL_SCREEN_COORDINATE)
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            dm_coordinate_info->s16X = 0;
            dm_coordinate_info->s16Y = 0;
            dm_coordinate_info->s16Width = MMI_ROTATED_LCD_WIDTH;
            dm_coordinate_info->s16Height = MMI_ROTATED_LCD_HEIGHT;
        }
        else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
        {
            dm_coordinate_info->s16X = 0;
            dm_coordinate_info->s16Y = 0;
            dm_coordinate_info->s16Width = MAIN_LCD_DEVICE_WIDTH;
            dm_coordinate_info->s16Height = MAIN_LCD_DEVICE_HEIGHT;
        }

        if (*UICtrlAccessPtr_p == DM_FULL_SCREEN_COORDINATE_FLAG)
        {
            dm_coordinate_info->Flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        }

        UICtrlAccessPtr_p++;
    }
    else if (*UICtrlAccessPtr_p == DM_CONTENT_COORDINATE_FLAG || *UICtrlAccessPtr_p == DM_CONTENT_COORDINATE)
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            dm_coordinate_info->s16X = MMI_ROTATED_CONTENT_X;
            dm_coordinate_info->s16Y = MMI_ROTATED_CONTENT_Y;
            dm_coordinate_info->s16Width = MMI_ROTATED_CONTENT_WIDTH;
            dm_coordinate_info->s16Height = MMI_ROTATED_CONTENT_HEIGHT;
        }
        else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
        {
            dm_coordinate_info->s16X = MMI_CONTENT_X;
            dm_coordinate_info->s16Y = MMI_CONTENT_Y;
            dm_coordinate_info->s16Width = MMI_CONTENT_WIDTH;
            dm_coordinate_info->s16Height = MMI_CONTENT_HEIGHT - tool_bar_height;
        }

        if (*UICtrlAccessPtr_p == DM_CONTENT_COORDINATE_FLAG)
        {
            dm_coordinate_info->Flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        }
        UICtrlAccessPtr_p++;
    }
    else if (*UICtrlAccessPtr_p == DM_SUBMENU_CONTENT_COORDINATE_FLAG || *UICtrlAccessPtr_p == DM_SUBMENU_CONTENT_COORDINATE)
    {
#ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            dm_coordinate_info->s16X = MMI_ROTATED_CONTENT_X;
            dm_coordinate_info->s16Y = MMI_ROTATED_CONTENT_Y;
            dm_coordinate_info->s16Width = MMI_ROTATED_CONTENT_WIDTH;
            dm_coordinate_info->s16Height = MMI_ROTATED_CONTENT_HEIGHT;
        }
        else
#endif /* __MMI_SCREEN_ROTATE__ */ 
        {
            dm_coordinate_info->s16X = MMI_SUBMENU_CONTENT_X;
            dm_coordinate_info->s16Y = MMI_SUBMENU_CONTENT_Y;
            dm_coordinate_info->s16Width = MMI_SUBMENU_CONTENT_WIDTH;
#if defined(__MMI_WEARABLE_DEVICE__) && (defined(__MMI_MAINLCD_240X240__)||defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_320X320__))
		if (g_dm_data.s32flags & DM_SHOW_SWATCH_SOFTKEY)
			 dm_coordinate_info->s16Height = MMI_SUBMENU_CONTENT_HEIGHT - MMI_SW_BUTTON_BAR_HEIGHT -1 - tool_bar_height;
		else
#endif /*__MMI_WEARABLE_DEVICE__*/
            dm_coordinate_info->s16Height = MMI_SUBMENU_CONTENT_HEIGHT - tool_bar_height;
        }

        if (*UICtrlAccessPtr_p == DM_SUBMENU_CONTENT_COORDINATE_FLAG)
        {
            dm_coordinate_info->Flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        }
        UICtrlAccessPtr_p++;
    }
    else if (*UICtrlAccessPtr_p == DM_COMMON_CONTENT_COORDINATE_FLAG || *UICtrlAccessPtr_p == DM_COMMON_CONTENT_COORDINATE)
    {
#ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            dm_coordinate_info->s16X = MMI_ROTATED_CONTENT_X;
            dm_coordinate_info->s16Y = MMI_ROTATED_CONTENT_Y;
            dm_coordinate_info->s16Width = MMI_ROTATED_CONTENT_WIDTH;
            dm_coordinate_info->s16Height = MMI_ROTATED_CONTENT_HEIGHT;
        }
        else
#endif /* __MMI_SCREEN_ROTATE__ */ 
        {
            dm_coordinate_info->s16X = MMI_COMMON_CONTENT_X;
            dm_coordinate_info->s16Y = MMI_COMMON_CONTENT_Y;
            dm_coordinate_info->s16Width = MMI_COMMON_CONTENT_WIDTH;
            dm_coordinate_info->s16Height = MMI_COMMON_CONTENT_HEIGHT - tool_bar_height;
        }

        if (*UICtrlAccessPtr_p == DM_COMMON_CONTENT_COORDINATE_FLAG)
        {
            dm_coordinate_info->Flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        }
        UICtrlAccessPtr_p++;
    }
    else if (*UICtrlAccessPtr_p == DM_EDITOR_CONTENT_COORDINATE_FLAG || *UICtrlAccessPtr_p == DM_EDITOR_CONTENT_COORDINATE)
    {
#ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            dm_coordinate_info->s16X = MMI_ROTATED_CONTENT_X;
            dm_coordinate_info->s16Y = MMI_ROTATED_CONTENT_Y;
            dm_coordinate_info->s16Width = MMI_ROTATED_CONTENT_WIDTH;
            dm_coordinate_info->s16Height = MMI_ROTATED_CONTENT_HEIGHT;
        }
        else
#endif /* __MMI_SCREEN_ROTATE__ */ 
        {
#if !defined(GUI_EDITOR_SHOW_TITLE)
            dm_coordinate_info->s16X = MMI_COMMON_CONTENT_X;
            dm_coordinate_info->s16Y = MMI_COMMON_CONTENT_Y - MMI_COMMON_TITLE_HEIGHT;
            dm_coordinate_info->s16Width = MMI_COMMON_CONTENT_WIDTH;
            dm_coordinate_info->s16Height = MMI_COMMON_CONTENT_HEIGHT + MMI_COMMON_TITLE_HEIGHT - tool_bar_height;
#else
            dm_coordinate_info->s16X = MMI_COMMON_CONTENT_X;
            dm_coordinate_info->s16Y = MMI_COMMON_CONTENT_Y;
            dm_coordinate_info->s16Width = MMI_COMMON_CONTENT_WIDTH;
            dm_coordinate_info->s16Height = MMI_COMMON_CONTENT_HEIGHT - tool_bar_height;
#endif  
        }

        if (*UICtrlAccessPtr_p == DM_EDITOR_CONTENT_COORDINATE_FLAG)
        {
            dm_coordinate_info->Flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        }
        UICtrlAccessPtr_p++;
    }
    else if (*UICtrlAccessPtr_p == DM_POPUP_SCREEN_COORDINATE_FLAG || *UICtrlAccessPtr_p == DM_POPUP_SCREEN_COORDINATE)
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            /* modify: "DisplayPopup screen" is consistent with "DisplayConfirm screen" when rotated. [07.40]*/
            dm_coordinate_info->s16X = MMI_ROTATED_POP_UP_DIALOG_X;
            dm_coordinate_info->s16Y = MMI_ROTATED_POP_UP_DIALOG_Y;
            dm_coordinate_info->s16Width = MMI_ROTATED_POP_UP_DIALOG_WIDTH;
            dm_coordinate_info->s16Height = MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT;            
        }
        else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
        {
            dm_coordinate_info->s16X = MMI_POP_UP_DIALOG_X;
            dm_coordinate_info->s16Y = MMI_POP_UP_DIALOG_Y;
            dm_coordinate_info->s16Width = MMI_POP_UP_DIALOG_WIDTH;
            dm_coordinate_info->s16Height = MMI_POP_UP_DIALOG_FULL_HEIGHT;
        }

        if (*UICtrlAccessPtr_p == DM_POPUP_SCREEN_COORDINATE_FLAG)
        {
            dm_coordinate_info->Flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        }
        UICtrlAccessPtr_p++;
    }
    else if (*UICtrlAccessPtr_p == DM_DEFAULT_TITLE_BAR_FLAG || *UICtrlAccessPtr_p == DM_DEFAULT_TITLE_BAR)
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            dm_coordinate_info->s16X = MMI_ROTATED_TITLE_X;
            dm_coordinate_info->s16Y = MMI_ROTATED_TITLE_Y;
            dm_coordinate_info->s16Width = MMI_ROTATED_TITLE_WIDTH;
            dm_coordinate_info->s16Height = MMI_ROTATED_TITLE_HEIGHT;
        }
        else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
        {
            dm_coordinate_info->s16X = MMI_TITLE_X;
            dm_coordinate_info->s16Y = MMI_TITLE_Y;
            dm_coordinate_info->s16Width = MMI_TITLE_WIDTH;
            dm_coordinate_info->s16Height = MMI_TITLE_HEIGHT;
        }

        if (*UICtrlAccessPtr_p == DM_DEFAULT_TITLE_BAR_FLAG)
        {
            dm_coordinate_info->Flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        }

        UICtrlAccessPtr_p++;
    }
    else if (*UICtrlAccessPtr_p == DM_DEFAULT_BUTTON_BAR_FLAG || *UICtrlAccessPtr_p == DM_DEFAULT_BUTTON_BAR)
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            dm_coordinate_info->s16X = MMI_ROTATED_BUTTON_BAR_X;
            dm_coordinate_info->s16Y = MMI_ROTATED_BUTTON_BAR_Y;
            dm_coordinate_info->s16Width = MMI_ROTATED_BUTTON_BAR_WIDTH;
            dm_coordinate_info->s16Height = MMI_ROTATED_BUTTON_BAR_HEIGHT;
        }
        else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
        {
            dm_coordinate_info->s16X = 0;
            dm_coordinate_info->s16Width = MAIN_LCD_DEVICE_WIDTH;
			#if defined(__MMI_WEARABLE_DEVICE__) && (defined(__MMI_MAINLCD_240X240__)||defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_320X320__))
			if (g_dm_data.s32flags & DM_SHOW_SWATCH_SOFTKEY)
			{
				dm_coordinate_info->s16Y = MAIN_LCD_DEVICE_HEIGHT - MMI_SW_BUTTON_BAR_HEIGHT - tool_bar_height;
				dm_coordinate_info->s16Height = MMI_SW_BUTTON_BAR_HEIGHT + tool_bar_height;
			}
			else
			#endif /*__MMI_WEARABLE_DEVICE__*/
			{
				dm_coordinate_info->s16Y = MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - tool_bar_height;
				dm_coordinate_info->s16Height = MMI_BUTTON_BAR_HEIGHT + tool_bar_height;
			}
        }

        if (*UICtrlAccessPtr_p == DM_DEFAULT_BUTTON_BAR_FLAG)
        {
            dm_coordinate_info->Flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        }
        UICtrlAccessPtr_p++;
    }
    else if (*UICtrlAccessPtr_p == DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG || *UICtrlAccessPtr_p == DM_DEFAULT_TITLE_LEFT_BUTTON)
    {
        dm_coordinate_info->s16X = MMI_TITLEBAR_BUTTON_GAP;
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
        dm_coordinate_info->s16Y = (MMI_STATUS_BAR_HEIGHT) + (MMI_COMMON_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1);
#else
        dm_coordinate_info->s16Y = (MMI_COMMON_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1);
#endif
        dm_coordinate_info->s16Width = MMI_TITLEBAR_BUTTON_WIDTH;
        dm_coordinate_info->s16Height = MMI_TITLEBAR_BUTTON_HEIGHT;

        if (*UICtrlAccessPtr_p == DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG)
        {
            dm_coordinate_info->Flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        }
        UICtrlAccessPtr_p++;        
    }
    else if (*UICtrlAccessPtr_p == DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG || *UICtrlAccessPtr_p == DM_DEFAULT_TITLE_RIGHT_BUTTON)
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            dm_coordinate_info->s16X = (MMI_ROTATED_LCD_WIDTH) - (MMI_TITLEBAR_BUTTON_GAP) - (MMI_TITLEBAR_BUTTON_WIDTH);
        #if defined(GUI_COMMON_SHOW_STATUS_ICON)
            dm_coordinate_info->s16Y = (MMI_STATUS_BAR_HEIGHT) + (MMI_COMMON_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1);
        #else
            dm_coordinate_info->s16Y = (MMI_COMMON_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1);
        #endif
            dm_coordinate_info->s16Width = MMI_TITLEBAR_BUTTON_WIDTH;
            dm_coordinate_info->s16Height = MMI_TITLEBAR_BUTTON_HEIGHT;
        }
        else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
        {
            dm_coordinate_info->s16X = (MAIN_LCD_DEVICE_WIDTH) - (MMI_TITLEBAR_BUTTON_GAP) - (MMI_TITLEBAR_BUTTON_WIDTH);
        #if defined(GUI_COMMON_SHOW_STATUS_ICON)
            dm_coordinate_info->s16Y = (MMI_STATUS_BAR_HEIGHT) + (MMI_COMMON_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1);
        #else
            dm_coordinate_info->s16Y = (MMI_COMMON_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1);
        #endif
            dm_coordinate_info->s16Width = MMI_TITLEBAR_BUTTON_WIDTH;
            dm_coordinate_info->s16Height = MMI_TITLEBAR_BUTTON_HEIGHT;
        }

        if (*UICtrlAccessPtr_p == DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG)
        {
            dm_coordinate_info->Flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        }
        UICtrlAccessPtr_p++;        
    }        
    else
    {
        dm_coordinate_info->s16X = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_coordinate_info->s16Y = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_coordinate_info->s16Width = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_coordinate_info->s16Height = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_coordinate_info->Flags = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;
    }

    if (dm_coordinate_info->Flags & DM_PREVIOUS_CONTROL_END_X)
    {
        dm_coordinate_info->s16X = prev_control_coordinates.s16X2 + dm_coordinate_info->s16X;
    }
    else if (dm_coordinate_info->Flags & DM_PREVIOUS_CONTROL_END_X_OFFSET_WIDTH)
    {
        dm_coordinate_info->s16X = prev_control_coordinates.s16X2 - dm_coordinate_info->s16Width;
    }
#ifndef __GDI_MEMORY_PROFILE_2__
    else
    {
        if (new_layer_x != 0)
        {
            dm_coordinate_info->s16X += new_layer_x;
        }
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    if (dm_coordinate_info->Flags & DM_PREVIOUS_CONTROL_END_Y)
    {
        dm_coordinate_info->s16Y = prev_control_coordinates.s16Y2 + dm_coordinate_info->s16Y;
    }
    else if (dm_coordinate_info->Flags & DM_PREVIOUS_CONTROL_END_Y_OFFSET_HEIGHT)
    {
        dm_coordinate_info->s16Y = prev_control_coordinates.s16Y2 - dm_coordinate_info->s16Height;
    }
#ifndef __GDI_MEMORY_PROFILE_2__
    else
    {
        if (new_layer_y != 0)
        {
            dm_coordinate_info->s16Y += new_layer_y;
        }
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    if (dm_coordinate_info->Flags & DM_WIDTH_OFFSET_PREVIOUS_CONTROL_END_X)
    {
        dm_coordinate_info->s16Width -= (prev_control_coordinates.s16X2 + 1);
    }
    if (dm_coordinate_info->Flags & DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y)
    {
        dm_coordinate_info->s16Height -= (prev_control_coordinates.s16Y2 + 1);
    }
    if (dm_coordinate_info->Flags & DM_HEIGHT_PREVIOUS_CONTROL_HEIGHT)
    {
        dm_coordinate_info->s16Height = prev_control_coordinates.coordinate.s16Height;
    }
    if (dm_coordinate_info->Flags & DM_WIDTH_PREVIOUS_CONTROL_WIDTH)
    {
        dm_coordinate_info->s16Width = prev_control_coordinates.coordinate.s16Width;
    }

    setup_previous_control(dm_coordinate_info);

    return UICtrlAccessPtr_p;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_cat_scr_coordinates
 * DESCRIPTION
 *  This function is used obtain the category screen coordinates
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_cat_scr_info         [IN/OUT]        Category screen coordinate info.
 * RETURNS
 *  void
 *****************************************************************************/
S16 *dm_get_cat_scr_coordinates(S16 *UICtrlAccessPtr_p, dm_cat_scr_info_struct *dm_cat_scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if full screen display */
    if ((*UICtrlAccessPtr_p == DM_FULL_SCREEN_COORDINATE_FLAG) || (*UICtrlAccessPtr_p == DM_FULL_SCREEN_COORDINATE))
    {
        dm_cat_scr_info->x1 = 0;
        dm_cat_scr_info->y1 = 0;
        dm_cat_scr_info->x2 = UI_device_width;
        dm_cat_scr_info->y2 = UI_device_height;

        if (*UICtrlAccessPtr_p == DM_FULL_SCREEN_COORDINATE_FLAG)
        {
            dm_cat_scr_info->flags = DM_NO_FLAGS;
            UICtrlAccessPtr_p++;
            return UICtrlAccessPtr_p;
        }
        UICtrlAccessPtr_p++;
    }
    else
    {
        dm_cat_scr_info->x1 = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_cat_scr_info->y1 = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_cat_scr_info->x2 = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_cat_scr_info->y2 = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;
    }

    dm_cat_scr_info->flags = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    return UICtrlAccessPtr_p;
}   /* end of dm_get_cat_scr_coordinates */


/*****************************************************************************
 * FUNCTION
 *  dm_get_status_icon_bar_coordinates
 * DESCRIPTION
 *  This function is used obtain the status icon bar coordinates.
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_status_info          [IN/OUT]        Status bar coordinate info.
 * RETURNS
 *  void
 *****************************************************************************/
S16 *dm_get_status_icon_bar_coordinates(S16 *UICtrlAccessPtr_p, dm_status_info_struct *dm_status_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*UICtrlAccessPtr_p == DM_DEFAULT_STATUS_BAR_FLAG || *UICtrlAccessPtr_p == DM_DEFAULT_STATUS_BAR)
    {
        /* status bar is not suported in rotated screen */
        dm_status_info->x = 0;
        dm_status_info->y = 0;
        dm_status_info->x1 = 0;
        dm_status_info->y1 = 0;
        dm_status_info->x2 = MAIN_LCD_DEVICE_WIDTH;
        dm_status_info->y2 = MMI_STATUS_BAR_HEIGHT;
        if (*UICtrlAccessPtr_p == DM_DEFAULT_STATUS_BAR_FLAG)
        {
            dm_status_info->flags = DM_NO_FLAGS;
        }
        else
        {
            UICtrlAccessPtr_p++;
            dm_status_info->flags = *UICtrlAccessPtr_p;
        }

        UICtrlAccessPtr_p++;
    }
    else
    {
        dm_status_info->x = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_status_info->y = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_status_info->x1 = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_status_info->y1 = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_status_info->x2 = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_status_info->y2 = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;

        dm_status_info->flags = *UICtrlAccessPtr_p;
        UICtrlAccessPtr_p++;
    }

    return UICtrlAccessPtr_p;
}   /* end of dm_get_status_icon_bar_coordinates */


/*****************************************************************************
 * FUNCTION
 *  dm_get_button_bar_coordinates
 * DESCRIPTION
 *  This function is used obtain the button bar coordinates.
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_buttonbar_info       [IN/OUT]        Button bar coordinate info.
 * RETURNS
 *  void
 *****************************************************************************/
S16 *dm_get_button_bar_coordinates(S16 *UICtrlAccessPtr_p, dm_buttonbar_info_struct *dm_buttonbar_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UICtrlAccessPtr_p = dm_get_coordinates(UICtrlAccessPtr_p, &dm_buttonbar_info->coordinate);

    dm_buttonbar_info->button_width = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;
    return UICtrlAccessPtr_p;
}   /* end of dm_get_button_bar_coordinates */


#ifdef __MMI_STOPWATCH__
/*****************************************************************************
 * FUNCTION
 *  dm_get_typical_stopwatch_coordinates
 * DESCRIPTION
 *  This function is used obtain the typical stopwatch control coordinates.
 * PARAMETERS
 *  UICtrlAccessPtr_p               [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_typical_stopwatch_info       [?]             
 *  dm_calendar_info(?)             [IN/OUT]        Calendar control coordinate info.
 * RETURNS
 *  void
 *****************************************************************************/
S16 *dm_get_typical_stopwatch_coordinates(
        S16 *UICtrlAccessPtr_p,
        dm_typical_stopwatch_info_struct *dm_typical_stopwatch_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UICtrlAccessPtr_p = dm_get_coordinates(UICtrlAccessPtr_p, &dm_typical_stopwatch_info->coordinate);

    dm_typical_stopwatch_info->typ_timer_x = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_typical_stopwatch_info->typ_timer_y = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_typical_stopwatch_info->typ_milsec_x = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_typical_stopwatch_info->typ_milsec_y = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_typical_stopwatch_info->typ_history_height = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_typical_stopwatch_info->typ_timer_x += dm_typical_stopwatch_info->coordinate.s16X;
    dm_typical_stopwatch_info->typ_timer_y += dm_typical_stopwatch_info->coordinate.s16Y;

    dm_typical_stopwatch_info->typ_milsec_x += dm_typical_stopwatch_info->coordinate.s16X;
    dm_typical_stopwatch_info->typ_milsec_y += dm_typical_stopwatch_info->coordinate.s16Y;

    return UICtrlAccessPtr_p;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_nway_stopwatch_coordinates
 * DESCRIPTION
 *  This function is used obtain the N Way stopwatch control coordinates.
 * PARAMETERS
 *  UICtrlAccessPtr_p           [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_nway_stopwatch_info      [?]             
 *  dm_calendar_info(?)         [IN/OUT]        Calendar control coordinate info.
 * RETURNS
 *  void
 *****************************************************************************/
S16 *dm_get_nway_stopwatch_coordinates(S16 *UICtrlAccessPtr_p, dm_nway_stopwatch_info_struct *dm_nway_stopwatch_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UICtrlAccessPtr_p = dm_get_coordinates(UICtrlAccessPtr_p, &dm_nway_stopwatch_info->coordinate);

    dm_nway_stopwatch_info->nway_main_timer_x1 = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_nway_stopwatch_info->nway_main_timer_y1 = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_nway_stopwatch_info->nway_main_timer_x2 = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_nway_stopwatch_info->nway_main_timer_y2 = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_nway_stopwatch_info->nway_dialog_x1 = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_nway_stopwatch_info->nway_dialog_y1 = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_nway_stopwatch_info->nway_dialog_x2 = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_nway_stopwatch_info->nway_dialog_y2 = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_nway_stopwatch_info->separator_height = *UICtrlAccessPtr_p;
    UICtrlAccessPtr_p++;

    dm_nway_stopwatch_info->nway_main_timer_x1 += dm_nway_stopwatch_info->coordinate.s16X;
    dm_nway_stopwatch_info->nway_main_timer_y1 += dm_nway_stopwatch_info->coordinate.s16Y;
    dm_nway_stopwatch_info->nway_main_timer_x2 += dm_nway_stopwatch_info->coordinate.s16X;
    dm_nway_stopwatch_info->nway_main_timer_y2 += dm_nway_stopwatch_info->coordinate.s16Y;
    dm_nway_stopwatch_info->nway_dialog_x1 += dm_nway_stopwatch_info->coordinate.s16X;
    dm_nway_stopwatch_info->nway_dialog_y1 += dm_nway_stopwatch_info->coordinate.s16Y;
    dm_nway_stopwatch_info->nway_dialog_x2 += dm_nway_stopwatch_info->coordinate.s16X;
    dm_nway_stopwatch_info->nway_dialog_y2 += dm_nway_stopwatch_info->coordinate.s16Y;

    return UICtrlAccessPtr_p;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  dm_get_category_history
 * DESCRIPTION
 *  This function is used obtain the category history.
 * PARAMETERS
 *  history_buffer      [IN/OUT]        Buffer of history data.
 * RETURNS
 *  U8 history
 *****************************************************************************/
U8 *dm_get_category_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 u8NoOfUICtrls = 0;
    U8 u8CtrlCt = 0;
    U8 *control_set_ptr = NULL;
    S16 *coordinate_set_p;
    dm_data_struct *p_dm_data = NULL;
    S32 s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_data.s32CatId)
    {
        p_dm_data = &g_dm_data;
    }
    else if (g_dm_sublcd_data.s32CatId)
    {
        p_dm_data = &g_dm_sublcd_data;
    }
    else
    {
        MMI_ASSERT(0);
    }
    control_set_ptr = dm_search_control_set((U16) p_dm_data->s32CatId, &coordinate_set_p);
    /* First element in Category-Controls map specifies the number of controls */
    u8NoOfUICtrls = control_set_ptr[0];
    for (u8CtrlCt = 1; u8CtrlCt <= u8NoOfUICtrls; u8CtrlCt++)
    {
        switch (control_set_ptr[u8CtrlCt])
        {
        #if ENABLE_CIRCULAR_3D_MENU 
            case DM_CIRCULAR_MENU1:
            {
                get_circular_menu_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
        #endif /* ENABLE_CIRCULAR_3D_MENU */

            case DM_LIST1:
            {
                get_list_menu_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
            case DM_DYNAMIC_LIST1:
            {
                get_list_menu_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
            case DM_DYNAMIC_MATRIX1:
            {
                get_matrix_menu_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
            case DM_ASYNCDYNAMIC_LIST1:
            {
                get_list_menu_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
            case DM_ASYNCDYNAMIC_MATRIX1:
            {
                get_matrix_menu_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
            case DM_MATRIX_MENU1:
            {
                get_matrix_menu_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
            case DM_MULTILINE_INPUTBOX1:
            {
                get_multiline_inputbox_category_history(
                    (U16) p_dm_data->s32CatId,
                    history_buffer);
                break;
            }
#ifdef UI_EMS_SUPPORT
            case DM_EMS_INPUTBOX1:
            {
                get_EMS_inputbox_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
#endif /* UI_EMS_SUPPORT */
#ifdef __MMI_EDITOR_DIALER_SUPPORT__
            case DM_DIALER_INPUT_BOX1:
            {
                get_dialer_inputbox_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
#endif
#if 1//def __MMI_EDITOR_SINGLINE_SUPPORT__
            case DM_SINGLELINE_INPUTBOX1:
            {
                get_singleline_inputbox_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
#endif
            case DM_LSK:
            {
                /* No history currently for this control */
                break;
            }
            case DM_RSK:
            {
                /* No history currently for this control */
                break;
            }
            case DM_TITLE1:
            {
                /* No history currently for this control */
                break;
            }
            case DM_STATUS_BAR1:
            {
                /* No history currently for this control */
                break;
            }
            case DM_INLINE_FIXED_LIST1:
            {
                wgui_get_inline_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
            case DM_SLIDE_CONTROL:
            {
                get_slide_control_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
#ifdef __MMI_STOPWATCH__
            case DM_TYPICAL_STOPWATCH:
            {
                get_list_menu_category_history((U16) p_dm_data->s32CatId, history_buffer);
                s = sizeof(list_menu_category_history);
                TO_4ALIGNED_SIZE(s);
                history_buffer += s;
                break;
            }
        #ifdef __MMI_STOPWATCH__
            case DM_NWAY_STOPWATCH:
            {
                get_stop_watch_history((U16) p_dm_data->s32CatId, history_buffer);
                s = sizeof(UI_stop_watch_history);
                TO_4ALIGNED_SIZE(s);
                history_buffer += s;
                break;
            }
        #endif /* __MMI_STOPWATCH__ */ 
#endif

#if (defined(__MMI_SEARCH_WEB__) || defined(__MMI_HIDD_SUPPORT__))
            case DM_PANEL:
            {
                get_panel_category_history((U16) p_dm_data->s32CatId, history_buffer);
                break;
            }
#endif
            default:
            {
                break;
            }
        }
    }
    return history_buffer;
}   /* end of dm_get_category_history */


/*****************************************************************************
 * FUNCTION
 *  dm_get_category_history_size
 * DESCRIPTION
 *  This function is used obtain the category history.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 history_size
 *****************************************************************************/
S32 dm_get_category_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 u8CtrlCt = -1;
    S32 u8NoOfUICtrls = -1;
    U8 *control_set_ptr = NULL;
    S16 *coordinate_set_ptr = NULL;
    S32 max_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_data.s32CatId)
    {
        control_set_ptr = dm_search_control_set((U16) g_dm_data.s32CatId, &coordinate_set_ptr);
    }
    else if (g_dm_sublcd_data.s32CatId)
    {
        control_set_ptr = dm_search_control_set((U16) g_dm_sublcd_data.s32CatId, &coordinate_set_ptr);
    }
    else
    {
        MMI_ASSERT(0);
    }
    /* First element in Category-Controls map specifies the number of controls */
    u8NoOfUICtrls = control_set_ptr[0];
    for (u8CtrlCt = 1; u8CtrlCt <= u8NoOfUICtrls; u8CtrlCt++)
    {
        S32 size = 0;

        switch (control_set_ptr[u8CtrlCt])
        {
#if ENABLE_CIRCULAR_3D_MENU
            case DM_CIRCULAR_MENU1:
                size = (sizeof(circular_menu_category_history));
                break;
#endif /* ENABLE_CIRCULAR_3D_MENU */
            case DM_LIST1:
                size = (sizeof(list_menu_category_history));
                break;
            case DM_DYNAMIC_LIST1:
                size = (sizeof(list_menu_category_history));
                break;
            case DM_DYNAMIC_MATRIX1:
                size = (sizeof(matrix_menu_category_history));
                break;
            case DM_ASYNCDYNAMIC_LIST1:
                size = (sizeof(list_menu_category_history));
                break;
            case DM_ASYNCDYNAMIC_MATRIX1:
            case DM_MATRIX_MENU1:
                size = (sizeof(matrix_menu_category_history));
                break;
            case DM_MULTILINE_INPUTBOX1:
                size = (sizeof(multiline_inputbox_category_history));
                break;
                
#ifdef UI_EMS_SUPPORT             
            case DM_EMS_INPUTBOX1:
                size = (sizeof(EMS_inputbox_category_history));
                break;
#endif /* UI_EMS_SUPPORT */

#ifdef __MMI_EDITOR_DIALER_SUPPORT__
            case DM_DIALER_INPUT_BOX1:
                size = (sizeof(dialer_inputbox_category_history));
                break;
#endif
#if 1//def __MMI_EDITOR_SINGLINE_SUPPORT__
            case DM_SINGLELINE_INPUTBOX1:
                size = (sizeof(singleline_inputbox_category_history));
                break;
#endif
            case DM_INLINE_FIXED_LIST1:
                size = (wgui_get_inline_history_size());
                break;
            case DM_SLIDE_CONTROL:
                size = (sizeof(slide_control_category_history));
                break;
#if (defined(__MMI_SEARCH_WEB__) || defined(__MMI_HIDD_SUPPORT__))
            case DM_PANEL:
                size = (sizeof(panel_category_history));
                break;
#endif
            default:
                break;
        }
        max_size = (size > max_size) ? (size) : (max_size);
    }
    return max_size;
}   /* end of dm_get_category_history_size */


/*****************************************************************************
 * FUNCTION
 *  dm_reset_title_coordinates
 * DESCRIPTION
 *  Reset function for the title coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_title_coordinates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_title_x = MMI_TITLE_X;
    MMI_title_y = MMI_TITLE_Y;
    MMI_title_height = MMI_TITLE_HEIGHT;
    MMI_title_width = MMI_TITLE_WIDTH;
}   /* end of dm_reset_title_coordinates */


/*****************************************************************************
 * FUNCTION
 *  dm_reset_fixed_list_coordinates
 * DESCRIPTION
 *  Reset function for the fixed list coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_fixed_list_coordinates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.x = MMI_content_x;
    MMI_fixed_list_menu.y = MMI_content_y;
    MMI_fixed_list_menu.width = MMI_content_width;
    MMI_fixed_list_menu.height = MMI_content_height;
}   /* end of dm_reset_fixed_list_coordinates */


/*****************************************************************************
 * FUNCTION
 *  dm_reset_inline_fixed_list_coordinates
 * DESCRIPTION
 *  Reset function for the inline fixed list coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_inline_fixed_list_coordinates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.x = MMI_content_x;
    MMI_fixed_list_menu.y = MMI_content_y;
    MMI_fixed_list_menu.width = MMI_content_width;
    MMI_fixed_list_menu.height = MMI_content_height;
}   /* end of dm_reset_inline_fixed_list_coordinates */


/*****************************************************************************
 * FUNCTION
 *  dm_reset_lsk_coordinates
 * DESCRIPTION
 *  Reset function for the lsk coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_lsk_coordinates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_softkeys[MMI_LEFT_SOFTKEY].x = 0;
    MMI_softkeys[MMI_LEFT_SOFTKEY].y = UI_device_height - MMI_softkey_height;
    MMI_softkeys[MMI_LEFT_SOFTKEY].width = MMI_softkey_width;
    MMI_softkeys[MMI_LEFT_SOFTKEY].height = MMI_softkey_height;
}   /* end of dm_reset_lsk_coordinates */


/*****************************************************************************
 * FUNCTION
 *  dm_reset_rsk_coordinates
 * DESCRIPTION
 *  Reset function for the rsk coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_rsk_coordinates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_softkeys[MMI_RIGHT_SOFTKEY].x = UI_device_width - MMI_softkey_width;
    MMI_softkeys[MMI_RIGHT_SOFTKEY].y = UI_device_height - MMI_softkey_height;
    MMI_softkeys[MMI_RIGHT_SOFTKEY].width = MMI_softkey_width;
    MMI_softkeys[MMI_RIGHT_SOFTKEY].height = MMI_softkey_height;
}   /* end of dm_reset_rsk_coordinates */

/*****************************************************************************
 * FUNCTION
 *  dm_reset_csk_coordinates
 * DESCRIPTION
 *  Reset function for the csk coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_csk_coordinates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_softkeys[MMI_CENTER_SOFTKEY].x = MMI_softkey_width + ((UI_device_width - (MMI_softkey_width) * 2 - MMI_center_softkey_width) >> 1);
    MMI_softkeys[MMI_CENTER_SOFTKEY].y = UI_device_height - MMI_softkey_height;
    MMI_softkeys[MMI_CENTER_SOFTKEY].width = MMI_center_softkey_width;
    MMI_softkeys[MMI_CENTER_SOFTKEY].height = MMI_softkey_height;
}   /* end of dm_reset_csk_coordinates */



/*****************************************************************************
 * FUNCTION
 *  dm_reset_multitaps_coordinates
 * DESCRIPTION
 *  Reset function for the multitap coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_multitaps_coordinates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of dm_reset_multitaps_coordinates */


/*****************************************************************************
 * FUNCTION
 *  dm_update_multitap_coordinates
 * DESCRIPTION
 *  This function updates the multitap coordinates depending on the multitap coordinates
 * PARAMETERS
 *  dm_multiline_inputbox_info      [IN]        Multiline inputbox information structure.
 *  dm_cat_scr_info                 [IN]        Category Screen information structure.
 * RETURNS
 *  void
 *****************************************************************************/
void dm_update_multitap_coordinates(
        dm_coordinates *dm_multiline_inputbox_info,
        dm_cat_scr_info_struct *dm_cat_scr_info)
{
    return;
}   /* end of dm_update_multitap_coordinates */


/*****************************************************************************
 * FUNCTION
 *  dm_register_category_controlled_callback
 * DESCRIPTION
 *  Register the callback function for category controlled area
 * PARAMETERS
 *  f       [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void dm_register_category_controlled_callback(void (*f) (dm_coordinates *coordinate))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_category_controlled_area_callback = f;
}   /* end of dm_register_category_controlled_callback */


/*****************************************************************************
 * FUNCTION
 *  dm_register_category_controlled2_callback
 * DESCRIPTION
 *  Register the callback function for category controlled area2
 * PARAMETERS
 *  f       [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void dm_register_category_controlled2_callback(void (*f) (dm_coordinates *coordinate))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_category_controlled_area2_callback = f;
}   /* end of dm_register_category_controlled_callback */


/*****************************************************************************
 * FUNCTION
 *  dm_reset_category_controlled_callback
 * DESCRIPTION
 *  Reset the callback function for category controlled area.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_category_controlled_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_category_controlled_area_callback = NULL;
    dm_category_controlled_area2_callback = NULL;
}   /* end of dm_reset_category_controlled_callback */

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  dm_register_sub_category_controlled_callback
 * DESCRIPTION
 *  Register the callback function for category controlled area
 * PARAMETERS
 *  f       [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void dm_register_sub_category_controlled_callback(void (*f) (dm_coordinates *coordinate))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_sub_category_controlled_area_callback = f;
}   /* end of dm_register_sub_category_controlled_callback */


/*****************************************************************************
 * FUNCTION
 *  dm_reset_sub_category_controlled_callback
 * DESCRIPTION
 *  Reset the callback function for category controlled area.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_sub_category_controlled_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_sub_category_controlled_area_callback = NULL;
}   /* end of dm_reset_sub_category_controlled_callback */

#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  dm_reset_str_image
 * DESCRIPTION
 *  This function ius used to reset the image and string areas count to 0.
 * PARAMETERS
 *  void
 *  UICtrlAccessPtr_p(?)        [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_str_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_string_count = 0;
    dm_image_count = 0;
    dm_back_fill_count = 0;
    dm_rectangle_count = 0;
    dm_line_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  dm_add_title
 * DESCRIPTION
 *  title wrapper for category screen
 * PARAMETERS
 *  text        [IN]        label of title
 *  icon        [IN]        icon of title
 * RETURNS
 *  void
 *****************************************************************************/
 //huking
 ///TODO: remove icon
void dm_add_title_ex(
	UI_string_type text
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
	, PU8 icon
#endif/*__MMI_ICONTEXT_BTN_DISPLAY_ICON__*/
	)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_title_string = text;
//huking	
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    MMI_title_icon = icon;
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
}


/*****************************************************************************
 * FUNCTION
 *  dm_add_softkey
 * DESCRIPTION
 *  softkey wrapper for category screen
 * PARAMETERS
 *  lsk_text    [IN]        label of left softkey
 *  lsk_icon    [IN]        icon of left softkey
 *  rsk_text    [IN]        label of right softkey
 *  rsk_icon    [IN]        icon of right softkey
 * RETURNS
 *  void
 *****************************************************************************/
 //huking
 ///TODO: remove icon
void dm_add_softkey_ex(
	UI_string_type lsk_text, 
#ifdef __MMI_ICONTEXT_BTN_DISPLAY_ICON__	
	PU8 lsk_icon, 
#endif/*__MMI_ICONTEXT_BTN_DISPLAY_ICON__*/	
	UI_string_type rsk_text
#ifdef __MMI_ICONTEXT_BTN_DISPLAY_ICON__	
	, PU8 rsk_icon
#endif/*__MMI_ICONTEXT_BTN_DISPLAY_ICON__*/	
	)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* reset softkey handle / show (hide) function */
    SetupCategoryKeyHandlers();
    
    /* set softkey content */
    set_left_softkey_label(lsk_text);
    set_right_softkey_label(rsk_text);	
#ifdef __MMI_ICONTEXT_BTN_DISPLAY_ICON__	
    set_left_softkey_icon(lsk_icon);
    set_right_softkey_icon(rsk_icon);
#endif/*__MMI_ICONTEXT_BTN_DISPLAY_ICON__*/	

    /* register default softkey handler */
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();
}


#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 


/*****************************************************************************
 * FUNCTION
 *  dm_add_image_int
 * DESCRIPTION
 *  This function is used to add image data. To be called by Category Screen
 * PARAMETERS
 *  img                         [IN]        
 *  image_name                  [IN]        
 *  background                  [IN]        Background Fill for the image
 *  dyn_prop                    [IN]        Image raw data or with header
 *  image_width                 [IN]        image width for image raw data
 *  image_height                [IN]        image height for image raw data
 * RETURNS
 *  void
 *****************************************************************************/
void dm_add_image_int(PU8 img, S32 img_size, UI_string_type image_name, UI_filled_area *background, U32 dyn_prop, U8 img_type, S32 image_width, S32 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Image type should be valid. */
    /* Removed the statement for build warning : pointless comparison of unsigned integer with zero */
    /* MMI_ASSERT((img_type >= GDI_IMAGE_TYPE_INVALID) && (img_type <= GDI_IMAGE_TYPE_SUM)); */
    MMI_ASSERT(img_type <= GDI_IMAGE_TYPE_SUM);

    gdi_lcd_get_active(&act_lcd_handle);
#ifdef __MMI_SUBLCD__
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        MMI_ASSERT(dm_image_count_sub < DM_MAX_SUBLCD_IMAGES);

        dm_image_array_sub[dm_image_count_sub].back_fill = background;
        dm_image_array_sub[dm_image_count_sub].image = (PU8) img;
        dm_image_array_sub[dm_image_count_sub].name = image_name;
        dm_image_array_sub[dm_image_count_sub].image_size = img_size;
        dm_image_array_sub[dm_image_count_sub].dyn_prop_flag = dyn_prop;
        dm_image_array_sub[dm_image_count_sub].image_type = img_type;
        dm_image_array_sub[dm_image_count_sub].width = image_width;
        dm_image_array_sub[dm_image_count_sub].height = image_height;
        dm_image_array_sub[dm_image_count_sub++].image_handle = GDI_ERROR_HANDLE;
    }
    else
#endif /* __MMI_SUBLCD__ */ 
    {
        MMI_ASSERT(dm_image_count < DM_MAX_IMAGES);

        dm_image_array[dm_image_count].back_fill = background;
        dm_image_array[dm_image_count].image = (PU8) img;
        dm_image_array[dm_image_count].name = image_name;
        dm_image_array[dm_image_count].image_size = img_size;
        dm_image_array[dm_image_count].dyn_prop_flag = dyn_prop;
        dm_image_array[dm_image_count].image_type = img_type;
        dm_image_array[dm_image_count].width = image_width;
        dm_image_array[dm_image_count].height = image_height;
        dm_image_array[dm_image_count++].image_handle = GDI_ERROR_HANDLE;
    }    
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SUBLCD__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SUBLCD__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


/*****************************************************************************
 * FUNCTION
 *  dm_get_image_handle
 * DESCRIPTION
 *  This function is used to get the animation handle. To be called by Category Screen
 * PARAMETERS
 *  count                       [IN]        the nummer of the animation
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
gdi_handle dm_get_image_handle(S32 count)//070706 Cylen, SWFlash
{
    return dm_image_array[count].image_handle;
}



/*****************************************************************************
 * FUNCTION
 *  dm_change_image
 * DESCRIPTION
 *  This function is used to change image data. To be called by Category Screen
 * PARAMETERS
 *  image       [IN]        Image to be changed.
 *  name        [IN]        Image Name to be changed
 *  index       [IN]        Index in dm_image_struct
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
void dm_change_image(PU8 image, UI_string_type name, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates coordinate;
    S16 *cur_UICtrlAccessPtr_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    /* Only image or name should be changed at one time */
    //      MMI_ASSERT ( ( name==NULL || image==NULL ) && ( name!= NULL || image!=NULL ) );
    //      if ( ( name!=NULL && image!=NULL ) || ( name== NULL && image==NULL ) )
    //              MMI_ASSERT(0);//Only one of two should be assigned.

    /* undefined image */
    MMI_ASSERT(index < dm_image_count);

    dm_image_array[index].image = image;
    dm_image_array[index].name = name;

    cur_UICtrlAccessPtr_p = dm_get_control_coordinates_from_category(g_dm_data.s32ScrId, g_dm_data.s32CatId, DM_IMAGE, index, &coordinate);
    dm_setup_and_draw_image(&cur_UICtrlAccessPtr_p, index);
    gdi_layer_unlock_frame_buffer();       
}


/*****************************************************************************
 * FUNCTION
 *  dm_set_image_blt_before_callback
 * DESCRIPTION
 *  set blt before callback for image
 *  do not support sublcd image, and popup image
 * PARAMETERS
 *  index           [IN]    index
 *  callback_ptr    [IN]    callback function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void dm_set_image_blt_before_callback(S32 index, void (*callback_ptr)(GDI_RESULT result))
{
    dm_image_array[index].blt_before_callback_ptr = callback_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  dm_add_string
 * DESCRIPTION
 *  This function is used to add string data. To be called by Category Screen
 * PARAMETERS
 *  string              [IN]        String to be displayed.
 *  font                [IN]        Font to be used to draw the string
 *  text_color          [IN]        Text Color for the string
 *  border_color        [IN]        Border Color for the string
 *  background          [IN]        Background Fill for the string
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
void dm_add_string(
        UI_string_type string,
        UI_font_type font,
        color text_color,
        color border_color,
        UI_filled_area *background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd_handle);

#ifdef __MMI_SUBLCD__
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        MMI_ASSERT(dm_string_count_sub < DM_MAX_SUBLCD_STRINGS);

        dm_string_array_sub[dm_string_count_sub].text_color = text_color;
        dm_string_array_sub[dm_string_count_sub].border_color = border_color;
        dm_string_array_sub[dm_string_count_sub].font = font;
        if (background)
        {
            dm_string_array_sub[dm_string_count_sub].back_fill = *background;
        }
        dm_string_array_sub[dm_string_count_sub++].string = string;
    }
    else
#endif /* __MMI_SUBLCD__ */ 
    {
        MMI_ASSERT(dm_string_count < DM_MAX_STRINGS);

        dm_string_array[dm_string_count].text_color = text_color;
        dm_string_array[dm_string_count].border_color = border_color;
        dm_string_array[dm_string_count].font = font;
        if (background)
        {
            dm_string_array[dm_string_count].back_fill = *background;
        }
        dm_string_array[dm_string_count++].string = string;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_change_string
 * DESCRIPTION
 *  This function is used to change string data. To be called by Category Screen
 * PARAMETERS
 *  string              [IN]        String to be displayed.
 *  font                [IN]        Font to be used to draw the string
 *  text_color          [IN]        Text Color for the string
 *  border_color        [IN]        Border Color for the string
 *  background          [IN]        Background Fill for the string
 * RETURNS
 *  void
 *****************************************************************************/
void dm_change_string(
        S32 index,
        UI_string_type string,
        UI_font_type font,
        color text_color,
        color border_color,
        UI_filled_area *background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd_handle;
    dm_coordinates coordinate;
    S16 *cur_UICtrlAccessPtr_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gdi_lcd_get_active(&act_lcd_handle);

#ifdef __MMI_SUBLCD__
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        MMI_ASSERT(index < DM_MAX_SUBLCD_STRINGS);

        dm_string_array_sub[index].text_color = text_color;
        dm_string_array_sub[index].border_color = border_color;
        dm_string_array_sub[index].font = font;
        if (background)
        {
            dm_string_array_sub[index].back_fill = *background;
        }
        dm_string_array_sub[index].string = string;
    }
    else
#endif /* __MMI_SUBLCD__ */ 
    {
        MMI_ASSERT(index < DM_MAX_STRINGS);

        dm_string_array[index].text_color = text_color;
        dm_string_array[index].border_color = border_color;
        dm_string_array[index].font = font;
        if (background)
        {
            dm_string_array[index].back_fill = *background;
        }
        dm_string_array[index].string = string;
    }


    cur_UICtrlAccessPtr_p = dm_get_control_coordinates_from_category(g_dm_data.s32ScrId, g_dm_data.s32CatId, DM_STRING, index, &coordinate);
    dm_setup_and_draw_string(&cur_UICtrlAccessPtr_p, index);
    gdi_layer_unlock_frame_buffer();
}





/*****************************************************************************
 * FUNCTION
 *  dm_reset_button_bar_coordinates
 * DESCRIPTION
 *  This function resets button bar to its original height.
 *  Reuired till all categories are moved to Draw Manager
 * PARAMETERS
 *  void
 *  UICtrlAccessPtr_p(?)        [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_image_info_struct I  N/OUT image area coordinate info.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_button_bar_coordinates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_button_bar_height(MMI_BUTTON_BAR_HEIGHT);

    /* Right softkey always have UI_BUTTON_RIGHT_ALIGN */
    set_softkey_flags_off(UI_BUTTON_RIGHT_ALIGN, MMI_LEFT_SOFTKEY);
    set_softkey_flags_on(UI_BUTTON_LEFT_ALIGN, MMI_LEFT_SOFTKEY);
    set_softkey_flags_on(UI_BUTTON_LEFT_ALIGN, MMI_CENTER_SOFTKEY);
    set_softkey_flags_off(UI_BUTTON_RIGHT_ALIGN, MMI_CENTER_SOFTKEY);
    set_softkey_flags_on(UI_BUTTON_CENTER_ICON_X, MMI_CENTER_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  dm_add_back_fill_area
 * DESCRIPTION
 *  This function is used to add back fill. To be called by Category Screen
 * PARAMETERS
 *  background      [IN]        Background Fill for the area
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
void dm_add_back_fill_area(UI_filled_area *background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dm_back_fill_count >= DM_MAX_FILL_AREAS)
    {
        return;
    }
    dm_back_fill_array[dm_back_fill_count++] = background;
}


/*****************************************************************************
 * FUNCTION
 *  dm_add_rectangle
 * DESCRIPTION
 *  This function is used to add rectangle. To be called by Category Screen
 * PARAMETERS
 *  line_color          [IN]        Color for the reactangle
 *  fill_rectangle      [IN]        In Whether the rectangle needs to be filled from inside
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
/* START VIJAY PMT 20050930 */
void dm_add_rectangle(color line_color, dm_rectangle_fill_style fill_rectangle)
/* END VIJAY PMT 20050930 */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dm_rectangle_count >= DM_MAX_RECTANGLES)
    {
        return;
    }
    dm_rectangle_array[dm_rectangle_count].fill_rectangle = fill_rectangle;
    dm_rectangle_array[dm_rectangle_count++].line_color = line_color;
}


/*****************************************************************************
 * FUNCTION
 *  dm_add_line
 * DESCRIPTION
 *  This function is used to add line. To be called by Category Screen
 * PARAMETERS
 *  line_color      [IN]        Color for the reactangle
 *  *(?)
 * RETURNS
 *  void
 *****************************************************************************/
void dm_add_line(color line_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dm_line_count >= DM_MAX_LINES)
    {
        return;
    }
    dm_line_array[dm_line_count++] = line_color;
}


/*****************************************************************************
 * FUNCTION
 *  dm_add_slide_control
 * DESCRIPTION
 *  This function is used to add slide control. To be called by Category Screen
 * PARAMETERS
 *  lower_limit         [IN]        
 *  upper_limit         [IN]        
 *  current_value       [IN]        
 *  change_callback     [IN]        
 *  label_string        [?]         
 *  line_color(?)       [IN]        Color for the reactangle
 * RETURNS
 *  void
 *****************************************************************************/
void dm_add_slide_control(
        S32 lower_limit,
        S32 upper_limit,
        S32 current_value,
        void (*change_callback) (S32 value),
        U8 *label_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dm_slide_control_count >= MMI_MAX_SLIDE_CONTROL)
    {
        MMI_ASSERT(dm_slide_control_count < MMI_MAX_SLIDE_CONTROL);
        return;
    }
    wgui_setup_slide_control(
        &MMI_slide_control[dm_slide_control_count],
        0,
        0,
        lower_limit,
        upper_limit,
        current_value,
        change_callback);
    set_slide_control_label(&MMI_slide_control[dm_slide_control_count++], label_string);
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_slide_control_count
 * DESCRIPTION
 *  This function is used to get count of active slide controls. To be called by Category Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 dm_get_slide_control_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dm_slide_control_count;
}


/*****************************************************************************
 * FUNCTION
 *  dm_scroll_text_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_scroll_text_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (idx = 0; idx < dm_scroll_text_count; idx++)
    {
        gui_handle_scrolling_text(&(dm_scroll_text[idx]));
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_add_scroll_text_ext
 * DESCRIPTION
 *  This function is used to add scroll text. To be called by Category Screen
 * PARAMETERS
 *  text                [IN]        Text buffer
 *  x                   [IN]        x
 *  y                   [IN]        y
 *  w                   [IN]        width
 *  h                   [IN]        height
 *  timer_callback      [IN]        Invoke when scroll finish
 *  draw_background     [IN]        Draw the text background
 *  text_color          [IN]        Text color
 *  border_color        [IN]        Border color
 *  is_force_scroll     [IN]        Force scroll or not
 * RETURNS
 *  void
 *****************************************************************************/
extern UI_string_type UI_strncpy(UI_string_type text1, UI_string_type text2, S32 n);
void dm_add_scroll_text_ext(
        UI_string_type text,
        S32 x,
        S32 y,
        S32 w,
        S32 h,
        void (*timer_callback) (void),
        void (*draw_background) (S32 x1, S32 y1, S32 x2, S32 y2),
        color text_color,
        color border_color,
        MMI_BOOL is_force_scroll)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width = w, string_height = h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dm_scroll_text_count >= DM_MAX_SCROLL_TEXT)
    {
        return;
    }

    memset(dm_scroll_text_buf[dm_scroll_text_count], 0, sizeof(MAX_SUB_MENU_SIZE));
    if (text != NULL)
    {
        UI_strncpy((UI_string_type) dm_scroll_text_buf[dm_scroll_text_count], text, MAX_SUBMENU_CHARACTERS);
    }

    dm_current_scroll_text = &dm_scroll_text[dm_scroll_text_count];

    if ((w == -1) && (h == -1))
    {
        /* pre-set the font, maybe this should be passed from category */
#if defined(__MMI_MAINLCD_128X64__)
        gui_set_font(&MMI_small_font);
#else /* __MMI_MAINLCD_128X64__ */
        gui_set_font(&MMI_medium_font);
#endif /* __MMI_MAINLCD_128X64__ */
        gui_measure_string(text, &string_width, &string_height);
    }

    if(is_force_scroll)
    {
        gui_force_scrolling_text(
            dm_current_scroll_text,
            x, y,
            string_width, string_height,
            (UI_string_type) dm_scroll_text_buf[dm_scroll_text_count++],
            dm_scroll_text_handler,
            draw_background,
            text_color,
            border_color);
    }
    else
    {
        gui_create_scrolling_text(
            dm_current_scroll_text,
            x, y,
            string_width, string_height,
            (UI_string_type) dm_scroll_text_buf[dm_scroll_text_count++],
            dm_scroll_text_handler,
            draw_background,
            text_color,
            border_color);
    }

    if (text_color.r != border_color.r || text_color.g != border_color.g || text_color.b != border_color.b)
    {
        dm_current_scroll_text->flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_add_scroll_text
 * DESCRIPTION
 *  This function is used to add scroll text. To be called by Category Screen
 * PARAMETERS
 *  text                [IN]        
 *  timer_callback      [IN]        
 *  draw_background     [IN]        
 *  text_color          [IN]        
 *  border_color        [IN]        
 *  line_color(?)       [IN]        Color for the reactangle
 * RETURNS
 *  void
 *****************************************************************************/
void dm_add_scroll_text(
        UI_string_type text,
        void (*timer_callback) (void),
        void (*draw_background) (S32 x1, S32 y1, S32 x2, S32 y2),
        color text_color,
        color border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_add_scroll_text_ext(
        text,
        0, 0, -1, -1,
        timer_callback,
        draw_background,
        text_color,
        border_color,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  dm_change_scroll_text
 * DESCRIPTION
 *  This function is only used to change scroll text. 
 *  If category wants to display it after changed, please remember to restart.
 * PARAMETERS
 *  index               [IN]        Scroll text index
 *  text                [IN]        Scroll text buffer
 * RETURNS
 *  void
 *****************************************************************************/
void dm_change_scroll_text(S32 index, UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index < 0) || (index >= dm_scroll_text_count))
    {
        return;
    }

    /* stop refresh */
    gui_scrolling_text_stop(&dm_scroll_text[index]);

    memset(dm_scroll_text_buf[index], 0, sizeof(MAX_SUB_MENU_SIZE));
    if (text != NULL)
    {
        UI_strncpy((UI_string_type) dm_scroll_text_buf[index], text, MAX_SUBMENU_CHARACTERS);
    }

    gui_change_scrolling_text(&dm_scroll_text[index], (UI_string_type)dm_scroll_text_buf[index]);
}


/*****************************************************************************
 * FUNCTION
 *  dm_stop_scroll_text
 * DESCRIPTION
 *  This function is used to stop scroll text. To be called by Category Screen
 * PARAMETERS
 *  index               [IN]        Scroll text index
 * RETURNS
 *  MMI_BOOL    If the text is NULL, then return false, else return true.
 *****************************************************************************/
MMI_BOOL dm_stop_scroll_text(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index < 0) || (index >= dm_scroll_text_count))
    {
        return MMI_FALSE;
    }

    /* when update the text to NULL, the scroll is not started */
    if((dm_scroll_text_buf[index][0] == 0) && (dm_scroll_text_buf[index][1] == 0))
    {
        return MMI_FALSE;
    }
    else
    {
        gui_scrolling_text_stop(&dm_scroll_text[index]);
        return MMI_TRUE;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  dm_restart_scroll_text
 * DESCRIPTION
 *  This function is used to restart scroll text. To be called by Category Screen
 * PARAMETERS
 *  index               [IN]        Scroll text index
 * RETURNS
 *  MMI_BOOL    If the text is NULL, then return false, else return true.
 *****************************************************************************/
MMI_BOOL dm_restart_scroll_text(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index < 0) || (index >= dm_scroll_text_count))
    {
        return MMI_FALSE;
    }

    /* when update the text to NULL, the scroll text should not started */
    if((dm_scroll_text_buf[index][0] == 0) && (dm_scroll_text_buf[index][1] == 0))
    {
        return MMI_FALSE;
    }
    else
    {
        /* reset the scrolling text position */
        dm_scroll_text[index].scroll_x = 0;
        /* show the scrolling text */
        gui_show_scrolling_text(&dm_scroll_text[index]);

        return MMI_TRUE;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  dm_play_scroll_text
 * DESCRIPTION
 *  This function is used to plays the paused scroll text. To be called by Category Screen
 * PARAMETERS
 *  index               [IN]        Scroll text index
 * RETURNS
 *  MMI_BOOL    If the text is NULL, then return false, else return true.
 *****************************************************************************/
MMI_BOOL dm_play_scroll_text(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 prev_scroll_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index < 0) || (index >= dm_scroll_text_count))
    {
        return MMI_FALSE;
    }

    /* when update the text to NULL, the scroll text should not started */
    if((dm_scroll_text_buf[index][0] == 0) && (dm_scroll_text_buf[index][1] == 0))
    {
        return MMI_FALSE;
    }
    else
    {
        prev_scroll_x = dm_scroll_text[index].scroll_x;
        /* show the scrolling text */
        if((dm_scroll_text[index].text_width > dm_scroll_text[index].width) ||
            (dm_scroll_text[index].force_scroll == MMI_TRUE))
        {
            dm_scroll_text[index].flags |= UI_SCROLLING_TEXT_ENABLE_SCROLL;
        }
        gui_show_scrolling_text(&dm_scroll_text[index]);
        dm_scroll_text[index].scroll_x = prev_scroll_x;    
        return MMI_TRUE;
    }    
}



/*****************************************************************************
 * FUNCTION
 *  dm_add_button
 * DESCRIPTION
 *  This function is used to add icon button. To be called by Category Screen
 * PARAMETERS
 *  text            [IN]        
 *  up_image        [IN]        Button up image
 *  down_image      [IN]        Button down image
 *  clear_fp        [IN]        
 * RETURNS
 *  U16         index
 *****************************************************************************/
U16 dm_add_button(UI_string_type text, PU8 up_image, PU8 down_image, gui_button_clear_background_hdlr clear_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_idx = dm_button_count++;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_icontext_button(&dm_button_array[curr_idx], -1, -1, -1, -1, text, up_image);
    dm_button_array[curr_idx].flags |= UI_BUTTON_DISABLE_BACKGND_DISPLAY | UI_BUTTON_SHIFT_BUTTON1;
    if (text != NULL)
    {
        dm_button_array[curr_idx].flags |= UI_BUTTON_CENTER_TEXT_X | UI_BUTTON_CENTER_TEXT_Y;
    }
    if (up_image != NULL || down_image != NULL)
    {
        dm_button_array[curr_idx].flags |= UI_BUTTON_CENTER_ICON_X | UI_BUTTON_CENTER_ICON_Y;
    }
    dm_button_array[curr_idx].clicked_down_icon = down_image;
    dm_button_array[curr_idx].clear_background_fp = clear_fp;

    return curr_idx;
}


/*****************************************************************************
 * FUNCTION
 *  dm_move_button
 * DESCRIPTION
 *  This function is used to move icon button. To be called by Category Screen
 * PARAMETERS
 *  index       [IN]        Index of dm_button_array
 *  x           [IN]        X coordinate
 *  y           [IN]        Y coordinate
 * RETURNS
 *  void
 *****************************************************************************/
void dm_move_button(U16 index, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_icontext_button(&dm_button_array[index], x, y);
}


/*****************************************************************************
 * FUNCTION
 *  dm_resize_button
 * DESCRIPTION
 *  This function is used to move icon button. To be called by Category Screen
 * PARAMETERS
 *  index       [IN]        Index of dm_button_array
 *  width       [IN]        Width of icon button
 *  height      [IN]        Height of icon button
 * RETURNS
 *  void
 *****************************************************************************/
void dm_resize_button(U16 index, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_icontext_button(&dm_button_array[index], width, height);
    dm_button_array[index].icon_x = 0;
    dm_button_array[index].icon_y = 0;
}


/*****************************************************************************
 * FUNCTION
 *  dm_redraw_button
 * DESCRIPTION
 *  This function is used to redraw icon button. To be called by Category Screen
 * PARAMETERS
 *  index       [IN]        Index of dm_button_array
 * RETURNS
 *  void
 *****************************************************************************/
void dm_redraw_button(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dm_get_button_count() == 0)
    {
        return;
    }
    gui_show_icontext_button(&dm_button_array[index]);
}

/*****************************************************************************
 * FUNCTION
 *  dm_update_popup_bg
 * DESCRIPTION
 *  This function is used to update popup background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_update_popup_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates coordinate;
    S16 *cur_UICtrlAccessPtr_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    cur_UICtrlAccessPtr_p = dm_get_control_coordinates_from_category(g_dm_data.s32ScrId, g_dm_data.s32CatId, DM_POPUP_BACKGROUND, -1, &coordinate);
    dm_setup_and_draw_popup_background(&cur_UICtrlAccessPtr_p);
    gdi_layer_unlock_frame_buffer();     
}



/*****************************************************************************
 * FUNCTION
 *  dm_get_control_coordinates_from_category
 * DESCRIPTION
 *  This function is used to obtain the coordinate of the specific control.
 * PARAMETERS
 *  S32ScrId                    [IN]            screen ID
 *  S32CatId                    [IN]            category ID
 *  control                     [IN]            control enum
 *  index                       [IN]            index of the duplicate controls
 *  coordinate                  [OUT]           coordinate
 * RETURNS
 *  current coordinate pointer
 *****************************************************************************/
S16* dm_get_control_coordinates_from_category(
        S32 S32ScrId,
        S32 S32CatId,
        mmi_dm_control_ids_enum control,
        S32 index,
        dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 u8CtrlCt = 0;
    S32 u8NoOfUICtrls = 0;
    S16 *UICtrlAccessPtr_p = NULL, *DeafultCoordinateSet_p = NULL;
    S16 *cur_UICtrlAccessPtr_p = NULL;
    typedef struct
    {
        dm_coordinates coordinates;
        S16 array[100];
    } temp_coordinates_struct;
    temp_coordinates_struct temp_coordinates;
    S32 idx = index;
    U8 *control_set_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_set_ptr = dm_search_control_set(S32CatId, &DeafultCoordinateSet_p);

    /* First element in Category-Controls map specifies the number of controls */
    u8NoOfUICtrls = control_set_ptr[0];

    if (S32ScrId >= 0)
    {
        UICtrlAccessPtr_p = dm_search_coordinate_set(S32ScrId);
    }
    if (UICtrlAccessPtr_p == NULL)
    {
        UICtrlAccessPtr_p = DeafultCoordinateSet_p;
    }
    /* Fist element in coordinate set specifies the coordinates of complete category screen */
    UICtrlAccessPtr_p = dm_get_cat_scr_coordinates(UICtrlAccessPtr_p, (dm_cat_scr_info_struct*)&temp_coordinates);

    for (u8CtrlCt = 1; u8CtrlCt <= u8NoOfUICtrls; u8CtrlCt++)
    {
        cur_UICtrlAccessPtr_p = UICtrlAccessPtr_p;
        switch (control_set_ptr[u8CtrlCt])
        {
            case DM_BASE_LAYER_START:
            case DM_BASE_LAYER_END:
#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
            case DM_NEW_LAYER_END:
#endif
            case DM_BASE_CONTROL_SET1:
            case DM_BASE_CONTROL_SET2:
            case DM_BASE_CONTROL_SET_SUBMENU:
            case DM_BASE_CONTROL_SET_COMMON:
            case DM_ALIGNED_AREA_END:
            case DM_DATE_TIME_DISPLAY:
                break;

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
            case DM_NEW_LAYER_START:
#endif
#if ENABLE_CIRCULAR_3D_MENU
            case DM_CIRCULAR_MENU1:
#endif /* ENABLE_CIRCULAR_3D_MENU */
            case DM_LIST1:
            case DM_INLINE_FIXED_LIST1:
            case DM_MATRIX_MENU1:
            case DM_DYNAMIC_LIST1:
            case DM_DYNAMIC_MATRIX1:
            case DM_ASYNCDYNAMIC_LIST1:
            case DM_ASYNCDYNAMIC_MATRIX1:
#if 1//def __MMI_EDITOR_SINGLINE_SUPPORT__
            case DM_SINGLELINE_INPUTBOX1:
#endif
            case DM_MULTILINE_INPUTBOX1:
            case DM_EMS_INPUTBOX1:
#ifdef __MMI_EDITOR_DIALER_SUPPORT__
            case DM_DIALER_INPUT_BOX1:
#endif
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
            case DM_HORIZONTAL_TAB_BAR:
#endif
            case DM_TITLE1:
            case DM_LSK:
            case DM_RSK:
            case DM_CSK:
            case DM_BUTTON:
            case DM_CALENDAR:
            case DM_ALIGNED_AREA_START:
            case DM_STRING:
            case DM_IMAGE:
            case DM_BACK_FILL_AREA:
            case DM_RECTANGLE:
            case DM_LINE:
            case DM_SLIDE_CONTROL:
            case DM_CATEGORY_CONTROLLED_AREA:
            case DM_CATEGORY_CONTROLLED_AREA2:
            case DM_POPUP_BACKGROUND:
#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
            case DM_WALL_PAPER:
#endif
            case DM_SCROLL_TEXT:
            case DM_PERCENTAGE_BAR:
#if (defined(__MMI_SEARCH_WEB__) || defined(__MMI_HIDD_SUPPORT__))
            case DM_PANEL:
#endif				
                UICtrlAccessPtr_p = dm_get_coordinates(UICtrlAccessPtr_p, (dm_coordinates*)&temp_coordinates);
                break;
//#endif
            case DM_STATUS_BAR1:
                UICtrlAccessPtr_p = dm_get_status_icon_bar_coordinates(UICtrlAccessPtr_p, (dm_status_info_struct*)&temp_coordinates);
                break;

            case DM_BUTTON_BAR1:
                UICtrlAccessPtr_p = dm_get_button_bar_coordinates(UICtrlAccessPtr_p, (dm_buttonbar_info_struct*)&temp_coordinates);
                break;

#ifdef __MMI_STOPWATCH__
            case DM_NWAY_STOPWATCH:
                UICtrlAccessPtr_p = dm_get_nway_stopwatch_coordinates(UICtrlAccessPtr_p, (dm_nway_stopwatch_info_struct*)&temp_coordinates);
                break;

            case DM_TYPICAL_STOPWATCH:
                UICtrlAccessPtr_p = dm_get_typical_stopwatch_coordinates(UICtrlAccessPtr_p, (dm_typical_stopwatch_info_struct*)&temp_coordinates);
                break;
#endif
            default:
                break;

        }

        if (control == control_set_ptr[u8CtrlCt])
        {
            if (idx <= 0)
            {
                *coordinate = temp_coordinates.coordinates;
                return cur_UICtrlAccessPtr_p;
            }
            else
            {
                idx --;
            }
        }
    }

    return NULL;
}

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
/*****************************************************************************
 * FUNCTION
 *  dm_create_layer
 * DESCRIPTION
 *  This function is to create new layer which is not defined in control_set
 * PARAMETERS
 *  x               [IN]        X-coordinate of new layer
 *  y               [IN]        Y-coordinate of new layer
 *  width           [IN]        Width of new layer
 *  height          [IN]        Height of new layer
 *  handle_ptr      [?]         
 *  flags           [IN]        Flags to identify the index of new layer
 * RETURNS
 *  GDI_RESULT  result of create layer
 *****************************************************************************/
GDI_RESULT dm_create_layer(S32 x, S32 y, S32 width, S32 height, gdi_handle *handle_ptr, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, act_layer_idx = 0, *act_dm_layers_count = NULL;
    U16 i = 0; //061506 double buffer
    GDI_HANDLE act_layer = GDI_ERROR_HANDLE, *act_dm_layers = NULL, new_layer;
    GDI_RESULT ret = 0;
    gdi_handle act_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create new layer using GDI APIs */
    ret = gdi_layer_create(x, y, width, height, &new_layer);
    if (ret < 0)
        return ret;

    gdi_lcd_get_active(&act_lcd_handle);

#ifdef __MMI_SUBLCD__
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        act_dm_layers = dm_layers_sub;
        act_dm_layers_count = &dm_layers_count_sub;
    }
    else if (act_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
#endif /* __MMI_SUBLCD__ */ 
    {
        act_dm_layers = dm_layers;
        act_dm_layers_count = &dm_layers_count;
    }

    switch (flags)
    {
        case DM_LAYER_BOTTOM:
            /* move each layer forward */
            for (idx = *act_dm_layers_count; idx > 0; idx--)
            {
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
                if ((act_dm_layers[idx - 1] == g_dm_scr_bg_cntx.layer_handle) || 
                        (act_dm_layers[idx -1 ] != GDI_ERROR_HANDLE))
#else
                if ((act_dm_layers[idx - 1] == g_dm_scr_bg_cntx.layer_handle) || 
                        (act_dm_layers[idx -1 ] != GDI_ERROR_HANDLE && 
                        (idx -1) == dm_wallpaper_layer_idx))
#endif
                {
                    break;
                }
                act_dm_layers[idx] = act_dm_layers[idx-1];
            }
            act_layer_idx = idx;
            break;

        case DM_LAYER_TOP:
            act_layer_idx = *act_dm_layers_count;
            break;

        case DM_LAYER_ACTIVE_TOP:
            /* get active layer handle */
            gdi_layer_get_active(&act_layer);

            /* find out active layer index in dm_layers */
            for (idx = 0; idx < *act_dm_layers_count; idx++)
                if (act_dm_layers[idx] == act_layer)
                {
                    break;
                }

            act_layer_idx = idx;
            /* move each layer forward */
            for (i = *act_dm_layers_count; i > idx; i--)
            {
                act_dm_layers[i] = act_dm_layers[i-1];
            }
            break;

        case DM_LAYER_ACTIVE_BOTTOM:
            if (*act_dm_layers_count == 0)
            {
                act_layer_idx = 0;
                break;
            }
            /* get active layer handle */
            gdi_layer_get_active(&act_layer);

            /* find out active layer index in dm_layers */
            for (idx = 0; idx < *act_dm_layers_count; idx++)
                if (act_dm_layers[idx] == act_layer)
                {
                    break;
                }

            act_layer_idx = ++idx;

            /* move each layer forward */
            for (i = *act_dm_layers_count; i > idx; i--)
            {
                act_dm_layers[i] = act_dm_layers[i-1];
            }
            break;

        default:
            ASSERT(0);
            break;
    }

    /* add layer count and add new layer to drawmanager */
            (*act_dm_layers_count)++;
    act_dm_layers[act_layer_idx] = new_layer;
            *handle_ptr = act_dm_layers[act_layer_idx];

    gdi_layer_set_blt_layer(act_dm_layers[0], act_dm_layers[1], act_dm_layers[2], act_dm_layers[3]);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  dm_create_layer_using_outside_memory
 * DESCRIPTION
 *  This function is to create new layer which is not defined in control_set and use outside memory
 * PARAMETERS
 *  x                       [IN]        X-coordinate of new layer
 *  y                       [IN]        Y-coordinate of new layer
 *  width                   [IN]        Width of new layer
 *  height                  [IN]        Height of new layer
 *  handle_ptr              [IN]        
 *  outside_memory          [IN]        Outside memory pointer
 *  outside_memory_size     [IN]        Outside memory size
 *  flags                   [IN]        Flags to identify the index of new layer
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT dm_create_layer_using_outside_memory(
            S32 x,
            S32 y,
            S32 width,
            S32 height,
            gdi_handle **handle_ptr,
            U8 *outside_memory,
            S32 outside_memory_size,
            U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, act_layer_idx = 0, *act_dm_layers_count = NULL;
    U16 i = 0; //061506 double buffer
    GDI_HANDLE act_layer = GDI_ERROR_HANDLE, *act_dm_layers = NULL, new_layer;
    GDI_RESULT ret = 0;
    gdi_handle act_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Create layer first, lazy free will destory old layer in drawmanager */
    ret = gdi_layer_create_using_outside_memory(
            x,
            y,
            width,
            height,
            &new_layer,
            outside_memory,
            outside_memory_size);
    if (ret < 0)
        return ret;
    
    gdi_lcd_get_active(&act_lcd_handle);

#ifdef __MMI_SUBLCD__
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        act_dm_layers = dm_layers_sub;
        act_dm_layers_count = &dm_layers_count_sub;
    }
    else if (act_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
#endif /* __MMI_SUBLCD__ */ 
    {
        act_dm_layers = dm_layers;
        act_dm_layers_count = &dm_layers_count;
    }

    switch (flags)
    {
        case DM_LAYER_BOTTOM:
            /* move each layer forward */
            for (idx = *act_dm_layers_count; idx > 0; idx--)
            {
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
                if ((act_dm_layers[idx - 1] == g_dm_scr_bg_cntx.layer_handle) || 
                        (act_dm_layers[idx - 1] != GDI_ERROR_HANDLE))
#else
                if ((act_dm_layers[idx - 1] == g_dm_scr_bg_cntx.layer_handle) || 
                        (act_dm_layers[idx - 1] != GDI_ERROR_HANDLE && 
                        (idx -1) == dm_wallpaper_layer_idx))
#endif
                {
                    break;
                }
                act_dm_layers[idx] = act_dm_layers[idx-1];
            }
            /* add to top of the scr_bg or add to the first  */
            act_layer_idx = idx;
            break;

        case DM_LAYER_TOP:
            /* add to last */
            act_layer_idx = *act_dm_layers_count;
            break;

        case DM_LAYER_ACTIVE_TOP:
            /* get active layer handle */
            gdi_layer_get_active(&act_layer);
            /* find out active layer index in dm_layers */
            for (idx = 0; idx < *act_dm_layers_count; idx++)
                if (act_dm_layers[idx] == act_layer)
                {
                    break;
                }

            act_layer_idx = idx;

            /* move each layer forward */
            for (i = *act_dm_layers_count; i > idx; i--)
            {
                act_dm_layers[i] = act_dm_layers[i-1];
            }
            break;

        case DM_LAYER_ACTIVE_BOTTOM:
            /* get active layer handle */
            gdi_layer_get_active(&act_layer);

            /* find out active layer index in dm_layers */
            for (idx = 0; idx < *act_dm_layers_count; idx++)
                if (act_dm_layers[idx] == act_layer)
                {
                    break;
                }

            act_layer_idx = ++idx;

            /* move each layer forward */
            for (i = *act_dm_layers_count; i > idx; i--)
            {
                act_dm_layers[i] = act_dm_layers[i-1];
            }
            break;
            
        default:
            ASSERT(0);
            break;
    }

    /* add layer count and add new layer to drawmanager */
            (*act_dm_layers_count)++;
    act_dm_layers[act_layer_idx] = new_layer;
            *handle_ptr = &act_dm_layers[act_layer_idx];

    gdi_layer_set_blt_layer(act_dm_layers[0], act_dm_layers[1], act_dm_layers[2], act_dm_layers[3]);

    return ret;
}


#else
/*****************************************************************************
 * FUNCTION
 *  dm_create_layer
 * DESCRIPTION
 *  This function is to create new layer which is not defined in control_set
 * PARAMETERS
 *  x               [IN]        X-coordinate of new layer
 *  y               [IN]        Y-coordinate of new layer
 *  width           [IN]        Width of new layer
 *  height          [IN]        Height of new layer
 *  handle_ptr      [?]         
 *  flags           [IN]        Flags to identify the index of new layer
 * RETURNS
 *  GDI_RESULT  result of create layer
 *****************************************************************************/
GDI_RESULT dm_create_layer(S32 x, S32 y, S32 width, S32 height, gdi_handle *handle_ptr, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(handle_ptr);
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  dm_create_layer_using_outside_memory
 * DESCRIPTION
 *  This function is to create new layer which is not defined in control_set and use outside memory
 * PARAMETERS
 *  x                       [IN]        X-coordinate of new layer
 *  y                       [IN]        Y-coordinate of new layer
 *  width                   [IN]        Width of new layer
 *  height                  [IN]        Height of new layer
 *  handle_ptr              [IN]        
 *  outside_memory          [IN]        Outside memory pointer
 *  outside_memory_size     [IN]        Outside memory size
 *  flags                   [IN]        Flags to identify the index of new layer
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT dm_create_layer_using_outside_memory(
            S32 x,
            S32 y,
            S32 width,
            S32 height,
            gdi_handle **handle_ptr,
            U8 *outside_memory,
            S32 outside_memory_size,
            U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //gdi_lcd_get_active(*handle_ptr);
    return GDI_FAILED;
}
#endif


#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
/*****************************************************************************
 * FUNCTION
 *  dm_add_blt_layer
 * DESCRIPTION
 *  This function is to add new layer into blt layer list
 * PARAMETERS
 *  handle_ptr      [IN]        New layer handle
 *  flags           [IN]        Flags to identify the index of new layer
 * RETURNS
 *  MMI_BOOL result of adding layer
 *****************************************************************************/
MMI_BOOL dm_add_blt_layer(gdi_handle handle_ptr, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, act_layer_idx = 0, *act_dm_layers_count = NULL;
    U16 i = 0; //061506 double buffer
    GDI_HANDLE act_layer = GDI_ERROR_HANDLE, *act_dm_layers = NULL;
    gdi_handle act_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd_handle);

#ifdef __MMI_SUBLCD__
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        act_dm_layers = dm_layers_sub;
        act_dm_layers_count = &dm_layers_count_sub;
    }
    else if (act_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
#endif /* __MMI_SUBLCD__ */ 
    {
        act_dm_layers = dm_layers;
        act_dm_layers_count = &dm_layers_count;
    }

    for (idx = 0; idx < *act_dm_layers_count; idx++)
    {
        if (act_dm_layers[idx] == handle_ptr)
        {
            return MMI_FALSE;
        }
    }

    switch (flags)
    {
        case DM_LAYER_BOTTOM:

            /* move each layer forward */
            /* 061506 double buffer Start */
            for (idx = *act_dm_layers_count; idx > 0; idx--)
            {
                act_dm_layers[idx] = act_dm_layers[idx-1];
            }
            /* 061506 double buffer End */

            act_dm_layers[0] = handle_ptr;

            (*act_dm_layers_count)++;

            break;

        case DM_LAYER_TOP:

            act_dm_layers[(*act_dm_layers_count)] = handle_ptr;

            (*act_dm_layers_count)++;

            break;

        case DM_LAYER_ACTIVE_TOP:

            /* get active layer handle */
            gdi_layer_get_active(&act_layer);

            /* find out active layer index in dm_layers */
            for (idx = 0; idx < *act_dm_layers_count; idx++)
                if (act_dm_layers[idx] == act_layer)
                {
                    break;
                }

            act_layer_idx = idx;

            /* move each layer forward */
            /* 061506 double buffer Start */
            for (i = *act_dm_layers_count; i > idx; i--)
            {
                act_dm_layers[i] = act_dm_layers[i-1];
            }
            /* 061506 double buffer End */

            (*act_dm_layers_count)++;

            act_dm_layers[act_layer_idx] = handle_ptr;

            break;

        case DM_LAYER_ACTIVE_BOTTOM:

            /* get active layer handle */
            gdi_layer_get_active(&act_layer);

            /* find out active layer index in dm_layers */
            for (idx = 0; idx < *act_dm_layers_count; idx++)
                if (act_dm_layers[idx] == act_layer)
                {
                    break;
                }

            act_layer_idx = ++idx;

            /* move each layer forward */
            /* 061506 double buffer Start */
            for (i = *act_dm_layers_count; i > idx; i--)
            {
                act_dm_layers[i] = act_dm_layers[i-1];
            }
            /* 061506 double buffer End */

            (*act_dm_layers_count)++;

            act_dm_layers[act_layer_idx] = handle_ptr;

            break;
    }

    gdi_layer_set_blt_layer(act_dm_layers[0], act_dm_layers[1], act_dm_layers[2], act_dm_layers[3]);

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  dm_set_blt_layer
 * DESCRIPTION
 *  This function is to set blt layer sequence
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT dm_set_blt_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_layer_set_blt_layer(dm_layers[0], dm_layers[1], dm_layers[2], dm_layers[3]);
}
#endif

/* Leo start 20050722, add button control */


/*****************************************************************************
 * FUNCTION
 *  dm_register_button_functions
 * DESCRIPTION
 *  set handling functions of buttons
 * PARAMETERS
 *  button_index        [IN]        Index of dm_button_array
 *  key_type            [IN]        Key event type
 *  f                   [IN]        Handling function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void dm_register_button_functions(U16 button_index, U16 key_type, FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    MMI_ASSERT(button_index < DM_MAX_BUTTONS);

    dm_button_func_ptrs[button_index][key_type] = f;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dm_reset_button_functions
 * DESCRIPTION
 *  reset handling functions of buttons
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_reset_button_functions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    U8 button_index, key_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (button_index = 0; button_index < DM_MAX_BUTTONS; button_index++)
        for (key_type = 0; key_type < MAX_KEY_TYPE; key_type++)
        {
            dm_button_func_ptrs[button_index][key_type] = NULL;
        }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dm_execute_button_handler
 * DESCRIPTION
 *  Execute left softkey handler from pen
 * PARAMETERS
 *  btn_index       [IN]        
 *  key_type        [IN]        - KEY_EVENT_DOWN, KEY_EVENT_UP, KEY_LONG_PRESS
 * RETURNS
 *  void
 *****************************************************************************/
void dm_execute_button_handler(U16 btn_index, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(btn_index < DM_MAX_BUTTONS);
    MMI_ASSERT(key_type < MAX_KEY_TYPE);

    if (dm_button_func_ptrs[btn_index][key_type] != NULL)
    {
        dm_button_func_ptrs[btn_index][key_type] ();
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) */
}


/*****************************************************************************
 * FUNCTION
 *  dm_is_redraw_screen
 * DESCRIPTION
 *  Execute left softkey handler from pen
 * PARAMETERS
 *  void
 *  key_type - KEY_EVENT_DOWN, KEY_EVENT_UP, KEY_LONG_PRESS(?)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL dm_is_redraw_screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_data.s32flags == DM_SUB_LCD_CONTEXT)
    {
        if (g_dm_cntx.redraw_screen_sub == REDRAW_2_REDRAW)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
#endif /* __MMI_SUBLCD__ */ 
    {
        if (g_dm_cntx.redraw_screen_main == REDRAW_2_REDRAW)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  dm_check_image_bound
 * DESCRIPTION
 *  check image bounder controlled by draw manager
 * PARAMETERS
 *  index       [IN]        Index of images
 *  point       [IN]        Pen point
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL dm_check_image_bound(U16 index, mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(PEN_CHECK_BOUND(
                (S32)point.x,
                (S32)point.y,
                (S32)dm_image_array[index].x,
                (S32)dm_image_array[index].y,
                dm_image_array[index].width,
                dm_image_array[index].height));
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
/*****************************************************************************
 * FUNCTION
 *  dm_get_layer_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_HANDLE dm_get_layer_handle(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dm_layers[index];
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_layer_handle_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_HANDLE *dm_get_layer_handle_ptr(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(dm_layers[index]);
}
#endif

#ifdef __DM_PROGRESS_BAR_9_SLICE_BG_IMAGE__
/*****************************************************************************
 * FUNCTION
 *  dm_add_percentage_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  init_value              [IN]   
 *  string                  [IN]
 *  bar_color               [IN]        
 *  bg_image                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 dm_add_percentage_bar(U16 init_value, U8 *string, color bar_color, U16 bg_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_percentage_bar_struct *act_bar = &dm_percentage_bar_array[dm_percentage_bar_count];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    act_bar->value = init_value;
    act_bar->bar_color = bar_color;
    act_bar->bg_image = bg_image;
    act_bar->progres_string = string;

    return dm_percentage_bar_count++;
}
#else


/*****************************************************************************
 * FUNCTION
 *  dm_add_percentage_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  init_value              [IN]   
 *  string                  [IN]
 *  bar_color               [IN]        
 *  bg_image                [IN]        
 *  left_side_image         [IN]        
 *  right_side_image        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 dm_add_percentage_bar(U16 init_value, U8 *string, color bar_color, U16 bg_image, U16 left_side_image, U16 right_side_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_percentage_bar_struct *act_bar = &dm_percentage_bar_array[dm_percentage_bar_count];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    act_bar->value = init_value;
    act_bar->bar_color = bar_color;
    act_bar->bg_image = bg_image;
    act_bar->left_side_image = left_side_image;
    act_bar->right_side_image = right_side_image;
    act_bar->progres_string = string;

    return dm_percentage_bar_count++;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  dm_update_percentage_bar_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id          [IN]        
 *  value       [IN]        
 *  string      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void dm_update_percentage_bar_value(S32 id, U16 value, U8* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_percentage_bar_array[id].value = value;
    dm_percentage_bar_array[id].progres_string = string;
}


/*****************************************************************************
 * FUNCTION
 *  dm_change_percentage_bar_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dm_change_percentage_bar_color(S32 id, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_percentage_bar_array[id].bar_color = c;
}


#ifdef __DM_PROGRESS_BAR_9_SLICE_BG_IMAGE__
/*****************************************************************************
 * FUNCTION
 *  dm_redraw_percentage_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dm_redraw_percentage_bar(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_percentage_bar_struct *act_bar = &dm_percentage_bar_array[id];

    S32 x = act_bar->x;
    S32 y = act_bar->y;
    S32 width = act_bar->width;
    S32 height = act_bar->height;
    U16 str_buf[5];
    S32 str_width = 0, str_height = 0;
    S32 img_x = 0, img_y = 0;
    S32 img_width = 0, img_height = 0;
    S32 bar_width = 0, bar_height = 0;
    gdi_handle temp_layer_ptr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    if (act_bar->progres_string == NULL)
    {
        gui_itoa(act_bar->value, (UI_string_type) & str_buf, 10);
        mmi_ucs2cat((S8*)&str_buf, (S8*)L"%");
        gui_measure_string((UI_string_type) str_buf, &str_width, &str_height);
    }
    else
    {
        gui_measure_string((UI_string_type) act_bar->progres_string, &str_width, &str_height);
    }
    gdi_image_get_dimension_id(act_bar->bg_image, &img_width, &img_height);

    /* clear background */
    gdi_layer_get_active(&temp_layer_ptr);
    if (g_dm_data.s32flags & DM_CLEAR_SCREEN_BACKGROUND_COLOR)
    {
        gdi_draw_solid_rect(x, y, x + width - 1, y + height - 1, GDI_COLOR_WHITE);
    }
    else
    {
        gdi_draw_solid_rect(x, y, x + width - 1, y + height - 1, GDI_COLOR_TRANSPARENT);
    }

    /* update text */
    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(x + ((width - str_width) >> 1) + str_width, y + ((height - str_height - img_height) / 3));
    }
    else
    {
        gui_move_text_cursor(x + ((width - str_width) >> 1), y + ((height - str_height - img_height) / 3));
    }
    gui_set_text_color(gui_color(0,0,0));
    
    if (act_bar->progres_string == NULL)
    {
        gui_print_text((UI_string_type) str_buf);
    }
    else
    {
        gui_print_text((UI_string_type) act_bar->progres_string);
    }

    /* update image */
    bar_width = width - (img_width * 2); 
    bar_height = img_height / 3 ;

    /* Draw the image and percentage bar within */
    img_x = x + img_width / 2;
    img_y = y + height - ((height - str_height - img_height) / 3 + img_height);

    gdi_image_draw_resized(img_x, img_y, 
        bar_width + img_width, img_height,
        (U8*) get_image(act_bar->bg_image));
    
    img_x = img_x + img_width / 2;
    img_y = img_y + bar_height;
    gdi_draw_solid_rect(
        img_x,
        img_y,
        img_x - 1 + (((bar_width + 1) * act_bar->value) / 100),
        img_y + bar_height - 1,
        gdi_act_color_from_rgb(255, act_bar->bar_color.r, act_bar->bar_color.g, act_bar->bar_color.b));

    gdi_layer_blt_previous(x, y, x + width - 1, y + height - 1);
}
#else


/*****************************************************************************
 * FUNCTION
 *  dm_redraw_percentage_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dm_redraw_percentage_bar(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_percentage_bar_struct *act_bar = &dm_percentage_bar_array[id];

    S32 x = act_bar->x;
    S32 y = act_bar->y;
    S32 width = act_bar->width;
    S32 height = act_bar->height;
    U16 str_buf[5];
    S32 str_width = 0, str_height = 0;
    S32 img_x = 0, img_y = 0;
    S32 img_width = 0, img_height = 0;
    S32 left_image_width = 0, left_image_height = 0;
    S32 right_image_width = 0, right_image_height = 0;
    gdi_handle temp_layer_ptr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    if (act_bar->progres_string == NULL)
    {
        gui_itoa(act_bar->value, (UI_string_type) & str_buf, 10);
        mmi_ucs2cat((S8*)&str_buf, (S8*)L"%");
        gui_measure_string((UI_string_type) str_buf, &str_width, &str_height);
    }
    else
    {
        gui_measure_string((UI_string_type) act_bar->progres_string, &str_width, &str_height);
    }
    gdi_image_get_dimension_id(act_bar->bg_image, &img_width, &img_height);
    gdi_image_get_dimension_id(act_bar->left_side_image, &left_image_width, &left_image_height);
    gdi_image_get_dimension_id(act_bar->right_side_image, &right_image_width, &right_image_height);

    /* clear background */
    gdi_layer_get_active(&temp_layer_ptr);
    if (g_dm_data.s32flags & DM_CLEAR_SCREEN_BACKGROUND_COLOR)
    {
        gdi_draw_solid_rect(x, y, x + width - 1, y + height - 1, GDI_COLOR_WHITE);
    }
    else
    {
        gdi_draw_solid_rect(x, y, x + width - 1, y + height - 1, GDI_COLOR_TRANSPARENT);
    }

    /* update text */
    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(x + ((width - str_width) >> 1) + str_width, y + ((height - str_height - img_height) / 3));
    }
    else
    {
        gui_move_text_cursor(x + ((width - str_width) >> 1), y + ((height - str_height - img_height) / 3));
    }
    gui_set_text_color(gui_color(0,0,0));
    
    if (act_bar->progres_string == NULL)
    {
        gui_print_text((UI_string_type) str_buf);
    }
    else
    {
        gui_print_text((UI_string_type) act_bar->progres_string);
    }

    /* update image */
    img_x = x + ((width - img_width - left_image_width - right_image_width) >> 1);
    img_y = y + height - ((height - str_height - img_height) / 3 + img_height);
#ifdef __MMI_MAINLCD_128X64__
    gdi_image_draw(img_x, img_y, (U8*) get_image(act_bar->left_side_image));
    gdi_image_draw(img_x + left_image_width - 1, img_y, (U8*) get_image(act_bar->bg_image));
    gdi_image_draw(img_x + left_image_width + img_width - 1, img_y, (U8*) get_image(act_bar->right_side_image));
    gdi_draw_solid_rect(
        img_x + left_image_width,
        img_y + 2,
        img_x + left_image_width - 1 + (((img_width + 1) * act_bar->value) / 100) - 2,
        img_y + img_height - 3,
        gdi_act_color_from_rgb(255, act_bar->bar_color.r, act_bar->bar_color.g, act_bar->bar_color.b));
#else /* __MMI_MAINLCD_128X64__ */
    gdi_draw_solid_rect(
        img_x + left_image_width,
        img_y + 1,
        img_x + left_image_width - 1 + (((img_width + 1) * act_bar->value) / 100),
        img_y + img_height - 2,
        gdi_act_color_from_rgb(255, act_bar->bar_color.r, act_bar->bar_color.g, act_bar->bar_color.b));
    gdi_image_draw(img_x, img_y, (U8*) get_image(act_bar->left_side_image));
    gdi_image_draw(img_x + left_image_width - 1, img_y, (U8*) get_image(act_bar->bg_image));
    gdi_image_draw(img_x + left_image_width + img_width - 1, img_y, (U8*) get_image(act_bar->right_side_image));
#endif /* __MMI_MAINLCD_128X64__ */
    gdi_layer_blt_previous(x, y, x + width - 1, y + height - 1);
}
#endif


#if (defined(__MMI_SEARCH_WEB__) || defined(__MMI_HIDD_SUPPORT__))
/* 121106 HID Start */
/*****************************************************************************
 * FUNCTION
 *  dm_add_panel
 * DESCRIPTION
 *  This function is used to add panel. To be called by Category Screen
 * PARAMETERS
 *  x                           [IN]        x of panel
 *  y                           [IN]        y of panel
 *  width                       [IN]        width of panel
 *  height                      [IN]        height of panel
 *  background                  [IN]        background painter
 *  display_focus               [IN]        whether to display focussed element differently
 *  repeat_period               [IN]        period of repeat events in milliseconds (0 for default)
 * RETURNS
 *  S32
 *****************************************************************************/
 S32 dm_add_panel(
        S32 x, 
        S32 y, 
        S32 width, 
        S32 height, 
        gui_util_painter_struct background,
        MMI_BOOL display_focus,
        U32 repeat_period)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dm_panel_count < DM_MAX_PANEL);
    gui_panel_create(&(dm_panel_array[dm_panel_count]), x, y, width, height, background, display_focus, repeat_period);

    return dm_panel_count++;
}

/*****************************************************************************
 * FUNCTION
 *  dm_add_panel_element
 * DESCRIPTION
 *  This function is used to add a element to certain panel
 * PARAMETERS
 *  panel_handle                    [IN]        panel handle to the panel existence
 *  x                               [IN]        x of element
 *  y                               [IN]        y of element
 *  width                           [IN]        width of element
 *  height                          [IN]        height of element
 *  keycode                         [IN]        keycode of element
 *  down_event_callback             [IN]        Down event callback
 *  up_event_callback               [IN]        up_event_callback of element
 *  repeat_event_callback           [IN]        repeat_event_callback of element
 *  disable_painter                 [IN]        disable_painter of element
 *  normal_painter                  [IN]        normal_painter of element
 *  focussed_painter                [IN]        focussed_painter painter
 *  down_painter                    [IN]        down_painter of element
 *  redraw_bg_after_state_changed   [IN]        whether to redraw bg after state changed
 * RETURNS
 *  S32
 *****************************************************************************/
S32 dm_add_panel_element(
        S32 panel_handle,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U16 keycode,
        FuncPtr down_event_callback,
        FuncPtr up_event_callback,
        FuncPtr repeat_event_callback,
        gui_util_painter_struct normal_painter,
        gui_util_painter_struct focussed_painter,
        gui_util_painter_struct down_painter,
        gui_util_painter_struct disable_painter,
        MMI_BOOL redraw_bg_after_state_changed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_panel_add_element(
            &(dm_panel_array[panel_handle]),
            x,
            y,
            width,
            height,
            keycode,
            down_event_callback,
            up_event_callback,
            repeat_event_callback,
            normal_painter,
            down_painter,
            focussed_painter,
            disable_painter, // TODO: change to disabled
            redraw_bg_after_state_changed);
}


/*****************************************************************************
 * FUNCTION
 *  dm_update_panel_element
 * DESCRIPTION
 *  update panel element
 * PARAMETERS
 *  panel_handle                    [IN]        Panel handle to the panel existence
 *  elem_idx                        [IN]        Element index
 *  keycode                         [IN]        keycode of element
 *  down_event_callback             [IN]        Down event callback
 *  up_event_callback               [IN]        up_event_callback of element
 *  repeat_event_callback           [IN]        repeat_event_callback of element
 *  disable_painter                 [IN]        disable_painter of element
 *  normal_painter                  [IN]        normal_painter of element
 *  focussed_painter                [IN]        focussed_painter painter
 *  down_painter                    [IN]        down_painter of element
 * RETURNS
 *  void
 *****************************************************************************/
void dm_update_panel_element(
        S32 panel_handle, 
        S32 elem_idx, 
        U16 keycode,
        FuncPtr down_event_callback,
        FuncPtr up_event_callback,
        FuncPtr repeat_event_callback,
        gui_util_painter_struct normal_painter,
        gui_util_painter_struct focussed_painter,
        gui_util_painter_struct down_painter,
        gui_util_painter_struct disable_painter)
{
     gui_panel_set_element_callback(
                &(dm_panel_array[panel_handle]),
                elem_idx,
                keycode,
                down_event_callback,
                up_event_callback,
                repeat_event_callback,
                normal_painter,
                down_painter,
                focussed_painter,
                disable_painter);
}


/*****************************************************************************
 * FUNCTION
 *  dm_set_panel_enable_element
 * DESCRIPTION
 *  Enable/Disable panel element
 * PARAMETERS
 *  panel_handle        [IN]            Panel handle to the panel existence
 *  elem_idx            [IN]            Element index
 *  enabled             [IN]            Is enable
 *  update_display      [IN]            Is redraw
 * RETURNS
 *  void
 *****************************************************************************/
void dm_set_panel_enable_element(S32 panel_handle, S32 elem_idx, MMI_BOOL enabled, MMI_BOOL update_display)
{
    gui_panel_enable_element(&(dm_panel_array[panel_handle]), elem_idx, enabled, update_display);
}


/*****************************************************************************
 * FUNCTION
 *  dm_set_panel_element_focus
 * DESCRIPTION
 *  This function is used to set the focused element of certain panel
 * PARAMETERS
 *  panel_handle                    [IN/OUT]    panel handle to the panel existence
 *  element_index                   [IN]        element_index to be focused
 *  update_display                  [IN]        whether to update the panel display
 * RETURNS
 *  void
 *****************************************************************************/
void dm_set_panel_element_focus(
        S32 panel_handle,
        S32 element_index,
        MMI_BOOL update_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_panel_set_element_focus(
        &(dm_panel_array[panel_handle]),
        element_index,
        update_display);
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_panel_element_focus
 * DESCRIPTION
 *  This function is used to get the focused element of certain panel
 * PARAMETERS
 *  panel_handle                    [IN]        panel handle to the panel existence
 * RETURNS
 *  S32
 *****************************************************************************/
S32 dm_get_panel_element_focus(S32 panel_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_panel_get_element_focus(&(dm_panel_array[panel_handle]));
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_panel_count
 * DESCRIPTION
 *  This function is used to get count of active panel
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 dm_get_panel_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dm_panel_count;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_panel_count
 * DESCRIPTION
 *  This function is used to set the key handler for a certain panel
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 dm_register_panel_keys(S32 panel_handle, FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 elem_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (elem_idx = 0; elem_idx < dm_panel_array[panel_handle].element_count; elem_idx++)
    {
        gui_panel_element_struct *e = &dm_panel_array[panel_handle].elements[elem_idx];
        if (e->keycode != KEY_INVALID)
        {
            SetKeyDownHandler(handler, e->keycode);
            SetKeyUpHandler(handler, e->keycode);
            SetKeyLongpressHandler(handler, e->keycode);
            SetKeyRepeatHandler(handler, e->keycode);
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_panel
 * DESCRIPTION
 *  This function is used to set the panel from a panel handle
 * PARAMETERS
 *  void
 * RETURNS
 *  gui_panel_struct*
 *****************************************************************************/
gui_panel_struct* dm_get_panel(S32 panel_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(dm_panel_array[panel_handle]);
}
#endif
/* 121106 HID End */

#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
/*****************************************************************************
 * FUNCTION
 *  dm_disable_small_screen_flatten
 * DESCRIPTION
 *  Disable small screen flattening.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_disable_small_screen_flatten(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_cntx.enable_small_screen_flatten != DM_SMALL_SCREEN_FLATTEN_FORCE_ON)
    {
        g_dm_cntx.enable_small_screen_flatten = DM_SMALL_SCREEN_FLATTEN_OFF;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_enable_small_screen_flatten
 * DESCRIPTION
 *  Enable small screen flattening.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_enable_small_screen_flatten(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dm_cntx.enable_small_screen_flatten != DM_SMALL_SCREEN_FLATTEN_FORCE_ON)
    {
        g_dm_cntx.enable_small_screen_flatten = DM_SMALL_SCREEN_FLATTEN_ON;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dm_force_small_screen_flatten
 * DESCRIPTION
 *  Force small screen flattening. Used only when going back to a small screen 
 *  in the history because the underlying full-screen app must be flattened even
 *  if it calls dm_disable_small_screen_flatten().
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_force_small_screen_flatten(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dm_cntx.enable_small_screen_flatten = DM_SMALL_SCREEN_FLATTEN_FORCE_ON;
}


/*****************************************************************************
 * FUNCTION
 *  dm_unforce_small_screen_flatten
 * DESCRIPTION
 *  Unforce small screen flattening back to the default on state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_unforce_small_screen_flatten(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dm_cntx.enable_small_screen_flatten = DM_SMALL_SCREEN_FLATTEN_ON;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  dm_get_dm_data_flag
 * DESCRIPTION
 *  Get the current dm data flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_get_dm_data_flag(S32* flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *flag = g_dm_data.s32flags;
}

/*****************************************************************************
 * FUNCTION
 *  dm_set_dm_data_flag
 * DESCRIPTION
 *  Set the current dm data flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_set_dm_data_flag(S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dm_data.s32flags = flag;
}


/*****************************************************************************
 * FUNCTION
 *  dm_imui_window_hide
 * DESCRIPTION
 *  This function needs to called after the IMUI window hides itself after display.
 *  It will redraw all the components in the category.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_imui_window_hide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 u8CtrlCt = 0;
    S32 u8NoOfUICtrls = 0;
    S16 *UICtrlAccessPtr_p = NULL, *DeafultCoordinateSet_p = NULL;
    //S32 idx = 0;
    U8 *control_set_ptr = NULL;
    S32 button_count = 0;
    S32 scroll_text_count = 0;
    S32 string_text_count = 0;
    dm_coordinates popup_clip = {0};
    gdi_handle temp_layer_ptr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset((void*)&prev_control_coordinates, 0, sizeof(prev_control_coordinates));

    control_set_ptr = dm_search_control_set((U16) g_dm_data.s32CatId, &DeafultCoordinateSet_p);

    /* First element in Category-Controls map specifies the number of controls */
    u8NoOfUICtrls = control_set_ptr[0];

    UICtrlAccessPtr_p = dm_search_coordinate_set(g_dm_data.s32ScrId);
    if (UICtrlAccessPtr_p == NULL)
    {
        UICtrlAccessPtr_p = DeafultCoordinateSet_p;
    }
    MMI_ASSERT(UICtrlAccessPtr_p != NULL);

    gdi_layer_lock_frame_buffer();

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        0,
        0,
        UI_device_width - 1,
        UI_device_height - 1);

    gdi_layer_get_active(&temp_layer_ptr); 
    #ifdef GDI_USING_LAYER
        //gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_TRANSPARENT);
        gdi_2d_fill_rect_to_act_layer(
            temp_layer_ptr,
            0,
            0,
            UI_device_width,
            UI_device_height,
            255, 
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
            GDI_COLOR_BLACK,
#else
            GDI_COLOR_TRANSPARENT,
#endif
            0,
            NULL);
    #else
        //gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_WHITE);
        gdi_2d_fill_rect_to_act_layer(
            temp_layer_ptr,
            0,
            0,
            UI_device_width,
            UI_device_height,
            255, 
#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
            GDI_COLOR_BLACK,
#else
            GDI_COLOR_WHITE,
#endif
            0,
            NULL);
    #endif

    gdi_layer_pop_clip();
    for (u8CtrlCt = 1; u8CtrlCt <= u8NoOfUICtrls; u8CtrlCt++)
    {
        switch (control_set_ptr[u8CtrlCt])
        {
            case DM_LIST1:
            {
                show_fixed_list();
                break;
            }
            case DM_DYNAMIC_LIST1:
            {
                show_dynamic_list();
                break;
            }
            case DM_ASYNCDYNAMIC_LIST1:
            {
                show_asyncdynamic_list();
                break;
            }
            case DM_MULTILINE_INPUTBOX1:
            {
                if (!get_multiline_inputbox_display_status())
                {
                     break;
                }
                wgui_show_inputbox();
                break;
            }
#ifdef UI_EMS_SUPPORT
            case DM_EMS_INPUTBOX1:
            {
                if (wgui_inputbox_information_flag)
                {
                    wgui_EMS_redraw_input_information_bar();
                }
                show_EMS_inputbox();
                break;
            }
#endif /* UI_EMS_SUPPORT */

#if 1//def __MMI_EDITOR_SINGLINE_SUPPORT__
            case DM_SINGLELINE_INPUTBOX1:
            {
                if (wgui_inputbox_information_flag && (g_dm_data.s32flags & DM_SINGLE_LINE_INPUT_BOX_WITH_INFORMATION_BAR))
                {
                    wgui_redraw_singleline_input_information_bar();         
                }
                show_singleline_inputbox();
                break;
            }
#endif
            case DM_LSK:
            {
                show_left_softkey();
                break;
            }
            case DM_RSK:
            {
                show_right_softkey();
                break;
            }
            case DM_BUTTON:
            {
                dm_redraw_button(button_count++);
                break;
            }
            case DM_TITLE1:
            {
                if ((g_dm_data.s32flags & DM_NO_TITLE))
                {
                    break;
                }
                if (g_dm_data.s32flags & DM_LEFT_ALIGN_TITLE)
                {
                    draw_title_left_align();
                }
                else if (g_dm_data.s32flags & DM_SCROLL_TITLE)
                {
                    setup_scrolling_title();
                    draw_scrolling_title();
                }
                else
                {
                    draw_title();
                }
                break;
            }

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
            case DM_HORIZONTAL_TAB_BAR:
            {
            #ifdef __MMI_TAB_BARS_SUPPORT__
                wgui_show_horizontal_tab_bar();
            #endif
                break;
            }
#endif
            case DM_CATEGORY_CONTROLLED_AREA:
            {
                dm_coordinates coordinate;
                dm_get_control_coordinates_from_category(
                g_dm_data.s32ScrId, g_dm_data.s32CatId, DM_CATEGORY_CONTROLLED_AREA, -1, &coordinate);
                if (dm_category_controlled_area_callback)
                {
                    (*dm_category_controlled_area_callback) (&coordinate);
                }
                break;
            }
            case DM_CATEGORY_CONTROLLED_AREA2:
            {
                dm_coordinates coordinate;
                dm_get_control_coordinates_from_category(
                g_dm_data.s32ScrId, g_dm_data.s32CatId, DM_CATEGORY_CONTROLLED_AREA2, -1, &coordinate);
                if (dm_category_controlled_area2_callback)
                {
                    (*dm_category_controlled_area2_callback) (&coordinate);
                }
                break;
            }
            case DM_STATUS_BAR1:
            {
                if ((g_dm_data.s32flags & DM_NO_STATUS_BAR))
                {
                    break;
                }
                #if !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
                if ((g_dm_data.s32flags & DM_SPECIFIC_HIDE_STATUS_BAR))
                {
                    wgui_status_icon_bar_update();
                }
                else
                {
                     show_title_status_icon();
                }
                #else /* !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) */
                wgui_status_icon_bar_update();
                #endif /* !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) */
                break;
            }
            case DM_BUTTON_BAR1:
            {
                dm_coordinates coordinate;
                dm_get_control_coordinates_from_category(
                g_dm_data.s32ScrId, g_dm_data.s32CatId, DM_BUTTON_BAR1, -1, &coordinate);
                if (!(g_dm_data.s32flags & DM_NO_SOFTKEY))
                {
                    if (!(coordinate.Flags & DM_BUTTON_DISABLE_BACKGROUND))
                    {
                        show_softkey_background();
                        draw_arrow_indication(
                            (S8) (coordinate.Flags & DM_BUTTON_BAR_LEFT_ARROW),
                            (S8) (coordinate.Flags & DM_BUTTON_BAR_RIGHT_ARROW),
                            (S8) (coordinate.Flags & DM_BUTTON_BAR_UP_ARROW),
                            (S8) (coordinate.Flags & DM_BUTTON_BAR_DOWN_ARROW));
                    }
                    show_softkey(MMI_LEFT_SOFTKEY);
                    show_softkey(MMI_RIGHT_SOFTKEY);
                    show_softkey(MMI_CENTER_SOFTKEY);
                #ifdef __MMI_ICON_BAR_SUPPORT__
                    #if defined(__MMI_FTE_SUPPORT__)
                    if(MMI_TRUE == wgui_icon_bar_is_created())
                    {
                        wgui_icon_bar_update();
                    }
                    #endif
                #endif
                }
                break;
            }
            case DM_INLINE_FIXED_LIST1:
            {
                show_fixed_list();
                redraw_current_inline_item();
                break;
            }
            case DM_BASE_CONTROL_SET1:
            {
                dm_setup_and_draw_base_control_set(NULL);
                break;
            }
            case DM_BASE_CONTROL_SET2:
            {
                dm_setup_and_draw_base_control_set2(NULL);
                break;
            }
            case DM_BASE_CONTROL_SET_SUBMENU:
            {
                dm_setup_and_draw_base_control_set_submenu(NULL);
                break;
            }
            case DM_BASE_CONTROL_SET_COMMON:
            {
                dm_setup_and_draw_base_control_set_common(NULL);
                break;
            }
            case DM_STRING:
            {
                dm_coordinates coordinate;
                S16 *cur_UICtrlAccessPtr_p = NULL;
                cur_UICtrlAccessPtr_p = dm_get_control_coordinates_from_category(g_dm_data.s32ScrId, g_dm_data.s32CatId,
                    DM_STRING, string_text_count, &coordinate);
                dm_setup_and_draw_string(&cur_UICtrlAccessPtr_p, string_text_count++);
                break;
            }
            case DM_SCROLL_TEXT:
            {
                dm_play_scroll_text(scroll_text_count++);
                break;
            }
            case DM_POPUP_BACKGROUND:
            {
                popup_clip.s16X = 0;
                popup_clip.s16Y = 0;
                popup_clip.s16Width = UI_device_width;
                popup_clip.s16Height = UI_device_height;    
                dm_popupbg_set_clip(&popup_clip);
                dm_redraw_popup_background();
                break;
            }
        }
    }
    /* if virtual keypad show flag is set, show the virtual keypad */
    if (g_dm_data.s32flags & DM_SHOW_VKPAD)
    {
        if (dm_show_vkpad_callback != NULL)
        {
            dm_show_vkpad_callback();
        }
        /* wgui_show_virtual_keyboard(); */
    }
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}   

/*****************************************************************************
 * FUNCTION
 *  dm_imui_window_display
 * DESCRIPTION
 *  This function needs to called before the IMUI window display
 *  It will stop the scrolling text of dm scrolling text control and
 *  the highlighted list items text and its hint.  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dm_imui_window_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 u8CtrlCt = 0;
    S32 u8NoOfUICtrls = 0;
    S16 *UICtrlAccessPtr_p = NULL, *DeafultCoordinateSet_p = NULL;
    //S32 idx = 0;
    U8 *control_set_ptr = NULL;
    S32 scroll_text_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset((void*)&prev_control_coordinates, 0, sizeof(prev_control_coordinates));

    control_set_ptr = dm_search_control_set((U16) g_dm_data.s32CatId, &DeafultCoordinateSet_p);

    /* First element in Category-Controls map specifies the number of controls */
    u8NoOfUICtrls = control_set_ptr[0];

    UICtrlAccessPtr_p = dm_search_coordinate_set(g_dm_data.s32ScrId);
    if (UICtrlAccessPtr_p == NULL)
    {
        UICtrlAccessPtr_p = DeafultCoordinateSet_p;
    }
    MMI_ASSERT(UICtrlAccessPtr_p != NULL);
    for (u8CtrlCt = 1; u8CtrlCt <= u8NoOfUICtrls; u8CtrlCt++)
    {
        switch (control_set_ptr[u8CtrlCt])
        {
            case DM_LIST1:
            case DM_DYNAMIC_LIST1:
            case DM_ASYNCDYNAMIC_LIST1:
            {
                gui_fixed_icontext_menuitem_stop_scroll();
                gui_pop_up_description_stop_scroll();
                break;
            }
            case DM_SCROLL_TEXT:
            {
                dm_stop_scroll_text(scroll_text_count++);
                break;
            }
        }
    }
}   


#ifdef __DM_SLIM_USE_MULTIPLE_LAYERS__
void dm_enable_fixed_layer_mode(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_enabled)
    {
        dm_setup_base_layer();
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
        dm_setup_and_draw_scr_bg(NULL);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 
    }

    g_dm_cntx.is_fixed_layer_mode = is_enabled;  
    
}

MMI_BOOL dm_is_fixed_layer_mode_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return g_dm_cntx.is_fixed_layer_mode;

}
#endif

void dm_get_main_lcd_data(dm_data_struct *data_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *data_context = g_dm_data;
}

void dm_set_main_lcd_data(dm_data_struct *data_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dm_data = *data_context;
}

void dm_set_sub_lcd_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dm_data = g_dm_sublcd_data;
    g_dm_data.s32flags |= DM_SUB_LCD_CONTEXT;
}



/*****************************************************************************
 * FUNCTION
 *  dm_add_title_id
 * DESCRIPTION
 *  This function is used to add title with IDs
 * PARAMETERS
 *  title_str_id        :    [IN]    Title String ID
 *  title_img_id       :    [IN]    Title Image ID
 * RETURNS
 *  void
 *****************************************************************************/
 //huking
 ///TODO: remove icon
void dm_add_title_id_ex(
	MMI_STR_ID title_str_id
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
	, MMI_IMG_ID title_img_id
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
	)
{
    dm_add_title((UI_string_type)GetString((U16)title_str_id), (PU8)GetImage((U16)title_img_id));
}



/*****************************************************************************
 * FUNCTION
 *  dm_add_softkey_id
 * DESCRIPTION
 *  This function is used to add softkeys with IDs
 * PARAMETERS
 *  lsk_str_id        :    [IN]    LSK String ID
 *  rsk_str_id        :    [IN]    RSK String ID
 * RETURNS
 *  void
 *****************************************************************************/
void dm_add_softkey_id(MMI_STR_ID lsk_str_id, MMI_STR_ID rsk_str_id)
{
    dm_add_softkey((UI_string_type) GetString((U16)lsk_str_id), 
                NULL ,
                (UI_string_type) GetString((U16)rsk_str_id), 
                NULL);
}



/*****************************************************************************
 * FUNCTION
 *  dm_add_softkey_str
 * DESCRIPTION
 *  This function is used to add softkeys with strings
 * PARAMETERS
 *  lsk_str        :    [IN]    LSK String
 *  rsk_str        :    [IN]    RSK String
 * RETURNS
 *  void
 *****************************************************************************/
void dm_add_softkey_str(UI_string_type lsk_str, UI_string_type rsk_str)
{
    dm_add_softkey(lsk_str, NULL, rsk_str, NULL);
}

#ifdef __MMI_SCRIPT_EASY__
#include "gdi_layer.h"
gdi_handle se_mtk_find_underlying_layer(gdi_handle layer)
{
    gdi_handle * layers;
    gdi_handle layer_buffer[4];
    int layer_count = 0;
    int i;

    if (!dm_layers_count)
    {
        memset(layer_buffer, 0xFF, sizeof(layer_buffer));
        layers = layer_buffer;
        layer_count = 4;
        gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);
    }
    else
    {
        layers = layer_buffer;
        for(i = 0; i < dm_layers_count; ++i)
        {
            if(!GDI_LAYER_GET_FLAG(dm_layers[i],GDI_LAYER_FLAG_LAZY_FREE))
            {   
                layers[layer_count++] = dm_layers[i];
            }
        }
    }
        
    for(i = layer_count - 1; i > 0; i--)
    {
        if (layers[i] == layer)
            return layers[i - 1];
    }
    return GDI_ERROR_HANDLE;
}
#endif 

