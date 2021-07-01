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
 *  app_thread_mgr.h
 *
 * Project:
 * -------- 
 *  IOT
 *
 * Description:
 * ------------
 *  
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

#ifndef APP_THREAD_MGR_H
#define APP_THREAD_MGR_H


/*************************************************************************
  * Include Statements
  *************************************************************************/
#include "kal_general_types.h"
#include "app_frm_thread_gprot.h"
#include "app_frm_launcher_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
typedef struct
{
	LOCAL_PARA_HDR
	THREAD_HANDLE	  thread_handle;
	void*			  data;
} APP_THREAD_CREATE_PARAM_STRUCT;
typedef struct
{
    THREAD_HANDLE              main_thread_hd;
    THREAD_FUNC                thread_function;
	APP_PROC                   app_main_proc;
	kal_taskid 				   task_id;
    MMI_ID                     mod_id;
	U8                         mod_index;
    U8                         thread_type;   // THREAD_TYPE_NATIVE, THREAD_TYPE_MRE or THREAD_TYPE_NONE
    U8                         valid_index;
} APP_THREAD_INFO;

/***************************************************************************** 
 * Function
 *****************************************************************************/

/*******************************************************************************
* FUNCTION
*  app_frm_get_thread_info
* DESCRIPTION
*  get the thread informaiton.
* PARAMETERS
*  hd: [IN] the handle of the thread.
* RETURNS
*  Return the information of the thread. If the target thread doesn't exist, return NULL.
******************************************************************************/
extern APP_THREAD_INFO* app_frm_get_thread_info(THREAD_HANDLE hd);
/*******************************************************************************
* FUNCTION
*  app_frm_release_thread_int
* DESCRIPTION
*  internal used, release the management information when the thread exited.
* PARAMETERS
*  hd: [IN] the handle of the thread.
* RETURNS
*  None.
******************************************************************************/
extern void app_frm_release_thread_int(THREAD_HANDLE hd);

/*****************************************************************************
 * FUNCTION
 *  app_frm_get_thread_handle_by_mod
 * DESCRIPTION
 *  used for get thread handle. this API does not support in main task.
 * PARAMETERS
*  mod_id: [IN] the thread mod id.
 * RETURNS
 *  return  The handle of the thread.
 *****************************************************************************/
extern THREAD_HANDLE app_frm_get_thread_handle_by_mod(U16 mod_id);

extern THREAD_HANDLE app_frm_add_main_thread(APP_PROC proc, void* param);
extern THREAD_HANDLE app_frm_remove_main_thread(THREAD_HANDLE handle);
#endif // APP_THREAD_MGR_H

