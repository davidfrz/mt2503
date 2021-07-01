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
 *    vmtsloader.c
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_CORT_TS__
#include "AP_BtSS.h"
#include "ts_csci_dynamic.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "csci.h"
#include "wdt_sw.h"

#include "vmsys.h"
#include "vmopt.h"
#include "vmio.h"
#include "vmlog.h"
#include "elf.h"
#include "elfldr.h"
#include "vmstdlib.h"
#include "vmmem.h"
#include "vmtsloader.h"
#include "vmpromng.h"
#include "vmpromnginner.h"

#define ts_min2(a, b) ((a) <= (b) ? (a) : (b))
#define ts_max2(a, b) ((a) >= (b) ? (a) : (b))

#define VM_TS_MAX_APP_SIZE 10

typedef struct
{
	char app[5];
	VMUINT8* load_addr;
	int used;
	void* tiny_address;
}vm_ts_app_list_struct;


vm_ts_app_list_struct vm_ts_app_list[VM_TS_MAX_APP_SIZE] = {
		{"app0", NULL, 0},
		{"app1", NULL, 0},
		{"app2", NULL, 0},
		{"app3", NULL, 0},
		{"app4", NULL, 0},
		{"app5", NULL, 0},
		{"app6", NULL, 0},
		{"app7", NULL, 0},
		{"app8", NULL, 0},
		{"app9", NULL, 0}
};

#if defined (__UPDATE_BINARY_FILE__)
CSCI_EXTERN_ARR(int,vm_ts_handle_list);/*defined in hal\system\AP_BtSS\src\AP_UBin_CSCI.c*/
#else
CSCI_DEFINE_ARR(int,vm_ts_handle_list, 20);
#endif /*defined (__UPDATE_BINARY_FILE__) */

extern _vm_pcb_t* pcb_table[];
extern vm_sm_builtin_struct mre_buildin_vtp_array[];
extern vm_sm_builtin_struct mre_buildin_vxp_array[];

extern VMINT _vm_sb_stack_push(VMINT r9);
extern VMINT _vm_sb_stack_pop(void);
extern VMINT vm_per_hash( VMCHAR * src );
extern VMWSTR vm_get_self_filename(void);

void vm_ts_reset_app_list(void)
{
	int i;
	
	for(i=0; i<VM_TS_MAX_APP_SIZE; i++)
	{
		if(vm_ts_handle_list[i]!=0)
		{
			vm_ts_app_list[i].load_addr= (VMUINT8*)vm_ts_handle_list[i];
			vm_ts_app_list[i].used = 1;
		}
		
	}
	
}

static VMINT vm_ts_resolve_symbol_sysv( const vm_ts_sysv_node_t *exe_node, VMUINT symbol, VMUINT *abs_value)
{
    vm_elf_symtbl_entry_t *syment;
    char *symname; 
    int found = 0;
    const vm_so_node_t *so_node;
    VMINT index;
    
    if (symbol == 0 /*STN_UNDEF*/) {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RESOLVE1);
        return -1;
    }
    
    if (symbol >= exe_node->sysv_symtab_count) {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RESOLVE2, symbol, exe_node->sysv_symtab_count);
        return -2;
    }
    
    syment = exe_node->sysv_symtab + symbol;
    symname = exe_node->sysv_dynstr + syment->st_name;
    
    if (syment->st_shndx != VM_SHN_UNDEF) {
        *abs_value = syment->st_value + (VMUINT)(exe_node->tiny_address - exe_node->sysv_virt);
        return 0;
    }
        
    if (VM_ELF32_ST_BIND(syment->st_info) == VM_STB_WEAK) {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RESOLVE3);
        return 0;
    }
    else {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RESOLVE4, symbol);
        return -3;
    }
}

