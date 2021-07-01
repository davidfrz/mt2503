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
 *   switchControl_mtk_1.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   USIM driver functions on for MTK multiple SIM controllers.
 *   
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
#ifndef DRV_SIM_OFF
#include  	"drv_comm.h"
#ifdef __SIM_DRV_MULTI_DRV_ARCH__
#include 	"reg_base.h"
#include 	"intrCtrl.h"
#include    "sim_reg_adp.h"

#include    "sim_al.h"
#include    "sim_hw_mtk.h"
#include 		"dma_sw.h"
#include    "sim_sw_comm.h"
//RHR#include    "dma_hw.h"
#include    "dma_sw.h"
//#include		"gpt_sw.h"
//RHR#include		"gpio_sw.h"
#include		"drv_hisr.h"
#include		"sim_mtk.h"

//#ifdef DRV_MULTIPLE_SIM
#if  (defined(DRV_SIM_ALL_SOLUTION_BUILT) || (defined(DRV_MULTIPLE_SIM) && defined(DRV_2_SIM_CONTROLLER)))
//#ifdef MT6318
//#include 	"pmic6318_sw.h"
//#endif   /*MT6318*/

#if defined(__SIM_PLUS__)
#include "msdc_def.h" 
#endif

#if defined(__USIM_DRV__)
#include		"usim_MT6302.h"

//#include "pwic.h"

//#if defined(MT6223PMU)
//#include "pmu_sw.h"
//#endif
//#ifdef DRV_2_SIM_CONTROLLER
#include "sim_ctrl_al.h"
//#include "..\..\..\ps\sim\include\sim_trc.h"
#include "sim_trc.h" 

//#endif
#ifdef SIM_CACHED_SUPPORT
//RHR#include    "init.h"
#include "cache_sw.h"
#endif

//#ifdef DUAL_MCU_SIM_V1
//#include "pmic6326_ccci_sw.h"
//#endif

/*RHR*/
#include "drv_features.h"
#include "drvpdn.h"
#if defined (LPWR_SLIM)
#include "l1sm_public.h"
#endif
#include "kal_non_specific_general_types.h"
#include "kal_release.h"
#include "kal_trace.h"
#include "kal_debug.h"
#include "stack_config.h"
#include "stdio.h"
#include "string.h"
/*RHR*/


#ifdef __CLKG_DEFINE__
#if (defined(DRVPDN_CON1) || defined(DRVPDN_CON0))
#error "__CLKG_DEFINE__ & DRVPDN_CON1 are all defined"
#else /*(defined(DRVPDN_CON1) || defined(DRVPDN_CON0))*/

#ifdef SIM_PDN_REG_VERSION_3
#define DRVPDN_CON1		CG_CON0
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON1		CG_CON1
#endif /*SIM_PDN_REG_VERSION_3*/

#ifdef SIM_PDN_REG_VERSION_3
/*MT6516 E2 has SIM2 PDN bit on MD side, we have to access CG_CON0 directly*/
#define DRVPDN_CON0		CG_CON0
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON0		CG_CON0
#endif /*SIM_PDN_REG_VERSION_3*/

#endif /*(defined(DRVPDN_CON1) || defined(DRVPDN_CON0))*/

#if (defined(DRVPDN_CON1_SIM) || defined(DRVPDN_CON0_SIM2))
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SIM are all defined"
#else /*(defined(DRVPDN_CON1_SIM) || defined(DRVPDN_CON0_SIM2))*/


#ifdef SIM_PDN_REG_VERSION_3
#define DRVPDN_CON1_SIM	CG_CON0_SIM
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON1_SIM	CG_CON1_SIM
#endif /*SIM_PDN_REG_VERSION_3*/

#ifdef SIM_PDN_REG_VERSION_3
/*MT6516 E2 has SIM2 PDN bit on MD side, we have to access this bit*/
#define DRVPDN_CON0_SIM2	CG_CON0_SIM2
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON0_SIM2	CG_CON0_SIM2
#endif /*SIM_PDN_REG_VERSION_3*/


#endif /*(defined(DRVPDN_CON1_SIM) || defined(DRVPDN_CON0_SIM2))*/
#endif /*__CLKG_DEFINE__*/


/*following decalration were moved from gpt_sw.h*, we should change them to dcl form eventually*/
//extern kal_uint8 GPTI_GetHandle(kal_uint8 *handle);
//extern kal_bool GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
//extern void GPTI_StopItem(kal_uint8 module);

extern void pmic6326_ccci_lock(kal_bool lock);


extern void SIM_SetRXTIDE(kal_uint16 RXTIDE, sim_HW_cb *hw_cb);
extern void SIM_SetTXTIDE(kal_uint16 _TXTIDE, sim_HW_cb *hw_cb);
extern Sim_Card *SimCard;
//extern 	kal_bool  TS_HSK_ENABLE;
extern kal_char sim_dbg_str[];

#define FILE_SWITCHCONTROL1	2

extern kal_uint32	hwCbArray[SIM_DRV_MTK_INTERFACE_NUM];
static usim_dcb_struct usim_cb[DRV_SIM_MAX_LOGICAL_INTERFACE];
//static  Sim_Card SimCard_cb[DRV_SIM_MAX_LOGICAL_INTERFACE];

//usim_dcb_struct	*usim_dcb = &usim_cb[0];
#ifndef DRV_SIM_HIGH_SPEED
static kal_uint8 BWT_Factor[3] = {1, 6, 12}; // 372/64 = 6, 372/32 = 12 
#else
static kal_uint8 BWT_Factor[5] = {1, 6, 12, 24, 48}; // 372/64 = 6, 372/32 = 12, 23< 372/16 < 24
#endif


#if defined(USIM_DEBUG)
#define BUF_COUNT		1024
kal_uint16 int_buffer[BUF_COUNT];
kal_uint32 buf_index;
#define PUSH_INT(a)	int_buffer[(buf_index&(BUF_COUNT-1))] = a;\
							buf_index++;
#else
#define PUSH_INT(a)	
#endif

#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
#ifdef SIM_CACHED_SUPPORT
extern kal_uint32	sim_uncachedTxBuffer0[], sim_uncachedRxBuffer0[], sim_uncachedTxBuffer1[], sim_uncachedRxBuffer1[];
#define GET_NCACHEDTX_P(p, a) {if(0==a) p=(kal_uint8 *)sim_uncachedTxBuffer0; else p=(kal_uint8 *)sim_uncachedTxBuffer1;}
#define GET_NCACHEDRX_P(p, a) {if(0==a) p=(kal_uint8 *)sim_uncachedRxBuffer0; else p=(kal_uint8 *)sim_uncachedRxBuffer1;}
extern kal_uint8 uncachedDmaBuffer0[], uncachedDmaBuffer1[];//the instance is declared in icc_sim_common_mtk.c
#define GET_NCACHED_USIM_DMA_BUF_P(p, a) {if(0==a) p=(kal_uint8 *)uncachedDmaBuffer0; else p=(kal_uint8 *)uncachedDmaBuffer1;}
#define GET_NCACHED_USIM_DMA_BUF_INT(p, a) {if(0==a) p=(kal_uint32)uncachedDmaBuffer0; else p=(kal_uint32)uncachedDmaBuffer1;}
#endif
#pragma arm section zidata, rwdata


#if defined(USIM_DEBUG)
extern void dbg_print(char * fmt,...);
static kal_uint32 start, end;
kal_uint32 get_current_time(void)
{
	return (SIM_Reg32(0x80200230));
}
kal_uint32 get_duration_tick(kal_uint32 previous_time)
{
	kal_uint32 result, current_time;

	current_time = SIM_Reg32(0x80200230);
	if (previous_time > current_time)
	{
		result = 0x80000 - previous_time + current_time;
	}
	else
	{
		result = current_time - previous_time;
	}
	return result;
}
#endif

// proto type
static kal_bool usim_check_input_volt(usim_power_enum  volt, sim_HW_cb *hw_cb);
static usim_status_enum usim_process_ATR(sim_HW_cb *hw_cb);
static void usim_process_TA1(kal_uint8 TA1, sim_HW_cb *hw_cb);
static void usim_process_PTS(sim_HW_cb *hw_cb);
static void usim_set_speed(usim_speed_enum speed, sim_HW_cb *hw_cb);
static void usim_set_protocol(usim_protocol_enum T, sim_HW_cb *hw_cb);
static void usim_set_timeout(kal_uint32 timeout, sim_HW_cb *hw_cb);
static kal_bool usim_select_power(usim_power_enum ExpectVolt, sim_HW_cb *hw_cb);
static void usim_activation(sim_HW_cb *hw_cb);
void usim_lisr_Multiple(void);
static void usim_deactivation(sim_HW_cb *hw_cb) ;
static void usim_t1end_handler(sim_HW_cb *hw_cb);
static void usim_hisr(void);
static void usim_rx_handler(kal_uint32 int_status, sim_HW_cb *hw_cb);
static void usim_send_block(kal_uint8 *adrs, sim_HW_cb *hw_cb);
static kal_bool usim_rx_block_handler(kal_uint32 *adrs, sim_HW_cb *hw_cb);
static sim_status usim_send_i_block(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, sim_HW_cb *hw_cb);
void sim_PDNDisable_MTK(sim_HW_cb *hw_cb);
void sim_PDNEnable_MTK(sim_HW_cb *hw_cb);
//kal_taskid kal_get_current_thread_ID(void);

extern sim_env SIM_GetCurrentEnv(kal_uint32 simInterface);
extern void L1sim_Init_MTK(sim_HW_cb *hw_cb);
extern kal_uint8 sim_Reset_MTK(kal_uint8 resetVolt, kal_uint8 *resultVolt,AtrStruct *Info, sim_HW_cb *hw_cb);
extern void L1sim_Configure_MTK(kal_uint8 clockMode, sim_HW_cb *hw_cb);
extern void sim_addMsg(kal_uint32 tag, kal_uint32 event, kal_uint32 data1, kal_uint32 data2);

/*defines here since these functions will be called in sim_drv_SW_function.h*/
static void usim_gpt_timeout_handler(void *parameter);
extern void sim_PowerOff_MTK(sim_HW_cb *hw_cb);
extern sim_status L1sim_Cmd_Layer_MTK(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, sim_HW_cb *hw_cb, kal_bool *isSW6263);
//kal_bool				sim_workingTaskWaiting; //this is used in Gemini projects, but sim_sw_comm.h used this, so we declared it
extern kal_bool simfactorytest;


#if defined (__SIM_DVT__)
kal_uint8 gTout = 0;
static kal_uint16 ATR[48];
kal_bool pauseInHisr;
kal_uint32 T1endTimes;
kal_bool useT1Switch = KAL_FALSE;
kal_bool T1SwitchEnabled = KAL_FALSE;
#endif
void USIM_WAIT_EVENT_MTK(usim_dcb_struct *usim_dcb)
{
	DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle,
                  USIM_GPT_TIMEOUT_PERIOD,
                  usim_gpt_timeout_handler,
                  usim_dcb);
	kal_retrieve_eg_events(usim_dcb->event,USIM_EVENT,KAL_AND_CONSUME,&usim_dcb->ev_flag,KAL_SUSPEND);
	if(usim_dcb->status != USIM_GPT_TIMEOUT)
		DRV_ICC_GPTI_StopItem(usim_dcb->gpt_handle);	
}

void USIM_SET_EVENT_Multiple(usim_dcb_struct *usim_dcb)
{
	DRV_ICC_GPTI_StopItem(usim_dcb->gpt_handle);
	kal_set_eg_events(usim_dcb->event,USIM_EVENT,KAL_OR);
}

/*************************************************************************
* FUNCTION
*  usim_check_input_volt
*
* DESCRIPTION
*	 check if the input volt is supported by the interface device
*
* PARAMETERS
*	volt: voltage used by SIM card
*
* RETURNS
*	KAL_TRUE: it is supported 
*	KAL_FALSE: not supported
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
static kal_bool usim_check_input_volt(usim_power_enum  volt, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	if(usim_dcb->sim_env == ME_18V_30V)
		return KAL_TRUE;
	if(usim_dcb->sim_env == ME_30V_ONLY && volt == CLASS_B_30V)
		return KAL_TRUE;	
	if(usim_dcb->sim_env == ME_18V_ONLY && volt == CLASS_C_18V)
		return KAL_TRUE;
	
	return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  usim_check_TCK
*
* DESCRIPTION
*	 check if TCK present and the checksum of ATR is correct
*
* PARAMETERS
*
* RETURNS
*	KAL_TRUE: TCK is not present or chekcsum is correct
*	KAL_FALSE: Chekcsum is incorrect
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_bool usim_check_TCK(sim_HW_cb *hw_cb)
{
	kal_uint32 i = 0;
	kal_uint8 ck = 0;
	kal_uint8 *ptr;
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	ptr = usim_dcb->ATR_data;
	

	//kal_print("usim_check_TCK");
	DRV_ICC_print(SIM_PRINT_CHECK_TCK, 0, 0, 0, 0, 0);

   while(SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK) == 0 && i++ <= 22)
   {
		kal_sleep_task(10);
   }	   	
	if(i >= 23)
	{
		//kal_print("TCK not present");
		DRV_ICC_print(SIM_PRINT_TCK_NOT_PRESENT, 0, 0, 0, 0, 0);
		return KAL_TRUE;
	}
	ptr[usim_dcb->ATR_index++] = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK);
	for(i=1;i<usim_dcb->ATR_index;i++)
		ck ^= ptr[i];
	if(ck != 0)
	{
		//kal_print("TCK checksum err");
		DRV_ICC_print(SIM_PRINT_TCK_CHECKSUM_ERR, 0, 0, 0, 0, 0);
		return KAL_FALSE;
	}

	//kal_print("TCK checksum ok");
	DRV_ICC_print(SIM_PRINT_TCK_CHECKSUM_OK, 0, 0, 0, 0, 0);
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  usim_process_ATR
*
* DESCRIPTION
*	1. wait all ATR characters received at HISR and put into usim_dcb->ATR_data
*	2. Get parameters from ATR, Fi, Di, T0_support, T1_support, reset mode, WWT(T0)
*		IFSC(T1), CWI, BWI, X, U
*
* PARAMETERS
*	None
* RETURNS
*  KAL_TRUE: Valid TS is received
*  KAL_FALSE: Valid TS is not received, card is not present or not supported
*
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static usim_status_enum usim_process_ATR(sim_HW_cb *hw_cb)
{
	kal_uint8 data,TD;
	kal_bool T15;
	kal_uint8 *ptr;	
	kal_uint32 index = 1;	// skip the first TS byte
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	ptr = usim_dcb->ATR_data;
	
   // get the application protocol of the sim card 
   if((ptr[index] & 0x0f) == 0)
   	usim_dcb->app_proto = SIM_PROTOCOL; // no historical char imply SIM_PROTOCOL
   do 
   {
   	data = ptr[index++];
   	USIM_CAL_TD_COUNT(data, index);
   }while(data & TDMask);
   usim_dcb->hist_index = index;
   if(ptr[index] == HIST_FIRST_USIM && ptr[index+1] == HIST_SEC_USIM 
   	&& ptr[index+3] == HIST_FOUR_USIM){
   	usim_dcb->app_proto = USIM_PROTOCOL;
   }
   else if(ptr[index] == HIST_FIRST_USIM && ptr[index+1] == HIST_SEC_USIM
   	&& ptr[index+3] == 0x51 && ptr[index+5] == HIST_FOUR_USIM){
   	//kal_print("historycal byte error");
	DRV_ICC_print(SIM_PRINT_HISTORICAL_BYTE_ERR, 0, 0, 0, 0, 0);
   	usim_dcb->app_proto = USIM_PROTOCOL;
   }
   else
   	usim_dcb->app_proto = SIM_PROTOCOL;
	// parse the content of ATR	
	T15 = KAL_FALSE;
	index = 1;
	TD = ptr[index++];	//T0
	if(TD & TAMask)
	{
		// TA1 (FI, DI)		
		data = ptr[index++];
		usim_process_TA1(data, hw_cb);
		//usim_dcb->WWT = INIT_WWT_T0*usim_dcb->Di;
		DRV_ICC_Calc_WWT(usim_dcb->Fi, usim_dcb->Di, 10, &usim_dcb->WWT);
	}			
	if(TD & TBMask)
	{
		// TB1 (PI, II) (neglect it)
		data = ptr[index++];
	}
	if(TD & TCMask)
	{
		// TC1 (N: extra guard time) (neglect it)
		data = ptr[index++];
		if(data != 0 && data != 255)
			return USIM_INVALID_ATR;
	}
	if( !(TD & TDMask))
	{
		usim_dcb->T0_support = KAL_TRUE;
		return USIM_NO_ERROR;
	}
	
	TD = ptr[index++]; // TD1
	if((TD & 0x0f) == 0)
		usim_dcb->T0_support = KAL_TRUE;
	else if((TD & 0x0f) == 1)
		usim_dcb->T1_support = KAL_TRUE;
	else if((TD & 0x0f) == 0x0f)
	{
		// T = 15 is forbidden in TD1
		return USIM_INVALID_ATR;
	}
	
	if(TD & TAMask)
	{
		//TA2 (specific mode)
#if defined(SIM_DEBUG_INFO)
		dbg_print("TA2(specific mode) \r\n");
#endif
		data = ptr[index++];
		usim_dcb->reset_mode = USIM_RESET_SPECIFIC;
		// chage the clock to the one before reset.
	}
	if(TD & TBMask)
	{
		// TB2 (PI2)(neglect it)
		data = ptr[index++];
	}
	if(TD & TCMask)
	{
		// TC2 (work waiting time = 960xWIxDi etu)(T0)
		data = ptr[index++];
		//usim_dcb->WWT = 960*data*usim_dcb->Di;
		DRV_ICC_Calc_WWT(usim_dcb->Fi, usim_dcb->Di, data, &usim_dcb->WWT);
	}
#if defined(SIM_DEBUG_INFO)
	dbg_print("WWT: %d \r\n",usim_dcb->WWT);
#endif
	if( !(TD & TDMask))
	{
		if(usim_dcb->T0_support && !usim_dcb->T1_support && !T15)
		{
			return USIM_NO_ERROR;
		}
		else
		{
			if (usim_check_TCK(hw_cb) == KAL_FALSE)
				return USIM_INVALID_ATR;
			else
				return USIM_NO_ERROR;
		}
	}
	
	TD = ptr[index++]; // TD2
	if((TD & 0x0f) == 1)
	{
		usim_dcb->T1_support = KAL_TRUE;
	}
	else if((TD & 0x0f) == 0x0f)
	{
		T15 = KAL_TRUE;
		goto global_interface;
	}
	if(TD & TAMask)
	{
		//TA3 (ISFC)
		data = ptr[index++];
		usim_dcb->ifsc = data;
#if defined(SIM_DEBUG_INFO)
		dbg_print("IFSC: %d \r\n",data);		
#endif
	}
	if(TD & TBMask)
	{
		kal_uint8 cwi,bwi;
		
		// TB3 (PI2)
		data = ptr[index++];
		cwi = data&0xf; // range from 0~5
		bwi = (data&0xf0)>>4;
		if(cwi > MAX_CWI)
			return USIM_INVALID_ATR;
		if(bwi > MAX_BWI)
			return USIM_INVALID_ATR;
		usim_dcb->CWT = (1<<cwi)+11;
		usim_dcb->BWT = (1<<bwi)*960; 
	}
	else
	{
		usim_dcb->CWT = USIM_CWT_DEFAULT;
		usim_dcb->BWT = USIM_BWT_DEFAULT;
	}	
#if defined(SIM_DEBUG_INFO)
	dbg_print("BWT: %d \r\n",usim_dcb->BWT);		
#endif
	if(TD & TCMask)
	{
		// TC3 (neglect)
		data = ptr[index++];
	}	
	if( !(TD & TDMask))
	{
		if(usim_dcb->T0_support && !usim_dcb->T1_support && !T15)
			return USIM_NO_ERROR;
		else
		{
			if (usim_check_TCK(hw_cb) == KAL_FALSE)
				return USIM_INVALID_ATR;
			else
				return USIM_NO_ERROR;
		}
	}
	TD = ptr[index++]; // TD3
	if((TD & 0x0f) != 0x0f)
	{
		if(usim_dcb->T0_support && !usim_dcb->T1_support && !T15)
			return USIM_NO_ERROR;
		else
		{
			if (usim_check_TCK(hw_cb) == KAL_FALSE)
				return USIM_INVALID_ATR;
			else
				return USIM_NO_ERROR;
		}
	}
	
global_interface:
	
	if (usim_check_TCK(hw_cb) == KAL_FALSE)
		return USIM_INVALID_ATR;
		
	if(TD & TAMask)
	{
		//TAi (clock stop(X) and power class(U))
		data = ptr[index++];
		usim_dcb->clock_stop_type = (usim_clock_stop_enum)(data&CLOCK_STOP_MSK);
		if(usim_dcb->app_proto == SIM_PROTOCOL)
			usim_dcb->power_class = CLASS_ALLSUPPORT;
		else
		usim_dcb->power_class = (usim_power_enum)(data & USIM_POW_CLASS_MSK);
#if defined(SIM_DEBUG_INFO)
		dbg_print("clock stop[7:8]|power class[1:6]: %x \r\n",data);
#endif
		/*SIM task need following information for UICC identification*/
		usim_dcb->TAiExist = KAL_TRUE;
	}
	else{ //from latest 7816-3, if ATR is valid without class indicator, host should continue normal operation
		return USIM_NO_ERROR;
	}
	// check if used power is supported by the UICC
	if((usim_dcb->power & usim_dcb->power_class) == 0)
	{
		if(usim_dcb->sim_env == ME_18V_30V)
		{
			if(usim_dcb->power == CLASS_C_18V)
				usim_dcb->power = CLASS_B_30V;
		
			return USIM_VOLT_NOT_SUPPORT;
		}
	}
	else if(usim_dcb->app_proto == SIM_PROTOCOL)
		return USIM_NO_ERROR;
	
	return USIM_NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  usim_process_TA1
