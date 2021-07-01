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
 *   bl_ImageLoader_v5.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Reponsible for loading image on SV5 platform
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
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __SV5_ENABLED__

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "sw_types.h"
#include "bl_common.h"
#include "br_GFH_file_info.h"
#include "br_GFH_bl_info.h"
#include "bl_GFH_body.h"
#include "bl_BootInfo.h"
#include "bl_common.h"
#include "bl_loader.h"
#include "bl_custom.h"
#include "bl_setting.h"
#include "bl_status.h"
#include "bl_FOTA.h"
#include "bl_init.h"
#include "br_bl_param.h"

#include "custom_img_config.h"

#include "br_time_stamp.h"
#ifdef __TIME_STAMP__ 
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#endif

#include "FTL.h"
#include "br_header_block.h"
#include "br_GFH_error.h"
#include "br_shared_flash_drv.h"
#include "cbr.h"
#include "Cbr_record_def.h"

#include <string.h>
/*************************************************************************
 * Macro and const definition
 *************************************************************************/
extern kal_uint32 custom_RAM_baseaddr(void);
extern kal_uint32 custom_FACTORY_ROM_baseaddr(void);
extern kal_bool IsMetaModeEnabled(void);
extern U32  GFH_Find(U32 buf_addr, GFH_TYPE type, void ** pp_gfh);
 
#define REMAPPING_ADDR (custom_RAM_baseaddr())
#define REMAPPING_MASK (custom_RAM_baseaddr()-1)
#define MAX_FLASH_BOUNDARY (0xffffffff)

#ifndef __USE_EXTERNAL_READ_BUFFER__
#define PAGE_BUFFER_ADDR (SYSRAM_BASE+0x1000)
#else
#define PAGE_BUFFER_ADDR ((kal_uint32)(&externalPageBuffer))
#endif

#ifdef __NFI_SHARED_DRV__
extern void FTL_SetNFISharedDrv(kal_uint32 funcTblAddr, kal_uint32 *pHandleBufAddr);
#endif /* __NFI_SHARED_DRV__ */

extern kal_uint32 bl_slim_div(const kal_uint32 n, const kal_uint32 d, kal_uint32 *pR);
extern kal_uint32 bl_slim_mod(const kal_uint32 n, const kal_uint32 d);
extern kal_uint32 SST_CheckBootloaderHash(kal_uint32* pBinary);

#if defined(__EXT_BL_UPDATE__)
const kal_uint32 EXT_BL_END_MARK[] = MTK_EXT_BL_END_MARK;
#endif /* __EXT_BL_UPDATE__ */

/*************************************************************************
 * Structure definition
 *************************************************************************/

/*************************************************************************
 * Global variables definition
 *************************************************************************/

kal_uint32 g_maui_load_addr = INVALID_START_ADDR;
FTL_FuncTbl *g_ftlFuncTbl = NULL;

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__XIP_SHADOWING__)

static kal_uint32 mauiReadLen = 0, restMauiFlashAddr = 0;

#endif

#pragma arm section zidata = "EXT_UN_INIT_ZI"

#ifdef __USE_EXTERNAL_READ_BUFFER__
static kal_uint32 externalPageBuffer[8192/4];
#endif

static kal_uint32 g_mauiInfoBuf[1024/4];

#pragma arm section zidata

static kal_bool g_mauiInfoRead = KAL_FALSE;

/*************************************************************************
 * External symbols
 *************************************************************************/

extern const kal_char blID1[];
extern const kal_char blID2[];
extern FTL_FuncTbl ftlFuncTbl;
extern FTL_FuncTbl ftlFuncTblBl;
extern BL_Info_Wrapper_st BL_Shared_info;
extern BL_Param_v4 *g_pBROM_BL_Param;
extern kal_bool g_bootupDisabled;
extern kal_uint32 g_bootupStatus;
   
/*************************************************************************
 * Declaration
 *************************************************************************/

kal_uint32 GetBinaryStartInFlash(GFH_FILE_TYPE type);

/*************************************************************************
 * Main code
 *************************************************************************/

#ifdef __NAND_BOOT__
/**********************************************************
Description : Initialziation routines for each memory devices
Input       : None
Output      : None
***********************************************************/
BL_STATUS InitNFI(void)
{
   
#if __MINI_BOOTLOADER__
   kal_uint32 i;
   kal_uint32 *pSrc, *pDst;

   // Copy the Bootloader Header from predefined space
   pSrc = (kal_uint32 *)(&g_pBROM_BL_Param->m_hdrblk_info.m_region0_u.m_nand_hdr);
   pDst = (kal_uint32 *)&BLHeader;
   
   for (i=0; i<(sizeof(BLHeader)>>2); i++)  // Need to make sure BLHeader is 4 bytes multiple.
   {
      *pDst++ = *pSrc++;
   }
   
   if ( strcmp(blID1, BLHeader.ID1) || strcmp(blID2, BLHeader.ID2) )
   {
      BL_PRINT(LOG_ERROR, "\nBootloader Header ID incorrect, quit!\n\r");
      BL_PRINT(LOG_ERROR, "\nID1(default %s) = %s\n\r", blID1, BLHeader.ID1);
      BL_PRINT(LOG_ERROR, "\nID2(default %s) = %s\n\n\n\r", blID2, BLHeader.ID2);
      return INVALID_START_ADDR;
   }

#ifdef __NFI_SHARED_DRV__
if(g_pBROM_BL_Param->m_ver >= 4 )
    //((SD_Flash_Mapping_Table*)(((U32 *)(g_pBROM_BL_Param->m_sd_flash_drv_tbl_addr))[g_pBROM_BL_Param->m_sd_flash_drv_idx]))->m_sd_flash_drv_tbl_addr,
   FTL_SetNFISharedDrv( 0xfff0b440, &g_pBROM_BL_Param->m_sd_flash_drv_handle_addr);
else
   FTL_SetNFISharedDrv(g_pBROM_BL_Param->m_sd_nand_flash_drv_tbl_addr, &g_pBROM_BL_Param->m_sd_flash_drv_handle_addr);
#endif /* __NFI_SHARED_DRV__ */

   g_ftlFuncTbl = &ftlFuncTblBl;

#else

   g_ftlFuncTbl = &ftlFuncTbl;

#endif

   g_ftlFuncTbl->FTL_Init(&BLHeader);

   return BL_ERROR_NONE;
}

