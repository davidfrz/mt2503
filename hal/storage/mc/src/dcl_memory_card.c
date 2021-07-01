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
 *    dcl_memory_card.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *	This Module defines DCL (Driver Common Layer) of the memory card driver and SDIO driver.
 *	The memory card driver provide here include SD, MMC, MS/MSPro.
 *	In thie file, DclSD_xxx is the API for SD driver, Dcl_SDIO_xxx is the API for SDIO driver, and DclMS_xxx is the API for MS and MSPro driver.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "drv_comm.h"
#include "msdc_reg_adap.h"
#include "dcl.h"
#include "intrCtrl.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "Drv_trc.h"
#include "cache_sw.h"
#include "init.h"

#ifdef DCL_MSDC_INTERFACE

#if !defined(DRV_MSDC_OFF)
/**************************************************************************
following defines options used in this file
***************************************************************************/
/*SD related handle*/
//for SDIO SD work together redefine handle All
#define DCL_SD_HANDLE_SD1	(MSDC_base|MSDC1_SD1)
#define DCL_SD_HANDLE_SIMPLUS	(MSDC_base|MSDC1_SD2)

#if defined(__MSDC2_SD_MMC__)||defined(__MSDC2_SD_SDIO__)	
#define DCL_SD_HANDLE_SD2	(MSDC2_base|MSDC2_SD1)
//#define DCL_SD_HANDLE_MSDC2_SD2	(MSDC2_base|MSDC2_SD2)
#endif

#if defined(__MSDC_SD_SDIO__)
#define DCL_SDIO_HANDLE_SDIO1	(MSDC_base|MSDC1_SDIO)
#endif

#if defined(__MSDC2_SD_SDIO__)
#define DCL_SDIO_HANDLE_SDIO2	(MSDC2_base|MSDC2_SDIO)
#endif

#define DCL_SD_GET_SEL_FROM_HANDLE(a) ((sd_select_enum)(a & 0xF))
#define DCL_SDIO_GET_SEL_FROM_HANDLE(a) ((sd_select_enum)(a & 0xF))


#if defined(__MSDC2_SD_MMC__)
extern MSDC_HANDLE MSDC2_Blk[SD_NUM];
extern T_SDC_HANDLE	gSD2_blk[SD_NUM];

#endif

//
#if 0
/* under construction !*/
#if defined(__MSDC2_SD_MMC__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
/* under construction !*/
#elif defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MSDC2_SD_SDIO__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*following definition is to help easy search for incomplete part*/
#define DCL_SD_IMPLEMENTATION_ASSERT ASSERT(0)

/**************************************************************************
following defines static global variables used in this file
***************************************************************************/
static kal_bool fgMSDCInit = KAL_FALSE;
static kal_bool fgSDInit = KAL_FALSE;
#if ((defined(__UBL__) || defined(__FUE__)) && defined(__CARD_DOWNLOAD__)) || defined(__MSDC_SD_SDIO__) 
static kal_bool fgSDIOInit = KAL_FALSE;
#endif



/*following variable is used to replace the compile option usage in the code*/
static kal_uint32 u4MSDCSupport;//stand for wihch HW MSDC will be used


//static kal_semid dclMsdcArb[3];
#if !defined(__UBL__)
static MSDC_LOCK_TAG dclMsdcLock[3];
#endif
/**************************************************************************
*	following defines global variables and definitions used for resource contention
*	with uint16 stands for a resource, every resource is composed as following:
*	using[15:13]   |   occupied[12]   |   magic[11:4]   |   RFU[3:0]
***************************************************************************/
static kal_uint16			sdResource[3];
//static kal_uint16			msdcResource[3];

#define DCL_SD_RESOURCE_OCCUPIED	0x1000
#define DCL_SD_RESOURCE_USING_MAX	0xE000
#define DCL_SD_RESOURCE_USING_INCREMENT	0x2000
#define DCL_SD_RESOURCE_MAGIC_MAX 0x0ff0
#define DCL_SD_RESOURCE_MAGIC_UNIT 0x0010
#define DCL_SD_GET_MAGIC_FROM_HANDLE(a) (a & DCL_SD_RESOURCE_MAGIC_MAX)
#define DCL_SD_GET_DUMMY_HANDLE(a) (a & (~DCL_SD_RESOURCE_MAGIC_MAX))
static sd_select_enum DCL_SD_USING_RESOURCE_START(DCL_HANDLE handle)
{
	sd_select_enum sel;
	kal_uint32 dclSDChkResMaskedValue;
	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_MMC__)
	sel = 0;
	#elif defined(__MSDC2_SD_MMC__)
	sel = 1;
	#endif
	if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
        {
	   if(DCL_SD_RESOURCE_OCCUPIED != (sdResource[sel] & DCL_SD_RESOURCE_OCCUPIED))
           {
		ASSERT(0);
	   }
	   if((handle & DCL_SD_RESOURCE_MAGIC_MAX) != (sdResource[sel] & DCL_SD_RESOURCE_MAGIC_MAX))
           {
		ASSERT(0);
	   }
        }
	dclSDChkResMaskedValue = SaveAndSetIRQMask();
	if(sdResource[sel] & DCL_SD_RESOURCE_USING_MAX){
		ASSERT(0);
	}
	sdResource[sel] += DCL_SD_RESOURCE_USING_INCREMENT;
	RestoreIRQMask(dclSDChkResMaskedValue);
	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	return sel;
}

static void DCL_SD_USING_RESOURCE_END(DCL_HANDLE handle,sd_select_enum sel)
{
	kal_uint32 dclSDChkResMaskedValue;
	dclSDChkResMaskedValue = SaveAndSetIRQMask();
	#if defined(__MSDC_SD_MMC__)
	sel = 0;
	#elif defined(__MSDC2_SD_MMC__)
	sel = 1;
	#endif
	if(DCL_SD_RESOURCE_USING_INCREMENT != (sdResource[sel] & DCL_SD_RESOURCE_USING_MAX)){
		ASSERT(0);
	}
	sdResource[sel] -= DCL_SD_RESOURCE_USING_INCREMENT;
	RestoreIRQMask(dclSDChkResMaskedValue);
}

/*******************************************************************************
*	following defines global variables and definitions used for debuging on resource management 
********************************************************************************/
typedef struct{
	kal_uint32	callerRetAddr;
	kal_uint32	ownerThdId;
} DCL_SD_DBG_RESOURCE;

static DCL_SD_DBG_RESOURCE	sdDbgRrc[3];

/**************************************************************************
*	following defines function tables of SD layer and MSDC layer. These function tables should only be accessed by functions in this file
*	I should pay some time to remove hard coding of array exntries.
***************************************************************************/
static SDDriver_t			*sdDriverTable[3];

static SDDriver_t			*sd2DriverTable[3];


static MSDCDriver_t		msdcDriverTable[3];

static MSDCDriver_t		msdc2DriverTable[3];


#if defined(__MSDC_SD_SDIO__)||defined(__MSDC2_SD_SDIO__)
static SDIODriver_t		*sdioDriverTable[2];
#endif

/******************************************************************************************
*following are extern variables from other file
******************************************************************************************/
#if defined(__MSDC_SD_MMC__)
extern SDDriver_t sd_driver_MTK1;
#endif
#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
extern SDDriver_t sd_driver_MTK2;
#endif


/**************************************************************************
followings are static functions that are only called by functions in this file
***************************************************************************/

/*************************************************************************
* FUNCTION
*  DclMSDC_init
*
* DESCRIPTION
* 	This function is to initialize MSDC related HW and SW.
*	This file is to be only called by DCL driver, so we set it statis.
*	Users should not remove "static" keyword unless you know MTK's memory card driver well.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	None
*
*************************************************************************/
static void DclMSDC_init(void)
{
	/*to get information about how many HW MSDC we will use*/
	u4MSDCSupport |= DCL_MSDC_HW_MSDC1;

#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
	u4MSDCSupport |= DCL_MSDC_HW_MSDC2;
#endif

	if(u4MSDCSupport & DCL_MSDC_HW_MSDC1){
		#if defined(__MSDC_SD_MMC__)||defined(__MSDC_SD_SDIO__)
		MSDC_Initialize();
		//dclMsdcArb[0] = kal_create_sem("MSDC1_lock", 1);
		init_MSDC_lock(&dclMsdcLock[0], "DCL_MSDC0_LOCK");
		#endif
	}
#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
	/*if MSDC2 is not compiled, there will be no MSDC_Initialize2, should wrap here*/
	if(u4MSDCSupport & DCL_MSDC_HW_MSDC2){
		MSDC2_Initialize();
		//dclMsdcArb[1] = kal_create_sem("MSDC2_lock", 1);
		init_MSDC_lock(&dclMsdcLock[1], "DCL_MSDC1_LOCK");
	}
#endif

	/*init MSDC driver tables, since the functions in every msdc drivers are few, we register then one by one*/
#if defined(__MSDC_SD_MMC__) || defined(__MSDC_SD_SDIO__)	
	msdcDriverTable[DCL_SD_GET_SEL_FROM_HANDLE(DCL_SD_HANDLE_SD1)].modulePDN = (DCL_MSDC_PDN)MSDC_PDNControl;
#endif

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	msdcDriverTable[DCL_SD_GET_SEL_FROM_HANDLE(DCL_SD_HANDLE_SIMPLUS)].modulePDN = (DCL_MSDC_PDN)MSDC_PDNControl; //in the design, sel = 2 is preserved for SIM+ card, which uses 1st MSDC's code

#elif defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
	msdc2DriverTable[DCL_SD_GET_SEL_FROM_HANDLE(DCL_SD_HANDLE_SIMPLUS)].modulePDN = (DCL_MSDC_PDN)MSDC2_PDNControl;

#endif

#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)	
	msdc2DriverTable[DCL_SD_GET_SEL_FROM_HANDLE(DCL_SD_HANDLE_SD2)].modulePDN = (DCL_MSDC_PDN)MSDC2_PDNControl;
#endif
}

