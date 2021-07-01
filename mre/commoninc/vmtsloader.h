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
 *    vmtsloader.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    tiny system driver loader.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VM_TSLOADER_H
#define _VM_TSLOADER_H

#ifdef __cplusplus
extern "C" {
#endif

#define VM_TS_LOAD_PRELOAD      0x1
#define VM_TS_LOAD_PRELOAD_READ 0x2

typedef struct vm_ts_preload_app_info vm_ts_preload_app_info_t;
typedef struct vm_ts_load_context     vm_ts_load_context_t;


typedef struct
{
    VMUINT8 *sysv_base;
    VMUINT   sysv_length;
    VMUINT8 *sysv_virt;
	vm_elf_symtbl_entry_t *sysv_symtab;
    VMUINT   sysv_symtab_count;
    char    *sysv_dynstr;
    VMUINT   sysv_dynstr_size;
    vm_elf_rel_t *sysv_dynrel;
    VMUINT   sysv_dynrel_count;
    vm_elf_rel_t *sysv_pltrel;
    VMUINT   sysv_pltrel_count;
	VMUINT8* tiny_address;
} vm_ts_sysv_node_t;

struct vm_ts_load_context 
{
    VMWCHAR* fileName;
    VMUINT8 preload_flags;
    vm_exec_format_enum suffix;
    
    VMUINT8 *load_buffer;
    VMUINT load_size;
    
    VMUINT8 *codeBase, *dataBase;
    VMUINT   codeSize,  dataSize;
    VMUINT roSize,  rwSize,  ziSize;
    void *entry;
    
    vm_ts_sysv_node_t sysv_node;
};


struct vm_ts_preload_app_info
{
	VMINT loadSize;

	void *loadBase;
	VMINT loadBufSize;
        
	vm_ts_load_context_t saved_context;
	void *entry;
	VMINT flags;
	VMWCHAR fullFileName[MAX_APP_NAME_LEN + 1];	
};

typedef struct _vm_ts_current_mode_struct
{
    VMUINT8 ref_count;
    VMUINT16 msg_len;
    /* LOCAL_PARA_HDR */
    VMINT mode;
}vm_ts_current_mode_struct;


VMINT vm_ts_load_normal(vm_ts_load_context_t *p_context);
VMINT vm_ts_read_preload_app_info(vm_ts_preload_app_info_t *preload_info);
VMINT vm_ts_preload_app(vm_ts_preload_app_info_t *preload_info);

#include "vmtsloader_sdk.h"

#ifdef __cplusplus
}
#endif 
#endif
