/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer).
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
 *============================================================================
 ****************************************************************************/

#ifndef __DCL_H__
#define __DCL_H__



typedef char              DCL_CHAR;
typedef signed char       DCL_INT8;
typedef signed short      DCL_INT16;
typedef signed long       DCL_INT32;

typedef unsigned char      DCL_UCHAR;
typedef unsigned char      DCL_UINT8;
typedef unsigned short     DCL_UINT16;
typedef unsigned long      DCL_UINT32;

#if !defined(GEN_FOR_PC) && !defined(__MTK_TARGET__)
   typedef signed __int64    DCL_INT64;
typedef unsigned __int64   DCL_UINT64;
#else
   typedef unsigned long long   DCL_UINT64;
   typedef signed long long     DCL_INT64;
#endif

typedef double             DCL_DOUBLE;

typedef int DCL_BOOL;
typedef enum
{
   DCL_FALSE = 0,
   DCL_TRUE
}DCL_BOOLEAN;

#define	DCL_DEFINITION_STRUCT
#include "dcl_gpt.h"
#include "dcl_gpio.h"
#include "dcl_uart.h"
#include "dcl_wdt.h"
#include "dcl_adc.h"
#include "dcl_bmt.h"
#include "dcl_pfc.h"
#include "dcl_rtc.h"
#include "dcl_i2c.h"
#include "dcl_aux.h"
#include "dcl_pwm.h"
#include "dclH_kbd.h"
#include "dclS_kbd.h"
#include "dcl_sts.h"
#include "dcl_msdc.h"
#include "dcl_usb_drv.h"
#include "dcl_usb_hcd.h"
#include "dcl_otg_drv.h"
#include "dcl_irda.h"
#include "dcl_sim.h"
#include "dcl_pmu.h"
#include "dcl_pw.h"
#include "dcl_chr_det.h"
#include "dcl_pxs.h"
#include "dcl_f32k_clk.h"
#include "dcl_eint.h"
#include "dcl_spi_slave.h"

/*******************************************************************************
 * DCL_STATUS 
 *******************************************************************************/
#if defined(STATUS_OK)
#undef STATUS_OK
#endif

#if defined(STATUS_FAIL)
#undef STATUS_FAIL  
#endif  

typedef DCL_INT32 DCL_STATUS;
typedef enum
{
   STATUS_OK = 0,
   STATUS_FAIL = -1,
   STATUS_INVALID_CMD = -2,
   STATUS_UNSUPPORTED = -3,
   STATUS_NOT_OPENED = -4,
   STATUS_INVALID_EVENT = -5,
   STATUS_INVALID_DCL_HANDLE = -6,
   STATUS_INVALID_CTRL_DATA = -7,
   STATUS_INVALID_CONFIGURATION = -8,
   STATUS_INVALID_ARGUMENT = -9,
   STATUS_ERROR_TIMEOUT = -10,
   STATUS_ERROR_CRCERROR = -11,
   STATUS_ERROR_READONLY = -12,
   STATUS_ERROR_WRONG_STATE = -13,
   STATUS_INVALID_DEVICE = -14,
   STATUS_ALREADY_OPENED = -15,
   STATUS_SET_VFIFO_FAIL = -16,
   STATUS_INVALID_OPERATION = -17,
   STATUS_DEVICE_NOT_EXIST = -18,

   //*/ I2C DCL added /*//
   STATUS_DEVICE_NOT_SUPPORT_DMA = -19,
   STATUS_DEVICE_IS_BUSY = -20,
   STATUS_ACKERR = -21, 
   STATUS_HS_NACKERR = -22,

   STATUS_BUFFER_EMPTY = 1
} DCL_STATUS_T;

/*******************************************************************************
 * DCL_DEV
 *******************************************************************************/
