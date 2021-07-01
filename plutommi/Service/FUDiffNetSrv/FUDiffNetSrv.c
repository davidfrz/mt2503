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
 * FUDiffNetSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Firmware differential package update service
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
* Included files
*****************************************************************************/
#include "MMI_features.h"

#ifdef __FUDIFFNET_ENABLE__
#include "FUDiffNetSrv.h"
#include "MMIDataType.h"
#include "MMI_trc_Int.h"
#include "MMI_conn_app_trc.h"
#include "Unicodexdcl.h"
#include "ShutdownSrvGprot.h"
#include "Fs_gprot.h"
#include "FUDIFFNET.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"

extern FUDIFFNET_ERROR_CODE FUDIFFNET_TriggerDL(WCHAR * filename, FUDIFFNET_UPDATE_TYPE update_type);

#ifdef __ROCK_FOTA_SUPPORT__
#define FOTA_DIFF_PKG_DIR               L"Z:\\@fota_rock"
#define FOTA_DIFF_PKG_PATH              L"Z:\\@fota_rock\\fota.delta"
#define FOTA_UPDATE_INFO                L"Z:\\rock_update_info"
#define FOTA_UPDATE_INFO_BAK            L"Z:\\rock_update_info.bak"
#else /* __ROCK_FOTA_SUPPORT__*/
#define FOTA_DIFF_PKG_DIR               L"Z:\\@fota_redbend"
#define FOTA_DIFF_PKG_PATH              L"Z:\\@fota_redbend\\fota.delta"
#define FOTA_UPDATE_INFO                L"Z:\\redbend_update_info"
#define FOTA_UPDATE_INFO_BAK            L"Z:\\redbend_update_info.bak"
#endif /* __ROCK_FOTA_SUPPORT__*/


srv_fudiffnet_flag_enum srv_fudiffnet_trigger(srv_fudiffnet_update_type_enum update_type, srv_fudiffnet_dm_type_enum dm_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fudiffnet_flag_enum ret = SRV_FUDIFFNET_FLAG_SUCCESS;
    FUDIFFNET_UPDATE_TYPE bl_update_type;
    FUDIFFNET_ERROR_CODE bl_error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //record dm type when trigger, it will be used to check in get fota result
    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUDiffNetSrv] trigger write dm type = %d", dm_type);
    WriteRecordSlim(
        NVRAM_EF_DIFF_FOTA_DM_TYPE_LID, 
        1, 
        &dm_type, 
        1);
            
    if (SRV_FUDIFFNET_UPDATE_FULL == update_type)
    {
        bl_update_type = FUDIFFNET_UPDATE_FULL;
    }
    else if (SRV_FUDIFFNET_UPDATE_PARTIAL == update_type)
    {
        bl_update_type = FUDIFFNET_UPDATE_PARTIAL;
    }

    bl_error_code = FUDIFFNET_TriggerDL(FOTA_DIFF_PKG_PATH, bl_update_type);
    switch (bl_error_code)
    {
        case 0:
            ret = SRV_FUDIFFNET_FLAG_SUCCESS;
            break;
        default:
            break;

    }
    return ret;
}

srv_fudiffnet_update_ret_enum srv_fudiffnet_read_update_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    srv_fudiffnet_update_ret_enum ret = SRV_FUDIFFNET_NO_UPDATE;
    FUDIFFNET_Update_Info update_info;
    UINT read;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUDIFFNETSRV_READ_UPDATE_INFO_START);
    fd = FS_Open(FOTA_UPDATE_INFO, FS_READ_ONLY);
    if (fd >= FS_NO_ERROR)
    {
        FS_Read(fd, (void *)&update_info, sizeof(update_info), &read);
        if (read == sizeof(update_info))
        {
            ret = update_info.m_error_code;
            if (update_info.m_error_code == 0)
            {
                ret = SRV_FUDIFFNET_UPDATE_SUCCESS;
            }
            else
            {
                ret = SRV_FUDIFFNET_UPDATE_FAIL;
            }
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUDIFFNETSRV_READ_UPDATE_INFO_FAIL, read);
        }
        FS_Close(fd);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUDIFFNETSRV_OPEN_UPDATE_INFO_FAIL);
    }

    return ret;
}

static mmi_ret srv_fudiffnet_delete_delta_callback(mmi_event_struct *param)
{
    MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUDIFFNETSRV_DELETE_FOTA_DELTA_SUCCESS);
    return 0;
}

