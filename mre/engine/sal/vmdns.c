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
*  
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
*
* Author:
* -------
*
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
 * removed!
*
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "mmi_features.h"
#include "vmswitch.h"

#ifdef __MRE_SAL_DNSD__
    
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmpromng.h"
#include "vmdns.h"
#include "mmi_trc.h"
#include "mmi_mre_trc.h"
#include "dnsd_gprot.h"

VMINT vm_dns_start(VMUINT32 port, VMCHAR *config_path, VMCHAR *domain_path)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_DNSD_S, 1, __LINE__);
    inet_dns_start((kal_uint32)port, (char *)config_path, (char *)domain_path);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_DNSD_E, 1, __LINE__);
    return 0;
}

VMINT vm_dns_stop(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_DNSD_S, 2, __LINE__);
    inet_dns_stop();
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_DNSD_E, 2, __LINE__);
    return 0;
}

VMINT vm_dns_get_state(void)
{
    VMINT ret;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_DNSD_S, 3, __LINE__);
    ret = (VMINT)inet_dns_get_state();
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_DNSD_E, ret, __LINE__);
    return ret;
}

VMINT vm_get_nwsetting_sym(VMCHAR* func_name)
{

    if(strcmp(func_name,"vm_dns_start") == 0)
        return (VMINT)vm_dns_start;
    if(strcmp(func_name,"vm_dns_stop") == 0)
        return (VMINT)vm_dns_stop;
    if(strcmp(func_name,"vm_dns_get_state") == 0)
        return (VMINT)vm_dns_get_state;        

	return 0;
}

#endif /* __MRE_SAL_DNSD__ */