typedef DCL_UINT16 DCL_DEV;
typedef enum
{
   DCL_UART_GROUP_START = 0,
   DCL_UART_DEV // Marco defined in dcl_uart.h
   DCL_I2C_GROUP_START = 0x100,
   DCL_I2C,
   DCL_I2C2,
   DCL_SPI_GROUP_START = 0x200,
   DCL_SPI,
   DCL_ADC_GROUP_START = 0x300,
   DCL_ADC,
   DCL_GPIO_GROUP_START = 0x400,
   DCL_GPIO,
   DCL_GPO,
   DCL_GPIO_CLK,
   DCL_PWM_GROUP_START = 0x500,
   DCL_PWM1,
   DCL_PWM2,
   DCL_PWM3,
   DCL_PWM4,
   DCL_PWM5,
   DCL_PWM6,
   DCL_SDIO_GROUP_START = 0x600,
   DCL_SDIO,   
   DCL_GPT_GROUP_START = 0x700,
   DCL_GPT_CB,
   DCL_GPT_BusyWait,
   DCL_GPT_FreeRUN3,
   DCL_GPT_FreeRUN4,
   DCL_XGPT,  
   DCL_BMT_GROUP_START = 0x800,
   DCL_BMT,
   DCL_PFC_GROUP_START = 0x900,
   DCL_PFC,
   DCL_RTC_GROUP_START = 0xA00,
   DCL_RTC,   
   DCL_PMU_GROUP_START = 0xB00,
   DCL_PMU,
   DCL_PW_GROUP_START = 0xC00,
   DCL_PW,
   DCL_CHR_USB_DET_GROUP_START = 0xD00,
   DCL_CHR_USB_DET,
   DCL_ALERTER_GROUP_START = 0xE00,
   DCL_ALERTER,
   DCL_KBD_GROUP_START = 0xF00,
   DCL_KBD,
   DCL_TS_GROUP_START = 0x1000,
   DCL_TS,   
   DCL_AUX_GROUP_START = 0x1100,
   DCL_AUX,
   DCL_WDT_GROUP_START = 0x1200,
   DCL_WDT,
   DCL_IRDA_GROUP_START = 0x1300,
   DCL_IRDA,
   DCL_USB_GROUP_START = 0x1400,
   DCL_USB,
   DCL_SIM_GROUP_START = 0x1500,
   DCL_SIM,
   DCL_SD_GROUP_START = 0x1600,
   DCL_SD,
   DCL_MS_GROUP_START = 0x1700,
   DCL_MS,   
   DCL_ONEW_GROUP_START = 0x1800,
   DCL_ONEW, //1-wire
   DCL_HDQ_GROUP_START = 0x1900,
   DCL_HDQ,
   DCL_PXS_GROUP_START = 0x1A00,
   DCL_PXS,
   DCL_F32K_CLK_GROUP_START = 0x1B00,
   DCL_F32K_CLK,
   DCL_EINT_GROUP_START = 0x1C00,
   DCL_EINT,
   DCL_SPI_SLAVE_GROUP_START =0X1D00,
   DCL_SPI_SLAVE
} DCL_DEV_T;

/*******************************************************************************
 * DCL_FLAGS
 *******************************************************************************/
typedef DCL_UINT32 DCL_FLAGS;
typedef enum
{
   FLAGS_NONE = 0,
   FLAGS_END
} DCL_FLAGS_T;


/*******************************************************************************
 * DCL_OPTIONS
 *******************************************************************************/
