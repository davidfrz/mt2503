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

/*******************************************************************************
 * Filename:
 * ---------
 * vmfota.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  fota 
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
*******************************************************************************/
#include "mmi_features.h"
#include "vmswitch.h"
//#ifdef __IOT__
#include "vmsys.h"
#include "vmfota.h"
#include "FUnetSrv.h"
#include "FUDiffNetSrv.h"
vm_srv_funet_flag_enum vm_srv_funet_trigger(VMWCHAR * file_name, vm_srv_funet_update_type_enum update_type)
{
#ifdef __FUNET_ENABLE__
	return srv_funet_trigger(file_name,(srv_funet_update_type_enum)update_type);
#else
	return VM_SRV_FUNET_FLAG_SUCCESS;
#endif
}

vm_fudiffnet_flag_enum vm_fudiffnet_trigger(vm_fudiffnet_update_type_enum update_type)
{
#ifdef __FUDIFFNET_ENABLE__
	return srv_fudiffnet_trigger((srv_fudiffnet_update_type_enum)update_type, SRV_FUDIFFNET_LITE_DM);
#else
	return VM_FUDIFFNET_FLAG_SUCCESS;
#endif
}
vm_fudiffnet_update_ret_enum vm_fudiffnet_get_fota_result(void)
{
#ifdef __FUDIFFNET_ENABLE__
	return srv_fudiffnet_get_fota_result(SRV_FUDIFFNET_LITE_DM);
#else
	return VM_FUDIFFNET_NO_UPDATE;
#endif
}
VMWCHAR* vm_fudiffnet_get_firmware_path(void)
{
#ifdef __FUDIFFNET_ENABLE__
	return srv_fudiffnet_get_firmware_path();
#else
	return NULL;
#endif
}

void vm_fudiffnet_get_fota_pre_info(vm_fudiffnet_fota_pre_info_struct* pre_info)
{
#ifdef __FUDIFFNET_ENABLE__
	srv_fudiffnet_get_fota_pre_info((srv_fudiffnet_fota_pre_info_struct*)pre_info);
#else
	return;
#endif
}


//#endif/*__IOT__*/