*
* DESCRIPTION
	1. 
Get Di and Fi from TA1
*
* PARAMETERS
	TA1: first interface character used to indicate the Fi and Di
	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*	usim_dcb->Fi, usim_dcb->Di 
*
*************************************************************************/
static void usim_process_TA1(kal_uint8 TA1, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	if(TA1 == ATR_TA1_64)
	{
#if defined(SIM_DEBUG_INFO)
		dbg_print("SPEED64 \r\n");
#endif
		usim_dcb->Fi = 512;
		usim_dcb->Di = 8;		
		usim_dcb->card_speed = SPEED_64;
	}
	else if(TA1 == ATR_TA1_32)
	{
#if defined(SIM_DEBUG_INFO)
		dbg_print("SPEED32 \r\n");
#endif
		usim_dcb->Fi = 512;
		usim_dcb->Di = 16;				
		usim_dcb->card_speed = SPEED_32;		
	}
	else if(TA1 == ATR_TA1_16)
	{	// only support speed32 even encounter a speed16 card
#if defined(SIM_DEBUG_INFO)
		dbg_print("SPEED16 \r\n");
#endif
		usim_dcb->Fi = 512;
#ifndef DRV_SIM_HIGH_SPEED
		usim_dcb->Di = 16;				
		usim_dcb->card_speed = SPEED_32;
#else
		usim_dcb->Di = 32;				
		usim_dcb->card_speed = SPEED_16;		
#endif
	}
	else if(TA1 == ATR_TA1_8)
	{	
#if defined(SIM_DEBUG_INFO)
		dbg_print("SPEED8 \r\n");
#endif
		usim_dcb->Fi = 512;
#ifndef DRV_SIM_HIGH_SPEED
		usim_dcb->Di = 16;
		usim_dcb->card_speed = SPEED_32;
#else
		usim_dcb->Di = 64;
		usim_dcb->card_speed = SPEED_8;
#endif
	}
	else
	{
#if defined(SIM_DEBUG_INFO)
		dbg_print("SPEED372 \r\n");		
#endif
		usim_dcb->Fi = 372;
		usim_dcb->Di = 1;					
		usim_dcb->card_speed = SPEED_372;		
	}
		 
}

/*************************************************************************
* FUNCTION
*  usim_process_PTS
*
* DESCRIPTION
*	1. Perform the PTS to select the protocol and enhanced speed parameter(Fn,Dn).
		T1 has higher priority than T0
*	2. Change the clock rate according to the PTS response
*	3. Enable the T0 or T1 controller according to the PTS response
*
* PARAMETERS
	None

* RETURNS
*	None
*
* GLOBALS AFFECTED
*	usim_dcb->speed
*
*************************************************************************/
static void usim_process_PTS(sim_HW_cb *hw_cb)
{
	kal_uint32 savedMask;
	kal_uint32 i;	
	kal_uint8 pts[PPS_LEN],pts_r[PPS_LEN],pck;
	usim_speed_enum speed;
	kal_bool echoed = KAL_TRUE;
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	

	/////dbg_print("usim_process_PTS \r\n");
	if(usim_dcb->app_proto == SIM_PROTOCOL)
	{
		/////dbg_print("PTS not performed (SIM_PROTOCOL) ");
		echoed = KAL_FALSE;
		goto exit;
	}
	if(usim_dcb->reset_mode == USIM_RESET_SPECIFIC)
	{
		/////dbg_print("not performed (specific mode)");
		echoed = KAL_TRUE;
		goto exit;
	}
	if(usim_dcb->high_speed_en)
	{
		if(usim_dcb->Di == 1)
			speed = SPEED_372;
		else if(usim_dcb->Di == 8)
			speed = SPEED_64;
		else if(usim_dcb->Di == 16)
			speed = SPEED_32;
#ifdef DRV_SIM_HIGH_SPEED
		else if(usim_dcb->Di == 32)
			speed = SPEED_16;
		else if(usim_dcb->Di == 64)
			speed = SPEED_8;
#endif		
		else
			speed = SPEED_372;
	}
	else
	{
		speed = SPEED_372;
	}
#if defined(SIM_DEBUG_INFO)
	dbg_print("select speed %d(372:64:32, 0:1:2)", speed); 
#endif	
	// generate PTS packet
	pts[PPSS] = 0xff;
	pck = 0xff;
	pts[PPS0] = USIM_PTS_PS1_MSK;
	if(usim_dcb->T1_support && usim_dcb->app_proto == USIM_PROTOCOL && !usim_dcb->T0_support ) // priority T1 > T0
	{	// T1 only usim card will go to here
#if defined(SIM_DEBUG_INFO)
		dbg_print("select T=1\r\n");
#endif
		pts[PPS0] |= USIM_PTS_PS0_T1;			
	}
#if defined(SIM_DEBUG_INFO)
	else
		dbg_print("select T=0\r\n");
#endif
	pck ^= pts[PPS0];
	if(speed == SPEED_372)
		pts[PPS1] = ATR_TA1_372_5;
	else if(speed == SPEED_64)
		pts[PPS1] = ATR_TA1_64;
	else if(speed == SPEED_32) 	// SPEED_32
		pts[PPS1] = ATR_TA1_32;					
#ifdef DRV_SIM_HIGH_SPEED
	else if(speed == SPEED_16) 	// SPEED_16
		pts[PPS1] = ATR_TA1_16;
	else if(speed == SPEED_8) 	// SPEED_8
		pts[PPS1] = ATR_TA1_8;
#endif
	pck ^= pts[PPS1];
		
	// send PTS packet
	usim_dcb->main_state = PTS_STATE;	
	pts[PCK] = pck;
	SIM_FIFO_Flush();	            
	// delay 100 clock cycles (30us) [MAUI_03431888]/[MAUI_03433590]
	while(SIM_Reg(SIM0_BASE_ADDR_MTK+SIM_CLR_STA)==1);
	/*
	{
		kal_uint32 t1;
		t1 = SIM_GetCurrentTime();
		while((SIM_GetCurrentTime()-t1) < 1);
	}  
	*/
	
	SIM_SetRXTIDE(PPS_LEN, hw_cb); 
	savedMask = SaveAndSetIRQMask();
	for(i=0;i<PPS_LEN;i++)
	{		
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,pts[i]);
	}
	RestoreIRQMask(savedMask);
	usim_set_timeout(INIT_WWT_T0, hw_cb);
	kal_set_eg_events(usim_dcb->event, 0, KAL_AND);
	DRV_ICC_GPTI_StopItem(usim_dcb->gpt_handle);
	USIM_WAIT_EVENT_MTK(usim_dcb);
	usim_set_timeout(0, hw_cb);
	if(usim_dcb->ev_status != USIM_NO_ERROR)
		echoed = KAL_FALSE;
	// read the response
	if(echoed)
	{
		for(i=0;i<PPS_LEN;i++)
		{		
			pts_r[i] = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK);
			if(pts[i]!= pts_r[i])
				echoed = KAL_FALSE;
		}
	}
	if(echoed)
	{
		dbg_print("PTS OK!\r\n");
		usim_set_speed(speed, hw_cb); 
		// Some high speed SIM card after clock rate change have to wait a while to
		// to receive the first command.
		if(pts[1] != 0x00)
			kal_sleep_task(10);
	}
	else
	{
		dbg_print("PTS Fail!\r\n");
		usim_set_speed(SPEED_372, hw_cb);
	}

exit:	
	// GSM will only use T=0, no matter t=1 is supported.
	if(usim_dcb->T1_support && !usim_dcb->T0_support &&
		(usim_dcb->app_proto == USIM_PROTOCOL) && echoed )
	{	// T1 only usim card will go to here
		usim_dcb->phy_proto = T1_PROTOCOL;		
		usim_set_protocol(T1_PROTOCOL, hw_cb);
		USIM_DISABLE_TXRX_HANSHAKE();					
		SIM_SetRXRetry(hw_cb, 0);
		SIM_SetTXRetry(hw_cb, 0);
	}
	else
	{
		usim_dcb->phy_proto = T0_PROTOCOL;	
		if(usim_dcb->app_proto == USIM_PROTOCOL)
			usim_set_protocol(T0_PROTOCOL, hw_cb); // SIM_PROTOCOL is enabled at simd.c			
		SIM_SetRXRetry(hw_cb, 7);
		SIM_SetTXRetry(hw_cb, 7);
		USIM_ENABLE_TXRX_HANSHAKE();
	}
	
	
}

/*************************************************************************
* FUNCTION
*  usim_set_timeout
*
* DESCRIPTION
*	 setup the timeout value in the unit of etu
*
* PARAMETERS
*	timeout: timeout value in the unit of etu , 0 means disabling timeout
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void usim_set_timeout(kal_uint32 timeout, sim_HW_cb *hw_cb)
{	
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
	if(timeout)
	{
		timeout >>= 2;
		SIM_SetTOUT(timeout+TOUT_OFFSET,hw_cb);
		usim_dcb->timeout = timeout+TOUT_OFFSET;
	}
	else
	{
		USIM_DISABLE_TOUT();
	}
}
/*************************************************************************
* FUNCTION
*  usim_set_speed
*
* DESCRIPTION
*	 setup the baudrate of the SIM card, only support 372, 64 and 32.
*	 speed 16 is not supported, use speed32 insteadly.
*
* PARAMETERS
*	timeout: timeout value in the unit of etu , 0 means disabling timeout
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void usim_set_speed(usim_speed_enum speed, sim_HW_cb *hw_cb)
{	
	usim_dcb_struct *usim_dcb;

   kal_uint16 sim_brr_div[SPEED_MAX] = {SIM_BRR_BAUD_Div372,
                                        SIM_BRR_BAUD_Div64,
                                        SIM_BRR_BAUD_Div32,
                                        SIM_BRR_BAUD_Div16,
                                        SIM_BRR_BAUD_Div8
                                        };
	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
			// clock: 13/4 = 3.25M, with default etu F/372
   SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK, (SIM_BRR_CLK_Div4 | sim_brr_div[speed]));	
	usim_dcb->speed = speed;		
	usim_dcb->BWT = usim_dcb->BWT*BWT_Factor[speed]+11;
}
/*************************************************************************
* FUNCTION
*  usim_set_protocol
*
* DESCRIPTION
*	 setup the physical protocol layer including T=0 and T=1.
*
* PARAMETERS
*	T: physical protocol layer including T=0 and T=1.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void usim_set_protocol(usim_protocol_enum T, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
	if( T == T1_PROTOCOL)
	{
		USIM_ENABLE_T1();
	}
	else
	{
		USIM_ENABLE_T0();
	}
	usim_dcb->phy_proto = T;
}
/*************************************************************************
* FUNCTION
*  usim_select_power
*
* DESCRIPTION
	1. Try the input voltage from application layer if availabe.
	2. Try the possible voltage which the ME can support.
	3. Get the valid TS
*
* PARAMETERS
	1. ExpectVolt: application layer give a expected power class

* RETURNS
*  KAL_TRUE: Valid TS is received
*  KAL_FALSE: Valid TS is not received, card is not present or not supported
*
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static kal_bool usim_select_power(usim_power_enum ExpectVolt, sim_HW_cb *hw_cb)
{
	kal_uint32 retry;
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
	/////dbg_print("usim_select_power with power: %d \r\n", ExpectVolt);

	SIM_FIFO_Flush();	
	if(usim_dcb->warm_rst == KAL_FALSE)
	{
		usim_deactivation(hw_cb);
		// decide the initial power class
		usim_dcb->power_in = ExpectVolt;
		if(ExpectVolt != UNKNOWN_POWER_CLASS)
		{			
			usim_dcb->power = ExpectVolt;
		}
		else
		{		
			if (usim_dcb->sim_env == ME_30V_ONLY)
			{
				usim_dcb->power = CLASS_B_30V;
			}
			else // ME_18_ONLY, ME_18V_30V
			{
			   usim_dcb->power = CLASS_C_18V;
			}
		}
	}	
	// start from low power class to high, if no ATR received, try another power class
	// if the an invalid TS byte is received, change the convention with the same power class
	retry = 0;
	while(retry++ < 3)
	{
		kal_set_eg_events(usim_dcb->event,0,KAL_AND);
		//2007_04_12, some 3G card will give wrong ATR in the first time, and we should reset it twice
		//If we don't reset these 2 variables, former wrong path will affect next time we process ATR
		usim_dcb->abort = usim_dcb->resync = KAL_FALSE;
		usim_activation(hw_cb);	
		USIM_WAIT_EVENT_MTK(usim_dcb);

#if	!defined( __MAUI_BASIC__) || defined(MEUT_ON_FPGA)
#if !defined(__L1_STANDALONE__)
#if defined(SIM_DEBUG_INFO)
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL1, __LINE__,
			usim_dcb->ev_status, usim_dcb->power, 
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), drv_get_current_time()
		);
#endif
#endif
#endif

		if(usim_dcb->ev_status == USIM_NO_ERROR )
		{	// a correct TS byte is received			
			USIM_WAIT_EVENT_MTK(usim_dcb);			
			// all ATR characters are received
			if(usim_dcb->ev_status != USIM_ATR_REC)
				return KAL_FALSE;
			else
				return KAL_TRUE;
		}
		else if(usim_dcb->ev_status == USIM_ATR_REC)
		{	// all ATR characters are received
			return KAL_TRUE;
		}
//#ifdef NO_SLIM_DEF
		else if(usim_dcb->warm_rst == KAL_TRUE)
		{
#if defined(SIM_DEBUG_INFO)
			dbg_print("warm reset fail!!\r\n");
#endif
			usim_deactivation(hw_cb);
			return KAL_FALSE;
		}
//#endif		
		else if((usim_dcb->ev_status == USIM_TS_INVALID || usim_dcb->ev_status == USIM_RX_INVALID)
			&& (usim_dcb->dir == USIM_DIRECT))
		{				
			// try another convention 
			usim_dcb->dir = (USIM_INVERSE == usim_dcb->dir)? USIM_DIRECT: USIM_INVERSE;
			usim_deactivation(hw_cb);			
#if defined(SIM_DEBUG_INFO)
			dbg_print("change another convention %d !!\r\n", usim_dcb->dir);			
#endif
		}
		else if(usim_dcb->ev_status == USIM_NO_ATR || usim_dcb->ev_status == USIM_BWT_TIMEOUT ||
			(usim_dcb->ev_status == USIM_TS_INVALID || usim_dcb->ev_status == USIM_RX_INVALID ))
		{
			retry = 0;
			usim_dcb->dir = USIM_DIRECT;
			// deactivate and delay			
			usim_deactivation(hw_cb);
			// change another power class if availabe, no retry with the same power class
			if(usim_dcb->sim_env == ME_18V_30V )
			{
				if(usim_dcb->power_in == UNKNOWN_POWER_CLASS && usim_dcb->power == CLASS_C_18V )
				{
					usim_dcb->power = CLASS_B_30V;
				}
				else if(usim_dcb->power_in != UNKNOWN_POWER_CLASS && usim_dcb->power_in == usim_dcb->power)
				{
					if(usim_dcb->power_in == CLASS_C_18V)
						usim_dcb->power = CLASS_B_30V;
					else
						usim_dcb->power = CLASS_C_18V;
				}				
				else
				{
					return KAL_FALSE;
				}				
			}
			else
			{
				return KAL_FALSE;
			}
			
		}
		else
		{
			ASSERT(0);
		}
	}
	return KAL_FALSE;
}
/*************************************************************************
* FUNCTION
*  usim_activation
*
* DESCRIPTION
* Perform the activation of USIM
* It is a cold reset
* select the power according to usim_dcb->power (input)
* select the convention according to usim_dcb->dir (input)
* the clock rate adopted is SPEED_372
* set the default timeout value
*
* PARAMETERS
	None
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static void usim_activation(sim_HW_cb *hw_cb)
{
	kal_uint16 reg = 0;
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	

	/////dbg_print("usim_activation, pow = %d, dir: %d \r\n",usim_dcb->power, usim_dcb->dir);




#if defined(__DRV_SIM_NEED_CUSTOM_CONTROL__)
/*old method, just copy here and will change it when necessary*/
	if(0 == simInterface){
		if (usim_dcb->power == CLASS_B_30V)
      			SIM_custom_SetVdd(0, PMIC_VSIM_3_0);
	   	else
      			SIM_custom_SetVdd(0, PMIC_VSIM_1_8);
	}
	else{
		if (usim_dcb->power == CLASS_B_30V)
      			SIM_custom_SetVdd(1, PMIC_VSIM_3_0);
	   	else
      			SIM_custom_SetVdd(1, PMIC_VSIM_1_8);
	}
#elif (!defined(__DRV_SIM_SIMIF_CONTROL_VSIM__))

	/*use PMU API*/
	if(SIM_base == hw_cb->mtk_baseAddr){
		DRV_ICC_PMU_setVolt(0, usim_dcb->power);
	}
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
	else if(SIM2_base == hw_cb->mtk_baseAddr){
		DRV_ICC_PMU_setVolt(1, usim_dcb->power);
	}
