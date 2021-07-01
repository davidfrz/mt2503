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

#ifndef __RFCOMM_ADP_H
#define __RFCOMM_ADP_H

/****************************************************************************
 *
 * File:
 *     $Workfile:rfcomm.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #1 $
 *
 * Description:
 *     Public types, defines, and prototypes for accessing the
 *     RFCOMM component.
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
#include "me_adp.h"
#include "sec_adp.h"
#include "eventmgr.h"

#if RFCOMM_PROTOCOL == XA_ENABLED
/*---------------------------------------------------------------------------
 * RFCOMM layer
 *
 *     RFCOMM is a protocol that emulates a number of serial ports over
 *     the L2CAP protocol. RFCOMM is based on another standard (ETSI's
 *     TS 07.10 standard, version 6.3.0) and also contains some
 *     Bluetooth-specific adaptations.
 *
 *     RFCOMM supports up to 60 multiplexed ports (each of which is
 *     known as an RFCOMM channel) for each device connection. However,
 *     the total number of channels is limited by this implementation
 *     to conserve RAM. (See the NUM_RF_CHANNELS configuration.)
 *
 *     RFCOMM may also be used to emulate RS-232 control signals and
 *     baud rate changes.
 */

/****************************************************************************
 *
 * Constants
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * RF_MIN_FRAME_SIZE constant
 *
 *     Defines the smallest maximum frame size allowed for an RFCOMM
 *     connection. The frame size is stored in the RfChannel structure
 *     before calling RF_OpenClientChannel.  After a connection is
 *     established, the frame size for a channel can be retrieved with
 *     RF_FrameSize.  The frame size in RFCOMM applies to both receive
 *     and transmit data.
 *
 *     Any RF_SendData call that specifies a packet larger than the
 *     negotiated frame size will fail.
 */
#define RF_MIN_FRAME_SIZE 23

/*---------------------------------------------------------------------------
 * RF_DEFAULT_FRAMESIZE constant
 *
 *     Defines the default frame size for RFCOMM channels.
 */
#define RF_DEFAULT_FRAMESIZE 127

/*---------------------------------------------------------------------------
 * RF_DEFAULT_PRIORITY constant
 *
 *     Identifies the default priority for an RFCOMM channel. The priority
 *     for a channel is stored in the RfChannel structure before calling
 *     RF_RegisterServerChannel or RF_OpenClientChannel.
 *
 *     Higher channel priorities correspond to lower values.
 */
#define RF_DEFAULT_PRIORITY  0

/*---------------------------------------------------------------------------
 * RF_LOWEST_PRIORITY constant
 *
 *     Identifies the lowest possible priority for an RFCOMM channel.
 *     Lower channel priorities correspond to higher priority values.
 */
#define RF_LOWEST_PRIORITY   63

/****************************************************************************
 *
 * Types
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * RfEvent type
 *
 *     All indications and confirmations are sent through a callback
 *     function as events. The type of event will determine which
 *     fields in the RfCallbackParms structure are valid.
 */
typedef U8 RfEvent;

/** A remote device has requested a connection to a local RFCOMM service.
 * Call RF_AcceptChannel to indicate whether the channel should be opened.
 * This call can be made during or after the callback.
 * The remote device associated with the channel is provided in "ptrs.remDev."
 */
#define RFEVENT_OPEN_IND              1

/** A channel is now open and ready for data exchange. The remote device
 *  associated with the channel is provided in "ptrs.remDev."
 */
#define RFEVENT_OPEN                  2

/** A request to close a channel was received. The remote device
 *  associated with the channel is provided in "ptrs.remDev."
 */
#define RFEVENT_CLOSE_IND             3

/** The channel is closed. The remote device
 *  associated with the channel is provided in "ptrs.remDev."
 */
#define RFEVENT_CLOSED                4

/** Data was received from the remote device. The "dataLen" and "ptrs.data"
 * fields describe the received data.
 */
#define RFEVENT_DATA_IND              5

/** RFCOMM is finished with the data packet provided in "ptrs.packet".
 * The RFCOMM user may reuse the packet structure to send more data.
 *
 * The "status" field indicates whether the packet was sent successfully
 * (BT_STATUS_SUCCESS) or if an error occurred (BT_STATUS_NO_CONNECTION).
 */
#define RFEVENT_PACKET_HANDLED        6