static VMINT vm_ts_parse_sysv_reloc( const vm_ts_sysv_node_t *exe_node, const vm_elf_rel_t* rel )
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMUINT8 type;
	VMUINT symbol;
    VMUINT *fix_address;
    VMINT ret;
    VMUINT symvalue;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	type = VM_ELF32_R_TYPE(rel->r_info);
	symbol = VM_ELF32_R_SYM(rel->r_info);
	
	fix_address = (VMUINT *)(exe_node->sysv_base + rel->r_offset - exe_node->sysv_virt);
	
	switch (type) 
	{
	default:
	case VM_R_ARM_CALL:  /* R_ARM_CALL is not a dynamic relocation in aaelf.pdf */
	case VM_R_ARM_JUMP24:/* R_ARM_JUMP24 is not a dynamic relocation in aaelf.pdf */
	    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RELOC1, type);
		return -1;
		 
	case VM_R_ARM_COPY:  /* R_ARM_COPY is a dynamic relocation, but we can't support it */
	    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RELOC2, type);
	    return -2;
	    
	case VM_R_ARM_RELATIVE:
		*fix_address += (VMUINT)(exe_node->tiny_address - exe_node->sysv_virt);
		return 0;
		
	case VM_R_ARM_ABS32:   /* R_ARM_ABS32 is not a dynamic relocation in aaelf.pdf */
	case VM_R_ARM_GLOB_DAT:
	case VM_R_ARM_JUMP_SLOT:
	    ret = vm_ts_resolve_symbol_sysv(exe_node, symbol, &symvalue);
	    if (ret == 0) {
	        *fix_address += symvalue;
	        return 0;
	    }
	    else {
	        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RELOC3, symbol, ret);
	        return -3;
	    }
	}
}


static VMINT vm_ts_do_sysv_loadfix(vm_ts_load_context_t *context, vm_elf_head_t *elf_head, 
                                    char *str_tab, VMUINT str_size,
                                    vm_elf_section_head_t *sh_tab, VMINT sh_num)
{
    vm_elf_section_head_t *rw_sh, *ro_sh, *sh;
    VMINT lerr = 0, info = 0, ret = 0;
    vm_elf_rel_t *prel;
    VMINT index;
	VMUINT highest_ro = 0, lowest_rw = 0xFFFFFFFF;

    ro_sh = get_elf_section_head_by_name(".text", str_tab, str_size, sh_tab, sh_num);
    if (ro_sh == NULL) {
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_DO_LOADFIX_RO);
        return VM_TS_LOAD_ERR_FORMAT;
    }
    rw_sh = get_elf_section_head_by_name(".data", str_tab, str_size, sh_tab, sh_num);
    if (rw_sh == NULL) {
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_DO_LOADFIX_RW);
        return VM_TS_LOAD_ERR_FORMAT;
    }
    
    context->codeBase = context->sysv_node.sysv_base + ro_sh->sh_offset;
    context->codeSize = ro_sh->sh_size;
    context->dataBase = context->sysv_node.sysv_base + rw_sh->sh_offset;
    context->dataSize = context->sysv_node.sysv_length - rw_sh->sh_offset;
	
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_DO_LOADFIX_INFO, context->codeBase, context->codeSize, context->dataBase, context->dataSize);

    for (index = 0, sh = sh_tab; index < sh_num; index++, sh++) 
	{
        if (!(sh->sh_flags & VM_SHF_ALLOC)) {
            continue;
        }
        if (sh->sh_flags & VM_SHF_WRITE) {
            lowest_rw = ts_min2(lowest_rw, sh->sh_addr);
        }
        else {
            highest_ro = ts_max2(highest_ro, sh->sh_addr + sh->sh_size);
        }
    }
	
    if (lowest_rw > highest_ro) 
	{
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_DO_LOADFIX_INFO, 0, 0, lowest_rw, highest_ro);
    }
    
    context->roSize = lowest_rw - (VMUINT)context->sysv_node.sysv_virt;
    
    if (context->preload_flags == VM_TS_LOAD_PRELOAD_READ) {
        return 0;
    }
    
    sh = get_elf_section_head_by_name(".dynstr", str_tab, str_size, sh_tab, sh_num);
    if (sh != NULL) {
        if (!(sh->sh_flags & VM_SHF_ALLOC)) {
            lerr = 3; goto bad;
        }
        
        context->sysv_node.sysv_dynstr = (char *)context->sysv_node.sysv_base + sh->sh_offset;
        context->sysv_node.sysv_dynstr_size = sh->sh_size;
    }
    
    sh = get_elf_section_head_by_name(".dynsym", str_tab, str_size, sh_tab, sh_num);
    if (sh != NULL) {
        if (!(sh->sh_flags & VM_SHF_ALLOC)) {
            lerr = 4; goto bad;
        }
        
        context->sysv_node.sysv_symtab = (vm_elf_symtbl_entry_t *)(context->sysv_node.sysv_base + sh->sh_offset);
        context->sysv_node.sysv_symtab_count = sh->sh_size / sizeof(vm_elf_symtbl_entry_t);
    }
        
    sh = get_elf_section_head_by_name(".rel.dyn", str_tab, str_size, sh_tab, sh_num);
    if (sh != NULL) {
        if (!(sh->sh_flags & VM_SHF_ALLOC)) {
            lerr = 6; goto bad;
        }

        context->sysv_node.sysv_dynrel = (vm_elf_rel_t *)(context->sysv_node.sysv_base + sh->sh_offset);
        context->sysv_node.sysv_dynrel_count = sh->sh_size/sizeof(vm_elf_rel_t);
        
        prel = context->sysv_node.sysv_dynrel;

        {
            for ( index = 0; index < context->sysv_node.sysv_dynrel_count; index++, prel++ ) {
                ret = vm_ts_parse_sysv_reloc( &context->sysv_node, prel );
                if (ret != 0) {
                    lerr = 8; info = index; goto bad;
                }
            }
        }
    }
    
    sh = get_elf_section_head_by_name(".rel.plt", str_tab, str_size, sh_tab, sh_num);
    if (sh != NULL) {
        if (!(sh->sh_flags & VM_SHF_ALLOC)) {
            lerr = 7; goto bad;
        }
        
        context->sysv_node.sysv_pltrel = (vm_elf_rel_t *)(context->sysv_node.sysv_base + sh->sh_offset);
        context->sysv_node.sysv_pltrel_count = sh->sh_size/sizeof(vm_elf_rel_t);
        
        prel = (vm_elf_rel_t *)(context->sysv_node.sysv_base + sh->sh_offset);

        {
            for ( index = 0; index < context->sysv_node.sysv_pltrel_count; index++, prel++ ) {
                ret = vm_ts_parse_sysv_reloc( &context->sysv_node, prel );
                if (ret != 0) {
                    lerr = 10; info = index; goto bad;
                }
            }
        }
    }
    
    return 0;
