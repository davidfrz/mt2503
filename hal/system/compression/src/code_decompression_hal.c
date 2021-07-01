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
 *   code_decompression_hal.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file perform the ZIMAGE and BOOT_ZIMAGE decompression processes.
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
 *============================================================================
 ****************************************************************************/

#if defined(__ZIMAGE_SUPPORT__)

/*****************************************************************************
 * Includes
 *****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "simple_memory_manager.h"
#include "cache_sw_int.h"
#include "code_decompression.h"
#include "custom_jump_tbl.h"
#include "viva.h"
#include "LzmaDec.h"

#if defined(__UPDATE_BINARY_FILE__) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)  // compile option
#include "custom_scatstruct.h"	//header file
EXTSRAM_REGION_INFO_T mmi_zi_region;  // variable define
//custom_query_dynamic_DC_ZI_MMIPOOL_region(&mmi_zi_region);  //function call
/* mmi_zi_region .addr �Y�Obegin address
mmi_zi_region .len  �Y�Oregion ��length*/
#endif

#define CPU_CACHE_LINE_SIZE_MASK 0x0000001F
#if defined(__EMPTY_MMI__)
#if (defined(__MAUI_BASIC__))
#pragma arm section rwdata = "CACHED_EXTSRAM_RW", zidata = "CACHED_EXTSRAM_ZI"
kal_uint8 g_zimage_working_buffer[(35*1024)];
#pragma arm section rwdata, zidata
#endif
#else
#define USE_MMI_MEMORY_AS_ZIMAGE_WORKING_MEMORY
#endif
#if defined(__MTK_TARGET__)
__weak extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$Base;
__weak extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$Length;
#endif
extern void *kal_tmp_mem_alloc(kal_uint32 size);
extern void kal_tmp_mem_free(void* mem_ptr);

extern SRes Private_LzmaFastDecode(Byte *dest, SizeT *destLen, const Byte *src, SizeT *srcLen,
                            const Byte *propData, unsigned propSize, ELzmaFinishMode finishMode,
                            ELzmaStatus *status, ISzAlloc *alloc, kal_uint32 *handle);
extern SRes Private_LzmaCheckDecode(ELzmaStatus *status, kal_uint32 handle);

/*****************************************************************************
 * Macros
 *****************************************************************************/
//#define ZIMAGE_MEASURE_ENABLE

#if defined (ZIMAGE_MEASURE_ENABLE)
extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time);

#define ZIMAGE_PARTITION_NUMBER  10

kal_uint32 __zimage_duration[ZIMAGE_PARTITION_NUMBER];
kal_uint32 __zimage_duration_index = 0;

#define ZIMAGE_MEASURE_START     do { __zimage_duration[__zimage_duration_index] = drv_get_current_time(); } while (0)
#define ZIMAGE_MEASURE_END       do { __zimage_duration[__zimage_duration_index++] = drv_get_duration_tick(__zimage_duration[i], drv_get_current_time()); } while (0)

#else

#define ZIMAGE_MEASURE_START
#define ZIMAGE_MEASURE_END

#endif

/*****************************************************************************
 * Data Structtures
 *****************************************************************************/
/* Use comment instead of enum intentionally
 * Type:
 * 0: SW LZMA
 * 1: SW LZMA with progress
 * 2: HW LZMA
*  3: SW LZMA with PCE-1
 */
typedef struct
{
   kal_uint32 type;
   kal_uint32 sourceAddress;
   kal_uint32 sourceSize;
   kal_uint32 destinationAddress;
   kal_uint32 destinationSize;
} ZIMAGEPartition;

typedef struct
{
   kal_uint32 partitionNumber;
   ZIMAGEPartition firstPartition;
} ZIMAGEHeader;

/*****************************************************************************
 * Prototypes
 *****************************************************************************/

/*****************************************************************************
 * Global Variables
 *****************************************************************************/
static STSMM _resource_decompress_smm;

/*****************************************************************************
 * Private Functions
 *****************************************************************************/
static void *zimage_malloc(void *p, unsigned int size)
{
   return smmMallocAligned(&_resource_decompress_smm, size, 4);
}

static void zimage_free(void *p, void *address)
{
   return;
}

/*****************************************************************************
 * Internal API Functions
 *****************************************************************************/
