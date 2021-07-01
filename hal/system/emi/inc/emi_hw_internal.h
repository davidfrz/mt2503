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
 *   emi_hw_internal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for CONFIG hardware registers
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __EMI_HW_INTERNAL_H__
#define __EMI_HW_INTERNAL_H__

#include "reg_base.h"

#if !defined(_REG_BASE_H)
#error "reg_base.h must be included first"
#endif  /* !_REG_BASE_H */


#if defined(MT6208)

#define EMI_CON0                 ((volatile UINT16P)(EMI_base+0x0000))  /* Bank 0 configuration */
#define EMI_CONA                 EMI_CON0
#define EMI_CON1                 ((volatile UINT16P)(EMI_base+0x0004))  /* Bank 1 configuration */
#define EMI_CONB                 EMI_CON1
#define EMI_CON2                 ((volatile UINT16P)(EMI_base+0x0008))  /* Bank 2 configuration */
#define EMI_CONC                 EMI_CON2
#define EMI_CON3                 ((volatile UINT16P)(EMI_base+0x000C))  /* Bank 3 configuration */
#define EMI_COND                 EMI_CON3
#define EMI_CON4                 ((volatile UINT16P)(EMI_base+0x0010))  /* Boot Mapping config  */
#define EMI_CON5                 ((volatile UINT16P)(EMI_base+0x0014))
#define EMI_GEN                  ((volatile UINT16P)(EMI_base+0x0014))
#define SDRAM_MODE               ((volatile UINT16P)(EMI_base+0x0020))
#define SDRAM_COMD               ((volatile UINT16P)(EMI_base+0x0024))
#define SDRAM_SET                ((volatile UINT16P)(EMI_base+0x0028))
#define PREFETCH_CON             ((volatile UINT16P)(EMI_base+0x0030))

#elif defined(MT6218)    /* MT6208 */

#define EMI_CONA0                ((volatile UINT16P)(EMI_base+0x0000))  /* Bank 0 configuration */
#define EMI_CONA1                ((volatile UINT16P)(EMI_base+0x0004))  /* Bank 0 configuration */
#define EMI_CONB0                ((volatile UINT16P)(EMI_base+0x0008))  /* Bank 1 configuration */
#define EMI_CONB1                ((volatile UINT16P)(EMI_base+0x000C))  /* Bank 1 configuration */
#define EMI_CONC0                ((volatile UINT16P)(EMI_base+0x0010))  /* Bank 2 configuration */
#define EMI_CONC1                ((volatile UINT16P)(EMI_base+0x0014))  /* Bank 2 configuration */
#define EMI_COND0                ((volatile UINT16P)(EMI_base+0x0018))  /* Bank 3 configuration */
#define EMI_COND1                ((volatile UINT16P)(EMI_base+0x001C))  /* Bank 3 configuration */
#define EMI_CONE0                ((volatile UINT16P)(EMI_base+0x0020))  /* Bank 4 configuration */
#define EMI_CONE1                ((volatile UINT16P)(EMI_base+0x0024))  /* Bank 4 configuration */
#define EMI_CONF0                ((volatile UINT16P)(EMI_base+0x0028))  /* Bank 5 configuration */
#define EMI_CONF1                ((volatile UINT16P)(EMI_base+0x002C))  /* Bank 5 configuration */
#define EMI_REMAP                ((volatile UINT16P)(EMI_base+0x0030))  /* EMI Re-map Control Register */
#define EMI_GEN                  ((volatile UINT16P)(EMI_base+0x0034))  /* EMI General Control Register */
#define PREFETCH_CON             ((volatile UINT16P)(EMI_base+0x0050))  /* Code Cache and Code Prefetch Control Register */
#define EMI_PATCHEN              ((volatile UINT16P)(EMI_base+0x0060))  /* EMI Patch Enable Register */
#define EMI_MSBPA0               ((volatile UINT16P)(EMI_base+0x0064))  /* EMI Patch Address 0 MSB Register */
#define EMI_LSBPA0               ((volatile UINT16P)(EMI_base+0x0068))  /* EMI Patch Address 0 LSB Register */
#define EMI_MSBPD0               ((volatile UINT16P)(EMI_base+0x006C))  /* EMI Patch Instruction 0 MLB Register */
#define EMI_LSBPD0               ((volatile UINT16P)(EMI_base+0x0070))  /* EMI Patch Instruction 1 LSB Register */
#define EMI_MSBPA1               ((volatile UINT16P)(EMI_base+0x0074))  /* EMI Patch Address 1 MSB Register */
#define EMI_LSBPA1               ((volatile UINT16P)(EMI_base+0x0078))  /* EMI Patch Address 1 LSB Register */
#define EMI_MSBPD1               ((volatile UINT16P)(EMI_base+0x007C))  /* EMI Patch Instruction 1 MLB Register */
#define EMI_LSBPD1               ((volatile UINT16P)(EMI_base+0x0080))  /* EMI Patch Instruction 1 LSB Register */

#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6268H)  /* MT6208 */

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0010))  /* EMI control register for bank 2 */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x0018))  /* EMI control register for bank 3 */
#define EMI_CONI                 ((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for Mobile-RAM */
#define EMI_CONJ                 ((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for Mobile-RAM */
#define EMI_CONK                 ((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for Mobile-RAM */
#define EMI_CONL                 ((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for Mobile-RAM */
#define EMI_REMAP                ((volatile UINT16P)(EMI_base+0x0060))  /* EMI Re-map Control Register */
#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0068))  /* EMI General Control Register 0 */
#define EMI_GENB                 ((volatile UINT32P)(EMI_base+0x0070))  /* EMI General Control Register 1 */

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6268H)
#define EMI_GENC                 ((volatile UINT32P)(EMI_base+0x0078))  /* EMI General Control Register 2 */
#endif /* MT6229 || MT6230 || MT6268T || MT6268H */

#if defined(MT6225)
#define EMI_ADMUX                ((volatile UINT32P)(EMI_base+0x0078))  /* ADMUX Control Register */
#endif /* MT6225 */

#elif defined(MT6253T) || defined(MT6253)   /* MT6208 */

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0004))  /* EMI control register for bank 1 */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 2 */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x000C))  /* EMI control register for bank 3 */
#define EMI_MONCTRL                 ((volatile UINT16P)(EMI_base+0x0020))  /* EMI monitor control */
#define EMI_REMAP                ((volatile UINT16P)(EMI_base+0x0040))  /* EMI Re-map Control Register */
#define EMI_GEN                 ((volatile UINT32P)(EMI_base+0x0044))  /* EMI General Control Register 0 */
#define EMI_CLOCKDEL		((volatile UINT32P)(EMI_base+0x0048))
#define EMI_BLOCKDEL		((volatile UINT32P)(EMI_base+0x004C))
#define EMI_DELA			((volatile UINT32P)(EMI_base+0x0050))
#define EMI_DELB			((volatile UINT32P)(EMI_base+0x0054))
#define EMI_DELC			((volatile UINT32P)(EMI_base+0x0058))
#define EMI_DELD			((volatile UINT32P)(EMI_base+0x005C))
#define PREFETCH_CON ((volatile UINT32P)(EMI_base+0x0070)) 
#define EMI_ADMUX		((volatile UINT32P)(EMI_base+0x0074))
#define EMI_EXTCON		((volatile UINT32P)(EMI_base+0x0078))
#define EMI_EXTCON2		((volatile UINT32P)(EMI_base+0x007C))
#define EMI_GEN2		      ((volatile UINT32P)(EMI_base+0x0080))
#define EMI_CONA_EXT	((volatile UINT32P)(EMI_base+0x0090))
#define EMI_CONB_EXT	((volatile UINT32P)(EMI_base+0x0094))

#elif defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)   /* MT6208 */
 
#define EMI_CONA                ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                ((volatile UINT32P)(EMI_base+0x0004))  /* EMI control register for bank 1 */
#define EMI_CONC                ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 2 */
#define EMI_MONCTRL             ((volatile UINT16P)(EMI_base+0x0020))  /* EMI monitor control */
#define EMI_REMAP               ((volatile UINT16P)(EMI_base+0x0040))  /* EMI Re-map Control Register */
#define EMI_GEN                 ((volatile UINT32P)(EMI_base+0x0044))  /* EMI General Control Register 1 */
#define EMI_CLOCKDEL		((volatile UINT32P)(EMI_base+0x0048))  /* EMI Clock Delay Control Register */

#define PREFETCH_CON            ((volatile UINT32P)(EMI_base+0x0070))  /* EMI Prefetch Control Register */ 
#define EMI_ADMUX		((volatile UINT32P)(EMI_base+0x0074))  /* EMI ADMUX Control Register */ 
#define EMI_EXTCON		((volatile UINT32P)(EMI_base+0x0078))  /* EMI Extension Control Register 1 */ 
#define EMI_EXTCON2		((volatile UINT32P)(EMI_base+0x007C))  /* EMI Extension Control Register 2 */ 
#define EMI_GEN2		((volatile UINT32P)(EMI_base+0x0080))  /* EMI General Control Register 2 */ 
#define EMI_EXTCON3		((volatile UINT32P)(EMI_base+0x0084))  /* EMI Extension Control Register 3 */ 

#define EMI_CONA_EXT	        ((volatile UINT32P)(EMI_base+0x0090))  /* EMI BANK0 Control Extension Register */ 
#define EMI_CONB_EXT	        ((volatile UINT32P)(EMI_base+0x0094))  /* EMI BANK1 Control Extension Register */ 
#define EMI_CONC_EXT	        ((volatile UINT32P)(EMI_base+0x0098))  /* EMI BANK2 Control Extension Register */ 
#define EMI_COND_EXT	        ((volatile UINT32P)(EMI_base+0x009C))  /* EMI BANK0/1/2 Control Extension Register */ 

#define EMI_ARBA	        ((volatile UINT32P)(EMI_base+0x00A0))  /* EMI MCU BW Filter Control Register */ 
#define EMI_ARBB	        ((volatile UINT32P)(EMI_base+0x00A4))  /* EMI DMA BW Filter Control Register */ 
#define EMI_ARBC	        ((volatile UINT32P)(EMI_base+0x00A8))  /* EMI GMC BW Filter Control Register */ 

#define EMI_IOA	                ((volatile UINT32P)(EMI_base+0x00C0))  /* EMI IO Control Register 1 */ 
#define EMI_IOB	                ((volatile UINT32P)(EMI_base+0x00C4))  /* EMI IO Control Register 2 */ 
#define EMI_IOC	                ((volatile UINT32P)(EMI_base+0x00C8))  /* EMI IO Control Register 3 */ 

#define EMI_GEN3		((volatile UINT32P)(EMI_base+0x00F0))  /* EMI General Control Register 3 */ 


#elif defined(MT6251) /* MT6251 */

