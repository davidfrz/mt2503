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
 *	Sal_impl.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   SAL  Header
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
#ifndef SAL_IMPL_H
#define SAL_IMPL_H


#include "common_def.h"
#include "sal_def.h"



volatile uint16* SALI_PcmEx_GetBuf(Sal_PcmEx_BufId_t id);
uint16 SALI_PcmEx_GetBufLen(Sal_PcmEx_BufId_t id);
volatile uint16* SALI_GetFltCoefAddr(uint8 type);
void SALI_Init();
void SALI_3G_Set_RxType(uint16 rx_type);
void SALI_Set_Sph_Nml_Mod(bool on);
void SALI_Upd_3G_Enc_Rate(uint16 enc_mod);
void SALI_Upd_3G_Dec_Rate(uint16 dec_mod);
bool SALI_Int_Resolve(uint16 iid, uint32 *sph_int);
void SALI_PcmEx_Config(Sal_PCMEx_t *cfg);
void SALI_Set_Sch_Delay(uint16 delR, uint16 delW, uint16 delM, uint16 delO);
void SALI_Config_SRC(kal_bool is_WB);
#if defined(MT6261) || defined(MT2501) || defined(MT2502) 
void SALI_PcmEx_SetState(uint8 is_DL, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta, Sal_PNW_Type_t pnw_type);
bool SALI_PcmEx_CheckState(uint8 is_DL, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta, Sal_PNW_Type_t pnw_type);
#else
void SALI_PcmEx_SetState(uint8 is_DL, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta);
bool SALI_PcmEx_CheckState(uint8 is_DL, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta);
#endif
void SALI_ENH_PathEnable(uint8 is_DL, bool on);
void SALI_3G_SetDtx(bool on);
volatile uint16 *SALI_Parameter_GetAddr(uint8 type);
void SALI_Set_3G(bool on);
void SALI_Enable_Codec(uint16 enc_mod, uint16 dec_mod);
void SALI_Fill_Enc_Silence(uint8 app_type, uint16 codec);
void SALI_AppSpec_Control(uint8 app_type, uint8 on);
void SALI_Set_2G_Sch_Delay(uint8 codec_mod, uint8 subchannel);
void SALI_Disable_Codec();





//void _AFE_SetAudioFlag(void);


#endif //AFE_H
