/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   Capacitive_TP_Goodix_GT818.h
 *
 *
 * Description:
 * ------------
 *   Capacitive Touch Panel I2C read/write Driver header file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __CAPACITIVE_TP_GOODIX_GT9XX_H__
#define __CAPACITIVE_TP_GOODIX_GT9XX_H__

#define __CTP_GOODIX_GT9XX_TRUE_MULTIPLE__


#define CTP_SLAVE_ADDR            0xBA
#define CTP_POWER_MODE_REG        0x8040

#define CTP_FW_HEADER_SIZE                0

#define CTP_VERSION_INFO_REG              0x8140
//#define CTP_MASTER_RESET_REG              0x4180
//#define CTP_MASTER_STATUS_REG             0x6088
#define CTP_MASTER_CODE_REG               0xC000
//#define CTP_DSP_ISP_BOOT_CODE_REG         0x9000
//#define CTP_SRAM_BAND_REG                 0x4048
#define CTP_FIRMWARE_SIZE                 (0x8000+CTP_FW_HEADER_SIZE)
//#define CTP_DSP_FIRMWARE_SIZE             (0x1000+CTP_FW_HEADER_SIZE)
//#define CTP_BAND_SIZE                     0x4000
//#define CTP_SS51_DOWNLOAD_SIZE            0x2000
//#define CTP_DSP_ISP_DOWNLOAD_SIZE         0x1000
//#define CTP_DSP_DOWNLOAD_SIZE             0x1000
//#define CTP_BOOTCODE_DOWNLOAD_SIZE        0x800
#define CTP_TOUCH_INFO_REG_BASE           0x814E
#define CTP_POINT_INFO_REG_BASE           0x814F
//#define CTP_DIFF_DATA_REG                 0xBB10
//#define CTP_RAW_DATA_REG                  0x8B98
//#define CTP_FLASH_RUN_REG                 0x4283
#define CTP_CONFIG_REG_BASE               0x8047
//#define CTP_BUFFER_STATUS_SHIFT           7
#define CTP_FIRMWARE_VERSION              0x8147
#define CTP_NVRAM_I2C_ADDRESS             0x5094
#define CTP_NVRAM_OPERATION_SIZE          0x5096
#define CTP_NVRAM_FILE_OFFSET             0x4196
#define CTP_NVRAM_OPERATION_CHECKSUM      0x4194
#define CTP_FLASH_POWER_OFF               0x4284

#define CTP_SRAM_BANK                     0x4048
#define CTP_MEM_CD_EN                     0x4049
#define CTP_CACHE_EN                      0x404B
#define CTP_TMR0_EN                       0x40B0
#define CTP_SWRST_B0_                     0x4180
#define CTP_CPU_SWRST_PULSE               0x4184
#define CTP_BOOTCTL_B0_                   0x4190
#define CTP_BOOT_OPT_B0_                  0x4218
#define CTP_BOOT_CTL_                     0x5094//0x4283
#define CTP_ANA_RXADC_B0_                 0x4250
#define CTP_RG_LDO_A18_PWD                0x426f
#define CTP_RG_BG_PWD                     0x426a
#define CTP_RG_CLKGEN_PWD                 0x4269
#define CTP_RG_DMY                        0x4282
#define CTP_RG_OSC_CALIB                  0x4268
#define CTP_OSC_CK_SEL                    0x4030

#define CTP_HANDSHAKING_START_REG 0xFFF
#define CTP_HANDSHAKING_END_REG   0x8000
#define CTP_SOFT_RESET_MODE       0x01
#define CTP_POINT_INFO_LEN        8
#define TPD_MAX_POINTS            5
#define MAX_TRANSACTION_LENGTH    8
#define I2C_DEVICE_ADDRESS_LEN    2
extern const char gpio_ctp_eint_pin;
extern const char gpio_ctp_reset_pin;

