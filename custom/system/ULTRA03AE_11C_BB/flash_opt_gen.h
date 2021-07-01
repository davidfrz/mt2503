/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   flash_opt_gen.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   NOR flash related options
 *
 * Author:
 * -------
 * -------
 *
 *   Memory Device database last modified on 2015/4/2
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/*
 *******************************************************************************
 PART 1:
   FLASH CONFIG Options Definition here
 *******************************************************************************
*/


#define __PAGE_BUFFER_PROGRAM__
#define __SERIAL_FLASH__
#define SF_DAL_MXIC
#define SF_DAL_WINBOND
#define __NON_INTEL_SIBLEY__


#define __SINGLE_BANK_NOR_DEVICE__


/*
 *******************************************************************************
 PART 2:
   FLASH FDM FEATURE CONFIG PARAMETERS translated from Manual custom_Memorydevice.h
 *******************************************************************************
*/

#define BUFFER_PROGRAM_ITERATION_LENGTH  (64)

/*
 *******************************************************************************
 PART 3:
   FLASH GEOMETRY translated from MEMORY DEVICE DATABASE
 *******************************************************************************
*/

/* NOR flash maximum block size (Byte) in file system region */
#define NOR_BLOCK_SIZE  0x10000
#define NOR_DISK0_BLOCK_SIZE 0x0

/* NAND flash total size (MB). PLEASE configure it as 0 if it is unknown. */
#define NAND_TOTAL_SIZE 0

/* NAND flash block size (KB). PLEASE configure it as 0 if it is unknown. */
#define NAND_BLOCK_SIZE 0

/*
 *******************************************************************************
 PART 4:
   FLASH FAT CONFIG translated from Manual custom_Memorydevice.h
 *******************************************************************************
*/

    

    #define NOR_FLASH_BASE_ADDRESS_DEFAULT     (0x00F00000)
    #define NOR_ALLOCATED_FAT_SPACE_DEFAULT    (0x00100000)
    #define FOTA_DM_FS_OFFSET 0x0
    #define FOTA_DM_FS_SECTOR_OFFSET 0

/*
 *******************************************************************************
 PART 6:
   FOTA UPDATABLE FLASH AREA
 *******************************************************************************
*/

#ifdef __FOTA_DM__
    #error "make\ULTRA03AE_11C_gprs.mak: Error! FOTA_ENABLE should not be defined!"
#endif /* __FOTA_DM__ */


#define CONFIG_FOTA_NOR_REGION_DEF \


#define CONFIG_FOTA_NOR_BLOCK_DEF \


#define CONFIG_FOTA_NOR_BANK_DEF \