static DCL_BOOL DclSD_PollExistence(DCL_UINT8 irqMSDCCode, DCL_UINT32 addrReg_MSDC_PS, sd_select_enum sel)
{
#if defined(__MSDC_SD_MMC__)
	IRQMask(irqMSDCCode);
	if(MSDC_Reg32(addrReg_MSDC_PS) & MSDC_PS_PIN0)
	{
		if(MSDC_Blk[sel].ins_level == MSDC_IOCTRL_PULL_UP)
			MSDC_Blk[sel].mIsPresent = KAL_FALSE;	
		else
			MSDC_Blk[sel].mIsPresent = KAL_TRUE;	
	}
	else
	{
		if(MSDC_Blk[sel].ins_level == MSDC_IOCTRL_PULL_UP)
			MSDC_Blk[sel].mIsPresent = KAL_TRUE;
		else
			MSDC_Blk[sel].mIsPresent = KAL_FALSE;	
	}
	IRQUnmask(irqMSDCCode);

	return MSDC_Blk[sel].mIsPresent;
#elif defined(__MSDC2_SD_MMC__)
	IRQMask(irqMSDCCode);
	if(MSDC_Reg32(addrReg_MSDC_PS) & MSDC_PS_PIN0)
	{
		if(MSDC2_Blk[sel].ins_level == MSDC_IOCTRL_PULL_UP)
			MSDC2_Blk[sel].mIsPresent = KAL_FALSE;	
		else
			MSDC2_Blk[sel].mIsPresent = KAL_TRUE;	
	}
	else
	{
		if(MSDC2_Blk[sel].ins_level == MSDC_IOCTRL_PULL_UP)
			MSDC2_Blk[sel].mIsPresent = KAL_TRUE;
		else
			MSDC2_Blk[sel].mIsPresent = KAL_FALSE;	
	}
	IRQUnmask(irqMSDCCode);

	return MSDC2_Blk[sel].mIsPresent;
#endif
}
#if defined(MSDC_CACHED_SUPPORT) && !((defined(__UBL__) || defined(__FUE__)) )
extern kal_bool DMA_Valid_Addr_Chk(const void *src, kal_uint32 length);
#endif
#if defined(__MSDC_SD_MMC__)||defined(__MSDC2_SD_MMC__)
static DCL_STATUS DclSD_CtrlCmdRead(sd_select_enum sel, SD_CTRL_READ_T *prRead)
{
//	DCL_UINT32 addrs, maxBlk;
	DCL_UINT32 maxBlk;
	DCL_SDC_CMD_STATUS status;
	DCL_UINT32	u4Sector; //this specify the starting sector to read
	DCL_UINT32	u4Sectors; //this specify the number of sectors to read
	void			*bufferAddr; //we will move move data from card to this address
	SDDriver_t	*sdDriver;

	/*parameters in prRead should not be changed, take these as local variable*/
	u4Sector = prRead->u4Sector;
	u4Sectors = prRead->u4Sectors;
	bufferAddr = prRead->bufferAddr;

	/*requirement check here*/
#if defined(__MSDC_SD_MMC__)
	if(KAL_FALSE == MSDC_Blk[sel].mIsInitialized || KAL_FALSE == MSDC_Blk[sel].mIsPresent)
#elif defined(__MSDC2_SD_MMC__)
	if(KAL_FALSE == MSDC2_Blk[sel].mIsInitialized || KAL_FALSE == MSDC2_Blk[sel].mIsPresent)
#endif
	{
		//ASSERT(0);
		status = (DCL_SDC_CMD_STATUS)STATUS_ERROR_WRONG_STATE;
		return status;
	}
#if defined(__MSDC_SD_MMC__)
	maxBlk = gSD_blk[sel].mCSD.capacity/512;	
#elif defined(__MSDC2_SD_MMC__)
	maxBlk = gSD2_blk[sel].mCSD.capacity/512;
#endif

	/*sectors & sector check*/
	if(0 == u4Sectors || u4Sectors > maxBlk || u4Sector > maxBlk){
		//ASSERT(0);
		status = (DCL_SDC_CMD_STATUS)STATUS_INVALID_CTRL_DATA;
		return status;
	}

	/*check that ending block should be smaller than maximum block number*/
	if((u4Sector + u4Sectors - 1) > maxBlk){
		//ASSERT(0);
		status = (DCL_SDC_CMD_STATUS)STATUS_INVALID_CTRL_DATA;
		return status;
	}

#if defined(MSDC_CACHED_SUPPORT)
#if defined(__MSDC_SD_MMC__)
#if (defined(__UBL__) || defined(__FUE__))
    MSDC_Blk[sel].isCachedBuf = KAL_TRUE;
#else
	/*tell buffer type each time this function called*/
    if (INT_QueryIsCachedRAM(bufferAddr, u4Sectors * DCL_SECTOR_SIZE)
        || !DMA_Valid_Addr_Chk(bufferAddr, u4Sectors * DCL_SECTOR_SIZE)){
		MSDC_Blk[sel].isCachedBuf = KAL_TRUE;
	}
	else
		MSDC_Blk[sel].isCachedBuf = KAL_FALSE;
#endif
#elif defined(__MSDC2_SD_MMC__)
#if (defined(__UBL__) || defined(__FUE__))
    MSDC2_Blk[sel].isCachedBuf = KAL_TRUE;
#else
	/*tell buffer type each time this function called*/
    if (INT_QueryIsCachedRAM(bufferAddr, u4Sectors * DCL_SECTOR_SIZE)
        || !DMA_Valid_Addr_Chk(bufferAddr, u4Sectors * DCL_SECTOR_SIZE)){
		MSDC2_Blk[sel].isCachedBuf = KAL_TRUE;
	}
	else
		MSDC2_Blk[sel].isCachedBuf = KAL_FALSE;
#endif
#endif
#endif

    #if defined(MT6250)
    if (INT_SW_SecVersion() == SW_SEC_0) {
        if ((kal_uint32)bufferAddr % 4)
		#if defined(__MSDC_SD_MMC__)	
            MSDC_Blk[sel].isCachedBuf = KAL_TRUE;
		#elif defined(__MSDC2_SD_MMC__)
			MSDC2_Blk[sel].isCachedBuf = KAL_TRUE;
		#endif
    }
    #endif

	/*power on MSDC module*/
	#if defined(__MSDC_SD_MMC__)
	msdcDriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_FALSE);
	sdDriver = sdDriverTable[sel];
	#elif defined(__MSDC2_SD_MMC__)
	msdc2DriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_FALSE);
	sdDriver = sd2DriverTable[sel];
	#endif
	
	
	/*block address or byte address*/
	#if defined(__MSDC_SD_MMC__)
	if(gSD_blk[sel].flags & SD_FLAG_HCS_SUPPORT)
	#elif defined(__MSDC2_SD_MMC__)
	if(gSD2_blk[sel].flags & SD_FLAG_HCS_SUPPORT)
	#endif
		u4Sector = u4Sector;
	else
		u4Sector = u4Sector * DCL_SECTOR_SIZE;

	if(u4Sectors > 1)
	{
		status = sdDriver->mulBlkRd(u4Sector, bufferAddr, u4Sectors);
	}
	else{
		status = sdDriver->singleBlkRd(u4Sector, bufferAddr);
	}
			
	/*power down MSDC module*/
	#if defined(__MSDC_SD_MMC__)
	msdcDriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_TRUE);
	#elif defined(__MSDC2_SD_MMC__)
	msdc2DriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_TRUE);
	#endif

	return status;

}
#if defined(MSDC_CACHED_SUPPORT)
extern kal_bool INT_QueryIsROMSpace(kal_uint32 addr);
#endif
static DCL_STATUS DclSD_CtrlCmdWrite(sd_select_enum sel, SD_CTRL_WRITE_T *prWrite)
{

	DCL_UINT32 maxBlk;//DCL_UINT32 addrs, maxBlk;
	DCL_SDC_CMD_STATUS status=0;
	DCL_UINT32	u4Sector; //this specify the starting sector to Write
	DCL_UINT32	u4Sectors; //this specify the number of sectors to Write
	void			*bufferAddr; //we will move move data from this address to the card
	SDDriver_t	*sdDriver;

	/*parameters in prRead should not be changed, take these as local variable*/
	u4Sector = prWrite->u4Sector;
	u4Sectors = prWrite->u4Sectors;
	bufferAddr = prWrite->bufferAddr;

	/*requirement check here*/
#if defined(__MSDC_SD_MMC__)
	if(KAL_FALSE == MSDC_Blk[sel].mIsInitialized || KAL_FALSE == MSDC_Blk[sel].mIsPresent)
#elif defined(__MSDC2_SD_MMC__)
	if(KAL_FALSE == MSDC2_Blk[sel].mIsInitialized || KAL_FALSE == MSDC2_Blk[sel].mIsPresent)
#endif

	{
		//ASSERT(0);
		status = (DCL_SDC_CMD_STATUS)STATUS_ERROR_WRONG_STATE;
		return status;
	}
#if defined(__MSDC_SD_MMC__)
	maxBlk = gSD_blk[sel].mCSD.capacity/512;
#elif defined(__MSDC2_SD_MMC__)
	maxBlk = gSD2_blk[sel].mCSD.capacity/512;
#endif

	/*sectors & sector check*/
	if(0 == u4Sectors || u4Sectors > maxBlk || u4Sector > maxBlk){
		//ASSERT(0);
		status = (DCL_SDC_CMD_STATUS)STATUS_INVALID_CTRL_DATA;
		return status;
	}

	/*check that ending block should be smaller than maximum block number*/
	if((u4Sector + u4Sectors - 1) > maxBlk){
		//ASSERT(0);
		status = (DCL_SDC_CMD_STATUS)STATUS_INVALID_CTRL_DATA;
		return status;
	}

#if defined(__MSDC_SD_MMC__) 
#if defined(MSDC_CACHED_SUPPORT)
#if (defined(__UBL__) || defined(__FUE__)) 
    MSDC_Blk[sel].isCachedBuf = KAL_TRUE;
#else
	/*tell buffer type each time this function called*/
    if (INT_QueryIsCachedRAM(bufferAddr, u4Sectors * DCL_SECTOR_SIZE)
        || !DMA_Valid_Addr_Chk(bufferAddr, u4Sectors * DCL_SECTOR_SIZE)){
		MSDC_Blk[sel].isCachedBuf = KAL_TRUE;
	}
	else
		MSDC_Blk[sel].isCachedBuf = KAL_FALSE;
#endif
#endif
#elif defined(__MSDC2_SD_MMC__)
#if defined(MSDC_CACHED_SUPPORT)
#if (defined(__UBL__) || defined(__FUE__)) 
	    MSDC2_Blk[sel].isCachedBuf = KAL_TRUE;
#else
		/*tell buffer type each time this function called*/
	    if (INT_QueryIsCachedRAM(bufferAddr, u4Sectors * DCL_SECTOR_SIZE)
	        || !DMA_Valid_Addr_Chk(bufferAddr, u4Sectors * DCL_SECTOR_SIZE)){
			MSDC2_Blk[sel].isCachedBuf = KAL_TRUE;
		}
		else
			MSDC2_Blk[sel].isCachedBuf = KAL_FALSE;
#endif
#endif

#endif

    #if defined(MT6250)
    if (INT_SW_SecVersion() == SW_SEC_0) {
        if ((kal_uint32)bufferAddr % 4)
			#if defined(__MSDC_SD_MMC__)
            MSDC_Blk[sel].isCachedBuf = KAL_TRUE; 
			#elif defined(__MSDC2_SD_MMC__)
			MSDC2_Blk[sel].isCachedBuf = KAL_TRUE; 
			#endif
    }
    #endif

    //
    // To check if data is put on serial flash or nor flash.
    //
#ifdef MSDC_CACHED_SUPPORT
	if (INT_QueryIsROMSpace((kal_uint32)bufferAddr) || 
	    INT_QueryIsROMSpace((kal_uint32)bufferAddr + u4Sectors*0x200)) {
	    #if defined(__MSDC_SD_MMC__)
	    MSDC_Blk[sel].isCachedBuf = KAL_TRUE;
		#elif defined(__MSDC2_SD_MMC__)
		MSDC2_Blk[sel].isCachedBuf = KAL_TRUE;
		#endif
	        
	}
#endif	
	/*power on MSDC module*/
	#if defined(__MSDC_SD_MMC__)
	msdcDriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_FALSE);
	sdDriver = sdDriverTable[sel];
	#elif defined(__MSDC2_SD_MMC__)
	msdc2DriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_FALSE);
	sdDriver = sd2DriverTable[sel];
	#endif
	
	/*block address or byte address*/
	#if defined(__MSDC_SD_MMC__)
	if(gSD_blk[sel].flags & SD_FLAG_HCS_SUPPORT)
	#elif defined(__MSDC2_SD_MMC__)
	if(gSD2_blk[sel].flags & SD_FLAG_HCS_SUPPORT)
	#endif
		u4Sector = u4Sector;
	else
		u4Sector = u4Sector * DCL_SECTOR_SIZE;

	if(u4Sectors > 1)
	{
	#if defined(__MSDC_SD_MMC__)
		if(SD_CARD == MSDC_Blk[sel].mMSDC_type)
	#elif defined(__MSDC2_SD_MMC__)
		if(SD_CARD == MSDC2_Blk[sel].mMSDC_type)
	#endif
			sdDriver->setPreEraseCnt(u4Sectors);
		status = sdDriver->mulBlkWr(u4Sector, bufferAddr, u4Sectors);
	}
	else{
		status = sdDriver->singleBlkWr(u4Sector, bufferAddr);
	}
			
	/*power down MSDC module*/
	#if defined(__MSDC_SD_MMC__)
	msdcDriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_TRUE);
	#elif defined(__MSDC2_SD_MMC__)
	msdc2DriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_TRUE);
	#endif

	return status;

}

