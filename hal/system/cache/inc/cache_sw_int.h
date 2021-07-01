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
 *   cache_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of code and data cache.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CACHE_SW_INT_H
#define _CACHE_SW_INT_H

#include "kal_general_types.h"
#include "cache_hw_int.h"
#include "custom_scatstruct.h"

/*************************************************************************
 * Define enums
 *************************************************************************/

/* size enum, non-cache related. */
enum 
{
    SIZE_512B = 512,
    SIZE_1KB = 1 * 1024,
    SIZE_4KB = 4 * 1024,
    SIZE_8KB = 8 * 1024,
    SIZE_16KB = 16 * 1024,
    SIZE_32KB = 32 * 1024,
    SIZE_64KB = 64 * 1024,
    SIZE_128KB = 128 * 1024,
    SIZE_256KB = 256 * 1024,
    SIZE_512KB = 512 * 1024,
    SIZE_1MB = 1 * 1024 * 1024,
    SIZE_2MB = 2 * 1024 * 1024,
    SIZE_4MB = 4 * 1024 * 1024,
    SIZE_8MB = 8 * 1024 * 1024,
    SIZE_16MB = 16 * 1024 * 1024,
    SIZE_32MB = 32 * 1024 * 1024,
    SIZE_64MB = 64 * 1024 * 1024
};

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(TK6516) || defined(MT6516) || defined(MT6268H) )

/* Code Cache and MPU */
typedef enum RegionSize_T
{
   CACHE_SIZE_1KB   = 0,
   CACHE_SIZE_2KB   = 0x02,
   CACHE_SIZE_4KB   = 0x04,
   CACHE_SIZE_8KB   = 0x06,
   CACHE_SIZE_16KB  = 0x08,
   CACHE_SIZE_32KB  = 0x0a,
   CACHE_SIZE_64KB  = 0x0c,
   CACHE_SIZE_128KB = 0x0e,
   CACHE_SIZE_256KB = 0x10,
   CACHE_SIZE_512KB = 0x12,
   CACHE_SIZE_1MB   = 0x14,
   CACHE_SIZE_2MB   = 0x16,
   CACHE_SIZE_4MB   = 0x18
} RegionSize;

/* code cache channel size */
enum 
{
    CACHE_CH_SIZE_1KB = 1 * 1024,
    CACHE_CH_SIZE_1KB_SHIFT = 10,
    CACHE_CH_SIZE_1KB_MASK = 0x000003FF,
    CACHE_CH_SIZE_4KB = 4 * 1024,
    CACHE_CH_SIZE_4KB_SHIFT = 12,
    CACHE_CH_SIZE_4KB_MASK = 0x00000FFF,
    CACHE_CH_SIZE_8KB = 8 * 1024,
    CACHE_CH_SIZE_8KB_SHIFT = 13,
    CACHE_CH_SIZE_8KB_MASK = 0x00001FFF,
    CACHE_CH_SIZE_16KB = 16 * 1024,
    CACHE_CH_SIZE_16KB_SHIFT = 14,
    CACHE_CH_SIZE_16KB_MASK = 0x00003FFF,
    CACHE_CH_SIZE_32KB = 32 * 1024,
    CACHE_CH_SIZE_32KB_SHIFT = 15,
    CACHE_CH_SIZE_32KB_MASK = 0x00007FFF,
    CACHE_CH_SIZE_64KB = 64 * 1024,
    CACHE_CH_SIZE_64KB_SHIFT = 16,
    CACHE_CH_SIZE_64KB_MASK = 0x0000FFFF,
    CACHE_CH_SIZE_128KB = 128 * 1024,
    CACHE_CH_SIZE_128KB_SHIFT = 17,
    CACHE_CH_SIZE_128KB_MASK = 0x0001FFFF,
    CACHE_CH_SIZE_256KB = 256 * 1024,
    CACHE_CH_SIZE_256KB_SHIFT = 18,
    CACHE_CH_SIZE_256KB_MASK = 0x0003FFFF,
    CACHE_CH_SIZE_512KB = 512 * 1024,
    CACHE_CH_SIZE_512KB_SHIFT = 19,
    CACHE_CH_SIZE_512KB_MASK = 0x0007FFFF,
    CACHE_CH_SIZE_1MB = 1 * 1024 * 1024,
    CACHE_CH_SIZE_1MB_SHIFT = 20,
    CACHE_CH_SIZE_1MB_MASK = 0x000FFFFF,
    CACHE_CH_SIZE_2MB = 2 * 1024 * 1024,
    CACHE_CH_SIZE_2MB_SHIFT = 21,
    CACHE_CH_SIZE_2MB_MASK = 0x001FFFFF,
    CACHE_CH_SIZE_4MB = 4 * 1024 * 1024,
    CACHE_CH_SIZE_4MB_SHIFT = 22,
    CACHE_CH_SIZE_4MB_MASK = 0x003FFFFF
};

