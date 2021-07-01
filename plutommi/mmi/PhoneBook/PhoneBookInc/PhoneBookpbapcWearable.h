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
 *  PhoneBookpbapcWearable.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  PBAPC
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PHONE_BOOK_PBAPC_WEARABLE_H__
#define __PHONE_BOOK_PBAPC_WEARABLE_H__

#include "MMI_features.h"

#if defined(__MMI_BT_PBAP_CLIENT__)

#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__) && defined(__MMI_WEARABLE_DEVICE__)

#include "MMIDataType.h"
#include "MMI_include.h"

#include "MMI_common_app_trc.h"
#include "mmi_rp_app_mainmenu_def.h"

#include "custom_phb_config.h"
#include "mmi_frm_scenario_gprot.h"
#include "MenuCuiGprot.h"

#include "PhbpbapSrvGprot.h"
#include "UcmSrvGprot.h"
#include "SmsUmBtMapProt.h"
#include "SmsAppGprot.h"
#include "UCMGProt.h"
#include "BtcmSrvGprot.h"

#include "Vcard_lib.h"

#include "PhoneBookResDef.h"
#include "mmi_rp_app_phonebook_def.h"
#include "PhoneBookProt.h"
#include "PhbCuiGprot.h"


#define MAX_PHB_PBAPC_MAX_FIELDS                        (5)

#define MMI_PHB_PBAPC_TRACE_GROUP                       TRACE_GROUP_9

#define MMI_PHB_PBAPC_FLAG_LOAD                         (1 << 0)
#define MMI_PHB_PBAPC_FLAG_LOADING                      (1 << 1)
#define MMI_PHB_PBAPC_FLAG_BG_LOADING                   (1 << 2)


typedef struct
{
    U8 bt_index;
    U8 phb_list;
    U8 flag_ext;

    MMI_ID parent_id;
    MMI_ID load_gid;
    MMI_ID load_sid;
    U16 contact_array[SRV_PHB_PBAPC_CONTACT_COUNT];
    U16 contact_count;

    U32 flag[SRV_PHB_PBAPC_LINK_NUM]; /* b0: load; b1: loading; b2: bg loading */

    /* view contact id & releated bt_index */
    U16 cid;
    U8 index;
    S32 hlight_index;
    /* view contact detail */
    mmi_phb_pbapc_phb_info_struct pse_phb;

    srv_phb_pbapc_jump_info_struct jump_info;
    U16 jmp_pos;

    mmi_id cui_id;
} mmi_phb_pbapc_cntx_struct;


/* func */
mmi_phb_pbapc_cntx_struct *mmi_phb_pbapc_get_cntx();

static void mmi_phb_pbapc_show_loading(MMI_ID parent_id, MMI_ID scrn_id);

static void mmi_phb_pbapc_show_connect();

static void mmi_phb_pbapc_show_fail();

static void mmi_phb_pbapc_entry_show_loading();

static void mmi_phb_pbapc_loading_lsk();

static void mmi_phb_pbapc_connect_lsk();

static void mmi_phb_pbapc_fail_lsk();

static void mmi_phb_pbapc_loading_rsk();

static void mmi_phb_pbapc_connect_rsk();

static void mmi_phb_pbapc_fail_rsk();

static void mmi_phb_pbapc_con_profile_cb(srv_bt_cm_bt_addr *dev_addr,
                                                 srv_bt_cm_connection_type conn_type,
                                                 MMI_BOOL result,
                                                 MMI_BOOL is_connect,
                                                 MMI_BOOL is_indicate);

static void mmi_phb_pbapc_show_loading_abort(MMI_ID parent_id, MMI_ID scrn_id);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_phb_pbapc_list_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif

static void mmi_phb_pbapc_show_list();

static S32 mmi_phb_pbapc_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size);

static void mmi_phb_pbapc_list_get_item_int(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2);

static void mmi_phb_pbapc_sync_contact();

static void mmi_phb_pbapc_cancel_sync();

mmi_ret mmi_phb_pbapc_notify_evt_hdlr(mmi_event_struct *evt);

static mmi_ret mmi_phb_pbapc_view_contact_proc(mmi_event_struct *evt);

static MMI_RET mmi_phb_pbapc_view_contact_scrn_proc(mmi_event_struct *evt);

static void mmi_phb_pbapc_get_info(mmi_phb_pbapc_phb_info_struct *phb_info);

static void mmi_phb_pbapc_show_contact_detail();

static void mmi_phb_pbapc_view_contact_highlight_hdlr(S32 index);

static MMI_BOOL mmi_phb_pbapc_set_view_flags(S32 index, U32* flag, U32* flag_ex);

static U16 mmi_phb_pbapc_get_num_type(U8 num_type);

static MMI_BOOL mmi_phb_pbapc_is_connect();

static void mmi_phb_pbapc_view_tap_callback(mmi_tap_type_enum tap_type, S32 index);

mmi_phb_pbapc_cntx_struct *mmi_phb_pbapc_get_cntx();

void mmi_phb_pbapc_alpha_search(mmi_id parent_id);

static mmi_ret mmi_phb_pbapc_alpha_proc(mmi_event_struct *evt);

static MMI_RET mmi_phb_pbapc_alpha_scrn_proc(mmi_event_struct *evt);

static void mmi_phb_pbapc_alpha_show();

static S32 mmi_phb_pbapc_alpha_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size);

static void mmi_phb_pbapc_alpha_get_item_int(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2);

#if 0
/* under construction !*/
#endif

static void *mmi_phb_pbapc_alpha_tap_callback(S32 index);

static S32 mmi_phb_pbapc_alpha_get_hint(S32 item_index, UI_string_type *hint_array);

/* bqb test func */

MMI_BOOL mmi_pbapc_is_bqb_test();

void mmi_pbapc_bqb_start();

static mmi_ret mmi_pbapc_bqb_grp_proc();

static mmi_ret mmi_pbapc_bqb_scr_proc(mmi_event_struct *evt);

static void mmi_pbapc_bqb_show();

static void mmi_pbapc_bqb_highlight_hdlr(S32 index);

static void mmi_pbapc_bqb_option();

static void mmi_pbapc_bqb_back();

static void mmi_pbapc_bqb_read_folder();

static S32 mmi_pbapc_bqb_read_folder_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data);

static void mmi_pbapc_bqb_abort();

static void mmi_pbapc_bqb_disconnect();

/* for phonebook list */

void mmi_phb_pbapc_entry_list_tab(void);

#endif /* defined(__MMI_PHB_PBAPC_SYNC_CONTACT__) && defined(__MMI_WEARABLE_DEVICE__) */

#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

#endif /* __PHONE_BOOK_PBAPC_WEARABLE_H__ */