#endif

#else //configure through SIMIF setting
	if (usim_dcb->power == CLASS_B_30V)
	{
		reg = SIM_CONF_SIMSEL;
#if defined (MT6250)        
   if(SIM_base == hw_cb->mtk_baseAddr){
      SIM_SetData(0xA0700054, 0x0300, 0x0300); //�YVSIM1��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
   else if(SIM2_base == hw_cb->mtk_baseAddr){
      SIM_SetData(0xA0700054, 0x3000, 0x3000); //�YVSIM2��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#endif

#elif defined (MT6260)   
   //wait oscar's PMU add new interface     
   if(SIM_base == hw_cb->mtk_baseAddr){
      SIM_SetData(0xA0700050, 0x0300, 0x0300); //�YVSIM1��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
   else if(SIM2_base == hw_cb->mtk_baseAddr){
      SIM_SetData(0xA0700050, 0x3000, 0x3000); //�YVSIM2��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#endif

#else   
   //wait oscar's PMU add new interface     
   if(SIM_base == hw_cb->mtk_baseAddr){
 	DRV_ICC_PMU_setVolt2(0, CLASS_B_30V);
      //SIM_SetData(0xA0700050, 0x0300, 0x0300); //�YVSIM1��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
   else if(SIM2_base == hw_cb->mtk_baseAddr){
	DRV_ICC_PMU_setVolt2(1, CLASS_B_30V);
      //SIM_SetData(0xA0700050, 0x3000, 0x3000); //�YVSIM2��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#endif
#endif 
	}
	else if (usim_dcb->power == CLASS_C_18V)
	{
#if defined (MT6250)        
   if(SIM_base == hw_cb->mtk_baseAddr){
      SIM_ClearBits(0xA0700054, 0x0100); //�YVSIM1��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
   else if(SIM2_base == hw_cb->mtk_baseAddr){
      SIM_ClearBits(0xA0700054, 0x1000); //�YVSIM2��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#endif

#elif defined (MT6260)        
   if(SIM_base == hw_cb->mtk_baseAddr){
      SIM_ClearBits(0xA0700050, 0x0100); //�YVSIM1��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
   else if(SIM2_base == hw_cb->mtk_baseAddr){
      SIM_ClearBits(0xA0700050, 0x1000); //�YVSIM2��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#endif

#else        
   if(SIM_base == hw_cb->mtk_baseAddr){
	DRV_ICC_PMU_setVolt2(0, CLASS_C_18V);
      //SIM_ClearBits(0xA0700050, 0x0100); //�YVSIM1��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
   else if(SIM2_base == hw_cb->mtk_baseAddr){
   	DRV_ICC_PMU_setVolt2(1, CLASS_C_18V);
      //SIM_ClearBits(0xA0700050, 0x1000); //�YVSIM2��3V�A�h�ݥ��z�LPMU register�]�w3V(default��1.8V)
   }
#endif
#endif 

	}
#ifdef DRV_SIM_VSIM2_ISSUE_76_SERIES
	if(SIM2_base == hw_cb->mtk_baseAddr){
		DRV_ICC_PMU_setVolt(1, usim_dcb->power);
	}
#endif //DRV_SIM_VSIM2_ISSUE_76_SERIES

#endif   //configure through SIMIF setting






	if(usim_dcb->dir == USIM_DIRECT)
		reg |= SIM_CONF_Direct;
	else
		reg |= SIM_CONF_InDirect;
	
	if(KAL_TRUE == usim_dcb->ts_hsk_en)
	{
		reg |= (SIM_CONF_TXHSK | SIM_CONF_RXHSK);
      SIM_SetRXRetry(hw_cb, 1);
	   SIM_SetTXRetry(hw_cb, 1);		
	}
	else
	{
      SIM_SetRXRetry(hw_cb, 0);
	   SIM_SetTXRetry(hw_cb, 0);		
	}	
	SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK,reg);
	
	SIM_FIFO_Flush();
	// delay 100 clock cycles (30us) [MAUI_03431888]/[MAUI_03433590]
	while(SIM_Reg(SIM0_BASE_ADDR_MTK+SIM_CLR_STA)==1);
	/*
	{
		kal_uint32 t1;
		t1 = SIM_GetCurrentTime();
		while((SIM_GetCurrentTime()-t1) < 1);
	}  
	*/
	SIM_SetRXTIDE(2, hw_cb);	// generate a interrupt while TS byte and T0 is received
	SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,USIM_IRQEN_ATR|SIM_STS_RXERR);
	reg = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
	usim_dcb->main_state = ACTIVATION_STATE;
	usim_dcb->ev_status = USIM_NO_ERROR;
	if(usim_dcb->warm_rst == KAL_FALSE)
	{

#if !defined(__DRV_SIM_SIMIF_CONTROL_VSIM__)
               if(SIM_base == hw_cb->mtk_baseAddr){
	            DRV_ICC_PMU_switch(0, KAL_TRUE);
               }
               else{
		     DRV_ICC_PMU_switch(1, KAL_TRUE);
               }
#endif


		sim_addMsg(SIM_DRIVER_ACT, hw_cb->simInterface, usim_dcb->power_in, usim_dcb->power);
		 USIM_POW_ON();	
 	}
	else
	{
		USIM_WRST();
		kal_sleep_task(10);
	}
	// go to usim_hisr of case RXTIDE, ATRERR, RXERR(parity error)
}
	
void usim_lisr_Multiple(void)
{
	sim_HW_cb *hw_cb;
	
	hw_cb = (sim_HW_cb *)(hwCbArray[sim_get_logical_from_SIMIF(0)]);
   IRQMask(hw_cb->mtk_lisrCode);
   drv_active_hisr(DRV_USIM_HSIR_ID);
}

void usim_lisr2_Multiple(void)
{
	sim_HW_cb *hw_cb;
	
	hw_cb = (sim_HW_cb *)(hwCbArray[sim_get_logical_from_SIMIF(1)]);
   IRQMask(hw_cb->mtk_lisrCode);
   drv_active_hisr(DRV_USIM2_HSIR_ID);
}
/*************************************************************************
* FUNCTION
*  usim_deactivation
*
* DESCRIPTION
*	1. deactivate the UICC card 
*	2. wait util the the deactivation is complete
*
* PARAMETERS
	None
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb->main_state
*
*************************************************************************/
static void usim_deactivation(sim_HW_cb *hw_cb) 
{	
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
	/////dbg_print("usim_deactivation\r\n");

	if(SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK)&SIM_CTRL_SIMON)
	{
		kal_uint32 i = 5;

		sim_addMsg(SIM_DRIVER_DEACT, hw_cb->simInterface, 0, 0);
		// before deactivate the SIM interface, turn on the clock first.
		SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);
		while(i--);
		kal_set_eg_events(usim_dcb->event,0,KAL_AND);
		sim_addMsg(SIM_DEACTIVATE_1, hw_cb->simInterface, usim_dcb->main_state, usim_dcb->ev_status);
	   SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_SIMOFF);
	   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_SIMON);
	   USIM_WAIT_EVENT_MTK(usim_dcb);

	/*turn off LDO*/

#if !defined(__DRV_SIM_SIMIF_CONTROL_VSIM__)
               if(0 == sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface)){
	            DRV_ICC_PMU_switch(0, KAL_FALSE);
               }
               else{
		     DRV_ICC_PMU_switch(1, KAL_FALSE);
               }
#endif
	kal_sleep_task(16);


	   
	   sim_addMsg(SIM_DEACTIVATE_2, hw_cb->simInterface, usim_dcb->main_state, usim_dcb->ev_status);
	     
	   USIM_CLR_FIFO();
	   usim_dcb->main_state = DEACTIVATION_STATE;
	   if(usim_dcb->ev_status == USIM_POWER_OFF)
	   	usim_dcb->main_state = DEACTIVATION_STATE;
	   else 
	   	ASSERT(0);
	}
}
/*************************************************************************
* FUNCTION
*  usim_t1end_handler
*
* DESCRIPTION
*	1. it is called while t1end interrupt is generated.
*	2. there are two different states in this function: 
		CMD_TX_STATE: a complete block is sent to UICC
		CMD_RX_INF_STATE: a complete block is received from UICC 
*
* PARAMETERS
	None
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb->main_state
*
*************************************************************************/
static void usim_t1end_handler(sim_HW_cb *hw_cb)
{	
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
#if defined(SIM_DEBUG_INFO)
	dbg_print("usim_t1end_handler ");
#endif
	switch(usim_dcb->main_state)
	{
		case CMD_TX_STATE:
#if defined(SIM_DEBUG_INFO)
			dbg_print("CMD_TX_STATE ");
#endif
			USIM_DMA_RX_TIDE();
#if defined (__SIM_DVT__)
			if(KAL_TRUE == useT1Switch && T1SwitchEnabled){
#if	!defined( __MAUI_BASIC__)
							 tst_sys_trace("T1 switched ");
#else
							 dbg_print("T1 switched ");
#endif

				/*flush DMA*/
				//DRV_WriteReg(0x60020414, 0x1);
				/*clear TXdisable*/
				//DRV_ClearBits(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, 0x1000);

			}
			else{
#endif /* End of #if defined (__SIM_DVT__) */
#ifdef SIM_CACHED_SUPPORT
			GET_NCACHED_USIM_DMA_BUF_INT(usim_dcb->dma_menu.addr, sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface));
#else						
			usim_dcb->dma_menu.addr = (kal_uint32)usim_dcb->dma_buffer;  // (kal_uint32)usim_dcb.rx_buf+usim_dcb->rx_index;
#endif
			usim_dcb->dma_input.type = DMA_HWRX;
			usim_dcb->dma_input.count = USIM_DMA_MAX_SIZE;
			DMA_Config(usim_dcb->dma_port,&usim_dcb->dma_input,KAL_TRUE);
#if defined (__SIM_DVT__)
			}
#endif /* End of #if defined (__SIM_DVT__) */
			if(usim_dcb->wtx == KAL_TRUE)
			{
				usim_dcb->wtx = KAL_FALSE;
				usim_set_timeout(usim_dcb->BWT * usim_dcb->wtx_m, hw_cb);
			}
			else
				usim_set_timeout(usim_dcb->BWT, hw_cb);
			usim_dcb->ev_status = USIM_NO_ERROR;
			usim_dcb->main_state = CMD_RX_STATE;
			SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, (SIM_STS_EDCERR|SIM_STS_RXERR|SIM_STS_T1END|SIM_STS_OV|SIM_STS_TOUT));
			break;
		case CMD_RX_STATE:
			{
				kal_uint8 len, pcb;
#ifdef SIM_CACHED_SUPPORT
				kal_uint8 *dma_buffer;
				GET_NCACHED_USIM_DMA_BUF_P(dma_buffer, sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface));
#else							
				kal_uint8 *dma_buffer = usim_dcb->dma_buffer;
#endif					
				
#if defined (__SIM_DVT__)
#if	!defined( __MAUI_BASIC__)
											 tst_sys_trace("CMD_RX_STATE ");
#else
											 kal_print("CMD_RX_STATE ");
#endif

#endif /* End of #if defined (__SIM_DVT__) */
				usim_set_timeout(0, hw_cb);
#if defined (__SIM_DVT__)
				if(KAL_TRUE == useT1Switch && T1SwitchEnabled){
					/*flush DMA*/
					//DRV_WriteReg(0x60020414, 0x1);
				}
#endif /* End of #if defined (__SIM_DVT__) */
#ifdef DRV_SIM_DMA_V2
            DMA_CleanUp(usim_dcb->dma_port);
//				DMA_Flush(usim_dcb->dma_port);
//				DMA_WaitforDone(usim_dcb->dma_port);   //a while loop to check running status.
//            DMA_WaitforDone_timeout(usim_dcb->dma_port);   //a while loop to check running status.
#if 0
#if defined (__SIM_DVT__)
/* under construction !*/
/* under construction !*/
#endif
#endif
				/*For short packets those haven't trigger DMA transfer, the 1st byte, NAD, havn't been updated in EMI.
				we need to wait enought time before EMI updated so that it is valid to latch NAD later.
				*/
				{
					kal_uint32 delayTime1;

					delayTime1 = drv_get_current_time();
					while(delayTime1 == drv_get_current_time());
				}
#else
				DMA_Stop(usim_dcb->dma_port);	
#endif
#if defined (__SIM_DVT__)
				if(KAL_TRUE == useT1Switch && T1SwitchEnabled){
					T1SwitchEnabled = KAL_FALSE;
					DRV_ClearBits(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, 0x2000);
					kal_sprintf(sim_dbg_str,"(%x,%x,%x)", dma_buffer[T1_NAD_INDEX], dma_buffer[T1_PCB_INDEX], dma_buffer[T1_LEN_INDEX]);
#if	!defined( __MAUI_BASIC__)
					tst_sys_trace(sim_dbg_str);
#else
					kal_print(sim_dbg_str);
#endif

				}
#endif /* End of #if defined (__SIM_DVT__) */
				if(usim_dcb->ev_status == USIM_RX_INVALID)
				{
					// comes from EDC or parity error
					USIM_SET_EVENT_Multiple(usim_dcb);
					return;
				}
				// receive a complete block, except a S-block received, there still is one
				// parameter byte in the fifo
				usim_dcb->header_rx[T1_NAD_INDEX] = dma_buffer[T1_NAD_INDEX]; // NAD
				pcb = usim_dcb->header_rx[T1_PCB_INDEX] = dma_buffer[T1_PCB_INDEX]; // PCB
				len = usim_dcb->header_rx[T1_LEN_INDEX] = dma_buffer[T1_LEN_INDEX]; // LEN	
#if defined(SIM_DEBUG_INFO)
				dbg_print("CMD_RX_STATE (reveive a block!! len: %d)",len );
#endif
#if defined (__SIM_DVT__)
				kal_sprintf(sim_dbg_str,"CMD_RX_STATE (reveive a block!! len: %d)",len );
#if	!defined( __MAUI_BASIC__)
				tst_sys_trace(sim_dbg_str);
#else
				kal_print(sim_dbg_str);
#endif

#endif /* End of #if defined (__SIM_DVT__) */
				if(len)
				{
					if(len == 1 && USIM_IS_SBLOCK(pcb))
					{
						usim_dcb->header_rx[T1_INF_INDEX] = dma_buffer[T1_INF_INDEX];
					}
					else
					{
						kal_mem_cpy(usim_dcb->rx_buf+usim_dcb->rx_index, &dma_buffer[T1_INF_INDEX], len);
					}
				}
				usim_dcb->ev_status = USIM_NO_ERROR;							
				USIM_SET_EVENT_Multiple(usim_dcb);
			}
			break;

		default:
			break;
	}
#if defined(SIM_DEBUG_INFO)
	dbg_print("\r\n");
#endif	
}
static void usim_timeout_handler(sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
#if defined(SIM_DEBUG_INFO)
	dbg_print("usim_timeout_handler ");
#endif	
	switch(usim_dcb->main_state)
	{
		case ATR_STATE:			
#if defined(SIM_DEBUG_INFO)
			dbg_print("ATR_STATE (timeout) should not go over here ");
#endif
			// may be optimized by parsing the content instead of using timeout.
			// read the remaining bytes of ATR
			{
				kal_uint32 count;
				
				count = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK);
				while(count--)
				{
					usim_dcb->ATR_data[usim_dcb->ATR_index++] = (kal_uint8)SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK);
				}
            usim_dcb->ev_status = USIM_ATR_REC;	
            USIM_SET_EVENT_Multiple(usim_dcb);
			}			
			break;
		case CLK_STOPPING_STATE:
#if defined(SIM_DEBUG_INFO)
			 dbg_print("CLK_STOPPING_STATE ");
#endif
			{
				kal_bool level;

				usim_set_timeout(0, hw_cb);
				usim_dcb->main_state = CLK_STOPPED_STATE;
				if(usim_dcb->clock_stop_type == CLOCK_STOP_HIGH )				
					level = KAL_TRUE;
				else
					level = KAL_FALSE; 
	               	SIM_Idle_MTK(level, hw_cb);
#ifndef __DRV_SIM_REG_ON_PDN_V2__
	               	/*controller's clock must now stopped, verify it*/
				if((SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK) & 0x2) != 0x2)
					ASSERT(0);
#endif
	               	 				
				SIM_DisAllIntr();
				#if defined(USIM_DEBUG)
				end = get_duration_tick(start);
				dbg_print("clock stoped!! duration = %d", end);
				#endif
			}
			break;
		case CLK_STOPPED_STATE:
#if defined(SIM_DEBUG_INFO)
			dbg_print("CLK_STOPPED_STATE ");
#endif
			{
				usim_dcb->main_state = MAIN_CMD_READY_STATE;
				usim_dcb->ev_status = USIM_NO_ERROR;
				USIM_SET_EVENT_Multiple(usim_dcb);
#if defined(SIM_DEBUG_INFO)
				dbg_print("clock start!!");
#endif
			}
			break;
		default:
#if defined(SIM_DEBUG_INFO)
			dbg_print("default:");
#endif
			DMA_Stop(usim_dcb->dma_port);	
			usim_dcb->ev_status = USIM_BWT_TIMEOUT;
			USIM_SET_EVENT_Multiple(usim_dcb);
	}
#if defined(SIM_DEBUG_INFO)	
	dbg_print("\r\n");
#endif	
}

static void usim_hisr_common(sim_HW_cb *hw_cb, kal_uint32 int_status)
{
	usim_dcb_struct *usim_dcb;
	//not like Gemini project, in dual controller solution, we need 2 individual HISR and thus every HISR mapping fixed interface
	usim_dcb = GET_USIM_CB(hw_cb->simInterface);

	usim_dcb->int_status = int_status;	
	PUSH_INT(int_status);
	/////dbg_print("usim_hisr int:%x\r\n",int_status);
#if defined (__SIM_DVT__)
				kal_sprintf(sim_dbg_str,"usim int Status:%x",int_status);
#if	!defined( __MAUI_BASIC__)
								tst_sys_trace(sim_dbg_str);
#else
							  kal_print(sim_dbg_str);
#endif
#endif /* End of #if defined (__SIM_DVT__) */

	if(int_status & SIM_STS_RXERR )
	{
#if defined(SIM_DEBUG_INFO)
		dbg_print("parity error \r\n");
#endif
		usim_set_timeout(0, hw_cb);
		usim_dcb->ev_status = USIM_RX_INVALID;
		if(usim_dcb->main_state ==  ACTIVATION_STATE)
		{
			SIM_DisAllIntr();
			USIM_SET_EVENT_Multiple(usim_dcb);
			goto end_of_hisr;
		}
		// wait t1end interrupt
	}
	
	if(int_status& SIM_STS_EDCERR)
	{	
#if defined(SIM_DEBUG_INFO)
		dbg_print("EDC error \r\n");
#endif
		usim_set_timeout(0, hw_cb);
		usim_dcb->ev_status = USIM_RX_INVALID;		
	}
	if(int_status& SIM_STS_TOUT)
	{
 		usim_timeout_handler(hw_cb);
 		goto end_of_hisr;
	}	
	if(int_status & SIM_STS_T1END)
	{
		usim_t1end_handler(hw_cb);
	}	
	if(int_status & SIM_STS_RX)
	{
		usim_rx_handler(int_status, hw_cb);
	}	
	if(int_status & SIM_STS_SIMOFF)
	{
		usim_dcb->ev_status = USIM_POWER_OFF;
		USIM_SET_EVENT_Multiple(usim_dcb);
		goto end_of_hisr;
	}
	if(int_status & SIM_STS_TXERR || int_status & SIM_STS_OV)
	{
		ASSERT(0);
	}	
	if(int_status & SIM_STS_NATR)
	{
		usim_dcb->ev_status = USIM_NO_ATR;
		USIM_SET_EVENT_Multiple(usim_dcb);
	}
	
end_of_hisr:
	
	IRQClearInt(hw_cb->mtk_lisrCode);
	IRQUnmask(hw_cb->mtk_lisrCode);   
	
	
}

