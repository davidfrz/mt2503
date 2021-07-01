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
 *   bl_FUDIFFNET.c
 *
 * Project:
 * --------
 *   Bootloader
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__FUDIFFNET_ENABLE__) && defined (__SV5_ENABLED__)


#define STATIC

#include <string.h>
#include <bl_types.h>
#include <bl_init.h>
#include <bl_common.h>
#include <bl_features.h>
#include <bl_loader.h>
//#include <msdc_adap_bl.h>
#include "bl_fudiffnet.h"
#include "dcl.h"
#include "ftl.h"
#include "kbd_table.h"
#include "drvpdn.h"
#include "bl_mtk_bb_reg.h"

#if defined(_NAND_FLASH_BOOTING_)
#include <nand_fdm.h>
#endif

#include "fs_gprot.h"

#include "cbr.h"
#include "br_GFH_parser.h"
#include "br_GFH_maui_info.h"
#include "br_GFH_flash_info.h"
#include "br_GFH_error.h"

#ifdef __FOTA_DM__
#include "custom_img_config.h"
#include "fue_err.h"
#include "fue.h"
#include "SSF_ROMinfo.h"
#include "SSF_ROMInfo_type.h"
#endif

#ifdef __ROCK_FOTA_SUPPORT__
#ifdef __FUDIFFNET_ROCK_ENABLE__
    #include "iot_rock.h"
    #include "iot_rock_ipl.h"
#endif
    #include "custom_img_config.h"
#else
#ifdef __FUDIFFNET_REDBEND_ENABLE__
    #include "RB_vRM_Update.h"
    #include "RB_vRM_Errors.h"
#endif
#endif

//RedBend
#include "kal_release.h"
#include "flash_opt.h"
#include "bl_custom.h"

extern void dbg_print(kal_char* fmt, ...);
//#define __FOTA_RB_DEBUG__

#ifdef __EXT_BOOTLOADER__ 

/*************************************************************************
 * Macro and const definition
 *************************************************************************/
//#define __TRANSMISSION_DEBUG__

#ifdef _NAND_FLASH_BOOTING_
#define ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(x) if(!(x)) {BL_PRINT(LOG_ERROR, "bl_Update ASSERT @ %d\n\r", __LINE__); return BL_FUDIFFNET_ERROR_INVALID_PARAM_IN_NAND_IMAGE_HEADER;}
#endif
#define ASSERT_VALID_PARAM_IN_XIM_BODY(x)          if(!(x)) {BL_PRINT(LOG_ERROR, "bl_Update ASSERT @ %d\n\r", __LINE__); return BL_FUDIFFNET_ERROR_INVALID_PARAM_IN_XIM_BODY;}

#define DUMMY_FILENAME            "DUMMY"

//Phase definition for displaying progress bar
#define INIT_PHASE   0
#define VERIFY_PHASE 1
#define UPDATE_PHASE 2
#define FINISH_PHASE 3

#define IS_OVERLAP(s1, l1, s2, l2) (((s1)>=(s2) && (s1)<(s2)+(l2)) || ((s2)>=(s1) && (s2)<(s1)+(l1)))

#define REMAPPING_MASK (custom_RAM_baseaddr()-1)
#ifdef __RAM_FLASH_REMAP_DONE_IN_EMI_INIT__
#define MAUI_ROM_START_ADDR (custom_ROM_baseaddr())   //Memory is remapped by HW, no need to remap the address here.
#define ROM_ADDR_MASK (custom_RAM_baseaddr())
#else
#define MAUI_ROM_START_ADDR (custom_ROM_baseaddr() & REMAPPING_MASK)
#define ROM_ADDR_MASK (0)
#endif
#define BOOTLOADER_ROM_REGION_LEN (custom_ROM_baseaddr()-custom_RAM_baseaddr())

//RedBend
//UPI_Working_buffer
kal_uint8 *   upi_working_buffer = 0;
#ifdef __ROCK_FOTA_SUPPORT__
extern kal_uint32 Image$$EXT_BL_IOT_ROCK_FOTA_WORKING_BUF$$ZI$$Base;
#else
extern kal_uint32 Image$$EXT_BL_REDBEND_FOTA_WORKING_BUF$$ZI$$Base;
#endif
#define UPI_WORKING_BUFFER_LEN         3670016 //3.5*1024*1024 = 3.5M

//UA return value
static kal_uint32 ua_return = 0;
#ifdef __ROCK_FOTA_SUPPORT__
static kal_uint32 need_update_nvram = 0;
#endif

//Fail-Safe stress test
//#define FAIL_SAFE_SANITY_TEST 
kal_uint32 write_backup = 0;
kal_uint32 fail_now = 1;

#ifndef __FUDIFFNET_REDBEND_ENABLE__
#define  S_RB_SUCCESS	        NULL
#define  E_RB_READ_ERROR	NULL
#define  E_RB_WRITE_ERROR	NULL  
#endif


/*************************************************************************
 * Structure definition
 *************************************************************************/
#if defined(_NAND_FLASH_BOOTING_)
//Currently not used
#endif /* _NAND_FLASH_BOOTING_ */

/*************************************************************************
 * External reference definition
 *************************************************************************/
// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary
#if defined(__LCD_DRIVER_IN_BL__)
extern void BL_LCDHWInit(void);
extern void BL_LCDSetBackLight(void);
extern void BL_ShowUpdateFirmwareInitBackground(void);
extern void BL_ShowUpdateFirmwareProgress(kal_uint16 percentage);
extern void BL_ShowUpdateFirmwareFail(kal_int32 r, kal_int32 g, kal_int32 b);
extern void BL_ShowUpdateFirmwareOK(void);
#endif /* __LCD_DRIVER_IN_BL__ */


//RedBend
extern custom_get_DIFFENFOTA_STOR_Region(kal_uint32* addr, kal_uint32* len);
extern FTL_FuncTbl ftlFuncTbl;

/*************************************************************************
 * Global variables definition
 *************************************************************************/
/********
Image Buffer
***/
/*This buffer for compressed image*/
kal_uint8 *  image_buf = 0;

/*This buffer for decompressed image*/
kal_uint8 *  decompression_buf = 0;

#pragma arm section zidata = "EXT_BL_IOT_FOTA_RAM_DUMMY_END"
kal_uint32  ram_dummy_end[1] ;
#pragma arm section zidata

kal_bool isCompressed = 0;


// Flash dependent variables
#if defined(_NAND_FLASH_BOOTING_)
// NAND-related parameters
kal_uint32 page_size = 0;
kal_uint32 page_per_block = 0;
static kal_uint32 block_size = 0;
static kal_uint32 page_size_with_spare = 0;
static kal_uint32 block_size_with_spare = 0;
Nand_ImageSpace_ST *pSpaceInfo = NULL;

#else /* _NAND_FLASH_BOOTING_ */

kal_uint32 page_size = NOR_PAGE_SIZE;
static kal_uint32 page_size_with_spare = NOR_PAGE_SIZE;

#endif /* _NAND_FLASH_BOOTING_ */


static kal_bool   last_fudiffnet_fail_flag = KAL_FALSE;
extern FTL_FuncTbl *g_ftlFuncTbl;

// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary
#if defined(__LCD_DRIVER_IN_BL__) 
static kal_bool lcd_inited = KAL_FALSE;
#endif /* __LCD_DRIVER_IN_BL__ */


/*************************************************************************
 * Declaration
 *************************************************************************/
STATIC kal_bool bl_IsMarkerFound(kal_uint32 mauiAddr);

static kal_bool bl_IsFUDIFFNETMarkerFound();



/*************************************************************************
 * General storage adatpation interfaces
 *************************************************************************/
static kal_int32 bl_fs_handle;             //For keeping the file handle got from FS
static kal_int32 bl_fs_seek_pointer;       //For record the file position during file system update on the net (FUDIFFNET)
static kal_int8 *pbl_ram_seek_pointer;      //For record the file position on the external ram (FUDIFFNET)
static kal_int32 bl_fs_postion;         //To record the current file position


/***************************************************************************//**
 * @brief The interface for FUDIFFNET to open file with File system existed.
 * 
 * This function is not alowed to be re-entrant.
 *
 * @param[in] filename    It is not used yet. Reserved the flexibility for future.
 *
 * @return  The error code. If the error code from FS is not recognizable, it just return
 *                the error code from FS.
 *
 ******************************************************************************/
kal_int32 bl_DL_Open(const kal_char *filename)
{

   //The drive letter will be taken by FS and always be redirect to the correct card drive
   //Thus we can use any drive letter here
   bl_fs_handle = FS_Open(FUDIFFNET_PKG_PATH, FS_READ_WRITE);

   //Check the result of FS API, and convert it to BL error code
   if(bl_fs_handle >= FS_NO_ERROR)
   {
   	  bl_fs_postion = 0;
      return BL_FUDIFFNET_ERROR_NONE;
   }
   else //Something wrong in FS, just return the error code from FS
   {
      return bl_fs_handle;
   }
}

/***************************************************************************//**
 * @brief The interface for FUDIFFNET to seek file with File system existed.
 * 
 * This function redirects to the subset functionaility of FS_seek.
 *
 * @param[in] offset    The offset of file from the file begin.
 * @param[in] origin    Reserved
 *
 * @return  The error code. If the error code from FS is not recognizable, it just return
 *                the error code from FS.
 *
 ******************************************************************************/

kal_int32 bl_fs_Seek(kal_uint32 offset, kal_int32 origin)
{
   ASSERT(origin == 0);
   
   bl_fs_seek_pointer = FS_Seek(bl_fs_handle, offset, 0);

   //Check the result of FS API, and convert it to BL error code
   if(bl_fs_seek_pointer >= FS_NO_ERROR)
   {
   	  bl_fs_postion = offset;
      return BL_FUDIFFNET_ERROR_NONE;
   }
   else
   {
      return bl_fs_seek_pointer;
   }
}



