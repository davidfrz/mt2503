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
 *	 gdi_primitive.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Primitive related.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "gd_primitive.h"
#include "stdlib.h"
#include "math.h"
#include "gdi_const.h"
#include "gdi_include.h"

#include "kal_general_types.h"
#include "kal_release.h"
#include "string.h"
#include "lcd_sw_rnd.h"
#include "setjmp.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"

#include "gdi_datatype.h"
#include "gdi_mutex.h"
#include "gdi_primitive.h"
#include "gd_include.h"
#include "gd_primitive_arm.h"

#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"

#include "gdi_internal.h"
#include "med_global.h"
#include "med_utility.h"


//warning
extern void gdi_img_buf_blending_color_PARGB6666(
    gdi_img_buf_struct *dst_buf, 
    gdi_color pargb8888_color,
    S32 width,
    S32 height);


#if !defined(GDI_SLIM_COLOR_FORMAT) || defined(GDI_LAYER_PARGB6666_SUPPORT)
void gdi_memset24(U8* address,U32 pixel,int size);
#endif
void gdi_memset32(U8* address,U32 pixel,int size);

/****************************************************************************
* Global variable 
*****************************************************************************/

jmp_buf						gdi_jmpbuf;
BOOL						gdi_jmpbuf_is_used=FALSE;

/****************************************************************************
* MACRO
*****************************************************************************/
#define SWAP(t,a,b) do {t tmp=a;a=b;b=tmp;} while(0)

/* check if pixel within clip, if not will return */
#define	GDI_CLIP_POINT_TEST(x, y)\
{\
	if( (x < GDI_LAYER.clipx1) || (x > GDI_LAYER.clipx2) ||\
		(y < GDI_LAYER.clipy1) || (y > GDI_LAYER.clipy2) )\
	{\
		GDI_RETURN_VOID;	\
	}\
}

#define	GDI_CLIP_TEXT_POINT_TEST(x, y)\
{\
	if( (x < GDI_LAYER.act_text_clip.x1) || (x > GDI_LAYER.act_text_clip.x2) ||\
		(y < GDI_LAYER.act_text_clip.y1) || (y > GDI_LAYER.act_text_clip.y2) )\
	{\
		GDI_RETURN_VOID;	\
	}\
}


#define GDI_CLIP_LINE_X_TEST(X1, X2)\
{\
	if(X1 < GDI_LAYER.clipx1)\
		X1 = GDI_LAYER.clipx1;\
	if(X2 > GDI_LAYER.clipx2)\
		X2 = GDI_LAYER.clipx2;\
}

#define GDI_CLIP_LINE_Y_TEST(Y1, Y2)\
{\
	if(Y1 < GDI_LAYER.clipy1)\
		Y1 = GDI_LAYER.clipy1;\
	if(Y2 > GDI_LAYER.clipy2)\
		Y2 = GDI_LAYER.clipy2;\
}

#define GDI_CLIP_LINE_XY_TEST(x1,y1,x2,y2)\
{\
	if(x1 < GDI_LAYER.clipx1)\
		x1 = GDI_LAYER.clipx1;\
	if(x2 > GDI_LAYER.clipx2)\
		x2 = GDI_LAYER.clipx2;\
	if(y1 < GDI_LAYER.clipy1)\
		y1 = GDI_LAYER.clipy1;\
	if(y2 > GDI_LAYER.clipy2)\
		y2 = GDI_LAYER.clipy2;\
}

#define AA_LINE_PRECISION_BITS 16
#define AA_LINE_FLOAT ((S32)((float)(x)*(float)(1 << AA_LINE_PRECISION_BITS)))


/*****************************************************************************
 * FUNCTION
 *  GAUSSIAN_INTEGRAL
 * DESCRIPTION
 *  return the value of gaussian integral
 * PARAMETERS
 *  dis         [IN]    the x (the distance from x to zero point)
 *  integral    [OUT]   the integral of gaussian from dis to infinity
 * RETURNS
 *  void
 *****************************************************************************/
#define GAUSSIAN_INTEGRAL(dis, integral)                    \
do                                                          \
{                                                           \
    S32 idx;                                                \
    if (dis > (2 << AA_LINE_PRECISION_BITS) ||              \
        dis < -(2 << AA_LINE_PRECISION_BITS))               \
    {                                                       \
        integral = 0;                                       \
    }                                                       \
    if (dis >= 0)                                           \
    {                                                       \
        idx = (dis * 10) >> AA_LINE_PRECISION_BITS;         \
        integral = gaussian_integral[idx];                  \
    }                                                       \
    else                                                    \
    {                                                       \
        dis = -dis;                                         \
        idx = (dis * 10) >> AA_LINE_PRECISION_BITS;         \
        integral = ((1 << AA_LINE_PRECISION_BITS) -         \
                    gaussian_integral[idx]);                \
    }                                                       \
} while(0)


/*****************************************************************************
 * FUNCTION
 *  ANTIALIASING_LINE_PUT_PIXEL
 * DESCRIPTION
 *  put pixel in gdi_draw_antialiasing_line
 * PARAMETERS
 *  x           [IN]    x (position of the point to be draw)
 *  y           [IN]    y
 *  lineR       [IN]    the red color of line
 *  lineG       [IN]    the green color of line
 *  lineB       [IN]    the blue color of line
 *  dis_to_line [IN]    the distance that the pixel to the line
 * RETURNS
 *  void
 *****************************************************************************/
#define ANTIALIASING_LINE_PUT_PIXEL(x, y, lineR, lineG, lineB, dis_to_line)                         \
do                                                                                                  \
{                                                                                                   \
    U32 bgA, bgR, bgG, bgB;                                                                         \
    /*U32 lineA, lineR, lineG, lineB;*/                                                             \
    U32 colorR, colorG, colorB;                                                                     \
    gdi_color bg_color;                                                                             \
    S32 integral, integral_inver, g1, g2, dis1, dis2;                                               \
                                                                                                    \
    dis1 = abs(dis_to_line) - (1 << (AA_LINE_PRECISION_BITS-1));                                    \
    dis2 = abs(dis_to_line) + (1 << (AA_LINE_PRECISION_BITS-1));                                    \
    GAUSSIAN_INTEGRAL(dis1, g1);                                                                    \
    GAUSSIAN_INTEGRAL(dis2, g2);                                                                    \
    integral = g1 - g2;                                                                             \
    integral_inver = (1 << AA_LINE_PRECISION_BITS) - integral;                                      \
    bg_color = gdi_act_get_pixel(x, y);                                                             \
    gdi_act_color_to_rgb(&bgA, &bgR, &bgG, &bgB, bg_color);                                         \
    /* if background color is transparent color, use color in abm_src_layer */                      \
    if (bg_color == source_key_value && source_key_enable && abm_src_layer != GDI_ERROR_HANDLE)     \
    {                                                                                               \
        bg_color = src_layer_get_pixel(src_layer_buf_ptr, src_layer_layer_width, x, y); \
        src_layer_color_to_rgb(&bgA, &bgR, &bgG, &bgB, bg_color);                               \
    }                                                                                               \
    colorR = (U32)((integral_inver * bgR) + (integral * lineR)) >> AA_LINE_PRECISION_BITS;          \
    colorG = (U32)((integral_inver * bgG) + (integral * lineG)) >> AA_LINE_PRECISION_BITS;          \
    colorB = (U32)((integral_inver * bgB) + (integral * lineB)) >> AA_LINE_PRECISION_BITS;          \
    gdi_draw_point(x, y, gdi_act_color_from_rgb(bgA, colorR, colorG, colorB));                   \
}while(0)

/* draw horizontal line */
__inline void GDI_DRAW_H_LINE(S32 x1, S32 x2, S32 y, gdi_color pixel_color)
{
	GDI_ENTER_CRITICAL_SECTION(GDI_DRAW_H_LINE)
		S32	h_index;
		for(h_index = x1; h_index <= x2; h_index++)
		{
			GDI_SET_BUFFER_PIXEL(h_index, y, pixel_color);
		}
	GDI_EXIT_CRITICAL_SECTION(GDI_DRAW_H_LINE)
}

__inline void GDI_DRAW_H_LINE_STYLE(S32 x1, S32 x2, S32 y, gdi_color pixel_color, U8 cycle, const U8 *bitvalues)
{
	GDI_ENTER_CRITICAL_SECTION(GDI_DRAW_H_LINE_STYLE)
		S32		h_index;
		kal_uint8 bitcount;
		for(h_index = x1, bitcount=0; h_index <= x2; h_index++, bitcount++, bitcount %= cycle)
		{
			if (bitvalues[bitcount])
			{
				GDI_SET_BUFFER_PIXEL(h_index, y, pixel_color);
			}
		}
	GDI_EXIT_CRITICAL_SECTION(GDI_DRAW_H_LINE_STYLE)
}

/* draw vertical line */
__inline void GDI_DRAW_V_LINE(S32 y1, S32 y2, S32 x, gdi_color pixel_color)
{
	GDI_ENTER_CRITICAL_SECTION(GDI_DRAW_V_LINE)
		S32	v_index;

		for(v_index = y1; v_index <= y2; v_index++)
		{
			GDI_SET_BUFFER_PIXEL(x,v_index,pixel_color);
		}
	GDI_EXIT_CRITICAL_SECTION(GDI_DRAW_V_LINE)
}

__inline void GDI_DRAW_V_LINE_STYLE(S32 y1, S32 y2, S32 x, gdi_color pixel_color, kal_uint8 cycle, const kal_uint8 *bitvalues)
{
	GDI_ENTER_CRITICAL_SECTION(GDI_DRAW_V_LINE_STYLE)
		S32		v_index;
		U8		bitcount;
		for(v_index = y1, bitcount=0; v_index <= y2; v_index++, bitcount++, bitcount %= cycle)
		{
			if (bitvalues[bitcount])
			{
				GDI_SET_BUFFER_PIXEL(x, v_index, pixel_color);
			}
		}
	GDI_EXIT_CRITICAL_SECTION(GDI_DRAW_V_LINE_STYLE)
}

static __inline void GDI_DRAW_RECT(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color pixel_color)
{
	S32	r_index;
	for(r_index = y1; r_index <=y2; r_index++)
	{
		GDI_DRAW_H_LINE(x1, x2, r_index, pixel_color);
	}
}

static __inline void GDI_DRAW_RECT16(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color pixel_color)
{
	U8* dest = GDI_LAYER.buf_ptr + ((x1+y1*GDI_LAYER.width)<<1);

	y2 -=y1; 
	y2++;

	x2-=x1;
	x2++;
	x2<<=1;
	x1 = GDI_LAYER.width<<1;
	
	while(y2--)
	{
		gdi_memset16(dest,(U16)pixel_color,x2);
		dest +=x1;
	}
}
#if !defined(GDI_SLIM_COLOR_FORMAT)

#ifdef GDI_PRIMITIVE_24_BIT_SUPPORT
static __inline void GDI_DRAW_RECT24(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color pixel_color)
{
	U8* dest = GDI_LAYER.buf_ptr + ((x1+y1*GDI_LAYER.width) * 3);

	y2 -=y1; 
	y2++;

	x2-=x1;
	x2++;
	x2 *= 3;
	x1 = GDI_LAYER.width * 3;
	
	while(y2--)
	{
		gdi_memset24(dest,(U32)pixel_color,x2);
		dest +=x1;
	}
}
#endif

#endif
static __inline void GDI_DRAW_RECT32(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color pixel_color)
{
	U8* dest = GDI_LAYER.buf_ptr + ((x1+y1*GDI_LAYER.width)<<2);

	y2 -=y1; 
	y2++;

	x2-=x1;
	x2++;
	x2<<=2;
	x1 = GDI_LAYER.width<<2;
	
	while(y2--)
	{
		gdi_memset32(dest,(U32)pixel_color,x2);
		dest +=x1;
	}
}

static void gdi_color_interpolate(gdi_color color0, gdi_color color1, U32 orig_ratio, gdi_color *result)
{
    U32 a0,r0,g0,b0;
    U32 a1,r1,g1,b1;
    U32 _100_RATIO = 100 - orig_ratio;
    gdi_act_color_to_rgb(&a0, &r0, &g0, &b0, color0);
    gdi_act_color_to_rgb(&a1, &r1, &g1, &b1, color1);
    *result = gdi_act_color_from_rgb(
                    (a0 * orig_ratio + a1 * _100_RATIO) / 100,
                    (r0 * orig_ratio + r1 * _100_RATIO) / 100,
                    (g0 * orig_ratio + g1 * _100_RATIO) / 100,
                    (b0 * orig_ratio + b1 * _100_RATIO) / 100);
}
/**************************************************************

	FUNCTION NAME		: gdi_draw_point()

  	PURPOSE				: draw a point

	INPUT PARAMETERS	: S32			x
							  S32			y
							  gdi_color pixel_color

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
__inline void gdi_draw_point(S32 x, S32 y, gdi_color pixel_color)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_draw_point)
		GDI_CLIP_POINT_TEST(x,y);
		GDI_SET_BUFFER_PIXEL(x,y,pixel_color);
	GDI_EXIT_CRITICAL_SECTION(gdi_draw_point)
}

void gdi_draw_line_ext(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color, BOOL is_dotted)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_draw_line_ext)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL steep;                                             /* y-scan or x-scan */
    S32 slope, dx, dy, d, incrE, incrNE, x, y;              /* slope is the direction that y goes */
    S32 rate, tmp;                                          /* used in cliping */
    S32 clipx1, clipx2, clipy1, clipy2;                     /* the clip area */
    BOOL draw_dot = TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((GDI_LAYER.clipy1 <= GDI_LAYER.clipy2) && (GDI_LAYER.clipx1 <= GDI_LAYER.clipx2));

    {
        clipx1 = x1;    /* clipx1,y1,x2,y2 is only used as tmp variables here */
        clipy1 = y1;
        clipx2 = x2;
        clipy2 = y2;
        if (x1 > x2)
        {
            clipx1 = x2;
            clipx2 = x1;
        }
        if (y1 > y2)
        {
            clipy1 = y2;
            clipy2 = y1;
        }
        /* return if the line is not in the clip region */
        GDI_CLIP_RECT_TEST(clipx1, clipy1, clipx2, clipy2, GDI_RETURN_VOID);
    }
    
    if ((!is_dotted) && (y1 == y2) && (y1 >= GDI_LAYER.clipy1) && (y1 <= GDI_LAYER.clipy2)) // Horizontal Line /
	{
		if(x1 > x2)     // exchange x /
		{
		    tmp = x1;
            x1 = x2;
            x2 = tmp;
		}
        if((x1 <= GDI_LAYER.clipx2) && (x2 >= GDI_LAYER.clipx1))
        {
            GDI_CLIP_LINE_X_TEST(x1,x2);
            GDI_DRAW_H_LINE(x1, x2, y1, line_color);
    	}
	}
	else if ((!is_dotted) && (x1 == x2) && (x1 >= GDI_LAYER.clipx1) && (x1 <= GDI_LAYER.clipx2)) // Vertical Line /
    {
		if(y1 > y2)     // exchange y /
		{
			tmp = y1;
            y1 = y2;
            y2 = tmp;
		}
        if((y1 <= GDI_LAYER.clipy2) && (y2 >= GDI_LAYER.clipy1))
        {
            GDI_CLIP_LINE_Y_TEST(y1,y2);
            GDI_DRAW_V_LINE(y1, y2, x1, line_color);
	    }
	}
    else
    {
        /* clip */
        gdi_layer_get_clip(&clipx1, &clipy1, &clipx2, &clipy2);

        if (x1 > x2)    
        {
            /* exchange two points: (x1,y1) and (x2,y2)*/
            tmp = x1;
            x1 = x2;
            x2 = tmp;

            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        dx = x2 - x1;
        dy = y2 - y1;
        
        if (dx == 0)
        {
            rate = 0;
        }
        else
        {
            rate = (dy << 20) / dx;
        }
        
        if (y1 <= y2) 
    	{
    		if (y1 < clipy1) 
    		{
    			int orgy = y1;
    			y1 = clipy1;
    			if (y1 > y2)
    				GDI_RETURN_VOID;
    			x1 = x1 - ((orgy - y1) * dx) / dy;
    		}

    		if (y2 > clipy2) 
    		{
    			int orgy = y2;
    			y2 = clipy2;
    			if (y1 > y2)
    				GDI_RETURN_VOID;
    			x2 = x2 - ((orgy - y2) * dx) / dy;
    		}
    	} 
    	else 
    	{ /* y1 > y2 */
    		if (y2 < clipy1) 
    		{
    			int orgy = y2;
    			y2 = clipy1;
    			if (y2 > y1)
    				GDI_RETURN_VOID;
    			x2 = x2 - ((orgy - y2) * dx) / dy;
    		}

    		if (y1 > clipy2) 
    		{
    			int orgy = y1;
    			y1 = clipy2;
    			if (y2 > y1)
    				GDI_RETURN_VOID;
    			x1 = x1 - ((orgy - y1) * dx) / dy;
    		}
    	}

    	if (x1 < clipx1) 
    	{
    		int orgx = x1;
    		x1 = clipx1;
    		if (x1 > x2)
    			GDI_RETURN_VOID;
    		y1 = y1 - (((orgx - x1) * rate) >> 20);
    	}

    	if (x2 > clipx2) 
    	{
    		int orgx = x2;
    		x2 = clipx2;
    		if (x1 > x2)
    			GDI_RETURN_VOID;
    		y2 = y2 - (((orgx - x2) * rate) >> 20);
    	}
        
        /* if the slope>1, need to exchange x-axis and y-axis */
        steep = (abs(y2 - y1) > abs(x2 - x1));  
        if (steep)
        {
            /* exchange x1 and y1, x2 and y2 */
            tmp = x1;
            x1 = y1;
            y1 = tmp;

            tmp = x2;
            x2= y2;
            y2 = tmp;
        }
        
        if (x1 > x2)    
        {
            /* exchange two points: (x1,y1) and (x2,y2) */
            tmp = x1;
            x1 = x2;
            x2 = tmp;

            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        
        dx = x2 - x1;
        dy = y2 - y1;
        
        if (dy < 0)
        {
            slope = -1;
            dy = -dy;
        }
        else
        {
            slope = 1;
        }

        /* variables for mid-point draw line algorithm */
        d = (2 * dy) - dx;
        incrE = 2 * dy;
        incrNE = 2 * (dy - dx);

        for (x = x1, y = y1; x <= x2; x++)
        {
            S32 outx, outy;
            if (steep)
            {
                outx = y;
                outy = x;
            }
            else
            {
                outx = x;
                outy = y;
            }

            if (is_dotted)
            {
                if (draw_dot == FALSE)
                {
                    draw_dot = TRUE;
                }
                else
                {
                    GDI_CLIP_POINT_TEST(outx,outy);
                    gdi_act_put_pixel(outx, outy, line_color);
                    draw_dot = FALSE;
                }
            }
            else
            {
                GDI_CLIP_POINT_TEST(outx,outy);
                gdi_act_put_pixel(outx, outy, line_color);
            }
 
            if (d < 0)
            {
                d += incrE;
            }
            else
            {
                d += incrNE;
                y += slope;
            }
        }
    }
 
    GDI_EXIT_CRITICAL_SECTION(gdi_draw_line_ext)
}


/**************************************************************

	FUNCTION NAME		: gdi_draw_line()

  	PURPOSE				: draw a line

	INPUT PARAMETERS	: S32			x1
							  S32			y1
							  S32			x2
							  S32			y2
							  gdi_color line_color

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_draw_line(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color)
{
	gdi_draw_line_ext(x1,y1,x2,y2, line_color,FALSE);
}


/**************************************************************

	FUNCTION NAME		: gdi_draw_line_style()

  	PURPOSE				: draw a style line

	INPUT PARAMETERS	: S32			x1
							  S32			y1
							  S32			x2
							  S32			y2
							  gdi_color line_color
							  U8			cycle
							  const U8  *bitvalues
	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_draw_line_style(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color, U8 cycle, const U8 *bitvalues)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_draw_line_style)
		if(y1 - y2 == 0) /* Horizontal Line */
		{
			/* within valid y clip */
			if((y1 >= GDI_LAYER.clipy1) && (y1 <= GDI_LAYER.clipy2))
			{
				if((x1 < x2) && (x1 <= GDI_LAYER.clipx2) && (x2 >= GDI_LAYER.clipx1))
				{
					GDI_CLIP_LINE_X_TEST(x1,x2);
					GDI_DRAW_H_LINE_STYLE(x1, x2, y1, line_color, cycle, bitvalues);
				}
				else if((x1 >= x2) && (x2 <= GDI_LAYER.clipx2) && (x1 >= GDI_LAYER.clipx1))
				{
					GDI_CLIP_LINE_X_TEST(x2,x1);
					GDI_DRAW_H_LINE_STYLE(x2, x1, y1, line_color, cycle, bitvalues);
				}
			}
		}
		else if(x1 - x2 == 0) /* Vertical Line */
		{
			/* within valid x clip */
			if((x1 >= GDI_LAYER.clipx1) && (x1 <= GDI_LAYER.clipx2))
			{
				if((y1 < y2) && (y1 <= GDI_LAYER.clipy2) && (y2 >= GDI_LAYER.clipy1))
				{
					GDI_CLIP_LINE_Y_TEST(y1,y2);
					GDI_DRAW_V_LINE_STYLE(y1, y2, x1, line_color, cycle, bitvalues);
				}
				else if((y1 >= y2) && (y2 <= GDI_LAYER.clipy2) && (y1 >= GDI_LAYER.clipy1))
				{
					GDI_CLIP_LINE_Y_TEST(y2,y1);
					GDI_DRAW_V_LINE_STYLE(y2, y1, x1, line_color, cycle, bitvalues);
				}
			}
		}
		else
		{
			gdi_draw_line_ext(x1,y1,x2,y2, line_color,TRUE); //FIXME: should support real dotted & cycle
		}
	GDI_EXIT_CRITICAL_SECTION(gdi_draw_line_style)
}



