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
 *  CallLogPbapc.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/

#include "MMI_features.h"

#if defined(__MMI_BT_PBAP_CLIENT__)
#include "Custom_events_notify.h"
#include "AlertScreen.h"
#include "PhbpbapSrvGprot.h"
#if defined ( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "wgui_touch_screen.h"
#endif /*defined ( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)*/
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_rp_app_calllog_def.h"
#include "string.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_popup.h"
#include "CallLogAdpPbapc.h"
#include "CallLogProt.h"
#ifdef __MMI_BT_MAP_CLIENT__
#include "SmsUmBtMapGProt.h"
#endif /*__MMI_BT_MAP_CLIENT__*/
#ifdef __MMI_BT_DIALER_SUPPORT__
#include "UcmGProtBT.h"
#endif /*__MMI_BT_DIALER_SUPPORT__*/
#include "BTMMIScrGprots.h"
#include "MMI_common_app_trc.h"
#include "wgui_categories_popup.h"
#include "CallLogGprot.h"
#include "UcmGprot.h"
#include "PhbCuiGprot.h"
#include "SmsAppGprot.h"
#include "CallLogAdpProt.h"
#include "CallLogLayout.h"
#ifdef __MMI_BT_NOTI_SRV__
#include "BTNotiSrvGprot.h"
#endif
#include "PhbpbapSrvGprot.h"
#include "Mmi_rp_app_bluetooth_def.h"

typedef struct
{
    U16 sel_log_idx;
    srv_phb_pbap_storage_enum sel_lt_storage;    
    MMI_ID self_gid;
    U32 total_num; /* total log count in current screen */    
} mmi_clog_pbapc_lt_inst_struct;

typedef struct
{
    MMI_ID parent_gid;
    U16 log_idx; /* if 0, means empty */
} mmi_clog_pbapc_op_inst_struct;

typedef struct
{
    U16 log_idx;
    WCHAR *buf;
} mmi_clog_pbapc_vr_inst_struct;


static mmi_clog_pbapc_lt_inst_struct g_mmi_clog_pbapc_lt_inst;
static mmi_clog_pbapc_op_inst_struct g_mmi_clog_pbapc_op_inst;
static mmi_clog_pbapc_vr_inst_struct g_mmi_clog_pbapc_vr_inst;
mmi_clog_pbapc_processing_inst_struct g_mmi_clog_pbapc_processing_inst;
static mmi_clog_reslove_hlt_item_struct g_mmi_clog_need_save_hlt_idx;
void mmi_clog_prepare_data(MMI_MENU_ID sel_menu_id, MMI_ID gid);
static void mmi_clog_pbapc_lt_show_list(void);
void mmi_clog_bt_compare_log_by_timestamp(S32 ret);

static void mmi_clog_pbapc_entry_show_processing(void);

static MMI_RET mmi_clog_pbapc_lt_group_proc(mmi_event_struct *evt);
static void mmi_clog_pbapc_read_cb(S32 result);
static void mmi_clog_pbapc_lt_item_hlt_hdlr(S32 sel);
static void mmi_clog_pbapc_lt_lsk_hdlr(void);
static void mmi_clog_pbapc_lt_csk_hdlr(void);
static void mmi_clog_pbapc_lt_rsk_hdlr(void);
static S32 mmi_clog_pbapc_lt_get_multi_log_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 item_count);
static S32 mmi_clog_pbapc_lt_get_log_hint(S32 item_index, UI_string_type *hint_array);
#ifdef __MMI_CLOG_TAB_SUPPORT__
static void mmi_clog_pbapc_processing_show(MMI_ID parent_id, MMI_ID scrn_id, mmi_clog_pbapc_op_type_enum type, srv_phb_pbap_storage_enum sel_lt_storage);
#endif

void mmi_clog_pbapc_processing_abort(void);

#if defined ( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_clog_pbapc_lt_tap_action_hdlr(mmi_tap_type_enum tap_type, S32 index);
static void mmi_clog_pbapc_lt_set_tap_hdlr(void);
#endif /*defined ( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)*/
static MMI_ID mmi_clog_pbapc_op_enter(MMI_ID parent_gid, mmi_clog_pbapc_op_type_enum type, U16 log_idx);
static void mmi_clog_pbapc_viewer_enter(MMI_ID parent_gid, U16 log_idx);
static void mmi_clog_pbapc_make_call(U16 caller_gid,U16 log_idx, MMI_BOOL is_send_key);
static void mmi_clog_pbapc_send_sms(mmi_id parent_gid, U16 log_idx);
static void mmi_clog_pbapc_vr_show_text(void);
#ifdef __MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__
static S32 mmi_clog_pbapc_vr_format_type(srv_phb_pbapc_clog_struct *log, U32 *cur_len);
#endif /*__MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__*/
static S32 mmi_clog_pbapc_vr_format_name(srv_phb_pbapc_clog_struct *log, U32 *cur_len);
static S32 mmi_clog_pbapc_vr_format_number(srv_phb_pbapc_clog_struct *log, U32 *cur_len);
static S32 mmi_clog_pbapc_vr_format_time(srv_phb_pbapc_clog_struct *log, U32 *cur_len);
#if 0
#ifdef __MMI_CLOG_TAB_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_CLOG_TAB_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CLOG_TAB_SUPPORT__ */
/* under construction !*/
#endif

static MMI_IMG_ID mmi_clog_pbapc_lt_get_img_by_call_type(mmi_clog_pbapc_clt_enum call_type);

static void mmi_clog_send_key_hdler();
static void mmi_clog_pbapc_make_bt_call(U16 caller_gid, U16 log_idx);
static void mmi_clog_act_make_call_cb(mmi_ucm_after_make_call_cb_struct *para);
static MMI_RET mmi_clog_act_pbap_group_proc(mmi_event_struct *evt);
static void mmi_clog_pbapc_op_evt_mm_select_hdlr(cui_menu_event_struct *evt);
static MMI_RET mmi_clog_pbapc_send_key_group_proc(mmi_event_struct *evt);
#ifdef __MMI_HF_SUPPORT__
void mmi_clog_update_log_by_end_call(srv_ucm_bt_release_call_ind_struct *para);
#endif
void mmi_clog_pbapc_show_category(S32 error_code, U8 *gui_buffer);
void mmi_clog_pbapc_processing_show_ex(MMI_ID parent_id, mmi_clog_pbapc_op_type_enum type, srv_phb_pbap_storage_enum sel_lt_storage);
#if 0
/* under construction !*/
/* under construction !*/
#endif

extern mmi_clog_get_last_num_struct g_mmi_clog_get_last_info;
S32 g_local_index;
extern mmi_clog_rsp_missed_call g_is_missed_call;
#ifdef __MMI_BT_NOTI_SRV__
#if SRV_PBAPC_LINK_NUM >= 2
extern NMGR_HANDLE bt_nmgr_handle[SRV_PBAPC_LINK_NUM];
#else
extern  NMGR_HANDLE bt_nmgr_handle ;
#endif

#ifdef __MMI_WEARABLE_DEVICE__
extern srv_bt_noti_missed_call_evt_struct g_bt_noti;
#endif
#endif /*__MMI_BT_NOTI_SRV__*/

mmi_clog_pbapc_ex_inst_struct g_mmi_clog_pbapc_cntx_ex_cb;
mmi_clog_pbapc_ex_inst_struct g_mmi_clog_pbapc_cntx_ex;
//mmi_clog_pbapc_cntx_struct g_mmi_clog_pbapc_cntx;

static S32 mmi_clog_pbapc_read_folder_cb(srv_phb_pbapc_load_clog_rsp *folder_rsp, void *user_data);

static pBOOL mmi_clog_pbapc_lt_get_log_item(S32 item_index, UI_string_type str_buff, U8 **img_buff_p, U8 str_img_mask);

void mmi_clog_bt_dialer_show(mmi_clog_lt_inst_struct *inst);
#ifdef __MMI_WEARABLE_DEVICE__
static void mmi_clog_bt_link_conn_screen();
#endif
#ifdef __MMI_WEARABLE_DEVICE__
static void mmi_clog_bt_show_list_in_disconn();
#else
static void mmi_clog_bt_show_list_in_disconn(mmi_clog_lt_inst_struct *inst, mmi_clog_lt_bt_tab_page_struct *page);
#endif
static void mmi_clog_bt_dialer_parse_file(MMI_MENU_ID sel_menu_id, U16 *path);
static void mmi_clog_bt_link_lsk_hdlr(void);
static void mmi_clog_bt_link_conn_profile_lsk_hdlr();
static void mmi_clog_bt_link_conn_profile_cb(srv_bt_cm_bt_addr *dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result, MMI_BOOL is_connect, MMI_BOOL is_indicate);
//void mmi_clog_bt_link_no_conn_show_list(mmi_clog_lt_inst_struct *inst, mmi_clog_lt_bt_tab_page_struct *page);
static void mmi_clog_bt_pbapc_build_list();
static void mmi_clog_pbapc_clear_missed_call(mmi_clog_lt_inst_struct *inst);
static S32 mmi_clog_bt_pbap_set_index_cb(srv_pbapc_query_req_struct *req);
static S32 mmi_clog_pbapc_is_connect();
static void  mmi_clog_pbapc_get_info(srv_phb_pbapc_clog_struct  *clog_info);

srv_phb_pbapc_clt_enum mmi_clog_pbapc_menu_to_storage_path(MMI_MENU_ID sel_menu_id);
static srv_phb_pbap_storage_enum mmi_clog_pbapc_clt_to_storage_path(srv_phb_pbapc_clt_enum clt);


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define MMI_CLOG_PBAPC_VR_TEMP_BUF_LEN                        (256)
#define MMI_CLOG_PBAPC_VR_TEMP_BUF_SIZE                       ((MMI_CLOG_PBAPC_VR_TEMP_BUF_LEN + 1) * ENCODING_LENGTH)
#define MMI_CLOG_PBAPC_VR_BUF_MAX_LEN                         (MMI_CLOG_PBAPC_CID_MAX_LEN + MMI_CLOG_PBAPC_NAME_MAX_LEN + 200)
#define MMI_CLOG_PBAPC_VR_BUF_MAX_SIZE                        ((MMI_CLOG_PBAPC_VR_BUF_MAX_LEN + 1) * ENCODING_LENGTH)
#define MMI_CLOG_PBAPC_VR_FORMAT_DATA_LEN                     (sizeof("\n\n\n") - 1)

typedef S32(*MMI_CLOG_PBAPC_VR_FORMAT_TEXT_PARA_HDLR) (srv_phb_pbapc_clog_struct *log, U32 *cur_len);

//extern mmi_clog_pbap_clog_info_cache_struct g_mmi_clog_pbapc_clog_info_cache[MMI_CLOG_PBAPC_ENTRIES];

static const MMI_CLOG_PBAPC_VR_FORMAT_TEXT_PARA_HDLR g_mmi_clog_pbapc_vr_format_text_tbl[] = 
{
#ifdef __MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__
	mmi_clog_pbapc_vr_format_type,
#endif /*__MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__*/
    mmi_clog_pbapc_vr_format_name,
    mmi_clog_pbapc_vr_format_number,
    mmi_clog_pbapc_vr_format_time,
};

