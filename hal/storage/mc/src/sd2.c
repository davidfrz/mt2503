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
 *   sd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for SD/MMC 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef DRV_MSDC_OFF
#include "kal_release.h"
//RHR ADD
#include "kal_general_types.h"
//#include "btif_sw.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_public_defs.h"
#include "init.h"

//RHR REMOVE
/*
#include "app_buff_alloc.h"
#include "intrCtrl.h"
#include "gpio_sw.h"
#include "init.h"
*/
//RHR
#include "kal_trace.h"
#include "dcl.h"
#include "drv_comm.h"
#include "drv_features.h"
#include "stack_config.h"
#include "us_timer.h"
#include "SST_sla.h"



#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)

#if !defined(__UBL__) || defined(__CARD_DOWNLOAD__) 
#include "msdc_reg_adap.h"
#include "reg_base.h"
#include "msdc_api.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "upll_ctrl.h"
#include "Drv_trc.h"

#include "dma_hw.h"

T_SDC_HANDLE	gSD2_blk[SD_NUM];

T_SDC_HANDLE	*gSD2 = &gSD2_blk[MSDC2_SD1];
extern MSDC_HANDLE *msdc2_handle;
extern kal_uint32 MSDC_Sector2[128];
extern MSDC_HANDLE *gMSDC2_Handle;




extern MSDC_Custom_Handle msdc_custom_handle;
extern kal_uint8 MSDC2_GetIOCtrlParam(void);
extern kal_bool INT_USBBoot(void);
kal_bool SD2_CheckTimeoutWithSleep(kal_int32 start_time,
                         kal_int32 duration_ms,
                         kal_int32 sleep_time);
extern void MSDC2_SetLatchTuning(void);

static kal_uint32 sd_cmd_extra = 0;

#ifdef DCL_MSDC_INTERFACE
#include "DCL.h"

SDC_CMD_STATUS SD2_SetCallBack(MSDC_CALLBACK callback1, MSDC_CALLBACK callback2, MSDC_CALLBACK callback3,MSDC_CALLBACK callback4,MSDC_CALLBACK callback5,MSDC_CALLBACK callback6);
SDC_CMD_STATUS SD2_SetReadTestFlag(kal_uint32 readTestFlag);
SDC_CMD_STATUS SD2_readTest(void);
SDC_CMD_STATUS SD2_SetUpllClock(void);

#ifdef __MEUT__
SDDriver_t sd_driver_MTK1 = {
	(DCL_SINGLE_BLK_RD)SD_ReadSingleBlock,
	(DCL_MUL_BLK_RD)SD_ReadMultiBlock,
	(DCL_SINGLE_BLK_WR)SD_WriteSingleBlock,
	(DCL_MUL_BLK_WR)SD_WriteMultiBlock,
	(DCL_SD_INITITALIZE)SD_Initialize,
	(DCL_SET_PRE_ERASE_CNT)SD_SetPreEraseBlk,
	(DCL_SD_SET_CALLBACK)SD_SetCallBack,
	(DCL_SET_READ_TEST_FLAG)SD_SetReadTestFlag,
	(DCL_SD_READ_TEST)SD_readTest,
	(DCL_SD_SET_UPLL_CLOCK_TEST)SD_SetUpllClock,
	(DCL_SD_ERASE_BLK)SD_FlushSectors,
};
#else
SDDriver_t sd_driver_MTK2 = {
	(DCL_SINGLE_BLK_RD)SD2_ReadSingleBlock,
	(DCL_MUL_BLK_RD)SD2_ReadMultiBlock,
	(DCL_SINGLE_BLK_WR)SD2_WriteSingleBlock,
	(DCL_MUL_BLK_WR)SD2_WriteMultiBlock,
	(DCL_SD_INITITALIZE)SD2_Initialize,
	(DCL_SET_PRE_ERASE_CNT)SD2_SetPreEraseBlk,
	(DCL_SD_SET_CALLBACK)NULL,
	(DCL_SET_READ_TEST_FLAG)NULL,
	(DCL_SD_READ_TEST)NULL,
	(DCL_SD_SET_UPLL_CLOCK_TEST)NULL,
	(DCL_SD_ERASE_BLK)SD2_FlushSectors,
};


#endif

#endif

#if defined( __MAUI_BASIC__) || defined( __MEUT__)
#define MSDC_TESTBUFFER_SIZE	512
kal_uint32	msdc2_testBuffer[(MSDC_TESTBUFFER_SIZE/4)];
kal_uint32	msdc2_writeBuffer[(MSDC_TESTBUFFER_SIZE/4)];

#define CMD_DVT_TEST_STATUS 7
kal_uint32 msdc2_ReadTestFlag;
MSDC_CALLBACK msdc2_TestCallBack1;
MSDC_CALLBACK msdc2_TestCallBack2;
MSDC_CALLBACK msdc2_TestCallBack3;
MSDC_CALLBACK msdc2_TestCallBack4;
MSDC_CALLBACK msdc2_TestCallBack5;
MSDC_CALLBACK msdc2_TestCallBack6;
static kal_uint32 sendCmdTimes =0;
#endif


#ifdef __CARD_DOWNLOAD__
extern kal_bool MSDC2_QueryIsPowerControllable(void);
extern void MSDC2_SetPower(kal_bool enable);
#endif

extern kal_uint32 gMsdc2ClksrcRate[MSDC_CLKSRC_NUM];

SDC_CMD_STATUS SD2_Acmd42(kal_bool connect)
{
	SDC_CMD_STATUS status;

	// send APP_CMD
	if((status = SD2_Cmd55(gSD2->mRCA))!=NO_ERROR)
		return status;
	// send cmd6
	if((status = SD2_Send_Cmd(SDC_CMD_ACMD42,connect))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD2_CheckStatus())!=NO_ERROR)
		return status;	

	gSD2->mCD_DAT3 = KAL_FALSE;	// pull-up resistor is disconnected for data trnasfer
	return NO_ERROR;
}


T_MSDC_CARD SD2_CheckSDorMMC()
{
	SDC_CMD_STATUS status; 


	SD2_Cmd8();

	status = SD2_Acmd41_SD();
	if (status == NO_ERROR)
		return gMSDC2_Handle->mMSDC_type;	// SD_CARD
	return UNKNOWN_CARD;
}


void SD2_SetDefault(void)
{
    MSDC_LOCK_TAG tempLock;
    kal_mem_cpy(&tempLock, &gSD2->mSDdrv_lock, sizeof(MSDC_LOCK_TAG));

	kal_mem_set(gSD2,0,sizeof(T_SDC_HANDLE));

	gSD2->mBKLength = 512;
	gSD2->mRCA = 0;
	gSD2->mInactive = KAL_FALSE;
	gSD2->mState = IDLE_STA;
	gSD2->bus_width = 1;
	gSD2->mCD_DAT3 = KAL_TRUE;

    kal_mem_cpy(&gSD2->mSDdrv_lock, &tempLock, sizeof(MSDC_LOCK_TAG));
}


extern void USBDL_CLK_ON(kal_bool turn_on);


#ifdef DRV_MSDC_CLK_SEARCH

kal_uint32 whenToStop2;
kal_uint32 stopTimeout2 = 300;

kal_bool sd2_DltTestWithClkStopped(kal_uint32 data_adrs)
{

	SDC_CMD_STATUS status1;
	kal_uint32	bufIndex, loopIndex;
	kal_uint32	timeoutIndex;
	kal_uint8		*bufPtr;
	kal_bool		status;

	
	bufPtr = (kal_uint8 *)MSDC_Sector2;

	if((512- 44) < whenToStop2)
		ASSERT(0);
		
	//if(NO_ERROR != status1)
		//ASSERT(0);
	kal_mem_set(bufPtr, 0, 512);

	{
		if((status1 = SD2_Send_Cmd(SDC_CMD_CMD17,data_adrs))!=NO_ERROR)
			return KAL_FALSE;
	}
	if((status1 = SD2_CheckStatus())!=NO_ERROR)
		return KAL_FALSE;
	status1 |=0;
	bufIndex = 0;
	loopIndex = 0;
	/*move data from FIFO to buffer*/
	while(((bufIndex*4)<512) && (loopIndex < 50000)){
		if(MSDC_Reg32(MSDC_STA2)&MSDC_STA_FIFOCNT){
			MSDC_Sector2[bufIndex] = MSDC_Reg32(MSDC_DAT2);
			bufIndex ++;

			/*the most impormant in this function, to make a delay to trigger crc error*/
			if((bufIndex*4 + 44) > whenToStop2){
				timeoutIndex = 0;
				while(timeoutIndex < stopTimeout2)
					timeoutIndex ++;
			}
		}
		loopIndex++;
	}

	if(MSDC_Reg32(SDC_DATSTA2) & SDC_DATSTA_DATCRCERR)
		status = KAL_FALSE;
	else
		status = KAL_TRUE;

	MSDC_LSD_SetBits32(MSDC_CFG2,MSDC_CFG_RST);
	bufIndex= 5000;
	while(bufIndex--);
	MSDC_LSD_ClearBits32(MSDC_CFG2,MSDC_CFG_RST);
	bufIndex= 50000;
	while(bufIndex--);

	/*write FIFOCLR to reset FIFO index*/
	MSDC2_CLR_FIFO();

	return status;
}


kal_bool SD2_IsClkInRange(kal_uint32 clk)
{
	kal_uint32 maxSpeed;

	maxSpeed = 25000;
	if(gSD2->flags & SD_FLAG_SD_TYPE_CARD){
		if(gSD2->flags & SD_FLAG_HS_SUPPORT){
			//maxSpeed = 50000 + 20000;
			maxSpeed = 50000;
		}
		else if(gSD2->flags & SD_FLAG_LIMITED_HIGH_SPEED_CARD){
			maxSpeed = 26000;
		}
	}
	else{
		if(gSD2->mCSD.ext_csd->card_type & HS_52M){
			maxSpeed = 52000;
		}
		else if(gSD2->mCSD.ext_csd->card_type & HS_26M){
			maxSpeed = 26000;
		}
	}
	if(maxSpeed > gMSDC2_Handle->msdc_clkTuneUpperBund)
		maxSpeed = gMSDC2_Handle->msdc_clkTuneUpperBund;

	if (clk <= maxSpeed) {
	    //gMSDC2_Handle->msdc_clkTuneUpperBund = clk;
		return KAL_TRUE;
	}

	return KAL_FALSE;
}


kal_bool SD2_CanCmdBeLatched(void)
{
	SDC_CMD_STATUS status = NO_ERROR;
	kal_uint32 resp[2];
	
	status = SD2_GetStatus(gSD2->mRCA, resp);
	if (NO_ERROR == status)
	{
#ifdef __MAUI_BASIC__
		dbg_print(" pass\n\r");
#endif
		return KAL_TRUE;
	}
	
#ifdef __MAUI_BASIC__
	dbg_print(" fail:%d",status);
#endif
	return KAL_FALSE;
}


SDC_CMD_STATUS SD2_CanDataBeLatched(msdc_clk_setting cs)
{
	SDC_CMD_STATUS status = NO_ERROR;
	kal_uint32 resp[2];
	kal_uint32 loopIndex;
	
	if (gSD2->flags & SD_FLAG_SD_TYPE_CARD)
		status = SD2_ReadSCR(resp);
	if (NO_ERROR != status)
	{
		return KAL_FALSE;
	}
#ifdef __MAUI_BASIC__
	dbg_print("\n\rtesting (%d, %d) for speed: %d", cs.clksrc, cs.sclkf, cs.cardClk);
#endif

	#ifdef MSDC_TRACE_LEVEL3
	MSDC2_add_dbg_msg(msdc_dbg_event_SD_clk_tuning, MSDC_Reg32(MSDC_CFG2), MSDC_Reg32(MSDC2_CLKACB_CFG));
	#endif
	status = SD2_SetBlength(512);
	if (NO_ERROR != status)
	{
		return KAL_FALSE;
	}

	for (loopIndex = 6; NO_ERROR == status && 0 < loopIndex; loopIndex--)
	{
		if(gSD2->flags & SD_FLAG_HCS_SUPPORT)
			status = SD2_ReadSingleBlock(loopIndex, MSDC_Sector2);
		else
			status = SD2_ReadSingleBlock(loopIndex * 512, MSDC_Sector2);
	}

	if (NO_ERROR == status && 0 == loopIndex)
	{
#ifdef LOW_COST_SUPPORT
#ifdef __MAUI_BASIC__
			dbg_print(" pass\n\r");
#endif
			return KAL_TRUE;

#else
		/*multiple block read pass, we now do clk stop test*/
		if (sd2_DltTestWithClkStopped(0))
		{
#ifdef __MAUI_BASIC__
			dbg_print(" pass\n\r");
#endif
			return KAL_TRUE;
		}	
#endif
	}
	
    //
    // To prevent bad card tuneclk spent too much time.
    // If dma can't get data and timeout, we set clock upper bund flag to prevent retry.
    //
    if (status == MSDC_GPT_TIMEOUT_ERR)
		return ERR_CMDOK_DATREADFAIL;
#ifdef __MAUI_BASIC__
	dbg_print(" fail:%d",status);
#endif
	return KAL_FALSE;
}

SDC_CMD_STATUS MSDC2_AutoCalibrate(
	msdc_acb_mode		mode,
	msdc_acb_scan_mode	scanMode,
	msdc_acb_tun_scheme	tunScheme,
	kal_uint8			tunBlockNum
	)
{
	kal_uint32 clkacb_cfg = 0, clkacb_sta = 0;
//	SDC_CMD_STATUS status = NO_ERROR;
	kal_uint32 t1;
//	kal_uint8 times = 0;
	
	clkacb_cfg |= MSDC_CLKACB_CFG_CLK_LATCH; // multiple phase clock

	switch (mode)
	{
	case MSDC_AM_CMD:
		clkacb_cfg &= ~MSDC_CLKACB_CFG_ACB_MODE;
		MSDC_WriteReg32(SDC_ARG, (kal_uint32)gSD2->mRCA<<16); // CMD13 arg: RCA
		break;
	case MSDC_AM_DAT:
		clkacb_cfg |= MSDC_CLKACB_CFG_ACB_MODE;
		MSDC_WriteReg32(SDC_ARG, 0);	// MSDC CMD18 will start from address 0
		break;
	default:
		ASSERT(0);
		return ERR_ACB_FAIL;
	}

	switch (scanMode)
	{
	case MSDC_ASM_DET:
		clkacb_cfg &= ~MSDC_CLKACB_CFG_SCANMODE;
		break;
	case MSDC_ASM_FULL:
		clkacb_cfg |= MSDC_CLKACB_CFG_SCANMODE;
		break;
	default:
		ASSERT(0);
		return ERR_ACB_FAIL;
	}

	switch (tunScheme)
	{
	case MSDC_ATS_DETECT:
		clkacb_cfg &= ~(MSDC_CLKACB_CFG_COARSE_EN | MSDC_CLKACB_CFG_FINE_EN);
		ASSERT(0);
		break;
	case MSDC_ATS_COARSE:
		clkacb_cfg |= MSDC_CLKACB_CFG_COARSE_EN;
		break;
	case MSDC_ATS_FINE:
		clkacb_cfg |= MSDC_CLKACB_CFG_FINE_EN;
		break;
	default:
		ASSERT(0);
		return ERR_ACB_FAIL;
	}

	if (tunBlockNum > 0xff)
	{
		ASSERT(0);
	}
	else
	{
		clkacb_cfg |= (tunBlockNum<<16) & MSDC_CLKACB_CFG_TUN_BLOCK_NUM;
	}

	clkacb_cfg |= MSDC_CLKACB_CFG_CLKTUN_ON;

	//read out data sta to make sure we will read latest one in the future
	gMSDC2_Handle->cmd_sta = *(volatile kal_uint16*)SDC_CMDSTA2;
	gMSDC2_Handle->dat_sta = *(volatile kal_uint16*)SDC_DATSTA2;

	MSDC_SetBits32(MSDC2_CLKACB_CFG, clkacb_cfg|MSDC_CLKACB_CFG_CLKTUN_ON); // start tuning

	t1 = drv_get_current_time();
	MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_ACB);
	// MSDC_CLKACB_STA_CLKTUN_DONE will be triggered even when MSDC_CLKACB_STA_ACB_TO was triggered
	while ((0 == ((clkacb_sta = MSDC_Reg32(MSDC2_CLKACB_STA)) & MSDC_CLKACB_STA_CLKTUN_DONE)) && 
		MSDC2_Check_Card_Present() && 
		!gMSDC2_Handle->is_timeout
		)
	{
		// should be finished within 15s [jocelyn's comment @ FPGA]
		if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_ACB*11)
			gMSDC2_Handle->is_timeout = KAL_TRUE;
	}
	MSDC2_STOP_TIMER();

	//read out data sta to make sure we will read latest one in the future
	gMSDC2_Handle->cmd_sta = *(volatile kal_uint16*)SDC_CMDSTA2;
	gMSDC2_Handle->dat_sta = *(volatile kal_uint16*)SDC_DATSTA2;

	if(gMSDC2_Handle->is_timeout)
	{
		kal_print("[MSDC] ACB timeout (GPT)\n\r");
		ASSERT(0);
		return MSDC_GPT_TIMEOUT_ERR;
	}

	if (clkacb_sta & MSDC_CLKACB_STA_ACB_TO)
	{
		kal_print("[MSDC] ACB timeout\n\r");
		ASSERT(0);
		return ERR_ACB_TIMEOUT;
	}

	return NO_ERROR;
}