#if RF_SEND_TEST == XA_ENABLED
/** The remote device has responded to a test sent by RF_SendTest.
 * The "status" field contains BT_STATUS_SUCCESS if the test succeeded,
 * or BT_STATUS_FAILED if the response did not match.
 *
 * This event is only available when RF_SEND_TEST is enabled.
 */
#define RFEVENT_TEST_CNF              7
#endif /* RF_SEND_TEST == XA_ENABLED */

/** The remote device has requested negotiation of port settings. The
 * requested settings are in "ptrs.portSettings". The relevant parameters
 * for this indication are identified in "ptrs.portSettings->parmMask".
 *
 * After reviewing all relevant parameters, the RFCOMM user must
 * call RF_AcceptPortSettings to indicate which parameters were accepted
 * or rejected.  Either RF_AcceptPortSettings or RF_DelayPortRsp must be
 * called during the callback.  If RF_DelayPortRsp is called, then the
 * processing of this event can be handled outside the context of the
 * callback.  If processing is delayed, it is important that the application
 * call RF_AcceptPortSettings within 10 seconds to prevent a link disconnect
 * by the remote device.
 *
 * If neither RF_AcceptPortSettings nor RF_DelayPortRsp are called during
 * the callback, the requested parameters are considered to be accepted
 * and a response will be generated automatically.  Port settings are only
 * used for RS232 emulation and have no real effect on the data format
 * or flow control at the RFCOMM layer.
 *
 * It is possible for a registered service to receive a port negotiation
 * before the channel is actually open (RFEVENT_OPEN). If a port
 * negotiation is never received by the application, default values
 * should be assumed: 9600 baud, 8 bits, 1 stop bit, no parity, and no
 * port flow control.
 */
#define RFEVENT_PORT_NEG_IND          8

#if RF_SEND_CONTROL == XA_ENABLED
/** A port settings negotiation request (started with RF_RequestPortSettings)
 * is now complete. During this event, the "ptrs.portSettings->parmMask"
 * field contains bits that indicate which parameters were accepted by the
 * remote device.
 *
 * This event is only available when RF_SEND_CONTROL is enabled.
 */
#define RFEVENT_PORT_NEG_CNF          9
#endif /* RF_SEND_CONTROL == XA_ENABLED */

/** The remote device has requested the status of the port settings.  The
 * application must respond with its current port settings by calling
 * RF_SendPortStatus.  Either RF_SendPortStatus or RF_DelayPortRsp must be
 * called during the callback.  If RF_DelayPortRsp is called, then the
 * processing of this event can be handled outside the context of the
 * callback.  If processing is delayed, it is important that the application
 * call RF_SendPortStatus within 10 seconds to prevent a link disconnect
 * by the remote device.
 *
 * If the application does not respond to this event during the callback,
 * the response will be generated  automatically with the default Serial Port
 * Profile settings of: 9600 baud, 8 data bits, 1 stop bit, and no parity.
 */
#define RFEVENT_PORT_STATUS_IND       10

#if RF_SEND_CONTROL == XA_ENABLED
/** The remote device has responded to a request for its current port
 * status.  This happens in response to RF_RequestPortStatus.  The relevant
 * parameters for this indication are identified in "ptrs.portSettings".
 *
 * This event is only available when RF_SEND_CONTROL is enabled.
 */
#define RFEVENT_PORT_STATUS_CNF       11
#endif /* RF_SEND_CONTROL == XA_ENABLED */

/** The remote device has provided modem status. The new status settings
 * are in "ptrs.modemStatus".
 */
#define RFEVENT_MODEM_STATUS_IND      12

/** The remote device has acknowledged new modem status settings. The RFCOMM
 * user sent these settings with the RF_SetModemStatus function.
 */
#define RFEVENT_MODEM_STATUS_CNF      13

#if RF_SEND_CONTROL == XA_ENABLED
/** The remote device has provided line status information. The new
 * line status settings are in "ptrs.lineStatus".
 *
 * This event is only available when RF_SEND_CONTROL is enabled.
 */
#define RFEVENT_LINE_STATUS_IND       14

/** RFCOMM has finished sending line status to the remote device. The RFCOMM
 * user sent these settings with the RF_SetLineStatus function.
 *
 * This event is only available when RF_SEND_CONTROL is enabled.
 */
#define RFEVENT_LINE_STATUS_CNF       15