kal_int32 bl_DL_Seek(kal_uint32 offset, kal_int32 origin)
{
   //U32 image_buf_limit = (kal_uint32)(&Image$$EXT_BL_IOT_FOTA_DECOMPRESSION_BUF$$ZI$$Limit);

   ASSERT(origin == 0);

   if(isCompressed)
   {
      /*
       pbl_ram_seek_pointer = ((kal_uint8*)decompression_buf)+offset;

       //Check the result of FS API, and convert it to BL error code
       if(pbl_ram_seek_pointer >= 0 && (U32)pbl_ram_seek_pointer < image_buf_limit)
       {
          return BL_FUDIFFNET_ERROR_NONE;
       }
       else
       {
          BL_PRINT(LOG_DEBUG, "Seek failed out of memory range...\n\r"); 
          return -1 ;
       }
      */
      return 0;
   }
   else
   {
       bl_fs_seek_pointer = FS_Seek(bl_fs_handle, offset, FS_FILE_BEGIN);

       //Check the result of FS API, and convert it to BL error code
       if(bl_fs_seek_pointer >= FS_NO_ERROR)
       {
          return BL_FUDIFFNET_ERROR_NONE;
       }
       else
       {
          return bl_fs_seek_pointer;
       }

   }
  
}


/***************************************************************************//**
 * @brief The interface for FUDIFFNET to read file with File system existed.
 * 
 * This function must be used after bl_DL_Open(). It will use the pre-defined file handle to
 * get the file into buffer.
 *
 * @param[in] buffer    The buffer to be put the read data.
 * @param[in] len         The length to read
 *
 * @return  If there is no error, The return value is the same as the input len. It is due to its caller
 *                expect there is no error only when the return == len.
 *
 ******************************************************************************/
kal_uint32 bl_fs_Read(void *buffer, kal_uint32 len)
{
   kal_uint32 read; 
   kal_int32  status;

   status = FS_Read(bl_fs_handle, buffer, len, &read);

   //Check the result of FS API, and convert it to BL error code
   if(status >= FS_NO_ERROR)
   {
#ifdef __ROCK_FOTA_SUPPORT__
      bl_fs_postion += read;
      return read;
#else
   	  bl_fs_postion += len;
      // Ignore the remaining length if it encountered the file end
      return len;
#endif
   }
   else
   {
      return -1;
   }
}

kal_uint32 bl_DL_Read(void *buffer, kal_uint32 len)
{

   //U32 image_buf_limit = (kal_uint32)(&Image$$EXT_BL_IOT_FOTA_DECOMPRESSION_BUF$$ZI$$Limit);

   kal_uint32 read; 
   kal_int32  status;
  

   if(isCompressed)
   {
      /*
       memcpy(buffer, pbl_ram_seek_pointer, len);
       pbl_ram_seek_pointer += len;

       //Check if seek pointer is still in valid range
       if(pbl_ram_seek_pointer >= 0 && (U32)pbl_ram_seek_pointer < image_buf_limit)
       {
          return len;
       }
       else
       {
          BL_PRINT(LOG_DEBUG, "Read failed out of memory range...\n\r");  
          return -1;
       }
      */
      return 0;
   }
   else
   {
       status = FS_Read(bl_fs_handle, buffer, len, &read);
       //Check the result of FS API, and convert it to BL error code
       if(status == FS_NO_ERROR)
       {
          // Ignore the remaining length if it encountered the file end
          return len;
       }
       else
       {
          return 0;
       }
   }
}



/***************************************************************************//**
 * @brief The interface for FUDIFFNET to close file with File system existed.
 * 
 * This function will close the file handler for cardDL, and deinit msdc.
 *
 ******************************************************************************/
void bl_DL_Close()
{
   //Close the file
   if(bl_fs_handle)
   {
   	  bl_fs_postion = 0;
      FS_Close(bl_fs_handle);
   }

}


/*************************************************************************
 * Public interface
 *************************************************************************/

/**********************************************************
Description : To tell if FUDIFFNET is under processing
Input       : None
Output      : None
***********************************************************/
kal_bool bl_IsFUDIFFNETGoing()
{

#ifndef _NAND_FLASH_BOOTING_

   if(bl_IsFUDIFFNETMarkerFound())
   {
      BL_PRINT(LOG_DEBUG, "Last FUDIFFNET is failed. Re-update Now...\n\r");
      last_fudiffnet_fail_flag = KAL_TRUE;
      return KAL_TRUE;
      
   }
   
#else /* _NAND_FLASH_BOOTING_ */

   //Currently not used
   
#endif /* _NAND_FLASH_BOOTING_ */

   return KAL_FALSE;
}


void bl_ClearFUDIFFNETTrigger()
{
   return;
}

/*************************************************************************
 * Utilities
 *************************************************************************/
#ifdef _NAND_FLASH_BOOTING_

    //Currently not used

#else /* _NAND_FLASH_BOOTING_ */

kal_uint32 bl_AddrToBlockIdx(kal_uint32 addr, FTL_OptParam *opt_param)
{
   kal_uint32 Block;
   kal_uint32 Page;
   kal_uint32 status;
   
   status = g_ftlFuncTbl->FTL_AddrToBlockPage(addr, &Block, &Page, opt_param);

   ASSERT(status == FTL_SUCCESS);

   return Block;
}

#endif /* _NAND_FLASH_BOOTING_ */

STATIC kal_bool bl_IsAddrOnBoundary(kal_uint32 addr)
{
#ifdef _NAND_FLASH_BOOTING_
   return (addr%block_size == 0);
#else
   return (addr == 0 || (bl_AddrToBlockIdx(addr-1, NULL) + 1 == bl_AddrToBlockIdx(addr, NULL)));
#endif /* _NAND_FLASH_BOOTING_ */
}


kal_bool bl_IsRegionOverlap(kal_uint32 addr1, kal_uint32 len1, kal_uint32 addr2, kal_uint32 len2)
{
   if(addr2>=addr1 && addr2<addr1+len1)
   {
      return KAL_TRUE;
   }
   if(addr1>=addr2 && addr1<addr2+len2)
   {
      return KAL_TRUE;
   }

   return KAL_FALSE;
}

void bl_DL_InitLCD()
{
// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary	
#if defined(__LCD_DRIVER_IN_BL__)

   if(!lcd_inited)
   {
      BL_PRINT(LOG_INFO, "Init LCD\n\r");
      BL_LCDHWInit();
      BL_ShowUpdateFirmwareInitBackground();
      BL_LCDSetBackLight();

      {
         DCL_HANDLE rtc_handler;
         DCL_HANDLE pw_handle;

         //before call dclpw, rtc is needed to be initialized
         rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
         DclRTC_Control(rtc_handler, RTC_CMD_SETXOSC, (DCL_CTRL_DATA_T *)NULL);
         DclRTC_Control(rtc_handler, RTC_CMD_HW_INIT, (DCL_CTRL_DATA_T *)NULL);
         DclRTC_Close(rtc_handler);

         //Use dclpw to latch the power
         pw_handle=DclPW_Open(DCL_PW, FLAGS_NONE);
         DclPW_Control(pw_handle,PW_CMD_POWERON,NULL);
         DclPW_Close(pw_handle);
      }

      lcd_inited = KAL_TRUE;

      //Re-init MSDC driver to reset GPIO ping
      bl_DL_Close();
      bl_DL_Open(DUMMY_FILENAME);
   }

#endif /* __LCD_DRIVER_IN_BL__ */
}



BL_FUDIFFNET_ERROR_CODE bl_UpdateProgress(kal_uint32 phase, kal_uint32 progress)
{
// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary

   //phase 0: initialzation, 10%
   //phase 1: verification,  30%
   //phase 2: upgrading,     50%
   //phase 3: finishing,     10%

#if 0
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
#endif

   WacthDogRestart();

   if(progress <= 100)
   {


#if defined(__LCD_DRIVER_IN_BL__)
      BL_PRINT(LOG_DEBUG, "[bl_UpdateProgress\n\r");
      bl_DL_InitLCD();
      //BL_ShowUpdateFirmwareProgress(totalProgress);
      BL_ShowUpdateFirmwareProgress(progress);
#endif // __LCD_DRIVER_IN_BL__ 
      //lastProgress = totalProgress;
   }


   return BL_FUDIFFNET_ERROR_NONE;
}

#ifdef __ROCK_FOTA_SUPPORT__
/*************************************************************************
* IoT ROCK IPL
*************************************************************************/

//TODO: progrss
void rock_trace(void* ctx, const char* fmt, ...) {
	va_list ap;
	va_start (ap, fmt);
	bl_print_internal(LOG_INFO, fmt, ap);
	va_end (ap);
	bl_print(LOG_INFO, "\r"); 
}
void rock_progress(void* ctx, int percent) {
	bl_print(LOG_INFO, "ENTER rock_progress current = %d\n\n\r", percent);
	bl_UpdateProgress(UPDATE_PHASE, percent);
	
}


int rock_read_block(void* ctx, unsigned char* dest, unsigned int start, unsigned int size) {



   long ret_val = -1; // read error

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

   //Currently not used
   return = 0; 
   
#else
{
   kal_uint32 block_idx = 0, page_offset = 0, current_page = 0, page_count  = 0;
   kal_int32 status = BL_FUDIFFNET_ERROR_NONE;
   kal_uint32 destination = (kal_uint32)dest;
   kal_uint32 page_buff[NOR_PAGE_SIZE >> 2];
   kal_uint32 nor_page_size = g_ftlFuncTbl->FTL_GetPageSize(); 
	kal_uint32 need_to_read = size;

//debug use
     kal_uint32 NOR_FLASH_Base = custom_get_NORFLASH_Base();
	 WacthDogRestart();
   
#ifdef __ROCK_FOTA_DEBUG__
      //bl_print(LOG_DEBUG, "NOR_FLASH_Base = 0x%x \n\r", NOR_FLASH_Base);
#endif
//debug use


   
#ifdef __ROCK_FOTA_DEBUG__
   //bl_print(LOG_DEBUG, "rock_read_block: 0x%x(%d) => 0x%x \n\r", start, size, dest);
#endif
   
   page_offset = (kal_uint32)start - 0x10000000; 
   page_offset &= ~(custom_get_NORFLASH_Base());
   while (page_offset >= g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL))
   {
      page_offset -= g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL);
      block_idx++;
   }

   start |= custom_get_NORFLASH_Base();
   //status = fue_fgal.query_info(&info);


   if (status != BL_FUDIFFNET_ERROR_NONE)
   {
#ifdef __ROCK_FOTA_DEBUG__
      bl_print(LOG_ERROR, "ERROR1 rock_read_block errcode = %d \n\r", status);
#endif

      return ret_val;
   }

   block_idx = bl_AddrToBlockIdx((kal_uint32)start, NULL);
   page_count = (g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL) / nor_page_size);

