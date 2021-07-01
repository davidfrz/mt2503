/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef __HCI_H
#define __HCI_H

/****************************************************************************
 *
 * File:
 *     $Workfile:hci.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #1 $
 *
 * Description:
 *     This file contains the upper layer API for the Host Controller 
 *     Interface driver.
 *
 * Copyright 1999-2005 Extended Systems, Inc.
 * Portions copyright 2005 iAnywhere Solutions, Inc.
 * All rights reserved. All unpublished rights reserved.
 *
 * Unpublished Confidential Information of iAnywhere Solutions, Inc.  
 * Do Not Disclose.
 *
 * No part of this work may be used or reproduced in any form or by any 
 * means, or stored in a database or retrieval system, without prior written 
 * permission of iAnywhere Solutions, Inc.
 * 
 * Use of this work is governed by a license granted by iAnywhere Solutions,
 * Inc.  This work contains confidential and proprietary information of
 * iAnywhere Solutions, Inc. which is protected by copyright, trade secret,
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/

#include "bttypes.h"
#include "bt_feature.h"

/*---------------------------------------------------------------------------
 * Host Controller Interface (HCI) layer
 *
 *     In a typical Bluetooth implementation, the "Host" system communicates
 *     with its Bluetooth "Host Controller" using the Host Controller
 *     Interface (HCI). This interface provides a standardized way to
 *     control Bluetooth operations like inquiry, connection establishment,
 *     piconet management, and data exchange.
 *
 *     The "Host Controller" receives HCI commands from the host. Internally,
 *     it uses the Link Manager and Baseband protocols to carry out the
 *     commands, and generates events in response to the host. The HCI
 *     also allows the exchange of ACL and SCO data.
 *
 *     The HCI layer uses an HCI Transport Driver to exchange commands,
 *     events, and data with the Host Controller. The Transport Driver
 *     is specific to the transport used, such as UART, RS232, or USB.
 */

/****************************************************************************
 *
 * Constants
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * HCI_NUM_HANDLES constant
 *
 *     Total number of HCI handles that HCI will be required to manage.
 *     This is equal to the number of ACL and SCO links allowed, plus
 *     two more for L2CAP broadcast handles.
 *     
 */
#define HCI_NUM_HANDLES (NUM_BT_DEVICES + NUM_SCO_CONNS + 2)
#define HCI_NUM_AMP_HANDLES (12)

/****************************************************************************
 *
 * Types
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * HciCallbackEvent type
 *
 *     These events are passed up to the Management Entity in the
 *     ME_Callback() function. The callback parameters (in HciCallbackParms)
 *     contain a union of different pointer types that are used depending
 *     on the event received.
 */
typedef U8 HciCallbackEvent;

/*
 * An event was received from the host controller. Events occur in response
 * to commands sent by the host, although several events can be received
 * for a single command.
 *
 * The "hciEvent" callback parameter contains the data associated with the
 * command. The "status" field will always indicate success, and the
 * "hciHandle" field is not used.
 */
#define HCI_CONTROLLER_EVENT 1

/*
 * Either SCO or ACL data was received from another device. This data can
 * be found in the "rxBuff" field. The type of data (ACL or SCO)
 * is identified in the rxBuff->flags field. The "hciHandle" field will also
 * be set with the ACL or SCO connection handle. The "status" field will
 * always indicate success.
 */
#define HCI_DATA_IND         2

/*
 * A transmitted ACL or SCO packet is free to be re-used by
 * higher layers. The returned packet is identified in the "packet" field,
 * and the "hciHandle" field indicates the connection on which the packet
 * was sent.
 *
 * If the "status" field indicates success, the packet was successfully sent
 * to the host controller, but the remote device might not have received
 * the data yet.
 *
 * If the "status" field indicates failure, the packet was not sent
 * successfully due to link disconnection or a transport error.
 */
#define HCI_PACKET_HANDLED   3

/*
 * A transmitted command is free to be re-used by higher layers.
 * The returned command is identified in the "cmd" field. The
 * "hciHandle" field is not used.
 *
 * If the "status" field indicates success, the command was successfully
 * transmitted to the host controller. One or more events will follow
 * in response.
 *
 * If the "status" field indicates failure, the command could not be
 * sent due to a transport error.
 */
#define HCI_COMMAND_HANDLED  4

/*
 * The HCI layer is ready for SCO or ACL transmit data. This event is
 * generated sometime after HCI_RequestToSend() is called by a higher layer.
 * The "status" field always indicates success.
 *
 * The "hciHandle" field contains the handle of the connection. During
 * the callback, data for this connection should be stored in the
 * "packet" field. The HCI layer will continue to generate this event
 * until the "packet" field is set to NULL.
 */
#define HCI_SEND_IND         5

/*
 * HCI initialization state has changed. The "status" field indicates whether
 * initialization succeeded or failed.   If "status" is BT_STATUS_FAILED, 
 * synchronization with the radio will be retried BT_HCI_NUM_INIT_RETRIES times.
 * If "status" is BT_STATUS_HCI_INIT_ERR, no more retries will be made.
 * All other callback fields are not used.
 */
#define HCI_INIT_STATUS      6

/*
 * HCI deinitialization is complete. The "status" field indicates whether
 * deinitialization completed gracefully  or not (succeeded or failed). All other 
 * callback fields are not used.
 */
#define HCI_DEINIT_STATUS    7

/*
 * An HCI transport error occured.  This can be the result of an error in the
 * the transport, or an error generated by the Bluetooth radio.
 */
#define HCI_TRANSPORT_ERROR  8

/* Event for bluetooth logo testing */
#define HCI_BLUETOOTH_LOGO   9

/* Vendor specific event (debugging) */
#define HCI_VENDOR_SPECIFIC  10

#define HCI_META_PKT_SENT_OUT 11

#define HCI_SEND_IND_AMP      12

/* End of HciCallbackEvent */

typedef enum
{
    MTK_FEATURE_FM_OVER_CONTROLLER = 0,
    MTK_FEATURE_MERGE_INTERFACE    = 1,
    MTK_FEATURE_UNIFY_IP           = 2,
    NUM_OF_MTK_FEATURE,
}MTKSupportFeature;

 //3DS_PROFILE
#if defined(__BT_3DS_PROFILE__) 
#define HCM01_TRIGGERED_CLOCK_CAPTURE	0x40
#define HCM01_SYN_TRAIN_COMPLETE			0x80
#define HCM02_CSB_TIMEOUT					0x04	
#define HCM02_SLAVE_PAGE_RESP_TIMEOUT     0x10
#define HCM02_INQ_RSP_NOTIFICATION		0x40
#endif

#ifdef __ANDROID_L_MIGRATION__
//RPA
#define HCI_OGF_VENDOR_SPECIFIC	(0x3F << 10) //0xFC00
#define HCI_SUB_OCF_VEND_Offloaded_RPA_ENABLE		(0x01)
#define HCI_SUB_OCF_VEND_Offloaded_RPA_ADD_IRK		(0x02)
#define HCI_SUB_OCF_VEND_Offloaded_RPA_REMOVE_IRK	(0x03)
#define HCI_SUB_OCF_VEND_Offloaded_RPA_CLEAR_IRK		(0x04)
#define HCI_SUB_OCF_VEND_Offloaded_RPA_READ_IRK		(0x05)
//RPA end
#endif

/*---------------------------------------------------------------------------
 * HciCommandType type
 *
 *     Commands are indicated to the HCI layer when calling
 *     HCI_SendCommand. A command type from the list below is specified
 *     in the "opCode" parameter to this function. Additional
 *     command-specific information is provided in the "cmd" parameter.
 */