#endif /* RF_SEND_CONTROL == XA_ENABLED */

/** The remote device has indicated that no RFCOMM data can be processed.
 * This indication affects all RFCOMM channels.  This event will only
 * be received if credit-based flow control has not been negotiated.
 */
#define RFEVENT_FLOW_OFF_IND          16

/** The remote device has indicated that RFCOMM data can be processed again.
 * This indication affects all RFCOMM channels.  This event will only
 * be received if credit-based flow control has not been negotiated.
 */
#define RFEVENT_FLOW_ON_IND           17

/** A resource is available for use by RF_AcceptPortSettings or
 *  RF_SendPortStatus.  If either of these functions returns
 *  BT_STATUS_NO_RESOURCES, this event will be sent to indicate that a
 *  resource is now available.
 */
#define RFEVENT_RESOURCE_FREE         18

/* End of RfEvent */

/*---------------------------------------------------------------------------
 * RfSignals type
 *
 *     Specifies signal types in an RfModemStatus structure.
 */
typedef U8 RfSignals;

/*
 * Group: Any of the following signals may be set or clear. They represent
 * standard TS 7.10 Terminology for expressing each possible signal.
 */
#define RF_FLOW  0x02   /*
                         * Set when sender is unable to receive frames. 
                         * This is only used when credit-based flow control 
                         * has not been negotiated. 
                         */
#define RF_RTC   0x04   /* Set when sender is ready to communicate.     */
#define RF_RTR   0x08   /* Set when sender is ready to receive data.    */
#define RF_IC    0x40   /* Set when a call is incoming.        */
#define RF_DV    0x80   /* Set when valid data is being sent.  */

/*
 * Group: The following signal names represent a subset of the TS 7.10 signals
 * above. They represent the signals that a DCE would send to a DTE device.
 */
#define RF_DSR   0x04
#define RF_CTS   0x08
#define RF_RI    0x40
#define RF_CD    0x80

/*
 * Group: The following signal names represent a subset of the TS 7.10 signals
 * above. They represent the signals that a DTE would send to a DCE device.
 */
#define RF_DTR   0x04
#define RF_RTS   0x08

/* End of RfSignals */

/*---------------------------------------------------------------------------
 * RfBaudRate type
 *
 *     Specifies the baud rate in an RfPortSettings structure. Note that
 *     the baud rate setting does not actually affect RFCOMM throughput.
 */
typedef U8 RfBaudRate;

#define RF_BAUD_2400         0x00
#define RF_BAUD_4800         0x01
#define RF_BAUD_7200         0x02
#define RF_BAUD_9600         0x03
#define RF_BAUD_19200        0x04
#define RF_BAUD_38400        0x05
#define RF_BAUD_57600        0x06
#define RF_BAUD_115200       0x07
#define RF_BAUD_230400       0x08

/* End of RfBaudRate */

/*---------------------------------------------------------------------------
 * RfDataFormat type
 *
 *     Specifies the data bits, stop bits, and parity in an RfPortSettings
 *     structure. The data bits, stop bits, and parity settings are OR'ed
 *     together in the "dataFormat" field.
 */
typedef U8 RfDataFormat;

/* Group: These values identify the number of data bits. */
#define RF_DATA_BITS_5       0x00
#define RF_DATA_BITS_6       0x02
#define RF_DATA_BITS_7       0x01
#define RF_DATA_BITS_8       0x03

/* Group: These values identify the number of stop bits. */
#define RF_STOP_BITS_1       0x00
#define RF_STOP_BITS_1_5     0x04

/* Group: These values identify whether of parity is used. */
#define RF_PARITY_NONE       0x00
#define RF_PARITY_ON         0x08

/*
 * Group: These values identify the type of parity in use. Note that
 * these values have no effect unless parity is enabled (RF_PARITY_ON).
 */
#define RF_PARITY_TYPE_ODD        0x00
#define RF_PARITY_TYPE_EVEN       0x20
#define RF_PARITY_TYPE_MARK       0x10
#define RF_PARITY_TYPE_SPACE      0x30

/*
 * Group: These masks allow you to select only the relevant bits from
 * the "dataFormat" field.
 */

/* AND with "dataFormat" for the data bits setting. */
#define RF_DATA_BITS_MASK    0x03

/* AND with "dataFormat" for the stop bits setting. */
#define RF_STOP_BITS_MASK    0x04

