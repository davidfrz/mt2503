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
 *   ts_lcd.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   This Module defines the LCD driver.
 *
 * Author:
 * -------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __TINY_SYS_TS__

#include "lcd_sw.h"
#include "lcd_hw.h"
#include "ts_display_sw.h"

volatile kal_uint32 ranesis_delay;

void LCD_init_tiny_lcd_ST7789S(void)
{
#if !defined(__LCM_IDLE_IN_MAUI__)
	LCD_CtrlWrite_ST7789S(0x39);
#endif
	
	LCD_CtrlWrite_ST7789S(0xE7);
	LCD_DataWrite_ST7789S(0x00);
}

void LCD_deinit_tiny_lcd_ST7789S(void)
{
	LCD_CtrlWrite_ST7789S(0x38);
	
	LCD_CtrlWrite_ST7789S(0xE7);
	LCD_DataWrite_ST7789S(0x10);
}

kal_uint16 LCD_GetColor_ST7789S(kal_uint8 *data, kal_uint8 index)
{
   kal_uint16 data_type;
   
   data_type = *data >> (index*2);
   data_type = data_type & 0x3;

   switch(data_type)
   {
      case 0:
	     data_type = 0;
      break;
      case 1:
	     data_type = 0x4208;
      break;
	  case 2:
         data_type = 0x8410;
	  break;
	  case 3:
	     data_type = 0xFFFF;
  	  break;
   }
   return data_type;
}

void LCD_TinyBlockWrite_ST7789S(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy, kal_uint8 *image_buffer)
{
   kal_uint16 LCD_x;
   kal_uint32 buffer_index;
   kal_uint8 data_index;
   kal_uint16 frame_color;
   kal_uint16 r_color,g_color,b_color, data_type;
   kal_uint32 total_pixel;

   LCD_CtrlWrite_ST7789S(0x2A);
   LCD_DataWrite_ST7789S((startx&0xFF00)>>8);
   LCD_DataWrite_ST7789S(startx&0xFF);
   LCD_DataWrite_ST7789S((endx&0xFF00)>>8);
   LCD_DataWrite_ST7789S(endx&0xFF);

   LCD_CtrlWrite_ST7789S(0x2B);
   LCD_DataWrite_ST7789S((starty&0xFF00)>>8);
   LCD_DataWrite_ST7789S(starty&0xFF);
   LCD_DataWrite_ST7789S((endy&0xFF00)>>8);
   LCD_DataWrite_ST7789S(endy&0xFF);

   LCD_CtrlWrite_ST7789S(0x2C);
	  
   total_pixel = (endx - startx + 1) * (endy - starty + 1);
   for(LCD_x = 0 ; LCD_x < total_pixel ; LCD_x++)
   {
      buffer_index = LCD_x >> 2;
      data_index = LCD_x & 0x3;
  
      frame_color = LCD_GetColor_ST7789S(image_buffer + buffer_index, data_index);
	  // 2-data lane, should change to 1-data lane to do tiny block write
#if defined(SERIAL_LCM_2_DATA_LINE_PROTOCOL)
      *((volatile unsigned char *) MAIN_LCD_DATA_ADDR)=(kal_uint8)((frame_color&0xFF00)>>8);
      *((volatile unsigned char *) MAIN_LCD_DATA_ADDR)=(kal_uint8)(frame_color&0xFF);		
#else  
  #if (defined(MAIN_LCD_9BIT_MODE)) 
	  r_color=((frame_color>>11)&0x1F)<<1;
	  g_color=(frame_color>>5)&0x3F;
	  b_color=((frame_color)&0x1F)<<1;
  #else
	  r_color=((frame_color&0xF800)>>10)|(data>>15); /* transfer to RGB666 */
	  g_color=((frame_color>>5)&0x3F);
	  b_color=((frame_color&0x1F)<<1)|((data>>4)&0x1);
  #endif
  #if (defined(MAIN_LCD_8BIT_MODE))
		*((volatile unsigned char *) MAIN_LCD_DATA_ADDR)=(kal_uint8)((frame_color&0xFF00)>>8);
		*((volatile unsigned char *) MAIN_LCD_DATA_ADDR)=(kal_uint8)(frame_color&0xFF); 	 
  #elif (defined(MAIN_LCD_9BIT_MODE))
		*((volatile unsigned short *) MAIN_LCD_DATA_ADDR)=((r_color<<3)|(g_color>>3));
		*((volatile unsigned short *) MAIN_LCD_DATA_ADDR)=((g_color&0x38)<<6)|b_color ;
  #elif (defined(MAIN_LCD_16BIT_MODE) || defined(MAIN_LCD_18BIT_MODE))
		*((volatile unsigned int *) MAIN_LCD_DATA_ADDR)=(r_color<<12)|(g_color<<6)|b_color;
  #endif
#endif
   }
}

TS_LCD_Funcs TS_LCD_func_ST7789S = {
   LCD_init_tiny_lcd_ST7789S,
   LCD_deinit_tiny_lcd_ST7789S,
   LCD_TinyBlockWrite_ST7789S
};


void TS_LCD_FunConfig(void)
{
   TSLCD = &TS_LCD_func_ST7789S;
}
#endif