typedef enum
{
/* Group: Link control commands */
    HCC_INQUIRY                      = 0x0401,
    HCC_INQUIRY_CANCEL               = 0x0402,
    HCC_START_PERIODIC_INQ_MODE      = 0x0403,
    HCC_EXIT_PERIODIC_INQ_MODE       = 0x0404,
    HCC_CREATE_CONNECTION            = 0x0405,
    HCC_DISCONNECT                   = 0x0406,
    HCC_ADD_SCO_CONNECTION           = 0x0407, /* Not in 1.2 */
    HCC_CREATE_CONNECTION_CANCEL     = 0x0408, /* 1.2 */
    HCC_ACCEPT_CON_REQ               = 0x0409,
    HCC_REJECT_CON_REQ               = 0x040A,
    HCC_LINK_KEY_REQ_REPL            = 0x040B,
    HCC_LINK_KEY_REQ_NEG_REPL        = 0x040C,
    HCC_PIN_CODE_REQ_REPL            = 0x040D,
    HCC_PIN_CODE_REQ_NEG_REPL        = 0x040E,
    HCC_CHNG_CONN_PACKET_TYPE        = 0x040F,
    HCC_AUTH_REQ                     = 0x0411,
    HCC_SET_CONN_ENCRYPT             = 0x0413,
    HCC_CHNG_CONN_LINK_KEY           = 0x0415,
    HCC_MASTER_LINK_KEY              = 0x0417,
    HCC_REM_NAME_REQ                 = 0x0419,
    HCC_REM_NAME_REQ_CANCEL          = 0x041A, /* 1.2 */
    HCC_READ_REMOTE_FEATURES         = 0x041B,
    HCC_READ_REMOTE_EXT_FEATURES     = 0x041C, /* 1.2 */
    HCC_READ_REMOTE_VERSION          = 0x041D,
    HCC_READ_CLOCK_OFFSET            = 0x041F,
    HCC_READ_LMP_HANDLE              = 0x0420, /* 1.2 */
    HCC_EXCHANGE_FIXED_INFO          = 0x0421, /* 1.2 */
    HCC_EXCHANGE_ALIAS_INFO          = 0x0422, /* 1.2 */
    HCC_PRIVATE_PAIRING_REQ_REPL     = 0x0423, /* 1.2 */
    HCC_PRIVATE_PAIRING_REQ_NEG_REPL = 0x0424, /* 1.2 */
    HCC_GENERATED_ALIAS              = 0x0425, /* 1.2 */
    HCC_ALIAS_ADDRESS_REQ_REPL       = 0x0426, /* 1.2 */
    HCC_ALIAS_ADDRESS_REQ_NEG_REPL   = 0x0427, /* 1.2 */
    HCC_SETUP_SYNC_CONNECTION        = 0x0428, /* 1.2 */
    HCC_ACCEPT_SYNC_CON_REQ          = 0x0429, /* 1.2 */
    HCC_REJECT_SYNC_CON_REQ          = 0x042A, /* 1.2 */
    HCC_IO_CAPABILITY_REPL           = 0x042B, /* 2.1 */
    HCC_USER_CONFIRM_REPL            = 0x042C, /* 2.1 */
    HCC_USER_CONFIRM_NEG_REPL        = 0x042D, /* 2.1 */
    HCC_USER_PASSKEY_REQ_REPL        = 0x042E, /* 2.1 */
    HCC_USER_PASSKEY_REQ_NEG_REPL    = 0x042F, /* 2.1 */
    HCC_USER_OOB_DATA_REQ_REPL       = 0x0430, /* 2.1 */
    HCC_USER_OOB_DATA_REQ_NEG_REPL   = 0x0433, /* 2.1 */

    HCC_IO_CAPABILITY_NEG_REPL       = 0x0434, /* 2.1 */
    HCC_CREATE_PHYSICAL_LINK         = 0x0435, /* 3.0+HS */
    HCC_ACCEPT_PHYSICAL_LINK         = 0x0436, /* 3.0+HS */
    HCC_DISCONNECT_PHYSICAL_LINK     = 0x0437, /* 3.0+HS */
    HCC_CREATE_LOGICAL_LINK          = 0x0438, /* 3.0+HS */
    HCC_ACCEPT_LOGICAL_LINK          = 0x0439, /* 3.0+HS */
    HCC_DISCONNECT_LOGICAL_LINK      = 0x043A, /* 3.0+HS */
    HCC_LOGICAL_LINK_CANCEL		     = 0x043B, /* 3.0+HS */
    HCC_FLOW_SPEC_MODIFY		     = 0x043C, /* 3.0+HS */

    HCC_ENHANCED_SETUP_SYNC_CONNECTION = 0x043D, /* CSA2 */

 //3DS_PROFILE
#if defined(__BT_3DS_PROFILE__)
    HCC_SET_CONNECTIONLESS_SLAVE_BROADCAST = 0x0441,
    HCC_START_SYNCHRONIZATION_TRAIN = 0x0443,    
#endif

/* Group: Link policy commands */
    HCC_HOLD_MODE                    = 0x0801,
    HCC_SNIFF_MODE                   = 0x0803,
    HCC_EXIT_SNIFF_MODE              = 0x0804,
    HCC_PARK_MODE                    = 0x0805,
    HCC_EXIT_PARK_MODE               = 0x0806,
    HCC_QOS_SETUP                    = 0x0807,
    HCC_ROLE_DISCOVERY               = 0x0809,
    HCC_SWITCH_ROLE                  = 0x080B,
    HCC_READ_LINK_POLICY             = 0x080C,
    HCC_WRITE_LINK_POLICY            = 0x080D,
    HCC_READ_DEFAULT_LINK_POLICY     = 0x080E, /* 1.2 */
    HCC_WRITE_DEFAULT_LINK_POLICY    = 0x080F, /* 1.2 */
    HCC_FLOW_SPECIFICATION           = 0x0810, /* 1.2 */
    HCC_SNIFF_SUBRATING              = 0x0811, /* 2.1 */

/* Group: Host controller and baseband commands */
    HCC_SET_EVENT_MASK               = 0x0C01,
    HCC_RESET                        = 0x0C03,
    HCC_EVENT_FILTER                 = 0x0C05,
    HCC_FLUSH                        = 0x0C08,
    HCC_READ_PIN_TYPE                = 0x0C09,
    HCC_WRITE_PIN_TYPE               = 0x0C0A,
    HCC_CREATE_NEW_UNIT_KEY          = 0x0C0B,
    HCC_READ_STORED_LINK_KEY         = 0x0C0D,
    HCC_WRITE_STORED_LINK_KEY        = 0x0C11,
    HCC_DEL_STORED_LINK_KEY          = 0x0C12,
    HCC_CHNG_LOCAL_NAME              = 0x0C13,
    HCC_READ_LOCAL_NAME              = 0x0C14,
    HCC_READ_CONN_ACCEPT_TIMEOUT     = 0x0C15,
    HCC_WRITE_CONN_ACCEPT_TIMEOUT    = 0x0C16,
    HCC_READ_PAGE_TIMEOUT            = 0x0C17,
    HCC_WRITE_PAGE_TIMEOUT           = 0x0C18,
    HCC_READ_SCAN_ENABLE             = 0x0C19,
    HCC_WRITE_SCAN_ENABLE            = 0x0C1A,
    HCC_READ_PAGE_SCAN_ACTIVITY      = 0x0C1B,
    HCC_WRITE_PAGE_SCAN_ACTIVITY     = 0x0C1C,
    HCC_READ_INQ_SCAN_ACTIVITY       = 0x0C1D,
    HCC_WRITE_INQ_SCAN_ACTIVITY      = 0x0C1E,
    HCC_READ_AUTH_ENABLE             = 0x0C1F,
    HCC_WRITE_AUTH_ENABLE            = 0x0C20,
    HCC_READ_ENCRYPT_MODE            = 0x0C21,
    HCC_WRITE_ENCRYPT_MODE           = 0x0C22,
    HCC_READ_CLASS_OF_DEVICE         = 0x0C23,
    HCC_WRITE_CLASS_OF_DEVICE        = 0x0C24,
    HCC_READ_VOICE_SETTING           = 0x0C25,
    HCC_WRITE_VOICE_SETTING          = 0x0C26,
    HCC_READ_AUTO_FLUSH_TIMEOUT      = 0x0C27,
    HCC_WRITE_AUTO_FLUSH_TIMEOUT     = 0x0C28,
    HCC_READ_NUM_BC_RETRANSMIT       = 0x0C29,
    HCC_WRITE_NUM_BC_RETRANSMIT      = 0x0C2A,
    HCC_READ_HOLD_MODE_ACTIVITY      = 0x0C2B,
    HCC_WRITE_HOLD_MODE_ACTIVITY     = 0x0C2C,
    HCC_READ_XMIT_POWER_LEVEL        = 0x0C2D,
    HCC_READ_SCO_FC_ENABLE           = 0x0C2E,
    HCC_WRITE_SCO_FC_ENABLE          = 0x0C2F,
    HCC_SET_CTRLR_TO_HOST_FLOW_CTRL  = 0x0C31,
    HCC_HOST_BUFFER_SIZE             = 0x0C33,
    HCC_HOST_NUM_COMPLETED_PACKETS   = 0x0C35,
    HCC_READ_LINK_SUPERV_TIMEOUT     = 0x0C36,
    HCC_WRITE_LINK_SUPERV_TIMEOUT    = 0x0C37,
    HCC_READ_NUM_IAC                 = 0x0C38,
    HCC_READ_CURRENT_IAC_LAP         = 0x0C39,
    HCC_WRITE_CURRENT_IAC_LAP        = 0x0C3A,
    HCC_READ_PAGE_SCAN_PERIOD_MODE   = 0x0C3B,
    HCC_WRITE_PAGE_SCAN_PERIOD_MODE  = 0x0C3C,
    HCC_READ_PAGE_SCAN_MODE          = 0x0C3D, /* Not in 1.2 */
    HCC_WRITE_PAGE_SCAN_MODE         = 0x0C3E, /* Not in 1.2 */
    HCC_SET_AFH_HOST_CHAN_CLASS      = 0x0C3F, /* 1.2 */
    HCC_READ_INQ_SCAN_TYPE           = 0x0C42, /* 1.2 */
    HCC_WRITE_INQ_SCAN_TYPE          = 0x0C43, /* 1.2 */
    HCC_READ_INQ_MODE                = 0x0C44, /* 1.2 */
    HCC_WRITE_INQ_MODE               = 0x0C45, /* 1.2 */
    HCC_READ_PAGE_SCAN_TYPE          = 0x0C46, /* 1.2 */
    HCC_WRITE_PAGE_SCAN_TYPE         = 0x0C47, /* 1.2 */
    HCC_READ_AFH_CHAN_ASSESS_MODE    = 0x0C48, /* 1.2 */
    HCC_WRITE_AFH_CHAN_ASSESS_MODE   = 0x0C49, /* 1.2 */
    HCC_READ_ANONYMITY_MODE          = 0x0C4A, /* 1.2 */
    HCC_WRITE_ANONYMITY_MODE         = 0x0C4B, /* 1.2 */
    HCC_READ_ALIAS_AUTH_ENABLE       = 0x0C4C, /* 1.2 */
    HCC_WRITE_ALIAS_AUTH_ENABLE      = 0x0C4D, /* 1.2 */
    HCC_READ_ANON_ADDR_CHNG_PARM     = 0x0C4E, /* 1.2 */
    HCC_WRITE_ANON_ADDR_CHNG_PARM    = 0x0C4F, /* 1.2 */
    HCC_RESET_FIXED_ADDR_COUNTER     = 0x0C50, /* 1.2 */
    HCC_WRITE_EXT_INQUIRY_RESPONSE   = 0x0C52, /* 2.1 */
    HCC_WRITE_SIMPLE_PAIRING_MODE    = 0x0C56, /* 2.1 */
    HCC_WRITE_INQUIRY_TX_PWR    = 0x0C59, /* 2.1 */
 //3DS_PROFILE
#if defined(__BT_3DS_PROFILE__)
    HCC_READ_INQ_RSP_XMIT_POWER_LEVEL = 0x0C58,
    HCC_SET_EVENT_MASK_PAGE_2 = 0x0C63,
    HCC_SET_RESERVED_LT_ADDR = 0x0C74,
    HCC_DELETE_RESERVED_LT_ADDR = 0x0C75, //TODO
    HCC_SET_CONNECTIONLESS_SLAVE_BROADCAST_DATA = 0x0C76,
    HCC_WRITE_SYNCHRONIZATION_TRAIN_PARAMETERS = 0x0C78,
#endif
    
    HCC_WRITE_FLOW_CONTROL_MODE      = 0x0C67, /* 3.0+HS */
    HCC_READ_LE_HOST_SUPPORT         = 0x0C6C, /* 4.0 */
    HCC_WRITE_LE_HOST_SUPPORT        = 0x0C6D, /* 4.0 */
#if defined (__BT_41_SECURE_CONNECTION__)
    HCC_WRITE_SECURE_CONNECTION_HOST_SUPPORT        = 0x0C7A, /* 4.1 Secure Connection */
    HCC_WRITE_AUTHENTICATED_TIMEOUT_COMMAND         = 0x0C7C, /* 4.1 Secure Connection */
    
#endif    

/* Group: Informational parameters */
    HCC_READ_LOCAL_VERSION           = 0x1001,
    HCC_READ_LOCAL_COMMANDS          = 0x1002, /* 1.2 */
    HCC_READ_LOCAL_FEATURES          = 0x1003,
    HCC_READ_LOCAL_EXT_FEATURES      = 0x1004, /* 1.2 */
    HCC_READ_BUFFER_SIZE             = 0x1005,
    HCC_READ_COUNTRY_CODE            = 0x1007, /* Not in 1.2 */
    HCC_READ_BD_ADDR                 = 0x1009,
    HCC_READ_DATA_BLOCK_SIZE         = 0x100A, /* 3.0+HS*/
    HCC_READ_LOCAL_CODECS            = 0x100B, /* CSA2 */

/* Group: Status parameters */
    HCC_READ_FAILED_CONTACT_COUNT    = 0x1401,
    HCC_RESET_FAILED_CONTACT_COUNT   = 0x1402,
    HCC_GET_LINK_QUALITY             = 0x1403,
    HCC_READ_RSSI                    = 0x1405,
    HCC_READ_AFH_CHANNEL_MAP         = 0x1406, /* 1.2 */
    HCC_READ_CLOCK                   = 0x1407, /* 1.2 */
    HCC_READ_LOCAL_AMP_INFO          = 0x1409, /* 3.0+HS */
    HCC_READ_LOCAL_AMP_ASSOC         = 0x140A, /* 3.0+HS */
    HCC_WRITE_REMOTE_AMP_ASSOC       = 0x140B, /* 3.0+HS */
//3DS_PROFILE
#if defined(__BT_3DS_PROFILE__)
    HCC_SET_TRIGGERED_CLOCK_CAPTURE = 0x140D,
    //HCC_SET_TRIGGERED_CLOCK_CAPTURE = 0x100D,
#endif

/* Group: Testing commands */
    HCC_READ_LOOPBACK_MODE           = 0x1801,
    HCC_WRITE_LOOPBACK_MODE          = 0x1802,
    HCC_ENABLE_DUT                   = 0x1803,
    HCC_WRITE_SSP_DEBUG_MODE         = 0x1804,

    /* Group: LE commands */
    HCC_LE_SET_EVENT_MASK            = 0x2001,
    HCC_LE_READ_BUFFER_SIZE          = 0x2002,
    HCC_LE_READ_LOCAL_FEATURES       = 0x2003,
    HCC_LE_SET_RANDOM_ADDRESS        = 0x2005,
    HCC_LE_SET_ADVERTISE_PARAM       = 0x2006,
    HCC_LE_READ_ADVERTISE_TX_POWER   = 0x2007,
    HCC_LE_SET_ADVERTISE_DATA        = 0x2008,
    HCC_LE_SET_SCAN_RESPONSE_DATA    = 0x2009,
    HCC_LE_SET_ADVERTISE_ENABLE      = 0x200A,
    HCC_LE_SET_SCAN_PARAM            = 0x200B,
    HCC_LE_SET_SCAN_ENABLE           = 0x200C,
    HCC_LE_CREATE_CONNECTION         = 0x200D,
    HCC_LE_CREATE_CONNECTION_CANCEL  = 0x200E,
    HCC_LE_READ_WHITE_LIST_SIZE      = 0x200F,
    HCC_LE_CLEAR_WHITE_LIST          = 0x2010,
    HCC_LE_ADD_TO_WHITE_LIST         = 0x2011,
    HCC_LE_REMOVE_FROM_WHITE_LIST    = 0x2012,
    HCC_LE_CONNECT_UPDATE            = 0x2013,
    HCC_LE_SET_HOST_CHANNEL_CLASS    = 0x2014,
    HCC_LE_READ_CHANNEL_MAP          = 0x2015,
    HCC_LE_READ_REMOTE_FEATURES      = 0x2016,
    HCC_LE_ENCRYPT                   = 0x2017,
    HCC_LE_RAND                      = 0x2018,
    HCC_LE_START_ENCRYPT             = 0x2019,
    HCC_LE_LONG_TERM_KEY_REQ_REPL    = 0x201A,
    HCC_LE_LONG_TERM_KEY_REQ_NEG_REPL= 0x201B,
    HCC_LE_READ_SUPPORT_STATES       = 0x201C,
    HCC_LE_RECEIVER_TEST             = 0x201D,
    HCC_LE_TRANSMITTER_TEST          = 0x201E,
    HCC_LE_TEST_END                  = 0x201F,

    /* Write BD address to controller */
    HCC_SET_BD_ADDR                        = 0xFC1A,
    HCC_SET_LMP_EXTENDED_FEATURE           = 0xFC1F,
    HCC_READ_PROPRIETARY_EXTENDED_FEATURES = 0xFC54,    
    HCC_SET_PINCODE_RSP_TIMEOUT            = 0xFC66,
    HCC_DUAL_PCM_SET_VALUE                 = 0xFC72,
    HCC_DUAL_PCM_SWITCH                    = 0xFC90,
#ifdef __A2DP_MULTI_LINK_FEATURE__
    /* Get 4 bytes clock offset for a2dp */
    HCC_READ_CLOCK_OFFSET_EXT              = 0xFCC5,
#endif 
    /* James 20070522, for peripheral test */
    /* Group: Peripheral test commands */
    HCC_MT66XX_Enabled_FLOW_CONTROL        = 0xFCEF,
    HCC_UART_PERIPHERAL_REQ                = 0xFCF0,
    HCC_UART_TEST_REQ                      = 0xFCF1,
#ifdef __ANTI_LOST_FEATURE__
    HCC_LOW_POWER_PRXM_ENABLE              = 0xFCF2,
#endif
#ifdef __BT_WOBLE__
    HCC_SET_STORED_KEY                     = 0xFCF3,
#else
    HCC_GPIO_TEST_REQ                      = 0xFCF3,
#endif
    HCC_WDT_TEST_REQ                       = 0xFCF4,
    HCC_PATCH_TEST_REQ                     = 0xFCF5,

#ifdef __ANDROID_L_MIGRATION__
    HCC_LE_VENDOR_CAP                             = HCI_OGF_VENDOR_SPECIFIC | 0x153,  //0xFD53
    HCC_LE_MULTI_ADV                              = HCI_OGF_VENDOR_SPECIFIC | 0x154,  //0xFD54
//RPA
    HCC_VENDOR_SPECIFIC_Offloaded_RPA	          = (HCI_OGF_VENDOR_SPECIFIC | 0x0155), // 0xFD55
//RPA end
/* vendor specific : batch scan */
    HCC_LE_BATCH_SCAN_CMD                         = HCI_OGF_VENDOR_SPECIFIC | 0x156,    //0xFD56,  // 0x3F << 10 | 0x156
    HCC_LE_PCF                                    = HCI_OGF_VENDOR_SPECIFIC | 0x157,   //0xFD57
#endif /* __ANDROID_L_MIGRATION__ */
}HciCommandType;