#endif /* __NAND_BOOT__ */

#ifdef __EMMC_BOOT__
/**********************************************************
Description : Exported API for loading ExtBootloader
Input       : None
Output      : None
***********************************************************/
BL_STATUS InitEMMC(void)
{
   g_ftlFuncTbl = &ftlFuncTbl;
    
   g_ftlFuncTbl->FTL_Init(NULL);
   
   return BL_ERROR_NONE;
}
#endif /* __EMMC_BOOT__ */

#ifdef __SF_BOOT__
/**********************************************************
Description : Exported API for loading ExtBootloader
Input       : None
Output      : None
***********************************************************/
BL_STATUS InitSF(void)
{
   g_ftlFuncTbl = &ftlFuncTbl;
    
   g_ftlFuncTbl->FTL_Init(NULL);
   
   return BL_ERROR_NONE;
}
#endif /* __SF_BOOT__ */

#ifdef __NOR_BOOT__
/**********************************************************
Description : Exported API for loading ExtBootloader
Input       : None
Output      : None
***********************************************************/
BL_STATUS InitNOR(void)
{
   g_ftlFuncTbl = &ftlFuncTbl;
    
   g_ftlFuncTbl->FTL_Init(NULL);
   
   return BL_ERROR_NONE;
}
#endif /* __NOR_BOOT__ */

/**********************************************************
Description : Exported API for loading ExtBootloader
Input       : None
Output      : None
***********************************************************/
void InitFlashDriver(void)
{
#if defined(__NAND_BOOT__)

   InitNFI();

#elif defined(__EMMC_BOOT__)

   InitEMMC();

#elif defined(__SF_BOOT__)

   InitSF();

#elif defined(__NOR_BOOT__)

   InitNOR();

#endif
}


#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

/**********************************************************
Description : Get the first block next to bootloader region
Input       : None
Output      : None
***********************************************************/
void SetTTBL(U32 *pTtbl, U32 num)
{
   
}

/**********************************************************
Description : Get the first block next to bootloader region
Input       : None
Output      : None
***********************************************************/
kal_bool ReadDataX(kal_uint32 ptr, kal_uint32 pageNo, kal_uint32 length, kal_bool bDAL, kal_uint32 *pNextPage)
{
   kal_uint32  page_size = g_ftlFuncTbl->FTL_GetPageSize();
   kal_uint32  page_per_block;
   FTL_OptParam ftl_opt;

   kal_bool goodBlockChecked = KAL_FALSE;

   ftl_opt.bypass_dal = (bDAL == KAL_TRUE) ? KAL_FALSE : KAL_TRUE;

   page_per_block = BL_SLIM_UDIV(g_ftlFuncTbl->FTL_GetBlockSize(0, &ftl_opt), page_size);

   ASSERT((BL_SLIM_UMOD(length, page_size)) == 0);

   if(length == 0)
   {
      return KAL_TRUE;
   }

   WacthDogRestart();

   while(length)
   {
      if(!goodBlockChecked)
      {
         while( g_ftlFuncTbl->FTL_CheckGoodBlock(BL_SLIM_UDIV(pageNo, page_per_block), &ftl_opt) == FTL_ERROR_BAD_BLOCK )
         {
            /* Skip the bad block */
            BL_PRINT(LOG_INFO, "\n\rBad block at block %d\n\r", BL_SLIM_UDIV(pageNo, page_per_block));
            
            pageNo = (BL_SLIM_UDIV(pageNo, page_per_block)+1)*page_per_block;
         }

         goodBlockChecked = KAL_TRUE;
      }

      if( g_ftlFuncTbl->FTL_ReadPage(BL_SLIM_UDIV(pageNo, page_per_block), BL_SLIM_UMOD(pageNo, page_per_block), (kal_uint32*)ptr, &ftl_opt) != FTL_SUCCESS )
      {
         BL_PRINT(LOG_CRIT, "Read error at block %d, page %d\n\r", BL_SLIM_UDIV(pageNo, page_per_block), BL_SLIM_UMOD(pageNo, page_per_block));
         return KAL_FALSE;
      }

      pageNo++;
      length -= page_size;
      ptr += page_size;

      /* Looking for the next good block */
      if ( (BL_SLIM_UMOD(pageNo, page_per_block))==0 )
      {
         goodBlockChecked = KAL_FALSE;
         BL_PRINT(LOG_INFO, "..");       
      }
   }

   if(pNextPage)
   {
      *pNextPage = pageNo;
   }

   return KAL_TRUE;
}