#endif //MSDC1 MSDC2
/***************************************************************************************
followings are DCL SD API exported 
*****************************************************************************************/

#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif
/*************************************************************************
* FUNCTION
*  DclSD_Initialize
*
* DESCRIPTION
* 	This function is to initialize the SD driver related resource.
*	This function should be called in system initialization before tasks are scheduling.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_OK : this should be the only return value since MSDC_initialize returns nothing.
*
*************************************************************************/
DCL_STATUS DclSD_Initialize(void)
{
	kal_uint32	maskedValue;
	
	maskedValue = SaveAndSetIRQMask();
	/*a sync mechanism to guarantee MSDC_Initialize is only called once*/
	if(KAL_FALSE == fgMSDCInit){
		fgMSDCInit = KAL_TRUE;
		RestoreIRQMask(maskedValue);
		DclMSDC_init();
	}
	else{
		RestoreIRQMask(maskedValue);
	}


	maskedValue = SaveAndSetIRQMask();
	if(KAL_FALSE == fgSDInit){
		fgSDInit = KAL_TRUE;
		RestoreIRQMask(maskedValue);
		/*init SD driver tables, there are too many entries in SD driver, so we hook it by pointer*/
	#if defined(__MSDC_SD_MMC__)
		sdDriverTable[DCL_SD_GET_SEL_FROM_HANDLE(DCL_SD_HANDLE_SD1)] = &sd_driver_MTK1;
	#endif

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
		sdDriverTable[DCL_SD_GET_SEL_FROM_HANDLE(DCL_SD_HANDLE_SIMPLUS)] = &sd_driver_MTK1; //in the design, sel = 2 is preserved for SIM+ card, which uses 1st MSDC's code
#elif defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
		sd2DriverTable[DCL_SD_GET_SEL_FROM_HANDLE(DCL_SD_HANDLE_SIMPLUS)] = &sd_driver_MTK2; 
#endif

#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)		
		sd2DriverTable[DCL_SD_GET_SEL_FROM_HANDLE(DCL_SD_HANDLE_SD2)] = &sd_driver_MTK2;
#endif
	}
	else{
		RestoreIRQMask(maskedValue);
	}
	
	return STATUS_OK;
}

#if defined(__MTK_TARGET__)&&defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

#if (defined(__UBL__) || defined(__FUE__)) && defined(__CARD_DOWNLOAD__)
DCL_STATUS DclSD_DeInitialize(void)
{
    fgMSDCInit  = KAL_FALSE;
    fgSDInit    = KAL_FALSE;
    fgSDIOInit  = KAL_FALSE;
	fgSDIOInit |=0;

	#if defined(__MSDC_SD_MMC__)
    MSDC_DeInit();
	#elif defined(__MSDC2_SD_MMC__)
	MSDC2_DeInit();
	#endif
	
    
    return STATUS_OK;
}
#endif

#if defined(__MSDC_SD_MMC__)||defined(__MSDC2_SD_MMC__)
/*************************************************************************
* FUNCTION
*  DclSD_Initialize
*
* DESCRIPTION
* 	This function is to get SD DCL handler.
*
* PARAMETERS
*	eDev - only valid for DCL_SD.
*	flags -following bit stand for specific meaning.
*		DCL_SD_FLAGS_CARD1: to get a handle for card 1
*		DCL_SD_FLAGS_CARD2: to get a handle for card 2
*		DCL_SD_FLAGS_SIMPLUS: to get a handle for sim plus
*		Other values are prohibited
* RETURNS
*  DCL_HANDLE_INVALID - Open failed.
*  other value - a valid handle
*
*************************************************************************/
DCL_HANDLE DclSD_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	kal_uint32 retAddr = 0;
	kal_uint32 thdId;	
	kal_uint32 sel;

	#if defined(__MSDC_SD_MMC__)
	sel = 0;
	#elif defined(__MSDC2_SD_MMC__)
	sel = 1;
	#endif
	if (dev != DCL_SD)
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID;
	}

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */
	thdId = (kal_uint32)kal_get_current_thread_ID();
#ifdef MSDC_TRACE_LEVEL2
	drv_trace4(TRACE_GROUP_8,MSDC_DCL_SD_OPEN, flags, (kal_uint32)retAddr, thdId ,(kal_uint32)drv_get_current_time());
