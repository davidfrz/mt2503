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
 * lei.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * Low Energy internal header
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __LEI_H
#define __LEI_H

#include "utils.h"
#include "hci.h"
#include "metypes.h"

#define LE_HCI_CMD_LIST_SIZE 32
#define LE_STACK_POOL_SIZE 10

#define LE_ADV_DATA_SIZE 31
//#define LE_DUAL_INQUIRY_INTERVAL (10.24 / 2 * 1000)   /* ms */

typedef enum
{
    LE_ADV_CHANNEL_37 = 0x01,
    LE_ADV_CHANNEL_38 = 0x02,
    LE_ADV_CHANNEL_39 = 0x04,
    LE_ADV_CHANNEL_ALL = 0x07
} LeAdvChannelType;

typedef enum
{
    HCI_ADV_IND = 0x00,
    HCI_ADV_DIRECT_IND = 0x01,
    HCI_ADV_SCAN_IND = 0x02,
    HCI_ADV_NONCONN_IND = 0x03,

    HCI_SCAN_RSP = 0x04
                   /* MTK: 0xFF is used to denote NOT ACCESSIBLE case */
} HciLeAdvertiseType;

typedef enum
{
    HCI_SCAN_PASSIVE = 0x00,
    HCI_SCAN_ACTIVE = 0x01
} HciLeScanType;

typedef enum
{
    ADV_ALLOW_ALL = 0x00,
    ADV_ALLOW_SCAN_WL = 0x01,          /* Allow scan from WL & connect from all */
    ADV_ALLOW_CONNECT_WL = 0x02,       /* Allow scan from all & connect from WL */
    ADV_ALLOW_SCAN_CONNECT_WL = 0x03,  /* Allow scan from WL & connect from WL */
} HciLeAdvertiseFilter;

typedef enum
{
    SCAN_ALLOW_ALL = 0x00,
    SCAN_ALLOW_WL_ONLY = 0x01,          /* Allow scan from WL */
} HciLeScanFilter;

typedef enum
{
    INITIAOR_NOT_USE_WL = 0x00,          /* Allow scan from WL */
    INITIAOR_USE_WL = 0x01,
} HciLeInitiatorFilter;

typedef enum
{
    BT_DEV_TYPE_UNKNOWN,   // 0
    BT_DEV_TYPE_LE,        // 1
    BT_DEV_TYPE_BR_EDR,    // 2
    BT_DEV_TYPE_BR_EDR_LE, // 3
    NUM_OF_BT_DEV_TYPE,
} BtDevType;

typedef enum
{
    BT_CONN_TYPE_UNKNOWN,
    BT_CONN_TYPE_LE,
    BT_CONN_TYPE_BR_EDR,
} BtConnType;

typedef enum
{
    LE_ADDR_PUBLIC,                          /* 0x00 */
    LE_ADDR_RANDOM                           /* 0x01 */
} LeAddrType;

typedef enum
{
    LE_CONN_DEV_REMOVE_REASON_TIMEOUT      = 0,
    LE_CONN_DEV_REMOVE_REASON_CONNECTED    = 1,
} LeConnDevRemoveReason;

typedef enum
{
    LE_CONN_DEV_EVT_CHANGED                = 0,
    LE_CONN_DEV_EVT_WL_CLEARED             = 1,
    LE_CONN_DEV_EVT_WL_ADDED               = 2,
    LE_CONN_DEV_EVT_CONNECT_DONE           = 3,
} LeConnDevEvt;

typedef enum
{
    LE_CONN_DEV_STATE_IDLE                 = 0,
    LE_CONN_DEV_STATE_CLEAR_WL             = 1,
    LE_CONN_DEV_STATE_ADD_WL               = 2,
    LE_CONN_DEV_STATE_CONNECT              = 3,
    LE_CONN_DEV_STATE_CONNECT_CANCEL       = 4,
} LeConnDevState;

typedef struct
{
    LeAddrType addrType;
    BD_ADDR    bdAddr;
    BOOL       inWhiteList;
    BOOL       inUse;
} LeConnDev;


typedef enum
{
    BEF_LE_LIMITED_DISCOVERABLE_MODE       = 0x01,
    BEF_LE_GENERAL_DISCOVERABLE_MODE       = 0x02,
    BEF_BR_EDR_NOT_SUPPORTED               = 0x04,
    BEF_SIMUL_LE_BR_EDR_CAPABLE_CONTROLLER = 0x08,
    BEF_SIMUL_LE_BR_EDR_CAPABLE_HOST       = 0x10
} LeAdFlags;

