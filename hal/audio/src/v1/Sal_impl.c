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
 * Sal_impl.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   DSP Setting control for Sal_exp
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

#include "sal_impl.h"
#include "sal_def.h"
#include "am.h"
#include "l1d_data.h"

#include "speech_def.h"
#include "l1audio_trace.h"

#include "ddload.h"


/* To work around the bug of DSP when handover in short time,
   Do not set handover flag to DSP, but VBI_Reset and other setting remain */

#define  SALI_VBI_Reset()          { *SHARE2_M2DI1 = 0x0838; \
                                L1Audio_Msg_VBI_RESET(); }
#define  SALI_VBI_End()            { *SHARE2_M2DI1 = 0x0839; \
                                L1Audio_Msg_VBI_END(); }

static const uint16 CodecSilencePattern[][17] = {
   {  0x4820,0xD617,0x0284,0x2480,0x9249,0x8924,0x8002,0x4924,          
      0x2492,0x0289,0x2480,0x9249,0x8924,0x8002,0x4924,0x2492,                          
      0x0009                                                   },       /* FR           */                
   {  0x4E20,0x875E,0x5473,0x8482,0x00E9,0x0000,0x0000         },       /* HR           */
   {  0x7A10,0x092D,0xB55F,0x7C06,0x185C,0xDE06,0x4230,0x0103,          
      0xA012,0x001A,0x0000,0x0000,0x0D6C,0x0000,0x0000,0x0000  },       /* EFR          */                
   {  0x00e2,0x5dfc,0xf095,0xcd4e,0x24da,0x0e04,0xf0fb,0x4f2e,          
      0x4430,0x9fa8,0x0319,0x56c0,0xc144,0x0278,0x70ea,0x0004  },       /* AMR12.2      */                
   {  0xe00a,0xf2e7,0x516b,0x19a1,0xc10d,0x145a,0x4c96,0x25e0,          
      0x5ce6,0x17b9,0x0982,0x225d,0x00c4                       },       /* AMR10.2      */                
   {  0x033c,0xe5cd,0xd9fb,0x387f,0x420c,0x8c99,0x58d7,0x1156,          
      0x397f,0x1074                                            },       /* AMR7.95      */                
   {  0xe00a,0xf2e7,0x9ac5,0x4433,0x185b,0x3e05,0xdc64,0xc886,          
      0xcd2e,0x0000                                            },       /* AMR7.4       */                
   {  0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,          
      0x0002                                                   },       /* AMR6.7       */                
   {  0xe00a,0xf2e7,0xb196,0xa8ae,0xbcb7,0x6fb9,0x0193,0x002e  },       /* AMR5.9       */
   {  0x3c0a,0x7e51,0x652c,0x5e91,0xd023,0xea5a,0x005b         },       /* AMR5.15      */
   {  0x3c0a,0x3e51,0x6529,0x3a49,0x977f,0x3565                },       /* AMR4.75      */
   {0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,0x0002},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000}     /* AMR-WB 6.60  */
};