/**************************************************************

	FUNCTION NAME		: gdi_draw_rect()

  	PURPOSE				: draw a rect (border only)

	INPUT PARAMETERS	: S32			x1
							  S32			y1
							  S32			x2
							  S32			y2
							  gdi_color frame_color

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_draw_rect(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color frame_color)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_draw_rect)
		S32 nx1,ny1,nx2,ny2;

		nx1 = x1;
		ny1 = y1;
		nx2 = x2;
		ny2 = y2;

		GDI_CLIP_RECT_TEST(nx1,ny1,nx2,ny2,GDI_RETURN_VOID);

		if(GDI_LAYER.clipy1<= y1 && y1 <= GDI_LAYER.clipy2)
			GDI_DRAW_H_LINE(nx1, nx2, y1, frame_color);	/* up horizontal */

		if(GDI_LAYER.clipy1<= y2 && y2 <= GDI_LAYER.clipy2)
			GDI_DRAW_H_LINE(nx1, nx2, y2, frame_color);	/* down horizontal */

		if(GDI_LAYER.clipx1<= x1 && x1 <= GDI_LAYER.clipx2)
			GDI_DRAW_V_LINE(ny1, ny2, x1, frame_color);	/* left vertical */

		if(GDI_LAYER.clipx1<= x2 && x2 <= GDI_LAYER.clipx2)
			GDI_DRAW_V_LINE(ny1, ny2, x2, frame_color);	/* right vertical */
		
	GDI_EXIT_CRITICAL_SECTION(gdi_draw_rect)
}



/**************************************************************

	FUNCTION NAME		: gdi_draw_solid_rect()

  	PURPOSE				: draw a solid rect

	INPUT PARAMETERS	: S32			x1
							  S32			y1
							  S32			x2
							  S32			y2
							  gdi_color rect_color

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_draw_solid_rect(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color rect_color)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_draw_solid_rect)
    do
    {
        GDI_CLIP_RECT_TEST(x1,y1,x2,y2,break);
    
        if(GDI_LAYER.bits_per_pixel == 16)
        {
            if (GDI_LAYER.cf == GDI_COLOR_FORMAT_UYVY422)
            {
                rect_color = 0x0080; /* Only support clear to black */
            }
        
            GDI_DRAW_RECT16(x1, y1, x2, y2, rect_color);
        }
        else if ((GDI_LAYER.bits_per_pixel == 32) && (rect_color == GDI_COLOR_TRANSPARENT))
        {   /* speed up 32-bit performance by memset(), it is safe to replace GDI_COLOR_TRANSPARENT as 0 since both alpha = 0 */
            U32 *p;
            S32 line_width, pitch; 
            S32 y;

            line_width = x2 - x1 + 1;
            pitch = GDI_LAYER.width;
            p = (U32*)GDI_LAYER.buf_ptr + x1 + y1 * pitch;

            for (y = y2 - y1; y >= 0; y--)
            {
                memset(p, 0, line_width * 4);
                p += pitch; 
            }               
        }
#if !defined(GDI_SLIM_COLOR_FORMAT)
    #ifdef GDI_PRIMITIVE_24_BIT_SUPPORT
        else if (GDI_LAYER.bits_per_pixel == 24)
        {
            kal_uint32 cbyte = (rect_color & 0xff);
            if (cbyte == (rect_color << 16 >> 24) &&
                cbyte == (rect_color << 8 >> 24))
            {
                kal_uint32 pitch;
                kal_int32 line_width;
                kal_int32 line_count;
                kal_uint8 *line_ptr;

                line_width = (x2 - x1 + 1) * 3;
                pitch = GDI_LAYER.width * 3;
                line_ptr = (kal_uint8*)GDI_LAYER.buf_ptr + y1 * pitch + x1 * 3;
                for (line_count = y2 - y1; line_count >= 0; line_count--)
                {
                    memset(line_ptr, cbyte, line_width);
                    line_ptr += pitch;
                }
            }
            else
            {
                GDI_DRAW_RECT24(x1, y1, x2, y2, rect_color);
            }
        }
    #endif
#endif
        else if(GDI_LAYER.bits_per_pixel == 32)
        {
            GDI_DRAW_RECT32(x1, y1, x2, y2, rect_color);                
        }
        else
        {
            GDI_DRAW_RECT(x1, y1, x2, y2, rect_color);
        }
    }while(0);
    GDI_EXIT_CRITICAL_SECTION(gdi_draw_solid_rect)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_draw_darken_rect
 * DESCRIPTION
 *  Darken all pixels in a rectangle. Trasnparent pixels are not supported.
 * PARAMETERS
 *  x1                 [IN]     x1
 *  y1                 [IN]     y1
 *  x2                 [IN]     x2
 *  y2                 [IN]     y2
 *  brightness_value   [IN]     brightness. Range: 0 (darkest) to 100 (brightest).
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_draw_darken_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 brightness_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_draw_darken_rect)	

    do
    {
        GDI_CLIP_RECT_TEST(x1, y1, x2, y2, break);

        /* use alpha blending to achieve the darken effect */
        // TODO: Use a dedicated function for darkening.
        gdi_effect_alpha_blending_rect((gdi_handle)gdi_act_layer, x1, y1, x2, y2, (100 - brightness_value) * 256 / 100, 0, 0, 0);
    } while(0);

    GDI_EXIT_CRITICAL_SECTION(gdi_draw_darken_rect)        
}


void gdi_draw_greyscale_rect(S32 x1,S32 y1,S32 x2,S32 y2, S32 white_value,S32 black_value)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_draw_greyscale_rect)	
	S32 x, y;
	gdi_color color;
	U32 a,r, g, b;//, max, min;
	gd_get_pixel_func get_ptr = gd_get_pixel[gdi_act_layer->cf];
	gd_put_pixel_func put_ptr = gd_put_pixel[gdi_act_layer->cf];
	S32 BW256,WB_B;

	GDI_CLIP_RECT_TEST(x1,y1,x2,y2,GDI_RETURN_VOID);
	
		{
			black_value = 256 - black_value;
		
			BW256 = (white_value*black_value)<<8;
		
			WB_B = black_value*(256 - white_value);
		
			for (y = y1; y <= y2; y++)
			{
				for (x = x1; x <= x2; x++)
				{
					color = get_ptr(x,y);
					gdi_act_color_to_rgb(&a,&r,&g,&b,color);
					r = (r + g + b)/3;
					//r = r + (256-r) * w / 256
					//r = r * b / 256
					r = (BW256 + r*WB_B) >> 16;
					if (r > 255)
						r = 255;
					put_ptr(x,y,gdi_act_color_from_rgb(a,r,r,r));
				}
			}
		}
	GDI_EXIT_CRITICAL_SECTION(gdi_draw_greyscale_rect)	
}


void gdi_effect_alpha_blending_rect_16(
        gdi_handle src_layer_handle,
        S32 x1,
        S32 y1,
        S32 x2,
        S32 y2,
        U32 transparent_color_a,
        U32 transparent_color_r,
        U32 transparent_color_g,
        U32 transparent_color_b)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_effect_alpha_blending_rect_16)
    
    do {
        gdi_layer_struct *src_layer, *dest_layer;
        kal_uint32 src_pitch, dest_pitch;
        kal_uint32 src_delta, dest_delta;
        kal_uint8 *src_buffer, *dest_buffer;
        kal_int32 pixel_count, line_count;
        kal_int32 inv_a;
        kal_uint32 color_prgb888;
        
        src_layer = (gdi_layer_struct*)src_layer_handle;
        dest_layer = gdi_act_layer;

        GDI_ASSERT(src_layer->bits_per_pixel == 16 && dest_layer->bits_per_pixel == 16);

        GDI_CLIP_RECT_TEST(x1, y1, x2, y2, break);

        src_pitch = src_layer->width * 2;
        dest_pitch = dest_layer->width * 2;
        src_buffer = src_layer->buf_ptr + src_pitch * y1 + x1 * 2;
        dest_buffer = dest_layer->buf_ptr + dest_pitch * y1 + x1 * 2;
        src_delta = src_pitch - (x2 - x1 + 1) * 2;
        dest_delta = dest_pitch - (x2 - x1 + 1) * 2;
        color_prgb888 = GDI_PARGB8888(
            0,
            GDI_DIV_255(transparent_color_r * transparent_color_a),
            GDI_DIV_255(transparent_color_g * transparent_color_a),
            GDI_DIV_255(transparent_color_b * transparent_color_a));
        inv_a = 255 - transparent_color_a;
        for (line_count = (y2 - y1 + 1); line_count > 0; line_count--)
        {
            for (pixel_count = (x2 - x1 + 1); pixel_count > 0; pixel_count--)
            {
                register kal_uint32 rgb565, rgb888;
                kal_uint32 r, g, b;
                
                rgb565 = GDI_MEM_GET_16(src_buffer);
                rgb888 = GDI_RGB888_FROM_RGB565(rgb565);
                r = GDI_DIV_255(GDI_R_OF_RGB888(rgb888) * inv_a);
                g = GDI_DIV_255(GDI_G_OF_RGB888(rgb888) * inv_a);
                b = GDI_DIV_255(GDI_B_OF_RGB888(rgb888) * inv_a);
                rgb888 = GDI_RGB888(r, g, b);
                rgb888 += color_prgb888;
                rgb565 = GDI_RGB565_FROM_RGB888(rgb888);

                GDI_MEM_PUT_16(dest_buffer, rgb565);

                src_buffer += 2;
                dest_buffer += 2;
            }

            src_buffer += src_delta;
            dest_buffer += dest_delta;
        }
    } while (0);
    
    GDI_EXIT_CRITICAL_SECTION(gdi_effect_alpha_blending_rect_16)
}


void gdi_effect_alpha_blending_rect_ex(
                                gdi_handle src_layer_handle,
                                S32 x1,S32 y1,S32 x2,S32 y2, 
                                U32 transparent_color_a,
                                U32 transparent_color_r,
                                U32 transparent_color_g,
                                U32 transparent_color_b)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_effect_alpha_blending_rect_ex)	
    {
		S32 x, y;
		gdi_color color;
		U32 a, r, g, b;
        gdi_layer_struct *src_layer = (gdi_layer_struct*) src_layer_handle;
		U8* src_buf = src_layer->buf_ptr;
		S32 src_layer_width = src_layer->width;
		gd_get_buf_pixel_func get_ptr = gd_get_buf_pixel[src_layer->cf];
        gd_color_to_rgb_func src_color_to_rgb = gd_color_to_rgb[src_layer->cf];
        
		S32 opacity_value = transparent_color_a * 256 / 255;
		S32 inverse_opacity_value = 256 - transparent_color_a * 256 / 255;
		S32 offset_x = gdi_act_layer->offset_x - src_layer->offset_x;
		S32 offset_y = gdi_act_layer->offset_y - src_layer->offset_y;

        transparent_color_a *= 256;
		transparent_color_r *= opacity_value;
		transparent_color_g *= opacity_value;
		transparent_color_b *= opacity_value;

		GDI_CLIP_RECT_TEST(x1,y1,x2,y2,break);

		for (y = y1; y <= y2; y++)
		{
			for (x = x1; x <= x2; x++)
			{
				color = get_ptr(src_buf,src_layer_width,x + offset_x,y + offset_y);
				src_color_to_rgb(&a,&r,&g,&b,color);
				a = ((transparent_color_a) +  (a * inverse_opacity_value)) >> 8;
				r = ((transparent_color_r) +  (r * inverse_opacity_value)) >> 8;
				g = ((transparent_color_g) +  (g * inverse_opacity_value)) >> 8;
				b = ((transparent_color_b) +  (b * inverse_opacity_value)) >> 8;
                gdi_act_put_pixel(x,y,gdi_act_color_from_rgb(a,r,g,b));
			}
		}
    }
	GDI_EXIT_CRITICAL_SECTION(gdi_effect_alpha_blending_rect_ex)
}

void gdi_effect_alpha_blending_rect(gdi_handle src_layer_handle,S32 x1,S32 y1,S32 x2,S32 y2, U32 transparent_color_a,U32 transparent_color_r,U32 transparent_color_g,U32 transparent_color_b)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_effect_alpha_blending_rect_ex)
	{
        gdi_layer_struct *src = ((gdi_layer_struct*)src_layer_handle);
        
        GDI_DEBUG_ASSERT(src_layer_handle);

        if(src->bits_per_pixel == 16 && gdi_act_layer->bits_per_pixel == 16 
        && gdi_act_color_from_rgb(0xff,0,255,0) == 0x07e0 ) // standard rgb565
            gdi_effect_alpha_blending_rect_16(src_layer_handle, x1, y1, x2, y2, transparent_color_a, transparent_color_r, transparent_color_g, transparent_color_b);
        else
            gdi_effect_alpha_blending_rect_ex(src_layer_handle, x1, y1, x2, y2, transparent_color_a, transparent_color_r, transparent_color_g, transparent_color_b);
	}
	GDI_EXIT_CRITICAL_SECTION(gdi_effect_alpha_blending_rect_ex)
}

/**************************************************************

	FUNCTION NAME		: gdi_draw_frame_rect()

  	PURPOSE				: draw a rect with frame and filling.

	INPUT PARAMETERS	: S32			x1
							  S32			y1
							  S32			x2
							  S32			y2
							  gdi_color rect_color
							  gdi_color	frame_color
							  S32			frame_width

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_draw_frame_rect(	S32 x1, S32 y1, S32 x2, S32 y2, gdi_color	rect_color, gdi_color	frame_color, S32			frame_width)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_draw_frame_rect)
		S32 i;

		GDI_CLIP_RECT_TEST(x1,y1,x2,y2,GDI_RETURN_VOID);

		/* draw interial color */
		GDI_DRAW_RECT(x1+frame_width, y1+frame_width, x2-frame_width, y2-frame_width, rect_color);

		/* draw frame */
		for( i = 0 ; i < frame_width; i++)
		{
			GDI_DRAW_H_LINE(x1+i, x2-i, y1+i, frame_color);	/* up horizontal */
			GDI_DRAW_H_LINE(x1+i, x2-i, y2-i, frame_color);	/* down horizontal */
			GDI_DRAW_V_LINE(y1+i, y2-i, x1+i, frame_color);	/* left vertical */
			GDI_DRAW_V_LINE(y1+i, y2-i, x2-i, frame_color);	/* right vertical */
		}
	GDI_EXIT_CRITICAL_SECTION(gdi_draw_frame_rect)
}