/* AND with "dataFormat" to determine whether parity is on.  */
#define RF_PARITY_MASK       0x08

/* AND with "dataFormat" to determine the type of parity selected. */
#define RF_PARITY_TYPE_MASK  0x30

/* End of RfDataFormat */

/*---------------------------------------------------------------------------
 * RfFlowControl type
 *
 *     Specifies the port flow control type in an RfPortSettings structure.
 *     This refers to flow control for RS232 emulation and not to the actual
 *     flow control of RFCOMM data which is controlled by either credit-based
 *     flow control (if negotiated), aggregate flow control (FCON/FCOFF), or
 *     the FC bit in the Modem Status Command.
 */
typedef U8 RfFlowControl;

#define RF_FLOW_CTRL_NONE    0x00
#define RF_XON_ON_INPUT      0x01
#define RF_XON_ON_OUTPUT     0x02
#define RF_RTR_ON_INPUT      0x04
#define RF_RTR_ON_OUTPUT     0x08
#define RF_RTC_ON_INPUT      0x10
#define RF_RTC_ON_OUTPUT     0x20

/*
 * Group: These symbols define common combinations of port flow control
 * settings used in RS232 emulation
 */
#define RF_FLOW_RTS_CTS      (RF_RTR_ON_INPUT | RF_RTR_ON_OUTPUT)
#define RF_FLOW_DTR_DSR      (RF_RTC_ON_INPUT | RF_RTC_ON_OUTPUT)
#define RF_FLOW_XON_XOFF     (RF_XON_ON_INPUT | RF_XON_ON_OUTPUT)

/* End of RfFlowControl */

/*---------------------------------------------------------------------------
 * RfPortSettingsMask type
 *
 *     Used to specify which settings in an RfPortSettings structure are
 *     valid.  Port settings are used for RS232 emulation.
 */
typedef U16 RfPortSettingsMask;

/* The "baudRate" field is valid. */
#define RF_PARM_BAUDRATE     0x0001

/* The RF_DATA_BITS_* part of the "dataFormat" field is valid. */
#define RF_PARM_DATABITS     0x0002

/* The RF_STOP_BITS_* part of the "dataFormat" field is valid. */
#define RF_PARM_STOPBITS     0x0004

/*
 * The RF_PARITY_NONE or RF_PARITY_ON part of the "dataFormat" field is
 * valid.
 */
#define RF_PARM_PARITY       0x0008

/* The RF_PARITY_* part of the "dataFormat" field is valid. */
#define RF_PARM_PARITY_TYPE  0x0010

/* All elements in the "dataFormat" field are valid. */
#define RF_PARM_DATA_FORMAT  (RF_PARM_DATABITS | RF_PARM_STOPBITS | \
                              RF_PARM_PARITY | RF_PARM_PARITY_TYPE)

/* The "xonChar" field is valid. */
#define RF_PARM_XON_CHAR     0x0020

/* The "xoffChar" field is valid. */
#define RF_PARM_XOFF_CHAR    0x0040

/*
 * Group: The following fields identify whether specific bits in the
 * "flowControl" field are valid. They are equivalent to the values
 * described in the RfFlowControl type.
 */
#define RF_PARM_XON_INPUT    0x0100
#define RF_PARM_XON_OUTPUT   0x0200
#define RF_PARM_RTR_INPUT    0x0400
#define RF_PARM_RTR_OUTPUT   0x0800
#define RF_PARM_RTC_INPUT    0x1000
#define RF_PARM_RTC_OUTPUT   0x2000

#define RF_PARM_FLOW_RTS_CTS  (RF_PARM_RTR_INPUT | RF_PARM_RTR_OUTPUT)
#define RF_PARM_FLOW_DTR_DSR  (RF_PARM_RTC_INPUT | RF_PARM_RTC_OUTPUT)
#define RF_PARM_FLOW_XON_XOFF (RF_PARM_XON_INPUT | RF_PARM_XON_OUTPUT)

/* End of RfPortSettingsMask */

/*---------------------------------------------------------------------------
 * RfLineStatus type
 *
 *     Represents the line status. Line status is set using the
 *     RF_SetLineStatus function. If the remote device changes the line
 *     status, an RfLineStatus value will be received during an
 *     RFEVENT_LINE_STATUS_IND event.
 */
typedef U8 RfLineStatus;