/**********************************************************
Description : Read the first page and check the GFH structure
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_ReadFileGFH(kal_uint32 flashBeginPage, kal_uint32 flashBoundPage, kal_uint32 *pNextPage, kal_uint32 *pReadLength)
{
   kal_uint32 target_addr;
   GFH_FILE_INFO_v1 *pGFHFileInfo;

   kal_uint32 page_no = flashBeginPage;
   kal_uint32 page_size = g_ftlFuncTbl->FTL_GetPageSize();
   kal_int32 to_read, read_part;

   pGFHFileInfo = (GFH_FILE_INFO_v1*)PAGE_BUFFER_ADDR;

   /* GFH_info should be smaller than one page */
   ASSERT(sizeof(GFH_FILE_INFO_v1) <= page_size);

   /* Read first page (GFH Info) to internal page buffer */
   if( ReadDataX((kal_uint32)pGFHFileInfo, page_no, page_size, KAL_TRUE, &page_no) == KAL_FALSE )
   {
      return INVALID_START_ADDR;
   }

   /* Sanity test of GFH */
   if( GFH_FILE_INFO_IsValid(pGFHFileInfo) != B_OK )
   {
      BL_PRINT(LOG_ERROR, "Invalid GFH File Info\n\r");
      return INVALID_START_ADDR;
   }

   /* Make sure the length of the data is still in the region */
   if( BL_SLIM_UDIV((pGFHFileInfo->m_file_len+page_size-1), page_size) + flashBeginPage > flashBoundPage )
   {
      BL_PRINT(LOG_ERROR, "file_len>bound_addr\n\r");
      return INVALID_START_ADDR;
   }

   /* Make sure the load address is in bank 0 */
   if( pGFHFileInfo->m_load_addr >= EMI_BANK_END || pGFHFileInfo->m_load_addr+pGFHFileInfo->m_file_len > EMI_BANK_END )
   {
      BL_PRINT(LOG_ERROR, "Invalad load addr %x\n\r", pGFHFileInfo->m_load_addr);
      return INVALID_START_ADDR;
   }

   target_addr = pGFHFileInfo->m_load_addr;
   
   /* Move the first page to its load address */
   memmove((kal_uint32*)(target_addr), (kal_uint32*)pGFHFileInfo, page_size);

   /* Read other GFHs */
   to_read = (kal_uint32)(BL_SLIM_UDIV(((pGFHFileInfo->m_content_offset - page_size)+(page_size-1)), page_size))*page_size;
   
   read_part = to_read + page_size;
   
   if(to_read > 0)
   {
      if(ReadDataX(target_addr+page_size, page_no, to_read, KAL_TRUE, &page_no) == KAL_FALSE)
      {
         return INVALID_START_ADDR;
      }
   }

   if(pReadLength)
   {
      *pReadLength = read_part;
   }

   if(pNextPage)
   {
      *pNextPage = page_no;
   }
   
   return target_addr;
}

/**********************************************************
Description : Read the the binary body, with a given skiping length
Input       : pGFHFileInfo:   The binary load address. GFH has to be loaded already
              pageNo:         Starting page number
              readPart:       Read length
Output      : Original buffer address
***********************************************************/
kal_uint32 bl_ReadFileBody(GFH_FILE_INFO_v1 *pGFHFileInfo, kal_uint32 pageNo, kal_uint32 readPart)
{
   kal_uint32 page_size = g_ftlFuncTbl->FTL_GetPageSize();
   
   kal_uint32 to_read = (kal_uint32)(BL_SLIM_UDIV(((pGFHFileInfo->m_file_len - readPart)+(page_size-1)), page_size))*page_size;
   
   if(to_read > 0)
   {
      if(ReadDataX(((kal_uint32)pGFHFileInfo)+readPart, pageNo, to_read, KAL_TRUE, NULL) == KAL_FALSE)
      {
         return INVALID_START_ADDR;
      }
   }

   return (kal_uint32)pGFHFileInfo;
}


#elif defined(__XIP_SHADOWING__)

/**********************************************************
Description : Read the first page and check the GFH structure
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_ReadFileGFH(kal_uint32 flashBeginAddr, kal_uint32 flashBoundAddr, kal_uint32 *pNextAddr, kal_uint32 *pReadLength)
{
   kal_uint32 target_addr;
  
   GFH_FILE_INFO_v1 *pGFHFileInfo;

   pGFHFileInfo = (GFH_FILE_INFO_v1*)flashBeginAddr;

   /* Sanity test of GFH */
   if( GFH_FILE_INFO_IsValid(pGFHFileInfo) != B_OK )
   {
      BL_PRINT(LOG_ERROR, "Invalid GFH File Info\n\r");
      return INVALID_START_ADDR;
   }

   /* Make sure the length of the data is still in the region */
   if( pGFHFileInfo->m_file_len + flashBeginAddr > flashBoundAddr )
   {
      BL_PRINT(LOG_ERROR, "file_len>bound_addr\n\r");
      return INVALID_START_ADDR;
   }

   /* Make sure the load address is in bank 0 */
   if( pGFHFileInfo->m_load_addr >= EMI_BANK_END || pGFHFileInfo->m_load_addr+pGFHFileInfo->m_file_len > EMI_BANK_END )
   {
      BL_PRINT(LOG_ERROR, "Invalad load addr %x\n\r", pGFHFileInfo->m_load_addr);
      return INVALID_START_ADDR;
   }

   // Because m_load_addr in XIP shadowing is flash address, we use a general variable generated by sysgen
   //target_addr = pGFHFileInfo->m_load_addr;
   target_addr = MAUI_LV_ADDR_NOR;
   
   /* Move the first page to its load address */
   memmove((kal_uint32*)(target_addr), (kal_uint32*)pGFHFileInfo, pGFHFileInfo->m_content_offset);

   if(pReadLength)
   {
      *pReadLength = pGFHFileInfo->m_content_offset;
   }

   if(pNextAddr)
   {
      *pNextAddr = flashBeginAddr + pGFHFileInfo->m_content_offset;
   }

   return target_addr;
}