/**************************************************************

	FUNCTION NAME		: gdi_draw_round_rect()

  	PURPOSE				: draw a rect with round frame

	INPUT PARAMETERS	: S32			x1
							  S32			y1
							  S32			x2
							  S32			y2
							  gdi_color rect_color
							  gdi_color	frame_color
							  S32			frame_width

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_draw_round_rect(	S32 x1, S32 y1, S32 x2, S32 y2, gdi_color	rect_color, gdi_color	frame_color, S32			frame_width)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_draw_round_rect)
		S32			i;
		S32			shift;
		gdi_color	result;

		GDI_CLIP_RECT_TEST(x1,y1,x2,y2,GDI_RETURN_VOID);

		/* draw interial color */
		GDI_DRAW_RECT(x1+frame_width, y1+frame_width, x2-frame_width, y2-frame_width, rect_color);


		/* draw frame */
		for( i = 0 ; i < frame_width; i++)
		{
			shift = frame_width - i;
			GDI_DRAW_H_LINE(x1+ shift, x2-shift, y1+i, frame_color);	/* up horizontal */
			GDI_DRAW_H_LINE(x1+ shift, x2-shift, y2-i, frame_color);	/* down horizontal */
			GDI_DRAW_V_LINE(y1+shift, y2-shift, x1+i, frame_color);	/* left vertical */
			GDI_DRAW_V_LINE(y1+shift, y2-shift, x2-i, frame_color);	/* right vertical */
		}

		/* draw anti_aliase pixels, make it smooth */
		gdi_color_interpolate(frame_color, rect_color, 10, &result);

		GDI_SET_BUFFER_PIXEL(x1+frame_width+1, y1+frame_width, result);
		GDI_SET_BUFFER_PIXEL(x1+frame_width,	y1+frame_width+1, result);

		GDI_SET_BUFFER_PIXEL(x1+frame_width+1, y2-frame_width, result);
		GDI_SET_BUFFER_PIXEL(x1+frame_width,	y2-frame_width-1, result);

		GDI_SET_BUFFER_PIXEL(x2-frame_width-1, y1+frame_width, result);
		GDI_SET_BUFFER_PIXEL(x2-frame_width,	y1+frame_width+1, result);

		GDI_SET_BUFFER_PIXEL(x2-frame_width-1, y2-frame_width, result);
		GDI_SET_BUFFER_PIXEL(x2-frame_width,	y2-frame_width-1, result);

		gdi_color_interpolate(frame_color, rect_color, 30, &result);

		GDI_SET_BUFFER_PIXEL(x1+frame_width	, y1+frame_width, result);
		GDI_SET_BUFFER_PIXEL(x1+frame_width	, y2-frame_width, result);
		GDI_SET_BUFFER_PIXEL(x2-frame_width	, y1+frame_width, result);
		GDI_SET_BUFFER_PIXEL(x2-frame_width	, y2-frame_width, result);
	GDI_EXIT_CRITICAL_SECTION(gdi_draw_round_rect)
}



/**************************************************************

	FUNCTION NAME		: gdi_draw_button_rect()

  	PURPOSE				: draw a rect with button style

	INPUT PARAMETERS	: S32			x1
							  S32			y1
							  S32			x2
							  S32			y2
							  gdi_color rect_color
							  gdi_color	frame_color
							  S32			frame_width
							  U16			button_height
							  BOOL		invert

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_draw_button_rect(	S32 x1, S32 y1, S32 x2, S32 y2, gdi_color	rect_color, gdi_color	frame_color, U16		frame_width, U16		button_height, BOOL		invert)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_draw_button_rect)
		S32		i;
		U16		shift;
		U16		ratio_light;
		U16		ratio_dark;

		gdi_color result_light;
		gdi_color retult_dark;
		gdi_color black = gdi_act_color_from_rgb(0xff,0,0,0);
		gdi_color white = gdi_act_color_from_rgb(0xff,255,255,255);

		/* draw rect and frame */
		GDI_CLIP_RECT_TEST(x1,y1,x2,y2,GDI_RETURN_VOID);
		gdi_draw_frame_rect(x1, y1, x2, y2, rect_color, frame_color, frame_width);


		/* add button style */
		ratio_light = 70;
		ratio_dark	= 80;
		for(i = 0; i < button_height; i++)
		{
			shift = button_height+frame_width-i-1;
            gdi_color_interpolate(rect_color, white, ratio_light, &result_light);
            gdi_color_interpolate(rect_color, black, ratio_dark, &retult_dark);
            if(invert == TRUE)
            {
                gdi_color tmp;
                tmp = result_light;
                result_light = retult_dark;
                retult_dark = tmp;
            }

			GDI_DRAW_H_LINE(x1+shift, x2-shift-1, y1+shift, result_light);	/* up horizontal */
			GDI_DRAW_V_LINE(y1+shift, y2-shift, x1+shift, result_light);		/* left vertical */

			GDI_DRAW_H_LINE(x1+shift, x2-shift, y2-shift, retult_dark);		/* down vertical */
			GDI_DRAW_V_LINE(y1+shift, y2-shift, x2-shift, retult_dark);		/* left vertical */
			ratio_light = ratio_light - 10;
			ratio_dark	= ratio_dark  - 10;
		}
	GDI_EXIT_CRITICAL_SECTION(gdi_draw_button_rect)
}


/**************************************************************

	FUNCTION NAME		: gdi_draw_shadow_rect()

  	PURPOSE				: draw a rect with shadow style

	INPUT PARAMETERS	: S32			x1
							  S32			y1
							  S32			x2
							  S32			y2
							  gdi_color rect_color
							  gdi_color	frame_color
							  S32			frame_width
							  gdi_color	shadow_color
							  S32		shadow_height

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_draw_shadow_rect(	S32 x1, S32 y1, S32 x2, S32 y2, gdi_color	rect_color, gdi_color	frame_color, S32			frame_width, gdi_color	shadow_color, S32			shadow_height)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_draw_shadow_rect)
		S32		 i;

		/* draw rect and frame */
		GDI_CLIP_RECT_TEST(x1,y1,x2,y2,GDI_RETURN_VOID);
		gdi_draw_frame_rect(x1, y1, x2, y2, rect_color, frame_color, frame_width);

		for( i = 0 ; i < shadow_height; i++)
		{
			GDI_DRAW_H_LINE(x1+i+2, x2+i+1, y2+i+1, shadow_color);	/* horizontal */
			GDI_DRAW_V_LINE(y1+i+2, y2+i+1, x2+i+1, shadow_color);	/* vertical */
		}
	GDI_EXIT_CRITICAL_SECTION(gdi_draw_shadow_rect)
}


/**************************************************************

	FUNCTION NAME		: gdi_draw_gradient_rect()

  	PURPOSE				: draw a rect with gradient filling

	INPUT PARAMETERS	: S32			x1
							  S32			y1
							  S32			x2
							  S32			y2
							  gdi_color rect_color
							  gdi_color	frame_color
							  S32			frame_width
							  gdi_gradient_rect_style_enum style

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_draw_gradient_rect(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color rect_color_start, gdi_color rect_color_end, gdi_color frame_color, S32 frame_width, gdi_gradient_rect_style_enum style)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_draw_gradient_rect)
		S32		 i,j;
		S32		 ratio;
		S32		 size;
		gdi_color result;

		GDI_CLIP_RECT_TEST(x1,y1,x2,y2,GDI_RETURN_VOID);

		switch(style)
		{
		case GDI_GRADIENT_RECT_HOR:
			{
				size = x2 - x1;
				if(size ==0) size = 1;

				for( i = x1 ; i <= x2; i++)
				{
					ratio = (i-x1)*100/size;
					gdi_color_interpolate(rect_color_end, rect_color_start, (U32)ratio, &result);	/* light */
					GDI_DRAW_V_LINE(y1, y2, i, result);	/* left vertical */
				}
				break;
			}

		case GDI_GRADIENT_RECT_VER:
			{
				size = y2 - y1;
				if(size ==0) size = 1;

				for( i = y1 ; i <= y2; i++)
				{
					ratio = (i-y1)*100/size;
					gdi_color_interpolate(rect_color_end, rect_color_start, (U32)ratio, &result);	/* light */
					GDI_DRAW_H_LINE(x1, x2, i, result);	/* left vertical */
				}
				break;
			}
    #ifndef __DISABLE_SANDBOX_LIB__
		case GDI_GRADIENT_RECT_DIA:
			{
				size = (x2-x1) + (y2-y1);

				for( i = y1 ; i <= y2; i++)
				{
					for(j = x1 ; j <= x2; j++)
					{
						ratio = ((i-y1)+(j-x1))*100/size;
						gdi_color_interpolate(rect_color_end, rect_color_start, (U32)ratio, &result);	/* light */
						GDI_SET_BUFFER_PIXEL(j, i, result);
					}
				}
				break;
			}

		case GDI_GRADIENT_RECT_DIA_INV:
			{
				size = (x2-x1) + (y2-y1);

				for( i = x1 ; i <= x2; i++)
				{
					for(j = y1 ; j <= y2; j++)
					{
						ratio = ((i-x1)+(j-y1))*100/size;
						gdi_color_interpolate(rect_color_start, rect_color_end, (U32)ratio, &result);	/* light */
						GDI_SET_BUFFER_PIXEL(i, j, result);
					}
				}
				break;
			}
		case GDI_GRADIENT_RECT_FLIP:
			{
				size = y2 - y1;
				if(size ==0) size = 1;

				for( i = y1 ; i <= y1+((y2-y1)>>1)-1; i++)
				{
					ratio = (i-y1)*2*100/size;
					if (ratio>100) ratio=100;
					gdi_color_interpolate(rect_color_start, rect_color_end, (U32)ratio, &result);	/* light */
					GDI_DRAW_H_LINE(x1, x2, i, result);	/* left vertical */
				}
				for( i = y1+((y2-y1)>>1) ; i <= y2; i++)
				{
					ratio = (y2-i)*2*100/size;
					if (ratio>100) ratio=100;
					gdi_color_interpolate(rect_color_start, rect_color_end, (U32)ratio, &result);	/* light */
					GDI_DRAW_H_LINE(x1, x2, i, result);	/* left vertical */
				}
				break;
			}
        #endif /* __DISABLE_SANDBOX_LIB__ */
		}
		/* draw frame */
		for( i = 0 ; i < frame_width; i++)
		{
			GDI_DRAW_H_LINE(x1+i, x2-i, y1+i, frame_color);	/* up horizontal */
			GDI_DRAW_H_LINE(x1+i, x2-i, y2-i, frame_color);	/* down horizontal */
			GDI_DRAW_V_LINE(y1+i, y2-i, x1+i, frame_color);	/* left vertical */
			GDI_DRAW_V_LINE(y1+i, y2-i, x2-i, frame_color);	/* right vertical */
		}
	GDI_EXIT_CRITICAL_SECTION(gdi_draw_gradient_rect)
}


/**************************************************************

	FUNCTION NAME		: gdi_2d_memory_blt()

  	PURPOSE				: 2d memory blt

	INPUT PARAMETERS	: U8 *src_ptr
							  S32 src_pitch
							  S32 src_offset_x
							  S32 src_offset_y,
							  S32 src_width
							  S32 src_height,
							  U8 *dest_ptr
							  S32 dest_pitch,
							  S32 dest_offset_x
							  S32 dest_offset_y,
							  gdi_rect_struct dest_clip)

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_2d_memory_blt(	
    U8 *src_ptr, 
    S32 src_pitch, 
    S32 src_offset_x, 
    S32 src_offset_y, 
    S32 src_width, 
    S32 src_height, 

    U8 *dest_ptr, 
    S32 dest_pitch, 
    S32 dest_offset_x, 
    S32 dest_offset_y, 
    gdi_rect_struct dest_clip,
    S32 bits_per_pixel
    )
{
	GDI_ENTER_CRITICAL_SECTION(gdi_2d_memory_blt)
{
        gdi_color_format cf = gdi_get_color_format(bits_per_pixel); // not support PARGB and UYVY422
        gd_bitblt[cf](
            dest_ptr,                   // dest
            dest_pitch,                 // dw
            0,                          // dh , un-used
            dest_offset_x,              // dx1
            dest_offset_y,              // dy1
            dest_offset_x+src_width-1,  // dx2
            dest_offset_y+src_height-1, // dy2

            src_ptr,                    // src
            src_pitch,                  // sw
            0,                          // sh , un-used
            src_offset_x,               // sx1
            src_offset_y,               // sy1
            src_offset_x+src_width-1,   // sx2
            src_offset_y+src_height-1,  // sy2
            dest_clip.x1,               
            dest_clip.y1,
            dest_clip.x2,
            dest_clip.y2,
            0x01ffffff,                 // src_key , no color will be 0x1ffffff
            GDI_COLOR_TRANSPARENT);
	}
	GDI_EXIT_CRITICAL_SECTION(gdi_2d_memory_blt)
}


/**************************************************************

	FUNCTION NAME		: gdi_2d_memory_blt_without_transpant_check()

  	PURPOSE				: 2d memory blt

	INPUT PARAMETERS	: U8 *src_ptr
							  S32 src_pitch
							  S32 src_offset_x
							  S32 src_offset_y,
							  S32 src_width
							  S32 src_height,
							  U8 *dest_ptr
							  S32 dest_pitch,
							  S32 dest_offset_x
							  S32 dest_offset_y,
							  gdi_rect_struct dest_clip)

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void gdi_2d_memory_blt_without_transpant_check(	U8 *src_ptr, S32 src_pitch, S32 src_offset_x, S32 src_offset_y, S32 src_width, S32 src_height, U8 *dest_ptr, S32 dest_pitch, S32 dest_offset_x, S32 dest_offset_y, gdi_rect_struct dest_clip,S32 bits_per_pixel)
{
	{
        gdi_color_format cf = gdi_get_color_format(bits_per_pixel); // not support PARGB & UYVY422
        gd_bitblt[cf](
            dest_ptr,                   // dest
            dest_pitch,                 // dw
            0,                          // dh , un-used
            dest_offset_x,              // dx1
            dest_offset_y,              // dy1
            dest_offset_x+src_width-1,  // dx2
            dest_offset_y+src_height-1, // dy2

            src_ptr,                    // src
            src_pitch,                  // sw
            0,                          // sh , un-used
            src_offset_x,               // sx1
            src_offset_y,               // sy1
            src_offset_x+src_width-1,   // sx2
            src_offset_y+src_height-1,  // sy2
            dest_clip.x1,               
            dest_clip.y1,
            dest_clip.x2,
            dest_clip.y2,
            0x01ffffff,                 // src_key , no color will be 0x1ffffff
            0x01ffffff);                // layer_key, no color will be 0x1ffffff
	}
}


#if defined(__MTK_TARGET__)

#ifndef __RVCT__

__inline int GDI_BYTE16SET(int sizeReg, int add, int a)
{
    __asm
	{
	        MOV r0, a;
	        MOV r1, r0;
	        MOV r2, r0;
	        MOV r3, r0;
	        MOV r4, add;
	        MOV r5, sizeReg;
	    CPYLOOP:
	        STMIA r4!, {r0, r1, r2, r3};
	        CMP r5, r4;
	        BGT CPYLOOP;
	        MOV add, r4;
	};

	return add;
}

#else


__asm void GDI_BYTE32SET(kal_uint32 *addr_end, kal_uint32 *addr, kal_uint32 val)
{
    ARM
    STMDB sp!, {r4-r9}

    MOV r9, r0 ; addr_end
    MOV r8, r1 ; addr

    ; prepare data registers
    MOV r0, r2
    MOV r1, r0
    MOV r2, r0
    MOV r3, r0
    MOV r4, r0
    MOV r5, r0
    MOV r6, r0
    MOV r7, r0
    
GDI_BYTE32SET_CPYLOOP
    STMIA r8!, {r0-r7}
    CMP r8, r9
    BLT GDI_BYTE32SET_CPYLOOP ; addr < addr_end

    LDMIA sp!, {r4-r9}
    
    BX lr
}


__asm int GDI_BYTE16SET_ONCE(kal_uint32 *addr, kal_uint32 val)
{
    ARM
    STMDB sp!, {r4}

    ; prepare data registers
    MOV r2, r1
    MOV r3, r1
    MOV r4, r1

    STMIA r0!, {r1-r4}
    LDMIA sp!, {r4}
    
    BX lr
}


#endif


#ifdef __MTK_TARGET__
//#pragma arm
#endif

void gdi_memset16(U8* address,U16 pixel,int size)
{
    if(size < 20)
    {
        register int add = (int)address;
        int sizeR = size;
        int postcount;
        if(add & 0x3)
        {
            *((unsigned short*)add) = pixel;
            add += 2;
            sizeR -= 2;
        }
        postcount = sizeR & 0x3;
        sizeR -= postcount;
        if(sizeR > 0)
        {
            register unsigned int a;
            register int sizeReg = sizeR;
            register int endAdd = add + sizeReg;
            a = pixel + (pixel << 16);
            do
            {
                ((unsigned int*)add)[0] = a;
                add += 4;
            }while(add < endAdd);
        }
        if(postcount != 0)
        {
            *((unsigned short*)add) = pixel;
        }
    }
    else
#ifdef __RVCT__ /* No non-RVCT version of GDI_BYTE32SET(), GDI_BYTE16SET_ONCE() */
    {
        register kal_uint8 *addr = (kal_uint8*)address;
        kal_int32 sizeR = size;
        kal_int32 postcount;
        kal_uint32 d_pixel = ((pixel << 16) | pixel);

        if ( (((kal_uint32)addr) & 0x2) != 0 )
        {
            /* Assume addr is 2-byte aligned */
            *((kal_uint16*)addr) = pixel;
            addr += 2;
            sizeR -= 2;
        }

        /* Now addr is 4-byte aligned */

        if (sizeR >= 32)
        {
            register kal_uint8 *addr_end;

            postcount = (sizeR & 0x01f);
            sizeR -= postcount;
            addr_end = addr + sizeR;
            GDI_BYTE32SET((kal_uint32*)addr_end, (kal_uint32*)addr, d_pixel);
            
            addr = addr_end;
            sizeR = postcount;
        }
        
        if (sizeR >= 16)
        {
            /* Now sizeR < 32 */
            GDI_BYTE16SET_ONCE((kal_uint32*)addr, d_pixel);
            
            addr += 16;
            sizeR -= 16;
        }

        postcount = sizeR & 0x2;
        sizeR = ((sizeR >> 2) << 2);
        if (sizeR != 0)
        {
            kal_uint8* addr_end = addr + sizeR;
            do
            {
                *((kal_uint32*)addr) = d_pixel;
                addr += 4;
            } while (addr != addr_end);
        }

        if (postcount != 0)
        {
            *((kal_uint16*)addr) = pixel;
        }
    }