/*---------------------------------------------------------------------------
 * HciEventType type
 *
 *     These events are indicated by HCI to the Management Entity during
 *     a HCI_CONTROLLER_EVENT callback. The event type is found in the
 *     "hciEvent->event" field of the callback parameters structure
 *     (HciCallbackParms).
 */
typedef enum
{
    HCE_INQUIRY_COMPLETE               = 0x01,
    HCE_INQUIRY_RESULT                 = 0x02,
    HCE_CONNECT_COMPLETE               = 0x03,
    HCE_CONNECT_REQUEST                = 0x04,
    HCE_DISCONNECT_COMPLETE            = 0x05,
    HCE_AUTH_COMPLETE                  = 0x06,
    HCE_REMOTE_NAME_REQ_COMPLETE       = 0x07,
    HCE_ENCRYPT_CHNG                   = 0x08,
    HCE_CHNG_CONN_LINK_KEY_COMPLETE    = 0x09,
    HCE_MASTER_LINK_KEY_COMPLETE       = 0x0A,
    HCE_READ_REMOTE_FEATURES_COMPLETE  = 0x0B,
    HCE_READ_REMOTE_VERSION_COMPLETE   = 0x0C,
    HCE_QOS_SETUP_COMPLETE             = 0x0D,
    HCE_COMMAND_COMPLETE               = 0x0E,
    HCE_COMMAND_STATUS                 = 0x0F,
    HCE_HARDWARE_ERROR                 = 0x10,
    HCE_FLUSH_OCCURRED                 = 0x11,
    HCE_ROLE_CHANGE                    = 0x12,
    HCE_NUM_COMPLETED_PACKETS          = 0x13,
    HCE_MODE_CHNG                      = 0x14,
    HCE_RETURN_LINK_KEYS               = 0x15,
    HCE_PIN_CODE_REQ                   = 0x16,
    HCE_LINK_KEY_REQ                   = 0x17,
    HCE_LINK_KEY_NOTIFY                = 0x18,
    HCE_LOOPBACK_COMMAND               = 0x19,
    HCE_DATA_BUFFER_OVERFLOW           = 0x1A,
    HCE_MAX_SLOTS_CHNG                 = 0x1B,
    HCE_READ_CLOCK_OFFSET_COMPLETE     = 0x1C,
    HCE_CONN_PACKET_TYPE_CHNG          = 0x1D,
    HCE_QOS_VIOLATION                  = 0x1E,
    HCE_PAGE_SCAN_MODE_CHANGE          = 0x1F, /* Not in 1.2 */
    HCE_PAGE_SCAN_REPETITION_MODE      = 0x20,
    HCE_FLOW_SPECIFICATION_COMPLETE    = 0x21, /* 1.2 */
    HCE_INQUIRY_RESULT_WITH_RSSI       = 0x22, /* 1.2 */
    HCE_READ_REMOTE_EXT_FEAT_COMPLETE  = 0x23, /* 1.2 */
    HCE_FIXED_ADDRESS                  = 0x24, /* 1.2 */
    HCE_ALIAS_ADDRESS                  = 0x25, /* 1.2 */
    HCE_GENERATE_ALIAS_REQ             = 0x26, /* 1.2 */
    HCE_ACTIVE_ADDRESS                 = 0x27, /* 1.2 */
    HCE_ALLOW_PRIVATE_PAIRING          = 0x28, /* 1.2 */
    HCE_ALIAS_ADDRESS_REQ              = 0x29, /* 1.2 */
    HCE_ALIAS_NOT_RECOGNIZED           = 0x2A, /* 1.2 */
    HCE_FIXED_ADDRESS_ATTEMPT          = 0x2B, /* 1.2 */
    HCE_SYNC_CONNECT_COMPLETE          = 0x2C, /* 1.2 */
    HCE_SYNC_CONN_CHANGED              = 0x2D, /* 1.2 */
    HCE_SNIFF_SUBRATING_EVENT          = 0x2E, /* Posh_assert */
    HCE_INQUIRY_RESULT_WITH_EIR        = 0x2F, /* 2.1 */
    HCE_ENCRYPTION_KEY_REFRESH_COMPLETE_EVENT   = 0x30, /* Posh_assert */
    HCE_IO_CAPABILITY_REQUEST          = 0x31, /* 2.1 */
    HCE_IO_CAPABILITY_RESPONSE         = 0x32, /* 2.1 */
    HCE_USER_CONFIRM_REQUSEST          = 0x33, /* 2.1 */
    HCE_USER_PASSKEY_REQUEST_EVENT     = 0x34, /* Posh_assert */
    HCE_REMOTE_OOB_DATA_REQUEST_EVENT  = 0x35, /* Posh_assert */
    HCE_SIMPLE_PAIRING_COMPLETE        = 0x36, /* 2.1 */
    HCE_LINK_SUPERVISION_TIMEOUT_CHNG  = 0x38, /* 2.1 */
    HCE_ENHANCED_FLUSH_COMPLETE        = 0x39, /* 2.1 */

    HCE_USER_PASSKEY_NOTIFICATION      = 0x3B, /* 2.1 */
    HCE_USER_KEYPRESS                  = 0x3C, /* 2.1 */
    HCE_REMOTE_HOST_SUPPORTED_FEATURES_NOTIFICATION_EVENT   = 0x3D,    /* Posh_assert */
    HCE_LE_META_EVENT                  = 0x3E, /* 4.0 */
    HCE_PHYSICAL_LINK_COMPLETE         = 0x40, /* 3.0+HS */
    HCE_CHANNEL_SELECTED               = 0x41, /* 3.0+HS */
    HCE_DISCONNECT_PHYSICAL_LINK       = 0x42, /* 3.0+HS */
    HCE_PHYSICAL_LINK_EARLY_WARNING    = 0x43, /* 3.0+HS */
    HCE_PHYSICAL_LINK_RECOVERY         = 0x44, /* 3.0+HS */
    HCE_LOGICAL_LINK_COMPLETE          = 0x45, /* 3.0+HS */
    HCE_DISCONNECT_LOGICAL_LINK        = 0x46, /* 3.0+HS */
    HCE_NUM_OF_COMPLETE_DATA_BLOCKS    = 0x48, /* 3.0+HS */
    HCE_AMP_STATUS_CHANGE              = 0x4D, /* 3.0+HS */
 //3DS_PROFILE
#if defined(__BT_3DS_PROFILE__)
    HCE_TRIGGERED_CLOCK_CAPTURE        = 0x4E,
    HCE_SYNCHRONIZATION_TRAIN_COMPLETE = 0x4F,
    HCE_SYNCHRONIZATION_TRAIN_RECEIVED = 0x50,
    HCE_CONECTIONLESS_SLAVE_BROADCAST_RECEIVED = 0x51,
    HCE_CONECTIONLESS_SLAVE_BROADCAST_TIMEOUT = 0x52,
    HCE_TRUNCATED_PAGE_COMPLETE        = 0x53,
    HCE_SLAVE_PAGE_RESPONSE_TIMEOUT    = 0x54,
    HCE_CONNECTIONLESS_SLAVE_BROADCAST_CHANNEL_MAP_CHANGE = 0x55,
    HCE_INQUIRY_RESPONSE_NOTIFICATION  = 0x56,
#endif
    HCE_AUTHENTICATED_PAYLOAD_TIMEOUT              = 0x57, /* BT4.1 */

    HCE_UART_SETTING_COMPLETE          = 0xF0,
#ifdef __ANTI_LOST_FEATURE__
    HCE_LOW_POWER_PRXM_EVENT           = 0xF2,
#endif
    HCE_BLUETOOTH_LOGO                 = 0xFE,
    HCE_VENDOR_SPECIFIC                = 0xFF,
}HciEventType;