#endif
	if(flags & DCL_SD_FLAGS_DEVICE_CARD1){
		if(DCL_SD_FLAGS_DEVICE_CARD1 != (flags & DCL_SD_FLAGS_DEVICE_ALL)){
			ASSERT(0);
		}
		if(flags & DCL_SD_FLAGS_USAGE_CMD){/*wanna get handle to control MSDC1, need contention for action handle*/
			kal_uint16	magic;

			//
			// To prevent resource to be occupied twice, use semaphore to gate here.
			//
		        get_MSDC_lock(&dclMsdcLock[0]);
			/*
			if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
			{
				kal_take_sem(dclMsdcArb[0], 1);
			
				// from here, we are the only one gets CMD right to MSDC1, but check the maic first
			if(sdResource[0] & DCL_SD_RESOURCE_OCCUPIED)
				ASSERT(0);
			}
			*/

			/*process the magic of the resource as rolling counter*/
			magic = (sdResource[0] & DCL_SD_RESOURCE_MAGIC_MAX);
			if(DCL_SD_RESOURCE_MAGIC_MAX == magic) /*if means 0x0FF0 achieved*/
				magic = DCL_SD_RESOURCE_MAGIC_UNIT;
			else
				magic += DCL_SD_RESOURCE_MAGIC_UNIT;
			
			sdResource[0] = (DCL_SD_RESOURCE_OCCUPIED | magic);

			sdDbgRrc[0].callerRetAddr = retAddr;
			sdDbgRrc[0].ownerThdId = thdId;
			sdDbgRrc[0].ownerThdId |=0;
				
			return (DCL_SD_HANDLE_SD1 | magic);
		}
		else{/*just wanna get handle to get information of this device, return handle directly*/
			return DCL_SD_HANDLE_SD1;
		}
	}
	else if(flags & DCL_SD_FLAGS_DEVICE_CARD2){
#if defined(__MSDC2_SD_MMC__)
		if(DCL_SD_FLAGS_DEVICE_CARD2 != (flags & DCL_SD_FLAGS_DEVICE_ALL)){
			ASSERT(0);
		}
		if(flags & DCL_SD_FLAGS_USAGE_CMD){/*wanna get handle to control MSDC2, need contention action handle*/
			kal_uint16	magic;
			
			//
			// The same as MSDC1.
			//
			get_MSDC_lock(&dclMsdcLock[1]);
			/*
			if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
			{
				kal_take_sem(dclMsdcArb[1], 1);
			
				// from here, we are the only one gets CMD right to MSDC2, but check the maic first
			if(sdResource[1] & DCL_SD_RESOURCE_OCCUPIED)
				ASSERT(0);
			}
			*/
			
			/*process the magic of the resource as rolling counter*/
			magic = (sdResource[1] & DCL_SD_RESOURCE_MAGIC_MAX);
			if(DCL_SD_RESOURCE_MAGIC_MAX == magic) /*if means 0x0FF0 achieved*/
				magic = DCL_SD_RESOURCE_MAGIC_UNIT;
			else
				magic += DCL_SD_RESOURCE_MAGIC_UNIT;
			
			sdResource[1] = (DCL_SD_RESOURCE_OCCUPIED | magic);

			sdDbgRrc[1].callerRetAddr = retAddr;
			sdDbgRrc[1].ownerThdId = thdId;
			
			return (DCL_SD_HANDLE_SD2 | magic);
		}
		else{/*just wanna get handle to get information of this device, return handle directly*/
			return DCL_SD_HANDLE_SD2;
		}
#else
		ASSERT(0);
#endif
	}
	else if(flags & DCL_SD_FLAGS_DEVICE_SIMPLUS){
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)||defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
		if(DCL_SD_FLAGS_DEVICE_SIMPLUS != (flags & DCL_SD_FLAGS_DEVICE_ALL)){
			ASSERT(0);
		}
		if(flags & DCL_SD_FLAGS_USAGE_CMD){
		kal_uint16	magic;
		get_MSDC_lock(&dclMsdcLock[sel]);
		magic = (sdResource[sel] & DCL_SD_RESOURCE_MAGIC_MAX);
			if(DCL_SD_RESOURCE_MAGIC_MAX == magic) /*if means 0x0FF0 achieved*/
				magic = DCL_SD_RESOURCE_MAGIC_UNIT;
			else
				magic += DCL_SD_RESOURCE_MAGIC_UNIT;
			
			sdResource[sel] = (DCL_SD_RESOURCE_OCCUPIED | magic);

			sdDbgRrc[sel].callerRetAddr = retAddr;
			sdDbgRrc[sel].ownerThdId = thdId;
				
			return (DCL_SD_HANDLE_SIMPLUS | magic);
		}
		else{/*just wanna get handle to get information of this device, return handle directly*/
		return DCL_SD_HANDLE_SIMPLUS;
		}
#else
		ASSERT(0);
#endif
	}
	return 0;
}

DCL_STATUS DclSD_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	ASSERT(0);
	return 	STATUS_UNSUPPORTED;
}
DCL_STATUS DclSD_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	ASSERT(0);
	return 	STATUS_UNSUPPORTED;
}
DCL_STATUS DclSD_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	DCL_SD_IMPLEMENTATION_ASSERT;
	return STATUS_UNSUPPORTED;
}
DCL_STATUS DclSD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	ASSERT(0);
	return 	STATUS_UNSUPPORTED;
}


typedef DCL_STATUS (*DCL_SD_CTRL_API) (DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);


DCL_STATUS DCL_SD_CTRL_API_READ(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_SDC_CMD_STATUS status=0;
	SD_CTRL_READ_T *prRead;
	sd_select_enum sel;

	sel=DCL_SD_USING_RESOURCE_START(handle);

	prRead = &(data->rSDRead);
	status = DclSD_CtrlCmdRead(sel, prRead);
			
	DCL_SD_USING_RESOURCE_END(handle,sel);

	return status;
}

DCL_STATUS DCL_SD_CTRL_API_WRITE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_SDC_CMD_STATUS status=0;
	SD_CTRL_WRITE_T *prWrite;
	sd_select_enum sel;

	sel=DCL_SD_USING_RESOURCE_START(handle);
			
	prWrite = &(data->rSDWrite);
	status = DclSD_CtrlCmdWrite(sel, prWrite);
			
	DCL_SD_USING_RESOURCE_END(handle,sel);

	return status;
}

DCL_STATUS DCL_SD_CTRL_API_READ_ODD_SIZE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_SDC_CMD_STATUS status=0;

		ASSERT(0);
	return status;
}

DCL_STATUS DCL_SD_CTRL_API_WRITE_ODD_SIZE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_SDC_CMD_STATUS status=0;

				ASSERT(0);
	
	return status;
}

DCL_STATUS DCL_SD_CTRL_API_INIT(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_SDC_CMD_STATUS status=0;
			sd_select_enum sel;

			sel=DCL_SD_USING_RESOURCE_START(handle);
			
			if (DCL_SD_HANDLE_SD1 == DCL_SD_GET_DUMMY_HANDLE(handle)
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)||defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
				|| DCL_SD_HANDLE_SIMPLUS == DCL_SD_GET_DUMMY_HANDLE(handle)
#endif
#if defined(__MSDC2_SD_MMC__)
				|| DCL_SD_HANDLE_SD2 == DCL_SD_GET_DUMMY_HANDLE(handle)
#endif
				)
			{
			#if defined(__MSDC_SD_MMC__)
				msdcDriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_FALSE);
				status = sdDriverTable[sel]->sdInititalize();
				msdcDriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_TRUE);
			#elif defined(__MSDC2_SD_MMC__)
				msdc2DriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_FALSE);
				status = sd2DriverTable[sel]->sdInititalize();
				msdc2DriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_TRUE);
			#endif
			}
			else{
				ASSERT(0);
			}
			
			DCL_SD_USING_RESOURCE_END(handle,sel);

	
	return status;
}

DCL_STATUS DCL_SD_CTRL_API_IS_INITED(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SD_CTRL_INITED_T *prInited;
	sd_select_enum sel;

	prInited = &(data->rSDInited);
	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_MMC__)
	prInited->fgInited = MSDC_Blk[sel].mIsInitialized;
	#elif defined(__MSDC2_SD_MMC__)
	prInited->fgInited = MSDC2_Blk[sel].mIsInitialized;
	#endif

	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_ANALOG_SWITCH(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_SDC_CMD_STATUS status;

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)||defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
	SD_CTRL_ANALOG_SWITCH_T *prSwitch;
	sel=DCL_SD_USING_RESOURCE_START(handle);
			
	prSwitch = &(data->rSDSwitch);
	sel = prSwitch->u4TargetInterface;
	#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	MSDC_Switch_Card(sel);
	#elif defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
	MSDC2_Switch_Card(sel);
	#endif
	
	
	DCL_SD_USING_RESOURCE_END(handle,sel);
			
	status = NO_ERROR;
#else
	ASSERT(0);
	status = (DCL_SDC_CMD_STATUS)STATUS_INVALID_CMD;
#endif

	return status;
}

