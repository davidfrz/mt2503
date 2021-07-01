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

#ifndef VMMAGICINTERNAL_H
#define VMMAGICINTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"


/*****************************************************************************
* FUNCTION
 *    vm_magic_save_data
 * DESCRIPTION
 *  save data pointer to resource
 * PARAMETERS
 *  pointer: [IN] the data pointer
 * RETURNS
 *  if 0, success; others, fail.
*****************************************************************************/
VMINT vm_magic_save_data(void* pointer);

/*****************************************************************************
* FUNCTION
 *    vm_magic_get_data_by_resid
 * DESCRIPTION
 *  get stored resource data by resource id
 * PARAMETERS
 *  resid:       [IN] the resource id when the return value storing 
 *  data_buffer: [OUT] the pointer which is got from resource by native handle
 * RETURNS
 *  if 0, success; others, fail.
*****************************************************************************/
VMINT vm_magic_get_data_by_resid(VMINT	resid, void** data_buffer);

/*****************************************************************************
* FUNCTION
 *    vm_magic_get_data_by_native_handle
 * DESCRIPTION
 *  get stored resource data by native handle
 * PARAMETERS
 *  native_handle: [IN] the return value native function handle the callback
 *  data_buffer: [OUT] the pointer which is got from resource by native handle
 *  p_handle: [IN] the app handle, can be transfered less than 0
 * RETURNS
 *  if 0, success; others, fail.
*****************************************************************************/
VMINT vm_magic_get_data_by_native_handle(VMINT native_handle, void** data_buffer, VMINT p_handle);

/*****************************************************************************
* FUNCTION
 *    vm_magic_cancel
 * DESCRIPTION
 *  release the memory in resource link table
 * PARAMETERS
 *  id: [IN] the resource id when return value saving in table
 * RETURNS
 *  if 0, success; others, fail.
*****************************************************************************/
VMINT vm_magic_cancel(VMINT id);
											
#ifdef __cplusplus
}
#endif 

#endif /* VMMAGICINTERNAL_H */