#define MMI_CLOG_PBAPC_MAIMENU_UI

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
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
    #ifndef __MMI_CLOG_TAB_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_CLOG_TAB_SUPPORT__ */
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
 *  mmi_clog_pbapc_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_enter(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLOG_TAB_SUPPORT__
    memset(&g_mmi_clog_pbapc_lt_inst, 0x00, sizeof(mmi_clog_pbapc_lt_inst_struct));

    g_mmi_clog_pbapc_lt_inst.self_gid = mmi_frm_group_create_ex(gid, 
                    GRP_ID_CLOG_PBAPC_LT, 
                    mmi_clog_pbapc_lt_group_proc, 
                    NULL, 
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(g_mmi_clog_pbapc_lt_inst.self_gid, 
                    SCR_ID_CLOG_PBAPC_LT, 
                    (FuncPtr)mmi_clog_pbapc_lt_tab_enter, 
                    NULL);
#else /* __MMI_CLOG_TAB_SUPPORT__ */
    menu_gid = cui_menu_create(gid,
                     CUI_MENU_SRC_TYPE_RESOURCE,
                     CUI_MENU_TYPE_APPSUB,
                     MEMU_ID_CLOG_PBAPC,
                     MMI_TRUE,
                     NULL);
        
    cui_menu_set_default_title_by_id(menu_gid, STR_ID_CLOG_CALL_LOG, GetRootTitleIcon(MAIN_MENU_CALL_LOG));
    
    cui_menu_set_default_left_softkey_by_id(menu_gid, STR_GLOBAL_OK);
    
    cui_menu_run(menu_gid);
#endif /* __MMI_CLOG_TAB_SUPPORT__ */
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid         [IN]   
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_to_storage_path
 * DESCRIPTION
 *  
 * PARAMETERS      
 *  sel_menu_id         [IN]        
 * RETURNS
 *  srv_phb_pbap_storage_enum
 *****************************************************************************/
srv_phb_pbapc_clt_enum mmi_clog_pbapc_menu_to_storage_path(MMI_MENU_ID sel_menu_id)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sel_menu_id)
    {
        case MENU_ID_CLOG_PBAPC_DIALED_CALL:
            return SRV_PHB_PBAPC_CLT_DIALED;
        case MENU_ID_CLOG_PBAPC_MISSED_CALL:
            return SRV_PHB_PBAPC_CLT_MISSED;
        case MENU_ID_CLOG_PBAPC_RECVED_CALL:
            return SRV_PHB_PBAPC_CLT_RECVED;
        case MENU_ID_CLOG_PBAPC_ALL_CALL:
            return SRV_PHB_PBAPC_CLT_ALL;
        default:
            {
                EXT_ASSERT(0, 0, 0, 0);
            } 
            break;
    }
    return SRV_PHB_PBAP_STORAGE_PHONE_CCH;
}


static srv_phb_pbap_storage_enum mmi_clog_pbapc_clt_to_storage_path(srv_phb_pbapc_clt_enum clt)
{
    switch (clt)
    {
        case SRV_PHB_PBAPC_CLT_DIALED:
            return SRV_PHB_PBAP_STORAGE_PHONE_OCH;
        case SRV_PHB_PBAPC_CLT_MISSED:
            return SRV_PHB_PBAP_STORAGE_PHONE_MCH;
        case SRV_PHB_PBAPC_CLT_RECVED:
            return SRV_PHB_PBAP_STORAGE_PHONE_ICH;
        case SRV_PHB_PBAPC_CLT_ALL:
            return SRV_PHB_PBAP_STORAGE_PHONE_CCH;
        default:
            {
               break;
            } 
            
    }
    return SRV_PHB_PBAP_STORAGE_NULL;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_select_hdlr
 * DESCRIPTION
 *  change static to not static
 * PARAMETERS      
 *  sel_menu_id         [IN]        
 * RETURNS
 * add para gid to test ehy not show processing and change static to non-static
 *  
 *****************************************************************************/
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
#endif

static void mmi_clog_pbapc_prepare_data(srv_phb_pbap_storage_enum lt_storage, MMI_ID gid)
{
    U8 index;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = NULL;
    clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    index = clog_pbapc_cntx->index;
#ifdef __MMI_WEARABLE_DEVICE__
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_IS_IN_BACKWARD, clog_pbapc_cntx->is_cancel, mmi_frm_is_in_backward_scenario(),index,clog_pbapc_cntx->flag[index]);
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_IS_IN_BACKWARD,-1, -1,gid,-1);
#else
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_IS_IN_BACKWARD, gid, mmi_frm_is_in_backward_scenario(),index,clog_pbapc_cntx->flag[index]);
#endif
    if (!(clog_pbapc_cntx->flag[index] & MMI_CLOG_PBAPC_FLAG_BG_LOAD))// two times & not first enter 
    {
        mmi_clog_pbapc_processing_show_ex(gid,MMI_CLOG_PBAPC_OP_TYPE_LT_LIST, lt_storage);
    }

    if (gid)
    {
        g_mmi_clog_pbapc_lt_inst.self_gid = gid;
    }    
    //mmi_clog_pbapc_init();
    if (mmi_frm_is_in_backward_scenario() 
#ifdef __MMI_WEARABLE_DEVICE__
       && !clog_pbapc_cntx->is_cancel
#endif
      )
    {
        g_mmi_clog_need_save_hlt_idx.is_need_save_idx = MMI_TRUE;
    }
    else
    {
        g_mmi_clog_need_save_hlt_idx.is_need_save_idx = MMI_FALSE;
    }
    

}


static void mmi_clog_pbapc_read_data(srv_phb_pbap_storage_enum lt_storage, MMI_ID gid)
{
    U8 index;
    mmi_clog_pbapc_ex_inst_struct *clog_cntx = mmi_clog_get_pbapc_cntx_ex();
    index = clog_cntx->index;
    mmi_clog_pbapc_prepare_data(lt_storage,gid);
    memset(&g_mmi_clog_pbapc_cntx_ex_cb,0x00,sizeof (mmi_clog_pbapc_ex_inst_struct));
    memcpy(&g_mmi_clog_pbapc_cntx_ex_cb, &g_mmi_clog_pbapc_cntx_ex, sizeof (mmi_clog_pbapc_ex_inst_struct));
    
    clog_cntx->flag[index] |= MMI_CLOG_PBAPC_FLAG_LOADING;
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BD_READ_DATA, index, clog_cntx->flag[index]);
    srv_phb_pbapc_load_clog(index,  mmi_clog_pbapc_read_folder_cb, &g_mmi_clog_pbapc_cntx_ex_cb);
   
}



