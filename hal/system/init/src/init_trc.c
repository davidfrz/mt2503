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
 *   init_trc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines bootup trace functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "custom_util.h"
#include "drvpdn.h"


/*******************************************************************************
 * Define global data
 *******************************************************************************/


/*******************************************************************************
 * Declare import data
 *******************************************************************************/
extern boot_mode_type system_boot_mode;


/*******************************************************************************
 * Declare function prototype 

 *******************************************************************************/

/*******************************************************************************
 * Declare import function prototype 
 *******************************************************************************/
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
#if defined(__USB_BOOTUP_TRACE__)
extern void USB_Boot_Trace_Init(void);
extern kal_int32 custom_usb_comport_setup_delay(void);
#else /* __USB_BOOTUP_TRACE__ */
extern void UART_Bootup_Init(void);
extern void Seriport_Driver_Boot_Trace_Init(void);//want bootup trace,but VFIFO maybe not ready,so close vfifo and init uart1 driver
#endif /* __USB_BOOTUP_TRACE__ */
#endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */
#if defined(__DUAL_TALK_MODEM_SUPPORT__) && defined(__KAL_RECORD_BOOTUP_LOG__)
extern void dbg_print_bootup_trace(char *fmt,...);
#endif  

#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
/*************************************************************************
* FUNCTION
*  INT_setInitLogFlag
*
* DESCRIPTION
*  This function is used to set init flag for tst, which will use the flag to determine whether
*  the system is at init. stage or not.
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
void INT_setInitLogFlag(void)
{
    is_init_stage = KAL_TRUE;
#if defined(__KAL_RECORD_BOOTUP_LOG__)
    is_init_log_enable = KAL_TRUE;
#else
       
    custom_InitKeypadGPIO();
    
    if(custom_IsBootupTraceKeyPressed())
    {
        is_init_log_enable = KAL_TRUE;
    }
    else
    {
        is_init_log_enable = KAL_FALSE;
    }
#endif    
}

/*************************************************************************
* FUNCTION
*  INT_InitBootupTrace
*
* DESCRIPTION
*  This function is used to init bootup trace driver.
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
void INT_InitBootupTrace(void)
{
#if defined(__USB_BOOTUP_TRACE__)
    INT_setInitLogFlag();
    if (is_init_log_enable == KAL_TRUE)
    {
        lpwr_init();
        DRVPDN_ini();
        DMA_Ini();
        USB_Boot_Trace_Init();
        #if !defined(__TINY_SYS__)
        //Tiny system use DTR to sync with catcher tool
        custom_usb_comport_setup_delay();
        #endif
    }
#else /* __USB_BOOTUP_TRACE__ */
    /* init uart baudrate (HW related) */
    UART_Bootup_Init();
    INT_setInitLogFlag();
#endif /* __USB_BOOTUP_TRACE__ */
}

/*************************************************************************
* FUNCTION
*  INT_printBootMode
*
* DESCRIPTION
*  This function is used to print out current boot-up mode.
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void INT_printBootMode(void)
{
    kal_char buff[40];

#if defined(__FACTORY_BIN__)
    sprintf(buff, "Supported Boot mode: META only");
#else

#if defined(__SPLIT_BINARY__)
    sprintf(buff, "Supported Boot mode: MAUI only");
#else
    sprintf(buff, "Supported Boot mode: ALL");
#endif /* __SPLIT_BINARY__ */
    
#endif /* __FACTORY_BIN__ */

#if defined(__DUAL_TALK_MODEM_SUPPORT__) && defined(__KAL_RECORD_BOOTUP_LOG__)
	  strcat(buff, "\n");
	  if(is_init_stage == KAL_TRUE) {
	      dbg_print_bootup_trace(buff);
	  }
#else
    kal_bootup_print(buff);
#endif //(__DUAL_TALK_MODEM_SUPPORT__) && defined(__KAL_RECORD_BOOTUP_LOG__)

    memset(buff, 0x0, sizeof(buff));
    sprintf(buff, "Boot mode: ");
    switch(system_boot_mode) {
        case FACTORY_BOOT:
	     strcat(buff, "FACTORY");
	 break;
	   
        case NORMAL_BOOT:
	     strcat(buff, "NORMAL");		  	
	 break;
	   
	 case USBMS_BOOT:
	     strcat(buff, "USB");	
	 break;
	   
	 case FUE_BOOT:
	     strcat(buff, "FUE");
	 break;
	   
	 default:
	     strcat(buff, "UNKNOWN");	 	
        break;
    }
    
#if defined(__DUAL_TALK_MODEM_SUPPORT__) && defined(__KAL_RECORD_BOOTUP_LOG__)
	  strcat(buff, "\n");
	  if(is_init_stage == KAL_TRUE) {
	      dbg_print_bootup_trace(buff);
	  }
#else
    kal_bootup_print(buff);
#endif //(__DUAL_TALK_MODEM_SUPPORT__) && defined(__KAL_RECORD_BOOTUP_LOG__)
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */
