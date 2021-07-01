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
 *	Sal_def.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   SAL  define 
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   
 * $Modtime:   
 * $Log:   
 *
 
 *******************************************************************************/
#ifndef SAL_DEF_H
#define SAL_DEF_H


#include "common_def.h"


typedef enum{
	SAL_PCMEX_PNW_BUF_UL1 = 0,//D2M
	SAL_PCMEX_PNW_BUF_UL2,//M2D
	SAL_PCMEX_PNW_BUF_DL1,//D2M
	SAL_PCMEX_PNW_BUF_DL2,//M2D
	SAL_PCMEX_DACA_BUF_UL,
	SAL_PCMEX_DACA_BUF_DL,
	SAL_PCMEX_BUF_SE,
	SAL_PCMEX_BUF_SE2,//mic2
	SAL_PCMEX_BUF_SD,
	SAL_PCMEX_BUF_IDLE_SE,
    SAL_PCMEX_AUX_P2W_BUF_DL,
    SAL_PCMEX_AUX_P2W_BUF_UL
}Sal_PcmEx_BufId_t;

#define SALI_FLTCOEF_TYPE_SIDETONE  0
#define SALI_FLTCOEF_TYPE_BKF_NB_UL 1
#define SALI_FLTCOEF_TYPE_BKF_NB_DL 2
#define SALI_FLTCOEF_TYPE_BKF_WB_UL 3
#define SALI_FLTCOEF_TYPE_BKF_WB_DL 4
#define SALI_FLTCOEF_TYPE_SRC       5
#define SALI_FLTCOEF_TYPE_AGC       6
#define SALI_FLTCOEF_TYPE_DMNR_NB   7
#define SALI_FLTCOEF_TYPE_DMNR_WB   8
#define SAL_3G_RX_SPEECH_GOOD  0
#define SAL_3G_RX_SPEECH_BAD   4
#define SAL_3G_RX_SID_FIRST    6
#define SAL_3G_RX_SID_UPDATE   8
#define SAL_3G_RX_SID_BAD      10
#define SAL_3G_RX_NO_DATA      14

#define SAL_FLTCOEFLEN_SIDETONE  31
#define SAL_FLTCOEFLEN_BKF_NB 	45
#define SAL_FLTCOEFLEN_BKF_WB 	90
#define SAL_FLTCOEFLEN_SRC 		82
#define SAL_FLTCOEFLEN_AGC 		40


#define SAL_DSPINT_PRIO_REC_EPL  1   //uplink
#define SAL_DSPINT_PRIO_REC_PCM  2   //uplink
#define SAL_DSPINT_PRIO_REC_VM   3   //downlink
#define SAL_DSPINT_PRIO_3G_DL    4
#define SAL_DSPINT_PRIO_3G_UL    5
#define SAL_DSPINT_PRIO_PNW_DL   6
#define SAL_DSPINT_PRIO_PNW_UL   7
#define SAL_DSPINT_PRIO_DACA_DL  8
#define SAL_DSPINT_PRIO_DACA_UL  9
#define SAL_DSPINT_PRIO_BGS_DL   10  //downlink, ping pong
#define SAL_DSPINT_PRIO_BGS_UL   11
#define SAL_DSPINT_PRIO_AVBT     12
#define SAL_DSPINT_PRIO_P2W_ENH_DL 13
#define SAL_DSPINT_PRIO_P2W_ENH_UL 14
#define SAL_DSPINT_PRIO_MAX      15


#define SAL_DSPINT_ID_REC_EPL    (1 << SAL_DSPINT_PRIO_REC_EPL)
#define SAL_DSPINT_ID_REC_PCM    (1 << SAL_DSPINT_PRIO_REC_PCM)
#define SAL_DSPINT_ID_REC_VM     (1 << SAL_DSPINT_PRIO_REC_VM)
#define SAL_DSPINT_ID_3G_DL      (1 << SAL_DSPINT_PRIO_3G_DL)
#define SAL_DSPINT_ID_3G_UL      (1 << SAL_DSPINT_PRIO_3G_UL)
#define SAL_DSPINT_ID_PNW_DL     (1 << SAL_DSPINT_PRIO_PNW_DL)
#define SAL_DSPINT_ID_PNW_UL     (1 << SAL_DSPINT_PRIO_PNW_UL)
#define SAL_DSPINT_ID_DACA_DL    (1 << SAL_DSPINT_PRIO_DACA_DL)
#define SAL_DSPINT_ID_DACA_UL    (1 << SAL_DSPINT_PRIO_DACA_UL)
#define SAL_DSPINT_ID_BGS_DL     (1 << SAL_DSPINT_PRIO_BGS_DL)
#define SAL_DSPINT_ID_BGS_UL     (1 << SAL_DSPINT_PRIO_BGS_UL)
#define SAL_DSPINT_ID_AVBT       (1 << SAL_DSPINT_PRIO_AVBT)
#define SAL_DSPINT_ID_P2W_ENH_DL (1 << SAL_DSPINT_PRIO_P2W_ENH_DL)
#define SAL_DSPINT_ID_P2W_ENH_UL (1 << SAL_DSPINT_PRIO_P2W_ENH_UL)

#define SALI_PARAMETER_TYPE_COMMON 0
#define SALI_PARAMETER_TYPE_MODE   1
#define SALI_PARAMETER_TYPE_VOL    2

#define SAL_APP_TYPE_2GCall 0
#define SAL_APP_TYPE_3GCall 1

static struct
{
    uint8   device;
    uint8   enc_mod;
    uint8   dec_mod;
    uint8   sub_channel;
    uint8   dtx;
    bool    fwe;
} sal_impl;

#if defined(MT6261) || defined(MT2501) || defined(MT2502)
typedef enum {
    SAL_PCMEX_TYPE_P2W = 0,
    SAL_PCMEX_TYPE_P4W
} Sal_PNW_Type_t;
#endif

typedef enum {
    SAL_PCMEX_TYPE_PNW = 0,
    SAL_PCMEX_TYPE_DACA,
    SAL_PCMEX_TYPE_REC_NML,
    SAL_PCMEX_TYPE_REC_EPL
} Sal_PcmEx_Type_t;

typedef enum {
    SAL_PCMEX_OFF = 0,
    SAL_PCMEX_ON,
    SAL_PCMEX_RDY
} Sal_PcmEx_State_t;


typedef enum {
    SAL_PCM_NARROWBAND = 0,
    SAL_PCM_WIDEBAND,
    SAL_PCM_UNDEFINED
} Sal_PcmBand_Config_t;


typedef struct {
	bool idle;
	bool swi_on;
	
	uint16 delR;
	uint16 delW;
	uint16 delM;

	Sal_PcmEx_Type_t type;
	Sal_PcmBand_Config_t band;   // Effective only if idle is true

	// For PNW
	bool UL_M2D_on;
	bool UL_D2M_on;
	bool UL_is_after_enh;
	bool DL_M2D_on;
	bool DL_D2M_on;
	bool DL_is_after_enh;
} Sal_PCMEx_t;

#endif //AFE_H