static const uint8 CodecPatternLength[] = {
   (uint8)((260 + 15) / 16),           /*  FR       */
   (uint8)((112 + 15) / 16 + 1),       /*  HR       */
   (uint8)((244 + 15) / 16),           /* EFR       */
   (uint8)((244 + 15) / 16),           /* AMR 12.2K */
   (uint8)((204 + 15) / 16),           /* AMR 10.2K */
   (uint8)((159 + 15) / 16),           /* AMR 7.95K */
   (uint8)((148 + 15) / 16),           /* AMR 7.4K  */
   (uint8)((134 + 15) / 16),           /* AMR 6.7K  */
   (uint8)((118 + 15) / 16),           /* AMR 5.9K  */
   (uint8)((103 + 15) / 16),           /* AMR 5.15K */
   (uint8)(( 95 + 15) / 16),           /* AMR 4.75K */
   (uint8)((132 + 15) / 16),           /* AMR-WB 6.60  */
   (uint8)((177 + 15) / 16),           /* AMR-WB 8.85  */
   (uint8)((253 + 15) / 16),           /* AMR-WB 12.65 */
   (uint8)((285 + 15) / 16),           /* AMR-WB 14.25 */
   (uint8)((317 + 15) / 16),           /* AMR-WB 15.85 */
   (uint8)((365 + 15) / 16),           /* AMR-WB 18.25 */
   (uint8)((397 + 15) / 16),           /* AMR-WB 19.85 */
   (uint8)((461 + 15) / 16),           /* AMR-WB 23.05 */
   (uint8)((477 + 15) / 16),           /* AMR-WB 23.85 */
};
const uint16 DSP_2GSCH_MARGIN_TABLE[] = {
   0x38+(16<<10)+(2<<8),     /* 1.2 : FR        */
   0x38+(12<<10)+(2<<8),     /* 1.2 : HR        */
   0x38+(16<<10)+(2<<8),     /* 1.2 : EFR       */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 12.2  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 10.2  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 7.95  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 7.4   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 6.7   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 5.9   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 5.15  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 4.75  */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 6.60     */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 8.85     */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 12.65    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 14.25    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 15.85    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 18.25    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 19.85    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 23.05    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 23.85    */
};