/**********************************************************
Description : Read the the binary body, with a given skiping length
Input       : pGFHFileInfo:   The binary load address. GFH has to be loaded already
              flashAddr:      Starting address
              readPart:       Read length
Output      : Original buffer address
***********************************************************/

kal_uint32 bl_ReadFileBody(GFH_FILE_INFO_v1 *pGFHFileInfo, kal_uint32 flashAddr, kal_uint32 readPart)
{
   memcpy((kal_uint8*)pGFHFileInfo+readPart, (kal_uint8*)flashAddr, pGFHFileInfo->m_file_len-readPart);
   
   return (kal_uint32)pGFHFileInfo;
}

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
kal_uint32 MapToCurrentFlashAddr(kal_uint32 addr)
{

#if defined(__RAM_FLASH_REMAP_DONE_IN_EMI_INIT__)
   //In new EMI, remap is always done by EMI init such that flash is on bank 1
   addr |= REMAPPING_ADDR;
#else
   addr &= REMAPPING_MASK;
#endif
   return addr;
}
#endif

#ifdef __MINI_BOOTLOADER__

#if defined(__EXT_BL_UPDATE__) && (defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__))

kal_bool bl_LoadAndCompareExtBootloaderEndMark(U32 begin_addr, U32 bound_addr)
{
   GFH_FILE_INFO_v1 *pGFHFileInfo;
   
   kal_uint32 page_size = g_ftlFuncTbl->FTL_GetPageSize();
   kal_uint32 page_per_block = BL_SLIM_UDIV(g_ftlFuncTbl->FTL_GetBlockSize(0, NULL), g_ftlFuncTbl->FTL_GetPageSize());
   kal_int32 markerPage = bound_addr-1;

   ASSERT(BL_SLIM_UMOD(bound_addr, page_per_block) == 0);
   
   pGFHFileInfo = (GFH_FILE_INFO_v1*)PAGE_BUFFER_ADDR;

   for(;markerPage>=begin_addr; markerPage-=page_per_block)
   {
      if(g_ftlFuncTbl->FTL_CheckGoodBlock(BL_SLIM_UDIV(markerPage, page_per_block), NULL) == FTL_ERROR_BAD_BLOCK)
      {
         BL_PRINT(LOG_INFO, "Bad block at block %d\n\r", BL_SLIM_UDIV(markerPage, page_per_block));
         continue;
      }

      if(g_ftlFuncTbl->FTL_ReadPage(BL_SLIM_UDIV(markerPage, page_per_block), BL_SLIM_UMOD(markerPage, page_per_block), (kal_uint32*)PAGE_BUFFER_ADDR, NULL) == FTL_SUCCESS )
      {
         if(CompareEndMarkWithError((kal_uint32*)(PAGE_BUFFER_ADDR+page_size-sizeof(EXT_BL_END_MARK)), EXT_BL_END_MARK, BIT_ERROR_THRESHOLD) == KAL_TRUE)
         {
            return KAL_TRUE;
         }
      }

      break;
   }

   return KAL_FALSE;
}

#endif /* __EXT_BL_UPDATE__ &&  (_NAND_FLASH_BOOTING_ || __EMMC_BOOTING__) */

#if defined(__NAND_BOOT__) || defined(__EMMC_BOOT__)
/**********************************************************
Description : Read Ext Bootloader from bootloader
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_ReadExtBootloaderFromFlash(kal_uint32 flashBegin, kal_uint32 flashBound)
{
   kal_uint32 page, readLen;
   kal_uint32 targetAddr;
   GFH_FILE_INFO_v1* pExtBlGFH;
   
   targetAddr = bl_ReadFileGFH(flashBegin, flashBound, &page, &readLen);
   pExtBlGFH = (GFH_FILE_INFO_v1*)targetAddr;

   if(targetAddr == INVALID_START_ADDR)
   {
      BL_PRINT(LOG_CRIT, "No ExtBL GFH found\n\r");
      return INVALID_START_ADDR;
   }

   //Do sanity test again on loaded GFH to detect EMI failure
   if( GFH_FILE_INFO_IsValid(pExtBlGFH) != B_OK )
   {
      BL_PRINT(LOG_ERROR, "Re-check ExtBL GFH failed. May be EMI problem!!\r");
      return INVALID_START_ADDR;
   }

   targetAddr = bl_ReadFileBody(pExtBlGFH, page, readLen);
   if(targetAddr == INVALID_START_ADDR)
   {
      BL_PRINT(LOG_CRIT, "Read ExtBL Body failed\n\r");
      return INVALID_START_ADDR;
   }

   return targetAddr;
}
#endif /* __NAND_BOOT__ || __EMMC_BOOT__  */

/**********************************************************
Description : Read Ext Bootloader from bootloader
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_ReadExtBootloaderContent(U32 begin_addr, U32 bound_addr, GFH_FLASH_DEV dev_type)
{
   kal_uint32 target_addr = INVALID_START_ADDR;
#ifdef __EMMC_BOOT__   
   kal_uint32 page_size;
#endif   
   
   TS_BEGIN(TSID_BL_LOAD_EXT_BOOTLOADER_BODY);
   
   switch(dev_type)
   {
#ifdef __NAND_BOOT__
      case F_NAND_TTBL:
      case F_NAND_SEQUENTIAL:         
      case F_NAND_FDM50:
      case F_SPI_NAND_SEQUENTIAL:
      case F_SPI_NAND_TTBL:
      case F_SPI_NAND_FDM50:

         if(dev_type == F_NAND_TTBL || dev_type == F_SPI_NAND_TTBL)
         {
            /* Set and enable TTBL translation */
            SetTTBL((U32*)&g_pBROM_BL_Param->m_hdrblk_info.m_region2_u.m_br_ttbl.m_log2phy_map.m_entry, 
                    g_pBROM_BL_Param->m_hdrblk_info.m_region2_u.m_br_ttbl.m_log2phy_map.m_num);
         }
         else
         {
            SetTTBL(0, 0);
         }

