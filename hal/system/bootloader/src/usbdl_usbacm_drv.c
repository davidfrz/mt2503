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
 *    usbacm_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb CDC ACM class driver
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef  __USB_DOWNLOAD__

#if defined(__USBDL_BOOTROM__)
#include "usbdl_bootrom.h"
#else
#include "kal_non_specific_general_types.h"
#include "uart_sw.h"
//#include "drv_comm.h"
#include "drv_features.h"
//#include <usb_comm.h>
#include "usbdl_usb_drv.h"
#include "usbdl_usb.h"
#include "usbdl_usb_resource.h"
#include "usbdl_usbacm_drv.h"
#include "usb_custom.h"
#endif

/* global variables */
UsbUartStruct USB2UARTPort;
UsbAcm_Struct g_UsbACM;

#if defined(USBACM_TX_WITHOUT_DMA)
kal_bool gUSBAcm_IsInEPComplete;
#endif

/* Exception flag */
//extern kal_uint8 INT_Exception_Enter; 

/* static functions */
static void USB_Acm_Ep0_SetLineCoding(void *data);
static void USB_Acm_Ep0_Command(Usb_Ep0_Status* pep0state,Usb_Command* pcmd);
static void USB_Acm_BulkOut_Hdr(void);
static void USB_Acm_BulkIn_Reset(void);
static void USB_Acm_BulkOut_Reset(void);
//static void USB_Acm_FT_BulkOut_Hdr(void );
static void USB_Acm_BulkIn_Hdr(void);

#ifdef  __USB_COMPORT_SUPPORT_TC01_DRIVER__
static void USB_Acm_VirtualIn_Reset(void);
static void USB_Acm_VirtualOut_Reset(void);
#endif
/*************************************************************
  translate ACM and UART setting functions
**************************************************************/

/* translate ACM line coding to UART DCB */
void USB2UART_LineCoding2DCB(UsbAcm_Line_Coding *pline_coding, UARTDCBStruct *pDCB)
{
	 pDCB->baud = (pline_coding->dwDTERate);
	 pDCB->stopBits = (UART_stopBits)(pline_coding->bCharFormat+1); 
	 pDCB->parity = (UART_parity)(pline_coding->bParityType);
	 pDCB->dataBits = (UART_bitsPerCharacter)(pline_coding->bDataBits);
}

/* translate UART DCB to ACM line coding */
void UART2USB_DCB2LineCoding(UARTDCBStruct *pDCB, UsbAcm_Line_Coding *pline_coding)
{
	  pline_coding->dwDTERate = (kal_uint32)(pDCB->baud);
	  pline_coding->bCharFormat = (kal_uint8)(pDCB->stopBits-1);
	  pline_coding->bParityType = (kal_uint8)(pDCB->parity);
	  pline_coding->bDataBits = (kal_uint8)(pDCB->dataBits);
}

#if  0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/************************************************************
	interface initialization functions
*************************************************************/

