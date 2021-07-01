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
 * FUNetSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Firmware update service
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

#include "MMI_features.h"

/***************************************************************************** 
* Included files
*****************************************************************************/

#include "FUNetSrv.h"

#ifdef __FUNET_ENABLE__

#include "FUNET.h"
#include "MMI_trc_Int.h"
#include "MMI_conn_app_trc.h"
#include "Unicodexdcl.h"
#include "ShutdownSrvGprot.h"
#include "Fs_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"

#define FOTA_UBIN_PKG_DIR               L"Z:\\@fota_iot"
#define FOTA_UBIN_PKG_PATH              L"Z:\\@fota_iot\\image.bin"
#define FOTA_UBIN_UPDATE_DIR            L"Z:\\@fota_iot_data"
#define FOTA_UBIN_UPDATE_INFO           L"Z:\\@fota_iot_data\\update_status"
#define FOTA_UBIN_UPDATE_INFO_BAK       L"Z:\\@fota_iot_data\\update_status.bak"

extern FUNET_ERROR_CODE FUNET_TriggerDL(WCHAR * filename, FUNET_UPDATE_TYPE update_type);

/*****************************************************************************
 * FUNCTION
 *  srv_funet_trigger
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name        [IN] update package
 *  update_type    [IN] full or partial update
 * RETURNS
 *  srv_funet_flag_enum: update result
 *****************************************************************************/
srv_funet_flag_enum srv_funet_trigger(WCHAR * file_name, srv_funet_update_type_enum update_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FUNET_UPDATE_TYPE bl_update_type;
    FUNET_ERROR_CODE bl_error_code = FUNET_ERROR_NONE;
    srv_funet_flag_enum ret = SRV_FUNET_FLAG_SUCCESS;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_FUNET_UPDATE_FULL == update_type)
    {
        bl_update_type = FUNET_UPDATE_FULL;
    }
    else if (SRV_FUNET_UPDATE_PARTIAL == update_type)
    {
        bl_update_type = FUNET_UPDATE_PARTIAL;
    }
    
    bl_error_code = FUNET_TriggerDL(file_name, bl_update_type);
    switch (bl_error_code)
    {
        case FUNET_ERROR_NONE:
            ret = SRV_FUNET_FLAG_SUCCESS;
            break;

        case FUNET_ERROR_FAIL_TO_DEL_CBR_UPDATING_INFO:
            ret = SRV_FUNET_FLAG_FAIL_DEL_CBR_UPDATING_INFO;
            break;

        case FUNET_ERROR_ERASE_MARKER_BLOCK:
            ret = SRV_FUNET_FLAG_ERASE_MARKER_BLOCK;
            break;

        case FUNET_ERROR_WRITE_MARKER_BLOCK:
            ret = SRV_FUNET_FLAG_WRITE_MARKER_BLOCK;
            break;

        case FUNET_ERROR_NO_DL_PACKAGE_FOUND:
            ret = SRV_FUNET_FLAG_NO_DL_PACKAGE_FOUND; 
            break;

        case FUNET_ERROR_FLASH_INIT_FAIL:
            ret = SRV_FUNET_FLAG_FLASH_INIT_FAIL;
            break;

        default:
            break;
            
    }

    return ret;
}

srv_funet_update_ret_enum srv_funet_read_update_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    srv_funet_update_ret_enum ret = SRV_FUNET_NO_UPDATE;
    FUNET_Update_Status update_info;
    UINT read;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_READ_UPDATE_INFO_START);
    fd = FS_Open(FOTA_UBIN_UPDATE_INFO, FS_READ_ONLY);
    if (fd >= FS_NO_ERROR)
    {
        FS_Read(fd, (void *)&update_info, sizeof(update_info), &read);
        if (read == sizeof(update_info))
        {
            ret = update_info.m_error_code;
            if (update_info.m_error_code == 0)
            {
                ret = SRV_FUNET_UPDATE_SUCCESS;
            }
            else
            {
                ret = SRV_FUNET_UPDATE_FAIL;
            }
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_READ_UPDATE_INFO_FAIL, read);
        }
        FS_Close(fd);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_OPEN_UPDATE_INFO_FAIL);
    }

    return ret;
}