typedef enum CacheType_T
{
   NO_CACHE   = 0x0000,  /* 128KB TCM, 0KB Cache  */
   CACHE_1WAY = 0x0100,  /* 120KB TCM, 8KB Cache  */
   CACHE_2WAY = 0x0200,  /* 112KB TCM, 16KB Cache */
   CACHE_4WAY = 0x0300   /* 96KB TCM, 32KB Cache  */
} CacheType;


/********************
 * constants
 ********************/

#define MAX_MPU_CHANNEL_LEN      (SIZE_4MB)
#define MAX_CACHE_CHANNEL_LEN    (SIZE_4MB)
#define MIN_MPU_CHANNEL_LEN      (SIZE_1KB)
#define MIN_CACHE_CHANNEL_LEN    (SIZE_1KB)
#define CACHE_SIZE_INDEX         (12)

#if defined(TK6516) || defined(MT6516)
#define CACHE_CHANNEL_NUM        (16)
#else /* TK6516 || MT6516 */
#define CACHE_CHANNEL_NUM        (8)
#endif /* TK6516 || MT6516 */

#define MPU_SIZE_INDEX           (12)

#if defined(TK6516) || defined(MT6516)
#define MPU_CHANNEL_NUM          (16)
#else /* TK6516 || MT6516 */
#define MPU_CHANNEL_NUM          (8)
#endif /* TK6516 || MT6516*/



#elif defined(MT6225) || defined(MT6253T) || defined(MT6253) || defined(MT6251)   /* MT6228 || MT6229 || MT6230 || MT6268T|| MT6268H */

/* Code Cache and MPU */
typedef enum RegionSize_T
{
   CACHE_SIZE_1KB   = 0,
   CACHE_SIZE_2KB   = 0x02,
   CACHE_SIZE_4KB   = 0x04,
   CACHE_SIZE_8KB   = 0x06,
   CACHE_SIZE_16KB  = 0x08,
   CACHE_SIZE_32KB  = 0x0a,
   CACHE_SIZE_64KB  = 0x0c,
   CACHE_SIZE_128KB = 0x0e,
   CACHE_SIZE_256KB = 0x10,
   CACHE_SIZE_512KB = 0x12,
   CACHE_SIZE_1MB   = 0x14,
   CACHE_SIZE_2MB   = 0x16,
   CACHE_SIZE_4MB   = 0x18,
   CACHE_SIZE_8MB   = 0x1a,
   CACHE_SIZE_16MB  = 0x1c
} RegionSize;

