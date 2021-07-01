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
 *   msdc2.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for MSDC controller
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
#include "drv_features.h"
#ifndef DRV_MSDC_OFF
#include "kal_release.h"
//RHR ADD
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "hisr_config.h"
#include "config_hw.h"
#include "init.h"
#include "pll.h"
//RHR REMOVE
/*
#include "kal_non_specific_general_types.h"
#include "kal_active_module.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "eint.h"
#include "fat_fs.h"
//#include "gpio_hw.h"
#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif//__MULTI_BOOT__
#include "pmu_sw.h"
#if defined(KAL_ON_NUCLEUS)
#include "nucleus.h"
#include "ev_defs.h"
#endif
*/
//RHR
#include "kal_trace.h"
#include "dcl.h"
#include "stack_common.h"  
#include "stack_msgs.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "intrCtrl.h"
#include "reg_base.h"
#include "drvpdn.h"
#include "drv_features.h"
#include "drv_comm.h"
#include "msdc_reg_adap.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "drv_hisr.h"
#include "drvpdn.h"
#include "l1sm_public.h"
#include "msdc_def.h"
#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)

#if !defined(__UBL__) || defined(__CARD_DOWNLOAD__) 


#include "msdc_api.h"
#include "msdc_def.h"
#include "sd_def.h"

//! EMB
#include "FTL.h"
//#if defined(__MSDC2_SD_MMC__)&&defined(__MSDC2_SD_SDIO__)
#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
#include "sdio_sw.h"
#endif
#include "upll_ctrl.h"
//#include "gpio_hw.h"
//#include "gpio_sw.h"
#include "Drv_trc.h"
#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /*__MULTI_BOOT__*/
//#include "sim_hw.h"





#ifdef __CLKG_DEFINE__
#ifdef DRVPDN_CON0
#error "__CLKG_DEFINE__ & DRVPDN_CON0 are all defined"
#else
#define DRVPDN_CON0		CG_CON0
#endif

#ifdef DRVPDN_CON1_SIM
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SIM are all defined"
#else
#define DRVPDN_CON1_SIM	CG_CON1_SIM
#endif

#ifdef DRVPDN_CON0_MSDC2
#error "__CLKG_DEFINE__ & DRVPDN_CON0_MSDC2 are all defined"
#else
#define DRVPDN_CON0_MSDC2	CG_CON0_MSDC2
#endif

#ifdef DRVPDN_CON0_CLR
#error "__CLKG_DEFINE__ & DRVPDN_CON0_CLR are all defined"
#else
#define DRVPDN_CON0_CLR	CG_CLR0
#endif

#ifdef DRVPDN_CON0_SET
#error "__CLKG_DEFINE__ & DRVPDN_CON0_SET are all defined"
#else
#define DRVPDN_CON0_SET	CG_SET0
#endif
#endif

MSDC_HANDLE MSDC2_Blk[SD_NUM];

#if defined(MT6256)
kal_uint32 gMsdc2ClksrcRate[MSDC_CLKSRC_NUM] = {94500, 86600, 74200, 65000};
#elif defined(MT6255)
kal_uint32 gMsdc2ClksrcRate[MSDC_CLKSRC_NUM] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
#elif defined(MT6250)
kal_uint32 gMsdc2ClksrcRate[MSDC_CLKSRC_NUM] = {97500, 86600, 78000, 65000};
#elif defined(MT6260)
kal_uint32 gMsdc2ClksrcRate[MSDC_CLKSRC_NUM] = {97000, 91000, 73000, 60600};
#elif defined(DRV_MSDC_CLKSRC_MT6261_SERIES)
kal_uint32 gMsdc2ClksrcRate[MSDC_CLKSRC_NUM] = {94500, 74300, 65000, 60600};
#else
kal_uint32 gMsdc2ClksrcRate[MSDC_CLKSRC_NUM] = {122200, 101800, 87200, 76300}; // KHz
#endif


#if defined(__UBL__) 
//#pragma arm section zidata = "EXT_BOOTLOADER_UNINIT_ZI"
#pragma arm section zidata = "EXT_UN_INIT_ZI"
#else
#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
#endif

kal_uint32 MSDC_Sector2[128] = {0};
MSDC_HANDLE *gMSDC2_Handle = &MSDC2_Blk[MSDC2_SD1];
extern T_SDC_HANDLE	*gSD2;

#ifdef MSDC_CACHED_SUPPORT
kal_uint32	msdc_uncachedBuf2[MSDC_UNCACHED_BUF_SIZE/4];	
#endif
#pragma arm section zidata, rwdata


#define MSDC2_DMA_BURSTLEN_LIMIT 65024
kal_bool MSDC2_useDMA4ByteBurst = KAL_FALSE;

#ifdef  __TST_WRITE_TO_FILE__
/*error recording: add this additional global variable to use when in error recording*/
MSDC_HANDLE MSDC2_ErrorRecordingBlk;
#endif


#if defined(DRV_MSDC2_SHARE_BY_SWITCH)
sd_select_enum current_card2; // active card
#if !defined(__CUST_NEW__)
extern kal_char MSDC2_GetLDO_GPIO(void);
extern kal_char MSDC2_GetSwitch_GPIO(void);
extern kal_char MSDC2_GetEXTLDO_GPIO(void);
extern kal_char MSDC2_GetSwitchDirection(void);
kal_char gpio_simplug_ldo_switch2;
kal_char gpio_ext_sd_ldo_switch2;
kal_char gpio_sim_msdc_switch2;	
#endif
#endif


#if !defined(LOW_COST_SUPPORT) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__) && !defined(__UBL__)
msdc_debugMessage msdc2_msgArray[MSDC_DBG_ARRAY_SIZE];
kal_uint32 msdc2_msdIndex;
#endif

// function predeclaration
void MSDC2_DMAInit(void);
void MSDC2_INT_Init(void);
void MSDC2_DMA_Callback(void);
void MSDC2_EINT_Handler(void);
void MSDC2_turnOnVMC(kal_bool turnOnLdo);


extern boot_mode_type stack_query_boot_mode(void); 

extern kal_uint32 MSDC2_GetCustom(void);
extern kal_bool SD2_CheckTimeoutWithSleep(kal_int32 start_time,
                         kal_int32 duration_ms,
                         kal_int32 sleep_time);
extern kal_bool FTL_isPollingMode(void);
extern module_type stack_int_get_active_module_id( void );


#ifdef __CARD_DOWNLOAD__
extern kal_bool MSDC2_QueryIsPowerControllable(void);
extern void MSDC2_SetPower(kal_bool enable);
#endif
#ifdef __MSDC_CD_EINT__

extern const unsigned char MSDC2_EINT_NO;
static kal_uint32 MSDC2_debounceTime;
static kal_bool cardDetectionEINTPolarity2;
#endif


#ifdef R1B_INTERRUPT_MODE
static void MSDC2_R1B_Init(void);
#endif

#if defined(__UBL__) || defined(__FUE__)
kal_bool MSDC2_START_TIMER(kal_uint16 x)
{
	gMSDC2_Handle->is_timeout = KAL_FALSE;
	return KAL_TRUE;
}
#else// defined(__UBL__) || defined(__FUE__)

kal_bool MSDC2_START_TIMER(kal_uint16 x)
{
	//DCL_HANDLE gpt_handle;
	DCL_STATUS status;
	SGPT_CTRL_START_T start;
	
	gMSDC2_Handle->is_timeout = KAL_FALSE;			
	start.u2Tick=x;
	start.pfCallback=MSDC2_TimeOutHandler;
	start.vPara=NULL;
	//gpt_handle= module |MSDC_GPT_CB_MAGIC_NUM;
	status=DclSGPT_Control(MSDC2_Blk[0].gpt_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
	if(STATUS_OK==status)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}
#endif// defined(__UBL__) || defined(__FUE__)


#if defined(__UBL__) || defined(__FUE__)
kal_bool MSDC2_STOP_TIMER()
{
	return KAL_TRUE;
}
#else// defined(__UBL__) || defined(__FUE__)
kal_bool MSDC2_STOP_TIMER()
{
	if(!gMSDC2_Handle->mIsPresent )
	{
		kal_set_eg_events(gMSDC2_Handle->MSDC_Events, 0, KAL_AND);
		return KAL_FALSE;
	}
	//MSDC_GPTI_StopItem(gMSDC2_Handle->gpt_handle);
        DclSGPT_Control(MSDC2_Blk[0].gpt_handle,SGPT_CMD_STOP,0);
	if(gMSDC2_Handle->is_timeout)
	{
		kal_set_eg_events(gMSDC2_Handle->MSDC_Events, 0, KAL_AND);
	}
	return KAL_TRUE;
}
#endif// defined(__UBL__) || defined(__FUE__)


#if !defined(__FUE__) && !defined(__UBL__)
void MSDC2_BusyWait_ms(kal_uint16 len)
{
 	kal_uint32 t1;
	t1 = drv_get_current_time();
	while(drv_get_duration_ms(t1)<1)
		;
}
#if 0
#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
/* under construction !*/
/* under construction !*/
#endif
#endif
kal_uint8 MSDC2_GPTI_GetHandle(DCL_HANDLE *handle)
{
 	//DCL_HANDLE gpt_handle;
	*handle=DclSGPT_Open(DCL_GPT_CB, 0);

	//*handle = 0xFF & gpt_handle;

	return KAL_TRUE;
}
#if 0
#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
/* under construction !*/
/* under construction !*/
#endif
#endif
#endif //!defined(__FUE__) && !defined(__UBL__)

void Reset_MSDC2()
{
	kal_uint32 t1,t2;
	if(!(MSDC_Reg32(MSDC_CFG2) & MSDC_CFG_RST))
	{
		MSDC_LSD_SetBits32(MSDC_CFG2,MSDC_CFG_RST);
		
	}
	t1=drv_get_current_time();
	while(MSDC_Reg32(MSDC_CFG2) & MSDC_CFG_RST)
	{
		t2=drv_get_current_time();
		if(t2>=t1)
		{
		  if((t2-t1)>2)
		  {
		  	MSDC_LSD_ClearBits32(MSDC_CFG2,MSDC_CFG_RST);
			
		  }
		}
		else
		{
			t1=drv_get_current_time();
		}
	}
}

void MSDC2_ClockInit(){
	MSDC_ClearBits32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);
	// set read timeout x5ms
	/*in 50MHZ case, we should set 80 to have at least 100ms timeout*/
	BitFieldWrite32_2((kal_uint32*)SDC_CFG2,(kal_uint32)80,SDC_CFG_DTOC);
	//set clock of serial clcok for initialization
#if defined(DRV_MSDC_CLK_MT6260_SERIES)
	MSDC_LSD_SetBits32(PLL_CLK_CONDD, RG_MSDC2_26M_SEL);
	MSDC_LSD_ClearBits32(MSDC_CFG2,MSDC_CFG_CLKSRC_PAT);	
#endif
#if defined(DRV_MSDC_CLKSRC_MT6261_SERIES)
	MSDC_LSD_SetBits32(PLL_CLK_CONDD, RG_MSDC2_26M_SEL);
//	MSDC_LSD_ClearBits32(PLL_CLK_CONDA, BT_APP_DIV_EN);
//	MSDC_LSD_SetBits32(PLL_CLK_CONDA, POWERFUL_DIV_EN1);

#endif
	MSDC_LSD_ClearBits32(MSDC_CFG2,MSDC_CFG_CLKSRC);

	gMSDC2_Handle->msdc_clock = MSDC_CLOCK;
	//ACMD41 must be work under clock 100K~400K
	MSDC2_SetClock(MSDC_INI_CLOCK);	

}