#ifdef __ROCK_FOTA_DEBUG__
   //bl_print(LOG_DEBUG, "rock_read_block block_idx = %d, page_count = %d, page_offset = %d \n\r", block_idx,page_count, page_offset);
#endif

   while (page_offset >= nor_page_size) 
   {  
      page_offset -= nor_page_size;
      current_page++;
      if (current_page == page_count) 
      { 
         block_idx++;
         current_page = 0;       
         page_count = (g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL) / nor_page_size);
      }
   }

#ifdef __ROCK_FOTA_DEBUG__
   //bl_print(LOG_DEBUG, "rock_read_block page_buff = %x, block_idx = %d, current_page= %d \n\r",page_buff,block_idx, current_page);
#endif

   status = g_ftlFuncTbl->FTL_ReadPage(block_idx, current_page, page_buff, NULL);

   if (status != FTL_SUCCESS)
   {
#ifdef __ROCK_FOTA_DEBUG__
      bl_print(LOG_ERROR, "ERROR2 rock_read_block errcode = %d, block_idx = %d, current_page = %d, page_offset = %d \n\r", status, block_idx, current_page, page_offset);
#endif

      return ret_val;
   }

   if ( size >= (nor_page_size - page_offset)) 
   {
      memcpy((void *)destination, (const void *)((kal_uint8 *)page_buff +page_offset), (nor_page_size - page_offset));
      //bl_print(LOG_INFO, "destination = %x %x %x \n\r", *(int*)destination, *(int*)(destination+4), *(int*)(destination +8)); //debug
      destination += nor_page_size - page_offset;
      size -= nor_page_size - page_offset;
      page_offset = 0;
   }
   else
   {
      memcpy((void *)destination, (const void *)((kal_uint8 *)page_buff +page_offset), size);
      //bl_print(LOG_INFO, "destination = %x %x %x \n\r", *(int*)destination, *(int*)(destination+4), *(int*)(destination +8)); //debug
      destination += size;
      page_offset += size;
      size -= size;
   }
      
   
   if (current_page == (page_count -1)) 
   { 
      block_idx++;
      current_page = 0;
   }
   else
   {
      current_page++;
   }

   while ( size > 0)
   {
      if (size >= nor_page_size)
      {
#ifdef __ROCK_FOTA_DEBUG__
         //bl_print(LOG_DEBUG, "Case1 rock_read_block destination = %x, block_idx = %d, current_page - %d \n\r", destination, block_idx, current_page );
#endif
         
         status = g_ftlFuncTbl->FTL_ReadPage(block_idx, current_page, (kal_uint32 *)destination, NULL);
         
         if (status != FTL_SUCCESS)
         {
#ifdef __ROCK_FOTA_DEBUG__
            bl_print(LOG_ERROR, "ERROR3 rock_read_block errcode = %d, block_idx = %d, current_page = %d, page_offset = %d \n",status, block_idx, current_page, page_offset);
#endif
            return ret_val;
         }

         destination += nor_page_size;
         size -= nor_page_size;
      }
      else
      {
#ifdef __ROCK_FOTA_DEBUG__
        // bl_print(LOG_DEBUG, "Case2 rock_read_block destination = %x, block_idx = %d, current_page - %d \n\r", destination, block_idx,current_page );
#endif

         status = g_ftlFuncTbl->FTL_ReadPage(block_idx, current_page, page_buff, NULL);
         
         if (status != FTL_SUCCESS)
         {
#ifdef __ROCK_FOTA_DEBUG__
            bl_print(LOG_ERROR, "ERROR4 rock_read_block errcode = %d, block_idx = %d, current_page = %d, page_offset = %d \n",status, block_idx, current_page, page_offset);
#endif

            return ret_val;
         }

         memcpy((void *)destination, (const void *)page_buff, size);
         destination += size;
         size -= size;
      }

      current_page++;

      if (current_page == page_count)
      {
         block_idx++;
         current_page = 0;
         page_count = (g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL) / nor_page_size);

#ifdef __ROCK_FOTA_DEBUG__
         //bl_print(LOG_DEBUG, "Case1 rock_read_block  block_idx = %d, current_page = %d , page_count = %d \n\r",block_idx,current_page,page_count );
#endif
      }

   }

   ret_val = need_to_read - size;
}
#endif

   //WatchDogRestart();
/*   
#if defined(__LCD_DRIVER_IN_BL__)
      BL_PRINT(LOG_DEBUG, "[bl_UpdateProgressR\n\r");
      bl_DL_InitLCD();
      BL_ShowUpdateFirmwareProgress_R(ret_val+50);
#endif // __LCD_DRIVER_IN_BL__ 
*/
   return ret_val;
}

int rock_write_block(void* ctx, unsigned char* src, unsigned int start, unsigned int size) {
   long ret_val = -1;
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
     //Currently not used
     return 0;
#else
{ 
   //Logical_Flash_info_st info;
   kal_int32  status = BL_FUDIFFNET_ERROR_NONE;
   kal_uint32 block_idx = 0, page_count = 0, current_page = 0;
   kal_uint32 address = start;
   //kal_uint32 size = g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL);
   kal_uint32 nor_page_size = g_ftlFuncTbl->FTL_GetPageSize(); 
   kal_uint32 source = (kal_uint32)src;
   kal_int32 need_to_write = size;
   kal_int32 write_size = size;
#ifdef __ROCK_FOTA_DEBUG__
   bl_print(LOG_DEBUG, "ENTER rock_write_block \n\r");
#endif


   //TODO: MAKR1 ; start + MAUI OFFSET
   //address += 0x40000;
   
   //status = fue_fgal.query_info(&info);
   //(kal_uint32)address |= custom_get_NORFLASH_Base();
   
   
   (kal_uint32)address -= 0x10000000; 
   block_idx = bl_AddrToBlockIdx((kal_uint32)address, NULL);

#ifdef __ROCK_FOTA_DEBUG__
   bl_print(LOG_DEBUG, "rock_write_block do erase  block_idx = %d  \n\r", block_idx);
#endif
   
   status = g_ftlFuncTbl->FTL_EraseBlock(block_idx, NULL);
   
   if (status != FTL_SUCCESS)
   {
#ifdef __ROCK_FOTA_DEBUG__
      bl_print(LOG_ERROR, "Error rock_write_block  errcode = %d, block  = %d \n\r", status, block_idx);
#endif
      
      return ret_val;
   }

   //Erase done, write data
#ifdef __ROCK_FOTA_DEBUG__
   bl_print(LOG_DEBUG, "ENTER rock_write_block write *address = %x, source = %x, size = %d \n\r",address, source, size);
#endif
   
   block_idx = bl_AddrToBlockIdx((kal_uint32)address, NULL);
   
   page_count = (g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL)/nor_page_size);

   while (write_size > 0 )
   {
      if ( current_page >= page_count)
      {

#ifdef __ROCK_FOTA_DEBUG__
         bl_print(LOG_DEBUG, "Change block  rock_write_block block_idx = %d, page_count = %d, current_page = %d \n\r",block_idx, page_count, current_page);
#endif
         
         current_page = 0;
         block_idx++;         
         page_count = (g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL)/nor_page_size);
      }

#ifdef __ROCK_FOTA_DEBUG__     
      //bl_print(LOG_DEBUG, "Write a page rock_write_block address = %x, source = %x, size =  %d \n\r",address, source, size);
      //bl_print(LOG_DEBUG, "CASE1 rock_write_block *source = %x, block_idx = %d, current_page = %d \n\r",source, block_idx, current_page);
#endif

      status = g_ftlFuncTbl->FTL_WritePage(block_idx, current_page, (kal_uint32 *)source, NULL);

      if (status == FTL_SUCCESS)
      {
         (kal_uint32)address += nor_page_size;
         source += nor_page_size;
         current_page++;
         write_size -= nor_page_size;
      }
      else
      {
#ifdef __ROCK_FOTA_DEBUG__
         bl_print(LOG_ERROR, " ERROR rock_write_block  errcode = %d, address %x, source = %x, size = %d, block_idx = %d, current_page = %d \n\r", \
                                                                   status, address, source, write_size, block_idx, current_page);
#endif
         return ret_val;
      }
   }

   ret_val = need_to_write - write_size;
   
}


#endif

   //WatchDogRestart();

   return ret_val;
}

int rock_read_delta(void* ctx, unsigned char* dest, unsigned int offset, unsigned int size) {
	 kal_uint32   result      = BL_FUDIFFNET_ERROR_NONE;

#ifdef __ROCK_FOTA_DEBUG__
   bl_print(LOG_INFO, "ENTER rock_read_delta buffer = %x, size = %d, offset = %x \n\r", dest, size, offset);
#endif

   //Adjust the offset to skip the MTK's header
   //dwStartAddressOffset += sizeof(FOTA_Package_Header_v1_st);

   result = bl_fs_Seek(offset, 0);  
   
   if(result == BL_FUDIFFNET_ERROR_NONE)
   {
      result = bl_fs_Read(dest, size);
   }else{
#ifdef __ROCK_FOTA_DEBUG__
      bl_print(LOG_INFO, "[rock_read_delta] bl_fs_Seek failed! \n\r");
#endif        
   }
  
#ifdef __ROCK_FOTA_DEBUG__
      bl_print(LOG_INFO, "LEAVE rock_read_delta, result=%d\n\n\r", result);
#endif


      return result;
}