srv_fudiffnet_update_ret_enum srv_fudiffnet_get_fota_result(srv_fudiffnet_dm_type_enum dm_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fudiffnet_update_ret_enum ret = SRV_FUDIFFNET_NO_UPDATE;
    srv_fudiffnet_dm_type_enum trigger_dm_type; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //get dm type for last trigger
    ReadRecordSlim(
        NVRAM_EF_DIFF_FOTA_DM_TYPE_LID, 
        1, 
        &trigger_dm_type, 
        NVRAM_EF_DIFF_FOTA_DM_TYPE_SIZE);
    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUDiffNetSrv] read trigger dm type = %d, dm type = %d", trigger_dm_type, dm_type);
    
    if (trigger_dm_type != dm_type)
    {
        return SRV_FUDIFFNET_NO_UPDATE;
    }

    if (srv_fmgr_fs_path_exist(FOTA_UPDATE_INFO) >= 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUDIFFNETSRV_UPDATE_INFO_IS_EXIST);
        ret = srv_fudiffnet_read_update_info();
        srv_fmgr_fs_delete(FOTA_UPDATE_INFO_BAK);
        srv_fmgr_fs_rename(FOTA_UPDATE_INFO, FOTA_UPDATE_INFO_BAK);
        srv_fmgr_async_delete(FOTA_DIFF_PKG_PATH, 0, srv_fudiffnet_delete_delta_callback, NULL);
    }
    else if (srv_fmgr_fs_path_exist(FOTA_DIFF_PKG_PATH) >= 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUDIFFNETSRV_ONLY_FOTA_DELTA_EXIST);
		srv_fmgr_async_delete(FOTA_DIFF_PKG_PATH, 0, srv_fudiffnet_delete_delta_callback, NULL);
        return SRV_FUDIFFNET_UPDATE_FAIL;
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUDIFFNETSRV_FOTA_NO_UPDATE);
        return SRV_FUDIFFNET_NO_UPDATE;
    }

    return ret;

}

WCHAR* srv_fudiffnet_get_firmware_path(void)
{
    return FOTA_DIFF_PKG_PATH;
}

void srv_fudiffnet_init(void)
{
    FS_HANDLE fd = -1;

    // create firmware folder if it is not exist
    fd = FS_Open(FOTA_DIFF_PKG_DIR, FS_OPEN_DIR | FS_READ_ONLY);
    if (FS_NO_ERROR > fd)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUDIFFNETSRV_FOTA_FOLDER_NOT_EXIST);
        fd = FS_CreateDir(FOTA_DIFF_PKG_DIR);
        //ASSERT(fd >= FS_NO_ERROR);
        if (FS_NO_ERROR > fd)
        {
            MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUDIFFNETSRV_CREATE_FOTA_DIR_FAIL);
        }
    }
    else
    {
        FS_Close(fd);
    }

    return;
}

void srv_fudiffnet_get_fota_pre_info(srv_fudiffnet_fota_pre_info_struct* pre_info)
{
    if (NULL == pre_info)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUDiffNetSrv] pre_info null pointer.");
        return;
    }
    //get brand & mode & domain & pin-code info
    ReadRecordSlim(
        NVRAM_EF_DIFF_FOTA_INFO_LID, 
        1, 
        pre_info, 
        NVRAM_EF_DIFF_FOTA_INFO_SIZE);

    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUDiffNetSrv] brand=%s, model=%s", pre_info->brand, pre_info->model);
    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUDiffNetSrv] domain=%s, pin_code=%s", pre_info->domain, pre_info->pin_code);

    return;
}

void srv_fudiffnet_get_swmc_fota_pre_info(srv_fudiffnet_fota_pre_info_swmc_struct* pre_info)
{
    if (NULL == pre_info)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUDiffNetSrv] pre_info null pointer.");
        return;
    }
    //get brand & mode & domain & pin-code info
    ReadRecordSlim(
        NVRAM_EF_DIFF_FOTA_INFO_SWMC_LID, 
        1, 
        pre_info, 
        NVRAM_EF_DIFF_FOTA_INFO_SWMC_SIZE);

    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUDiffNetSrv] brand=%s, model=%s", pre_info->brand, pre_info->model);
    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUDiffNetSrv] domain=%s, pin_code=%s", pre_info->domain, pre_info->pin_code);

    return;
}
#ifdef __ROCK_FOTA_SUPPORT__
void srv_fudiffnet_get_rock_fota_pre_info(srv_fudiffnet_rock_fota_pre_info_struct* pre_info)
{
    if (NULL == pre_info)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUDiffNetSrv] srv_fudiffnet_get_rock_fota_pre_info null pointer.");
        return;
    }
    //get brand & mode & domain & pin-code info
    ReadRecordSlim(
        NVRAM_EF_ROCK_FOTA_INFO_LID, 
        1, 
        pre_info, 
        NVRAM_EF_ROCK_FOTA_INFO_SIZE);

    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUDiffNetSrv] rock fota brand=%s, model=%s", pre_info->brand, pre_info->model);

    return;
}
#endif /*__ROCK_FOTA_SUPPORT__*/

#endif /*__FUDIFFNET_ENABLE__*/