/*************************************************************************
* FUNCTION
*  MSDC_SetClock
*
* DESCRIPTION
*
* PARAMETERS
*	clock: the desired operating clock rate in the unit of kHz
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MSDC2_SetClock(kal_uint32 clock)
{
	kal_uint32 cfg;

	if(clock == 0)
		return;
	MSDC_LSD_ClearBits32(SDC_CFG2,SDC_CFG_SIEN);
	cfg = ((gMSDC2_Handle->msdc_clock+clock-1)/clock);
	if(cfg <=2 )
	{		
		cfg = 0;
		gMSDC2_Handle->op_clock = gMSDC2_Handle->msdc_clock/2;
	}
	else
	{
		//I change , cfg = (cfg >> 2) + (cfg&3 != 0); , to following line for Lint wrning
		cfg = (cfg >> 2) + (((cfg & 3) != 0)? 1: 0);
		if(0 != cfg){
			gMSDC2_Handle->op_clock = gMSDC2_Handle->msdc_clock/(4*cfg);
		}
		else{
			ASSERT(0);			
		}
	}
	#if defined(MT2501)||defined(MT2502)||defined(MT6261)
	BitFieldWrite32_2((kal_uint32*)MSDC_CFG2,2,MSDC_CFG_CLKSRC);
	#endif
	BitFieldWrite32_2((kal_uint32*)MSDC_CFG2,(kal_uint32)cfg,MSDC_CFG_SCLKF);
	MSDC_LSD_SetBits32(SDC_CFG2,SDC_CFG_SIEN);
	
}


void MSDC2_SetClockSource(T_MSDC_CLK_TYPE type)
{
	switch (type)
	{
	case MSDC_CLOCK_MCU:

#if defined(MT6260)
		MSDC_LSD_ClearBits32(PLL_CLK_CONDD, RG_MSDC2_26M_SEL);
#else
		MSDC_LSD_ClearBits32(MSDC_CFG2, MSDC_CFG_CLKSRC);
#endif
		break;
	case MSDC_CLOCK_MCPLL:
#if defined(MT6260)
		MSDC_LSD_SetBits32(PLL_CLK_CONDD, RG_MSDC2_26M_SEL);
#else
		MSDC_LSD_SetBits32(MSDC_CFG2, MSDC_CFG_CLKSRC);
#endif
		break;
	default:
		ASSERT(0);
	}
}

/*************************************************************************
* FUNCTION
*  MSDC2_Check_Card_Present
*
* DESCRIPTION
*	c
*
* PARAMETERS
*	ON: turn on power saving or not
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
kal_bool MSDC2_Check_Card_Present(void)
{
	return gMSDC2_Handle->mIsPresent;

}

kal_bool MSDC2_Check_Card_Mount(void)
{
    return gMSDC2_Handle->mIsInitialized;
}
#if !defined(__MSDC_SD_MMC__)&&!defined(__MSDC_SD_SDIO__)

//just for ata link pass jeffrey 2014.3.24
kal_bool MSDC_Check_Card_Mount(void)
{
    return gMSDC2_Handle->mIsInitialized;
}
#endif
#if defined(MT6256) || defined(MT6276) || defined(MT6255) || defined(MT6250)
//After MT6260 PDN driver will not support this
void MSDC2_PDNControl(kal_bool ON)
{
	gMSDC2_Handle->mIsPWDown = ON;
	if(ON)
	{	// OFF
#if defined(__UBL__) || defined(__FUE__)
		//ASSERT(0);
#else//defined(__UBL__) || defined(__FUE__)
		// clear all pending IRQ
		MSDC2_CLR_INT();
        DRVPDN_Enable(PDN_MSDC2);
#ifdef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
        DRVPDN_Enable(PDN_MSDC);//guilin
#endif
		#if defined(MT6250)
        if (INT_SW_SecVersion() == SW_SEC_0) {
		    PDN_SET(PDN_SW_MSDC);
        }
		#endif
#endif//__UBL__//__CARD_DOWNLOAD__
	}
	else
	{	// ON

#if defined(__UBL__) || defined(__FUE__)
       	DRVPDN_Disable(PDN_MSDC2);
		#if defined(MT6250)
        if (INT_SW_SecVersion() == SW_SEC_0) {
		    PDN_CLR(PDN_SW_MSDC);
        }
		#endif
#else//defined(__UBL__) || defined(__FUE__)
        DRVPDN_Disable(PDN_MSDC2);
#ifdef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
        DRVPDN_Disable(PDN_MSDC);//guilin
#endif
		#if defined(MT6250)
        if (INT_SW_SecVersion() == SW_SEC_0) {
		    PDN_CLR(PDN_SW_MSDC);
        }
		#endif

#endif//__UBL__//__CARD_DOWNLOAD__
	}

}

#else //MSDC_DRV_SUPPORT_LPWR
#define MSDC2_SLEEP_MODE_INVALID_HANDLE 0xFF
static kal_uint8 MSDC2_sm_handler = MSDC2_SLEEP_MODE_INVALID_HANDLE;
void MSDC2_PDNControl(kal_bool ON)
{
	gMSDC2_Handle->mIsPWDown = ON;
    if(MSDC2_SLEEP_MODE_INVALID_HANDLE == MSDC2_sm_handler)//
    {
        MSDC2_sm_handler = L1SM_GetHandle();
    }
	if(ON)
	{	// OFF
		MSDC_CLR_INT();
        PDN_SET(PDN_MSDC2); //power down dev
#ifdef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
        PDN_SET(PDN_MSDC); //power down dev
#endif
#if !defined(__UBL__) && !defined(__FUE__)
		L1SM_SleepEnable(MSDC2_sm_handler);  //unlock sleep mode
#endif//__UBL__//__CARD_DOWNLOAD__
	}
	else
	{	// ON
		PDN_CLR(PDN_MSDC2);
#ifdef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
        PDN_CLR(PDN_MSDC);
#endif
#if !defined(__UBL__) && !defined(__FUE__)        
		L1SM_SleepDisable(MSDC2_sm_handler); //lock sleep mode		
#endif//__UBL__//__CARD_DOWNLOAD__
	}
}
#endif


/*************************************************************************
* FUNCTION
*  MSDC_TimeOutHandler2
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
void MSDC2_TimeOutHandler(void *parameter)
{
	kal_print("MSDC2_TimeOutHandler");
#if defined(MSDC_TRACE_LEVEL3)
	MSDC_add_dbg_msg(msdc_dbg_event_GPT_timeout, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), MSDC_Reg32(SDC_STA2));
#endif
	
	gMSDC2_Handle->is_timeout = KAL_TRUE;	

	kal_set_eg_events(gMSDC2_Handle->MSDC_Events,
				(EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_SDR1BIRQ|EVENT_DMAIRQ),
				KAL_OR);	

}



/*************************************************************************
* FUNCTION
*  MSDC_GetCardStatus
*
* DESCRIPTION
*	Check currently card is present or not.
*
* PARAMETERS
*	
*
* RETURNS
*
* GLOBALS AFFECTED
*	msdc_eint_state
*
*
*************************************************************************/
int MSDC2_GetCardStatus(void * DriveData, int AckType)
{
	MSDC_HANDLE *msdc = (MSDC_HANDLE *)DriveData;;

#if defined(__AUDIO_DSP_LOWPOWER__)
	AUDMA_LOCK(AUDMA_ID_MSDC);
#endif

	// a debounce mechanism 
	if(kal_query_systemInit() == KAL_FALSE && KAL_FALSE == INT_QueryExceptionStatus()
		&& msdc->mIsPresent==KAL_TRUE)
	{
#if !defined(__UBL__) && !defined(__FUE__)
		kal_sleep_task(100);
#endif
	}	 
	ENTER_CRITICAL();
	msdc->send_ilm = KAL_TRUE;
	EXIT_CRITICAL();
	
#if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
	/*since in SIM plus solution, only SD_MSDC2_CARD1 support hot plug. we only power down MSDC here*/
	if(!msdc->mIsPresent && current_card2 == SD_MSDC2_CARD1)
		MSDC2_PDNControl(KAL_TRUE);	
#else
	if(!msdc->mIsPresent)
		MSDC2_PDNControl(KAL_TRUE);
#endif

#if defined(__AUDIO_DSP_LOWPOWER__)
	AUDMA_UNLOCK(AUDMA_ID_MSDC);
#endif
	return 0;
}


void MSDC2_SendCardInd(module_type dest_id,sd_select_enum sel, kal_uint32 msg_id)
{
	module_type module_id;
	
	#if defined(__MSDC_SD_SDIO__)|| defined(__MSDC2_SD_SDIO__)
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
		return;
	#endif // __MSDC_SD_SDIO__

#ifdef	__DRV_MSDC_FAST_FORMAT__
	/*	in fast format, there is chance to plug out card when task is waiting for 
		DMA or timeout event from large number of DMA transfer, 
	*/
	if(KAL_TRUE == MSDC2_Blk[sel].MSDC_fastFormat)
	{
		if(KAL_FALSE == MSDC2_Blk[sel].is_timeout){
		DclSGPT_Control(MSDC2_Blk[0].gpt_handle,SGPT_CMD_STOP,0);
			MSDC2_Blk[sel].is_timeout = KAL_TRUE;	
			kal_set_eg_events(MSDC2_Blk[sel].MSDC_Events, EVENT_DMAIRQ, KAL_OR);
		}
	}
#endif

	#ifdef MSDC_TRACE_LEVEL1
	drv_trace2(TRACE_GROUP_6, MSDC_INFORM_HOTPLUGILM, sel, MSDC2_Blk[sel].send_ilm);
	#endif


	//in current design, only SIM plus solution need two card indication.
   	#if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH) //xuehui ye
	if(MSDC2_Blk[sel].send_ilm || sel == SD_MSDC2_CARD1) //SD_SIM)
	#else
	if(MSDC2_Blk[sel].send_ilm)
	#endif
	{
		ilm_struct *msdc_ilm;
		msdc_card_detect_ind_struct *local;

		local = (msdc_card_detect_ind_struct*)
				   construct_local_para(sizeof(msdc_card_detect_ind_struct), TD_CTRL);	   
		local->media_size = 1;
		local->media_index = sel;
		#if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
		local->media_size = 1;
		local->media_status=MSDC2_Blk[sel].mIsPresent;
		local->media_array_size=sizeof(MSDC2_Blk[sel]);
		local->media_index = 1;
		#endif
		#if defined(__MSDC2_SD_MMC__) || defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH) //xuehui ye
		local->media_array = &MSDC2_Blk[sel];
		#else
		local->media_array = &MSDC2_Blk[0];
		#endif	   
		if(kal_if_hisr()){
	   		msdc_ilm = allocate_ilm(MOD_DRV_HISR);
	   		msdc_ilm->src_mod_id = MOD_DRV_HISR;
		}
		else{
			module_id = stack_int_get_active_module_id();
			msdc_ilm = allocate_ilm(module_id);
			msdc_ilm->src_mod_id = module_id;
			kal_print("[MSDC]msg send in task");
		}
		
		#if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH) //xuehui ye
		if(sel == SD_MSDC2_CARD1)
		{
			//msdc_ilm->msg_id = MSG_ID_MSDC_CARD_DETECT_IND;
			msdc_ilm->msg_id = (msg_type)msg_id;
			MSDC2_Blk[sel].send_ilm = KAL_FALSE;
		}
		else
		{
			//msdc_ilm->msg_id = MSG_ID_SIM_PLUS_DETECT_IND;
			msdc_ilm->msg_id = (msg_type)msg_id;
		}
		#else
		//msdc_ilm->msg_id = MSG_ID_MSDC_CARD_DETECT_IND;
		msdc_ilm->msg_id = (msg_type)msg_id;
		MSDC2_Blk[sel].send_ilm = KAL_FALSE;
		#endif
		
		msdc_ilm->sap_id = DRIVER_PS_SAP;
		msdc_ilm->local_para_ptr = (local_para_struct *)local;
		msdc_ilm->peer_buff_ptr = NULL;
		msdc_ilm->dest_mod_id = dest_id;
		msg_send_ext_queue(msdc_ilm);

	    if (msg_id == MSG_ID_MSDC_CARD_DISPLAY_IND)
	        MSDC2_Blk[sel].send_ilm = KAL_TRUE;
	    else
	        MSDC2_Blk[sel].send_ilm = KAL_FALSE;		
	}
}


kal_bool MSDC2_GetMediaChanged(sd_select_enum sel)
{	
	kal_bool ret;

	ENTER_CRITICAL();
	ret = (MSDC2_Blk[sel].mIsChanged )?(KAL_TRUE):(KAL_FALSE);
	MSDC2_Blk[sel].mIsChanged = KAL_FALSE;	
	EXIT_CRITICAL();
		
	return ret; 
}

void MSDC2_InvertN(kal_uint8 *dest, kal_uint8 *src, kal_uint8 len)
{
	int i;
	for(i=0; i<len; i++)
		*(dest+len-1-i) = *(src+i);
	
}

void  MSDC2_IOInit(){
	// set the output driving capability from customization interface
	MSDC_SetData32(
		MSDC_IOCON2,
		MSDC_IOCON_ODCCFG0|MSDC_IOCON_ODCCFG1|MSDC_IOCON_SCRCFG0|MSDC_IOCON_SCRCFG1,
		MSDC2_GetIOCtrlParam()
		);
	MSDC_SetBits32(MSDC_IOCON2, MSDC_IOCON_SAMPON|MSDC_IOCON_CMDSEL);
	MSDC_SetData32(MSDC_IOCON2, MSDC_IOCON_SAMPLEDLY, 1 << 24);
	gMSDC2_Handle->ins_level = MSDC_IOCTRL_PULL_UP;
	//Set pull up to 47K
	//move this from SD_Initialize, to prevent currents leaking without T-card.
	MSDC_WriteReg32(MSDC_IOCON21, MSDC_IOCON1_ALL_PULLUP_47K);
	
}


MSDC2_InitializeSwitchGpio()
{
#if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
    DCL_HANDLE handle;
	#if !defined(__CUST_NEW__)
	GPIO_LDO_SWITCH = MSDC_GetLDO_GPIO();
	GPIO_EXT_SD_LDO_SWITCH = MSDC_GetEXTLDO_GPIO();
	GPIO_SIM_MSDC_SWITCH = MSDC_GetSwitch_GPIO();
	#endif
	//GPIO_ModeSetup(GPIO_SIM_MSDC_SWITCH, 0); // gpio mode (replaced by DCL)
		handle = DclGPIO_Open(DCL_GPIO,GPIO_SIM_MSDC_SWITCH);
		DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
		DclGPIO_Close(handle);
	//GPIO_InitIO(OUTPUT, GPIO_SIM_MSDC_SWITCH); // replaced by DCL
		handle = DclGPIO_Open(DCL_GPIO,GPIO_SIM_MSDC_SWITCH);
		DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
		DclGPIO_Close(handle);
	/*bewlow comes after JRD SIM+ issue on 2007_03_08, use custom setting instead of fix value*/
	//GPIO_WriteIO(MSDC_GetSwitchDirection(), GPIO_SIM_MSDC_SWITCH); // replaced by DCL
		handle = DclGPIO_Open(DCL_GPIO,GPIO_SIM_MSDC_SWITCH);
		if(0==MSDC_GetSwitchDirection())
			DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
		else if(1==MSDC_GetSwitchDirection())
			DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
		else
		{
			DclGPIO_Close(handle);
			ASSERT(0);
		}
		DclGPIO_Close(handle);
	/*end of changes of JRD SIM+ issue on 2007_03_08*/
#endif
}