/* code cache channel size */
enum 
{
    CACHE_CH_SIZE_1KB = 1 * 1024,
    CACHE_CH_SIZE_1KB_SHIFT = 10,
    CACHE_CH_SIZE_1KB_MASK = 0x000003FF,
    CACHE_CH_SIZE_2KB = 2 * 1024,
    CACHE_CH_SIZE_2KB_SHIFT = 11,
    CACHE_CH_SIZE_2KB_MASK = 0x000007FF,
    CACHE_CH_SIZE_4KB = 4 * 1024,
    CACHE_CH_SIZE_4KB_SHIFT = 12,
    CACHE_CH_SIZE_4KB_MASK = 0x00000FFF,
    CACHE_CH_SIZE_8KB = 8 * 1024,
    CACHE_CH_SIZE_8KB_SHIFT = 13,
    CACHE_CH_SIZE_8KB_MASK = 0x00001FFF,
    CACHE_CH_SIZE_16KB = 16 * 1024,
    CACHE_CH_SIZE_16KB_SHIFT = 14,
    CACHE_CH_SIZE_16KB_MASK = 0x00003FFF,
    CACHE_CH_SIZE_32KB = 32 * 1024,
    CACHE_CH_SIZE_32KB_SHIFT = 15,
    CACHE_CH_SIZE_32KB_MASK = 0x00007FFF,
    CACHE_CH_SIZE_64KB = 64 * 1024,
    CACHE_CH_SIZE_64KB_SHIFT = 16,
    CACHE_CH_SIZE_64KB_MASK = 0x0000FFFF,
    CACHE_CH_SIZE_128KB = 128 * 1024,
    CACHE_CH_SIZE_128KB_SHIFT = 17,
    CACHE_CH_SIZE_128KB_MASK = 0x0001FFFF,
    CACHE_CH_SIZE_256KB = 256 * 1024,
    CACHE_CH_SIZE_256KB_SHIFT = 18,
    CACHE_CH_SIZE_256KB_MASK = 0x0003FFFF,
    CACHE_CH_SIZE_512KB = 512 * 1024,
    CACHE_CH_SIZE_512KB_SHIFT = 19,
    CACHE_CH_SIZE_512KB_MASK = 0x0007FFFF,
    CACHE_CH_SIZE_1MB = 1 * 1024 * 1024,
    CACHE_CH_SIZE_1MB_SHIFT = 20,
    CACHE_CH_SIZE_1MB_MASK = 0x000FFFFF,
    CACHE_CH_SIZE_2MB = 2 * 1024 * 1024,
    CACHE_CH_SIZE_2MB_SHIFT = 21,
    CACHE_CH_SIZE_2MB_MASK = 0x001FFFFF,
    CACHE_CH_SIZE_4MB = 4 * 1024 * 1024,
    CACHE_CH_SIZE_4MB_SHIFT = 22,
    CACHE_CH_SIZE_4MB_MASK = 0x003FFFFF,
    CACHE_CH_SIZE_8MB = 8 * 1024 * 1024,
    CACHE_CH_SIZE_8MB_SHIFT = 23,
    CACHE_CH_SIZE_8MB_MASK = 0x007FFFFF,
    CACHE_CH_SIZE_16MB = 16 * 1024 * 1024,
    CACHE_CH_SIZE_16MB_SHIFT = 24,
    CACHE_CH_SIZE_16MB_MASK = 0x00FFFFFF
};

typedef enum CacheType_T
{
   NO_CACHE   = 0x0000,  /* 0KB Cache  */
   CACHE_1WAY = 0x0100,  /* 8KB Cache  */
   CACHE_2WAY = 0x0200   /* 16KB Cache */
} CacheType;


/********************
 * constants
 ********************/

#define MAX_MPU_CHANNEL_LEN     (SIZE_16MB)
#define MAX_CACHE_CHANNEL_LEN   (SIZE_16MB)
#define MIN_MPU_CHANNEL_LEN     (SIZE_1KB)
#define MIN_CACHE_CHANNEL_LEN   (SIZE_1KB)
#define CACHE_SIZE_INDEX        (14)

#if defined(MT6225)
#define CACHE_CHANNEL_NUM       (8)
#elif defined(MT6253T) || defined(MT6253) || defined(MT6251) /* MT6225 */
#define CACHE_CHANNEL_NUM       (16)
#endif /* MT6225 */

#define MPU_SIZE_INDEX          (14)

#if defined(MT6225)
#define MPU_CHANNEL_NUM         (8)
#elif defined(MT6253T) || defined(MT6253) || defined(MT6251) /* MT6225 */
#define MPU_CHANNEL_NUM         (16)
#endif /* MT6225 */

#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

#if defined(MT6253E_S00) || defined(MT6253L_S00) || defined(MT6252_S00) || defined(MT6252H_S00)

/* Code Cache and MPU */
typedef enum RegionSize_T
{
   CACHE_SIZE_512B  = 0,	
   CACHE_SIZE_1KB   = 0x02,
   CACHE_SIZE_2KB   = 0x04,
   CACHE_SIZE_4KB   = 0x06,
   CACHE_SIZE_8KB   = 0x08,
   CACHE_SIZE_16KB  = 0x0a,
   CACHE_SIZE_32KB  = 0x0c,
   CACHE_SIZE_64KB  = 0x0e,
   CACHE_SIZE_128KB = 0x10,
   CACHE_SIZE_256KB = 0x12,
   CACHE_SIZE_512KB = 0x14,
   CACHE_SIZE_1MB   = 0x16,
   CACHE_SIZE_2MB   = 0x18,
   CACHE_SIZE_4MB   = 0x1a,
   CACHE_SIZE_8MB   = 0x1c,
   CACHE_SIZE_16MB  = 0x1e,
   CACHE_SIZE_32MB  = 0x20,
   CACHE_SIZE_64MB  = 0x22
} RegionSize;