int rock_get_blocksize(void* ctx) {
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
  
   //Currently not used
   return 0;   
   
#else

   kal_uint32 block_size = 0, block_idx = 1;
   block_size = g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL);

#ifdef __ROCK_FOTA_DEBUG__
   bl_print(LOG_DEBUG, "ENTER rock_get_blocksize, ret=%d\n\n\r", block_size);
#endif

   return block_size;
#endif
}

/**********************************************************
Description : Called after flash driver is initialized. Do whatever check related to the flash
Input       : None
Output      : Status of the check
***********************************************************/
BL_FUDIFFNET_ERROR_CODE bl_CheckFlashDeviceStatus()
{

//NOR platform might not be block aligned
#ifdef _NAND_FLASH_BOOTING_
  //Currently not used
  return BL_FUDIFFNET_ERROR_NONE;
#endif

   return BL_FUDIFFNET_ERROR_NONE;
}

BL_FUDIFFNET_ERROR_CODE FTL_ERROR_TO_FUDIFFNET_ERROR(FTL_STATUS_CODE ftlErrorCode)
{
   switch(ftlErrorCode)
   {
   case FTL_SUCCESS:
   case FTL_ERROR_ECC_CORRECTED:
      return BL_FUDIFFNET_ERROR_NONE;

   case FTL_ERROR_READ_FAILURE:
      return BL_FUDIFFNET_ERROR_FLASH_READ;

   case FTL_ERROR_WRITE_FAILURE:
      return BL_FUDIFFNET_ERROR_FLASH_PROGRAM;

   case FTL_ERROR_ERASE_FAILURE:
      return BL_FUDIFFNET_ERROR_FLASH_ERASE;

   case FTL_ERROR_BAD_BLOCK:
      return BL_FUDIFFNET_ERROR_FLASH_BAD_BLOCK;

   }

   return BL_FUDIFFNET_ERROR_FLASH_OTHER_ERROR;
}

/*************************************************************************
 * Image updaters
 *************************************************************************/
#ifdef _NAND_FLASH_BOOTING_

//Currently not used

BL_FUDIFFNET_ERROR_CODE bl_DoUpdate()
{
   BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;  

   //Currently not used
   
   return status;
}


#else /* _NAND_FLASH_BOOTING_ */

BL_FUDIFFNET_ERROR_CODE bl_DoUpdate()
{
   BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;

#ifdef __FUDIFFNET_ROCK_ENABLE__
   kal_uint32 backupBufferAdd = 0;
   kal_uint32 backupBufferSize = 0;
   //kal_uint32 start = MAUI_ROM_START_ADDR;
   //kal_uint32 length  = custom_get_NORFLASH_Size();
   //kal_int32  endBlock = bl_AddrToBlockIdx(start+length-1, NULL);
   
   IOT_UPDATA_CONTEXT ctx;


   //Check UPI working buffer
   if (0 == upi_working_buffer) {
       BL_PRINT(LOG_ERROR, "Can not alloc UPI working buffer\n");
       return BL_FUDIFFNET_ERROR_INSUFFICIENT_WORKING_BUF;
   }
   

   custom_get_DIFFENFOTA_STOR_Region(&backupBufferAdd, &backupBufferSize);



	//ctx.rom_base = 0;
	//ctx.rom_base = custom_get_NORFLASH_Base();
	ctx.rom_base = TINYSYS_ROM1_BEGIN_ADDRESS;
	ctx.ram_base = upi_working_buffer;
	ctx.ram_len = UPI_WORKING_BUFFER_LEN;
	ctx.backup_base = backupBufferAdd;
	ctx.backup_len = backupBufferSize;
	ctx.update_nvram = 0;
	ctx.user_context = 0;
   
   WacthDogDisable();

   //Init Cache for update performance
   CacheInit(); 
   
	ua_return = iot_patch(&ctx);
	need_update_nvram = ctx.update_nvram;

   //Cache deInit
   CacheDeinit();
   
   WacthDogRestart();

   BL_PRINT(LOG_INFO, "IOT_ROCK_PATCH returns %x!, update_nvram : %d\n", ua_return, need_update_nvram);

   if(ua_return != 0){
      status = BL_FUDIFFNET_ERROR_UPDATE_ERROR_END;  
   }
   
#endif

   return status;
}

#endif /* _NAND_FLASH_BOOTING_ */
#else
/*************************************************************************
* RedBend IPL
*************************************************************************/
void LOG_HEX(const char *str, const char *p, int len)
{
  int i;

  if(str)
  {
     BL_PRINT(LOG_INFO, "(%s) ", str);
  } else {
     BL_PRINT(LOG_INFO, " ");
  }

  for (i = 0; i < len; i++) {
     BL_PRINT(LOG_INFO, "%02X ", p[i]);
  }

  BL_PRINT(LOG_INFO, "\n");
}


 RB_UINT32 RB_Trace(void *pbUserData, const char *aFormat,...)
{
   va_list ap;
   va_start (ap, aFormat);

   bl_print_internal(LOG_INFO, aFormat, ap);

   va_end (ap);

   bl_print(LOG_INFO, "\r"); 
   
   return S_RB_SUCCESS;
}

/* RB_GetDelta() - Get the Delta either as a whole or in block pieces */
long RB_GetDelta(
	void *pbUserData,				    /* User data passed to all porting routines */
	unsigned char *pbBuffer,			/* pointer to user buffer */
    RB_UINT32 dwStartAddressOffset,     /* offset from start of delta file */
    RB_UINT32 dwSize)                   /* buffer size in bytes */
{
   kal_uint32   result      = BL_FUDIFFNET_ERROR_NONE;

#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_INFO, "ENTER RB_GetDelta buffer = %x, size = %d, offset = %x \n\r", pbBuffer, dwSize, dwStartAddressOffset);
#endif

   //Adjust the offset to skip the MTK's header
   //dwStartAddressOffset += sizeof(FOTA_Package_Header_v1_st);

   result = bl_fs_Seek(dwStartAddressOffset, 0);  
   
   if(result == BL_FUDIFFNET_ERROR_NONE)
   {
      result = bl_fs_Read(pbBuffer, dwSize);
   }else{
#ifdef __FOTA_RB_DEBUG__
      bl_print(LOG_INFO, "[RB_GetDelta] bl_fs_Seek failed! \n\r");
#endif        
   }
  
#ifdef __FOTA_RB_DEBUG__
      bl_print(LOG_INFO, "LEAVE RB_GetDelta, result=%d\n\n\r", result);
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

   if(result == dwSize)
   {
      return S_RB_SUCCESS;
   }else{
      return E_RB_READ_ERROR;
   }
}

long RB_GetRBDeltaOffset(void *pbUserData, RB_UINT32 signed_delta_offset, RB_UINT32* delta_offset)
{
  
#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_INFO, "ENTER RB_GetRBDeltaOffset signed_delta_offset=0x%x \n\r", signed_delta_offset);
#endif

   *delta_offset = signed_delta_offset; 

   return 0;
}

void RB_Progress(
	void *pbUserData,					/* User data passed to all porting routines */
	RB_UINT32 uPercent)			        /* progress info in percents */
{
//#ifndef __MAUI_BASIC__
//#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_INFO, "ENTER RB_Progress current = %d\n\n\r", uPercent);
   bl_UpdateProgress(UPDATE_PHASE, uPercent);
//#endif

//#endif /*__MAUI_BASIC__*/  
}

long RB_ResetTimerA(void)
{
#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_DEBUG, "RB_ResetTimerA \n\n\r");
#endif

   WacthDogRestart();
   return 0;
}

long RB_GetBlockSize(void *pbUserData) /* returns the size of a memory-block */
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
  
   //Currently not used
   return 0;   
   
#else

   kal_uint32 block_size = 0, block_idx = 1;
   block_size = g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL);

#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_DEBUG, "ENTER RB_GetBlockSize, ret=%d\n\n\r", block_size);
#endif

   return block_size;
#endif
}

long RB_ReadImage(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned char *pbBuffer,			/* pointer to user buffer */
    RB_UINT32 dwStartAddress,		    /* memory address to read from */
    RB_UINT32 dwSize)				    /* number of bytes to copy */
{

   long ret_val = E_RB_READ_ERROR;

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

   //Currently not used
   return = S_RB_SUCCESS; 
   
#else
{
   kal_uint32 block_idx = 0, page_offset = 0, current_page = 0, page_count  = 0;
   kal_int32 status = BL_FUDIFFNET_ERROR_NONE;
   kal_uint32 destination = (kal_uint32)pbBuffer;
   kal_uint32 page_buff[NOR_PAGE_SIZE >> 2];
   kal_uint32 nor_page_size = g_ftlFuncTbl->FTL_GetPageSize(); 


//debug use
     kal_uint32 NOR_FLASH_Base = custom_get_NORFLASH_Base();
     RB_ResetTimerA();
   
#ifdef __FOTA_RB_DEBUG__
      bl_print(LOG_DEBUG, "NOR_FLASH_Base = 0x%x \n\r", NOR_FLASH_Base);
#endif
//debug use


   
#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_DEBUG, "RB_ReadImage: 0x%x(%d) => 0x%x \n\r", dwStartAddress, dwSize, pbBuffer);
#endif

   page_offset = (kal_uint32)dwStartAddress - 0x10000000; 
   page_offset &= ~(custom_get_NORFLASH_Base());
   while (page_offset >= g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL))
   {
      page_offset -= g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL);
      block_idx++;
   }

   dwStartAddress |= custom_get_NORFLASH_Base();
   //status = fue_fgal.query_info(&info);

   if (status != BL_FUDIFFNET_ERROR_NONE)
   {
#ifdef __FOTA_RB_DEBUG__
      bl_print(LOG_ERROR, "ERROR1 RB_ReadImage errcode = %d \n\r", status);
#endif

      return ret_val;
   }

   block_idx = bl_AddrToBlockIdx((kal_uint32)dwStartAddress, NULL);
   page_count = (g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL) / nor_page_size);

