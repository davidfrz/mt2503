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
 * Filename:
 * ---------
 *  gdi_ata.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI ATA
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#if defined(__ATA_SUPPORT__) && defined(__MTK_TARGET__) && defined(__LCD_SUPPORT__)


#include "gdi_include.h"



#define TOUCH_POINT1_X	  20
#define TOUCH_POINT1_y	  20

#define TOUCH_POINT2_X	  LCD_WIDTH-20
#define TOUCH_POINT2_y	  20

#define TOUCH_POINT3_X	  LCD_WIDTH-20
#define TOUCH_POINT3_y	  LCD_HEIGHT-20

#define TOUCH_POINT4_X	  20
#define TOUCH_POINT4_y	  LCD_HEIGHT-20


#define TOUCH_CIRCLE_R	  5


extern void (*ata_tp_ui)(kal_uint8);

extern void (*ata_lcm_ui)(kal_uint8);



void gdi_ata_tp_ui(kal_uint8 point_state)
{		 

	gdi_handle layer = GDI_NULL_HANDLE;
	gdi_layer_get_base_handle (&layer);
	gdi_layer_push_and_set_active (layer);

	gdi_layer_clear (GDI_COLOR_BLACK);

	if (((point_state>>0) & 0x01) == 0)
	{
		gdi_draw_solid_circle (TOUCH_POINT1_X, TOUCH_POINT1_y, TOUCH_CIRCLE_R, GDI_COLOR_RED);
	}
	else
	{
		gdi_draw_solid_circle (TOUCH_POINT1_X, TOUCH_POINT1_y, TOUCH_CIRCLE_R, GDI_COLOR_GREEN);
	}



	if (((point_state>>1) & 0x01) == 0)
	{
		gdi_draw_solid_circle (TOUCH_POINT2_X, TOUCH_POINT2_y, TOUCH_CIRCLE_R, GDI_COLOR_RED);
	}
	else
	{
		gdi_draw_solid_circle (TOUCH_POINT2_X, TOUCH_POINT2_y, TOUCH_CIRCLE_R, GDI_COLOR_GREEN);
	}


	if (((point_state>>2) & 0x01) == 0)
	{
		gdi_draw_solid_circle (TOUCH_POINT3_X, TOUCH_POINT3_y, TOUCH_CIRCLE_R, GDI_COLOR_RED);
	}
	else
	{
		gdi_draw_solid_circle (TOUCH_POINT3_X, TOUCH_POINT3_y, TOUCH_CIRCLE_R, GDI_COLOR_GREEN);
	}


	if (((point_state>>3) & 0x01) == 0)
	{
		gdi_draw_solid_circle (TOUCH_POINT4_X, TOUCH_POINT4_y, TOUCH_CIRCLE_R, GDI_COLOR_RED);
	}
	else
	{
		gdi_draw_solid_circle (TOUCH_POINT4_X, TOUCH_POINT4_y, TOUCH_CIRCLE_R, GDI_COLOR_GREEN);
	}

	gdi_layer_pop_and_restore_active ();
	gdi_layer_blt (layer, 0, 0, 0, 0, 0, LCD_WIDTH-1, LCD_HEIGHT-1);

}


void gdi_ata_lcm_ui(kal_uint8 color_state)
{	
	gdi_handle layer = GDI_NULL_HANDLE;
	gdi_layer_get_base_handle (&layer);
	gdi_layer_push_and_set_active (layer);
		 
	switch (color_state)
	{
		case 1:
			gdi_layer_clear (GDI_COLOR_RED);
			break;
		case 2:
			gdi_layer_clear (GDI_COLOR_GREEN);
			break;
		case 3:
			gdi_layer_clear (GDI_COLOR_BLUE);
			break;
		case 4:
			gdi_layer_clear (GDI_COLOR_WHITE);
			break;
		case 5:
			gdi_layer_clear (GDI_COLOR_BLACK);
			break;

		default:
			gdi_layer_clear (GDI_COLOR_RED);
			break;
	}
	
	gdi_layer_pop_and_restore_active ();
	gdi_layer_blt (layer, 0, 0, 0, 0, 0, LCD_WIDTH-1, LCD_HEIGHT-1);

}

void gdi_ata_init()
{
	
	ata_tp_ui = gdi_ata_tp_ui;
	
	ata_lcm_ui = gdi_ata_lcm_ui;
}


#endif