bad:
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_SYSV_FIX, lerr, info, ret);
	return VM_TS_LOAD_ERR_FORMAT;
}

static VMINT vm_ts_do_file_sysv_loadfix(vm_ts_load_context_t *context, vm_elf_handle_t *handle)
{
    vm_elf_section_head_t *sh_tab, *str_sh;
    VMINT sh_tabsize;
    char* str_tab = NULL;
    VMUINT nread;
    
    VMINT lerr = 0, ret = 0;
    
    if ((handle->elf_head.e_shnum == 0) || (handle->elf_head.e_shentsize == 0)) {
        lerr = 1; ret = handle->elf_head.e_shentsize; goto bad;
    }
    if (handle->elf_head.e_shstrndx == VM_SHN_UNDEF) {
        lerr = 2; goto bad;
    }
    if (handle->elf_head.e_shstrndx >= handle->elf_head.e_shnum) {
        lerr = 3;  ret = handle->elf_head.e_shnum; goto bad;
    }
    
    // read the whole sectin table in once, each entry is 40B, in GCC generated file, near 22 ==> 880B
    sh_tabsize = handle->elf_head.e_shentsize * handle->elf_head.e_shnum;
    sh_tab = _vm_kernel_malloc(sh_tabsize);
    if (sh_tab == NULL) {
        lerr = 4;  goto bad;
    }
    vm_file_seek(handle->file, handle->elf_head.e_shoff, BASE_BEGIN);
    ret = vm_file_read(handle->file, sh_tab, sh_tabsize, &nread);
    if (ret != sh_tabsize) {
        lerr = 5; goto free_shtab;
    }
    
    str_sh = sh_tab + handle->elf_head.e_shstrndx;
    
    str_tab = _vm_kernel_malloc(str_sh->sh_size);
    if (str_tab == NULL) {
        lerr = 6; goto free_shtab;
    }
    ret = read_elf_section(handle, str_sh, str_tab);
    if (ret != 0) {
        lerr = 7; goto free_strtab;
    }
    
    ret = vm_ts_do_sysv_loadfix(context, &handle->elf_head, str_tab, str_sh->sh_size, sh_tab, handle->elf_head.e_shnum);
    _vm_kernel_free(str_tab);
    _vm_kernel_free(sh_tab);
    if (ret != 0) {
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_DO_FILE_LOADFIX_INFO, ret);
    }
    return ret;
    