#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_DEBUG, "RB_ReadImage block_idx = %d, page_count = %d, page_offset = %d \n\r", block_idx,page_count, page_offset);
#endif

   while (page_offset >= nor_page_size) 
   {  
      page_offset -= nor_page_size;
      current_page++;
      if (current_page == page_count) 
      { 
         block_idx++;
         current_page = 0;       
         page_count = (g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL) / nor_page_size);
      }
   }

#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_DEBUG, "RB_ReadImage page_buff = %x, block_idx = %d, current_page= %d \n\r",page_buff,block_idx, current_page);
#endif

   status = g_ftlFuncTbl->FTL_ReadPage(block_idx, current_page, page_buff, NULL);

   if (status != FTL_SUCCESS)
   {
#ifdef __FOTA_RB_DEBUG__
      bl_print(LOG_ERROR, "ERROR2 RB_ReadImage errcode = %d, block_idx = %d, current_page = %d, page_offset = %d \n\r", status, block_idx, current_page, page_offset);
#endif

      return ret_val;
   }

   if ( dwSize >= (nor_page_size - page_offset)) 
   {
      memcpy((void *)destination, (const void *)((kal_uint8 *)page_buff +page_offset), (nor_page_size - page_offset));
      //bl_print(LOG_INFO, "destination = %x %x %x \n\r", *(int*)destination, *(int*)(destination+4), *(int*)(destination +8)); //debug
      destination += nor_page_size - page_offset;
      dwSize -= nor_page_size - page_offset;
      page_offset = 0;
   }
   else
   {
      memcpy((void *)destination, (const void *)((kal_uint8 *)page_buff +page_offset), dwSize);
      //bl_print(LOG_INFO, "destination = %x %x %x \n\r", *(int*)destination, *(int*)(destination+4), *(int*)(destination +8)); //debug
      destination += dwSize;
      page_offset += dwSize;
      dwSize -= dwSize;
   }
      
   
   if (current_page == (page_count -1)) 
   { 
      block_idx++;
      current_page = 0;
   }
   else
   {
      current_page++;
   }

   while ( dwSize > 0)
   {
      if (dwSize >= nor_page_size)
      {
#ifdef __FOTA_RB_DEBUG__
         bl_print(LOG_DEBUG, "Case1 RB_ReadImage destination = %x, block_idx = %d, current_page - %d \n\r", destination, block_idx, current_page );
#endif
         
         status = g_ftlFuncTbl->FTL_ReadPage(block_idx, current_page, (kal_uint32 *)destination, NULL);
         
         if (status != FTL_SUCCESS)
         {
#ifdef __FOTA_RB_DEBUG__
            bl_print(LOG_ERROR, "ERROR3 RB_ReadImage errcode = %d, block_idx = %d, current_page = %d, page_offset = %d \n",status, block_idx, current_page, page_offset);
#endif

            return ret_val;
         }

         destination += nor_page_size;
         dwSize -= nor_page_size;
      }
      else
      {
#ifdef __FOTA_RB_DEBUG__
         bl_print(LOG_DEBUG, "Case2 RB_ReadImage destination = %x, block_idx = %d, current_page - %d \n\r", destination, block_idx,current_page );
#endif

         status = g_ftlFuncTbl->FTL_ReadPage(block_idx, current_page, page_buff, NULL);
         
         if (status != FTL_SUCCESS)
         {
#ifdef __FOTA_RB_DEBUG__
            bl_print(LOG_ERROR, "ERROR4 RB_ReadImage errcode = %d, block_idx = %d, current_page = %d, page_offset = %d \n",status, block_idx, current_page, page_offset);
#endif

            return ret_val;
         }

         memcpy((void *)destination, (const void *)page_buff, dwSize);
         destination += dwSize;
         dwSize -= dwSize;
      }

      current_page++;

      if (current_page == page_count)
      {
         block_idx++;
         current_page = 0;
         page_count = (g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL) / nor_page_size);

#ifdef __FOTA_RB_DEBUG__
         bl_print(LOG_DEBUG, "Case1 RB_ReadImage  block_idx = %d, current_page = %d , page_count = %d \n\r",block_idx,current_page,page_count );
#endif
      }

   }

   ret_val = S_RB_SUCCESS;
}
#endif

   //WatchDogRestart();

   return ret_val;
}


long RB_ReadBackupBlock(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned char *pbBuffer,			/* pointer to user buffer in RAM where the data will be copied */
	RB_UINT32 dwBlockAddress,		    /* address of data to read into RAM. Must be inside one of the backup buffer blocks */
	RB_UINT32 dwSize)				    /* buffer size in bytes */
{

#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_DEBUG, "RB_ReadBackupBlock: 0x%x(%d) => 0x%x \n\r", dwBlockAddress, dwSize, pbBuffer);
#endif

   return RB_ReadImage(pbUserData, pbBuffer, dwBlockAddress, dwSize);
}


long RB_WriteBlock(
	void *pbUserData,					/* User data passed to all porting routines */
	RB_UINT32 dwBlockAddress,		    /* address of the block to be updated */
	unsigned char *pbBuffer)			/* pointer to data to be written */
{
   long ret_val = E_RB_WRITE_ERROR;

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

     //Currently not used
     return S_RB_SUCCESS;

#else

{ 
   //Logical_Flash_info_st info;
   kal_int32  status = BL_FUDIFFNET_ERROR_NONE;
   kal_uint32 block_idx = 0, page_count = 0, current_page = 0;
   kal_uint32 address = dwBlockAddress;
   kal_uint32 size = g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL);
   kal_uint32 nor_page_size = g_ftlFuncTbl->FTL_GetPageSize(); 
   kal_uint32 source = (kal_uint32)pbBuffer;


#ifdef FAIL_SAFE_SANITY_TEST
   if(!write_backup){   
      if(fail_now){
         //Corrupt Source data by erasing  
         (kal_uint32)address -= 0x10000000; 
         block_idx = bl_AddrToBlockIdx((kal_uint32)address, NULL);
         g_ftlFuncTbl->FTL_EraseBlock(block_idx, NULL);
         
         fail_now = 0; // complete block update next round
         return E_RB_WRITE_ERROR;
      }else{
         fail_now = 1; // corrupt flash data next round
      }
   }
   write_backup = 0;  //reset write_backup
   
#endif

   
#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_DEBUG, "ENTER RB_WriteBlock \n\r");
#endif
   
   //status = fue_fgal.query_info(&info);
   //(kal_uint32)address |= custom_get_NORFLASH_Base();
   
   (kal_uint32)address -= 0x10000000; 
   block_idx = bl_AddrToBlockIdx((kal_uint32)address, NULL);

#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_DEBUG, "RB_WriteBlock do erase  block_idx = %d  \n\r", block_idx);
#endif
   
   status = g_ftlFuncTbl->FTL_EraseBlock(block_idx, NULL);
   
   if (status != FTL_SUCCESS)
   {
#ifdef __FOTA_RB_DEBUG__
      bl_print(LOG_ERROR, "Error RB_WriteBlock  errcode = %d, block  = %d \n\r", status, block_idx);
#endif
      
      return ret_val;
   }

   //Erase done, write data
#ifdef __FOTA_RB_DEBUG__
   bl_print(LOG_DEBUG, "ENTER RB_WriteBlock write *address = %x, source = %x, size = %d \n\r",address, source, size);
#endif
   
   block_idx = bl_AddrToBlockIdx((kal_uint32)address, NULL);
   
   page_count = (g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL)/nor_page_size);

   while (size > 0 )
   {
      if ( current_page >= page_count)
      {
         current_page = 0;
         block_idx++;         
         page_count = (g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL)/nor_page_size);

#ifdef __FOTA_RB_DEBUG__
         bl_print(LOG_DEBUG, "Change block  RB_WriteBlock block_idx = %d, page_count = %d, current_page = %d \n\r",block_idx, page_count, current_page);
#endif
         
      }

#ifdef __FOTA_RB_DEBUG__     
      bl_print(LOG_DEBUG, "Write a page RB_WriteBlock address = %x, source = %x, size =  %d \n\r",address, source, size);
      bl_print(LOG_DEBUG, "CASE1 RB_WriteBlock *source = %x, block_idx = %d, current_page = %d \n\r",source, block_idx, current_page);
#endif

      status = g_ftlFuncTbl->FTL_WritePage(block_idx, current_page, (kal_uint32 *)source, NULL);

      if (status == FTL_SUCCESS)
      {
         (kal_uint32)address += nor_page_size;
         source += nor_page_size;
         current_page++;
         size -= nor_page_size;
         
      }
      else
      {
#ifdef __FOTA_RB_DEBUG__
         bl_print(LOG_ERROR, " ERROR RB_WriteBlock  errcode = %d, address %x, source = %x, size = %d, block_idx = %d, current_page = %d \n\r", \
                                                                   status, address, source, size, block_idx, current_page);
#endif
         return ret_val;
      }
   }

   ret_val = S_RB_SUCCESS;
   
}

#endif

   //WatchDogRestart();

   return ret_val;
}


long RB_WriteBackupBlock(
	void *pbUserData,					/* User data passed to all porting routines */
	RB_UINT32 dwBlockStartAddress,	    /* address of the block to be updated */
	unsigned char *pbBuffer)  	        /* RAM to copy data from */
{
#ifdef __FOTA_RB_DEBUG__
       bl_print(LOG_DEBUG, "RB_WriteBackupBlock \n\r");
#endif


#ifdef FAIL_SAFE_SANITY_TEST
       write_backup = 1;
#endif

    return RB_WriteBlock(pbUserData, dwBlockStartAddress, pbBuffer);
}


long RB_ReadImageNewKey(
	void *pbUserData,
	unsigned char *pbBuffer,
	RB_UINT32 dwStartAddress,
	RB_UINT32 dwSize)
{
    //not used
    return RB_ReadImage(pbUserData, pbBuffer, dwStartAddress, dwSize);
}

long RB_WriteBackupPartOfBlock(
	void *pbUserData,
	RB_UINT32 dwStartAddress,
	RB_UINT32 dwSize,
	unsigned char* pbBuffer)
{
    //not used
    return 0;
}

