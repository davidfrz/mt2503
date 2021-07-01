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
 * nvram_l1def.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file provides a fuction for NVRAM Task to get L1 default value
 *
 * Author:
 * -------
 * -------
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
#include "nvram_main.h"         /* nvram_ltable_entry_struct & nvram_ptr, should be removed in the future */
#include "nvram_l1def.h"

#ifdef __MTK_TARGET__
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "stack_config.h"
#include "app_ltlcom.h" /* Task message communiction */


/* L1 calibration data defination */
#include "m12193.h"
#include "m12190.h"
#include "l1cal.h"


#include "nvram_data_items.h"





#endif /* __MTK_TARGET__ */ 


/*****************************************************************************
 * FUNCTION
 *  nvram_get_L1_default_value_to_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lid         [IN]        
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_get_L1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i, j;
    l1cal_agcPathLoss_T *agc;
    l1cal_rampTable_T *ramp;
    l1cal_afcData_T *afc;

    /* l1cal_txiq_T  txiq; */
    FrequencyBand band = FrequencyBand850;

    l1cal_interRampData_T *interRamp;

#if defined(__EPSK_TX__)
    l1cal_EPSK_interRampData_T *EPSK_interRamp;
#endif 
    l1cal_crystalAfcData_T *crystalAfc;
    l1cal_crystalCapData_T *crystalCap;
    nvram_ltable_entry_struct *ldi;

