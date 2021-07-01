/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cp15.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for coprocessor(CP15) control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CP15_H__
#define __CP15_H__


#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

#include "kal_general_types.h"

/************************************
  * I/D-TCM related. 
  ***********************************/
extern kal_uint32 cp15_read_tcm_status(void);
extern kal_uint32 cp15_read_itcm_region(void);
extern kal_uint32 cp15_read_dtcm_region(void);
extern void cp15_enable_itcm(kal_uint32 addr);
extern void cp15_enable_dtcm(kal_uint32 addr);

#if defined(__ARM11_MMU__)
extern void cp15_tcm_select(kal_uint32 value);
extern kal_uint32 cp15_read_tcm_cache_size(void);
extern kal_uint32 cp15_tcm_status(void);
extern kal_uint32 cp15_read_itcm(void);
extern kal_uint32 cp15_read_dtcm(void);
extern void cp15_itcm_secure_access(kal_uint32 value);
extern void cp15_dtcm_secure_access(kal_uint32 value);
#endif /* __ARM11_MMU__ */

/************************************
  * General (I/D-Cache) cache related. 
  ***********************************/
extern kal_uint32 cp15_read_cache_type(void);
extern void cp15_invalidate_idcache_single(kal_uint32 mva);
extern void cp15_invalidate_idcache_region(kal_uint32 addr, kal_uint32 nr_cache);
extern void 	cp15_set_idcache_replacement_policy(void);

#if defined(__ARM11_MMU__)
extern void cp15_Cache_Behavior(void);
extern void cp15_switch_cache2RR(void);
#endif /* __ARM11_MMU__ */

/************************************
  * I-Cache related. 
  ***********************************/
extern void cp15_enable_icache(void);
extern void cp15_disable_icache(void);
extern void cp15_invalidate_icache(void);
extern void cp15_invalidate_icache_single(kal_uint32 mva);
extern void cp15_invalidate_icache_region(kal_uint32 addr, kal_uint32 nr_cache);
extern kal_uint32 cp15_is_icache_enabled(void);
extern void cp15_lockdown_icache(kal_uint32 L);
extern void cp15_prefetch_icache_line(kal_uint32 mva);


/************************************
  * D-Cache related. 
  ***********************************/
extern void cp15_enable_dcache(void);
extern void cp15_disable_dcache(void);
extern void cp15_invalidate_dcache(void);
extern void cp15_invalidate_dcache_single(kal_uint32 mva);
extern void cp15_clean_dcache_single(kal_uint32 mva);
extern void cp15_drain_write_buffer(void);
extern void cp15_invalidate_dcache_region(kal_uint32 addr, kal_uint32 nr_cache);
extern void cp15_clean_dcache_region(kal_uint32 addr, kal_uint32 nr_cache);
extern void cp15_clean_and_invalidate_dcache_region(kal_uint32 addr, kal_uint32 nr_cache);
extern void	cp15_clean_dcache(void);
extern kal_uint32 cp15_is_dcache_enabled(void);
extern void cp15_lockdown_dcache(kal_uint32 L);


/************************************
  * MMU related. 
  ***********************************/
extern void cp15_lockdown_TLB_entry(unsigned int addr);
extern kal_uint32 cp15_read_tbbr(void);
extern void cp15_write_tbbr(kal_uint32 addr);
extern void cp15_enable_mmu(void);
extern void cp15_disable_mmu(void);
extern kal_uint32 cp15_read_domain_access(void);
extern void cp15_write_domain_access(kal_uint32 domain, kal_uint32 access);
extern kal_uint32 cp15_read_ifsr(void);
extern kal_uint32 cp15_read_dfsr(void);
extern kal_uint32 cp15_read_far(void);
extern void cp15_invalidate_tlb_single(kal_uint32 mva);
extern void cp15_invalidate_tlb(void);
extern void cp15_enable_rom_protect(void);
extern void cp15_disable_rom_protect(void);
extern void cp15_enable_sys_protect(void);
extern void cp15_disable_sys_protect(void);
extern void cp15_enable_alignment_fault(void);
extern void cp15_disable_alignment_fault(void);

#if defined(__ARM11_MMU__)
extern kal_uint32 cp15_read_tbbr(void);
extern kal_uint32 cp15_read_tbbr1(void);
extern void cp15_write_tbbr1(kal_uint32 tbbr);
extern kal_uint32 cp15_read_ifar(void);
extern void cp15_disable_ap_subpage(void);
extern void cp15_enable_unaligned_access(void);
#endif /* __ARM11_MMU__ */

/************************************
  * Other cp15 feature related. 
  ***********************************/
extern void cp15_enter_low_pwr_state(void);

#if defined(__ARM11_MMU__)
extern void cp15_enable_branch_prediction(void);
extern void cp15_read_ctrl_register(void);
extern void cp15_set_ns_bit(void);
extern void cp15_Non_Secure_Access(void);
extern void cp15_switch_big_endian(void);
extern void cp15_switch_little_endian(void);
extern void cp15_data_memory_barrier(void);
#endif /* __ARM11_MMU__ */

#else   /* __ARM9_MMU__ || __ARM11_MMU__ */

/* define empty macro for backward compatible */

#define cp15_read_ifsr() 0
#define cp15_read_dfsr() 0
#define cp15_read_far() 0

#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */

#endif  /* __CP15_H__ */