#if defined(__EXT_BL_UPDATE__)
         if(bl_LoadAndCompareExtBootloaderEndMark(begin_addr, bound_addr) == KAL_FALSE)
         {
            BL_PRINT(LOG_INFO, "End mark is not found\r\n");
            return INVALID_START_ADDR;
         }
#endif /* __EXT_BL_UPDATE__ */

         target_addr = bl_ReadExtBootloaderFromFlash(begin_addr, bound_addr);
         
         break;
#endif /* __NAND_BOOT__ */

#ifdef __EMMC_BOOT__
      case F_EMMC_BOOT_REGION:
      case F_EMMC_DATA_REGION:

         page_size = g_ftlFuncTbl->FTL_GetPageSize();
         ASSERT(BL_SLIM_UMOD(begin_addr, page_size) == 0 && BL_SLIM_UMOD(bound_addr, page_size) == 0);

         begin_addr = BL_SLIM_UDIV(begin_addr, page_size);
         bound_addr = BL_SLIM_UDIV(bound_addr, page_size);

#if defined(__EXT_BL_UPDATE__)
         if(bl_LoadAndCompareExtBootloaderEndMark(begin_addr, bound_addr) == KAL_FALSE)
         {
            BL_PRINT(LOG_INFO, "End mark is not found\r\n");
            return INVALID_START_ADDR;
         }
#endif /* __EXT_BL_UPDATE__ */

         target_addr = bl_ReadExtBootloaderFromFlash(begin_addr, bound_addr);

         break;
#endif /* __EMMC_BOOT__ */

#if defined(__NOR_BOOT__) || defined(__SF_BOOT__)
      case F_NOR:
      case F_SF:
         begin_addr = MapToCurrentFlashAddr(begin_addr);

#if defined(__EXT_BL_UPDATE__)
         if(CompareEndMarkWithError((kal_uint32*)(begin_addr+BL_IMG_MAX_SIZE-sizeof(EXT_BL_END_MARK)), EXT_BL_END_MARK, BIT_ERROR_THRESHOLD) == KAL_FALSE)
         {
            BL_PRINT(LOG_INFO, "End mark is not found\r\n");
            return INVALID_START_ADDR;
         }
#endif /* __EXT_BL_UPDATE__ */

         if(GFH_FILE_INFO_IsValid((GFH_FILE_INFO_v1*)begin_addr) == 0)
         {
            target_addr = begin_addr;
         }

         if((((GFH_FILE_INFO_v1*)begin_addr)->m_attr & FILE_INFO_ATTR_XIP) == 0)
         {
            memcpy((void*)((GFH_FILE_INFO_v1*)begin_addr)->m_load_addr, (void*)begin_addr, ((GFH_FILE_INFO_v1*)begin_addr)->m_file_len);
            target_addr = ((GFH_FILE_INFO_v1*)begin_addr)->m_load_addr;
         }
            
         break;
#endif /* __NOR_BOOT__ || __SF_BOOT__ */

      default:
         BL_PRINT(LOG_ERROR, "Unsupported dev type %d", dev_type);
   }

   if(target_addr != INVALID_START_ADDR)
   {
      TS_INFO(TSID_BL_LOAD_EXT_BOOTLOADER_BODY, 0, ((GFH_FILE_INFO_v1*)(target_addr))->m_file_len, 0);
   }

   TS_END(TSID_BL_LOAD_EXT_BOOTLOADER_BODY);
   
   return target_addr;
}

/**********************************************************
Description : Exported API for loading ExtBootloader
Input       : None
Output      : None
***********************************************************/

