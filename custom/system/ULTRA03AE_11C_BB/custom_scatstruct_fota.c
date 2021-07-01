/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_scatstruct_fota.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the scatter file dependent APIs for FOTA
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
 * removed!
 * removed!
 * removed!
 *
 ****************************************************************************/


#include "kal_general_types.h"


#ifdef __MTK_TARGET__
#if defined(__FUE__)

/*******************************************************************************
 * Define import global data.
 *******************************************************************************/

/*This linker sybmol is only used for Cortex-R series and ARM-provided MPU*/
extern kal_uint32 Image$$UA_INTSRAM_CODE$$Base;
extern kal_uint32 Image$$UA_INTSRAM_CODE$$Length;
extern kal_uint32 Image$$UA_INTSRAM_DATA$$Base;
extern kal_uint32 Image$$UA_INTSRAM_DATA$$Length;


/*************************************************************************
* FUNCTION
*  custom_get_UA_INTSRAM_CODE_Base
*
* DESCRIPTION
*  Retrieve the base address of UA_INTSRAM_CODE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_UA_INTSRAM_CODE_Base(void)
{
    return 0x70008000;
}

/*************************************************************************
* FUNCTION
*  custom_get_UA_INTSRAM_CODE_Length
*
* DESCRIPTION
*  Retrieve the MAX Length of UA_INTSRAM_CODE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_UA_INTSRAM_CODE_Length(void)
{
    return 0x00001300;
}
/*************************************************************************
* FUNCTION
*  custom_get_UA_INTSRAM_DATA_Base
*
* DESCRIPTION
*  Retrieve the base address of UA_INTSRAM_DATA
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_UA_INTSRAM_DATA_Base(void)
{
    return 0x70009300;
}

/*************************************************************************
* FUNCTION
*  custom_get_UA_INTSRAM_DATA_Length
*
* DESCRIPTION
*  Retrieve the END address of UA_INTSRAM_DATA
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_UA_INTSRAM_DATA_Length(void)
{
    return 0x00000D00;
}

#endif /* __FUE__ */
#endif /* __MTK_TARGET__ */
