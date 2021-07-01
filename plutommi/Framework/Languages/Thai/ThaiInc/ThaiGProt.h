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
 *  ThaiGProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Langauge module Thai header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef THAI_GPROT_H
#define THAI_GPROT_H
#include "MMI_features.h"
#include "MMIDatatype.h"
#include "gui_data_types.h"
#include "wgui_inputs.h" /* for MAX_MULTITAPS */

/* RHR */
#include "kal_general_types.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define THAI_CHARACTER_UCS2_RANGE(x)     ( (((U16)(x) > 0x0E01) &&((U16)(x) < 0x0E5B))?(1) : (0) )
#define THAI_CHAR_RANGE(x) (((x) >= 0x0E01 && (x) <= 0x0E5B) || (x) == 0xF70F || (x) == 0xF700)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern MMI_BOOL IsThaiToneMark(U16 ch);
extern MMI_BOOL IsThaiBaseLineChar(U16 ch);
extern MMI_BOOL IsThaiAboveLineChar(U16 ch);
extern MMI_BOOL IsThaiBottomLineChar(U16 ch);
extern MMI_BOOL IsThaiLongTailChar(U16 ch);
extern MMI_BOOL IsThaiDigitChar(U16 ch);
extern MMI_BOOL IsThaiBaseSignChar(U16 ch);
extern MMI_BOOL HaveThaiCharacter(U16 *str);
extern BOOL IsThaiUpSign(U16 ch);
extern BOOL IsThaiSignChar(U16 ch);
extern BOOL IsThaiBaseLineVowel(U16 ch);
extern MMI_BOOL IsThaiUpVowel(U16 ch);
extern MMI_BOOL IsThaiUpDownVowel(U16 ch);
extern MMI_BOOL IsThaiConsonant(U16 ch);

extern UI_character_type *get_thai_multitap_string(S32 i);
extern UI_character_type *get_thai_multitap_string_for_vk(S32 i);

extern const UI_character_type default_multitap_thai_strings_normal[MAX_MULTITAPS][32];
extern S32 thai_get_cluster(UI_string_type string, S32 start, S32 end);


/***************************************************************************** 
* Global Function
*****************************************************************************/

#endif /* THAI_GPROT_H */ 