#else 
/* Code Cache and MPU */
typedef enum RegionSize_T
{
   CACHE_SIZE_512B  = 0,	
   CACHE_SIZE_1KB   = 0x01,
   CACHE_SIZE_2KB   = 0x02,
   CACHE_SIZE_4KB   = 0x03,
   CACHE_SIZE_8KB   = 0x04,
   CACHE_SIZE_16KB  = 0x05,
   CACHE_SIZE_32KB  = 0x06,
   CACHE_SIZE_64KB  = 0x07,
   CACHE_SIZE_128KB = 0x08,
   CACHE_SIZE_256KB = 0x09,
   CACHE_SIZE_512KB = 0x0A,
   CACHE_SIZE_1MB   = 0x0B,
   CACHE_SIZE_2MB   = 0x0C,
   CACHE_SIZE_4MB   = 0x0D,
   CACHE_SIZE_8MB   = 0x0E,
   CACHE_SIZE_16MB  = 0x0F,
   CACHE_SIZE_32MB  = 0x10,
   CACHE_SIZE_64MB  = 0x11
} RegionSize;
#endif /* defined(MT6253E_S00) || defined(MT6253L_S00) */

/* code cache channel size */
enum 
{
    CACHE_CH_SIZE_512B = 512,
    CACHE_CH_SIZE_512B_SHIFT = 9,
    CACHE_CH_SIZE_512B_MASK = 0x000001FF,
    CACHE_CH_SIZE_1KB = 1 * 1024,
    CACHE_CH_SIZE_1KB_SHIFT = 10,
    CACHE_CH_SIZE_1KB_MASK = 0x000003FF,
    CACHE_CH_SIZE_2KB = 2 * 1024,
    CACHE_CH_SIZE_2KB_SHIFT = 11,
    CACHE_CH_SIZE_2KB_MASK = 0x000007FF,    
    CACHE_CH_SIZE_4KB = 4 * 1024,
    CACHE_CH_SIZE_4KB_SHIFT = 12,
    CACHE_CH_SIZE_4KB_MASK = 0x00000FFF,
    CACHE_CH_SIZE_8KB = 8 * 1024,
    CACHE_CH_SIZE_8KB_SHIFT = 13,
    CACHE_CH_SIZE_8KB_MASK = 0x00001FFF,
    CACHE_CH_SIZE_16KB = 16 * 1024,
    CACHE_CH_SIZE_16KB_SHIFT = 14,
    CACHE_CH_SIZE_16KB_MASK = 0x00003FFF,
    CACHE_CH_SIZE_32KB = 32 * 1024,
    CACHE_CH_SIZE_32KB_SHIFT = 15,
    CACHE_CH_SIZE_32KB_MASK = 0x00007FFF,
    CACHE_CH_SIZE_64KB = 64 * 1024,
    CACHE_CH_SIZE_64KB_SHIFT = 16,
    CACHE_CH_SIZE_64KB_MASK = 0x0000FFFF,
    CACHE_CH_SIZE_128KB = 128 * 1024,
    CACHE_CH_SIZE_128KB_SHIFT = 17,
    CACHE_CH_SIZE_128KB_MASK = 0x0001FFFF,
    CACHE_CH_SIZE_256KB = 256 * 1024,
    CACHE_CH_SIZE_256KB_SHIFT = 18,
    CACHE_CH_SIZE_256KB_MASK = 0x0003FFFF,
    CACHE_CH_SIZE_512KB = 512 * 1024,
    CACHE_CH_SIZE_512KB_SHIFT = 19,
    CACHE_CH_SIZE_512KB_MASK = 0x0007FFFF,
    CACHE_CH_SIZE_1MB = 1 * 1024 * 1024,
    CACHE_CH_SIZE_1MB_SHIFT = 20,
    CACHE_CH_SIZE_1MB_MASK = 0x000FFFFF,
    CACHE_CH_SIZE_2MB = 2 * 1024 * 1024,
    CACHE_CH_SIZE_2MB_SHIFT = 21,
    CACHE_CH_SIZE_2MB_MASK = 0x001FFFFF,
    CACHE_CH_SIZE_4MB = 4 * 1024 * 1024,
    CACHE_CH_SIZE_4MB_SHIFT = 22,
    CACHE_CH_SIZE_4MB_MASK = 0x003FFFFF,
    CACHE_CH_SIZE_8MB = 8 * 1024 * 1024,
    CACHE_CH_SIZE_8MB_SHIFT = 23,
    CACHE_CH_SIZE_8MB_MASK = 0x007FFFFF,
    CACHE_CH_SIZE_16MB = 16 * 1024 * 1024,
    CACHE_CH_SIZE_16MB_SHIFT = 24,
    CACHE_CH_SIZE_16MB_MASK = 0x00FFFFFF,
    CACHE_CH_SIZE_32MB = 32 * 1024 * 1024,
    CACHE_CH_SIZE_32MB_SHIFT = 25,
    CACHE_CH_SIZE_32MB_MASK = 0x01FFFFFF,
    CACHE_CH_SIZE_64MB = 64 * 1024 * 1024,
    CACHE_CH_SIZE_64MB_SHIFT = 26,
    CACHE_CH_SIZE_64MB_MASK = 0x03FFFFFF
};