DCL_STATUS DCL_SD_CTRL_API_FAST_FORMAT_START(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	sd_select_enum sel;

	/*currently we only support fast format on SD1, check it*/
	if(DCL_SD_HANDLE_SD1 != DCL_SD_GET_DUMMY_HANDLE(handle)){
		ASSERT(0);
	}

	sel=DCL_SD_USING_RESOURCE_START(handle);
	#if defined(__MSDC_SD_MMC__)
	SD_startFastFormat();
	#elif defined(__MSDC2_SD_MMC__)
	SD2_startFastFormat();
	#endif
	DCL_SD_USING_RESOURCE_END(handle,sel);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_FAST_FORMAT_STOP(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	sd_select_enum sel;

	/*currently we only support fast format on SD1, check it*/
	if(DCL_SD_HANDLE_SD1 != DCL_SD_GET_DUMMY_HANDLE(handle)){
		ASSERT(0);
	}

	sel=DCL_SD_USING_RESOURCE_START(handle);
	#if defined(__MSDC_SD_MMC__)		
	SD_closeFastFormat();
	#elif defined(__MSDC2_SD_MMC__)
	SD2_closeFastFormat();
	#endif

	DCL_SD_USING_RESOURCE_END(handle,sel);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_IS_FAST_FORMAT_RUNNING(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
#ifdef __DRV_MSDC_FAST_FORMAT__
	SD_CTRL_FAST_FORMAT_T *ff = &(data->rSDFastFormat);
#endif
	sd_select_enum sel;

	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	sel|=0;
#ifdef __DRV_MSDC_FAST_FORMAT__
	#if defined(__MSDC_SD_MMC__)
	ff->enable = (DCL_BOOL)MSDC_Blk[sel].MSDC_fastFormat;
	#elif defined(__MSDC2_SD_MMC__)
	ff->enable = (DCL_BOOL)MSDC2_Blk[sel].MSDC_fastFormat;
	#endif
#endif

	return STATUS_OK;		 
}

DCL_STATUS DCL_SD_CTRL_API_GET_CAPACITY(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SD_CTRL_GET_CAPACITY_T *prGetCapacity;
	sd_select_enum sel;
			
	prGetCapacity = &(data->rSDGetCapacity);
	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_MMC__)
	prGetCapacity->pu8Capacity = gSD_blk[sel].mCSD.capacity;
	#elif defined(__MSDC2_SD_MMC__)
	prGetCapacity->pu8Capacity = gSD2_blk[sel].mCSD.capacity;
	#endif
	prGetCapacity->gHighCapacityCard = SD_FLAG_HCS_SUPPORT ? KAL_TRUE:KAL_FALSE;
	
	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_IS_EXISTENCE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SD_CTRL_EXISTENCE_T *prExistence;
	sd_select_enum sel;
/*this function differs to SD_CTRL_CMD_POLL_EXISTENCE, we only get status from global variables*/			
	prExistence = &(data->rSDExistence);
	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_MMC__)
	prExistence->fgPresent = MSDC_Blk[sel].mIsPresent;//MSDC_Blk[sel].mIsInitialized;
	#elif defined(__MSDC2_SD_MMC__)
	prExistence->fgPresent = MSDC2_Blk[sel].mIsPresent;
	#endif
	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_POLL_EXISTENCE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
//	DCL_SDC_CMD_STATUS status;
	SD_CTRL_EXISTENCE_T *prPollExistence;
	sd_select_enum sel;

	/*this function differs to SD_CTRL_CMD_IS_EXISTENCE, we will get card's status again*/

	/*we don't support hot plug of SIM+ , so hot plug related functions are prohibited*/


	sel=DCL_SD_USING_RESOURCE_START(handle);
		
	prPollExistence = &(data->rSDExistence);
#if defined(__MSDC_SD_MMC__)
	if (MSDC1_SD1 == sel 
	#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
		|| MSDC1_SD2 == sel
	#endif
		)
	{
		prPollExistence->fgPresent = DclSD_PollExistence(IRQ_MSDC_CODE, MSDC_PS, sel);
	}
#elif defined(__MSDC2_SD_MMC__)
	if (MSDC2_SD1 == sel 
	#if defined(DRV_MSDC2_DUAL_TCARD_BY_SWITCH)
			|| MSDC2_SD2 == sel
	#endif
			)
		{
			prPollExistence->fgPresent = DclSD_PollExistence(IRQ_MSDC2_CODE, MSDC_PS2, sel);
		}
#endif
	DCL_SD_USING_RESOURCE_END(handle,sel);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_SET_CLEAR_EXISTENCE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SD_CTRL_EXISTENCE_T *prExistence;
	sd_select_enum sel;

	prExistence = &(data->rSDExistence);
	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_MMC__)
	MSDC_Blk[sel].mIsPresent =(kal_bool)prExistence->fgPresent;
	#elif defined(__MSDC2_SD_MMC__)
	MSDC2_Blk[sel].mIsPresent =(kal_bool)prExistence->fgPresent;
	#endif

	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_WRITE_PROTECTION(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SD_CTRL_WRITE_PROTECTION_T *prWP;
	sd_select_enum sel;
			
	prWP = &(data->rSDWriteProrect);
	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_MMC__)
	prWP->fgReadOnly = gSD_blk[sel].mWPEnabled;
	#elif defined(__MSDC2_SD_MMC__)
	prWP->fgReadOnly = gSD2_blk[sel].mWPEnabled;
	#endif
	
	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_QUERY_EVER_PLUGOUT(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SD_CTRL_QUERY_EVER_PLUGOUT_T *prQueryPlugOut;
	sd_select_enum sel;


	prQueryPlugOut = &(data->rSDQueryEverPugOut);
	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_MMC__)
	prQueryPlugOut->fgEverPLugOut = MSDC_Blk[sel].MSDC_everPlugOut;
	#elif defined(__MSDC2_SD_MMC__)
	prQueryPlugOut->fgEverPLugOut = MSDC2_Blk[sel].MSDC_everPlugOut;
	#endif
	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_RESET_EVER_PLUGOUT(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
//	DCL_SDC_CMD_STATUS status;
	sd_select_enum sel;

	/*everPLugOut is set true in hot plug interrupt and DCL provide function to set false*/



			
	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);

	#if defined(__MSDC_SD_MMC__)
	MSDC_Blk[sel].MSDC_everPlugOut = KAL_FALSE;
	#elif defined(__MSDC2_SD_MMC__)
	MSDC2_Blk[sel].MSDC_everPlugOut = KAL_FALSE;
	#endif
	
	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_FORCE_SINGLE_LINE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SD_CTRL_FORCE_SINGLE_LINE_T *prForceSingleLine;
	sd_select_enum sel;

			
	/*should add a assertion check for the MSDC that only support single line mode*/
	prForceSingleLine = &(data->rSDForceSingleLine);
	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_MMC__)
	MSDC_Blk[sel].trySingleLine = (kal_bool)prForceSingleLine->fgIsItTrue;
	#elif defined(__MSDC2_SD_MMC__)
	MSDC2_Blk[sel].trySingleLine = (kal_bool)prForceSingleLine->fgIsItTrue;
	#endif

	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_GO_IDLE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	sd_select_enum sel;

	/*This function is to set global state mIsInitialized = false, it is only driver can set it to true*/

	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_MMC__)
	MSDC_Blk[sel].mIsInitialized = KAL_FALSE;
	#elif defined(__MSDC2_SD_MMC__)
	MSDC2_Blk[sel].mIsInitialized = KAL_FALSE;
	#endif

	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_CACHEABLE_BUFFER(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{	
#ifdef MSDC_CACHED_SUPPORT
	SD_CTRL_CACHEABLE_BUFFER_T *prCachedBuffer;
	sd_select_enum sel;

	sel=DCL_SD_USING_RESOURCE_START(handle);
			
	prCachedBuffer = &(data->rSDCacheableBuf);
	#if defined(__MSDC_SD_MMC__)
	MSDC_Blk[sel].isCachedBuf = (kal_bool)prCachedBuffer->fgIsCACHEABLE;
	#elif defined(__MSDC2_SD_MMC__)
	MSDC2_Blk[sel].isCachedBuf = (kal_bool)prCachedBuffer->fgIsCACHEABLE;
	#endif
	
	DCL_SD_USING_RESOURCE_END(handle,sel);
#endif

	return STATUS_OK;
}

DCL_STATUS DCL_SD_CTRL_API_SET_READ_FLAG(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{        
			DCL_SDC_CMD_STATUS status; 
			sd_select_enum sel;
			SD_CTRL_SET_READ_TEST_FLAG_T *readFlag;
			
			readFlag =&(data->rSDSetReadTestFlag);
			sel=DCL_SD_USING_RESOURCE_START(handle);
			#if defined(__MSDC_SD_MMC__)
			status = sdDriverTable[sel]->sdSetReadTestFlag(readFlag->readTestFlag);
			#elif defined(__MSDC2_SD_MMC__)
			status = sd2DriverTable[sel]->sdSetReadTestFlag(readFlag->readTestFlag);
			#endif
			DCL_SD_USING_RESOURCE_END(handle,sel);
			return status;
			
}
DCL_STATUS DCL_SD_CTRL_API_SET_READ_TEST(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
			
			DCL_SDC_CMD_STATUS status;  
			sd_select_enum sel;
			
			sel=DCL_SD_USING_RESOURCE_START(handle);
			#if defined(__MSDC_SD_MMC__)
			msdcDriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_FALSE);
			status = sdDriverTable[sel]->sdSetReadTest();
			msdcDriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_TRUE);
			#elif defined(__MSDC2_SD_MMC__)
			msdcDriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_FALSE);
			status = sdDriverTable[sel]->sdSetReadTest();
			msdcDriverTable[sel].modulePDN((DCL_BOOLEAN)KAL_TRUE);
			#endif
			
			DCL_SD_USING_RESOURCE_END(handle,sel);
			
			return status;
		
}
DCL_STATUS DCL_SD_CTRL_API_SET_UPLL_CLOCK(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
			
			DCL_SDC_CMD_STATUS status;  
			sd_select_enum sel;
			
			sel=DCL_SD_USING_RESOURCE_START(handle);
			//msdcDriverTable[sel].modulePDN(KAL_FALSE);
			#if defined(__MSDC_SD_MMC__)
			status = sdDriverTable[sel]->sdSetUpllClock();
			#elif defined(__MSDC2_SD_MMC__)
			status = sd2DriverTable[sel]->sdSetUpllClock();
			#endif
			//msdcDriverTable[sel].modulePDN(KAL_TRUE);
			DCL_SD_USING_RESOURCE_END(handle,sel);
			return status;
		
}
DCL_STATUS DCL_SD_CTRL_API_SET_CALLBACK(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{		
			DCL_SDC_CMD_STATUS status;
			SD_CTRL_CALLBACK_T *callBack;
			sd_select_enum sel;
			
			callBack =&(data->rSDCallBackFunc);
			sel=DCL_SD_USING_RESOURCE_START(handle);
			#if defined(__MSDC_SD_MMC__)
			status = sdDriverTable[sel]->sdSetCallBack(callBack->callback1,callBack->callback2,callBack->callback3,callBack->callback4,callBack->callback5,callBack->callback6);
			#elif defined(__MSDC2_SD_MMC__)
			status = sd2DriverTable[sel]->sdSetCallBack(callBack->callback1,callBack->callback2,callBack->callback3,callBack->callback4,callBack->callback5,callBack->callback6);
			#endif
			DCL_SD_USING_RESOURCE_END(handle,sel);
			return status;		 
}
DCL_STATUS DCL_SD_CTRL_API_FLUSH_SECTORS(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{		
			DCL_SDC_CMD_STATUS status;
			SD_CTRL_FLUSH_T *flush;
			sd_select_enum sel;
			
			flush =&(data->rSDFlush);
			sel=DCL_SD_USING_RESOURCE_START(handle);
			#if defined(__MSDC_SD_MMC__)
			status = sdDriverTable[sel]->eraseBlk(flush->startSector,flush->sectorNum);
			#elif defined(__MSDC2_SD_MMC__)
			status = sd2DriverTable[sel]->eraseBlk(flush->startSector,flush->sectorNum);
			#endif
			DCL_SD_USING_RESOURCE_END(handle,sel);
			return status;		 
}
DCL_STATUS DCL_SD_CTRL_API_GET_AND_CLEAR_MEDIA_CHANGED(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{		
//			DCL_SDC_CMD_STATUS status;
			SD_CTRL_MEDIA_CHANGED_T *changed;
			sd_select_enum sel;

			changed = &(data->rSDMediaChanged);
			sel=DCL_SD_USING_RESOURCE_START(handle);
			#if defined(__MSDC_SD_MMC__)
			changed->changed = MSDC_GetMediaChanged(sel);
			#elif defined(__MSDC2_SD_MMC__)
			changed->changed = MSDC2_GetMediaChanged(sel);
			#endif
			DCL_SD_USING_RESOURCE_END(handle,sel);
			return STATUS_OK;		 
}
DCL_SD_CTRL_API	DclSD_APITbl[SD_CTRL_CMD_DUMMY_END - SD_CTRL_CMD_BASE] = 
{
	DCL_SD_CTRL_API_READ,
	DCL_SD_CTRL_API_WRITE,
	DCL_SD_CTRL_API_READ_ODD_SIZE,
	DCL_SD_CTRL_API_WRITE_ODD_SIZE,
	DCL_SD_CTRL_API_INIT,
	DCL_SD_CTRL_API_IS_INITED,
	DCL_SD_CTRL_API_ANALOG_SWITCH,
	DCL_SD_CTRL_API_FAST_FORMAT_START,
	DCL_SD_CTRL_API_FAST_FORMAT_STOP,
	DCL_SD_CTRL_API_IS_FAST_FORMAT_RUNNING,
	DCL_SD_CTRL_API_GET_CAPACITY,
	DCL_SD_CTRL_API_IS_EXISTENCE,
	DCL_SD_CTRL_API_POLL_EXISTENCE,
	DCL_SD_CTRL_API_SET_CLEAR_EXISTENCE,
	DCL_SD_CTRL_API_WRITE_PROTECTION,
	DCL_SD_CTRL_API_QUERY_EVER_PLUGOUT,
	DCL_SD_CTRL_API_RESET_EVER_PLUGOUT,
	DCL_SD_CTRL_API_FORCE_SINGLE_LINE,
	DCL_SD_CTRL_API_GO_IDLE,
	DCL_SD_CTRL_API_CACHEABLE_BUFFER,
	DCL_SD_CTRL_API_SET_CALLBACK,
	DCL_SD_CTRL_API_SET_READ_FLAG,
	DCL_SD_CTRL_API_SET_READ_TEST,
	DCL_SD_CTRL_API_SET_UPLL_CLOCK,
	DCL_SD_CTRL_API_FLUSH_SECTORS,
	DCL_SD_CTRL_API_GET_AND_CLEAR_MEDIA_CHANGED,
};


// for debugging
DCL_CTRL_CMD_T dcl_sd_cmd_start = SD_CTRL_CMD_BASE;
DCL_CTRL_CMD_T dcl_sd_cmd_end = SD_CTRL_CMD_DUMMY_END;
DCL_STATUS DclSD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{

	DCL_SDC_CMD_STATUS status = 0;

  // Mark here because we use dclsd_open to take semaphore.
  /*
	//dispatch
	if (SD_CTRL_CMD_DUMMY_END > cmd && SD_CTRL_CMD_BASE <= cmd){
		if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
		{
			if (DCL_SD_HANDLE_SD1 == DCL_SD_GET_DUMMY_HANDLE(handle))
				//kal_take_sem(dclMsdcArb[0], 1);
				get_MSDC_lock(&dclMsdcLock[0]);
#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
			else if (DCL_SD_HANDLE_SD2 == DCL_SD_GET_DUMMY_HANDLE(handle))
				//kal_take_sem(dclMsdcArb[1], 1);
				get_MSDC_lock(&dclMsdcLock[1]);
#endif
		}
  */

		#if 0
/* under construction !*/
		#else
		status = DclSD_APITbl[cmd - SD_CTRL_CMD_BASE](handle, cmd, data);
		#endif

    // Remove give semaphore, we move it to dclsd_close.
    /*
		if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
		{
			if (DCL_SD_HANDLE_SD1 == DCL_SD_GET_DUMMY_HANDLE(handle))
				//kal_give_sem(dclMsdcArb[0]);
				free_MSDC_lock(&dclMsdcLock[0]);
#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
			else if (DCL_SD_HANDLE_SD2 == DCL_SD_GET_DUMMY_HANDLE(handle))
				//kal_give_sem(dclMsdcArb[1]);
				free_MSDC_lock(&dclMsdcLock[1]);
#endif
		}
		
	}
	else{
		ASSERT(0);
		status = STATUS_INVALID_CMD;
	}
    */

	/*status central wrapper here, this is an inefficient but readable way*/
	switch(status){
		case NO_ERROR:
			return STATUS_OK;
			//break;			
		case ERR_CMD_TIMEOUT:/*fall through*/
			return STATUS_ERROR_TIMEOUT;
			//break;
		case ERR_DAT_CRCERR:
		case MSDC_GPT_TIMEOUT_ERR:
	  case ERR_CMD_RSPCRCERR:	
		    return STATUS_ERROR_CRCERROR;
		//	break;			
		case ERR_WRITE_PROTECT:
			return STATUS_ERROR_READONLY;
		//	break;
		case ERR_CMDOK_DATREADFAIL:
			return ERR_CMDOK_DATREADFAIL;
		default:
			//ASSERT(0);
			return STATUS_ERROR_WRONG_STATE;
	//	break;
	}

}



DCL_STATUS DclSD_Close(DCL_HANDLE handle)
{
	sd_select_enum sel;

	sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_MMC__)
	sel = 0;
	#elif defined(__MSDC2_SD_MMC__)
	sel = 1;
	#endif
	/*check whether it is action handle, if not, return directly*/
	if(0 == DCL_SD_GET_MAGIC_FROM_HANDLE(handle)){
		return STATUS_OK;
	}
	else{
		kal_uint16	magic;
		//jinxing remove this . since we never do free later.
		//DCL_SD_USING_RESOURCE_START(handle);
		/*after this point, we think that none should be able to use this action handle*/
		
		/*process the magic of the resource*/
		magic = (sdResource[sel] & DCL_SD_RESOURCE_MAGIC_MAX);
		if(DCL_SD_RESOURCE_MAGIC_MAX == magic){ /*if means 0x0FF0 achieved*/
			magic = DCL_SD_RESOURCE_MAGIC_UNIT;
		}
		else{
			magic += DCL_SD_RESOURCE_MAGIC_UNIT;
		}
		sdResource[sel] = magic;

		//
		// To make a pair of taking and giving semaphore, add back the following action.
		//
		#if defined(__MSDC_SD_MMC__)
		free_MSDC_lock(&dclMsdcLock[0]);
		#elif defined(__MSDC2_SD_MMC__)
		free_MSDC_lock(&dclMsdcLock[1]);
		#endif
		/*
		if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
			kal_give_sem(dclMsdcArb[sel]);
		*/

		return STATUS_OK;
	}		
}
#endif //MSDC,MSDC2
/***************************************************************************************
followings are DCL SDIO API exported 
*****************************************************************************************/


/**************************************************************************
followings are DCL API exported 
***************************************************************************/
/*************************************************************************
* FUNCTION
*  DclSD_Initialize
*
* DESCRIPTION
* 	This function is to initialize the SD driver related resource. 
*	This function should be called in system initialization before tasks are scheduling.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_OK : this should be the only return value since MSDC_initialize returns nothing.
*
*************************************************************************/
#if defined(__MSDC_SD_SDIO__)
extern SDIODriver_t sdio_driver_MTK1;//guilin
DCL_STATUS DclSDIO_Initialize(void)
{
	kal_uint32	maskedValue;

	maskedValue = SaveAndSetIRQMask();
	/*a sync mechanism to guarantee MSDC_Initialize is only called once*/
	if(KAL_FALSE == fgMSDCInit){
		fgMSDCInit = KAL_TRUE;
		RestoreIRQMask(maskedValue);
		DclMSDC_init();
	}
	else{
		RestoreIRQMask(maskedValue);
	}
	MSDC_turnOnVMC(KAL_TRUE);//mtk05649
	maskedValue = SaveAndSetIRQMask();
	if(KAL_FALSE == fgSDIOInit){
		fgSDIOInit = KAL_TRUE;
		RestoreIRQMask(maskedValue);
		/*init SD driver tables, there are too many entries in SD driver, so we hook it by pointer*/
#if defined(__MSDC_SD_SDIO__)		
		sdioDriverTable[DCL_SDIO_GET_SEL_FROM_HANDLE(DCL_SDIO_HANDLE_SDIO1)] = &sdio_driver_MTK1;
#endif

#if defined(__MSDC2_SD_SDIO__)
		sdioDriverTable[DCL_SDIO_GET_SEL_FROM_HANDLE(DCL_SDIO_HANDLE_SDIO2)] = &sdio_driver_MTK2; //in the design, sel = 2 is preserved for SIM+ card, which uses 1st MSDC's code
#endif
	}
	else{
		RestoreIRQMask(maskedValue);
	}
	
	return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclSD_Initialize
*
* DESCRIPTION
* 	This function is to get SD DCL handler.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_OK : this should be the only return value since MSDC_initialize returns nothing.
*
*************************************************************************/
DCL_HANDLE DclSDIO_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	kal_uint32 retAddr = 0;
	kal_uint32 thdId;	

	if (dev != DCL_SDIO)
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID;
	}

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */
	thdId = (kal_uint32)kal_get_current_thread_ID();

	//drv_trace4(TRACE_GROUP_8, MSDC_DCL_SD_OPEN, flags, retAddr, thdId , drv_get_current_time());

	if(flags & DCL_SDIO_FLAGS_SDIO1){
		if(DCL_SDIO_FLAGS_SDIO1 != (flags & DCL_SDIO_FLAGS_ALL)){
			ASSERT(0);
		}
		get_MSDC_lock(&dclMsdcLock[0]);
		return DCL_SDIO_HANDLE_SDIO1;
	}
#if defined(__MSDC2_SD_SDIO__)
	else if(flags & DCL_SDIO_FLAGS_SDIO2){
		if(DCL_SDIO_FLAGS_SDIO2 != (flags & DCL_SDIO_FLAGS_ALL)){
			ASSERT(0);
		}
		get_MSDC_lock(&dclMsdcLock[1]);
		return DCL_SDIO_HANDLE_SDIO2;
	}
#endif
}

DCL_STATUS DclSDIO_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	ASSERT(0);
	return 	STATUS_UNSUPPORTED;
}
DCL_STATUS DclSDIO_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	ASSERT(0);
	return 	STATUS_UNSUPPORTED;
}
DCL_STATUS DclSDIO_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	DCL_SD_IMPLEMENTATION_ASSERT;
	return STATUS_UNSUPPORTED;
}
DCL_STATUS DclSDIO_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	//DCL_SD_IMPLEMENTATION_ASSERT;
	//ASSERT(0);
	//return 	STATUS_UNSUPPORTED;
	// guilin
    sd_select_enum sel;
    
    sel = DCL_SDIO_GET_SEL_FROM_HANDLE(handle);
    sdioDriverTable[sel]->hisr_callback(DCL_SDIO_FUCN_0, callback);
    sdioDriverTable[sel]->hisr_callback(DCL_SDIO_FUCN_1, callback);

    return STATUS_OK;
}