#define EMI_REMAP                ((volatile UINT16P)(L1_CACHE_base+0x0040))  /* MT6251 SYSRAM Re-map Control Register */

#elif defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B)   /* MT6208 */

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0010))  /* EMI control register for bank 2 */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x0018))  /* EMI control register for bank 3 */

#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))  /* EMI control register for bank 3 */
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* EMI control register for bank 3 */
#define EMI_CONG                 ((volatile UINT32P)(EMI_base+0x0030))  /* EMI control register for bank 3 */
#define EMI_CONH                 ((volatile UINT32P)(EMI_base+0x0038))  /* EMI control register for bank 3 */

#define EMI_CONI                 ((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for MR/EMR */
#define EMI_CONJ                 ((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for DRAM Controller timing configuration 1. */
#define EMI_CONK                 ((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for DRAM Controller timing configuration 2. */
#define EMI_CONL                 ((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for DRAM Controller read data path configuration. */
#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))  /* EMI control register 3 for DRAM Controller read delay timing configuration. */
#define EMI_CONN                 ((volatile UINT32P)(EMI_base+0x0068))  /* EMI control register 3 for DRAM Controller function configuration. */
#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))  /* EMI General Control Register 0 */
#define EMI_GENB                 ((volatile UINT32P)(EMI_base+0x0078))  /* EMI General Control Register 1 */
#define EMI_GENC                 ((volatile UINT32P)(EMI_base+0x0080))  /* EMI General Control Register 2 */
#define EMI_GEND                 ((volatile UINT32P)(EMI_base+0x0088))  /* EMI General Control Register 3 */
#define EMI_REMAP                ((volatile UINT32P)(EMI_base+0x0070))  /* EMI Re-map Control Register */

#define DRAM_TYPE_MASK		0x00070000
#define DRAM_TYPE_SDR		0x00000000
#define DRAM_TYPE_DDR		0x00020000

#elif defined(MT6268A)   /* MT6208 */

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0010))  /* EMI control register for bank 2 */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x0018))  /* EMI control register for bank 3 */

#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))  /* EMI control register for bank 3 */
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* EMI control register for bank 3 */
#define EMI_CONG                 ((volatile UINT32P)(EMI_base+0x0030))  /* EMI control register for bank 3 */
#define EMI_CONH                 ((volatile UINT32P)(EMI_base+0x0038))  /* EMI control register for bank 3 */

#define EMI_CONI                 ((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for MR/EMR */
#define EMI_CONJ                 ((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for DRAM Controller timing configuration 1. */
#define EMI_CONK                 ((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for DRAM Controller timing configuration 2. */
#define EMI_CONL                 ((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for DRAM Controller read data path configuration. */
#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))  /* EMI control register 3 for DRAM Controller read delay timing configuration. */
#define EMI_CONN                 ((volatile UINT32P)(EMI_base+0x0068))  /* EMI control register 3 for DRAM Controller function configuration. */
#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))  /* EMI General Control Register 0 */
#define EMI_GENB                 ((volatile UINT32P)(EMI_base+0x0078))  /* EMI General Control Register 1 */
#define EMI_GENC                 ((volatile UINT32P)(EMI_base+0x0080))  /* EMI General Control Register 2 */
#define EMI_GEND                 ((volatile UINT32P)(EMI_base+0x0088))  /* EMI General Control Register 3 */
#define EMI_GENE                 ((volatile UINT32P)(EMI_base+0x0090))  /* EMI General Control Register 3 */
#define EMI_DQSA                 ((volatile UINT32P)(EMI_base+0x01B0))  /* EMI General Control Register 3 */
#define EMI_REMAP                ((volatile UINT32P)(EMI_base+0x0070))  /* EMI Re-map Control Register */
#define EMI_DRCT                 ((volatile UINT32P)(EMI_base+0x01A0))  /* EMI Dummy-read Control Register */

#define DRAM_TYPE_MASK		0x00070000
#define DRAM_TYPE_SDR		0x00000000
#define DRAM_TYPE_DDR		0x00020000

#elif defined(MT6268) || defined(MT6236) || defined(MT6236B)  /* MT6208 */

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0010))  /* EMI control register for bank 2 */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x0018))  /* EMI control register for bank 3 */

#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))  /* EMI control register for bank 3 */
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* EMI control register for bank 3 */
#define EMI_CONG                 ((volatile UINT32P)(EMI_base+0x0030))  /* EMI control register for bank 3 */
#define EMI_CONH                 ((volatile UINT32P)(EMI_base+0x0038))  /* EMI control register for bank 3 */

#define EMI_CONI                 ((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for MR/EMR */
#define EMI_CONJ                 ((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for DRAM Controller timing configuration 1. */
#define EMI_CONK                 ((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for DRAM Controller timing configuration 2. */
#define EMI_CONL                 ((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for DRAM Controller read data path configuration. */
#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))  /* EMI control register 3 for DRAM Controller read delay timing configuration. */
#define EMI_CONN                 ((volatile UINT32P)(EMI_base+0x0068))  /* EMI control register 3 for DRAM Controller function configuration. */

#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))  /* EMI General Control Register 0 */
#define EMI_GENB                 ((volatile UINT32P)(EMI_base+0x0078))  /* EMI General Control Register 1 */
#define EMI_GENC                 ((volatile UINT32P)(EMI_base+0x0080))  /* EMI General Control Register 2 */
#define EMI_GEND                 ((volatile UINT32P)(EMI_base+0x0088))  /* EMI General Control Register 3 */
#define EMI_GENE                 ((volatile UINT32P)(EMI_base+0x0090))  /* EMI General Control Register 3 */

#define EMI_DELA                 ((volatile UINT32P)(EMI_base+0x0098))  /* EMI Delay Control Register 0 */
#define EMI_DELB                 ((volatile UINT32P)(EMI_base+0x00A0))  /* EMI Delay Control Register 1 */
#define EMI_DELC                 ((volatile UINT32P)(EMI_base+0x00A8))  /* EMI Delay Control Register 2 */
#define EMI_DELD                 ((volatile UINT32P)(EMI_base+0x00B0))  /* EMI Delay Control Register 3 */
#define EMI_DELE                 ((volatile UINT32P)(EMI_base+0x00B8))  /* EMI Delay Control Register 4 */
#define EMI_DELF                 ((volatile UINT32P)(EMI_base+0x00C0))  /* EMI Delay Control Register 5 */
#define EMI_DELG                 ((volatile UINT32P)(EMI_base+0x00C8))  /* EMI Delay Control Register 6 */
#define EMI_DELH                 ((volatile UINT32P)(EMI_base+0x00D0))  /* EMI Delay Control Register 7 */
#define EMI_DELI                 ((volatile UINT32P)(EMI_base+0x00D8))  /* EMI Delay Control Register 8 */
#define EMI_DELJ                 ((volatile UINT32P)(EMI_base+0x00E0))  /* EMI Delay Control Register 9 */


#define EMI_DQSA                 ((volatile UINT32P)(EMI_base+0x01B0))  /* EMI DQS Auto Tracking Control Register 0 */
#define EMI_DQSB                 ((volatile UINT32P)(EMI_base+0x01B8))  /* EMI DQS Auto Tracking Control Register 1 */
#define EMI_DQSC                 ((volatile UINT32P)(EMI_base+0x01C0))  /* EMI DQS Auto Tracking Control Register 2 */
#define EMI_DQSD                 ((volatile UINT32P)(EMI_base+0x01C8))  /* EMI DQS Auto Tracking Control Register 3 */

#define EMI_ARBA                 ((volatile UINT32P)(EMI_base+0x0200))  /* EMI Bandwidth Filter Control M0 */
#define EMI_ARBB                 ((volatile UINT32P)(EMI_base+0x0208))  /* EMI Bandwidth Filter Control M1 */
#define EMI_ARBC                 ((volatile UINT32P)(EMI_base+0x0210))  /* EMI Bandwidth Filter Control M2 */
#define EMI_ARBD                 ((volatile UINT32P)(EMI_base+0x0218))  /* EMI Bandwidth Filter Control M3 */
#define EMI_ARBE                 ((volatile UINT32P)(EMI_base+0x0220))  /* EMI Bandwidth Filter Control M4 */
#define EMI_ARBF                 ((volatile UINT32P)(EMI_base+0x0228))  /* EMI Bandwidth Filter Control M5 */
#define EMI_ARBG                 ((volatile UINT32P)(EMI_base+0x0230))  /* EMI Bandwidth Filter Control M6 */
#define EMI_ARBH                 ((volatile UINT32P)(EMI_base+0x0238))  /* EMI Bandwidth Filter Control GMC0 */
#define EMI_ARBI                 ((volatile UINT32P)(EMI_base+0x0240))  /* EMI Bandwidth Filter Control GMC1 */

#define EMI_RDCT                 ((volatile UINT32P)(EMI_base+0x02B0))  /* EMI SDR Auto Tracking Control Register */
#define EMI_RWDL                 ((volatile UINT32P)(EMI_base+0x02B8))  /* EMI SDR Auto Tracking Windows Delay */
#define EMI_RTDL                 ((volatile UINT32P)(EMI_base+0x02C0))  /* EMI SDR Auto Tracking Path Delay */
#define EMI_RWCL                 ((volatile UINT32P)(EMI_base+0x02C8))  /* EMI SDR Auto Tracking Windows Value */
#define EMI_RTCL                 ((volatile UINT32P)(EMI_base+0x02D0))  /* EMI SDR Auto Tracking Delay Value */

#define EMI_REMAP                ((volatile UINT32P)(EMI_base+0x0070))  /* EMI Re-map Control Register */

#define EMI_DRCT                 ((volatile UINT32P)(EMI_base+0x01A0))  /* EMI Dummy-read Control Register */

#define DRAM_TYPE_MASK		0x00070000
#define DRAM_TYPE_SDR		0x00000000
#define DRAM_TYPE_DDR		0x00020000

