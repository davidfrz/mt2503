#ifndef _FUNET_H_
#define _FUNET_H_

#if defined(__FUNET_ENABLE__) 
#include "kal_general_types.h"

// internal data structure
/*
typedef struct {
   kal_uint32         m_info_type_magic;  //The magic pattern to represent the update agent   
   GFH_MAUI_INFO_v1   m_maui_info;
} FUNET_UPDATING_RECORD;
*/

// update type
typedef enum
{
	  FUNET_UPDATE_FULL,                 
    FUNET_UPDATE_PARTIAL       // for differential package extension
} FUNET_UPDATE_TYPE;

// size of marker region
#define FUNET_MARKER_REGION_SIZE   (32)

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
    kal_char  m_marker[FUNET_MARKER_REGION_SIZE];
    
    /* reserved & make the structure 64 bytes */
    kal_int32 reserved[4];   
             
}  FUNET_Update_Info; 

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
}  FUNET_Update_Status; 


// macro definition
#define FUNET_MARKER                (0x54454E46)



typedef kal_int16 FUNET_ERROR_CODE;

//Error code

#define FUNET_ERROR_NONE                                               (0)

//Internal error
//#define FUNET_ERROR_INSUFFICIENT_WORKING_BUF                           (-100)
//#define FUNET_ERROR_INSUFFICIENT_MACR_BUF                              (-101)
//#define FUNET_ERROR_INSUFFICIENT_GFH_INFO_BUF                          (-102)

//XIM format
//#define FUNET_ERROR_INVALID_XIM_START                                  (-300)
//#define FUNET_ERROR_INVALID_PARAM_IN_NAND_IMAGE_HEADER                 (-301)
//#define FUNET_ERROR_INVALID_PARAM_IN_XIM_BODY                          (-302)
//#define FUNET_ERROR_INVALIDE_HEADER_SIG                                (-303)
//#define FUNET_ERROR_INVALIDE_BODY_SIG                                  (-304)
//#define FUNET_ERROR_INVALID_XIM_CONTENT                                (-305)
//#define FUNET_ERROR_ADDRESS_OR_LENGTH_NOT_BLOCK_BOUNDARY               (-306)
//#define FUNET_ERROR_REGION_OVERLAP                                     (-307)
//#define FUNET_ERROR_INVALID_BINARY_OPERATION                           (-308)
//#define FUNET_ERROR_INVALID_BINARY_ADDRESS                             (-309)
//#define FUNET_ERROR_INVALID_UPDATING_BINARY                            (-310)
//#define FUNET_ERROR_INVALID_PARTIAL_UPDATE_PACKAGE                     (-311)
//#define FUNET_ERROR_BOOTLOADER_CANNOT_BE_UPDATED                       (-312)
//#define FUNET_ERROR_XIM_INVALID_PARAM                                  (-313)
//#define FUNET_ERROR_TOTALBBM_IM_ON_NON_TOTALBBM_TARGET                 (-314)
//#define FUNET_ERROR_NON_TOTALBBM_IM_ON_TOTALBBM_TARGET                 (-315)
//#define FUNET_ERROR_MISMATCHED_FS_COUNT                                (-316)
//#define FUNET_ERROR_MISMATCHED_BRMT                                    (-317)
//#define FUNET_ERROR_NEED_TO_UPDATE_ALL_FS                              (-318)
//#define FUNET_ERROR_NO_BOOT_CERT_EXIST                                 (-319)
//#define FUNET_ERROR_INVALID_XIM_END                                    (-399)

//Version checking
//#define FUNET_ERROR_VERSION_ERROR_START                                (-400)
//#define FUNET_ERROR_MISMATCHED_BL_PAIRED_VERION                        (-401)
//#define FUNET_ERROR_MISMATCH_DLPKG_SW_VER                              (-402)
//#define FUNET_ERROR_MISMATCH_DLPKG_PLATFORM_ID                         (-403)
//#define FUNET_ERROR_INCOMPATIBLE_FEATURES                              (-404)
//#define FUNET_ERROR_CUSTOM_CHECK_FAIL                                  (-405)
//#define FUNET_ERROR_NO_ROM_INFO_FOUND                                  (-406)
//#define FUNET_ERROR_NO_PKG_ROM_INFO_FOUND                              (-407)
//#define FUNET_ERROR_GET_ROMINFO_FAIL                                   (-408)
//#define FUNET_ERROR_NO_PKG_GFH_FILE_INFO_FOUND                         (-409)
//#define FUNET_ERROR_NO_PKG_GFH_MAUI_INFO_FOUND                         (-410)
//#define FUNET_ERROR_NO_ROM_GFH_MAUI_INFO_FOUND                         (-411)
//#define FUNET_ERROR_VERSION_ERROR_END                                  (-499)

