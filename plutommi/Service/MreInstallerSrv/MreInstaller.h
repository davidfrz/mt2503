
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
*   VreDLTaskMgr.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   
*
* Author:
* -------
 * -------
*
*============================================================================*/
#ifndef MRE_INSTALLER_H
#define MRE_INSTALLER_H

#include "BtNotiSrvGprot.h"
#include "MMIDataType.h"

typedef enum
{
    SRV_MRE_INSTALLER_INSTALL_START,
    SRV_MRE_INSTALLER_INSTALL_FAIL,
    SRV_MRE_INSTALLER_INSTALL_SUCCESS,
    SRV_MRE_INSTALLER_UNINSTALL_FAIL,
    SRV_MRE_INSTALLER_UNINSTALL_SUCCESS
} srv_mre_installer_uninstall_result_enum;


typedef enum
{
    SRV_MRE_INSTALLER_RET_NO_ERROR = 0,
    SRV_MRE_INSTALLER_RET_UNKNOWN_ERROR = -1000,    /* unknown error */
    SRV_MRE_INSTALLER_RET_FILE_NOT_EXIST,           /* file not exist */
    SRV_MRE_INSTALLER_RET_FILE_INTEGRITY_ERROR,     /* file length error */
    SRV_MRE_INSTALLER_RET_LINK_DISCONNECTED,
    SRV_MRE_INSTALLER_RET_MRE_PARSE_PARA_ERROR,
    SRV_MRE_INSTALLER_RET_PARSE_PARA_ERROR,
    SRV_MRE_INSTALLER_RET_MAP_FILE_PARSE_PARA_ERROR
} srv_mre_installer_ret_code;

typedef enum
{
    SRV_MRE_INSTALLER_DELETE_FILE = -6,
    SRV_MRE_INSTALLER_UNINSTALL_ALL = -4,
    SRV_MRE_INSTALLER_GET_INSTALL_STATUS = -2,
    SRV_MRE_INSTALLER_UNINSTALL = -1,
    SRV_MRE_INSTALLER_GET_ALL_INSTALLED_VXP = 5,
    SRV_MRE_INSTALLER_GET_PERMISSION = 7,
    SRV_MRE_INSTALLER_SET_PERMISSION = 8,
    SRV_MRE_INSTALLER_GET_CTA_STATUS = 9
} srv_mre_action_code;


typedef struct
{
    S32 action_code;
    srv_bt_cm_bt_addr bt_addr;
    CHAR mre_file_ext[BT_NOTIFY_XML_FILE_NAME_LENTH];
    WCHAR xml_file_path[BT_NOTIFY_XML_FILE_NAME_LENTH];
    U32 permission;
}mre_installer_cntx;


typedef struct
{
    char provider[49 + 1];                                        // provider id
    //U32 version;                                         // version   
    CHAR version[16];
    S32 app_id;                                        // app_id
    CHAR app_name[BT_NOTIFY_XML_FILE_NAME_LENTH + 1];
    //CHAR *app_name;
    U32 app_name_len;
	U32 preinstall;  // 1 instead of can not uninstall
} mre_installer_app_info_struct;


void srv_bt_noti_recv_init(void);
void srv_mre_installer_callback(void *data);
MMI_BOOL srv_mre_installer_set_mre_auth(WCHAR *mre_file_path, U32 user_def_auth);
MMI_BOOL srv_mre_installer_get_mre_auth(WCHAR *mre_file_path, U32 *app_defined_auth, U32 *user_defined_auth);



#endif