static S32 mmi_clog_pbapc_read_folder_cb(srv_phb_pbapc_load_clog_rsp *folder_rsp, void *user_data)
{
    U8 index ;
    mmi_clog_pbapc_ex_inst_struct *cb_pbapc_cntx = NULL; 
    mmi_clog_pbapc_ex_inst_struct *pbapc_cntx = NULL;
    pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();

    cb_pbapc_cntx = (mmi_clog_pbapc_ex_inst_struct *)user_data;
    index = cb_pbapc_cntx->index;
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BD_READ_DATA_CB, pbapc_cntx->index, pbapc_cntx->flag[index], folder_rsp->ret);
    if (pbapc_cntx->index == cb_pbapc_cntx->index)// if fail and read firt , it  will loading always
    {
        pbapc_cntx->flag[index]&= ~(MMI_CLOG_PBAPC_FLAG_LOADING|MMI_CLOG_PBAPC_FLAG_BG_LOAD);
        pbapc_cntx->flag[index]|= MMI_CLOG_PBAPC_FLAG_LOAD;
        mmi_clog_pbapc_processing_abort();
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
#ifdef __MMI_WEARABLE_DEVICE__
/* under construction !*/
#endif
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


#define MMI_CLOG_PBAPC_LT_UI

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_clog_pbapc_lt_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {     
#if 0
/* under construction !*/
#endif
        memset(&g_mmi_clog_pbapc_lt_inst, 0 , sizeof(mmi_clog_pbapc_lt_inst_struct));        
    }
  
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_item_hlt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_item_hlt_hdlr(S32 sel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_clog_struct clog_info;
    U16 cid;
    mmi_clog_pbapc_ex_inst_struct *clog_cntx = mmi_clog_get_pbapc_cntx_ex();
    
    g_mmi_clog_pbapc_lt_inst.sel_log_idx = sel;
    clog_cntx->store_index = clog_cntx->clog_array[sel];
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_HIGH_LIGHT, sel, clog_cntx->store_index);
    g_mmi_clog_need_save_hlt_idx.call_info = &(g_mmi_clog_need_save_hlt_idx.save_info);
    mmi_clog_pbapc_get_info(&clog_info);
    memcpy(&clog_cntx->pse_info,&clog_info,sizeof(srv_phb_pbapc_clog_struct));
    memcpy(g_mmi_clog_need_save_hlt_idx.call_info, &clog_info, sizeof(srv_phb_pbapc_clog_struct));
    //g_mmi_clog_need_save_hlt_idx.call_info = g_mmi_clog_pbapc_clog_info_cache[sel].clog_info;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_title_by_lt_id
 * DESCRIPTION
 *  
 * PARAMETERS        
 *  lt_storage       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_STR_ID mmi_clog_pbapc_lt_get_title_by_storageID(srv_phb_pbap_storage_enum lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_SHOW_LIST, lt_storage, 0);
    switch(lt_storage)
	{
		case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            return STR_GLOBAL_DIALLED_CALLS;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            return STR_GLOBAL_MISSED_CALLS;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            return STR_GLOBAL_RECEIVED_CALLS;
        case SRV_PHB_PBAP_STORAGE_PHONE_CCH:
            return STR_ID_CLOG_ALL_CALL;
        default:
            break;
	}
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_img_by_lt_id
 * DESCRIPTION
 *  
 * PARAMETERS        
 *  lt_storage       [IN]        
 * RETURNS
 *  MMI_IMG_ID
 *****************************************************************************/
static MMI_IMG_ID mmi_clog_pbapc_lt_get_img_by_lt_storage(srv_phb_pbap_storage_enum lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(lt_storage)
	{
		case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            return IMG_ID_CLOG_DIALED_CALL;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            return IMG_ID_CLOG_MISSED_CALL;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            return IMG_ID_CLOG_RECVED_CALL; 
        case SRV_PHB_PBAP_STORAGE_PHONE_CCH:
            return IMG_ID_CLOG_ALL_CALL;
        default:
            break;
	}
    return 0;
}


static U16 mmi_clog_pbapc_lt_get_index_by_storage(srv_phb_pbap_storage_enum lt_storage)
{
    U16 index;
    switch(lt_storage)
	{
		case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            index = 0;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            index = 1;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            index = 2; 
        case SRV_PHB_PBAP_STORAGE_PHONE_CCH:
            index = 3;
        default:
            break;
	}
    return index;
}


static MMI_IMG_ID mmi_clog_pbapc_lt_get_img_by_call_type(mmi_clog_pbapc_clt_enum call_type)
{
    switch(call_type)
    {
        case MMI_CLOG_PBAPC_CLT_DIALED:
            return IMG_ID_CLOG_DIALED_CALL;
        case  MMI_CLOG_PBAPC_CLT_MISSED:
            return IMG_ID_CLOG_MISSED_CALL;
        case  MMI_CLOG_PBAPC_CLT_RECVED: 
            return IMG_ID_CLOG_RECVED_CALL;
        case MMI_CLOG_PBAPC_CLT_ALL:
            return IMG_ID_CLOG_ALL_CALL;
        default:
            return IMG_ID_CLOG_UNKOWN_CALL;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_string
 * DESCRIPTION
 *  
 * PARAMETERS     
 *  log             [IN]     
 *  str_buff        [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_get_string(srv_phb_pbapc_clog_struct *call_log, WCHAR *str_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR post[20];
    U32 post_len = 0;   
    const WCHAR *unknown_cid;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (call_log->name[0] == '\0' && call_log->cid[0] == '\0')
    {
        unknown_cid = (const WCHAR*)get_string(STR_ID_CLOG_UNKNOWN_NUMBER);	
        mmi_wcsncpy((WCHAR*) str_buff, unknown_cid, MAX_SUBMENU_CHARACTERS);
    }
    else if (call_log->name[0] == '\0')
    {
    
        if (call_log->cid[0] == '-')
        {
            unknown_cid = (const WCHAR*)get_string(STR_ID_CLOG_INVALID_NUMBER);
            mmi_wcsncpy((WCHAR*) str_buff, unknown_cid, MAX_SUBMENU_CHARACTERS);
        }
        else
        {
            mmi_asc_n_to_wcs((WCHAR*) str_buff, (CHAR*)call_log->cid, (MAX_SUBMENU_CHARACTERS - post_len));
        }

    }
    else
    {
        if (call_log->name[0] == '-')
        {
            unknown_cid = (const WCHAR*)get_string(STR_ID_CLOG_INVALID_NUMBER);
            mmi_wcsncpy((WCHAR*) str_buff, unknown_cid, MAX_SUBMENU_CHARACTERS);
        }
        else
        {
            mmi_wcsncpy((WCHAR*) str_buff, (const WCHAR*)call_log->name, MAX_SUBMENU_CHARACTERS - post_len);
        }
    }

    if (post_len)
        mmi_wcscat((WCHAR*) str_buff, (const WCHAR*)post);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_log_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
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
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
/* under construction !*/
#else /**/
/* under construction !*/
#endif /**/
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
 *  mmi_clog_pbapc_lt_get_multi_log_items
 * DESCRIPTION
 *  Asyncdynamic list item load function
 * PARAMETERS
 *  start_index      :    [IN]     Start index of menu item
 *  menu_data        :    [OUT]    A pointer of parameter to store the menu data
 *  item_count        :    [IN]     The number of load menu items
 * RETURNS
 *  S32
 * RETURN VALUES
 *  Number of items can be retrieved
 *****************************************************************************/
S32 mmi_clog_pbapc_lt_get_multi_log_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 item_count)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 total_count;
    S32 i, items = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_count = (S32) g_mmi_clog_pbapc_lt_inst.total_num;
    
    for (i = start_index; items < item_count && i < total_count; i++, items++)
    {
        mmi_clog_pbapc_lt_get_log_item(i, 
            menu_data[items].item_list[0], 
            menu_data[items].image_list, 0);
    }
    return items;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_log_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
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
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
/* under construction !*/
#else /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/
/* under construction !*/
#endif /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/    
/* under construction !*/
/* under construction !*/
#ifdef __MMI_WEARABLE_DEVICE__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_WEARABLE_DEVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_clog_pbapc_op_enter(GRP_ID_CLOG_PBAPC_LT, MMI_CLOG_PBAPC_OP_TYPE_LT_LIST, g_mmi_clog_pbapc_lt_inst.sel_log_idx);//MODIFY
    MMI_TRACE(MMI_CLOG_TRC_INFO,TRC_MMI_CLOG_LSK_HDLR, g_mmi_clog_pbapc_lt_inst.self_gid);
    mmi_clog_pbapc_op_enter(g_mmi_clog_pbapc_lt_inst.self_gid, MMI_CLOG_PBAPC_OP_TYPE_LT_LIST, g_mmi_clog_pbapc_lt_inst.sel_log_idx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_rsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WEARABLE_DEVICE__
    mmi_frm_group_close(GRP_ID_CLOG_LAYOUT);
#else /*__MMI_WEARABLE_DEVICE__*/
#if defined(__MMI_TAB_BAR_SUPPORT_TAB_PAGE__) || defined (__MMI_PHB_PBAPC_SYNC_CONTACT__) 
    mmi_frm_group_close(GRP_ID_CLOG_LAYOUT);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    mmi_frm_scrn_close_active_id();
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
#endif /*__MMI_WEARABLE_DEVICE__*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_csk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_pbapc_viewer_enter(g_mmi_clog_pbapc_lt_inst.self_gid, g_mmi_clog_pbapc_lt_inst.sel_log_idx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_send_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_send_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_pbapc_make_call(GRP_ID_CLOG_PBAPC_LT, g_mmi_clog_pbapc_lt_inst.sel_log_idx, MMI_TRUE);  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_read_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_inst      [IN]        parent inst      
 * RETURNS
 *  
 *****************************************************************************/
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
#ifdef __MTK_TARGET__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_CLOG_TAB_SUPPORT__
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
/* under construction !*/
#endif

#ifdef __MMI_WEARABLE_DEVICE__
void mmi_clog_pbapc_connect_update_inbg(U8 index)
{
    S32 ret;
    srv_bt_cm_bt_addr addr;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = NULL;
    clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();

    clog_pbapc_cntx->index = 0;
    clog_pbapc_cntx->is_cancel = 0;
    clog_pbapc_cntx->flag[0] = 0;
    ret = srv_pbapc_get_btd_addr(&addr, 0);
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BW_PBAPC_CONNECT_2,index, mmi_frm_scrn_get_active_id(), SCR_ID_CLOG_LAYOUT);
    if (ret >= 0)
    {
        if (mmi_frm_scrn_get_active_id() != SCR_ID_CLOG_LAYOUT && !mmi_frm_group_is_present(GRP_ID_CLOG_LAYOUT))
        {
            MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BW_PBAPC_CONNECT_1,clog_pbapc_cntx->flag[0], addr.lap, addr.uap);
            clog_pbapc_cntx->addr[0] = addr;
            clog_pbapc_cntx->index = 0;// only has end call first, then enter ,if enter first , it will not update.
            clog_pbapc_cntx->flag[0] |= MMI_CLOG_PBAPC_FLAG_BG_LOAD;// NOW write is 0 first
            mmi_clog_pbapc_read_data(SRV_PHB_PBAP_STORAGE_PHONE_CCH, 0);
        }
        else
        {
            mmi_frm_display_dummy_screen();
            mmi_frm_scrn_close_active_id();
        }
    }


}
#endif


#ifdef __MMI_HF_SUPPORT__
static void mmi_clog_pbap_update_log()
{
    StopTimer(MMI_CLOG_PBAPC_TIMER);
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BW_PBAPC_TIME_OUT);
    mmi_clog_pbapc_read_data(SRV_PHB_PBAP_STORAGE_PHONE_CCH, 0);
}


void mmi_clog_update_log_by_end_call(srv_ucm_bt_release_call_ind_struct *para)//NEED NEW API
{
    S32 index;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = NULL;

    clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    index = srv_pbapc_get_btd_index(&(para->dev_addr), SRV_PBAPC_FLAG_CONNECTED);

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_UPDATE_BY_END_CALL,index, clog_pbapc_cntx->flag[index], para->dev_addr);
    if (index >= 0)
    {
#ifndef __MMI_WEARABLE_DEVICE__
        if (index == clog_pbapc_cntx->index)
#endif
        {
            clog_pbapc_cntx->addr[index] = para->dev_addr;
            clog_pbapc_cntx->index = index;// only has end call first, then enter ,if enter first , it will not update.
            if (clog_pbapc_cntx->flag[index] == MMI_CLOG_PBAPC_FLAG_LOAD)
            {
                clog_pbapc_cntx->flag[index] &= ~MMI_CLOG_PBAPC_FLAG_LOAD;
            }

            clog_pbapc_cntx->flag[index] |= MMI_CLOG_PBAPC_FLAG_BG_LOAD;
            StartTimer(MMI_CLOG_PBAPC_TIMER, 2000, mmi_clog_pbap_update_log);
        }
#ifndef __MMI_WEARABLE_DEVICE__
        else
        {
            clog_pbapc_cntx->flag[index] = 0;
        }
#endif
    }
}
#endif


static void mmi_clog_send_key_hdler()
{
    mmi_clog_pbapc_make_bt_call(0, g_mmi_clog_pbapc_lt_inst.sel_log_idx);
}


#ifdef __MMI_CLOG_TAB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_title_by_lt_id
 * DESCRIPTION
 *  
 * PARAMETERS        
 *  lt_storage       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_clog_pbapc_lt_get_image_by_storageID(srv_phb_pbap_storage_enum lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(lt_storage)
	{
		case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            return IMG_ID_CLOG_TAB_DIALED_CALL;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            return IMG_ID_CLOG_TAB_MISSED_CALL;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            return IMG_ID_CLOG_TAB_RECVED_CALL;  
        default:
            break;
	}
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_storageID_2_scrID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sel_lt_storage        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_clog_pbapc_lt_storageID_2_scrID(srv_phb_pbap_storage_enum sel_lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID Page_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sel_lt_storage)
    {
	    case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            Page_ID = SCR_ID_CLOG_PBAPC_LT_DIALED_CALL;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            Page_ID = SCR_ID_CLOG_PBAPC_LT_MISSED_CALL;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            Page_ID = SCR_ID_CLOG_PBAPC_LT_RECVED_CALL;
            break;
        default:
            Page_ID = SCR_ID_CLOG_PBAPC_LT_DIALED_CALL;
            break;
    }
    
    return Page_ID;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_storageID_2_tabID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sel_lt_storage        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_clog_lt_id_enum mmi_clog_pbapc_lt_storageID_2_tabID(srv_phb_pbap_storage_enum sel_lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_lt_id_enum tab_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sel_lt_storage)
    {
	    case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            tab_ID = MMI_CLOG_LT_ID_DIALED_CALL;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            tab_ID = MMI_CLOG_LT_ID_MISSED_CALL;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            tab_ID = MMI_CLOG_LT_ID_RECVED_CALL;
            break;
        default:
            tab_ID = MMI_CLOG_LT_ID_DIALED_CALL;
            break;
    }
    
    return tab_ID;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tabID_2_storageID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tab_ID        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
srv_phb_pbap_storage_enum mmi_clog_pbapc_lt_tabID_2_storageID(mmi_clog_lt_id_enum tab_ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbap_storage_enum storage_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(tab_ID)
    {
         case MMI_CLOG_LT_ID_DIALED_CALL:
            storage_ID = SRV_PHB_PBAP_STORAGE_PHONE_OCH;
            break;
        case MMI_CLOG_LT_ID_MISSED_CALL:
            storage_ID = SRV_PHB_PBAP_STORAGE_PHONE_MCH;
            break;
        case MMI_CLOG_LT_ID_RECVED_CALL:
            storage_ID = SRV_PHB_PBAP_STORAGE_PHONE_ICH;
            break;
        default:
            storage_ID = SRV_PHB_PBAP_STORAGE_PHONE_OCH;
            break;
    }
    
    return storage_ID;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tab_set_page_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  page_info        [IN]     
 *  lt_id        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tab_exit_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tab_enter_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grp_data        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
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
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
#endif 
/* under construction !*/
#if defined (__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
#endif 
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
 *  mmi_clog_pbapc_lt_tab_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tab_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif

#else

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_show_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/

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
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
/* under construction !*/
#else
/* under construction !*/
#endif
#ifdef __MMI_TAB_PAGE_SUPPORT_TAB_PAGE__
#if SRV_PBAPC_LINK_NUM >= 2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
/* under construction !*/
#endif
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
#if 0
#ifdef __MMI_WEARABLE_DEVICE__
/* under construction !*/
#else
#if SRV_PBAPC_LINK_NUM >= 2
/* under construction !*/
#else
#if defined ( __MMI_TELEPHONY_SUPPORT__ ) || defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)
/* under construction !*/
#endif /*__MMI_TELEPHONY_SUPPORT__*/
#endif
#endif /*__MMI_WEARABLE_DEVICE__*/
#endif
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
 *  mmi_clog_pbapc_lt_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 * evt       [IN]     
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_list_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id      [IN]
 *  lt_type_id      [IN]
 * RETURNS
 *  
 *****************************************************************************/
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
#endif /* __MMI_CLOG_TAB_SUPPORT__ */
#endif
#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_set_tap_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_set_tap_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_tap_callback(mmi_clog_pbapc_lt_tap_action_hdlr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tap_action_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tap_type        [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_tap_action_hdlr(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {        
       //mmi_clog_pbapc_viewer_enter(GRP_ID_CLOG_PBAPC_LT, g_mmi_clog_pbapc_lt_inst.sel_log_idx);
        mmi_clog_pbapc_viewer_enter(g_mmi_clog_pbapc_lt_inst.self_gid, g_mmi_clog_pbapc_lt_inst.sel_log_idx);
    }
}

#endif /*defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)*/


static void mmi_clog_pbapc_lt_set_touch_hdlr(void)
{
    wgui_register_tap_callback(mmi_clog_send_key_hdler);
}

#define MMI_CLOG_PBAPC_ACT

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_make_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  caller_gid        [IN]  
 *  log_idx            [IN]  
 *  is_send_key       [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_make_call(U16 caller_gid, U16 log_idx, MMI_BOOL is_send_key)
{
#ifdef __MMI_BT_DIALER_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_pbapc_ex_inst_struct *clog_cntx_p = mmi_clog_get_pbapc_cntx_ex();
    clog_cntx_p->store_index = clog_cntx_p->clog_array[log_idx];

    mmi_clog_pbapc_get_info(&(clog_cntx_p->pse_info));

    mmi_ucm_dial_option_bt(clog_cntx_p->pse_info.cid);
#endif /*__MMI_BT_DIALER_SUPPORT__*/

}

static void  mmi_clog_pbapc_get_info(srv_phb_pbapc_clog_struct  *clog_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U16 store_index;
    srv_phb_pbapc_btd_enum bt_index;
    mmi_clog_pbapc_ex_inst_struct *clog_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clog_cntx_p = mmi_clog_get_pbapc_cntx_ex();
    memset(clog_info, 0x00, sizeof(srv_phb_pbapc_clog_struct));
    bt_index = clog_cntx_p->index;
    store_index = clog_cntx_p->store_index;
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_GET_CLOG_INFO,bt_index, store_index, clog_cntx_p->path);
    srv_phb_pbapc_get_clog_entry(bt_index,clog_cntx_p->path, store_index, clog_info);

}


static void mmi_clog_pbapc_make_bt_call(U16 caller_gid, U16 log_idx)
{
    S32 ret;
    srv_clog_log_struct log;
    mmi_ucm_make_call_para_struct call_para;
    U16 num[41];
    srv_phb_pbapc_clog_struct  *clog_info;
    mmi_clog_pbapc_ex_inst_struct *clog_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clog_cntx_p = mmi_clog_get_pbapc_cntx_ex();
    clog_info = &clog_cntx_p->pse_info;
    mmi_ucm_init_call_para(&call_para);
    
    mmi_asc_to_ucs2((CHAR*)num, clog_info->cid);
    call_para.ucs2_num_uri = num;

    call_para.adv_para.is_ip_dial = MMI_FALSE;
    call_para.adv_para.after_make_call_callback = mmi_clog_act_make_call_cb;   
    call_para.adv_para.after_callback_user_data = NULL;
    call_para.adv_para.phb_data = clog_info->name;
    mmi_ucm_call_launch(caller_gid, &call_para);
}


static void mmi_clog_act_make_call_cb(mmi_ucm_after_make_call_cb_struct *para)
{ 
    mmi_frm_group_close(g_mmi_clog_pbapc_op_inst.parent_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid         [IN]  
 *  log_idx            [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_send_sms(mmi_id parent_gid, U16 log_idx)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_write_msg_para_struct para;
    srv_phb_pbapc_clog_struct *call_log;
    mmi_clog_pbapc_ex_inst_struct *clog_cntx_p = mmi_clog_get_pbapc_cntx_ex();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(&para, 0 , sizeof(mmi_sms_write_msg_para_struct));
    call_log = &clog_cntx_p->pse_info;

    para.ascii_addr = call_log->cid;
    mmi_sms_write_msg_lanch(parent_gid,&para);

}


static void mmi_clog_pbapc_save_to_contact(mmi_id parent_gid, U16 log_idx)
{
    S32 ret;
    srv_clog_log_struct log;
    U16 number[42];
    mmi_clog_pbapc_ex_inst_struct *clog_cntx_p;
    srv_phb_pbapc_clog_struct *clog_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ID sub_gid= cui_phb_save_contact_create(parent_gid);
    if (MMI_CLOG_IS_GID_INVALID(sub_gid))
    {
       // mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }
    clog_cntx_p = mmi_clog_get_pbapc_cntx_ex();
    clog_info = &clog_cntx_p->pse_info;

    if (clog_info->name[0] != '\0')
    {
        cui_phb_save_contact_set_name(sub_gid, clog_info->name, NULL);
    }
    mmi_asc_to_ucs2((CHAR*)number,clog_info->cid);
    cui_phb_save_contact_set_number(sub_gid, number);
    cui_phb_save_contact_run(sub_gid);
}


#define MMI_CLOG_PBAPC_OPTION_UI
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_op_evt_mm_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_pbapc_op_evt_mm_select_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    mmi_clog_pbapc_ex_inst_struct *clog_cntx_p = mmi_clog_get_pbapc_cntx_ex();
    group_id = mmi_frm_group_create_ex(g_mmi_clog_pbapc_op_inst.parent_gid, GRP_ID_AUTO_GEN, mmi_clog_act_pbap_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

     mmi_clog_pbapc_get_info(&clog_cntx_p->pse_info);

    switch(evt->highlighted_menu_id)
    {
        case MENU_ID_CLOG_PBAPC_VIEW:
            //mmi_clog_pbapc_viewer_enter(g_mmi_clog_pbapc_op_inst.parent_gid, g_mmi_clog_pbapc_op_inst.log_idx);
            mmi_clog_pbapc_viewer_enter(group_id, g_mmi_clog_pbapc_op_inst.log_idx);

            break;
        case MENU_ID_CLOG_PBAPC_MAKE_CALL:
            mmi_clog_pbapc_make_bt_call(0, g_mmi_clog_pbapc_op_inst.log_idx);
            //mmi_clog_pbapc_make_call(g_mmi_clog_pbapc_op_inst.parent_gid, g_mmi_clog_pbapc_op_inst.log_idx, MMI_FALSE);
            break;

        case MENU_ID_CLOG_PBAPC_SEND_SMS:
            mmi_clog_pbapc_send_sms(group_id, g_mmi_clog_pbapc_op_inst.log_idx);
            //mmi_clog_pbapc_send_sms(g_mmi_clog_pbapc_op_inst.parent_gid, g_mmi_clog_pbapc_op_inst.log_idx);
            break;
        case MENU_ID_CLOG_SAVE_TO_LOCAL_PHB:
            //mmi_clog_pbapc_save_to_contact(g_mmi_clog_pbapc_op_inst.parent_gid, g_mmi_clog_pbapc_op_inst.log_idx);
            mmi_clog_pbapc_save_to_contact(group_id, g_mmi_clog_pbapc_op_inst.log_idx);
            break;
         default:
            break;
    }   
}


static MMI_RET mmi_clog_act_pbap_group_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            //cui_phb_save_contact_close(sub_gid);
            mmi_frm_group_close(g_mmi_clog_pbapc_op_inst.parent_gid);
        }
        break;
        default:
            break;
    }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_op_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_pbapc_op_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            memset(&g_mmi_clog_pbapc_op_inst, 0x0, sizeof(mmi_clog_pbapc_op_inst_struct));
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_clog_pbapc_op_evt_mm_select_hdlr((cui_menu_event_struct*)evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(((cui_menu_event_struct*)evt)->sender_id);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_op_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  type            [IN] 
 *  log_idx         [IN] 
 * RETURNS
 *  
 *****************************************************************************/
static MMI_ID mmi_clog_pbapc_op_enter(MMI_ID parent_gid, mmi_clog_pbapc_op_type_enum type, U16 log_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui;
    MMI_ID gid ;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_gid == GRP_ID_INVALID)
        return GRP_ID_INVALID;

    g_mmi_clog_pbapc_op_inst.log_idx = log_idx;
    g_mmi_clog_pbapc_op_inst.parent_gid = parent_gid;

    if (parent_gid == GRP_ID_CLOG_PBAPC_VIEWER)
    {
        gid = GRP_ID_CLOG_PBAPC_VIEW_OPTION;
    }
    else
    {
        gid = GRP_ID_CLOG_PBAPC_OPTION;

    }
    g_mmi_clog_pbapc_op_inst.parent_gid = mmi_frm_group_create_ex(parent_gid, gid, mmi_clog_pbapc_op_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui = cui_menu_create(
                    gid,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_OPTION,
                    MENU_ID_CLOG_PBAPC_OPTION,
                    MMI_TRUE,
                    0);
    if (type == MMI_CLOG_PBAPC_OP_TYPE_LIST_VIEWER)               	
        cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_VIEW, MMI_TRUE);
    else
        cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_VIEW, MMI_FALSE);
     //MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_OP_ENTER, mmi_bt_is_call_supported(), mmi_bt_is_message_access_profile_supported());

    cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_MAKE_CALL, MMI_FALSE);
#ifdef __MMI_BTD_BOX_UI_STYLE__
    if(!srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION,&clog_pbapc_cntx->addr[clog_pbapc_cntx->indx])) 
    {
        cui_menu_set_item_disabled(cui, MENU_ID_CLOG_PBAPC_MAKE_CALL, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_disabled(cui, MENU_ID_CLOG_PBAPC_MAKE_CALL, MMI_FALSE);
    }

#endif 

#ifdef __MMI_BTD_BOX_UI_STYLE__
    cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_SEND_SMS, MMI_TRUE);