typedef enum CacheType_T
{
   NO_CACHE   = 0x0000,  /* 0KB Cache  */
   CACHE_1WAY = 0x0100,  /* 8KB Cache  */
   CACHE_2WAY = 0x0200,   /* 16KB Cache */
   CACHE_4WAY = 0x0300   /* 32KB Cache */   
} CacheType;


/********************
 * constants
 ********************/
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define MAX_MPU_CHANNEL_LEN     (SIZE_64MB)
#define MAX_CACHE_CHANNEL_LEN   (SIZE_64MB)
#define MIN_MPU_CHANNEL_LEN     (SIZE_4KB)
#define MIN_CACHE_CHANNEL_LEN   (SIZE_4KB)

#define CACHE_SIZE_INDEX        (17)
#define CACHE_CHANNEL_NUM       (16)

#define MPU_SIZE_INDEX          (17)
#define MPU_CHANNEL_NUM         (16)
#else /* MT6250 */
#define MAX_MPU_CHANNEL_LEN     (SIZE_64MB)
#define MAX_CACHE_CHANNEL_LEN   (SIZE_64MB)
#define MIN_MPU_CHANNEL_LEN     (SIZE_512B)
#define MIN_CACHE_CHANNEL_LEN   (SIZE_512B)

#define CACHE_SIZE_INDEX        (17)
#define CACHE_CHANNEL_NUM       (32)

#define MPU_SIZE_INDEX          (17)
#define MPU_CHANNEL_NUM         (32)
#endif /* MT6250 */

#if defined(MT6261) || defined(MT2501) || defined(MT2502)
#define REMAP_CHANNEL_NUM       3
#else
#define REMAP_CHANNEL_NUM       2
#endif

#endif  /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */


/*******************************************************************************
 * enums
 *******************************************************************************/

enum 
{
   L1CACHE_CH_ENABLE = 0x00000001,
   L1CACHE_CH_DISABLE = 0x00000000,
#if defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   L1CACHE_CH_CACHEABLE = 0x00000100,
#else
   L1CACHE_CH_CACHEABLE = 0x00000040,
#endif   
   L1CACHE_CH_NONCACHEABLE = 0x00000000
};

#if defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

#if defined(MT6253E_S00) || defined(MT6253L_S00) || defined(MT6252_S00) || defined(MT6252H_S00)

typedef enum MPU_ATTRIBUTE_T
{
   NON_READABLE_NON_WRITEABLE = 0x00,
   NON_READABLE_BUT_WRITEABLE = 0x40,
   READABLE_BUT_NON_WRITEABLE = 0x80,
   READABLE_WRITEABLE = 0xc0
} MPU_ATTRIBUTE;

#else