static void usim_hisr(void)
{
	kal_uint32 int_status;
	sim_HW_cb *hw_cb;
	usim_dcb_struct *usim_dcb;

	/*logical SIM 1 not exactly work on physical SIM1 interface, we only know interrrupt comes from SIM1, have to find its logical */
	hw_cb = (sim_HW_cb *)(hwCbArray[sim_get_logical_from_SIMIF(0)]);
	//not like Gemini project, in dual controller solution, we need 2 individual HISR and thus every HISR mapping fixed interface
	usim_dcb = GET_USIM_CB(hw_cb->simInterface);

	int_status = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
	sim_addMsg(SIM_INT_USIM, 0, int_status, usim_dcb->ev_status);
	usim_hisr_common(hw_cb, int_status);
}


static void usim_hisr2(void)
{
	kal_uint32 int_status;
	sim_HW_cb *hw_cb;
	usim_dcb_struct *usim_dcb;

	hw_cb = (sim_HW_cb *)(hwCbArray[sim_get_logical_from_SIMIF(1)]);
	//not like Gemini project, in dual controller solution, we need 2 individual HISR and thus every HISR mapping fixed interface
	usim_dcb = GET_USIM_CB(hw_cb->simInterface);

	int_status = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
	sim_addMsg(SIM_INT_USIM, 1, int_status, usim_dcb->ev_status);	
	usim_hisr_common(hw_cb, int_status);	
}



/*************************************************************************
* FUNCTION
*  usim_rx_handler
*
* DESCRIPTION
*	1. It is called byt usim_hisr
*	2. It is called while RXTIDE interrupt is triggerred
*
* PARAMETERS
	None
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static void usim_rx_handler(kal_uint32 int_status, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;
#if defined (__SIM_DVT__)
   kal_uint16 i;
#endif
	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
	/////dbg_print("usim_rx_handler ");
	
	switch(usim_dcb->main_state)
	{
		case ACTIVATION_STATE:
			/////dbg_print("ACTIVATION_STATE ");		
			{
				kal_uint8 TS,T0,count;

#if defined (__SIM_DVT__)
				for (i = 0;i < 16; i++)
					ATR[i] = SIM_Reg(SIM0_BASE_ADDR_MTK + 0x0094);
#endif
				TS = SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_DATA_MTK));
				/////dbg_print("TS = %x ", TS);
				if(TS == 0x3B || TS == 0x3F)
				{					
					usim_set_timeout(INIT_WWT_T0, hw_cb);
					USIM_ENABLE_TXRX_HANSHAKE();					
					SIM_SetRXRetry(hw_cb, USIM_RETRY);
					SIM_SetTXRetry(hw_cb, USIM_RETRY);    
					count = 0;
					T0 = SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_DATA_MTK));
					usim_dcb->hist_index = T0&0xf; // use to contain the length of historical char (temperary)
					USIM_CAL_TD_COUNT(T0, count);
					if((T0 & TDMask) == (kal_uint32)NULL)
					{
						count += usim_dcb->hist_index;
						if(count >= SIM_TOTAL_FIFO_LEN)
						{
							usim_dcb->abort = KAL_TRUE;	// for temp usage (separate two times)
							count -= 6;					
						}
						usim_dcb->resync = KAL_TRUE; // for temp usage (last time)								
					}
					else
						count++;
					if(count == 0)
					{
						usim_dcb->ev_status = USIM_ATR_REC;
						USIM_SET_EVENT_Multiple(usim_dcb);
					}
					else
					{
						usim_dcb->rx_size = count+1;	// for temp usage (index to TD byte)
						SIM_SetRXTIDE(count, hw_cb); 
						SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK),USIM_IRQEN_NORMAL);
						usim_dcb->ev_status = USIM_NO_ERROR;
					}
					
					usim_dcb->main_state = ATR_STATE;
					usim_dcb->ATR_index = 0;
					usim_dcb->ATR_data[usim_dcb->ATR_index++] = TS;
					usim_dcb->ATR_data[usim_dcb->ATR_index++] = T0;
				}	
				else
				{					
					usim_dcb->ev_status = USIM_TS_INVALID;
					SIM_DisAllIntr(); // prevent the following ATR bytes trigger RX interrupt
					SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
				}		
				USIM_SET_EVENT_Multiple(usim_dcb);
			}			
			break;
		case ATR_STATE:			
			{	// receive all ATR data without timeout to indicate
				kal_uint32 count;
				kal_uint8 TD;
				
				count = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK);
#if defined (__SIM_DVT__)
				for (i = 0;i < 16; i++)
					ATR[i] = SIM_Reg(SIM0_BASE_ADDR_MTK + 0x0094);
#endif
				/////dbg_print("ATR_STATE : %d ",count);				
				while(count--)
					usim_dcb->ATR_data[usim_dcb->ATR_index++] = (kal_uint8)SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK);
				if(usim_dcb->abort == KAL_TRUE)
				{
					usim_dcb->abort = KAL_FALSE;
					SIM_SetRXTIDE(6, hw_cb); 
					usim_dcb->resync = KAL_TRUE;
					break;
				}
				if(usim_dcb->resync == KAL_FALSE)
				{
					TD = usim_dcb->ATR_data[usim_dcb->rx_size];
					/////dbg_print(", TD = %x ,%d", TD,usim_dcb->rx_size);
					count = 0;
					USIM_CAL_TD_COUNT(TD, count);			
					if((TD & TDMask) == (kal_uint32)NULL)
					{
						count += usim_dcb->hist_index;
						if(count >= SIM_TOTAL_FIFO_LEN)
						{
							// usim_dcb->rx_index = count; // for temp usage (total ATR len)
							usim_dcb->abort = KAL_TRUE;	// for temp usage (separate two times)
							count -= 6;					
						}
						usim_dcb->resync = KAL_TRUE; // for temp usage (last time)								
					}
					else
						count++;				
					usim_dcb->rx_size += (count);	// for temp usage (index to TD byte)
					SIM_SetRXTIDE(count, hw_cb); 					
				}
				else
				{
					usim_set_timeout(0, hw_cb);
					/////dbg_print("\r\n!! all ATR received \r\n");
					usim_dcb->hist_index = 0;
					usim_dcb->rx_size = 0;					
					usim_dcb->resync = KAL_FALSE;
					usim_dcb->abort = KAL_FALSE;
	            usim_dcb->ev_status = USIM_ATR_REC;
	            USIM_SET_EVENT_Multiple(usim_dcb);					
				}				
			}
			break;
		case PTS_STATE:
			SIM_DisAllIntr();
			usim_dcb->ev_status = USIM_NO_ERROR;
			USIM_SET_EVENT_Multiple(usim_dcb);
			break;			

		default:
			break;
	}
}

/*************************************************************************
* FUNCTION
*  usim_send_block
*
* DESCRIPTION
*	1. sending a block to UICC, with header in usim_dcb->header_tx
*	2. if len > 0 then using DMA to transfer data from tx buffer to the fifo of sim
		interface.
	3. after a complete block is sent, T1END is generated
	4. after that, three bytes of received block header will come into rx fifo
*
* PARAMETERS
	adrs: tx buffer address
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static void usim_send_block(kal_uint8 *adrs, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;
	kal_uint32 len, pcb;
	kal_uint8 *header;
	
	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
	//usim_dcb_struct *dcb = usim_dcb;

	header = usim_dcb->header_tx;
	usim_dcb->main_state = CMD_TX_STATE;
	USIM_CLR_FIFO();
	// delay 100 clock cycles (30us) [MAUI_03431888]/[MAUI_03433590]
	while(SIM_Reg(SIM0_BASE_ADDR_MTK+SIM_CLR_STA)==1);
	/*
	{
		kal_uint32 t1;
		t1 = SIM_GetCurrentTime();
		while((SIM_GetCurrentTime()-t1) < 1);
	}  
	*/
	// make sure FIFO really cleared
	SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
{
	kal_uint32 loopIndex;

	for(loopIndex = 500; 0 < loopIndex; loopIndex--);
}
	// write header into fifo
	len = header[T1_LEN_INDEX];	
	pcb = header[T1_PCB_INDEX];
#if defined(SIM_DEBUG_INFO)
	dbg_print("usim_send_block [00][%x][%x]\r\n",pcb, len);
#endif
	#if defined(USIM_DEBUG)
	{
		kal_uint32 i;
		dbg_print("tx:");
		if(USIM_IS_SBLOCK(pcb)&& len ==1)
		{
			dbg_print(" %x",header[T1_INF_INDEX]);
		}
		else
		{
			for(i=0;i<len;i++)
			{
				dbg_print(" %x",adrs[i]);
			}
		}
		dbg_print("\r\n");
	}
	#endif
	
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), header[T1_NAD_INDEX]);
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), pcb);
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), len);
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), len);
	// transfer by DMA if the count > 12, otherwise by MCU
	SIM_SetTXTIDE(1, hw_cb);
	if(len > 12)
	{
		usim_dcb->dma_menu.addr = (kal_uint32)adrs;
		usim_dcb->dma_input.type = DMA_HWTX;
		usim_dcb->dma_input.count = (kal_uint16)len;
#if defined (__SIM_DVT__)
		if(KAL_TRUE == useT1Switch){
			T1SwitchEnabled = KAL_TRUE;
			DRV_SetBits(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, 0x2000);
		}
#endif /* End of #if defined (__SIM_DVT__) */
		USIM_TX_START_T1();
#if defined (__SIM_DVT__)
		if(KAL_TRUE == useT1Switch){
			DMA_Config(usim_dcb->dma_port,&usim_dcb->dma_input,KAL_FALSE);
//			DRV_WriteReg32(DMA_DST(DMA_SIM), uncachedDmaBuffer0); //20
//			DRV_WriteReg(DMA_COUNT(DMA_SIM), USIM_DMA_MAX_SIZE); //28
			DMA_Run(usim_dcb->dma_port);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		}
		else{
#endif /* End of #if defined (__SIM_DVT__) */
		DMA_Config(usim_dcb->dma_port,&usim_dcb->dma_input,KAL_TRUE);
	}

#if defined (__SIM_DVT__)
	}
#endif /* End of #if defined (__SIM_DVT__) */
	else if(USIM_IS_SBLOCK(pcb)&& len ==1)
	{
		SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), header[T1_INF_INDEX]);
		USIM_TX_START_T1();
	}
	else
	{
		kal_uint32 i;
		
		for(i=0;i<len;i++)
			SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), adrs[i]);
		USIM_TX_START_T1();
	}
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_STS_T1END);
}
/*
1. send S blocks of request or response.
2. if sending request, check if the response is correct.
3. if sending response,
4. EDC will be generated(tx) and removed(rx) by T1 controller

id: PCB of the S block
param: parameter of the S-block

*/
static usim_status_enum usim_send_s_block(usim_s_block_id_enum id, kal_uint8 param, sim_HW_cb *hw_cb)	
{
	kal_uint8 *tx_buf, *rx_buf, len, t;
	kal_bool is_resp;
	kal_uint32 i;
	//usim_dcb_struct *dcb = usim_dcb;
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	

#if defined(SIM_DEBUG_INFO)
	dbg_print("usim_send_s_block id:%x, param:%d \r\n", id, param);
#endif
	tx_buf = usim_dcb->header_tx;
	rx_buf = usim_dcb->header_rx;
	tx_buf[T1_NAD_INDEX] = USIM_NAD_DEFAULT;
	tx_buf[T1_PCB_INDEX] = id;
	//is_resp = ((id & PCB_S_RESP) != 0);
	is_resp = (((kal_uint32)id & PCB_S_RESP) != 0)?KAL_TRUE: KAL_FALSE;
	usim_dcb->cmd_state = (is_resp)?(S_BlOCK_RESP_TX):(S_BlOCK_REQ_TX);
	if(id==IFS_REQ || id==WTX_REQ || id==IFS_RESP|| id==WTX_RESP )
	{
		len = 4;
		tx_buf[T1_LEN_INDEX] = 1;
	}
	else
	{
		len = 3;
		tx_buf[T1_LEN_INDEX] = 0;
	}
   tx_buf[T1_INF_INDEX] = param;
   usim_dcb->retry = 0;

   while(usim_dcb->retry++ < 3)
   {
		usim_send_block(tx_buf, hw_cb);
		USIM_WAIT_EVENT_MTK(usim_dcb);
		if(usim_dcb->ev_status == USIM_NO_ERROR)
		{
			if(!is_resp)
			{
				for(t=0,i=0;i<len;i++)
					t += rx_buf[i]^tx_buf[i];
				if(t != PCB_S_RESP)
					continue;
			}			
			break;
		}
   }
   if(usim_dcb->retry == 4)
   {
   	usim_deactivation(hw_cb);
   }
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	
	return USIM_NO_ERROR;	
	
}

/*************************************************************************
* FUNCTION
*  usim_rx_block_handler
*
* DESCRIPTION
*	1. process the received block including I, R, and S blocks
*	2. prepare the next sending block header in the usim_dcb->header_tx
*
* PARAMETERS
	adrs: address of the data buffer
	
* RETURNS
	KAL_TRUE: a valid block is received
	KAL_FALSE: an invalid block is received
	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static kal_bool usim_rx_block_handler(kal_uint32 *adrs, sim_HW_cb *hw_cb)
{
	kal_uint8 pcb, len;
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	

	if(usim_dcb->header_rx[T1_NAD_INDEX] != 0)
	{
#if defined(SIM_DEBUG_INFO)
		dbg_print("(invlid block) invalid NAD\r\n");
#endif
		return KAL_FALSE;
	}
	pcb = usim_dcb->header_rx[T1_PCB_INDEX];
	len = usim_dcb->header_rx[T1_LEN_INDEX];
	if(len > usim_dcb->ifsd) // 0 <= len <= IFSC (max 254)
		return KAL_FALSE;
	#if defined(USIM_DEBUG)
	{	
		dbg_print("rx:%x %x %x",usim_dcb->header_rx[0],usim_dcb->header_rx[1],usim_dcb->header_rx[2]);
		if(USIM_IS_SBLOCK( usim_dcb->header_rx[1]))
			dbg_print(" %x \r\n",usim_dcb->rx_buf[3]);
	
	}
	#endif
	// USIM_INV_N(usim_dcb->ns);
	if(USIM_IS_IBLOCK(pcb))
	{	// I-block
#if defined(SIM_DEBUG_INFO)
		dbg_print("received a I-block\r\n");
#endif
		if(pcb & PCB_I_RFU)
		{
#if defined(SIM_DEBUG_INFO)
			dbg_print("(invlid block) error PCB \r\n");
#endif
			return KAL_FALSE;
		}	
		#if defined(USIM_DEBUG)
		{
			kal_uint32 i;
			for(i=0;i<len;i++)
			{
				dbg_print(" %x",usim_dcb->rx_buf[usim_dcb->rx_index+i]);
			}
			dbg_print("\r\n");
		}
		#endif
		if((pcb & PCB_I_SEQ) != usim_dcb->nr)
		{
#if defined(SIM_DEBUG_INFO)
			dbg_print("(invlid block) receive sequence err\r\n");
#endif
			return KAL_FALSE;
		}
		if(usim_dcb->header_rx[T1_LEN_INDEX] > usim_dcb->ifsd)
		{
#if defined(SIM_DEBUG_INFO)
			dbg_print("(invalid block) receive lenght > IFSD \r\n");
#endif
			return KAL_FALSE;
		}		
		if(usim_dcb->header_tx[T1_PCB_INDEX]== RESYNC_REQ)
		{
			// must receive a S RESP not any other block
#if defined(SIM_DEBUG_INFO)
			dbg_print("(invalid block) must receive a S RESP not any other block \r\n");
#endif
			return KAL_FALSE;			
		}
			
		usim_dcb->tx_chain = KAL_FALSE;
		USIM_INV_N(usim_dcb->nr);
		usim_dcb->retry = 0;
		usim_dcb->tx_size -= usim_dcb->header_tx[T1_LEN_INDEX];
		usim_dcb->tx_index += usim_dcb->header_tx[T1_LEN_INDEX]; 		
		usim_dcb->rx_size  -= usim_dcb->header_rx[T1_LEN_INDEX]; 		
		usim_dcb->rx_index += usim_dcb->header_rx[T1_LEN_INDEX];
		if(pcb & PCB_I_M)
		{
			// a chaining I-block received send a R-block
			usim_dcb->rx_chain = KAL_TRUE;
#if defined(SIM_DEBUG_INFO)
			dbg_print("chaining...\r\n");
#endif
			USIM_MAKE_R_BLOCK_Multiple(PCB_R_STATUS_OK);
		}
		else
		{	// command complete
#if defined(SIM_DEBUG_INFO)
			dbg_print("command complete!!\r\n");
#endif
			usim_dcb->rx_chain = KAL_FALSE;
			usim_dcb->retry = 0;
			usim_dcb->main_state = MAIN_CMD_READY_STATE;
		}				
	}
	else if(USIM_IS_RBLOCK(pcb))
	{	// R-block
#if defined(SIM_DEBUG_INFO)
		dbg_print("received a R-block\r\n");
#endif
		if(usim_dcb->header_tx[T1_PCB_INDEX]== RESYNC_REQ)
		{
			// must receive a S RESP not any other block
#if defined(SIM_DEBUG_INFO)
			dbg_print("(invalid block) must receive a S RESP not any other block \r\n");
#endif
			return KAL_FALSE;			
		}
		if(len)
		{
#if defined(SIM_DEBUG_INFO)
			dbg_print("(invalid block) R block of len = %d \r\n", len);
#endif
			return KAL_FALSE;
		}						
		if(usim_dcb->tx_chain && (pcb & PCB_R_STATUS) == 0)
		{	// receive a err free R block
			if(((pcb & PCB_R_SEQ)<<2) == usim_dcb->ns )
			{	// send next chaining block				
				if(usim_dcb->abort == KAL_TRUE)
				{
					usim_dcb->main_state = MAIN_CMD_READY_STATE;
				}
				else if(usim_dcb->tx_size != 0)
				{
					// normal chaining case
					usim_dcb->retry = 0;
					usim_dcb->tx_size -= usim_dcb->ifsc;
					usim_dcb->tx_index += usim_dcb->ifsc; 			
					*adrs =(kal_uint32)(usim_dcb->tx_buf+usim_dcb->tx_index);
					if(usim_dcb->tx_size <= usim_dcb->ifsc)
					{
						pcb = 0;
						len = usim_dcb->tx_size;
						usim_dcb->cmd_state = I_BLOCK_M0_TX;
					}
					else	// txSize > IFSC
					{
						pcb = PCB_I_M;
						len = usim_dcb->ifsc;
						usim_dcb->cmd_state = I_BLOCK_M1_TX;
					}
					if(usim_dcb->ns) 
						pcb |= PCB_I_SEQ;
					usim_dcb->header_tx[T1_PCB_INDEX] = pcb;
					usim_dcb->header_tx[T1_LEN_INDEX] = len;	
					usim_dcb->header_tx_bak[T1_PCB_INDEX] = pcb;
					usim_dcb->header_tx_bak[T1_LEN_INDEX] = len;	
					USIM_INV_N(usim_dcb->ns);
					}
			}
			else
			{	// sending the previous I block again				
				usim_dcb->retry++;
				usim_dcb->cmd_state = usim_dcb->cmd_state_bak;
				usim_dcb->header_tx[T1_PCB_INDEX] = usim_dcb->header_tx_bak[T1_PCB_INDEX];
				usim_dcb->header_tx[T1_LEN_INDEX] = usim_dcb->header_tx_bak[T1_LEN_INDEX];				
			}
		}
		else
		{
			// error handling R-Block received
			if((pcb & PCB_R_SEQ)<<2 != (usim_dcb->ns) )
			{	// previous sending sequence
				usim_dcb->retry++;
				usim_dcb->cmd_state = usim_dcb->cmd_state_bak;
				usim_dcb->header_tx[T1_PCB_INDEX] = usim_dcb->header_tx_bak[T1_PCB_INDEX];
				usim_dcb->header_tx[T1_LEN_INDEX] = usim_dcb->header_tx_bak[T1_LEN_INDEX];
			}
			else
			{				
				// next sending sequence
				// send the previous R-block again
				usim_dcb->retry = 0;
				return KAL_FALSE;
			}			
		}		
	}
	else if(USIM_IS_SBLOCK(pcb))
	{	// S-block(REQ)
#if defined(SIM_DEBUG_INFO)
		dbg_print("receive S-block(%x)\r\n",pcb);
#endif
		if(USIM_IS_RESP(pcb))
		{	// response (only resync response block will be received.)
#if defined(SIM_DEBUG_INFO)
			dbg_print("receive RESP block!\r\n");
#endif
			if(pcb == RESYNC_RESP && usim_dcb->header_tx[T1_PCB_INDEX]== RESYNC_REQ )
			{
				if(len != 0)
				{
#if defined(SIM_DEBUG_INFO)
					dbg_print("Invalid len of RESYNC");
#endif
					return KAL_FALSE;
				}
				// resync complete (the card is reset to the initial state)
				usim_dcb->main_state = MAIN_CMD_READY_STATE;
				usim_dcb->ns = 0;
				usim_dcb->nr = 0;
				usim_dcb->resync = KAL_TRUE;
				usim_dcb->retry = 0;
				// usim_dcb->ifsc = USIM_IFSC_DEFAULT;
			}
			else
			{
#if defined(SIM_DEBUG_INFO)
				dbg_print("receive a error S RESP,[%x]\r\n", pcb);
#endif
				return KAL_FALSE;			
			}
		}
		else
		{ // receiving a S-block of request
			if(usim_dcb->header_tx[T1_PCB_INDEX]== RESYNC_REQ)
			{
				// must receive a S RESP not any other block
#if defined(SIM_DEBUG_INFO)
				dbg_print("(invalid block) must receive a S RESP not any other block \r\n");
#endif
				return KAL_FALSE;			
			}
		
			usim_dcb->cmd_state = S_BlOCK_RESP_TX;
			usim_dcb->header_tx[T1_PCB_INDEX]= pcb|PCB_S_RESP;
			usim_dcb->header_tx[T1_LEN_INDEX]= len;		
			if(len)
			{
				usim_dcb->header_tx[T1_INF_INDEX] = usim_dcb->header_rx[T1_INF_INDEX];
			}
			switch(pcb)
			{
				case RESYNC_REQ:
#if defined(SIM_DEBUG_INFO)
					dbg_print("(ERR) receive RESYNC_REQ\r\n");
#endif
					return KAL_FALSE;
					//break; //remove for for RVCT warning
				case IFS_REQ:	
#if defined(SIM_DEBUG_INFO)
					dbg_print("receive IFS_REQ\r\n");					
#endif
					if(len != 1)
						return KAL_FALSE;
					usim_dcb->ifsc = usim_dcb->header_rx[T1_INF_INDEX];
					break;
				case ABORT_REQ:
#if defined(SIM_DEBUG_INFO)
					dbg_print("receive ABORT_REQ\r\n");
#endif
					if(len != 0)
						return KAL_FALSE;	
					usim_dcb->retry = 0;
					usim_dcb->abort = KAL_TRUE;
					/*in the FTA test 7.3.11, after the abbort request, card will resend data, so we should reset rx_index to zero*/
					usim_dcb->rx_index = 0;
					break;
				case WTX_REQ:
					if(len != 1)
						return KAL_FALSE;
					usim_dcb->retry = 0;
