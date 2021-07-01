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
 *
 * Filename:
 * ---------
 * Sal_exp.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   The Interface between Audio Manager(AM) and DSP 
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   
 * $Modtime:   
 * $Log:  


 *******************************************************************************/
#include "Sal_exp.h"
#include "Sal_impl.h"
#include "sal_def.h"
#include "speech_def.h"



volatile uint16* SAL_PcmEx_GetBuf(Sal_PcmEx_BufId_t id)
{
	return SALI_PcmEx_GetBuf(id);
}
uint16 SAL_PcmEx_GetBufLen(Sal_PcmEx_BufId_t id)
{
	return SALI_PcmEx_GetBufLen(id);
}
volatile uint16* SAL_Sidetone_GetFltCoefAddr()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_SIDETONE);
}
volatile uint16* SAL_BKF_GetFltCoefAddr_NB_UL()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_BKF_NB_UL);
}

volatile uint16* SAL_BKF_GetFltCoefAddr_NB_DL()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_BKF_NB_DL);
}
#if DSP_16K_NR_SUPPORT
uint16* SAL_BKF_GetFltCoefAddr_WB_UL()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_BKF_WB_UL);
}
uint16* SAL_BKF_GetFltCoefAddr_WB_DL()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_BKF_WB_DL);
}
#endif
volatile uint16* SAL_SRC_GetFltCoefAddr()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_SRC);
}
volatile uint16* SAL_AGC_GetFltCoefAddr()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_AGC);
}
void SAL_Dsp_Sph_Init()
{
    SALI_Init();
}
void SAL_3G_Set_RxType(uint16 rx_type)
{
    SALI_3G_Set_RxType(rx_type);
}

void SAL_Set_Sph_Nml_Mod(uint32 on)
{
    SALI_Set_Sph_Nml_Mod(on);
}

void SAL_3G_Upd_Enc_Cod(uint32 enc_mod)
{
    SALI_Upd_3G_Enc_Rate(enc_mod);
}

void SAL_3G_Upd_Dec_Cod(uint32 dec_mod)
{	
    SALI_Upd_3G_Dec_Rate(dec_mod);
}

bool SAL_DSPINT_Resolve(uint16 iid, uint32 *sph_int)
{
    return SALI_Int_Resolve(iid, sph_int);
}

void SAL_PcmEx_Config(Sal_PCMEx_t *cfg)
{
    ASSERT_REBOOT(cfg != 0);
    SALI_PcmEx_Config(cfg);
}

#if defined(MT6261) || defined(MT2501) || defined(MT2502)
void SAL_PcmEx_SetStateUL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta, Sal_PNW_Type_t pnw_type)
{
	SALI_PcmEx_SetState(0, type, sta, pnw_type);
}

void SAL_PcmEx_SetStateDL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta, Sal_PNW_Type_t pnw_type)
{
	SALI_PcmEx_SetState(1, type, sta, pnw_type);
}

bool SAL_PcmEx_CheckStateUL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta, Sal_PNW_Type_t pnw_type)
{
	return SALI_PcmEx_CheckState(0, type, sta, pnw_type);
}

bool SAL_PcmEx_CheckStateDL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta, Sal_PNW_Type_t pnw_type)
{
	return SALI_PcmEx_CheckState(1, type, sta, pnw_type);
}
#else
void SAL_PcmEx_SetStateUL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
	SALI_PcmEx_SetState(0, type, sta);
}

void SAL_PcmEx_SetStateDL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
	SALI_PcmEx_SetState(1, type, sta);
}

bool SAL_PcmEx_CheckStateUL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
	return SALI_PcmEx_CheckState(0, type, sta);
}

bool SAL_PcmEx_CheckStateDL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
	return SALI_PcmEx_CheckState(1, type, sta);
}
#endif

void SAL_ENH_SetULPath(bool on)
{
	SALI_ENH_PathEnable(0, on);
}

void SAL_3G_SetDtx(bool on)
{
	SALI_3G_SetDtx(on);
}

volatile uint16 *SAL_CommonPar_GetBuf(void)
{
	return SALI_Parameter_GetAddr(SALI_PARAMETER_TYPE_COMMON);
}

volatile uint16 *SAL_ModePar_GetBuf(void)
{
	return SALI_Parameter_GetAddr(SALI_PARAMETER_TYPE_MODE);
}
volatile uint16 *SAL_VolPar_GetBuf(void)
{
    return SALI_Parameter_GetAddr(SALI_PARAMETER_TYPE_VOL);
}
void SAL_3G_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 dtx, uint32 delR, uint32 delW, uint32 delM)
{
   SALI_Set_3G(true);
   SALI_Enable_Codec(enc_mod, dec_mod);
   SALI_Upd_3G_Enc_Rate(enc_mod);
   SALI_Upd_3G_Dec_Rate(dec_mod);
   SALI_3G_SetDtx(dtx);
   SALI_Fill_Enc_Silence(SAL_APP_TYPE_3GCall, enc_mod);
   SALI_Set_Sch_Delay(delR, delW, delM, 0);
   SALI_AppSpec_Control(SAL_APP_TYPE_3GCall, 1);
}

void SAL_2G_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 sub_channel)
{
   SALI_Enable_Codec(enc_mod, dec_mod);
   SALI_Fill_Enc_Silence(SAL_APP_TYPE_2GCall, enc_mod);
   SALI_Set_2G_Sch_Delay(enc_mod, sub_channel);	
   SALI_AppSpec_Control(SAL_APP_TYPE_2GCall, 1);
}

void SAL_2G_Call_Close()
{
    SALI_Disable_Codec();
 	SALI_AppSpec_Control(SAL_APP_TYPE_2GCall, 0);
}

void SAL_3G_Call_Close()
{
    SALI_Disable_Codec();
    SALI_3G_Set_RxType(SAL_3G_RX_NO_DATA);
    SALI_Set_3G(false);
	SALI_AppSpec_Control(SAL_APP_TYPE_3GCall, 0);
}