/*************************************************************************
* FUNCTION
*  DclGPIO_Control
*
* DESCRIPTION
*  This function is to send command to control the GPIO module.
*
* PARAMETERS
*	handle - a valid handle return by DclGPIO_Open()
*  cmd   - a control command for GPIO module
*          1. GPIO_CMD_READ: to read the input value of a GPIO port (high/low)
*          2. GPIO_CMD_WRITE: to write to the output of a GPIO port (high/low)
*          3. GPIO_CMD_SET_MODE: to set the mode of a GPIO port
*          4. GPIO_CMD_SET_DIR: to set the direction of a GPIO port
*          5. GPIO_CMD_RETURN_MODE: to get the mode of a GPIO port
*          6. GPIO_CMD_RETURN_DIR: to get the direction of a GPIO port
*          7. GPIO_CMD_RETURN_OUT: to return the output value of a GPIO port
*          8. GPIO_CMD_ENABLE_PULL: to enable the pull resister for a GPIO port
*          9. GPIO_CMD_SEL_PULL: to select the pull up or pull down for a GPIO port
*          10. GPIO_CMD_SET_DINV: to set the inversion of a GPIO port
*          11. GPIO_CMD_SET_DEBUG: to enable or disable debug mode
*          12. GPIO_CMD_SET_CLK_OUT: to set the clock frequency for a clock output
*          13. GPIO_CMD_SET_TM_DIR: to set TM direction
*  data - for 1. GPIO_CMD_READ: pointer to a HGPT_CTRL_CLK_T structure
*             2. GPIO_CMD_WRITE: pointer to a HGPT_CTRL_RESET_T structure
*             3. GPIO_CMD_SET_MODE: pointer to a GPIO_CTRL_SET_MODE_T structure
*             4. GPIO_CMD_SET_DIR: pointer to a GPIO_CTRL_SET_DIR_T structure
*             5. GPIO_CMD_RETURN_MODE: pointer to a GPIO_CTRL_RETURN_MODE_T structure
*             6. GPIO_CMD_RETURN_DIR: pointer to a GPIO_CTRL_RETURN_DIR_T structure
*             7. GPIO_CMD_RETURN_OUT: pointer to a GPIO_CTRL_RETURN_OUT_T structure
*             8. GPIO_CMD_ENABLE_PULL: pointer to a GPIO_CTRL_ENABLE_PULL_T structure
*             9. GPIO_CMD_SEL_PULL: pointer to a GPIO_CTRL_SEL_PULL_T structure
*             10. GPIO_CMD_SET_DINV: pointer to a GPIO_CTRL_SET_DINV_T structure
*             11. GPIO_CMD_SET_DEBUG: pointer to a GPIO_CTRL_SET_DEBUG_T structure
*             12. GPIO_CMD_SET_CLK_OUT: pointer to a GPIO_CTRL_SET_CLK_OUT_T structure
*             13. GPIO_CMD_SET_TM_DIR: pointer to a GPIO_CTRL_SET_TM_DIR_T structure
*
* RETURNS
*	STATUS_OK - command is executed successfully.
*	STATUS_FAIL - command is failed.
*  STATUS_INVALID_CMD - The command is invalid.
*  STATUS_INVALID_HANDLE - The handle is invalid.
*  STATUS_INVALID_CTRL_DATA - The ctrl data is not valid.
*************************************************************************/
DCL_STATUS DclSDIO_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_BOOL status;/*in the world of SDIO driver, the return value is either trur or false*/
    sd_select_enum sel;

    sel = DCL_SDIO_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_SDIO__)
    msdcDriverTable[sel].modulePDN(KAL_FALSE);
	#elif defined(__MSDC2_SD_SDIO__)
	msdc2DriverTable[sel].modulePDN(KAL_FALSE);
	#endif
	switch(cmd){
		case SDIO_CTRL_CMD_REG_WR:
		{
			SDIO_CTRL_REG_RW_T *prRegWr;

			prRegWr = &data->rSDIORegRw;
			status = sdioDriverTable[sel]->regWr(prRegWr->function, prRegWr->addr, prRegWr->data, prRegWr->op);
			break;
		}
		case SDIO_CTRL_CMD_REG_WR_ISR:
		{
			SDIO_CTRL_REG_RW_T *prRegWrIsr;

			prRegWrIsr = &data->rSDIORegRw;
			status = sdioDriverTable[sel]->regWrInIsr(prRegWrIsr->function, prRegWrIsr->addr, prRegWrIsr->data, prRegWrIsr->op);
			break;
		}
		case SDIO_CTRL_CMD_DATA_WR:
		{
			SDIO_CTRL_DAT_RW_T *prDatWr;

			prDatWr = &data->rSDIODatRw;
			status = sdioDriverTable[sel]->dataWr(prDatWr->function, prDatWr->addr, (DCL_UINT8  *)prDatWr->buffer, prDatWr->op, prDatWr->count, prDatWr->block);
			break;
		}
		case SDIO_CTRL_CMD_REG_RD:
		{
			SDIO_CTRL_REG_RW_T *prRegRd;

			prRegRd = &data->rSDIORegRw;
			status = sdioDriverTable[sel]->regRd(prRegRd->function, prRegRd->addr, &prRegRd->data, prRegRd->op);
			break;			
		}
		case SDIO_CTRL_CMD_DATA_RD:
		{
			SDIO_CTRL_DAT_RW_T *prDatRd;

			prDatRd = &data->rSDIODatRw;
			status = sdioDriverTable[sel]->dataRd(prDatRd->function, prDatRd->addr, (DCL_UINT8  *)prDatRd->buffer, prDatRd->op, prDatRd->count, prDatRd->block);
			break;
		}
		case SDIO_CTRL_CMD_CHECK_INTR:
		{
			SDIO_CTRL_CHECK_INTR_T *prCheckIntr;

			prCheckIntr = &data->rSDIOCheckIntr;
			status = sdioDriverTable[sel]->checkIntr(prCheckIntr->function, prCheckIntr->pending);
			break;
		}
		case SDIO_CTRL_CMD_ENABLE_INTR:
		{
			SDIO_CTRL_ENABLE_T *prEnableIntr;

			prEnableIntr = &data->rSDIOEnable;
			status = sdioDriverTable[sel]->enableIntr(prEnableIntr->function, prEnableIntr->enable);
			break;
		}
		case SDIO_CTRL_CMD_INIT:
		{
			status = sdioDriverTable[sel]->sdioInititalize();
			break;
		}
		case SDIO_CTRL_CMD_ABORT:
		{
			DCL_SDIO_function_id_enum function;

			function = data->rSDIOFunction;
			status = sdioDriverTable[sel]->abort(function);
			break;
		}
		case SDIO_CTRL_CMD_SW_RST:
		{
			status = sdioDriverTable[sel]->swRst();
			break;
		}
		case SDIO_CTRL_CMD_QUERY_BLK_SIZE:
		{
			DCL_SDIO_function_id_enum function;

			function = data->rSDIOFunction;
			status = sdioDriverTable[sel]->qryBlkSize(function);
			break;
		}
		case SDIO_CTRL_CMD_SET_BLK_SIZE:
		{
			SDIO_CTRL_SET_BLK_SIZE_T *prSetBlkSize;

			prSetBlkSize = &data->rSDIOSetBlkSize;
			status = sdioDriverTable[sel]->setBlkSize(prSetBlkSize->function, prSetBlkSize->size);
			break;
		}
		case SDIO_CTRL_CMD_ENABLE_IO:
		{
			SDIO_CTRL_ENABLE_T *prEnableIO;

			prEnableIO = &data->rSDIOEnable;
			status = sdioDriverTable[sel]->enableIO(prEnableIO->function, prEnableIO->enable);
			break;
		}
		case SDIO_CTRL_CMD_SET_BUS_WIDTH:
		{
			DCL_SD_BITWIDTH busWidth;

			busWidth = data->rSDIOBusWidth;
			status = sdioDriverTable[sel]->setBusWidth(busWidth);
			break;
		}
        //---------------------------------------------------------------------
        case SDIO_CTRL_CMD_CMD52_READ:
            {
                SDIO_CTRL_CMD52_T *prCMD52;
                
                prCMD52 = &data->rSDIOCMD52;
                status = sdioDriverTable[sel]->cmd52_read(prCMD52->func, prCMD52->addr, &prCMD52->rdata, &prCMD52->r5_resp);
                break;
            }
        case SDIO_CTRL_CMD_CMD52_WRITE:
            {
                SDIO_CTRL_CMD52_T *prCMD52;
                
                prCMD52 = &data->rSDIOCMD52;
                status = sdioDriverTable[sel]->cmd52_write(prCMD52->func, prCMD52->addr, prCMD52->wdata, &prCMD52->r5_resp);
                break;
            }
        case SDIO_CTRL_CMD_CMD52_WRITE_READ:
            {
                SDIO_CTRL_CMD52_T *prCMD52;
                sd_select_enum sel;
                
                prCMD52 = &data->rSDIOCMD52;
                sel = DCL_SDIO_GET_SEL_FROM_HANDLE(handle);
                status = sdioDriverTable[sel]->cmd52_write_read(prCMD52->func, prCMD52->addr, prCMD52->wdata, &prCMD52->rdata, &prCMD52->r5_resp);
                break;
            }
        case SDIO_CTRL_CMD_CMD53_READ:
            {
                SDIO_CTRL_CMD53_T *prCMD53;
                
                prCMD53 = &data->rSDIOCMD53;
                status = sdioDriverTable[sel]->cmd53_read(prCMD53->func, prCMD53->addr, prCMD53->buffer, prCMD53->op, prCMD53->count, prCMD53->block, &prCMD53->r5_resp);
                break;
            }
        case SDIO_CTRL_CMD_CMD53_WRITE:
            {
                SDIO_CTRL_CMD53_T *prCMD53;
                
                prCMD53 = &data->rSDIOCMD53;
                status = sdioDriverTable[sel]->cmd53_write(prCMD53->func, prCMD53->addr, prCMD53->buffer, prCMD53->op, prCMD53->count, prCMD53->block, &prCMD53->r5_resp);
                break;
            }
        case SDIO_CTRL_CMD_MCUDMA_READ:
            {
                SDIO_CTRL_CMD_REG_T *prCMDREG;
                
                prCMDREG = &data->rSDIOCMDREG;
                status = sdioDriverTable[sel]->mcudma_read(&prCMDREG->data);
                break;                
            }
        case SDIO_CTRL_CMD_MCUDMA_WRITE:
            {
                SDIO_CTRL_CMD_REG_T *prCMDREG;
                
                prCMDREG = &data->rSDIOCMDREG;
                status = sdioDriverTable[sel]->mcudma_write(prCMDREG->data);
                break;                
            }
        case SDIO_CTRL_CMD_CLKPADRED_READ:
            {
                SDIO_CTRL_CMD_REG_T *prCMDREG;
                
                prCMDREG = &data->rSDIOCMDREG;
                status = sdioDriverTable[sel]->clkpadred_read(&prCMDREG->data);
                break;                
            }
        case SDIO_CTRL_CMD_CLKPADRED_WRITE:
            {
                SDIO_CTRL_CMD_REG_T *prCMDREG;
                
                prCMDREG = &data->rSDIOCMDREG;
                status = sdioDriverTable[sel]->clkpadred_write(prCMDREG->data);
                break;                
            }
        case SDIO_CTRL_CMD_FORCEMCU_READ:
            {
                SDIO_CTRL_CMD_REG_T *prCMDREG;
                
                prCMDREG = &data->rSDIOCMDREG;
                status = sdioDriverTable[sel]->forcemcu_read(&prCMDREG->data);
                break;                
            }
        case SDIO_CTRL_CMD_FORCEMCU_WRITE:
            {
                SDIO_CTRL_CMD_REG_T *prCMDREG;
                
                prCMDREG = &data->rSDIOCMDREG;
                status = sdioDriverTable[sel]->forcemcu_write(prCMDREG->data);
                break;                
            }
        case SDIO_CTRL_CMD_GETCLK:
            {
                SDIO_CTRL_CMD_REG_T *prCMDREG;
                
                prCMDREG = &data->rSDIOCMDREG;
                status = sdioDriverTable[sel]->getclk(&prCMDREG->data);
                break;                
            }
        case SDIO_CTRL_CMD_SETCLK:
            {
                SDIO_CTRL_CMD_REG_T *prCMDREG;
                
                prCMDREG = &data->rSDIOCMDREG;
                status = sdioDriverTable[sel]->setclk(prCMDREG->data);
                break;                
            }
		case SDIO_CTRL_CMD_GET_BLK_SIZE:
		{
			SDIO_CTRL_SET_BLK_SIZE_T *prSetBlkSize;

			prSetBlkSize = &data->rSDIOSetBlkSize;
			status = sdioDriverTable[sel]->getBlkSize(prSetBlkSize->function, &prSetBlkSize->size);
			break;
		}
        //---------------------------------------------------------------------
		default:
			ASSERT(0);
			status = STATUS_INVALID_CMD;
			break;
	}
	#if defined(__MSDC_SD_SDIO__)
    msdcDriverTable[sel].modulePDN(KAL_TRUE);
	#elif defined(__MSDC2_SD_SDIO__)
	msdc2DriverTable[sel].modulePDN(KAL_TRUE);
	#endif
	
    kal_prompt_trace(MOD_MSDC_HISR,"[%s %d]cmd=%d status=%d",__FUNCTION__,__LINE__,(cmd - SDIO_CTRL_CMD_REG_WR),status);//guilin
	/*status central wrapper here, this is an inefficient but readable way*/
	switch(status){
		case NO_ERROR:
			return STATUS_OK;
		//	break;			
		case ERR_CMD_TIMEOUT:/*fall through*/
		case MSDC_GPT_TIMEOUT_ERR:
			return STATUS_ERROR_TIMEOUT;
		//	break;
		case ERR_DAT_CRCERR:
			return STATUS_ERROR_CRCERROR;
		//	break;			
		case ERR_WRITE_PROTECT:
			return STATUS_ERROR_READONLY;
		//	break;
		case STATUS_ERROR_WRONG_STATE: /*following status code are in the scope of DCL return value, return directly*/
		case STATUS_INVALID_CTRL_DATA:
			return status;
		//	break;
		default:
			//ASSERT(0);
			return STATUS_FAIL;
		break;
	}
	
	/*should not arrive here*/
	ASSERT(0);
	return STATUS_FAIL;
}