const uint16 DSP_2GSCH_DELAY_TABLE_SUBCH0[13][2] =
{    /*  SE      SD  */                    /*   SE  SD   */
   { (0x00B5), 0x0139 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
   { (0x0090), 0x01B4 },  /* T2 = 1 /14 */ /*  3.9 11.8  */
   { (0x006B), 0x018F },  /* T2 = 2 /15 */ /*  2.9 10.8  */
   { (0x0046), 0x016A },  /* T2 = 3 /16 */ /*  1.9  9.8  */
   { (0x00C1), 0x0145 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
   { (0x009C), 0x01C0 },  /* T2 = 5 /18 */ /*  4.2 12.1  */
   { (0x0077), 0x019B },  /* T2 = 6 /19 */ /*  3.2 11.1  */
   { (0x0052), 0x0176 },  /* T2 = 7 /20 */ /*  2.2 10.1  */
   { (0x002D), 0x0151 },  /* T2 = 8 /21 */ /*  1.2 13.5  */
   { (0x00A8), 0x01CC },  /* T2 = 9 /22 */ /*  4.5 12.5  */
   { (0x0083), 0x01A8 },  /* T2 = 10/23 */ /*  3.5 11.5  */
   { (0x005E), 0x0183 },  /* T2 = 11/24 */ /*  2.5 10.5  */
   { (0x0039), 0x015E }   /* T2 = 12/25 */ /*  1.5 13.8  */
};

const uint16 DSP_2GSCH_DELAY_TABLE_SUBCH1[13][2] =
{      /*  SE      SD  */                       /*   SE  SD   */
   { (0x00B5)+0x25, 0x0139 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
   { (0x0090)+0x25, 0x01B4 },  /* T2 = 1 /14 */ /*  3.9 11.8  */
   { (0x006B)+0x25, 0x018F },  /* T2 = 2 /15 */ /*  2.9 10.8  */
   { (0x0046)+0x25, 0x016A },  /* T2 = 3 /16 */ /*  1.9  9.8  */
   { (0x00C1)+0x25, 0x0145 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
   { (0x009C)+0x25, 0x01C0 },  /* T2 = 5 /18 */ /*  4.2 12.1  */
   { (0x0077)+0x25, 0x019B },  /* T2 = 6 /19 */ /*  3.2 11.1  */
   { (0x0052)+0x25, 0x0176 },  /* T2 = 7 /20 */ /*  2.2 10.1  */
   { (0x002D)+0x25, 0x0151 },  /* T2 = 8 /21 */ /*  1.2 13.5  */
   { (0x00A8)+0x25, 0x01CC },  /* T2 = 9 /22 */ /*  4.5 12.5  */
   { (0x0083)+0x25, 0x01A8 },  /* T2 = 10/23 */ /*  3.5 11.5  */
   { (0x005E)+0x25, 0x0183 },  /* T2 = 11/24 */ /*  2.5 10.5  */
   { (0x0039)+0x25, 0x015E }   /* T2 = 12/25 */ /*  1.5 13.8  */
};

volatile uint16* SALI_PcmEx_GetBuf(Sal_PcmEx_BufId_t id)
{
	
	volatile uint16 *addr = 0;

	switch(id){
		
		case SAL_PCMEX_PNW_BUF_UL1:
			addr = DSP_SPH_PNW_BUF_UL1;
			break;
		case SAL_PCMEX_PNW_BUF_UL2:
			addr = DSP_SPH_PNW_BUF_UL2;
			break;
		case SAL_PCMEX_PNW_BUF_DL1:
			addr = DSP_SPH_PNW_BUF_DL1;
			break;		
		case SAL_PCMEX_PNW_BUF_DL2:
			addr = DSP_SPH_PNW_BUF_DL2;
			break;
		case SAL_PCMEX_DACA_BUF_UL:
			addr = DSP_SPH_DACA_UL_BUF;
			break;
		case SAL_PCMEX_DACA_BUF_DL:
			addr = DSP_SPH_DACA_DL_BUF;
			break;
		case SAL_PCMEX_BUF_SE:
			addr = DSP_DM_ADDR(5, *DSP_SPH_SE_BUF_PTR);
			break;
		case SAL_PCMEX_BUF_SD:
			addr = DSP_DM_ADDR(5, *DSP_SPH_SD_BUF_PTR);
			break;	
        case SAL_PCMEX_AUX_P2W_BUF_DL:
            addr = DSP_SPH_AUX_P2W_BUF_DL;
            break;
        case SAL_PCMEX_AUX_P2W_BUF_UL:
            addr = DSP_SPH_AUX_P2W_BUF_UL;
            break;
        case SAL_PCMEX_BUF_SE2:  // Not supported in MT6260
		default:
			ASSERT(0);
			break;
	}

	return DSP_DM_ADDR(5, *addr);
}
uint16 SALI_PcmEx_GetBufLen(Sal_PcmEx_BufId_t id)
{
    uint16 len = 0;

	switch(id)
	{
		case SAL_PCMEX_PNW_BUF_UL1:
		case SAL_PCMEX_PNW_BUF_UL2:
			len = *DSP_SPH_PNW_LEN_UL;
			break;
		case SAL_PCMEX_PNW_BUF_DL1:
		case SAL_PCMEX_PNW_BUF_DL2:
			len = *DSP_SPH_PNW_LEN_DL;
			break;
		case SAL_PCMEX_BUF_SE:
			len = *DSP_SPH_BAND_FLAG & 0x4 ? 320 : 160; // bit2 --> codec band, bit1 --> sch DL band, bit0 --> sch UL band
			break;
		case SAL_PCMEX_BUF_SD:
			len = *DSP_SPH_BAND_FLAG & 0x2 ? 320 : 160; // bit2 --> codec band, bit1 --> sch DL band, bit0 --> sch UL band
			break;
		case SAL_PCMEX_DACA_BUF_UL:
		    len = *DSP_SPH_DACA_LEN_UL;
		    break;
		case SAL_PCMEX_DACA_BUF_DL:
			len = *DSP_SPH_DACA_LEN_DL;
			break;
        case SAL_PCMEX_BUF_IDLE_SE:
            len = *DSP_SPH_BAND_FLAG & 0x1 ? 320 : 160; // bit2 --> codec band, bit1 --> sch DL band, bit0 --> sch UL band
            break;
        case SAL_PCMEX_BUF_SE2:  // MT6260 does not support dual microphone
		default:
			ASSERT(0);
			break;
	}

	return len;
}


volatile uint16* SALI_GetFltCoefAddr(uint8 type)
{
	volatile uint16 *addr = 0;
	
	switch(type)
	{
		case SALI_FLTCOEF_TYPE_SIDETONE:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_ST);
			break;
		case SALI_FLTCOEF_TYPE_BKF_NB_UL:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_BKF_NB_UL);
			break;
		case SALI_FLTCOEF_TYPE_BKF_NB_DL:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_BKF_NB_DL);
			break;
		case SALI_FLTCOEF_TYPE_SRC:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_SRC);
			break;	
		case SALI_FLTCOEF_TYPE_AGC:
			addr = DSP_PM_ADDR(3, FLTCOEF_TYPE_AGC_ADDR);
			break;	
		case SALI_FLTCOEF_TYPE_DMNR_NB:      // MT6260 does not support dual microphone
		case SALI_FLTCOEF_TYPE_DMNR_WB:      // MT6260 does not support dual microphone
#if DSP_16K_NR_SUPPORT		
        case SALI_FLTCOEF_TYPE_BKF_WB_UL:    
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_BKF_WB_UL);
			break;
		case SALI_FLTCOEF_TYPE_BKF_WB_DL:   
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_BKF_WB_DL);
			break;