typedef enum
{
    HCE_LE_CONNECT_COMPLETE = 0x01,
    HCE_LE_ADVERTISE_REPORT,                    /* 0x02 */
    HCE_LE_CONNECT_UPDATE_COMPLETE,             /* 0x03 */
    HCE_LE_READ_REMOTE_FEATURES_COMPLETE,       /* 0x04 */
    HCE_LE_LONG_TERM_KEY_REQUEST_EVENT,        /* 0x05 */
    HCE_LE_ENHANCED_CONNECT_COMPLETE = 0x0A
}HciLeSubEventType;

#ifdef __ANDROID_L_MIGRATION__
typedef enum
{
    HCC_LE_SCAN_FILTER_ENABLE = 0,
    HCC_LE_SCAN_FILTER_PARAM_SETUP,             /* 1 */
    HCC_LE_SCAN_FILTER_BROADCAST_ADDR,      /* 2 */
    HCC_LE_SCAN_FILTER_SVC_UUID,                    /* 3 */
    HCC_LE_SCAN_FILTER_SOL_SVC_UUID,            /* 4 */
    HCC_LE_SCAN_FILTER_LOCAL_NAME,               /* 5 */
    HCC_LE_SCAN_FILTER_MANU_DATA,                /* 6 */
    HCC_LE_SCAN_FILTER_SVC_DATA,                   /* 7 */
    HCC_LE_SCAN_FILTER_ALL,                              /* 8 */
}HciLeScanFilterSubCmdType;