#ifdef __MSDC2_CD_EINT__
kal_bool EINT_DefaultPolarity2 = KAL_FALSE;

void EINT_Callback2(void)
{

	#ifdef __MSDC2_CD_EINT__
		drv_trace4(TRACE_GROUP_6, MSDC_INFORM_HOTPLUG, gMSDC2_Handle->msdc_int, cardDetectionEINTPolarity2, gMSDC2_Handle->mIsPresent, drv_get_current_time());

    //
    // To-do how to check it is EINT int.
    //
  
        EINT_Mask(MSDC2_EINT_NO);
		
        if (EINT_DefaultPolarity2 == KAL_FALSE) {
            gMSDC2_Handle->mIsPresent = ((cardDetectionEINTPolarity2) ? KAL_FALSE : KAL_TRUE);
        }
        else {
            gMSDC2_Handle->mIsPresent = ((cardDetectionEINTPolarity2) ? KAL_TRUE : KAL_FALSE);		
        }		
		//cardDetectionEINTPolarity = gMSDC2_Handle->mIsPresent;
        cardDetectionEINTPolarity = ((cardDetectionEINTPolarity2) ? KAL_FALSE : KAL_TRUE); 
        EINT_Set_Polarity(MSDC2_EINT_NO, cardDetectionEINTPolarity2);
        EINT_UnMask(MSDC2_EINT_NO); 

		#endif	
		
		
		if(KAL_FALSE == gMSDC2_Handle->mIsPresent){
       		gMSDC2_Handle->MSDC_everPlugOut = KAL_TRUE;
			MSDC2_CLR_FIFO();
			MSDC2_CLR_INT();
			DMA_Stop(gMSDC2_Handle->msdc_dmaport);		
      		MSDC2_turnOnVMC(KAL_FALSE);
		}	
		else {
		    #if !defined(MT6250) && !defined(MSDC_SD_BITS4_BUS)
		    MSDC2_SendCardInd(MOD_MMI, SD_MSDC2_CARD1, MSG_ID_MSDC_CARD_DISPLAY_IND);
		    #endif   
		}

			#if !defined(FMT_NOT_PRESENT)
		if (gMSDC2_Handle->msdc_custom_handle.IsCardInd)
		{
			if (gMSDC2_Handle->msdc_custom_handle.IsCardInd())
				MSDC2_SendCardInd(MOD_FMT, SD_MSDC2_CARD1, MSG_ID_MSDC_CARD_DETECT_IND);
		}
		else
		{
			MSDC2_SendCardInd(MOD_FMT, SD_MSDC2_CARD1, MSG_ID_MSDC_CARD_DETECT_IND);
		}
			#endif//!defined(FMT_NOT_PRESENT)
			
			
			if(KAL_FALSE == gMSDC2_Handle->mIsPresent){
       		gMSDC2_Handle->MSDC_everPlugOut = KAL_TRUE;
			MSDC2_CLR_FIFO();
			MSDC2_CLR_INT();
			DMA_Stop(gMSDC2_Handle->msdc_dmaport);		
      		MSDC2_turnOnVMC(KAL_FALSE);
		}	
		else {
		    #if !defined(MT6250) && !defined(MSDC_SD_BITS4_BUS)
		    MSDC2_SendCardInd(MOD_MMI, SD_MSDC2_CARD1, MSG_ID_MSDC_CARD_DISPLAY_IND);
		    #endif   
		}

			#if !defined(FMT_NOT_PRESENT)
		if (gMSDC2_Handle->msdc_custom_handle.IsCardInd)
		{
			if (gMSDC2_Handle->msdc_custom_handle.IsCardInd())
				MSDC_SendCardInd(MOD_FMT, SD_MSDC2_CARD1, MSG_ID_MSDC_CARD_DETECT_IND);
		}
		else
		{
			MSDC2_SendCardInd(MOD_FMT, SD_MSDC2_CARD1, MSG_ID_MSDC_CARD_DETECT_IND);
		}
			#endif//!defined(FMT_NOT_PRESENT)
}
void MSDC2_EINT_Registration()
{
    cardDetectionEINTPolarity2 = EINT_DefaultPolarity2; 
    MSDC2_debounceTime = 50;

    EINT_Mask(MSDC2_EINT_NO);
    EINT_Registration(MSDC2_EINT_NO, KAL_TRUE, cardDetectionEINTPolarity2, EINT_Callback2, KAL_TRUE); //PMU_CHR_EINT_PIN=8
    EINT_SW_Debounce_Modify(MSDC2_EINT_NO, MSDC2_debounceTime);    // 32768Hz
    EINT_UnMask(MSDC2_EINT_NO);

}
#endif


extern kal_semid dualMsdc2Arb;
#if 0
#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
/* under construction !*/
/* under construction !*/
#endif
#endif
void MSDC2_Initialize(void)
{
    #if defined(MT6255)
    //
    // 6255E1 clock has four sources: /5.5, /6, /7, /8.
    // 6255E2 or later has differ four sources: /4.5, /5.5, /6, /7
    //
    switch (INT_SW_SecVersion()) {
        
        // 6255_E1
        case SW_SEC_0: {
            gMsdc2ClksrcRate[0] = 75600; // 416/5.5
            gMsdc2ClksrcRate[1] = 69300; // 416/6
            gMsdc2ClksrcRate[2] = 59400; // 416/7
            gMsdc2ClksrcRate[3] = 52000; // 416/8
        } break;
                
        // 6255_E2,E3,E4 or later
        default: {
            gMsdc2ClksrcRate[0] = 92400; // 416/4.5
            gMsdc2ClksrcRate[1] = 75600; // 416/5.5
            gMsdc2ClksrcRate[2] = 69300; // 416/6
            gMsdc2ClksrcRate[3] = 59400; // 416/7     
        } break;
                                 
    };        
    #endif
   if (gMSDC2_Handle->mIsInitMSDC)
      return;

   kal_mem_set(gSD2,0,sizeof(T_SDC_HANDLE));

   #if defined(MT6276)
      DRV_SetBits(WPLL_CON0, 0x80);	// WPLL_CON0: bit MSDC_CLK_EN
   #elif defined(MT6256) || defined(MT6255)
   #if defined(MSDC_TEST_MSDC1_FROM_MSDC2_CODE)
      DRV_SetBits((PLL_base+0x0104), 0x8040);
   #else
      DRV_SetBits((PLL_base+0x0104), 0x8080);
   #endif
   #endif


#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
		MSDC_Switch_init();
		MSDC2_Blk[SD_SDIO].setting_MSDC_CFG = 0x15a00021;
		MSDC2_Blk[SD_SDIO].setting_MSDC_IOCON = 0x010002d2;
		MSDC2_Blk[SD_SDIO].setting_SDC_CFG = 0x28038200;
		MSDC2_Blk[SD_SDIO].mMSDC_type = SD_CARD;
		MSDC2_Blk[SD_SDIO].mIsPresent = KAL_TRUE;
		/*SD card will be used in very early state, change to SD card first*/
		MSDC_Switch(0);
#endif
#if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH) 
dualMsdc2Arb = kal_create_sem("MSDC2_lock", 1);
#endif

#ifdef DRV_MSDC_4_BYTE_BURST
	MSDC2_useDMA4ByteBurst = KAL_TRUE;
#endif

	// turn on the power of controler
	MSDC2_PDNControl(KAL_FALSE);
		
	gMSDC2_Handle->msdc_clock = MSDC_CLOCK;

	if(gMSDC2_Handle->gpt_handle == 0)
		MSDC2_GPTI_GetHandle(&gMSDC2_Handle->gpt_handle);

	if (gMSDC2_Handle->msdc_custom_handle.Init)
		gMSDC2_Handle->msdc_custom_handle.Init();

	MSDC_SetBits32(MSDC_CFG2, MSDC_CFG_MSDC|MSDC_CFG_PINEN);
	MSDC2_IOInit();
	/*busy loop to wait msdc controller recharge*/
	MSDC2_BusyWait_ms(1);


#ifdef __CARD_DOWNLOAD__

    if (MSDC2_QueryIsPowerControllable())
        MSDC2_SetPower(KAL_TRUE);
#endif//__CARD_DOWNLOAD__

	MSDC2_SET_FIFO(1);

	
#ifdef DRV_MSDC2_SHARE_BY_SWITCH
	MSDC2_InitializeSwitchGpio();
#endif

	
#ifdef DRV_MSDC2_DUAL_TCARD_BY_SWITCH
	/*2nd T-card always does not support hot plug, so set it present in initialization*/
	MSDC2_Blk[SD_T_CARD_2].mIsPresent = KAL_TRUE;
	MSDC2_Blk[SD_T_CARD_2].mIsChanged = KAL_TRUE;
    current_card2 = SD_MSDC2_CARD1;
#endif
	

	gMSDC2_Handle->mIsPresent = KAL_TRUE; 
	#if !defined(__MSDC2_CD_EINT__)
	MSDC_WriteReg32(MSDC_PS2, MSDC_PS_CDEN|MSDC_PS_PIEN0|MSDC_PS_POEN0);
	#endif
	MSDC2_turnOnVMC(gMSDC2_Handle->mIsPresent);

	#if defined(R1B_INTERRUPT_MODE)
	MSDC2_INT_Init();	
	MSDC2_R1B_Init();
	#endif	// end of MSDC_INT
	#ifdef MSDC_DMA
	MSDC2_DMAInit();
	#endif	


    #ifdef __MSDC2_CD_EINT__
    MSDC2_EINT_Registration();    
    #endif
    	
	#ifdef __MULTI_BOOT__
	if(stack_query_boot_mode() != NORMAL_BOOT)
		gMSDC2_Handle->send_ilm = KAL_FALSE;
	else
		gMSDC2_Handle->send_ilm = KAL_TRUE;
	#else
		gMSDC2_Handle->send_ilm = KAL_FALSE;
	#endif
		
	#ifdef DRV_MSDC_CLK_SEARCH
		gMSDC2_Handle->msdc_clkTuneUpperBund = MSDC_CLOCK/2;
#ifdef DRV_MSDC2_DUAL_TCARD_BY_SWITCH
		MSDC2_Blk[SD_T_CARD_2].msdc_clkTuneUpperBund = MSDC_CLOCK/2;
#endif		
	#endif

#ifdef DRV_MSDC2_DUAL_TCARD_BY_SWITCH

/*we will initialize MSDC setting for card1, but for card 2, we have to init its setting in its context*/
MSDC2_Blk[SD_T_CARD_2].setting_MSDC_CFG =  MSDC_Reg32(MSDC_CFG2); //xuehui change it 0x1;
MSDC2_Blk[SD_T_CARD_2].setting_MSDC_IOCON = MSDC_Reg32(MSDC_IOCON2); //xuehui change it  0x0;
MSDC2_Blk[SD_T_CARD_2].setting_SDC_CFG =  MSDC_Reg32(SDC_CFG2); //xuehui change it 0x0;
MSDC2_Blk[SD_T_CARD_2].mMSDC_type = SD_CARD;
MSDC_WriteReg32(MSDC2_IRQMASK0,0xffffffff);
#endif

    MSDC2_PDNControl(KAL_TRUE);
    gMSDC2_Handle->mIsInitMSDC = KAL_TRUE;
}
#if 0
#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
/* under construction !*/
/* under construction !*/
#endif
#endif

void MSDC2_DeInit(void)
{
    DMA_FreeChannel(gMSDC2_Handle->msdc_dmaport);

    gMSDC2_Handle->mIsInitMSDC = KAL_FALSE;
    
    //
    // Patch for GPIO re-setting after LCDinit in card download flow.
    // After re-setting GPIO, we need to do SD_Initialize again.
    //
    gMSDC2_Handle->mIsInitialized = KAL_FALSE;
}


#ifdef  __TST_WRITE_TO_FILE__
/*error recording: add this function to do MSDC reset when error recording*/
void MSDC2_ErrorRecordingReset(){
	
	if(NULL != gMSDC2_Handle->msdc_dmaport){
			DMA_Stop(gMSDC2_Handle->msdc_dmaport);
	}
//this is a temp soluction for tst write to sd card features.
/*	
	MSDC_ErrorRecordingBlk.gpt_handle = gMSDC2_Handle->gpt_handle;
	MSDC_ErrorRecordingBlk.MSDC_Events = gMSDC2_Handle->MSDC_Events;
	MSDC_ErrorRecordingBlk.msdc_dmaport = gMSDC2_Handle->msdc_dmaport;
	gMSDC2_Handle = &MSDC_ErrorRecordingBlk;
	MSDC_Initialize();
*/	
   memcpy(&MSDC2_ErrorRecordingBlk,gMSDC2_Handle,sizeof(MSDC2_ErrorRecordingBlk));
}
#endif