#elif defined(MT6276)  /* MT6208 */

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0010))  /* EMI control register for bank 2 */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x0018))  /* EMI control register for bank 3 */
#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))  /* EMI control register for bank 0 */
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* EMI control register for bank 1 */
#define EMI_CONG                 ((volatile UINT32P)(EMI_base+0x0030))  /* EMI control register for bank 2 */
#define EMI_CONH                 ((volatile UINT32P)(EMI_base+0x0038))  /* EMI control register for bank 3 */
#define EMI_CONI                 ((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for Mobile-RAM */
#define EMI_CONJ                 ((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for Mobile-RAM */
#define EMI_CONK                 ((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for Mobile-RAM */
#define EMI_CONL                 ((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for Mobile-RAM */
#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))
#define EMI_CONN                 ((volatile UINT32P)(EMI_base+0x0068))
#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))
#define EMI_DRCT                 ((volatile UINT32P)(EMI_base+0x0078))
#define EMI_DDRV                 ((volatile UINT32P)(EMI_base+0x0080))
#define EMI_GEND                 ((volatile UINT32P)(EMI_base+0x0088))
#define EMI_PPCT                 ((volatile UINT32P)(EMI_base+0x0090))
#define EMI_MDCL                 ((volatile UINT32P)(EMI_base+0x0098))
#define EMI_DLLV                 ((volatile UINT32P)(EMI_base+0x00A0))
#define EMI_DFTC                 ((volatile UINT32P)(EMI_base+0x00F0))
#define EMI_DFTD                 ((volatile UINT32P)(EMI_base+0x00F8))
#define EMI_ARBA                 ((volatile UINT32P)(EMI_base+0x0100))
#define EMI_ARBB                 ((volatile UINT32P)(EMI_base+0x0108))
#define EMI_ARBC                 ((volatile UINT32P)(EMI_base+0x0110))
#define EMI_ARBD                 ((volatile UINT32P)(EMI_base+0x0118))
#define EMI_ARBE                 ((volatile UINT32P)(EMI_base+0x0120))
#define EMI_ARBF                 ((volatile UINT32P)(EMI_base+0x0128))
#define EMI_ARBG                 ((volatile UINT32P)(EMI_base+0x0130))
#define EMI_SLCT                 ((volatile UINT32P)(EMI_base+0x0150))
#define EMI_ABCT	             ((volatile UINT32P)(EMI_base+0x0158))
#define EMI_MPUA                 ((volatile UINT32P)(EMI_base+0x0160))
#define EMI_MPUB                 ((volatile UINT32P)(EMI_base+0x0168))
#define EMI_MPUC                 ((volatile UINT32P)(EMI_base+0x0170))
#define EMI_MPUD                 ((volatile UINT32P)(EMI_base+0x0178))
#define EMI_MPUE                 ((volatile UINT32P)(EMI_base+0x0180))
#define EMI_MPUF	             ((volatile UINT32P)(EMI_base+0x0188))
#define EMI_MPUG	             ((volatile UINT32P)(EMI_base+0x0190))
#define EMI_MPUH	             ((volatile UINT32P)(EMI_base+0x0198))
#define EMI_MPUI	             ((volatile UINT32P)(EMI_base+0x01A0))
#define EMI_MPUJ                 ((volatile UINT32P)(EMI_base+0x01A8))
#define EMI_MPUK                 ((volatile UINT32P)(EMI_base+0x01B0))
#define EMI_MPUL                 ((volatile UINT32P)(EMI_base+0x01B8))
#define EMI_MPUM                 ((volatile UINT32P)(EMI_base+0x01C0))
#define EMI_MPUN                 ((volatile UINT32P)(EMI_base+0x01C8))
#define EMI_MPUO                 ((volatile UINT32P)(EMI_base+0x01D0))
#define EMI_MPUP                 ((volatile UINT32P)(EMI_base+0x01D8))
#define EMI_MPUQ                 ((volatile UINT32P)(EMI_base+0x01E0))
#define EMI_MPUR                 ((volatile UINT32P)(EMI_base+0x01E8))
#define EMI_MPUS                 ((volatile UINT32P)(EMI_base+0x01F0))
#define EMI_MPUT                 ((volatile UINT32P)(EMI_base+0x01F8))
#define EMI_IDLA                 ((volatile UINT32P)(EMI_base+0x0200))
#define EMI_IDLB                 ((volatile UINT32P)(EMI_base+0x0208))
#define EMI_IDLC                 ((volatile UINT32P)(EMI_base+0x0210))
#define EMI_IDLD                 ((volatile UINT32P)(EMI_base+0x0218)) 
#define EMI_IDLE                 ((volatile UINT32P)(EMI_base+0x0220))
#define EMI_IDLF                 ((volatile UINT32P)(EMI_base+0x0228))
#define EMI_IDLG                 ((volatile UINT32P)(EMI_base+0x0230))
#define EMI_IDLH                 ((volatile UINT32P)(EMI_base+0x0238))
#define EMI_IDLI                 ((volatile UINT32P)(EMI_base+0x0240))
#define EMI_IDLJ                 ((volatile UINT32P)(EMI_base+0x0248))
#define EMI_IDLK                 ((volatile UINT32P)(EMI_base+0x0250))
#define EMI_ODLA                 ((volatile UINT32P)(EMI_base+0x0258))
#define EMI_ODLB                 ((volatile UINT32P)(EMI_base+0x0260))
#define EMI_ODLC	             ((volatile UINT32P)(EMI_base+0x0268))
#define EMI_ODLD	             ((volatile UINT32P)(EMI_base+0x0270))
#define EMI_ODLE	             ((volatile UINT32P)(EMI_base+0x0278))
#define EMI_ODLF	             ((volatile UINT32P)(EMI_base+0x0280))
#define EMI_ODLG	             ((volatile UINT32P)(EMI_base+0x0288))
#define EMI_DUTA	             ((volatile UINT32P)(EMI_base+0x0290))
#define EMI_DUTB                 ((volatile UINT32P)(EMI_base+0x0298))
#define EMI_DUTC	             ((volatile UINT32P)(EMI_base+0x02A0))
#define EMI_DRVA                 ((volatile UINT32P)(EMI_base+0x02A8))    
#define EMI_DRVB                 ((volatile UINT32P)(EMI_base+0x02B0))    
#define EMI_IOCL                 ((volatile UINT32P)(EMI_base+0x02B8))   
#define EMI_IOCM                 ((volatile UINT32P)(EMI_base+0x02C0))   
#define EMI_IODC                 ((volatile UINT32P)(EMI_base+0x02C8))    
#define EMI_ODTA                 ((volatile UINT32P)(EMI_base+0x02D0))    
#define EMI_ODTB                 ((volatile UINT32P)(EMI_base+0x02D8)) 
#define EMI_DQSA                 ((volatile UINT32P)(EMI_base+0x0300))
#define EMI_DQSB                 ((volatile UINT32P)(EMI_base+0x0308))
#define EMI_DQSC                 ((volatile UINT32P)(EMI_base+0x0310))
#define EMI_DQSD                 ((volatile UINT32P)(EMI_base+0x0318))
#define EMI_DQSE                 ((volatile UINT32P)(EMI_base+0x0320))
#define EMI_DQSV                 ((volatile UINT32P)(EMI_base+0x0328))
#define EMI_CALA                 ((volatile UINT32P)(EMI_base+0x0330))
#define EMI_CALB                 ((volatile UINT32P)(EMI_base+0x0338))
#define EMI_CALC                 ((volatile UINT32P)(EMI_base+0x0340))
#define EMI_CALD                 ((volatile UINT32P)(EMI_base+0x0348))
#define EMI_CALE                 ((volatile UINT32P)(EMI_base+0x0350))
#define EMI_CALF                 ((volatile UINT32P)(EMI_base+0x0358))
#define EMI_CALG                 ((volatile UINT32P)(EMI_base+0x0360))
#define EMI_CALH                 ((volatile UINT32P)(EMI_base+0x0368))
#define EMI_CALI                 ((volatile UINT32P)(EMI_base+0x0370))
#define EMI_CALJ                 ((volatile UINT32P)(EMI_base+0x0378))
#define EMI_CALK                 ((volatile UINT32P)(EMI_base+0x0380))
#define EMI_CALL                 ((volatile UINT32P)(EMI_base+0x0388))
#define EMI_CALM                 ((volatile UINT32P)(EMI_base+0x0390))
#define EMI_CALN                 ((volatile UINT32P)(EMI_base+0x0398))
#define EMI_CALO                 ((volatile UINT32P)(EMI_base+0x03A0))
#define EMI_CALP                 ((volatile UINT32P)(EMI_base+0x03A8))
#define EMI_DUCA                 ((volatile UINT32P)(EMI_base+0x03B0))
#define EMI_DUCB                 ((volatile UINT32P)(EMI_base+0x03B8))
#define EMI_DUCC                 ((volatile UINT32P)(EMI_base+0x03C0))
#define EMI_DUCD                 ((volatile UINT32P)(EMI_base+0x03C8))
#define EMI_DUCE                 ((volatile UINT32P)(EMI_base+0x03D0))
#define EMI_BMEN                 ((volatile UINT32P)(EMI_base+0x0400))
#define EMI_BCNT                 ((volatile UINT32P)(EMI_base+0x0408))
#define EMI_TACT                 ((volatile UINT32P)(EMI_base+0x0410))
#define EMI_TSCT                 ((volatile UINT32P)(EMI_base+0x0418))
#define EMI_WACT                 ((volatile UINT32P)(EMI_base+0x0420))
#define EMI_WSCT                 ((volatile UINT32P)(EMI_base+0x0428))
#define EMI_BACT                 ((volatile UINT32P)(EMI_base+0x0430))
#define EMI_BSCT                 ((volatile UINT32P)(EMI_base+0x0438))
#define EMI_MSEL                 ((volatile UINT32P)(EMI_base+0x0440))
#define EMI_TSCT2                ((volatile UINT32P)(EMI_base+0x0448))
#define EMI_TSCT3                ((volatile UINT32P)(EMI_base+0x0450))
#define EMI_WSCT2                ((volatile UINT32P)(EMI_base+0x0458))
#define EMI_WSCT3                ((volatile UINT32P)(EMI_base+0x0460))
#define EMI_MSEL2                ((volatile UINT32P)(EMI_base+0x0468))
#define EMI_MSEL3                ((volatile UINT32P)(EMI_base+0x0470))
#define EMI_MSEL4                ((volatile UINT32P)(EMI_base+0x0478))
#define EMI_MSEL5                ((volatile UINT32P)(EMI_base+0x0480))
#define EMI_MSEL6                ((volatile UINT32P)(EMI_base+0x0488))
#define EMI_MSEL7                ((volatile UINT32P)(EMI_base+0x0490))
#define EMI_MSEL8                ((volatile UINT32P)(EMI_base+0x0498))
#define EMI_MSEL9                ((volatile UINT32P)(EMI_base+0x04A0))
#define EMI_MSEL10               ((volatile UINT32P)(EMI_base+0x04A8))
#define EMI_BMID0                ((volatile UINT32P)(EMI_base+0x04B0))
#define EMI_BMID1                ((volatile UINT32P)(EMI_base+0x04B8))
#define EMI_BMID2                ((volatile UINT32P)(EMI_base+0x04C0))
#define EMI_BMID3                ((volatile UINT32P)(EMI_base+0x04C8))
#define EMI_BMID4                ((volatile UINT32P)(EMI_base+0x04D0))
#define EMI_BMID5                ((volatile UINT32P)(EMI_base+0x04D8))
#define EMI_TTYPE1               ((volatile UINT32P)(EMI_base+0x0500))
#define EMI_TTYPE2               ((volatile UINT32P)(EMI_base+0x0508))
#define EMI_TTYPE3               ((volatile UINT32P)(EMI_base+0x0510))
#define EMI_TTYPE4               ((volatile UINT32P)(EMI_base+0x0518))
#define EMI_TTYPE5               ((volatile UINT32P)(EMI_base+0x0520))
#define EMI_TTYPE6               ((volatile UINT32P)(EMI_base+0x0528))
#define EMI_TTYPE7               ((volatile UINT32P)(EMI_base+0x0530))
#define EMI_TTYPE8               ((volatile UINT32P)(EMI_base+0x0538))
#define EMI_TTYPE9               ((volatile UINT32P)(EMI_base+0x0540))
#define EMI_TTYPE10              ((volatile UINT32P)(EMI_base+0x0548))
#define EMI_TTYPE11              ((volatile UINT32P)(EMI_base+0x0550))
#define EMI_TTYPE12              ((volatile UINT32P)(EMI_base+0x0558))
#define EMI_TTYPE13              ((volatile UINT32P)(EMI_base+0x0560))
#define EMI_TTYPE14              ((volatile UINT32P)(EMI_base+0x0568))
#define EMI_TTYPE15              ((volatile UINT32P)(EMI_base+0x0570))
#define EMI_TTYPE16              ((volatile UINT32P)(EMI_base+0x0578))
#define EMI_TTYPE17              ((volatile UINT32P)(EMI_base+0x0580))
#define EMI_TTYPE18              ((volatile UINT32P)(EMI_base+0x0588))
#define EMI_TTYPE19              ((volatile UINT32P)(EMI_base+0x0590))
#define EMI_TTYPE20              ((volatile UINT32P)(EMI_base+0x0598))
#define EMI_TTYPE21              ((volatile UINT32P)(EMI_base+0x05A0))
#define EMI_MBISTA               ((volatile UINT32P)(EMI_base+0x0600))
#define EMI_MBISTB               ((volatile UINT32P)(EMI_base+0x0608))
#define EMI_MBISTC               ((volatile UINT32P)(EMI_base+0x0610))
#define EMI_MBISTD               ((volatile UINT32P)(EMI_base+0x0618))
#define EMI_MBISTE               ((volatile UINT32P)(EMI_base+0x0620))
#define EMI_RFCA                 ((volatile UINT32P)(EMI_base+0x0630))
#define EMI_RFCB                 ((volatile UINT32P)(EMI_base+0x0638))
#define EMI_RFCC                 ((volatile UINT32P)(EMI_base+0x0640))
#define EMI_RFCD                 ((volatile UINT32P)(EMI_base+0x0648))