kal_uint32 MSDC2_ManuCalibrate(
	msdc_clk_setting	cs,
	msdc_acb_mode 		mode
	)
{
	kal_uint8 i, j;
	kal_uint32 phaseArraySeamless = 0;

	// command manual-calibrate
	for (i = 0; i < (1 << (cs.sclkf + 1)); i ++)
	{
		for (j = 0; j < DIV_CLKSRC(cs.clksrc); j ++)
		{
			switch (mode)
			{
			case MSDC_AM_CMD:
				MSDC_SetData32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_CMD_PHASE, (i << 27) | (j << 24));
				if (KAL_TRUE == SD2_CanCmdBeLatched())
					phaseArraySeamless |= 1 << (j + i * DIV_CLKSRC(cs.clksrc));
				break;
				
			case MSDC_AM_DAT:
				MSDC_SetData32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_DAT_PHASE, (i << 11) | (j << 8));
				if (KAL_TRUE == SD2_CanDataBeLatched(cs))
					phaseArraySeamless |= 1 << (j + i * DIV_CLKSRC(cs.clksrc));
				break;
			
			default:
				ASSERT(0);
				break;
			}
		}
	}

	return phaseArraySeamless;
}
	
#define MAX_NUM_MULTI_PHASE2	32
SDC_CMD_STATUS FindMostConsecutiveBits2(
	kal_uint32 word,
	kal_uint8 wordLen,
	kal_uint8 threshold,
	kal_uint8 *pos
	)
{
	kal_uint8 confidenceCnt[MAX_NUM_MULTI_PHASE2];
	//kal_uint32 mask = 0;
	kal_int8 i = 0, j = 0;
	kal_uint8 pos_of_largest = 0, test_pos = 0;
	kal_uint8 len_of_MostConsecutiveBits = 0;

	kal_mem_set(confidenceCnt, 0, MAX_NUM_MULTI_PHASE2 * sizeof(kal_uint8));

	for (i = 0; i < wordLen; i ++)
	{
		if (0 == ((1 << i) & word))
			continue;	// bit i is '0', then skip
		confidenceCnt[i] = 1;

		for (j = 1; j < wordLen; j ++)
		{
			test_pos = ((i + j) < wordLen)? (i + j) : (i + j - wordLen);
			if (0 == ((1 << test_pos) & word))
				break;
			else
				confidenceCnt[i]++;	// bit (i+j) is '1', then benefit to bit i
		}

		if (confidenceCnt[i] > confidenceCnt[pos_of_largest])
			pos_of_largest = i;

		i += confidenceCnt[i] - 1;	// skip following continuous '1' for speedup
	}

	len_of_MostConsecutiveBits = (confidenceCnt[pos_of_largest] + threshold - 1);
	len_of_MostConsecutiveBits |=0;
	// find nothing!
	if (confidenceCnt[pos_of_largest] < threshold)
		return ERR_NOT_FOUND;

	// choose the middle of the most consecutive bits
	*pos = pos_of_largest + (confidenceCnt[pos_of_largest] / 2);
	if (*pos >= wordLen)	// rounding
		*pos -= wordLen;

	return NO_ERROR;
}

SDC_CMD_STATUS MSDC2_AutoCalibrate_FindBestLatchWindow(
	msdc_acb_scan_mode scanMode,
	kal_uint8 *pos
	)
{
	// TODO: MSDC_ASM_DET
	
	// MSDC_ASM_FULL
	kal_uint32 crcsta = 0;
	kal_uint32 crcWord = 0;
	SDC_CMD_STATUS status = NO_ERROR;
	
	crcsta = MSDC_Reg32(MSDC2_CLKACB_CRCSTA1);

	// confirm enable bit number in CRCSTA is FULL mode
	if (MSDC_CLKACB_CRC_STA_ENABLE != (crcsta & MSDC_CLKACB_CRC_STA_ENABLE))
	{
		ASSERT(0);
		return ERR_ACB_STA_ENABLE_FAIL;
	}

	// 2's compliment of the CRC 16-bits: 1 => OKAY bit
	crcWord = (kal_uint16)((~crcsta) & MSDC_CLKACB_CRC_STA_CRC);
	status = FindMostConsecutiveBits2(crcWord, 16, 3, pos);

	return status;
}

SDC_CMD_STATUS MSDC2_ManuCali_FindBestLatchWindow(
	msdc_clk_setting cs,
	kal_uint32 phaseArraySeamless,
	kal_uint8 *pos
	)
{
	SDC_CMD_STATUS status = NO_ERROR;
	kal_uint8 posSeamless = 0, sclkf = 0, clksrc = 0;
	
	status = FindMostConsecutiveBits2(
		phaseArraySeamless,
		DIV_SCLKF(cs.sclkf) * DIV_CLKSRC(cs.clksrc),
		3,
		&posSeamless
		);
	if (NO_ERROR != status)
		return ERR_NOT_FOUND;

	sclkf = posSeamless / DIV_CLKSRC(cs.clksrc);
	clksrc = posSeamless - sclkf * DIV_CLKSRC(cs.clksrc);
	*pos = sclkf << 3 | clksrc;

	return NO_ERROR;
}

kal_uint32 SD2_ClkTuning_AutoCalibrate(msdc_clk_setting cs)
{
//	kal_uint32 clkacb_cfg = 0, clkacb_sta = 0;
	SDC_CMD_STATUS status = NO_ERROR;
	kal_uint8 pos = 0;

	// 1. command auto-calibrate
	status = MSDC2_AutoCalibrate(MSDC_AM_CMD, MSDC_ASM_FULL, MSDC_ATS_COARSE, 10);
	if (NO_ERROR == status)
	{
		status = MSDC2_AutoCalibrate_FindBestLatchWindow(MSDC_ASM_FULL, &pos);
		if (NO_ERROR == status)
		{
			// found CMD latch, and then fill it into CMD_PHASE
			MSDC_SetData32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_CMD_PHASE, ((kal_uint32)pos) << 24);
		}
		else
		{
			// TODO: not found CMD latch in coarse-tune, try fine-tune
		}
	}
	else
		return status;

	// 2. data auto-calibrate
	status = MSDC2_AutoCalibrate(MSDC_AM_DAT, MSDC_ASM_FULL, MSDC_ATS_COARSE, 10);
	if (NO_ERROR == status)
	{
		status = MSDC2_AutoCalibrate_FindBestLatchWindow(MSDC_ASM_FULL, &pos);
		if (NO_ERROR == status)
		{
			// found CMD latch, and then fill it into CMD_PHASE
			MSDC_SetData32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_DAT_PHASE, ((kal_uint32)pos) << 8);
		}
		else
		{
			// TODO: not found CMD latch in coarse-tune, try fine-tune
		}
	}
	else
		return status;

	return NO_ERROR;
}

kal_uint32 SD2_ClkTuning_ManualCalibrate(msdc_clk_setting cs)
{
	SDC_CMD_STATUS status = NO_ERROR;
	kal_uint8 pos = 0;
	kal_uint32 phaseArraySeamless = 0;

	MSDC_SetBits32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_CLK_LATCH); // multiple phase clock

	// 1. command manual-calibrate
	phaseArraySeamless = MSDC2_ManuCalibrate(cs, MSDC_AM_CMD);
	status = MSDC2_ManuCali_FindBestLatchWindow(cs, phaseArraySeamless, &pos);
	if (NO_ERROR == status)
	{
		// found CMD latch, and then fill it into CMD_PHASE
		MSDC_SetData32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_CMD_PHASE, ((kal_uint32)pos) << 24);
	}
	else
		return status;

	// 2. data manual-calibrate
	phaseArraySeamless = MSDC2_ManuCalibrate(cs, MSDC_AM_DAT);
	status = MSDC2_ManuCali_FindBestLatchWindow(cs, phaseArraySeamless, &pos);
	if (NO_ERROR == status)
	{
		// found CMD latch, and then fill it into DAT_PHASE
		MSDC_SetData32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_DAT_PHASE, ((kal_uint32)pos) << 8);
	}
	else
		return status;

	return NO_ERROR;
}

kal_uint32 SD2_ClkTuning_FeedbackClk(msdc_clk_setting cs)
{
	kal_int32 i = 0;
	SDC_CMD_STATUS status = NO_ERROR;

	MSDC_ClearBits32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_CLK_LATCH); // feedback clock

	for (i = 0; i < 2; i ++)
	{
		if (i == 0)
		{
			//exchange this temporarily.
			//MSDC_SetBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);
			MSDC_ClearBits32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);

		}
		else
		{
			//MSDC_ClearBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);
			MSDC_SetBits32(MSDC2_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);
		}

		// check errors (e.g. CRC) with this configuration
		if (KAL_FALSE == SD2_CanCmdBeLatched())
			continue;
		status = SD2_CanDataBeLatched(cs);
		if (KAL_TRUE == status)
			return NO_ERROR;
		if(ERR_CMDOK_DATREADFAIL == status )
		{
			//MSDC_STOP_TIMER();
			gMSDC2_Handle->is_timeout = KAL_TRUE;
			return ERR_CMDOK_DATREADFAIL;
		}

	}
	return ERR_NOT_FOUND;
}

kal_uint32 SD2_tuneCLK2()
{
	msdc_clk_setting cs;
	kal_uint32 status;

	for (cs.sclkf = 0; cs.sclkf < MSDC_SCLKF_NUM; cs.sclkf ++)
	{
		// criteria : clock should > 12.5MHz	// TODO: [Samuel]
		//if (cs.sclkf >= 2)
		//	ASSERT(0);

		for (cs.clksrc = 0; cs.clksrc < MSDC_CLKSRC_NUM; cs.clksrc ++)
		{
#if defined(MT6260)
			if (2==cs.clksrc)
				continue;
#endif
			//#if defined(DRV_MSDC_CLKSRC_MT6261_SERIES)
			#if defined(MT6261)
			if(3 == cs.clksrc )
				continue;
			#endif
			#if defined(MT2501)||defined(MT2502)
			if((0== cs.clksrc) ||(1== cs.clksrc))
				continue;
			#endif
			cs.cardClk = gMsdc2ClksrcRate[cs.clksrc] / DIV_SCLKF(cs.sclkf);

			if (SD2_IsClkInRange(cs.cardClk) && gMSDC2_Handle->mIsPresent)
			{
				// configure MSDC_CFG
				MSDC_SetData32(MSDC_CFG2, MSDC_CFG_CLKSRC, cs.clksrc << 3);
				MSDC_SetData32(MSDC_CFG2, MSDC_CFG_SCLKF, cs.sclkf << 8);
	
				if (cs.cardClk >= 25000) // 25MHz
				{
					if (gMSDC2_Handle->tuningTopology.HighSpeed)
					{
						status = gMSDC2_Handle->tuningTopology.HighSpeed(cs);
						if (NO_ERROR == status)
							return cs.cardClk;
						else if(ERR_CMDOK_DATREADFAIL == status)
							return ERR_CMDOK_DATREADFAIL;				
					}
				}
				else
				{
					if (gMSDC2_Handle->tuningTopology.NormalSpeed1)
					{
						status = gMSDC2_Handle->tuningTopology.NormalSpeed1(cs);
						if (NO_ERROR == status)
							return cs.cardClk;
						else if(ERR_CMDOK_DATREADFAIL == status )
							return ERR_CMDOK_DATREADFAIL;
					}
					if (gMSDC2_Handle->tuningTopology.NormalSpeed2)
					{
						status = gMSDC2_Handle->tuningTopology.NormalSpeed2(cs);
						if (NO_ERROR == status)
							return cs.cardClk;
						else if(ERR_CMDOK_DATREADFAIL == status)
							return ERR_CMDOK_DATREADFAIL;
					}
				}
			}
		}
	}

	return 0;
}

#endif//#ifdef DRV_MSDC_CLK_SEARCH


#ifdef __MAUI_BASIC__

kal_bool	msdcOddNumberSizeTestByDMA2;
kal_bool	msdcDoNotRST2;
SDC_CMD_STATUS msdcTransferLengthTest2(kal_uint32 size, kal_uint8 *compareBuffer, kal_uint32 data_adrs)
{

	SDC_CMD_STATUS status1;
	kal_uint32	bufIndex, loopIndex;
	kal_uint8		*bufPtr;

	
	if(size > MSDC_TESTBUFFER_SIZE)
		ASSERT(0);
	bufPtr = (kal_uint8 *)msdc2_testBuffer;
	status1 = SD2_SetBlength(size);
	if(NO_ERROR != status1)
		ASSERT(0);
	kal_mem_set(bufPtr, 0, MSDC_TESTBUFFER_SIZE);
	if((status1 = SD2_Send_Cmd(SDC_CMD_CMD17,data_adrs))!=NO_ERROR)	
		ASSERT(0);
	if((status1 = SD2_CheckStatus())!=NO_ERROR)
		ASSERT(0);

	bufIndex = 0;
	loopIndex = 0;
	/*move data from FIFO to buffer*/
	while(((bufIndex*4)<=size) && (loopIndex < 50000)){
		if(MSDC_Reg32(MSDC_STA2)&MSDC_STA_FIFOCNT){
			msdc2_testBuffer[bufIndex] = MSDC_Reg32(MSDC_DAT2);
			bufIndex ++;
		}
		loopIndex++;
	}

	/*compare*/
	bufIndex = 0;
	
	for(bufIndex = 0; bufIndex < size; bufIndex++){
		if(*(bufPtr + bufIndex) != *(compareBuffer+bufIndex))
			ASSERT(0);
	}

	if(KAL_FALSE == msdcDoNotRST2){
		MSDC_LSD_SetBits32(MSDC_CFG2,MSDC_CFG_RST);
		bufIndex= 5000;
		while(bufIndex--);
		MSDC_LSD_ClearBits32(MSDC_CFG2,MSDC_CFG_RST);
		bufIndex= 50000;
		while(bufIndex--);
	}
	/*write FIFOCLR to reset FIFO index*/
	MSDC_WriteReg32(MSDC_STA2, MSDC_STA_FIFOCLR);
	
	return status1;
}