#else /*__MMI_BTD_BOX_UI_STYLE__*/
#if defined(__MMI_WEARABLE_DEVICE__)
    cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_SEND_SMS, MMI_TRUE);
#else
    cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_SEND_SMS, MMI_FALSE);
#endif
#endif /*__MMI_BTD_BOX_UI_STYLE__*/
#ifndef __MMI_TELEPHONY_SUPPORT__
    cui_menu_set_item_hidden(cui, MENU_ID_CLOG_SAVE_TO_LOCAL_PHB, MMI_TRUE);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    cui_menu_run(cui);
    return cui;
}

#define MMI_CLOG_PBAPC_VIWER_UI
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt                [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_clog_pbapc_vr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {
        memset(&g_mmi_clog_pbapc_vr_inst, 0x0, sizeof(mmi_clog_pbapc_vr_inst_struct));
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [IN]                
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_pbapc_vr_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
		case EVT_ID_SCRN_INACTIVE:
		{
			mmi_frm_scrmem_free(g_mmi_clog_pbapc_vr_inst.buf);
			g_mmi_clog_pbapc_vr_inst.buf = NULL;
		}
		break;
		case EVT_ID_SCRN_ACTIVE:
			mmi_clog_pbapc_vr_show_text();
		break;
		default:
		 break;
	}
   
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_viewer_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  log_idx         [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_pbapc_viewer_enter(MMI_ID parent_gid, U16 log_idx)
{
    g_mmi_clog_pbapc_vr_inst.log_idx = log_idx;

    mmi_frm_group_create_ex(parent_gid, GRP_ID_CLOG_PBAPC_VIEWER, mmi_clog_pbapc_vr_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
	mmi_frm_scrn_create(GRP_ID_CLOG_PBAPC_VIEWER, SCR_ID_CLOG_PBAPC_VIEWER, mmi_clog_pbapc_vr_scrn_proc, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_pbapc_op_enter(GRP_ID_CLOG_PBAPC_VIEWER, MMI_CLOG_PBAPC_OP_TYPE_LIST_VIEWER, g_mmi_clog_pbapc_vr_inst.log_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_csk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_clog_vr_make_call_hdlr(MMI_CLOG_KEY_CSK);
    mmi_clog_pbapc_vr_lsk_hdlr();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_rsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_CLOG_PBAPC_VIEWER);
    /* mmi_frm_scrn_close_active_id(); */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_send_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_send_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_pbapc_make_call(GRP_ID_CLOG_PBAPC_VIEWER, g_mmi_clog_pbapc_vr_inst.log_idx, MMI_TRUE);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format_remove_tail
 * DESCRIPTION
 *  
 * PARAMETERS       
 *  cur_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_format_remove_tail(U32 cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cur_len >= MMI_CLOG_PBAPC_VR_FORMAT_DATA_LEN);
    g_mmi_clog_pbapc_vr_inst.buf[cur_len - 2] = '\0';
}
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_cp_key_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf             [IN/OUT]         
 *  buf_max_len     [IN]        
 *  cur_len         [IN/OUT]         
 *  key_str_id      [IN]        
 *  value           [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_cp_key_value(WCHAR *buf, U32 buf_max_len, U32 *cur_len, MMI_STR_ID key_str_id, WCHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    WCHAR *str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(key_str_id)
	{
		str = get_string(key_str_id);
    	len = mmi_wcslen(str);
    }

	len += (mmi_wcslen(value) + MMI_CLOG_PBAPC_VR_FORMAT_DATA_LEN);
	
    if (*cur_len + len > buf_max_len)
        return MMI_FALSE;
	
	if(key_str_id)
    	kal_wsprintf(buf + *cur_len, "%w%w%w%w", str, L"\n", value, L"\n\n");
	else
		kal_wsprintf(buf + *cur_len, "%w%w", value, L"\n");
    *cur_len = mmi_wcslen(buf);
    return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format
 * DESCRIPTION
 *  
 * PARAMETERS     
 *  log         [IN]     
 * RETURNS
 *  
 *****************************************************************************/
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
#endif

#ifdef __MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_get_clt_str_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  clt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_STR_ID mmi_clog_pbapc_vr_get_clt_str_id(mmi_clog_pbapc_clt_enum clt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id = STR_GLOBAL_EMPTY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (clt)
    {
        case MMI_CLOG_PBAPC_CLT_DIALED:
            str_id = STR_ID_CLOG_DIALED_CALL;
            break;

        case MMI_CLOG_PBAPC_CLT_MISSED:
            str_id = STR_ID_CLOG_MISSED_CALL;
            break;

        case MMI_CLOG_PBAPC_CLT_RECVED:
            str_id = STR_ID_CLOG_RECVED_CALL;
            break;
        default:
            break;
    }
    return str_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format_type
 * DESCRIPTION
 *  
 * PARAMETERS    
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_format_type(srv_phb_pbapc_clog_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = mmi_clog_pbapc_vr_get_clt_str_id((mmi_clog_pbapc_clt_enum)log->call_type);
    return mmi_clog_pbapc_vr_cp_key_value(g_mmi_clog_pbapc_vr_inst.buf, MMI_CLOG_PBAPC_VR_BUF_MAX_LEN, cur_len, STR_ID_CLOG_TYPE, get_string(str_id));
}

#endif /*__MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format_name
 * DESCRIPTION
 *  
 * PARAMETERS   
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_format_name(srv_phb_pbapc_clog_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* name */
    if (log->name[0] == '\0')
        return MMI_TRUE;
    return mmi_clog_pbapc_vr_cp_key_value(
            g_mmi_clog_pbapc_vr_inst.buf,
            MMI_CLOG_PBAPC_VR_BUF_MAX_LEN,
            cur_len,
            STR_ID_CLOG_NAME,
            log->name);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format_number
 * DESCRIPTION
 *  
 * PARAMETERS    
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_format_number(srv_phb_pbapc_clog_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *value;    
    WCHAR w_cid[MMI_CLOG_PBAPC_CID_MAX_LEN + 2];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (log->cid[0] != '\0')
    {
        mmi_asc_n_to_wcs((WCHAR*) w_cid, (CHAR*)log->cid, (MMI_CLOG_PBAPC_CID_MAX_LEN+1)) ;
        value = w_cid;
    }
    else
    {
        value = get_string(STR_GLOBAL_NO_NUMBER); 
    }
    return mmi_clog_pbapc_vr_cp_key_value(
        g_mmi_clog_pbapc_vr_inst.buf,
        MMI_CLOG_PBAPC_VR_BUF_MAX_LEN,
        cur_len,
        STR_ID_CLOG_NUMBER,
        value);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_get_call_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf                 [IN]     
 *  buf_max_len         [IN]     
 *  key_str_id          [IN] 
 *  value               [IN] 
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_get_call_time(WCHAR *buf, U32 buf_max_len, U32 *cur_len, MMI_STR_ID key_str_id, WCHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    //WCHAR *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //str = get_string(key_str_id);
    len = mmi_wcslen(value) + MMI_CLOG_PBAPC_VR_FORMAT_DATA_LEN;

    if (*cur_len + len > buf_max_len)
        return MMI_FALSE;

    kal_wsprintf(buf + *cur_len, "%w%w",  value, L"\n");
    *cur_len = mmi_wcslen(buf);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format_time
 * DESCRIPTION
 *  
 * PARAMETERS  
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_format_time(srv_phb_pbapc_clog_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MMI_FALSE;
    U32 len;
    WCHAR *str_buf;
    U32 i = 0;
    WCHAR *str;
    applib_time_struct refer_time;
 
    memset((void *)&refer_time, 0x0, sizeof(applib_time_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 
	for (i=0; i < MMI_CLOG_PBAPC_TIME_DETAIL_MAX_NUM; i++)
	{
            if (applib_dt_compare_time(&log->timestamp[i],&refer_time, NULL)== DT_TIME_EQUAL)
            {
               ret = MMI_TRUE;
		
            }
            else
            {
                str = get_string(STR_ID_CLOG_TIMESTAMP);
                kal_wsprintf(g_mmi_clog_pbapc_vr_inst.buf + *cur_len, "%w%w", str, L"\n");
                *cur_len = mmi_wcslen(g_mmi_clog_pbapc_vr_inst.buf);
                str_buf = OslMalloc(MMI_CLOG_PBAPC_VR_TEMP_BUF_SIZE);

                /*get time*/
                date_string((UI_time*) & log->timestamp[i], (UI_string_type) str_buf, DT_IDLE_SCREEN);
                mmi_wcscat(str_buf, L" ");
                len = mmi_wcslen((const WCHAR*)str_buf);
                time_string((UI_time*) & log->timestamp[i], (UI_string_type) (str_buf + len), DT_IDLE_SCREEN);
		 /*get string*/
		 ret = mmi_clog_pbapc_vr_cp_key_value(g_mmi_clog_pbapc_vr_inst.buf, MMI_CLOG_PBAPC_VR_BUF_MAX_LEN, cur_len, 0, str_buf);
    	        OslMfree(str_buf);
            }

        }
	kal_wsprintf(g_mmi_clog_pbapc_vr_inst.buf + *cur_len, "%w",L"\n");
	*cur_len = mmi_wcslen(g_mmi_clog_pbapc_vr_inst.buf);
	 
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_prepare_text_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_prepare_text_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_pbapc_ex_inst_struct* clog_cntx = mmi_clog_get_pbapc_cntx_ex();

    g_mmi_clog_pbapc_vr_inst.buf = mmi_frm_scrmem_alloc(MMI_CLOG_PBAPC_VR_BUF_MAX_SIZE);
    if(g_mmi_clog_pbapc_vr_inst.buf == NULL)
        return -1;
    
    mmi_clog_pbapc_vr_format(&clog_cntx->pse_info);

#if 0
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__    
/* under construction !*/
#else /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/
/* under construction !*/
#endif /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/   
#endif
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_show_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_show_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8 *gui_buf = NULL;
    S32 has_lsk = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mmi_clog_pbapc_vr_prepare_text_data();

    if (ret != 0)
    {
        mmi_frm_group_close(GRP_ID_CLOG_PBAPC_VIEWER);
        return;
    }
    ShowCategory74Screen(
        STR_GLOBAL_VIEW,
        GetRootTitleIcon(MAIN_MENU_CALL_LOG),
        (has_lsk == MMI_FALSE ? NULL : STR_GLOBAL_OPTIONS),
        (has_lsk == MMI_FALSE ? NULL : IMG_GLOBAL_OPTIONS),
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) g_mmi_clog_pbapc_vr_inst.buf,
        (S32) (mmi_wcslen(g_mmi_clog_pbapc_vr_inst.buf) + 1),
        gui_buf);
    
    if(has_lsk)
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        SetCenterSoftkeyFunction(mmi_clog_pbapc_vr_csk_hdlr, KEY_EVENT_UP);
        redraw_center_softkey();
        SetLeftSoftkeyFunction(mmi_clog_pbapc_vr_lsk_hdlr, KEY_EVENT_UP);
    }
    SetRightSoftkeyFunction(mmi_clog_pbapc_vr_rsk_hdlr, KEY_EVENT_UP);
    mmi_ucm_handle_sendkeys_for_call(mmi_clog_send_key_hdler, KEY_EVENT_DOWN);
}
#define MMI_CLOG_PBAPC_PROCESSING_UI

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_processing_abort
 * DESCRIPTION
 *  show aborting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_processing_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_in;
    is_in = mmi_frm_scrn_is_present(g_mmi_clog_pbapc_processing_inst.parent_gid, SCR_ID_CLOG_PBAPC_LT_PROCESSING, MMI_FRM_NODE_ALL_FLAG);
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_BT_LOAD_ABORT,is_in,(g_mmi_clog_pbapc_processing_inst.parent_gid));

    if (is_in)
    {
        mmi_frm_scrn_close(g_mmi_clog_pbapc_processing_inst.parent_gid,SCR_ID_CLOG_PBAPC_LT_PROCESSING);
    }   
}


static MMI_RET mmi_clog_pbapc_close_scrn_by_back(mmi_event_struct *evt)
{
    //g_mmi_clog_pbapc_cntx.is_canceled = MMI_TRUE;
    /*if(g_mmi_clog_pbapc_cntx.phapc_op_handle)
    {
        srv_phb_pbapc_destory_handle(g_mmi_clog_pbapc_cntx.phapc_op_handle);
        g_mmi_clog_pbapc_cntx.phapc_op_handle = NULL;
    }*/
    mmi_frm_group_close(g_mmi_clog_pbapc_processing_inst.parent_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_entry_show_processing
 * DESCRIPTION
 *  show processing
 * PARAMETERS
 *  parent_id             [IN]
 *  scrn_id            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_entry_show_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id;
    U8 *gui_buffer;
    MMI_BOOL ret = MMI_FALSE;
    MMI_BOOL is_exist = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if(g_mmi_clog_pbapc_processing_inst.type == MMI_CLOG_PBAPC_OP_TYPE_LT_LIST)
    {
        title_id = mmi_clog_pbapc_lt_get_title_by_storageID(g_mmi_clog_pbapc_processing_inst.sel_lt_storage);
    }
    else if(g_mmi_clog_pbapc_processing_inst.type == MMI_CLOG_PBAPC_OP_TYPE_LIST_VIEWER)
    {
        title_id = STR_GLOBAL_VIEW;
    }
    else
    {
        title_id = STR_ID_CLOG_CALL_LOG;
    }

#ifndef __MMI_PHB_PBAPC_SYNC_CONTACT__    
    if(mmi_frm_scrn_get_active_id() == SCR_ID_CLOG_PBAPC_LT_PROCESSING)
        return;
#endif
    //gui_buffer = mmi_frm_scrn_tab_page_get_active_gui_buf();
    ret = mmi_frm_scrn_enter(g_mmi_clog_pbapc_processing_inst.parent_gid,SCR_ID_CLOG_PBAPC_LT_PROCESSING,NULL,mmi_clog_pbapc_entry_show_processing,MMI_FRM_FULL_SCRN);
    if (!ret)
    return ;
#ifdef __MMI_WEARABLE_DEVICE__
    ShowCategory63Screen(GetString(STR_ID_CLOG_PBAPC_SYNC), GetRootTitleIcon(MAIN_MENU_CALL_LOG), NULL);
#else
    ShowCategory63Screen(GetString(STR_GLOBAL_LOADING), GetRootTitleIcon(MAIN_MENU_CALL_LOG), NULL);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_processing_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [IN]                
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_pbapc_processing_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        //	mmi_clog_pbapc_entry_show_processing();
            break;
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            //loading data cancled 
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            break;
        default:
            break;
        }
   
    return MMI_RET_OK;
}


void mmi_clog_bt_reset_pbapc_num()
{
    g_mmi_clog_pbapc_lt_inst.total_num = 0 ;        
    g_mmi_clog_pbapc_lt_inst.sel_log_idx = 0;
}


#ifdef __MMI_WEARABLE_DEVICE__
static S32 mmi_clog_pbapc_lt_get_multi_log_items_inbw(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    S32 i,k;
    S32 total_count;
    mmi_clog_pbapc_lt_get_multi_log_items(start_index, menu_data, data_size);
    for (i = 0; i < data_size ;i++)
    {
        k = start_index + i;
        mmi_clog_pbapc_lt_get_log_hint(k, menu_data[i].item_list);        
    }
    return data_size;
}
#endif


void mmi_clog_pbapc_show_category(S32 error_code, U8 *gui_buffer)
{

    S32 category_error_flag;
    S32 has_lsk = MMI_FALSE;
    srv_phb_pbap_storage_enum storage;
    U8 index;
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_SHOW_CATEGORY, error_code, gui_buffer, g_mmi_clog_pbapc_lt_inst.total_num);
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    index = cui_tab_get_select_index(SCR_ID_CLOG_LAYOUT);
#else
    index = mmi_frm_scrn_tab_get_active_page_index();
#endif

    if(error_code < 0)
    {
        g_mmi_clog_pbapc_lt_inst.total_num = 0 ;        
        g_mmi_clog_pbapc_lt_inst.sel_log_idx = 0;
    }
    if (g_mmi_clog_pbapc_lt_inst.total_num)
        has_lsk = MMI_TRUE;
    else /*it also can set other string*/
    #ifdef __MMI_WEARABLE_DEVICE__
        wgui_cat_set_list_menu_empty_lable(get_string(STR_ID_CLOG_NO_LOG));
    #else
        wgui_cat_set_list_menu_empty_lable(get_string(STR_GLOBAL_EMPTY));
    #endif

#ifdef __MMI_WEARABLE_DEVICE__
    wgui_swatch_two_line_menu_list_screen
    ((PU8)get_string(STR_ID_CLOG_CALL_LOG),
    (PU8)GetImage(GetRootTitleIcon(MAIN_MENU_CALL_LOG)),
    NULL,
    IMG_ID_CLOG_MISSED_CALL,
    NULL,
    g_mmi_clog_pbapc_lt_inst.total_num,
    mmi_clog_pbapc_lt_get_multi_log_items_inbw,
    g_mmi_clog_pbapc_lt_inst.sel_log_idx,
    gui_buffer);

#else
    storage = mmi_clog_pbapc_clt_to_storage_path(g_mmi_clog_pbapc_cntx_ex.path);

    wgui_cat1031_show(
#ifdef __MMI_WEARABLE_DEVICE__
        get_string(STR_ID_CLOG_CALL_LOG),
#else
        get_string(mmi_clog_pbapc_lt_get_title_by_storageID(storage)),
#endif
        (PU8)GetImage(GetRootTitleIcon(MAIN_MENU_CALL_LOG)),
        (has_lsk == MMI_FALSE ? NULL : get_string(STR_GLOBAL_OPTIONS)),
        (has_lsk == MMI_FALSE ? NULL : (PU8)GetImage(IMG_GLOBAL_OPTIONS)),
#ifdef __MMI_WEARABLE_DEVICE__
        NULL,
        NULL,
#else
        get_string(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
#endif
        g_mmi_clog_pbapc_lt_inst.total_num,
        mmi_clog_pbapc_lt_get_multi_log_items,
        mmi_clog_pbapc_lt_get_log_hint,
        g_mmi_clog_pbapc_lt_inst.sel_log_idx,
        index,
        IMG_ID_CLOG_MISSED_CALL,
        IMG_GLOBAL_SIM1, /* Just to get image demision but not care what it is */
        gui_buffer,
        &category_error_flag);
#endif
#ifndef __MMI_WEARABLE_DEVICE__
    if (g_mmi_clog_pbapc_lt_inst.total_num)
    {
        SetCenterSoftkeyFunction(mmi_clog_pbapc_lt_csk_hdlr, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_clog_pbapc_lt_lsk_hdlr, KEY_EVENT_UP);
        mmi_ucm_handle_sendkeys_for_call(mmi_clog_send_key_hdler, KEY_EVENT_DOWN);
    }

    SetRightSoftkeyFunction(mmi_clog_pbapc_lt_rsk_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif
#if defined ( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_clog_pbapc_lt_set_tap_hdlr();
#endif
#endif

#ifdef __MMI_WEARABLE_DEVICE__
    if (g_mmi_clog_pbapc_lt_inst.total_num)
    {
        mmi_clog_pbapc_lt_set_touch_hdlr();
        SetCenterSoftkeyFunction(mmi_clog_send_key_hdler,KEY_EVENT_DOWN);
    }
    SetRightSoftkeyFunction(mmi_clog_pbapc_lt_rsk_hdlr, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_entry_show_processing
 * DESCRIPTION
 *  show processing
 * PARAMETERS
 *  parent_id       [IN]
 *  scrn_id         [IN]
 *  type            [IN]
 *  sel_lt_storage  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
#if 0
 #ifdef __MMI_CLOG_TAB_SUPPORT__
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
#endif


void mmi_clog_pbapc_processing_show_ex(MMI_ID parent_id, mmi_clog_pbapc_op_type_enum type, srv_phb_pbap_storage_enum sel_lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_id)
    {
        g_mmi_clog_pbapc_processing_inst.parent_gid = parent_id;
    }

    g_mmi_clog_pbapc_processing_inst.type = type;
    g_mmi_clog_pbapc_processing_inst.sel_lt_storage = sel_lt_storage;
    mmi_clog_pbapc_entry_show_processing();
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
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
/* under construction !*/
#else
/* under construction !*/
#endif 
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
/* under construction !*/
#else /**/
/* under construction !*/
#endif /**/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
/* under construction !*/
#else /**/
/* under construction !*/
#endif /**/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
/* under construction !*/
#else /**/
/* under construction !*/
#endif /**/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
/* under construction !*/
#else /**/
/* under construction !*/
#endif /**/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void mmi_clog_pbapc_lt_show_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    MMI_ID scrn_id;
    U8 index;
    mmi_clog_pbapc_ex_inst_struct *cntx =  mmi_clog_get_pbapc_cntx_ex(); 
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    index = cui_tab_get_select_index(SCR_ID_CLOG_LAYOUT);
#else
    index = mmi_frm_scrn_tab_get_active_page_index();
#endif
#ifdef __MMI_TAB_PAGE_SUPPORT_TAB_PAGE__
#if SRV_PBAPC_LINK_NUM >= 2
    if (index == 1)
        gui_buffer = cui_tab_get_screen_gui_buf(MMI_CLOG_LT_ID_BT,GRP_ID_CLOG_SUB_BT_DEVICE);
    else
        gui_buffer = cui_tab_get_screen_gui_buf(MMI_CLOG_LT_ID_BT_V3,SCR_ID_CLOG_SUB_BT_DEVICE_V3);
#else
    gui_buffer = cui_tab_get_screen_gui_buf(MMI_CLOG_LT_ID_BT,GRP_ID_CLOG_SUB_BT_DEVICE);
#endif
#else
    gui_buffer = (U8*)mmi_frm_scrn_get_active_gui_buf();
#endif
    RegisterHighlightHandler(mmi_clog_pbapc_lt_item_hlt_hdlr);

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_CONN_IS_BACKWARD, g_mmi_clog_need_save_hlt_idx.is_need_save_idx);
    if (g_mmi_clog_need_save_hlt_idx.is_need_save_idx)
    {
        srv_phb_pbapc_clog_struct *save_info = g_mmi_clog_need_save_hlt_idx.call_info;
       
        srv_phb_pbapc_clog_struct *log_info = &cntx->pse_info;

        MMI_TRACE(MMI_CLOG_TRC_INFO,TRC_MMI_CLOG_BT_DIALER_CONN_SAVE_TIME_STAMP,save_info->timestamp[0].nHour,save_info->timestamp[0].nMin, save_info->timestamp[0].nSec);
        MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_CONN_TIME_STAMP,log_info->timestamp[0].nHour,log_info->timestamp[0].nMin, log_info->timestamp[0].nSec);

        if (applib_dt_compare_time(&log_info->timestamp[0], &save_info->timestamp[0], NULL) != DT_TIME_EQUAL)
        {
            g_mmi_clog_pbapc_lt_inst.sel_log_idx = 0;
            gui_buffer = NULL;
        }
    }
    else 
    {
        gui_buffer  = NULL;
        g_mmi_clog_pbapc_lt_inst.sel_log_idx = 0;      
    }
    if (cntx->is_active != 1)
    {
        return;
    }
    
    mmi_clog_pbapc_show_category(1, gui_buffer);
}


static pBOOL mmi_clog_pbapc_lt_get_log_item(S32 item_index, UI_string_type str_buff, U8 **img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_clog_struct pse_clog;
    mmi_clog_pbapc_ex_inst_struct *clog_cntx = NULL;
    if (item_index < 0 || item_index >= (S32) g_mmi_clog_pbapc_lt_inst.total_num)
    {
        MMI_ASSERT(item_index < (S32) g_mmi_clog_pbapc_lt_inst.total_num);
        return MMI_FALSE;
    }
    clog_cntx = mmi_clog_get_pbapc_cntx_ex();
    
    srv_phb_pbapc_get_clog_entry(clog_cntx->index, clog_cntx->path, clog_cntx->clog_array[item_index], &pse_clog);
    mmi_clog_pbapc_lt_get_string(&pse_clog, str_buff);

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_BT_GET_ITEM, clog_cntx->path, item_index, pse_clog.call_type);
    if (clog_cntx->path == SRV_PHB_PBAPC_CLT_ALL)
    {
        *img_buff_p =
        (U8*) 
        GetImage(mmi_clog_pbapc_lt_get_img_by_call_type(pse_clog.call_type));
    }
    else
    {
        *img_buff_p =
        (U8*) GetImage(mmi_clog_pbapc_lt_get_img_by_call_type(clog_cntx->path));//?
    } 
    return MMI_TRUE;
}


S32 mmi_clog_pbapc_lt_get_log_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_clog_struct call_log;
    mmi_clog_pbapc_ex_inst_struct *pbapc_cntx;
    applib_time_struct refer_time;
    pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    memset((void *)&refer_time, 0x0, sizeof(applib_time_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (item_index < 0 || item_index >= (S32) g_mmi_clog_pbapc_lt_inst.total_num)
    {
        return MMI_FALSE;
    }

    srv_phb_pbapc_get_clog_entry(pbapc_cntx->index, pbapc_cntx->path, pbapc_cntx->clog_array[item_index], &call_log);
   
    if (applib_dt_compare_time(&call_log.timestamp[0],&refer_time, NULL)== DT_TIME_EQUAL)
    {
#ifdef __MMI_WEARABLE_DEVICE__
        mmi_wcscpy(hint_array[1], (WCHAR *)GetString(STR_ID_CLOG_UNKOWN_CALL));
#else
        mmi_wcscat(hint_array[0], (WCHAR *)GetString(STR_ID_CLOG_UNKOWN_CALL));
#endif
    }
    else
    {
    #ifdef __MMI_WEARABLE_DEVICE__
        date_string((UI_time*) & call_log.timestamp[0], hint_array[1], DT_IDLE_SCREEN);
        mmi_wcscat(hint_array[1], L" ");
        time_string((UI_time*) & call_log.timestamp[0], 
                (UI_string_type) (hint_array[1] + mmi_wcslen((const 
                WCHAR*)hint_array[1])), 
                DT_IDLE_SCREEN);
    #else
        date_string((UI_time*) & call_log.timestamp[0], hint_array[0], DT_IDLE_SCREEN);
        mmi_wcscat(hint_array[0], L" ");
        time_string((UI_time*) & call_log.timestamp[0], 
            (UI_string_type) (hint_array[0] + mmi_wcslen((const WCHAR*)hint_array[0])), 
            DT_IDLE_SCREEN);
    #endif

    }
    return MMI_TRUE;
}


/************************************calllog view screen***********************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format
 * DESCRIPTION
 *  
 * PARAMETERS     
 *  log         [IN]     
 * RETURNS
 *  
 *****************************************************************************/

static S32 mmi_clog_pbapc_vr_format(srv_phb_pbapc_clog_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    U32 cur_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_mmi_clog_pbapc_vr_format_text_tbl) / sizeof(MMI_CLOG_PBAPC_VR_FORMAT_TEXT_PARA_HDLR); i++)
    {
        ret = (g_mmi_clog_pbapc_vr_format_text_tbl[i]) (log, &cur_len);
        if (!ret)
        {
            mmi_clog_pbapc_vr_format_remove_tail(cur_len);
            return ret;
        }
    }
    mmi_clog_pbapc_vr_format_remove_tail( cur_len);
    MMI_ASSERT(ret <= MMI_CLOG_PBAPC_VR_BUF_MAX_LEN);
    return MMI_TRUE;
}

static MMI_MENU_ID mmi_clog_bt_pbapc_get_menu_id(mmi_clog_lt_id_enum lt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(lt_id)
    {
        case MMI_CLOG_LT_ID_DIALED_CALL:
            return MENU_ID_CLOG_PBAPC_DIALED_CALL;
        case MMI_CLOG_LT_ID_MISSED_CALL:
            return MENU_ID_CLOG_PBAPC_MISSED_CALL;
        case MMI_CLOG_LT_ID_RECVED_CALL:
            return MENU_ID_CLOG_PBAPC_RECVED_CALL;
        case MMI_CLOG_LT_ID_ALL_CALL:
            return MENU_ID_CLOG_PBAPC_ALL_CALL;
        default:
            break;
    }
}


void mmi_clog_bt_dialer_show(mmi_clog_lt_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_clt_enum lt_storage;
    srv_phb_pbap_storage_enum storage;
    mmi_clog_lt_bt_tab_page_struct *page;
    mmi_clog_pbapc_ex_inst_struct *pbapc_cntx = NULL; 
    srv_bt_cm_bt_addr bt_addr;
    MMI_MENU_ID sel_menu_id; 
    S32 ret;
    S32 get_ret;
    U8 index;
    U8 *gui_buffer;
    pbapc_cntx = mmi_clog_get_pbapc_cntx_ex(); 
#ifdef __MMI_WEARABLE_DEVICE__
    index = 0;
#else /*__MMI_WEARABLE_DEVICE__*/
#ifndef __MMI_PHB_PBAPC_SYNC_CONTACT__
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    index = cui_tab_get_select_index(SCR_ID_CLOG_LAYOUT);
#else
    index = mmi_frm_scrn_tab_get_active_page_index();
#endif/*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    index = index -1;
#endif
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
#else /*__MMI_PHB_PBAPC_SYNC_CONTACT__*/
        MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BW_PBAPC_FROM_MISSED,g_is_missed_call.bt_index, g_is_missed_call.is_from_bt);

        if(g_is_missed_call.is_from_bt)
        {
            index = g_is_missed_call.bt_index;
        }
        else
        {
            index = pbapc_cntx->index;
        }
    
#endif /*__MMI_PHB_PBAPC_SYNC_CONTACT__*/
#endif /*__MMI_WEARABLE_DEVICE__*/
    pbapc_cntx->index = index;
    get_ret = mmi_clog_pbapc_is_connect();
    sel_menu_id = mmi_clog_bt_pbapc_get_menu_id(inst->sel_lt_id);
    lt_storage = mmi_clog_pbapc_menu_to_storage_path(sel_menu_id);
    pbapc_cntx->path = lt_storage;
    pbapc_cntx->parent_id = inst->self_gid;
    storage = mmi_clog_pbapc_clt_to_storage_path(lt_storage);
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BW_PBAPC_MAIN_FLOW, get_ret,pbapc_cntx->flag[index],pbapc_cntx->index);

    if (get_ret >= 0)
    {
        if (get_ret)
        {
#ifdef __MMI_WEARABLE_DEVICE__            
            pbapc_cntx->is_cancel = 0;
#endif
            if (pbapc_cntx->flag[index] & MMI_CLOG_PBAPC_FLAG_LOAD)
            {
                mmi_clog_pbapc_clear_missed_call(inst);
                mmi_clog_bt_pbapc_build_list();

            }
            else  if (pbapc_cntx->flag[index] & MMI_CLOG_PBAPC_FLAG_BG_LOAD)
            {
                mmi_clog_pbapc_processing_show_ex(inst->self_gid, MMI_CLOG_PBAPC_OP_TYPE_LT_LIST, lt_storage);
            }
            else
            {
                mmi_clog_pbapc_clear_missed_call(inst);
                mmi_clog_pbapc_read_data(storage,inst->self_gid);
            }
        }
        else
        {
            if (mmi_bt_dialer_app_is_connected())//only pbap not connect
            {
                pbapc_cntx ->dis_style = 2;

            }
            else
            {
                pbapc_cntx ->dis_style = 1;
            }
#ifdef __MMI_WEARABLE_DEVICE__
            mmi_clog_bt_show_list_in_disconn();
#else 
            mmi_clog_bt_show_list_in_disconn(inst, page);
#endif
        }

    }
    else
    {
        {
            pbapc_cntx ->dis_style = 1;
#ifdef __MMI_WEARABLE_DEVICE__
            mmi_clog_bt_show_list_in_disconn();
#else 
            mmi_clog_bt_show_list_in_disconn(inst, page);
#endif
        }
    }

}

static void mmi_clog_bt_pbapc_build_list()
{
    U32 max_count;
    U8 index;
    srv_phb_pbapc_clt_enum storage;

    mmi_clog_pbapc_ex_inst_struct *pbapc_cntx = NULL;
    pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    storage = pbapc_cntx->path;
    index = pbapc_cntx->index;
    if (storage == SRV_PHB_PBAPC_CLT_ALL)
    {
        max_count = MMI_CLOG_PBAPC_ALL_CALL_ENTRIES;
    }
    else
    {
        max_count = MMI_CLOG_PBAPC_ENTRIES;
    }
    g_mmi_clog_pbapc_lt_inst.total_num = srv_phb_pbapc_build_clog_list(index, storage, pbapc_cntx->clog_array, max_count);
    mmi_clog_pbapc_lt_show_list();

}

#ifdef __MMI_WEARABLE_DEVICE__
static void mmi_clog_bt_show_list_in_disconn()
{
    U8 *gui_buffer;
    mmi_clog_pbapc_ex_inst_struct *pbapc_cntx = NULL;
    pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BW_PBAPC_CANCEL_CONFIRM, pbapc_cntx->is_cancel);
    if (!pbapc_cntx->is_cancel)
    {
        mmi_clog_bt_link_conn_screen();//FOR Wearable.
    }
    else
    {
        mmi_clog_bt_pbapc_build_list();
        /*if (ret >= 0)
        {
            mmi_clog_bt_dialer_parse_file(sel_menu_id, path);
        }
        else
        {
            gui_buffer = mmi_frm_scrn_get_active_gui_buf();
            mmi_clog_pbapc_show_category(-1, gui_buffer);
        }*/
        //pbapc_cntx->is_cancel = 0;
    }
}
#else
static void mmi_clog_bt_show_list_in_disconn(mmi_clog_lt_inst_struct *inst, mmi_clog_lt_bt_tab_page_struct *page)
{
    mmi_clog_pbapc_ex_inst_struct *pbapc_cntx = NULL;
    pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();

    wgui_set_menu_empty_string_by_id(STR_ID_PHB_PBAPC_NO_CONN);
    mmi_clog_bt_link_no_conn_show_list(inst, page);

    if (pbapc_cntx->dis_style == 1)
    {
        SetLeftSoftkeyFunction(mmi_clog_bt_link_lsk_hdlr, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_clog_bt_link_lsk_hdlr, KEY_EVENT_UP);
    }
    else if (pbapc_cntx->dis_style == 2)
    {
        SetLeftSoftkeyFunction(mmi_clog_bt_link_conn_profile_lsk_hdlr, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_clog_bt_link_conn_profile_lsk_hdlr, KEY_EVENT_UP);
    }
}
#endif


#ifdef __MMI_BT_NOTI_SRV__
static void mmi_clog_pbapc_clear_missed_call(mmi_clog_lt_inst_struct *inst)
{
    U8 index;
    mmi_clog_pbapc_ex_inst_struct *pbapc_cntx = NULL; 
    pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    index = pbapc_cntx->index;
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BW_PBAPC_CLEAR_MISSED_CALL, index, inst->sel_lt_id,g_is_missed_call.is_from_bt);
    if (inst->sel_lt_id == MMI_CLOG_LT_ID_MISSED_CALL || inst->sel_lt_id == MMI_CLOG_LT_ID_ALL_CALL)
    {
#ifdef __MMI_WEARABLE_DEVICE__
        wgui_status_icon_bar_hide_icon(STATUS_ICON_BT_MISSED_CALL);
        mmi_frm_group_close(GRP_ID_BT_CLOG_MISSE_CALL);
        MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_WR_MISS_CLEAR, g_bt_noti.missed_call_count);
        if (g_bt_noti.missed_call_count)
        {
            srv_bt_noti_update_remote_missed_call(&g_bt_noti.bt_addr);
            g_bt_noti.missed_call_count = 0;
        }
#else
#if SRV_PBAPC_LINK_NUM >= 2
        MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BW_PBAPC_CLEAR_MISSED_CALL_2, g_is_missed_call.missed_bt_addr[index].lap,g_is_missed_call.missed_bt_addr[index].uap);
        if (g_is_missed_call.is_from_bt)
        {
            if(bt_nmgr_handle[index])
            {
                mmi_frm_nmgr_alert_cancel(bt_nmgr_handle[index]);
            }    
        }
        else
        {
            srv_bt_noti_update_remote_missed_call(&g_is_missed_call.missed_bt_addr[index]);
            if(bt_nmgr_handle[index])
            {
                mmi_frm_nmgr_alert_cancel(bt_nmgr_handle[index]);
            }
        }
#else
        srv_bt_noti_update_remote_missed_call(&pbapc_cntx->addr[0]);
        if(bt_nmgr_handle)
        {
            mmi_frm_nmgr_alert_cancel(bt_nmgr_handle);
        }
#endif
#endif
    }
}
#endif