kal_uint32 LoadExtBootloader()
{
   BR_Layout_v1 *pBootRegionLayout;
   kal_uint32 i;
   kal_uint32 ext_bl_addr = INVALID_START_ADDR;

   TS_BEGIN(TSID_BL_LOAD_EXT_BOOTLOADER);

   TS_BEGIN(TSID_BL_INIT_MINI_FLASH_DRV);
   InitFlashDriver();
   TS_END(TSID_BL_INIT_MINI_FLASH_DRV);

   /* Sanity test on Boot region layout */
   pBootRegionLayout = &g_pBROM_BL_Param->m_hdrblk_info.m_region1_u.m_br_layout;

   if(strcmp(pBootRegionLayout->m_identifier, BRLYT_ID))
   {
      BL_PRINT(LOG_ERROR, "\nLayout ID error\n\r");
      return INVALID_START_ADDR;
   }

   /* Scan all possible bootloaders */
   for(i=0; i<MAX_BL_NUM; i++)
   {
      if(pBootRegionLayout->m_bl_desc[i].m_bl_type != ARM_EXT_BL
#if defined(__EXT_BL_UPDATE__)
      && pBootRegionLayout->m_bl_desc[i].m_bl_type != ARM_EXT_BL_BACKUP         
#endif         
         )
      {
         continue;
      }

      //Basic checks
      
      if(pBootRegionLayout->m_bl_desc[i].m_bl_exist_magic != BL_EXIST_MAGIC)
      {
         BL_PRINT(LOG_ERROR, "No EXIST_MAGIC for ExtBootloader\n\r");
         return INVALID_START_ADDR;
      }

      if(pBootRegionLayout->m_bl_desc[i].m_bl_attribute & BL_ATTR_LOAD_BY_BOOTROM)
      {
         BL_PRINT(LOG_WARN, "Bootrom has loaded ExtBootloader!?\n\r");
         return INVALID_START_ADDR;
      }

      //Load the bootloader
      
      ext_bl_addr = bl_ReadExtBootloaderContent(pBootRegionLayout->m_bl_desc[i].m_bl_begin_dev_addr, pBootRegionLayout->m_bl_desc[i].m_bl_boundary_dev_addr, pBootRegionLayout->m_bl_desc[i].m_bl_dev);


#if !defined(__BRINGUP_SUPPORT__)

#if !defined(__16_3_SEG__) && !defined(__32_32_SEG__) || defined(__MTK_SECURE_PLATFORM__)

      //Check the bootloader hash
      
      if(ext_bl_addr != INVALID_START_ADDR)
      {
         if(SST_CheckBootloaderHash((kal_uint32*)ext_bl_addr) != 0)
         {
            BL_PRINT(LOG_INFO, "Bad ExtBL hash\r\n");
            ext_bl_addr = INVALID_START_ADDR;
         }
      }

#endif
      
#endif /* !__BRINGUP_SUPPORT__ */

      if(ext_bl_addr == INVALID_START_ADDR)
      {
#if defined(__EXT_BL_UPDATE__)
         if(pBootRegionLayout->m_bl_desc[i].m_bl_type == ARM_EXT_BL)
         {
            BL_PRINT(LOG_INFO, "Failed to load ExtBootloader, try Backup\r\n");
            continue;
         }
#endif
         BL_PRINT(LOG_CRIT, "Error when loading ExtBootloader\n\r");
         return INVALID_START_ADDR;
      }

      if(ext_bl_addr != ((GFH_FILE_INFO_v1*)(ext_bl_addr))->m_load_addr)
      {
         BL_PRINT(LOG_ERROR, "Mismatched load address\n\r");
         return INVALID_START_ADDR;
      }

#if defined(__EXT_BL_UPDATE__)
      g_extBlUpdateInfo.m_current_bl          = (pBootRegionLayout->m_bl_desc[i].m_bl_type == ARM_EXT_BL) ? E_EXTBL_PRIMARY_REGION : E_EXTBL_BACKUP_REGION;
      g_extBlUpdateInfo.m_current_bl_size     = ((GFH_FILE_INFO_v1*)(ext_bl_addr))->m_file_len;
#endif

      break;
   }

   if(i == MAX_BL_NUM)
   {
      BL_PRINT(LOG_ERROR, "No ExtBootloader exists in BR\n\r");
      return INVALID_START_ADDR;
   }

   TS_END(TSID_BL_LOAD_EXT_BOOTLOADER);

   return ext_bl_addr;
}

#endif /* __MINI_BOOTLOADER__ */

#ifdef __EXT_BOOTLOADER__


#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

/**********************************************************
Description : load image list information.
Input       : start_blk: start block of searching
Output      : Return if Image List or backup is loaded
Assumptions : FUE image is programmed to flash in block aligned manner
***********************************************************/
kal_bool LoadImageListblock(kal_uint32 start_blk)
{
   extern FTL_FuncTbl *g_ftlFuncTbl;
   
   kal_int32 status;
   kal_bool ret = KAL_TRUE;
   
   TS_BEGIN(TSID_BL_LOAD_ILB_CBR);

   CBR_SetEnv(E_CBR_IDX_CBR, (kal_uint32*)PAGE_BUFFER_ADDR, 8192, g_ftlFuncTbl);
   
   TS_BEGIN(TSID_BL_INIT_CBR);
   status = CBR_Init(E_CBR_IDX_CBR, start_blk);
   TS_END(TSID_BL_INIT_CBR);

   if(status != CBR_SUCCESS)
   {
      if(status == CBR_NO_BLOCK_FOUND)
      {
         BL_PRINT(LOG_INFO, "No CBR is found\n\r");
         goto _error;
      }

      BL_PRINT(LOG_ERROR, "Serious error in CBR, %d\n\r", status);
      ret = KAL_FALSE;
      goto _error;
      
   }

   TS_BEGIN(TSID_BL_READ_FLASH_LAYOUT_INFO);
   status = CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_LAYOUT, (kal_uint8*)&BL_Shared_info.m_bl_flash_layout, sizeof(FlashLayout), NULL);
  
   if(status < CBR_SUCCESS)
   {
      BL_PRINT(LOG_ERROR, "Unable to read FlashLayout, %d\n\r", status);
      goto _error;
   }
  
   status = CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_SPACE_INFO, (kal_uint8*)&BL_Shared_info.m_bl_image_space, sizeof(Nand_ImageSpace_ST), NULL);
  
   if(status < CBR_SUCCESS)
   {
      BL_PRINT(LOG_ERROR, "Unable to read SpaceInfo, %d\n\r", status);
      goto _error;
   }

   status = CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_MAUI_INFO, (kal_uint8*)&g_mauiInfoBuf, sizeof(g_mauiInfoBuf), NULL);

#if 0  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   if(status >= CBR_SUCCESS)
   {
      g_mauiInfoRead = KAL_TRUE;
   }
#endif
   
   TS_END(TSID_BL_READ_FLASH_LAYOUT_INFO);       

   TS_END(TSID_BL_LOAD_ILB_CBR);
   return ret;

