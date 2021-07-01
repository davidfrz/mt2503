/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    PictBridgeGProt.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef __PICT_BRIDGE_GPROT_H__
#define __PICT_BRIDGE_GPROT_H__
#include "MMI_features.h"

#ifdef __MMI_PICT_BRIDGE_SUPPORT__

/* auto add by kw_check begin */
#include "fs_type.h"
#include "kal_general_types.h"
/* RHR add end */
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_init 
 * DESCRIPTION
 *  This function initialize PictBridge MMI.
 * PARAMETERS
 *   void 
 * RETURNS
 *   void
 *****************************************************************************/
extern void mmi_pict_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_dps_disconnect_ind 
 * DESCRIPTION
 *  This function be invoked in case of DPS disconnect.
 * PARAMETERS
 *   void 
 * RETURNS
 *   void
 *****************************************************************************/
extern void mmi_pict_dps_disconnect_ind(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_print_file_handle_with_filepath 
 * DESCRIPTION
 *  get a printing file's FS handle and file path, invoked by USB task
 * PARAMETERS
 *  obj_handle          : [IN]        object handle in startJob request
 *  filepath            : [OUT]       file path
 *  max_filepath_length : [OUT]       file path length
 * RETURNS
 *  file handle of object
 *****************************************************************************/
extern FS_HANDLE mmi_pict_return_print_file_handle_with_filepath(kal_uint32 obj_handle, kal_uint16 *filepath, kal_uint16 *max_filepath_length);

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_print_file_handle_with_filename
 * DESCRIPTION
 *  get a printing file's FS handle and file name, invoked by USB task
 * PARAMETERS
 *  obj_handle          : [IN]        object handle in startJob request
 *  filename            : [OUT]       file name
 *  max_filename_length : [OUT]       file name length
 * RETURNS
 *  file handle of object
 *****************************************************************************/
extern FS_HANDLE mmi_pict_return_print_file_handle_with_filename(kal_uint32 obj_handle,  kal_uint16 *filename, kal_uint16 *max_filename_length);

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_current_print_file_info 
 * DESCRIPTION
 *  get a printing file's information, invoked by USB task 
 * PARAMETERS
 *  info            : [OUT]       file information
 * RETURNS
 *  indicate operation result
 *****************************************************************************/
extern int mmi_pict_return_current_print_file_info(FS_DOSDirEntry *info);
#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

#endif /* __PICT_BRIDGE_GPROT_H__ */