#else
	{
		register int add = (int)address;
		int sizeR = size;
		int postcount;
		register unsigned int a;
		if(add & 0x3)
		{
			*((unsigned short*)add) = pixel;
			add += 2;
			sizeR -= 2;
		}
		postcount = (((unsigned int)sizeR) &0x00f);
		sizeR -= postcount;
		{
			register int sizeReg = sizeR + (int)add;
			a = pixel + (pixel << 16);
			add = GDI_BYTE16SET(sizeReg, add, a);
		}
		sizeR = ((postcount >> 2) << 2);
		if(sizeR > 0)
		{
			register int sizeReg = sizeR;
			register int endAdd = add + sizeReg;
			do
			{
				((unsigned int*)add)[0] = a;
				add += 4;
			}while(add < endAdd);
		}
		if((postcount & 0x3) != 0)
		{
			*((unsigned short*)add) = pixel;
		}
	}
#endif
}

#if !defined(GDI_SLIM_COLOR_FORMAT) || defined(GDI_LAYER_PARGB6666_SUPPORT)
void gdi_memset24(U8* address,U32 pixel,int size)
{
    register int add = (int)address;
    int sizeR = size;
    int postcount;
    unsigned int p3 = (pixel << 8) | (pixel >> 16); /* RGBR */
    unsigned int p2 = (pixel << 16) | (pixel >> 8); /* GBRG */
    unsigned int p1 = pixel | (pixel << 24); /* BRGB */
    unsigned char R = (unsigned char)(p3 & 0xFF);
    unsigned char G = (unsigned char)(p2 & 0xFF);
    unsigned char B = (unsigned char)(p1 & 0xFF);

    if (sizeR <= 2*3)
    {
        postcount = sizeR;
    }
    else
    {
        if(add & 0x1)
	    {
		    ((unsigned char*)add)[0] = B;
		    ((unsigned char*)add)[1] = G;
		    ((unsigned char*)add)[2] = R;
		    add += 3;
		    sizeR -= 3;        
	    }

        if(add & 0x2)
	    {
		    ((unsigned short*)add)[0] = (unsigned short)(p1 & 0xFFFF);
		    ((unsigned short*)add)[1] = (unsigned short)(p1 >> 16);
            ((unsigned short*)add)[2] = (unsigned short)(p2 & 0xFFFF);
		    add += 6;
		    sizeR -= 6;
	    }    
        
	    postcount = sizeR % 12;
	    sizeR -= postcount;
	    if(sizeR > 0)
	    {		
		    register int sizeReg = sizeR;
		    register int endAdd = add + sizeReg;
    		
		    do
		    {
			    ((unsigned int*)add)[0] = p1;
                ((unsigned int*)add)[1] = p2;
                ((unsigned int*)add)[2] = p3;
			    add += 12;
		    }while(add < endAdd);
	    }
    }

	if(postcount > 0)
	{
        do
		{
			((unsigned char*)add)[0] = B;
            ((unsigned char*)add)[1] = G;
            ((unsigned char*)add)[2] = R;
			add += 3;
            postcount -= 3;
		}while(postcount > 0);
	}
}
#endif


void gdi_memset32(U8* address,U32 pixel,int size)
{
    if(size < 20)
    {
        register int add = (int)address;
        int sizeR = size;
        int postcount;
        
        postcount = sizeR & 0x3;
        sizeR -= postcount;
        if(sizeR > 0)
        {
            register unsigned int a;
            register int sizeReg = sizeR;
            register int endAdd = add + sizeReg;
            a = pixel;
            do
            {
                ((unsigned int*)add)[0] = a;
                add += 4;
            }while(add < endAdd);
        }
    }
    else
#ifdef __RVCT__ /* No non-RVCT version of GDI_BYTE32SET(), GDI_BYTE16SET_ONCE() */
    {
        register kal_uint8 *addr = (kal_uint8*)address;
        kal_int32 sizeR = size;
        kal_int32 postcount;

        if (sizeR >= 32)
        {
            register kal_uint8 *addr_end;

            postcount = (sizeR & 0x01f);
            sizeR -= postcount;
            addr_end = addr + sizeR;
            GDI_BYTE32SET((kal_uint32*)addr_end, (kal_uint32*)addr, pixel);
            
            addr = addr_end;
            sizeR = postcount;
        }
        
        if (sizeR >= 16)
        {
            /* Now sizeR < 32 */
            GDI_BYTE16SET_ONCE((kal_uint32*)addr, pixel);
            
            addr += 16;
            sizeR -= 16;
        }

        /* Assume size is multiple of 4 */
        sizeR = ((sizeR >> 2) << 2);
        if (sizeR != 0)
        {
            kal_uint8* addr_end = addr + sizeR;
            do
            {
                *((kal_uint32*)addr) = pixel;
                addr += 4;
            } while (addr != addr_end);
        }
    }
#else
	{
		register int add = (int)address;
		int sizeR = size;
		int postcount;
		register unsigned int a;

		postcount = (((unsigned int)sizeR) &0x00f);
		sizeR -= postcount;
		{
			register int sizeReg = sizeR + (int)add;
			a = pixel;
			add = GDI_BYTE16SET(sizeReg, add, a);
		}
		sizeR = ((postcount >> 2) << 2);
		if(sizeR > 0)
		{
			register int sizeReg = sizeR;
			register int endAdd = add + sizeReg;
			do
			{
				((unsigned int*)add)[0] = a;
				add += 4;
			}while(add < endAdd);
		}
	}
#endif
}

#ifdef __MTK_TARGET__
//#pragma thumb
#endif


#else
void gdi_memset16(U8* address,U16 pixel,int size)
{
        register int add = (int)address;
        int sizeR = size;
        int postcount;
        if(add & 0x3)
	{
		*((unsigned short*)add) = pixel;
		add += 2;
		sizeR -= 2;
	}
	postcount = sizeR & 0x3;
	sizeR -= postcount;
	if(sizeR > 0)
	{
		register unsigned int a;
		register int sizeReg = sizeR;
		register int endAdd = add + sizeReg;
		a = pixel + (pixel << 16);
		do
		{
			((unsigned int*)add)[0] = a;
			add += 4;
		}while(add < endAdd);
	}
	if(postcount != 0)
	{
		*((unsigned short*)add) = pixel;
	}
}


#if !defined(GDI_SLIM_COLOR_FORMAT) || defined(GDI_LAYER_PARGB6666_SUPPORT)
void gdi_memset24(U8* address,U32 pixel,int size)
{
    register int add = (int)address;
    int sizeR = size;
    int postcount;
    unsigned int p3 = (pixel << 8) | (pixel >> 16); /* RGBR */
    unsigned int p2 = (pixel << 16) | (pixel >> 8); /* GBRG */
    unsigned int p1 = pixel | (pixel << 24); /* BRGB */
    unsigned char R = (unsigned char)(p3 & 0xFF);
    unsigned char G = (unsigned char)(p2 & 0xFF);
    unsigned char B = (unsigned char)(p1 & 0xFF);

    if (sizeR <= 2*3)
    {
        postcount = sizeR;
    }
    else
    {
        if(add & 0x1)
	    {
		    ((unsigned char*)add)[0] = B;
		    ((unsigned char*)add)[1] = G;
		    ((unsigned char*)add)[2] = R;
		    add += 3;
		    sizeR -= 3;        
	    }

        if(add & 0x2)
	    {
		    ((unsigned short*)add)[0] = (unsigned short)(p1 & 0xFFFF);
		    ((unsigned short*)add)[1] = (unsigned short)(p1 >> 16);
            ((unsigned short*)add)[2] = (unsigned short)(p2 & 0xFFFF);
		    add += 6;
		    sizeR -= 6;
	    }    
        
	    postcount = sizeR % 12;
	    sizeR -= postcount;
	    if(sizeR > 0)
	    {		
		    register int sizeReg = sizeR;
		    register int endAdd = add + sizeReg;
    		
		    do
		    {
			    ((unsigned int*)add)[0] = p1;
                ((unsigned int*)add)[1] = p2;
                ((unsigned int*)add)[2] = p3;
			    add += 12;
		    }while(add < endAdd);
	    }
    }

	if(postcount > 0)
	{
        do
		{
			((unsigned char*)add)[0] = B;
            ((unsigned char*)add)[1] = G;
            ((unsigned char*)add)[2] = R;
			add += 3;
            postcount -= 3;
		}while(postcount > 0);
	}
}
#endif


void gdi_memset32(U8* address,U32 pixel,int size)
{
    register int add = (int)address;
    int sizeR = size;
    int postcount;
        
	postcount = sizeR & 0x3;
	sizeR -= postcount;
	if(sizeR > 0)
	{
		register unsigned int a;
		register int sizeReg = sizeR;
		register int endAdd = add + sizeReg;
		a = pixel;
		do
		{
			((unsigned int*)add)[0] = a;
			add += 4;
		}while(add < endAdd);
	}
	if(postcount != 0)
	{
		*((unsigned int*)add) = pixel;
	}
}

#endif