#ifdef __MMI_WEARABLE_DEVICE__
static void mmi_clog_bt_link_rsk_hdlr()
{
    mmi_clog_pbapc_ex_inst_struct* pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    pbapc_cntx->is_cancel = 1;
    mmi_frm_scrn_close(pbapc_cntx->parent_id,SCR_ID_CLOG_BT_CONN_FAIL);
}


static void mmi_clog_bt_link_conn_screen()
{ 
    U16 str_id,lsk_str;
    MMI_BOOL ret;
    MMI_BOOL is_connect;
    mmi_clog_pbapc_ex_inst_struct* pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();

    ret = mmi_frm_scrn_enter(pbapc_cntx->parent_id, SCR_ID_CLOG_BT_CONN_FAIL,NULL,mmi_clog_bt_link_conn_screen,MMI_FRM_FULL_SCRN);
    if (!ret)
        return ;
    is_connect = srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &pbapc_cntx->addr[0]);
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BW_PBAPC_NO_CONNECT, is_connect, pbapc_cntx->dis_style);
    if (is_connect)
    {
        mmi_frm_scrn_close(pbapc_cntx->parent_id,SCR_ID_CLOG_BT_CONN_FAIL);
        return ;
    }
    if (pbapc_cntx->dis_style == 1)
    {
        str_id = STR_ID_PHB_PBAPC_NOT_CONNECTED;
        lsk_str = STR_GLOBAL_CONNECT;
    }
    else if (pbapc_cntx->dis_style == 2)
    {
        str_id = STR_ID_PHB_PBAPC_FAIL_SYNC;
        lsk_str = STR_ID_PHB_PBAPC_RETRY;
    }
    wgui_showcategory6333_screen
        (NULL,
        get_string(lsk_str),
        get_string(STR_GLOBAL_CANCEL),
        get_string(str_id),
        NULL);
    SetRightSoftkeyFunction(mmi_clog_bt_link_rsk_hdlr,KEY_EVENT_UP);
    if (pbapc_cntx->dis_style == 2)
    {
        SetLeftSoftkeyFunction(mmi_clog_bt_link_conn_profile_lsk_hdlr, KEY_EVENT_UP);
    }
    else if (pbapc_cntx->dis_style == 1)
    {
        SetLeftSoftkeyFunction(mmi_clog_bt_link_lsk_hdlr,KEY_EVENT_UP);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_bt_link_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_bt_link_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id = mmi_frm_group_get_active_id();

    mmi_clog_pbapc_ex_inst_struct *pbapc_cntx  = mmi_clog_get_pbapc_cntx_ex();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (srv_bt_cm_get_busy_dev() == NULL)
    {
        g_local_index =  pbapc_cntx->index;
        srv_pbapc_set_query_func(mmi_clog_bt_pbap_set_index_cb);
    }
    mmi_bt_dialer_show_popup(group_id);
#ifdef __MMI_WEARABLE_DEVICE__
    mmi_frm_scrn_close(pbapc_cntx->parent_id,SCR_ID_CLOG_BT_CONN_FAIL);
#endif
}