SDC_CMD_STATUS msdcWriteLengthTest2(kal_uint32 size, kal_uint8 *compareBuffer, kal_uint32 data_adrs, kal_bool notChange)
{

	SDC_CMD_STATUS status1;
	kal_uint32	bufIndex, loopIndex;
	kal_uint8		*bufPtr, *writeBufPtr;

	
	if(size > 56)
		ASSERT(0);
	bufPtr = (kal_uint8 *)msdc2_testBuffer;
	writeBufPtr = (kal_uint8 *)msdc2_writeBuffer;
	status1 = SD2_SetBlength(size);
	if(NO_ERROR != status1)
		ASSERT(0);
	kal_mem_set(bufPtr, 0, MSDC_TESTBUFFER_SIZE);
	

	if(notChange){
		kal_mem_cpy(writeBufPtr, compareBuffer, size);
	}
	else{
		kal_mem_set(writeBufPtr, (kal_uint8)size, size);
	}

	/*RST MSDC or index may not reset well*/
	if(KAL_FALSE == msdcDoNotRST2){
		MSDC_LSD_SetBits32(MSDC_CFG2,MSDC_CFG_RST);
		bufIndex= 5000;
		while(bufIndex--);
		MSDC_LSD_ClearBits32(MSDC_CFG2,MSDC_CFG_RST);
		bufIndex= 50000;
		while(bufIndex--);
	}
	/*write FIFOCLR to reset FIFO index*/
	MSDC_WriteReg32(MSDC_STA2, MSDC_STA_FIFOCLR);
	
	if((status1 = SD2_Send_Cmd(SDC_CMD_CMD24,data_adrs))!=NO_ERROR)
		ASSERT(0);
	if((status1 = SD2_CheckStatus())!=NO_ERROR)
		ASSERT(0);

	bufIndex = 0;
	loopIndex = 0;
	/*move data from FIFO to buffer*/
	while(((bufIndex*4)<=size) && (loopIndex < 50000)){
		if(MSDC_Reg32(MSDC_STA2)&MSDC_STA_BE){
			MSDC_WriteReg32(MSDC_DAT2, msdc2_writeBuffer[bufIndex]);
			bufIndex ++;
		}
		loopIndex++;
	}

	/*MCU runs much faster than SD interface, give some delay*/
	while(bufIndex < 5000){
		bufIndex++;
	}

	if(SDC_DATSTA_BLKDONE != MSDC_Reg32(SDC_DATSTA2))
		ASSERT(0);

	if(KAL_FALSE == msdcDoNotRST2){
		/*RST MSDC or index may not reset well*/
		MSDC_LSD_SetBits32(MSDC_CFG2,MSDC_CFG_RST);
		bufIndex= 5000;
		while(bufIndex--);
		MSDC_LSD_ClearBits32(MSDC_CFG2,MSDC_CFG_RST);
		bufIndex= 50000;
		while(bufIndex--);
	}
	/*write FIFOCLR to reset FIFO index*/
	MSDC_WriteReg32(MSDC_STA2, MSDC_STA_FIFOCLR);
	
	if((status1 = SD2_Send_Cmd(SDC_CMD_CMD17,data_adrs))!=NO_ERROR)	
		ASSERT(0);
	if((status1 = SD2_CheckStatus())!=NO_ERROR)
		ASSERT(0);

	bufIndex = 0;
	loopIndex = 0;
	/*move data from FIFO to buffer*/
	while(((bufIndex*4)<=size) && (loopIndex < 50000)){
		if(MSDC_Reg32(MSDC_STA2)&MSDC_STA_FIFOCNT){
			msdc2_testBuffer[bufIndex] = MSDC_Reg32(MSDC_DAT2);
			bufIndex ++;
		}
		loopIndex = 0;
	}

	/*compare*/
	bufIndex = 0;
	
	for(bufIndex = 0; bufIndex < size; bufIndex++){
		if(*(bufPtr + bufIndex) != *(writeBufPtr+bufIndex))
			ASSERT(0);
	}
	
	return status1;
}
#endif


SDC_CMD_STATUS SD2_Initialize(void)
{
	kal_uint32 cid[4],csd[4],scr[4];
	kal_uint32 i;
	kal_uint16 rca;
	SDC_CMD_STATUS status;

#if !defined(__UBL__) && !defined(__FUE__)
	#if !defined (__MSDC_DUAL_CARD_SWITCH__)
	MSDC2_turnOnVMC(KAL_FALSE);	
	#endif
	// Delay 10ms to make sure vmc off stable. According to SA's comments.
	for (i = 0; i < 5; i++)
        ust_busy_wait(2000);	
	MSDC2_turnOnVMC(KAL_TRUE);  
	
#endif//!defined(__UBL__) && !defined(__FUE__)
	gMSDC2_Handle->tuningTopology.HighSpeed = SD2_ClkTuning_FeedbackClk;//SD_ClkTuning_AutoCalibrate;
	gMSDC2_Handle->tuningTopology.NormalSpeed1 = SD2_ClkTuning_FeedbackClk;
	gMSDC2_Handle->tuningTopology.NormalSpeed2 = NULL;//SD_ClkTuning_ManualCalibrate;

#ifdef __CARD_DOWNLOAD__

    if (MSDC2_QueryIsPowerControllable())
    {	
    	/* fix [MAUI_02438803] The popup of card plug in/out keeps coming continuosly. */
        //MSDC_SetPower(KAL_FALSE);
        //kal_sleep_task(2);
        MSDC_SetPower(KAL_TRUE);
    }

#endif//__CARD_DOWNLOAD__

	if(gMSDC2_Handle->mIsInitialized == KAL_TRUE)
	{
		return NO_ERROR;
	}
	
#if !defined(__UBL__) && !defined(__FUE__)
    #ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/
	if(KAL_FALSE == INT_QueryExceptionStatus())
    #endif
	// reset the events
	kal_set_eg_events(gMSDC2_Handle->MSDC_Events, 0, KAL_AND);
#endif//!defined(__UBL__) && !defined(__FUE__)
	
	// reset msdc
	Reset_MSDC2();
	MSDC2_IOInit();
	MSDC2_ClockInit();	

	// default disable 4-bit
	MSDC_ClearBits32(SDC_CFG2,SDC_CFG_MDLEN);
	// initial global sturctures
	SD2_SetDefault();

	MSDC2_SetLatchTuning();

	/* enable 74 SD clk by s/w */
	MSDC_SetBits32(MSDC_CFG2, 0x80);
	{		
	//	for(i=0;i<100000;i++);
		ust_busy_wait(1500);
	}
	/* stop SD clk by s/w */
	MSDC_ClearBits32(MSDC_CFG2, 0x80);

	// send the card to IDLE state
	status = SD2_Reset();
	SD_INITIALIZE_STATUS_CHECK();

	// and validate the OCR  (CMD0,CMD1 or ADMD41)
	if(SD2_CheckSDorMMC() == UNKNOWN_CARD)
	{
		SD_TRACE2(TRACE_GROUP_5, MSDC_GENERAL_FAIL, MSDC_DRV_TRC_FILE_SD, __LINE__);
		status = ERR_STATUS;
		goto err;
	}

	// get CID(CMD2)
	status = SD2_GetCID(cid);
	SD_INITIALIZE_STATUS_CHECK();
	// get or set RCA(CMD3)
	status = SD2_ValidateRCA(&rca);
	SD_INITIALIZE_STATUS_CHECK();
	// get CSD and analysis the CSD(CMD9)
	status = SD2_GetCSD(gSD2->mRCA,csd);
	SD_INITIALIZE_STATUS_CHECK();
	
	// Set driver stage register DSR to default value (0x0404)(CMD4)
	if(gSD2->mCSD.dsr_imp)
		if((status = SD2_SetDSR())!=NO_ERROR)
		{
			//dbg_print("6\r\n");
			SD_TRACE2(TRACE_GROUP_5, MSDC_GENERAL_FAIL, MSDC_DRV_TRC_FILE_SD, __LINE__);
			goto err;
		}
	
	#if !defined(__MSDC_NO_WRITE_PROTECT__)
	// check write proctect switch(WP at SDC_STA)
	{
		if((MSDC_Reg32(SDC_STA2) & SDC_STA_WP))
		{
			gSD2->mWPEnabled = KAL_TRUE;
			kal_print("[MSDC]WP\r\n");
		}
	}
	#endif
	
	// select the card (CMD7) ,maybe locked 
	status = SD2_SelectCard(gSD2->mRCA);
	SD_INITIALIZE_STATUS_CHECK();
	if(status == CARD_IS_LOCKED)
		gSD2->mIsLocked = KAL_TRUE;
	//default 1 bit data line.
		status = SD2_ReadSCR(scr);
		SD_INITIALIZE_STATUS_CHECK();

		#if defined(MSDC2_SD_BITS4_BUS)
		if(KAL_FALSE == gMSDC2_Handle->trySingleLine){
			status = SD2_SetBusWidth(BIT_4W);
			SD_INITIALIZE_STATUS_CHECK();
			
		}
		#endif
		

		status = SD2_Acmd42(KAL_FALSE);
		SD_INITIALIZE_STATUS_CHECK();

		
		if(gSD2->flags & SD_FLAG_CMD6_SUPPORT)
		{
			status = SD2_SelectHighSpeed_SD11();
			if(status == NO_ERROR)
			{
				kal_print("SD2_SelectHighSpeed_SD11 Success.\r\n");
				gSD2->flags |= SD_FLAG_HS_ENABLED;
			}
		}

#ifdef DRV_MSDC_CLK_SEARCH
	status = SD2_tuneCLK2();
	if(0 != status)
	{
		if (status == ERR_CMDOK_DATREADFAIL) 
		{
		//SD_TRACE2(TRACE_GROUP_5, MSDC_ERROR_TUNECLKFAIL, MSDC_Reg32(MSDC_CFG), MSDC_Reg32(MSDC_IOCON));
			gMSDC2_Handle->msdc_clkTuneUpperBund = 0;
			return ERR_CMDOK_DATREADFAIL;
	  }
		else
		{
			gMSDC2_Handle->msdc_clkTuneUpperBund = status;
			status = NO_ERROR;
		}
	}
	else
	{
		SD_TRACE2(TRACE_GROUP_5, MSDC_ERROR_TUNECLKFAIL, MSDC_Reg32(MSDC_CFG2), MSDC_Reg32(MSDC_IOCON2));
		status = ERR_ERRORS;
		goto err;
	}
#else
	MSDC2_SetClockSource(MSDC_CLOCK_MCU);
	gMSDC2_Handle->msdc_clock = MSDC_CLOCK;
	MSDC2_SetClock(26000);
#endif
	// set block length (CMD16)
	status = SD2_SetBlength(512);
	SD_INITIALIZE_STATUS_CHECK();
err:
	if(status != NO_ERROR)
	{
		kal_print("SD mount fail!");
		SD2_SetDefault();
		gMSDC2_Handle->mIsInitialized = KAL_FALSE;
		gMSDC2_Handle->mIsPresent = KAL_FALSE;
		MSDC2_turnOnVMC(gMSDC2_Handle->mIsPresent);
	}
	else
	{
		kal_print("SD mount ok!");
		gMSDC2_Handle->mIsInitialized = KAL_TRUE;
	}
	kal_set_eg_events(gMSDC2_Handle->MSDC_Events, 0, KAL_AND);
	// Modify the return value to a general value to make dclsd_control can identify this in switch case.
	return ((status == NO_ERROR) ? NO_ERROR : ERR_STATUS);
}

static kal_uint32 power2(kal_uint32 num)
{
   return 1 << num;
}

void SD2_AnalysisCSD(kal_uint32* csd)
{	
	kal_uint8 *ptr;
	kal_uint32 c_mult,c_size;
	
	ptr = (kal_uint8*)csd;
	c_mult = c_size = 0;
	// these offsets refer to the spec. of SD and MMC 
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.csd_ver, ptr, 126,2);	
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.tacc,ptr,112,8);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.nsac,ptr,104,8);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.tran_speed,ptr,96,8);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.ccc,ptr,84,12);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.r_blk_len,ptr,80,4);
	gSD2->mCSD.r_blk_len = power2(gSD2->mCSD.r_blk_len);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.r_blk_part,ptr,79,1);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.w_blk_misali,ptr,78,1);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.r_blk_misali,ptr,77,1);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.dsr_imp,ptr,76,1);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.w_blk_part,ptr,21,1);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.w_blk_len,ptr,22,4);
	gSD2->mCSD.w_blk_len = power2(gSD2->mCSD.w_blk_len);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.wp_grp_enable,ptr,31,1);
	GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.temp_wp, ptr, 12, 1);
    GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.perm_wp, ptr, 13, 1);
	if(gSD2->mCSD.temp_wp || gSD2->mCSD.perm_wp)
        gSD2->mWPEnabled = KAL_TRUE;
	// there are some difference of CSD between SD and MMC
	if(gMSDC2_Handle->mMSDC_type == MMC_CARD || gMSDC2_Handle->mMSDC_type == MMC42_CARD)
	{
		GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.spec_ver, ptr, 122,4);		
		GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.erase_sec_size_mmc,ptr,42,5);
		gSD2->mCSD.erase_sec_size_mmc = (gSD2->mCSD.erase_sec_size_mmc+1)*gSD2->mCSD.w_blk_len; 
		GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.erase_grp_size_mmc,ptr,37,5);
		gSD2->mCSD.erase_grp_size_mmc = (gSD2->mCSD.erase_grp_size_mmc+1)*gSD2->mCSD.erase_sec_size_mmc;
		GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.wp_grp_size_mmc,ptr,32,5);		
		gSD2->mCSD.wp_grp_size_mmc = (gSD2->mCSD.wp_grp_size_mmc + 1)*gSD2->mCSD.erase_grp_size_mmc;	
	}
	else // SD_CARD
	{
		GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.erase_sec_size_sd,ptr,39,7);
		gSD2->mCSD.erase_sec_size_sd += 1;
		GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.wp_prg_size_sd,ptr,32,7);
		gSD2->mCSD.wp_prg_size_sd = (gSD2->mCSD.wp_prg_size_sd+1) * gSD2->mCSD.erase_sec_size_sd;
		GetBitFieldN_2((kal_uint8*)&gSD2->mCSD.erase_blk_en_sd,ptr,46,1);
	}
	
	if(gMSDC2_Handle->mMSDC_type == SD20_HCS_CARD && gSD2->mCSD.csd_ver >= SD_CSD_VER_20)
	{
		GetBitFieldN_2((kal_uint8*)&c_size,ptr,48,22);
		gSD2->mBKNum = (c_size+1);
		gSD2->mCSD.capacity = (kal_uint64)gSD2->mBKNum*512*1024;
	}
	else
	{
		GetBitFieldN_2((kal_uint8*)&c_mult,ptr,47,3);
		c_mult = power2(c_mult+2);
		GetBitFieldN_2((kal_uint8*)&c_size,ptr,62,12);
		gSD2->mBKNum = (c_size+1)*c_mult;
		gSD2->mCSD.capacity = (kal_uint64)(c_size+1)*(kal_uint64)c_mult*(kal_uint64)gSD2->mCSD.r_blk_len;
	}
	
}


void SD2_AnalysisCID(kal_uint32* cid)
{
	kal_uint8	i;
	kal_uint8* pcid;
	pcid = (kal_uint8*)cid;


		gSD2->mCID.mid = *(pcid+15);
		gSD2->mCID.oid = *(pcid+13) + 256*(*(pcid+14));
		for(i=0;i<5;i++)
			gSD2->mCID.pnm[i] = *(pcid+8+i);
		gSD2->mCID.prv = *(pcid+7);
		//gSD2->mCID.psn = *(kal_uint32*)(pcid+3);
		gSD2->mCID.psn = (*(kal_uint32*)(pcid+4)<<8)|*(pcid+3);
		gSD2->mCID.month = (kal_uint8)GET_BIT(*(pcid+1),0,BIT_MASK_4);
		gSD2->mCID.year = GET_BIT(*(pcid+1),4,BIT_MASK_4)+16*GET_BIT(*(pcid+2),0,BIT_MASK_4) + 2000;

	#ifdef MSDC_TRACE_LEVEL1
	drv_trace2(TRACE_GROUP_6, MSDC_INFORM_CID, gSD2->mCID.mid, gSD2->mCID.oid);
	#endif
}



void SD2_AnalysisSCR(kal_uint32* scr)
{
	kal_uint8 *pscr;

	pscr = (kal_uint8*)scr;
	gSD2->mSCR.spec_ver = (SD_SPEC)((kal_uint8)GET_BIT(*(pscr),0,BIT_MASK_4));
	if(gSD2->mSCR.spec_ver > SD_SPEC_101)
		gSD2->flags |= SD_FLAG_CMD6_SUPPORT;
	gSD2->mSCR.dat_after_erase = (kal_uint8)GET_BIT(*(pscr+1),7,BIT_MASK_1);
	gSD2->mSCR.security = (kal_uint8)GET_BIT(*(pscr+1),4,BIT_MASK_3);
	gSD2->mSCR.bus_width = (kal_uint8)GET_BIT(*(pscr+1),0,BIT_MASK_4);
}