/*
 * When set, one or more errors have occurred. Any of the following bits
 * may be set to indicate an error. If RF_LINE_ERROR is clear, no error
 * has occurred, regardless of the state of the other bits.
 */
#define RF_LINE_ERROR  0x01
#define RF_OVERRUN     0x02     /* Set to indicate an overrun error. */
#define RF_PARITY      0x04     /* Set to indicate a parity error. */
#define RF_FRAMING     0x08     /* Set to indicate a framing error. */

/* End of RfLineStatus */

/*---------------------------------------------------------------------------
 * RfAggregateFlow type
 *
 *     Represents a state for a particular device's aggregate RFCOMM flow
 *     control.
 */
typedef U8 RfAggregateFlow;

/*
 * Flow control is off; the remote device has requested that no data be
 * sent to its RFCOMM channels.  This is only used when credit-based
 * flow control has not been negotiated.
 *
 */
#define RF_FLOW_OFF  FALSE

/*
 * Flow control is on; the remote device is allowing data on all of its
 * RFCOMM channels.  This is only used when credit-based flow control has
 * not been negotiated.
 */
#define RF_FLOW_ON   TRUE

/* End of RfAggregateFlow */

/* Forward references for callback function */
typedef struct _RfCallbackParms RfCallbackParms;
typedef struct _RfChannel RfChannel;

/*---------------------------------------------------------------------------
 * RfCallback type
 *
 *     Represents a callback function called by RFCOMM to indicate events
 *     and data to the RFCOMM user. The event is targeted to the
 *     RFCOMM channel identified by the "channel" parameter. Information
 *     about the event is contained in the "parms" parameter.
 *
 *     A callback function is provided to RFCOMM by storing it in an
 *     RfChannel structure and calling RF_RegisterServerChannel.
 */
typedef void (*RfCallback)(RfChannel *channel, RfCallbackParms *parms);

/* End of RfCallback */

#if (BT_SECURITY == XA_ENABLED) && (RF_SECURITY == XA_ENABLED)
/*---------------------------------------------------------------------------
 * SEC_RFCOMM_ID
 *
 * Security ID for RFCOMM access.  This value is used to initialize a security
 * record for level 2 security.
 *
 * When registering a security record for RFCOMM, the 'id' field is set to
 * SEC_RFCOMM_ID.
 *
 * The 'channel' field is set to the server ID on incoming connections
 * (see RfService).  When registering a security record for incoming connections,
 * the 'level' field of the security record should only use the following flags:
 *
 *   BSL_AUTHENTICATION_IN
 *   BSL_AUTHORIZATION_IN
 *   BSL_ENCRYPTION_IN
 *
 * For outgoing connections, the 'channel' field is set to the address of the
 * RfChannel structure that will be used to create the client connection.
 * This value must be cast to a U32.  When registering a security record for
 * an outgoing connection, the 'level' field of the security record should only
 * use the following flags:
 *
 *   BSL_AUTHENTICATION_OUT
 *   BSL_AUTHORIZATION_OUT
 *   BSL_ENCRYPTION_OUT
 *
 * See BtSecurityToken and SEC_Register for more information.
 */
#define SEC_RFCOMM_ID (BtProtocolId)RfSecCallback
void RfSecCallback(const BtEvent *Event);
#endif /* (BT_SECURITY == XA_ENABLED) && (RF_SECURITY == XA_ENABLED) */

/* End of RfSecCallback */

/****************************************************************************
 *
 * Data Structures
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * RfPortSettings structure
 *
 *     Represents port settings for an RFCOMM channel. Port settings
 *     are used for RS232 emulation.  They are informational and have
 *     no real effect on the data stream at the RFCOMM level.  To change
 *     port settings for a channel, this structure is filled and provided
 *     to RFCOMM using the RF_RequestPortSettings function.
 *
 *     When the remote device changes port settings, RFCOMM provides
 *     this structure along with the RFEVENT_PORT_NEG_IND event. The
 *     RFCOMM user can then review the settings, then accept or reject
 *     them with RF_AcceptPortSettings.
 *
 *     Fields in this structure may be valid or invalid, depending on
 *     the contents of the "parmMask" field.
 */