free_strtab:
    _vm_kernel_free(str_tab);
free_shtab:
    _vm_kernel_free(sh_tab);
bad:
	
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_DO_FILE_LOADFIX_INFO, ret);

    {
        static const VMINT err_map[] = { VM_TS_LOAD_ERR_UNKNOWN, VM_TS_LOAD_ERR_FORMAT, VM_TS_LOAD_ERR_FORMAT,
             VM_TS_LOAD_ERR_FORMAT, VM_TS_LOAD_ERR_UNKNOWN,  VM_TS_LOAD_ERR_UNKNOWN,
             VM_TS_LOAD_ERR_FORMAT, VM_TS_LOAD_ERR_UNKNOWN };
        return err_map[lerr];
    }
}

static VMINT vm_ts_load_normal(vm_ts_load_context_t *context)
{
    vm_elf_handle_t handle;
    vm_elf_prog_head_t ph;
    VMINT index;
    VMINT load_count;
    VMINT base_offset, base_virt, max_virt;
    VMUINT ziSize = 0;
    VMUINT nread;
    VMINT lerr = 0,ret = 0;
    
    ret = open_elf(context->fileName, &handle);
    if (ret != 0) {
        lerr = 1; goto open_failed;
    }
    
    base_offset = 0xFFFFFFFF;
    base_virt = 0xFFFFFFFF;
    max_virt = 0;
    load_count = 0;
    for (index = 0; index < handle.elf_head.e_phnum; index++) {
        ret = read_elf_prog_head_by_index(&handle, index, &ph);
        if (ret != 0) {
            lerr = 2; goto read_failed;
        }
        
        if (ph.p_type != VM_PT_LOAD) {
            continue;
        }
        load_count++;
        if (ph.p_vaddr != ph.p_paddr) {
            /* for normal application, this 2 fields must be equal */
            /* if they are different, maybe it's an OS image or some bare image, we can't load */
            lerr = 3; ret = ph.p_paddr; goto read_failed;
        }
        
        base_offset = ts_min2(base_offset, ph.p_offset);
        base_virt   = ts_min2(base_virt,   ph.p_vaddr);
        max_virt    = ts_max2(max_virt, ph.p_vaddr + ph.p_memsz);
        if (max_virt == (ph.p_vaddr + ph.p_memsz)) {
            ziSize = (ph.p_memsz - ph.p_filesz);
        }
    }
    
    if (load_count == 0) {
        lerr = 4; goto read_failed;
    }
    
    if (base_offset != 0) {
        lerr = 5; goto read_failed;
    }
    
    if (context->preload_flags != VM_TS_LOAD_PRELOAD_READ) {
        if (context->load_size < (max_virt - base_virt)) {
            lerr = 6; ret = (max_virt - base_virt); goto read_failed;
        }
        
        for (index = 0; index < handle.elf_head.e_phnum; index++) {
            ret = read_elf_prog_head_by_index(&handle, index, &ph);
            if (ret != 0) {
                lerr = 7; goto read_failed;
            }
            
            if (ph.p_type != VM_PT_LOAD) {
                continue;
            }
            
            vm_file_seek(handle.file, ph.p_offset, BASE_BEGIN);
            ret = vm_file_read(handle.file, context->load_buffer + (ph.p_vaddr - base_virt), ph.p_filesz, &nread);
            if (ret < 0) {
                lerr = 8; goto read_failed;
            }
            memset(context->load_buffer + (ph.p_vaddr - base_virt) + ph.p_filesz, 0, ph.p_memsz - ph.p_filesz);
        }
    }
    
    context->sysv_node.sysv_base = context->load_buffer;
    context->sysv_node.sysv_length = max_virt - base_virt;
    context->sysv_node.sysv_virt = (VMUINT8 *)base_virt;
    ret = vm_ts_do_file_sysv_loadfix(context, &handle);
    if (ret != 0) {
        lerr = 9; goto read_failed;
    }
    close_elf(&handle);
    
    context->rwSize = context->sysv_node.sysv_length - context->roSize - ziSize;
    context->ziSize = ziSize;
    context->entry = (void *)(context->sysv_node.sysv_base + handle.elf_head.e_entry - context->sysv_node.sysv_virt);
    
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LOAD_NORMAL, context->rwSize, context->ziSize, context->entry);

    return 0;
    