static const kal_uint8 bitsperpixels[]   = { 1, 8, 16, 24, 32, 32, 16, 8, 24 };
static const kal_uint8 reserve_padding[] = { 7, 0,  0,  0,  0,  0,  0, 0,  0 };
S32 gdi_sizeof_pixels(gdi_color_format cf,S32 width,S32 height)
{
    if (cf <GDI_COLOR_FORMAT_STANDARD_END)
    {
        return ((width * gdi_bits_per_pixel(cf) + reserve_padding[cf]) >> 3) * height;
    }
	
    width  = (width+7) & (~0x7);
    height = (height+7) & (~0x7); 
    
	if(cf == GDI_COLOR_FORMAT_MAINLCD)
        return ((width*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*height;
	
#ifdef __MMI_SUBLCD__
	if(cf == GDI_COLOR_FORMAT_SUBLCD)
		return ((width*GDI_SUBLCD_BIT_PER_PIXEL)>>3)*height;
#endif

	GDI_ASSERT(0);
	return 0;
}

gdi_color_format gdi_get_color_format(S32 bits)
{
    /*
     * WARNING!! This API won't return GDI_COLOR_FORMAT_32_PARGB & GDI_COLOR_FORMAT_UYVY422
     */
	if(bits == 1)
		return GDI_COLOR_FORMAT_1;
#ifdef GDI_COLORFORMAT8_PALETTE
	else if(bits == 8)
		return GDI_COLOR_FORMAT_8;
#endif /* GDI_COLORFORMAT8_PALETTE */
	else if(bits == 16)
		return GDI_COLOR_FORMAT_16;
	else if(bits == 18)
		return GDI_COLOR_FORMAT_24;
	else if(bits == 24)
		return GDI_COLOR_FORMAT_24;
	else if(bits == 32)
		return GDI_COLOR_FORMAT_32;
	
	else if(bits == DRV_MAINLCD_BIT_PER_PIXEL)
		return GDI_COLOR_FORMAT_MAINLCD;
	
#ifdef __MMI_SUBLCD__
	else if(bits == DRV_SUBLCD_BIT_PER_PIXEL)
		return GDI_COLOR_FORMAT_SUBLCD;
#endif

	else
		GDI_ASSERT(0);
	return GDI_COLOR_FORMAT_32; // default we use the maximum data type
}

S32 gdi_bits_per_pixel(gdi_color_format cf)
{
	if(cf <GDI_COLOR_FORMAT_STANDARD_END)
		return bitsperpixels[cf];
	
	if(cf == GDI_COLOR_FORMAT_MAINLCD)
		return GDI_MAINLCD_BIT_PER_PIXEL;
	
#ifdef __MMI_SUBLCD__
	if(cf == GDI_COLOR_FORMAT_SUBLCD)
		return GDI_SUBLCD_BIT_PER_PIXEL;
#endif

	GDI_ASSERT(0);
	return 0;
}


/**************************************************************

	GDI Software Resizer
	
***************************************************************/

/*
 * NOTICE: to make a region ARM9 D-cacheable, it must comply with some rules.
 * If we make other variables D-cacheable without checking these rules, 
 * it may have potential issues.
 */
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "CACHEDZI",  rwdata = "CACHEDRW" 
#endif
#if defined(GDI_USING_PBM)
gdi_resizer_struct GDI_RESIZER;
gdi_resizer_put_func gdi_resizer_put;


#if defined(__MTK_TARGET__)
#pragma arm section zidata, rwdata
#endif


#if defined(__MTK_TARGET__)
#pragma arm section code = "INTERNCODE"
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_resizer_put_null
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_resizer_put_null(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	// keep empty
}

#if defined(GDI_USE_RGB565_TO_SHOW_BW)
/*****************************************************************************
 * FUNCTION
 *  gdi_resizer_put_mainlcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_resizer_put_1(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * W06.26 Fix the wrong position GDI_RESIZER.want_sx and GDI_RESIZER.want_sy
     * Use GDI_RESIZER.next_want_sx - GDI_RESIZER.want_sx_table instead of GDI_RESIZER.want_sx
     * as jumping to the next pixel
     * GDI_RESIZER.next_want_dy - 1 is the current y position
     */
	if(want_draw)
		GDI_SET_BUFFER_PIXEL_1(
			(GDI_RESIZER.want_dx1 + (int)(GDI_RESIZER.next_want_sx - GDI_RESIZER.want_sx_table) - 1), 
			(GDI_RESIZER.next_want_dy - 1),
			(c));

	// generate next_position
	if(GDI_RESIZER.next_want_sx >= GDI_RESIZER.want_sx_table_end)
	{
		GDI_RESIZER.next_want_sx = GDI_RESIZER.want_sx_table;

		//GDI_RESIZER.want_sy = (((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.y_scale_factor) >> 16);
		GDI_RESIZER.want_sy = ((((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.src_height_range << 1) +  GDI_RESIZER.dest_height_range) / (GDI_RESIZER.dest_height_range << 1));

		if(GDI_RESIZER.next_want_dy < GDI_RESIZER.want_dy1 || GDI_RESIZER.next_want_dy > GDI_RESIZER.want_dy2)
		{
			gdi_resizer_put=gdi_resizer_put_null;
			return;
		}
		GDI_RESIZER.next_want_dy += GDI_RESIZER.dir_y;
	}
	GDI_RESIZER.want_sx = *GDI_RESIZER.next_want_sx++;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_non_resizer_put_mainlcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_non_resizer_put_1(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_RESIZER_PUT_PIXEL(COLOR)			GDI_SET_BUFFER_PIXEL_1((GDI_RESIZER.offset_dx + GDI_RESIZER.want_sx),(GDI_RESIZER.offset_dy + GDI_RESIZER.want_sy),COLOR)
	#define GDI_RESIZER_INCREASE_DEST				
	GDI_NON_RESIZER_PUT_X(c,want_draw);
	#undef GDI_RESIZER_PUT_PIXEL
	#undef GDI_RESIZER_INCREASE_DEST
}

#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_resizer_put_8
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_resizer_put_8(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(want_draw)
		*((U8*)GDI_RESIZER.dest) = (U8)c;

	GDI_RESIZER.dest+=1;
	// generate next_position
	if(GDI_RESIZER.next_want_sx >= GDI_RESIZER.want_sx_table_end)
	{
		GDI_RESIZER.next_want_sx = GDI_RESIZER.want_sx_table;

		if(GDI_RESIZER.dir_x>0)
			GDI_RESIZER.dest = gdi_act_layer->buf_ptr + (GDI_RESIZER.want_dx1+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )*1;
		else
			GDI_RESIZER.dest = gdi_act_layer->buf_ptr + (GDI_RESIZER.want_dx2+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )*1;
		//GDI_RESIZER.want_sy = (((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.y_scale_factor) >> 16);
		GDI_RESIZER.want_sy = ((((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.src_height_range << 1) +  GDI_RESIZER.dest_height_range) / (GDI_RESIZER.dest_height_range << 1));

		if(GDI_RESIZER.next_want_dy < GDI_RESIZER.want_dy1 || GDI_RESIZER.next_want_dy > GDI_RESIZER.want_dy2)
		{
			gdi_resizer_put=gdi_resizer_put_null;
			return;
		}
		GDI_RESIZER.next_want_dy += GDI_RESIZER.dir_y;
	}
	GDI_RESIZER.want_sx = *GDI_RESIZER.next_want_sx++;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_resizer_put_16
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_resizer_put_16(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(want_draw)
		*((U16*)GDI_RESIZER.dest) = (U16)c;

	GDI_RESIZER.dest+=2;
	// generate next_position
	if(GDI_RESIZER.next_want_sx >= GDI_RESIZER.want_sx_table_end)
	{
		GDI_RESIZER.next_want_sx = GDI_RESIZER.want_sx_table;

		if(GDI_RESIZER.dir_x>0)
			GDI_RESIZER.dest = gdi_act_layer->buf_ptr + (GDI_RESIZER.want_dx1+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )*2;
		else
			GDI_RESIZER.dest = gdi_act_layer->buf_ptr + (GDI_RESIZER.want_dx2+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )*2;
		//GDI_RESIZER.want_sy = (((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.y_scale_factor) >> 16);
		GDI_RESIZER.want_sy = ((((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.src_height_range << 1) +  GDI_RESIZER.dest_height_range) / (GDI_RESIZER.dest_height_range << 1));

		if(GDI_RESIZER.next_want_dy < GDI_RESIZER.want_dy1 || GDI_RESIZER.next_want_dy > GDI_RESIZER.want_dy2)
		{
			gdi_resizer_put=gdi_resizer_put_null;
			return;
		}
		GDI_RESIZER.next_want_dy += GDI_RESIZER.dir_y;
	}
	GDI_RESIZER.want_sx = *GDI_RESIZER.next_want_sx++;
}

    
/*****************************************************************************
 * FUNCTION
 *  gdi_resizer_put_24
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_resizer_put_24(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(want_draw)
	{
		U32 *ptr = (U32*)(GDI_RESIZER.dest);
		switch(((U32)ptr)&0x3)
		{
		case 0:
			*ptr = (*ptr&0xff000000)|(c&0x00ffffff);
			break;
		case 1:
			ptr= (U32*)(((U32)ptr)&(~0x3));
			*ptr = (*ptr&0x000000ff)|(c<<8);
			break;
		case 2:
			ptr= (U32*)(((U32)ptr)&(~0x3));
			*ptr = (*ptr&0x0000ffff)|(c<<16); ptr++;
			*ptr = (*ptr&0xffffff00)|((c&0x00ff0000)>>16);
			break;
		default:
			ptr= (U32*)(((U32)ptr)&(~0x3));
			*ptr = (*ptr&0x00ffffff)|(c<<24); ptr++;
			*ptr = (*ptr&0xffff0000)|((c&0x00ffff00)>>8);
			break;
		}
	}

	GDI_RESIZER.dest+=3;
	// generate next_position
	if(GDI_RESIZER.next_want_sx >= GDI_RESIZER.want_sx_table_end)
	{
		GDI_RESIZER.next_want_sx = GDI_RESIZER.want_sx_table;

		if(GDI_RESIZER.dir_x>0)
			GDI_RESIZER.dest = gdi_act_layer->buf_ptr + (GDI_RESIZER.want_dx1+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )*3;
		else
			GDI_RESIZER.dest = gdi_act_layer->buf_ptr + (GDI_RESIZER.want_dx2+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )*3;
		//GDI_RESIZER.want_sy = (((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.y_scale_factor) >> 16);
		GDI_RESIZER.want_sy = ((((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.src_height_range << 1) +  GDI_RESIZER.dest_height_range) / (GDI_RESIZER.dest_height_range << 1));

		if(GDI_RESIZER.next_want_dy < GDI_RESIZER.want_dy1 || GDI_RESIZER.next_want_dy > GDI_RESIZER.want_dy2)
		{
			gdi_resizer_put=gdi_resizer_put_null;
			return;
		}
		GDI_RESIZER.next_want_dy += GDI_RESIZER.dir_y;
	}
	GDI_RESIZER.want_sx = *GDI_RESIZER.next_want_sx++;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_resizer_put_32
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_resizer_put_32(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(want_draw)
	{
		 *(U32*)(GDI_RESIZER.dest) = (U32)c;
	}

	GDI_RESIZER.dest+=4;
	// generate next_position
	if(GDI_RESIZER.next_want_sx >= GDI_RESIZER.want_sx_table_end)
	{
		GDI_RESIZER.next_want_sx = GDI_RESIZER.want_sx_table;

		if(GDI_RESIZER.dir_x>0)
			GDI_RESIZER.dest = gdi_act_layer->buf_ptr + (GDI_RESIZER.want_dx1+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )*4;
		else
			GDI_RESIZER.dest = gdi_act_layer->buf_ptr + (GDI_RESIZER.want_dx2+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )*4;
		//GDI_RESIZER.want_sy = (((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.y_scale_factor) >> 16);
		GDI_RESIZER.want_sy = ((((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.src_height_range << 1) +  GDI_RESIZER.dest_height_range) / (GDI_RESIZER.dest_height_range << 1));

		if(GDI_RESIZER.next_want_dy < GDI_RESIZER.want_dy1 || GDI_RESIZER.next_want_dy > GDI_RESIZER.want_dy2)
		{
			gdi_resizer_put=gdi_resizer_put_null;
			return;
		}
		GDI_RESIZER.next_want_dy += GDI_RESIZER.dir_y;
	}
	GDI_RESIZER.want_sx = *GDI_RESIZER.next_want_sx++;
}

#if  GDI_MAINLCD_BIT_PER_PIXEL ==  1 || !defined(GDI_USING_LAYER)


/*****************************************************************************
 * FUNCTION
 *  gdi_resizer_put_mainlcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_resizer_put_mainlcd(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * W06.26 Fix the wrong position GDI_RESIZER.want_sx and GDI_RESIZER.want_sy
     * Use GDI_RESIZER.next_want_sx - GDI_RESIZER.want_sx_table instead of GDI_RESIZER.want_sx
     * as jumping to the next pixel
     * GDI_RESIZER.next_want_dy - 1 is the current y position
     */
	if(want_draw)
		DRV_MAINLCD_SET_BUFFER_PIXEL(
			(GDI_RESIZER.want_dx1 + (int)(GDI_RESIZER.next_want_sx - GDI_RESIZER.want_sx_table) - 1), 
			(GDI_RESIZER.next_want_dy - 1),
			(c));

	// generate next_position
	if(GDI_RESIZER.next_want_sx >= GDI_RESIZER.want_sx_table_end)
	{
		GDI_RESIZER.next_want_sx = GDI_RESIZER.want_sx_table;

		//GDI_RESIZER.want_sy = (((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.y_scale_factor) >> 16);
		GDI_RESIZER.want_sy = ((((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.src_height_range << 1) +  GDI_RESIZER.dest_height_range) / (GDI_RESIZER.dest_height_range << 1));

		if(GDI_RESIZER.next_want_dy < GDI_RESIZER.want_dy1 || GDI_RESIZER.next_want_dy > GDI_RESIZER.want_dy2)
		{
			gdi_resizer_put=gdi_resizer_put_null;
			return;
		}
		GDI_RESIZER.next_want_dy += GDI_RESIZER.dir_y;
	}
	GDI_RESIZER.want_sx = *GDI_RESIZER.next_want_sx++;
}
#elif GDI_MAINLCD_BIT_PER_PIXEL == 16
	#define gdi_resizer_put_mainlcd 	gdi_resizer_put_16
#elif GDI_MAINLCD_BIT_PER_PIXEL == 24
	#define gdi_resizer_put_mainlcd 	gdi_resizer_put_24
#elif GDI_MAINLCD_BIT_PER_PIXEL == 32
	#define gdi_resizer_put_mainlcd 	gdi_resizer_put_32
#else
	#error "Unknown MAINLCD_BIT_PER_PIXEL"
#endif

#ifdef __MMI_SUBLCD__
#if GDI_SUBLCD_BIT_PER_PIXEL ==  1 || !defined(GDI_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gdi_resizer_put_sublcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_resizer_put_sublcd(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * W06.26 Fix the wrong position GDI_RESIZER.want_sx and GDI_RESIZER.want_sy
     * Use GDI_RESIZER.next_want_sx - GDI_RESIZER.want_sx_table instead of GDI_RESIZER.want_sx
     * as jumping to the next pixel
     * GDI_RESIZER.next_want_dy - 1 is the current y position
     */
	if(want_draw)
		DRV_SUBLCD_SET_BUFFER_PIXEL(
			(GDI_RESIZER.want_dx1 + (int)(GDI_RESIZER.next_want_sx - GDI_RESIZER.want_sx_table) - 1), 
			(GDI_RESIZER.next_want_dy - 1),
			(c));

	// generate next_position
	if(GDI_RESIZER.next_want_sx >= GDI_RESIZER.want_sx_table_end)
	{
		GDI_RESIZER.next_want_sx = GDI_RESIZER.want_sx_table;

		//GDI_RESIZER.want_sy = (((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.y_scale_factor) >> 16);
		GDI_RESIZER.want_sy = ((((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * GDI_RESIZER.src_height_range << 1) +  GDI_RESIZER.dest_height_range) / (GDI_RESIZER.dest_height_range << 1));

		if(GDI_RESIZER.next_want_dy < GDI_RESIZER.want_dy1 || GDI_RESIZER.next_want_dy > GDI_RESIZER.want_dy2)
		{
			gdi_resizer_put=gdi_resizer_put_null;
			return;
		}
		GDI_RESIZER.next_want_dy += GDI_RESIZER.dir_y;
	}
	GDI_RESIZER.want_sx = *GDI_RESIZER.next_want_sx++;
}
#elif GDI_SUBLCD_BIT_PER_PIXEL == 16
	#define gdi_resizer_put_sublcd 	gdi_resizer_put_16
#elif GDI_SUBLCD_BIT_PER_PIXEL == 24
	#define gdi_resizer_put_sublcd 	gdi_resizer_put_24
#elif GDI_SUBLCD_BIT_PER_PIXEL == 32
	#define gdi_resizer_put_sublcd 	gdi_resizer_put_32
#else
		#error "Unknown SUBLCD_BIT_PER_PIXEL"
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  gdi_non_resizer_put_8
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_non_resizer_put_8(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_RESIZER_PUT_PIXEL(COLOR)			*((U8*)GDI_RESIZER.dest) = (U8)COLOR
	#define GDI_RESIZER_INCREASE_DEST				GDI_RESIZER.dest ++
	GDI_NON_RESIZER_PUT_X(c,want_draw);
	#undef GDI_RESIZER_PUT_PIXEL
	#undef GDI_RESIZER_INCREASE_DEST
}


/*****************************************************************************
 * FUNCTION
 *  gdi_non_resizer_put_16
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_non_resizer_put_16(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_RESIZER_PUT_PIXEL(COLOR)		*((U16*)GDI_RESIZER.dest) = (U16)COLOR
	#define GDI_RESIZER_INCREASE_DEST			GDI_RESIZER.dest +=2
	GDI_NON_RESIZER_PUT_X(c,want_draw);
	#undef GDI_RESIZER_PUT_PIXEL
	#undef GDI_RESIZER_INCREASE_DEST
}


/*****************************************************************************
 * FUNCTION
 *  gdi_non_resizer_put_24
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_non_resizer_put_24(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_RESIZER_PUT_PIXEL(COLOR)			\
			do\
			{\
				U32 *ptr = (U32*)(GDI_RESIZER.dest);\
				switch(((U32)ptr)&0x3)\
				{\
				case 0:\
					*ptr = (*ptr&0xff000000)|(COLOR&0x00ffffff);\
					break;\
				case 1:\
					ptr= (U32*)(((U32)ptr)&(~0x3));\
					*ptr = (*ptr&0x000000ff)|(COLOR<<8);\
					break;\
				case 2:\
					ptr= (U32*)(((U32)ptr)&(~0x3));\
					*ptr = (*ptr&0x0000ffff)|(COLOR<<16); ptr++;\
					*ptr = (*ptr&0xffffff00)|((COLOR&0x00ff0000)>>16);\
					break;\
				default:\
					ptr= (U32*)(((U32)ptr)&(~0x3));\
					*ptr = (*ptr&0x00ffffff)|(COLOR<<24); ptr++;\
					*ptr = (*ptr&0xffff0000)|((COLOR&0x00ffff00)>>8);\
				}\
			}while(0)

	#define GDI_RESIZER_INCREASE_DEST				GDI_RESIZER.dest +=3
	GDI_NON_RESIZER_PUT_X(c,want_draw);
	#undef GDI_RESIZER_PUT_PIXEL
	#undef GDI_RESIZER_INCREASE_DEST
}


/*****************************************************************************
 * FUNCTION
 *  gdi_non_resizer_put_32
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_non_resizer_put_32(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_RESIZER_PUT_PIXEL(COLOR)			*((U32*)GDI_RESIZER.dest) = (U32)COLOR
	#define GDI_RESIZER_INCREASE_DEST				GDI_RESIZER.dest +=4
	GDI_NON_RESIZER_PUT_X(c,want_draw);
	#undef GDI_RESIZER_PUT_PIXEL
	#undef GDI_RESIZER_INCREASE_DEST
}

#if  GDI_MAINLCD_BIT_PER_PIXEL ==  1 || !defined(GDI_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gdi_non_resizer_put_mainlcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_non_resizer_put_mainlcd(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_RESIZER_PUT_PIXEL(COLOR)			DRV_MAINLCD_SET_BUFFER_PIXEL((GDI_RESIZER.offset_dx + GDI_RESIZER.want_sx),(GDI_RESIZER.offset_dy + GDI_RESIZER.want_sy),COLOR)
	#define GDI_RESIZER_INCREASE_DEST				
	GDI_NON_RESIZER_PUT_X(c,want_draw);
	#undef GDI_RESIZER_PUT_PIXEL
	#undef GDI_RESIZER_INCREASE_DEST
}
#elif GDI_MAINLCD_BIT_PER_PIXEL == 16
	#define gdi_non_resizer_put_mainlcd 	gdi_non_resizer_put_16
#elif GDI_MAINLCD_BIT_PER_PIXEL == 24
	#define gdi_non_resizer_put_mainlcd 	gdi_non_resizer_put_24
#elif GDI_MAINLCD_BIT_PER_PIXEL == 32
	#define gdi_non_resizer_put_mainlcd 	gdi_non_resizer_put_32
#else
	#error "Unknown MAINLCD_BIT_PER_PIXEL"
#endif

#ifdef __MMI_SUBLCD__
#if GDI_SUBLCD_BIT_PER_PIXEL ==  1 || !defined(GDI_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gdi_non_resizer_put_sublcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_non_resizer_put_sublcd(gdi_color c,BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_RESIZER_PUT_PIXEL(COLOR)			DRV_SUBLCD_SET_BUFFER_PIXEL((GDI_RESIZER.offset_dx + GDI_RESIZER.want_sx),(GDI_RESIZER.offset_dy + GDI_RESIZER.want_sy),COLOR)
	#define GDI_RESIZER_INCREASE_DEST				
	GDI_NON_RESIZER_PUT_X(c,want_draw);
	#undef GDI_RESIZER_PUT_PIXEL
	#undef GDI_RESIZER_INCREASE_DEST
}
#elif GDI_MAINLCD_BIT_PER_PIXEL == 16
	#define gdi_non_resizer_put_sublcd 	gdi_non_resizer_put_16
#elif GDI_MAINLCD_BIT_PER_PIXEL == 24
	#define gdi_non_resizer_put_sublcd 	gdi_non_resizer_put_24
#elif GDI_MAINLCD_BIT_PER_PIXEL == 32
	#define gdi_non_resizer_put_sublcd 	gdi_non_resizer_put_32
#else
	#error "Unknown MAINLCD_BIT_PER_PIXEL"
#endif
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_resizer_set_want_sy
 * DESCRIPTION
 *  update resizer context depends on want_sy
 * PARAMETERS
 *  want_sy       [IN]  the next line resizer want to draw
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_resizer_set_want_sy(S32 want_sy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	S32 dy;

    // out of clipping should not update want_sx, want_sy
    if( GDI_RESIZER.want_sx <0 || GDI_RESIZER.want_sy < 0) return;
    
	// sometime we need to stop auto increase dy, and manual set the position
	GDI_RESIZER.dir_y = 0; 
	// default : the pixel line (want_sy) will not be accept !!
	GDI_RESIZER.want_sy = want_sy+1; 

	// non resize handler
	if(GDI_RESIZER.want_sx_table==NULL)
	{
		if ((want_sy) >= GDI_RESIZER.want_start_sy && (want_sy) <= GDI_RESIZER.want_end_sy)
		{
			GDI_RESIZER.want_sx = GDI_RESIZER.want_start_sx;
			GDI_RESIZER.want_sy = want_sy;
			//W05.40 Compute GDI_RESIZER.dest by GDI_RESIZER.want_dx1 and GDI_RESIZER.want_dy1
			//GDI_RESIZER.dest = gdi_act_layer->buf_ptr + ((GDI_RESIZER.want_sx+GDI_RESIZER.want_sy*gdi_act_layer->width* bitsperpixels[gdi_act_layer->vcf])>>3);
			GDI_RESIZER.dest = gdi_act_layer->buf_ptr 
								+ (((GDI_RESIZER.want_dx1
								+(GDI_RESIZER.want_dy1+GDI_RESIZER.want_sy-GDI_RESIZER.want_start_sy)*gdi_act_layer->width)
								* gdi_bits_per_pixel(gdi_act_layer->cf))>>3);
		}
		return ;
	}
	
	
	for(;;)
	{
		// want_sy project to dy
		dy = ((want_sy * GDI_RESIZER.dest_height_range << 1) +  GDI_RESIZER.src_height_range) / (GDI_RESIZER.src_height_range << 1);
		
		//check this want_dy will also project to want_sy
		if( want_sy ==  ((((dy) * GDI_RESIZER.src_height_range << 1) +  GDI_RESIZER.dest_height_range) / (GDI_RESIZER.dest_height_range << 1)))
			break;

		dy ++;
		// check dy + 1 will project to want_sy
		if( want_sy == ((((dy) * GDI_RESIZER.src_height_range << 1) +  GDI_RESIZER.dest_height_range) / (GDI_RESIZER.dest_height_range << 1)))
			break;

		
		return;// this line will not be accept !!
	}

	dy += GDI_RESIZER.offset_dy;

	// check this destination is out of clipping area ?
	if(dy < GDI_RESIZER.want_dy1 || dy > GDI_RESIZER.want_dy2)
		return;// this line will not be accept !!

	GDI_RESIZER.want_sy = want_sy;
	GDI_RESIZER.next_want_dy = dy;
	GDI_RESIZER.next_want_sx = GDI_RESIZER.want_sx_table;
	GDI_RESIZER.want_sx = *GDI_RESIZER.next_want_sx++;
	
	if(GDI_RESIZER.dir_x>0)
		GDI_RESIZER.dest = gdi_act_layer->buf_ptr 
							+ ((	(	GDI_RESIZER.want_dx1
									+GDI_RESIZER.next_want_dy* gdi_act_layer->width )
									* gdi_bits_per_pixel(gdi_act_layer->cf))>>3);
	else
		GDI_RESIZER.dest = gdi_act_layer->buf_ptr 
							+ ((		(GDI_RESIZER.want_dx2
									+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )
									* gdi_bits_per_pixel(gdi_act_layer->cf))>>3);
	
}
#endif

#if defined(__MTK_TARGET__)
#pragma arm section code
#endif

#if defined(GDI_USING_PBM)
typedef void (*gdi_resizer_put_func)(gdi_color c,BOOL want_draw);
const static gdi_resizer_put_func gdi_resizer_put_table[]=
{
#if defined(GDI_USE_RGB565_TO_SHOW_BW)
	gdi_resizer_put_1, //(gdi_resizer_put_func)gd_null_pointer_function, // 1
#else
    (gdi_resizer_put_func)gd_null_pointer_function, // 1
#endif
	gdi_resizer_put_8, // 8
	gdi_resizer_put_16, // 16
	gdi_resizer_put_24, // 24
	gdi_resizer_put_32, // 32
	gdi_resizer_put_32, // 32PARGB
	(gdi_resizer_put_func)gd_null_pointer_function, // UYVY422
	gdi_resizer_put_8,  /* A8 */
	gdi_resizer_put_24, /* PARGB6666 */
	gdi_resizer_put_mainlcd, // main
#ifdef __MMI_SUBLCD__
	gdi_resizer_put_sublcd
#else
	(gdi_resizer_put_func)gd_null_pointer_function, // sub
#endif
};
const static gdi_resizer_put_func gdi_non_resizer_put_table[]=
{
#if defined(GDI_USE_RGB565_TO_SHOW_BW)
    gdi_non_resizer_put_1,
#else
	(gdi_resizer_put_func)gd_null_pointer_function, // 1
#endif
	gdi_non_resizer_put_8, // 8
	gdi_non_resizer_put_16, // 16
	gdi_non_resizer_put_24, // 24
	gdi_non_resizer_put_32, // 32
	gdi_non_resizer_put_32, // 32PARGB
	(gdi_resizer_put_func)gd_null_pointer_function, // UYVY422
	gdi_non_resizer_put_8,  /* A8 */
	gdi_non_resizer_put_24,  /* PARGB6666 */
	gdi_non_resizer_put_mainlcd, // main
#ifdef __MMI_SUBLCD__
	gdi_non_resizer_put_sublcd // sub
#else
	(gdi_resizer_put_func)gd_null_pointer_function // sub
#endif
};


/*****************************************************************************
 * FUNCTION
 *  gdi_resizer_init
 * DESCRIPTION
 *  init the resizer
 * PARAMETERS
 *  src_width              [IN] srouce width
 *  src_height             [IN] source height
 *  src_clipx1             [IN] source clip x1
 *  src_clipy1             [IN] source clip y1
 *  src_clipx2             [IN] source clip x2
 *  src_clipy2             [IN] source clip y2
 *  dest_x1                [IN] destination x1
 *  dest_y1                [IN] destination y1
 *  dest_x2                [IN] destination x2
 *  dest_y2                [IN] destination y2
 * RETURNS
 *  S32, return 0 if no pixel to output, 1 if decoder need to continue to decode, -1 if error.
 *****************************************************************************/
S32 gdi_resizer_init(
				S32 src_width,S32 src_height, 
				S32 src_clipx1, S32 src_clipy1,S32 src_clipx2,S32 src_clipy2,
				S32 dest_x1,S32 dest_y1,S32 dest_x2,S32 dest_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dest_width;
	S32 dest_height;
	S32 dir_x;
	S32 dir_y;
	S32 src_width_range;
	S32 src_height_range;
	S32 dest_width_range;
	S32 dest_height_range;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_RESIZER.want_sx = GDI_RESIZER.want_sy = -1;
	
	// we don't support 1, 8 bites color format in this resizer
	if(src_width  <=0) return 0;
	if(src_height <=0) return 0;

	dir_x=dir_y=1;

	if(dest_x1>dest_x2)
	{
		GDI_DEBUG_ASSERT(0); // current, we only support dir_x >0
		SWAP(S32,dest_x1,dest_x2);
		dir_x = -1;
	}
	if(dest_y1>dest_y2)
	{
		SWAP(S32,dest_y1,dest_y2);
		dir_y = -1;
	}
	

	GDI_RESIZER.dest = gdi_act_layer->buf_ptr;
	GDI_RESIZER.offset_dx = dest_x1;
	GDI_RESIZER.offset_dy = dest_y1;
	dest_width = dest_x2-dest_x1+1;
	dest_height = dest_y2-dest_y1+1;
	
    gdi_image_set_update_area(dest_x1,dest_y1,dest_x2,dest_y2);
	
	GDI_RESIZER.want_dx1 = dest_x1;
	GDI_RESIZER.want_dy1 = dest_y1;
	GDI_RESIZER.want_dx2 = dest_x2;
	GDI_RESIZER.want_dy2 = dest_y2;

	GDI_RESIZER.dir_x = dir_x;
	GDI_RESIZER.dir_y = dir_y;
	
	// check the clipping area
	GDI_CLIP_RECT_TEST(GDI_RESIZER.want_dx1,GDI_RESIZER.want_dy1,GDI_RESIZER.want_dx2,GDI_RESIZER.want_dy2,return 0); // no pixel will be render !!

	/* W06.16 Use Coordinate Range instead of width and height */
	/* Use round off to compute want_sx and want_sy */
	if (1 == src_width)
	{
		src_width = 2;
	}
	if (1 == dest_width)
	{
		dest_width = 2;
	}
	if (1 == src_height)
	{
		src_height = 2;
	}
	if (1 == dest_height)
	{
		dest_height = 2;
	}
	src_width_range = src_width - 1;
	src_height_range = src_height - 1;
	dest_width_range  = dest_width - 1;
	dest_height_range  = dest_height - 1;
	//multiply_factor = ((src_width_range) <<16)/ (dest_width_range);
	// make y_scale_factor
	//GDI_RESIZER.y_scale_factor 		= ((src_height_range)<<16)  / (dest_height_range);
	//GDI_RESIZER.y_inv_scale_factory	= ((dest_height_range)<<16 )  / (src_height_range);
	GDI_RESIZER.src_height_range 		= src_height_range;
	GDI_RESIZER.dest_height_range	= dest_height_range;

	{
		int dx1,dy1,dx2,dy2;
		// check the source clipping area
		dx1 = dest_x1 + (src_clipx1*(dest_width_range<<1) + src_width_range)/(src_width_range<<1);
		dx2 = dest_x1 + (src_clipx2*(dest_width_range<<1) + src_width_range)/(src_width_range<<1);		
		
		dy1 = dest_y1 + (src_clipy1*(dest_height_range<<1) + src_height_range)/(src_height_range<<1);
		dy2 = dest_y1 + (src_clipy2*(dest_height_range)<<1) + src_height_range/(src_height_range<<1);		

		GDI_CLIP_TWO_RECT(
			GDI_RESIZER.want_dx1, GDI_RESIZER.want_dy1,
			GDI_RESIZER.want_dx2, GDI_RESIZER.want_dy2,
			dx1,dy1,
			dx2,dy2,
			return 0);

		//W05.39 Check points may be out of clipping area because of dividing
		while ( (((GDI_RESIZER.want_dx1 - GDI_RESIZER.offset_dx) * src_width_range << 1) + dest_width_range) / (dest_width_range << 1) < src_clipx1 )
			GDI_RESIZER.want_dx1++;

		while((((GDI_RESIZER.want_dy1 - GDI_RESIZER.offset_dy) * src_height_range << 1) + dest_height_range) / (dest_height_range << 1) < src_clipy1)
			GDI_RESIZER.want_dy1++;

		while ( (((GDI_RESIZER.want_dx2 - GDI_RESIZER.offset_dx) * src_width_range << 1) + dest_width_range) / (dest_width_range << 1) > src_clipx2 )
			GDI_RESIZER.want_dx2--;

		while((((GDI_RESIZER.want_dy2 - GDI_RESIZER.offset_dy) * src_height_range << 1) + dest_height_range) / (dest_height_range << 1)> src_clipy2)
			GDI_RESIZER.want_dy2--;
	}


	// non resize handler
	if(src_width == dest_width && src_height == dest_height)
	{
		U32 bytes_per_pixel = gdi_bits_per_pixel(gdi_act_layer->cf) >> 3;
		GDI_RESIZER.want_sx_table = NULL;
		GDI_RESIZER.dest = gdi_act_layer->buf_ptr;
		if(dir_x >0)
		{
			GDI_RESIZER.want_sx 		=
			GDI_RESIZER.want_start_sx = GDI_RESIZER.want_dx1 - dest_x1;
			GDI_RESIZER.want_end_sx 	= GDI_RESIZER.want_dx2 - dest_x1;
			
			GDI_RESIZER.dest 		+= GDI_RESIZER.want_dx1*bytes_per_pixel;
		}
		else
		{
			GDI_RESIZER.want_sx 		=
			GDI_RESIZER.want_start_sx = GDI_RESIZER.want_dx2 - dest_x1;
			GDI_RESIZER.want_end_sx  = GDI_RESIZER.want_dx1 - dest_x1;
			GDI_RESIZER.dest 		+= GDI_RESIZER.want_dx2*bytes_per_pixel;			
		}
		if(dir_y >0)
		{
			GDI_RESIZER.want_sy 		=
			GDI_RESIZER.want_start_sy = GDI_RESIZER.want_dy1 - dest_y1;
			GDI_RESIZER.want_end_sy 	= GDI_RESIZER.want_dy2 - dest_y1;
			
			GDI_RESIZER.dest 		+= GDI_RESIZER.want_dy1*gdi_act_layer->width*bytes_per_pixel;
			GDI_RESIZER.dest_pitch_jump = (gdi_act_layer->width - (GDI_RESIZER.want_dx2-GDI_RESIZER.want_dx1+1)) * bytes_per_pixel; ///TODO: only support dir_x>0
		}
		else
		{
			GDI_RESIZER.want_sy 		=
			GDI_RESIZER.want_start_sy = GDI_RESIZER.want_dy2 - dest_y1;
			GDI_RESIZER.want_end_sy  = GDI_RESIZER.want_dy1 - dest_y1;
			
			GDI_RESIZER.dest 		+= GDI_RESIZER.want_dy2*gdi_act_layer->width*bytes_per_pixel;
			GDI_RESIZER.dest_pitch_jump = -(gdi_act_layer->width + (GDI_RESIZER.want_dx2-GDI_RESIZER.want_dx1+1)) * bytes_per_pixel; ///TODO: only support dir_x>0
		}
		gdi_resizer_put = gdi_non_resizer_put_table[gdi_act_layer->cf];

		return 1;		
	}


	// return error when want_sx_table memory is not enough
	if ( GDI_RESIZER.want_dx2-GDI_RESIZER.want_dx1+1 > GDI_MAX_RESIZE_WIDTH)
    {
        return -1;
    }

        GDI_RESIZER.want_sx_table = (S16*)gdi_alloc_ext_mem(GDI_MAX_RESIZE_WIDTH * sizeof(S16));
        if (GDI_RESIZER.want_sx_table == NULL)
        {
            return 0;
        }

	// make want_x table
	{
		S32 x;
		S32 i;
		S32 start_dx,end_dx;

		if(dir_x>0)
		{
			start_dx = GDI_RESIZER.want_dx1;
			end_dx = GDI_RESIZER.want_dx2;
		}
		else
		{
			start_dx = GDI_RESIZER.want_dx2;
			end_dx = GDI_RESIZER.want_dx1;
		}
			
		for(i=0,x=start_dx;x<=end_dx;x+=dir_x,i++)
		{
			S32 d = x - dest_x1;
			GDI_RESIZER.want_sx_table[i] = (S16)((((d) * src_width_range << 1) + dest_width_range) / (dest_width_range << 1));
		}
		GDI_RESIZER.want_sx_table_end = GDI_RESIZER.want_sx_table+i;
		GDI_RESIZER.next_want_sx = GDI_RESIZER.want_sx_table;
	}

	if(dir_y>0)
		GDI_RESIZER.next_want_dy = GDI_RESIZER.want_dy1;
	else
		GDI_RESIZER.next_want_dy = GDI_RESIZER.want_dy2;

	// set the put pixel function pointer
	gdi_resizer_put = gdi_resizer_put_table[gdi_act_layer->cf];
	// init want position
	if(dir_x>0)
		GDI_RESIZER.dest = gdi_act_layer->buf_ptr + (((GDI_RESIZER.want_dx1+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )* bitsperpixels[gdi_act_layer->vcf])>>3);
	else
		GDI_RESIZER.dest = gdi_act_layer->buf_ptr + (((GDI_RESIZER.want_dx2+ GDI_RESIZER.next_want_dy* gdi_act_layer->width )* bitsperpixels[gdi_act_layer->vcf])>>3);
	
	GDI_RESIZER.want_sx = *GDI_RESIZER.next_want_sx++;
	GDI_RESIZER.want_sy = ((((GDI_RESIZER.next_want_dy  - GDI_RESIZER.offset_dy) * src_height_range << 1) +  dest_height_range) / (dest_height_range << 1));
	GDI_RESIZER.next_want_dy +=dir_y;
	return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_resizer_deinit
 * DESCRIPTION
 *  Deinit resizer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_resizer_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: use memory allocator
    if (GDI_RESIZER.want_sx_table)
    {
        gdi_free_ext_mem((void*)&GDI_RESIZER.want_sx_table);
        GDI_RESIZER.want_sx_table = NULL;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  gdi_fill_dot_rect
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  
 *****************************************************************************/
void gdi_fill_dot_rect(S32 x1,S32 y1,S32 x2,S32 y2,gdi_color c)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_fill_dot_rect)
    {
        gd_fill_dot_rect[gdi_act_layer->cf](
                                                gdi_act_layer->buf_ptr,
                                                gdi_act_layer->width,
                                                gdi_act_layer->height,
                                                x1,y1,
                                                x2,y2,
                                                gdi_act_layer->clipx1,
                                                gdi_act_layer->clipy1,
                                                gdi_act_layer->clipx2,
                                                gdi_act_layer->clipy2,
                                                c);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_fill_dot_rect)
}

void gdi_bitblt_internal(U8* src_ptr, U32 src_pitch, 
			S32 src_offset_x, S32 src_offset_y, 
			U32 src_width, U32 src_height,
			gdi_color_format src_cf,
			U8* dest_ptr, U32 dest_pitch,
			S32 dest_offset_x, S32 dest_offset_y,
			S32 dest_clip_x1, S32 dest_clip_y1, S32 dest_clip_x2, S32 dest_clip_y2,
			gdi_color_format dest_cf, U32 dest_buf_size,
			BOOL tilt,
			BOOL enable_src_key, gdi_color src_key,
			BOOL is_alpha_blending, U8 alpha_value,
			BOOL is_rop_mode, U8 rop_value,
			U8 transform_value,
			U8 transform_direction)
{
#if defined(GDI_USING_2D_ENGINE_V2)
	gdi_2d_buffer_struct src;
	gdi_2d_begin();
    if (GDI_TRANSFORM_DIRECTION_RB == transform_direction)
    {
	    gdi_2d_set_buffer(&src,src_ptr,src_pitch,
		    		src_width,src_height,
			    	src_offset_x + src_width - 1, src_offset_y + src_height - 1,
				    src_offset_x,src_offset_y,
				    src_offset_x + src_width - 1, src_offset_y + src_height - 1,
				    src_cf);
	    gdi_2d_set_dest_buffer(dest_ptr, dest_pitch,
		    		src_width, src_height,
			    	dest_offset_x + src_width - 1, dest_offset_y + src_height - 1,
				    dest_clip_x1, dest_clip_y1,
				    dest_clip_x2, dest_clip_y2,
				    dest_cf);
    }
    else
    {
	    gdi_2d_set_buffer(&src,src_ptr,src_pitch,
		    		src_width,src_height,
			    	src_offset_x,src_offset_y,
				    src_offset_x,src_offset_y,
				    src_offset_x + src_width - 1, src_offset_y + src_height - 1,
				    src_cf);
	    gdi_2d_set_dest_buffer(dest_ptr, dest_pitch,
		    		src_width, src_height,
			    	dest_offset_x, dest_offset_y,
				    dest_clip_x1, dest_clip_y1,
				    dest_clip_x2, dest_clip_y2,
				    dest_cf);
    }
	gdi_2d_bitblt(tilt,
			enable_src_key, src_key,
			is_alpha_blending, alpha_value,
			is_rop_mode, rop_value,
			transform_value,
			transform_direction,
			&src, 1);
	gdi_2d_end();
#endif
}

void gdi_bits_draw(S32 x,S32 y,U8* src,S32 src_size,S32 w,S32 h,S32 bits_per_pixel,gdi_color palette[])
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_bits_draw)
    {
        gd_image_bits_draw[gdi_act_layer->cf](
                                                gdi_act_layer->buf_ptr,
                                                gdi_act_layer->width,
                                                gdi_act_layer->height,
                                                x,y,
                                                x+w-1,y+h-1,
                                                src,w,h,
                                                0,0,w-1,h-1,
                                                src_size,bits_per_pixel,palette,
                                                gdi_act_layer->clipx1,
                                                gdi_act_layer->clipy1,
                                                gdi_act_layer->clipx2,
                                                gdi_act_layer->clipy2);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_bits_draw)
}


#define R_OF_RGB565(p)      ((p) >> 11)
#define G_OF_RGB565(p)      (((p) << 21) >> 26)
#define B_OF_RGB565(p)      (((p) << 27) >> 27)

/*****************************************************************************
 * FUNCTION
 *  gdi_rgb565_to_rgb888
 * DESCRIPTION
 *  convert RGB565 to RGB888
 * PARAMETERS
 *  p       [IN]    RGB565 pixel
 * RETURNS
 *  24-bit RGB888 pixel
 *****************************************************************************/
U32 gdi_rgb565_to_rgb888(U32 p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32     result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* extend p's B[4:0] to result B[7:0] */
    result = B_OF_RGB565(p) << 3;

    /* extend p's G[10:5] to result G[15:8] */
    result += G_OF_RGB565(p) << (8 + 2);

    /* extend p's R[15:11] to result B[23:16] */
    result += R_OF_RGB565(p) << (16 + 3);

    return result;
}


void gdi_draw_circle(S32 x, S32 y, S32 r, gdi_color circle_color)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_draw_circle)
    {
        float delta;
        S32 m, n;

        for (delta = 5.0 / 4 - r, m = 0, n = r; m <= n; m ++)
        {
            gdi_draw_point(x + m, y + n, circle_color);
            gdi_draw_point(x + m, y - n, circle_color);
            gdi_draw_point(x - m, y + n, circle_color);
            gdi_draw_point(x - m, y - n, circle_color);
            gdi_draw_point(x + n, y + m, circle_color);
            gdi_draw_point(x + n, y - m, circle_color);
            gdi_draw_point(x - n, y + m, circle_color);
            gdi_draw_point(x - n, y - m, circle_color);

            if (delta >= 0)
            {
                delta += 2.0 * (m - n) + 5;
                n --;
            }
            else
            {
                delta += m * 2.0 + 3;
            }
        }
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_draw_circle)
}

void gdi_draw_solid_circle(S32 x, S32 y, S32 r, gdi_color circle_color)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_draw_solid_circle)
    {
        float delta;
        S32 m, n;

        for (delta = 5.0 / 4 - r, m = 0, n = r; m <= n; m ++)
        {
            gdi_draw_line(x + m, y + n, x + m, y - n, circle_color);
            gdi_draw_line(x - m, y + n, x - m, y - n, circle_color);
            gdi_draw_line(x + n, y + m, x + n, y - m, circle_color);
            gdi_draw_line(x - n, y + m, x - n, y - m, circle_color);

            if (delta >= 0)
            {
                delta += 2.0 * (m - n) + 5;
                n --;
            }
            else
            {
                delta += m * 2.0 + 3;
            }
        }
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_draw_solid_circle)
}