#define EMI_REMAP                ((volatile UINT32P)(EMI_base+0x0070))  /* EMI Re-map Control Register */

#define DRAM_TYPE_MASK		0x00070000
#define DRAM_TYPE_SDR		0x00000000
#define DRAM_TYPE_DDR		0x00020000

#elif defined(MT6250)  /* MT6208 */
#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */

#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))  /* EMI control register for bank 0 */
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* EMI control register for bank 1 */

#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))

#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))
#define EMI_RDCT                 ((volatile UINT32P)(EMI_base+0x0088))
#define EMI_DLLV                 ((volatile UINT32P)(EMI_base+0x0090))

#define EMI_IDLA                 ((volatile UINT32P)(EMI_base+0x00C0))
#define EMI_IDLB                 ((volatile UINT32P)(EMI_base+0x00C8))
#define EMI_IDLC                 ((volatile UINT32P)(EMI_base+0x00D0))
#define EMI_IDLD                 ((volatile UINT32P)(EMI_base+0x00D8))
#define EMI_IDLE                 ((volatile UINT32P)(EMI_base+0x00E0))

#define EMI_ODLA	             ((volatile UINT32P)(EMI_base+0x00E8))
#define EMI_ODLB	             ((volatile UINT32P)(EMI_base+0x00F0))
#define EMI_ODLC	             ((volatile UINT32P)(EMI_base+0x00F8))
#define EMI_ODLD	             ((volatile UINT32P)(EMI_base+0x0100))
#define EMI_ODLE	             ((volatile UINT32P)(EMI_base+0x0108))
#define EMI_ODLF	             ((volatile UINT32P)(EMI_base+0x0110))

#define EMI_IOA	                 ((volatile UINT32P)(EMI_base+0x0130))
#define EMI_IOB	                 ((volatile UINT32P)(EMI_base+0x0138))

#define EMI_DSRAM	             ((volatile UINT32P)(EMI_base+0x0150))

#define EMI_ARBA                 ((volatile UINT32P)(EMI_base+0x0180))
#define EMI_ARBB                 ((volatile UINT32P)(EMI_base+0x0188))
#define EMI_ARBC                 ((volatile UINT32P)(EMI_base+0x0190))
#define EMI_SLCT                 ((volatile UINT32P)(EMI_base+0x0198))
#define EMI_ABCT	           ((volatile UINT32P)(EMI_base+0x01A0))

#define EMI_BMEN                 ((volatile UINT32P)(EMI_base+0x0200))
#define EMI_BCNT                 ((volatile UINT32P)(EMI_base+0x0208))
#define EMI_TACT                 ((volatile UINT32P)(EMI_base+0x0210))
#define EMI_TSCT                 ((volatile UINT32P)(EMI_base+0x0218))
#define EMI_WACT                 ((volatile UINT32P)(EMI_base+0x0220))
#define EMI_WSCT                 ((volatile UINT32P)(EMI_base+0x0228))
#define EMI_BACT                 ((volatile UINT32P)(EMI_base+0x0230))
#define EMI_BSCT0                ((volatile UINT32P)(EMI_base+0x0238))
#define EMI_BSCT1                ((volatile UINT32P)(EMI_base+0x0240))
#define EMI_MSEL                 ((volatile UINT32P)(EMI_base+0x0248))
#define EMI_TSCT2                ((volatile UINT32P)(EMI_base+0x0250))
#define EMI_TSCT3                ((volatile UINT32P)(EMI_base+0x0258))
#define EMI_WSCT2                ((volatile UINT32P)(EMI_base+0x0260))
#define EMI_WSCT3                ((volatile UINT32P)(EMI_base+0x0268))

#define EMI_TTYPE1               ((volatile UINT32P)(EMI_base+0x0280))
#define EMI_TTYPE2               ((volatile UINT32P)(EMI_base+0x0288))
#define EMI_TTYPE3               ((volatile UINT32P)(EMI_base+0x0290))

#define EMI_MBISTA               ((volatile UINT32P)(EMI_base+0x0300))
#define EMI_MBISTB               ((volatile UINT32P)(EMI_base+0x0308))
#define EMI_MBISTC               ((volatile UINT32P)(EMI_base+0x0310))
#define EMI_MBISTD               ((volatile UINT32P)(EMI_base+0x0318))

#define EMI_TEST                ((volatile UINT32P)(EMI_base+0x0330))  

#define EMI_REMAP                ((volatile UINT16P)(BOOT_ENG_base +0x0000))  /* EMI Re-map Control Register */ 

#define EMI_EFUSE           ((volatile UINT32P)0xA01C0104)  

#elif defined(MT6260)  /* MT6208 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */

#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* EMI control register for bank 1 */

#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))

#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))
#define EMI_AADMUX               ((volatile UINT32P)(EMI_base+0x0080))
#define EMI_RDCT                 ((volatile UINT32P)(EMI_base+0x0088))
#define EMI_DLLV                 ((volatile UINT32P)(EMI_base+0x0090))

#define EMI_IDLA                 ((volatile UINT32P)(EMI_base+0x00C0))
#define EMI_IDLB                 ((volatile UINT32P)(EMI_base+0x00C8))
#define EMI_IDLC                 ((volatile UINT32P)(EMI_base+0x00D0))
#define EMI_IDLD                 ((volatile UINT32P)(EMI_base+0x00D8))
#define EMI_IDLE                 ((volatile UINT32P)(EMI_base+0x00E0))

#define EMI_ODLA	             ((volatile UINT32P)(EMI_base+0x00E8))
#define EMI_ODLB	             ((volatile UINT32P)(EMI_base+0x00F0))
#define EMI_ODLC	             ((volatile UINT32P)(EMI_base+0x00F8))
#define EMI_ODLD	             ((volatile UINT32P)(EMI_base+0x0100))
#define EMI_ODLE	             ((volatile UINT32P)(EMI_base+0x0108))
#define EMI_ODLF	             ((volatile UINT32P)(EMI_base+0x0110))

#define EMI_IOA	                 ((volatile UINT32P)(EMI_base+0x0130))
#define EMI_IOB	                 ((volatile UINT32P)(EMI_base+0x0138))

#define EMI_DSRAM	             ((volatile UINT32P)(EMI_base+0x0150))

#define EMI_ARBA                 ((volatile UINT32P)(EMI_base+0x0170))
#define EMI_ARBB                 ((volatile UINT32P)(EMI_base+0x0178))
#define EMI_ARBC                 ((volatile UINT32P)(EMI_base+0x0180))
#define EMI_SLCT                 ((volatile UINT32P)(EMI_base+0x0198))
#define EMI_ABCT	           ((volatile UINT32P)(EMI_base+0x01A0))

#define EMI_BMEN                 ((volatile UINT32P)(EMI_base+0x0200))
#define EMI_BCNT                 ((volatile UINT32P)(EMI_base+0x0208))
#define EMI_TACT                 ((volatile UINT32P)(EMI_base+0x0210))
#define EMI_TSCT                 ((volatile UINT32P)(EMI_base+0x0218))
#define EMI_WACT                 ((volatile UINT32P)(EMI_base+0x0220))
#define EMI_WSCT                 ((volatile UINT32P)(EMI_base+0x0228))
#define EMI_BACT                 ((volatile UINT32P)(EMI_base+0x0230))
#define EMI_BSCT0                ((volatile UINT32P)(EMI_base+0x0238))
#define EMI_BSCT1                ((volatile UINT32P)(EMI_base+0x0240))

#define EMI_TTYPE1               ((volatile UINT32P)(EMI_base+0x0280))


#define EMI_MBISTA               ((volatile UINT32P)(EMI_base+0x0300))
#define EMI_MBISTB               ((volatile UINT32P)(EMI_base+0x0308))
#define EMI_MBISTC               ((volatile UINT32P)(EMI_base+0x0310))
#define EMI_MBISTD               ((volatile UINT32P)(EMI_base+0x0318))

#define EMI_TEST                ((volatile UINT32P)(EMI_base+0x0330))  

#define EMI_REMAP                ((volatile UINT16P)(BOOT_ENG_base +0x0000))  /* EMI Re-map Control Register */ 

#define EMI_EFUSE           ((volatile UINT32P)0xA01C0104)

#elif defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))

#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))
#define EMI_RDCT                 ((volatile UINT32P)(EMI_base+0x0088))
#define EMI_DLLV                 ((volatile UINT32P)(EMI_base+0x0090))