static S32 mmi_clog_bt_pbap_set_index_cb(srv_pbapc_query_req_struct *req)
{
    req->bt_index = g_local_index;
    srv_pbapc_set_query_func(NULL);
    return 0;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_bt_link_conn_profile_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_bt_link_conn_profile_lsk_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    mmi_id cui_id;
    U8 index;
    srv_bt_cm_bt_addr addr;
    mmi_clog_pbapc_ex_inst_struct* pbapc_cntx = NULL;
    MMI_ID group_id = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_CONN_LSK_HDLR, group_id);
   // mmi_bt_dialer_conn_profile(NULL, group_id, SRV_BT_CM_PBAPC_CONNECTION, mmi_clog_bt_link_conn_profile_cb);
    pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    index = pbapc_cntx->index;
    ret = srv_phb_pbapc_get_btd_addr(&addr, index);
    //addr = pbapc_cntx->addr[index];
    cui_id = cui_bt_dialer_connecting_create(group_id);
    if (cui_id != GRP_ID_INVALID)
    {
        pbapc_cntx->cui_id = cui_id;
        cui_bt_dialer_connecting_run(cui_id);
        pbapc_cntx->ret = srv_pbapc_connect(&addr, mmi_clog_bt_link_conn_profile_cb);
    #ifdef __MMI_WEARABLE_DEVICE__
        mmi_frm_scrn_close(pbapc_cntx->parent_id,SCR_ID_CLOG_BT_CONN_FAIL);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_bt_link_conn_profile_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_bt_link_conn_profile_cb(srv_bt_cm_bt_addr *dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result, MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U16 str_id;
    mmi_clog_pbapc_ex_inst_struct* pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_CONN_CB, result);
#ifdef __MMI_WEARABLE_DEVICE__
    cui_bt_dialer_connecting_close(pbapc_cntx->cui_id);
    if (!result)
    {
        if (srv_bt_cm_get_busy_dev() != NULL)
        {
            str_id =  STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(str_id));
        }
    }