void BitFieldWrite32_2(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask)
{
	kal_uint8 bit_pos;
	kal_uint32 tmp;
	
	bit_pos = 0;
	tmp = MSDC_Reg32(dest);
	// get bit positoin
	while(!((mask >> bit_pos++) & 1));	
	//use mask clear the corresponding area	
	tmp &= ~mask;
	//shift src to the corresponding positiion
	src <<= (bit_pos - 1);
	//copy src into destination	
	tmp |= src;
	MSDC_WriteReg32(dest, tmp);
}


/*************************************************************************
* FUNCTION
*  BitFieldRead32_2
*
* DESCRIPTION
*	read src to dest at mask position
*
* PARAMETERS
*	dest: destination to store
*	src: value to be written
*	mask: bit mask
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/

// Note: mask must ve continuous area during 32 bits.eg, 
// src : 00A3BF00, mask : 00FF0000
// after BitFieldRead, dest : A3
void BitFieldRead32_2(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask)
{
	kal_uint8 bit_pos = 0;
	
	while(!((mask >> bit_pos++) & 1));
	src &= mask;
	*(kal_uint32 *)dest = src >> (bit_pos - 1);
}


// get the bit field value of start_bit with width bits
// note 1) start_bit start from bit 0
//		2) prepare dest with initialized with zeros
//		3) width must less than 32 if using the retrun value as a result
// eg,
// src:00110110, start_bit:2,width:3 => dest:101 
void GetBitFieldN_2(kal_uint8* dest, kal_uint8* src, kal_uint16 start_bit, kal_uint16 width)
{
	int i;
	kal_uint16 bytes, bits;

	//kal_mem_set(dest,0,width/8+1);
	kal_mem_set(dest, 0, (width/8) + (0 == (width%8) ? 0:1));
	for( i = 0; i < width; i++)
	{	
		bytes = (start_bit+i)/8;
		bits  = (start_bit+i)%8;		
		*(dest+i/8) |= (kal_uint8)(((*(src+bytes) >> bits) & 1) << (i%8));		
	}

	/*in MT6238, address of kal_uint32 is checked strictly, and we don't need the return value of this function*/
	/*change it's return type to void*/
	return ;
}

void MSDC2_SetLatchTuning(void)
{
	if (gMSDC2_Handle->op_clock < MSDC_OP_CLOCK)
	{
		// feedback clock from pad is used to latch data from card
		BitFieldWrite32_2((kal_uint32*)MSDC2_CLKACB_CFG, 0, MSDC_CLKACB_CFG_CLK_LATCH);
		return;
	}
	// DIV 8
	BitFieldWrite32_2((kal_uint32*)MSDC_CFG2, 2, MSDC_CFG_SCLKF);
	// DIV 5
	BitFieldWrite32_2((kal_uint32*)MSDC_CFG2, 3, MSDC_CFG_CLKSRC);
	// feedback clock from pad is used to latch data from card
	BitFieldWrite32_2((kal_uint32*)MSDC2_CLKACB_CFG, 0, MSDC_CLKACB_CFG_CLK_LATCH);
}

#ifdef MSDC_DMA 
extern kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE);
#if 0
#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
/* under construction !*/
/* under construction !*/
#endif
#endif
/*************************************************************************
* FUNCTION
*  MSDC_DMAInit
*
* DESCRIPTION
*	Initialize MSDC's DMA
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC2_DMAInit(void)
{

#ifndef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
#ifdef  __TST_WRITE_TO_FILE__
	/*error recording: it mens this functions is called twice, just skip*/
	if(KAL_FALSE == INT_QueryExceptionStatus())
#endif	
	#if defined(MT6250)
	//
	// MT6250E1. DMA bug needs sw workaround.
	//
	if (INT_SW_SecVersion() == SW_SEC_0)
		gMSDC2_Handle->msdc_dmaport = DMA_FullSize_GetChannel(DMA_SW);
	else
    #endif
		gMSDC2_Handle->msdc_dmaport = DMA_GetChannel(DMA_MSDC2);	

#else
	gMSDC2_Handle->msdc_dmaport = DMA_GetChannel(DMA_MSDC);
#endif

/*
	gMSDC2_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
	gMSDC2_Handle->msdc_menu.TMOD.cycle = 0x4;

#ifndef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
	gMSDC2_Handle->msdc_menu.master = DMA_MSDC;
#else
	gMSDC2_Handle->msdc_menu.master = DMA_MSDC2;
#endif
*/

	#if defined(MT6250)
	//
	// MT6250E1. DMA bug needs sw workaround.
	//	
	if (INT_SW_SecVersion() == SW_SEC_0) {
		gMSDC2_Handle->full_menu.source = 0;
		gMSDC2_Handle->full_menu.destination = 0;
        gMSDC2_Handle->full_menu.TMOD.burst_mode = KAL_TRUE;
        gMSDC2_Handle->full_menu.TMOD.cycle = 0x4;
    
        #ifndef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
        gMSDC2_Handle->full_menu.master = DMA_MSDC2;
        #else
        gMSDC2_Handle->full_menu.master = DMA_MSDC;
        #endif

        gMSDC2_Handle->msdc_input.menu = &gMSDC2_Handle->full_menu;
        
	}
	else 
    #endif
    {
		gMSDC2_Handle->msdc_menu.addr = NULL;			
	gMSDC2_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
	gMSDC2_Handle->msdc_menu.TMOD.cycle = 0x4;
    
#ifndef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
	gMSDC2_Handle->msdc_menu.master = DMA_MSDC2;
#else
	gMSDC2_Handle->msdc_menu.master = DMA_MSDC;
#endif

        gMSDC2_Handle->msdc_input.menu = &gMSDC2_Handle->msdc_menu;
    }

	gMSDC2_Handle->msdc_input.type = DMA_HWRX;
	gMSDC2_Handle->msdc_input.size = DMA_LONG;
	gMSDC2_Handle->msdc_input.count = 0;



#if defined(DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH)
	MSDC2_Blk[SD_SDIO].msdc_dmaport = MSDC2_Blk[SD_MSDC2_CARD1].msdc_dmaport;
	MSDC2_Blk[SD_SDIO].msdc_menu.TMOD.burst_mode = KAL_TRUE;
	MSDC2_Blk[SD_SDIO].msdc_menu.TMOD.cycle = 0x4;
	MSDC2_Blk[SD_SDIO].msdc_menu.master = DMA_MSDC;
	MSDC2_Blk[SD_SDIO].msdc_menu.addr = NULL;

	MSDC2_Blk[SD_SDIO].msdc_input.type = DMA_HWRX;
	MSDC2_Blk[SD_SDIO].msdc_input.size = DMA_LONG;
	MSDC2_Blk[SD_SDIO].msdc_input.count = 0;
	MSDC2_Blk[SD_SDIO].msdc_input.menu = &MSDC2_Blk[SD_SDIO].msdc_menu;
	//MSDC2_Blk[SD_SIM].msdc_menu = MSDC2_Blk[SD_MSDC2_CARD1].msdc_menu;
	//MSDC2_Blk[SD_SIM].msdc_input = MSDC2_Blk[SD_MSDC2_CARD1].msdc_input	;
#elif defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
	MSDC2_Blk[SD_T_CARD_2].msdc_dmaport = MSDC2_Blk[SD_MSDC2_CARD1].msdc_dmaport;
	MSDC2_Blk[SD_T_CARD_2].msdc_menu.TMOD.burst_mode = KAL_TRUE;
	MSDC2_Blk[SD_T_CARD_2].msdc_menu.TMOD.cycle = 0x4;
	MSDC2_Blk[SD_T_CARD_2].msdc_menu.master = DMA_MSDC;
	MSDC2_Blk[SD_T_CARD_2].msdc_menu.addr = NULL;

	MSDC2_Blk[SD_T_CARD_2].msdc_input.type = DMA_HWRX;
	MSDC2_Blk[SD_T_CARD_2].msdc_input.size = DMA_LONG;
	MSDC2_Blk[SD_T_CARD_2].msdc_input.count = 0;
	MSDC2_Blk[SD_T_CARD_2].msdc_input.menu = &MSDC2_Blk[SD_T_CARD_2].msdc_menu;
	//MSDC2_Blk[SD_SIM].msdc_menu = MSDC2_Blk[SD_MSDC2_CARD1].msdc_menu;
	//MSDC2_Blk[SD_SIM].msdc_input = MSDC2_Blk[SD_MSDC2_CARD1].msdc_input	;
#endif

    #if defined(MSDC_START_DMA_IN_CALLBACK)
    gMSDC2_Handle->msdc_uncachedBufs[0]=&msdc_uncachedBuf2[0];
    gMSDC2_Handle->msdc_uncachedBufs[1]=&msdc_uncachedBuf2[MSDC_UNCACHED_BUF_SIZE/4/2];
    #endif
	//msdc_input.callback = MSDC_DMA_Callback;	
}
#if 0
#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
/* under construction !*/
/* under construction !*/
#endif
#endif
/************************************************************************
* FUNCTION
*  MSDC_DMATransferFinal_In_Callback
*
* DESCRIPTION
*	Initialize MSDC's DMA
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
#if defined(MSDC_START_DMA_IN_CALLBACK)

void MSDC2_DMATransferFinal_In_Callback(void)
{

    #ifdef MSDC_CACHED_SUPPORT
    kal_uint32  msdc_input_prev=0;
    kal_uint32  msdc_input_next=gMSDC2_Handle->msdc_input_next;
    #endif
	kal_uint32 total_count = gMSDC2_Handle->total_count;
	kal_bool is_aligned = gMSDC2_Handle->is_aligned;
	
	#if defined(MT6250)
	SW_SECVERSION sw_version=INT_SW_SecVersion();
	#endif

	MSDC2_STOP_TIMER();

    total_count -= gMSDC2_Handle->msdc_input.count;
	
    gMSDC2_Handle->total_count = total_count;
	if ( total_count==0 ) {
		kal_set_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_DMAIRQ,KAL_OR);
		return;
    }

	/*copy data here if we need to do further transfer*/
    #ifdef MSDC_CACHED_SUPPORT
        if(KAL_TRUE == gMSDC2_Handle->isCachedBuf){
    	    //have do memory copy stuff here
    	    if (DMA_HWTX == gMSDC2_Handle->msdc_input.type )  {
        		kal_mem_cpy(msdc_uncachedBuf2, (void *)gMSDC2_Handle->cachedBufCopyPtr, 4 * msdc_input_next);
        		msdc_input_prev=4 * msdc_input_next;
        		//dbg_print("NC write copy %d\n\r", msdc_input_next);
    	    } else  
            if (DMA_HWRX == gMSDC2_Handle->msdc_input.type ) {
                gMSDC2_Handle->msdc_uncachedBufs_idx^=1;
                msdc_input_prev = 4 * gMSDC2_Handle->msdc_input.count;
     #if defined(MT6250)
                if (SW_SEC_0 == sw_version)
    		        gMSDC2_Handle->full_menu.destination = (kal_uint32)gMSDC2_Handle->msdc_uncachedBufs[gMSDC2_Handle->msdc_uncachedBufs_idx];
                else
     #endif
                gMSDC2_Handle->msdc_menu.addr = (kal_uint32)gMSDC2_Handle->msdc_uncachedBufs[gMSDC2_Handle->msdc_uncachedBufs_idx];
            }
        }
    #endif

	if(is_aligned)
	{
        gMSDC2_Handle->msdc_input.count = msdc_input_next;

        #if defined(__DRV_MSDC_FAST_FORMAT__) && defined(__DMA_API_V2__)
	        if ((KAL_TRUE == gMSDC2_Handle->MSDC_fastFormat) && (gMSDC2_Handle->mIsInitialized==KAL_TRUE))
                gMSDC2_Handle->msdc_menu.addr = 0; // DMA FIX_PATTERN = 0;
        #endif

        #if defined(MT6250)
		if (sw_version == SW_SEC_0)
			DMA_FullSize_Config(gMSDC2_Handle->msdc_dmaport,&gMSDC2_Handle->msdc_input,KAL_TRUE);
        else
        #endif
		    DMA_Config_B2W(gMSDC2_Handle->msdc_dmaport,&gMSDC2_Handle->msdc_input,KAL_TRUE,KAL_FALSE);

        #if defined(__DRV_MSDC_FAST_FORMAT__) && !defined(__DMA_API_V2__)
		    if ((KAL_TRUE == gMSDC2_Handle->MSDC_fastFormat) && (gMSDC2_Handle->mIsInitialized==KAL_TRUE))
			{
				MSDC_ClearBits32(DMA_CON(gMSDC2_Handle->msdc_dmaport), DMA_CON_SINC);
			}
			else
        #endif
			{
                #ifdef MSDC_CACHED_SUPPORT
				/*we don't need to increase the addr when encounter cached buffer, since we only have a fix size uncached buffer to use*/
				if(KAL_FALSE == gMSDC2_Handle->isCachedBuf)
                #endif
			    {
				    gMSDC2_Handle->msdc_menu.addr += gMSDC2_Handle->msdc_input.count*4;
			    }
		    }
	}
	else
	{ //not aligned
        #ifdef MSDC_CACHED_SUPPORT
			if(KAL_TRUE == gMSDC2_Handle->isCachedBuf)
				ASSERT(0);
        #endif

        #if defined(__DRV_MSDC_FAST_FORMAT__) && defined(__DMA_API_V2__)
	    if ((KAL_TRUE == gMSDC2_Handle->MSDC_fastFormat) && (gMSDC2_Handle->mIsInitialized==KAL_TRUE))
            gMSDC2_Handle->msdc_menu.addr = 0; // DMA FIX_PATTERN = 0;
        #endif
        gMSDC2_Handle->msdc_input.count = (total_count > MSDC2_DMA_BURSTLEN_LIMIT)?(MSDC2_DMA_BURSTLEN_LIMIT):(total_count);

        #if defined(MT6250)
		if (sw_version == SW_SEC_0)
			DMA_FullSize_Config(gMSDC2_Handle->msdc_dmaport,&gMSDC2_Handle->msdc_input,KAL_TRUE);
        else
        #endif
		    DMA_Config_B2W(gMSDC2_Handle->msdc_dmaport,&gMSDC2_Handle->msdc_input,KAL_TRUE,KAL_TRUE);

		gMSDC2_Handle->msdc_menu.addr += gMSDC2_Handle->msdc_input.count;
	}

	gMSDC2_Handle->timeout_period = (50 + (gMSDC2_Handle->msdc_input.count>>5));

	if(gMSDC2_Handle->msdc_input.type == DMA_HWTX)
		gMSDC2_Handle->timeout_period <<= 2 ;
	if(gMSDC2_Handle->mMSDC_type == MMC_CARD)
		gMSDC2_Handle->timeout_period <<= 1;

    if(gMSDC2_Handle->timeout_period > MSDC_TIMEOUT_PERIOD_DAT)
	    gMSDC2_Handle->timeout_period = MSDC_TIMEOUT_PERIOD_DAT;

    #ifdef __DRV_MSDC_FAST_FORMAT__
    	if((KAL_TRUE == gMSDC2_Handle->MSDC_fastFormat) && (gMSDC2_Handle->mIsInitialized==KAL_TRUE))
    		gMSDC2_Handle->timeout_period = gMSDC2_Handle->timeout_period<<3;
    #endif

	MSDC_START_TIMER(gMSDC2_Handle->timeout_period);

    #ifdef MSDC_CACHED_SUPPORT
		if (KAL_TRUE == gMSDC2_Handle->isCachedBuf) {
		    if(DMA_HWTX == gMSDC2_Handle->msdc_input.type)
			    msdc_input_next = ((total_count-msdc_input_next) > MSDC_UNCACHED_TRASNFER_SIZE)?(MSDC_UNCACHED_TRASNFER_SIZE):(total_count-msdc_input_next);
			else
			    msdc_input_next = ((total_count-msdc_input_next) > MSDC_UNCACHED_TRASNFER_SIZE/2)?(MSDC_UNCACHED_TRASNFER_SIZE/2):(total_count-msdc_input_next);
		} else
    #endif
		    msdc_input_next = ((total_count-msdc_input_next) > MSDC2_DMA_BURSTLEN_LIMIT)?(MSDC2_DMA_BURSTLEN_LIMIT):(total_count-msdc_input_next);
        gMSDC2_Handle->msdc_input_next=msdc_input_next;

	/*copy data here if we need to do further transfer*/
    #ifdef MSDC_CACHED_SUPPORT
        if(KAL_TRUE == gMSDC2_Handle->isCachedBuf){
            if(MSDC_UNCACHED_BUF_SIZE < (4 * gMSDC2_Handle->msdc_input.count))
    			ASSERT(0);
    
    	    if (DMA_HWRX == gMSDC2_Handle->msdc_input.type) {
    		    /*copy to upper application's buffer*/
    		    kal_mem_cpy((void *)gMSDC2_Handle->cachedBufCopyPtr, gMSDC2_Handle->msdc_uncachedBufs[gMSDC2_Handle->msdc_uncachedBufs_idx^1], msdc_input_prev);
    		    //dbg_print("NC read copy %d\n\r", msdc_input_prev);
    
    	    }
    	    //Shall be msdc_input_next for TX. However, it does not harm since they can be different only in final DMA segment
    	    gMSDC2_Handle->cachedBufCopyPtr += msdc_input_prev; 
        }
    #endif


}