typedef enum MPU_ATTRIBUTE_T
{
   PRIV_RW_USER_RW = 0x00,
   PRIV_RW         = 0x20,
   PRIV_RW_USER_RO = 0x40,
   PRIV_RW_USER_WO = 0x60,
   PRIV_RO_USER_RO = 0x80,
   NO_ACCESS       = 0xA0
} MPU_ATTRIBUTE;

#endif /* #if defined(MT6253E_S00) || defined(MT6253L_S00) */

#else
typedef enum MPU_ATTRIBUTE_T
{
   NON_READABLE_NON_WRITEABLE = 0x00,
   NON_READABLE_BUT_WRITEABLE = 0x40,
   READABLE_BUT_NON_WRITEABLE = 0x80,
   READABLE_WRITEABLE = 0xc0
} MPU_ATTRIBUTE;
#endif /* defined(MT6253E) || defined(MT6253L) */

/*******************************************************************************
 * structs
 *******************************************************************************/

typedef struct CacheMenu_T
{   
   kal_uint32  c_addr;
   kal_uint32  c_range;   
   kal_uint16  c_channel;   
   kal_uint16  c_enable;   
} CacheMenuType;


typedef struct MPUMenu_T
{   
   kal_uint32     m_addr;
   kal_uint32     m_range;
   kal_uint16     m_channel;   
   MPU_ATTRIBUTE  m_attribute;   
#if defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   kal_uint8      m_cacheable;
#endif
   kal_uint8      m_enable;
} MPUMenuType;


typedef struct CodeCACHEHitRate_T
{   
   kal_uint64  hitCount1;
   kal_uint64  accessCount1;
   kal_uint64  hitCount2;
   kal_uint64  accessCount2;
} CodeCacheHitCount;


/*******************************************************************************
 * constants & macros
 *******************************************************************************/

#define  L1CACHE_CH_ENABLE_OFFSET       0x00000000
#define  L1CACHE_CH_CACHEABLE_OFFSET 0x00000006
#define  L1CACHE_CH_ENABLE_MASK          0x00000001
#if defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define  L1CACHE_CH_CACHEABLE_MASK    0x00000100
#else
#define  L1CACHE_CH_CACHEABLE_MASK    0x00000040
#endif /* MT6253E || MT6253L */
#define  L1CACHE_CH_ADDR_MASK             0xFFFFFC00
#define  L1CACHE_CH_SIZE_MASK              0x0000003E
#define  L1CACHE_GEN_CACHESIZE_MASK   0x0300

#define CPU_CACHE_LINE_SIZE 32
#define CPU_CACHE_LINE_BIT_OFFSET 5
#define CPU_CACHE_LINE_SIZE_MASK 0x0000001F
#define CPU_CACHE_SIZE 32 * 1024
#define CPU_CACHE_WAY_COUNT 4
#define CPU_CACHE_LINE_NUMBER 1024
#define CPU_CACHE_LINE_NUMBER_PER_WAY 256

#define CPU_CACHE_OP_LOCK_COUNTER 64            // MT6250
#define CPU_INVALIDATE_THRESHOLD (264 * 1024)   // This indicates the size that we use clean_and_invalidate to replace invalidate operation

/* Cache-related op. */
#define IS_CACHE_CHANNEL_SIZE_ALIGNED(value, ch_mask) ((value&ch_mask)==0? 1: 0)
#if defined(MT6225) || defined(MT6253)
#define InvalidCodeCacheByAddr(addr) do { *CACHE_OP = ((addr) & 0xFFFFFFE0 ) | 0x00030009; } while (0)
#define InvalidCodeCacheByAlignedAddr(addr) do { *CACHE_OP = (addr) | 0x00030009; } while (0)
#else /* MT6225 || MT6253 */
#define InvalidCodeCacheByAddr(addr) do { *CACHE_OP = ((addr) & 0xFFFFFFE0 ) | 0x00000005; } while (0)
#define InvalidCodeCacheByAlignedAddr(addr) do { *CACHE_OP = (addr) | 0x00000005; } while (0)
#endif /* MT6225 || MT6253 */

#if defined(MT6253E)||defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define CleanCodeCacheByAddr(addr) do { *CACHE_OP = ((addr) & 0xFFFFFFE0 ) | 0x00000015; } while (0)
#define CleanCodeCacheByAlignedAddr(addr) do { *CACHE_OP = (addr) | 0x00000015; } while (0)
#else
#define CleanCodeCacheByAddr(addr) do {} while (0)
#define CleanCodeCacheByAlignedAddr(addr) do {} while (0)    
#endif /* MT6253E || MT6253L */