#define EMI_IDLC                 ((volatile UINT32P)(EMI_base+0x00D0))
#define EMI_IDLD                 ((volatile UINT32P)(EMI_base+0x00D8))
#define EMI_IDLE                 ((volatile UINT32P)(EMI_base+0x00E0))

#define EMI_ODLC	             ((volatile UINT32P)(EMI_base+0x00F8))
#define EMI_ODLD	             ((volatile UINT32P)(EMI_base+0x0100))
#define EMI_ODLE	             ((volatile UINT32P)(EMI_base+0x0108))
#define EMI_ODLF	             ((volatile UINT32P)(EMI_base+0x0110))

#define EMI_IOA	                 ((volatile UINT32P)(EMI_base+0x0130))
#define EMI_IOB	                 ((volatile UINT32P)(EMI_base+0x0138))

#define EMI_DSRAM	             ((volatile UINT32P)(EMI_base+0x0150))
#define EMI_MSRAM	             ((volatile UINT32P)(EMI_base+0x0158))
#define EMI_MREG_RW	      ((volatile UINT32P)(EMI_base+0x0160))

#define EMI_ARBA                 ((volatile UINT32P)(EMI_base+0x0170))
#define EMI_ARBB                 ((volatile UINT32P)(EMI_base+0x0178))
#define EMI_ARBC                 ((volatile UINT32P)(EMI_base+0x0180))
#define EMI_SLCT                 ((volatile UINT32P)(EMI_base+0x0198))
#define EMI_ABCT	           ((volatile UINT32P)(EMI_base+0x01A0))

#define EMI_BMEN                 ((volatile UINT32P)(EMI_base+0x0200))
#define EMI_BCNT                 ((volatile UINT32P)(EMI_base+0x0208))
#define EMI_TACT                 ((volatile UINT32P)(EMI_base+0x0210))
#define EMI_TSCT                 ((volatile UINT32P)(EMI_base+0x0218))
#define EMI_WACT                 ((volatile UINT32P)(EMI_base+0x0220))
#define EMI_WSCT                 ((volatile UINT32P)(EMI_base+0x0228))
#define EMI_BACT                 ((volatile UINT32P)(EMI_base+0x0230))
#define EMI_BSCT0                ((volatile UINT32P)(EMI_base+0x0238))
#define EMI_BSCT1                ((volatile UINT32P)(EMI_base+0x0240))

#define EMI_TTYPE1               ((volatile UINT32P)(EMI_base+0x0280))


#define EMI_MBISTA               ((volatile UINT32P)(EMI_base+0x0300))
#define EMI_MBISTB               ((volatile UINT32P)(EMI_base+0x0308))
#define EMI_MBISTC               ((volatile UINT32P)(EMI_base+0x0310))
#define EMI_MBISTD               ((volatile UINT32P)(EMI_base+0x0318))

#define EMI_TEST                   ((volatile UINT32P)(EMI_base+0x0330))  

#define EMI_VENDOR_INFO    ((volatile UINT32P)(EMI_base+0x0348))  

#define EMI_REMAP                ((volatile UINT16P)(BOOT_ENG_base +0x0000))  /* EMI Re-map Control Register */ 

#define EMI_EFUSE           ((volatile UINT32P)0xA01C0104)

#elif defined(MT6256)  /* MT6208 */

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */

#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))  /* EMI control register for bank 0 */
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* EMI control register for bank 1 */

#define EMI_CONI                 ((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for Mobile-RAM */
#define EMI_CONJ                 ((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for Mobile-RAM */
#define EMI_CONK                 ((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for Mobile-RAM */
#define EMI_CONL                 ((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for Mobile-RAM */
#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))
#define EMI_CONN                 ((volatile UINT32P)(EMI_base+0x0068))

#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))
#define EMI_DRCT                 ((volatile UINT32P)(EMI_base+0x0078))
#define EMI_DDRV                 ((volatile UINT32P)(EMI_base+0x0080))
#define EMI_GEND                 ((volatile UINT32P)(EMI_base+0x0088))
#define EMI_PPCT                 ((volatile UINT32P)(EMI_base+0x0090))
#define EMI_MSIZ                 ((volatile UINT32P)(EMI_base+0x0098))

#define EMI_DLLV                 ((volatile UINT32P)(EMI_base+0x00A0))

#define EMI_DFTC                 ((volatile UINT32P)(EMI_base+0x00F0))
#define EMI_DFTD                 ((volatile UINT32P)(EMI_base+0x00F8))

#define EMI_ARBA                 ((volatile UINT32P)(EMI_base+0x0100))
#define EMI_ARBB                 ((volatile UINT32P)(EMI_base+0x0108))
#define EMI_ARBC                 ((volatile UINT32P)(EMI_base+0x0110))
#define EMI_ARBD                 ((volatile UINT32P)(EMI_base+0x0118))
#define EMI_ARBE                 ((volatile UINT32P)(EMI_base+0x0120))
#define EMI_ARBF                 ((volatile UINT32P)(EMI_base+0x0128))

#define EMI_SLCT                 ((volatile UINT32P)(EMI_base+0x0150))
#define EMI_ABCT	             ((volatile UINT32P)(EMI_base+0x0158))
#define EMI_IDLA                 ((volatile UINT32P)(EMI_base+0x0200))
#define EMI_IDLB                 ((volatile UINT32P)(EMI_base+0x0208))
#define EMI_IDLC                 ((volatile UINT32P)(EMI_base+0x0210))
#define EMI_IDLD                 ((volatile UINT32P)(EMI_base+0x0218)) 
#define EMI_IDLE                 ((volatile UINT32P)(EMI_base+0x0220))
#define EMI_IDLF                 ((volatile UINT32P)(EMI_base+0x0228))
#define EMI_IDLG                 ((volatile UINT32P)(EMI_base+0x0230))
#define EMI_IDLH                 ((volatile UINT32P)(EMI_base+0x0238))
#define EMI_IDLI                 ((volatile UINT32P)(EMI_base+0x0240))
#define EMI_IDLJ                 ((volatile UINT32P)(EMI_base+0x0248))
#define EMI_IDLK                 ((volatile UINT32P)(EMI_base+0x0250))

#define EMI_ODLA                 ((volatile UINT32P)(EMI_base+0x0258))
#define EMI_ODLB                 ((volatile UINT32P)(EMI_base+0x0260))
#define EMI_ODLC	             ((volatile UINT32P)(EMI_base+0x0268))
#define EMI_ODLD	             ((volatile UINT32P)(EMI_base+0x0270))
#define EMI_ODLE	             ((volatile UINT32P)(EMI_base+0x0278))
#define EMI_ODLF	             ((volatile UINT32P)(EMI_base+0x0280))
#define EMI_ODLG	             ((volatile UINT32P)(EMI_base+0x0288))
#define EMI_DUTA	             ((volatile UINT32P)(EMI_base+0x0290))
#define EMI_DUTB                 ((volatile UINT32P)(EMI_base+0x0298))
#define EMI_DUTC	             ((volatile UINT32P)(EMI_base+0x02A0))
#define EMI_DRVA                 ((volatile UINT32P)(EMI_base+0x02A8))    
#define EMI_DRVB                 ((volatile UINT32P)(EMI_base+0x02B0))    
#define EMI_IOCL                 ((volatile UINT32P)(EMI_base+0x02B8))   
#define EMI_IOCM                 ((volatile UINT32P)(EMI_base+0x02C0))   
#define EMI_IODC                 ((volatile UINT32P)(EMI_base+0x02C8))    
#define EMI_ODTA                 ((volatile UINT32P)(EMI_base+0x02D0))    
#define EMI_ODTB                 ((volatile UINT32P)(EMI_base+0x02D8)) 

#define EMI_DQSA                 ((volatile UINT32P)(EMI_base+0x0300))
#define EMI_DQSB                 ((volatile UINT32P)(EMI_base+0x0308))
#define EMI_DQSE                 ((volatile UINT32P)(EMI_base+0x0320))
#define EMI_DQSV                 ((volatile UINT32P)(EMI_base+0x0328))

#define EMI_CALA                 ((volatile UINT32P)(EMI_base+0x0330))
#define EMI_CALB                 ((volatile UINT32P)(EMI_base+0x0338))

#define EMI_CALE                 ((volatile UINT32P)(EMI_base+0x0350))
#define EMI_CALF                 ((volatile UINT32P)(EMI_base+0x0358))

#define EMI_CALI                 ((volatile UINT32P)(EMI_base+0x0370))
#define EMI_CALJ                 ((volatile UINT32P)(EMI_base+0x0378))
#define EMI_CALM                 ((volatile UINT32P)(EMI_base+0x0390))
#define EMI_CALN                 ((volatile UINT32P)(EMI_base+0x0398))
#define EMI_CALO                 ((volatile UINT32P)(EMI_base+0x03A0))
#define EMI_CALP                 ((volatile UINT32P)(EMI_base+0x03A8))

#define EMI_DUCA                 ((volatile UINT32P)(EMI_base+0x03B0))
#define EMI_DUCB                 ((volatile UINT32P)(EMI_base+0x03B8))
#define EMI_DUCC                 ((volatile UINT32P)(EMI_base+0x03C0))
#define EMI_DUCD                 ((volatile UINT32P)(EMI_base+0x03C8))
#define EMI_DUCE                 ((volatile UINT32P)(EMI_base+0x03D0))

