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
 * BTMMIApkSmartInstall.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for dispatch primitive from goep obex to different applications.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#include "BtcmSrvGprot.h"
#include "Bluetooth_struct.h"
#include "btsendcuigprot.h"
#include "BTMMISend.h"
#include "ProfilesSrvGprot.h"
#include "custom_events_notify.h"
#include "app_mine.h"
#include "AlertScreen.h"
#include "Conversions.h"
#include "PhoneSetupGprots.h"

#ifdef __MMI_OPP_SUPPORT__
#include "BTMMIOppGprots.h"
#include "OppSrvGprot.h"
#include "BtCMCUIGprot.h"
/* auto add by kw_check begin */
#include "mmi_rp_app_bluetooth_def.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_conn_app_trc.h"
#include "kal_trace.h"
#include "string.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "fs_type.h"
#include "Unicodexdcl.h"
#include "FileMgrSrvGProt.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_res_range_def.h"
#include "CustDataRes.h"

#include "NotificationGprot.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_timer_gprot.h"
#include "CustMenuRes.h"
#include "FileMgrGProt.h"
#include "app_mem.h"
#include "stack_config.h"
#include "wgui_categories_text_viewer.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "lcd_sw_rnd.h"
#ifdef __BT_DIALER_SUPPORT__
#include "bt_common_config.h"
#endif

#include "Mmi_rp_srv_btcm_def.h"


#define APK_FOLDER L"@Apk"
 