typedef DCL_UINT32 DCL_OPTIONS;
typedef enum
{
   OPTIONS_NONE = 0,
   GPT_OPTIONS_START = OPTIONS_NONE,
   GPT_OPTIONS //Please see dcl_gpt.h
   GPIO_OPTIONS_START = 0x100,
   GPIO_OPTIONS //Please see dcl_gpio.h
   ADC_OPTIONS_START = 0x200,
   ADC_OPTIONS //Please see dcl_adc.h
   WDT_OPTIONS_START = 0x300,
   WDT_OPTIONS //Please see dcl_wdt.h
   BMT_OPTIONS_START = 0x400,
   BMT_OPTIONS // Please see dcl_bmt.h   
   PFC_OPTIONS_START = 0x500,
   PFC_OPTIONS // Please see dcl_pfc.h   
   RTC_OPTIONS_START = 0x600,
   RTC_OPTIONS // Please see dcl_rtc.h
   I2C_OPTIONS_START = 0x700,
   I2C_OPTIONS //Please see dcl_i2c.h
   AUX_OPTIONS_START = 0x800,
   AUX_OPTIONS //Please see dcl_aux.h
   TS_OPTIONS_START = 0x900,
   TS_OPTIONS//Please see dcl_ts.h
   USB_DRV_OPTIONS_START = 0xA00,
   USB_DRV_OPTIONS//Please see dcl_usb_drv.h
   USB_HCD_OPTIONS_START = 0xB00,
   USB_HCD_OPTIONS//Please see dcl_usb_hcd.h
   OTG_DRV_OPTIONS_START = 0xC00,
   OTG_DRV_OPTIONS//Please see dcl_otg_drv.h
   IRDA_OPTIONS_START = 0xD00,
   IRDA_OPTIONS//Please see dcl_irda.h
   PMU_OPTIONS_START = 0xE00,
   PMU_OPTIONS // Please see dcl_pmu.h
   PW_OPTIONS_START = 0xF00,
   PW_OPTIONS // Please see dcl_pw.h
   CHR_DET_OPTIONS_START = 0x1000,
   CHR_DET_OPTIONS // Please see dcl_chr_usb_det.h
   PXS_OPTIONS_START = 0x2000,
   PXS_OPTIONS // Please see dcl_pxs.h
   F32K_CLK_OPTIONS_START = 0x4000,
   F32K_CLK_OPTIONS // Please see dcl_f32k_clk.h
   OPTIONS_MAX
} DCL_OPTIONS_T;

/*******************************************************************************
 * DCL_HANDLE
 *******************************************************************************/
typedef DCL_INT32 DCL_HANDLE;
#define DCL_HANDLE_NONE    (0)
#define DCL_HANDLE_INVALID    (-1)
#define DCL_HANDLE_OCCUPIED    (-2)

/*******************************************************************************
 * DCL_BUFF
 *******************************************************************************/
typedef DCL_UINT8  DCL_BUFF;
typedef DCL_UINT32  DCL_BUFF_LEN;

/*******************************************************************************
 * DCL_CONFIGURE_T
 *******************************************************************************/
typedef union
{
   PWM_CONFIGS//Please see dcl_PWM.h
   // For ADC, please see dcl_adc.h
   ADC_CONFIGS
   // For BMT, please see dcl_bmt.h
   BMT_CONFIGS   
   // For PFC, please see dcl_pfc.h
   PFC_CONFIGS   
   // For RTC, please see dcl_rtc.h
   RTC_CONFIGS
   // For WDT, please see dcl_wdt.h
   WDT_CONFIGS
   // For I2C, please see dcl_i2c.h
   I2C_CONFIGS
   // For AUX, please see dcl_aux.h
   AUX_CONFIGS
   // For USB_DRV, please see dcl_usb_drv.h
   USB_DRV_CONFIGS
   // For USB_HCD, please see dcl_usb_hcd.h
   USB_HCD_CONFIGS
   // For OTG_DRV, please see dcl_otg_drv.h
   OTG_DRV_CONFIGS
   // For IRDA, please see dcl_irda.h
   IRDA_CONFIGS
   // For PMU, please see dcl_pmu.h
   PMU_CONFIGS
   // For PW, please see dcl_pw.h
   PW_CONFIGS   
   // For CHR&USB detection , please see dcl_chr_usb_det.h
   CHR_DET_CONFIGS
   // For SIM, please see dcl_sim.h
   SIM_CONFIGS
   //for TS, please see dcl_ts.h
   TS_CONFIGS
   // For PXS, please see dcl_pxs.h
   PXS_CONFIGS
   // For F32K_CLK, please see dcl_f32k_clk.h
   F32K_CLK_CONFIGS
} DCL_CONFIGURE_T;


/*******************************************************************************
 * DCL_EVENT
 *******************************************************************************/
