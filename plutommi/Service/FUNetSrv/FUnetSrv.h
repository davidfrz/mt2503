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
 * FUNetSrv.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Firmware update service header file
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

#ifndef __FUNET_SRV_H__
#define __FUNET_SRV_H__

#include "MMI_features.h"
#include "MMIDataType.h"

#ifdef __FUNET_ENABLE__

typedef enum
{
    SRV_FUNET_FLAG_SUCCESS,
    SRV_FUNET_FLAG_FAIL_DEL_CBR_UPDATING_INFO,
    SRV_FUNET_FLAG_ERASE_MARKER_BLOCK,
    SRV_FUNET_FLAG_WRITE_MARKER_BLOCK,
    SRV_FUNET_FLAG_NO_DL_PACKAGE_FOUND,
    SRV_FUNET_FLAG_FLASH_INIT_FAIL
} srv_funet_flag_enum;

typedef enum
{
    SRV_FUNET_UPDATE_FULL,
    SRV_FUNET_UPDATE_PARTIAL
} srv_funet_update_type_enum;

typedef enum
{
    SRV_FUNET_NO_UPDATE, 
    SRV_FUNET_UPDATE_SUCCESS, 
    SRV_FUNET_UPDATE_FAIL
} srv_funet_update_ret_enum;

/*****************************************************************************
 * NOTE:
 *     This structure is come from common_nvram_editor_data_item.h, so it must be sync.
 *****************************************************************************/
typedef struct
{
    kal_uint8 domain[256];
    kal_uint8 model[50];
    kal_uint8 dl_key[32+1];
}srv_funet_fota_pre_info_struct;

/* Internal Prototype */

/*****************************************************************************
 * FUNCTION
 *  srv_funet_trigger
 * DESCRIPTION
 *  Trigger bootloader to update. 
 * PARAMETERS
 *  file_name            [IN] FOTA update package
 *  update_type        [IN] Full update or partial update    
 * RETURNS
 *  srv_funet_flag_enum: update flag return
 *****************************************************************************/
extern srv_funet_flag_enum srv_funet_trigger(WCHAR * file_name, srv_funet_update_type_enum update_type);

/*****************************************************************************
 * FUNCTION
 *  srv_funet_get_fota_result
 * DESCRIPTION
 *  get update result from update_info file. 
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_funet_update_ret_enum
 *
 * Sample code:
 * 
 * srv_funet_update_ret_enum ret = SRV_FUDIFFNET_NO_UPDATE;
 * 
 * ret = srv_funet_get_fota_result();
 * if (SRV_FUNET_UPDATE_SUCCESS == ret)
 * {
 *     kal_promt_trace( "fota update success.");
 * }
 * else if (SRV_FUNET_UPDATE_FAIL == ret)
 * {
 *     kal_promt_trace( "fota update failed.");
 * }
 * else if (SRV_FUNET_NO_UPDATE == ret)
 * {
 *     kal_promt_trace( "fota no update.");
 * }
 *****************************************************************************/
extern srv_funet_update_ret_enum srv_funet_get_fota_result(void);

/*****************************************************************************
 * FUNCTION
 *  srv_funet_get_ubin_path
 * DESCRIPTION
 *  get update bin path 
 * PARAMETERS
 *  void
 * RETURNS
 *  WCHAR*
 *
 * Sample code:
 *  
 * WCHAR* ubin_path = NULL;
 * ubin_path = srv_funet_get_ubin_path();
 * 
 *****************************************************************************/
extern WCHAR* srv_funet_get_ubin_path(void);

#if (!defined(__UPDATE_BINARY_FILE__))
/*****************************************************************************
 * FUNCTION
 *  srv_funet_get_fbin_path
 * DESCRIPTION
 *  get full bin path 
 * PARAMETERS
 *  void
 * RETURNS
 *  WCHAR*
 *
 * Sample code:
 *  
 * WCHAR* fbin_path = NULL;
 * fbin_path = srv_funet_get_fbin_path();
 * 
 *****************************************************************************/
extern WCHAR* srv_funet_get_fbin_path(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_funet_init
 * DESCRIPTION
 *  create update bin folder 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_funet_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_funet_get_fota_pre_info
 * DESCRIPTION
 *  get some pre info which need to be used to check new version in fota process.
 * PARAMETERS
 *  pre_info        [OUT] fota pre info structure
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_funet_get_fota_pre_info(srv_funet_fota_pre_info_struct* pre_info);

#endif /* __FUNET_ENABLE__ */

#endif /* __FUNET_SRV_H__ */
