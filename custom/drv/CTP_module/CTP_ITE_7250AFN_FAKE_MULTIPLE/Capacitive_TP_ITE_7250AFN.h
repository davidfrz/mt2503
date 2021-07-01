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
 *   Capacitive_TP_Cypress_CY8CTMA340.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "Capacitive_TP_I2C.h"

//Controller parameter getting/setting flag
#define CTP_SLAVE_ADDR		0x8C

#define MAX_FINGER_NUM		2

#define COMMAND_BUFFER_INDEX          0x20
#define QUERY_BUFFER_INDEX            0x80
#define COMMAND_RESPONSE_BUFFER_INDEX 0xA0
#define SYSTEM_COMMAND_RESPONSE_INDEX 0xC0
#define POINT_BUFFER_INDEX            0xE0

#define POINT_DATA_SIZE 64

#define QUERY_BUFFER_NEW_POINT_INFO 0x80
#define POINT_BUFFER_FORMAT_MASK    0xF0
#define POINT_BUFFER_FORMAT_POINT   0x00
#define POINT_BUFFER_FORMAT_GESTURE 0x80

#define POINT_BUFFER_POINT_INFO_MASK   0x07
#define POINT_BUFFER_POINT_OFFSET   0x00
#define POINT_BUFFER_POINT_INFO_0   0x01
#define POINT_BUFFER_POINT_INFO_1   0x02
#define POINT_BUFFER_POINT_INFO_2   0x04

#define POINT_BUFFER_X0_LSB_OFFSET 0x02
#define POINT_BUFFER_X0_MSB_OFFSET 0x03
#define POINT_BUFFER_Y0_LSB_OFFSET 0x04
#define POINT_BUFFER_Y0_MSB_OFFSET 0x03
#define POINT_BUFFER_Z0_OFFSET     0x05

#define POINT_BUFFER_X1_LSB_OFFSET 0x06
#define POINT_BUFFER_X1_MSB_OFFSET 0x07
#define POINT_BUFFER_Y1_LSB_OFFSET 0x08
#define POINT_BUFFER_Y1_MSB_OFFSET 0x07
#define POINT_BUFFER_Z1_OFFSET     0x09

#define POINT_BUFFER_X2_LSB_OFFSET 0x0A
#define POINT_BUFFER_X2_MSB_OFFSET 0x0B
#define POINT_BUFFER_Y2_LSB_OFFSET 0x0C
#define POINT_BUFFER_Y2_MSB_OFFSET 0x0B
#define POINT_BUFFER_Z2_OFFSET     0x0D

#define POINT_BUFFER_X_MSB_MASK   0x0F
#define POINT_BUFFER_X_MSB_SHIFT  0x08 //shift << 8
#define POINT_BUFFER_Y_MSB_MASK   0xF0
#define POINT_BUFFER_Y_MSB_SHIFT  0x04 //shift << 4
#define POINT_BUFFER_Z_MASK       0xF

#define COMMAND_IDENTIFY_SENSOR     0x0
#define COMMAND_INQUIRY_SENSOR      0x1
#define COMMAND_SET_POWER_MODE      0x4
#define COMMAND_RESET_QUEUE         0x7
#define COMMAND_ENTER_FW_UPGRADE    0x0
#define COMMAND_EXIT_FW_UPGRADE     0x80
#define COMMAND_FW_UPGRADE_MODE     0x60
#define COMMAND_SET_FW_OFFSET       0x9
#define COMMAND_WRITE_FLASH         0xA
#define COMMAND_READ_FLASH          0xB
#define COMMAND_REINIT_FW           0xC
#define COMMAND_WRITE_MEMORY        0xD
#define COMMAND_WRITE_REGISTER      0xE0
#define COMMAND_READ_MEMORY         0xE
#define COMMAND_READ_REGISTER       0xE1
#define COMMAND_IDLE_SLEEP_MODE     0x11
#define COMMAND_SET_TIME_INTERVAL   0x12
#define COMMAND_MP_CALIBRATION      0x13
#define COMMAND_SET_POINT_THRESHOLD 0x15

#define COMMAND_DATA_TYPE_BYTE   0x1
#define COMMAND_DATA_TYPE_WORD   0x2
#define COMMAND_DATA_TYPE_DWORD  0x4

#define COMMAND_POWER_SLEEP_MODE 0x2

#define FW_UPDATE_START  0xF1
#define FW_UPDATE_ERROR  0x2F
#define FW_UPDATE_FINISH 0x87

#define CTP_I2C_WRITE(reg, data)\
{\
	ctp_i2c_send(CTP_SLAVE_ADDR, reg, &data, 1);\
}

#define CTP_I2C_MULTI_WRITE(data, len)\
{\
	ctp_i2c_send(CTP_SLAVE_ADDR, *data, data+1, len-1);\
}

#define CTP_I2C_READ(reg, data, len)\
{\
	ctp_i2c_receive(CTP_SLAVE_ADDR, reg, data, len);\
}



typedef struct
{   
   kal_uint32 mode;
}CTP_device_mode_struct;

typedef struct
{   
	kal_uint32 start_offset;
	kal_uint32 write_flash_pointer;
	kal_uint32 read_flash_pointer;
	kal_uint32 value;
}CTP_firmware_struct;