long RB_EraseBackupBlock(
	void *pbUserData,
	RB_UINT32 dwStartAddress)
{
    //not used
    return 0;
}


/**********************************************************
Description : Called after flash driver is initialized. Do whatever check related to the flash
Input       : None
Output      : Status of the check
***********************************************************/
BL_FUDIFFNET_ERROR_CODE bl_CheckFlashDeviceStatus()
{

//NOR platform might not be block aligned
#ifdef _NAND_FLASH_BOOTING_
  //Currently not used
  return BL_FUDIFFNET_ERROR_NONE;
#endif

   return BL_FUDIFFNET_ERROR_NONE;
}

BL_FUDIFFNET_ERROR_CODE FTL_ERROR_TO_FUDIFFNET_ERROR(FTL_STATUS_CODE ftlErrorCode)
{
   switch(ftlErrorCode)
   {
   case FTL_SUCCESS:
   case FTL_ERROR_ECC_CORRECTED:
      return BL_FUDIFFNET_ERROR_NONE;

   case FTL_ERROR_READ_FAILURE:
      return BL_FUDIFFNET_ERROR_FLASH_READ;

   case FTL_ERROR_WRITE_FAILURE:
      return BL_FUDIFFNET_ERROR_FLASH_PROGRAM;

   case FTL_ERROR_ERASE_FAILURE:
      return BL_FUDIFFNET_ERROR_FLASH_ERASE;

   case FTL_ERROR_BAD_BLOCK:
      return BL_FUDIFFNET_ERROR_FLASH_BAD_BLOCK;

   }

   return BL_FUDIFFNET_ERROR_FLASH_OTHER_ERROR;
}

/*************************************************************************
 * Image updaters
 *************************************************************************/
#ifdef _NAND_FLASH_BOOTING_

//Currently not used

BL_FUDIFFNET_ERROR_CODE bl_DoUpdate()
{
   BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;  

   //Currently not used
   
   return status;
}


#else /* _NAND_FLASH_BOOTING_ */

BL_FUDIFFNET_ERROR_CODE bl_DoUpdate()
{
   BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;

#ifdef __FUDIFFNET_REDBEND_ENABLE__
   kal_uint32 block_size = 0, block_idx = 1; 
   vRM_DeviceData devData;
   CustomerPartitionData partitionData[1];
   kal_uint32 backupBlocksArr[2];
   kal_uint32 backupBufferAdd;
   kal_uint32 backupBufferSize;
   kal_uint32 backupBufferAdd_check;
   kal_uint32 componentInstallerTypes[1] = {0};

   //debug Read
#if 0
/* under construction !*/
/* under construction !*/
#endif
   //debug Read


   //Get flash block size
   block_size = g_ftlFuncTbl->FTL_GetBlockSize(block_idx, NULL);
   BL_PRINT(LOG_INFO, "Flash block_size = %x\n", block_size);
   

   //Check UPI working buffer
   if (0 == upi_working_buffer) {
       BL_PRINT(LOG_ERROR, "Can not alloc UPI working buffer\n");
       return BL_FUDIFFNET_ERROR_INSUFFICIENT_WORKING_BUF;
   }
   
      
   custom_get_DIFFENFOTA_STOR_Region(&backupBufferAdd, &backupBufferSize);
   backupBlocksArr[0] = backupBufferAdd;
   backupBlocksArr[1] = backupBufferAdd + block_size; 

   BL_PRINT(LOG_INFO, "backupBufferAdd[0] = %x\n", backupBufferAdd);
   BL_PRINT(LOG_INFO, "backupBufferAdd[1] = %x\n", backupBufferAdd + block_size);

   //check
   backupBufferAdd_check = backupBlocksArr[0] + backupBufferSize;

   if(backupBufferAdd_check != (backupBlocksArr[1] + block_size)){
        BL_PRINT(LOG_ERROR, "backupBufferAdd_check != backupBlocksAdd + 2 blocks\n");
        BL_PRINT(LOG_ERROR, "backupBufferAdd_check = %x\n", backupBufferAdd_check);
   }

   memset(&devData, 0x00, sizeof(devData));
   memset(&partitionData, 0x00, sizeof(partitionData));

   partitionData[0].partition_name = (kal_uint8*)L"par0";
   partitionData[0].rom_start_address = 0;
   partitionData[0].mount_point = 0;
   partitionData[0].strSourcePath = 0;
   partitionData[0].strTargetPath = 0;
   partitionData[0].partition_type = PT_FOTA;

   devData.ui32Operation = 0; //Scout & Update: 0 ; Dry Update: 2;
   devData.pRam = upi_working_buffer;
   devData.ui32RamSize = UPI_WORKING_BUFFER_LEN;
   devData.ui32NumberOfBuffers = 2;
   devData.pBufferBlocks = backupBlocksArr;
   devData.ui32NumberOfPartitions = 1;
   devData.pFirstPartitionData = partitionData;
   devData.pTempPath = 0;
   devData.enmUpdateType = UT_NO_SELF_UPDATE;
   devData.pComponentInstallerTypes = (kal_uint32*)componentInstallerTypes;
   devData.ui32ComponentInstallerTypesNum = 1;
   //devData.ui32ComponentUpdateFlags = not used;
   //devData.ui32OrdinalToUpdate= not used;
   devData.pDeltaPath = (char*)FUDIFFNET_PKG_PATH;
   devData.pbUserData = 0;

   WacthDogDisable();

   //Init Cache for update performance
   CacheInit(); 
   
#ifdef FAIL_SAFE_SANITY_TEST
   BL_PRINT(LOG_INFO, "In FAIL_SAFE_SANITY_TEST mode...\n");
   ua_return = E_RB_WRITE_ERROR;
   
   while(ua_return==E_RB_WRITE_ERROR){
      ua_return = RB_vRM_Update(&devData);
   }
#else
   ua_return = RB_vRM_Update(&devData);
#endif

   //Cache deInit
   CacheDeinit();
   
   WacthDogRestart();

   BL_PRINT(LOG_INFO, "RB_vRM_Update returns %x!\n", ua_return);

   if(ua_return != 0){
      status = BL_FUDIFFNET_ERROR_UPDATE_ERROR_END;  
   }
   
#endif  
   
   return status;
}

#endif /* _NAND_FLASH_BOOTING_ */
#endif

/*************************************************************************
 * update markers
 *************************************************************************/
#ifdef _NAND_FLASH_BOOTING_

      //Currently not used

#else /* _NAND_FLASH_BOOTING_ */

STATIC kal_bool bl_IsMarkerFound(kal_uint32 mauiAddr)
{
   kal_uint32 i;
   kal_uint32 blockIdx;
   kal_uint32 markerAddr;

   g_ftlFuncTbl->FTL_Init(NULL);

   blockIdx = bl_AddrToBlockIdx(mauiAddr, NULL);

   markerAddr = mauiAddr + g_ftlFuncTbl->FTL_GetBlockSize(blockIdx, NULL);

   for(i=0; i<page_size/4; i++)
   {
      if(*((kal_uint32*)(markerAddr)+i) != FUDIFFNET_MARKER)
      {
         return KAL_FALSE;

      }
   }

   return KAL_TRUE;
}

/*
 * Close FUDIFFNET package handler
 */
BL_FUDIFFNET_ERROR_CODE bl_FUDIFFNET_ClosePKG()
{
    BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;	
    kal_int32 fs_err = FS_NO_ERROR;
    	
    fs_err = FS_Close(bl_fs_handle);
    
		if(fs_err != FS_NO_ERROR)
		{
        BL_PRINT(LOG_DEBUG, "File to close pkg...%d\n\r", fs_err);
		    status = BL_FUDIFFNET_ERROR_FAIL_TO_CLOSE_FILE;
		}
		
		return status;

}
/*
 * Re-Open FUDIFFNET package handler and seek it to previous operation position
 */
BL_FUDIFFNET_ERROR_CODE bl_FUDIFFNET_ReOpenPKG()
{

    BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;	
    kal_int32 fs_err = FS_NO_ERROR;
        
    // open handler for pkg again
		bl_fs_handle = FS_Open(FUDIFFNET_PKG_PATH, FS_READ_WRITE);
				    
		if(bl_fs_handle < 0)
		{
	      fs_err = bl_fs_handle;
				status = BL_FUDIFFNET_ERROR_FAIL_TO_OPEN_FILE;
	  }

    if(status == BL_FUDIFFNET_ERROR_NONE)
    {	
	      fs_err = FS_Seek(bl_fs_handle, bl_fs_postion, 0);
	      if(fs_err < FS_NO_ERROR)
	      {
	          status = BL_FUDIFFNET_ERROR_FAIL_TO_SEEK_FILE;
	      }
    }
    
    if(status != BL_FUDIFFNET_ERROR_NONE)
    {
#ifdef __ROCK_FOTA_SUPPORT__
        BL_PRINT(LOG_DEBUG, "File to re-open pkg...%d,bl_fs_postion=%d\n\r", fs_err, bl_fs_postion);
#else /* __ROCK_FOTA_SUPPORT__*/
        BL_PRINT(LOG_DEBUG, "File to re-open pkg...%d\n\r", fs_err);
#endif /* __ROCK_FOTA_SUPPORT__*/
    }
    
    return status;
}

/* 
 * Create update info if it does not exist.
 * The update info contains 1. FUDIFFNET_Update_Info structure (64 bytes) 2. MAUI gfh info => will be write in runtime
 */
