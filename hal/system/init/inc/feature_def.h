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
 *   feature_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Feature combination definition
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

#ifndef _FEATURE_DEF_H_
#define _FEATURE_DEF_H_

/* Features that will be referred by bootloader and FlashTool */
#define   MAUI_FC_NONE                0x0000
#define   MAUI_FC_SECURE              0x0001 
#define   MAUI_FC_FOTA                0x0002
#define   MAUI_FC_NOR_FLASH_BOOTING   0x0004
#define   MAUI_FC_USBDL               0x0008
#define   MAUI_FC_SW_ROOT_KEY_IN_BL   0x0010
#define   MAUI_FC_MBA                 0x0020
#define   MAUI_FC_SYSDRV_ON_NAND      0x0040
#define   MAUI_FC_SECURE_RO           0x0080
#define   MAUI_FC_USBDL_IN_BOOTROM    0x0100
#define   MAUI_FC_EXT_BL_UPDATE       0x0200
#define   MAUI_FC_SPLIT_BIN_SUPPORT   0x0400
#define   MAUI_FC_FAST_LOGO           0x0800
#define   MAUI_FC_XIP_SHADOWING       0x1000


//Define feature combination flag
#ifdef __MTK_SECURE_PLATFORM__
/* under construction !*/
#else
#define SECURE_SWITCH                 0
#endif

#ifdef __FOTA_DM__
#define FOTA_SWITCH                   MAUI_FC_FOTA
#else
#define FOTA_SWITCH                   0
#endif

#ifdef __NOR_FLASH_BOOTING__
#define NOR_FLASH_BOOTING_SWITCH      MAUI_FC_NOR_FLASH_BOOTING
#else
#define NOR_FLASH_BOOTING_SWITCH      0
#endif

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)
#define USBDL_SWITCH                  MAUI_FC_USBDL
#else
#define USBDL_SWITCH                  0
#endif

#ifdef __MULTIPLE_BINARY_FILES__
#define MBA_SWITCH                    MAUI_FC_MBA
#else
#define MBA_SWITCH                    0
#endif

#if defined(__BIND_TO_CHIP__) || defined(__BIND_TO_KEY__)
#define SW_ROOT_KEY_IN_BL_SWITCH      MAUI_FC_SW_ROOT_KEY_IN_BL
#else
#define SW_ROOT_KEY_IN_BL_SWITCH      0
#endif

#if defined (__FS_SYSDRV_ON_NAND__) && !defined (_NAND_FLASH_BOOTING_)
#define SYSDRV_ON_NAND_SWITCH         MAUI_FC_SYSDRV_ON_NAND
#else
#define SYSDRV_ON_NAND_SWITCH         0
#endif

#ifdef __SECURE_RO_ENABLE__
#define SECURE_RO_ENABLE_SWITCH       MAUI_FC_SECURE_RO
#else
#define SECURE_RO_ENABLE_SWITCH       0
#endif

#ifdef __USBDL_IN_BOOTROM__
#define USBDL_IN_BOOTROM_SWITCH       MAUI_FC_USBDL_IN_BOOTROM
#else
#define USBDL_IN_BOOTROM_SWITCH       0
#endif

#ifdef __EXT_BL_UPDATE__
#define EXT_BL_UPDATE_SWITCH          MAUI_FC_EXT_BL_UPDATE
#else
#define EXT_BL_UPDATE_SWITCH          0
#endif

#ifdef __SPLIT_BINARY__
#define SPLIT_BIN_SUPPORT_SWITCH      MAUI_FC_SPLIT_BIN_SUPPORT
#else
#define SPLIT_BIN_SUPPORT_SWITCH      0
#endif

#ifdef __FAST_LOGO__
#define FAST_LOGO_SWITCH              MAUI_FC_FAST_LOGO
#else
#define FAST_LOGO_SWITCH              0
#endif

#ifdef __XIP_SHADOWING__
#define XIP_SHADOWING_SWITCH          MAUI_FC_XIP_SHADOWING
#else
#define XIP_SHADOWING_SWITCH          0
#endif

#define FEATURE_COMBINATION           (SECURE_SWITCH | FOTA_SWITCH | NOR_FLASH_BOOTING_SWITCH | USBDL_SWITCH | \
                                       SW_ROOT_KEY_IN_BL_SWITCH | MBA_SWITCH | SYSDRV_ON_NAND_SWITCH | \
                                       SECURE_RO_ENABLE_SWITCH | USBDL_IN_BOOTROM_SWITCH | EXT_BL_UPDATE_SWITCH | \
                                       SPLIT_BIN_SUPPORT_SWITCH | FAST_LOGO_SWITCH | XIP_SHADOWING_SWITCH)

#define FEATURE_COMBINATINO_EX        (0)
                    
                    
#define MIN_FLASHTOOL_VER_REQURIEMENT (0x00000001)

#endif /* _FEATURE_DEF_H_ */