/* communication interface create function, prepare descriptor */
void USB_Acm_CommIf_Create(void *ifname)
{
	kal_uint8 ep_id;
	kal_uint8 if_id;


	/* get resource number and register to gUsbDevice */
	g_UsbACM.comm_if_info = USB_Get_Interface_Number(&if_id);
	g_UsbACM.comm_ep_intr_info = USB_Get_Intr_Ep(&ep_id); /* number is 3  */

	/* record interface name and interface descriptor length */
	g_UsbACM.comm_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbACM.comm_if_info->ifdscr_size = USB_CDC_IF_LENGTH;
	g_UsbACM.comm_ep_intr_info->epdscr_size = USB_EPDSC_LENGTH;

	/* related endpoint info and class specific command handler*/
	g_UsbACM.comm_if_info->ep_info[0] = (Usb_Ep_Info*)g_UsbACM.comm_ep_intr_info;
	g_UsbACM.comm_if_info->if_class_specific_hdlr = USB_Acm_Ep0_Command;

	/* standard interface descriptor */
//	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bLength = USB_CDC_IF_LENGTH;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bLength = USB_IFDSC_LENGTH;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bDescriptorType = USB_INTERFACE;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bInterfaceNumber = if_id;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bAlternateSetting = 0;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bNumEndpoints = USB_CDC_ACM_COMM_EP_NUMBER;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bInterfaceClass = USB_ACM_COMM_INTERFACE_CLASS_CODE;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bInterfaceSubClass = USB_ACM_COMM_INTERFACE_SUBCLASS_CODE;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bInterfaceProtocol = USB_ACM_COMM_INTERFACE_PROTOCOL_CODE;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->iInterface = 
		USB_Get_String_Number((void *)g_UsbACM.acm_param->comm_interface_string);   
	/*Header Functional Descriptor*/
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->HFbFunctionLength = 0x05;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->HFbDescriptorType = 0x24;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->HFbDescriptorSubtype = 0x00;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bcdCDC = 0x0110;
	/*Abstract Control Management Functional Descriptor*/
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->ACMFbFunctionLength = 0x04;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->ACMFbDescriptorType = 0x24;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->ACMFbDescriptorSubtype = 0x02;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->ACMFbmCapabilities = 0x0f;
	/*Union Functional Descriptor*/
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->UFbFunctionLength = 0x05;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->UFbDescriptorType = 0x24;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->UFbDescriptorSubtype = 0x06;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bMasterInterface = if_id;
#ifdef  __USB_COMPORT_SUPPORT_TC01_DRIVER__		 
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bSlaveInterface0 = 0x01;
#else
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bSlaveInterface0 = g_UsbACM.data_interface_id;
#endif
	/*Call Management Descriptor*/
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->CMFbFunctionLength = 0x05;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->CMFbDescriptorType = 0x24;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->CMFbDescriptorSubtype = 0x01;
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->CMFbmCapabilities = 0x03;
#ifdef  __USB_COMPORT_SUPPORT_TC01_DRIVER__		
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bDataInterface = 0x01;
#else
	((Usb_Cdc_If_Dscr*)&g_UsbACM.comm_if_info->ifdscr.classif)->bDataInterface = g_UsbACM.data_interface_id;
#endif
	/* endpoint handler*/
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, NULL);
	g_UsbACM.comm_ep_intr_info->ep_reset = NULL;
	
	/* endpoint descriptor */
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN | ep_id);	/*InPipe*/
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.bmAttributes = USB_EP_INTR;
#ifndef __USB_HS_ENABLE__
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_INTR_MAXP&0xff; 		/*HW-dependent*/
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_INTR_MAXP>>8)&0xff; 
#endif
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.bInterval = 1;
	g_UsbACM.comm_ep_intr_info->ep_status.epin_status.byEP = ep_id;
	g_UsbACM.comm_ep_intr_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
}