SDC_CMD_STATUS SD2_WaitCmdRdyOrTo(void)
{

	MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
	#ifdef MSDC_TRACE_LEVEL2
	drv_trace2(TRACE_GROUP_7, MSDC_EVENTGP_MONITOR, ((EV_GCB *)gMSDC2_Handle->MSDC_Events)->ev_current_events, __LINE__);
	#endif		
	{
	volatile kal_uint16 sdc_cmdsta;
	kal_uint32 t1;

	t1 = drv_get_current_time();
	do
	{
        SD2_CheckTimeoutWithSleep(t1,  MSDC_TIMEOUT_PERIOD_CMD*11,1);
		sdc_cmdsta = MSDC_Reg32(SDC_CMDSTA2);

	} while (!sdc_cmdsta && MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout);
	MSDC2_STOP_TIMER();
	#ifdef MSDC_TRACE_LEVEL2
	drv_trace2(TRACE_GROUP_7, MSDC_EVENTGP_MONITOR, ((EV_GCB *)gMSDC2_Handle->MSDC_Events)->ev_current_events, __LINE__);
	#endif
	MSDC2_CLR_INT();
	gMSDC2_Handle->cmd_sta = sdc_cmdsta;
	if(sdc_cmdsta & SDC_CMDSTA_CMDTO)            
	{
	#ifdef MSDC_TRACE_LEVEL2
		drv_trace4(TRACE_GROUP_4, MSDC_ERROR_CMDTIMEOUT, sdc_cmdsta, drv_get_current_time(),
			MSDC_Reg32(SDC_STA2), MSDC_Reg32(MSDC_IOCON2));
        #endif
		return ERR_CMD_TIMEOUT;
	}
	else if(sdc_cmdsta & SDC_CMDSTA_RSPCRCERR)   
	{
	#ifdef MSDC_TRACE_LEVEL1
		drv_trace4(TRACE_GROUP_4, MSDC_ERROR_RSPCRC, sdc_cmdsta, drv_get_current_time(),
			MSDC_Reg32(SDC_STA2), MSDC_Reg32(MSDC_IOCON2));
        #endif
		return ERR_CMD_RSPCRCERR;
	}
	else if(sdc_cmdsta & SDC_CMDSTA_CMDRDY)      
		return NO_ERROR;                                     	
	}
	if(gMSDC2_Handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
	
	return NO_ERROR;
}


SDC_CMD_STATUS SD2_WaitDatRdyOrTo(void)
{
	MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
	
	{
	volatile kal_uint16 sdc_datsta;	
	kal_uint32 t1;

	t1 = drv_get_current_time();
	do
	{
        SD2_CheckTimeoutWithSleep(t1, MSDC_TIMEOUT_PERIOD_DAT * 11,1);
		sdc_datsta = MSDC_Reg32(SDC_DATSTA2);
	} while (!sdc_datsta && MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout);
	MSDC2_STOP_TIMER();
	MSDC2_CLR_INT();
	gMSDC2_Handle->dat_sta = sdc_datsta;

	if(KAL_TRUE == kal_query_systemInit()){
		#if defined(MSDC_TRACE_LEVEL3)
		MSDC2_add_dbg_msg(msdc_dbg_event_SD_datsta_systemInit, gMSDC2_Handle->dat_sta, gMSDC2_Handle->is_timeout);
		#endif
	}
	
	if(sdc_datsta & SDC_DATSTA_DATTO)              
	{
		kal_print("[MSDC]:dat timeout");
		#ifdef MSDC_TRACE_LEVEL1
		drv_trace4(TRACE_GROUP_4, MSDC_ERROR_DATTIMEOUT, sdc_datsta, drv_get_current_time(),
			MSDC_Reg32(SDC_STA2), MSDC_Reg32(MSDC_IOCON2));
                #endif
		return ERR_DAT_TIMEOUT;                    
	}
	else if(sdc_datsta & SDC_DATSTA_DATCRCERR)     
	{
	#ifdef MSDC_TRACE_LEVEL1
		drv_trace4(TRACE_GROUP_4, MSDC_ERROR_DATCRC, sdc_datsta, drv_get_current_time(),
			MSDC_Reg32(SDC_STA2), MSDC_Reg32(MSDC_IOCON2));
        #endif
		return ERR_DAT_CRCERR;                     
	}
	else if(sdc_datsta & SDC_DATSTA_BLKDONE)       
		return NO_ERROR;                                     
	}
	if(gMSDC2_Handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
	
	return NO_ERROR;
}


extern kal_bool FTL_isPollingMode(void);


kal_uint32 direct_msdc_entry2=0;
SDC_CMD_STATUS SD2_WaitCardNotBusy(void)
{
	kal_uint32 t1, t2;
	kal_uint16 exec_times = 0;
   kal_uint32 	flags = 0;
//   register kal_uint16 msdc_int;

	t1 = drv_get_current_time();
	MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
   t2 = drv_get_current_time();
   MSDC_SLA_Start_Logging("R1B");
#if defined(R1B_INTERRUPT_MODE)
if(kal_query_systemInit() == KAL_TRUE 
#ifdef  __TST_WRITE_TO_FILE__	/*error recording: considering error recording additionally*/
   || (KAL_TRUE == INT_QueryExceptionStatus())
#endif
   )
{
   while(SD2_IS_R1B_BUSY && MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
   {
   	  if(SD2_CheckTimeoutWithSleep(t1,MSDC_TIMEOUT_PERIOD_DAT*11,1)){
         drv_trace1(TRACE_GROUP_5, MSDC_FAIL_WAITNOTBUSY_TIMEOUT, MSDC_Reg32(SDC_STA2));
   	 }      
	};
}
else
	{
   kal_set_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_AND);	
//   IRQUnmask(IRQ_MSDC_CODE);

	if(!gMSDC2_Handle->mIsPresent)
		//guilin return
      return ERR_INVALID_CARD;//guilin
  // 	msdc_int = MSDC_Reg32(MSDC_INTR);
	
	//if(msdc_int & MSDC_INT_SDR1BIRQ)
   if(SD2_IS_R1B_BUSY)
   {
	 // direct_msdc_entry++;
     // kal_set_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_OR);	
 //    MSDC_ENABLE_INT();// (deactive)  
	kal_retrieve_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_AND_CONSUME,&flags,KAL_SUSPEND);				
	}
   else
   {
   	 direct_msdc_entry2++;
   }

 //  IRQMask(IRQ_MSDC_CODE);
 //  MSDC_DISABLE_INT();
  // kal_print("receive r1b Interrupt");
#if defined(MSDC_TRACE_LEVEL2) && defined(R1B_INTERRUPT_MODE)
  drv_trace2(TRACE_GROUP_6,MSDC_INFORM_R1B_DEBUG,direct_msdc_entry2,gMSDC2_Handle->LISR_Entry_Count);
  drv_trace8(TRACE_GROUP_6,MSDC_INFORM_R1B_DEBUG_2,gMSDC2_Handle->SDCMDIRQ_Entry_Count, \
  	gMSDC2_Handle->SDMCIRQ_Entry_Count, gMSDC2_Handle->SDDATIRQ_Entry_Count,gMSDC2_Handle->SDR1bIRQ_Entry_count,\
  	gMSDC2_Handle->SDIOIRQ_Entry_Count, gMSDC2_Handle->SDPINIRQ_Entry_Count,0,0);
  #endif
 }
#else	
	{
	while(SD2_IS_R1B_BUSY && MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
	{
		if(SD2_CheckTimeoutWithSleep(t1,MSDC_TIMEOUT_PERIOD_DAT*11,1)){
			drv_trace1(TRACE_GROUP_5, MSDC_FAIL_WAITNOTBUSY_TIMEOUT, MSDC_Reg32(SDC_STA2));
		}
	};
}
#endif
	MSDC_SLA_Stop_Logging("R1B");
	#ifdef MSDC_TRACE_LEVEL2
	drv_trace2(TRACE_GROUP_6, MSDC_INFORM_CARD_PROGRAMMING, drv_get_duration_ms(t2), exec_times);
	#endif

	MSDC2_CLR_INT();
	MSDC2_STOP_TIMER();

    if(!SD2_IS_R1B_BUSY && gMSDC2_Handle->is_timeout == KAL_FALSE)//guilin
    	return NO_ERROR;
    else
        return ERR_CMD_TIMEOUT;
}


#ifdef __MAUI_BASIC__
SDC_CMD_STATUS SD2_WaitCardNotBusy_cmd38(void)
{
	kal_uint32 t1, t2;
	kal_uint16 exec_times = 0;
   kal_uint32 	flags = 0;
   register kal_uint16 msdc_int;

	t1 = drv_get_current_time();
	MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT*10);
   t2 = drv_get_current_time();
   MSDC_SLA_Start_Logging("R1B");

#if defined(R1B_INTERRUPT_MODE)
if(kal_query_systemInit() == KAL_TRUE 
#ifdef  __TST_WRITE_TO_FILE__	/*error recording: considering error recording additionally*/
   || (KAL_TRUE == INT_QueryExceptionStatus())
#endif
   )
{
   while(SD2_IS_R1B_BUSY && MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
   {
      if(drv_get_duration_ms(t1) > 1 && kal_query_systemInit() == KAL_FALSE && (KAL_FALSE == INT_QueryExceptionStatus()))
      {
         exec_times ++;
         if (KAL_TRUE == FTL_isPollingMode())
         {	
            MSDC2_BusyWait_ms(5);
         }
         else
         {
            kal_sleep_task(1);
         }
      }
      if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
      {
         drv_trace1(TRACE_GROUP_5, MSDC_FAIL_WAITNOTBUSY_TIMEOUT, MSDC_Reg32(SDC_STA2));

		   gMSDC2_Handle->is_timeout = KAL_TRUE;
      }
	};
}
else
	{

   kal_set_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_AND);	
//   IRQUnmask(IRQ_MSDC_CODE);

	if(!gMSDC2_Handle->mIsPresent)
		//guilin return
      return ERR_INVALID_CARD;//guilin
  // 	msdc_int = MSDC_Reg32(MSDC_INTR);
	
	//if(msdc_int & MSDC_INT_SDR1BIRQ)
   if(SD2_IS_R1B_BUSY)
   {
	 // direct_msdc_entry++;
     // kal_set_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_OR);	
 //    MSDC_ENABLE_INT();// (deactive)  
	kal_retrieve_eg_events(gMSDC2_Handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_AND_CONSUME,&flags,KAL_SUSPEND);				
	}
   else
   {
   	 direct_msdc_entry2++;
   }

 //  IRQMask(IRQ_MSDC_CODE);
 //  MSDC_DISABLE_INT();
  // kal_print("receive r1b Interrupt");
#if defined(MSDC_TRACE_LEVEL2) && defined(R1B_INTERRUPT_MODE)
  drv_trace2(TRACE_GROUP_6,MSDC_INFORM_R1B_DEBUG,direct_msdc_entry2,gMSDC2_Handle->LISR_Entry_Count);
  drv_trace8(TRACE_GROUP_6,MSDC_INFORM_R1B_DEBUG_2,gMSDC2_Handle->SDCMDIRQ_Entry_Count, \
  	gMSDC2_Handle->SDMCIRQ_Entry_Count, gMSDC2_Handle->SDDATIRQ_Entry_Count,gMSDC2_Handle->SDR1bIRQ_Entry_count,\
  	gMSDC2_Handle->SDIOIRQ_Entry_Count, gMSDC2_Handle->SDPINIRQ_Entry_Count,0,0);
  #endif
 }
#else	
	{
	while(SD2_IS_R1B_BUSY && MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
	{
      if(drv_get_duration_ms(t1) > 1 && kal_query_systemInit() == KAL_FALSE && (KAL_FALSE == INT_QueryExceptionStatus()))
      {
			exec_times ++;
			if (KAL_TRUE == FTL_isPollingMode())
			{	
				MSDC2_BusyWait_ms(5);
			}
			else
			{
				kal_sleep_task(1);
		    }
		}
      if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*100) // 15000ms
      {
#ifdef MSDC_TRACE_LEVEL1
			drv_trace1(TRACE_GROUP_5, MSDC_FAIL_WAITNOTBUSY_TIMEOUT, MSDC_Reg32(SDC_STA2));
#endif
			gMSDC2_Handle->is_timeout = KAL_TRUE;
		}
	};
}
#endif
	MSDC_SLA_Stop_Logging("R1B");
	#ifdef MSDC_TRACE_LEVEL2
	drv_trace2(TRACE_GROUP_6, MSDC_INFORM_CARD_PROGRAMMING, drv_get_duration_ms(t2), exec_times);
	#endif

	MSDC2_CLR_INT();
	MSDC2_STOP_TIMER();
#if 0
/* under construction !*/
#else
    if(!SD2_IS_R1B_BUSY && gMSDC2_Handle->is_timeout == KAL_FALSE)//guilin
    	return NO_ERROR;
    else
        return ERR_CMD_TIMEOUT;
#endif
}

#endif // __MAUI_BASIC__



SDC_CMD_STATUS SD2_CheckStatus()
{
	kal_uint32 status;

	MSDC_LSD_ReadReg32(SDC_RESP02,&status);
	#ifdef MSDC_TRACE_LEVEL2
	drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, status, __LINE__);
	#endif
	if((status & SDC_CSTA_MASK)==0 )
		return NO_ERROR;
	if(status &SDC_CARD_IS_LOCKED)
		return CARD_IS_LOCKED;

	return ERR_STATUS;
}


SDC_CMD_STATUS SD2_Send_Cmd(kal_uint32 cmd, kal_uint32 arg)
{
	SDC_CMD_STATUS status;
	kal_uint32 t1;

	t1 = drv_get_current_time();
	MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
	#ifdef MSDC_TRACE_LEVEL2
	drv_trace2(TRACE_GROUP_7, MSDC_EVENTGP_MONITOR, ((EV_GCB *)gMSDC2_Handle->MSDC_Events)->ev_current_events, __LINE__);
	#endif
	// check the controller is ready (stop transaction will fail)
	if(cmd != SDC_CMD_CMD12)		
	{
		while(SD2_IS_SDC_BUSY && MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
		{
            SD2_CheckTimeoutWithSleep(t1, MSDC_TIMEOUT_PERIOD_CMD * 11,1);
		}
	}
	else
	{
		while(SD2_IS_CMD_BUSY && MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
		{
            SD2_CheckTimeoutWithSleep(t1, MSDC_TIMEOUT_PERIOD_CMD * 11,1);
		}
	}
	MSDC2_STOP_TIMER();
	#ifdef MSDC_TRACE_LEVEL1
	drv_trace2(TRACE_GROUP_7, MSDC_EVENTGP_MONITOR, ((EV_GCB *)gMSDC2_Handle->MSDC_Events)->ev_current_events, __LINE__);
	#endif
	if(gMSDC2_Handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
	
	MSDC2_CLR_INT();
	
	gMSDC2_Handle->cmd_sta = MSDC_Reg32(SDC_CMDSTA2);
	gMSDC2_Handle->dat_sta = MSDC_Reg32(SDC_DATSTA2);
	
	#ifdef MSDC_TRACE_LEVEL1
	drv_trace4(TRACE_GROUP_6, MSDC_INFORM_BEFORE_SEND_CMD, gMSDC2_Handle->cmd_sta, gMSDC2_Handle->dat_sta, MSDC_Reg32(SDC_CMD2), __LINE__);
    #endif
    
	// fill out the argument
	MSDC_LSD_WriteReg32(SDC_ARG2,arg);
	// launch the command
	if(0x8D != cmd){
	#ifdef MSDC_TRACE_LEVEL3
		MSDC2_add_dbg_msg(msdc_dbg_event_SD_CMD_issue, cmd, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)));
		MSDC2_add_dbg_msg(msdc_dbg_event_SD_CMD_issue2, arg, MSDC_Reg32(SDC_CFG2));
	#endif
	}
	MSDC_LSD_WriteReg32(SDC_CMD2, cmd | sd_cmd_extra);
	if((status = SD2_WaitCmdRdyOrTo())!=NO_ERROR)
		return status; 

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_Reset(void)
{
	SDC_CMD_STATUS status;

	status = SD2_Send_Cmd(SDC_CMD_CMD0,SDC_NO_ARG);
	gSD2->mState = IDLE_STA;

	return status;
}


SDC_CMD_STATUS SD2_Cmd55(kal_uint16 rca)
{
	SDC_CMD_STATUS status;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD55,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD2_CheckStatus())!=NO_ERROR)
		return status;
	//check APP_CMD bit in status register
	MSDC_LSD_ReadReg32(SDC_RESP02,&status);
	
	#ifdef MSDC_TRACE_LEVEL2
	drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, status, __LINE__);
	#endif
	
	if(!(status & R1_APP_CMD_5))
		return ERR_APPCMD_FAILED;

	return NO_ERROR;	
}