typedef struct _RfPortSettings
{
    RfBaudRate baudRate;        /* Indicates the baud rate */
    RfDataFormat dataFormat;    /*
                                 * Contains data bits, stop bits, and
                                 * parity settings.
                                 */
    RfFlowControl flowControl;  /* Indicates port flow control options */
    U8 xonChar;                 /* Indicates the XON character */
    U8 xoffChar;                /* Indicates the XOFF character */

    /*
     * Contains a bitmask of settings.
     *
     * When changing port settings with RF_RequestPortSettings, "parmMask"
     * indicates which port settings are being changed.
     *
     * During an RFEVENT_PORT_NEG_IND event, "parmMask" describes which
     * parameters the remote device sent.
     */
    RfPortSettingsMask parmMask;

} RfPortSettings;

/*---------------------------------------------------------------------------
 * RfModemStatus structure
 *
 * Represents the status of V.24 signals. To send signals on a connection,
 * create and fill in this structure, then call RF_SetModemStatus.
 *
 * When the remote device sends these signals, RFCOMM generates an
 * RFEVENT_MODEM_STATUS_IND event. During this event, you can read the
 * status in the RfCallbackParms "ptrs.modemStatus" field.
 */
typedef struct _RfModemStatus
{
    RfSignals signals;  /*
                         * Contains all signals that apply to this status
                         * message.
                         */
    U8 breakLen;        /*
                         * Indicates the length of the break signal in 200 ms
                         * units. If 0, no break signal was sent. Must be
                         * between 0 and 15 (inclusive).
                         */
} RfModemStatus;

/*---------------------------------------------------------------------------
 * RfCallbackParms structure
 *
 *     Describes a callback event and any data that relates to the event.
 *     Various fields in the structure may be valid or not, depending
 *     on the "event" field.
 */
struct _RfCallbackParms
{
    RfEvent event;      /* Type of the RFCOMM event */
    BtStatus status;    /* Status or error information */
    U16 dataLen;        /*
                         * Length of data (provided during RFEVENT_DATA_IND
                         * events).
                         */

    /*
     * Group: The event type determines whether a field in this
     * union is valid.
     */
    union
    {

        /*
         * During an RFEVENT_PACKET_HANDLED event, contains the previously
         * transmitted packet.
         */
        BtPacket *packet;

        /*
         * During an RFEVENT_DATA_IND event, contains the data received from the
         * remote device.
         */
        U8 *data;

        /*
         * During an RFEVENT_MODEM_STATUS_IND event, contains modem status settings.
         */
        RfModemStatus *modemStatus;

        /*
         * During an RFEVENT_LINE_STATUS_IND event, contains line status settings.
         */
        RfLineStatus *lineStatus;

        /*
         * During an RFEVENT_PORT_NEG_IND, RFEVENT_PORT_NEG_CNF, or
         * RFEVENT_PORT_STATUS_CNF event, contains port settings.
         */
        RfPortSettings *portSettings;

        /* During an RFEVENT_OPEN event, contains the remote device structure */
        BtRemoteDevice *remDev;

    } ptrs;
};

/*---------------------------------------------------------------------------
 * RfService structure
 *
 *     Represents an RFCOMM service entity. An RFCOMM service may offer
 *     one or more channels (one for each remote device it allows).
 *     These channels are added to the service with the
 *     RF_RegisterServerChannel function.
 */
typedef struct _RfService
{
    /*
     * Identifies the ID that corresponds to this service. This ID value
     * must be set to 0 before this structure is first used.
     * After the service has been registered, it contains an RFCOMM ID.
     * Register this ID with SDP so that remote devices can locate
     * this RFCOMM service. This ID can also be used as the channel in
     * BtSecurityRecords (for incoming connections only)
     */
    U8 serviceId;
} RfService;

/*---------------------------------------------------------------------------
 * RfChannel structure
 *
 *     Represents a single RFCOMM channel. The RFCOMM user must create
 *     this structure and fill in the "callback", "maxFrameSize", and
 *     "priority" fields prior to calling RF_OpenClientChannel.  Only the
 *     "callback" filed must be set when calling RF_RegisterServerChannel.
 */
struct _RfChannel
{
    ListEntry node; /* Used internally by RFCOMM. */

    /* Callback function for channel events */
    RfCallback callback;

    /*
     * Frame size for the channel. This value must be between
     * RF_MIN_FRAME_SIZE and RF_MAX_FRAME_SIZE.
     */
    U16 maxFrameSize;