kal_uint32 MSDC2_DMATransferFinal(void)
{

	kal_uint32 t1;//total_count = gMSDC2_Handle->total_count,
	kal_bool is_poll = gMSDC2_Handle->is_poll;
	//kal_bool is_aligned = gMSDC2_Handle->is_aligned;
	kal_uint32 flags;

	flags = 0;
	flags |=0;
	

	// wait until running bit clr
	if(gMSDC2_Handle->msdc_input.type == DMA_HWTX)
		gMSDC2_Handle->timeout_period <<= 2 ;
	if(gMSDC2_Handle->mMSDC_type == MMC_CARD)
		gMSDC2_Handle->timeout_period <<= 1;

    if(gMSDC2_Handle->timeout_period > MSDC_TIMEOUT_PERIOD_DAT)
	    gMSDC2_Handle->timeout_period = MSDC_TIMEOUT_PERIOD_DAT;

#ifdef __DRV_MSDC_FAST_FORMAT__
	if((KAL_TRUE == gMSDC2_Handle->MSDC_fastFormat) && (gMSDC2_Handle->mIsInitialized==KAL_TRUE))
		gMSDC2_Handle->timeout_period = gMSDC2_Handle->timeout_period<<3;
#endif

	t1 = drv_get_current_time();
	MSDC2_START_TIMER(gMSDC2_Handle->timeout_period);

#ifndef __MEUT__
	drv_trace2(TRACE_GROUP_7, MSDC_EVENTGP_MONITOR, ((EV_GCB *)gMSDC2_Handle->MSDC_Events)->ev_current_events, __LINE__);
#endif
	#if defined(MSDC_TRACE_LEVEL3)
	MSDC_add_dbg_msg(msdc_dbg_event_DMA_RLCT_Monitor, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), MSDC_Reg(DMA_COUNT(gMSDC2_Handle->msdc_dmaport)));
	#endif

	if(is_poll)
	{
		while(IS_MSDC_DMA_RUN(gMSDC2_Handle->msdc_dmaport) && MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
		{
		    SD2_CheckTimeoutWithSleep(t1,  gMSDC2_Handle->timeout_period*11,1);
		}
		#if defined(MSDC_TRACE_LEVEL3)
		MSDC_add_dbg_msg(msdc_dbg_event_SD_transfer_poll_end2, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), 0);
		#endif
		gMSDC2_Handle->total_count-= gMSDC2_Handle->msdc_input.count;
	}
	else
	{
#if defined(__UBL__) || defined(__FUE__)
	    ASSERT(0);
#endif
        
		kal_retrieve_eg_events(gMSDC2_Handle->MSDC_Events,(EVENT_DMAIRQ),KAL_OR_CONSUME,&flags,KAL_SUSPEND);
		#if defined(MSDC_TRACE_LEVEL3)
		MSDC_add_dbg_msg(msdc_dbg_event_SD_transfer_event_retreived2, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), 0);
		#endif
	}
	MSDC2_STOP_TIMER();

#ifndef __MEUT__
	drv_trace2(TRACE_GROUP_7, MSDC_EVENTGP_MONITOR, ((EV_GCB *)gMSDC2_Handle->MSDC_Events)->ev_current_events, __LINE__);
#endif

    if (IS_MSDC_DMA_RUN(gMSDC2_Handle->msdc_dmaport))
        return MSDC_GPT_TIMEOUT_ERR;

    /*copy data here if we need to do further transfer*/
    #ifdef MSDC_CACHED_SUPPORT
    	if(KAL_TRUE == gMSDC2_Handle->isCachedBuf){
    		if(DMA_HWRX == gMSDC2_Handle->msdc_input.type){
    			//copy to upper application's buffer
    			if(MSDC_UNCACHED_BUF_SIZE < (4 * gMSDC2_Handle->msdc_input.count))
    				ASSERT(0);
    			kal_mem_cpy((void *)gMSDC2_Handle->cachedBufCopyPtr, gMSDC2_Handle->msdc_uncachedBufs[gMSDC2_Handle->msdc_uncachedBufs_idx], 4 * gMSDC2_Handle->msdc_input.count);
    		}
    	}
    #endif

    //if (gMSDC2_Handle->total_count == 0) return MSDC_NOERROR;

	return MSDC_NOERROR; //FIX ME
}
#endif

/************************************************************************
* FUNCTION
*  MSDC_StartDMAUpdateAddr
*
* DESCRIPTION
*	This function used to start DMA, and update the buffer address.
*     Pay attention to the sequence of update count, start DMA, update buffer address. 
*     In one DMA tranfer loop : 
*     count:  update count -> start DMA -> use the count do memory copy for cacheable buffer
*     addr:   assign original addr in MSDC_DMATransferFirst -> start DMA ->update addr for next transfer
* PARAMETERS
*     
* RETURNS
*
* GLOBALS AFFECTED
*    The global varible blow may be changed:
*    gMSDC2_Handle->msdc_menu.addr
*************************************************************************/
void MSDC2_StartDMAUpdateAddr(){

	//start DMA
#if defined(MT6250)
		if (INT_SW_SecVersion() == SW_SEC_0)
		DMA_FullSize_Config(gMSDC2_Handle->msdc_dmaport,&gMSDC2_Handle->msdc_input,KAL_TRUE);
		else                
#endif
		DMA_Config_B2W(gMSDC2_Handle->msdc_dmaport,&gMSDC2_Handle->msdc_input,KAL_TRUE,gMSDC2_Handle->isDMA_B2W);

//update address for next time
//address for first time is assigned in MSDC_DMATransferFirst
#ifdef MSDC_CACHED_SUPPORT
	 if(KAL_TRUE == gMSDC2_Handle->isCachedBuf)//address is fixed for cacheable
	 {;}else
#endif
	if(DMA_LONG == gMSDC2_Handle->msdc_input.size){
		gMSDC2_Handle->msdc_menu.addr += gMSDC2_Handle->msdc_input.count*4;
	}else if(DMA_BYTE == gMSDC2_Handle->msdc_input.size){
		gMSDC2_Handle->msdc_menu.addr += gMSDC2_Handle->msdc_input.count;
	}
#if defined(__DRV_MSDC_FAST_FORMAT__) && defined(__DMA_API_V2__)
	if ((KAL_TRUE == gMSDC2_Handle->MSDC_fastFormat) && (gMSDC2_Handle->mIsInitialized==KAL_TRUE)){
		gMSDC2_Handle->msdc_menu.addr = 0;
		MSDC_ClearBits32(DMA_CON(gMSDC2_Handle->msdc_dmaport), DMA_CON_SINC);
	}
#endif

}
/*************************************************************************
* FUNCTION
*  MSDC_DMATransfer
*
* DESCRIPTION
*	MSDC using DAM for data transfer 
*
* PARAMETERS
*	adrs: data buffer
*	count: bytes to be transfered
*	isTx: ture for move data from MSDC to data buffer and vise versa
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC2_DMATransferFirst(kal_uint32 adrs,kal_uint32 count, kal_bool isTx)
{

	kal_uint32 total_count;
	kal_bool is_aligned, is_poll;
	#if defined(MSDC_START_DMA_IN_CALLBACK)
	kal_uint32 msdc_input_next;
	#endif
	
	#if defined(MT6250)
	SW_SECVERSION sw_version=INT_SW_SecVersion();
	#endif
#if defined(__UBL__) || defined(__FUE__)
	//ASSERT(0);
#endif

	DMA_Stop(gMSDC2_Handle->msdc_dmaport);	
  kal_set_eg_events(gMSDC2_Handle->MSDC_Events,0,KAL_AND);
#ifdef MSDC_CACHED_SUPPORT
	if (KAL_TRUE == gMSDC2_Handle->isCachedBuf){
	    //BEGIN Light 120907
	    #if defined(MSDC_START_DMA_IN_CALLBACK)
	    //msdc_uncachedBufs_idx=0;
	    //msdc_uncachedBuf=gMSDC2_Handle->msdc_uncachedBufs[0];
	    gMSDC2_Handle->msdc_uncachedBufs_idx=0;//It should be initialized before starting DMA(will be used in DMA callback)
	    #endif
		
		#if defined(MT6250)
		// MT6250E1. DMA bug needs sw workaround.
		if (sw_version == SW_SEC_0) {
			if (isTx) {
				gMSDC2_Handle->full_menu.source = (kal_uint32)msdc_uncachedBuf2;
				gMSDC2_Handle->full_menu.destination = MSDC_DAT2;
			} else {
				gMSDC2_Handle->full_menu.source = MSDC_DAT2;
				gMSDC2_Handle->full_menu.destination = (kal_uint32)msdc_uncachedBuf2;
			}		
		}
		else 
        #endif
			gMSDC2_Handle->msdc_menu.addr = (kal_uint32)msdc_uncachedBuf2;
        
		gMSDC2_Handle->cachedBufCopyPtr = adrs;
		#if defined(MT6250)
        if (sw_version == SW_SEC_0)
		adrs = (kal_uint32)msdc_uncachedBuf2;
		#endif
	}
	else
#endif
	{
		#if defined(MT6250)    
        if (sw_version == SW_SEC_0) {
    		if (isTx) {
    			gMSDC2_Handle->full_menu.source = adrs;
    			gMSDC2_Handle->full_menu.destination = MSDC_DAT2;
    		} else {
    			gMSDC2_Handle->full_menu.source = MSDC_DAT2;
    			gMSDC2_Handle->full_menu.destination = adrs;
    		}			
        }
        else 
        #endif
            gMSDC2_Handle->msdc_menu.addr = adrs;

	}
	
	if(isTx)
	{
		gMSDC2_Handle->timeout_period = (50 + (count>>5));
		gMSDC2_Handle->msdc_input.type = DMA_HWTX;
#if defined(__UBL__) || defined(__FUE__)
		{
			gMSDC2_Handle->msdc_input.callback = NULL;
			is_poll = KAL_TRUE;
		}
#else//defined(__UBL__) || defined(__FUE__)
		if(count <= MSDC_WRITE_THD_POLL)
		//if(0)
		{
			gMSDC2_Handle->msdc_input.callback = NULL;
			is_poll = KAL_TRUE;			
		}
		else
		{
			gMSDC2_Handle->msdc_input.callback = MSDC2_DMA_Callback;
			is_poll = KAL_FALSE;
		}
#endif//defined(__UBL__) || defined(__FUE__)
	}
	else
	{
		gMSDC2_Handle->timeout_period = (50 + (count>>7));
		gMSDC2_Handle->msdc_input.type = DMA_HWRX;
#if defined(__UBL__) || defined(__FUE__)
		{
			gMSDC2_Handle->msdc_input.callback = NULL;
			is_poll = KAL_TRUE;
		}
#else//defined(__UBL__) || defined(__FUE__)
		if(count <= MSDC_READ_THD_POLL)
		//if(0)
		{
			gMSDC2_Handle->msdc_input.callback = NULL;
			is_poll = KAL_TRUE;
		}
		else
		{
			gMSDC2_Handle->msdc_input.callback = MSDC2_DMA_Callback;
			is_poll = KAL_FALSE;
		}
#endif//defined(__UBL__) || defined(__FUE__)
	}

	if(kal_query_systemInit() == KAL_TRUE 
#ifdef  __TST_WRITE_TO_FILE__	/*error recording: considering error recording additionally*/
		|| (KAL_TRUE == INT_QueryExceptionStatus())
