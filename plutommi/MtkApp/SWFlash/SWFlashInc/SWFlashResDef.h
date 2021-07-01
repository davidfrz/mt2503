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
 *  SWFlashResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Resource definitions.
 *
 *  Author:
 * -------
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef SWFLASHRESDEF_H
#define SWFLASHRESDEF_H

#include "MMI_features.h"   /* add if you use any compile options defined in MMI_features.h */

#ifdef __MMI_SWFLASH__

#include "MMIDataType.h"    /* for resource base */

/***************************************************************************** 
 * Typedef for Resource Enum
 *****************************************************************************/
/* Screen IDs */
typedef enum
{
    SCR_ID_SWFLASH = SWFLASH_BASE + 1,
   
    SCR_ID_SWFLASH_PLAYBACK,
   
    SCR_ID_SWFLASH_OPTION_PLAY,
    SCR_ID_SWFLASH_OPTION_INFO,

    SCR_ID_SWFLASH_PERCENTAGE_BAR,
    SCR_ID_SWFLASH_STORAGE_SELECT,
    SCR_ID_SWFLASH_WAP_PUSH_SELECT_STORSGE,
    SCR_ID_SWFLASH_REPLACE_VIEW,
    SCR_ID_SWFLASH_REPLACE_VIEW_FROM_WAP_PUSH,
    SCR_ID_SWFLASH_DUMMY_SCREEN,
    SCR_ID_SWFLASH_TOTAL
} SWFLASH_SCREEN_ID;

/* String IDs */

typedef enum
{
    STR_ID_SWFLASH = SWFLASH_BASE + 1,
    STR_ID_SWFLASH_APP,
    STR_ID_SWFLASH_PLAYBACK,

    STR_ID_SWFLASH_OPTION,
    STR_ID_SWFLASH_OPTION_INFO,

    STR_ID_SWFLASH_INFO_TITLE,
    STR_ID_SWFLASH_INFO_CATEGORY,
    STR_ID_SWFLASH_INFO_SIZE,
    STR_ID_SWFLASH_INFO_BYTE,
    STR_ID_SWFLASH_INFO_DATE,
    STR_ID_SWFLASH_INFO_TIME,
    STR_ID_SWFLASH_INFO_COMPANY,

    STR_ID_SWFLASH_INFO_CATEGORY_ANIMATION,
    STR_ID_SWFLASH_INFO_CATEGORY_CRAZYGAME,
    STR_ID_SWFLASH_INFO_CATEGORY_KARAOK,
    STR_ID_SWFLASH_INFO_CATEGORY_MOVIECLIP,
    STR_ID_SWFLASH_INFO_CATEGORY_UNKNOWN,

    STR_ID_SWFLASH_NOTIFY_FILE_ERROR,
    STR_ID_SWFLASH_NOTIFY_NETWORK_ERROR,
    STR_ID_SWFLASH_NOTIFY_DISK_FULL,
    STR_ID_SWFLASH_NOTIFY_TOO_BIG,

    STR_ID_SWFLASH_ASK_PLAYBACK,
    STR_ID_SWFLASH_ASK_DOWNLOAD2,
    STR_ID_SWFLASH_ZDD_FILE_INVALID,
    STR_ID_SWFLASH_ZDD_FILE_SAVE_FAIL,
    STR_ID_SWFLASH_ZDD_READ_ONLY,
    STR_ID_SWFLASH_FILE_REPLACE,
    STR_ID_SWFLASH_NETWORK_BUSY,
    STR_ID_SWFLASH_NETWORK_NOT_READY,

    STR_ID_SWFLASH_TOTAL
} SWFLASH_STRING_LIST;

/* Image IDs */

typedef enum
{
    IMG_ID_SWFLASH = SWFLASH_BASE + 1,
    IMG_ID_SWFLASH_APP2,  
    
    IMG_ID_SWFLASH_CAT1_PL,
    IMG_ID_SWFLASH_CAT2_PL,
    IMG_ID_SWFLASH_CAT3_PL,
    IMG_ID_SWFLASH_CAT4_PL,
    IMG_ID_SWFLASH_CAT5_PL,
    IMG_ID_SWFLASH_CAT6_PL,
    IMG_ID_SWFLASH_CAT7_PL,
    IMG_ID_SWFLASH_CAT8_PL,
    IMG_ID_SWFLASH_CAT9_PL,

    IMG_ID_SWFLASH_CAT1_DL,
    IMG_ID_SWFLASH_CAT2_DL,
    IMG_ID_SWFLASH_CAT3_DL,
    IMG_ID_SWFLASH_CAT4_DL,
    IMG_ID_SWFLASH_CAT5_DL,
    IMG_ID_SWFLASH_CAT6_DL,
    IMG_ID_SWFLASH_CAT7_DL,
    IMG_ID_SWFLASH_CAT8_DL,
    IMG_ID_SWFLASH_CAT9_DL,
    
    IMG_ID_SWFLASH_TOTAL
} SWFLASH_IMAGE_LIST;

#endif  /* __MMI_SWFLASH__ */

#endif /* SWFLASHRESDEF_H */ 