#endif
		default:
            ASSERT_REBOOT(0);
	}

	return addr;
}

void SALI_Init()
{
	*DSP_SPH_HR_FR_CTRL = 0x0E;
	*DSP_SPH_SCH_IMPROVE_CTRL = 0x0405;
    
    sal_impl.device = 0;
    sal_impl.enc_mod = 0;
    sal_impl.dec_mod = 0;
    sal_impl.sub_channel = 0;
    
    sal_impl.fwe = false;
}

void SALI_3G_Set_RxType(uint16 rx_type)
{
	*DSP_SPH_3G_SD_DATA_HDR = rx_type & 0xE;
}

void SALI_Set_Sph_Nml_Mod(bool on)
{
    if (on)
    {
        *DSP_SPH_8K_CTRL |= 0x8000;
    }
	else
    {
        *DSP_SPH_8K_CTRL &= ~0x8000;
    }
}

void SALI_Upd_3G_Enc_Rate(uint16 enc_mod)
{
	*DSP_SPH_3G_SE_RATE = enc_mod;
}

void SALI_Upd_3G_Dec_Rate(uint16 dec_mod)
{
	*DSP_SPH_3G_SD_RATE = dec_mod;
}

bool SALI_Int_Resolve(uint16 iid, uint32 *sph_int)
{
    uint32 val = 0;
    uint16 mask = 0;
    volatile uint16 *ptr = 0;
    bool from_sph = true;

    switch (iid)
    {
        case DSP_IID_SPEECH_UL_ID:
            mask = *DSP_SPH_D2C_UL_INT;
            if (mask & 0x0001)
            {
                val += SAL_DSPINT_ID_REC_PCM;
            }
            if (mask & 0x0002)
            {
                val += SAL_DSPINT_ID_REC_EPL;
            }
            if (mask & 0x0004)
            {
                val += SAL_DSPINT_ID_PNW_UL;
            }
		    if (mask & 0x0008)
            {
                val += SAL_DSPINT_ID_DACA_UL;
            }
		    if (mask & 0x0010)
            {
                val += SAL_DSPINT_ID_3G_UL;
            }
            if (mask & 0x0020)
            {
                val += SAL_DSPINT_ID_BGS_UL;
            }
            if (mask & 0x0100)
            {
                val += SAL_DSPINT_ID_P2W_ENH_UL;
            }
            *DSP_SPH_D2C_UL_INT = 0;
            break;
        case DSP_IID_SPEECH_DL_ID:
            mask = *DSP_SPH_D2C_DL_INT;
            if (mask & 0x0001)
            {
                val += SAL_DSPINT_ID_REC_VM;
            }
		    if (mask & 0x0004)
            {
                val += SAL_DSPINT_ID_PNW_DL;
            }
		    if (mask & 0x0008)
            {
                val += SAL_DSPINT_ID_DACA_DL;
            }
		    if (mask & 0x0010)
            {
                val += SAL_DSPINT_ID_3G_DL;
            }
		    if (mask & 0x0020)
            {
                val += SAL_DSPINT_ID_BGS_DL;
            }
		    if (mask & 0x0040)
            {
                val += SAL_DSPINT_ID_AVBT;
            }
            if (mask & 0x0100)
            {
                val += SAL_DSPINT_ID_P2W_ENH_DL;
            }
            *DSP_SPH_D2C_DL_INT = 0;
            break;
        default:
            from_sph = false;
            break;
    }
    
    *sph_int = val;
    return from_sph;
}

