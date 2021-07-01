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

#ifndef __LE_ADP_H
#define __LE_ADP_H

#include "metypes.h"
#include "lei.h"

#define GET_BTDEVTYPE(x)  (x&0x0f)
#define GET_BTLETYPE(x)   ((x&0xf0)>>4)
#define GET_BTLINKTYPE(x,y)   ((x&0x0f)|(y&0x0f)<<4)

// LE address type
#define BT_LE_TYPE_PUBLIC                   0x0
#define BT_LE_TYPE_RANDOM                   0x1

// For setting the lcoal address 
typedef unsigned char  BtAddSetType;

#define BT_ADDR_SET_TYPE_LE_RANDOM_STATIC           0x10
#define BT_ADDR_SET_TYPE_LE_RANDOM_PRIVATE_NONRESOL 0x20
#define BT_ADDR_SET_TYPE_LE_RANDOM_PRIVATE_RESOL    0x40

typedef enum
{
    BLF_ENCRYPTION = 0,
    /* 4.1 features */
    /* Connection Parameters Request Procedure */
    BLF_CONN_PARAM_REQ = 1,
    /* Extended Reject Indication */
    BLF_EXT_REJECT_IND = 2,
    /* Slave-initiated Features Exchange */
    BLF_SLAVE_INIT_FEAT_EXCHANGE = 3,
    /* LE Ping */
    BLF_PING = 4,
} BtLEFeature;

/* ------------------------------------------------------ *
 *                       SM related definition            *
 * ------------------------------------------------------ */
#define SM_CONFIRM_VALUE_LENGTH 16
#define SM_RANDOM_VALUE_LENGTH 16
#define SM_STK_VALUE_LENGTH 16
#define SM_LTK_VALUE_LENGTH 16
#define SM_IRK_VALUE_LENGTH 16
#define SM_CSRK_VALUE_LENGTH 16
#define SM_EDIV_VALUE_LENGTH 2
#define SM_RAND_VALUE_LENGTH 8
#define SM_SIGNATURE_LENGTH 12
#define SM_MAC_LENGTH 8

typedef enum
{
    SM_KEY_LTK  = 0x01,
    SM_KEY_EDIV = 0x02,
    SM_KEY_RAND = 0x04,
    SM_KEY_IRK  = 0x08,
    SM_KEY_ADDR = 0x10,
    SM_KEY_CSRK = 0x20
} SmKeyType;

typedef enum
{
    SM_IO_CAPABILITY_DISPLAY_ONLY,        /* 0x00 */
    SM_IO_CAPABILITY_DISPLAY_YESNO,       /* 0x01 */
    SM_IO_CAPABILITY_KEYBOARD_ONLY,       /* 0x02 */
    SM_IO_CAPABILITY_NO_INPUT_NO_OUTPUT,  /* 0x03 */
    SM_IO_CAPABILITY_KEYBOARD_DISPLAY     /* 0x04 */
} SmIOCapability;

typedef enum
{
    SM_OOB_DATA_PRESENT_NO,        /* 0x00 */
    SM_OOB_DATA_PRESENT_YES        /* 0x01 */
} SmOOBFlag;

typedef enum
{
    SM_BONDING_NO,        /* 0x00 */
    SM_BONDING_YES        /* 0x01 */
} SmBondingFlag;

typedef struct
{
    BOOL mitm;
    SmOOBFlag oob;
    SmBondingFlag bond;
    U8 *service_list;
    U8 service_no;
} SmPairAttribute;
/* ------------------------------------------------------ *
 *                  LE related API prototype              *
 * ------------------------------------------------------ */
void LE_Init(void);

void LeUtilsUpdateLocalDevName(const U8 *name, U8 length);
BOOL LeUtilsComposeAdvParams(LeAdvParamMask mask, LeAdvParam *inParam, LeAdvParam *outParam);
U8 leUtilComposeAdvertiseData(U8 *buf, U32 bufLen, LeAdvDataTypeMask mask, LeAdvDataType *advData);
U8 leUtilComposeScanRspData(U8 *buf, U32 bufLen, LeAdvDataTypeMask mask, LeAdvDataType *advData);
BtStatus leUtilUpdateAdvertiseData(LeAdvDataTypeMask advMask, LeAdvDataType *advData);
BtStatus leUtilUpdateAdvertiseParams(LeAdvParamMask advParamsMask, LeAdvParam *advParams);

LeHciCmd *LeFindHciToken(BtOperation *op);