typedef DCL_UINT32  DCL_EVENT;
typedef enum
{
   EVENT_NULL = 0,
   // For HGPT, please see dcl_gpt.h
   GPT_EVENTS_START = EVENT_NULL,
   GPT_EVENTS
   //for GPIO, please see dcl_gpio.h
   GPIO_EVENTS_START = 0x100,
   GPIO_EVENTS
   // For BMT, please see dcl_bmt.h
   BMT_EVENTS_START = 0x200,
   BMT_EVENTS
   // For PFC, please see dcl_pfc.h
   PFC_EVENTS_START = 0x300,
   PFC_EVENTS
   // For RTC, please see dcl_rtc.h
   RTC_EVENTS_START = 0x400,
   RTC_EVENTS
   // For WDT, please see dcl_wdt.h
   WDT_EVENTS_START = 0x500,
   WDT_EVENTS
   // For ADC, please see dcl_adc.h
   ADC_EVENTS_START = 0x600,
   ADC_EVENTS
   // For I2C, please see dcl_i2c.h
   I2C_EVENTS_START = 0x700,
   I2C_EVENTS
   // For AUX, please see dcl_aux.h
   AUX_EVENTS_START = 0x800,
   AUX_EVENTS
   //For Keypad, Please see dcl_kbd.h
   KBDH_EVENTS_START = 0x900,
   KBDH_EVENTS
   //For TS, Please see dcl_ts.h
   TS_EVENTS_START = 0xA00,
   TS_EVENTS
   //For USB_DRV, please see dcl_usb_drv.h
   USB_DRV_EVENTS_START = 0xB00,
   USB_DRV_EVENTS
   //For USB_HCD, please see dcl_usb_hcd.h
   USB_HCD_EVENTS_START = 0xC00,
   USB_HCD_EVENTS
   //For OTG_DRV, please see dcl_otg_drv.h
   OTG_DRV_EVENTS_START = 0xD00,
   OTG_DRV_EVENTS
   // For IrDA, please see dcl_irda.h
   IRDA_EVENTS_START = 0xE00,
   IRDA_EVENTS
   // For pmu, please see dcl_pmu.h
   PMU_EVENTS_START = 0xF00,
   PMU_EVENTS
   // For pw, please see dcl_pw.h
   PW_EVENTS_START = 0x1000,
   PW_EVENTS
   // For Chr&USB detection , please see dcl_chr_usb_det.h
   CHR_DET_EVENTS_START = 0x1100,
   CHR_DET_EVENTS
   // For PXS, please see dcl_pxs.h
   PXS_EVENTS_START = 0x1200,
   PXS_EVENTS
   // For F32K_CLK, please see dcl_f32k_clk.h
   F32K_CLK_EVENTS_START = 0x1300,
   F32K_CLK_EVENTS   
   SERIPORT_EVENTS_START = 0x1400,  	/*For SIO(include UART and USB)*/
   UART_EVENTS
   SPI_EVENTS_START = 0x1500,  /*for SPI*/
   EINT_EVENTS_START = 0x1600,
   EINT_EVENTS
   SPI_SLAVE_EVENTS_START = 0x1700,
   SPI_SLAVE_EVENTS
   EVENT_END
} DCL_EVENT_T;

/*******************************************************************************
 * PFN_DCL_CALLBACK
 *******************************************************************************/
typedef void (*PFN_DCL_CALLBACK)(DCL_EVENT event);

/*******************************************************************************
 * DCL_CTRL_CMD
 *******************************************************************************/