static mmi_ret srv_funet_delete_ubin_cb(mmi_event_struct *param)
{
    MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_DELETE_UBIN_SUCCESS);
    return 0;
}

srv_funet_update_ret_enum srv_funet_get_fota_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_funet_update_ret_enum ret = SRV_FUNET_NO_UPDATE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_fmgr_fs_path_exist(FOTA_UBIN_UPDATE_INFO) >= 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_UPDATE_INFO_IS_EXIST);
        ret = srv_funet_read_update_info();
        srv_fmgr_fs_delete(FOTA_UBIN_UPDATE_INFO_BAK);
        srv_fmgr_fs_rename(FOTA_UBIN_UPDATE_INFO, FOTA_UBIN_UPDATE_INFO_BAK);
        srv_fmgr_async_delete(FOTA_UBIN_PKG_PATH, 0, srv_funet_delete_ubin_cb, NULL);
    }
    else if (srv_fmgr_fs_path_exist(FOTA_UBIN_PKG_PATH) >= 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_ONLY_UBIN_FILE_EXIST);
        srv_fmgr_async_delete(FOTA_UBIN_PKG_PATH, 0, srv_funet_delete_ubin_cb, NULL);
        return SRV_FUNET_UPDATE_FAIL;
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_FOTA_NO_UPDATE);
        return SRV_FUNET_NO_UPDATE;
    }

    return ret;

}

WCHAR* srv_funet_get_ubin_path(void)
{
    return FOTA_UBIN_PKG_PATH;
}

#if (!defined(__UPDATE_BINARY_FILE__))
WCHAR* srv_funet_get_fbin_path(void)
{
    return FOTA_UBIN_PKG_PATH;
}
#endif

void srv_funet_init(void)
{
    FS_HANDLE fd = -1;

    // create ubin folder if it is not exist
    fd = FS_Open(FOTA_UBIN_PKG_DIR, FS_OPEN_DIR | FS_READ_ONLY);
    if (FS_NO_ERROR > fd)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_FOTA_FOLDER_NOT_EXIST);
        fd = FS_CreateDir(FOTA_UBIN_PKG_DIR);
        //ASSERT(fd >= FS_NO_ERROR);
        if (FS_NO_ERROR > fd)
        {
            MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_CREATE_FOTA_DIR_FAIL);
        }
    }
    else
    {
        FS_Close(fd);
    }

	// create ubin update status  folder if it is not exist
    fd = FS_Open(FOTA_UBIN_UPDATE_DIR, FS_OPEN_DIR | FS_READ_ONLY);
    if (FS_NO_ERROR > fd)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_FOTA_FOLDER_NOT_EXIST);
        fd = FS_CreateDir(FOTA_UBIN_UPDATE_DIR);
        //ASSERT(fd >= FS_NO_ERROR);
        if (FS_NO_ERROR > fd)
        {
            MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_FUNETSRV_CREATE_FOTA_DIR_FAIL);
        }
    }
    else
    {
        FS_Close(fd);
    }

    return;
}

void srv_funet_get_fota_pre_info(srv_funet_fota_pre_info_struct* pre_info)
{
    if (NULL == pre_info)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUNetSrv] null pointer.");
        return;
    }

    //get brand & mode info
    ReadRecordSlim(
        NVRAM_EF_UBIN_FOTA_INFO_LID, 
        1, 
        pre_info, 
        NVRAM_EF_UBIN_FOTA_INFO_SIZE);

    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUNetSrv] domain=%s", pre_info->domain);
    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUNetSrv] model=%s", pre_info->model);
    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[FUNetSrv] dl_key=%s", pre_info->dl_key);

    return;
}

#endif /* __FUNET_ENABLE__ */