read_failed:
    close_elf(&handle);
open_failed:
	
	
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LOAD_NORMAL, 0,0, lerr);

    {
        static const VMINT err_map[] = { VM_TS_LOAD_ERR_UNKNOWN, VM_TS_LOAD_ERR_FORMAT, VM_TS_LOAD_ERR_IO,
             VM_TS_LOAD_ERR_FORMAT, VM_TS_LOAD_ERR_FORMAT,  VM_TS_LOAD_ERR_FORMAT, VM_TS_LOAD_ERR_FORMAT, VM_TS_LOAD_ERR_IO, VM_TS_LOAD_ERR_IO,
             VM_TS_LOAD_ERR_UNKNOWN };
        if (lerr == 9) {
            return ret;
        }
        return err_map[lerr];
    }
}

static VMINT vm_ts_do_rom_sysv_loadfix(vm_ts_load_context_t *context, VMUINT8 *execImage, vm_elf_head_t *elf_head)
{
    vm_elf_section_head_t *sh_tab, *str_sh;
    char *str_tab;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    if ((elf_head->e_shnum == 0) || (elf_head->e_shentsize == 0)) {
        lerr = 1; info = elf_head->e_shnum; ret = elf_head->e_shentsize; goto bad;
    }
    if (elf_head->e_shstrndx == VM_SHN_UNDEF) {
        lerr = 2; goto bad;
    }
    if (elf_head->e_shstrndx >= elf_head->e_shnum) {
        lerr = 3; info = elf_head->e_shstrndx; ret = elf_head->e_shnum; goto bad;
    }
    
    sh_tab = (vm_elf_section_head_t *)(execImage + elf_head->e_shoff);
    str_sh = sh_tab + elf_head->e_shstrndx;
    str_tab = (char *)(execImage + str_sh->sh_offset);
    
    ret = vm_ts_do_sysv_loadfix(context, elf_head, str_tab, str_sh->sh_size, sh_tab, elf_head->e_shnum);
    if (ret != 0) {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LDR_ROM_SYSV_FIX, 5, info, ret);
    }
    return ret;

bad:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LDR_ROM_SYSV_FIX, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_TS_LOAD_ERR_UNKNOWN, VM_TS_LOAD_ERR_FORMAT, VM_TS_LOAD_ERR_FORMAT,
             VM_TS_LOAD_ERR_FORMAT };
        return err_map[lerr];
    }
}

static VMINT vm_ts_load_rom_normal(vm_ts_load_context_t *context)
{
    VMUINT8* execImage;
    vm_elf_head_t *head;
    vm_elf_prog_head_t *ph;
    VMINT index;
    VMINT load_count;
    VMINT base_offset, base_virt, max_virt;
    VMUINT ziSize = 0;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    execImage = vm_get_execrom_ptr((VMWCHAR*)context->fileName);
    if (execImage == NULL) {
        lerr = 1; goto bad_fn;
    }
    
    head = (vm_elf_head_t *)execImage;
    if (strncmp((char *)head->e_ident, "\x7f""ELF", 4) != 0) {
        lerr = 2; info = *(VMINT *)(head->e_ident); goto bad_fn;
    }
    
    base_offset = 0xFFFFFFFF;
    base_virt = 0xFFFFFFFF;
    max_virt = 0;
    load_count = 0;
    ph = (vm_elf_prog_head_t *)(execImage + head->e_phoff);
    for (index = 0; index < head->e_phnum; index++, ph++) {
        if (ph->p_type != VM_PT_LOAD) {
            continue;
        }
        load_count++;
        
        base_offset = ts_min2(base_offset, ph->p_offset);
        base_virt   = ts_min2(base_virt,   ph->p_vaddr);
        max_virt    = ts_max2(max_virt, ph->p_vaddr + ph->p_memsz);
        if (max_virt == (ph->p_vaddr + ph->p_memsz)) {
            ziSize = (ph->p_memsz - ph->p_filesz);
        }
    }
    
    if (load_count == 0) {
        lerr = 3; goto bad_fn;
    }
    if (base_offset != 0) {
        lerr = 4; info = base_offset; goto bad_fn;
    }
    
    if (context->preload_flags != VM_TS_LOAD_PRELOAD_READ) {
        // check the load buffer is large enough
        if (context->load_size < (max_virt - base_virt)) {
            lerr = 5; info = context->load_size; ret = (max_virt - base_virt); goto bad_fn;
        }
        
        ph = (vm_elf_prog_head_t *)(execImage + head->e_phoff);
        for (index = 0; index < head->e_phnum; index++, ph++) {
            if (ph->p_type != VM_PT_LOAD) {
                continue;
            }
            // do the load
            memcpy(context->load_buffer + (ph->p_vaddr - base_virt), execImage + ph->p_offset, ph->p_filesz);
            memset(context->load_buffer + (ph->p_vaddr - base_virt) + ph->p_filesz, 0, ph->p_memsz - ph->p_filesz);
        }
    }
    
    context->sysv_node.sysv_base = context->load_buffer;
    context->sysv_node.sysv_length = max_virt - base_virt;
    context->sysv_node.sysv_virt = (VMUINT8 *)base_virt;
    ret = vm_ts_do_rom_sysv_loadfix(context, execImage, head);
    if (ret != 0) {
        lerr = 6; goto bad_fn;
    }
    
    context->rwSize = context->sysv_node.sysv_length - context->roSize - ziSize;
    context->ziSize = ziSize;
    // both RVCT & GCC can apply this
    context->entry = (void *)(context->sysv_node.sysv_base + head->e_entry - context->sysv_node.sysv_virt);
    return 0;
    
bad_fn:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LDR_ROM_N_SYSV, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_TS_LOAD_ERR_UNKNOWN, VM_TS_LOAD_ERR_FORMAT, VM_TS_LOAD_ERR_FORMAT,
             VM_TS_LOAD_ERR_FORMAT, VM_TS_LOAD_ERR_FORMAT,  VM_TS_LOAD_ERR_UNKNOWN};
        if (lerr == 6) {
            return ret;
        }
        return err_map[lerr];
    }
}