void LeHciSetEventMask(U8 *mask);
void LeHciReadBufferSize(void);
void LeHciReadLocalFeatures(void);
void LeHciSetRandomAddress(BD_ADDR bdAddr);
void ME_LeHciSetupRandomAddress(BD_ADDR bdAddr);
void LeHciSetAdvertiseParm(U16 intervalMin,
                           U16 intervalMax,
                           HciLeAdvertiseType type,
                           LeAddrType ownAddrType,
                           LeAddrType directAddrType,
                           BD_ADDR bdAddr,
                           LeAdvChannelType channelMap,
                           HciLeAdvertiseFilter filter);
void LeHciReadAdvertiseTxPower(void);
void LeHciSetAdvertiseData(U8 dataLen, U8 *data);
void LeHciSetScanRspData(U8 dataLen, U8 *data);
BtStatus LeHciSetAdvertiseEnable(BOOL enable);
void LeHciSetScanParm(HciLeScanType type, U16 interval, U16 window, LeAddrType ownAddrType, HciLeScanFilter filter);
BtStatus LeHciSetScanEnable(BOOL enable, BOOL filterDup);
BtStatus LeHciCreateConnection(struct _BtRemoteDevice *remDev,
                               U16 scanInterval,
                               U16 scanWindow,
                               HciLeInitiatorFilter filter,
                               LeAddrType peerAddrType,
                               BD_ADDR *peerAddr,
                               LeAddrType ownAddrType,
                               U16 connIntervalMin,
                               U16 connIntervalMax,
                               U16 connLatency,
                               U16 supervisionTO,
                               U16 CEMin,
                               U16 CEMax);
void LeHciCreateConnectionCancel(void);
void LeHciReadWhiteListSize(void);
void LeHciClearWhiteList(void);
void LeHciAddToWhiteList(LeAddrType addrType, BD_ADDR bdAddr);
void LeHciRemoveFromWhiteList(LeAddrType addrType, BD_ADDR bdAddr);
U8 LeHciUpdateConnection(U16 handle, U16 intervalMin, U16 intervalMax, U16 latency, U16 sTimeout, U16 ceMin, U16 ceMax);
void LeHciSetChannelMap(U8 *map);
void LeHciReadChannelMap(U16 handle);
void LeHciReadRemoteFeatures(U16 handle);
BtStatus LeHciAES128Encrypt(BtCallBack cb, U8 *key, U8 *data);
BtStatus LeHciRand(BtCallBack cb);
BtStatus LeHciStartEncryption(U16 hciHandle, U64 random, U16 ediv, U8 *ltk);
void LeHciLTKRequestReply(U16 hciHandle, U8 *ltk);
void LeHciLTKRequestNegReply(U16 hciHandle);
void LeHciReadSupportedStates(void);
void LeHandleEvents(U8 len, U8 *parm);
void LeHandleOp(BtOpEvent event);
void LeHandleSetScanParmOp(BtOpEvent event);
void LeHandleSetScanEnabledOp(BtOpEvent event);
void LeHandleConnectTimeout(EvmTimer *timer);
void LeHciReceiverTest(U8 rxFreq);
void LeHciTransmitterTest(U8 txFreq, U8 len, U8 payload);
void LeHciTestEnd(void);
void LeUpdateConnDevList(LeConnDevEvt event);
BtStatus LeAddConnDevice(LeAddrType addrType, BD_ADDR *bdAddr);
BtStatus LeRemoveConnDevice(BD_ADDR *bdAddr, LeConnDevRemoveReason reason);

/* ------------------------------------------------------ *
 *                  SM related API prototype              *
 * ------------------------------------------------------ */
BtStatus SM_PasskeyEntry(BtDeviceContext *bdc, BOOL accept, U32 passkey);
BtStatus SM_JustWorkRsp(BtDeviceContext *bdc, BOOL accept);
BtStatus SM_SetOobData(BtDeviceContext *bdc, BOOL accept, U8 *tk);
BtStatus SM_Bond(BtDeviceContext *bdc, SmPairAttribute *attr);
BtStatus SM_CancelBonding(BtDeviceContext *bdc);
void SM_CMAC(BtCallBack callback, BD_ADDR *bdAddr, U8 *k, U8 *m, U32 mLen, U32 tLen);
void SM_CMAC_Verify(BtCallBack callback, BD_ADDR *bdAddr, U8 *k, U8 *m, U32 mLen, U32 tLen, U8 *mac);
void SM_Init(void);
void SM_GenCSRK(U8 *csrk);
void SM_GenIRK(U8 *irk);

#ifdef __ANDROID_L_MIGRATION__
BtStatus LeHciReadRPA(LeAddrType addrType, BD_ADDR * addr);
#endif

#endif /* __LE_ADP_H */