static void gdi_draw_arc_int(S32 circle_x, S32 circle_y, S32 circle_r, int startAngle, int endAngle, gdi_color color)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_draw_arc_int)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 
     * Bresenham Algorithm: Draw 1/8 circle
     */
    int x, y, d;
    int ang;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = 0;
    y = circle_r;
    d = 1 - circle_r;

    while (x <= y)
    {
        ang = atan2(y, x) * 180 / 3.1415926;
        if (90 - ang >= startAngle && 90 - ang <= endAngle)
        {   /* first 1/8 circle, angle:(0~45), coord.:(x,y) */
            gdi_draw_point(circle_x + x, circle_y + y, color);
            gdi_draw_point(circle_x + x, circle_y + y - 1, color);
        }
        if (ang >= startAngle && ang <= endAngle)
        {   /* second 1/8 circle, angle:(45~90), coord.:(y,x) */
            gdi_draw_point(circle_x + y, circle_y + x, color);
            gdi_draw_point(circle_x + y, circle_y + x -1, color);
        }
        if (180 - ang >= startAngle && 180 - ang <= endAngle)
        {   /* third 1/8 circle, angle:(90~135), coord.:(y,-x) */
            gdi_draw_point(circle_x + y, circle_y - x, color);
            gdi_draw_point(circle_x + y + 1, circle_y - x, color);
        }
        if (90 + ang >= startAngle && 90 + ang <= endAngle)
        {   /* fourth 1/8 circle, angle:(135~180), coord.:(x,-y) */
            gdi_draw_point(circle_x + x, circle_y - y, color);
            gdi_draw_point(circle_x + x, circle_y - y - 1, color);
        }
        if (270 - ang >= startAngle && 270 - ang <= endAngle)
        {   /* fifth 1/8 circle, angle:(180~225), coord.:(-x,-y) */
            gdi_draw_point(circle_x - x, circle_y - y, color);
            gdi_draw_point(circle_x - x, circle_y - y - 1, color);
        }
        if (180 + ang >= startAngle && 180 + ang <= endAngle)
        {   /* sixth 1/8 circle, angle:(225~270), coord.:(-y,-x) */
            gdi_draw_point(circle_x - y, circle_y - x, color);
            gdi_draw_point(circle_x - y, circle_y - x - 1, color);
        }
        if (360 - ang >= startAngle && 360 - ang <= endAngle)
        {   /* seventh 1/8 circle, angle:(270~315), coord.:(-y,x) */
            gdi_draw_point(circle_x - y, circle_y + x, color);
            gdi_draw_point(circle_x - y, circle_y + x - 1, color);
        }
        if (270 + ang >= startAngle && 270 + ang <= endAngle)
        {   /* eighth 1/8 circle, angle:(315~360), coord.:(-x,y) */
            gdi_draw_point(circle_x - x, circle_y + y, color);
            gdi_draw_point(circle_x - x, circle_y + y - 1, color);
        }
        if (d > 0)
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        else
        {
            d += 2 * x + 3;
        }
        x++;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_draw_arc_int)
}