typedef enum
{
    HCC_LE_MULTI_ADV_PARAM = 1,             /* 1 */
    HCC_LE_MULTI_ADV_DATA,                     /* 2 */
    HCC_LE_MULTI_ADV_SCAN_DATA,           /* 3 */
    HCC_LE_MULTI_ADVRAND_ADDR,            /* 4 */
    HCC_LE_MULTI_ADV_ENABLE,                  /* 5 */
}HciLeMultiAdvSubCmdType;

typedef enum
{
    HCE_VENDOR_LE_MULTI_ADV_ST_CHG = 0x55,
}HciVendorSubEventType;
/* Vendor  */
#endif

/*---------------------------------------------------------------------------
 * HcStatus type
 *
 *     The first parameter in an HCI event often contains a "status" value.
 *     0x00 means pending or success, according to the event type, but
 *     other values provide a specific reason for the failure. These
 *     values are listed below.
 */
typedef U8 HcStatus;

#define HC_STATUS_SUCCESS                 0x00
#define HC_STATUS_UNKNOWN_HCI_CMD         0x01
#define HC_STATUS_NO_CONNECTION           0x02
#define HC_STATUS_HARDWARE_FAILURE        0x03
#define HC_STATUS_PAGE_TIMEOUT            0x04
#define HC_STATUS_AUTH_FAILURE            0x05
#define HC_STATUS_KEY_MISSING             0x06
#define HC_STATUS_MEMORY_FULL             0x07
#define HC_STATUS_CONN_TIMEOUT            0x08
#define HC_STATUS_MAX_NUM_CONNS           0x09
#define HC_STATUS_MAX_SCO_CONNS           0x0A
#define HC_STATUS_ACL_ALREADY_EXISTS      0x0B
#define HC_STATUS_CMD_DISALLOWED          0x0C
#define HC_STATUS_HOST_REJ_NO_RESOURCES   0x0D
#define HC_STATUS_HOST_REJ_SECURITY       0x0E
#define HC_STATUS_HOST_REJ_PERSONAL_DEV   0x0F
#define HC_STATUS_HOST_TIMEOUT            0x10
#define HC_STATUS_UNSUPP_FEATUR_PARM_VAL  0x11
#define HC_STATUS_INVAL_HCI_PARM_VAL      0x12
#define HC_STATUS_CONN_TERM_USER_REQ      0x13
#define HC_STATUS_CONN_TERM_LOW_RESOURCES 0x14
#define HC_STATUS_CONN_TERM_POWER_OFF     0x15
#define HC_STATUS_CONN_TERM_LOCAL_HOST    0x16
#define HC_STATUS_REPEATED_ATTEMPTS       0x17
#define HC_STATUS_PAIRING_DISALLOWED      0x18
#define HC_STATUS_UNKNOWN_LMP_PDU         0x19
#define HC_STATUS_UNSUPP_REMOTE_FEATURE   0x1A
#define HC_STATUS_SCO_OFFSET_REJECTED     0x1B
#define HC_STATUS_SCO_INTERVAL_REJECTED   0x1C
#define HC_STATUS_SCO_AIR_MODE_REJECTED   0x1D
#define HC_STATUS_INVALID_LMP_PARM        0x1E
#define HC_STATUS_UNSPECIFIED_ERROR       0x1F
#define HC_STATUS_UNSUPP_LMP_PARM         0x20
#define HC_STATUS_ROLE_CHANGE_DISALLOWED  0x21
#define HC_STATUS_LMP_RESPONSE_TIMEDOUT   0x22
#define HC_STATUS_LMP_ERR_TRANSACT_COLL   0x23
#define HC_STATUS_LMP_PDU_DISALLOWED      0x24
#define HC_STATUS_ENCRYPTN_MODE_UNACCEPT  0x25
#define HC_STATUS_UNIT_KEY_USED           0x26
#define HC_STATUS_QOS_NOT_SUPPORTED       0x27
#define HC_STATUS_INSTANT_PASSED          0x28
#define HC_STATUS_PAIRING_W_UNIT_KEY_UNSUPP         0x29
#define HC_STATUS_DIFFERENT_TRANSACTION_COLLISION   0x2A
#define HC_STATUS_INSUFF_RESOURCES_FOR_SCATTER_MODE 0x2B
#define HC_STATUS_QOS_UNACCEPTABLE_PARAMETER        0x2C
#define HC_STATUS_QOS_REJECTED                      0x2D
#define HC_STATUS_CHANNEL_CLASSIF_NOT_SUPPORTED     0x2E
#define HC_STATUS_INSUFFICIENT_SECURITY             0x2F
#define HC_STATUS_PARAMETER_OUT_OF_MANDATORY_RANGE  0x30
#define HC_STATUS_SCATTER_MODE_NO_LONGER_REQUIRED   0x31
#define HC_STATUS_ROLE_SWITCH_PENDING               0x32
#define HC_STATUS_SCATTER_MODE_PARM_CHNG_PENDING    0x33
#define HC_STATUS_RESERVED_SLOT_VIOLATION           0x34
#define HC_STATUS_SWITCH_FAILED                     0x35
#define HC_STATUS_EIR_TOO_LARGE                     0x36
#define HC_STATUS_HOST_NOT_SUPPORT_SSP              0x37
#define HC_STATUS_HOST_BUSY_PAIRING                 0x38
#define HC_STATUS_NO_SUITABLE_CHANNEL               0x39
#define HC_STATUS_CONTROLLER_BUSY                   0x3A
#define HC_STATUS_UNACCEPTABLE_CONN_INTERVAL        0x3B
#define HC_STATUS_DIRECTED_ADV_TIMEOUT              0x3C
#define HC_STATUS_MIC_FAILURE                       0x3D
#define HC_STATUS_CONN_ESTABLISH_FAILED             0x3E
#define HC_STATUS_MAC_CONN_FAILED                   0x3F