    /*
     * Priority of the channel. Channels with higher priority have smaller
     * "priority" values. Generally, data on higher priority channels is
     * sent before lower priority channels. The priority must be between
     * RF_DEFAULT_PRIORITY (0) and RF_LOWEST_PRIORITY (63).
     */
    U8 priority;

    /*
     * User context.  In some environments the context of the application
     * during a callback is not known.  In these cases, a pointer to the
     * application's context can be stored in userContext and then
     * retrieved during the callback.
     */
    void *userContext;

    /* === Internal use only === */
#if (BT_SECURITY == XA_ENABLED) && (RF_SECURITY == XA_ENABLED)
    BtSecurityToken secToken;
#if (BT_SEC_LEVEL2_SETTING_ENABLED == XA_ENABLED)
    BtSecurityRecord secRecord;
    U8 incoming;
#endif /* (BT_SEC_LEVEL2_SETTING_ENABLED == XA_ENABLED) */
#endif /* (BT_SECURITY == XA_ENABLED) && (RF_SECURITY == XA_ENABLED) */
    BtRemoteDevice *remDev;
    U8 secLevel;
    U8 state;
    U8 muxId;
    U8 dlcId;
    U8 dlci;
    U8 rfChFlags;
    ListEntry txQueue;
    EvmTimer timer;
    U8 cmdSent;
    RfSignals rfSignals;
    S16 rxCredit;
    U16 BusyCredit;
    EvmTimer creditTimer;
    U16 txCredit;
    U8 grantedCredit;
    U8 initialRxCredit;
    U16 initialFrameSize;
};

/*---------------------------------------------------------------------------
 * RF_AdvanceCredit()
 *
 *     Advances transmit credit to the remote device.
 *
 * Parameters:
 *     Channel - Identifies the channel for this action. The channel must
 *         be open for credit to be advanced.
 *
 *     Credit - Each credit value represents one RFCOMM packet.  Advancing n
 *         credits allows the remote device to send n packets.  Once those
 *         packets have been sent, the remote device can no longer send (flow
 *         is off).  Subsequent calls to RF_AdvanceCredit will allow the
 *         remote device to send again (flow is on).  Credits are additive,
 *         so calling this function once with 3 credits and then with 2 credits
 *         will grant a total of 5 credits to the remote device, allowing the
 *         remote device to send 5 RFCOMM packets.
 *
 *         It is important to know that there are two types of flow control
 *         at the RFCOMM protocol layer.  Newer devices use "credit" based
 *         flow control, and older devices use the FC bit in the modem status
 *         command to control flow.  RFCOMM will always try to negotiate
 *         credit-based flow control with a remote device during the connection
 *         process. If that negotiation is successful, then RFCOMM provides
 *         a completely reliable link.  If the negotiation is not successful,
 *         the link is automatically managed by RFCOMM using MSC commands,
 *         based on the credits granted by the application.  It is never
 *         necessary for the application to send an MSC command to control
 *         the flow of data.
 *
 *         Since RFCOMM is running over packet-based protocols, it may not
 *         flow the link off with great precision when forced to use MSC
 *         commands.  In this case, RFCOMM's flow control is unreliable.
 *         It is possible for an application to receive more data packets
 *         than the credits advanced.
 *
 *         Because of this unreliability, some buffer overflow will need to
 *         be allocated for data that is received after the FC bit is sent.
 *         The amount of buffer space to allocate is difficult to calculate,
 *         so some experimentation may be required.  An application, if possible,
 *         should use some higher layer flow control mechanism if greater
 *         precision is required.
 *
 *         Only Bluetooth 1.0B devices (and earlier) will not negotiate
 *         credit flow control.  These devices are fairly scarce.  All
 *         Bluetooth 1.1 compliant devices must support credit flow control.
 *
 *         Call RF_CreditFlowEnabled to determine what type of flow control
 *         has been negotiated.
 *
 * Returns:
 *      BT_STATUS_SUCCESS - Credit was advanced successfully.
 *
 *      BT_STATUS_FAILED - Credit could not be advanced.  Either the maximum
 *          amount of credit was exceeded, or credit flow control is not
 *          enabled.
 *
 *      BT_STATUS_NO_CONNECTION - no RFCOMM connection has been established
 *          yet.  A connection must exist to advance credit.
 *
 *      BT_STATUS_INVALID_PARM - A parameter was invalid or the channel is
 *          not open (XA_ERROR_CHECK only).
 */