#define MTKL1CACHE_CleanAllCacheLines() (*CACHE_OP = 0x0000013)
#define MTKL1CACHE_InvalidAllCacheLines() (*CACHE_OP = 0x0000003)
#define MTKL1CACHE_CleanCacheLines_by_SetWay(set, way) (*CACHE_OP = (kal_uint32)(((set)<<5)|((1<<way)<<16)|0x00000019))
#define MTKL1CACHE_InvalidateCacheLines_by_SetWay(set, way) (*CACHE_OP = (kal_uint32)(((set)<<5)|((1<<way)<<16)|0x00000009))


/*******************************************************************************
 * prototypes
 ******************************************************************************/
 
void CodeCacheConfig(CacheType type, kal_bool enable);
void CodeCacheSetting(CacheMenuType *cacheMenu);
void MPUSetting(MPUMenuType *menu);
void CacheAccessHitCount(CodeCacheHitCount *ret);
void CacheInit(void);
kal_int32   invalidate_l1cache(kal_uint32 addr, kal_uint32 len);
kal_int32   clean_l1cache(kal_uint32 addr, kal_uint32 len);
kal_int32 invalidate_wt_cache(kal_uint32 addr, kal_uint32 len);
kal_uint32 free_all_channels(kal_uint32 start_addr, kal_uint32 end_addr);
kal_int32  query_l1cache_free_ch_num(void);
kal_int32 query_is_l1cache_cacheable(kal_uint32 addr, kal_uint32 len, kal_uint32 query_ram);

#if !defined(__MTK_MMU__)
kal_uint32 dynamic_switch_cacheable_region(kal_uint32 start_addr, kal_uint32 end_addr, kal_uint32 total_size, kal_uint32 cacheable);
#endif /* __MTK_MMU__ */

#endif  /* __MTK_L1CACHEABLE__ */




#if defined(__MTK_L2CACHEABLE__)


/*******************************************************************************
 * constants & macros
 *******************************************************************************/

#define  DataCacheDisabled              0x80000013
#define  DataCacheInvalidateAll         0x80000050
#define  DataCacheInvalidateCleanAll 0x80000070
#define  DataCacheDrainWriteBuffer    0x80000002
#define  DataCacheEnabled               0x80000003
#define  DataCacheGATEDG                0x00000040
#define  DataCacheFBBR                  0x00000100
#define  DataCacheCommandBusy           0x01

#define  DataCacheWaitCommandReady() \
   while ( *(L2C_STA) & DataCacheCommandBusy );

#define  MTKL2CACHE_InvalidateAllCacheLines() \
   *L2C_CON |= DataCacheInvalidateAll; \
   DataCacheWaitCommandReady();

#define  MTKL2CACHE_CleanAndInvalidateAllCacheLines() \
   *L2C_CON |= DataCacheInvalidateCleanAll; \
   DataCacheWaitCommandReady();

#define  MTKL2CACHE_DrainWriteBuffer() \
   *L2C_CON |= DataCacheDrainWriteBuffer; \
   DataCacheWaitCommandReady();


/*******************************************************************************
 * prototypes
 ******************************************************************************/

kal_bool DataCacheConfig(kal_bool enable, kal_bool reservedForMPEG4);
kal_uint32        EnableFBBR(void);
void                DisableFBBR(kal_uint32 val);
kal_uint32        GateDG(void);
void                UngateDG(kal_uint32 val);

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6268H) )

/********************
 * constants
 ********************/

#define  DataCacheLocking2Way      0x00000020

/********************
 * prototypes
 ********************/

kal_uint32 Lock2WaysForMPEG4(void);
void Unlock2WaysForMPEG4(kal_uint32 val);

#elif defined(MT6238) || defined(MT6239)   /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */

/********************
 * constants
 ********************/
 
#define  DataCacheDIRTYAALL              0x00000080
#define  DataCacheEX                          0x00000200
#define  DataCacheC2WBUF                 0x00000400
#define  DataCacheBURSTDIS                0x00000800
#define  DataCacheCNTEN                     0x00001000
#define  DataCacheGMCNotBypassL2    	0x00002000