#endif
		|| (KAL_TRUE == FTL_isPollingMode())
	)
	{
		gMSDC2_Handle->msdc_input.callback = NULL;
		is_poll = KAL_TRUE;
	}
//	drv_trace2(TRACE_GROUP_6, MSDC_INFORM_DMA_TRANSFER_CACHED_WRITE, 0, 0);
    #if defined(MSDC_START_DMA_IN_CALLBACK)
    //Since no user claim to use cacheable buffer, use this check to verify if any user still use cacheable buffer
    if (KAL_TRUE == gMSDC2_Handle->isCachedBuf) {
		kal_uint32 owner;
		owner |=0;
        if(isTx) {
            if (count>MSDC_WRITE_THD_POLL)
         //  if (count>=1)
            	{
            		owner = (kal_uint32)kal_get_current_thread_ID();
					//dbg_print("count>MSDC_WRITE_THD_POLL,count=%d,threadID=%d",count,owner);
					drv_trace2(TRACE_GROUP_6, MSDC_INFORM_DMA_TRANSFER_CACHED_WRITE, count, owner);
					//drv_trace2(TRACE_GROUP_6, MSDC_INFORM_DMA_TRANSFER_CACHED_WRITE, total_count, owner);
                }
        } else {
            if (count>MSDC_READ_THD_POLL)
			//	if (count>=1)
                {
            		owner = (kal_uint32)kal_get_current_thread_ID();
					//dbg_print("count>MSDC_READ_THD_POLL,count=%d,threadID=%d",count,owner);
					drv_trace2(TRACE_GROUP_6, MSDC_INFORM_DMA_TRANSFER_CACHED_READ, count, owner);
					//drv_trace2(TRACE_GROUP_6, MSDC_INFORM_DMA_TRANSFER_CACHED_READ, total_count, owner);
                }
        }
    }
    #endif

#ifndef MSDC_CACHED_SUPPORT
	if(adrs%4 == 0)
	{
		is_aligned = KAL_TRUE;
		total_count = count;
	}
	else
	{
		is_aligned = KAL_FALSE;
		total_count = count<<2;
	}
#else
	if(adrs%4 == 0 || KAL_TRUE == gMSDC2_Handle->isCachedBuf)
	{
		is_aligned = KAL_TRUE;
		total_count = count;
	}
	else
	{
		is_aligned = KAL_FALSE;
		total_count = count<<2;
	}
#endif
	gMSDC2_Handle->total_count = total_count;// this put lasting length to be transferred in this session
	gMSDC2_Handle->is_poll = is_poll;
	gMSDC2_Handle->is_aligned = is_aligned;
#if defined(__DRV_MSDC_FAST_FORMAT__) && defined(__DMA_API_V2__)
	if ((KAL_TRUE == gMSDC2_Handle->MSDC_fastFormat) && (gMSDC2_Handle->mIsInitialized==KAL_TRUE))
	{
		gMSDC2_Handle->msdc_input.fixed_pattern = KAL_TRUE; // enable DMA FIX_EN
		gMSDC2_Handle->msdc_menu.addr = 0; // DMA FIX_PATTERN = 0;
		//MSDC_ClearBits32(DMA_CON(gMSDC2_Handle->msdc_dmaport), DMA_CON_SINC);
	}
	else
		gMSDC2_Handle->msdc_input.fixed_pattern = KAL_FALSE;
#endif
//this count will be used to do memory copy for cacheable Tx transfer
#ifdef MSDC_CACHED_SUPPORT
	if(KAL_TRUE == gMSDC2_Handle->isCachedBuf)
		gMSDC2_Handle->msdc_input.count = (total_count > MSDC_UNCACHED_TRASNFER_SIZE)?(MSDC_UNCACHED_TRASNFER_SIZE):(total_count);
	else 
#endif			
	gMSDC2_Handle->msdc_input.count = (total_count > MSDC2_DMA_BURSTLEN_LIMIT)?(MSDC2_DMA_BURSTLEN_LIMIT):(total_count);

		if(is_aligned)
		{
			if(KAL_TRUE == MSDC2_useDMA4ByteBurst){
				MSDC2_SET_FIFO(4);
                
                #if defined(MT6250)
                if (sw_version == SW_SEC_0)
                    gMSDC2_Handle->full_menu.TMOD.burst_mode = KAL_TRUE;
                else
                #endif
                
				gMSDC2_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
                BitFieldWrite32_2((kal_uint32*)MSDC_IOCON2, (kal_uint32)1, MSDC_IOCON_DMABURST);
			}
			else{
				MSDC2_SET_FIFO(1);
                
                #if defined(MT6250)
                if (sw_version == SW_SEC_0)
                    gMSDC2_Handle->full_menu.TMOD.burst_mode = KAL_FALSE;
                else
                #endif
                
				gMSDC2_Handle->msdc_menu.TMOD.burst_mode = KAL_FALSE;
				
                BitFieldWrite32_2((kal_uint32*)MSDC_IOCON2, (kal_uint32)0, MSDC_IOCON_DMABURST);
		}			
		
#ifdef MSDC_CACHED_SUPPORT
	if(KAL_TRUE == gMSDC2_Handle->isCachedBuf){ 
		//have do memory copy before start DMA for Tx
		if(DMA_HWTX == gMSDC2_Handle->msdc_input.type){
			if(MSDC_UNCACHED_BUF_SIZE < (4 * gMSDC2_Handle->msdc_input.count))
				ASSERT(0);
			//copy from upper application buffer
			kal_mem_cpy(msdc_uncachedBuf2, (void *)gMSDC2_Handle->cachedBufCopyPtr, 4 * gMSDC2_Handle->msdc_input.count);
			gMSDC2_Handle->cachedBufCopyPtr += gMSDC2_Handle->msdc_input.count * 4;
		}
            		#if defined(MSDC_START_DMA_IN_CALLBACK)
            		else { // DMA_HWRX == gMSDC2_Handle->msdc_input.type
            		    if ( total_count>MSDC_UNCACHED_TRASNFER_SIZE )
                            gMSDC2_Handle->msdc_input.count=MSDC_UNCACHED_TRASNFER_SIZE/2;
	}
#endif
            	    }
            		#endif
			gMSDC2_Handle->msdc_input.size = DMA_LONG;
		gMSDC2_Handle->isDMA_B2W = KAL_FALSE;

		}
		else /*not aligned*/
		{
#ifdef MSDC_CACHED_SUPPORT
			if(KAL_TRUE == gMSDC2_Handle->isCachedBuf)
				ASSERT(0);
#endif
			MSDC2_SET_FIFO(1);
            BitFieldWrite32_2((kal_uint32*)MSDC_IOCON2, (kal_uint32)0, MSDC_IOCON_DMABURST);

            #if defined(MT6250)
            if (sw_version == SW_SEC_0)
                gMSDC2_Handle->full_menu.TMOD.burst_mode = KAL_TRUE;
            else
            #endif
			gMSDC2_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
		gMSDC2_Handle->msdc_input.size = DMA_BYTE;
		gMSDC2_Handle->isDMA_B2W = KAL_TRUE;

	}

	MSDC2_StartDMAUpdateAddr();
#if defined(MSDC_START_DMA_IN_CALLBACK)
    #ifdef MSDC_CACHED_SUPPORT
		if (KAL_TRUE == gMSDC2_Handle->isCachedBuf) {
		    if(DMA_HWTX == gMSDC2_Handle->msdc_input.type)
		        msdc_input_next = ((total_count-gMSDC2_Handle->msdc_input.count) > MSDC_UNCACHED_TRASNFER_SIZE)?(MSDC_UNCACHED_TRASNFER_SIZE):(total_count-gMSDC2_Handle->msdc_input.count);
		    else
			    msdc_input_next = ((total_count-gMSDC2_Handle->msdc_input.count) > MSDC_UNCACHED_TRASNFER_SIZE/2)?(MSDC_UNCACHED_TRASNFER_SIZE/2):(total_count-gMSDC2_Handle->msdc_input.count);
		} else
    #endif
		    msdc_input_next = ((total_count-gMSDC2_Handle->msdc_input.count) > MSDC2_DMA_BURSTLEN_LIMIT)?(MSDC2_DMA_BURSTLEN_LIMIT):(total_count-gMSDC2_Handle->msdc_input.count);
        gMSDC2_Handle->msdc_input_next=msdc_input_next;
#endif        
    //dbg_print("Total %d, current %d, next %d\n\r", total_count, gMSDC2_Handle->msdc_input.count, msdc_input_next);
}
#if !defined(MSDC_START_DMA_IN_CALLBACK)
kal_uint32 MSDC2_DMATransferFinal(void)
{

	kal_uint32 total_count = gMSDC2_Handle->total_count, t1;
	kal_bool is_poll = gMSDC2_Handle->is_poll;
	kal_uint32 retrived_events = 0;
	#if defined(MT6250)
	SW_SECVERSION sw_version=INT_SW_SecVersion();
	#endif
		
#if defined(__UBL__) || defined(__FUE__)
	//ASSERT(0);
#endif
	while(1)
	{
		// wait until running bit clr
		if(gMSDC2_Handle->msdc_input.type == DMA_HWTX)
			gMSDC2_Handle->timeout_period <<= 2 ;

	if(gMSDC2_Handle->timeout_period > MSDC_TIMEOUT_PERIOD_DAT)
		gMSDC2_Handle->timeout_period = MSDC_TIMEOUT_PERIOD_DAT;
		
#ifdef __DRV_MSDC_FAST_FORMAT__
			if((KAL_TRUE == gMSDC2_Handle->MSDC_fastFormat) && (gMSDC2_Handle->mIsInitialized==KAL_TRUE))
				gMSDC2_Handle->timeout_period = gMSDC2_Handle->timeout_period<<3;
#endif
		
		t1 = drv_get_current_time();
		MSDC2_START_TIMER(gMSDC2_Handle->timeout_period);
		
#ifndef __MEUT__		
		drv_trace2(TRACE_GROUP_7, MSDC_EVENTGP_MONITOR, ((EV_GCB *)gMSDC2_Handle->MSDC_Events)->ev_current_events, __LINE__);
#endif
		#if defined(MSDC_TRACE_LEVEL3)
		MSDC_add_dbg_msg(msdc_dbg_event_DMA_RLCT_Monitor, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), MSDC_Reg(DMA_COUNT(gMSDC2_Handle->msdc_dmaport)));
		#endif

		if(is_poll)
		{
			while(IS_MSDC_DMA_RUN(gMSDC2_Handle->msdc_dmaport) && MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
			{
                SD2_CheckTimeoutWithSleep(t1, gMSDC2_Handle->timeout_period * 11,1);
			}
			#if defined(MSDC_TRACE_LEVEL3)
			MSDC_add_dbg_msg(msdc_dbg_event_SD_transfer_poll_end2, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), 0);
			#endif
		}
		else
		{
			kal_retrieve_eg_events(gMSDC2_Handle->MSDC_Events,(EVENT_DMAIRQ),KAL_OR_CONSUME,&retrived_events,KAL_SUSPEND);				
			#if defined(MSDC_TRACE_LEVEL3)
			MSDC_add_dbg_msg(msdc_dbg_event_SD_transfer_event_retreived2, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), 0);
			#endif
		}				
		MSDC2_STOP_TIMER();