void SD2_Cmd8(void)
{
	kal_uint32 resp;

	if(SD2_Send_Cmd(SDC_CMD_CMD8,SDC_CMD8_ARG)!=NO_ERROR)
	{
		kal_print("SD_Cmd8 fail \r\n");
		SD2_Reset();
		gSD2->mCMD8Resp = SD_CMD8_RESP_NORESP;
		return;
	}
	MSDC_LSD_ReadReg32(SDC_RESP02,&resp);
	
	#ifdef MSDC_TRACE_LEVEL2
	drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, resp, __LINE__);
	#endif
	
	if(resp == SDC_CMD8_ARG)
		gSD2->mCMD8Resp = SD_CMD8_RESP_VALID;
	else
		gSD2->mCMD8Resp = SD_CMD8_RESP_INVALID;
}


SDC_CMD_STATUS SD2_Cmd1_MMC(void)
{
	SDC_CMD_STATUS status;
	kal_uint32 _ocr, ocr_i, t1, t2;


	if(gSD2->mCMD8Resp == SD_CMD8_RESP_INVALID)
		return ERR_CMD8_INVALID;
	ocr_i = (SDC_OCR_DEFAULT|MMC_HIGH_DESITY_CHECK_BIT);


	if(gMSDC2_Handle->is_init_timeout == KAL_TRUE)
		return ERR_R3_OCR_BUSY;
	t2 = drv_get_current_time();
	do{
		t1 = drv_get_current_time();
		MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
		while((MSDC2_IS_BUSY)
			&& MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				gMSDC2_Handle->is_timeout = KAL_TRUE;
		};
		MSDC2_STOP_TIMER();		
		if(gMSDC2_Handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;		

	#ifdef MSDC_TRACE_LEVEL2
	drv_trace4(TRACE_GROUP_6, MSDC_INFORM_BEFORE_SEND_CMD, MSDC_Reg32(SDC_CMDSTA2), MSDC_Reg32(SDC_DATSTA2), MSDC_Reg32(SDC_CMD), __LINE__);
        #endif		
  
		MSDC_LSD_WriteReg32(SDC_ARG2,ocr_i);
		MSDC_LSD_WriteReg32(SDC_CMD2, SDC_CMD_CMD1 | sd_cmd_extra);
		if((status = SD2_WaitCmdRdyOrTo())  != NO_ERROR)
		{
			return status;
		}		
		MSDC_LSD_ReadReg32(SDC_RESP02, &_ocr);
		drv_trace1(TRACE_GROUP_6, MSDC_INFORM_CMD1OCR, _ocr);
		if((_ocr & SDC_OCR_DEFAULT) == 0)
			return ERR_OCR_NOT_SUPPORT;
		if(!gMSDC2_Handle->mIsPresent)
			return MSDC_CARD_NOT_PRESENT;
		
		if(!(_ocr&SDC_OCR_BUSY))		
		{
			if(drv_get_duration_ms(t2) > MSDC_TIMEOUT_PERIOD_INI)
			{
				gMSDC2_Handle->is_init_timeout = KAL_TRUE;			
				break;
			}					
			if((kal_query_systemInit() == KAL_TRUE) 
#ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/
				|| (KAL_TRUE == INT_QueryExceptionStatus())
#endif
				|| KAL_TRUE == FTL_isPollingMode()
			)
			{
				MSDC2_BusyWait_ms(30);
			}
			else
			{	
				kal_sleep_task(7);
			}	
				
		}
		else
			break;		
	}while(1);

	if(gMSDC2_Handle->is_init_timeout)
		return ERR_CMD_TIMEOUT;

	if((_ocr & MMC_HIGH_DESITY_CHECK_MSK) == MMC_HIGH_DESITY_CHECK_BIT)
	{
		gSD2->flags |= SD_FLAG_HCS_SUPPORT;
		gMSDC2_Handle->mMSDC_type = MMC42_CARD;
		kal_print("MMC4.2 or higher");
	}
	else
	gMSDC2_Handle->mMSDC_type = MMC_CARD;
	gSD2->mInactive = KAL_FALSE;
	gSD2->mSDC_ocr = _ocr;
	gSD2->mState = READY_STA;
	
	return NO_ERROR;
}


SDC_CMD_STATUS SD2_WaitMSDCNotBusy()
{
	kal_uint32 t1;
	t1 = drv_get_current_time();		
	MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
	while((MSDC2_IS_BUSY)
		&& MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
	{
        SD2_CheckTimeoutWithSleep(t1, MSDC_TIMEOUT_PERIOD_CMD * 11,1);
	};
	MSDC2_STOP_TIMER();
	if(gMSDC2_Handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
	else
		return NO_ERROR;
	
}

SDC_CMD_STATUS SD2_Acmd41_SD(void)
{

	SDC_CMD_STATUS		status;
	kal_uint32			ocr_response = 0,  ocr_i = 0;
	kal_uint32 			t1;
	kal_bool            is_first_time = KAL_TRUE;
	
	if(gSD2->mCMD8Resp == SD_CMD8_RESP_NORESP)
		ocr_i = SDC_OCR_DEFAULT;
	else if(gSD2->mCMD8Resp == SD_CMD8_RESP_VALID)
		ocr_i = (SDC_OCR_DEFAULT|SD_ACMD41_HCS);
	else if(gSD2->mCMD8Resp == SD_CMD8_RESP_INVALID)
		return ERR_CMD8_INVALID;	

	t1 = drv_get_current_time();
	gMSDC2_Handle->is_init_timeout = KAL_FALSE;
	do{
		if((status=SD2_WaitMSDCNotBusy())!=NO_ERROR)
			return status;
		if((status=SD2_Cmd55(SDC_RCA_DEFAULT))!=NO_ERROR)
			return status;
		if((status=SD2_WaitMSDCNotBusy())!=NO_ERROR)
			return status;
		if (is_first_time)
		{//query
			status=SD2_Send_Cmd(SDC_CMD_CMD41_SD , 0);
			is_first_time = KAL_FALSE;
		}			
		else
		{//set
			status=SD2_Send_Cmd(SDC_CMD_CMD41_SD ,ocr_i);
		}
		if(status!=NO_ERROR)
			return status;
		
		MSDC_LSD_ReadReg32(SDC_RESP02, &ocr_response);
		
		#ifdef MSDC_TRACE_LEVEL1
		drv_trace1(TRACE_GROUP_6, MSDC_INFORM_ACMD41OCR, ocr_response);
		#endif
		
		if((ocr_response & SDC_OCR_DEFAULT) == 0)
			return ERR_OCR_NOT_SUPPORT;
		if(!gMSDC2_Handle->mIsPresent)
			return ERR_CARD_NOT_PRESENT;	
		if(!(ocr_response & SDC_OCR_BUSY))		
		{
			if(SD2_CheckTimeoutWithSleep(t1,MSDC_TIMEOUT_PERIOD_INI,7))
			{ 
				gMSDC2_Handle->is_init_timeout = KAL_TRUE;			
				break;			
			}
		}else if (is_first_time)
		{			
			continue;
		}
		else
			break;		
	}
	while(1);
	if(gMSDC2_Handle->is_init_timeout)
		return ERR_R3_OCR_BUSY;

	gSD2->mInactive = KAL_FALSE;
	gSD2->mSDC_ocr = ocr_response;

	gSD2->flags |= SD_FLAG_SD_TYPE_CARD;	
	if(ocr_response & SD_ACMD41_HCS)
	{
		gSD2->flags |= SD_FLAG_HCS_SUPPORT;
		gMSDC2_Handle->mMSDC_type = SD20_HCS_CARD;
		kal_print("SD2.0 or higher");
	}
	else if(gSD2->mCMD8Resp == SD_CMD8_RESP_VALID)
		gMSDC2_Handle->mMSDC_type = SD20_LCS_CARD;
	else
		gMSDC2_Handle->mMSDC_type = SD_CARD;
	gSD2->mState = READY_STA;

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_GetCID(kal_uint32 Cid[4])
{
	int i;
	SDC_CMD_STATUS status;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD2,SDC_NO_ARG))!=NO_ERROR)
		return status;
	//read R2
	for(i=0;i<4;i++)
		MSDC_LSD_ReadReg32((SDC_RESP02+i*sizeof(kal_uint32)), &Cid[i]);
	SD2_AnalysisCID(Cid);
	gSD2->mState = IDENT_STA;
	
	return NO_ERROR;
}


SDC_CMD_STATUS SD2_ValidateRCA(kal_uint16* pRca)
{
	SDC_CMD_STATUS status;
	kal_uint32 resp;
	kal_uint8  state;

	if(gSD2->flags & SD_FLAG_SD_TYPE_CARD )
	{
		//read RCA form card
		if((status = SD2_Send_Cmd(SDC_CMD_CMD3_SD,SDC_NO_ARG))!=NO_ERROR)
			return status;
		//read R6
		MSDC_LSD_ReadReg32(SDC_RESP02, &resp);
		#ifdef MSDC_TRACE_LEVEL1
		drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, resp, __LINE__);
		#endif
		*pRca = resp >>  16;
		gSD2->mRCA =*pRca;
		
	}

	

	gSD2->mState = STBY_STA;
	return NO_ERROR;
}

SDC_CMD_STATUS SD2_SetDSR(void)
{
	return SD2_Send_Cmd(SDC_CMD_CMD4,(kal_uint32)SDC_DSR_DEFAULT<<16);
}



SDC_CMD_STATUS SD2_SelectCard(kal_uint16 rca)
{
	SDC_CMD_STATUS status;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD7,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;
		
	//read R1b
	if((status = SD2_WaitCardNotBusy())!=NO_ERROR)	
		return status;
	if((status = SD2_CheckStatus())!=NO_ERROR)
		return status;

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_GetCSD(kal_uint16 rca, kal_uint32 Csd[4])
{
	SDC_CMD_STATUS status;
	kal_uint32 i;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD9,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;
	// read R2
	for(i=0;i<4;i++)
	{
		MSDC_LSD_ReadReg32((volatile kal_uint32 *)(SDC_RESP02+i*4), &Csd[i]);

	}
	// analysis CSD...
	SD2_AnalysisCSD(Csd);

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_GetAddressedCID(kal_uint16 rca, kal_uint32 Cid[4])
{
	SDC_CMD_STATUS status;
	kal_uint32 i;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD10,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;

	// read R2
	for(i=0;i<4;i++)
	{
		MSDC_LSD_ReadReg32((volatile kal_uint32 *)(SDC_RESP02+i*4), &Cid[i]);

	}
	return NO_ERROR;
}


SDC_CMD_STATUS SD2_StopTrans(kal_bool isTx)
{
	SDC_CMD_STATUS status;
	kal_uint32 retry = 0;

#if defined(SD_STOP_SLOW)
	kal_uint32 t1 = 0;
#endif


	while(retry < 30)
	{
		if((status = SD2_Send_Cmd(SDC_CMD_CMD12,SDC_NO_ARG))!=NO_ERROR)
		{
			retry ++;
		}
		else
		{
			break;
		}
	}
	if(retry >= 30)
	{
		return status;
	}
	if(isTx)
		SD2_WaitCardNotBusy();
	

#ifdef SD_STOP_SLOW 	

		t1 = drv_get_current_time();
		MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT0_LOW);
		while ((SD2_IS_R1B_BUSY)
			&& MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
		{
			if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT0_LOW*11)
				gMSDC2_Handle->is_timeout = KAL_TRUE;
		};
		MSDC2_STOP_TIMER();
		if (gMSDC2_Handle->is_timeout)
		{
		    kal_print("MSDC error: [CMD12]DAT line busy over 250ms");
		   // ASSERT(0);
			return MSDC_GPT_TIMEOUT_ERR;
		}

		t1 = drv_get_current_time();
		MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_CARD_NOT_RDY);
		while (MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
		{
			SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&status);

			//if (((status & R1_CUR_STATE) >> 9) == TRAN_STA)
			if (status & R1_READY_FOR_DATA_8) // fix MAUI_02829325
				break;

			if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
				kal_sleep_task(2);

			if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CARD_NOT_RDY*11)
				gMSDC2_Handle->is_timeout = KAL_TRUE;
		};
		MSDC2_STOP_TIMER();
		if (gMSDC2_Handle->is_timeout)
		{
		    kal_print("MSDC error: [CMD12] card not back to TRANSFER state in 2s");
		   // ASSERT(0);
			return MSDC_GPT_TIMEOUT_ERR;
		}
#endif//SD_STOP_SLOW

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_GetStatus(kal_uint16 rca, kal_uint32* resp)
{
	SDC_CMD_STATUS status;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD13,(kal_uint32)rca <<16))!=NO_ERROR)
		return status;

	MSDC_LSD_ReadReg32(SDC_RESP02,resp);
	#ifdef MSDC_TRACE_LEVEL2
	drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, *resp, __LINE__);
	#endif
	if((*resp) & SDC_CARD_ECC_FAILED)
	{
		#ifdef MSDC_TRACE_LEVEL1
		drv_trace1(TRACE_GROUP_4, MSDC_ERROR_CARDINTERNALECCFAIL, *resp);
		#endif
	}

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_SetBlength(kal_uint32 BKLength)
{
	SDC_CMD_STATUS status;

	// maximal value of block length is 2048
	if(BKLength > SDC_MAX_BKLENGTH)
		return ERR_INVALID_BKLENGTH;
	if(!gSD2->mCSD.r_blk_part && BKLength < gSD2->mCSD.max_r_blk_len )
		return ERR_INVALID_BKLENGTH;		
	if((status = SD2_Send_Cmd(SDC_CMD_CMD16,BKLength))!=NO_ERROR)
		return status;
	//read R1
	status = SD2_CheckStatus();		
	// 2. configure the controller
	gSD2->mBKLength = BKLength;
	BitFieldWrite32_2((kal_uint32*)SDC_CFG2,BKLength,SDC_CFG_BLKLEN);

	return NO_ERROR;
}


kal_bool SD2_CheckTimeoutWithSleep(kal_int32 start_time,
                         kal_int32 duration_ms,
                         kal_int32 sleep_time)
{
    kal_int32 elapsed_time = drv_get_duration_ms(start_time);
    //check timeout or not
    if(elapsed_time > duration_ms)
    {
        gMSDC2_Handle->is_timeout = KAL_TRUE;
    }
	else
    {
    	gMSDC2_Handle->is_timeout = KAL_FALSE;
    }
	if ((elapsed_time > 10)
		&& (KAL_FALSE == kal_query_systemInit())
#ifdef  __TST_WRITE_TO_FILE__/*error recording: considering error recording additionally*/
        && (KAL_FALSE == INT_QueryExceptionStatus())
#endif
        && (KAL_FALSE == FTL_isPollingMode())
#if !defined(__UBL__) && !defined(__FUE__)
        && (KAL_FALSE == kal_if_hisr())
        && (KAL_FALSE == kal_if_lisr())
#endif
		)
        {
            kal_sleep_task(sleep_time);
        }

    return gMSDC2_Handle->is_timeout;

}