void SALI_PcmEx_Config(Sal_PCMEx_t *cfg)
{
    switch (cfg->type)
    {
        case SAL_PCMEX_TYPE_PNW:
            {
                kal_uint16 ctrl_UL = *DSP_SPH_PNW_CTRL_UL;
                kal_uint16 ctrl_DL = *DSP_SPH_PNW_CTRL_DL;
                
                ctrl_UL = cfg->UL_M2D_on       ? ctrl_UL | (0x0001 << 11) : ctrl_UL & ~(0x0001 << 11);
                ctrl_UL = cfg->UL_D2M_on       ? ctrl_UL | (0x0001 << 10) : ctrl_UL & ~(0x0001 << 10);
                ctrl_UL = cfg->UL_is_after_enh ? ctrl_UL | (0x0001 <<  9) : ctrl_UL & ~(0x0001 <<  9);
                ctrl_DL = cfg->DL_M2D_on       ? ctrl_DL | (0x0001 << 11) : ctrl_DL & ~(0x0001 << 11);
                ctrl_DL = cfg->DL_D2M_on       ? ctrl_DL | (0x0001 << 10) : ctrl_DL & ~(0x0001 << 10);
                ctrl_DL = cfg->DL_is_after_enh ? ctrl_DL | (0x0001 <<  9) : ctrl_DL & ~(0x0001 <<  9);
                
                *DSP_SPH_PNW_CTRL_UL = ctrl_UL;
                *DSP_SPH_PNW_CTRL_DL = ctrl_DL;
            }
            break;
        case SAL_PCMEX_TYPE_DACA:
            {
                if (cfg->band == SAL_PCM_NARROWBAND)
                {
                    *DSP_SPH_DACA_CTRL |=  0x0100;
                }
	        	else
                {
                    *DSP_SPH_DACA_CTRL &= ~0x0100;
                }
            }
            break;
        default:
            ASSERT_REBOOT(0);
            break;
    }
    		
	// An idle PNA, DACA or recording application
	if (cfg->idle)
    {
        if (cfg->swi_on)
        {
            AM_DSP_SetSRCCtrl(sp_getSpeFlag());
            SALI_Config_SRC((kal_bool)(cfg->band == SAL_PCM_WIDEBAND));
            SALI_Set_Sch_Delay(cfg->delR, cfg->delW, cfg->delM, 0);
            SALI_VBI_Reset();
        }
        else
        {
            SALI_VBI_End();
        }
	}
}

void SALI_Config_SRC(kal_bool is_WB)
{
    if (is_WB)
    {
        *DSP_SPH_8K_CTRL |= 0x8;
    }
    else
    {
        *DSP_SPH_8K_CTRL &= ~0x8;
    }
    
    return;
}