#define HC_STATUS_CHIP_LIMITATION                   0xF1

/* End of HcStatus */

/*---------------------------------------------------------------------------
 * HciHandle type
 *
 * The HciHandle contains an 12-bit connection identifier as well as
 * two bits for packet boundary flags and two bits for broadcast flags.
 * These fields are combined together to exchange information about the
 * packet data exchanged between the Host Controller and L2CAP.
 *
 */
typedef U16 HciHandle;

/*
 * Group: Broadcast Flags. When receiving a packet from the Host Controller,
 * one of these flags may be set. If no flags are set, the packet is
 * a normal, point-to-point transmission.
 */

/*
 * The Host Controller sets this flag in a received packet's handle
 * to indicate it was received as an Active or Piconet Broadcast packet.
 *
 * L2CAP should not use this flag for transmitted packets, but use
 * ACTIVE_BC_HANDLE instead.
 */
#define ACTIVE_BROADCAST       0x4000

/*
 * The Host Controller sets this flag in a received packet's handle
 * to indicate it was received as a Piconet Broadcast packet while
 * in "park" mode.
 *
 * L2CAP should not use this flag for transmitted packets, but use
 * PICONET_BC_HANDLE instead.
 */
#define PICONET_BROADCAST      0x8000

/* Represents an invalid Host Controller handle. */
#define INVALID_HCI_HANDLE      0xFFFF

/*
 * Broadcast handle used by L2CAP to transmit to all active slaves
 * (not including parked slaves).
 */
#define ACTIVE_BC_HANDLE       (0x0F01 | ACTIVE_BROADCAST)

/*
 * Broadcast handle used by L2CAP to transmit to all slaves, including
 * both parked and active slaves.
 */
#define PICONET_BC_HANDLE       (0x0F00 | PICONET_BROADCAST)

/*
 * Group: Packet Boundary Flags. When receiving a packet from the Host
 * Controller, either of these two flags will be set. When sending a
 * packet to the Host Controller, the HCI layer fills in these
 * fields automatically.
 */

#if defined (__BT_2_1_AUTO_FLUSH__)
#define CONTINUING_PACKET      (0x1000) /*
                                         * This packet fragment continues
                                         * a previously started L2CAP packet.
                                         */
#define FIRST_PACKET           (0x0000) /*
                                         * This packet fragment is the
                                         * first fragment of an L2CAP packet.
                                         */

#define FIRST_AUTO_FLUSH_PACKET    (0x2000)     /*
                                                 * This packet fragment is the
                                                 * first automatically flishable packet fragment of an L2CAP packet.
                                                 */

#else /* defined (__BT_2_1_AUTO_FLUSH__) */ 

#define CONTINUING_PACKET      0x1000   /*
                                         * This packet fragment continues
                                         * a previously started L2CAP packet.
                                         */
#define FIRST_PACKET           0x2000   /*
                                         * This packet fragment is the
                                         * first fragment of an L2CAP packet.
                                         */

/* End of HciHandle */
#endif /* defined (__BT_2_1_AUTO_FLUSH__) */ 

#define BT_SUPERVISION_TIMEOUT_DEFAULT_VALUE 0x7D00

/*---------------------------------------------------------------------------
 * HciPrescanFlags type
 *
 *     Describes the order in which prescan structures will be registered.  
 */
typedef U8 HciPrescanFlags;

#define PRESCAN_FLAG_LAST      0x00
#define PRESCAN_FLAG_FIRST     0x01

 /* Forward reference for HciPacket */
typedef struct _HciPacket HciPacket;

/****************************************************************************
 *
 * Data Structures
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * HciCommand structure
 * 
 *     Represents an HCI command to be sent to the host controller when
 *     calling HCI_SendCommand.
 *
 *     The parameters buffer contains a set of command-specific parameters.
 *     The format and description for these parameters can be found in
 *     the Bluetooth HCI specification.
 */
typedef struct _HciCommand
{
    ListEntry node; /* For internal use only */

    U8 header[3];   /* For internal use only */

    /*
     * Command-specific parameters provided by the caller of
     * HCI_SendCommand. Note that the length of this buffer is
     * limited to HCI_CMD_PARM_LEN in btconfig.h. If a larger paramters
     * buffer is required, override this configuration setting
     * in overide.h.
     */
    U8 parms[HCI_CMD_PARM_LEN];

} HciCommand;

typedef struct _HciReducedCommand
{
    ListEntry node; /* For internal use only */

    U8 header[3];   /* For internal use only */

    /*
     * Command-specific parameters provided by the caller of
     * HCI_SendCommand. Note that the length of this buffer is
     * limited to HCI_CMD_PARM_LEN in btconfig.h. If a larger paramters
     * buffer is required, override this configuration setting
     * in overide.h.
     */
    U8 parms[10];

} HciReducedCommand;

/*---------------------------------------------------------------------------
 * HciEvent structure
 *
 *     When the host controller generates events, these events are passed
 *     to the ME_Callback function with a callback event type of
 *     HCI_CONTROLLER_EVENT. The contents of the HCI event are found in
 *     the callback parameters "hciEvent" field.
 *
 *     The parameters buffer contains a set of event-specific parameters.
 *     The format and description for these parameters can be found in
 *     the Bluetooth HCI specification.
 */
typedef struct _HciEvent
{
    HciEventType event; /* The type of HCI event received  */
    U8 len;             /* Length of the event parameters */
    U8 *parms;          /* Event-specific parameters */
} HciEvent;

/*---------------------------------------------------------------------------
 * HciBuffer structure
 *
 *     Represents a buffer of data received from the hardware by the
 *     transport. Except for "node", all of the fields in this structure
 *     must be initialized before providing it to the HCI layer with
 *     HCI_BufferInd.
 */
typedef struct _HciBuffer
{
    ListEntry node; /* Node element for linked list management. */
    U16 len;        /* Length of data in "buffer". */
    U8 *buffer;     /* Pointer to received data buffer. */
    U8 flags;   /*
                 * Flags to identify the type of packet.
                 * Actually uses the HciBufFlags type.
                 */
#if XA_STATISTICS == XA_ENABLED
    U32 hci_timer;
#endif /* XA_STATISTICS == XA_ENABLED */
} HciBuffer;
typedef struct _HciMetaBuffer
{
    U16 con_hdl;
    U16 len;    /* Length of data in "buffer". */
    U8 *buffer; /* Pointer to received data buffer. */
} HciMetaBuffer;

/*---------------------------------------------------------------------------
 * HciCallbackParms structure
 *
 *     To indicate different kinds of events to the Management Entity,
 *     the HCI layer calls the ME_Callback function with an HciCallbackEvent
 *     and a callback parameters structure (this one).
 *
 *     Different fields in the "ptr" union are valid depending on the
 *     event type. See the definition for HciCallbackEvent for more
 *     information.
 */
typedef struct _HciCallbackParms
{
    BtStatus status;    /* May indicate the status of an operation */
    HciHandle hciHandle;        /*
                                 * May indicate the HCI handle concerned with the
                                 * event.
                                 */
    U8 morePacketWaiting;
    /*
     * Group: Only one of the following fields may be valid. The correct
     * field to use will depend on the HciCallbackEvent received by
     * the ME_Callback.
     */
#ifdef __BT_3_0_HS__
    HciHandle ampHandle;       
#endif    
    union
    {
        HciEvent *hciEvent;         /* Host controller event      */
        HciBuffer *rxBuff;          /* Received packet  */
        BtPacket *packet;           /* Returned transmit packet   */
        HciCommand *cmd;            /* Host controller command    */
        HciMetaBuffer *rxMetaBuff;  /* Received packet  */
        U8 txNumber;
    } ptr;
} HciCallbackParms;