#ifdef LOW_COST_SUPPORT
SDC_CMD_STATUS SD2_ReadSingleBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer) // slim
{
    return SD2_ReadMultiBlock(data_adrs,rxbuffer,1); // slim
}
#else
SDC_CMD_STATUS SD2_ReadSingleBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer)
{
	kal_uint32 count, whileIndex;
	SDC_CMD_STATUS status;

	
	EnableMSDC2_DMA();
	count = MSDC_SD_BLOCK_SIZE;
	MSDC2_DMATransferFirst((kal_uint32)rxbuffer,count,KAL_FALSE);
	if((status = SD2_Send_Cmd(SDC_CMD_CMD17,data_adrs))!=NO_ERROR)	
		goto ERR_Exit;
	if((status = SD2_CheckStatus())!=NO_ERROR)
		goto ERR_Exit;
	status = MSDC2_DMATransferFinal();
	if(status != NO_ERROR)
	{
		#if defined(MSDC_TRACE_LEVEL3)
		MSDC2_add_dbg_msg(msdc_dbg_event_SD_datTimeOut_sta, MSDC_Reg32(SDC_DATSTA2), gMSDC2_Handle->dat_sta);
		#endif
		goto ERR_Exit;			
	}		
	if((status = SD2_WaitDatRdyOrTo())!=NO_ERROR)
		goto ERR_Exit;
	
	DisableMSDC2_DMA();
	MSDC2_CLR_FIFO();
	
#ifdef SD_STOP_SLOW 	
		{
			kal_uint32 cardStatus;
			whileIndex = 0x40000;
			while(SD2_IS_R1B_BUSY && whileIndex) 
				whileIndex--;
			whileIndex = 0x100;
			do{	
				status = SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&cardStatus);
				if(NO_ERROR != status){
					kal_print("[MSDC]CMD13 fail when singleBlockRead!");
					goto ERR_Exit;
				}
				whileIndex--;
			}while(((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
		}
#endif

	
	Reset_MSDC2();//reset state machine to prevent problem like FIFO not clear or DMA chaos

	return NO_ERROR;
ERR_Exit:
	{
		kal_uint32 tmp;
		

		DisableMSDC2_DMA();
		Reset_MSDC2();

		// SD_StopTrans(KAL_FALSE);		
		SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&tmp);
		MSDC_LSD_ReadReg32(SDC_DATSTA2,&tmp);
		MSDC2_CLR_FIFO();		
		return status;
	}
	
}
#endif


#ifdef LOW_COST_SUPPORT
SDC_CMD_STATUS SD2_ReadMultiBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num) // slim
{
    SDC_CMD_STATUS status;
    kal_uint32 j, count ,whileIndex;
#ifndef MSDC_DMA
    kal_uint32 i;   
#endif
#if defined(__UBL__)
	MSDC2_SET_FIFO(1);
	BitFieldWrite32_2((kal_uint32*)MSDC_IOCON2, (kal_uint32)0, MSDC_IOCON_DMABURST);
#else
    EnableMSDC2_DMA();
#endif
    count = MSDC_SD_BLOCK_SIZE; 
#if !defined(__UBL__)
    MSDC2_DMATransferFirst((kal_uint32)rxbuffer,count*num,KAL_FALSE);    
    //read out data sta to make sure we will read latest one in the future
    gMSDC2_Handle->dat_sta = MSDC_Reg32(SDC_DATSTA2);
#endif
    if((status = SD2_Send_Cmd((num==1 ? SDC_CMD_CMD17 : SDC_CMD_CMD18),data_adrs))!=NO_ERROR)

        goto ERR_Exit;
    if((status = SD2_CheckStatus())!=NO_ERROR)
        goto ERR_Exit;  
    count = MSDC_SD_BLOCK_SIZE; 
#if defined(__UBL__)
	{
		kal_uint32 t1;
		whileIndex = 0;
		while(1)
		{
			t1 = drv_get_current_time();
			if(MSDC_Reg32(MSDC_STA2)&MSDC_STA_DRQ)
			{
			//	tmpdata = DRV_Reg32(MSDC_DAT);
			//	*(rxbuffer+whileIndex) = tmpdata;
			*(rxbuffer+whileIndex) = DRV_Reg32(MSDC_DAT2);


				whileIndex++;
				if(whileIndex >= (count*num))
					break;

				t1 = drv_get_current_time();
			}
			else
			{		
				if(drv_get_duration_ms(t1)>= MSDC_TIMEOUT_PERIOD_DAT*11 )
				{
					gMSDC2_Handle->is_timeout = KAL_TRUE;
					goto ERR_Exit;
				}
				
			}

		}
  
   }
#else
    status = MSDC2_DMATransferFinal();
#endif
#if !defined(__UBL__)
    if(status != NO_ERROR){
        gMSDC2_Handle->dat_sta = MSDC_Reg32(SDC_DATSTA2);
        
	#ifdef MSDC_TRACE_LEVEL3
        MSDC2_add_dbg_msg(msdc_dbg_event_SD_datTimeOut_sta, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), gMSDC2_Handle->dat_sta);
	#endif
        if(gMSDC2_Handle->dat_sta & SDC_DATSTA_DATTO)              
        { 
		#ifdef MSDC_TRACE_LEVEL1            
            //kal_print("[MSDC]:dat timeout");
		#endif
        }
        if(gMSDC2_Handle->dat_sta & SDC_DATSTA_DATCRCERR)     
        {
	        #ifdef MSDC_TRACE_LEVEL1 
            //kal_print("[MSDC]:dat crc");
		#endif
        }   
	#ifdef MSDC_TRACE_LEVEL1
        drv_trace1(TRACE_GROUP_5, MSDC_FAIL_CMD18_DMA_TRANSFER, gMSDC2_Handle->dat_sta);
	#endif
            goto ERR_Exit;  
    }
#endif
    if((status = SD2_WaitDatRdyOrTo())!=NO_ERROR)
        goto ERR_Exit;
    
    Reset_MSDC2();
    MSDC2_CLR_INT();
#if !defined(__UBL__)
    DisableMSDC2_DMA();
#endif
if(num==1)
{
#ifdef SD_STOP_SLOW 	
    {
        kal_uint32 cardStatus;
        whileIndex = 0x40000;
        while(SD2_IS_R1B_BUSY && whileIndex) 
            whileIndex--;
        whileIndex = 0x100;
        do{ 
            status = SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&cardStatus);
            if(NO_ERROR != status){
                //kal_print("[MSDC]CMD13 fail when singleBlockRead!");
                goto ERR_Exit;
            }
            whileIndex--;
        }while(((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
    }
#endif
}
else
{
    if(gSD2->flags & SD_FLAG_MMC_MRSW_FAIL)
    {
        kal_uint32 delay = 200;
        while(delay--);     
    }
    if((status = SD2_StopTrans(KAL_FALSE))!=NO_ERROR)
    {
        //if((data_adrs/gSD->mBKLength + j) < gSD->mBKNum)          
            goto ERR_Exit;      
    }
}
    MSDC2_CLR_FIFO();    


    Reset_MSDC2();//reset state machine to prevent problem like FIFO not clear or DMA chaos
	
    return NO_ERROR;
    
ERR_Exit:


    DisableMSDC2_DMA();
    Reset_MSDC2();       
    if(num>1)
        SD2_StopTrans(KAL_FALSE);        
    SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&j);
    MSDC_LSD_ReadReg32(SDC_DATSTA2,&j);
    MSDC2_CLR_FIFO();
    return status;
    
}
#else
SDC_CMD_STATUS SD2_ReadMultiBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num)
{
	SDC_CMD_STATUS status;
	kal_uint32 j, count;
	#ifndef MSDC_DMA
	kal_uint32 i;	
	#endif

	EnableMSDC2_DMA();
	count = MSDC_SD_BLOCK_SIZE;	
	MSDC2_DMATransferFirst((kal_uint32)rxbuffer,count*num,KAL_FALSE);	

	//read out data sta to make sure we will read latest one in the future
	gMSDC2_Handle->dat_sta = MSDC_Reg32(SDC_DATSTA2);
	if((status = SD2_Send_Cmd(SDC_CMD_CMD18,data_adrs))!=NO_ERROR)
	
		goto ERR_Exit;
	if((status = SD2_CheckStatus())!=NO_ERROR)
		goto ERR_Exit;	
	count = MSDC_SD_BLOCK_SIZE;	
	status = MSDC2_DMATransferFinal();
	if(status != NO_ERROR){
		gMSDC2_Handle->dat_sta = MSDC_Reg32(SDC_DATSTA2);
		
		#ifdef MSDC_TRACE_LEVEL3
		MSDC2_add_dbg_msg(msdc_dbg_event_SD_datTimeOut_sta, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), gMSDC2_Handle->dat_sta);
		#endif
		if(gMSDC2_Handle->dat_sta & SDC_DATSTA_DATTO)              
		{ 
			#ifdef MSDC_TRACE_LEVEL1            
			kal_print("[MSDC2]:dat timeout");
			#endif
		}
		if(gMSDC2_Handle->dat_sta & SDC_DATSTA_DATCRCERR)     
		{
		        #ifdef MSDC_TRACE_LEVEL1 
			kal_print("[MSDC2]:dat crc");
			#endif
		}	
		#ifdef MSDC_TRACE_LEVEL1
		drv_trace1(TRACE_GROUP_5, MSDC_FAIL_CMD18_DMA_TRANSFER, gMSDC2_Handle->dat_sta);
		#endif
			goto ERR_Exit;	
	}

	if((status = SD2_WaitDatRdyOrTo())!=NO_ERROR)
		goto ERR_Exit;
	
	
	MSDC2_CLR_INT();
	DisableMSDC2_DMA();

	if(gSD2->flags & SD_FLAG_MMC_MRSW_FAIL)
	{
		kal_uint32 delay = 200;
		while(delay--);		
	}
	if((status = SD2_StopTrans(KAL_FALSE))!=NO_ERROR)
	{
		//if((data_adrs/gSD->mBKLength + j) < gSD->mBKNum)			
			goto ERR_Exit;		
	}
	MSDC2_CLR_FIFO();	

	
	Reset_MSDC2();//reset state machine to prevent problem like FIFO not clear or DMA chaos
	
	return NO_ERROR;
	
ERR_Exit:


	DisableMSDC2_DMA();
	Reset_MSDC2();		
	SD2_StopTrans(KAL_FALSE);		
	SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&j);
	MSDC_LSD_ReadReg32(SDC_DATSTA2,&j);
	MSDC2_CLR_FIFO();
	return status;
	
}
#endif


#if defined(__UBL__)
#pragma arm section code = "EXT_BOOTLOADER_CODE", rwdata = "EXT_BOOTLOADER_RW", zidata = "EXT_BOOTLOADER_ZI"
#endif

#if defined(MT6255)
SDC_CMD_STATUS SD2_DummySingleWrite(kal_uint32 address, kal_uint32 *buf)
{
	SDC_CMD_STATUS status;
	kal_uint32 count;    

    Reset_MSDC2();
	EnableMSDC2_DMA();
	count = MSDC_SD_BLOCK_SIZE;	
	
	MSDC2_DMATransferFirst((kal_uint32)buf,count,KAL_TRUE);	
			
	if((status = SD2_Send_Cmd(SDC_CMD_CMD24,address))!=NO_ERROR)
		return status;
		
	if((status = SD2_CheckStatus())!=NO_ERROR)
		return status;

	status = MSDC2_DMATransferFinal();
	if(status != NO_ERROR)
		return status;	
		
	// wait R1b interrupt because cmd24 is configured as R1b response but cmd25 needn't
	if((status = SD2_WaitCardNotBusy())!=NO_ERROR)	
		return status;	
		 
    if((status = SD2_WaitDatRdyOrTo())!=NO_ERROR)
		return status;
        
	DisableMSDC2_DMA();
	MSDC2_CLR_FIFO();   
	
	return NO_ERROR; 
}
#endif

#ifdef LOW_COST_SUPPORT
SDC_CMD_STATUS SD2_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer) // slim
{
    return SD2_WriteMultiBlock(address, txbuffer, 1); // slim
}
#else
SDC_CMD_STATUS SD2_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer)
{
	SDC_CMD_STATUS status;
	kal_uint32 count, whileIndex;
#ifdef DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION
	kal_uint32 cardStatus = 0;
	kal_uint32 t1 = 0;
#endif
	kal_uint32 *ptr;	


	if(gSD2->mWPEnabled)
		return ERR_WRITE_PROTECT;
	count = MSDC_SD_BLOCK_SIZE;
		
	ptr = txbuffer;
	count = MSDC_SD_BLOCK_SIZE;	
	EnableMSDC2_DMA();
	MSDC2_DMATransferFirst((kal_uint32)ptr,count,KAL_TRUE);	
	if((status = SD2_Send_Cmd(SDC_CMD_CMD24,address))!=NO_ERROR)
		goto ERR_Exit;
	if((status = SD2_CheckStatus())!=NO_ERROR)
		goto ERR_Exit;
	status = MSDC2_DMATransferFinal();
	if(status != NO_ERROR)
		goto ERR_Exit;	
	// wait R1b interrupt because cmd24 is configured as R1b response but cmd25 needn't
	if((status = SD2_WaitCardNotBusy())!=NO_ERROR)	
		 goto ERR_Exit;	
	DisableMSDC2_DMA();
	if((status = SD2_WaitDatRdyOrTo())!=NO_ERROR){
		if (ERR_DAT_CRCERR == status){     
			kal_print("[MSDC2]:dat crc");
#ifdef DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION
			// it's a fake crc error reported due to mis-latch, and R1b is useless.
			kal_sleep_task(55);	// wait for 250 ms (the largest period of programming from spec)

			t1 = drv_get_current_time();
    		MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_CARD_NOT_RDY);
    		while (MSDC2_Check_Card_Present() && !gMSDC2_Handle->is_timeout)
    		{
    			SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&cardStatus);
    			if (((cardStatus & R1_CUR_STATE) >> 9) == TRAN_STA)
    				break;

    			if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
    				kal_sleep_task(2);

    			if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CARD_NOT_RDY*11)
    				gMSDC2_Handle->is_timeout = KAL_TRUE;
    		};
    		MSDC2_STOP_TIMER();
    		if (gMSDC2_Handle->is_timeout)
    		{
    		    kal_print("MSDC error: [CMD24] card not back to TRANSFER state in 2s");
    		    //ASSERT(0);
    			return MSDC_GPT_TIMEOUT_ERR;
    		}
#endif
		}
		else if (ERR_DAT_TIMEOUT == status)
			ASSERT(0);
		goto ERR_Exit;
	}
	
#ifdef SD_STOP_SLOW 	
		{
			kal_uint32 cardStatus; 
                        //wait 1.2s at moust.
			whileIndex = 0x100;
			while(SD2_IS_R1B_BUSY && whileIndex) 
			{
			   if((kal_query_systemInit() == KAL_TRUE) 
            #ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/
				|| (KAL_TRUE == INT_QueryExceptionStatus())
            #endif
				|| KAL_TRUE == FTL_isPollingMode()
			    )
				{
					MSDC2_BusyWait_ms(4);
				}
				else
				{
					kal_sleep_task(1);
		                 }
				whileIndex--;
			}
			whileIndex = 0x100;
			do{	
				status = SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&cardStatus);
				if(NO_ERROR != status){
					kal_print("[MSDC]CMD13 fail when singleBlockWrite!");
					goto ERR_Exit;				
				}
				whileIndex--;
			}while(((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
		}
#endif

	return NO_ERROR;
ERR_Exit:
	{
		kal_uint32 tmp;
		

		DisableMSDC2_DMA();
		Reset_MSDC2();
		//SD_StopTrans(KAL_TRUE);		
		SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&tmp);
		MSDC_LSD_ReadReg32(SDC_DATSTA2,&tmp);
		return status;
	}
	
}
#endif


#ifdef DRV_MSDC_CHECK_MULTIBLOCK_WRITE_FINISHED
#if defined(MT6250)
#define DATA_BUS_NOT_BUSY 0x18000000
#define DATA_BUS_BUSY_MASK 0x1F000000
#elif defined(MT6260)
#define DATA_BUS_NOT_BUSY 0x01800000	
#define DATA_BUS_BUSY_MASK 0x01F00000
#elif defined(MT6261) || defined(MT2502) || defined(MT2501)
#define DATA_BUS_NOT_BUSY 0x01800000	
#define DATA_BUS_BUSY_MASK 0x01F00000
#endif
SDC_CMD_STATUS SD2_WaitLastBlockFinish(void)
{
	kal_int32 t1  = drv_get_current_time();
	kal_int32 val = 0;
	SDC_CMD_STATUS status = NO_ERROR;
    MSDC_WriteReg32(MSDC2_DEBUG_SELECTION, 3);
    do{
        val = MSDC_Reg32(MSDC2_DEBUG_REG);
        if (DATA_BUS_NOT_BUSY == (val & DATA_BUS_BUSY_MASK))
        {
            status = NO_ERROR;
			break;
        }
		if(SD2_CheckTimeoutWithSleep(t1,10,1))
		{
			status = MSDC_GPT_TIMEOUT_ERR;
			break;
		}
    }while(1);

	return status;
}
#endif