//ILB or Update record
//#define FUNET_ERROR_ILB_ERROR_START                                    (-500)
//#define FUNET_ERROR_OUT_OF_ILB_AREA                                    (-501)
//#define FUNET_ERROR_ILB_READ_FAILURE                                   (-502)
//#define FUNET_ERROR_UNEXPECTED_ILB_TYPE                                (-503)
//#define FUNET_ERROR_MULTIPLE_MAIN_ILB                                  (-504)
//#define FUNET_ERROR_MULTIPLE_DLPKG_ILB                                 (-505)
//#define FUNET_ERROR_UNABLE_TO_FIND_DLPKG_ILB                           (-506)
//#define FUNET_ERROR_UNABLE_TO_FIND_MAIN_ILB                            (-507)
//#define FUNET_ERROR_SCAN_ILB_FAIL                                      (-508)
//#define FUNET_ERROR_UNABLE_TO_FIND_CBR_IMAGE_INFO                      (-509)
//#define FUNET_ERROR_UNABLE_TO_FIND_CBR_SPACE_INFO                      (-510)
//#define FUNET_ERROR_FAIL_TO_WRITE_CBR_IMAGE_INFO                       (-511)
//#define FUNET_ERROR_FAIL_TO_WRITE_CBR_SPACE_INFO                       (-512)
//#define FUNET_ERROR_FAIL_TO_ADD_CBR_UPDATING_INFO                      (-513)
#define FUNET_ERROR_FAIL_TO_DEL_CBR_UPDATING_INFO                      (-514)
//#define FUNET_ERROR_FAIL_TO_READ_CBR_UPDATING_INFO                     (-515)
//#define FUNET_ERROR_OTHER_UA_IS_DOING_UPDATE                           (-516)
#define FUNET_ERROR_ERASE_MARKER_BLOCK                                 (-530)
#define FUNET_ERROR_WRITE_MARKER_BLOCK                                 (-531)
//#define FUNET_ERROR_ILB_ERROR_END                                      (-599)

//Updating related
//#define FUNET_ERROR_UPDATE_ERROR_START                                 (-600)
//#define FUNET_ERROR_3RDROM_REMAP_TBL_TOO_SMALL                         (-601)
//#define FUNET_ERROR_OVER_RESERVED_BOUNDARY                             (-602)
//#define FUNET_ERROR_3RDROM_REMAP_TBL_WRITE_FAILURE                     (-603)
//#define FUNET_ERROR_TOO_MANY_BAD_BLOCK                                 (-604)
//#define FUNET_ERROR_CODE_FS_OVERLAPED                                  (-605)
//#define FUNET_ERROR_INVALID_FDM_MAPTBL                                 (-606)
//#define FUNET_ERROR_NO_BLOCK_FOR_CHKREF                                (-607)
//#define FUNET_ERROR_CHKREF_DATA_PREPARE_FAIL                           (-608)
//#define FUNET_ERROR_CHKREF_UPDATE_FAIL                                 (-609)
//#define FUNET_ERROR_CHKREF_IMG_NOT_FOUND                               (-610)
//#define FUNET_ERROR_XIM_IMG_SIZE_EXCEED_MAX_VALUE                      (-611)
//#define FUNET_ERROR_INVALID_XIM_IMG_MAX_BLOCK_NUMBER                   (-612)
//#define FUNET_ERROR_BOOTCERT_EXCEED_BLOCKSIZE                          (-613)
//#define FUNET_ERROR_CODE_FAT_OVERLAPED                                 (-614)
//#define FUNET_ERROR_EARSE_SDS                                          (-615)
//#define FUNET_ERROR_UPDATE_ERROR_END                                   (-699)

//DL PKG adaptation
//#define FUNET_ERROR_PACKAGE_ACCESS_ERROR_START                         (-700)
//#define FUNET_ERROR_NO_CARD_FOUND                                      (-701)
#define FUNET_ERROR_NO_DL_PACKAGE_FOUND                                (-702)
//#define FUNET_ERROR_PACKAGE_SEEK_FAIL                                  (-703)
//#define FUNET_ERROR_PACKAGE_READ_FAIL                                  (-704)
//#define FUNET_ERROR_PACKAGE_ACCESS_ERROR_END                           (-799)

//Flash operation
//#define FUNET_ERROR_FLASH_ERROR_START                                  (-800)
//#define FUNET_ERROR_FLASH_READ                                         (-801)
//#define FUNET_ERROR_FLASH_PROGRAM                                      (-802)
//#define FUNET_ERROR_FLASH_ERASE                                        (-803)
//#define FUNET_ERROR_FLASH_BAD_BLOCK                                    (-804)
//#define FUNET_ERROR_FLASH_CHECK_SUM                                    (-805)
//#define FUNET_ERROR_NFI_UNEXPECED_BEHAVIOR                             (-806)
//#define FUNET_ERROR_FLASH_OTHER_ERROR                                  (-807)
#define FUNET_ERROR_FLASH_INIT_FAIL                                    (-808)
//#define FUNET_ERROR_READ_BRMT_FAIL                                     (-809)
//#define FUNET_ERROR_WRITE_BRMT_FAIL                                    (-810)
//#define FUNET_ERROR_TOO_LARGE_BRMT                                     (-811)
//#define FUNET_ERROR_FLASH_ERROR_END                                    (-899)

//MSDC specific
//#define FUNET_ERROR_MSDC_GET_DISK_GEO                                  (-900)

//FOTA related
//#define FUNET_NO_FOTA_ROM_INFO                                         (-1000)
//#define FUNET_NO_FOTA_RESERVOIR                                        (-1001)



extern FUNET_ERROR_CODE GPS_FW_TriggerDL(WCHAR * filename);
#endif /* __FUNET_ENABLE__ */

#endif /* _FUNET_H_ */