/* ME callback function */
void ME_Callback(U8 event, HciCallbackParms *parms);

/*---------------------------------------------------------------------------
 * RadioHandlerCallback type
 *
 *     Called by the HCI driver to allow radio initialization.
 */
typedef void (*RadioHandlerCallback) (U8 event, HciCallbackParms *parms);

/* End of RadioHandlerCallback */

//Function Pointer Version1
typedef struct _gormcall_ver1
{

    BtStatus(*BtRadio_HCI_Reset)(void);
    void (*BtRadio_HCI_RegisterRadioHandler)(RadioHandlerCallback radioHandlerCallback);
    BtStatus(*BtRadio_HciTransmitCommand)(U16 opCode, U8 parmLen, HciCommand *cmd, BOOL internal, BOOL insertTail);
    BtStatus(*BtRadio_HCI_HostWakeupStartTimer)(void);
    void (*BtRadio_HCI_Set_State)(U8 state);
    void (*BtRadio_EVM_StartTimer)(EvmTimer *timer, U32 ms);
    void (*BtRadio_EVM_CancelTimer)(EvmTimer *timer);
    U16(*BtRadio_BT_XFile_EncryptionCommandOpcode)(U16 opcode);
    void (*BtRadio_BT_XFile_EncryptionCommand)(U8 *data, U16 length);
    void (*BtRadio_BT_XfileGenAuthenticationInitKeyStep0)(void);
    void (*BtRadio_BT_XfileGenAuthenticationInitKeyStep1)(void);
    void (*BtRadio_BT_XfileGenAuthenticationInitKeyStep2)(void);
    void (*BtRadio_BT_XfileGenAuthenticationInitKeyStep3)(void);
    void (*BtRadio_HciTransportError1)(U8 index);
    //version0 end
    U8* (*BtRadio_StackBuffer_Temp_Get)(U32 *buff_size);
    void (*BtRadio_StackBuffer_Temp_Give)(U8 *buff_p, U32 buff_size);
    //version1 end

} GormCall_Ver1;
#if HCI_ALLOW_PRESCAN == XA_ENABLED

typedef BOOL(*HciTxPrescanHandler) (HciPacket *Packet);
typedef BOOL(*HciTxDoneHandler) (HciPacket *Packet);
typedef BOOL(*HciRxPrescanHandler) (HciBuffer *Buffer);
typedef BOOL(*HciRxDoneHandler) (HciBuffer *Buffer);

/*---------------------------------------------------------------------------
 * HciPrescanHandler structure
 *
 *     Handler used to register functions that examine HCI data before it is
 *     transmitted to the radio and when it is received from the radio.  This
 *     can be used for debugging (as in sniffer.c) or to actually modify
 *     HCI data in cases where the formatting of the data needs to be (or is)
 *     different than the current Bluetooth spec.  These are very powerful
 *     functions, which can trouble if not used properly.  If the data is
 *     not modified in the function, and the function always returns FALSE,
 *     then they should cause no problems.
 */
typedef struct _HciPrescanHandler
{
    ListEntry node; /* Used internally by HCI */

    /*
     * Called before data is transmittted. Return TRUE if the event
     * was handled.  If TRUE is returned, the prescan MUST have sent
     * the packet, otherwise the HCI flow control could be  compromised.
     */
    HciTxPrescanHandler hciTxPrescan;

    /*
     * Called when the transmit is complete. Return TRUE if the event
     * was handled.  If TRUE is returned, the HCI_COMMAND_HANDLED event
     * will not be passed up to ME.
     */
    HciTxDoneHandler hciTxDone;

    /*
     * Called before receive data is sent up to the Management
     * Entity.  Return TRUE if the event was handled. If TRUE is
     * returned, the data (or event) will not be passed up to ME.
     */
    HciRxPrescanHandler hciRxPrescan;

    /*
     * Called when the receive data has been handled. Return TRUE if the
     * event was handled. If TRUE is returned, the prescan must be
     * responsible for returning the receive buffer to RXBUFF.
     */
    HciRxDoneHandler hciRxDone;

} HciPrescanHandler;

/* End of HciPrescanHandler */

#endif /* HCI_ALLOW_PRESCAN == XA_ENABLED */

/****************************************************************************
 *
 * Function Reference - Upper layer functions
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * HCI_Init()
 *
 *     Initialize the HCI queues, receive buffers, and broadcast handles.  
 *
 * Returns:
 *     BT_STATUS_SUCCESS - HCI is initialized.
 *
 *     BT_STATUS_FAILED - hardware failed to initialize.
 */
BtStatus HCI_Init(void);

/*---------------------------------------------------------------------------
 * HCI_Deinit()
 *
 *     Deinitialize the HCI.  Return all resources to the upper layers.
 */
void HCI_Deinit(void);

/*---------------------------------------------------------------------------
 * HCI_Reset()
 *
 *     Sends the HCC_RESET command only. Called by Radio_Init in the module
 *     initialization code to give flexibility on how and when it is called
 *     during the radio initialization.
 *
 * Returns:
 *     BT_STATUS_PENDING - HCI is initializing the radio to a known state.  
 *       HCI is initializing the radio to a known state. The status will 
 *       indicate successful or unsucessfull attempt. 
 *      
 */
BtStatus HCI_Reset(void);
//#ifdef __ENABLE_SLEEP_MODE__
BtStatus HCI_HostWakeupStartTimer(void);
//#endif /* __ENABLE_SLEEP_MODE__ */
/*---------------------------------------------------------------------------
 * HCI_Config()
 *
 *    Initiates the sequence of commands for negotiating HCI Flow Control 
 *    including the following: 
 *      HCC_READ_BUFFER_SIZE, 
 *      HCC_SET_CTRLR_TO_HOST_FLOW_CTRL,
 *      HCC_HOST_BUFFER_SIZE, 
 *      HCC_WRITE_SCO_FC_ENABLE 
 *    When the process is completed, callbacks of one of these commands will
 *    indicate to the ME that the HCI is initialized vi HCI_RadioInitialized. 
 *
 * Returns:
 *     BT_STATUS_PENDING - HCI is now initializing the Host Controller.  
 *         When initialization is complete, the Management Entity will be 
 *         called with an HCI_INIT_STATUS event. The "status" field will 
 *         indicate whether the intialization was successful.
 */
BtStatus HCI_Config(void);

/*---------------------------------------------------------------------------
 * HCI_RegisterRadioHandler()
 *
 *     Called by the Radio Manager to register a radio handler.  Radio
 *     handlers are modules that send vendor specific commands and handle
 *     events required to properly initialize a radio.  Only one handler is
 *     allowed to be registered at a time (since only one radio is supported
 *     at a time).  A handler must be registered before the HCI is initialized.
 *
 *     Once the HCI is properly initialized, the handler will be called with 
 *     an HCI_INIT_STATUS event.  At this time the handler can begin to send 
 *     any vendor specific events that it requires.
 *
 * Parameters:
 *     radioHandlerCallback - Radio handler callback entry point.  This parameter
 *         should contain a pointer to the radio handler's callback function.
 *
 * Returns:
 *     BT_STATUS_SUCCESS - The radio handler callback was successfully
 *         registered with HCI.
 *
 *     BT_STATUS_FAILED - The radio handler was not registered, because the HCI
 *         has already been initialized.
 */
void HCI_RegisterRadioHandler(RadioHandlerCallback radioHandlerCallback);

/*---------------------------------------------------------------------------
 * HCI_DeregisterRadioHandler()
 *
 *     Called by the transport driver to deregister a radio handler.  Radio
 *     handlers are modules that send vendor specific commands and handle
 *     events required to properly initialize a radio.  Once this function is
 *     called, the HCI will no longer call the radio handler, but direct
 *     events to the ME.
 *
 * Parameters:
 *     void
 *
 * Returns:
 *     void
 */
void HCI_DeregisterRadioHandler(void);

#define HCI_DeregisterRadioHandler() HCI_RegisterRadioHandler(0)