#if defined(SIM_DEBUG_INFO)
					dbg_print("receive WTX_REQ\r\n");
#endif
					// re-start the BWT( according to the spec, the timer should be restart after 
					// the WTX response has been sent.
					usim_dcb->wtx = KAL_TRUE;
					usim_dcb->wtx_m = usim_dcb->header_rx[T1_INF_INDEX];;
					break;
				default:
					return KAL_FALSE;
			}
		}
	}
	else
	{
#if defined(SIM_DEBUG_INFO)
		dbg_print("Invalid PCB \r\n");
#endif
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}
/*************************************************************************
* FUNCTION
*  usim_err_handler
*
* DESCRIPTION
*	1. send R block to UICC to indicate the previous block is error at previous two retry. 
*	2. send S(RESYN) to UICC to recover the errors.
*	3. deactivate the UICC 
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*	usim_dcb->retry
*
*************************************************************************/
static void usim_err_handler(sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
	// send R block
	usim_dcb->retry++;
#if defined(SIM_DEBUG_INFO)
	dbg_print("usim_err_handler %d",usim_dcb->retry);	
#endif
	USIM_CLR_FIFO();
	if(usim_dcb->retry < 3)
	{
#if defined(SIM_DEBUG_INFO)
		dbg_print("send R block!\r\n");
#endif
		{
			if(usim_dcb->ev_status == USIM_RX_INVALID)
			{
				USIM_MAKE_R_BLOCK_Multiple(PCB_R_STATUS_EDC_ERR);	
			}
			else
			{
				USIM_MAKE_R_BLOCK_Multiple(PCB_R_STATUS_OTHER_ERR);	
			}	
		}
	}
	else if(usim_dcb->retry <  6)
	{
		// next level error handling => resync		
#if defined(SIM_DEBUG_INFO)
		dbg_print("send RESYNC REQ !\r\n");
#endif
		USIM_MAKE_S_RESYNC_Multiple();		
	}
	else
	{
		// deactivate
		usim_deactivation(hw_cb);
	}
}

/*these 2 functions will be used by other files, so we should have different names */
void sim_PDNDisable_MTK(sim_HW_cb *hw_cb)
{
#if (2 == SIM_DRV_MTK_INTERFACE_NUM) && !defined(__MEUT__) && defined(__OLD_PDN_ARCH__)
	if(DRVPDN_CON0 != hw_cb->mtk_pdnAddr && DRVPDN_CON1 != hw_cb->mtk_pdnAddr)
		ASSERT(0);
	if(DRVPDN_CON0_SIM2 != hw_cb->mtk_pdnBit && DRVPDN_CON1_SIM != hw_cb->mtk_pdnBit)
		ASSERT(0);
	if(PDN_SIM2 != hw_cb->mtk_pdnDevice && PDN_SIM != hw_cb->mtk_pdnDevice)
		ASSERT(0);
#endif		
#ifdef __OLD_PDN_ARCH__
	DRVPDN_Disable(hw_cb->mtk_pdnAddr, hw_cb->mtk_pdnBit, hw_cb->mtk_pdnDevice);
	sim_addMsg(SIM_PDNDIS, hw_cb->simInterface, SIM_Reg(DRVPDN_CON0), SIM_Reg(DRVPDN_CON1));
#else
#if defined (LPWR_SLIM)
	if (hw_cb->mtk_pdnDevice == PDN_DEV_SIM)
		PDN_CLR(PDN_SIM); //power down dev
	else	
	   PDN_CLR(PDN_SIM2); //power down dev
	L1SM_SleepDisable(hw_cb->smHandler); //lock sleep mode		
#else
	DRVPDN_Disable((PDN_DEVICE)hw_cb->mtk_pdnDevice);
	/*use another API to fulfill my debug usage*/
#endif
#endif

}

void sim_PDNEnable_MTK(sim_HW_cb *hw_cb)
{
	
#if (2 == SIM_DRV_MTK_INTERFACE_NUM) && !defined(__MEUT__) && defined(__OLD_PDN_ARCH__)
	if(DRVPDN_CON0 != hw_cb->mtk_pdnAddr && DRVPDN_CON1 != hw_cb->mtk_pdnAddr)
		ASSERT(0);
	if(DRVPDN_CON0_SIM2 != hw_cb->mtk_pdnBit && DRVPDN_CON1_SIM != hw_cb->mtk_pdnBit)
		ASSERT(0);
	if(PDN_SIM2 != hw_cb->mtk_pdnDevice && PDN_SIM != hw_cb->mtk_pdnDevice)
		ASSERT(0);
#endif
#ifdef __OLD_PDN_ARCH__
	/*we use new manner to set pdn bit*/
	DRVPDN_Enable(hw_cb->mtk_pdnAddr, hw_cb->mtk_pdnBit, hw_cb->mtk_pdnDevice);
	
	sim_addMsg(SIM_PDNEN, hw_cb->simInterface, SIM_Reg(DRVPDN_CON0), SIM_Reg(DRVPDN_CON1));
#else
	//sim_addMsg(SIM_PDNEN, hw_cb->simInterface, SIM_Reg(DRVPDN_CON0), SIM_Reg(DRVPDN_CON1));
#if defined (LPWR_SLIM)
	if (hw_cb->mtk_pdnDevice == PDN_DEV_SIM)
		PDN_SET(PDN_SIM); //power down dev
	else	
	   PDN_SET(PDN_SIM2); //power down dev
	L1SM_SleepEnable(hw_cb->smHandler);  //unlock sleep mode	
#else
	DRVPDN_Enable((PDN_DEVICE)hw_cb->mtk_pdnDevice);
	/*use another API to fulfill my debug usage*/
#endif
#endif

}

/*************************************************************************
* FUNCTION
*  usim_send_i_block
*
* DESCRIPTION
*	1. send I block to UICC with length of ifsc including case 1~4.
*
* PARAMETERS
*	1. txData: tx buffer containing command header optional with tx data.
*	2. txSize: length of the tx data
*	3. rxData: rx buffer (must inluding two extra one for sw1 and sw2)
*	4. rxSize: length of the rx data except sw1|sw2
*	
* RETURNS
*	status bytes(SW1|SW2), 0 means a physical error.
*	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static sim_status usim_send_i_block(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, sim_HW_cb *hw_cb)
{	
	kal_uint8 pcb, len;
	kal_uint32 count,adrs;
	usim_status_enum status;
	kal_uint16 sw;
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	

#if defined(SIM_DEBUG_INFO)
	dbg_print("\r\n\r\n @@@@ usim_send_i_block @@@@\r\n");
#endif
	sim_PDNDisable_MTK(hw_cb);
	if(usim_dcb->clock_stop_en == KAL_TRUE)
	{
		if(usim_dcb->main_state == CLK_STOPPING_STATE)
		{
			usim_set_timeout(0, hw_cb);
			usim_dcb->main_state = MAIN_CMD_READY_STATE;
		}
		else if(usim_dcb->main_state == CLK_STOPPED_STATE)
		{
			SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);
			usim_set_timeout(usim_dcb->etu_of_700, hw_cb);
			SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, SIM_IRQEN_TOUT);
			USIM_WAIT_EVENT_MTK(usim_dcb);			
		}
	}
	
	
	do
	{
		status = USIM_NO_ERROR;
		usim_dcb->tx_index = 0;
		usim_dcb->rx_index = 0;
		usim_dcb->tx_buf = txData;
		if(rxData == NULL)
			usim_dcb->rx_buf = usim_dcb->sw;	
		else
			usim_dcb->rx_buf = rxData;
		usim_dcb->tx_size = *txSize;			
		usim_dcb->rx_size = *rxSize+2; // include SW1, SW2 
		usim_dcb->retry = 0;
		usim_dcb->abort = KAL_FALSE;
		usim_dcb->resync = KAL_FALSE;
		usim_dcb->rx_chain = KAL_FALSE;
		
		count = *txSize;
		adrs =(kal_uint32)usim_dcb->tx_buf;
		if(count <= usim_dcb->ifsc)
		{
			pcb = 0;
			len = count;
			usim_dcb->tx_chain = KAL_FALSE;
			usim_dcb->cmd_state = I_BLOCK_M0_TX;
		}
		else	// txSize > IFSC
		{
			pcb = PCB_I_M;
			len = usim_dcb->ifsc;
			usim_dcb->tx_chain = KAL_TRUE;
			usim_dcb->cmd_state = I_BLOCK_M1_TX;
		}
		if(usim_dcb->ns) 
			pcb |= PCB_I_SEQ;
		
		usim_dcb->cmd_state_bak = usim_dcb->cmd_state;	
		usim_dcb->header_tx[T1_NAD_INDEX] = USIM_NAD_DEFAULT;
		usim_dcb->header_tx[T1_PCB_INDEX] = pcb;
		usim_dcb->header_tx_bak[T1_PCB_INDEX] = pcb;
		usim_dcb->header_tx[T1_LEN_INDEX] = len;		
		usim_dcb->header_tx_bak[T1_LEN_INDEX] = len;
		USIM_INV_N(usim_dcb->ns);
		
		while(1)
		{
			usim_send_block((kal_uint8*)adrs, hw_cb);
			USIM_WAIT_EVENT_MTK(usim_dcb);			
			if(usim_dcb->ev_status == USIM_NO_ERROR)
			{	// a complete block is received
				if(usim_rx_block_handler(&adrs, hw_cb)== KAL_FALSE)
					usim_err_handler(hw_cb);
			}
			else 
			{
				usim_err_handler(hw_cb);
			}
			if(usim_dcb->main_state == MAIN_CMD_READY_STATE)
			{
				// command complete
				*rxSize = usim_dcb->rx_index;
				break;
			}
			if(DEACTIVATION_STATE == usim_dcb->main_state)
			{
				status =  USIM_DEACTIVATED;
				break;
			}

		}
		
/*    [ALPS00411009][MT6589][in-house FTA][UICC] 7.3.11(UICC) 
      receive s-abort request and reply s-abort resp is defined by spec. it is not error
		if(usim_dcb->abort == KAL_TRUE)
		{
			status = USIM_DATA_ABORT;
			break;
		}
*/		
		if(usim_dcb->main_state == DEACTIVATION_STATE)
		{
			status =  USIM_DEACTIVATED;
			break;
		}
	}while(usim_dcb->resync == KAL_TRUE);

	if(usim_dcb->clock_stop_en == KAL_TRUE && DEACTIVATION_STATE != usim_dcb->main_state)
	{
		usim_dcb->main_state = CLK_STOPPING_STATE;
		usim_set_timeout(usim_dcb->etu_of_1860, hw_cb);
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, SIM_IRQEN_TOUT);
		#if defined(USIM_DEBUG)
		start = get_current_time();
		#endif
	}
	usim_dcb->status = status;
	if(status != USIM_NO_ERROR)
		return SIM_SW_STATUS_FAIL;
	// the *rxsize include the sw1 and sw1, the upper layer should prepare it.
	*rxSize -= 2;
	if(rxData == NULL)
	{
	   sw =(kal_uint16)((usim_dcb->sw[0]<<8)|(usim_dcb->sw[1]));
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC34, sw, *txSize, *rxSize,usim_dcb->sw[0],usim_dcb->sw[1]);

		return sw;
	}
	sw = (rxData[*rxSize]<<8)|(rxData[*rxSize+1]);
//#if defined(SIM_DEBUG_INFO)
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC30, sw, *txSize, *rxSize,0,0);
//#endif
	return sw;

}

/*************************************************************************
* FUNCTION
*  usim_InterfaceCheck
*
* DESCRIPTION
*	do platform sim interface support check, mainly on checking whether this platform support second sim interface
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
void static usim_InterfaceCheck(sim_HW_cb *hw_cb)
{
	if(hw_cb->simInterface > 2)
		ASSERT(0);
}

/*************************************************************************
* FUNCTION
*  usim_update_sim_to_ready
*
* DESCRIPTION
*	1. update the ATR informations from usim_dcb into SimCard
*		to make sim(t=0) driver work..
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*	SimCard
*	TOUTValue
*
*************************************************************************/
void static usim_update_sim_to_ready(sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;
	Sim_Card *SimCard;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	SimCard = GET_SIM_CB(hw_cb->simInterface);
	
	SimCard->app_proto = usim_dcb->app_proto;
	SimCard->State = SIM_PROCESSCMD;
	SimCard->Data_format = usim_dcb->dir;
	if(usim_dcb->power == CLASS_B_30V)
		SimCard->Power = SIM_30V;
	else if(usim_dcb->power == CLASS_C_18V)
		SimCard->Power = SIM_18V;
	SimCard->SIM_ENV = usim_dcb->sim_env;
	SimCard->Speed = usim_dcb->speed;
	SimCard->clkStop = usim_dcb->clock_stop_en;
	if(usim_dcb->clock_stop_type == CLOCK_STOP_HIGH)
		SimCard->clkStopLevel = KAL_TRUE;
	else if(usim_dcb->clock_stop_type == CLOCK_STOP_LOW)
		SimCard->clkStopLevel = KAL_FALSE;
	SimCard->sim_card_speed = (sim_card_speed_type)usim_dcb->card_speed;
	SimCard->TOUTValue = usim_dcb->WWT>>2;
	SimCard->power_class = usim_dcb->power_class;
}
/*************************************************************************
* FUNCTION
*  L1usim_Init
*
* DESCRIPTION
*	1. It is the initialization function of usim driver
*	2. It shall be called only once.
*	3. It gets the customization data of borad-supported voltage.
*	4. It initialize the structure of usim control block .
*	5. It get a GPT handler, a dma port,and register lisr, hisr, a event groug 
*
* PARAMETERS
	None
	
* RETURNS
	None
	
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static void L1usim_Init(sim_HW_cb *hw_cb)	
{	
	usim_dcb_struct *usim_dcb;
	kal_uint32 hwCtrl;



	usim_dcb = GET_USIM_CB(hw_cb->simInterface);

	sim_addMsg(SIM_INIT_USIM, hw_cb->simInterface, 0, 0);
	
	
	if(usim_dcb->warm_rst == KAL_FALSE)
	{
		usim_dcb->sim_env = SIM_GetCurrentEnv(hw_cb->simInterface);
		usim_dcb->dir = USIM_DIRECT;
		usim_dcb->speed = SPEED_372;
		usim_dcb->clock_stop_en = KAL_FALSE;
		usim_dcb->clock_stop_type = CLOCK_STOP_UNKONW;
		usim_dcb->phy_proto = T1_PROTOCOL;
		usim_dcb->warm_rst = KAL_FALSE;
		usim_dcb->rx_size = 0;
		usim_dcb->rx_buf = NULL;
		usim_dcb->tx_size = 0;
		usim_dcb->tx_buf = NULL;
		usim_dcb->Fi = FI_DEFAULT;	
		usim_dcb->Di = DI_DEFAULT;
		usim_dcb->header_tx[0] = NAD;
		usim_dcb->ts_hsk_en = KAL_TRUE;
		usim_dcb->WWT = INIT_WWT_T0;
		usim_dcb->etu_of_1860 = (1860/32);
		usim_dcb->etu_of_700 = (700/32);
		usim_dcb->present = KAL_TRUE;
		usim_dcb->power_class = UNKNOWN_POWER_CLASS;

		/*there will be no enable enhanced_speed function, we should set this myself*/
		usim_dcb->high_speed_en = KAL_TRUE;
					
		// note: MT6218B half channel can't work, use full channel insteadly.
		#if !defined(MT6218B) && !defined(MT6218)

		if(usim_dcb->dma_port == 0)
			usim_dcb->dma_port = DMA_GetChannel((DMA_Master)hw_cb->mtk_dmaMaster);

		
		usim_dcb->dma_menu.TMOD.burst_mode = KAL_FALSE;
		usim_dcb->dma_menu.master = (DMA_Master)hw_cb->mtk_dmaMaster;
		usim_dcb->dma_menu.addr = (kal_uint32)NULL;
		usim_dcb->dma_input.type = DMA_HWTX;
		usim_dcb->dma_input.size = DMA_BYTE;
		usim_dcb->dma_input.callback = NULL;
		usim_dcb->dma_input.menu = &usim_dcb->dma_menu;
		#endif
		if(usim_dcb->event == NULL){
		  hwCtrl = sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface);
		  if(MTK_SIMIF0 == hwCtrl){
				usim_dcb->event = kal_create_event_group("USIM_EV");
		  }
		  else if(MTK_SIMIF1 == hwCtrl){		  
				usim_dcb->event = kal_create_event_group("USIM_EV2");
		  }
			else
				ASSERT(0);
		}
		
		if(SIM_base == hw_cb->mtk_baseAddr){
			if((kal_uint32)hw_cb != hwCbArray[hw_cb->simInterface])
				ASSERT(0);
			if(IRQ_SIM_CODE != hw_cb->mtk_lisrCode)
				ASSERT(0);			
			DRV_Register_HISR(DRV_USIM_HSIR_ID, usim_hisr);
			if(usim_dcb->gpt_handle == (kal_uint32)NULL)
				DRV_ICC_GPTI_GetHandle(&usim_dcb->gpt_handle);
			IRQSensitivity(hw_cb->mtk_lisrCode, LEVEL_SENSITIVE);
		}
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
		else if(SIM2_base == hw_cb->mtk_baseAddr){
			if((kal_uint32)hw_cb != hwCbArray[hw_cb->simInterface])
				ASSERT(0);
			if(IRQ_SIM2_CODE != hw_cb->mtk_lisrCode)
				ASSERT(0);			
			DRV_Register_HISR(DRV_USIM2_HSIR_ID, usim_hisr2);
			if(usim_dcb->gpt_handle == (kal_uint32)NULL)
				DRV_ICC_GPTI_GetHandle(&usim_dcb->gpt_handle);
			IRQSensitivity(hw_cb->mtk_lisrCode, LEVEL_SENSITIVE);
		}