#ifndef __MEUT__
		drv_trace2(TRACE_GROUP_7, MSDC_EVENTGP_MONITOR, ((EV_GCB *)gMSDC2_Handle->MSDC_Events)->ev_current_events, __LINE__);
#endif
		
		if(IS_MSDC_DMA_RUN(gMSDC2_Handle->msdc_dmaport))// if DMA is running,there must be something wrong
			return MSDC_GPT_TIMEOUT_ERR;

		total_count -= gMSDC2_Handle->msdc_input.count;

#ifdef MSDC_CACHED_SUPPORT
	if(KAL_TRUE == gMSDC2_Handle->isCachedBuf){ 
		//if has rest data for Tx, copy data to uncacheable buffer for next transfer
		if(DMA_HWTX == gMSDC2_Handle->msdc_input.type){
			if(0 != total_count){
				if(MSDC_UNCACHED_BUF_SIZE < (4 * gMSDC2_Handle->msdc_input.count))
					ASSERT(0);
				//copy from upper application buffer
				kal_mem_cpy(msdc_uncachedBuf2, (void *)gMSDC2_Handle->cachedBufCopyPtr,
				    4 * ((total_count > MSDC_UNCACHED_TRASNFER_SIZE)?(MSDC_UNCACHED_TRASNFER_SIZE):(total_count)));
			}
		}else{
			/*copy to upper application's buffer*/
			if(MSDC_UNCACHED_BUF_SIZE < (4 * gMSDC2_Handle->msdc_input.count))
				ASSERT(0);
			kal_mem_cpy((void *)gMSDC2_Handle->cachedBufCopyPtr, msdc_uncachedBuf2, 4 * gMSDC2_Handle->msdc_input.count);
		}
		gMSDC2_Handle->cachedBufCopyPtr += gMSDC2_Handle->msdc_input.count * 4;
	}
#endif	
		//transfer finished	
	    if(total_count == 0) break;

//after do memory copy, if need to do next transfer, update count.
#ifdef MSDC_CACHED_SUPPORT
			if(KAL_TRUE == gMSDC2_Handle->isCachedBuf)
				gMSDC2_Handle->msdc_input.count = (total_count > MSDC_UNCACHED_TRASNFER_SIZE)?(MSDC_UNCACHED_TRASNFER_SIZE):(total_count);
			else 
#endif			
			gMSDC2_Handle->msdc_input.count = (total_count > MSDC2_DMA_BURSTLEN_LIMIT)?(MSDC2_DMA_BURSTLEN_LIMIT):(total_count);

		//start next transfer
		MSDC2_StartDMAUpdateAddr();

		gMSDC2_Handle->timeout_period = (50 + (gMSDC2_Handle->msdc_input.count>>5));
	}
	
	return MSDC_NOERROR;

}
#endif //!defined(MSDC_START_DMA_IN_CALLBACK)

#endif // DMA

void* GetMsdc2Handle(kal_uint8 id)
{
    return (void*)&MSDC2_Blk[id];
}
#ifdef R1B_INTERRUPT_MODE
static void MSDC2_R1B_Init(void)
{
	//close all the Interrupt source except R1b Interrupt.
//	MSDC_SetBits32(MSDC_CFG, MSDC_CFG_DIRQE);
	//[DIRQ]disable Data Request Interrupt.
	MSDC_ClearBits32(MSDC_CFG2,MSDC_CFG_DIRQE);

	//[PINIRQ]
	//this interrpt is set or clear before enter this function.
 
	//[SDCMDIRQ]
	//[SDDATIRQ]
	MSDC_WriteReg32(MSDC2_IRQMASK0,0xffffffff);
	//[SDMCIRQ]
	//[MSIFIRQ]
	//Memory Stick Interrupt was disable.
	MSDC2_CLR_INT();	
	MSDC2_ENABLE_INT();// (deactive)
	IRQUnmask(IRQ_MSDC2_CODE);
}
#endif

#if !defined(__FUE__) && !defined(__UBL__)
#if !defined(__MSDC_SD_MMC__)&&!defined(__MSDC_SD_SDIO__)
void init_MSDC_lock(PMSDC_LOCK_TAG lock, const kal_char *str)
{
    if (lock->mtd_mutex == NULL)
    {
        strcpy(lock->name, str);
        lock->mtd_mutex = kal_create_mutex(lock->name);
        lock->lock_count = 0;
        lock->owner_id = NULL;
    }
}

static kal_uint8 msdc_lock_user = 0;

void get_MSDC_lock(PMSDC_LOCK_TAG lock)
{
	if (msdc_lock_user > 0)
		;//ASSERT(0); // init debugging purpose
	else
		msdc_lock_user ++;

    if( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;
    if (kal_if_hisr() == KAL_TRUE || kal_if_lisr() == KAL_TRUE)
    {
        kal_uint32 retaddr0=0;
        #if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retaddr0 = 0;
        #else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retaddr0,lr
        }
        #endif  /* __RVCT__ */
        EXT_ASSERT(0, retaddr0, 0, 0);
    }
    if( kal_get_task_self_id() == lock->owner_id )
    {
        force_ASSERT(0 != lock->lock_count, lock->lock_count, (kal_uint32)lock->owner_id, (kal_uint32)lock->mtd_mutex);
        lock->lock_count++;
    }
    else
    {
        if(lock->mtd_mutex == NULL)
        {
        	init_MSDC_lock(lock, lock->name);
        }
        kal_take_mutex(lock->mtd_mutex);
        lock->owner_id = kal_get_task_self_id();
        lock->lock_count++;
    }
}

void free_MSDC_lock(PMSDC_LOCK_TAG lock)
{
	if (msdc_lock_user != 1)
		;//ASSERT(0); // init debugging purpose
	else
		msdc_lock_user --;

    if( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;
    if( kal_get_task_self_id() == lock->owner_id )
    {
        force_ASSERT(lock->lock_count > 0, lock->lock_count, (kal_uint32)lock->owner_id, (kal_uint32)lock->mtd_mutex);
        lock->lock_count--;
        if(0 == lock->lock_count)
        {
            lock->owner_id = NULL;
            if(lock->mtd_mutex != NULL)
                kal_give_mutex(lock->mtd_mutex);
        }
    }
    else
    {
        force_ASSERT(0, (kal_uint32)lock->owner_id, (kal_uint32)kal_get_task_self_id(), (kal_uint32)lock->mtd_mutex);
    }
}
#endif
#else /* __FUE__, __UBL__ */

//#define init_MSDC_lock(x)

//#define get_MSDC_lock(x)

//#define free_MSDC_lock(x)

#endif /* !defined(__FUE__) && !defined(__UBL__) */

#if defined(R1B_INTERRUPT_MODE)

#if 0
#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
/* under construction !*/
/* under construction !*/
#endif
#endif
void MSDC2_INT_Init(void)
{
#ifdef  __TST_WRITE_TO_FILE__
   /*error recording: it mens this functions is called twice, just return*/
   if(KAL_TRUE == INT_QueryExceptionStatus())
   	return;
#endif
   gMSDC2_Handle->MSDC_Events = kal_create_event_group("MSDC2 Events");


#if defined( DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH)
	MSDC2_Blk[SD_SDIO].MSDC_Events = gMSDC2_Handle->MSDC_Events;
#elif defined( DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
	MSDC2_Blk[SD_T_CARD_2].MSDC_Events = gMSDC2_Handle->MSDC_Events;
#endif


   DRV_Register_HISR(DRV_MSDC2_HISR_ID, MSDC2_HISR_Entry);
#ifndef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
   IRQ_Register_LISR(IRQ_MSDC2_CODE, MSDC2_LISR,"MSDC2 ISR");
   IRQSensitivity(IRQ_MSDC2_CODE,LEVEL_SENSITIVE);
   IRQUnmask(IRQ_MSDC2_CODE);
#else
   IRQ_Register_LISR(IRQ_MSDC_CODE, MSDC2_LISR,"MSDC2 ISR");
   IRQSensitivity(IRQ_MSDC_CODE,LEVEL_SENSITIVE);
   IRQUnmask(IRQ_MSDC_CODE);
#endif
	// enable MSDC interrupt
	MSDC2_CLR_INT();	

	MSDC2_DISABLE_INT();// (active)turn off other interrupt event except pin interrupt			
  
}

#if 0
#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
/* under construction !*/
/* under construction !*/
#endif
#endif

void MSDC2_LISR(void)
{

//mask IRQ.
#ifndef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
	IRQMask(IRQ_MSDC2_CODE);
#else
	IRQMask(IRQ_MSDC_CODE);
#endif
//this is debug information.
#if defined(MSDC_TRACE_LEVEL2) && defined(R1B_INTERRUPT_MODE)
gMSDC2_Handle->LISR_Entry_Count++;
#endif

//IRQMask(SD_MSDC2_CARD1);
gMSDC2_Handle->msdc_int = MSDC_Reg32(MSDC_INTR2);

if(gMSDC2_Handle->msdc_int & MSDC_INT_PINIRQ)
{
    #ifdef DRV_MSDC_CLK_SEARCH
    gMSDC2_Handle->msdc_clkTuneUpperBund = MSDC_CLOCK/2;
    MSDC_ClearBits32(MSDC_IOCON2, MSDC_IOCON_CMDRE);
    #endif
}

drv_active_hisr(DRV_MSDC2_HISR_ID);


}


void MSDC2_HISR_Entry(void)
{
	//register kal_uint16 msdc_int = 0;
	kal_uint16 msdc_ps = 0;
    #if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
	kal_bool previos_present=KAL_FALSE;
    #endif
		
#ifdef __MAUI_BASIC__
    if(gMSDC2_Handle->msdc_int & MSDC_INT_PINIRQ)
        dbg_print("[%s %d]msdc_int=0x%x",__FUNCTION__,__LINE__,gMSDC2_Handle->msdc_int);    
    if(gMSDC2_Handle->msdc_int & MSDC_INT_SDIOIRQ)
        dbg_print("[%s %d]MSDC_HISR_SDIO",__FUNCTION__,__LINE__);    
#endif
    

	//TurnOnMSDC();		
	MSDC2_PDNControl(KAL_FALSE);
	//msdc_int = MSDC_Reg32(MSDC_INTR);
	#if defined(R1B_INTERRUPT_MODE)
	if(gMSDC2_Handle->msdc_int & MSDC_INT_SDCMDIRQ)
	{	
      #if defined(MSDC_TRACE_LEVEL2) && defined(R1B_INTERRUPT_MODE)
      gMSDC2_Handle->SDCMDIRQ_Entry_Count++;
      #endif
		kal_set_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_SDCMDIRQ,KAL_OR);
	}
	if(gMSDC2_Handle->msdc_int & MSDC_INT_SDDATIRQ)
	{
      #if defined(MSDC_TRACE_LEVEL2) && defined(R1B_INTERRUPT_MODE)
      gMSDC2_Handle->SDDATIRQ_Entry_Count++;
      #endif
		kal_set_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_SDDATIRQ,KAL_OR);
		
	}
	if(gMSDC2_Handle->msdc_int & MSDC_INT_SDMCIRQ)
	{
      #if defined(MSDC_TRACE_LEVEL2) && defined(R1B_INTERRUPT_MODE)
      gMSDC2_Handle->SDMCIRQ_Entry_Count++;
      #endif	   
		kal_set_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_SDMCIRQ,KAL_OR);
		
	}
	if(gMSDC2_Handle->msdc_int & MSDC_INT_SDR1BIRQ)
	{
      #if defined(MSDC_TRACE_LEVEL2) && defined(R1B_INTERRUPT_MODE)
      gMSDC2_Handle->SDR1bIRQ_Entry_count++;
      #endif		   
		kal_set_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_OR);		
	}
	#endif//defined(R1B_INTERRUPT_MODE)

	#if defined(__MSDC2_SD_SDIO__)
	/*SDIO*/
	if(gMSDC2_Handle->msdc_int & MSDC_INT_SDIOIRQ)
	{	    
      #if defined(MSDC_TRACE_LEVEL2) && defined(R1B_INTERRUPT_MODE)
      gMSDC2_Handle->SDIOIRQ_Entry_Count++;
      #endif		    
      SDIO2_HISR_Entry();		   		 
	} 
	#endif//defined(__MSDC_SD_MMC__)&&defined(__MSDC_SD_SDIO__)
	

	#if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
	if(gMSDC2_Handle->msdc_int & MSDC_INT_PINIRQ)
	{
		previos_present=MSDC2_Blk[SD_MSDC2_CARD1].mIsPresent;
		MSDC2_Blk[SD_MSDC2_CARD1].mIsInitialized = KAL_FALSE;				
		MSDC2_Blk[SD_MSDC2_CARD1].mIsChanged = KAL_TRUE;				
		if(MSDC_Reg32(MSDC_PS) & MSDC_PS_PIN0)
		{
			if(MSDC2_Blk[SD_MSDC2_CARD1].ins_level == MSDC_IOCTRL_PULL_UP)
				MSDC2_Blk[SD_MSDC2_CARD1].mIsPresent = KAL_FALSE;	
			else
				MSDC2_Blk[SD_MSDC2_CARD1].mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(MSDC2_Blk[SD_MSDC2_CARD1].ins_level == MSDC_IOCTRL_PULL_UP)
				MSDC2_Blk[SD_MSDC2_CARD1].mIsPresent = KAL_TRUE;
			else
				MSDC2_Blk[SD_MSDC2_CARD1].mIsPresent = KAL_FALSE;	
		}
		
		//if(MSDC2_Blk[SD_MSDC2_CARD1].mIsPresent == KAL_FALSE && current_card == SD_MSDC2_CARD1)
		if(MSDC2_Blk[SD_MSDC2_CARD1].mIsPresent == KAL_FALSE)
		{
	    #if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
	    if(previos_present!=MSDC2_Blk[SD_MSDC2_CARD1].mIsPresent) 
	        MSDC_SendCardInd(MOD_MMI, SD_MSDC2_CARD1, MSG_ID_MSDC_CARD_DETECT_IND);
	    #endif			
		}	
		else {
		    #if !defined(FMT_NOT_PRESENT)
		    #if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH) 
		    if(previos_present!=MSDC2_Blk[SD_MSDC2_CARD1].mIsPresent) {
		        MSDC_SendCardInd(MOD_MMI, SD_MSDC2_CARD1, MSG_ID_MSDC_CARD_DISPLAY_IND); 
		        MSDC_SendCardInd(MOD_MMI, SD_MSDC2_CARD1, MSG_ID_MSDC_CARD_DETECT_IND);
		    }
		    #endif		    
		    #endif
		}
		
	    drv_trace4(TRACE_GROUP_6, MSDC_INFORM_HOTPLUG, gMSDC2_Handle->msdc_int, msdc_ps, MSDC2_Blk[SD_MSDC2_CARD1].mIsPresent, drv_get_current_time());		
	    
		}

	#else 
		#if !defined(__MSDC2_CD_EINT__)
    msdc_ps = MSDC_Reg32(MSDC_PS2);
 
	
    if(gMSDC2_Handle->msdc_int & MSDC_INT_PINIRQ) {
		
	#if defined(MSDC_TRACE_LEVEL2) && defined(R1B_INTERRUPT_MODE)
      gMSDC2_Handle->SDPINIRQ_Entry_Count++;
    #endif
	#ifdef MSDC_TRACE_LEVEL1
	  drv_trace4(TRACE_GROUP_6, MSDC_INFORM_HOTPLUG, gMSDC2_Handle->msdc_int, msdc_ps, gMSDC2_Handle->mIsPresent, drv_get_current_time());	  
        #endif
		gMSDC2_Handle->mIsInitialized = KAL_FALSE;
		gMSDC2_Handle->mIsChanged = KAL_TRUE;
		#if defined(R1B_INTERRUPT_MODE)
		kal_set_eg_events(gMSDC2_Handle->MSDC_Events,
			(EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_SDR1BIRQ|EVENT_DMAIRQ),
			KAL_OR);		
		#endif//defined(R1B_INTERRUPT_MODE)

	    #ifdef __MSDC_CD_EINT__
	    
        #else
		if(MSDC_IOCTRL_PULL_UP==gMSDC2_Handle->ins_level)
		{
			gMSDC2_Handle->mIsPresent = ((msdc_ps & MSDC_PS_PIN0) ? KAL_FALSE : KAL_TRUE);	
		}
		else
		{
			gMSDC2_Handle->mIsPresent = ((msdc_ps & MSDC_PS_PIN0) ? KAL_TRUE : KAL_FALSE);
		}
		#endif

		if(KAL_FALSE == gMSDC2_Handle->mIsPresent){
       		gMSDC2_Handle->MSDC_everPlugOut = KAL_TRUE;
			MSDC2_CLR_FIFO();
			MSDC2_CLR_INT();
			DMA_Stop(gMSDC2_Handle->msdc_dmaport);		
      		MSDC2_turnOnVMC(KAL_FALSE);
		}	
		else {
		    #if !defined(MT6250) && !defined(MSDC_SD_BITS4_BUS)
		    MSDC2_SendCardInd(MOD_MMI, MSDC2_SD1, MSG_ID_MSDC_CARD_DISPLAY_IND);
		    #endif   
		}

			#if !defined(FMT_NOT_PRESENT)
		if (gMSDC2_Handle->msdc_custom_handle.IsCardInd)
		{
			if (gMSDC2_Handle->msdc_custom_handle.IsCardInd())
				MSDC2_SendCardInd(MOD_FMT, MSDC2_SD1, MSG_ID_MSDC_CARD_DETECT_IND);
		}
		else
		{
			MSDC2_SendCardInd(MOD_FMT, MSDC2_SD1, MSG_ID_MSDC_CARD_DETECT_IND);
		}
			#endif//!defined(FMT_NOT_PRESENT)
    	}
		#endif
		#endif
		// Set the power down bit too fast will cause MSDC failed to detect next card plug in/out
		// So, move it to GetCardStatus
		//MSDC_PDNControl(KAL_TRUE);

	#ifndef MSDC_TEST_MSDC1_FROM_MSDC2_CODE
	IRQUnmask(IRQ_MSDC2_CODE);				
	#else
	IRQUnmask(IRQ_MSDC_CODE);	
	#endif
}


