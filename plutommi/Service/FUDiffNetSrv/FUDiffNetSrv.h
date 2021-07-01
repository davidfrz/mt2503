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
 * FUDiffNetSrv.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Firmware differential package update service header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __FUDIFFNET_SRV_H__
#define __FUDIFFNET_SRV_H__

#include "MMI_features.h"

#ifdef __FUDIFFNET_ENABLE__
#include "kal_general_types.h"

typedef enum
{
    SRV_FUDIFFNET_FLAG_SUCCESS,
    SRV_FUDIFFNET_FLAG_FAIL_DEL_CBR_UPDATING_INFO,
    SRV_FUDIFFNET_FLAG_ERASE_MARKER_BLOCK,
    SRV_FUDIFFNET_FLAG_WRITE_MARKER_BLOCK,
    SRV_FUDIFFNET_FLAG_NO_DL_PACKAGE_FOUND,
    SRV_FUDIFFNET_FLAG_FLASH_INIT_FAIL
} srv_fudiffnet_flag_enum;

typedef enum
{
    SRV_FUDIFFNET_UPDATE_FULL,
    SRV_FUDIFFNET_UPDATE_PARTIAL
} srv_fudiffnet_update_type_enum;


typedef enum
{
    SRV_FUDIFFNET_NO_UPDATE,
    SRV_FUDIFFNET_UPDATE_SUCCESS,
    SRV_FUDIFFNET_UPDATE_FAIL
} srv_fudiffnet_update_ret_enum;

typedef enum
{
    SRV_FUDIFFNET_LITE_DM,
    SRV_FUDIFFNET_SWMC_DM
} srv_fudiffnet_dm_type_enum;
/*****************************************************************************
 * NOTE:
 *     This structure is copy from bl_fudiffnet.h, so it must be sync with bl_fudiffnet.h
 *****************************************************************************/
#define FUDIFFNET_MARKER_REGION_SIZE   (32)

/* this structure contains 1. update information for DM, 2. marker for power loss recovery */
typedef struct
{	  
    /* version of structure */
    kal_int32 m_ver;
    /* update information for DM*/
    kal_int32 m_error_code;
    /* the behavior of bootloader for this error */
    kal_int32 m_behavior;    // 0 : reboot, 1 : hang
    /* check if DM has read */
    kal_int32 m_is_read;     // 0 : read, 1 : not read
    /* marker for power loss recovery */
    kal_char  m_marker[FUDIFFNET_MARKER_REGION_SIZE];
    
    /* reserved & make the structure 64 bytes */
    kal_int32 reserved[4];   
             
}  FUDIFFNET_Update_Info; 

/*****************************************************************************
 * NOTE:
 *     This structure is come from common_nvram_editor_data_item.h, so it must be sync.
 *****************************************************************************/
typedef struct
{
    kal_uint8 brand[50];
    kal_uint8 model[50];
    kal_uint8 domain[30];
    kal_uint8 pin_code[30];
}srv_fudiffnet_fota_pre_info_struct; //for lite DM

typedef struct
{
    kal_uint8 brand[50];
    kal_uint8 model[50];
    kal_uint8 domain[30];
    kal_uint8 pin_code[30];
}srv_fudiffnet_fota_pre_info_swmc_struct; //for SWM client

#ifdef __ROCK_FOTA_SUPPORT__
typedef struct
{
    kal_uint8 brand[50];
    kal_uint8 model[50];
}srv_fudiffnet_rock_fota_pre_info_struct;
#endif /*__ROCK_FOTA_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  srv_fudiffnet_trigger
 * DESCRIPTION
 *  Trigger bootloader to update differential package. 
 * PARAMETERS
 *  update_type        [IN] Full update or partial update    
 *  dm_type            [IN] dm type      
 * RETURNS
 *  srv_fudiffnet_flag_enum: update flag return
 * 
 * Sample code:
 * srv_fudiffnet_dm_type_enum dm_type = SRV_FUDIFFNET_SWMC_DM;
 *if (SRV_FUDIFFNET_FLAG_SUCCESS == srv_fudiffnet_trigger(SRV_FUDIFFNET_UPDATE_PARTIAL, dm_type))
 *{
 *	 srv_reboot_normal_start(); //reboot device
 *}
 *else
 *{
 *	 kal_promt_trace( "FOTARecvSrv trigger fudiffnet fail.");
 *}
 *
 *****************************************************************************/