void ZImageDecompressByPartitionWithBuffer
         (kal_uint32 source, kal_uint32 destination,
          kal_uint32 notifyLength, kal_uint32 notifyTotalLength, kal_uint32 *notifyCurrentLength, ZImageNotifyFunction notifyFunction,
          kal_uint8 *workingBuffer, kal_uint32 workingBufferSize)
{
#if defined(__MTK_TARGET__)

   const ZIMAGEHeader *header = (const ZIMAGEHeader *)source;
   const ZIMAGEPartition *partitions = &header->firstPartition;
   kal_uint32 i;
   kal_uint32 handle;
   kal_uint32 fastDecode = 0;
   SRes ret;
   ELzmaStatus status;

   ISzAlloc alloc = { zimage_malloc, zimage_free };
   smmInit(&_resource_decompress_smm, workingBuffer, workingBufferSize);

   /* Foreach partition, perform the corresponding action */
   for (i = 0; i < header->partitionNumber; ++i)
   {
      /* Adjust the address from relative to absolute */
      kal_uint8 *sourceAddress = (kal_uint8 *)(source + partitions[i].sourceAddress);
      kal_uint8 *destinationAddress = (kal_uint8 *)(destination + partitions[i].destinationAddress);
      kal_uint32 sourceSize = partitions[i].sourceSize - (LZMA_PROPS_SIZE + 8);
      kal_uint32 destinationSize = partitions[i].destinationSize;

      if (0 == partitions[i].type)
      {
         ZIMAGE_MEASURE_START;

         ret = LzmaDecodeWithOption(destinationAddress, &destinationSize,
                                    sourceAddress + LZMA_PROPS_SIZE + 8, &sourceSize,
                                    sourceAddress, LZMA_PROPS_SIZE, LZMA_FINISH_ANY, &status, &alloc,
                          LZMA_ADDON_OPTION_T);
         if(SZ_OK != ret)
         {
             ASSERT(0);
         }

         ZIMAGE_MEASURE_END;
      }
      else if (1 == partitions[i].type)
      {
         CLzmaDec state;
         kal_uint32 decompressLength;
         kal_uint32 sourceSizeCurrent;

         ZIMAGE_MEASURE_START;

         LzmaDec_Construct(&state);

         ret = LzmaDec_AllocateProbs(&state, sourceAddress, LZMA_PROPS_SIZE, &alloc);
         if(SZ_OK != ret)
         {
             ASSERT(0);
         }

         sourceAddress += LZMA_PROPS_SIZE + 8;

         state.dic = destinationAddress;
         state.dicBufSize = destinationSize;

         LzmaDec_Init(&state);

         for(decompressLength = 0; decompressLength < destinationSize; )
         {
            notifyFunction(*notifyCurrentLength + decompressLength, notifyTotalLength);

            sourceSizeCurrent = sourceSize;

            decompressLength += notifyLength;
            if(decompressLength > destinationSize)
            {
               decompressLength = destinationSize;
            }

            ret = LzmaDec_DecodeToDicWithOption(&state, decompressLength, sourceAddress,
                                                &sourceSizeCurrent, LZMA_FINISH_ANY, &status,
                                                LZMA_ADDON_OPTION_T);

            sourceAddress += sourceSizeCurrent;
            sourceSize -= sourceSizeCurrent;
         }
         notifyFunction(*notifyCurrentLength + decompressLength, notifyTotalLength);
         *notifyCurrentLength += destinationSize;

         if(SZ_OK != ret)
         {
             ASSERT(0);
         }

         ret = LzmaDec_DecodeFinishWithOption(&state, destinationAddress, &destinationSize,
                                              sourceAddress, &sourceSize, LZMA_FINISH_ANY, &status,
                                              LZMA_ADDON_OPTION_T);

         if (SZ_OK != ret)
         {
            ASSERT(0);
         }

         ZIMAGE_MEASURE_END;
      }
      else if (2 == partitions[i].type)
      {
         ZIMAGE_MEASURE_START;

         ret = Private_LzmaFastDecode
                         (destinationAddress, &destinationSize,
                          sourceAddress + LZMA_PROPS_SIZE + 8, &sourceSize,
                          sourceAddress, LZMA_PROPS_SIZE, LZMA_FINISH_ANY, &status, &alloc, &handle);

         fastDecode = 1;

         if(SZ_OK != ret)
         {
             ASSERT(0);
         }

#if defined(ZIMAGE_MEASURE_ENABLE)
         /* Check decompress */
         if (fastDecode)
         {
            ret = Private_LzmaCheckDecode(&status, handle);

            if (SZ_OK != ret)
            {
               ASSERT(0);
            }
         }

         ZIMAGE_MEASURE_END;
#endif
      }
      else if (3 == partitions[i].type)
      {
         ZIMAGE_MEASURE_START;

         {
#if defined(__ALICE_SUPPORT__)
            extern kal_uint32 Image$$ALICE$$RO$$Base;
            extern kal_uint32 Image$$ALICE$$RO$$Limit;
            kal_uint32 dictBuffer = (kal_uint32)&Image$$ALICE$$RO$$Base;
            kal_uint32 dictSize = ((kal_uint32)&Image$$ALICE$$RO$$Limit) - dictBuffer;
            kal_uint32 dictInfo[2];
            dictSize = (0x400000 < dictSize) ? 0x400000 : dictSize;
            dictInfo[0] = dictBuffer;
            dictInfo[1] = dictSize;
            status = (ELzmaStatus)dictInfo;
            ret = LzmaDecodeWithOption(destinationAddress, &destinationSize,
                                       sourceAddress + LZMA_PROPS_SIZE + 8, &sourceSize,
                                       sourceAddress, LZMA_PROPS_SIZE, LZMA_FINISH_ANY, &status, &alloc,
                                       LZMA_ADDON_OPTION_T_P);
#endif
         }
         if(SZ_OK != ret)
         {
             ASSERT(0);
         }

         ZIMAGE_MEASURE_END;
      }
      else
      {
         /* Unknown type */
         ASSERT(0);
      }
   }

#if !defined(ZIMAGE_MEASURE_ENABLE)
   /* Check decompress */
   if (fastDecode)
   {
      ret = Private_LzmaCheckDecode(&status, handle);

      if (SZ_OK != ret)
      {
         ASSERT(0);
      }
   }
#endif

   MTKL1CACHE_CleanAllCacheLines();

#endif /* __MTK_TARGET__ */
}