static void mmi_bt_send_get_folder_path(U16* folder_path)
 {
	 U8 drv = SRV_FMGR_SYSTEM_DRV;
	 kal_wsprintf(folder_path, "%c:\\%w\\", drv, APK_FOLDER);
 }
 
 void mmi_bt_send_apk_floder_init(void)
 {
	 U16 dir_path[(SRV_FMGR_PATH_MAX_LEN+1)<<1] = {0};
	 FS_HANDLE fsHandle = NULL;
	 S32 folder_name_len = 0;
	 static MMI_BOOL mmi_bt_apk_init_flag = MMI_FALSE;
	 
	 kal_prompt_trace(MOD_MMI_CONN_APP, "OppMMI: mmi_bt_send_apk_floder_init() mmi_bt_apk_init_flag= %d", mmi_bt_apk_init_flag);
	 if (MMI_TRUE == mmi_bt_apk_init_flag)
	 {
		 return;
	 }
 
	 // Get apk folder path
	 mmi_bt_send_get_folder_path(dir_path);
	 if (srv_fmgr_fs_path_exist(dir_path) >= 0 || srv_fmgr_fs_create_folder(dir_path) >= FS_NO_ERROR)
	 {
		 mmi_bt_apk_init_flag = MMI_TRUE;
		 kal_prompt_trace(MOD_MMI_CONN_APP, "OppMMI: mmi_bt_send_apk_floder_init() mmi_bt_apk_init_flag= %d", mmi_bt_apk_init_flag);
	 }
 }
 void mmi_bt_send_get_apk_path(U16 *file_path)
 {
	 FS_HANDLE list = NULL;
	 U16 dir_path[(SRV_FMGR_PATH_MAX_LEN+1)<<1] ={0};
	 U16 batchSize = 1;
	 U8 buff[116];
	 fs_list_param_struct param = {0};
	 FS_Pattern_Struct pattern;
	 U32 open_result;
 
	 mmi_bt_send_get_folder_path(dir_path);
	 mmi_wcscpy(file_path, dir_path);
 
 
	 mmi_wcscat(dir_path, L"*.*");
	 mmi_wcscpy(pattern.Pattern, L"*.apk");
	 
	 param.name_pattern_count = 1;
	 param.name_pattern = &pattern;
	 param.path = dir_path;
	 param.index = 0;
	 param.buff_size = 116; //FS_LIST_SIZE(batchSize);
	 param.buff = buff;
 
	 for (open_result = FS_ListOpen(&param, &list); open_result >= 0 && list > 0; FS_ListReload(&param, &list))
	 {
		 FS_DOSDirEntry e = {0};
		 WCHAR fileName[FS_MAX_FILE_NAME_LENGTH] = {0};
		 open_result = FS_ListNext(list, &e, param.path, (WCHAR*)fileName, FS_MAX_FILE_NAME_LENGTH, 0);
		 if(open_result >= FS_NO_ERROR)
		 {
			 mmi_wcscat(file_path, fileName);
			 break; 		 
		 }
	 }
	 FS_Close(list);
 }
 void mmi_bt_send_smart_phone_apk(MMI_ID parent_id, srv_bt_cm_bt_addr* dev_addr)
 {
	 U16 file_path[(SRV_FMGR_PATH_MAX_LEN+1)<<1] = {0};
	 cui_bt_sending_para_struct para;
	 cui_bt_sending_obj_struct obj;
	 extern void srv_bt_cm_copy_addr(void *dest,void *src);
 
	 mmi_bt_send_get_apk_path(file_path);
 
	 memset(&para, 0, sizeof(cui_bt_sending_para_struct));
	 memset(&obj, 0, sizeof(cui_bt_sending_obj_struct));
 
	 obj.data.obj_type = CUI_BT_SENDIND_USE_FILE;
	 obj.data.u.file.path = file_path;
	 para.obj = &obj;
	 
	 para.option = CUI_BT_SENDIND_OPT_SPECIFIC_DEVICE;
	 srv_bt_cm_copy_addr(&para.addr, dev_addr);
	 kal_prompt_trace(MOD_MMI_CONN_APP, "BTMMISend:mmi_bt_send_smart_phone_apk(), launch cui, parent_id=0x%08x", parent_id);
 
	 cui_bt_sending_launch(parent_id, &para);
 }

 #if defined(__MMI_BT_APK_SMART_INSTALL_SUPPORT__)
 void mmi_oppc_connect_ind_handle_for_smart_install(void *para)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 srv_opp_conn_notify_struct *conn_notify = (srv_opp_conn_notify_struct*) para;
 
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 
	 kal_prompt_trace(MOD_MMI_CONN_APP, "OppMMI: mmi_oppc_connect_ind_handle_for_smart_install() 0");
	 if(srv_oppc_is_idle() && SRV_OPP_CONN_FAILED != conn_notify->type && SRV_OPP_CONN_SCO_REJECT != conn_notify->type)
		 return;
	 kal_prompt_trace(MOD_MMI_CONN_APP, "OppMMI: mmi_oppc_connect_ind_handle_for_smart_install() 1");
 
	 srv_oppc_handle_smart_install(MMI_TRUE,(MMI_BOOL)(conn_notify->type == SRV_OPP_CONN_SUCC));
 }
 
 void mmi_oppc_send_ind_handle_for_smart_install(void* para)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 srv_opp_snd_notify_struct *snd_result = (srv_opp_snd_notify_struct*) para;
 
	 if (snd_result->type == SRV_OPP_SND_SUCC)
	 {
		 srv_oppc_handle_smart_install(MMI_FALSE, MMI_TRUE);
	 }
 }
 
 void mmi_bt_oppc_disconn_for_smart_install(srv_bt_cm_bt_addr *dev_addr, void* cb_ptr)
 {
	 if(cb_ptr)
	 {
		 ((srv_oppc_cm_cb)cb_ptr)(dev_addr, SRV_BT_CM_OPPC_CONNECTION, MMI_FALSE, MMI_FALSE, MMI_FALSE);
	 }
 }
 
 // only push apk to SP
 void mmi_bt_oppc_conn_for_smart_install(srv_bt_cm_bt_addr *dev_addr, void* cb_ptr)
 {
	 MMI_BOOL is_headset;
	 MMI_BOOL is_dialer;
	 U16 sp_pushed_check;
	 const srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_dev_info(dev_addr);
 
	 // check if need push apk to remote device
	 // do not need to pushe if remoted device is mtk bt dialer, headset.
	 // or pushed successfully previous, currently is sharing.
	 MMI_BT_ASSERT(dev_info != NULL);
	 is_dialer = srv_bt_cm_is_bt_dialer((const srv_bt_cm_bt_addr*)dev_addr);
	 is_headset = srv_bt_cm_is_headset(dev_info->cod);
	 sp_pushed_check = srv_oppc_apk_pushed_record_check(dev_addr);
	 
	 kal_prompt_trace(MOD_MMI_CONN_APP, "BTMMISend: mmi_bt_send_smart_phone_apk() is_dialer[%d], is_headset[%d], push_mask[%d]",
			 is_dialer, is_headset, sp_pushed_check);
 
	 if (sp_pushed_check || (is_dialer || is_headset) || srv_oppc_is_sending())
	 {
		 ((srv_oppc_cm_cb)cb_ptr)(dev_addr, SRV_BT_CM_OPPC_CONNECTION, MMI_FALSE, MMI_TRUE, MMI_FALSE);
		 return;
	 }
 
	 // push
	 srv_oppc_set_conn_app_cb(cb_ptr);
	 mmi_bt_send_smart_phone_apk(GRP_ID_ROOT, dev_addr);
 }
#endif /*defined(__MMI_BT_APK_SMART_INSTALL_SUPPORT__)*/
#endif
#endif