void SALI_Set_Sch_Delay(uint16 delR, uint16 delW, uint16 delM, uint16 delO)
{
    *DSP_SPH_DEL_R = delR;
    *DSP_SPH_DEL_W = delW;
    *DSP_SPH_DEL_M = delM;
    *DSP_SPH_DEL_O = delO;
}
#if defined(MT6261) || defined(MT2501) || defined(MT2502)
void SALI_PcmEx_SetState(uint8 is_DL, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta, Sal_PNW_Type_t pnw_type)
{
    ASSERT_REBOOT(sta == SAL_PCMEX_ON || sta == SAL_PCMEX_OFF);
    ASSERT(type == SAL_PCMEX_TYPE_PNW || type == SAL_PCMEX_TYPE_DACA);
    ASSERT( SAL_PCMEX_TYPE_P2W == pnw_type || SAL_PCMEX_TYPE_P4W == pnw_type);
    
    if (type == SAL_PCMEX_TYPE_PNW)
    {
      if( SAL_PCMEX_TYPE_P2W == pnw_type ){
         volatile uint16 *addr = DSP_SPH_AUX_P2W_CTRL;
         
         if(is_DL){              
            if (sta == SAL_PCMEX_ON){
               *addr = (*addr & 0xff0f) | 0x0010;
            }else{
               *addr = (*addr & 0xff0f) ;
            } 
         }else{
            if (sta == SAL_PCMEX_ON){
               *addr = (*addr & 0xfff0) | 0x0001;
            }else{
               *addr = (*addr & 0xfff0) ;
            }   
         }      
      }else{
         volatile uint16 *addr = is_DL ? DSP_SPH_PNW_CTRL_DL : DSP_SPH_PNW_CTRL_UL;
           
   		if (sta == SAL_PCMEX_ON){
            *addr = (*addr & 0xfff0) | 0x0101;
         }else{
            *addr = (*addr & 0xfef0);
   		} 
	   }
	}
	else
    {
        volatile uint16 *addr = DSP_SPH_DACA_CTRL;
        
        if (is_DL)
        {
			if (sta == SAL_PCMEX_ON)
            {
                *addr = (*addr & 0xff0f) + 0x0010;
            }
			else
            {
                *addr = (*addr & 0xff0f);
            }
		}
		else
        {
			if (sta == SAL_PCMEX_ON)
            {
                *addr = (*addr & 0xfff0) + 0x0001;
            }
			else
            {
                *addr = (*addr & 0xfff0);
            }
		}
	}
    
    return;
}
#else
void SALI_PcmEx_SetState(uint8 is_DL, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
    ASSERT_REBOOT(sta == SAL_PCMEX_ON || sta == SAL_PCMEX_OFF);
    ASSERT(type == SAL_PCMEX_TYPE_PNW || type == SAL_PCMEX_TYPE_DACA);
    
    if (type == SAL_PCMEX_TYPE_PNW)
    {
        volatile uint16 *addr = is_DL ? DSP_SPH_PNW_CTRL_DL : DSP_SPH_PNW_CTRL_UL;
        
		if (sta == SAL_PCMEX_ON)
        {
            *addr = (*addr & 0xfff0) | 0x0101;
        }
        else 
        {
            *addr = (*addr & 0xfef0);
		}
	}
	else
    {
        volatile uint16 *addr = DSP_SPH_DACA_CTRL;
        
        if (is_DL)
        {
			if (sta == SAL_PCMEX_ON)
            {
                *addr = (*addr & 0xff0f) + 0x0010;
            }
			else
            {
                *addr = (*addr & 0xff0f);
            }
		}
		else
        {
			if (sta == SAL_PCMEX_ON)
            {
                *addr = (*addr & 0xfff0) + 0x0001;
            }
			else
            {
                *addr = (*addr & 0xfff0);
            }
		}
	}
    
    return;
}
#endif