void ZImageDecompressByPartition(kal_uint32 source, kal_uint32 destination,
                                 kal_uint32 notifyLength, kal_uint32 notifyTotalLength,
                                 kal_uint32 *notifyCurrentLength, ZImageNotifyFunction notifyFunction)
{
#if defined(__MTK_TARGET__)
#if defined(USE_MMI_MEMORY_AS_ZIMAGE_WORKING_MEMORY)
#define ZIMAGE_DECOMPRESS_BUFFER_SIZE    (40*1024)
#if defined(__UPDATE_BINARY_FILE__) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__) // compile option
	 kal_uint32 workingSize;
	 kal_uint32 mmimemAddr;
	 kal_uint8 *workingBuffer;
   custom_query_dynamic_DC_ZI_MMIPOOL_region(&mmi_zi_region);  //function call
	/* mmi_zi_region .addr �Y�Obegin address
	mmi_zi_region .len  �Y�Oregion ��length*/
   workingSize = ((kal_uint32)(mmi_zi_region.len) - (CPU_CACHE_LINE_SIZE_MASK + 1));
   mmimemAddr = (kal_uint32)((mmi_zi_region.addr + CPU_CACHE_LINE_SIZE_MASK) & ~CPU_CACHE_LINE_SIZE_MASK);
   workingBuffer = (kal_uint8 *)mmimemAddr;
   if (workingSize < ZIMAGE_DECOMPRESS_BUFFER_SIZE)
   {
      ASSERT(0);
   }
#else
   kal_uint32 workingSize = ((kal_uint32)(&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$Length) - (CPU_CACHE_LINE_SIZE_MASK + 1));
   kal_uint32 mmimemAddr = (((kal_uint32)(&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$Base) + CPU_CACHE_LINE_SIZE_MASK) & ~CPU_CACHE_LINE_SIZE_MASK);
   kal_uint8 *workingBuffer = (kal_uint8 *)mmimemAddr;
   if (workingSize < ZIMAGE_DECOMPRESS_BUFFER_SIZE)
   {
      ASSERT(0);
   }
#endif
#else
#define ZIMAGE_DECOMPRESS_BUFFER_SIZE    (35*1024)
#if (defined(__MAUI_BASIC__))
	 kal_uint8 *workingBuffer = &g_zimage_working_buffer[0];
#else
   kal_uint8 *workingBuffer = (kal_uint8 *)kal_tmp_mem_alloc(ZIMAGE_DECOMPRESS_BUFFER_SIZE);
#endif
#endif

   ZImageDecompressByPartitionWithBuffer(source, destination,
                                         notifyLength, notifyTotalLength, notifyCurrentLength, notifyFunction,
                                         workingBuffer, ZIMAGE_DECOMPRESS_BUFFER_SIZE);

#if defined(USE_MMI_MEMORY_AS_ZIMAGE_WORKING_MEMORY)
   kal_mem_set((void*) mmimemAddr, 0x0, ZIMAGE_DECOMPRESS_BUFFER_SIZE);
#else
#if (defined(__MAUI_BASIC__))
#else
   kal_tmp_mem_free(workingBuffer);
#endif //#if (defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__))
#endif
#endif
}

