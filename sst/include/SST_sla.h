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
 *   SST_sla.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the necessary API needed by software LA.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _SST_SLA_
#define _SST_SLA_

#include "us_timer.h"
#include "SST_Concurrent_utility.h"
#include "kal_general_types.h"

/* Type Definition */
typedef struct SA_LoggingNode_T
{
   /* Manadatory information structure member */

#if defined(__HW_US_TIMER_SUPPORT__)
   kal_uint32   jobID;
   kal_uint32   USCNT;
   kal_uint32   frameNo;
#else /* __HW_US_TIMER_SUPPORT__ */
   kal_uint32   jobID;
   kal_uint16   TQCNT;
   kal_uint16   TQWRAP;
   kal_uint32   frameNo;
#endif /* __HW_US_TIMER_SUPPORT__ */   

} SA_LoggingNode;

/* Type Definition */
typedef struct SA_LoggingThread_T
{
   kal_uint32   ThreadID;
   kal_uint32   time;
} SA_LoggingThread;

typedef enum 
{
   SA_stop = 0,
   SA_start = 1,
   SA_label = 2
} SA_ACTION_T;

typedef enum 
{
   TAG_NEST_BEGIN   = 0xE0,
   TAG_NEST_END     = 0xE1,
   TAG_SINGLE_LABEL = 0xE2,
   TAG_BEGIN_POINT  = 0xE3,
   TAG_END_POINT    = 0xE4
} SA_TAG_T;

#if defined(__CONCURRENCY_LMU_SWLA__)
typedef enum {
	SA_LMU_HOOKLOGGING,
	SA_LMU_LOGGINGLISR,
	SA_LMU_CUSTOMLOGGING,
	SA_LMU_HWLOGGING
} SA_LMU_ACTION_T;
#endif

typedef struct SA_MainDescHeader_T
{
  SA_HEADER_ID_T desc_id;
  kal_uint32     log_sz;
}
SA_MainDescHeader;

typedef struct SA_AddonHeader_T
{
  SA_HEADER_ID_T desc_id;
  kal_uint32     log_sz;
  kal_char       ext_name[8];  
} SA_AddonHeader;

/* 
 * IF extra add-on parts are required, please modify this following number
 */
#define SA_MAX_ADDON_INFO_NUM 3

typedef struct SA_LoggingHeader_T
{   
   SA_MainDescHeader main_desc;
   SA_AddonHeader    addon_info[SA_MAX_ADDON_INFO_NUM];    
} SA_LoggingHeader;

typedef struct SA_AddonInfo_T
{   
  SA_HEADER_ID_T desc_id;
  kal_uint32 log_sz;
  kal_char ext_name[8];
  void (*SLA_AddonInfoInitFunc)(void);
  kal_bool SA_SwapOutLogging;
  kal_uint8 *(*SLA_AddonInfoLoggingFunc)(void);
  void (*SLA_AddonInfoDllDataInitFunc)(kal_uint8 **ARef, kal_uint32 *szARef);
} SA_AddonInfo;

#if defined(__CONCURRENCY_LMU_SWLA__)

/* 
 * Define the LMU-based SWLA header structure
 */
 
typedef struct SA_StructureSummary_T
{
  kal_uint32     len_header;
  kal_uint32     len_maindesc;
  kal_uint32     len_addondesc;
  kal_uint32     len_refdesc; 
} SA_StructureSummary;

typedef struct SA_LmuMainDescHeader_T
{
  SA_HEADER_ID_T desc_id;
  kal_uint32     base_timestamp;
  kal_uint32     usc_value;
  kal_uint32     log_sz;
}
SA_LmuMainDescHeader;

typedef struct SA_LmuLoggingHeader_T
{   
   SA_StructureSummary  structure_summary; //this field must be ignored in RAM logging
   SA_LmuMainDescHeader main_desc;
   SA_AddonHeader       addon_info[SA_MAX_ADDON_INFO_NUM];    
} SA_LmuLoggingHeader;

#endif   /* __CONCURRENCY_LMU_SWLA__ */


/* Prototypes */
kal_uint32 SLA_Enable(void);
kal_uint32 SLA_Disable(void);
void SLA_TriggerLogging(kal_uint32 fEnable);
kal_bool SLA_RetreiveLoggingBuffer(kal_uint8 **startAddr, kal_uint32 *size, kal_uint8 **currPtr);
kal_bool SLA_RetreiveHeader(kal_uint8 **MADesc, kal_uint32 *szMADesc, kal_uint8 **ARef, kal_uint32 *szARef);

kal_bool SLA_IsLmuLogging(void);
kal_uint32 SLA_HookLogging(void);
void SLA_LoggingLISR(kal_uint32 ID);

void SLA_CustomLogging(kal_char *customJob, SA_ACTION_T saAction);
void SLA_HWLogging(kal_char *customJob, SA_ACTION_T saAction);

void SLA_RAMLogging(kal_uint32 jobID);

#if defined(__CONCURRENCY_LMU_SWLA__)
void SLA_LMULogging(kal_uint32 ID, SA_LMU_ACTION_T action );
#endif

kal_bool SST_Get_CustPara_Addr_Len(kal_uint32 *p_addr, kal_uint32 *p_len);

void SLA_SleepComp(void);

kal_bool SLA_Check_Unused_RAM_Availability(kal_uint32 idx);

kal_uint32 SLA_Respond(void);
kal_bool SLA_IsEnabled(void);
kal_uint32 SLA_TurnOn(void);
kal_uint32 SLA_TurnOff(void);
kal_uint32 SLA_Init(void);

kal_int32 SLA_Register(SA_HEADER_ID_T desc_id, kal_uint32 log_sz, kal_char ext_name[], kal_uint8 *(*SLA_AddonInfoInitFunc)(void), kal_uint8 *(*SLA_AddonInfoLoggingFunc)(void), kal_bool SA_SwapOutLogging, void (*SLA_AddonInfoDllDataInitFunc)(kal_uint8 **ARef, kal_uint32 *szARef) );

void SLA_Disable_low_RAM_SWLA(void);
void SLA_Enable_low_RAM_SWLA(void);
void SLA_Print_low_RAM_SWLA(void);

#endif /* _SST_SLA_ */