#if defined(MT6261) || defined(MT2501) || defined(MT2502)
bool SALI_PcmEx_CheckState(uint8 is_DL, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta, Sal_PNW_Type_t pnw_type)
{
    bool ret = false;
    
    ASSERT(type == SAL_PCMEX_TYPE_PNW || type == SAL_PCMEX_TYPE_DACA);
    
    if (type == SAL_PCMEX_TYPE_PNW)
    {
        if( SAL_PCMEX_TYPE_P2W == pnw_type ){            
           if(is_DL){
              ret = (((*DSP_SPH_AUX_P2W_CTRL & 0xf0)>>4) == sta);
           }else{
              ret = ((*DSP_SPH_AUX_P2W_CTRL & 0xf) == sta);            
           }     
        }else{      
           if (is_DL)
           {
               ret = ((*DSP_SPH_PNW_CTRL_DL & 0xf) == sta);
           }
           else
           {
               ret = ((*DSP_SPH_PNW_CTRL_UL & 0xf) == sta);
           }
        }
	}
	else
    {
        if (is_DL)
        {
            ret = ((*DSP_SPH_DACA_CTRL >> 4 & 0xf) == sta);
        }
        else
        {
            ret = ((*DSP_SPH_DACA_CTRL      & 0xf) == sta);
        }
	}

	return ret;
}
#else
bool SALI_PcmEx_CheckState(uint8 is_DL, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
    bool ret = false;
    
    ASSERT(type == SAL_PCMEX_TYPE_PNW || type == SAL_PCMEX_TYPE_DACA);
    
    if (type == SAL_PCMEX_TYPE_PNW)
    {
        if (is_DL)
        {
            ret = ((*DSP_SPH_PNW_CTRL_DL & 0xf) == sta);
        }
        else
        {
            ret = ((*DSP_SPH_PNW_CTRL_UL & 0xf) == sta);
        }
	}
	else
    {
        if (is_DL)
        {
            ret = ((*DSP_SPH_DACA_CTRL >> 4 & 0xf) == sta);
        }
        else
        {
            ret = ((*DSP_SPH_DACA_CTRL      & 0xf) == sta);
        }
	}

	return ret;
}
#endif
void SALI_ENH_PathEnable(uint8 is_DL, bool on)
{
    *DSP_SPH_UL_COMFORT_NOISE_THRESHOLD = 32;
	*DSP_SPH_UL_COMFORT_NOISE_SHIFT     = (uint16)-12;
    
    if (is_DL)
	{
		if(on)
        {
            *DSP_SPH_ENH_DL_CTRL |=  0x0004;
        }
		else
        {
            *DSP_SPH_ENH_DL_CTRL &= ~0x0004;
        }
	}
	else
    {
        if (on)
        {
            *DSP_SPH_ENH_UL_CTRL |=  0x0002;
        }
		else
        {
            *DSP_SPH_ENH_UL_CTRL &= ~0x0002;
        }
	}
}
void SALI_3G_SetDtx(bool on)
{
    sal_impl.dtx = on;
    
    if (on)
    {
        *DSP_SPH_COD_CTRL |= 0x4;
    }
	else
    {
        *DSP_SPH_COD_CTRL &= ~0x4;
    }
}

volatile uint16 *SALI_Parameter_GetAddr(uint8 type)
{
    volatile uint16 *addr = 0;
    
    switch (type)
    {
        case SALI_PARAMETER_TYPE_COMMON:
            addr = DSP_DM_ADDR(SPH_EMP_PAGE, *DSP_SPH_EMP_ADDR);
            break;
        case SALI_PARAMETER_TYPE_MODE:
            addr = DSP_DM_ADDR(SPH_EMP_PAGE, (*DSP_SPH_EMP_ADDR + 12));
            break;
        case SALI_PARAMETER_TYPE_VOL:
            addr = DSP_DM_ADDR(SPH_EMP_PAGE, (*DSP_SPH_EMP_ADDR + 8));
            break;
        default:
            ASSERT_REBOOT(false);
            break;
	}
    
    return addr;
}
void SALI_Set_3G(bool on)
{
    *DSP_SPH_3G_CTRL = on ? 1 : 0;
}