#ifndef LOW_COST_SUPPORT
SDC_CMD_STATUS SD2_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num)
{
	SDC_CMD_STATUS status;
	kal_uint32 count;
		
	if(gSD2->mWPEnabled)
		return ERR_WRITE_PROTECT;
    #if defined(MT6255)
    if ((INT_SW_SecVersion() == SW_SEC_0 )||
        (INT_SW_SecVersion() == SW_SEC_1 )
        ) {
            
        status = SD2_DummySingleWrite(address, txbuffer);
        if (status != NO_ERROR) {
            kal_print("Dummy write fail");
            goto ERR_Exit;        
        }
    }
    #endif
	EnableMSDC2_DMA();	
	count = MSDC_SD_BLOCK_SIZE;	
	
	MSDC2_DMATransferFirst((kal_uint32)txbuffer,count*num,KAL_TRUE);
	if((status = SD2_Send_Cmd(SDC_CMD_CMD25,address))!=NO_ERROR)

		goto ERR_Exit;
	if((status = SD2_CheckStatus())!=NO_ERROR)
		goto ERR_Exit;
	   
	
		status = MSDC2_DMATransferFinal();
		if(status != NO_ERROR){
			#if defined(MSDC_TRACE_LEVEL3)
			MSDC2_add_dbg_msg(msdc_dbg_event_SD_multi_blk_write_issue1, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), status);
			#endif
			//sd_writeFailReason = 1;
			gMSDC2_Handle->dat_sta = MSDC_Reg32(SDC_DATSTA2);
			if(gMSDC2_Handle->dat_sta & SDC_DATSTA_DATTO){
				#ifdef MSDC_TRACE_LEVEL1
				kal_print("[MSDC2]:dat timeout");
                #endif
			}
			if(gMSDC2_Handle->dat_sta & SDC_DATSTA_DATCRCERR){     
				#ifdef MSDC_TRACE_LEVEL1
				kal_print("[MSDC2]:dat crc");
				#endif
			}
			goto ERR_Exit;
		}
		if((status = SD2_WaitDatRdyOrTo())!=NO_ERROR){
			#if defined(MSDC_TRACE_LEVEL3)
			MSDC2_add_dbg_msg(msdc_dbg_event_SD_multi_blk_write_issue2, status, 0);
			#endif
			//sd_writeFailReason = 2;
			goto ERR_Exit;			
		}
	

	DisableMSDC2_DMA();
#if defined(DRV_MSDC_CHECK_MULTIBLOCK_WRITE_FINISHED)	
	if(NO_ERROR != SD2_WaitLastBlockFinish())
		goto ERR_Exit;
#endif	
	if((status = SD2_StopTrans(KAL_TRUE))!=NO_ERROR)
		goto ERR_Exit;
	
	MSDC2_CLR_INT();
	
	return NO_ERROR;
ERR_Exit:
	{
		kal_uint32 tmp;
			
		DisableMSDC2_DMA();
		Reset_MSDC2();
		SD2_StopTrans(KAL_TRUE);		
		SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&tmp);
		MSDC_LSD_ReadReg32(SDC_DATSTA2,&tmp);
		return status;
	}

}
#else
SDC_CMD_STATUS SD2_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num) // slim
{
    SDC_CMD_STATUS status;
	kal_uint32 count, whileIndex;

    
        
    if(gSD2->mWPEnabled)
        return ERR_WRITE_PROTECT;
#if defined(MT6255)
    if ((INT_SW_SecVersion() == SW_SEC_0 )||
        (INT_SW_SecVersion() == SW_SEC_1 )
        ) 
        {
            
        status = SD2_DummySingleWrite(address, txbuffer);
        if (status != NO_ERROR) {
            kal_print("Dummy write fail");
            goto ERR_Exit;        
        }
    }
#endif
    EnableMSDC2_DMA();   
    count = MSDC_SD_BLOCK_SIZE; 


    MSDC2_DMATransferFirst((kal_uint32)txbuffer,count*num,KAL_TRUE);

    if((status = SD2_Send_Cmd((num==1? SDC_CMD_CMD24 : SDC_CMD_CMD25),address))!=NO_ERROR)
        goto ERR_Exit;
    if((status = SD2_CheckStatus())!=NO_ERROR)
        goto ERR_Exit;
       

        status = MSDC2_DMATransferFinal();
        if(status != NO_ERROR){
		#if defined(MSDC_TRACE_LEVEL3)
            MSDC2_add_dbg_msg(msdc_dbg_event_SD_multi_blk_write_issue1, MSDC_Reg(DMA_RLCT(gMSDC2_Handle->msdc_dmaport)), status);
		#endif
            //sd_writeFailReason = 1;
            gMSDC2_Handle->dat_sta = MSDC_Reg32(SDC_DATSTA2);
            if(gMSDC2_Handle->dat_sta & SDC_DATSTA_DATTO){
                #ifdef MSDC_TRACE_LEVEL1
				kal_print("[MSDC2]:dat timeout");
                #endif
            }
            if(gMSDC2_Handle->dat_sta & SDC_DATSTA_DATCRCERR){     
				#ifdef MSDC_TRACE_LEVEL1
                kal_print("[MSDC2]:dat crc");
				#endif
            }
            goto ERR_Exit;
        }
        // wait R1b interrupt because cmd24 is configured as R1b response but cmd25 needn't
        if((num==1)&&((status = SD2_WaitCardNotBusy())!=0))
             goto ERR_Exit; 
        if((status = SD2_WaitDatRdyOrTo())!=NO_ERROR){
		#if defined(MSDC_TRACE_LEVEL3)
            MSDC2_add_dbg_msg(msdc_dbg_event_SD_multi_blk_write_issue2, status, 0);
		#endif
            //sd_writeFailReason = 2;
            goto ERR_Exit;          
        }

    DisableMSDC2_DMA();

#ifdef DRV_MSDC_CHECK_MULTIBLOCK_WRITE_FINISHED
		if((num>1)&&(NO_ERROR != SD2_WaitLastBlockFinish()))
		{			
			goto ERR_Exit;
		}
#endif

    if((num >1)&&((status = SD2_StopTrans(KAL_TRUE)))!=NO_ERROR)
        goto ERR_Exit;

#ifdef SD_STOP_SLOW 	
            if(num ==1){
                kal_uint32 cardStatus;
                //kal_uint32 time1, time2,time3;
                //wait 1.2s at moust.
                //time1 = drv_get_current_time();
                whileIndex = 0x100;
                while(SD2_IS_R1B_BUSY && whileIndex) 
                {
                   if((kal_query_systemInit() == KAL_TRUE) 
                           #ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/
                    || (KAL_TRUE == INT_QueryExceptionStatus())
                           #endif
                    || KAL_TRUE == FTL_isPollingMode()
                    )
                    {
                        MSDC2_BusyWait_ms(4);
                    }
                    else
                    {
                        kal_sleep_task(1);
                             }
                    whileIndex--;
                }
                whileIndex = 0x100;
                do{ 
                    status = SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&cardStatus);
                    if(NO_ERROR != status){
                        kal_print("[MSDC2]CMD13 fail when singleBlockWrite!");
                        goto ERR_Exit;              
                    }
                    whileIndex--;
                }while(((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
            }
#endif

    MSDC2_CLR_INT();
  //  Reset_MSDC2();
if(num>1)
{
	MSDC_LSD_SetBits32(MSDC_STA2,MSDC_STA_FIFOCLR);
	while((MSDC_Reg(MSDC_STA2)&MSDC_STA_FIFOCLR )!=0);
}
    return NO_ERROR;
ERR_Exit:
    {
        kal_uint32 tmp;
        
	
        DisableMSDC2_DMA();
        Reset_MSDC2();
        if(num >1)SD2_StopTrans(KAL_TRUE);     
        SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA2,&tmp);
        return status;
    }

}
#endif
#if defined(__UBL__)
#pragma arm section code, rwdata, zidata
#endif


SDC_CMD_STATUS SD2_SetBusWidth(SD_BITWIDTH width)
{
	SDC_CMD_STATUS status;

	// check if card support 4 bits bus
	if((width == BIT_4W) && !(gSD2->mSCR.bus_width&0x04))
		return ERR_NOT_SUPPORT_4BITS;
	// send APP_CMD
	if((status = SD2_Cmd55(gSD2->mRCA))!=NO_ERROR)
		return status;
	// send cmd6
	if((status = SD2_Send_Cmd(SDC_CMD_ACMD6,width))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD2_CheckStatus())!=NO_ERROR)
		return status;
	if (BIT_4W == width)
	{
    	// set the controler MDLEN to enable 4-bit bus width
    	MSDC_LSD_SetBits32(SDC_CFG2,SDC_CFG_MDLEN);
    	gSD2->bus_width = 4;
    }
    else if (BIT_1W == width)
	{
    	// clear the controler MDLEN to enable 1-bit bus width
    	MSDC_LSD_ClearBits32(SDC_CFG2,SDC_CFG_MDLEN);
    	gSD2->bus_width = 1;
    }

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_ReadSCR(kal_uint32* scr)
{
	SDC_CMD_STATUS status;
	kal_uint32 i, t1;

	ASSERT((kal_uint32)scr % 4  == 0);
	// set block length(MSDC_CFG)
	if((status = SD2_SetBlength(8))!=NO_ERROR)
		return status;
	// send APP_CMD
	if((status = SD2_Cmd55(gSD2->mRCA))!=NO_ERROR)
		return status;
	// send command
	if((status = SD2_Send_Cmd(SDC_CMD_ACMD51,SDC_NO_ARG))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD2_CheckStatus())!=NO_ERROR)
		return status;	
	// read data(8bytes)	
	// failed to use DMA with burst mode
	t1 = drv_get_current_time();
	MSDC2_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
	for(i=0;i<2;)
	{	
        SD2_CheckTimeoutWithSleep(t1, MSDC_TIMEOUT_PERIOD_DAT * 11,1);
		if(!gMSDC2_Handle->mIsPresent)
			return ERR_CARD_NOT_PRESENT;
		if(gMSDC2_Handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;
		if(MSDC_Reg32(MSDC_STA2) & MSDC_STA_DRQ)
		{
			*(kal_uint32*)(scr+i) = MSDC_Reg32(MSDC_DAT2);
			i++;
		}
	}

   
   if((status = SD2_WaitDatRdyOrTo())!=NO_ERROR)
   {
		kal_uint32 retry =0 ;
		while(retry < 30)
		{
			if(( SD2_Send_Cmd(SDC_CMD_CMD12,SDC_NO_ARG))!=NO_ERROR)
			{
				retry ++;
			}
			else
			{
				break;
			}
		}
		return status;	
   }		

	MSDC2_STOP_TIMER();
	// analysis scr
	SD2_AnalysisSCR(scr);

	MSDC2_CLR_FIFO();
	return NO_ERROR;
	
}


SDC_CMD_STATUS SD2_SetPreEraseBlk(kal_uint32 num)
{
	SDC_CMD_STATUS status;

	//[22:0] number of blocks 
	num &= 0x003FFF;
	// send APP_CMD
	if((status = SD2_Cmd55(gSD2->mRCA))!=NO_ERROR)
		return status;
	// send CMD23
	if((status = SD2_Send_Cmd(SDC_CMD_ACMD23,num))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD2_CheckStatus())!=NO_ERROR)
		return status;	

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_EraseCmdClass(kal_uint32 cmd ,kal_uint32 address)
{
	SDC_CMD_STATUS status;
	kal_uint32 sdcard_status;

	if(cmd != SDC_CMD_CMD38)
	{
		if((status = SD2_Send_Cmd(cmd,address))!=NO_ERROR)
			return status;
	}
	else if((status = SD2_Send_Cmd(cmd,SDC_NO_ARG))!=NO_ERROR)
			return status;

	//read R1
	if((status = SD2_CheckStatus())!=NO_ERROR)
		return status;
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
#else
	if(cmd == SDC_CMD_CMD38)
	{
#ifdef __MAUI_BASIC__
        if((status=SD2_WaitCardNotBusy_cmd38())!=NO_ERROR)
            return status;
#else
		if((status=SD2_WaitCardNotBusy())!=NO_ERROR)
		    return status;
#endif
		do{	
    		if((status=SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&sdcard_status))!=NO_ERROR)
    		    return status;
    		if(gMSDC2_Handle->mIsPresent == KAL_FALSE)
    			return ERR_INVALID_CARD;
        }while(CurState(sdcard_status)!= TRAN_STA);
	}
#endif	
	return NO_ERROR;
}


SDC_CMD_STATUS SD2_Switch_MMC40(kal_uint8 access, kal_uint8 index, kal_uint8 value, kal_uint8 set)
{
	SDC_CMD_STATUS status = NO_ERROR;
	kal_uint32 arg = 0;
	kal_uint32 resp = 0;
	kal_bool retry = KAL_FALSE; 
//	remount = KAL_FALSE;
//	kal_uint8 *pData = NULL;

switch_start:

	arg = (access<<24)|(index<<16)|(value<<8)|set;
	// send command
	if ((status = SD2_Send_Cmd(SDC_CMD_CMD6_MMC40,arg))!= NO_ERROR)
	{
		goto ERR_Exit;
	}
	//read R1b
	if((status = SD2_WaitCardNotBusy())!=NO_ERROR)
		goto ERR_Exit;


    SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&status);

	//read R1
	if((status = SD2_CheckStatus())!=NO_ERROR)
		goto ERR_Exit;

	MSDC_LSD_ReadReg32(SDC_RESP02, &resp);
	if ((resp & MMC_SWITCH_ERROR) != 0)
	{
	    if (retry == KAL_FALSE)
	    {
	    	#ifdef MSDC_TRACE_LEVEL2
		drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, resp, __LINE__);
		#endif
		retry = KAL_TRUE;
		goto switch_start;
	    }
	    else
	    {
	        MSDC2_CLR_FIFO();
	        Reset_MSDC2();
		return ERR_MMC_SWITCH_ERROR;
	}
	}

	MSDC2_CLR_FIFO();
	Reset_MSDC2();
	return NO_ERROR;

ERR_Exit:
	MSDC2_CLR_FIFO();
	Reset_MSDC2();
	return status;
}


SDC_CMD_STATUS SD2_Switch_SD11(kal_uint32 arg, T_SWITCH_STATUS* info)
{
	SDC_CMD_STATUS status = NO_ERROR;
	
	BitFieldWrite32_2((kal_uint32*)SDC_CFG2,SD_CMD6_RESP_LEN,SDC_CFG_BLKLEN);	
	EnableMSDC2_DMA();
	MSDC2_DMATransferFirst((kal_uint32)info,(SD_CMD6_RESP_LEN>>2),KAL_FALSE);	
	if((status = SD2_Send_Cmd(SDC_CMD_CMD6_SD11,arg))!=NO_ERROR)
		goto exit;
	if((status = SD2_CheckStatus())!=NO_ERROR)
		goto exit;
	status = MSDC2_DMATransferFinal();	
	
exit:	
	DisableMSDC2_DMA();	
	return status;
}

typedef struct
{
    kal_uint16 max_current;
    kal_uint16 group1_info;
    kal_uint16 group1_status;
    kal_uint8  group1_result;
    kal_uint8  structure_version;
}T_Group1SwitchStatus;
/*************************************************************************
* FUNCTION
*	SD_ParseGroup1FunctionStatus
*
* DESCRIPTION
*	Parse the Group1 functons' information form the data returned by CMD6
*
* PARAMETERS
*	arg: 
*		T_Group1SwitchStatus* sf_status :  information of group1 function
*		kal_uint8* crude_info			: crude data returned by CMD6
*	resp:
*
* RETURNS
*	void
*
* GLOBALS AFFECTED
*	None
* NOTE
*
*************************************************************************/
void SD2_ParseGroup1FunctionStatus(T_Group1SwitchStatus* sf_status, kal_uint8* crude_info)
{
    sf_status->max_current = (((*(kal_uint8 *)crude_info) << 8)
        | (*(kal_uint8 *)(crude_info + 1)));
    sf_status->group1_info = (((*(kal_uint8 *)(crude_info + 12)) << 8)
        | (*(kal_uint8 *)(crude_info + 13)));
    sf_status->group1_result = ((*(kal_uint8 *)(crude_info + 16)) & 0xf);
    sf_status->structure_version = (*(kal_uint8 *)(crude_info + 17));
    sf_status->group1_status = (((*(kal_uint8 *)(crude_info + 28)) << 8)
        | (*(kal_uint8 *)(crude_info + 29)));    
}



SDC_CMD_STATUS SD2_QuerySwithHighSpeed(kal_uint32 arg)
{
	T_Group1SwitchStatus sf_status;
	SDC_CMD_STATUS  	 cmd_status;
	if ((cmd_status = SD2_Switch_SD11(arg, (T_SWITCH_STATUS*)MSDC_Sector2)) != NO_ERROR)
       return cmd_status;
    SD2_ParseGroup1FunctionStatus(&sf_status,(kal_uint8*)MSDC_Sector2);
	if (0 == sf_status.max_current)
    	return ERR_HIGH_SPEED_CONSUMPTION;
	if ((SD_FUNC_HIGH_SPEED == sf_status.group1_result)\
		&& (0==(sf_status.group1_status & (1 << SD_FUNC_HIGH_SPEED))))
    	return NO_ERROR;//the high speed function can be switched
	if ((0xF == sf_status.group1_result) || (!(sf_status.group1_info & (1 << SD_FUNC_HIGH_SPEED))))
		return ERR_HIGH_SPEED_NOT_SUPPORT;//not support	
	if (sf_status.group1_status & (1 << SD_FUNC_HIGH_SPEED))//busy      
        return ERR_HIGH_SPEED_BUSY;
    return ERR_HIGH_SPEED_COMMON_ERROR;
}


