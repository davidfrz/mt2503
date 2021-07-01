/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc.                                                                                                                                                       (C) 2009
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS                                                                                                                                                       ("MEDIATEK SOFTWARE")
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
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE                                                                                                                                                       (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bl_funet.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *   Definition for firmware update via the internet
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _BL_FUDIFFNET_H_
#define _BL_FUDIFFNET_H_

#if defined(__FUDIFFNET_ENABLE__) && defined(__SV5_ENABLED__)

#include "br_GFH.h"
#include "br_GFH_dl_package_info.h"

#ifndef __FUDIFFNET_REDBEND_ENABLE__
typedef unsigned int RB_UINT32;
#endif

typedef struct
{
    GFH_FILE_TYPE         m_bin_type;    
    kal_int32             m_bin_offset; 
} IOT_BIN_INFO; 


typedef struct
{
    /*length of IOT_FOTA_HEADER*/
    kal_int32     header_len;
    /*reserved for extensibility */
    kal_int32     m_reserved[3];
    /*offset of each binary*/
    IOT_BIN_INFO  m_extra_info[GFH_DL_PKG_EXTRA_INFO_COUNT];  
} IOT_HEADER;


typedef kal_int16 BL_FUDIFFNET_ERROR_CODE;

typedef struct
{
    GFH_FILE_INFO_v1        gfh_file_info;
    GFH_DL_PACKAGE_INFO_v2  gfh_dl_package_info;
} DL_PACKAGE_GFH;

typedef struct{
    char            m_project_id[64];  //string to describe project name and S/W version
    char            m_type_ver[8];     //resource type and version["MBAVer" + 2 byte version number]
    unsigned short  m_compressed;      //resouce bin compress or not(v3 or later)
    unsigned short  m_existed;         //resource bin entry exist or not (v3 or later)
    unsigned int    m_base_addr;       //base address of resource
    unsigned int    m_compressed_size; //if compress, compress size(v3 or later)
    unsigned int    m_max_ram_size;    //memory usage size(v3 or later)
    unsigned int    m_res_type;        //resource type (0x06000000 = LangPack, 0x07000000 = CustPack)
    unsigned int    m_exec_addr;       //execution address(v3 or later)
    unsigned int    m_table_size;      //size of resource table
    unsigned int    m_content_size;    //size of resource content
    unsigned int    m_magic;           //resource magic 0x12345678
    
} MTK_Recource_Entry_V3;
#define RESOURCE_ENTRY_MAGIC 0x12345678
#define RESOURCE_ENTRY_NUM   5

#ifdef __ROCK_FOTA_SUPPORT__
    #define FUDIFFNET_PKG_PATH         L"Z:\\@fota_rock\\fota.delta"
    #define UI_PATH                    L"Z:\\rock_update_info"
    #define UPDATED_STATUS_PATH        L"Z:\\rock_update_status"
#else
    #define FUDIFFNET_PKG_PATH         L"Z:\\@fota_redbend\\fota.delta"
    #define UI_PATH                    L"Z:\\redbend_update_info"
    #define UPDATED_STATUS_PATH        L"Z:\\redbend_update_status"
#endif

// size of marker region
#define FUDIFFNET_MARKER_REGION_SIZE   (32)
// version of update info structure
#define FUDIFFNET_UI_VERSION           (1)

/* this structure contains 1. update information for DM, 2. marker for power loss recovery */
typedef struct
{	  
    /* version of structure */
    kal_int32 m_ver;
    /* update information for DM*/
    kal_int32 m_error_code;
    /* the behavior of bootloader for this error */
    kal_int32 m_behavior;    // 0 : reboot, 1 : hang
    /* check if DM has read */
    kal_int32 m_is_read;     // 0 : read, 1 : not read
    /* marker for power loss recovery */
    kal_char  m_marker[FUDIFFNET_MARKER_REGION_SIZE];
    
    /* reserved & make the structure 64 bytes */
    kal_int32 reserved[4];   
             
}  FUDIFFNET_Update_Info; 

/* this structure contains update status */
typedef struct
{	  
    /* version of structure */
    kal_int32 m_ver;
    /* marker for power loss recovery */
    kal_int32  m_marker;  
    /* update status fo DM*/
    kal_int32 m_error_code;  
    /* reserved & make the structure 32 bytes */
    kal_int32 reserved[5];
}  FUDIFFNET_Update_Status; 



#define MIN(a,b) ((a)<(b)?(a):(b))

#ifdef __SERIAL_FLASH_EN__
#define NOR_PAGE_SIZE             (512)         //512 bytes
#else
#define NOR_PAGE_SIZE             (2048)        //2048 bytes
#endif

#define FUDIFFNET_MAX_PAGE_SIZE             (4096)
#define FUDIFFNET_MAX_SPARE_SIZE            (128)
#define MAX_PAGE_SIZE_WITH_SPARE  (FUDIFFNET_MAX_PAGE_SIZE+FUDIFFNET_MAX_SPARE_SIZE)

#define INVALID_OFFSET            (0xffffffff)
#define INVALID_BLOCK_IDX         (0xffffffff)
#define INVALID_ADDR              (0xffffffff)
#define INVALID_LEN               (0xffffffff)
#define INVALID_4B_CONTENT        (0xffffffff)
#define INVALID_1B_CONTENT        (0xff)

#define ENFB_MASK                 (0x00000041)
#define B_MASK                    (0x00000080) 
#define U_MASK                    (0x00000010) 
#define P_IMAGE_MASK              (0x00000008)
#define FS_IMAGE_MASK             (0x00000004)
#define RS_IMAGE_MASK             (0x00000002)

#define FDMVER_MASK               (0x00ffffff)
#define FDMVER_105_MASK           (0xff00ffff)
#define FDMVER_205                (0x00000205)
#define FDMVER_105                (0x00000105)
#define FDMVER_005                (0x00000005)
#define IM_FDMVER_500             (0x0500)

#define FUDIFFNET_MARKER              (0x544e5546)

#define TRANSMISSION_WRAP_MASK    (0xff)
#define TRANSMISSION_DBG_MAGIC    (0xedb88320L)
#define TRANSMISSION_DBG_PATTERN  (0xcd)

//Error code

#define BL_FUDIFFNET_ERROR_NONE                                               (0)

//Internal error
#define BL_FUDIFFNET_ERROR_INSUFFICIENT_WORKING_BUF                           (-100)
#define BL_FUDIFFNET_ERROR_INSUFFICIENT_MACR_BUF                              (-101)
#define BL_FUDIFFNET_ERROR_INSUFFICIENT_GFH_INFO_BUF                          (-102)


//PKG format
#define BL_FUDIFFNET_ERROR_INVALID_XIM_START                                  (-300)
#define BL_FUDIFFNET_ERROR_INVALID_PARAM_IN_NAND_IMAGE_HEADER                 (-301)
#define BL_FUDIFFNET_ERROR_INVALID_PARAM_IN_XIM_BODY                          (-302)
#define BL_FUDIFFNET_ERROR_INVALIDE_HEADER_SIG                                (-303)
#define BL_FUDIFFNET_ERROR_INVALIDE_BODY_SIG                                  (-304)
#define BL_FUDIFFNET_ERROR_INVALID_XIM_CONTENT                                (-305)
#define BL_FUDIFFNET_ERROR_ADDRESS_OR_LENGTH_NOT_BLOCK_BOUNDARY               (-306)
#define BL_FUDIFFNET_ERROR_REGION_OVERLAP                                     (-307)
#define BL_FUDIFFNET_ERROR_INVALID_BINARY_OPERATION                           (-308)
#define BL_FUDIFFNET_ERROR_INVALID_BINARY_ADDRESS                             (-309)
#define BL_FUDIFFNET_ERROR_INVALID_UPDATING_BINARY                            (-310)
#define BL_FUDIFFNET_ERROR_INVALID_PARTIAL_UPDATE_PACKAGE                     (-311)
#define BL_FUDIFFNET_ERROR_BOOTLOADER_CANNOT_BE_UPDATED                       (-312)
#define BL_FUDIFFNET_ERROR_XIM_INVALID_PARAM                                  (-313)
#define BL_FUDIFFNET_ERROR_TOTALBBM_IM_ON_NON_TOTALBBM_TARGET                 (-314)
#define BL_FUDIFFNET_ERROR_NON_TOTALBBM_IM_ON_TOTALBBM_TARGET                 (-315)
#define BL_FUDIFFNET_ERROR_MISMATCHED_FS_COUNT                                (-316)
#define BL_FUDIFFNET_ERROR_MISMATCHED_BRMT                                    (-317)
#define BL_FUDIFFNET_ERROR_NEED_TO_UPDATE_ALL_FS                              (-318)
#define BL_FUDIFFNET_ERROR_NO_BOOT_CERT_EXIST                                 (-319)
#define BL_FUDIFFNET_ERROR_PKG_PARTIAL_UPDATE_ERROR                           (-320)
#define BL_FUDIFFNET_ERROR_OVERLAP_WITH_TARGET_FS                             (-321)
#define BL_FUDIFFNET_ERROR_FS_CANNOT_BE_UPDATED                               (-322)
#define BL_FUDIFFNET_ERROR_MBA_BIN_COMBINATION_ERROR                          (-323)
#define BL_FUDIFFNET_ERROR_MBA_LANG_PACK_NOT_MATCH_ERROR                      (-324)
#define BL_FUDIFFNET_ERROR_MBA_CUST_PACK_NOT_MATCH_ERROR                      (-325)
#define BL_FUDIFFNET_ERROR_OVERLAP_WITH_WIFI_BIN                              (-326)






#define BL_FUDIFFNET_ERROR_INVALID_XIM_END                                    (-399)

//Binary content checking (Feature combination,Version checking,MBA rule,Filesystem owelapping)
#define BL_FUDIFFNET_ERROR_VERSION_ERROR_START                                (-400)
#define BL_FUDIFFNET_ERROR_MISMATCHED_BL_PAIRED_VERION                        (-401)
#define BL_FUDIFFNET_ERROR_MISMATCH_DLPKG_SW_VER                              (-402)
#define BL_FUDIFFNET_ERROR_MISMATCH_DLPKG_PLATFORM_ID                         (-403)
#define BL_FUDIFFNET_ERROR_INCOMPATIBLE_FEATURES                              (-404)
#define BL_FUDIFFNET_ERROR_CUSTOM_CHECK_FAIL                                  (-405)
#define BL_FUDIFFNET_ERROR_NO_ROM_INFO_FOUND                                  (-406)
#define BL_FUDIFFNET_ERROR_NO_PKG_ROM_INFO_FOUND                              (-407)
#define BL_FUDIFFNET_ERROR_GET_ROMINFO_FAIL                                   (-408)
#define BL_FUDIFFNET_ERROR_NO_PKG_GFH_FILE_INFO_FOUND                         (-409)
#define BL_FUDIFFNET_ERROR_NO_PKG_GFH_MAUI_INFO_FOUND                         (-410)
#define BL_FUDIFFNET_ERROR_NO_ROM_GFH_MAUI_INFO_FOUND                         (-411)
#define BL_FUDIFFNET_ERROR_MBA_JUMP_TABLE_ADDR_NOT_MATCH_WITH_TARGET          (-412)
#define BL_FUDIFFNET_ERROR_MBA_ENRTY_VALID_CHECK_FAIL                         (-413)
#define BL_FUDIFFNET_ERROR_MBA_BASE_ADDR_CHECK_FAIL                           (-414)
#define BL_FUDIFFNET_ERROR_MBA_INFO_NOT_MATCH                                 (-415)
#define BL_FUDIFFNET_ERROR_MBA_COMPRESSED_RULE_CHECK_FAIL                     (-416)




#define BL_FUDIFFNET_ERROR_VERSION_ERROR_END                                  (-499)

// Update record
#define BL_FUDIFFNET_ERROR_ILB_ERROR_START                                    (-500)
#define BL_FUDIFFNET_ERROR_UNABLE_TO_FIND_CBR_SPACE_INFO                      (-510)
#define BL_FUDIFFNET_ERROR_FAIL_TO_WRITE_CBR_IMAGE_INFO                       (-511)
#define BL_FUDIFFNET_ERROR_FAIL_TO_WRITE_CBR_SPACE_INFO                       (-512)
#define BL_FUDIFFNET_ERROR_FAIL_TO_ADD_CBR_UPDATING_INFO                      (-513)
#define BL_FUDIFFNET_ERROR_FAIL_TO_DEL_CBR_UPDATING_INFO                      (-514)
#define BL_FUDIFFNET_ERROR_FAIL_TO_READ_CBR_UPDATING_INFO                     (-515)
#define BL_FUDIFFNET_ERROR_OTHER_UA_IS_DOING_UPDATE                           (-516)
#define BL_FUDIFFNET_ERROR_ERASE_MARKER_BLOCK                                 (-530)
#define BL_FUDIFFNET_ERROR_WRITE_MARKER_BLOCK                                 (-531)
#define BL_FUDIFFNET_ERROR_UNABLE_TO_FIND_CBR_IMAGE_INFO                      (-532)

#define BL_FUDIFFNET_ERROR_ILB_ERROR_END                                      (-599)

//Updating related
#define BL_FUDIFFNET_ERROR_UPDATE_ERROR_START                                 (-600)
#define BL_FUDIFFNET_ERROR_3RDROM_REMAP_TBL_TOO_SMALL                         (-601)
#define BL_FUDIFFNET_ERROR_OVER_RESERVED_BOUNDARY                             (-602)
#define BL_FUDIFFNET_ERROR_3RDROM_REMAP_TBL_WRITE_FAILURE                     (-603)
#define BL_FUDIFFNET_ERROR_TOO_MANY_BAD_BLOCK                                 (-604)
#define BL_FUDIFFNET_ERROR_CODE_FS_OVERLAPED                                  (-605)
#define BL_FUDIFFNET_ERROR_INVALID_FDM_MAPTBL                                 (-606)
#define BL_FUDIFFNET_ERROR_NO_BLOCK_FOR_CHKREF                                (-607)
#define BL_FUDIFFNET_ERROR_CHKREF_DATA_PREPARE_FAIL                           (-608)
#define BL_FUDIFFNET_ERROR_CHKREF_UPDATE_FAIL                                 (-609)
#define BL_FUDIFFNET_ERROR_CHKREF_IMG_NOT_FOUND                               (-610)
#define BL_FUDIFFNET_ERROR_XIM_IMG_SIZE_EXCEED_MAX_VALUE                      (-611)
#define BL_FUDIFFNET_ERROR_INVALID_XIM_IMG_MAX_BLOCK_NUMBER                   (-612)
#define BL_FUDIFFNET_ERROR_CODE_FAT_OVERLAPED                                 (-614)
#define BL_FUDIFFNET_ERROR_EARSE_SDS                                          (-615)
//#define BL_FUDIFFNET_ERROR_CANNOT_DL_FS                                       (-616)
#define BL_FUDIFFNET_ERROR_UPDATE_ERROR_END                                   (-699)

//DL PKG adaptation
#define BL_FUDIFFNET_ERROR_PACKAGE_ACCESS_ERROR_START                         (-700)
#define BL_FUDIFFNET_ERROR_NO_CARD_FOUND                                      (-701)
#define BL_FUDIFFNET_ERROR_NO_DL_PACKAGE_FOUND                                (-702)
#define BL_FUDIFFNET_ERROR_PACKAGE_SEEK_FAIL                                  (-703)
#define BL_FUDIFFNET_ERROR_PACKAGE_READ_FAIL                                  (-704)
#define BL_FUDIFFNET_ERROR_PACKAGE_ACCESS_ERROR_END                           (-799)

//Flash operation
#define BL_FUDIFFNET_ERROR_FLASH_ERROR_START                                  (-800)
#define BL_FUDIFFNET_ERROR_FLASH_READ                                         (-801)
#define BL_FUDIFFNET_ERROR_FLASH_PROGRAM                                      (-802)
#define BL_FUDIFFNET_ERROR_FLASH_ERASE                                        (-803)
#define BL_FUDIFFNET_ERROR_FLASH_BAD_BLOCK                                    (-804)
#define BL_FUDIFFNET_ERROR_FLASH_CHECK_SUM                                    (-805)
#define BL_FUDIFFNET_ERROR_NFI_UNEXPECED_BEHAVIOR                             (-806)
#define BL_FUDIFFNET_ERROR_FLASH_OTHER_ERROR                                  (-807)
#define BL_FUDIFFNET_ERROR_FLASH_INIT_FAIL                                    (-808)
#define BL_FUDIFFNET_ERROR_READ_BRMT_FAIL                                     (-809)
#define BL_FUDIFFNET_ERROR_WRITE_BRMT_FAIL                                    (-810)
#define BL_FUDIFFNET_ERROR_TOO_LARGE_BRMT                                     (-811)
#define BL_FUDIFFNET_ERROR_FLASH_ERROR_END                                    (-899)


#define BL_FUDIFFNET_ERROR_FAIL_TO_CREATE_FILE                                (-1100)
#define BL_FUDIFFNET_ERROR_FAIL_TO_OPEN_FILE                                  (-1101)
#define BL_FUDIFFNET_ERROR_FAIL_TO_CLOSE_FILE                                 (-1102)
#define BL_FUDIFFNET_ERROR_FAIL_TO_READ_FILE                                  (-1103)
#define BL_FUDIFFNET_ERROR_FAIL_TO_WRITE_FILE                                 (-1104)
#define BL_FUDIFFNET_ERROR_FAIL_TO_SEEK_FILE                                  (-1105)
#define BL_FUDIFFNET_ERROR_FAIL_TO_DELETE_FILE                                (-1106)

//Memory operation  
#define BL_FUDIFFNET_ERROR_COPY_TO_RAM_FAIL                                   (-1106)//new
#define BL_FUDIFFNET_ERROR_COMPRESSED_BINARY_TOO_LARGE                        (-1107)//new
#define BL_FUDIFFNET_ERROR_DECOMPRESSED_BINARY_TOO_LARGE                      (-1108)//new




#define BL_FUDIFFNET_ERROR_FAIL_TO_CREATE_UI                               (-1110)

#endif /* __FUNET_ENABLE__ && __SV5_ENABLED__ */

#endif /* _BL_FUNET_H_ */