#define EMI_BMEN                 ((volatile UINT32P)(EMI_base+0x0400))
#define EMI_BCNT                 ((volatile UINT32P)(EMI_base+0x0408))
#define EMI_TACT                 ((volatile UINT32P)(EMI_base+0x0410))
#define EMI_TSCT                 ((volatile UINT32P)(EMI_base+0x0418))
#define EMI_WACT                 ((volatile UINT32P)(EMI_base+0x0420))
#define EMI_WSCT                 ((volatile UINT32P)(EMI_base+0x0428))
#define EMI_BACT                 ((volatile UINT32P)(EMI_base+0x0430))
#define EMI_BSCT                 ((volatile UINT32P)(EMI_base+0x0438))
#define EMI_MSEL                 ((volatile UINT32P)(EMI_base+0x0440))
#define EMI_TSCT2                ((volatile UINT32P)(EMI_base+0x0448))
#define EMI_TSCT3                ((volatile UINT32P)(EMI_base+0x0450))
#define EMI_WSCT2                ((volatile UINT32P)(EMI_base+0x0458))
#define EMI_WSCT3                ((volatile UINT32P)(EMI_base+0x0460))
#define EMI_MSEL2                ((volatile UINT32P)(EMI_base+0x0468))
#define EMI_MSEL3                ((volatile UINT32P)(EMI_base+0x0470))
#define EMI_MSEL4                ((volatile UINT32P)(EMI_base+0x0478))
#define EMI_MSEL5                ((volatile UINT32P)(EMI_base+0x0480))
#define EMI_MSEL6                ((volatile UINT32P)(EMI_base+0x0488))
#define EMI_MSEL7                ((volatile UINT32P)(EMI_base+0x0490))
#define EMI_MSEL8                ((volatile UINT32P)(EMI_base+0x0498))
#define EMI_MSEL9                ((volatile UINT32P)(EMI_base+0x04A0))
#define EMI_MSEL10               ((volatile UINT32P)(EMI_base+0x04A8))
#define EMI_BMID0                ((volatile UINT32P)(EMI_base+0x04B0))
#define EMI_BMID1                ((volatile UINT32P)(EMI_base+0x04B8))
#define EMI_BMID2                ((volatile UINT32P)(EMI_base+0x04C0))
#define EMI_BMID3                ((volatile UINT32P)(EMI_base+0x04C8))
#define EMI_BMID4                ((volatile UINT32P)(EMI_base+0x04D0))
#define EMI_BMID5                ((volatile UINT32P)(EMI_base+0x04D8))
#define EMI_TTYPE1               ((volatile UINT32P)(EMI_base+0x0500))
#define EMI_TTYPE2               ((volatile UINT32P)(EMI_base+0x0508))
#define EMI_TTYPE3               ((volatile UINT32P)(EMI_base+0x0510))
#define EMI_TTYPE4               ((volatile UINT32P)(EMI_base+0x0518))
#define EMI_TTYPE5               ((volatile UINT32P)(EMI_base+0x0520))
#define EMI_TTYPE6               ((volatile UINT32P)(EMI_base+0x0528))
#define EMI_TTYPE7               ((volatile UINT32P)(EMI_base+0x0530))
#define EMI_TTYPE8               ((volatile UINT32P)(EMI_base+0x0538))
#define EMI_TTYPE9               ((volatile UINT32P)(EMI_base+0x0540))
#define EMI_TTYPE10              ((volatile UINT32P)(EMI_base+0x0548))
#define EMI_TTYPE11              ((volatile UINT32P)(EMI_base+0x0550))
#define EMI_TTYPE12              ((volatile UINT32P)(EMI_base+0x0558))
#define EMI_TTYPE13              ((volatile UINT32P)(EMI_base+0x0560))
#define EMI_TTYPE14              ((volatile UINT32P)(EMI_base+0x0568))
#define EMI_TTYPE15              ((volatile UINT32P)(EMI_base+0x0570))
#define EMI_TTYPE16              ((volatile UINT32P)(EMI_base+0x0578))
#define EMI_TTYPE17              ((volatile UINT32P)(EMI_base+0x0580))
#define EMI_TTYPE18              ((volatile UINT32P)(EMI_base+0x0588))
#define EMI_TTYPE19              ((volatile UINT32P)(EMI_base+0x0590))
#define EMI_TTYPE20              ((volatile UINT32P)(EMI_base+0x0598))
#define EMI_TTYPE21              ((volatile UINT32P)(EMI_base+0x05A0))
#define EMI_MBISTA               ((volatile UINT32P)(EMI_base+0x0600))
#define EMI_MBISTB               ((volatile UINT32P)(EMI_base+0x0608))
#define EMI_MBISTC               ((volatile UINT32P)(EMI_base+0x0610))
#define EMI_MBISTD               ((volatile UINT32P)(EMI_base+0x0618))
#define EMI_MBISTE               ((volatile UINT32P)(EMI_base+0x0620))
#define EMI_RFCA                 ((volatile UINT32P)(EMI_base+0x0630))
#define EMI_RFCB                 ((volatile UINT32P)(EMI_base+0x0638))
#define EMI_RFCC                 ((volatile UINT32P)(EMI_base+0x0640))
#define EMI_RFCD                 ((volatile UINT32P)(EMI_base+0x0648))

#define EMI_REMAP                ((volatile UINT32P)(EMI_base+0x0070))  /* EMI Re-map Control Register */

#define DRAM_TYPE_MASK		0x00070000
#define DRAM_TYPE_SDR		0x00000000
#define DRAM_TYPE_DDR		0x00020000

#elif defined(MT6255)  || defined(MT6922) /* MT6208 */

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */

#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))  /* EMI control register for bank 0 */
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* EMI control register for bank 1 */

#define EMI_CONI                 ((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for Mobile-RAM */
#define EMI_CONJ                 ((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for Mobile-RAM */
#define EMI_CONK                 ((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for Mobile-RAM */
#define EMI_CONL                 ((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for Mobile-RAM */
#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))
#define EMI_CONN                 ((volatile UINT32P)(EMI_base+0x0068))

#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))
#define EMI_DRCT                 ((volatile UINT32P)(EMI_base+0x0078))
#define EMI_DDRV                 ((volatile UINT32P)(EMI_base+0x0080))
#define EMI_GEND                 ((volatile UINT32P)(EMI_base+0x0088))
#define EMI_PPCT                 ((volatile UINT32P)(EMI_base+0x0090))

#define EMI_DLLV                 ((volatile UINT32P)(EMI_base+0x00A0))

#define EMI_DFTC                 ((volatile UINT32P)(EMI_base+0x00F0))
#define EMI_DFTD                 ((volatile UINT32P)(EMI_base+0x00F8))

#define EMI_ARBA                 ((volatile UINT32P)(EMI_base+0x0100))
#define EMI_ARBB                 ((volatile UINT32P)(EMI_base+0x0108))
#define EMI_ARBC                 ((volatile UINT32P)(EMI_base+0x0110))
#define EMI_ARBD                 ((volatile UINT32P)(EMI_base+0x0118))
#define EMI_ARBE                 ((volatile UINT32P)(EMI_base+0x0120))

#define EMI_SLCT                 ((volatile UINT32P)(EMI_base+0x0150))
#define EMI_ABCT	             ((volatile UINT32P)(EMI_base+0x0158))
 
#define EMI_IDLE                 ((volatile UINT32P)(EMI_base+0x0220))
#define EMI_IDLF                 ((volatile UINT32P)(EMI_base+0x0228))
#define EMI_IDLG                 ((volatile UINT32P)(EMI_base+0x0230))
#define EMI_IDLH                 ((volatile UINT32P)(EMI_base+0x0238))
#define EMI_IDLI                 ((volatile UINT32P)(EMI_base+0x0240))
#define EMI_IDLJ                 ((volatile UINT32P)(EMI_base+0x0248))
#define EMI_IDLK                 ((volatile UINT32P)(EMI_base+0x0250))

#define EMI_ODLC	             ((volatile UINT32P)(EMI_base+0x0268))
#define EMI_ODLD	             ((volatile UINT32P)(EMI_base+0x0270))
#define EMI_ODLE	             ((volatile UINT32P)(EMI_base+0x0278))
#define EMI_ODLG	             ((volatile UINT32P)(EMI_base+0x0288))
#define EMI_DUTA	             ((volatile UINT32P)(EMI_base+0x0290))
#define EMI_DUTB                 ((volatile UINT32P)(EMI_base+0x0298))
//#define EMI_DUTC	             ((volatile UINT32P)(EMI_base+0x02A0))
#define EMI_DRVA                 ((volatile UINT32P)(EMI_base+0x02A8))    
#define EMI_DRVB                 ((volatile UINT32P)(EMI_base+0x02B0))    
#define EMI_IOCL                 ((volatile UINT32P)(EMI_base+0x02B8))   
#define EMI_IOCM                 ((volatile UINT32P)(EMI_base+0x02C0))   

#define EMI_DQSA                 ((volatile UINT32P)(EMI_base+0x0300))
#define EMI_DQSB                 ((volatile UINT32P)(EMI_base+0x0308))
#define EMI_DQSE                 ((volatile UINT32P)(EMI_base+0x0320))
#define EMI_DQSV                 ((volatile UINT32P)(EMI_base+0x0328))

#define EMI_CALA                 ((volatile UINT32P)(EMI_base+0x0330))
#define EMI_CALB                 ((volatile UINT32P)(EMI_base+0x0338))

#define EMI_CALE                 ((volatile UINT32P)(EMI_base+0x0350))
#define EMI_CALF                 ((volatile UINT32P)(EMI_base+0x0358))

#define EMI_CALI                 ((volatile UINT32P)(EMI_base+0x0370))
#define EMI_CALJ                 ((volatile UINT32P)(EMI_base+0x0378))
#define EMI_CALM                 ((volatile UINT32P)(EMI_base+0x0390))
#define EMI_CALN                 ((volatile UINT32P)(EMI_base+0x0398))
#define EMI_CALO                 ((volatile UINT32P)(EMI_base+0x03A0))
#define EMI_CALP                 ((volatile UINT32P)(EMI_base+0x03A8))

#define EMI_DUCA                 ((volatile UINT32P)(EMI_base+0x03B0))
#define EMI_DUCB                 ((volatile UINT32P)(EMI_base+0x03B8))
#define EMI_DUCC                 ((volatile UINT32P)(EMI_base+0x03C0))
#define EMI_DUCD                 ((volatile UINT32P)(EMI_base+0x03C8))
#define EMI_DUCE                 ((volatile UINT32P)(EMI_base+0x03D0))

#define EMI_BMEN                 ((volatile UINT32P)(EMI_base+0x0400))
#define EMI_BCNT                 ((volatile UINT32P)(EMI_base+0x0408))
#define EMI_TACT                 ((volatile UINT32P)(EMI_base+0x0410))
#define EMI_TSCT                 ((volatile UINT32P)(EMI_base+0x0418))
#define EMI_WACT                 ((volatile UINT32P)(EMI_base+0x0420))
#define EMI_WSCT                 ((volatile UINT32P)(EMI_base+0x0428))
#define EMI_BACT                 ((volatile UINT32P)(EMI_base+0x0430))
#define EMI_BSCT                 ((volatile UINT32P)(EMI_base+0x0438))
#define EMI_MSEL                 ((volatile UINT32P)(EMI_base+0x0440))
#define EMI_TSCT2                ((volatile UINT32P)(EMI_base+0x0448))
#define EMI_TSCT3                ((volatile UINT32P)(EMI_base+0x0450))
#define EMI_WSCT2                ((volatile UINT32P)(EMI_base+0x0458))
#define EMI_WSCT3                ((volatile UINT32P)(EMI_base+0x0460))
#define EMI_MSEL2                ((volatile UINT32P)(EMI_base+0x0468))
#define EMI_MSEL3                ((volatile UINT32P)(EMI_base+0x0470))
#define EMI_BSCT2                ((volatile UINT32P)(EMI_base+0x05A8)) 

#define EMI_BSCT3                ((volatile UINT32P)(EMI_base+0x05B0)) 

