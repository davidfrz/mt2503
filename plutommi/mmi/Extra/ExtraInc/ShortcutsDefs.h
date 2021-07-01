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
 * ShortcutsDefs.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant and enum value used in Shortcuts application.
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
   * Nov 12 2005 mtk01215
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : ShortcutsDefs.h

   PURPOSE     : Shortcuts application 

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : May 12,03

**************************************************************/
#ifndef _MMI_SHORTCUTSDEFS_H
#define _MMI_SHORTCUTSDEFS_H
#include "MMI_features.h"
#ifndef __DISABLE_SHORTCUTS_IMPL__
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
/* 
 * Define
 */
#define SHCT_COUNT_BYTE                0
#define SHCT_INTEGRITY_BYTE            1
#define SHCT_DATA_BYTE                 2

#define ENABLE_STATE                   1
#define DISABLE_STATE                  0

#define SHCT_DEFAULT_MENU_ID           65534
#define SHCT_NVRAM_SIZE                NVRAM_SHORTCUTS_SIZE
#define MMI_SHCT_MAX_QUICK_MENU_LIST   10
#define MMI_SHCT_MAX_DISPLAY_LIST       60
#define MMI_SHCT_MAX_DYNAMIC_REG_LIST   5
#define SHCT_FOLDER_NAME L"Z:\\@shortcuts\\"

/* 
 * Typedef 
 */

/* Option Ids */
typedef enum
{
    SHR_OPTIONS_ADD = 0,
    SHR_OPTIONS_EDIT,
    SHR_OPTIONS_DELETE,
    SHR_OPTIONS_DELETE_ALL,
    SHR_OPTIONS_ENABLE,
    SHR_OPTIONS_DISABLE,
    SHR_OPTIONS_CHANGE_ORDER,
    SHR_OPTIONS_TOTAL
} OPTION_ID_SHCT_ENUM;


#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
typedef enum
{
    DEDICATED_KEY_UP,
    DEDICATED_KEY_DOWN,
    DEDICATED_KEY_LEFT,
    DEDICATED_KEY_RIGHT,
    TOTAL_DEDICATED_KEYS
} mmi_shct_nav_key_enum;
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */ 

typedef enum
{
    /* SEPCIAL */
    MMI_SHCT_DISPLAY_TYPE_VENUS_SHELL,
    MMI_SHCT_DISPLAY_TYPE_SPECIAL_END,
    /* GENERAL */
    MMI_SHCT_DISPLAY_TYPE_CANDIDATE,
    MMI_SHCT_DISPLAY_TYPE_QUICK_MENU,
    MMI_SHCT_DISPLAY_TYPE_END
} mmi_shct_display_type_enum;

typedef enum
{
    MMI_SHCT_ITEM_TYPE_NONE,
    MMI_SHCT_ITEM_TYPE_MENU,
    MMI_SHCT_ITEM_TYPE_JAVA,
    MMI_SHCT_ITEM_TYPE_BRW_BOOKMARK,
    MMI_SHCT_ITEM_TYPE_TOTAL
} mmi_shct_item_type_enum;


typedef struct
{
    MMI_ID menu_id[MMI_SHCT_MAX_DYNAMIC_REG_LIST];
    U8     unreg_count;
} mmi_shct_dynamic_reg_struct;

typedef struct
{
    MMI_MENU_ID SelShctList[MMI_SHCT_MAX_QUICK_MENU_LIST];
    mmi_shct_dynamic_reg_struct dynamic_reg_list;
    MMI_MENU_ID *edit_list;
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
    MMI_MENU_ID DediShctList[TOTAL_DEDICATED_KEYS];
    U8 CurrSelArrow;
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */ 
    U8 NumSelShct;      /* number of selected shortcut */
    U8 CurrSelShct;     /* current selected shortcut from shortcut list */
    MMI_MENU_ID CurrEditShct;    /* current selected shortcut from candidate list */
    U8 CurrOptionShct;  /* current selected option item */
    U8 Integrity;
    S32 Order;          /* order of selected item */
    /* displayItemNum; */
    void* sel_chct_cb;
    MMI_ID cui_menu_quick_menu_cfg_id;
} shct_context_struct;

#ifdef __J2ME__
#define SHCT_JAVA_MID_STORAGE_NAME_LEN  32
#define SHCT_JAVA_MID_MAP_FILE_NAME L"Z:\\@shortcuts\\shortcuts_java_mid_map.tmp"
typedef struct
{
    MMI_ID java_mid_id;
    S8 java_mid_storage_name[SHCT_JAVA_MID_STORAGE_NAME_LEN];
} mmi_shct_java_mid_map_struct;
#endif /* __J2ME__ */

#if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
#define SHCT_BRW_BKM_MAX_DISPLAY_LEN    32
#define SHCT_BRW_BKM_MAX_TITLE_LEN      128
#define SHCT_BRW_BKM_MAP_FILE_NAME      L"Z:\\@shortcuts\\shortcuts_brw_bkm_map.tmp"
#endif /* defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__) */


/*
 * Extern Global Variable
 */
extern shct_context_struct g_shct_cntx;

extern U32 g_mmi_shct_max_cand_list;

extern const U8 g_mmi_shct_quick_menu_default_list_num;
extern const MMI_MENU_ID g_mmi_shct_quick_menu_default_list[];

#ifdef __MMI_DEDICATED_KEY_SHORTCUTS__
extern const MMI_MENU_ID g_mmi_shct_nav_key_default_list[];
#endif /* __MMI_DEDICATED_KEY_SHORTCUTS__ */

/* 
 * Extern Global Function
 */
#endif /* __DISABLE_SHORTCUTS_IMPL__ */ /* #ifndef __DISABLE_SHORTCUTS_IMPL__ */
#endif /* _MMI_SHORTCUTSDEFS_H */ 