#endif  /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */

#endif  /* __MTK_L2CACHEABLE__ */




#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__)

/*******************************************************************************
 * constants & macros
 *******************************************************************************/
#define ROUNDUP_1KB(v)    \
        do {    \
            (v) = (((v) + 1024 - 1) >> 10) << 10;    \
        } while (0)

#define ROUNDUP_4KB(v)    \
        do {    \
            (v) = (((v) + 4096 - 1) >> 12) << 12;    \
        } while (0)

#define ROUNDDOWN_4KB(v)  \
        do {    \
            (v) = (v) & ~(4096 - 1);    \
        } while (0)


#if defined(__MTK_MMU__)
/* ARM9 DCache region offset */
#define CREG_OFFSET 0xF0000000
#define CREG_SYS_OFFSET 0xF8000000

/* Map To Cached ReGion Physical Address */
#define MAP2CREGPA(addr) ((kal_uint32)(addr) & ~CREG_OFFSET | (custom_get_1st_ROM_RAMBase() & 0xF8000000))
#define MAP2CREGVA(addr) (((kal_uint32)(addr) ^ (custom_get_1st_ROM_RAMBase() & 0xF0000000)) | CREG_OFFSET)
#else
/* ARM9 DCache region offset */
#define CREG_OFFSET 0xF0000000
#define CREG_SYS_OFFSET 0xF8000000

/* MMV2 cache region offset */
#define MMV2CREG_OFFSET 0xE0000000

/* Map To Cached ReGion Physical Address */
#define MAP2CREGPA(addr) ((kal_uint32)(addr) & ~CREG_OFFSET | (custom_get_1st_ROM_RAMBase() & 0xF0000000))
#define MAP2CREGVA(addr) (((kal_uint32)(addr) ^ (custom_get_1st_ROM_RAMBase() & 0xF0000000)) | CREG_OFFSET)
#endif /* __MTK_MMU__ */

#define MAP2CREGPA_SYS(addr) ((kal_uint32)(addr) & ~CREG_SYS_OFFSET | custom_get_SysRam_Base())
#define MAP2CREGVA_SYS(addr) (((kal_uint32)(addr) & ~(custom_get_SysRam_Base())) | CREG_SYS_OFFSET)

#define MAP2CREGNEWA(olda, newa) (((kal_uint32)(olda) & ~CREG_SYS_OFFSET) | ((kal_uint32)(newa) & CREG_SYS_OFFSET))

#define CPU_CACHE_LINE_SIZE 32
#define CPU_CACHE_LINE_BIT_OFFSET 5
#define CPU_CACHE_LINE_SIZE_MASK 0x0000001F
#define CPU_CACHE_WAY_COUNT 4

/*******************************************************************************
 * function prototypes
 *******************************************************************************/

kal_uint32 check_cptbl_pool(void);
kal_uint32 check_fptbl_pool(void);

#endif /* __ARM9_MMU__ && __ARM11_MMU__ && __MTK_MMU__ */


/* To be revised - START */
#if (defined(MT6261) || defined(MT2501) || defined(MT2502)) && (!defined(__BT_BOX_SUPPORT__))
#define PROTECT_REGION_BEFORE_INIT
#endif

typedef enum {
		Vector_0xF_bank_Section,
		Normal_Section1,
	#if defined(__BOOT_ZIMAGE_SUPPORT__)
		Boot_Zimage_Section,
	#endif
	#if defined(__ZIMAGE_SUPPORT__)
		Zimage_Section,
		Normal_Section2,
	#endif
	#if defined(__DCM_WITH_COMPRESSION__) || defined(__DYNAMIC_CODE_MANAGER__)
	#if !defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
		DCM_Section,
		Normal_Section3,
	#endif
	#endif
		Normal_section_dummy,
		Protect_Region_max_ID
} Protect_Ram_Region_ID;


typedef struct {
   	kal_uint32 region_star_addr;  // the protect region start addr
   	kal_uint16 channel;
   	MPU_ATTRIBUTE attribute;
} Protect_Ram_Region_Before_Init_Struct_T;


extern void MPU_Protect_Before_Init(void);
extern void MPU_Unprotect_One_Region(Protect_Ram_Region_ID id);
/* To be revised - END */

#endif /* !_CACHE_SW_INT_H */