static void gdi_draw_half_circle_int(S32 circle_x, S32 circle_y, S32 circle_r, S32 width, int angle, gdi_color color)
{
    int dx = (circle_r - (width + 1) / 2) * sin(angle * 3.1415926 / 180);
    int dy = (circle_r - (width + 1) / 2) * cos(angle * 3.1415926 / 180);
    int cx = circle_x + dx;
    int cy = circle_y + dy;
    if (angle <= 180) cx++; else cx--;
    if (angle >= 90 && angle <= 270) cy--; else cy++;
    gdi_draw_solid_circle(cx, cy,  (width + 1)/ 2, color);
}

static void gdi_draw_half_circle(S32 circle_x, S32 circle_y, S32 circle_r, S32 width, int startAngle, int angleExtent, gdi_color color)
{
    int endAngle;
    if (angleExtent > 360) angleExtent = 360;
    endAngle = startAngle + angleExtent;
    //gdi_draw_half_circle_int(circle_x, circle_y, circle_r, width, startAngle, color);
    if (endAngle > 360)
    {
        gdi_draw_half_circle_int(circle_x, circle_y, circle_r, width, endAngle - 360, color);
    }
    else
    {
        gdi_draw_half_circle_int(circle_x, circle_y, circle_r, width, endAngle, color);
    }
}

void gdi_draw_arc(S32 circle_x, S32 circle_y, S32 circle_r, int startAngle, int angleExtent, gdi_color color)
{
    int endAngle;
    if (angleExtent > 360) angleExtent = 360;
    endAngle = startAngle + angleExtent;
    if (endAngle > 360)
    {
        gdi_draw_arc_int(circle_x, circle_y, circle_r, startAngle, 360, color);
        gdi_draw_arc_int(circle_x, circle_y, circle_r, 0, endAngle - 360, color);
    }
    else
    {
        gdi_draw_arc_int(circle_x, circle_y, circle_r, startAngle, endAngle, color);
    }
}

void gdi_draw_arc_ext(S32 circle_x, S32 circle_y, S32 circle_r, S32 width, int startAngle, int angleExtent, gdi_color color)
{
    S32 i;
    for (i = 0; i < width; ++i)
    {
        gdi_draw_arc(circle_x, circle_y, circle_r - i, startAngle, angleExtent, color);
    }
}

void gdi_draw_ring(S32 circle_x, S32 circle_y, S32 circle_r, S32 width, int startAngle, int angleExtent, gdi_color sColor, gdi_color mColor, gdi_color eColor)
{
    gdi_draw_arc_ext(circle_x, circle_y, circle_r, width, startAngle, angleExtent, mColor);
    gdi_draw_half_circle_int(circle_x, circle_y, circle_r, width, startAngle, sColor);
    gdi_draw_half_circle(circle_x, circle_y, circle_r, width, startAngle, angleExtent, eColor);
}

void gdi_draw_solid_arc(S32 circle_x, S32 circle_y, S32 circle_r, int startAngle, int angleExtent, gdi_color color)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_draw_solid_arc)
        
    gdi_draw_arc(circle_x, circle_y, circle_r, startAngle, angleExtent, color);
    circle_r--;
    while (circle_r > 0)
    {
        gdi_draw_arc(circle_x, circle_y, circle_r, startAngle, angleExtent, color);
        gdi_draw_point(circle_x + circle_r, circle_y + circle_r, color);
        gdi_draw_point(circle_x + circle_r, circle_y - circle_r, color);
        gdi_draw_point(circle_x - circle_r, circle_y - circle_r, color);
        gdi_draw_point(circle_x - circle_r, circle_y + circle_r, color);
        circle_r--;
    }
    gdi_draw_point(circle_x, circle_y, color);
    
    GDI_EXIT_CRITICAL_SECTION(gdi_draw_solid_arc)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_draw_antialiasing_line
 * DESCRIPTION
 *  draw a anti-aliasing line
 * PARAMETERS
 *  x1          [IN]    the start point x1
 *  y1          [IN]    the start point y1
 *  x2          [IN]    the end point x2
 *  y2          [IN]    the end point y2
 *  line_color  [IN]    the color of line
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_draw_antialiasing_line(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_draw_antialiasing_line)
    const S32 gaussian_integral[21] =   {   32767,      26958,      21431,      16431,      12127,
                                            8603,       5859,       3825,       2393,       1432,
                                            820,        449,        234,        117,         55,
                                            25,         11,          4,          1,          0,
                                            0};
/*        __|__                         */
/*      _/  |  \_                       */
/*     /    |    \                      */
/* ___/     |     \___                  */
/* --------------------------->x-axis   */
/*          0    1     2    3           */
/* the gaussian_integral[x*10] is the integral of gaussian from x to infinity and shift left 16 */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL steep;                                             /* y-scan or x-scan */
    S32 slope, dx, dy, d, incrE, incrNE, x, y, two_v_dx;    /* slope is the direction that y goes */
    U32 lineA, lineR, lineG, lineB;                         /* color of line */
    double sqrt_result;                                     /* used to store result of sqrt() */
    S32 invDenom_i, two_dx_invDemon_i;                      /* used to compute distance between pixel and line */
    S32 tmp;                                                /* used in cliping */
    gdi_handle abm_src_layer;                               /* abm source layer */
    BOOL source_key_enable;                                 /* if the source layer enable the source key */
    gdi_color source_key_value;                             /* the source key value of abm source layer */
    S32 clipx1, clipx2, clipy1, clipy2;                     /* the clip area */
    U8* src_layer_buf_ptr = NULL;                           /* buf_ptr of abm_src_layer*/
    S32 src_layer_layer_width = 0;                          /* layer_width of abm_src_layer*/
    gd_get_buf_pixel_func src_layer_get_pixel = NULL;       /* get_buf_pixel() function pointer of abm_src_layer*/
    gd_color_to_rgb_func src_layer_color_to_rgb = NULL;     /* color_to_rgb() functio pointer of abm_src_layer*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((GDI_LAYER.clipy1 <= GDI_LAYER.clipy2) && (GDI_LAYER.clipx1 <= GDI_LAYER.clipx2));
    
    if ((y1 == y2) && (y1 >= GDI_LAYER.clipy1) && (y1 <= GDI_LAYER.clipy2)) // Horizontal Line /
	{
		if(x1 > x2)     // exchange x /
		{
		    tmp = x1;
            x1 = x2;
            x2 = tmp;
		}
        if((x1 <= GDI_LAYER.clipx2) && (x2 >= GDI_LAYER.clipx1))
        {
            GDI_CLIP_LINE_X_TEST(x1,x2);
            GDI_DRAW_H_LINE(x1, x2, y1, line_color);
    	}
	}
	else if ((x1 == x2) && (x1 >= GDI_LAYER.clipx1) && (x1 <= GDI_LAYER.clipx2)) // Vertical Line /
    {
		if(y1 > y2)     // exchange y /
		{
			tmp = y1;
            y1 = y2;
            y2 = tmp;
		}
        if((y1 <= GDI_LAYER.clipy2) && (y2 >= GDI_LAYER.clipy1))
        {
            GDI_CLIP_LINE_Y_TEST(y1,y2);
            GDI_DRAW_V_LINE(y1, y2, x1, line_color);
	    }
	}
    else
    {
        /* get abm source layer */
        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        gdi_get_alpha_blending_source_layer(&abm_src_layer);
        if (abm_src_layer != GDI_ERROR_HANDLE)
        {   
            gdi_layer_struct *tmpstruc = (gdi_layer_struct*)abm_src_layer;
            src_layer_buf_ptr = tmpstruc->buf_ptr;
            src_layer_layer_width = tmpstruc->width;
            src_layer_get_pixel = gd_get_buf_pixel[tmpstruc->cf];
            src_layer_color_to_rgb = gd_color_to_rgb[tmpstruc->cf];
        }
        
        /* clip */
        gdi_layer_get_clip(&clipx1, &clipy1, &clipx2, &clipy2);

        if (x1 > x2)    
        {
            /* exchange two points: (x1,y1) and (x2,y2)*/
            tmp = x1;
            x1 = x2;
            x2 = tmp;

            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        dx = x2 - x1;
        dy = y2 - y1;
        
        /* if the slope>1, need to exchange x-axis and y-axis */
        steep = (abs(y2 - y1) > abs(x2 - x1));  
        if (steep)
        {
            /* exchange x1 and y1, x2 and y2 */
            tmp = x1;
            x1 = y1;
            y1 = tmp;

            tmp = x2;
            x2= y2;
            y2 = tmp;
        }
        
        if (x1 > x2)    
        {
            /* exchange two points: (x1,y1) and (x2,y2) */
            tmp = x1;
            x1 = x2;
            x2 = tmp;

            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        
        dx = x2 - x1;
        dy = y2 - y1;
        
        if (dy < 0)
        {
            slope = -1;
            dy = -dy;
        }
        else
        {
            slope = 1;
        }

        /* variables for mid-point draw line algorithm */
        d = (2 * dy) - dx;
        incrE = 2 * dy;
        incrNE = 2 * (dy - dx);

        /* variables for anti-aliasing */
        two_v_dx = 0;
        sqrt_result = sqrt((double)(dx * dx + dy * dy));
        invDenom_i = (S32)((1.0 / (2.0 * sqrt_result)) * (1 << AA_LINE_PRECISION_BITS)); /* shift AA_LINE_PRECISION_BITS to make float to S32 */
        two_dx_invDemon_i = 2 * dx * invDenom_i;

        /* get line color rgb */
        gdi_act_color_to_rgb(&lineA, &lineR, &lineG, &lineB, line_color);

        for (x = x1, y = y1; x <= x2; x++)
        {
            S32 slope1, slope2, outx, outy, clip1, clip2;
            if (steep)
            {
                outx = y;
                outy = x;
                slope1 = slope;
                slope2 = 0;
                clip1 = clipx1;
                clip2 = clipx2;
            }
            else
            {
                outx = x;
                outy = y;
                slope1 = 0;
                slope2 = slope;
                clip1 = clipy1;
                clip2 = clipy2;
            }
            do
            {
                if ((outx < clipx1) || (outx > clipx2) ||
            	    (outy < clipy1) || (outy > clipy2))
            	{
            	    break;	
            	}
                ANTIALIASING_LINE_PUT_PIXEL(outx, outy, lineR, lineG, lineB, two_v_dx * invDenom_i);
                tmp = y + slope;
                if (tmp >= clip1 && tmp <= clip2)
                {
                    ANTIALIASING_LINE_PUT_PIXEL(outx + slope1, outy + slope2, lineR, lineG, lineB, two_dx_invDemon_i - two_v_dx * invDenom_i);
                }
                tmp = y - slope;
                if (tmp >= clip1 && tmp <= clip2)
                {
                    ANTIALIASING_LINE_PUT_PIXEL(outx - slope1, outy - slope2, lineR, lineG, lineB, two_dx_invDemon_i + two_v_dx * invDenom_i);
                }
            }while(0);
            if (d < 0)
            {
                two_v_dx = d + dx;
                d += incrE;
            }
            else
            {
                two_v_dx = d - dx;
                d += incrNE;
                y += slope;
            }
        }
    }
 
    GDI_EXIT_CRITICAL_SECTION(gdi_draw_antialiasing_line)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_draw_polygon
 * DESCRIPTION
 *  draw a polygon
 * PARAMETERS
 *  point_array [IN]    point array
 *  point_num   [IN]    the number of elements of point array
 *  color       [IN]    the color of polygon
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_draw_polygon(gdi_point2D_struct point[], U32 point_num, gdi_color color)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_draw_polygon)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/       
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (point_num == 0)
    {
        GDI_RETURN_VOID;
    }
    if (point_num == 1)
    {
        gdi_draw_point(point[0].x, point[0].y, color);
        GDI_RETURN_VOID;
    }
    for (i = 0 ; i < point_num ; i++)
    {
        U32 idx = (i + 1);
        if (i == (point_num - 1))
        {
            idx = 0;
        }
        gdi_draw_line_ext(point[i].x, point[i].y, point[idx].x, point[idx].y, color, FALSE);
    }
    
    GDI_EXIT_CRITICAL_SECTION(gdi_draw_polygon)
}


static void gdi_draw_solid_polygon_AddNode(
                gdi_polygon_edge_struct **head, 
                gdi_polygon_edge_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*head == NULL)
    {
        *head = node;
        node->next = NULL;
    }
    else
    {
        gdi_polygon_edge_struct *Etmp = *head;
        if (((node->Xfra == 0) && (Etmp->Xint == node->Xint)) || 
            (Etmp->Xint > node->Xint))
        {
            node->next = Etmp;
            *head = node;
            return;
        }
        while (Etmp->next != NULL)
        {
            /* insert node with ordering by Xcur */
            if (((node->Xfra == 0) && (Etmp->next->Xint == node->Xint)) || 
                (Etmp->next->Xint > node->Xint))
            {
                node->next = Etmp->next;
                Etmp->next = node;
                break;
            }
            Etmp = Etmp->next;
        }
        if (Etmp->next == NULL)
        {
            /* insert to tail */
            Etmp->next = node;
            node->next = NULL;
        }
    }
}
static void gdi_draw_solid_polygon_RemoveNextNode(
                gdi_polygon_edge_struct **head, 
                gdi_polygon_edge_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node == NULL)
    {
        *head = (*head)->next;
    }
    else if (node->next !=  NULL)
    {
        node->next = node->next->next;
    }
}