#if defined(CMD_END)
#undef CMD_END  
#endif 
typedef DCL_UINT32  DCL_CTRL_CMD;
typedef enum
{
   CMDS_START = 0,
   /* Below is the command for GPIO */
   //please make sure GPIO Command start from zero! [drv_tool genertate a char type variable]
   GPIO_CMDS_START = CMDS_START, 
   GPIO_CMDS //please see dcl_gpio.h
   /* Below is the command for UART */
   UART_CMDS_START = 0x100,
   UART_CMDS //please see dcl_uart.h
   /* Below is the command for GPT */
   GPT_CMDS_START = 0x200,
   GPT_CMDS //please see dcl_gpt.h
   /* Below is the command for ADC */
     /* Exported adc schedule APIs */
   ADC_CMDS_START = 0x300,
   ADC_CMDS
     /* Interfac for Hardware ADC */
   HADC_CMDS_START = 0x400,
   HADC_CMDS
   /* Below is the command for WDT */
   WDT_CMDS_START = 0x500,
   WDT_CMDS
   /* Below is the command for BMT */
   BMT_CMDS_START = 0x600,
   BMT_CMDS // Please see dcl_bmt.h
   /* Below is the command for PFC */
   PFC_CMDS_START = 0x700,
   PFC_CMDS // Please see dcl_pfc.h
   /* Below is the command for RTC */
   RTC_CMDS_START = 0x800,
   RTC_CMDS // Please see dcl_rtc.h
   /* Below is the command for I2C */
   I2C_CMDS_START = 0x900,
   I2C_CMDS
   /* Below is the command for AUX */
   AUX_CMDS_START = 0xA00,
   AUX_CMDS
   /* Below is the command for KBD */
   KBDH_CMDS_START = 0xB00,
   KBDH_CMDS
   KBD_CMDS_START = 0xC00,
   KBD_CMDS//Please see dcl_kbd.h
   /* Below is the command for OWM */
   PWM_CMDS_START = 0xD00,
   PWM_CMDS//Please see dcl_PWM.h
   ALERTER_CMDS_START = 0xE00,
   ALERTER_CMDS //please see dcl_pwm.h
   /* Below is the command for TS */
   TS_CMDS_START = 0xF00,
   TS_CMDS//Please see dcl_ts.h
   /* Below is the command for SD*/
   SD_CMDS_START = 0x1000,
   SD_CMDS//Please see dcl_msdc.h
   /* Below is the command for SDIO*/
   SDIO_CMDS_START = 0x1100,
   SDIO_CMDS//Please see dcl_msdc.h
   /* Below is the commands for USB_DRV, please see dcl_usb_drv.h */
   USB_DRV_CMDS_START = 0x1300,
   USB_DRV_CMDS
   /* Below is the commands for USB_HCD, please see dcl_usb_hcd.h */
   USB_HCD_CMDS_START = 0x1400,
   USB_HCD_CMDS
   /* Below is the commands for OTG_DRV, please see dcl_otg_drv.h */
   OTG_DRV_CMDS_START = 0x1500,
   OTG_DRV_CMDS
   /* Below is the command for IRDA*/
   IRDA_CMDS_START = 0x1600,
   IRDA_CMDS//Please see dcl_irda.h
   /* Below is the command for SIM*/
   SIM_CMDS_START = 0x1700,
   SIM_CMDS//Please see dcl_msdc.h
   /* Below is the command for PMU */
   PMU_CMDS_START = 0x1800,
   PMU_CMDS //Please see dcl_pmu.h
   /* Below is the command for PW */
   PW_CMDS_START = 0x1900,
   PW_CMDS //Please see dcl_pw.h
   /* Below is the command for CHR USB DETECT */
   CHR_DET_CMDS_START = 0x1A00,
   CHR_DET_CMDS //Please see dcl_chr_usb_det.h
   /* Below is the command for PXS */
   PXS_CMDS_START = 0x1B00,
   PXS_CMDS //Please see dcl_pxs.h
   /* Below is the command for F32K_CLK */
   F32K_CLK_CMDS_START = 0x1D00,
   F32K_CLK_CMDS //please see dcl_f32k_clk.h	
   /* Below is the command for eint */
   EINT_CMDS_START = 0x1E00,
   EINT_CMDS  //please see dcl_eint.h
   SPI_SLAVE_CMDS_START = 0x1F00,
   SPI_SLAVE_CMDS  //please see dcl_spi_slave.h
   CMD_END
} DCL_CTRL_CMD_T;

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
typedef union
{
   /* GPT control datas, please see dcl_gpt.h */
   GPT_CTRLS
   /* UART control datas, please see dcl_uart.h */
   UART_CTRLS
   /* GPIO control datas, please see dcl_gpio.h */
   GPIO_CTRLS
   /* ADC control datas, please see dcl_adc.h */
   ADC_CTRLS
   /* WDT control datas, please see dcl_wdt.h */
   WDT_CTRLS
   /* Below is the ctrl structures for BMT */
   BMT_CTRLS //Please see dcl_bmt.h
   /* Below is the ctrl structures for PFC */
   PFC_CTRLS // Please see dcl_pfc.h
   /* RTC control datas, please see dcl_rtc.h */
   RTC_CTRLS // Please see dcl_rtc.h
   /* I2C control datas, please see dcl_i2c.h */
   I2C_CTRLS
   /* AUX control datas, please see dcl_aux.h */
   AUX_CTRLS
   /* KBD control datas, please see dcl_kbd.h */
   /* KBD control datas, please see dcl_kbd.h */
  KBDS_CTRLS//Please see dcl_kbd.h
   KBDH_CTRLS
   /* PWM control datas, please see dcl_PWM.h */
   PWM_CTRLS//Please see dcl_PWM.h   
   ALERTER_CTRLS
   /* TS control datas, please see dcl_ts.h */
   TS_CTRLS//Please see dcl_ts.h
   /* Below is the ctrl structures for SD*/
   SD_CTRLS//Please see dcl_msdc.h
   /* Below is the ctrl structures for SDIO*/
   SDIO_CTRLS//Please see dcl_msdc.h
   /* Below is the control data structures for USB_DRV, please see dcl_usb_drv.h */
   USB_DRV_CTRLS
   /* Below is the control data structures for USB_HCD, please see dcl_usb_hcd.h */
   USB_HCD_CTRLS
   /* Below is the control data structures for OTG_DRV, please see dcl_otg_drv.h */
   OTG_DRV_CTRLS
   /* Below is the ctrl structures for IRDA*/
   IRDA_CTRLS//Please see dcl_irda.h
   /* Below is the ctrl structures for SIM*/
   SIM_CTRLS//Please see dcl_sim.h
   /* Below is the ctrl structures for PMU */
   PMU_CTRLS//Please see dcl_pmu.h
   /* Below is the ctrl structures for Power up reason */
   PW_CTRLS//Please see dcl_pW.h
   /* Below is the ctrl structures for Chr & USB detection */
   CHR_DET_CTRLS//Please see dcl_chr_usb_det.h   
   /* Below is the ctrl structures for PXS */
   PXS_CTRLS//Please see dcl_pxs.h
   /* Below is the ctrl structures for SIM_GPIO */
   F32K_CLK_CTRLS//please see dcl_f32k_clk.h   
   /* Below is the ctrl structures for SPI_SLAVE*/
   SPI_SLAVE_CTRLS //please see dcl_spi_slave.h   
} DCL_CTRL_DATA_T;