VMINT vm_ts_read_preload_app_info(vm_ts_preload_app_info_t *preload_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_ts_load_context_t *p_context;
    VMINT ret = 0;
    
    if (!preload_info->fullFileName || preload_info->fullFileName[0] == 0)
    {
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_T_NOT);
        return VM_TS_LOAD_ERR_FORMAT;
    }

  
  	p_context = &preload_info->saved_context;
        
    p_context->fileName = preload_info->fullFileName;
    p_context->preload_flags = VM_TS_LOAD_PRELOAD_READ;
	p_context->suffix = vm_parse_exec_format(p_context->fileName);

    if(p_context->suffix == VM_EXEC_ROM)
    {
    	ret = vm_ts_load_rom_normal(p_context);
    }
	else
	{
    	ret = vm_ts_load_normal(p_context);
	}
	
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_READ_P, 0, ret);

    if (ret != 0) {
        return ret;
    }
    
    preload_info->loadSize = p_context->roSize + p_context->rwSize + p_context->ziSize;
	
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_READ_P, 0, preload_info->loadSize);

    return 0;
}

VMINT vm_ts_preload_app(vm_ts_preload_app_info_t *preload_info)
{
                
	vm_ts_load_context_t *p_context = &preload_info->saved_context;
	VMINT ret = 0;
	
	p_context->load_buffer = (VMUINT8 *)preload_info->loadBase;
	p_context->load_size = preload_info->loadBufSize;
	p_context->preload_flags = 0;
	
    if(p_context->suffix == VM_EXEC_ROM)
    {
    	ret = vm_ts_load_rom_normal(p_context);
    }
	else
	{
    	ret = vm_ts_load_normal(p_context);
	}
	
	return ret;
}

static VMINT vm_ts_get_path(VMINT drv, VMWSTR name, VMWSTR wname)
{
	VMINT find_hdl;   
	struct vm_fileinfo_t info;

    kal_wsprintf((WCHAR *)wname, "%c:\\@BTMre\\installed\\bt_notify_mre_%w.vtp", drv, name);

	if((find_hdl = vm_find_first(wname, &info)) >= 0)
	{
		vm_find_close(find_hdl);
		return TRUE;
	}
    
    kal_wsprintf((WCHAR *)wname, "%c:\\@BTMre\\installed\\%w.vtp", drv, name);

	if((find_hdl = vm_find_first(wname, &info)) >= 0)
	{
		vm_find_close(find_hdl);
		return TRUE;
	}
    
	kal_wsprintf((WCHAR *)wname, "%c:\\mre\\%w.vtp", drv, name);

	if((find_hdl = vm_find_first(wname, &info)) >= 0)
	{
		vm_find_close(find_hdl);
		return TRUE;
	}
	return FALSE;
}