static void gdi_draw_solid_polygon_UpdateX(
                gdi_polygon_edge_struct *head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_polygon_edge_struct *Etmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Etmp = head;
    while (Etmp != NULL)
    {
        if (Etmp->slope_y == 0)
        {
            Etmp = Etmp->next;
            continue;
        }
        Etmp->Xfra += Etmp->slope_x;
        if (Etmp->Xfra > 0)
        {
            while (Etmp->Xfra > Etmp->slope_y)
            {
                Etmp->Xint++;
                Etmp->Xfra -= Etmp->slope_y;
            }
        }
        else if (Etmp->Xfra < 0)
        {
            while ((0 - Etmp->Xfra) > Etmp->slope_y)
            {
                Etmp->Xint--;
                Etmp->Xfra += Etmp->slope_y;
            }
        }
        Etmp = Etmp->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_draw_solid_polygon
 * DESCRIPTION
 *  draw a solid polygon
 * PARAMETERS
 *  point_array [IN]    point array
 *  point_num   [IN]    the number of elements of point array
 *  color       [IN]    the color of polygon
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_draw_solid_polygon(
            gdi_point2D_struct point[], 
            U32 point_num, 
            gdi_color color)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_draw_solid_polygon)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/       
    S32 i;
    S32 Ycur;   /* Current Y */
    gdi_polygon_edge_struct *AET_head = NULL, *AET_head_sort = NULL;    /* Active Edge Table */
    gdi_polygon_edge_struct *EYmin = NULL, *EYmax = NULL;  /* Edge with the smallest Y & largest Y */
    gdi_polygon_edge_struct *ET = NULL;     /* Edge Table*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (point_num == 0)
    {
        GDI_RETURN(GDI_SUCCEED);
    }
    else if (point_num == 1)
    {
        gdi_draw_point(point[0].x, point[0].y, color);
        GDI_RETURN(GDI_SUCCEED);
    }
    else if (point_num == 2)
    {
        gdi_draw_line_ext(point[0].x, point[0].y, point[1].x, point[1].y, color, FALSE);
        GDI_RETURN(GDI_SUCCEED);
    }

    ET = (gdi_polygon_edge_struct*)gdi_alloc_ext_mem(sizeof(gdi_polygon_edge_struct)*point_num);
    if (ET == NULL)
    {
        GDI_RETURN(GDI_FAILED);
    }
    
    /* init Edge Table (ET) */
    for (i = 0 ; i < point_num ; i++)
    {
        gdi_point2D_struct *p1, *p2;
        U32 idx = (i + 1);

        if (i == (point_num - 1))
        {
            idx = 0;
        }
        /* p1 is the point with smaller y */
        /* If p1.y==p2.y, p1 is the point with larger x. */
        if ((point[i].y < point[idx].y) ||
            ((point[i].y == point[idx].y) && (point[i].x > point[idx].x)))
        {
            p1 = &point[i];
            p2 = &point[idx];
        }
        else
        {
            p1 = &point[idx];
            p2 = &point[i];
        }
        ET[i].Ymax = p2->y;
        ET[i].Ymin = p1->y;
        ET[i].slope_x = p2->x - p1->x;
        ET[i].slope_y = p2->y - p1->y;
        ET[i].Xint = p1->x;
        ET[i].Xfra = ET[i].slope_y;
        if (ET[i].slope_x < 0)
        {
            ET[i].Xfra = 0 - ET[i].Xfra;
        }
        ET[i].next = NULL;

        /* Find EYmin and EYmax */
        if ((EYmin == NULL) || (ET[i].Ymin < EYmin->Ymin))
        {
            EYmin = &ET[i];
        }
        if ((EYmax == NULL) || (ET[i].Ymax > EYmax->Ymax))
        {
            EYmax = &ET[i];
        }
    }

    for (Ycur = EYmin->Ymin ; Ycur <= EYmax->Ymax ; )
    {
        gdi_polygon_edge_struct *Etmp = NULL, *Epre = NULL;

        /* remove edges with Ymax==Ycur from AET */
        Etmp = AET_head;
        while (Etmp != NULL)
        {
            if ((Etmp->Ymax <= Ycur) && (Ycur != EYmax->Ymax))
            {
                gdi_draw_solid_polygon_RemoveNextNode(&AET_head, Epre);
            }
            else
            {
                Epre = Etmp;
            }
            Etmp = Etmp->next;
        }
        
        /* resort by X */
        AET_head_sort = NULL;
        while (AET_head != NULL)
        {
            Etmp = AET_head;
            AET_head = AET_head->next;
            gdi_draw_solid_polygon_AddNode(&AET_head_sort, Etmp);
        }
        AET_head = AET_head_sort;
        
        /* move edges with Y==Ycur in ET to AET */
        for (i = 0 ; i < point_num ; i++)
        {
            if (ET[i].Ymin == Ycur)
            {
                gdi_draw_solid_polygon_AddNode(&AET_head, &ET[i]);
            }
        }
        /* draw scan line */
        Etmp = AET_head;
        while (Etmp != NULL)
        {
            gdi_polygon_edge_struct *Enxt = Etmp->next;
            while (Enxt != NULL)
            {
                if (Enxt->slope_y != 0)
                {
                    break;
                }
                Enxt = Enxt->next;
            }
            if (Enxt == NULL)
            {
                break;
            }
            if (Etmp->Xint == Enxt->Xint)
            {
                gdi_draw_point(Etmp->Xint, Ycur, color);
            }
            else
            {
                gdi_draw_line_ext(Etmp->Xint, Ycur, Enxt->Xint, Ycur, color, FALSE);
            }
            
            /* go to next next edge */
            Etmp = Enxt;
            Etmp = Etmp->next;
        }

        Ycur++;
        if (Ycur > gdi_act_layer->clipy2)   /* clip y */
        {
            break;
        }
        
        /* update Xcur of edges in AET */
        gdi_draw_solid_polygon_UpdateX(AET_head);

    }
    if (ET != NULL)
    {
        gdi_free_ext_mem((void**)&ET);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_draw_solid_polygon)
    return GDI_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_trans_color_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
gdi_img_buf_color_format_enum gdi_img_buf_trans_color_format(U32 gdi_color_format)
{
	switch(gdi_color_format)
	{
        case GDI_COLOR_FORMAT_16:
            return GDI_IMG_BUF_COLOR_FORMAT_RGB565;
            
        case GDI_COLOR_FORMAT_24:
            return GDI_IMG_BUF_COLOR_FORMAT_RGB888;
            
        case GDI_COLOR_FORMAT_32:
            return GDI_IMG_BUF_COLOR_FORMAT_ARGB8888;
            
        case GDI_COLOR_FORMAT_32_PARGB:
            return GDI_IMG_BUF_COLOR_FORMAT_PARGB8888;

        case GDI_COLOR_FORMAT_PARGB6666:
            return GDI_IMG_BUF_COLOR_FORMAT_PARGB6666;
            
        default:
            return GDI_IMG_BUF_COLOR_FORMAT_UNKNOWN;
    
	}
}

/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_fill_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_fill_color(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    
    /* Optimize for empty size */
    if (width <= 0 || height <= 0)
    {
        return;
    }

    /* Optimize for 16 bits */
    switch (dst_buf->color_format)
    {
        case GDI_IMG_BUF_COLOR_FORMAT_RGB565:
            gdi_img_buf_fill_color_16(dst_buf, dst_color, width, height);
            break;
        #if !defined(GDI_SLIM_COLOR_FORMAT)
        case GDI_IMG_BUF_COLOR_FORMAT_RGB888:
        case GDI_IMG_BUF_COLOR_FORMAT_PARGB6666:
            gdi_img_buf_fill_color_24(dst_buf, dst_color, width, height);
            break;
        #endif
        
        case GDI_IMG_BUF_COLOR_FORMAT_ARGB8888:
        case GDI_IMG_BUF_COLOR_FORMAT_PARGB8888:
            gdi_img_buf_fill_color_32(dst_buf, dst_color, width, height);
            break;
        default:
            GDI_DEBUG_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_blending_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_blending_color(
    gdi_img_buf_struct *dst_buf, 
    gdi_color pargb8888_color,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    
    /* Optimize for empty size */
    if (width <= 0 || height <= 0)
    {
        return;
    }

    /* Optimize for transparent color */
    if (GDI_A_OF_PARGB8888(pargb8888_color) == 0x00)
    {
        /* Do nothing */
        return;
    }

    /* Optimize for opaque color */
    if (GDI_A_OF_PARGB8888(pargb8888_color) == 0xff)
    {
        switch (dst_buf->color_format)
        {
            case GDI_IMG_BUF_COLOR_FORMAT_RGB565:
                gdi_img_buf_fill_color_16(dst_buf, GDI_RGB565_FROM_ARGB8888(pargb8888_color), width, height);
                break;
            #if !defined(GDI_SLIM_COLOR_FORMAT)
            case GDI_IMG_BUF_COLOR_FORMAT_RGB888:
                gdi_img_buf_fill_color_24(dst_buf, GDI_RGB888_FROM_ARGB8888(pargb8888_color), width, height);
                break;
            #endif
            #ifdef GDI_LAYER_PARGB6666_SUPPORT
            case GDI_IMG_BUF_COLOR_FORMAT_PARGB6666:
                gdi_img_buf_fill_color_24(dst_buf, GDI_PARGB6666_FROM_ARGB8888(pargb8888_color), width, height);
                break;
            #endif
            case GDI_IMG_BUF_COLOR_FORMAT_ARGB8888:
            case GDI_IMG_BUF_COLOR_FORMAT_PARGB8888:
                gdi_img_buf_fill_color_32(dst_buf, pargb8888_color, width, height);
                break;
            default:
                GDI_DEBUG_ASSERT(0);
                break;
        }
        return;
    }

    switch (dst_buf->color_format)
    {
        case GDI_IMG_BUF_COLOR_FORMAT_RGB565:
            gdi_img_buf_blending_color_16(dst_buf, pargb8888_color, width, height);
            break;
        #if !defined(GDI_SLIM_COLOR_FORMAT)
        case GDI_IMG_BUF_COLOR_FORMAT_RGB888:
            gdi_img_buf_blending_color_24(dst_buf, pargb8888_color, width, height);
            break;
        #endif

    #ifdef GDI_LAYER_PARGB6666_SUPPORT
        case GDI_IMG_BUF_COLOR_FORMAT_PARGB6666:
            gdi_img_buf_blending_color_PARGB6666(dst_buf, pargb8888_color, width, height);
            break;
    #endif
        
        case GDI_IMG_BUF_COLOR_FORMAT_ARGB8888:
            gdi_img_buf_convert_PARGB8888_from_ARGB8888(dst_buf, width, height);
            gdi_img_buf_blending_color_PARGB8888(dst_buf, pargb8888_color, width, height);
            gdi_img_buf_convert_ARGB8888_from_PARGB8888(dst_buf, width, height);
            break;
        case GDI_IMG_BUF_COLOR_FORMAT_PARGB8888:
            gdi_img_buf_blending_color_PARGB8888(dst_buf, pargb8888_color, width, height);
            break;
        default:
            // not support
            GDI_DEBUG_ASSERT(0);
            break;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_flatten
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_flatten(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color_key,
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);

    /* Optimize for empty size */
    if (width <= 0 || height <= 0)
    {
        return;
    }

    if (dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565 &&
        src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565)
    {
        gdi_img_buf_flatten_16_16(dst_buf, dst_color_key, src_buf, width, height);
    }
    else 
    {
        gdi_img_buf_flatten_general(dst_buf, dst_color_key, src_buf, width, height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_copy
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_copy(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);

    /* Optimize for empty size */
    if (width <= 0 || height <= 0)
    {
        return;
    }

    /* Optimize for same color format */
    if (dst_buf->color_format == src_buf->color_format)
    {
        gdi_img_buf_copy_same_format(dst_buf, src_buf, width, height);
        return;
    }
    
    gdi_img_buf_copy_general(dst_buf, src_buf, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_copy
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_blending(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);

    /* Optimize for empty size */
    if (width <= 0 || height <= 0)
    {
        return;
    }

    if (src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888)
    {
        // not support
        GDI_DEBUG_ASSERT(0);
        return;
    }

    /* Optimize for non-alpha source */
    if (src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565 ||
        src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_RGB888)
    {
        /* Optimize for same color format */
        if (dst_buf->color_format == src_buf->color_format)
        {
            gdi_img_buf_copy_same_format(dst_buf, src_buf, width, height);
            return;
        }
        
        gdi_img_buf_copy_general(dst_buf, src_buf, width, height);
        return;
    }

    if (src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888)
    {
        if (dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565)
        {
            gdi_img_buf_blending_16_PARGB8888(dst_buf, src_buf, width, height);
        }
        #if !defined(GDI_SLIM_COLOR_FORMAT)
        else if (dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_RGB888)
        {
            gdi_img_buf_blending_24_PARGB8888(dst_buf, src_buf, width, height);
        }
        #endif
        
        else if (dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888)
        {
            gdi_img_buf_convert_PARGB8888_from_ARGB8888(dst_buf, width, height);
            gdi_img_buf_blending_PARGB8888_PARGB8888(dst_buf, src_buf, width, height);
            gdi_img_buf_convert_ARGB8888_from_PARGB8888(dst_buf, width, height);
        }
        else if (dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888)
        {
            gdi_img_buf_blending_PARGB8888_PARGB8888(dst_buf, src_buf, width, height);
        }
    #ifdef GDI_LAYER_PARGB6666_SUPPORT
        else if (dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666)
        {
            gdi_img_buf_blending_PARGB8888_to_PARGB6666(dst_buf, src_buf, width, height);
        }
    #endif
        else
        {
            // not support
            GDI_DEBUG_ASSERT(0);
        }
        return;
    }
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    else if (src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666)
    {
        if (dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666)
        {
            gdi_img_buf_blending_PARGB6666_to_PARGB6666(dst_buf, src_buf, width, height);
        }
        else if (dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565)
        {
            gdi_img_buf_blending_PARGB6666_to_RGB565(dst_buf, src_buf, width, height);
        }
        else
        {
            GDI_DEBUG_ASSERT(0);
        }
        return;
    }
#endif
    
    GDI_DEBUG_ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_blending_scale
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_blending_scale(
    gdi_img_buf_struct *dst_buf, 
    S32 dst_width,
    S32 dst_height,
    const gdi_img_buf_struct *src_buf,
    S32 src_width,
    S32 src_height,
    S32 offset_x,
    S32 offset_y)
{
}

/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_prepare_img_buf_struct
 * DESCRIPTION
 *  given the buffer info and dest_rect and buffer clip,
 *  return a gdi_img_buf_struct and gdi_rect_struct.
 *  If one of clip value is negative, return gdi_img_buf_struct and gdi_rect_struct without clipping.
 *  If return GDI_FAILED, means dest_rect and clip area has no intersection.
 * PARAMETERS
 *  output_img_buf_struct   [OUT]      gdi_img_buf_struct
 *  dest_rect               [IN/OUT]   destination area
 *  buf_ptr                 [IN]       buffer pointer
 *  buf_width               [IN]       buffer width
 *  buf_bpp                 [IN]       buffer byte per pixel
 *  buf_cf                  [IN]       buffer color format (ex, GDI_COLOR_FORMAT_16)
 *  clip_x1                 [IN]       clip area
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *  If return GDI_FAILED, means dest_rect and clip area has no intersection.
 *****************************************************************************/
GDI_RESULT gdi_img_buf_prepare_img_buf_struct(
                    gdi_img_buf_struct *output_img_buf_struct,
                    gdi_rect_struct *dest_rect,
                    U8 *buf_ptr,
                    S32 buf_width,
                    S32 buf_bpp,
                    U32 buf_cf,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    gdi_result ret = GDI_SUCCEED;

    if (output_img_buf_struct == NULL)
    {
        return GDI_SUCCEED;
    }

    do
    {
        if ((clip_x1 >= 0) && (clip_y1 >= 0) && (clip_x2 >= 0) && (clip_y2 >= 0))
        {
            ret = GDI_FAILED;
            GDI_CLIP_TWO_RECT(
                dest_rect->x1, 
                dest_rect->y1, 
                dest_rect->x2, 
                dest_rect->y2,
                clip_x1,
                clip_y1,
                clip_x2,
                clip_y2,
                break);
            ret = GDI_SUCCEED;
        }

        output_img_buf_struct->pitch_bytes = buf_width * buf_bpp;
        output_img_buf_struct->color_format = gdi_img_buf_trans_color_format(buf_cf);
        output_img_buf_struct->ptr = buf_ptr;
        output_img_buf_struct->ptr += ((dest_rect->y1 * buf_width) + dest_rect->x1) * buf_bpp;
        
    } while(0);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_cf_get_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cf      [IN] Color format
 *  a       [IN] Alpha (0 ~ 255)
 *  r       [IN] Red (0 ~ 255)
 *  g       [IN] Green (0 ~ 255)
 *  b       [IN] Blue (0 ~ 255)
 * RETURNS
 *  Color value in given color format
 *****************************************************************************/
gdi_color gdi_cf_get_color(
            gdi_color_format cf,
            kal_uint32 a,
            kal_uint32 r,
            kal_uint32 g,
            kal_uint32 b)
{
    return gd_color_from_rgb[cf](a, r, g, b);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_cf_separate_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cf      [IN] Color format
 *  color   [IN] Color value in given color format
 *  a       [OUT] Alpha separated from color, ranges 0 ~ 255
 *  r       [OUT] Red component separated from color, ranges 0 ~ 255
 *  g       [OUT] Green component separated from color, ranges 0 ~ 255
 *  b       [OUT] Blue component separated from color, ranges 0 ~ 255
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_cf_separate_color(
        gdi_color_format cf,
        gdi_color color,
        kal_uint32 *a,
        kal_uint32 *r,
        kal_uint32 *g,
        kal_uint32 *b)
{
    gd_color_to_rgb[cf](a, r, g, b, color);
}

