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
 *   maui_GFH_body.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain the GFH body and content for tiny system parts
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __SV5_ENABLED__

#include "br_GFH_file_info.h"
#include "br_GFH_UBIN_info.h"
#include "GFH_defs.h"
#include "UBIN_GFH_body.h"
#include "custom_img_config.h"
#include "kal_general_types.h"
#include "custom_scatstruct.h"
#include "custom_featureconfig.h"
#include "verno.h"
#include "ubin_verno.h"

//==============================================================================
// Linker symbols
//==============================================================================
//Need check with yinli
extern kal_uint32 Load$$UB_ROM_GFH$$Base;
extern kal_uint32 Image$$UB_ROM_GFH$$Length;

#define UBIN_VERSION 1

//==============================================================================
// Smart watch tiny system GFH header body
//==============================================================================
#pragma arm section rodata = "UB_ROM_GFH"

const UBIN_GFH g_ubin_gfh =
{
      // GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),  // GFH_Header m_gfh_hdr
         GFH_FILE_INFO_ID,              // char m_identifier[12]

         UBIN_VERSION,                  // U32 m_file_ver
         IOT_UBIN_BIN,                  // GFH_FILE_TYPE m_file_type
         FLASH_DEV_NONE,                // GFH_FLASH_DEV m_flash_dev
         SIG_NONE,                      // GFH_SIG_TYPE m_sig_type

         (kal_uint32)(&Load$$UB_ROM_GFH$$Base),      // m_load_addr, must be at bank1
         GFH_FILE_SIZE_BY_POST_BUILD,                       // m_file_len
         GFH_FILE_MAX_SIZE_IGNORED,                         // m_max_size
         (kal_uint32)(&Image$$UB_ROM_GFH$$Length),          // m_content_offset (UBIN symbol table address)
         SIG_NONE_LEN,                                      // m_sig_len
         0,                                                 // m_jump_offset
         0                                                  // m_attr
      },

      // GFH_UBIN_INFO_v1
      {
         GFH_HEADER(GFH_UBIN_INFO, 1),                  // GFH_Header m_gfh_hdr
         BUILD_DATE_TIME_STR,                           // m_mbin_build_time
         VERNO_STR,                                     // m_mbin_project_id
         UBIN_BUILD_DATE_TIME_STR,                      // m_ubin_build_time
         ((CONFIG_IOTFOTA_UB_ROM_SIZE) & ~(4096 - 1))   // m_ubin_max_size
      },
};

#pragma arm section rodata


#pragma arm section zidata = "UB_DUMMY_SYMBOL"
volatile kal_uint32 ubin_dummy_data = 0;
#pragma arm section zidata

//==============================================================================
//Signature
//==============================================================================
kal_char * ubin_get_mbin_verno(void)
{
    return (kal_char *)(g_ubin_gfh.gfh_ubin_info.m_mbin_project_id);
}

kal_char * ubin_get_ubin_build_time(void)
{
    return (kal_char *)(g_ubin_gfh.gfh_ubin_info.m_ubin_build_time);
}


//==============================================================================
// Public APIs
//==============================================================================


//==============================================================================
// Dummy reference
//==============================================================================
kal_uint32 UBIN_DummyReference()
{
    kal_uint32 size = 0;
    size += (kal_uint32)(&g_ubin_gfh) + (kal_uint32)(&ubin_dummy_data);
    return size;
}

#endif /* __SV5_ENABLED__ */