DCL_STATUS DclSDIO_Close(DCL_HANDLE handle)
{
//	DCL_SD_IMPLEMENTATION_ASSERT;
//	return STATUS_UNSUPPORTED;

    sd_select_enum sel;

    sel = DCL_SD_GET_SEL_FROM_HANDLE(handle);
	#if defined(__MSDC_SD_SDIO__)
    free_MSDC_lock(&dclMsdcLock[0]);
	#elif defined(__MSDC2_SD_SDIO__)
	free_MSDC_lock(&dclMsdcLock[1]);
	#endif

    return STATUS_OK;
}
#endif


#else /*!defined(DRV_MSDC_OFF)*/


DCL_STATUS DclSD_Initialize(void)
{
	return STATUS_FAIL;
}

DCL_STATUS DclSD_DeInitialize(void)
{
	return STATUS_FAIL;
}

DCL_HANDLE DclSD_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   return DCL_HANDLE_INVALID;
}

DCL_STATUS DclSD_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSD_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSD_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_FAIL;
}

DCL_STATUS DclSD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_FAIL;
}

DCL_STATUS DclSD_Close(DCL_HANDLE handle)
{
	return STATUS_FAIL;
}


DCL_STATUS DclSDIO_Initialize(void)
{
	return STATUS_FAIL;
}

DCL_HANDLE DclSDIO_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   return DCL_HANDLE_INVALID;
}

DCL_STATUS DclSDIO_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSDIO_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSDIO_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSDIO_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_FAIL;
}

DCL_STATUS DclSDIO_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_FAIL;
}

DCL_STATUS DclSDIO_Close(DCL_HANDLE handle)
{
	return STATUS_FAIL;
}

DCL_STATUS DclMS_Initialize(void)
{
	return STATUS_FAIL;
}

DCL_HANDLE DclMS_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   return DCL_HANDLE_INVALID;
}

DCL_STATUS DclMS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclMS_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclMS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclMS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_FAIL;
}

DCL_STATUS DclMS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_FAIL;
}

DCL_STATUS DclMS_Close(DCL_HANDLE handle)
{
	return STATUS_FAIL;
}


#endif /*!defined(DRV_MSDC_OFF)*/

#endif //DCL_MSDC_INTERFACE