#endif
		else
			ASSERT(0);
		
	}
	
	// reset these value no matter cold or warm reset
	usim_dcb->main_state = ACTIVATION_STATE;
	usim_dcb->ifsc = USIM_IFSC_DEFAULT;
	usim_dcb->ifsd = USIM_IFSD_DEFAULT;
	usim_dcb->ns = 0;
	usim_dcb->nr = 0;

	if(SIM_base == hw_cb->mtk_baseAddr){	
		IRQ_Register_LISR(hw_cb->mtk_lisrCode, usim_lisr_Multiple,"USIM_Lisr");
		if(usim_dcb->warm_rst == KAL_FALSE)
			IRQUnmask(hw_cb->mtk_lisrCode);
	}
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
	else if(SIM2_base == hw_cb->mtk_baseAddr){
		IRQ_Register_LISR(hw_cb->mtk_lisrCode, usim_lisr2_Multiple,"USIM2_Lisr");
		if(usim_dcb->warm_rst == KAL_FALSE)
			IRQUnmask(hw_cb->mtk_lisrCode);
	}
#endif
	else
		ASSERT(0);
	
}

/*************************************************************************
* FUNCTION
*  L1sim_Reset
*
* DESCRIPTION
* 1. Reset the sim card and parse the ATR and perform the PTS(optional) and 
		enter the command ready mode
* 2. First time it is a cold reset, second it's a warm reset
* 3. If the ExpectVolt equal to the current volt, perform a warm reset. 
		Otherwise perform a cold reset.
* 4. Finally, S-block of IFS request is sent the UICC to configure the IFSD  
*
* PARAMETERS
	1. ExpectVolt: application layer give a expected power class

* RETURNS
*  USIM_VOLT_NOT_SUPPORT: Valid TS is received
*  KAL_FALSE: Valid TS is not received, card is not present or not supported
*
* GLOBALS AFFECTED
*	usim_dcb
*
*************************************************************************/
static usim_status_enum L1usim_Reset(usim_power_enum ExpectVolt, usim_power_enum *ResultVolt, sim_HW_cb *hw_cb)
{
	kal_uint32 retry;
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
#if defined(SIM_DEBUG_INFO)
	dbg_print("L1usim_Reset\r\n");
#endif
	sim_PDNDisable_MTK(hw_cb);

//#ifdef NO_SLIM_DEF
	if(usim_dcb->clock_stop_en == KAL_TRUE && usim_dcb->warm_rst == KAL_TRUE &&
		usim_dcb->phy_proto == T1_PROTOCOL)
	{
		if(usim_dcb->main_state == CLK_STOPPING_STATE)
		{
			usim_set_timeout(0, hw_cb);
			usim_dcb->main_state = MAIN_CMD_READY_STATE;
		}
		else if(usim_dcb->main_state == CLK_STOPPED_STATE)
		{
			SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);
			usim_set_timeout(usim_dcb->etu_of_700, hw_cb);
			SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, SIM_IRQEN_TOUT);
			USIM_WAIT_EVENT_MTK(usim_dcb);
		}
	}	
//#endif	
	L1usim_Init(hw_cb);
	if(usim_check_input_volt(ExpectVolt, hw_cb) == KAL_FALSE)
		return USIM_VOLT_NOT_SUPPORT; 	
	// 1. Activate the USIM interface
	SIM_DisAllIntr();	
	DMA_Stop(usim_dcb->dma_port);
	usim_set_speed(SPEED_372, hw_cb);
	usim_set_timeout(INIT_WWT_T0, hw_cb);
	/*
	if(TS_HSK_ENABLE)
	{
		SIM_SetRXRetry(hw_cb, 7);
		SIM_SetTXRetry(hw_cb, 7);
		USIM_ENABLE_TXRX_HANSHAKE();		
	}
	*/
	// if corrupted ATRs are received, retry 3 times
	for(retry = 0; retry < ATR_RETRY; retry++)
	{
		kal_set_eg_events(usim_dcb->event,0,KAL_AND);
		if(usim_select_power(ExpectVolt, hw_cb) == KAL_FALSE)
		{
//#ifdef NO_SLIM_DEF
			if(usim_dcb->warm_rst == KAL_TRUE)
				return USIM_ATR_ERR;
//#endif
			if( usim_dcb->ts_hsk_en == KAL_TRUE)
				usim_dcb->ts_hsk_en = KAL_FALSE;
			else
				return USIM_NO_INSERT;
			//continue;
		}
		else if (usim_process_ATR(hw_cb) == USIM_NO_ERROR) 			
				break;
				
		ExpectVolt = usim_dcb->power;		
	}
	if(retry == 3)
		return USIM_ATR_ERR;
	*ResultVolt = usim_dcb->power;
	// 3. Process PTS
	//if(usim_dcb->reset_mode == USIM_RESET_NEGOTIABLE)
	{
		usim_process_PTS(hw_cb);
		// 4. Configure the IFSD	
		if(usim_dcb->phy_proto == T1_PROTOCOL)
		{
			if( usim_send_s_block(IFS_REQ, USIM_IFSD_MAX, hw_cb) == USIM_NO_ERROR){
				/*if we failed to send S block when negotiating IFSD and deactivate the card, we should report the reset status correctly*/
				if(DEACTIVATION_STATE == usim_dcb->main_state)
					return USIM_S_BLOCK_FAIL;
					
				usim_dcb->ifsd = USIM_IFSD_MAX;
			}
		}
	}
	// NOTE: can't turn off the PDN bit of SIM interface over, it will cause
	// the SIM behavior abnormal. 
	usim_dcb->main_state = MAIN_CMD_READY_STATE;
	usim_dcb->cmd_state = USIM_CMD_READY;
	kal_set_eg_events(usim_dcb->event,0,KAL_AND);
	return USIM_NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  L1usim_PowerOff
*
* DESCRIPTION
*	1. perform the deactivation to UICC
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
static void L1usim_PowerOff(sim_HW_cb *hw_cb)
{
	
	//DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
	sim_PDNDisable_MTK(hw_cb);
	usim_deactivation(hw_cb);
	//DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);	
	sim_PDNEnable_MTK(hw_cb);
}
/*************************************************************************
* FUNCTION
*  L1usim_Get_Card_Info
*
* DESCRIPTION
*	get the card informations
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
static void L1usim_Get_Card_Info(sim_info_struct *info, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
	ASSERT(usim_dcb->main_state >= ATR_STATE);
	info->power = usim_dcb->power;	
	info->speed = usim_dcb->speed;	
	info->clock_stop = usim_dcb->clock_stop_type;
	info->app_proto = usim_dcb->app_proto;
	info->phy_proto = usim_dcb->phy_proto;
	info->T0_support = usim_dcb->T0_support;
	info->T1_support = usim_dcb->T1_support;
	info->hist_index = usim_dcb->hist_index;
	info->ATR = usim_dcb->ATR_data;
	info->TAiExist = usim_dcb->TAiExist;
	info->ATR_length = usim_dcb->ATR_index;
    info->isSW6263 = usim_dcb->isSW6263;
}
#ifdef NO_SLIM_DEF
/*************************************************************************
* FUNCTION
*  L1usim_Enable_Enhanced_Speed
*
* DESCRIPTION
*	1. enable the enhance speed mode if UICC supports
*	2. shall be called before reset after init
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
static void L1usim_Enable_Enhanced_Speed(kal_bool enable, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	//ASSERT(usim_dcb->main_state == IDLE_STATE);
	usim_dcb->high_speed_en = enable;
}
#endif
/*************************************************************************
* FUNCTION
*  L1usim_Set_ClockStopMode
*
* DESCRIPTION
*	setup the clock stop mode according to the ATR information.
*
* PARAMETERS
*	mode:	clock stop mode
*
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
static void L1usim_Set_ClockStopMode(usim_clock_stop_enum mode, sim_HW_cb *hw_cb)
{	
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	if(mode & CLOCK_STOP_MSK)
	{		
		// calculate the clock to etu for 1860 and 700
		usim_dcb->etu_of_1860 = (1860/(usim_dcb->Fi/usim_dcb->Di))+10; // longer than spec.
		usim_dcb->etu_of_700 = (700/(usim_dcb->Fi/usim_dcb->Di))+5;
		usim_dcb->clock_stop_en = KAL_TRUE;
		if(mode == CLOCK_STOP_ANY)
			usim_dcb->clock_stop_type = CLOCK_STOP_LOW;
		else
			usim_dcb->clock_stop_type = mode;
	}
	else
	{
		usim_dcb->clock_stop_en = KAL_FALSE;
	}
}
/*************************************************************************
* FUNCTION
*  L1usim_Cmd
*
* DESCRIPTION
*	usim T=1 command
*
* PARAMETERS
*	1. txData: tx buffer containing command header optional with tx data.
*	2. txSize: length of the tx data
*	3. rxData: rx buffer (must inluding two extra one for sw1 and sw2)
*	4. rxSize: length of the rx data except sw1|sw2
*	
* RETURNS
*	status bytes(SW1|SW2), 0 means a physical error.

* GLOBALS AFFECTED
*
*************************************************************************/
static sim_status L1usim_Cmd(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;
#ifdef SIM_CACHED_SUPPORT
	sim_status	SW;
	kal_uint8	*pNoncachedTx, *pNoncachedRx;
#endif

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	

	/*
	if(usim_dcb->main_state != MAIN_CMD_READY_STATE && usim_dcb->main_state != CLK_STOPPED_STATE)
	{
		kal_prompt_trace(MOD_SIM,"[SIM_DRV]:L1usim_Cmd is called at err state");
		return SIM_SW_STATUS_FAIL;
	}
	*/
	if(rxData == NULL && *rxSize != 0)
		ASSERT(0);
	if(usim_dcb->cmd_case == usim_case_1)
	{ // for case1, only 4 bytes need to be transfer
		*txSize = 4;
		*rxSize = 0;
	}	
#ifdef SIM_CACHED_SUPPORT
	if (INT_QueryIsCachedRAM(txData, *txSize) || INT_QueryIsCachedRAM(rxData, 512)){
		GET_NCACHEDTX_P(pNoncachedTx, sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface));
		GET_NCACHEDRX_P(pNoncachedRx, sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface));
		kal_mem_cpy(pNoncachedTx, txData, *txSize);
		if(INT_QueryIsCachedRAM(rxData, 512)){
			SW = usim_send_i_block((kal_uint8 *)pNoncachedTx, txSize, (kal_uint8 *)pNoncachedRx, rxSize, hw_cb);
			if(0 != *rxSize){
				if(512 < *rxSize)
					ASSERT(0);
				if(0 == rxData)
					ASSERT(0);
				kal_mem_cpy(rxData, pNoncachedRx, *rxSize);
			}
		}
		else{
			SW = usim_send_i_block((kal_uint8 *)pNoncachedTx, txSize, rxData, rxSize, hw_cb);
		}

		return SW;
	}
#endif

#ifdef SIM_CACHED_SUPPORT_WRITE_THROUGH_SERIES
	invalidate_wt_cache((kal_uint32)rxData, *rxSize);
#endif

	return usim_send_i_block(txData, txSize, rxData, rxSize, hw_cb);
}
/*************************************************************************
* FUNCTION
*  usim_TimeOutHandler
*
* DESCRIPTION
*	Callback function of gpt timer, and launched while MSDC busy for a while

*
* PARAMETERS
*	
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
static void usim_gpt_timeout_handler(void *parameter)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = (usim_dcb_struct *)parameter;
	
/*
	kal_prompt_trace(MOD_SIM,"[SIM_DRV]: usim gpt timeout !");
*/
	usim_dcb->status  = USIM_GPT_TIMEOUT;
	USIM_SET_EVENT_Multiple(usim_dcb);
}

#if defined (__SIM_DVT__)
kal_uint32 sim_toutTestTim1, sim_toutTestTim2;
kal_bool sim_ToutTest, sim_ToutTest2;

void sim_toutTestGptCallback(void *parameter)
{
	sim_HW_cb *hw_cb;
	kal_uint32 toutValue;
	usim_dcb_struct *usim_dcb;
	kal_uint16 stsValue;

	hw_cb = (sim_HW_cb *)parameter;
	usim_dcb = GET_USIM_CB(hw_cb->simInterface);

if (gTout == 1)
{
	stsValue = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
	if(0x8 != stsValue){/*tout not expired, start new gpt*/
//		kal_sprintf(sim_dbg_str,"CB: tout test with value : %d", stsValue);
//		kal_print(sim_dbg_str);

		toutValue = DRV_Reg32(SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK);
		//drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL1, __LINE__, hw_cb->simInterface, toutValue , DRV_Reg32(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), 0, 0, drv_get_current_time());
		//kal_prompt_trace(MOD_SIM,"sim tout test : not expired, %d, %x, %x, %x, %x, %x, %x", hw_cb->simInterface, toutValue, stsValue, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), (kal_uint32)hw_cb);
		DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle, 2, sim_toutTestGptCallback, (void *)hw_cb);
	}
	else{ /*timeout happen, print message and create set new tout setting*/
		toutValue = DRV_Reg32(SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK);
		//drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL1, __LINE__, hw_cb->simInterface, toutValue , DRV_Reg32(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), 0, drv_get_duration_ms(sim_toutTestTim1), drv_get_current_time());
		kal_prompt_trace(MOD_SIM,"sim tout test : expired, %d, %x, %d", hw_cb->simInterface, toutValue, drv_get_duration_ms(sim_toutTestTim1));

		SIM_ClearBits(SIM0_BASE_ADDR_MTK+SIM_CONF_MTK, 0x80);
		toutValue *= 2;
		if(toutValue == 0)
		   while(1);
		DRV_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), toutValue);
		kal_sprintf(sim_dbg_str,"CB2: tout test with value : %d 0x%x", stsValue, toutValue);
#if	!defined( __MAUI_BASIC__)
		tst_sys_trace(sim_dbg_str);
#else
		dbg_print(sim_dbg_str);
#endif

		sim_toutTestTim1 = drv_get_current_time();
		DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle, 2, sim_toutTestGptCallback, (void *)hw_cb);
		DRV_SetBits(SIM0_BASE_ADDR_MTK+SIM_CONF_MTK, 0x80);

	}
}
else
{

		stsValue = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
		if((0x1000 & stsValue) != 0x1000){/*tout not expired, start new gpt*/
	// 	kal_sprintf(sim_dbg_str,"CB: tout test with value : %d", stsValue);
	// 	kal_print(sim_dbg_str);
	
			toutValue = DRV_Reg32(SIM0_BASE_ADDR_MTK + SIM_TOUT2_MTK);
			//drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL1, __LINE__, hw_cb->simInterface, toutValue , DRV_Reg32(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), 0, 0, drv_get_current_time());
			//kal_prompt_trace(MOD_SIM,"sim tout test : not expired, %d, %x, %x, %x, %x, %x, %x", hw_cb->simInterface, toutValue, stsValue, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), (kal_uint32)hw_cb);
			DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle, 2, sim_toutTestGptCallback, (void *)hw_cb);
		}
		else{ /*timeout happen, print message and create set new tout setting*/
			toutValue = DRV_Reg32(SIM0_BASE_ADDR_MTK + SIM_TOUT2_MTK);
			//drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL1, __LINE__, hw_cb->simInterface, toutValue , DRV_Reg32(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), 0, drv_get_duration_ms(sim_toutTestTim1), drv_get_current_time());
			kal_prompt_trace(MOD_SIM,"sim tout2 test : expired, %d, %x, %d", hw_cb->simInterface, toutValue, drv_get_duration_ms(sim_toutTestTim1));
	
			SIM_ClearBits(SIM0_BASE_ADDR_MTK+SIM_CONF_MTK, 0x4000);
			toutValue *= 2;
			if(toutValue == 0x400000)
			   toutValue = 0x3FFFFF;
			if(toutValue == 0)
				while(1);
			DRV_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT2_MTK), toutValue);
			kal_sprintf(sim_dbg_str,"CB2: tout2 test with value : %d 0x%x", stsValue, toutValue);
#if	!defined( __MAUI_BASIC__)
			tst_sys_trace(sim_dbg_str);
#else
			dbg_print(sim_dbg_str);
#endif

			sim_toutTestTim1 = drv_get_current_time();
			DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle, 2, sim_toutTestGptCallback, (void *)hw_cb);
			DRV_SetBits(SIM0_BASE_ADDR_MTK+SIM_CONF_MTK, 0x4000);
	
		}

	}

}

//#define WTIME_TEST
//#define WTIME2_TEST
//#define EGTIME_TEST
//#define BAUD_8N4_TEST
//#define SIM_REG_TEST
//#define ATIME_TEST
//#define DTIME_TEST
//#define APB_REG_TEST