_error:
   g_bootupDisabled = KAL_TRUE;   
   g_bootupStatus = BL_BOOTUP_FAIL_REASON_UNABLE_TO_READ_ILB;
   return ret;
}

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */





/**********************************************************
Description : Load rest part of Primary 
Input       : None
Output      : None
***********************************************************/
kal_uint32 LoadMauiBody(void)
{
   kal_uint32 addr;

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__XIP_SHADOWING__)

   TS_BEGIN(TSID_BL_LOAD_MAUI_BODY);
   TS_INFO(TSID_BL_LOAD_MAUI_BODY, ((GFH_FILE_INFO_v1*)g_maui_load_addr)->m_file_len, ((GFH_FILE_INFO_v1*)g_maui_load_addr)->m_file_len-mauiReadLen, g_maui_load_addr);
   addr = bl_ReadFileBody((GFH_FILE_INFO_v1*)g_maui_load_addr, restMauiFlashAddr, mauiReadLen);
   TS_END(TSID_BL_LOAD_MAUI_BODY);

   if(addr == INVALID_START_ADDR)
   {
      BL_PRINT(LOG_ERROR, "Loading MAUI body failed\n\r");
      g_bootupDisabled = KAL_TRUE;
      g_bootupStatus = BL_BOOTUP_FAIL_LOADING_MAUI_BODY_ERROR;
      return addr;
   }

#else

   addr = g_maui_load_addr;

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ || __XIP_SHADOWING__ */


#ifdef __MTK_SECURE_PLATFORM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_SECURE_PLATFORM__ */

   return addr;
}


/**********************************************************
Description : Read MAUI's first GFH to its load address
Input       : None
Output      : None
***********************************************************/
BL_STATUS LoadMAUIFirstPart(void)
{

#ifndef __FOTA_DM__

   kal_uint32 mauiFlashAddr = INVALID_START_ADDR;

   const kal_uint32 loadSequence[][2] = { 
      {PRIMARY_MAUI, PRIMARY_FACTORY_BIN},  //For Normal mode, try to lunch MAUI first
      {PRIMARY_FACTORY_BIN, PRIMARY_MAUI},  //For META mode, try to lunch FactoryBin first
   };
   
   kal_int32 currentLoadSequence = 0;
   kal_int32 i;

   TS_BEGIN(TSID_BL_LOAD_MAUI_FIRST_PART);

   //Find the proper binary to load -- MAUI or FACTORY bin
   if(IsMetaModeEnabled())
   {
      currentLoadSequence = 1;
   }
   
   for(i=0; i<sizeof(loadSequence[0])/sizeof(loadSequence[0][0]); i++)
   {
      mauiFlashAddr = GetBinaryStartInFlash((GFH_FILE_TYPE)loadSequence[currentLoadSequence][i]);
      
      if(mauiFlashAddr != INVALID_START_ADDR)
      {
         if(loadSequence[currentLoadSequence][i] == PRIMARY_FACTORY_BIN)
         {
            BL_PRINT(LOG_INFO, "Launching FactoryBin in Combine mode...\r\n");
         }
         
         break;
      }  
   }

   if(mauiFlashAddr != INVALID_START_ADDR)
   {
#if defined(__NAND_BOOT__) || defined(__EMMC_BOOT__) || defined(__XIP_SHADOWING__)

      g_maui_load_addr = bl_ReadFileGFH(mauiFlashAddr, MAX_FLASH_BOUNDARY, &restMauiFlashAddr, &mauiReadLen);

#elif defined(__NOR_BOOT__) || defined(__SF_BOOT__)

      if(GFH_FILE_INFO_IsValid((GFH_FILE_INFO_v1*)mauiFlashAddr) == 0)
      {
         g_maui_load_addr = mauiFlashAddr;
      }
      else
      {
         BL_PRINT(LOG_ERROR, "Invalid MAUI GFH, addr=%x\n\r", mauiFlashAddr);
      }

#endif

      if(g_maui_load_addr == INVALID_START_ADDR)
      {
         BL_PRINT(LOG_ERROR, "Failed to get MAUI's first part\n\r");
         return BL_ERROR;
      }
   }
   else
   {
      BL_PRINT(LOG_ERROR, "No MAUI binary in FlashLayout or Flash\n\r");

      g_bootupDisabled = KAL_TRUE;
      g_bootupStatus = BL_BOOTUP_FAIL_LOADING_MAUI_HEAD_ERROR;
   }

   TS_END(TSID_BL_LOAD_MAUI_FIRST_PART);

#endif /* __FOTA_DM__ */

   return BL_ERROR_NONE;
}


/**********************************************************
Description : Get the first block next to bootloader region
Input       : None
Output      : Return 
***********************************************************/
kal_uint32 GetMainRegionStartBlock(void)
{
#if defined(__NAND_BOOT__)
   kal_uint32 page_per_block = BL_SLIM_UDIV(g_ftlFuncTbl->FTL_GetBlockSize(0, NULL), g_ftlFuncTbl->FTL_GetPageSize());
   return BL_SLIM_UDIV((g_pBROM_BL_Param->m_hdrblk_info.m_region1_u.m_br_layout.m_main_region_dev_addr + page_per_block - 1), page_per_block);
#elif defined(__NOR_BOOT__) || defined(__SF_BOOT__) || defined(__EMMC_BOOTING__)
   kal_uint32 block_size = g_ftlFuncTbl->FTL_GetBlockSize(0, NULL);
   return BL_SLIM_UDIV((g_pBROM_BL_Param->m_hdrblk_info.m_region1_u.m_br_layout.m_main_region_dev_addr + block_size - 1), block_size);
#endif
}

