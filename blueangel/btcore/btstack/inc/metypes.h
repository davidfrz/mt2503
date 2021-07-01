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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * smi.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * Low Energy Security Manager Protocol internal header
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/
#ifndef __METYPES_H
#define __METYPES_H

/* Forward declaration of the callback parameters */
typedef struct _BtEvent BtEvent;

typedef struct _BtDeviceContext BtDeviceContext;

/*---------------------------------------------------------------------------
 * BtCallBack type
 *
 *     A function of this type is called to indicate general Bluetooth and
 *     ME events.
 */
typedef void (*BtCallBack)(const BtEvent *);

/* End of BtCallBack */

/*---------------------------------------------------------------------------
 *
 * BtOpEvent defines events for the operation state machine.
 */
typedef U8 BtOpEvent;

#define BOE_NOP        0x00     /* No operation */
#define BOE_START      0x01     /* Start of operation */
#define BOE_CONT       0x02     /* Continue the operation */
#define BOE_TASK_END   0x03     /* Task finished successfully */
#define BOE_TASK_ERR   0x04     /* Task ended because of an error */

typedef U8 BtOpType;

/*---------------------------------------------------------------------------
 *
 * BtOpType defines Bluetooth operations.
 */
#define BOP_NOP               0x00      /* No operation */
#define BOP_INQUIRY           0x01      /* Inquiry operation */
#define BOP_CANCEL_INQ        0x02      /* Cancel Inquiry operation */
#define BOP_INQUIRY_SCAN      0x03      /* Change discoverability mode */
#define BOP_PAGE_SCAN         0x04      /* Change connectability mode */
#define BOP_LINK_CONNECT      0x05      /* Initiate a link connection */
#define BOP_LINK_ACCEPT       0x06      /* Accept an incoming link */
#define BOP_LINK_REJECT       0x07      /* Reject an incoming link */
#define BOP_LINK_DISCONNECT   0x08      /* Disconnet a link */
#define BOP_AUTHENTICATE      0x09      /* Authenticate the link */
#define BOP_LINK_KEY_RSP      0x0a      /* Respond to link key request */
#define BOP_PIN_CODE_RSP      0x0b      /* Respond to pin code request */
#define BOP_AUTHORIZE         0x0c      /* Authorization  operation */
#define BOP_ENCRYPTION        0x0d      /* Encryption operation */
#define BOP_SECURITY_MODE     0x0e      /* Set security mode operation */
#define BOP_ACCESS_MODE       0x0f      /* Change accessability mode operation */
#define BOP_CANCEL_INQUIRY    0x10      /* Cancel inquiry operation */
#define BOP_REM_NAME_REQ      0x11      /* Remote name request operation */
#define BOP_LOCAL_NAME_CHG    0x12      /* Local name change */

/*
 * Mode change operations must be continguous with no other operations
 * between. Hold must be first and exit park mode must be last.
 */
#define BOP_HOLD_MODE         0x13      /* Hold mode operation */
#define BOP_SNIFF_MODE        0x14      /* Enter sniff mode operation */
#define BOP_EXIT_SNIFF_MODE   0x15      /* Exit sniff mode */
#define BOP_PARK_MODE         0x16      /* Enter park mode */
#define BOP_EXIT_PARK_MODE    0x17      /* Exit park mode */
/* end of mode change operations */

#define BOP_SWITCH_ROLE       0x18
#define BOP_WRITE_COD         0x19      /* Write class of device */
#define BOP_GEN_COMMAND       0x1a      /* General command */
#define BOP_SCO_CONNECT       0x1b      /* Initiate a SCO link connection */
#define BOP_SCO_ACCEPT        0x1c      /* Accept an incoming link */
#define BOP_SCO_REJECT        0x1d      /* Reject an incoming link */
#define BOP_SCO_DISCONNECT    0x1e      /* Disconnet a link */
#define BOP_LINK_IN_REJECT    0x1f      /* Internal link reject */
#define BOP_SCO_VOICESET      0x20      /* Set SCO voice parameters */
#define BOP_WRITE_LINK_POLICY 0x21      /* Set link policy */
#define BOP_READ_BDADDR       0x22      /* Read local BD_ADDR */
#define BOP_WRITE_DEF_LNK_POL 0x23      /* Set default link policy */
#define BOP_SCO_SETUP         0x24      /* Initiate an SCO link setup (BT v1.2) */
#define BOP_CANCEL_CONNECT    0x25      /* Cancel a link connection */
#define BOP_CANCEL_REM_NAME   0x26      /* Cancel a remote name request */
#define BOP_CHANNEL_CLASS     0x27      /* Set channel classification for AFH */
#define BOP_DISCOVER_ROLE     0x28      /* Discover Role */
#define BOP_CANCEL_AUTHORIZE  0x29      /* Cancel Authorization request */
#define BOP_INQUIRY_TX_PWR           0x2a      /* Inquiry tx power operation */

#define BOP_PIN_CODE_BY_ADDR_RSP    0x30
#define BOP_CHANGE_PACKET_TYPE      0x31
#define BOP_DISABLE_AFH                     0x33
#define BOP_READ_REMOTE_FEATURE     0x34

#define BOP_SET_HCI_EVENT_MASK      0x35
#define BOP_WRITE_SUPERVISION_TIMEOUT     0x36
#define BOP_WRITE_LOCAL_LOOPBACK     0x37

#define BOP_READ_REMOTE_VERSION 0x38
#define BOP_READ_RSSI 0x39