typedef enum
{
    LE_APPEARANCE_UNKNOWN                  = 0,
    LE_APPEARANCE_PHONE                    = 64,
    LE_APPEARANCE_COMPUTER                 = 128,
    LE_APPEARANCE_WATCH                    = 192,
    LE_APPEARANCE_CLOCK                    = 256,
    LE_APPEARANCE_DISPLAY                  = 320,
    LE_APPEARANCE_REMOTE_CONTROL           = 384,
    LE_APPEARANCE_EYE_GLASSES              = 448,
    LE_APPEARANCE_TAG                      = 512,
    LE_APPEARANCE_KEYRING                  = 576,
    LE_APPEARANCE_MEDIA_PLAYER             = 640,
    LE_APPEARANCE_BARCODE_SCANNER          = 704,
} LeAppearanceType;


typedef enum
{
    LE_PROFILE_NONE                        = 0,
    LE_PROFILE_ANP                         = 0x00000001,
    LE_PROFILE_BLP                         = 0x00000002,
    LE_PROFILE_FMP                         = 0x00000004,
    LE_PROFILE_HOGP                        = 0x00000008,
    LE_PROFILE_HRP                         = 0x00000010,
    LE_PROFILE_HTP                         = 0x00000020,
    LE_PROFILE_PASP                        = 0x00000040,
    LE_PROFILE_PXP                         = 0x00000080,
    LE_PROFILE_SCPP                        = 0x00000100,
    LE_PROFILE_TIP                         = 0x00000200,
    LE_PROFILE_ALL                         = 0xFFFFFFFF,
} LeProfile;




typedef struct
{
    U16 intervalMin;    /* value = (desired interval/0.625ms) */
    U16 intervalMax;    /* value = (desired interval/0.625ms) */
} BtLEAdvParm;

typedef struct
{
    U16 scanInterval;  /* value = (desired interval/0.625ms) */
    U16 scanWindow;    /* value = (desired interval/0.625ms) */
    U16 connIntervalMin;  /* value = (desired interval/1.25ms) */
    U16 connIntervalMax;  /* value = (desired interval/1.25ms) */
    BOOL privacy;
} BtLELinkParm;

typedef struct
{
    U64 random;
    U16 ediv;
    U8 ltk[16];
} BtLEEncParm;

typedef struct _BtLERecord
{
    BD_ADDR bdAddr;
    BtDevType devType;
    LeAddrType addrType;
    LeProfile profiles;
} BtLERecord;

/* ------------------------------------------------------ *
 *           GAP Peripheral related definition            *
 * ------------------------------------------------------ */

/* define mask for LE advertising parameter update */
typedef U16 LeAdvParamMask;

#define LE_ADV_PARAM_NONE             0x0000
#define LE_ADV_PARAM_INTERVAL_MIN     0x0001
#define LE_ADV_PARAM_INTERVAL_MAX     0x0002
#define LE_ADV_PARAM_ADVTYPE          0x0004
#define LE_ADV_PARAM_OWN_ADDRTYPE     0x0008
#define LE_ADV_PARAM_DIRECT_ADDRTYPE  0x0010
#define LE_ADV_PARAM_DIRECT_BDADDR    0x0020
#define LE_ADV_PARAM_CHANNEL_MAP      0x0040
#define LE_ADV_PARAM_ADV_FILTER       0x0080
#define LE_ADV_PARAM_ALL_MASK         0x00FF

/* define mask for LE advertising data update */
typedef U16 LeAdvDataTypeMask;

#define LE_ADV_DATA_TYPE_NONE                         (0x0000)
#define LE_ADV_DATA_TYPE_LOCAL_NAME                   (0x0001 << 1)
#define LE_ADV_DATA_TYPE_APPEARANCE                   (0x0001 << 2)
#define LE_ADV_DATA_TYPE_SERVICE_UUID                 (0x0001 << 3)
#define LE_ADV_DATA_TYPE_SERVICE_16UUID               (0x0001 << 4) 
#define LE_ADV_DATA_TYPE_SERVICE_32UUID               (0x0001 << 5)
#define LE_ADV_DATA_TYPE_SERVICE_128UUID              (0x0001 << 6)
#define LE_ADV_DATA_TYPE_SERVICE_DATA_16UUID          (0x0001 << 9)
#define LE_ADV_DATA_TYPE_SERVICE_DATA_32UUID          (0x0001 << 10)
#define LE_ADV_DATA_TYPE_SERVICE_DATA_128UUID         (0x0001 << 11)
#define LE_ADV_DATA_TYPE_FLAGS                        (0x0001 << 12)
#define LE_ADV_DATA_TYPE_MANU_DATA                    (0x0001 << 13)
#define LE_ADV_DATA_TYPE_SLAVE_CONN_INTERVAL          (0x0001 << 14)
#define LE_ADV_DATA_TYPE_TX_POWER_LEVEL               (0x0001 << 15)
#define LE_ADV_DATA_TYPE_ADV_INTERVAL                 (0x0001 << 16)
#define LE_ADV_DATA_TYPE_SERVICE_SOLICITATION_16UUID  (0x0001 << 17)
#define LE_ADV_DATA_TYPE_SERVICE_SOLICITATION_32UUID  (0x0001 << 18)
#define LE_ADV_DATA_TYPE_SERVICE_SOLICITATION_128UUID (0x0001 << 19)