kal_int32 bl_FUDIFFNET_CreateUpdateInfo()
{
   kal_int32 ui_handle;
   FUDIFFNET_Update_Info ui;
   kal_int32 write;
   kal_int32 fs_err = FS_NO_ERROR;
   BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;	


   status = bl_FUDIFFNET_ClosePKG();


   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
    	 // create update info if it does not exist
       if(FS_Open(UI_PATH, FS_READ_ONLY) <= 0)
       {
           ui_handle = FS_Open(UI_PATH, FS_CREATE_ALWAYS);
           
           if(ui_handle >= 0)
           {
               ui.m_ver = FUDIFFNET_UI_VERSION;
               ui.m_error_code = BL_FUDIFFNET_ERROR_NONE;
               ui.m_is_read = 0;
               memset(ui.m_marker, 0x0, FUDIFFNET_MARKER_REGION_SIZE);
               
               fs_err = FS_Write(ui_handle, &ui, sizeof(ui), &write);
               
               if(fs_err != FS_NO_ERROR)
               {
                   return fs_err;
               }
               else
               {
                   fs_err = FS_Close(ui_handle);
                   if(fs_err != FS_NO_ERROR)
                   {
                       return fs_err;
                   }
               }
           }
           else
           {
               BL_PRINT(LOG_DEBUG, "Open UI_PATH failed ui_handle = %d\n\r", ui_handle);
               return ui_handle;
           }
       }
   }

   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
       status = bl_FUDIFFNET_ReOpenPKG();
   }
   
   BL_PRINT(LOG_DEBUG, "[bl_FUDIFFNET_CreateUpdateInfo] status = %d\n\r", status);
   return status;
}

/* 
 * Create status info if it does not exist.
 * The update info contains 1. FUDIFFNET_Update_Info (32bytes)
 */

kal_int32 bl_FUDIFFNET_CreateStatusInfo()
{
   kal_int32 ui_handle;
   //FUDIFFNET_Update_Info ui;
   BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;	


   status = bl_FUDIFFNET_ClosePKG();


   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
      ui_handle = FS_Open(UPDATED_STATUS_PATH, FS_CREATE_ALWAYS);
           
       if(ui_handle < 0)
       {
           return BL_FUDIFFNET_ERROR_FAIL_TO_CREATE_UI;
       }

   }


   status = bl_FUDIFFNET_ReOpenPKG();
 
   return status;
}




/*
 * RAW read update info
 */
BL_FUDIFFNET_ERROR_CODE bl_FUDIFFNET_ReadUI(kal_uint32 offset, void * buffer, kal_int32 buffer_size , const kal_wchar *FileName)
{
    BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;	
    kal_int32 fs_err = FS_NO_ERROR;
    kal_int32 ui_handle;
    kal_int32 read, write;
    //kal_uint32 i;
    //FUDIFFNET_Update_Info ui;
	
	
	  status = bl_FUDIFFNET_ClosePKG();

    
    if(status == BL_FUDIFFNET_ERROR_NONE)
    {
    	  // open update update_info
		    ui_handle = FS_Open(FileName, FS_READ_WRITE);
		    if(ui_handle < 0) //Something wrong in FS, just give the error code from FS
		    {  
		        fs_err = ui_handle;
		        status = BL_FUDIFFNET_ERROR_FAIL_TO_OPEN_FILE;
		    }
    }
    
    if(status == BL_FUDIFFNET_ERROR_NONE)
    {
        fs_err = FS_Seek(ui_handle, offset, 0);
        if(fs_err < FS_NO_ERROR)
		    {
		        status = BL_FUDIFFNET_ERROR_FAIL_TO_SEEK_FILE;
		    }
    }
    
    if(status == BL_FUDIFFNET_ERROR_NONE)
    {
        fs_err = FS_Read(ui_handle, buffer, buffer_size, &read);
				
        if(fs_err != FS_NO_ERROR)
		    {
		        status = BL_FUDIFFNET_ERROR_FAIL_TO_READ_FILE;
		    }
    }
    
    
    if(status == BL_FUDIFFNET_ERROR_NONE)
    {
    	  fs_err = FS_Close(ui_handle);
		    if(fs_err != FS_NO_ERROR)
		    {
		        status = BL_FUDIFFNET_ERROR_FAIL_TO_CLOSE_FILE;
		    }
    }   
		
	if(status == BL_FUDIFFNET_ERROR_NONE)
	{
		  status = bl_FUDIFFNET_ReOpenPKG();
	}


		BL_PRINT(LOG_DEBUG, "File operation status...%d\n\r", fs_err);
	  
	  return status;
    
}
/*
 * RAW write update info
 */
BL_FUDIFFNET_ERROR_CODE bl_FUDIFFNET_WriteUI(kal_uint32 offset, void * buffer, kal_int32 buffer_size, const kal_wchar *FileName)
{
    BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;	
    kal_int32 fs_err = FS_NO_ERROR;
    kal_int32 ui_handle;
    kal_int32 write;
    //FUDIFFNET_Update_Info ui;
	
	
	  status = bl_FUDIFFNET_ClosePKG();

    /*if(status == BL_FUDIFFNET_ERROR_NONE)
    {
		    if(bl_FUDIFFNET_CreateUpdateInfo() != 0)
			  {
			  	 status = BL_FUDIFFNET_ERROR_FAIL_TO_CREATE_UI;
			  }
	  }*/
    
    if(status == BL_FUDIFFNET_ERROR_NONE)
    {
    	  // open update update_info
		    ui_handle = FS_Open(FileName, FS_READ_WRITE);
		    if(ui_handle < 0) //Something wrong in FS, just give the error code from FS
		    {  
		        fs_err = ui_handle;
		        status = BL_FUDIFFNET_ERROR_FAIL_TO_OPEN_FILE;
		    }
    }
    
    if(status == BL_FUDIFFNET_ERROR_NONE)
    {
        fs_err = FS_Seek(ui_handle, offset, 0);
        if(fs_err < FS_NO_ERROR)
		    {
		        status = BL_FUDIFFNET_ERROR_FAIL_TO_SEEK_FILE;
		    }
    }
    
    if(status == BL_FUDIFFNET_ERROR_NONE)
    {
        fs_err = FS_Write(ui_handle, buffer, buffer_size, &write);
        if(fs_err != FS_NO_ERROR)
		    {
		        status = BL_FUDIFFNET_ERROR_FAIL_TO_WRITE_FILE;
		    }
    }
    
    if(status == BL_FUDIFFNET_ERROR_NONE)
    {
    	  fs_err = FS_Close(ui_handle);
		    if(fs_err != FS_NO_ERROR)
		    {
		        status = BL_FUDIFFNET_ERROR_FAIL_TO_CLOSE_FILE;
		    }
    }   

		
    if(status == BL_FUDIFFNET_ERROR_NONE)
		{
		    status = bl_FUDIFFNET_ReOpenPKG();
	  }

    BL_PRINT(LOG_DEBUG, "File operation status...%d\n\r", fs_err);
		
	  
	  return status;
    
}



/*
 * Check if the marker in update info structure is "FUNTFUNTFUNTFUNT..."
 */
STATIC kal_bool bl_IsFUDIFFNETMarkerFound()
{
   kal_int32 ui_handle;
   kal_int32 read;
   kal_uint32 i;
   kal_bool marker_found = KAL_TRUE;
   FUDIFFNET_Update_Info ui;
   
   ui_handle = FS_Open(UI_PATH, 0);

   if(ui_handle < 0)
   {
      //BL_PRINT(LOG_DEBUG, "Open FS failed...%d\n\r", ui_handle);
      marker_found = KAL_FALSE;
   }
   else
   {
       if(FS_Read(ui_handle, &ui, sizeof(ui), &read) == FS_NO_ERROR)
	     {
	         for(i=0; i<sizeof(ui.m_marker)/4; i++)
	         {
	             if(*((kal_uint32*)(ui.m_marker)+i) != FUDIFFNET_MARKER)
		           {
		               marker_found = KAL_FALSE;
		           }
		       }
	     }
	     else
	     {
		       marker_found = KAL_FALSE;
	     } 	   
       FS_Close(ui_handle);
 	 }
 	 
 	 return marker_found;
   
}
/*
 * 1. Write marker to UI structure
 * 2. Write flash information to UI (this is according to original CardDL 
 *    which will use flash information to verify pkg body => bl_VerifyPKGBody()) 
 */
BL_FUDIFFNET_ERROR_CODE bl_MarkFUDIFFNET()
{
	
    BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;	
    FUDIFFNET_Update_Info ui;
    kal_uint32 i;
    

    status = bl_FUDIFFNET_CreateUpdateInfo();


    if(status == BL_FUDIFFNET_ERROR_NONE)    
    {
        status = bl_FUDIFFNET_ReadUI(0, &ui, sizeof(FUDIFFNET_Update_Info),UI_PATH);
    }

    if(status == BL_FUDIFFNET_ERROR_NONE)    
    {
		    // write marker
		    for(i=0; i<sizeof(ui.m_marker)/4; i++)
		    {
		        *((kal_uint32*)(ui.m_marker)+i) = FUDIFFNET_MARKER;
		    }
		    // 1. Write marker to UI structure    
		    bl_FUDIFFNET_WriteUI(0, &ui, sizeof(FUDIFFNET_Update_Info), UI_PATH);
    }

/*    
    // 2. Write flash information to UI (this is according to original CardDL
    if(status == BL_FUDIFFNET_ERROR_NONE)    
    {
        bl_FUDIFFNET_WriteUI(sizeof(FUDIFFNET_Update_Info), flash_pmaui_gfh_buf, sizeof(flash_pmaui_gfh_buf),UI_PATH);
    }

*/
    return status;
	
	
}


/*
 * Clear the marker in UI structure
 */
BL_FUDIFFNET_ERROR_CODE bl_UnMarkFUDIFFNET()
{
    BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;	
    FUDIFFNET_Update_Info ui;
    kal_uint32 i;
    
    status = bl_FUDIFFNET_ReadUI(0, &ui, sizeof(FUDIFFNET_Update_Info),UI_PATH);
    
    if(status == BL_FUDIFFNET_ERROR_NONE)    
    {
		    // clear
		    for(i=0; i<sizeof(ui.m_marker)/4; i++)
		    {
		        *((kal_uint32*)(ui.m_marker)+i) = 0x0;
		    }

    #ifdef __ROCK_FOTA_SUPPORT__
		    ui.m_error_code = ua_return; //rock UA return value 
		    ui.reserved[0] = need_update_nvram;
    #else /* __ROCK_FOTA_SUPPORT__*/
		    ui.m_error_code = ua_return; //Redbend UA return value 
    #endif /* __ROCK_FOTA_SUPPORT__*/
		    
		    bl_FUDIFFNET_WriteUI(0, &ui, sizeof(FUDIFFNET_Update_Info),UI_PATH);
    }
  
    return status;
}