#define BOP_WRITE_AUTOMATICALLY_FLUSHED_TIMEOUT 0x3A
#define BOP_SNIFF_SUBRATING_MODE        0x3B    /* Enter sniff subrating mode operation */
#define BOP_EXTENDED_INQUIRY_RESPONSE   0x3C

#define BOP_WRITE_IO_CAPABILITY_RESPONSE    0x3D
#define BOP_USER_CONFIRM_BT_ADDR_RSP        0x3E
#define BOP_STOP_ENCRYPTION        0x3F /* Encryption operation */

#define BOP_DELETE_STORED_LINK_KEY 0x40
#define BOP_WRITE_SCAN_MODE        0x41
#define BOP_WRITE_IAC_VALUE        0x42
#define BOP_START_AUTHENTICATION_CHIP        0x43
#define BOP_START_ENCRYPTION_CHIP        0x44

#define BOP_WRITE_AFH               0x45
#define BOP_WRITE_PTA1               0x46
#define BOP_WRITE_PTA2               0x47
#define BOP_WRITE_PTAINFO           0x48
#define BOP_WRITE_UART_SEND_SPEED   0x49
#define BOP_WRITE_MT66XX_FLOW_CONTROL_ENABLED  0x4A
#define BOP_READ_SEQUENCE           0x4B    //20090805, Add by Posh
#define BOP_READ_WIFI_RSSI          0x4C
#define BOP_SET_RX_RANGE            0x4D
#define BOP_SET_TX_DEFAULT_POWER      0x4E
#define BOP_SET_TX_UPDATE_POWER        0x4F

#define BOP_SET_DUAL_PCM_SETTING       0x50
#define BOP_SET_DUAL_PCM_SWITCH        0x51
#define BOP_WRITE_SSP_DEBUG            0x52
#define BOP_WRITE_ENABLE_FM_OVER_SBC    0x53
#define BOP_WRITE_DISABLE_FM_OVER_SBC   0x54
#define BOP_READ_REMOTE_CLOCK_OFFSET 0x55
#define BOP_READ_REMOTE_EXT_FEATURE 0x56

#define BOP_CREATE_PHYSICAL_LINK        0x60
#define BOP_ACCEPT_PHYSICAL_LINK        0x61
#define BOP_DISCONNECT_PHYSICAL_LINK    0x62
#define BOP_CREATE_LOGICAL_LINK         0x63
#define BOP_ACCEPT_LOGICAL_LINK         0x64
#define BOP_DISCONNECT_LOGICAL_LINK     0x65
#define BOP_LOGICAL_LINK_CANCEL         0x66
#define BOP_FLOW_SPEC_MODIFY            0x67
#define BOP_READ_LOCAL_AMP_INFO         0x68
#define BOP_READ_LOCAL_AMP_ASSOC        0x69
#define BOP_WRITE_REMOTE_AMP_ASSOC      0x6A
#define BOP_READ_DATA_BLOCK_SIZE        0x6B
#define BOP_READ_TX_POWER               0x6C
#define BOP_USER_OOB_DATA_RSP           0x6D
#define BOP_QOS_SETUP                   0x6E

#define BOP_LE 0x70
#define BOP_LE_SET_SCAN_PARM            0x71
#define BOP_LE_SET_SCAN_ENABLED         0x72

#define BOP_TEST_MODE 0x80
#define BOP_TEST_HCI  0x81

#ifdef __ANTI_LOST_FEATURE__
#define BOP_LOW_POWER_PRXM_ENABLE       0x81
#endif

#ifdef __A2DP_MULTI_LINK_FEATURE__
#define BOP_READ_REMOTE_CLOCK_OFFSET_EXT 0x82
#endif

 //3DS_PROFILE
#if defined(__BT_3DS_PROFILE__)
#define CSB_MAX_DATA_LEN 17
#define CSB_DATA_NO_FRAGMENTATION 0x03
#define CSB_DATA_NO_ENDING_FRAGMENT 0x02
#define CSB_DATA_NO_STARTING_FRAGMENT 0x01
#define CSB_DATA_NO_CINTINUATION_FRAGMENTATION 0x00

#define BOP_SET_TRIGGERED_CLOCK_CAPTURE 0x90
#define BOP_SET_CONNECTIONLESS_SLAVE_BROADCAST_DATA 0x91
#define BOP_SET_CONNECTIONLESS_SLAVE_BROADCAST 0x92
#define BOP_WRITE_SYNCHRONIZATION_TRAIN_PARAMETERS 0x93
#define BOP_START_SYNCHRONIZATION_TRAIN 0x94
#define BOP_SET_RESERVED_LTADDR 0x95
#define BOP_DELETE_RESERVED_LTADDR 0x96
#endif

#if defined (__BT_41_SECURE_CONNECTION__)
#define BOP_BT_WRITE_AUTHENTICATED_PAYLOAD_TIMEOUT              0x97
#endif

#ifdef __BT_WOBLE__
#define BOP_UPDATE_WAKEUP_DEV                   0x98
#endif

#ifdef __ANDROID_L_MIGRATION__
#define BOP_SET_RPA_LIST 0xA0      /* Add or remove RPA device */
#endif

#define BOP_BUSY              0xfe      /* Indicate op queue is busy */

typedef struct _BtOperation
{
    ListEntry node;
    BtOpType opType;
} BtOperation;


#endif  /* __METYPES_H */