#define TPD_PROXIMITY_WORK_REG_BASE   0x920
#define TPD_PROXIMITY_SAMPLE_REG      0xA88
#define TPD_PROXIMITY_BASE_REG        0xAD8
#define TPD_LARGE_OBJECT_DETECT_REG   0x71D

#define _FW_TOTAL_PAGES                   32
#define _FW_FRAME_PAGES	                  16
#define _DSP_TOTAL_PAGES                  4 // CCH modified
#define _BOOTCODE_TOTAL_PAGES             32
#define _FW_FRAME_BYTES	                  (_FW_FRAME_PAGES*1024)
#define _DSP_TOTAL_BYTES                  (_DSP_TOTAL_PAGES*1024)
#define _BOOTCODE_TOTAL_BYTES             (_BOOTCODE_TOTAL_PAGES*1024)

#define CTP_STAT_NUMBER_TOUCH     0xF
#define GPIO_CTP_INT_PIN          gpio_ctp_eint_pin
#define GPIO_CTP_SHUTDN_PIN       gpio_ctp_reset_pin
#define GPIO_CTP_EINT_NO          4
#define CONFIG_LEN (186)

//hotknot
#define GTP_COMPATIBLE_MODE  0	//not use in FLASH series
#ifdef __HOTKNOT_SUPPORT__
#define GTP_HOTKNOT_MODULE   1	//for HOTKNOT feature
#else
#define GTP_HOTKNOT_MODULE   0	//for HOTKNOT feature
#endif
#define GTP_AUTO_UPDATE_HOTKNOT   0	//for HOTKNOT update firmware in FS
#define GTP_DEBUG_ARRAY_ON 1
#define GTP_SUPPORT_I2C_DMA 1



#define GTP_DEBUG_ON         1

#define REG_2ND_CMD         0x8040
#define REG_1ST_CMD         0x8046
#define REG_LINK_MODE       0x81A8
#define REG_PAIR_FLAG       0x81AA
#define REG_XFE_STATE       0xAB10
#define REG_NOTIFY_STATE    0xAB1F
#define REG_SNDBUF_START    0xAC90
#define REG_DATA_FRESH      0xAD91
#define REG_RCVBUF_STATE    0xAE10
#define REG_RCVBUF_START    0xAE12

#define CMD_ENTER_SLAVE     0x20
#define CMD_ENTER_MASTER    0x21
#define CMD_ENTER_TRANSFER  0x22
#define CMD_EXIT_SLAVE      0x28
#define CMD_EXIT_MASTER     0x29
#define CMD_EXIT_TRANSFER   0x2A

#define MODE_TOUCH_ONLY     0x00
#define MODE_PAIRED         0X55
#define MODE_SLAVE          0x88
#define MODE_MASTER         0x99
#define MODE_SEND           0xAA
#define MODE_RECEIVE        0xBB

typedef enum
{
	CHIP_TYPE_GT9 = 0,
	CHIP_TYPE_GT9F = 1,
}CHIP_TYPE_T;





//end
typedef struct 
{
    kal_uint8 vendor_id_1;
    kal_uint8 vendor_id_2;
    kal_uint8 product_id_1;
    kal_uint8 product_id_2;
    kal_uint8 version_1;
    kal_uint8 version_2;
} ctp_info_t;

extern kal_bool ctp_i2c_receive_ext(kal_uint8 ucDeviceAddr, kal_uint16 ucBufferIndex, kal_uint8* pucData, kal_uint32 unDataLength);
extern kal_bool ctp_i2c_send(kal_uint8 ucDeviceAddr, kal_uint8 ucBufferIndex, kal_uint8* pucData, kal_uint32 unDataLength);

#define CTP_I2C_read(a,b,c) ctp_i2c_receive_ext( CTP_SLAVE_ADDR, a, b, c)
#define CTP_I2C_send(a,b,c) ctp_i2c_send_ext( CTP_SLAVE_ADDR, a, b, c)

//kal_bool MSDC_Check_Card_Mount(void);

#endif