//#define EMI_MSEL4                ((volatile UINT32P)(EMI_base+0x0478))
//#define EMI_MSEL5                ((volatile UINT32P)(EMI_base+0x0480))
//#define EMI_MSEL6                ((volatile UINT32P)(EMI_base+0x0488))
//#define EMI_MSEL7                ((volatile UINT32P)(EMI_base+0x0490))
//#define EMI_MSEL8                ((volatile UINT32P)(EMI_base+0x0498))
//#define EMI_MSEL9                ((volatile UINT32P)(EMI_base+0x04A0))
//#define EMI_MSEL10               ((volatile UINT32P)(EMI_base+0x04A8))
//#define EMI_BMID0                ((volatile UINT32P)(EMI_base+0x04B0))
//#define EMI_BMID1                ((volatile UINT32P)(EMI_base+0x04B8))
//#define EMI_BMID2                ((volatile UINT32P)(EMI_base+0x04C0))
//#define EMI_BMID3                ((volatile UINT32P)(EMI_base+0x04C8))
//#define EMI_BMID4                ((volatile UINT32P)(EMI_base+0x04D0))
//#define EMI_BMID5                ((volatile UINT32P)(EMI_base+0x04D8))
//#define EMI_TTYPE1               ((volatile UINT32P)(EMI_base+0x0500))
//#define EMI_TTYPE2               ((volatile UINT32P)(EMI_base+0x0508))
//#define EMI_TTYPE3               ((volatile UINT32P)(EMI_base+0x0510))
//#define EMI_TTYPE4               ((volatile UINT32P)(EMI_base+0x0518))
//#define EMI_TTYPE5               ((volatile UINT32P)(EMI_base+0x0520))
//#define EMI_TTYPE6               ((volatile UINT32P)(EMI_base+0x0528))
//#define EMI_TTYPE7               ((volatile UINT32P)(EMI_base+0x0530))
//#define EMI_TTYPE8               ((volatile UINT32P)(EMI_base+0x0538))
//#define EMI_TTYPE9               ((volatile UINT32P)(EMI_base+0x0540))
//#define EMI_TTYPE10              ((volatile UINT32P)(EMI_base+0x0548))
//#define EMI_TTYPE11              ((volatile UINT32P)(EMI_base+0x0550))
//#define EMI_TTYPE12              ((volatile UINT32P)(EMI_base+0x0558))
//#define EMI_TTYPE13              ((volatile UINT32P)(EMI_base+0x0560))
//#define EMI_TTYPE14              ((volatile UINT32P)(EMI_base+0x0568))
//#define EMI_TTYPE15              ((volatile UINT32P)(EMI_base+0x0570))
//#define EMI_TTYPE16              ((volatile UINT32P)(EMI_base+0x0578))
//#define EMI_TTYPE17              ((volatile UINT32P)(EMI_base+0x0580))
//#define EMI_TTYPE18              ((volatile UINT32P)(EMI_base+0x0588))
//#define EMI_TTYPE19              ((volatile UINT32P)(EMI_base+0x0590))
//#define EMI_TTYPE20              ((volatile UINT32P)(EMI_base+0x0598))
//#define EMI_TTYPE21              ((volatile UINT32P)(EMI_base+0x05A0))

#define EMI_MBISTA               ((volatile UINT32P)(EMI_base+0x0600))
#define EMI_MBISTB               ((volatile UINT32P)(EMI_base+0x0608))
#define EMI_MBISTC               ((volatile UINT32P)(EMI_base+0x0610))
#define EMI_MBISTD               ((volatile UINT32P)(EMI_base+0x0618))
#define EMI_MBISTE               ((volatile UINT32P)(EMI_base+0x0620))

#define EMI_RFCA                 ((volatile UINT32P)(EMI_base+0x0630))
#define EMI_RFCB                 ((volatile UINT32P)(EMI_base+0x0638))
#define EMI_RFCC                 ((volatile UINT32P)(EMI_base+0x0640))
//#define EMI_RFCD                 ((volatile UINT32P)(EMI_base+0x0648))

#define EMI_REMAP                ((volatile UINT32P)(EMI_base+0x0070))  /* EMI Re-map Control Register */

#define EMI_EFUSE           ((volatile UINT32P)0x801C0104)  
#define DRAM_TYPE_MASK		0x00070000
#define DRAM_TYPE_SDR		0x00000000
#define DRAM_TYPE_DDR		0x00020000

#elif defined(MT6516)  /* MT6208 */

#if !defined(__SMART_PHONE_MODEM__)

/**
  * Define MD to AP backdoor access 
  */
#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0010))  /* EMI control register for bank 2 */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x0018))  /* EMI control register for bank 3 */
#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))
#define EMI_CONG                 ((volatile UINT32P)(EMI_base+0x0030))
#define EMI_CONH                 ((volatile UINT32P)(EMI_base+0x0038))
#define EMI_CONI                 ((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for MR/EMR */
#define EMI_CONJ                 ((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for DRAM Controller timing configuration 1. */
#define EMI_CONK                 ((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for DRAM Controller timing configuration 2. */
#define EMI_CONL                 ((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for DRAM Controller read data path configuration. */
#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))  /* EMI control register 3 for DRAM Controller read delay timing configuration. */
#define EMI_CONN                 ((volatile UINT32P)(EMI_base+0x0068))  /* EMI control register 3 for DRAM Controller function configuration. */
#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))  /* EMI General Control Register 0 */
#define EMI_GENB                 ((volatile UINT32P)(EMI_base+0x0078))  /* EMI General Control Register 1 */
#define EMI_GENC                 ((volatile UINT32P)(EMI_base+0x0080))  /* EMI General Control Register 2 */
#define EMI_GEND                 ((volatile UINT32P)(EMI_base+0x0088))  /* EMI General Control Register 3 */
#define EMI_GENE                 ((volatile UINT32P)(EMI_base+0x0090))  /* EMI General Control Register 3 */

#define EMI_REMAP                ((volatile UINT32P)(EMI_base+0x0070))  /* EMI Re-map Control Register */

#define EMI_DQSA                 ((volatile UINT32P)(EMI_base+0x01B0))  /* DQSI auto-tracking control for CS[0] */
#define EMI_DQSB                 ((volatile UINT32P)(EMI_base+0x01B8))  /* DQSI auto-tracking control for CS[0] */
#define EMI_DQSC                 ((volatile UINT32P)(EMI_base+0x01C0))  /* DQSI auto-tracking control for CS[0] */
#define EMI_DQSD                 ((volatile UINT32P)(EMI_base+0x01C8))  /* DQSI auto-tracking control for CS[0] */
#define EMI_DQSV                 ((volatile UINT32P)(EMI_base+0x01D0))  /* DQSI auto-tracking calibrating delay value */

#endif /* !__SMART_PHONE_MODEM__ */

#define EMI_MPUL                 ((volatile UINT32P)(MD_ONLY_EMI_BASE+0x0140))
#define EMI_MPUO                 ((volatile UINT32P)(MD_ONLY_EMI_BASE+0x0158))

#elif defined(TK6516)  /* MT6208 */

/**
  * No TK6516's definition.
  */

#elif defined(MT6270A)   /* MT6208 */


#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0010))  /* EMI control register for bank 2 */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x0018))  /* EMI control register for bank 3 */

#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))  /* EMI control register for bank 3 */
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* EMI control register for bank 3 */
#define EMI_CONG                 ((volatile UINT32P)(EMI_base+0x0030))  /* EMI control register for bank 3 */
#define EMI_CONH                 ((volatile UINT32P)(EMI_base+0x0038))  /* EMI control register for bank 3 */

#define EMI_CONI                 ((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for MR/EMR */
#define EMI_CONJ                 ((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for DRAM Controller timing configuration 1. */
#define EMI_CONK                 ((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for DRAM Controller timing configuration 2. */
#define EMI_CONL                 ((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for DRAM Controller read data path configuration. */
#define EMI_CONM                 ((volatile UINT32P)(EMI_base+0x0060))  /* EMI control register 3 for DRAM Controller read delay timing configuration. */
#define EMI_CONN                 ((volatile UINT32P)(EMI_base+0x0068))  /* EMI control register 3 for DRAM Controller function configuration. */

#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0070))  /* EMI General Control Register 0 */
#define EMI_GENB                 ((volatile UINT32P)(EMI_base+0x0078))  /* EMI General Control Register 1 */
#define EMI_GENC                 ((volatile UINT32P)(EMI_base+0x0080))  /* EMI General Control Register 2 */
#define EMI_GEND                 ((volatile UINT32P)(EMI_base+0x0088))  /* EMI General Control Register 3 */
#define EMI_GENE                 ((volatile UINT32P)(EMI_base+0x0090))  /* EMI General Control Register 3 */

#define EMI_DELA                 ((volatile UINT32P)(EMI_base+0x0098))  /* EMI Delay Control Register 0 */
#define EMI_DELB                 ((volatile UINT32P)(EMI_base+0x00A0))  /* EMI Delay Control Register 1 */
#define EMI_DELC                 ((volatile UINT32P)(EMI_base+0x00A8))  /* EMI Delay Control Register 2 */
#define EMI_DELD                 ((volatile UINT32P)(EMI_base+0x00B0))  /* EMI Delay Control Register 3 */
#define EMI_DELE                 ((volatile UINT32P)(EMI_base+0x00B8))  /* EMI Delay Control Register 4 */
#define EMI_DELF                 ((volatile UINT32P)(EMI_base+0x00C0))  /* EMI Delay Control Register 5 */
#define EMI_DELG                 ((volatile UINT32P)(EMI_base+0x00C8))  /* EMI Delay Control Register 6 */
#define EMI_DELH                 ((volatile UINT32P)(EMI_base+0x00D0))  /* EMI Delay Control Register 7 */
#define EMI_DELI                 ((volatile UINT32P)(EMI_base+0x00D8))  /* EMI Delay Control Register 8 */
#define EMI_DELJ                 ((volatile UINT32P)(EMI_base+0x00E0))  /* EMI Delay Control Register 9 */


#define EMI_DQSA                 ((volatile UINT32P)(EMI_base+0x01B0))  /* EMI DQS Auto Tracking Control Register 0 */
#define EMI_DQSB                 ((volatile UINT32P)(EMI_base+0x01B8))  /* EMI DQS Auto Tracking Control Register 1 */
#define EMI_DQSC                 ((volatile UINT32P)(EMI_base+0x01C0))  /* EMI DQS Auto Tracking Control Register 2 */
#define EMI_DQSD                 ((volatile UINT32P)(EMI_base+0x01C8))  /* EMI DQS Auto Tracking Control Register 3 */