void SALI_Enable_Codec(uint16 enc_mod, uint16 dec_mod)
{
    sal_impl.enc_mod = enc_mod;
    sal_impl.dec_mod = dec_mod;
    
    *DSP_SPH_COD_MODE = dec_mod | (enc_mod << 8);               
    *DSP_SPH_COD_VAD = enc_mod > 2 ? 1 : 0;
    *DSP_SPH_COD_CTRL |= 0x33;
}

void SALI_Fill_Enc_Silence(uint8 app_type, uint16 codec)
{
    volatile uint16 *addr = 0;
    
    if (app_type == SAL_APP_TYPE_2GCall)
    {
        addr = DSP_SPH_2G_SE_DATA_HDR;
    }
	else if (app_type == SAL_APP_TYPE_3GCall)
    {
        addr = DSP_SPH_3G_SE_DATA_HDR;
    }
	else
    {
        ASSERT(0);
    }
    
    if (codec >= 0x20)
    {
        codec = codec - 0x20 + 0x0B;
    }
    
    if (codec >= (sizeof(CodecPatternLength)/sizeof(CodecPatternLength[0])))
    {
        return;
    }
    
    {
        const uint16 *pat_info = CodecSilencePattern[codec];
        uint32 len = (uint16)CodecPatternLength[codec];
        uint32 I;

        *addr++ = 2;
        for (I = 0; I < len; I++)
        {
            *addr++ = *pat_info++;
        }
    }
}

void SALI_AppSpec_Control(uint8 app_type, uint8 on)
{
	switch(app_type)
	{
		case SAL_APP_TYPE_2GCall:
		    if (on)
            {
                DSP_SPH_APP_MODE = SPH_APP_MODE_CALL_2G;
                *DSP_SPH_SCH_IMPROVE_CTRL &= ~0x4000; //Enable DSH_2G_UL_CRC
            }
            else
            {
                DSP_SPH_APP_MODE = SPH_APP_MODE_NONE;
                *DSP_SPH_SCH_IMPROVE_CTRL |=  0x4000;
            }
            break;
		case SAL_APP_TYPE_3GCall:
			if (on)
            {
                DSP_SPH_APP_MODE = SPH_APP_MODE_CALL_3G;
	   		    *DSP_SPH_SCH_IMPROVE_CTRL &= ~0x4000; //Enable DSH_2G_UL_CRC
			}
			else
            {
                DSP_SPH_APP_MODE = SPH_APP_MODE_NONE;
		   	    *DSP_SPH_SCH_IMPROVE_CTRL |=  0x4000; 
			}
			break;
	}
}

void SALI_Set_2G_Sch_Delay(uint8 codec_mod, uint8 subchannel)
{
    uint16 n = (uint16)L1D_GetT2();
	uint16 delay = L1D_Get_Win_TQ_WRAP() - TQ_WRAP_COUNT;

	sal_impl.sub_channel = subchannel;

    if (n >= 13)
    {
        n -= 13;
    }

    if (codec_mod >= 0x20)
    {
        codec_mod -= 0x20 - 0x0B;
    }
    
    ASSERT(codec_mod < (sizeof(DSP_2GSCH_MARGIN_TABLE)/sizeof(DSP_2GSCH_MARGIN_TABLE[0])));
    
    if (subchannel == 0)
    {
        *DSP_SPH_DEL_R = DSP_2GSCH_DELAY_TABLE_SUBCH0[n][0];
        *DSP_SPH_DEL_W = DSP_2GSCH_DELAY_TABLE_SUBCH0[n][1];
    }
    else
    {
        *DSP_SPH_DEL_R = DSP_2GSCH_DELAY_TABLE_SUBCH1[n][0];
        *DSP_SPH_DEL_W = DSP_2GSCH_DELAY_TABLE_SUBCH1[n][1];
        n += 13;
    }
    
    *DSP_SPH_DEL_M = DSP_2GSCH_MARGIN_TABLE[codec_mod];
    *DSP_SPH_DEL_O = delay;
}

void SALI_Disable_Codec()
{
    *DSP_SPH_COD_CTRL &= 0xFF00;
}