/* communication interface reset function, should enable EP, but we do not use this interrupt EP so not enable it */
void USB_Acm_CommIf_Reset(void)
{
	g_UsbACM.intrpipe = &g_UsbACM.comm_ep_intr_info->ep_status.epin_status;
}
/* communication interface speed reset function, enable EP's speed-specific descriptor */
void USB_Acm_CommIf_Speed_Reset(kal_bool b_other_speed)
{
#ifdef __USB_HS_ENABLE__
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_INTR_MAXP_FS&0xff;
//	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_INTR_MAXP_FS>>8)&0xff;
	g_UsbACM.comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
#endif
}
/* data interface create function, prepare descriptor */
void USB_Acm_DataIf_Create(void *ifname)
{
	kal_uint8 ep_in_id;
	kal_uint8 ep_out_id;
	kal_uint8 if_id;
	

	/* get resource number and register to gUsbDevice */
	g_UsbACM.data_if_info = USB_Get_Interface_Number(&if_id);
	g_UsbACM.data_interface_id = if_id;
	g_UsbACM.data_ep_in_info = USB_Get_Bulk_Tx_Ep(&ep_in_id);
	g_UsbACM.data_ep_out_info = USB_Get_Bulk_Rx_Ep(&ep_out_id);

	/* record interface name and interface descriptor length */
	g_UsbACM.data_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbACM.data_if_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_UsbACM.data_ep_in_info->epdscr_size = USB_EPDSC_LENGTH;
	g_UsbACM.data_ep_out_info->epdscr_size = USB_EPDSC_LENGTH;

	/* related endpoint info and class specific command handler*/
	g_UsbACM.data_if_info->ep_info[0] = g_UsbACM.data_ep_in_info;
	g_UsbACM.data_if_info->ep_info[1] = (Usb_Ep_Info*)g_UsbACM.data_ep_out_info;
	g_UsbACM.data_if_info->if_class_specific_hdlr = NULL;

	/* standard interface descriptor */
	g_UsbACM.data_if_info->ifdscr.stdif.bLength = USB_IFDSC_LENGTH;
	g_UsbACM.data_if_info->ifdscr.stdif.bDescriptorType = USB_INTERFACE;
	g_UsbACM.data_if_info->ifdscr.stdif.bInterfaceNumber = if_id;
	g_UsbACM.data_if_info->ifdscr.stdif.bAlternateSetting = 0;
	g_UsbACM.data_if_info->ifdscr.stdif.bNumEndpoints = USB_CDC_ACM_DATA_EP_NUMBER;
	g_UsbACM.data_if_info->ifdscr.stdif.bInterfaceClass = USB_ACM_DATA_INTERFACE_CLASS_CODE;
#ifdef  __USB_COMPORT_SUPPORT_TC01_DRIVER__
	g_UsbACM.data_if_info->ifdscr.stdif.bInterfaceSubClass = 0xFF;//USB_ACM_DATA_INTERFACE_SUBCLASS_CODE;
#else
	g_UsbACM.data_if_info->ifdscr.stdif.bInterfaceSubClass = USB_ACM_DATA_INTERFACE_SUBCLASS_CODE;
#endif
	g_UsbACM.data_if_info->ifdscr.stdif.bInterfaceProtocol = USB_ACM_DATA_INTERFACE_PROTOCOL_CODE; 
	g_UsbACM.data_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbACM.acm_param->data_interface_string);   

	/* endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_in_id, USB_Acm_BulkIn_Hdr);
//	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_in_id, NULL);
	g_UsbACM.data_ep_in_info->ep_reset = USB_Acm_BulkIn_Reset;
	
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_out_id, USB_Acm_BulkOut_Hdr);
	g_UsbACM.data_ep_out_info->ep_reset = USB_Acm_BulkOut_Reset;

	
	/* endpoint descriptor */
	g_UsbACM.data_ep_in_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_UsbACM.data_ep_in_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_UsbACM.data_ep_in_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN | ep_in_id);   /*InPipe*/
	g_UsbACM.data_ep_in_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef __USB_HS_ENABLE__
	g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USBDL_EP_BULK_MAXP&0xff;
	g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USBDL_EP_BULK_MAXP>>8)&0xff;
#endif
	g_UsbACM.data_ep_in_info->epdesc.stdep.bInterval = 0;
	g_UsbACM.data_ep_in_info->ep_status.epin_status.byEP = ep_in_id;
	g_UsbACM.data_ep_in_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	g_UsbACM.data_ep_out_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_UsbACM.data_ep_out_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_UsbACM.data_ep_out_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_OUT | ep_out_id);   /*OutPipe*/
	g_UsbACM.data_ep_out_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef __USB_HS_ENABLE__
	g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USBDL_EP_BULK_MAXP&0xff;
	g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USBDL_EP_BULK_MAXP>>8)&0xff;
#endif
	g_UsbACM.data_ep_out_info->epdesc.stdep.bInterval = 0;
	g_UsbACM.data_ep_out_info->ep_status.epout_status.byEP = ep_out_id;
}


/* data interface reset function, enable EP*/
void USB_Acm_DataIf_Reset(void)
{
#ifndef  __USB_COMPORT_SUPPORT_TC01_DRIVER__
	g_UsbACM.txpipe = &g_UsbACM.data_ep_in_info->ep_status.epin_status;
	g_UsbACM.rxpipe = &g_UsbACM.data_ep_out_info->ep_status.epout_status;

#ifndef __USBDL_IN_BOOTROM__	 // if USB has already setup COm port, doesn't need to change HW setting
	/* Non-DMA */
	USB_TxEPEn(g_UsbACM.txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
	/* Non-DMA */
	USB_RxEPEn(g_UsbACM.rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
#endif
#endif
}


/* data interface speed reset function, enable EP's speed-specific descriptor */
void USB_Acm_DataIf_Speed_Reset(kal_bool b_other_speed)
{
#ifdef __USB_HS_ENABLE__
	if(USB_Is_High_Speed() == KAL_TRUE)
	{
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USBDL_EP_BULK_MAXP&0xff;
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USBDL_EP_BULK_MAXP>>8)&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USBDL_EP_BULK_MAXP&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USBDL_EP_BULK_MAXP>>8)&0xff;
	}
	else
	{
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
//			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_UsbACM.data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
//			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_UsbACM.data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;

	}
#endif
}