/*
 * 1. Write update status to  structure
 */
BL_FUDIFFNET_ERROR_CODE bl_MarkStatus(BL_FUDIFFNET_ERROR_CODE updateStatus)
{
	
    BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;	
    FUDIFFNET_Update_Status ui;
    //kal_uint32 i;
    
    status = bl_FUDIFFNET_CreateStatusInfo();

    if(status == BL_FUDIFFNET_ERROR_NONE)    
    {
        memset(&ui, 0, sizeof(FUDIFFNET_Update_Status));
		// write marker
		ui.m_ver = 0;
		ui.m_error_code = updateStatus;
		ui.m_marker = FUDIFFNET_MARKER;
		    
		// 1. Write marker to UI structure    
		bl_FUDIFFNET_WriteUI(0, &ui, sizeof(FUDIFFNET_Update_Status), UPDATED_STATUS_PATH);

	    BL_PRINT(LOG_DEBUG, "Status update Done...%d\n\r", status);
    }
    
    return status;	
}

BL_FUDIFFNET_ERROR_CODE bl_UnMarkStatus()
{
	BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;
    kal_int32 ui_handle;

    status = bl_FUDIFFNET_ClosePKG();

    ui_handle = FS_Delete(UPDATED_STATUS_PATH);
    
   
    if(status == BL_FUDIFFNET_ERROR_NONE)
    {
	    status = bl_FUDIFFNET_ReOpenPKG();
	}

	return status;
}

#endif /* _NAND_FLASH_BOOTING_ */


/*************************************************************************
 * MAIN functions
 *************************************************************************/

BL_FUDIFFNET_ERROR_CODE bl_InitialUpdate()
{
   BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;

#ifdef _NAND_FLASH_BOOTING_

   //Currently not used
   
#else /* _NAND_FLASH_BOOTING_ */

   /* !!! The bl_MarkCDL can be ignore in FUDIFFNET and FUDIFFNET case */
   status = bl_MarkFUDIFFNET();


#endif /* _NAND_FLASH_BOOTING_ */

   return status;
}


BL_FUDIFFNET_ERROR_CODE bl_FinishUpdate()
{
   BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;

#ifdef _NAND_FLASH_BOOTING_

  //Currently not used

#else

   /* !!! We still call bl_WriteMarkerBlocks in FUDIFFNET to make sure the 2nd block of MAUI to be written*/
   status = bl_UnMarkFUDIFFNET();

#endif

   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
      bl_ClearFUDIFFNETTrigger();
   }

   return status;
}

void bl_ShowFUDIFFNETSuccess(void)
{
// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary	
#if defined(__LCD_DRIVER_IN_BL__)
   BL_ShowUpdateFirmwareOK();
#endif /* __LCD_DRIVER_IN_BL__ */
}

void bl_ShowFUDIFFNETError(BL_FUDIFFNET_ERROR_CODE status)
{
// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary

#if defined(__LCD_DRIVER_IN_BL__)
   kal_uint32 i;

   typedef struct {
      BL_FUDIFFNET_ERROR_CODE error_start;
      BL_FUDIFFNET_ERROR_CODE error_end;
      kal_uint16 rgb[3];
   } ERROR_MAP;

   const ERROR_MAP error_map[] =
   {
      {BL_FUDIFFNET_ERROR_INVALID_XIM_START,          BL_FUDIFFNET_ERROR_INVALID_XIM_END,           {255, 255,   0} }, //Yellow
      {BL_FUDIFFNET_ERROR_VERSION_ERROR_START,        BL_FUDIFFNET_ERROR_VERSION_ERROR_END,         {255,   0, 255} }, //Purple
      {BL_FUDIFFNET_ERROR_ILB_ERROR_START,            BL_FUDIFFNET_ERROR_ILB_ERROR_END,             {  0, 255, 255} }, //Light blue
      {BL_FUDIFFNET_ERROR_UPDATE_ERROR_START,         BL_FUDIFFNET_ERROR_UPDATE_ERROR_END,          {255,   0,   0} }, //Red
      {BL_FUDIFFNET_ERROR_PACKAGE_ACCESS_ERROR_START, BL_FUDIFFNET_ERROR_PACKAGE_ACCESS_ERROR_END,  {  0,   0, 255} }, //Blue
      {BL_FUDIFFNET_ERROR_FLASH_ERROR_START,          BL_FUDIFFNET_ERROR_FLASH_ERROR_END,           {  0, 255,   0} }, //Green
   };

   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
      return;
   }

   bl_DL_InitLCD();

   for(i=0; i<sizeof(error_map)/sizeof(*error_map); i++)
   {
      if(status <= error_map[i].error_start && status >= error_map[i].error_end)
      {
         BL_ShowUpdateFirmwareFail(error_map[i].rgb[0], error_map[i].rgb[1], error_map[i].rgb[2]);
         return;
      }
   }

   //Other erros
   BL_ShowUpdateFirmwareFail(0, 0, 0);
#endif /* __LCD_DRIVER_IN_BL__ */

}

BL_FUDIFFNET_ERROR_CODE bl_UpdateDiffMain(kal_bool forcedExec)
{
   BL_FUDIFFNET_ERROR_CODE status = BL_FUDIFFNET_ERROR_NONE;
   BL_FUDIFFNET_ERROR_CODE finish_status = BL_FUDIFFNET_ERROR_NONE;
  
#ifdef __ROCK_FOTA_SUPPORT__
   BL_PRINT(LOG_DEBUG, "%x\n\r", (&Image$$EXT_BL_IOT_ROCK_FOTA_WORKING_BUF$$ZI$$Base)); 
   
   /*Init memory buffer*/   
   upi_working_buffer = (kal_uint8 *)(&Image$$EXT_BL_IOT_ROCK_FOTA_WORKING_BUF$$ZI$$Base);
#else /* __ROCK_FOTA_SUPPORT__*/
   BL_PRINT(LOG_DEBUG, "%x\n\r", (&Image$$EXT_BL_REDBEND_FOTA_WORKING_BUF$$ZI$$Base)); 
   
   /*Init memory buffer*/   
   upi_working_buffer = (kal_uint8 *)(&Image$$EXT_BL_REDBEND_FOTA_WORKING_BUF$$ZI$$Base);
#endif /* __ROCK_FOTA_SUPPORT__*/


#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
#endif

   BL_PRINT(LOG_DEBUG, "Acessing T-FLASH...\n\r");   
   
   //Step1. Open update file
   status = bl_DL_Open(DUMMY_FILENAME);
   
   if(status != BL_FUDIFFNET_ERROR_NONE)
   {
        BL_PRINT(LOG_DEBUG, "Open delta package failed or package does not exist...%d\n\r", status);
        bl_DL_Close();

        status == BL_FUDIFFNET_ERROR_NO_DL_PACKAGE_FOUND;
        
        return status; 
   }
 

   BL_PRINT(LOG_INFO, "\n\r");

   //Step2. Init flash driver and check device status
   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
      if(g_ftlFuncTbl->FTL_Init(NULL) != FTL_SUCCESS)
      {
         status = BL_FUDIFFNET_ERROR_FLASH_INIT_FAIL;
      }

      if(status != BL_FUDIFFNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Init FTL is failed...%d\n\r", status);
      }

   }

   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
      status = bl_CheckFlashDeviceStatus();
      if(status != BL_FUDIFFNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Check falsh device is failed..%d\n\r", status);
      }

   }
  
   //Step3. Start to updating
   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
      BL_PRINT(LOG_INFO, "[Initiate update]\n\r");
      status = bl_InitialUpdate();
      if(status != BL_FUDIFFNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Initial Update is failed...%d\n\r", status);
      }
   }

   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
      //bl_UpdateProgress(UPDATE_PHASE, 0);
      BL_PRINT(LOG_INFO, "[Perform update]\n\r");

      status = bl_DoUpdate();
      
      if(status != BL_FUDIFFNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "FOTA update failed...%d\n\r", status);
      }

   }

   //Step4. Post-process and clean up
   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
      //bl_UpdateProgress(FINISH_PHASE, 0);

#ifdef _NAND_FLASH_BOOTING_

   // Currently not used
   
#endif /* _NAND_FLASH_BOOTING_ */
   }

   //if(status == BL_FUDIFFNET_ERROR_NONE)
   if(1) 
   {
      bl_UpdateProgress(FINISH_PHASE, 50);
      BL_PRINT(LOG_INFO, "[Clean up]\n\r");

      //reset marker after update is completed, regardless succssful or fail
      finish_status = bl_FinishUpdate();
      if(finish_status != BL_FUDIFFNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Cannot finish...%d\n\r", status);
      }

   }
   /*Write update status to fs*/
   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
      bl_UnMarkStatus();
   }else
   {
      bl_MarkStatus(status);
   }

if(1){
   if(status == BL_FUDIFFNET_ERROR_NONE)
   {
      //bl_UpdateProgress(FINISH_PHASE, 100);
      bl_ShowFUDIFFNETSuccess();
      bl_DL_Close();

      ClrRetnFlag(RETN_FUNET_FULL_DL_EN | RETN_FUNET_PARTIAL_DL_EN);
      BL_PRINT(LOG_INFO, "[FUDIFFNET] Update done, reboot now ...\n\r");
      SetWDTNormalResetFlag();
      WatchDogResetAll();   
   }
   else
   {
      //bl_UpdateProgress(FINISH_PHASE, 100);
      bl_ShowFUDIFFNETError(status);
   
      ClrRetnFlag(RETN_FUNET_FULL_DL_EN | RETN_FUNET_PARTIAL_DL_EN);
      BL_PRINT(LOG_ERROR, "***Something wrong during update, status=%d\n\r", status);
      SetWDTNormalResetFlag();
      WatchDogResetAll();      
   }
}   
   return status;
}

#endif /* __EXT_BOOTLOADER__ */

#endif /* __FUDIFFNET_ENABLE__ &&  __SV5_ENABLED__ */