kal_uint32 ZImageGetNotifyLength(kal_uint32 source)
{
   const ZIMAGEHeader *header = (const ZIMAGEHeader *)source;
   const ZIMAGEPartition *partitions = &header->firstPartition;
   kal_uint32 i;
   kal_uint32 result = 0;

   /* Foreach partition, get the notify length */
   for (i = 0; i < header->partitionNumber; ++i)
   {
      if (1 == partitions[i].type)
      {
         result += partitions[i].destinationSize;
      }
   }

   return result;
}

/*****************************************************************************
 * Public API Functions
 *****************************************************************************/
extern unsigned int Image$$ZIMAGE_ER$$Base;
extern unsigned int Image$$ZIMAGE_ER$$Length;
extern unsigned int Image$$BOOT_ZIMAGE_ER$$Base;

#pragma arm section rwdata="ZIMAGE_RWDATA", zidata="ZIMAGE_ZIDATA"
int ZIMAGEDummyFlag = 0xFFFFFFFF;
#pragma arm section rwdata, zidata

kal_int32 ZImageDecompressHal(kal_uint32 notifyLength, ZImageNotifyFunction notifyFunction)
{
   kal_uint32 notifyTotalLength = 0;
   kal_uint32 notifyCurrentLength = 0;
   kal_uint32 count;

   notifyTotalLength += ZImageGetNotifyLength(vivaInfo.zimage_base);
   for(count = 0; count < MAX_COMPRESSED_BIN_SUPPORT; count++){
   	  if(GET_Res_IsExisted(count) && GET_Res_IsCompressed(count)){
         notifyTotalLength += ZImageGetNotifyLength(((kal_uint32)GET_Res_LoadAddr(count) + GET_Res_TBLSize(count)));
      }
   }

   ZImageDecompressByPartition(vivaInfo.zimage_base, (kal_uint32)&Image$$ZIMAGE_ER$$Base,
                               notifyLength, notifyTotalLength, &notifyCurrentLength, notifyFunction);
   /*For MBA with compression Feature*/
   for(count = 0; count < MAX_COMPRESSED_BIN_SUPPORT; count++){
      if(GET_Res_IsExisted(count) && GET_Res_IsCompressed(count)){
         ZImageDecompressByPartition(((kal_uint32)GET_Res_LoadAddr(count) + GET_Res_TBLSize(count)), (kal_uint32)GET_Res_ExecAddr(count),
               notifyLength, notifyTotalLength, &notifyCurrentLength, notifyFunction);
      }
   }

   ZIMAGEDummyFlag = 0;

   return 0;
}

void BootZImageDecompress(void)
{
#if defined(__BOOT_ZIMAGE_SUPPORT__)

#define BOOT_ZIMAGE_DECOMPRESS_BUFFER_SIZE    (35*1024)

   kal_uint8 *workingBuffer = (kal_uint8 *)&Image$$ZIMAGE_ER$$Base;
   kal_uint32 length = 0;

   ASSERT(BOOT_ZIMAGE_DECOMPRESS_BUFFER_SIZE <= (kal_uint32)&Image$$ZIMAGE_ER$$Length);

   ZImageDecompressByPartitionWithBuffer(vivaInfo.boot_zimage_base, (kal_uint32)&Image$$BOOT_ZIMAGE_ER$$Base,
                                         0, 0, &length, 0, workingBuffer, BOOT_ZIMAGE_DECOMPRESS_BUFFER_SIZE);

#endif
}

#else /* __ZIMAGE_SUPPORT__ */

#include "kal_general_types.h"
#include "code_decompression.h"

//kal_int32 ZImageDecompressHal(kal_uint32 notifyLength, ZImageNotifyFunction notifyFunction) { return 0; }
void BootZImageDecompress(void) { /* Do nothing */ }

#endif /* __ZIMAGE_SUPPORT__ */