#else
    cui_bt_dialer_connecting_close(pbapc_cntx->cui_id);
    if (!result)
    {
        if (pbapc_cntx->ret != SRV_PBAPC_RET_OK)
        {
            str_id =  STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
        }
        else
        {
            str_id = STR_BT_CONN_FAILED;

        }
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
        (WCHAR*)GetString(str_id));
    }
#endif

}


static S32 mmi_clog_pbapc_is_connect()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bt_index;
    MMI_BOOL ret = MMI_FALSE;
    srv_bt_cm_bt_addr addr;
    mmi_clog_pbapc_ex_inst_struct *phb_pbapc_cntx_p = NULL;
    S32 result = -1;

#if !defined(__MTK_TARGET__)
    return MMI_TRUE;
#endif
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_clog_get_pbapc_cntx_ex();

    bt_index = phb_pbapc_cntx_p->index;
    result = srv_phb_pbapc_get_btd_addr(&addr, bt_index);
    phb_pbapc_cntx_p->addr[bt_index] = addr;
    if (result == SRV_PHB_PBAPC_RET_OK)
    {
        ret = srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &addr);
    }
    else
    {
        return result;
    }

#if !defined(__MTK_TARGET__)
    return MMI_TRUE;
#endif
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_BW_PBAPC_IS_CONNECT, bt_index, result);
    return ret;


}


void mmi_clog_view_from_idle_by_type(MMI_BOOL is_from_local)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_from_local)
    {
        g_is_missed_call.is_from_local = MMI_TRUE;
    }
    else
    {
        g_is_missed_call.is_from_bt= MMI_TRUE;
    }
}


mmi_clog_pbapc_ex_inst_struct* mmi_clog_get_pbapc_cntx_ex()
{
    return &g_mmi_clog_pbapc_cntx_ex;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_BT_PBAP_CLIENT__ */ 