/* Name type depedence by name length(shortened or complete) */
typedef struct _AdvLocalName
{
    U8 nameLen;
	U8 *localName;
} AdvLocalName;

typedef struct _AdvManufacturerData
{
    U16 manuDataLen;
	U8  *manuData;
} AdvManufacturerData;

typedef struct
{
    U16 minInterval;
    U16 maxInterval;
} SlaveConnIntervalRange;

/* Spec: shall not contain more than one instance for each Service UUID data size  */
typedef struct _Service16UUIDElem
{
    U8 serviceNum;
	U16 *uuidList;
} Service16UUIDElem;

typedef struct _Service32UUIDElem
{
    U8 serviceNum;
	U32 *uuidList;
} Service32UUIDElem;

typedef struct _Service128UUIDElem
{
    U8 serviceNum;
	U8 *uuidList;
} Service128UUIDElem;

typedef struct _ServiceUUID
{    
    Service16UUIDElem  uuid16;
    Service32UUIDElem  uuid32;
    Service128UUIDElem uuid128;
} ServiceUUID;

typedef struct _ServiceDataElem
{
	U8 uuidDataLen;
	U8 *uuidData;
} ServiceDataElem;

/* Default support 16 UUID in current stage */
typedef struct _ServiceData
{
    ServiceDataElem uuid16;
	ServiceDataElem uuid32;
    ServiceDataElem uuid128;
} ServiceData;

typedef struct _ServiceSolicitation
{
    Service16UUIDElem uuid16;      
    Service32UUIDElem uuid32; 
    Service128UUIDElem uuid128; 
} ServiceSolicitation;

typedef struct
{ 
    LeAdFlags               flag;
	AdvManufacturerData     manu;            /* manufacturer specific data */
    AdvLocalName            name;            /* local device name */
    SlaveConnIntervalRange  conn_int_range;  /* slave prefered conn interval range */	
    U16                     appearance; 
    S8                      txpower;
    ServiceUUID             service;
	ServiceData             service_data;
    ServiceSolicitation     solication;
	U16                     adv_int;         /* advertising interval */
} LeAdvDataType;


typedef struct
{
    BtOperation op;  /* Chain to MEC(opList) */

    /* HCI command */
    HciCommandType cmd;
    U8 parmLen;                  /* command parm length and return event parm length */
    U8 parms[HCI_CMD_PARM_LEN];  /* command parm and return event parm */
    U8 cmdToHci;

    union
    {
        BOOL enable;  /* HCC_LE_SET_SCAN_ENABLE: need to remember parm due to same command but different event handling */
    } cmdParm;

    union
    {
        struct _BtRemoteDevice *remDev;  /* use link handler */
        BtCallBack callback;
    } handler;
} LeHciCmd;



typedef struct _LeAdvParam
{
	U16                  advIntervalMin; 
	U16                  advIntervalMax;
	HciLeAdvertiseType   advType;
	LeAddrType           ownAddrType;
	LeAddrType           directAddrType;
	BD_ADDR              directBDAddr;
	LeAdvChannelType     channelMap;
	HciLeAdvertiseFilter advFilter;
} LeAdvParam;



/*---------------------------------------------------------------------------
 * Le Context Structure
 *
 *   This structure provides the context and state information for the entire SM module
 */
typedef struct _BtLeContext
{
    U16 interval;
    U16 window;
    U8 type;
    U8 ownAddrType;
    U8 filter;
    BOOL advEnabled;              // For Peripheral
    BOOL advScanEnabled;          // For Centrol
    U8 setScanParameterFlag;
    U8 setEnabledFlag;
    U8 currentEnabledState;
    LeHciCmd hciScanParmCmd;
    LeHciCmd hciScanEnabledCmd;
    U8 advData[LE_ADV_DATA_SIZE];
    U8 advDataLen;
	U8 advScanRspData[LE_ADV_DATA_SIZE];
	U8 advScanRspDataLen;
    LeAdvParam currentAdvParam;
    LeAdvDataType currentAdvData;

    LeHciCmd hciCmd[LE_HCI_CMD_LIST_SIZE];
    U8 curCmdIdx;

    LeConnDev connDevList[NUM_BT_DEVICES];
    LeConnDevState connDevState;
    U8 connDevSize;
    BOOL clear;
    struct _SmContext *smCtx;

//#ifdef __BT_4_0_PRIVACY__
    BD_ADDR random_bdaddr;

    union
    {
        struct
        {
            U8 prand[3];   /* intermediate data */
            BtCallBack cb; /* intermediate data */
        } genRandomAddr;
        struct
        {
            U8 recIndex;   /* intermediate data */
            BD_ADDR resAddr;   /* intermediate data */
            BtCallBack cb; /* intermediate data */
        } resolveRandomAddr;
    } op;
//#endif
} BtLeContext;

void SM_LinkCallback(struct _BtRemoteDevice *remDev, struct _BtEvent *event);

#endif /* __LEI_H */