void sim_toutTest_viaGPT(kal_uint32 toutValue, sim_HW_cb *hw_cb, kal_uint8 toutIndex)
{
	kal_uint16 tmpReg;
	kal_uint32 time1, time2;
	usim_dcb_struct *usim_dcb;

   gTout = toutIndex;
	sim_PDNDisable_MTK(hw_cb);
	SIM_WriteReg(0xa0010324, 0x0020);
	SIM_WriteReg(0xa0010324, 0x0010);

	kal_sprintf(sim_dbg_str,"tout2 test with value : %d", toutValue);
#if	!defined( __MAUI_BASIC__)
	tst_sys_trace(sim_dbg_str);
#else
	dbg_print(sim_dbg_str);
#endif



	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	if(0 == hw_cb->simInterface)
		sim_ToutTest = KAL_TRUE;
	else
		sim_ToutTest2 = KAL_TRUE;


	IRQMask(hw_cb->mtk_lisrCode);

       if(SIM_base == hw_cb->mtk_baseAddr){
	            DRV_ICC_PMU_switch(0, KAL_TRUE);
       }
       else{
		     DRV_ICC_PMU_switch(1, KAL_TRUE);
       }

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), 0x1);
	kal_sleep_task(10);


	/*set speed 8*/
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), 0x21);

	/*make sure SIM_IRQEN TOUT is set*/
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), 0xffff);

	/*set WTIME*/
	if(toutIndex == 1)
	   DRV_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), toutValue);
	else
	{
	   DRV_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT2_MTK), toutValue);
		kal_sprintf(sim_dbg_str,"tout2 test with value : %d", DRV_Reg32((SIM0_BASE_ADDR_MTK + SIM_TOUT2_MTK)));
#if	!defined( __MAUI_BASIC__)
		tst_sys_trace(sim_dbg_str);
#else
		dbg_print(sim_dbg_str);
#endif


}
	/*read clear IRQ*/
	tmpReg = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);

	if(toutIndex == 1)
	{
	   SIM_ClearBits(SIM0_BASE_ADDR_MTK+SIM_CONF_MTK, 0x80);
	   }
   else
   {
	   SIM_ClearBits(SIM0_BASE_ADDR_MTK+SIM_CONF_MTK, 0x4000);
	   }

	sim_toutTestTim1 = drv_get_current_time();
	DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle, 2, sim_toutTestGptCallback, (void *)hw_cb);
	if(toutIndex == 1)
	{
	   DRV_SetBits(SIM0_BASE_ADDR_MTK+SIM_CONF_MTK, 0x80);
	   }
   else
   {
	   DRV_SetBits(SIM0_BASE_ADDR_MTK+SIM_CONF_MTK, 0x4000);
		kal_sprintf(sim_dbg_str,"tout2 SIM_CONF_MTK with value : %d", DRV_Reg((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK)));
#if	!defined( __MAUI_BASIC__)
		tst_sys_trace(sim_dbg_str);
#else
		dbg_print(sim_dbg_str);
#endif


	   }
}



void sim_underRunTest(sim_HW_cb *hw_cb)
{
	kal_uint16 tmpReg;
	kal_uint32 time1, time2;
	usim_dcb_struct *usim_dcb;

	sim_PDNDisable_MTK(hw_cb);

	kal_sprintf(sim_dbg_str,"sim_underRunTest");
#if	!defined( __MAUI_BASIC__)
	tst_sys_trace(sim_dbg_str);
#else
	dbg_print(sim_dbg_str);
#endif



	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	if(0 == hw_cb->simInterface)
		sim_ToutTest = KAL_TRUE;
	else
		sim_ToutTest2 = KAL_TRUE;


	IRQMask(hw_cb->mtk_lisrCode);

       if(SIM_base == hw_cb->mtk_baseAddr){
	            DRV_ICC_PMU_switch(0, KAL_TRUE);
       }
       else{
		     DRV_ICC_PMU_switch(1, KAL_TRUE);
       }

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), 0x1);
	kal_sleep_task(10);

	/*read clear IRQ*/
	tmpReg = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);

	/*make sure SIM_IRQEN is set*/
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), 0xffff);


	/*ream FIFO many times*/
	kal_prompt_trace(MOD_SIM,"EGTIME test : %d, %x, %x, %x, %x", hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK));





}




void sim_extraGTimeTest(sim_HW_cb *hw_cb)
{
	kal_uint16 tmpReg;
	kal_uint32 time1, time2;
	usim_dcb_struct *usim_dcb;
	kal_uint32 loopIndex;

	sim_PDNDisable_MTK(hw_cb);

	kal_sprintf(sim_dbg_str,"sim_extraGTimeTest");
#if	!defined( __MAUI_BASIC__)
	tst_sys_trace(sim_dbg_str);
#else
	dbg_print(sim_dbg_str);
#endif



	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	if(0 == hw_cb->simInterface)
		sim_ToutTest = KAL_TRUE;
	else
		sim_ToutTest2 = KAL_TRUE;


	IRQMask(hw_cb->mtk_lisrCode);

       if(SIM_base == hw_cb->mtk_baseAddr){
	            DRV_ICC_PMU_switch(0, KAL_TRUE);
       }
       else{
		     DRV_ICC_PMU_switch(1, KAL_TRUE);
       }

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), 0x1);
	kal_sleep_task(10);

	/*read clear IRQ*/
	//tmpReg = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);

	/*make sure SIM_IRQEN is set*/
	//SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), 0xffff);


	/*ream FIFO many times*/
	//kal_prompt_trace(MOD_SIM,"EGTIME test : %d, %x, %x, %x, %x", hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK));

#if 1
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + 0x58), 0x1);
	for(loopIndex = 0; loopIndex< 5; loopIndex++){
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK, 0x5a);
	}
	kal_sleep_task(10);

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + 0x58), 0x2);
	for(loopIndex = 0; loopIndex< 5; loopIndex++){
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK, 0x5a);
	}
	kal_sleep_task(10);

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + 0x58), 0x4);
	for(loopIndex = 0; loopIndex< 5; loopIndex++){
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK, 0x5a);
	}
	kal_sleep_task(10);

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + 0x58), 0x8);
	for(loopIndex = 0; loopIndex< 5; loopIndex++){
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK, 0x5a);
	}
	kal_sleep_task(10);

#endif
#if 0
/* under construction !*/
#if	!defined( __MAUI_BASIC__)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if	!defined( __MAUI_BASIC__)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if	!defined( __MAUI_BASIC__)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if	!defined( __MAUI_BASIC__)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif
#if 1

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + 0x58), 0x10);
	for(loopIndex = 0; loopIndex< 5; loopIndex++){
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK, 0x5a);
	}
	kal_sleep_task(10);

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + 0x58), 0x20);
	for(loopIndex = 0; loopIndex< 5; loopIndex++){
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK, 0x5a);
	}
	kal_sleep_task(10);

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + 0x58), 0x40);
	for(loopIndex = 0; loopIndex< 5; loopIndex++){
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK, 0x5a);
	}
	kal_sleep_task(10);

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + 0x58), 0x80);
	for(loopIndex = 0; loopIndex< 5; loopIndex++){
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK, 0x5a);
	}
	kal_sleep_task(10);

#endif
}

void sim_ATimeTest(sim_HW_cb *hw_cb)
{
	kal_uint16 tmpReg;
	kal_uint32 time1, time2;
	usim_dcb_struct *usim_dcb;
	kal_uint32 loopIndex;

	sim_PDNDisable_MTK(hw_cb);

	kal_sprintf(sim_dbg_str,"sim_ATimeTest");
#if	!defined( __MAUI_BASIC__)
	tst_sys_trace(sim_dbg_str);
#else
	dbg_print(sim_dbg_str);
#endif



	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	if(0 == hw_cb->simInterface)
		sim_ToutTest = KAL_TRUE;
	else
		sim_ToutTest2 = KAL_TRUE;


	IRQMask(hw_cb->mtk_lisrCode);

       if(SIM_base == hw_cb->mtk_baseAddr){
	            DRV_ICC_PMU_switch(0, KAL_TRUE);
       }
       else{
		     DRV_ICC_PMU_switch(1, KAL_TRUE);
       }

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), 0x1);
	kal_sleep_task(10);

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + 0x58), 0x1);
	for(loopIndex = 0; loopIndex< 5; loopIndex++){
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK, 0x5a);
	}
	kal_sleep_task(10);

}


sim_reg_readCheck(kal_uint32 *regAddr, kal_uint32 regValue, char *testItem)
{
	kal_uint32	simReg;
	char			errorMessage[120];

	simReg = DRV_Reg32(regAddr);
	if(regValue != simReg){
		//kal_sprintf(errorMessage, "Error:address %x read back %x while do %s\n\r", (kal_uint32)regAddr, simReg, testItem);
		kal_sprintf(sim_dbg_str, "(%s)Error:address %x read back %x while expecting %x\n\r",testItem, (kal_uint32)regAddr, simReg, regValue);
#if	!defined( __MAUI_BASIC__)
			tst_sys_trace(sim_dbg_str);
#else
			dbg_print(sim_dbg_str);
#endif

	}
}


void sim_reg_resetCheck(sim_HW_cb *hw_cb)
{

	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_CTRL_MTK),			0x00000000,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_CONF_MTK),			0x00000000,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_BRR_MTK),			0x000005d1,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_IRQEN_MTK),		0x00000000,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_STS_MTK),			0x00000000,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_RETRY_MTK),		0x00000303,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_TIDE_MTK),			0x00000000,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_COUNT_MTK),		0x00000000,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_ATIME_MTK),		0x000002BE,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_DTIME_MTK),		0x0000000F,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_TOUT_MTK),			0x00000260,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)((SIM0_BASE_ADDR_MTK+0x4C)),	0x0000000A,	"resetTest");//SIM+004Ch is SIM_GTIME
	sim_reg_readCheck((kal_uint32 *)((SIM0_BASE_ADDR_MTK+0x50)),	0x0000000F,	"resetTest");//SIM+0050h is SIM_ETIME
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_INS_MTK),			0x00000000,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_IMP3_MTK),			0x00000000,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_SW1_MTK),			0x00000000,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_SW2_MTK),			0x00000000,	"resetTest");
	sim_reg_readCheck((kal_uint32 *)((SIM0_BASE_ADDR_MTK+0x70)),	0x00000001,	"resetTest");//SIM+0070h is SIM_ATRSTA
	sim_reg_readCheck((kal_uint32 *)((SIM0_BASE_ADDR_MTK+0x74)),	0x00000001,	"resetTest");//SIM+0074h is SIM_STATUS
//#ifdef MT6268 //MT6268 and later
	sim_reg_readCheck((kal_uint32 *)((SIM0_BASE_ADDR_MTK+ SIM_EXT_TIME_MTK)),	0x00000001,	"resetTest");
//#endif
}




void sim_reg_RAWCheck(sim_HW_cb *hw_cb)
{
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_CTRL_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_CTRL_MTK),			0x0000000a,	"RAWCheck_1");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_CTRL_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_CTRL_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_CTRL_MTK),			0x00000011,	"RAWCheck_2");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_CTRL_MTK), 0x00000000);
#if 1

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_CONF_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_CONF_MTK),		0x00002aaa,	"RAWCheck_3");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_CONF_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_CONF_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_CONF_MTK),		0x00001555,	"RAWCheck_4");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_CONF_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_BRR_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_BRR_MTK),			0x000002aa,	"RAWCheck_5");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_BRR_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_BRR_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_BRR_MTK),			0x00000555,	"RAWCheck_6");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_BRR_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_IRQEN_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_IRQEN_MTK),		0x00000aaa,	"RAWCheck_7");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_IRQEN_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_IRQEN_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_IRQEN_MTK),		0x00000555,	"RAWCheck_8");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_IRQEN_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_STS_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_STS_MTK),			0x00000000,	"RAWCheck_9");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_STS_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_STS_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_STS_MTK),			0x00000000,	"RAWCheck_10");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_STS_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_RETRY_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_RETRY_MTK),		0x00000202,	"RAWCheck_11");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_RETRY_MTK), 0x0000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_RETRY_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_RETRY_MTK),		0x00000505,	"RAWCheck_12");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_RETRY_MTK), 0x0000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_TIDE_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_TIDE_MTK),			0x00000a0a,	"RAWCheck_13");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_TIDE_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_TIDE_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_TIDE_MTK),			0x00000505,	"RAWCheck_14");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_TIDE_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_COUNT_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_COUNT_MTK),		0x00000000,	"RAWCheck_15");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_COUNT_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_COUNT_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_COUNT_MTK),		0x00000000,	"RAWCheck_16");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_COUNT_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_ATIME_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_ATIME_MTK),		0x000002aa,	"RAWCheck_17");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_ATIME_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_ATIME_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_ATIME_MTK),		0x00000155,	"RAWCheck_18");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_ATIME_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_DTIME_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_DTIME_MTK),		0x0000002a,	"RAWCheck_19");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_DTIME_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_DTIME_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_DTIME_MTK),		0x00000015,	"RAWCheck_20");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_DTIME_MTK), 0x00000000);

	DRV_WriteReg32((SIM0_BASE_ADDR_MTK+ SIM_TOUT_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_TOUT_MTK),			0x002AAAAA,	"RAWCheck_21");
	DRV_WriteReg32((SIM0_BASE_ADDR_MTK+ SIM_TOUT_MTK), 0x00000000);
	DRV_WriteReg32((SIM0_BASE_ADDR_MTK+ SIM_TOUT_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_TOUT_MTK),			0x00155555,	"RAWCheck_22");
	DRV_WriteReg32((SIM0_BASE_ADDR_MTK+ SIM_TOUT_MTK), 0x00000000);

	DRV_WriteReg(((SIM0_BASE_ADDR_MTK+0x4C)), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)((SIM0_BASE_ADDR_MTK+0x4C)),	0x0000000a,	"RAWCheck_23");
	DRV_WriteReg(((SIM0_BASE_ADDR_MTK+0x4C)), 0x00000000);
	DRV_WriteReg(((SIM0_BASE_ADDR_MTK+0x4C)), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)((SIM0_BASE_ADDR_MTK+0x4C)),	0x00000005,	"RAWCheck_24");
	DRV_WriteReg(((SIM0_BASE_ADDR_MTK+0x4C)), 0x00000000);

	DRV_WriteReg(((SIM0_BASE_ADDR_MTK+0x50)), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)((SIM0_BASE_ADDR_MTK+0x50)),	0x0000002a,	"RAWCheck_25");
	DRV_WriteReg(((SIM0_BASE_ADDR_MTK+0x50)), 0x00000000);
	DRV_WriteReg(((SIM0_BASE_ADDR_MTK+0x50)), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)((SIM0_BASE_ADDR_MTK+0x50)),	0x00000015,	"RAWCheck_26");
	DRV_WriteReg(((SIM0_BASE_ADDR_MTK+0x50)), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_INS_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_INS_MTK),			0x000000aa,	"RAWCheck_27");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_INS_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_INS_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_INS_MTK),			0x00000155,	"RAWCheck_28");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_INS_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_IMP3_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_IMP3_MTK),			0x000000aa,	"RAWCheck_29");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_IMP3_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_IMP3_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_IMP3_MTK),			0x00000055,	"RAWCheck_30");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_IMP3_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_SW1_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_SW1_MTK),			0x00000000,	"RAWCheck_31");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_SW1_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_SW1_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_SW1_MTK),			0x00000000,	"RAWCheck_32");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_SW1_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_SW2_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_SW2_MTK),			0x00000000,	"RAWCheck_33");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_SW2_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_SW2_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_SW2_MTK),			0x00000000,	"RAWCheck_34");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_SW2_MTK), 0x00000000);
// for MT6268B and later
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_EXT_TIME_MTK), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_EXT_TIME_MTK),			0x0000000a,	"RAWCheck_35");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_EXT_TIME_MTK), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_EXT_TIME_MTK), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ SIM_EXT_TIME_MTK),			0x00000005,	"RAWCheck_36");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ SIM_EXT_TIME_MTK), 0x00000000);

	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ 0x58), 0xAAAAAAAA);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ 0x58),			0x000000aa,	"RAWCheck_37");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ 0x58), 0x00000000);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ 0x58), 0x55555555);
	sim_reg_readCheck((kal_uint32 *)(SIM0_BASE_ADDR_MTK+ 0x58),			0x00000055,	"RAWCheck_38");
	DRV_WriteReg((SIM0_BASE_ADDR_MTK+ 0x58), 0x00000000);

#endif
}


void sim_RegTest(sim_HW_cb *hw_cb)
{
	sim_PDNDisable_MTK(hw_cb);
	IRQMask(hw_cb->mtk_lisrCode);

       if(SIM_base == hw_cb->mtk_baseAddr){
	            DRV_ICC_PMU_switch(0, KAL_TRUE);
       }
       else{
		     DRV_ICC_PMU_switch(1, KAL_TRUE);
       }

	sim_reg_resetCheck(hw_cb);
	sim_reg_RAWCheck(hw_cb);

}

void sim_baud8N4Test(sim_HW_cb *hw_cb)
{
	kal_uint16 tmpReg;
	kal_uint32 time1, time2;
	usim_dcb_struct *usim_dcb;
	kal_uint32 loopIndex;

	sim_PDNDisable_MTK(hw_cb);

#if	!defined( __MAUI_BASIC__)
		tst_sys_trace("sim_baud8N4Test");
#else
		dbg_print("sim_baud8N4Test");
#endif


	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	if(0 == hw_cb->simInterface)
		sim_ToutTest = KAL_TRUE;
	else
		sim_ToutTest2 = KAL_TRUE;


	IRQMask(hw_cb->mtk_lisrCode);

       if(SIM_base == hw_cb->mtk_baseAddr){
               DRV_ICC_PMU_setVolt(0, CLASS_B_30V);
	            DRV_ICC_PMU_switch(0, KAL_TRUE);
       }
       else{
           DRV_ICC_PMU_setVolt(1, CLASS_B_30V);
		     DRV_ICC_PMU_switch(1, KAL_TRUE);
       }

	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), 0x1);
	kal_sleep_task(10);



#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	/*set speed 16*/
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), 0x41);

	for(loopIndex = 0; loopIndex< 5; loopIndex++){
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK, 0xa5);
	}
	kal_sleep_task(5);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


}


#endif /* End of #if defined (__SIM_DVT__) */
//------------------------------------------------------------------------//
// General interfaces of sim driver
//------------------------------------------------------------------------//
/*************************************************************************
* FUNCTION
*  L1sim_Reset_All
*
* DESCRIPTION
*	1. general interface of sim reset for T=0 and T=1
*	2. it support warm reset for UICC
*	3. first enable error repeat handling process to cover parity error at ATR, if not 
*		success, disable it.
*	4. for SIM protocol with T=0, additional reset will be perfromed.
*
* PARAMETERS
*	ExpectVolt: expected input voltage for the SIM card.
*	ResultVolt: finally used power voltage.
*	warm: specify warm reset for UICC
*
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/
usim_status_enum L1sim_Reset_MTK(sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm, sim_HW_cb *hw_cb)
{
	usim_status_enum status;
	usim_dcb_struct *usim_dcb;
	Sim_Card *SimCard;

#ifdef DUAL_MCU_SIM_V1
	pmic6326_ccci_lock(KAL_TRUE);

	if(1 == sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface)){
		/*AP side may be sleep, polling until we got non-zero value from this register*/
		while(0 == SIM_Reg(0xF0001020));
			if(0 ==(SIM_Reg(0xF0001020) & 0x80))
				ASSERT(0);
	}