extern srv_fudiffnet_flag_enum srv_fudiffnet_trigger(srv_fudiffnet_update_type_enum update_type, srv_fudiffnet_dm_type_enum dm_type);

/*****************************************************************************
 * FUNCTION
 *  srv_fudiffnet_get_fota_result
 * DESCRIPTION
 *  get update result from update_info file. 
 * PARAMETERS
 *  dm_type            [IN] dm type
 * RETURNS
 *  srv_fudiffnet_update_ret_enum
 *
 * Sample code:
 * 
 * srv_fudiffnet_update_ret_enum ret = SRV_FUDIFFNET_NO_UPDATE;	
 * srv_fudiffnet_dm_type_enum dm_type = SRV_FUDIFFNET_SWMC_DM;
 * ret = srv_fudiffnet_get_fota_result(dm_type);
 * if (SRV_FUDIFFNET_UPDATE_SUCCESS == ret)
 * {
 *     kal_promt_trace( "fota update success.");
 * }
 * else if(SRV_FUDIFFNET_UPDATE_FAIL == ret)
 * {
 *     kal_promt_trace( "fota update failed.");
 * }
 * else if(SRV_FUDIFFNET_NO_UPDATE == ret)
 * {
 *     kal_promt_trace( "fota no update.");
 * }
 *****************************************************************************/
extern srv_fudiffnet_update_ret_enum srv_fudiffnet_get_fota_result(srv_fudiffnet_dm_type_enum dm_type);

/*****************************************************************************
 * FUNCTION
 *  srv_fudiffnet_get_firmware_path
 * DESCRIPTION
 *  get firmware path 
 * PARAMETERS
 *  void
 * RETURNS
 *  WCHAR*
 *
 * Sample code:
 *  
 * WCHAR* firmware_path = NULL;
 * firmware_path = srv_fudiffnet_get_firmware_path();	
 * 
 *****************************************************************************/
extern WCHAR* srv_fudiffnet_get_firmware_path(void);

/*****************************************************************************
 * FUNCTION
 *  srv_fudiffnet_init
 * DESCRIPTION
 *  create firmware folder 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_fudiffnet_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_fudiffnet_get_fota_pre_info
 * DESCRIPTION
 *  get some pre info which need to be used to check new version in fota process
 *  for litm DM
 * PARAMETERS
 * pre_info        [OUT] fota pre info structure for litm DM
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_fudiffnet_get_fota_pre_info(srv_fudiffnet_fota_pre_info_struct* pre_info);

/*****************************************************************************
 * FUNCTION
 *  srv_fudiffnet_get_swmc_fota_pre_info
 * DESCRIPTION
 *  get some pre info which need to be used to check new version in fota process
 *  for SWM client
 * PARAMETERS
 * pre_info        [OUT] fota pre info structure for SWM client
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_fudiffnet_get_swmc_fota_pre_info(srv_fudiffnet_fota_pre_info_swmc_struct* pre_info);

#ifdef __ROCK_FOTA_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_fudiffnet_get_rock_fota_pre_info
 * DESCRIPTION
 *  get rock fota pre info which need to be used to check new version in fota process.
 * PARAMETERS
 * pre_info        [OUT] rock fota pre info structure  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_fudiffnet_get_rock_fota_pre_info(srv_fudiffnet_rock_fota_pre_info_struct* pre_info);
#endif /*__ROCK_FOTA_SUPPORT__*/
#endif /*__FUDIFFNET_ENABLE__*/

#endif /* __FUDIFFNET_SRV_H__ */