/*definitions of structures are finished, undefine DCL_DEFINITION_STRUCT*/
#undef DCL_DEFINITION_STRUCT
#define DCL_DEFINITION_PROTOTYPE
#include "dcl_common.h"
#include "dcl_uart.h"
#include "dcl_msdc.h"
#include "dcl_gpio.h"
#include "dcl_gpt.h"
#include "dcl_adc.h"
#include "dcl_bmt.h"
#include "dcl_pfc.h"
#include "dcl_rtc.h"
#include "dcl_i2c.h"
#include "dcl_aux.h"
#include "dcl_wdt.h"
#include "dcl_pwm.h"
#include "dcl_usb_drv.h"
#include "dcl_usb_hcd.h"
#include "dcl_otg_drv.h"
#include "dcl_irda.h"
#include "dcl_sim.h"
#include "dcl_pmu.h"
#include "dclH_kbd.h"
#include "dclS_kbd.h"
#include "dcl_pw.h"
#include "dcl_chr_det.h"
#include "dcl_sts.h"  /* Added here to overcome compilation/link error */
#include "dcl_pxs.h"
#include "dcl_f32k_clk.h"
#include "dcl_eint.h"
#include "dcl_spi_slave.h"
#undef DCL_DEFINITION_PROTOTYPE

#endif  /* __DCL_H__ */