#ifdef  __USB_COMPORT_SUPPORT_TC01_DRIVER__
void USB_Acm_VirtualIf_Create(void *ifname)
{
	kal_uint8 ep_in_id;
	kal_uint8 ep_out_id;
	kal_uint8 if_id;
	

	/* get resource number and register to gUsbDevice */
	g_UsbACM.virtual_if_info = USB_Get_Interface_Number(&if_id);
	g_UsbACM.virtual_ep_in_info = USB_Get_Bulk_Tx_Ep(&ep_in_id);
	g_UsbACM.virtual_ep_out_info = USB_Get_Bulk_Rx_Ep(&ep_out_id);

	/* record interface name and interface descriptor length */
	g_UsbACM.virtual_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbACM.virtual_if_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_UsbACM.virtual_ep_in_info->epdscr_size = USB_EPDSC_LENGTH;
	g_UsbACM.virtual_ep_out_info->epdscr_size = USB_EPDSC_LENGTH;

	/* related endpoint info and class specific command handler*/
	g_UsbACM.virtual_if_info->ep_info[0] = g_UsbACM.virtual_ep_in_info;
	g_UsbACM.virtual_if_info->ep_info[1] = (Usb_Ep_Info*)g_UsbACM.virtual_ep_out_info;
	g_UsbACM.virtual_if_info->if_class_specific_hdlr = NULL;

	/* standard interface descriptor */
	g_UsbACM.virtual_if_info->ifdscr.stdif.bLength = USB_IFDSC_LENGTH;
	g_UsbACM.virtual_if_info->ifdscr.stdif.bDescriptorType = USB_INTERFACE;
	g_UsbACM.virtual_if_info->ifdscr.stdif.bInterfaceNumber = if_id;
	g_UsbACM.virtual_if_info->ifdscr.stdif.bAlternateSetting = 0;
	g_UsbACM.virtual_if_info->ifdscr.stdif.bNumEndpoints = USB_CDC_ACM_DATA_EP_NUMBER;
	g_UsbACM.virtual_if_info->ifdscr.stdif.bInterfaceClass = 0xFF;//USB_ACM_DATA_INTERFACE_CLASS_CODE;
	g_UsbACM.virtual_if_info->ifdscr.stdif.bInterfaceSubClass = 0xFF;//USB_ACM_DATA_INTERFACE_SUBCLASS_CODE;
	g_UsbACM.virtual_if_info->ifdscr.stdif.bInterfaceProtocol = USB_ACM_DATA_INTERFACE_PROTOCOL_CODE; 
	g_UsbACM.virtual_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbACM.acm_param->data_interface_string);   

	/* endpoint handler */

	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_in_id, USB_Acm_BulkIn_Hdr);
	g_UsbACM.data_ep_in_info->ep_reset = USB_Acm_VirtualIn_Reset;
	
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_out_id, USB_Acm_BulkOut_Hdr);
	g_UsbACM.data_ep_out_info->ep_reset = USB_Acm_VirtualOut_Reset;
	
	
	/* endpoint descriptor */
	
	g_UsbACM.virtual_ep_in_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_UsbACM.virtual_ep_in_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_UsbACM.virtual_ep_in_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN | ep_in_id);  
	g_UsbACM.virtual_ep_in_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef __USB_HS_ENABLE__
	g_UsbACM.virtual_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USBDL_EP_BULK_MAXP&0xff;
	g_UsbACM.virtual_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USBDL_EP_BULK_MAXP>>8)&0xff;