#endif
	
   	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	/*we should do platform check here, not allow to access interface 2 on one-SIM platform*/
	usim_InterfaceCheck(hw_cb);

	/*we should additionally check whether this interface has owner or not*/
	if(0 != usim_dcb->ownerTask  &&  kal_get_current_thread_ID() != usim_dcb->ownerTask && simfactorytest!=KAL_TRUE)
		ASSERT(0);
	
//	sim_baud8N4Test(hw_cb);
//	return USIM_NO_INSERT;
#if defined (__SIM_DVT__)
#if defined(BAUD_8N4_TEST)
	sim_baud8N4Test(hw_cb);
	return USIM_NO_INSERT;
#elif defined(SIM_REG_TEST)
	sim_RegTest(hw_cb);
	return USIM_NO_INSERT;
#endif

	if(KAL_TRUE == sim_ToutTest && 0 == hw_cb->simInterface)
		return USIM_NO_INSERT;
	if(KAL_TRUE == sim_ToutTest2 && 1 == hw_cb->simInterface)
		return USIM_NO_INSERT;
#endif /* End of #if defined (__SIM_DVT__) */
	if(warm == KAL_FALSE)
	{
#if defined(SIM_DEBUG_INFO)
		dbg_print("cold reset \r\n");
#endif
		//TS_HSK_ENABLE = KAL_TRUE;
		status = L1usim_Reset(ExpectVolt, ResultVolt, hw_cb);


		if (simfactorytest!=KAL_TRUE)
		usim_dcb->ownerTask = kal_get_current_thread_ID();
		if(status < 0)
		{
			//these string should cross over sometimes, fix when we meet
			//kal_sprintf(sim_dbg_str,"L1usim_Reset failed!(%d, %d)",status, hw_cb->simInterface);
			//kal_print(sim_dbg_str);
			DRV_ICC_print(SIM_PRINT_L1USIM_RESET_FAIL, status, hw_cb->simInterface, 0, 0, 0);
			//L1sim_PowerOff_All(simInterface);
#if defined (__SIM_DVT__)
#if defined(WTIME_TEST)
			sim_toutTest_viaGPT(16, hw_cb, 1);
			while(1)
			{
				kal_sleep_task(5);
			}
#elif defined(WTIME2_TEST)
			sim_toutTest_viaGPT(16, hw_cb, 2);
			while(1)
			{
				kal_sleep_task(5);
			}
#elif defined(EGTIME_TEST)
			sim_extraGTimeTest(hw_cb);
#elif defined(ATIME_TEST)
			sim_ATimeTest(hw_cb);
#elif defined(DTIME_TEST)
			sim_DTimeTest(hw_cb);

#endif

#else  /* End of #if defined (__SIM_DVT__) */
                        /* Normal power off flow */
			L1usim_PowerOff(hw_cb);
#endif /* End of #if defined (__SIM_DVT__) */
			if(status == USIM_NO_INSERT)
				usim_dcb->present = KAL_FALSE;
			#ifdef DUAL_MCU_SIM_V1
				pmic6326_ccci_lock(KAL_FALSE);
			#endif			
			return status;
			/*
			TS_HSK_ENABLE = KAL_FALSE;	
			status = L1usim_Reset(ExpectVolt, ResultVolt);
			if(status <0)
			{
				L1sim_PowerOff_All();
				MT6302_RACE_RELEASE(sim_MT6302_protectionRst);
				return status;
			}
			*/
		}
		else
		{
			kal_uint32 i;
			kal_char *p;
			

#if defined(SIM_DEBUG_INFO)
			if(USIM_DIRECT != usim_dcb->dir)
				dbg_print("indirect card!!!!");
#endif			
			p = sim_dbg_str;
			kal_sprintf(p,"[SIM_DRV]:SIM%d ATR= ", hw_cb->simInterface);
			p += strlen(p);
			for(i = 0; i< usim_dcb->ATR_index; i++)
			{
				kal_sprintf(p,"%02X",usim_dcb->ATR_data[i]);
				p+= 2;
			}
			kal_print(sim_dbg_str);
			//kal_sprintf(sim_dbg_str,"[SIM_DRV]: L1usim_Reset OK v: %d, T: %d, app: %d, speed:%d",
			//	usim_dcb->power, usim_dcb->phy_proto, usim_dcb->app_proto, usim_dcb->card_speed);
			//kal_print(sim_dbg_str);
			DRV_ICC_print(SIM_PRINT_L1USIM_RST_OK, usim_dcb->power, usim_dcb->phy_proto, usim_dcb->app_proto, usim_dcb->card_speed, 0);

			kal_sprintf(sim_dbg_str,"[SIM_DRV]: L1usim_Reset OK voltage: %d, T: %d, app: %d, speed:%d",
			usim_dcb->power, usim_dcb->phy_proto, usim_dcb->app_proto, usim_dcb->card_speed);
#if	!defined( __MAUI_BASIC__)
			tst_sys_trace(sim_dbg_str);
#else
			kal_print(sim_dbg_str);
#endif

			/*reset successfully, record its IR or AL state*/
			if(SIM_Reg(SIM0_BASE_ADDR_MTK + 0x0070) & 0x100){
				kal_sprintf(sim_dbg_str,"[SIM_DRV]:AL card, convention : %02X", usim_dcb->ATR_data[0]);
#if	!defined( __MAUI_BASIC__)
				tst_sys_trace(sim_dbg_str);
#else
				kal_print(sim_dbg_str);
#endif
			}
			else if(SIM_Reg(SIM0_BASE_ADDR_MTK + 0x0070) & 0x80){
				kal_sprintf(sim_dbg_str,"[SIM_DRV]:IR card, convention : %02X", usim_dcb->ATR_data[0]);
#if	!defined( __MAUI_BASIC__)
				tst_sys_trace(sim_dbg_str);
#else
				kal_print(sim_dbg_str);
#endif
			}
			else
				ASSERT(0);
		}
		if(usim_dcb->phy_proto == T0_PROTOCOL)
		{		
			
			kal_uint8 s;
			kal_uint8 power;

			#if !defined(MT6218B) && !defined(MT6218)
			SimCard = GET_SIM_CB(hw_cb->simInterface);
			SimCard->sim_dmaport = usim_dcb->dma_port;
			#endif			
			L1sim_Init_MTK(hw_cb);
			if(usim_dcb->power == CLASS_C_18V)
				power = SIM_18V;
			else 
				power = SIM_30V;		
			if(usim_dcb->app_proto == SIM_PROTOCOL)
			{
				s = sim_Reset_MTK(power, NULL, NULL, hw_cb);
#ifdef SIM_REMOVE_ATR_ASSERT
				if(SIM_NO_ERROR != s){
					usim_dcb->present = KAL_FALSE;
					status = USIM_NO_INSERT;
					return status;
				}
#endif
				ASSERT(s == SIM_NO_ERROR);
#ifdef DRV_SIM_RETRY_3V_ON_PTS_ERROR
				{ /* For [MAUI_01321659] begin */
					if (SimCard->Power == SIM_18V)
						*ResultVolt = CLASS_C_18V;
					else if (SimCard->Power == SIM_30V)
						*ResultVolt = CLASS_B_30V;
					else
						ASSERT(0);
				} /* For [MAUI_01321659] end */
#endif
			}
			else
				usim_update_sim_to_ready(hw_cb);

		}
	}
//#ifdef NO_SLIM_DEF
	else
	{
#if defined(SIM_DEBUG_INFO)
		dbg_print("warm reset \r\n");
#endif
		if(usim_dcb->app_proto == USIM_PROTOCOL)
		{
			usim_dcb->warm_rst = KAL_TRUE;
			status = L1usim_Reset(usim_dcb->power, ResultVolt, hw_cb);
			usim_dcb->warm_rst = KAL_FALSE;
			if(status <0)
			{
				//L1sim_PowerOff_All(simInterface);
				L1usim_PowerOff(hw_cb);
			#ifdef DUAL_MCU_SIM_V1
				pmic6326_ccci_lock(KAL_FALSE);
			#endif
				return status;
			}
			if(usim_dcb->phy_proto == T0_PROTOCOL)
			{		
				kal_uint8 power = 0;

				SimCard = GET_SIM_CB(hw_cb->simInterface);
				SimCard->sim_dmaport = usim_dcb->dma_port;
				L1sim_Init_MTK(hw_cb);
				if(usim_dcb->power == CLASS_C_18V)
					power = SIM_18V;
				else 
					power = SIM_30V;
				if(usim_dcb->app_proto == SIM_PROTOCOL){
					sim_Reset_MTK(power, NULL, NULL, hw_cb);
#ifdef DRV_SIM_RETRY_3V_ON_PTS_ERROR
					{ /* For [MAUI_01321659] begin */
						if (SimCard->Power == SIM_18V)
							*ResultVolt = CLASS_C_18V;
						else if (SimCard->Power == SIM_30V)
							*ResultVolt = CLASS_B_30V;
						else
							ASSERT(0);
					} /* For [MAUI_01321659] end */
#endif
				}
				else
					usim_update_sim_to_ready(hw_cb);
			}			
		}
		else
		{
			status = USIM_INVALID_WRST;
		}
	}
//#endif		
#ifdef DUAL_MCU_SIM_V1
	pmic6326_ccci_lock(KAL_FALSE);
#endif
		
	return status;
}
/*************************************************************************
* FUNCTION
*  L1sim_Enable_Enhanced_Speed_All
*
* DESCRIPTION
*	enable the enhance speed
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/

void L1sim_Enable_Enhanced_Speed_MTK(kal_bool enable, sim_HW_cb *hw_cb)
{
#ifdef NO_SLIM_DEF
	L1sim_Enable_Enhanced_Speed(enable, hw_cb);
	L1usim_Enable_Enhanced_Speed(enable, hw_cb);
#endif	
	
}
/*************************************************************************
* FUNCTION
*  L1sim_Select_Prefer_PhyLayer_All
*
* DESCRIPTION
*	select the prefer physical layer protocol, the selected one has higher priority
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/

void L1sim_Select_Prefer_PhyLayer_MTK(sim_protocol_phy_enum T, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	usim_dcb->perfer_phy_proto = T;
}
/*************************************************************************
* FUNCTION
*  L1sim_Set_ClockStopMode_All
*
* DESCRIPTION
*	configure the clock stop mode.
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/

kal_bool L1sim_Set_ClockStopMode_MTK(sim_clock_stop_enum mode, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	
	if(usim_dcb->phy_proto == T0_PROTOCOL)
	{
		if(mode == CLOCK_STOP_HIGH)
			L1sim_Configure_MTK(CLOCK_STOP_AT_HIGH, hw_cb);
		else if(mode == CLOCK_STOP_LOW || mode == CLOCK_STOP_ANY)
			L1sim_Configure_MTK(CLOCK_STOP_AT_LOW, hw_cb);
		else
			L1sim_Configure_MTK(CLOCK_STOP_NOT_ALLOW, hw_cb);
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
		
	}
	else
	{
		L1usim_Set_ClockStopMode(mode, hw_cb);
	}
	
	return KAL_TRUE;
}
/*************************************************************************
* FUNCTION
*  L1sim_PowerOff_All
*
* DESCRIPTION
*	turn off the SIM card.
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/

void L1sim_PowerOff_MTK(sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usim_dcb;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);

#ifdef DUAL_MCU_SIM_V1
	sim_addMsg(0x11111801, hw_cb->simInterface, 0, 0);
	pmic6326_ccci_lock(KAL_TRUE);
	sim_addMsg(0x11111802, hw_cb->simInterface, 0, 0);
#endif

	/*we should additionally check whether this interface has owner or not*/
	if(0 != usim_dcb->ownerTask  &&  kal_get_current_thread_ID() != usim_dcb->ownerTask  && simfactorytest!=KAL_TRUE)
		ASSERT(0);

	
	
	if(usim_dcb->phy_proto == T0_PROTOCOL){
#ifdef DUAL_MCU_SIM_V1
		sim_addMsg(0x11111803, hw_cb->simInterface, 0, 0);
		kal_sleep_task(50);
#endif
		sim_PowerOff_MTK(hw_cb);
#ifdef DUAL_MCU_SIM_V1
		kal_sleep_task(100);
		sim_addMsg(0x11111804, hw_cb->simInterface, 0, 0);
#endif
	}
	else{
#ifdef DUAL_MCU_SIM_V1
		sim_addMsg(0x11111805, hw_cb->simInterface, 0, 0);
		kal_sleep_task(50);
#endif
		L1usim_PowerOff(hw_cb);
#ifdef DUAL_MCU_SIM_V1
		kal_sleep_task(100);
		sim_addMsg(0x11111806, hw_cb->simInterface, 0, 0);
#endif
	}

#ifdef DUAL_MCU_SIM_V1
	sim_addMsg(0x11111807, hw_cb->simInterface, 0, 0);
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL1, __LINE__, hw_cb->simInterface, 0, 0, 0, 0, drv_get_current_time());
#endif
	pmic6326_ccci_lock(KAL_FALSE);
	sim_addMsg(0x11111808, hw_cb->simInterface, 0, 0);
#endif
	
	usim_dcb->present = KAL_FALSE;
}
/*************************************************************************
* FUNCTION
*  L1sim_Get_Card_Info_All
*
* DESCRIPTION
*	get the card information
*
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*
*************************************************************************/

void L1sim_Get_Card_Info_MTK(sim_info_struct *info, sim_HW_cb *hw_cb)
{
	L1usim_Get_Card_Info(info, hw_cb);
}
/*************************************************************************
* FUNCTION
*  L1sim_Cmd_All
*
* DESCRIPTION
*	1. check which case the command belongs to.
*	2. direct the command into T=0 or T=1 protocol layer. 
*
* PARAMETERS
*	1. txData: tx buffer containing command header optional with tx data.
*	2. txSize: length of the tx data
*	3. rxData: rx buffer (for T=1, must inluding two extra one for sw1 and sw2)
*	4. rxSize: length of the rx data except sw1|sw2
*	
* RETURNS
*	status bytes(SW1|SW2), 0 means a physical error.
*
* GLOBALS AFFECTED
*
*************************************************************************/
sim_status L1sim_Cmd_MTK(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, sim_HW_cb *hw_cb)
{
	usim_dcb_struct *usimCard;
	sim_status result;
     	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);
	usimCard = GET_USIM_CB(hw_cb->simInterface);
	/*we should do platform check here, not allow to access interface 2 on one-SIM platform*/
	usim_InterfaceCheck(hw_cb);

	/*we should additionally check whether this interface has owner or not*/
	if(0 != usimCard->ownerTask  &&  kal_get_current_thread_ID() != usimCard->ownerTask  && simfactorytest!=KAL_TRUE)
		ASSERT(0);

	
	
	if(usimCard->present == KAL_FALSE){
		return SIM_SW_STATUS_FAIL;
	}
	
	
	
	// check cmd cases
	if(*txSize <= 5 && rxData == NULL)
	{
		//SIM case1 txSize = 5 bytes, UICC case1 txSize = 4 bytes
		usimCard->cmd_case = usim_case_1;
		/////dbg_print("usim_case_1 \r\n");
	}
	else if(*txSize == 5 && rxData != NULL)
	{
		usimCard->cmd_case = usim_case_2;
		if(((0 == txData[LEN_INDEX]) && (256 > *rxSize)) || (*rxSize < txData[LEN_INDEX])){
			return 0x0000;
		}
		/////dbg_print("usim_case_2 \r\n");
	}
	else if(*txSize != 5 && rxData == NULL)
	{
		//SIM case3 txSize > 5 bytes, UICC case3 txSize > 5 bytes
		usimCard->cmd_case = usim_case_3;
		/////dbg_print("usim_case_3 \r\n");
	}
	else if(*txSize != 5 && rxData != NULL)
	{
		usimCard->cmd_case = usim_case_4;
		/////dbg_print("usim_case_4 \r\n");
	}	
	SimCard->cmd_case = usimCard->cmd_case;
#if defined(SIM_DEBUG_INFO)
   DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC1, *txData,*(txData+1),*(txData+2),*(txData+3),*(txData+4));
   DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC1, *txSize,*rxSize,hw_cb->simInterface,*rxData,SimCard->cmd_case);
#endif
	if(usimCard->phy_proto == T0_PROTOCOL)
	{		
		result = L1sim_Cmd_Layer_MTK(txData, txSize,  rxData, rxSize, hw_cb, &usimCard->isSW6263);
#if defined(SIM_DEBUG_INFO)
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC19, *txData,*(txData+1),*(txData+2),*(txData+3),*(txData+4));
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC19, *rxData,*(rxData+1),*(rxData+2),*(rxData+3),*(rxData+4));
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC19, *txSize,*rxSize,result,usimCard->isSW6263,SimCard->cmd_case);
#endif
		return result;
	}
	else
	{
		result = L1usim_Cmd(txData, txSize,  rxData, rxSize, hw_cb);
		return result;
	}
}

void L1sim_EOC_MTK(sim_HW_cb *hw_cb)
{
	/*there should be nothing to do in EOC in dual controller solution*/
}

void sim_toutTest(kal_uint32 toutValue, sim_HW_cb *hw_cb)
{
#ifdef SIM_HW_TEST

	kal_uint32 time1, time2;
#if defined(SIM_DEBUG_INFO)
	kal_sprintf(sim_dbg_str,"tout test with value : %d", toutValue);
	kal_print(sim_dbg_str);
#endif	
	IRQMask(hw_cb->mtk_lisrCode);
	
	/*set speed 8*/
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), 0x21);

	/*make sure SIM_IRQEN TOUT is set*/
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), 0x8);
	
	/*set WTIME*/
	DRV_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), toutValue);

	/*read clear IRQ*/
	SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);

	SIM_ClearBits(SIM_CONF, 0x80);

	time1 = drv_get_current_time();
	DRV_SetBits(SIM_CONF, 0x80);
	while(0x8 != SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK));

	time2 = drv_get_duration_ms(time1);
   time2 = time2;
	IRQUnmask(hw_cb->mtk_lisrCode);

#if defined(SIM_DEBUG_INFO)
	kal_sprintf(sim_dbg_str,"tout test done with period : %d ms", time2);
	kal_print(sim_dbg_str);
#endif
	

#endif //SIM_HW_TEST

}


sim_ctrlDriver sim_ctrlDriver_MTK = {
	L1sim_Reset_MTK,
	L1sim_Cmd_MTK,
	L1sim_PowerOff_MTK,
	L1sim_Get_Card_Info_MTK,
	L1sim_Enable_Enhanced_Speed_MTK,
	L1sim_Select_Prefer_PhyLayer_MTK,
	L1sim_Set_ClockStopMode_MTK,
	L1sim_EOC_MTK,
	sim_addMsg,
	sim_toutTest
};


//--------------------------------------------------------------------------//
// usim driver unit test code
//--------------------------------------------------------------------------//
/*
The behavior of the T1 controller
1. enable T1 controller
2. write NAD, PCB, LEN  into SIM_DATA
3. write LEN into SIMP3
4. configure the DMA for data transfer (INF field) 
5. write any value into SIM_INS (trigger to start)
6. generate the T1END interrupt.
7. if a response block is received, T1END is generated again
8. The received block is in the data buffer, the EDC is checked and removed.
*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef PINCODE_TEST
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
#ifdef GEMINI_UNIT_TEST_ON_2_TASK
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else	// USIM_DEBUG
void usim_ut_main(void)
{
}
#endif // USIM_DEBUG
#endif // __USIM_DRV__
#endif //DRV_MULTIPLE_SIM
#endif /*__SIM_DRV_MULTI_DRV_ARCH__*/

#endif //DRV_SIM_OFF