/**********************************************************
Description : Search the flash layout structure to find the binary region
Input       : Binary type
Output      : The region the binary may occupy
              NAND, eMMC => page index
              NOR, Serial flash => Address
***********************************************************/
kal_bool GetBinaryRegionInFlash(GFH_FILE_TYPE type, kal_uint32 *pStart, kal_uint32 *pBoundary )
{
   kal_bool found = KAL_FALSE;
   
#if defined(__NAND_BOOT__) || defined(__EMMC_BOOT__)
   kal_uint32 i;
   FlashLayout *pFlashLayout = &(BL_Shared_info.m_bl_flash_layout);
   
   for( i=0 ;i<pFlashLayout->regionCount; i++ )
   {
      if( pFlashLayout->region[i].binaryType == type )
      {
         if(pStart)
         {
            *pStart = pFlashLayout->region[i].u.nandEmmc.startPage;
         }
         if(pBoundary)
         {
            *pBoundary = pFlashLayout->region[i].u.nandEmmc.boundPage;
         }
         found = KAL_TRUE;
         break;
      }
   }
#elif defined(__NOR_BOOT__) || defined(__SF_BOOT__)

   kal_uint32 targetAddr = INVALID_START_ADDR;

   if(type == PRIMARY_MAUI)
   {
      targetAddr = MAUI_START_ADDR_NOR;
   }
   else if(type == PRIMARY_FACTORY_BIN)
   {
      targetAddr = FACTORY_BIN_START_ADDR_NOR;
   }

   if(targetAddr != INVALID_START_ADDR)
   {
      GFH_FILE_INFO_v1 *pGFHFileInfo = (GFH_FILE_INFO_v1*)MapToCurrentFlashAddr(targetAddr);

      if( GFH_FILE_INFO_IsValid(pGFHFileInfo) == B_OK )
      {
         kal_uint32 boundaryAddr;
         
         if(pGFHFileInfo->m_max_size != GFH_FILE_MAX_SIZE_IGNORED)
         {
            boundaryAddr = (kal_uint32)(pGFHFileInfo) + pGFHFileInfo->m_max_size - 1;
         }
         else
         {
            boundaryAddr = (kal_uint32)(pGFHFileInfo) + pGFHFileInfo->m_file_len - 1;
         }
            
         if( pGFHFileInfo->m_file_type == type )
         {
            if(pStart)
            {
               *pStart = (kal_uint32)pGFHFileInfo;
            }
            if(pBoundary)
            {
               *pBoundary = boundaryAddr;
            }
            found = KAL_TRUE;
         }
      }
   }
   
#endif

   return found;
}


/**********************************************************
Description : Get the starting address of specified binary type
Input       : None
Output      : Starting address
              NAND, eMMC => page index
              NOR, Serial flash => Address
***********************************************************/
kal_uint32 GetBinaryStartInFlash(GFH_FILE_TYPE type)
{
   kal_uint32 found = KAL_FALSE;
   kal_uint32 start;
   
   found = GetBinaryRegionInFlash(type, &start, NULL);

   return found ? start : INVALID_START_ADDR;

}

/**********************************************************
Description : Get the binary length from the GFH
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_GetBinaryLoadAddrAndLength(kal_uint32 flashBeginPage, kal_uint32 *pLength)
{
   kal_uint32 target_addr;
   GFH_FILE_INFO_v1 *pGFHFileInfo = NULL;

   kal_uint32 page_no = flashBeginPage;
   kal_uint32 page_size = g_ftlFuncTbl->FTL_GetPageSize();

   /* GFH_info should be smaller than one page */
   ASSERT(sizeof(GFH_FILE_INFO_v1) <= page_size);

#if defined(__NAND_BOOT__) || defined(__EMMC_BOOT__)

   pGFHFileInfo = (GFH_FILE_INFO_v1*)PAGE_BUFFER_ADDR;

   /* Read first page (GFH Info) to internal page buffer */
   if( ReadDataX((kal_uint32)pGFHFileInfo, page_no, page_size, KAL_TRUE, &page_no) == KAL_FALSE )
   {
      return INVALID_START_ADDR;
   }
#elif defined(__NOR_BOOT__) || defined(__SF_BOOT__)

    ASSERT(0);
    
#endif

   /* Sanity test of GFH */
   if( GFH_FILE_INFO_IsValid(pGFHFileInfo) != B_OK )
   {
      BL_PRINT(LOG_ERROR, "Invalid GFH File Info\n\r");
      return INVALID_START_ADDR;
   }

   target_addr = pGFHFileInfo->m_load_addr;

   if(pLength)
   {
      *pLength = pGFHFileInfo->m_file_len;
   }
   
   return target_addr;
}

GFH_MAUI_INFO_v1 *bl_GetMAUIInfo(void)
{
   GFH_MAUI_INFO_v1 *pMauiInfo = NULL;
   kal_uint32 status;

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
   if(g_mauiInfoRead)
   {
      pMauiInfo = (GFH_MAUI_INFO_v1*)&g_mauiInfoBuf;
   }
#endif   

#ifndef __FOTA_DM__
   if(!pMauiInfo)
   {
      if(g_maui_load_addr != INVALID_START_ADDR)
      {
         status = GFH_Find(g_maui_load_addr, GFH_MAUI_INFO, (void **)&pMauiInfo);
      }
   }

   if(!pMauiInfo)
   {
      BL_PRINT(LOG_INFO, "No MAUI INFO found in MAUI bin\n\r");
   }
#endif   

   return pMauiInfo;
}

#endif /* __EXT_BOOTLOADER__ */

#endif /* __SV5_ENABLED__ */