#endif
	g_UsbACM.virtual_ep_in_info->epdesc.stdep.bInterval = 0;
	g_UsbACM.virtual_ep_in_info->ep_status.epin_status.byEP = ep_in_id;
	g_UsbACM.virtual_ep_in_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	
	g_UsbACM.virtual_ep_out_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_UsbACM.virtual_ep_out_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_UsbACM.virtual_ep_out_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_OUT | ep_out_id);  
	g_UsbACM.virtual_ep_out_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef __USB_HS_ENABLE__
	g_UsbACM.virtual_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USBDL_EP_BULK_MAXP&0xff;
	g_UsbACM.virtual_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USBDL_EP_BULK_MAXP>>8)&0xff;
#endif
	g_UsbACM.virtual_ep_out_info->epdesc.stdep.bInterval = 0;
	g_UsbACM.virtual_ep_out_info->ep_status.epout_status.byEP = ep_out_id;
	
}

extern void USB_Acm_VirtualIf_Reset(void)
{
	g_UsbACM.txpipe = &g_UsbACM.virtual_ep_in_info->ep_status.epin_status;
	g_UsbACM.rxpipe = &g_UsbACM.virtual_ep_out_info->ep_status.epout_status;

#ifndef __USBDL_IN_BOOTROM__	 // if USB has already setup COm port, doesn't need to change HW setting
	/* Non-DMA */
	USB_TxEPEn(g_UsbACM.txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
	/* Non-DMA */
	USB_RxEPEn(g_UsbACM.rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
#endif
}

void USB_Acm_VirtualIf_Speed_Reset(kal_bool b_other_speed)
{
#ifdef __USB_HS_ENABLE__
	if(USB_Is_High_Speed() == KAL_TRUE)
	{
			g_UsbACM.virtual_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USBDL_EP_BULK_MAXP&0xff;
			g_UsbACM.virtual_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USBDL_EP_BULK_MAXP>>8)&0xff;
			g_UsbACM.virtual_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USBDL_EP_BULK_MAXP&0xff;
			g_UsbACM.virtual_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USBDL_EP_BULK_MAXP>>8)&0xff;
	}
	else
	{
			g_UsbACM.virtual_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
			g_UsbACM.virtual_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
			g_UsbACM.virtual_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
			g_UsbACM.virtual_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;

	}
#endif
}
#endif
/************************************************************
	global variable g_UsbACM initialize and release functions
*************************************************************/

/* initialize global variable g_UsbACM */
void USB_Init_Acm_Status(void)
{
	g_UsbACM.txpipe = NULL;
	g_UsbACM.rxpipe = NULL;
	g_UsbACM.intrpipe = NULL;
	g_UsbACM.data_interface_id = 0;
//	g_UsbACM.break_detect = KAL_FALSE;
//	g_UsbACM.break_number = 0;
//	g_UsbACM.out_pipe_race = KAL_FALSE;
//	g_UsbACM.send_Txilm = KAL_FALSE;
//	g_UsbACM.send_Rxilm = KAL_TRUE;
//	g_UsbACM.send_UARTilm = KAL_FALSE;
//	g_UsbACM.ring_buffer_timer_counting = KAL_FALSE;
}

/* release global variable g_UsbACM */
void USB_Release_Acm_Status(void)
{
	g_UsbACM.txpipe = NULL;
	g_UsbACM.rxpipe = NULL;
	g_UsbACM.intrpipe = NULL;
	g_UsbACM.data_interface_id = 0;
}


/************************************************************
	EP0 handle functions
************************************************************/

/* set USB request line coding to UART DCB structure */
static void USB_Acm_Ep0_SetLineCoding(void *data)
{
	kal_uint32 nCount;


	/* read setting and set to UART structure*/
	nCount = USB_EP0_Pkt_Len();

	if(nCount > 0)
	{
		USB_EPFIFORead(0, nCount, &g_UsbACM.line_coding);
   		USB2UART_LineCoding2DCB(&g_UsbACM.line_coding, &USB2UARTPort.DCB);
   		gUsbDevice.ep0_state = USB_EP0_RX_STATUS;
   		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);
	}	
}