/*---------------------------------------------------------------------------
 * HCI_RadioInitialized()
 *
 *     Called by the radio manager to indicates to the HCI that radio 
 *     initialization is complete.
 *
 * Parameters:
 *     Status - Tells the status of initialization.  If successful, then
 *         the HCI is operational.  If not successful, then initialization
 *         failed.
 *
 * Returns:
 *     void
 */
void HCI_RadioInitialized(BtStatus Status);

/*---------------------------------------------------------------------------
 * HCI_RadioDeinitialized()
 *
 *     Called by the radio manager to indicates to the HCI that radio 
 *     deinitialization is complete.
 *
 * Parameters:
 *     void
 *
 * Returns:
 *     void
 */
void HCI_RadioDeinitialized(void);

/*---------------------------------------------------------------------------
 * HCI_SendCommand()
 *
 *     Starts sending a command to the host controller. After the command
 *     is completely sent to the host controller, HCI calls ME_Callback
 *     with the HCI_COMMAND_HANDLED callback event type. The callback
 *     parameters contain the command that was sent (in "ptr.cmd") and
 *     the success of the operation (in "status").
 *
 *     In response to the command, the host controller will send one
 *     or more events. These events are also passed to the ME_Callback
 *     function as described by the HciCallbackType HCI_CONTROLLER_EVENT
 *     type.
 *
 *     Before calling this function, the command's "parms" field must
 *     be filled with the appropriate command-specific parameters as
 *     defined in the Bluetooth specification. Filling the "header"
 *     field is not required.
 *
 * Parameters:
 *    opCode - The type of HCI command to send. 
 *
 *    parmLen - The length of the command parameters.  The command
 *        parameter block is located in the HciCommand structure.
 *
 *    cmd - the command structure. The "cmd->parm" field must be filled
 *        with command-specific parameters.
 *
 * Returns:
 *    BT_STATUS_PENDING - the command was accepted by the HCI. The
 *        upper layer will be notified at a later time of the command
 *        completion and/or status.
 *
 *    BT_STATUS_INVALID_PARM - the "cmd" parameter is not valid 
 *        (XA_ERROR_CHECK only).
 */

BtStatus MeSendHciCommandRaw(HciCommandType opCode, U8 parmLen);

#if defined(__ENABLE_STACK_SEC__)
void BT_Xfile_PrintOpcode(U16 opcode);

#define MeSendHciCommand(a, b) \
    MEC(curTask) = a; \
    BT_Xfile_PrintOpcode(a);\
    MeSendHciCommandRaw((HciCommandType)(((a & 0x00FF) ^ BT_XFileGetKey0()) | ((((a & 0xFF00)>>8)^ BT_XFileGetKey1()) << 8)), b)
#else
void HCI_PrintOpcode(U16 opcode);

#define MeSendHciCommand(a, b) \
    MEC(curTask) = a; \
    HCI_PrintOpcode(a);\
    MeSendHciCommandRaw((HciCommandType)(((a & 0x00FF) ^ 0) | ((((a & 0xFF00)>>8)^ 0) << 8)), b)
#endif /* __ENABLE_STACK_SEC__ */


#ifdef __ENABLE_SLEEP_MODE__
void HciHostWakeupRetryHandler(EvmTimer *timer);
#endif
void HciRadioWakeupRetryHandler(EvmTimer *timer);

#if HCI_ALLOW_PRESCAN == XA_ENABLED
/*---------------------------------------------------------------------------
 * HCI_RegisterPrescan()
 *
 *     Used to register functions that examine HCI data before it is
 *     transmitted to the radio and when it is received from the radio.  This
 *     can be used for debugging (as in sniffer.c) or to actually modify
 *     HCI data in cases where the formatting of the data needs to be (or is)
 *     different than the current Bluetooth spec.  This call may be called
 *     only after the stack initialization completes (EVM_Init returns).  It
 *     should NOT be called at interrupt time or during the execution of the
 *     high-priority driver thread (see OS_StopHardware).
 *
 * Parameters:
 *     Handler - Structure that contains entry points to the prescan handlers.
 *               The hciTxPrescan, hciTxDone, hciRxPrescan, and hciRxDone 
 *               fields must be initialized before calling this function.  
 *               Multiple handlers can be registered and will be called in 
 *               the order that they are registered.  A NULL value can be
 *               assigned to an entry point to indicate that no prescan
 *               is required for that particular function.
 *
 *     Flags - The Flags describe how the prescan structure will be
 *             registered.  One of the following values should be used:
 *
 *             PRESCAN_FLAG_LAST (default) - If this flag is used, the prescan
 *                 will be registered at the end of the current list. 
 *
 *             PRESCAN_FLAG_FIRST - If this flag is set, the prescan will
 *                 be registered at the front of the current list.
 *
 * Returns:
 *     BT_STATUS_SUCCESS - The handler was registered successfully.
 *
 *     BT_STATUS_INVALID_PARM - The Handler structure was not properly 
 *         initialized.              
 *
 *     BT_STATUS_IN_USE - The handler was not registered, because it is 
 *         already in use.
 */
BtStatus HCI_RegisterPrescan(HciPrescanHandler *Handler, HciPrescanFlags Flags);

/*---------------------------------------------------------------------------
 * HCI_UnegisterPrescan()
 *
 *     Used to unregister the prescan handler (see HCI_RegisterPrescan()).
 *
 * Parameters:
 *     Handler - Structure that contains entry points to the prescan handlers.
 *
 * Returns:
 *     BT_STATUS_SUCCESS - The handler was unregistered successfully.
 *
 *     BT_STATUS_INVALID_PARM - The Handler structure was not valid.
 *
 *     BT_STATUS_FAILED - The handler was not registered, and could not be
 *         unregistered.
 */
BtStatus HCI_UnregisterPrescan(HciPrescanHandler *Handler);
#endif /* HCI_ALLOW_PRESCAN == XA_ENABLED */

/****************************************************************************
 *
 * Function Reference - Internal functions.
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * HCI_RequestToSend()
 *
 *     Called to notify HCI that the Management Entity has SCO or ACL
 *     data ready to send.  Must only be called when the stack is already locked.
 *
 *     Later, when HCI is running on the stack thread and is able to
 *     send, it will call ME_Callback with the HCI_SEND_IND event. The
 *     callback parameters will contain the requested HciHandle to
 *     indicate which connection is ready for data.
 *
 *     During the callback, the "packet" field of the callback
 *     parameters structure is filled with a BtPacket to be sent,
 *     or filled with NULL to indicate that no more packets to send
 *     on that connection. The HCI layer will continue to generate
 *     HCI_SEND_IND events until the "packet" field is returned
 *     as NULL.
 *
 *     When a packet has been completely sent to the Host Controller,
 *     the HCI calls ME again with an HCI_PACKET_HANDLED event.
 *     The "packet" callback parameters field contains a pointer to
 *     the packet that was transmitted.  The "status" field indicates
 *     whether the packet was sent successfully.
 *     
 *     Requests to send on multiple simultaneous connections are
 *     allowed.
 *     
 * Parameters:
 *     handle - Data is ready to be transmitted for this HCI connection
 *         handle.
 *
 * Returns:
 *     BT_STATUS_SUCCESS - The request was successful
 * 
 *     BT_STATUS_FAILED - The request failed because the connection
 *         associated with handle could not be found.
 */
BtStatus HCI_RequestToSend(HciHandle handle);

/****************************************************************************
 *
 * Function Reference - Lower-layer functions
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * HCI_Process()
 *
 *     Called by EVM_Process() to give a thread of execution to the
 *     Bluetooth stack. During this call, all received data and events
 *     are processed. Requests to send data or commands are handled as well.
 *     Must only be called when the stack is already locked.
 */
void HCI_Process(void);
BOOL HciCheckWifiSetting(void);
void HCI_WifiCommandTimeoutHandler(EvmTimer *Timer);
U8 BTQueryPowerOnState(void);

#if defined(__ENABLE_STACK_SEC__)
U8 HCI_IsValidAclPacketCount(U16 packetLeft);
U8 HCI_IsValidAclPacket(void);
U8 HCI_IsValidAclPacketLen(void);
U8 HCI_IsValidScoPacketLen(void);
#endif /* __ENABLE_STACK_SEC__ */

#ifdef __TINY_SYS__
void HCI_TinyInit(void);
#endif
#endif /* __HCI_H */ 

