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

/*******************************************************************************
 * Filename:
 * ---------
 *  StopwatchProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : StopwatchProt.h

   PURPOSE     : It contains the prototype declaration of internally used functions

   REMARKS     : nil

   AUTHOR      : Deepali Gupta

   DATE     : 05/01/2004

**************************************************************/
#ifndef __STOPWATCH_PROT_H__
#define __STOPWATCH_PROT_H__

#include "MMI_features.h"
#ifdef __MMI_STOPWATCH__

#include "MMIDataType.h"
#include "wgui_categories_stopwatch.h"
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* All structures Typedef Delaration
*****************************************************************************/


#define MAX_STOPWATCH_RECORDS    10

#define MAX_RECORD_NAME_LENGTH      16

#define MAX_TIMER_RECORD_DIGITS     11

#define POPUP_TIME               UI_POPUP_NOTIFYDURATION_TIME_2000

enum MP_TIMER_STATE
{
    TIMER_NOT_STARTED = 0,
    TIMER_STARTED,
    TIMER_STOPPED,
    TIMER_RUNNING
};

enum TIMER_TYPE
{
    LAP_TIMER = 0,
    SPLIT_TIMER
};

#ifndef MMI_ON_HARDWARE_P
#ifndef NVRAM_STOPWATCH_RECORD_SIZE
#ifdef __UCS2_ENCODING
#define NVRAM_STOPWATCH_RECORD_SIZE  1152
#else 
#define NVRAM_STOPWATCH_RECORD_SIZE  980
#endif 
#endif /* NVRAM_STOPWATCH_RECORD_SIZE */ 
#endif /* MMI_ON_HARDWARE_P */

typedef struct
{
    U8 recHr;
    U8 recMin;
    U8 recSec;
    U8 recMsec;
} nRecordDetail;

typedef struct
{
    CHAR name[(MAX_RECORD_NAME_LENGTH + 1) *ENCODING_LENGTH];
    nRecordDetail nRecordData[MAX_TIMER_RECORDS];
    U8 numOfRecords;
} stopwatchRecord;

/* For global variables of stopwatch */
typedef struct
{
    S32 numofCurrTimerRecords;
    U8 numOfSavedTimerRecords;
    U8 splitLapTimer;
    U8 recordName[(MAX_RECORD_NAME_LENGTH + 1) *ENCODING_LENGTH];
    S32 currHilitedRecord;
    pBOOL replaceRecord;
    pBOOL isRecordPresent;
    U8 TimerState;
    /* For MultiPurpose Stopwatch */
    U8 MPTimerState;
    U8 currentTimerIndex;
    S32 currentHiliteTimer;
    mmi_id editor_cui_record_name;
    mmi_id menu_cui_view_record;
    mmi_id menu_cui_typical;
    mmi_id menu_cui_timing_option;
} mmi_stopwatch_cntx_struct;

typedef struct
{
    U8 timerIndex[MAX_MULTIPURPOSE_TIMER];
    U16 assignedKey[MAX_MULTIPURPOSE_TIMER];
} nWayTimerStruct;

/***************************************************************************** 
* Global Variables 
*****************************************************************************/
extern mmi_stopwatch_cntx_struct gStopwatchAppInfo;

/***************************************************************************** 
* Local Function Declaration 
*****************************************************************************/
extern void mmi_stopwatch_typical_entry(void);
extern void mmi_stopwatch_multi_purpose_entry(void);
extern void InitMultipurposeStopwatch(void);

/***************************************************************************** 
* Global Function Declaration 
*****************************************************************************/
extern void HighlightStopwatch(void);
extern void StartIndexTimer(void);

#endif /* __MMI_STOPWATCH__ */ 
#endif /* __STOPWATCH_PROT_H__ */ 