static VMINT vm_ts_name_preprocess(VMWSTR name, VMWSTR wname)
{
	if (kal_wstrchr((WCHAR *)name, '\\') == NULL)
	{
		if (!vm_ts_get_path(vm_get_removeable_driver(), name, wname))
		{
			MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_T_NOT);
			if (!vm_ts_get_path(vm_get_system_driver(), name, wname) )
			{
			    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_T_NOT);
			    if (!vm_ts_get_path(vm_get_nvram_driver(), name, wname) )
    			    {
    				VMUINT i,appcount,smcount,socount,vtpcount, vxpcount;
    				VMWCHAR tempName[64];
    				VMCHAR tempName1[64];
    				
    				vm_init_default_game(&appcount, &smcount, &socount, &vtpcount, &vxpcount);
    				
    				for(i = 0; i < vtpcount; i++)
    				{
    					vm_ascii_to_ucs2((VMWSTR)tempName, 64, (VMSTR)mre_buildin_vtp_array[i].file_name);
    					if(kal_wstrcmp((WCHAR *)tempName, (WCHAR *)name) == 0)
    					{
    						sprintf(tempName1, "%c:\\%u.rom", 64, mre_buildin_vtp_array[i].address);
    						vm_ascii_to_ucs2((VMWSTR)wname, 64, (VMSTR) tempName1);
    						return 0;
    					}
    				}
    				return -1;
			    }
			}
		}
	}
	else
	{
		VMINT find_hdl;
		struct vm_fileinfo_t info;
		
		vm_wstrcpy(wname, name);

		if((find_hdl = vm_find_first(wname, &info)) >= 0)
		{
			vm_find_close(find_hdl);
		}
		else
		{
			MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_F_NOT);
			return -1;
		}
	}
	return 0;
}

VMINT vm_ts_check_boot_up_source(_vm_pcb_t* pcb)
{
	//BOOT_UP_SOURCE source;
	//source = AP_check_boot_up_source();

	//if(source == WARM_BOOT || source == COLD_BOOT || source == HIBERNATION_EXCEPTION)
	{
		VMWCHAR* exec_filename = NULL;
		char ascii[MAX_APP_NAME_LEN] = {0};
		VMINT hashvalue = 0;
		int i;
		
		vm_ucs2_to_ascii(ascii,MAX_APP_NAME_LEN,pcb->fullFileName);
		
		hashvalue = vm_per_hash(ascii);
		
		for(i=0; i<VM_TS_MAX_APP_SIZE; i++)
		{
			if(hashvalue == vm_ts_handle_list[i+VM_TS_MAX_APP_SIZE])
			{
				vm_ts_app_list[i].load_addr = (VMUINT8*)vm_ts_handle_list[i];
				vm_ts_app_list[i].used = 1;
				return 1;
			}
		}
		
		return 0;
		
	}
	
	//return 0;
}

VMINT vm_ts_get_hash_value(void)
{
	VMWCHAR* exec_filename = NULL;
	char ascii[MAX_APP_NAME_LEN] = {0};
	exec_filename = vm_get_self_filename();

	if (exec_filename == NULL)
	{
		return 0;
	}
	
	vm_ucs2_to_ascii(ascii,MAX_APP_NAME_LEN,exec_filename);

	return vm_per_hash(ascii);
}