BtStatus RF_AdvanceCredit(RfChannel *Channel, U8 Credit);

BtStatus RF_RespondChannel(RfChannel *channel, BOOL flag);

/*---------------------------------------------------------------------------
 * RF_AcceptChannel()
 *
 *     Accepts an incoming request in response to an RFEVENT_OPEN_IND event.
 *     This event occurs when a remote client attempts to connect to a
 *     local RFCOMM server channel. Either this function or RF_RejectChannel
 *     must be used to respond to the connection request.
 *
 * Parameters:
 *     channel - Identifies the channel to be accepted. This channel is
 *         provided to the callback function as a parameter during the
 *         RFEVENT_OPEN_IND event.
 *
 * Returns:
 *     BT_STATUS_PENDING - The accept message will be sent. The application
 *         will receive a RFEVENT_OPEN when the accept message has been sent
 *         and the channel is open.
 *
 *     BT_STATUS_FAILED - The specified channel did not have a pending
 *         connection request or the stack has run out of resources.
 *
 *     BT_STATUS_NO_CONNECTION - No L2CAP connection exists.
 *
 *     BT_STATUS_INVALID_PARM - Invalid parameter (XA_ERROR_CHECK only).
 */
BtStatus RF_AcceptChannel(RfChannel *channel);

#define RF_AcceptChannel(c) RF_RespondChannel(c, TRUE)

/*---------------------------------------------------------------------------
 * RF_RejectChannel()
 *
 *     Rejects an incoming request in response to an RFEVENT_OPEN_IND event.
 *     This event occurs when a remote client attempts to connect to a
 *     local RFCOMM server channel. Either this function or RF_AcceptChannel
 *     must be used to respond to the connection request.
 *
 * Parameters:
 *     channel - Identifies the channel to be rejected. This channel is
 *         provided to the callback function as a parameter during the
 *         RFEVENT_OPEN_IND event.
 *
 * Returns:
 *     BT_STATUS_PENDING - The rejection message has been sent. RFCOMM
 *         will provide an RFEVENT_CLOSED event when the rejection is complete.
 *
 *     BT_STATUS_FAILED - The specified channel did not have a pending
 *         connection request or the stack has run out of resources.
 *
 *     BT_STATUS_INVALID_PARM - Invalid parameter (XA_ERROR_CHECK only).
 */
BtStatus RF_RejectChannel(RfChannel *channel);

#define RF_RejectChannel(c) RF_RespondChannel(c, FALSE)

/*---------------------------------------------------------------------------
 * RF_CloseChannel()
 *
 *     Closes a connected channel between two devices.  When the channel
 *     is closed, the RFCOMM user will receive an RFEVENT_CLOSED event.
 *
 *     If it is used to close a connecting channel, then BT_STATUS_SUCCESS will
 *     be returned, and there is no RFEVENT_CLOSED event to notify RFCOMM user.
 *
 *     If outstanding transmit packets exist when a channel is closed,
 *     they will be returned to the RFCOMM user with RFEVENT_PACKET_HANDLED
 *     events. The "status" field for these events will be set to
 *     BT_STATUS_NO_CONNECTION.  All packets are returned to the application
 *     before the RFEVENT_CLOSED event is received.
 *
 * Parameters:
 *     channel - Identifies the channel to be closed. If it is a server
 *         channel, the RFEVENT_CLOSED event indicates that the connection
 *         is closed and a new client may attempt to connect to the channel.
 *
 *         If "channel" is a client channel, RFEVENT_CLOSED indicates that
 *         the connection is closed and channel structure can be re-used
 *         or deallocated.
 *
 * Returns:
 *     BT_STATUS_SUCCESS - The channel is closed successfully.
 *
 *     BT_STATUS_PENDING - The request to close the channel will be sent.
 *         The application will receive an RFEVENT_CLOSED event when the
 *         channel is closed.
 *
 *     BT_STATUS_IN_PROGRESS - RFCOMM is already in the process of closing.
 *
 *     BT_STATUS_FAILED - The channel is not in the correct state.
 *
 *     BT_STATUS_INVALID_PARM - Invalid parameter (XA_ERROR_CHECK only).
 */
BtStatus RF_CloseChannel(RfChannel *Channel);

#endif /* RFCOMM_PROTOCOL == XA_ENABLED */
#endif /* __RFCOMM_ADP_H */