SDC_CMD_STATUS SD2_SelectHighSpeed_SD11(void)
{
    SDC_CMD_STATUS high_speed_status;
	kal_int32      t1;
	t1 = drv_get_current_time();
	do 
	{
    	high_speed_status = SD2_QuerySwithHighSpeed(SD_CMD6_QUERY_HIGH_SPEED);//query
		if (NO_ERROR == high_speed_status)
		{
			high_speed_status = SD2_QuerySwithHighSpeed(SD_CMD6_SELECT_HIGH_SPEED);//switch
			if (NO_ERROR == high_speed_status)
			{
				gSD2->flags |= SD_FLAG_HS_SUPPORT;
				break;
			}
			if (ERR_HIGH_SPEED_BUSY != high_speed_status)
				break;			
		}
		if (ERR_HIGH_SPEED_BUSY != high_speed_status)
				break;
		if(SD2_CheckTimeoutWithSleep(t1,500,1))
		{
            high_speed_status = ERR_HIGH_SPEED_TIMEOUT;//timeout
            break;
		}
	}while(1);	
	return high_speed_status;
}


SDC_CMD_STATUS SD2_GoInactive(kal_uint16 rca)
{
	SDC_CMD_STATUS status;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD15,(kal_uint32)rca <<16))!= NO_ERROR)
		return status;

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_ReadStream_MMC(kal_uint32 address, kal_uint32* rxbuffer, kal_uint32 bytes)
{
	SDC_CMD_STATUS status;
	kal_uint32 count;
#ifndef MSDC_DMA
	kal_uint32 i;
#endif

	MSDC2_CLR_FIFO();
	count = (bytes%4)?(bytes/4+1):(bytes/4);
#ifdef MSDC_DMA
	EnableMSDC2_DMA();
	MSDC2_DMATransferFirst((kal_uint32)rxbuffer,count,KAL_FALSE);
#endif
	//launch stream read command
	if((status = SD2_Send_Cmd(SDC_CMD_CMD11_MMC,address)) != NO_ERROR)
	{
		goto ERR_Exit;
	}
	//read R1
	if((status = SD2_CheckStatus())!= NO_ERROR)
	{		
		SD2_WaitDatRdyOrTo();
		goto ERR_Exit;
	}
	

#ifdef MSDC_DMA
	status = MSDC2_DMATransferFinal();
	if(status != NO_ERROR)
	{
		goto ERR_Exit;			
	}		
#else		
	//size assumed to be multiple of 4
	for(i=0;i<count;)
	{
		//check fifo is not empty
		if(!MSDC2_IS_FIFO_EMPTY)
		{
			*(rxbuffer+i) = MSDC_Reg32(MSDC_DAT2);
			i++;
		}
	}
#endif
	DisableMSDC2_DMA();
	SD2_StopTrans(KAL_FALSE);
	MSDC2_CLR_FIFO();
	return NO_ERROR;

ERR_Exit:
	{
		kal_uint32 tmp;

		DisableMSDC2_DMA();
		Reset_MSDC2();

		SD2_StopTrans(KAL_FALSE);		
		SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&tmp);
		MSDC_LSD_ReadReg32(SDC_DATSTA2,&tmp);
		MSDC2_CLR_FIFO();		
		return status;
	}
	 
}



SDC_CMD_STATUS SD2_WriteStream_MMC(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 bytes)
{
	SDC_CMD_STATUS status;
	kal_uint32 count;
#ifndef MSDC_DMA
	kal_uint32 i;
#endif

	if(!gSD2->mCSD.w_blk_part && (address + bytes)%512 != 0)
		return ERR_ERRORS;		
	
		MSDC2_CLR_FIFO();
		count = (bytes%4)?(bytes/4+1):(bytes/4);
#ifdef MSDC_DMA
		EnableMSDC2_DMA();
		MSDC2_DMATransferFirst((kal_uint32)txbuffer,count,KAL_TRUE);
#endif

 	if((status = SD2_Send_Cmd(SDC_CMD_CMD20_MMC,address))!= NO_ERROR)
	{
		goto ERR_Exit;
 	}	
	if((status = SD2_CheckStatus())!= NO_ERROR)
	{
		goto ERR_Exit;
 	}
 #ifdef MSDC_DMA
	 status = MSDC2_DMATransferFinal();
	 if(status != NO_ERROR)
	 {
		 goto ERR_Exit;		 
	 } 	 
#else		
	for(i=0;i<count;)
	{
		
		if(!MSDC2_IS_FIFO_FULL)
		{
			MSDC_WriteReg32(MSDC_DAT2, *(txbuffer+i));
			i++;
		}
		// check data ready (512 bytes)
		if((i%128) == 0)
			SD2_WaitCardNotBusy();
	}
#endif
	DisableMSDC2_DMA();
	SD2_StopTrans(KAL_TRUE);
	MSDC2_CLR_FIFO();
	return NO_ERROR;

ERR_Exit:
	{
		kal_uint32 tmp;
		
		DisableMSDC2_DMA();
		Reset_MSDC2();

		SD2_StopTrans(KAL_TRUE);		
		SD2_GetStatus(gSD2->mRCA,(kal_uint32*)&tmp);
		MSDC_LSD_ReadReg32(SDC_DATSTA2,&tmp);
		MSDC2_CLR_FIFO();		
		return status;
	}
}



SDC_CMD_STATUS SD2_ProgramCSD(kal_uint32 Csd[4])
{
	SDC_CMD_STATUS status;
	kal_uint32 i;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD27,0))!= NO_ERROR)
		return status;

	//read R1
	if((status = SD2_CheckStatus())!= NO_ERROR)
	{
		SD2_WaitDatRdyOrTo();
		return status;
	}
	//clear fifo 
	MSDC2_CLR_FIFO();

	//send CSD 128 bits = 4x32
	for(i=0;i<4;i++)
		MSDC_WriteReg32(MSDC_DAT2, Csd[i]);

	//wait until crc status token received
	if((status = SD2_WaitDatRdyOrTo())!= NO_ERROR)
		return status;

	//wait until programming is finished
	SD2_WaitCardNotBusy();
	return NO_ERROR;
}



SDC_CMD_STATUS SD2_SetWriteProtect(kal_uint32 address)
{
	SDC_CMD_STATUS status;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD28,address))!= NO_ERROR)
		return status;
	if((status = SD2_CheckStatus())!= NO_ERROR)
		return status;

	//wait until data line is ready
	SD2_WaitCardNotBusy();
	return NO_ERROR;
}


SDC_CMD_STATUS SD2_ClrWriteProtect(kal_uint32 address)
{
	SDC_CMD_STATUS status;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD29,address))!= NO_ERROR)
		return status;
	if((status = SD2_CheckStatus())!= NO_ERROR)
		return status;
	SD2_WaitCardNotBusy();
	return NO_ERROR;
}


SDC_CMD_STATUS SD2_SendWriteProtect(kal_uint32 address, kal_uint32* WPBits32)
{
	SDC_CMD_STATUS status;
	kal_uint32	tmp;
	
	BitFieldWrite32_2((kal_uint32*)SDC_CFG2,4,SDC_CFG_BLKLEN);
	MSDC2_CLR_FIFO();
	if((status = SD2_Send_Cmd(SDC_CMD_CMD30,address))!= NO_ERROR)
		return status;
	if((status = SD2_CheckStatus())!= NO_ERROR)
		return status;
	//read 32 write protection bits
	MSDC_LSD_ReadReg32(MSDC_DAT2,&tmp);
	MSDC2_InvertN((kal_uint8*)WPBits32,(kal_uint8*)&tmp,4);
	// configure the controller to the original block length
	BitFieldWrite32_2((kal_uint32*)SDC_CFG2,gSD2->mBKLength,SDC_CFG_BLKLEN);

	return NO_ERROR;
}



SDC_CMD_STATUS SD2_FastIO_MMC(kal_uint16 rca, kal_bool isWrite, kal_uint8 reg_adrs, kal_uint8 data)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg = 0;

	arg = rca << 16;
	arg |= isWrite << 15;
	arg |= reg_adrs << 8;
	arg |= data;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD39_MMC,arg))!= NO_ERROR)
		return status;
	if((status = SD2_CheckStatus())!= NO_ERROR)
		return status;

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_GoIRQ_MMC(void)
{
	SDC_CMD_STATUS status;

	if((status = SD2_Send_Cmd(SDC_CMD_CMD40_MMC,SDC_NO_ARG))!= NO_ERROR)
		return status;
	status = *(kal_uint32*)SDC_RESP02;
	#ifdef MSDC_TRACE_LEVEL2
	drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, status, __LINE__);
	#endif

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_GetSDStatus(kal_uint32* sd_status)
{
	SDC_CMD_STATUS status;
	kal_uint32 blklen,i;

	// save the orignial block length
	blklen = gSD2->mBKLength;
	// set block length
	if((status = SD2_SetBlength(64))!= NO_ERROR)
		return status;
	// clear fifo
	MSDC2_CLR_FIFO();
	// send APP_CMD
	if((status = SD2_Cmd55(gSD2->mRCA))!= NO_ERROR)
		return status;
	// send CMD13
	if((status = SD2_Send_Cmd(SDC_CMD_ACMD13,SDC_NO_ARG))!= NO_ERROR)
		return status;
	//read R1
	if((status = SD2_CheckStatus())!= NO_ERROR)
		return status;	
	// read sd status(64bytes = 4x16)	
	for(i=0;i<16;)
	{
		if(!MSDC2_IS_FIFO_EMPTY)
		{
			*(kal_uint32*)(sd_status+i) = MSDC_Reg32(MSDC_DAT2);
			i++;
		}
	}

	// resotre block length
	if((status = SD2_SetBlength(blklen))!= NO_ERROR)
		return status;

	return NO_ERROR;
}


SDC_CMD_STATUS SD2_GetNumWrittenBlk(kal_uint32* num)
{
	SDC_CMD_STATUS status;
	kal_uint32 blklen,tmp;

	// save the orignial block length
	blklen = gSD2->mBKLength;
	// set block length
	if((status = SD2_SetBlength(4)) != NO_ERROR)
		return status;
	// clear fifo
	MSDC2_CLR_FIFO();
	// send APP_CMD
	if((status = SD2_Cmd55(gSD2->mRCA)) != NO_ERROR)
		return status;
	// send CMD22
	if((status = SD2_Send_Cmd(SDC_CMD_ACMD22,SDC_NO_ARG)) != NO_ERROR)
		return status;
	//read R1
	if((status = SD2_CheckStatus()) != NO_ERROR)
		return status;	
	// read the number of written write blocks(4bytes)	
	while(MSDC2_IS_FIFO_EMPTY);

	tmp = MSDC_Reg32(MSDC_DAT2);
	MSDC2_InvertN((kal_uint8*)num,(kal_uint8*)&tmp,4);
	// resotre block length
	if((status = SD2_SetBlength(blklen))!= NO_ERROR)
		return status;
	return NO_ERROR;
}


#ifdef DRV_MSDC_HW_CONTENTION
extern kal_semid dclMsdcArb;
#endif


void SD2_startFastFormat(void)
{
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_LOCK(AUDMA_ID_MSDC);
#endif

#ifdef DRV_MSDC_HW_CONTENTION
	kal_uint32 retAddr;

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */
	

	if(NULL == dclMsdcArb)
		ASSERT(0);
	if(kal_query_systemInit()== KAL_FALSE){
		/*must gain resource here before calling writeSectors*/
		kal_take_sem(dclMsdcArb, 1);
		SD_setArbRetAddr(retAddr);
		SD_setArbThdId((kal_uint32)kal_get_current_thread_ID());
	}
#endif	

	

#if defined(__DRV_MSDC_FAST_FORMAT__)
	gMSDC2_Handle->MSDC_fastFormat = KAL_TRUE;
#endif
}


void SD2_closeFastFormat(void)
{
	

#if defined(__DRV_MSDC_FAST_FORMAT__)
	gMSDC2_Handle->MSDC_fastFormat = KAL_FALSE;
#endif

#ifdef DRV_MSDC_HW_CONTENTION
	if(kal_query_systemInit()== KAL_FALSE){
		/*when the semaphore is returned, we set thdId to zero, but not retAddr, we can know that it is released from here*/
		SD_setArbThdId(NULL);
		kal_give_sem(dclMsdcArb);
	}
#endif

#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_UNLOCK(AUDMA_ID_MSDC);
#endif
}



#if defined(__UBL__)
#pragma arm section code = "EXT_BOOTLOADER_CODE", rwdata = "EXT_BOOTLOADER_RW", zidata = "EXT_BOOTLOADER_ZI"
#endif


SDC_CMD_STATUS SD2_FlushSectors(kal_uint32 startSector, kal_uint32 sectorNum)
{
	SDC_CMD_STATUS status;
	kal_uint32 sectorMult;

	if(gSD2->flags & SD_FLAG_HCS_SUPPORT)
		sectorMult = 1;
	else
		sectorMult = SECTOR_SIZE;

	MSDC2_PDNControl(KAL_FALSE);
	// there are differences between SD and MMC
	// tag erase start(CMD32)
	if((status = SD2_EraseCmdClass(SDC_CMD_CMD32, sectorMult * startSector)) != NO_ERROR){
		return status;
	}
	// tag erase end(CMD33)
	if((status = SD2_EraseCmdClass(SDC_CMD_CMD33, sectorMult * (startSector + sectorNum - 1))) != NO_ERROR){
		goto ErrorExit;
	}
	// erase...(CMD38)
	if((status = SD2_EraseCmdClass(SDC_CMD_CMD38,0)) != NO_ERROR){
		goto ErrorExit;
	}
	
ErrorExit:
	MSDC2_PDNControl(KAL_TRUE);
	return status;
}


#if defined(__UBL__)
#pragma arm section code, rwdata, zidata
#endif


#endif//!defined(__UBL__) || defined(__CARD_DOWNLOAD__) 

#endif

#else //DRV_MSDC_OFF
#include "kal_release.h"
//RHR ADD
#include "kal_general_types.h"
#include "btif_sw.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_public_defs.h"
//RHR REMOVE
/*
#include "kal_non_specific_general_types.h"
#include "app_buff_alloc.h"
#include "intrCtrl.h"
//#include "gpio_sw.h"
#include "init.h"
#include "pmic_features.h"
#include "pmu_sw.h"
#include "nucleus.h"
#include "ev_defs.h"
*/
//RHR
#include "gpt_sw.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "upll_ctrl.h"
#include	"Drv_trc.h"
#ifdef DCL_MSDC_INTERFACE
#include "DCL.h"
void SD2_dummyAPI(void){}
SDC_CMD_STATUS SD2_SetBlength(kal_uint32 BKLength){}
SDDriver_t sd_driver_MTK2 = {
	(DCL_SINGLE_BLK_RD)SD2_dummyAPI,
	(DCL_MUL_BLK_RD)SD2_dummyAPI,
	(DCL_SINGLE_BLK_WR)SD2_dummyAPI,
	(DCL_MUL_BLK_WR)SD2_dummyAPI,
	(DCL_SD_INITITALIZE)SD2_dummyAPI,
	(DCL_SET_PRE_ERASE_CNT)SD2_dummyAPI,
	(DCL_SD_SET_CALLBACK)SD2_dummyAPI,
	(DCL_SET_READ_TEST_FLAG)SD2_dummyAPI,
	(DCL_SD_READ_TEST)SD2_dummyAPI,
	(DCL_SD_SET_UPLL_CLOCK_TEST)SD2_dummyAPI,
	(DCL_SD_ERASE_BLK)SD2_dummyAPI,
};
#endif //DCL_MSDC_INTERFACE

void SD2_startFastFormat(void){}
void SD2_closeFastFormat(void){}
T_SDC_HANDLE	gSD2_blk[SD_NUM];
T_SDC_HANDLE	*gSD2 = gSD2_blk;

#if defined( __MAUI_BASIC__) || defined( __MEUT__)
kal_uint32 msdc_ReadTestFlag;
#endif


#endif //DRV_MSDC_OFF