/* parse class specific request */
static void USB_Acm_Ep0_Command(Usb_Ep0_Status* pep0state,Usb_Command* pcmd)
{
	kal_bool bError = KAL_FALSE;


	switch (pcmd->bRequest)
	{
	case USB_ACM_SET_LINE_CODING:
		/* register handler to handle the get data*/
		USB_Register_EP0_RxHdlr(USB_Acm_Ep0_SetLineCoding);
		gUsbDevice.ep0_state =USB_EP0_RX;
		break;
	case USB_ACM_GET_LINE_CODING:
		/* tell host the current setting */
		USB_Generate_EP0Data(pep0state, pcmd, &g_UsbACM.line_coding, 7);
		break;
	case USB_ACM_SET_CONTROL_LINE_STATE:
	case USB_ACM_SEND_BREAK:
		/* do not need to do anything */
		break;
	case USB_ACM_SEND_ENCAPSULATED_COMMAND:  
	case USB_ACM_GET_ENCAPSULATED_RESPONSE: 
	case USB_ACM_SET_COMM_FEATURE: 
	case USB_ACM_GET_COMM_FEATURE:
	case USB_ACM_CLEAR_COMM_FEATURE:
	default:
		bError = KAL_TRUE;
		break;
	}

	/* Stall command if an error occured */
	if (gUsbDevice.ep0_state == USB_EP0_IDLE)
	{
		gUsbDevice.ep0_state = USB_EP0_RX_STATUS;
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
}


/************************************************************
	Bulk EP OUT handle functions
*************************************************************/

/* 
    Used to retreive exception log, all interrupts are disabled 
    Note that this is special for sending exception log since interrupt is disabled when exception occurs
    It must not be used in normal time 
*/

/*
void USB2UART_Polling_Recv_Data(void)
{
	USB_Polling_Recv_Data(g_UsbACM.rxpipe->byEP);
}
*/

//#define USBDL_DEBUG
#ifdef USBDL_DEBUG
#pragma arm section zidata = "LARGE_BUFFER"
typedef struct{
	kal_int32 roomleft;
	kal_uint32 count;
}acm_bulkout_array;
acm_bulkout_array  bulkarray[256];
kal_uint8 bulkindex;
static kal_uint32 total_count;
#pragma arm section zidata
#endif



/* EP Bulk Out interrupt handler, called by EP interrupt */
#if 1
static void USB_Acm_BulkOut_Hdr(void )
{
	kal_uint32 nCount;

	if(usbacm_rx_buf.len == 0)
	{	
	nCount = USB_EP_Rx_Pkt_Len(g_UsbACM.rxpipe->byEP);
	usbacm_rx_buf.len = nCount;
	USB_EPFIFORead(g_UsbACM.rxpipe->byEP, nCount, usbacm_rx_buf.data);
	USB_EP_Bulk_Rx_Ready(g_UsbACM.rxpipe->byEP);
	}
}

#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef USBDL_DEBUG
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/* EP Bulk In reset handler */
static void USB_Acm_BulkIn_Reset(void)
{
	g_UsbACM.txpipe = &g_UsbACM.data_ep_in_info->ep_status.epin_status;
	usbacm_tx_buf.len = 0;
}

static void USB_Acm_BulkIn_Hdr(void)
{
#if defined(__USB_DOWNLOAD__) && defined(USBACM_TX_WITHOUT_DMA)
	gUSBAcm_IsInEPComplete = KAL_TRUE;
#endif
}

/* EP Bulk Out reset handler */
static void USB_Acm_BulkOut_Reset(void)
{
	g_UsbACM.rxpipe = &g_UsbACM.data_ep_out_info->ep_status.epout_status;
	usbacm_rx_buf.len = 0;
}

#ifdef  __USB_COMPORT_SUPPORT_TC01_DRIVER__
/* EP Bulk In reset handler */
static void USB_Acm_VirtualIn_Reset(void)
{
	g_UsbACM.txpipe = &g_UsbACM.virtual_ep_in_info->ep_status.epin_status;
	usbacm_tx_buf.len = 0;
}

/* EP Bulk Out reset handler */
static void USB_Acm_VirtualOut_Reset(void)
{
	g_UsbACM.rxpipe = &g_UsbACM.virtual_ep_out_info->ep_status.epout_status;
	usbacm_rx_buf.len = 0;
}
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif  /*  __USB_DOWNLOAD__ */