VMINT vm_ts_driver_load(VMWSTR fileName, VMINT size)
{
	VMINT ret,i;
    VMINT share_size = size;
	vm_ts_preload_app_info_t preload_info;

    memset(&preload_info, 0, sizeof(vm_ts_preload_app_info_t));
	
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LOAD_ENTER);

	ret = vm_ts_name_preprocess(fileName, preload_info.fullFileName);
    if (ret)
    {
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LOAD_EXIT, 1);
        return VM_TS_LOAD_ERR_IO;
    }
		
 	ret = vm_ts_read_preload_app_info(&preload_info);
	
    if (ret)
    {
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LOAD_EXIT, 2);
        return VM_TS_LOAD_ERR_IO;
    }

	for(i=0; i<VM_TS_MAX_APP_SIZE; i++)
	{

		if(vm_ts_app_list[i].used == 0)
			break;
	}

	if(i>=VM_TS_MAX_APP_SIZE)
	{
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LOAD_EXIT, 4);
		return VM_TS_LOAD_ERR_MAXSIZE;
	}

	if(size % 4 == 0)
		share_size = size;
	else if(size % 4 == 1)
		share_size = size+3;
	else if(size % 4 == 2)
		share_size = size+2;
	else
		share_size = size+1;
		
	ret =  csci_alloc(preload_info.loadSize + 8 + share_size, vm_ts_app_list[i].app, &vm_ts_app_list[i].load_addr);

	if(ret < 0 || vm_ts_app_list[i].load_addr == NULL )
	{
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LOAD_EXIT, 5);
		return VM_TS_LOAD_ERR_MEMORY;
	}
	
	vm_ts_handle_list[i] = (int)vm_ts_app_list[i].load_addr;
	vm_ts_handle_list[i+VM_TS_MAX_APP_SIZE] = vm_ts_get_hash_value();
		
	vm_ts_app_list[i].used = 1;
	preload_info.saved_context.sysv_node.tiny_address = (VMUINT8 *)(csci_ts_addr(vm_ts_app_list[i].load_addr)+ 8 + share_size);
    preload_info.loadBufSize = preload_info.loadSize;
    preload_info.loadBase = vm_ts_app_list[i].load_addr + 8 + share_size;
	
    ret = vm_ts_preload_app(&preload_info);
	
    if (ret)
    {
		vm_ts_app_list[i].used = 0;
        csci_free(vm_ts_app_list[i].load_addr);
		vm_ts_app_list[i].load_addr = NULL;
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LOAD_EXIT, 6);
    }
	else
	{
		*((int*)vm_ts_app_list[i].load_addr) = (VMINT)preload_info.saved_context.entry - (VMINT)vm_ts_app_list[i].load_addr;
		*((int*)(vm_ts_app_list[i].load_addr+4)) = share_size;
	}
	
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_LOAD_EXIT, 0);

	return i;
		
}

void vm_ts_driver_free(VMINT handle)
{	
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_FREE);
	vm_ts_app_list[handle].used = 0;
	csci_free(vm_ts_app_list[handle].load_addr);
	vm_ts_app_list[handle].load_addr = NULL;
	vm_ts_handle_list[handle] = 0;
	vm_ts_handle_list[handle+VM_TS_MAX_APP_SIZE] = 0;
}

void* vm_ts_driver_get_mem(VMINT handle)
{
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_TS_GET_MEMORY);
	return (void*)(vm_ts_app_list[handle].load_addr + 8);
}

VMINT vm_ts_driver_get_handle(void)
{
	VMINT i;
	VMINT hashvalue = vm_ts_get_hash_value();
	
	for(i=0; i<VM_TS_MAX_APP_SIZE; i++)
	{
		if(hashvalue == vm_ts_handle_list[i+VM_TS_MAX_APP_SIZE])
		{
			vm_ts_app_list[i].load_addr = (VMUINT8*)vm_ts_handle_list[i];
			vm_ts_app_list[i].used = 1;
			return i;
		}
	}
	return -1;
}

int vm_ts_ap_mode_callback(AP_BtSS_mode mode)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	ilm_struct *ilm_ptr = NULL;
    vm_ts_current_mode_struct *current_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(AP_BTSS_SUSPEND == mode )
    {
	    current_mode = (vm_ts_current_mode_struct*) construct_local_para(sizeof(vm_ts_current_mode_struct), TD_RESET);
	    current_mode->mode = mode;

		/*----------------------------------------------------------------*/
		/* Code Body													  */
		/*----------------------------------------------------------------*/
		ilm_ptr = allocate_ilm(MOD_TINY_HISR);
		ilm_ptr->src_mod_id = MOD_TINY_HISR;
		ilm_ptr->dest_mod_id = MOD_MMI;
		ilm_ptr->msg_id = MSG_ID_MRE_SWITCH_TO_AP_MODE;
		ilm_ptr->sap_id = 0;
		ilm_ptr->local_para_ptr = (local_para_struct*)current_mode;
		ilm_ptr->peer_buff_ptr = NULL;
		SEND_ILM(MOD_TINY_HISR, MOD_MMI, 0, ilm_ptr);
	}
	return 1;
}

#endif