#define EMI_ARBA                 ((volatile UINT32P)(EMI_base+0x0200))  /* EMI Bandwidth Filter Control M0 */
#define EMI_ARBB                 ((volatile UINT32P)(EMI_base+0x0208))  /* EMI Bandwidth Filter Control M1 */
#define EMI_ARBC                 ((volatile UINT32P)(EMI_base+0x0210))  /* EMI Bandwidth Filter Control M2 */
#define EMI_ARBD                 ((volatile UINT32P)(EMI_base+0x0218))  /* EMI Bandwidth Filter Control M3 */
#define EMI_ARBE                 ((volatile UINT32P)(EMI_base+0x0220))  /* EMI Bandwidth Filter Control M4 */
#define EMI_ARBF                 ((volatile UINT32P)(EMI_base+0x0228))  /* EMI Bandwidth Filter Control M5 */
#define EMI_ARBG                 ((volatile UINT32P)(EMI_base+0x0230))  /* EMI Bandwidth Filter Control M6 */
#define EMI_ARBH                 ((volatile UINT32P)(EMI_base+0x0238))  /* EMI Bandwidth Filter Control GMC0 */
#define EMI_ARBI                 ((volatile UINT32P)(EMI_base+0x0240))  /* EMI Bandwidth Filter Control GMC1 */

#define EMI_RDCT                 ((volatile UINT32P)(EMI_base+0x02B0))  /* EMI SDR Auto Tracking Control Register */
#define EMI_RWDL                 ((volatile UINT32P)(EMI_base+0x02B8))  /* EMI SDR Auto Tracking Windows Delay */
#define EMI_RTDL                 ((volatile UINT32P)(EMI_base+0x02C0))  /* EMI SDR Auto Tracking Path Delay */
#define EMI_RWCL                 ((volatile UINT32P)(EMI_base+0x02C8))  /* EMI SDR Auto Tracking Windows Value */
#define EMI_RTCL                 ((volatile UINT32P)(EMI_base+0x02D0))  /* EMI SDR Auto Tracking Delay Value */

#define EMI_REMAP                ((volatile UINT32P)(EMI_base+0x0070))  /* EMI Re-map Control Register */

#define EMI_DRCT                 ((volatile UINT32P)(EMI_base+0x01A0))  /* EMI Dummy-read Control Register */

#define DRAM_TYPE_MASK		0x00070000
#define DRAM_TYPE_SDR		0x00000000
#define DRAM_TYPE_DDR		0x00020000



#define AP_EMI_CONA                 ((volatile UINT32P)(AP_EMI_base+0x0000))  /* EMI control register for bank 0 */
#define AP_EMI_CONB                 ((volatile UINT32P)(AP_EMI_base+0x0008))  /* EMI control register for bank 1 */
#define AP_EMI_CONC                 ((volatile UINT32P)(AP_EMI_base+0x0010))  /* EMI control register for bank 2 */
#define AP_EMI_COND                 ((volatile UINT32P)(AP_EMI_base+0x0018))  /* EMI control register for bank 3 */

#define AP_EMI_CONE                 ((volatile UINT32P)(AP_EMI_base+0x0020))  /* EMI control register for bank 3 */
#define AP_EMI_CONF                 ((volatile UINT32P)(AP_EMI_base+0x0028))  /* EMI control register for bank 3 */
#define AP_EMI_CONG                 ((volatile UINT32P)(AP_EMI_base+0x0030))  /* EMI control register for bank 3 */
#define AP_EMI_CONH                 ((volatile UINT32P)(AP_EMI_base+0x0038))  /* EMI control register for bank 3 */

#define AP_EMI_CONI                 ((volatile UINT32P)(AP_EMI_base+0x0040))  /* EMI control register 0 for MR/EMR */
#define AP_EMI_CONJ                 ((volatile UINT32P)(AP_EMI_base+0x0048))  /* EMI control register 1 for DRAM Controller timing configuration 1. */
#define AP_EMI_CONK                 ((volatile UINT32P)(AP_EMI_base+0x0050))  /* EMI control register 2 for DRAM Controller timing configuration 2. */
#define AP_EMI_CONL                 ((volatile UINT32P)(AP_EMI_base+0x0058))  /* EMI control register 3 for DRAM Controller read data path configuration. */
#define AP_EMI_CONM                 ((volatile UINT32P)(AP_EMI_base+0x0060))  /* EMI control register 3 for DRAM Controller read delay timing configuration. */
#define AP_EMI_CONN                 ((volatile UINT32P)(AP_EMI_base+0x0068))  /* EMI control register 3 for DRAM Controller function configuration. */

#define AP_EMI_GENA                 ((volatile UINT32P)(AP_EMI_base+0x0070))  /* EMI General Control Register 0 */
#define AP_EMI_GENB                 ((volatile UINT32P)(AP_EMI_base+0x0078))  /* EMI General Control Register 1 */
#define AP_EMI_GENC                 ((volatile UINT32P)(AP_EMI_base+0x0080))  /* EMI General Control Register 2 */
#define AP_EMI_GEND                 ((volatile UINT32P)(AP_EMI_base+0x0088))  /* EMI General Control Register 3 */
#define AP_EMI_GENE                 ((volatile UINT32P)(AP_EMI_base+0x0090))  /* EMI General Control Register 3 */

#define AP_EMI_DELA                 ((volatile UINT32P)(AP_EMI_base+0x0098))  /* EMI Delay Control Register 0 */
#define AP_EMI_DELB                 ((volatile UINT32P)(AP_EMI_base+0x00A0))  /* EMI Delay Control Register 1 */
#define AP_EMI_DELC                 ((volatile UINT32P)(AP_EMI_base+0x00A8))  /* EMI Delay Control Register 2 */
#define AP_EMI_DELD                 ((volatile UINT32P)(AP_EMI_base+0x00B0))  /* EMI Delay Control Register 3 */
#define AP_EMI_DELE                 ((volatile UINT32P)(AP_EMI_base+0x00B8))  /* EMI Delay Control Register 4 */
#define AP_EMI_DELF                 ((volatile UINT32P)(AP_EMI_base+0x00C0))  /* EMI Delay Control Register 5 */
#define AP_EMI_DELG                 ((volatile UINT32P)(AP_EMI_base+0x00C8))  /* EMI Delay Control Register 6 */
#define AP_EMI_DELH                 ((volatile UINT32P)(AP_EMI_base+0x00D0))  /* EMI Delay Control Register 7 */
#define AP_EMI_DELI                 ((volatile UINT32P)(AP_EMI_base+0x00D8))  /* EMI Delay Control Register 8 */
#define AP_EMI_DELJ                 ((volatile UINT32P)(AP_EMI_base+0x00E0))  /* EMI Delay Control Register 9 */


#define AP_EMI_DQSA                 ((volatile UINT32P)(AP_EMI_base+0x01B0))  /* EMI DQS Auto Tracking Control Register 0 */
#define AP_EMI_DQSB                 ((volatile UINT32P)(AP_EMI_base+0x01B8))  /* EMI DQS Auto Tracking Control Register 1 */
#define AP_EMI_DQSC                 ((volatile UINT32P)(AP_EMI_base+0x01C0))  /* EMI DQS Auto Tracking Control Register 2 */
#define AP_EMI_DQSD                 ((volatile UINT32P)(AP_EMI_base+0x01C8))  /* EMI DQS Auto Tracking Control Register 3 */

#define AP_EMI_ARBA                 ((volatile UINT32P)(AP_EMI_base+0x0200))  /* EMI Bandwidth Filter Control M0 */
#define AP_EMI_ARBB                 ((volatile UINT32P)(AP_EMI_base+0x0208))  /* EMI Bandwidth Filter Control M1 */
#define AP_EMI_ARBC                 ((volatile UINT32P)(AP_EMI_base+0x0210))  /* EMI Bandwidth Filter Control M2 */
#define AP_EMI_ARBD                 ((volatile UINT32P)(AP_EMI_base+0x0218))  /* EMI Bandwidth Filter Control M3 */
#define AP_EMI_ARBE                 ((volatile UINT32P)(AP_EMI_base+0x0220))  /* EMI Bandwidth Filter Control M4 */
#define AP_EMI_ARBF                 ((volatile UINT32P)(AP_EMI_base+0x0228))  /* EMI Bandwidth Filter Control M5 */
#define AP_EMI_ARBG                 ((volatile UINT32P)(AP_EMI_base+0x0230))  /* EMI Bandwidth Filter Control M6 */
#define AP_EMI_ARBH                 ((volatile UINT32P)(AP_EMI_base+0x0238))  /* EMI Bandwidth Filter Control GMC0 */
#define AP_EMI_ARBI                 ((volatile UINT32P)(AP_EMI_base+0x0240))  /* EMI Bandwidth Filter Control GMC1 */

#define AP_EMI_RDCT                 ((volatile UINT32P)(AP_EMI_base+0x02B0))  /* EMI SDR Auto Tracking Control Register */
#define AP_EMI_RWDL                 ((volatile UINT32P)(AP_EMI_base+0x02B8))  /* EMI SDR Auto Tracking Windows Delay */
#define AP_EMI_RTDL                 ((volatile UINT32P)(AP_EMI_base+0x02C0))  /* EMI SDR Auto Tracking Path Delay */
#define AP_EMI_RWCL                 ((volatile UINT32P)(AP_EMI_base+0x02C8))  /* EMI SDR Auto Tracking Windows Value */
#define AP_EMI_RTCL                 ((volatile UINT32P)(AP_EMI_base+0x02D0))  /* EMI SDR Auto Tracking Delay Value */

#define AP_EMI_REMAP                ((volatile UINT32P)(AP_EMI_base+0x0070))  /* EMI Re-map Control Register */

#define AP_EMI_DRCT                 ((volatile UINT32P)(AP_EMI_base+0x01A0))  /* EMI Dummy-read Control Register */

#define DRAM_TYPE_MASK		0x00070000
#define DRAM_TYPE_SDR		0x00000000
#define DRAM_TYPE_DDR		0x00020000


#else   /* MT6208 */

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* Bank 0 configuration */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* Bank 1 configuration */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0010))  /* Bank 2 configuration */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x0018))  /* Bank 3 configuration */
#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))  /* Bank 4 configuration */
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* Bank 5 configuration */
#define EMI_CONG                 ((volatile UINT32P)(EMI_base+0x0030))  /* Bank 6 configuration */
#define EMI_CONH                 ((volatile UINT32P)(EMI_base+0x0038))  /* Bank 7 configuration */
#define EMI_REMAP                ((volatile UINT16P)(EMI_base+0x0040))  /* EMI Re-map Control Register */
#define EMI_GEN                  ((volatile UINT32P)(EMI_base+0x0044))  /* EMI General Control Register */
#define PREFETCH_CON             ((volatile UINT32P)(EMI_base+0x0050))  /* Code Cache and Code Prefetch Control Register */

#if defined(MT6223) || defined(MT6223P)
#define EMI_ADMUX                ((volatile UINT32P)(EMI_base+0x0078))  /* ADMUX Control Register */
#endif  /* MT6223  || MT6223P*/

#endif   /* MT6208 */


#endif  /* !__EMI_HW_INTERNAL_H__ */