void MSDC2_DMA_Callback(void)
{
	#if defined(MSDC_TRACE_LEVEL3)
	MSDC_add_dbg_msg(msdc_dbg_event_DMA_done, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), 0);
	#endif
	
    #if !defined(MSDC_START_DMA_IN_CALLBACK)	
	kal_set_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_DMAIRQ,KAL_OR);
	#else
	    MSDC_DMATransferFinal_In_Callback();
	#endif
}


#ifdef DRV_MSDC2_SHARE_BY_SWITCH
MSDC2_changeSwContext(sd_select_enum sel)
{
	gMSDC2_Handle = &MSDC2_Blk[sel];
	gSD2 = &gSD2_blk[sel];
}

/*
	this function do not consider race condition issue, caller should make sure this function is called without risk
	currently, this function is called in sdio_drv.c and sd_drv.c
*/
MSDC2_backupHwSetting()
{
	/*backup MSDC_CFG, MSDC_IOCON, SDC_CFG*/
	gMSDC2_Handle->setting_MSDC_CFG = MSDC_Reg32(MSDC_CFG2);
	gMSDC2_Handle->setting_MSDC_IOCON = MSDC_Reg32(MSDC_IOCON2);
	gMSDC2_Handle->setting_SDC_CFG = MSDC_Reg32(SDC_CFG2);
}

MSDC2_retreiveHwSetting()
{
	MSDC_WriteReg32(MSDC_CFG2, gMSDC2_Handle->setting_MSDC_CFG);
	MSDC_WriteReg32(MSDC_IOCON2, gMSDC2_Handle->setting_MSDC_IOCON);
	MSDC_WriteReg32(SDC_CFG2, gMSDC2_Handle->setting_SDC_CFG);
}
#endif


#if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
void MSDC2_Switch_Card(sd_select_enum sel)
{
	DCL_HANDLE handle;

	if(current_card2 == sel)
		return;
	
	ENTER_CRITICAL();
	current_card2 = sel;	

	/*bewlow comes after JRD SIM+ issue on 2007_03_08, use custom setting instead of fix value*/
	if(GPIO_SELECT_MSDC == sel)
	{
		//GPIO_WriteIO(MSDC_GetSwitchDirection(), GPIO_SIM_MSDC_SWITCH); // replaced by DCL
		handle = DclGPIO_Open(DCL_GPIO,GPIO_SIM_MSDC_SWITCH);
		if(0==MSDC2_GetSwitchDirection())
			DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
		else if(1==MSDC2_GetSwitchDirection())
			DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
		else
		{
			DclGPIO_Close(handle);
			ASSERT(0);
		}
		DclGPIO_Close(handle);
	}
	else if(GPIO_SELECT_SIM == sel)
	{
		//GPIO_WriteIO(1-MSDC_GetSwitchDirection(), GPIO_SIM_MSDC_SWITCH); // replaced by DCL
		handle = DclGPIO_Open(DCL_GPIO,GPIO_SIM_MSDC_SWITCH);
		if(0==(1-MSDC2_GetSwitchDirection()))
			DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
		else if(1==(1-MSDC2_GetSwitchDirection()))
			DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
		else
		{
			DclGPIO_Close(handle);
			ASSERT(0);
		}
		DclGPIO_Close(handle);
	}
	else
		ASSERT(0);
	/*end of changes of JRD SIM+ issue on 2007_03_08*/
	
	MSDC2_changeSwContext(sel);
	EXIT_CRITICAL();
	



	MSDC2_retreiveHwSetting();


}
#endif


#endif //end of MSDC_INT


void MSDC2_turnOnVMC(kal_bool turnOnLdo)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
    #if defined(MT6256)||defined(MT6255)
        PMU_CTRL_LDO_BUCK_SET_VOLTAGE val1; 
    #endif
#if defined(MT6250)
	PMU_CTRL_LDO_BUCK_SET_STB_EN ldo_buck_set_stb_en;
	ldo_buck_set_stb_en.mod |=0;
#endif
	/*
		currently, we just call the PMIC API to control the LDO.
		We have to add debug information here so that we can assert on race conditions.
	*/
	turnOnLdo = KAL_TRUE;
	handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
#if defined(MT6256)||defined(MT6255)
val1.voltage = PMU_VOLT_03_300000_V;
val1.mod = VMC;
DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val1);
#endif
#if defined(MT6250)
	// For MT6250E1, PMU soft start enable/disable issue will cause voltage drop.
	// Before initialization, enable soft start to prevent mis-trigger OC.
	// After card plug out, disable soft start.
	if ((INT_SW_SecVersion() == SW_SEC_0) && (!turnOnLdo)) {
		ldo_buck_set_stb_en.mod = VMC;
		ldo_buck_set_stb_en.enable = DCL_TRUE;
		DclPMU_Control(handle, LDO_BUCK_SET_STB_EN, (DCL_CTRL_DATA_T *)&ldo_buck_set_stb_en);
	}
#endif
val.enable = turnOnLdo;
val.mod = VMC;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
// For MT6250E1, PMU soft start enable/disable issue will cause voltage drop.
// Before initialization, enable soft start to prevent mis-trigger OC.
// After card plug out, disable soft start.
//
#if defined(MT6250)
	// For MT6250E1, PMU soft start enable/disable issue will cause voltage drop.
	// Before initialization, enable soft start to prevent mis-trigger OC.
	// After card plug out, disable soft start.
	if ((INT_SW_SecVersion() == SW_SEC_0) && turnOnLdo) {
		ldo_buck_set_stb_en.mod = VMC;
		ldo_buck_set_stb_en.enable = DCL_FALSE;
		DclPMU_Control(handle, LDO_BUCK_SET_STB_EN, (DCL_CTRL_DATA_T *)&ldo_buck_set_stb_en);
	}
#endif
	DclPMU_Close(handle);
}



#if defined(MSDC_TRACE_LEVEL3)
void MSDC2_add_dbg_msg( msdc_dbg_Event event, kal_uint32 data1, kal_uint32 data2)
{
#if !defined(LOW_COST_SUPPORT) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__) && !defined(__UBL__)
	kal_uint32 bufIndex;
	msdc_debugMessage *msg;

	if(0 == msdc2_msgArray)
		ASSERT(0);

	ENTER_CRITICAL();
	bufIndex = msdc2_msdIndex;
	if(MSDC_DBG_ARRAY_MASK == msdc2_msdIndex)
		msdc2_msdIndex = 0;
	else
		msdc2_msdIndex ++;
	EXIT_CRITICAL();
	msg = &msdc2_msgArray[bufIndex];
	
	msg->event = event;
	msg->data32_0 = data1;
	msg->data32_1 = data2;
	msg->time = drv_get_current_time();
#endif
}
#endif


#endif//!defined(__UBL__) || defined(__CARD_DOWNLOAD__) 

#else
	#if !defined(__MSDC_SD_MMC__)&&!defined(__MSDC_SD_SDIO__)
	kal_bool MSDC_Check_Card_Mount(void)
	{
    return gMSDC_Handle->mIsInitialized;
	
	}
	#endif
#endif 

#else //DRV_MSDC_OFF
#include "kal_release.h"
#include "msdc_def.h"

/*
#include "kal_release.h"
//RHR REMOVE
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "eint.h"
#include "fat_fs.h"
*/
//RHR
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"     
#include "intrCtrl.h"
#include "reg_base.h"
#include "drvpdn.h"
//#include "gpt_sw.h"
#include "drv_comm.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "drv_hisr.h"
#include "msdc_def.h"

/*here are dummy API*/
void MSDC2_Initialize(void){};
void MSDC2_PDNControl(kal_bool ON){};
int MSDC2_GetCardStatus(void * DriveData, int AckType){};
kal_bool MSDC2_GetMediaChanged(sd_select_enum id){};
MSDC_HANDLE MSDC2_Blk[SD_NUM];
MSDC_HANDLE	*gMSDC2_Handle = &(MSDC2_Blk[0]);
//kal_bool MSDC_everPlugOut;



#endif //DRV_MSDC_OFF