#if defined(__PS_SERVICE__) 
    l1cal_tx_power_rollback_T *tx_power_rollback;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_util_get_data_item(&ldi, lid);

    kal_mem_set(buffer, 0x00, ldi->size);
    
    switch (lid)
    {
        case NVRAM_EF_L1_AGCPATHLOSS_LID:
            /* L1 Data - AGC */
            agc = (l1cal_agcPathLoss_T*) buffer;
            for (i = 0; i < FrequencyBandCount; i++)
            {
                if (AGC_PATHLOSS_TABLE[i] != 0)
                {
                    kal_mem_cpy(
                        &agc->agcPathLoss[i][0],
                        AGC_PATHLOSS_TABLE[i],
                        (sizeof(sAGCGAINOFFSET) * PLTABLE_SIZE));
                }
            }
            break;
        case NVRAM_EF_L1_RAMPTABLE_GSM850_LID:
        case NVRAM_EF_L1_RAMPTABLE_GSM900_LID:
        case NVRAM_EF_L1_RAMPTABLE_DCS1800_LID:
        case NVRAM_EF_L1_RAMPTABLE_PCS1900_LID:
            /* L1 Data - Ramp */
            ramp = (l1cal_rampTable_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_RAMPTABLE_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_RAMPTABLE_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_RAMPTABLE_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_RAMPTABLE_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            if (RampData[band] != 0)
            {
                extern void L1D_RF_InitEmptyRampData( int rf_band, int is_epsk );
                L1D_RF_InitEmptyRampData( band, 0/*gmsk*/ );
                kal_mem_cpy(&ramp->rampData, RampData[band], sizeof(sRAMPDATA));
            }
            break;
        #if defined(__EPSK_TX__)
        case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID:
        case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID:
        case NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID:
        case NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID:
            /* L1 Data - Ramp */
            ramp = (l1cal_rampTable_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            if (RampData_EPSK[band] != 0)
            {
                extern void L1D_RF_InitEmptyRampData( int rf_band, int is_epsk );
                L1D_RF_InitEmptyRampData( band, 1/*epsk*/ );
                kal_mem_cpy(&ramp->rampData, RampData_EPSK[band], sizeof(sRAMPDATA));
            }
            break;
        #endif /* defined(__EPSK_TX__) */ 
        case NVRAM_EF_L1_AFCDATA_LID:
            /* L1 Data - Afc */
            afc = (l1cal_afcData_T *)buffer;
           #if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)
			     afc->dacValue = l1d_rf_custom_input_data.RF_Others_Variable.xafc_dac_default;
			     afc->slopeInv = l1d_rf_custom_input_data.RF_Others_Variable.xafc_inv_slope;
           #else
            afc->dacValue = PSI_EE;
            afc->slopeInv = C_PSI_STA;
           #endif
            break;
        case NVRAM_EF_L1_TXIQ_LID:
            /* L1 Data - TX IQ */
            //txiq.TxTrimI   = bbtx_trim_i;
            //txiq.TxTrimQ   = bbtx_trim_q;
            //txiq.TxOffsetI = bbtx_offset_i;
            //txiq.TxOffsetQ = bbtx_offset_q;
            //kal_mem_cpy(buffer, &txiq, sizeof(l1cal_txiq_T));
            L1D_RF_Custom_BBTXParameter_Update();
            kal_mem_cpy(buffer, &BBTXParameters, sizeof(l1cal_txiq_T));
            break;
        case NVRAM_EF_L1_RFSPECIALCOEF_LID:
            /* L1 Data - RF Special coef */
        {
            extern void L1D_RF_Init_SpecialCoef(void);

            L1D_RF_Init_SpecialCoef();
        }
            kal_mem_cpy(buffer, &RFSpecialCoef, sizeof(l1cal_rfspecialcoef_T));
            break;
        case NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID:
        case NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID:
        case NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID:
        case NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID:
            interRamp = (l1cal_interRampData_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            /* Shine modified start */
            if (InterRampData[band] != 0)
            {
                extern void L1D_RF_InitEmptyInterRampData( void* p );
                L1D_RF_InitEmptyInterRampData( InterRampData[band] );
                kal_mem_cpy(&(interRamp->interRampData[0]), InterRampData[band], sizeof(sMIDRAMPDATA));
            }
            /* Shine modified end */
            break;

        #if defined(__EPSK_TX__)
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID:
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID:
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID:
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID:
            EPSK_interRamp = (l1cal_EPSK_interRampData_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            for (i = 0; i < 4; i++)
            {
                if ((*(EPSK_InterRampData[band])[i]) != 0)
                {
                    extern void L1D_RF_InitEmptyInterRampData( void *p );
                    L1D_RF_InitEmptyInterRampData( (*(EPSK_InterRampData[band])[i]) );
                    kal_mem_cpy(
                        &(EPSK_interRamp->EPSK_interRampData[i]),
                        (*(EPSK_InterRampData[band])[i]),
                        sizeof(sMIDRAMPDATA));
                }
            }
            break;
        #endif /* defined(__EPSK_TX__) */ 

        case NVRAM_EF_L1_CRYSTAL_AFCDATA_LID:
            /* Shine modified start */
            crystalAfc = (l1cal_crystalAfcData_T*) buffer;
            kal_mem_cpy(&(crystalAfc->XO_SlopeAreaData[0]), XO_SlopeAreaData_RO, sizeof(l1cal_crystalAfcData_T));
            /* Shine modified end */
            break;
        case NVRAM_EF_L1_CRYSTAL_CAPDATA_LID:
            /* Shine modified start */
            L1D_RF_CAPID_Update();
            crystalCap = (l1cal_crystalCapData_T*) buffer;
            kal_mem_cpy(&(crystalCap->cap_id), &XO_CapID, sizeof(l1cal_crystalCapData_T));
            /* Shine modified end */
            break;
        #if defined(__PS_SERVICE__) 
        case NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_LID:
            tx_power_rollback = (l1cal_tx_power_rollback_T*) buffer;
            for (i = 0; i < FrequencyBandCount; i++)
            {
                if (tx_power_rollback_gmsk[i] != 0)
                {
                    kal_mem_cpy(&(tx_power_rollback->rollback_data[i]), tx_power_rollback_gmsk[i], sizeof(sTX_POWER_ROLLBACK));
                }
            }        	  
        	  break;
        #if defined(__EGPRS_MODE__) 
        case NVRAM_EF_L1_EPSK_TX_POWER_ROLLBACK_TABLE_LID:
        	  tx_power_rollback = (l1cal_tx_power_rollback_T*) buffer;
            for (i = 0; i < FrequencyBandCount; i++)
            {
                if (tx_power_rollback_epsk[i] != 0)
                {
                    kal_mem_cpy(&(tx_power_rollback->rollback_data[i]), tx_power_rollback_epsk[i], sizeof(sTX_POWER_ROLLBACK));
                }
            }        	  
        	  break;
        #endif /*defined(__EGPRS_MODE__)*/        	  
        #endif /*defined(__PS_SERVICE__)*/
        #if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
        case NVRAM_EF_L1_GMSK_TXPC_LID:
            L1D_RF_TXPC_GET_L1_SETTING( (sTXPC_L1CAL*)buffer, 0 /*GMSK*/ );
            break;
        #if defined(__EPSK_TX__)
        case NVRAM_EF_L1_EPSK_TXPC_LID:
            L1D_RF_TXPC_GET_L1_SETTING( (sTXPC_L1CAL*)buffer, 1 /*EPSK*/ );
            break;
        #endif /*defined(__EPSK_TX__)*/
        #endif /*defined(__2G_TX_POWER_CONTROL_SUPPORT__)*/
        #if defined(__MULTI_LNA_MODE_CALIBRATION_SUPPORT__)
        case NVRAM_EF_L1_LNAPATHLOSS_LID:
            /* L1 Data - LNA */
            L1D_RF_GetLnaPathLossTable( (sLNAPATHLOSS_L1CAL*)buffer );
            break;
        #endif /*defined(__MULTI_LNA_MODE_CALIBRATION_SUPPORT__)*/
        #if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)
        case NVRAM_EF_L1_2G_RF_PARAMETER_LID:
            kal_mem_cpy(buffer, &l1d_rf_custom_input_data, sizeof(l1d_rf_custom_input_data_T));
		    break;
        #endif
        #if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
        #if !defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__)
        case NVRAM_EF_L1_TEMPERATURE_ADC_LID:
            L1D_RF_TXPC_GET_TEMP_ADC( (sTEMPERATURE_ADC_L1CAL*)buffer );
            break;
        #endif /*!defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__)*/
        #endif /*defined(__2G_TX_POWER_CONTROL_SUPPORT__)*/
        #if defined(__F32_XOSC_REMOVAL_SUPPORT__)
        case NVRAM_EF_L1_CLOAD_FREQ_OFFSET_LID:
            L1D_RF_GetCLoadFreqOffset( (kal_int32*)buffer );
            break;
        #endif /*defined(__F32_XOSC_REMOVAL_SUPPORT__)*/
        
        default:
            ASSERT(KAL_FALSE);
            break;
    }

#endif /* __MTK_TARGET__ */ 

}

void  nvram_init_L1_RF_customInputData(void)
{
#ifdef __MTK_TARGET__
   #if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)
      sL1D_RF_CUSTOM_INPUT_DATA *l1d_rf_custom_input_data_buffer = (sL1D_RF_CUSTOM_INPUT_DATA *)get_ctrl_buffer( sizeof( sL1D_RF_CUSTOM_INPUT_DATA ) );
      nvram_errno_enum error_no;
      error_no = nvram_external_read_data(NVRAM_EF_L1_2G_RF_PARAMETER_LID, 1, (kal_uint8 *)l1d_rf_custom_input_data_buffer, NVRAM_EF_L1_2G_RF_PARAMETER_SIZE);
      ASSERT(error_no == KAL_TRUE);
      kal_mem_cpy(&l1d_rf_custom_input_data, l1d_rf_custom_input_data_buffer, sizeof(sL1D_RF_CUSTOM_INPUT_DATA));
      free_ctrl_buffer( l1d_rf_custom_input_data_buffer );
   #endif   
#endif /* __MTK_TARGET__ */    
}


