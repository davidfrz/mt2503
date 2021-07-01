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
 *   gui_config.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   GUI Configuration
 *
 *                  gui_switch.h
 *                   /        \
 *           gui_config.h    wgui.h
 * There are three files containing configuration variables about gui components.
 * gui_switch.h is in the bottom layer.
 * All these configuration variable which can be modified by customers have been defined or switched in this file.
 * And all these configuration variable prefixed with CFG_
 * gui_config.h and wgui.h are in the topper layer
 * The macros and compile options used in gui components can be defined in these two files. 
 * Some of them based on the macros in gui_switch.h
 *
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


#ifndef __GUI_CONFIG_H__
#define __GUI_CONFIG_H__

#include "MMI_features.h"
#include "gui_switch.h"

#ifndef __OPTR_NONE__
#include "operator_gui.h"
#endif

/* *FORMATTER-DISABLE* */

/**********************************************************************************************/
/*                                                     Dependency and Exclusive Rules								          */
/*                                                   Please Do Not Modify under this Line								   */
/**********************************************************************************************/

/***************************** Do Not Modifiy ****************************************************/

/*************************** Dependency Rule of Wallpaper and List Background  ***********************/
/* __MMI_WALLPAPER_ON_BOTTOM__ must be defined in 128X160 and other LCD size more than 128X160 after 07A */
/**/#if !defined(__MMI_DM_BW_WITHOUT_WALLPAPER__) && !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X64__)					/**/
/**/	#define __MMI_WALLPAPER_ON_BOTTOM__												/**/	/* Detail Info: [Use an image on a new layer as the background]*/
/**/#endif																					/**/
/***************************** Do Not Modifiy ****************************************************/

/*************************** Dependency Rule of Two Line Menuitem  ***********************/
/**/#if !defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) && (defined(__MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__) || defined(__MMI_PROFILES_TWO_LINE_MENUITEM_DISPLAY__)) || defined(__MMI_BCR__)
/**/#define __MMI_UI_TWO_LINE_MENUITEM_STYLES__
/**/#endif																					/**/
/***************************** Do Not Modifiy ****************************************************/

/*************************** Dependency Rule of Highlight Effect *************************************/
/**/#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__													/**/
/**/	#ifndef	__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__										/**/
/**/		#error "Please define __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__ in MMI_features.h"		/**/
/**/	#endif																				/**/
/**/	#if		__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__	==	HIGHLIGHT_EFFECT_TRANSPARENCY	/**/
/**/		#define UI_LIST_EFFECT_TYPE TRANSPARENCY									/**/
/**/	#elif	__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__	==	HIGHLIGHT_EFFECT_FLASH_FEELING	/**/
/**/		#define UI_LIST_EFFECT_TYPE FLASH_FEELING										/**/
/**/	#elif	__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__	==	HIGHLIGHT_EFFECT_ANIMATION		/**/
/**/		#define UI_LIST_EFFECT_TYPE ANIMATION											/**/
/**/	#elif	__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__	==	HIGHLIGHT_EFFECT_SLIDE		    /**/
/**/		#define UI_LIST_EFFECT_TYPE SLIDE                                               /**/
/**/	#elif	__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__	==	HIGHLIGHT_EFFECT_NONE			/**/
/**/		#define UI_LIST_EFFECT_TYPE NONE												/**/
/**/	#else																				/**/
/**/		#error "Please define __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__ in MMI_features.h"		/**/
/**/	#endif																				/**/
/**/#endif																					/**/
/***************************** Do Not Modifiy ****************************************************/
#if 0
/* under construction !*/
/**/#ifndef	__MMI_UI_SOFTKEY_STYLE__														/**/			
/* under construction !*/
/**/#endif																					/**/
/**/#if		__MMI_UI_SOFTKEY_STYLE__	==	SOFTKEY_STYLE_DALMATIAN						/**/
/* under construction !*/
/* under construction !*/
/**/#elif	__MMI_UI_SOFTKEY_STYLE__	==	SOFTKEY_STYLE_TECHNO							/**/
/* under construction !*/
/* under construction !*/
/**/#endif																					/**/
/**/#if		__MMI_UI_SOFTKEY_STYLE__	==	SOFTKEY_STYLE_NONE								/**/
/**/	#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)				/**/
/* under construction !*/
/**/	#else																				/**/
/* under construction !*/
/**/	#endif																				/**/
/**/#endif																					/**/
/* under construction !*/
#endif//
/*************************** Dependency Rule of Statusbar *****************************************/
/**/#ifndef	__MMI_UI_STATUSBAR_STYLE__														/**/						
/**/	#error "Please define __MMI_UI_STATUSBAR_STYLE__ in MMI_features.h"					/**/
/**/#endif																					/**/
/**/																						/**/
#if 0
/**/#if defined(__MMI_UI_DALMATIAN_STATUSBAR__) && defined(__MMI_UI_DALMATIAN_SOFTKEYS__) 	/**/
/* under construction !*/
/**/#endif																					/**/
#endif//0
/***************************** Do Not Modifiy ****************************************************/

/***************************** Dependency Rule of Status Bar on Bottom *****************************/
/**/#if defined(__MMI_UI_DALMATIAN_STATUSBAR__) || defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) || defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
/**/	#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__												/**/
/**/		//#error "__MMI_UI_STATUS_BAR_AT_BOTTOM__ should not be defined in MMI_features.h because of dependency"
/**/		#undef __MMI_UI_STATUS_BAR_AT_BOTTOM__											/**/
/**/	#endif																				/**/
/**/#endif																					/**/
/***************************** Do Not Modifiy ****************************************************/

/***************************** Dependency Rule of BT Box idle short cuts *****************************/
/**/#if defined(__MMI_BTD_BOX_UI_STYLE__)                                             /**/
/**/	#define __MMI_BT_BOX_IDLE_SHORTCUTS__												/**/
/**/#endif																					/**/
/***************************** Do Not Modifiy ****************************************************/

/**********************************************************************************************/
/*                       End of Dependency and Exclusive Rules								          */
/**********************************************************************************************/

/* *FORMATTER-ENABLE* */

#define __MMI_PLUTO_GPRS__
//#define __MMI_PLUTO_LISTBOX__
//#define __MMI_PLUTO_DOUBLEPX_ROUND_CORNER__

#define __MMI_INSCREEN_MULTILINE_TEXTBOX__
#ifdef __MMI_INSCREEN_MULTILINE_TEXTBOX__
    #define INSCREEN_MUTLILINE_TITLE_ENABLE   1
    #define INSCREEN_MULTILINE_SHOW_TITLE  1        /* putting it 0 will display info bar */
#endif /* __MMI_INSCREEN_MULTILINE_TEXTBOX__ */ 
#define __NEW_MULTI_LINE_INPUTBOX__

    /* Use this parameter to change the device's color depth */
    /* currently supported values are 1,2,16,24,32           */
    /* Note: This is different from the GUIs color depth     */

#ifdef __BW_MMI__
#ifdef _WIN32
    #define DEVICE_COLOR_DEPTH          24
#else 
    #define DEVICE_COLOR_DEPTH          1
#endif 
#else /* __BW_MMI__ */ 
    #define DEVICE_COLOR_DEPTH          24
#endif /* __BW_MMI__ */ 

#if defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_7__)
    /* New style introduced in 08B for wider scrollbar width */
    #define UI_SCROLLBAR_STYLE_7

#elif defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_6__)
    /* New style introduced in 08A for wider scrollbar width */
    #define UI_SCROLLBAR_STYLE_6

#elif defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_5__)

    /* New style introduced in 07A for full-screen background */
    #define UI_SCROLLBAR_STYLE_5

#elif defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_4__)

    /* New style introduced in 07A for full-screen background */
    #define UI_SCROLLBAR_STYLE_4

#elif defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_3__)

    /* Thick scrollbar using predefined image */
    #define UI_SCROLLBAR_STYLE_3

#elif defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_2__)

    /* Rounded bar with arrows */
    #define UI_SCROLLBAR_STYLE_2

#elif defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_1__)

    /* Old-style flat scrollbar style */
    #define UI_SCROLLBAR_STYLE_1

//#elif defined(__MMI_OP12_SCROLLBAR_STYLE__)

    /* VFR specific style */
//    #define UI_SCROLLBAR_STYLE_8

#elif defined(__MMI_FTE_SUPPORT__)
    /* User style 7 to show thin scroll bar */
    #define UI_SCROLLBAR_STYLE_7

#elif defined(__MMI_MAINLCD_240X400__) && defined(__MMI_TOUCH_SCREEN__ )
    /* 240x400 with touch screen */
    #define UI_SCROLLBAR_STYLE_6

#elif defined(__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)

    #define UI_SCROLLBAR_STYLE_7


#elif defined(__MMI_MAINLCD_96X64__)
    #define UI_SCROLLBAR_STYLE_9


#elif !defined(MT6205B) && !defined(MT6205) && !defined(__MMI_MAINLCD_128X128__)

    /* Use style 4 for resolutions >= 128x160 by default */
    #define UI_SCROLLBAR_STYLE_4

#else 

    /* MT6205 can also turn on the new UI styles but it is slightly slower and 
     * larger on 128x128. 
     * Developers can decide whether the performance degration is acceptable */
    #define UI_SCROLLBAR_STYLE_1

#endif 


    /* Srollbar width                                                    */
    /* It can be defined in MMI_features.h or automatically decided here */
#if defined(CFG_UI_SCROLLBAR_WIDTH)
    #define UI_SCROLLBAR_WIDTH CFG_UI_SCROLLBAR_WIDTH
#else 
    #error "Wrong option"
#endif

#ifdef __MMI_FTE_SUPPORT__

    #if defined(__MMI_UI_SCROLLBAR_WIDER_STYLE_1__)
    /* Use style1 as indicator style  */
    #define UI_SCROLLBAR_WIDER_STYLE_1

    #elif defined(__MMI_UI_SCROLLBAR_WIDER_STYLE_2__)
    /* Use style2 as indicator style  */
    #define UI_SCROLLBAR_WIDER_STYLE_2

    #elif defined(__MMI_UI_SCROLLBAR_WIDER_STYLE_3__)
    /* Use style3 as indicator style  */
    #define UI_SCROLLBAR_WIDER_STYLE_3

    #elif defined(__MMI_UI_SCROLLBAR_WIDER_STYLE_4__)
    /* Use style4 as indicator style  */
    #define UI_SCROLLBAR_WIDER_STYLE_4

    #elif defined(__MMI_UI_SCROLLBAR_WIDER_STYLE_6__)
    /* Use style6 as indicator style  */
    #define UI_SCROLLBAR_WIDER_STYLE_6

    #elif defined(__MMI_UI_SCROLLBAR_WIDER_STYLE_7__)
    /* Use style7 as indicator style */
    #define UI_SCROLLBAR_WIDER_STYLE_7
    #else
    /* Use style5 as indicator style */
    #define UI_SCROLLBAR_WIDER_STYLE_5
    #endif

#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_FTE_SUPPORT__
    #ifdef GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN
        #define UI_SCROLLBAR_NARROW_WIDTH 6
    #endif

    #if defined(CFG_UI_SCROLLBAR_WIDER_WIDTH)
        #define UI_SCROLLBAR_WIDER_WIDTH CFG_UI_SCROLLBAR_WIDER_WIDTH
    #else 
        #error "Wrong option"
    #endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE_3__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE_2__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE_1__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif !defined(MT6205B) && !defined(MT6205)
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif 
/* under construction !*/
#if defined(__MMI_UI_SOFTKEY_DEFAULT_STYLE_2__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_UI_SOFTKEY_DEFAULT_STYLE_1__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif//0

    /* Use this parameter to specify that the device uses an */
    /* Indexed color system. Normally color depths <=8 use an   */
    /* Indexed color system.                           */
    /* Valid values are 0 and 1                        */
#define DEVICE_INDEXED_COLOR_SYSTEM    0

    /* Use this parameter to specify that the GUI uses an    */
    /* Indexed color system. Normally color depths <=8 use an   */
    /* Indexed color system                         */
    /* Valid values are 0 and 1                        */
#define UI_INDEXED_COLOR_SYSTEM        0

    /* Use this parameter to change the GUI color depth      */
    /* currently supported values are 1,2,16,24,32           */
    /* Note: This is the color depth used internally by the  */
    /* GUI. This is automatically converted to the device    */
    /* depth before displaying                         */
#define UI_COLOR_DEPTH              24

    /* Support for Keyboard: Simulator / Hardware            */
    /* Note: The simulator uses PC keyboard               */
    /* Valid values are 0 and 1                        */
#define UI_KEYBOARD_SUPPORT            1

    /* Support for Pointing device: Simulator / Hardware     */
    /* Note: The simulator uses PC mouse                  */
    /* Valid values are 0 and 1                        */
    /* Not available yet                            */
#define UI_POINTING_DEVICE_SUPPORT     0

    /* Support for Double buffering in the UI             */
    /* Valid values are 0 and 1. 1=Double buffering enabled  */
#define UI_DOUBLE_BUFFER_SUPPORT    1


/* code added vandana to enable the 4 way navigation key on the softkey background */
/* ISSUE GPRS PPT 6 BOTTOM NAVIAGTION KEYS */
#if defined(CFG_UI_ENABLE_BOTTOM_NAVIGATION_KEYS) && (CFG_UI_ENABLE_BOTTOM_NAVIGATION_KEYS == __ON__)
    #define ENABLE_BOTTOM_NAVIGATION_KEYS  1
#endif
    /* ISSUE GPRS PPT 6 END */
    /* Support for two way or four way navigation            */
    /* Valid values are one of the above navigation types    */
#if defined(CFG_UI_NAVIGATION_KEYS_TYPE)
    #define UI_NAVIGATION_KEYS_TYPE        CFG_UI_NAVIGATION_KEYS_TYPE
#else 
    #error "Wrong option"
#endif

    /* Quick startup build: For simulator testing            */
    /* Valid values are 0 and 1. If 1, quick start is enabled   */
#define BUILD_TYPE_X86WIN32_QUICK_START         0

    /* Disable redraw: For simulator testing              */
    /* Valid values are 0 and 1. If 1, Redraw is disabled    */
#define BUILD_TYPE_X86WIN32_DISABLE_REDRAW      0

    /* Double buffered graphics in Win32 platform            */
    /* Valid values are 0 and 1. 1=Double buffering enabled  */
#define BUILD_TYPE_X86WIN32_DOUBLE_BUFFERED     1

    /* 1: Simulates HW graphics on the simulator                      */
    /* 0: Uses simulator graphics                                  */
    /* Set this to 0 to build on the hardware */
#define WINGUI_SIMULATE_HW          0

    /* Supported Build Types                           */
    /* Value must be a word                         */
#define BUILD_TYPE_X86WIN32            0x00A1
#define BUILD_TYPE_HW_PLUTO            0x00A2

    /* Current MMI build type:                         */
    /* Value must be one of the above build types            */
#define MMI_BUILD_TYPE              BUILD_TYPE_HW_PLUTO

    /* GUI objects, feature support                    */

    /* Image fill support (bitmap textures) in filled areas  */
    /* Valid values are 0 and 1                        */
#define UI_BITMAP_FILL_SUPPORT         0

    /* Gradient color fill support in filled areas           */
    /* Valid values are 0 and 1                        */
#define UI_GRADIENT_COLOR_FILL_SUPPORT 0

    /* Horizontal scrolling and Horizontal scrollbar support */
    /* in multi-line input box. Valid values are 0 and 1     */
#define UI_MULTILINE_INPUTBOX_HSCROLL  1

    /* Date and Time input type selectors.                */
    /* None of the following are implemented currently       */

    /* Day input category types: Do not modify these values  */
    /* Input box type                               */
#define UI_DAY_INPUT_CATEGORY_TYPE1    1
    /* Calendar matrix type                         */
#define UI_DAY_INPUT_CATEGORY_TYPE2    2
    /* Spin control type                            */
#define UI_DAY_INPUT_CATEGORY_TYPE3    3

    /* Type of Day input to use in the GUI                */
    /* Valid values are one of the above types               */
#define UI_DAY_INPUT_CATEGORY_TYPE     UI_DAY_INPUT_CATEGORY_TYPE1

    /* Month input category types: Do not modify these values   */
    /* Input box type                               */
#define UI_MONTH_INPUT_CATEGORY_TYPE1  1
    /* Drop down list type                             */
#define UI_MONTH_INPUT_CATEGORY_TYPE2  2
    /* Spin control type                            */
#define UI_MONTH_INPUT_CATEGORY_TYPE3  3

    /* Type of Month input to use in the GUI              */
    /* Valid values are one of the above types               */
#define UI_MONTH_INPUT_CATEGORY_TYPE   UI_MONTH_INPUT_CATEGORY_TYPE1

    /* Year input category types: Do not modify these values */
    /* Input box type                               */
#define UI_YEAR_INPUT_CATEGORY_TYPE1   1
    /* Drop down list type                             */
#define UI_YEAR_INPUT_CATEGORY_TYPE2   2
    /* Spin control type                            */
#define UI_YEAR_INPUT_CATEGORY_TYPE3   3

    /* Type of Year input to use in the GUI               */
    /* Valid values are one of the above types               */
#define UI_YEAR_INPUT_CATEGORY_TYPE    UI_YEAR_INPUT_CATEGORY_TYPE1

    /* Use these flags to turn off Pluto EMS library support */
#define UI_DISABLE_EMS_INPUT_BOX       0
#define UI_DISABLE_EMS_CATEGORY_SCREENS      0

/* Config EMS view mode, 1: Scroll by page, 0: Scroll by line */
#define UI_EMS_VIEW_PAGE               1

/* Type of scrolling to use in text menuitems            */
/* Valid values are one of the above symbols          */
#if defined(CFG_UI_TEXT_MENUITEM_SCROLL_TYPE)
    #define UI_TEXT_MENUITEM_SCROLL_TYPE   CFG_UI_TEXT_MENUITEM_SCROLL_TYPE
#else 
    #error "Wrong option"
#endif

    /* Time for scrolling text in menu items              */
    /* Value must be an integer (milliseconds)               */
    /* Typical values: 100 to 500                      */
#if defined(CFG_UI_TEXT_MENUITEM_SCROLL_TIME)
    #define  UI_TEXT_MENUITEM_SCROLL_TIME  CFG_UI_TEXT_MENUITEM_SCROLL_TIME
#else 
    #error "Wrong option"
#endif

    /* Number of pixels by which the text scrolls            */
    /* in menu items.                               */
    /* Value must be an integer (units are in pixels)        */
    /* Typical values: 1 to 5                          */
#if defined(CFG_UI_TEXT_MENUITEM_SCROLL_SIZE)
    #define UI_TEXT_MENUITEM_SCROLL_SIZE   CFG_UI_TEXT_MENUITEM_SCROLL_SIZE
#else 
    #error "Wrong option"
#endif

    /* For Marquee type text scrolling in menu items, this      */
    /* specifies the blank gap that should appear at the end */
    /* of the string.                                  */
    /* Value must be an integer (units are in pixels)        */
    /* Typical values: 16 to 64 (This depends on font size)  */
#if defined(CFG_UI_TEXT_MENUITEM_SCROLL_GAP)
    #define UI_TEXT_MENUITEM_SCROLL_GAP    CFG_UI_TEXT_MENUITEM_SCROLL_GAP
#else 
    #error "Wrong option"
#endif

    /* This specifies the delay after which a highlighted item  */
    /* will scroll. This is a multiple of                 */
    /* UI_TEXT_MENUITEM_SCROLL_TIME                    */
    /* Value must be an integer. Typically 1, 2 -- etc.      */
    /* Depends on the value of UI_TEXT_MENUITEM_SCROLL_TIME  */
#if defined(CFG_UI_TEXT_MENUITEM_SCROLL_PAUSE)
    #define UI_TEXT_MENUITEM_SCROLL_PAUSE  CFG_UI_TEXT_MENUITEM_SCROLL_PAUSE
#else 
    #error "Wrong option"
#endif

/* gap from the menu X1 to menuitem X1 */
#if defined(CFG_UI_MENUITEM_X1_GAP)
    #define GUI_MENUITEM_X1_GAP CFG_UI_MENUITEM_X1_GAP
#else 
    #error "Wrong option"
#endif
/* gap from the menu X2 to menuitem X2 */
#if defined(CFG_UI_MENUITEM_X2_GAP)
    #define GUI_MENUITEM_X2_GAP CFG_UI_MENUITEM_X2_GAP
#else 
    #error "Wrong option"
#endif

/* text right gap for text, icontext, and two-state menuitems */
#if defined(CFG_UI_MENUITEM_TEXT_RIGHT_GAP)
    #define GUI_MENUITEM_TEXT_RIGHT_GAP CFG_UI_MENUITEM_TEXT_RIGHT_GAP
#else 
    #error "Wrong option"
#endif

/* menu item icon and text position */
#if defined(CFG_UI_TEXT_MENUITEM_TEXT_X)
    #define GUI_TEXT_MENUITEM_TEXT_X        CFG_UI_TEXT_MENUITEM_TEXT_X
#else
    #error "Wrong option"
#endif

#if defined(CFG_UI_ICONTEXT_MENUITEM_ICON_X)
    #define GUI_ICONTEXT_MENUITEM_ICON_X    CFG_UI_ICONTEXT_MENUITEM_ICON_X
#else
    #error "Wrong option"
#endif

#if defined(CFG_UI_ICONTEXT_MENUITEM_TEXT_X)
    #define GUI_ICONTEXT_MENUITEM_TEXT_X    CFG_UI_ICONTEXT_MENUITEM_TEXT_X
#else
    #error "Wrong option"
#endif

    /* Enable or disable pop up descriptions              */
    /* 0: Disables, 1: Enables                         */
#if defined(CFG_UI_ENABLE_POP_UP_DESCRIPTIONS) && (CFG_UI_ENABLE_POP_UP_DESCRIPTIONS == __ON__)
    #define UI_ENABLE_POP_UP_DESCRIPTIONS  1
#endif

    /* Type of scrolling to use in Pop up descriptions       */
    /* Valid values are one of the above symbols          */
#if defined(CFG_UI_POP_UP_DESCRIPTION_SCROLL_TYPE)
    #define UI_POP_UP_DESCRIPTION_SCROLL_TYPE CFG_UI_POP_UP_DESCRIPTION_SCROLL_TYPE
#else 
    #error "Wrong option"
#endif

    /* Enable or disable word-by-word text scrolling         */
    /* 0: Disables, 1: Enables                         */
#define UI_USE_WORD_SCROLLING_TEXT     0

#if 0
/* under construction !*/
/* under construction !*/
#if defined(MT6205B)
/* under construction !*/
#else 
/* under construction !*/
#endif 
#endif

#define ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING            1
#define ENABLE_LIST_MENU_FRAME_SKIPPING                  1
#define ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING        1
#define ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING         1
#define ENABLE_DIRECT_MAIN_MENU_FRAME_SKIPPING           1
#define ENABLE_INLINE_SINGLELINE_INPUTBOX_FRAME_SKIPPING 1

#if(!UI_DISABLE_EMS_INPUT_BOX)
    #define ENABLE_EMS_INPUTBOX_FRAME_SKIPPING               1
#endif 

#define UI_FRAME_SKIP_TIMEOUT                         150
#define UI_FRAME_START_TIMEOUT                        100
#define DIRECT_MAIN_MENU_FRAME_SKIP_RATE              UI_FRAME_SKIP_TIMEOUT

/* Deprecated option: always use GDI image decoder on MoDIS and target */
#define USE_PLUTO_GIF_LIBRARY    1

    /* Support for blinking cursors                    */
    /* 1: Enables blinking cursor, 0: disable             */

#define  UI_BLINKING_CURSOR_SUPPORT    1

/* cursor wait time*/
#if defined(CFG_UI_CURSOR_WAIT_TIME)
    #define UI_CURSOR_WAIT_TIME CFG_UI_CURSOR_WAIT_TIME
#else 
    #error "Wrong option"
#endif

/* cursor blink time */
#if defined(CFG_UI_CURSOR_BLINK_TIME)
    #define UI_CURSOR_BLINK_TIME CFG_UI_CURSOR_BLINK_TIME
#else 
    #error "Wrong option"
#endif

    /*  POPUP screen attribute  */
    // #define UI_POPUP_NOTIFYDURATION_TIME                 1000

    //Gurinder - 23/4/2004 - Information Bar Height Macro Defined.
    //Leo remove #define INFORMATION_BAR_HEIGHT                     12
    /* This macro is used for enabling the reuse of main menu shadow buffer. Make sure that 
       u check at all places if this is enabled for the buffer sizes being used. */
#define  __USE_MAIN_MENU_MATRIX_BUFFER 1

    /* Multi-layer configuration */
    /* sub menu */
#define UI_SUBMENU_OPACITY_BASED_LAYER 255
#define UI_SUBMENU_OPACITY_LAYER1 40
    /* Multilayer mask */
#define UI_MUL_BKG_MAINMENU      0x0001
#define UI_MUL_BKG_SUBMENU    0x0002
#define UI_MUL_ALL_ON            0xFFFF
#define UI_MUL_ALL_OFF           0x0000

#ifdef __MMI_LCD_PARTIAL_ON__

#if  defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__)
    /*
     * Height of the displayed region of  LCD partial on 
     * * This should be larger than font height and follow LCD partial display alignment
     * * 1. Dialer font has typical height 48
     */    
    #define UI_LCD_PARTIAL_ON_HEIGHT 64
#else
    /*
     * Height of the displayed region of  LCD partial on 
     * * This should be larger than font height and follow LCD partial display alignment
     * * 1. Dialer font has typical height 27
     * * 2. Most known LCM has partial display alignment < 4.
     */
    #define UI_LCD_PARTIAL_ON_HEIGHT 32
#endif /* __MMI_MAINLCD_320X480__ */
#endif /* __MMI_LCD_PARTIAL_ON__ */ 

#ifndef __MMI_MAIN_BASE_LAYER_FORMAT__
    #define __MMI_MAIN_BASE_LAYER_FORMAT__  GDI_COLOR_FORMAT_16
#endif

#ifndef __MMI_SUB_BASE_LAYER_FORMAT__
    #define __MMI_SUB_BASE_LAYER_FORMAT__   GDI_COLOR_FORMAT_16
#endif

#ifndef __MMI_DEVICE_BMP_FORMAT__
    #define __MMI_DEVICE_BMP_FORMAT__       16
#endif


/* 
 * the left gap from the slider button to the slider background image
 * This value depends on the background image style, e.g. round-rected or bordered.
 */
#if defined(CFG_UI_SLIDER_X1_GAP)
    #define UI_SLIDER_X1_GAP    CFG_UI_SLIDER_X1_GAP
#else 
    #error "Wrong option"
#endif

/* 
 * the right gap from the slider button to the slider background image
 * This value depends on the background image style, e.g. round-rected or bordered.
 */
#if defined(CFG_UI_SLIDER_X2_GAP)
    #define UI_SLIDER_X2_GAP    CFG_UI_SLIDER_X2_GAP
#else 
    #error "Wrong option"
#endif


#if defined(CFG_UI_SLIDE_CONTROL_FOCUS_GAP)
    #define GUI_SLIDE_CONTROL_FOCUS_GAP                 CFG_UI_SLIDE_CONTROL_FOCUS_GAP
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_SLIDE_CONTROL_TEXT_LABEL_TO_FOCUS_GAP)
    #define GUI_SLIDE_CONTROL_TEXT_LABEL_TO_FOCUS_GAP   CFG_UI_SLIDE_CONTROL_TEXT_LABEL_TO_FOCUS_GAP
#else 
    #error "Wrong option"
#endif

#if defined(__MMI_MAINLCD_128X64__)
#define GUI_SLIDE_CONTROL_TEXT_LABEL_TO_SLIDE_GAP   (2)

#else

#define GUI_SLIDE_CONTROL_TEXT_LABEL_TO_SLIDE_GAP   (GUI_SLIDE_CONTROL_TEXT_LABEL_TO_FOCUS_GAP + GUI_SLIDE_CONTROL_FOCUS_GAP)
#endif

#define GUI_SLIDE_CONTROL_TEXT_X_GAP                    (CFG_UI_SLIDE_TEXT_X_GAP)


/* shortcut */
#if defined(CFG_UI_SHORTCUT_WIDTH)
    #define GUI_SHORTCUT_WIDTH              CFG_UI_SHORTCUT_WIDTH          /* default wdith of shortcut */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_SHORTCUT_GAP)
    #define GUI_SHORTCUT_GAP                CFG_UI_SHORTCUT_GAP           /* default GAP of shortcut */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_SHORTCUT_TEXT_BORDER_X_GAP)
    #define GUI_SHORTCUT_TEXT_BORDER_X_GAP  CFG_UI_SHORTCUT_TEXT_BORDER_X_GAP           /* gap of border text */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_SHORTCUT_INSERT_GAP)
    #define GUI_SHORTCUT_INSERT_GAP         CFG_UI_SHORTCUT_INSERT_GAP           /* gap between normal mode and insert mode */     
#else 
    #error "Wrong option"
#endif




/* title */
#if defined(CFG_UI_TITLE_NON_ICON_GAP)
    #define GUI_TITLE_NON_ICON_GAP          CFG_UI_TITLE_NON_ICON_GAP           /* gap between text area and title area */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_TITLE_ICON_GAP)
    #define GUI_TITLE_ICON_GAP              CFG_UI_TITLE_ICON_GAP           /* gap between text area and icon area */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_TITLE_TEXT_GAP)
    #define GUI_TITLE_TEXT_GAP              CFG_UI_TITLE_TEXT_GAP           /* gap between text width and text area */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_TITLE_SCROLLING_GAP)
    #define GUI_TITLE_SCROLLING_GAP         CFG_UI_TITLE_SCROLLING_GAP           /* gap between scrolling area and title area */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_TITLE_SCROLLING_INIT_X)
    #define GUI_TITLE_SCROLLING_INIT_X      CFG_UI_TITLE_SCROLLING_INIT_X          /* init x of scrolling */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_TITLE_SCROLLING_INIT_Y)
    #define GUI_TITLE_SCROLLING_INIT_Y      CFG_UI_TITLE_SCROLLING_INIT_Y           /* init y of scrolling */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_TITLE_SCROLLING_INIT_WIDTH)
    #define GUI_TITLE_SCROLLING_INIT_WIDTH  CFG_UI_TITLE_SCROLLING_INIT_WIDTH           /* init width of scrolling */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_TITLE_SCROLLING_INIT_HEIGHT)
    #define GUI_TITLE_SCROLLING_INIT_HEIGHT CFG_UI_TITLE_SCROLLING_INIT_HEIGHT           /* init height of scrolling */
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_TITLE_SCROLLING_ICON_X)
    #define GUI_TITLE_SCROLLING_ICON_X      CFG_UI_TITLE_SCROLLING_ICON_X           /* left position of icon*/
#else 
    #error "Wrong option"
#endif


/* Editor config section */
#define EMS_DISPLAY_SPECIAL_CHARACTERS             0

#define GUI_INPUT_BOX_MAX_LENGTH 2048 /* characters. This value will control editor / font engine / IME / MMS contains */


#if 0
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) || defined(__MMI_MAINMENU_ROTATE_SUPPORT__)
/* under construction !*/
/* under construction !*/
#else /* defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) || defined(__MMI_MAINMENU_ROTATE_SUPPORT__) */
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) || defined(__MMI_MAINMENU_ROTATE_SUPPORT__) */
#endif//0

/* Setting this value to __ON__ will cause icons to be drawn from bottom baseline  */
/* Setting to 0 will cause icons to be drawn from center baseline          */
/* MTK added by JL for Joyce's request */
#if defined(CFG_UI_STATUS_ICONS_DRAW_FROM_BOTTOM_BASELINE) && (CFG_UI_STATUS_ICONS_DRAW_FROM_BOTTOM_BASELINE == __ON__) && (!defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__))
    #define STATUS_ICONS_DRAW_FROM_BOTTOM_BASELINE      1
#else
    #define STATUS_ICONS_DRAW_FROM_BOTTOM_BASELINE      0
#endif

/* define truncate suffix dots */
#define GUI_TEXT_TRUNCATE_SUFFIX         (L"...")
#define GUI_TEXT_TRUNCATE_SUFFIX_COUNT   3

#if 0
#ifndef LOW_COST_SUPPORT
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
/* under construction !*/
#if defined(__MMI_FTE_SUPPORT__)/* && defined(LOW_COST_SUPPORT)*/
/* under construction !*/
#endif
#endif

#ifndef __MMI_MAINLCD_96X64__ 
  #ifndef __MMI_IV_PLUTO_SLIM__
   #define __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
  #endif
#endif




#if 0
/* under construction !*/
#ifdef __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
/* under construction !*/
#endif
#endif//0

#ifdef __MMI_FWUI_SLIM__
  #if (!defined(__MMI_TOUCH_SCREEN__)) && (!defined(__MMI_FTE_SUPPORT__))
    #ifndef __MMI_UI_MENU_SLIM__
    #define __MMI_UI_MENU_SLIM__
    #endif
  #endif
#endif


//huking

#ifdef __MMI_UI_MENU_SLIM__
	#ifndef __MMI_UI_MENU_ENHANCEMENT_SLIM__
	#define __MMI_UI_MENU_ENHANCEMENT_SLIM__
	#endif/*__MMI_UI_MENU_ENHANCEMENT_SLIM__*/
#endif/*__MMI_UI_MENU_SLIM__*/

#ifdef __MMI_UI_MENU_SLIM__
	#undef __MMI_UI_TRANSPARENT_EFFECT__
#endif/*__MMI_UI_MENU_SLIM__*/


//__MMI_MENUITEM_DOTTED_UNDERLINE_SUPPORT__

#ifdef __MMI_UI_MENU_SLIM__
	#ifndef __MMI_UI_MENU_FORCE_LOOP__
	#define __MMI_UI_MENU_FORCE_LOOP__
	#endif/*__MMI_UI_MENU_FORCE_LOOP__*/
#endif/*__MMI_UI_MENU_SLIM__*/

#ifdef __MMI_UI_MENU_SLIM__
	#ifndef __MMI_UI_MENU_AUTO_DISABLE_SCROLLBAR__
	#define __MMI_UI_MENU_AUTO_DISABLE_SCROLLBAR__
	#endif/*__MMI_UI_MENU_FORCE_LOOP__*/
#endif/*__MMI_UI_MENU_SLIM__*/

#ifdef __MMI_MAINLCD_96X64__
	#ifndef __MMI_UI_PAGE_MAINMENU_SUPPORT__
	#define __MMI_UI_PAGE_MAINMENU_SUPPORT__
	#endif/*__MMI_UI_MATRIX_MAINMENU_SUPPORT__*/
#endif/*__MMI_MAINLCD_96X64__*/

#ifndef __MMI_UI_MENU_SLIM__
	#ifndef __MMI_HORIZONTAL_SCROLL_BAR_SUPPORT__
	#define __MMI_HORIZONTAL_SCROLL_BAR_SUPPORT__
    #endif/*__MMI_HORIZONTAL_SCROLL_BAR_SUPPORT__*/
#endif/*__MMI_UI_MENU_SLIM__*/

#if  defined(__MMI_FWUI_SLIM__)&&(!defined(__MMI_MAINLCD_96X64__))
  #ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
  #define __MMI_TITLE_BAR_NO_ICON_SHCT__
  #endif
#endif/*defined(__MMI_FWUI_SLIM__)&&(!defined(__MMI_MAINLCD_96X64__))*/


//end huking add

#if !defined(__ULC_SLIM_EMS__)
#define UI_EMS_SUPPORT
#endif

#ifdef __OP01_FWPBW__
/* always turn on the ems remaining counter otherwise the csk area can hold the ems remaining counter */
#define __MMI_MESSAGES_EMS_REMAINING_COUNTER__
#endif

#ifdef __OP01_FWPCOLOR__
// CMCC requirement
#define __MMI_MESSAGES_EMS_REMAINING_COUNTER__
#endif

// editor support extract keyword from text buffer

#if defined(__MMI_USSD_REPLY_IN_SAME_SCREEN__) 
#define GUI_INPUTS_KEYWORDS_SUPPORT        1
#endif

/* FTE SLIM Image only support 240X320. Ref CustResDefPLUTO.h */
#if defined(__32_32_SEG__) && defined(__MMI_MAINLCD_240X320__) && defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    #ifndef __MMI_CLNDR_FTE_SLIM_RES__
    #define __MMI_CLNDR_FTE_SLIM_RES__
    #endif
#endif

/*FTE SLIM Image*/
#if defined(__32_32_SEG__) && defined(__MMI_MAINLCD_240X320__) && defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#ifndef __DM_PROGRESS_BAR_9_SLICE_BG_IMAGE__
#define __DM_PROGRESS_BAR_9_SLICE_BG_IMAGE__
#endif
#endif


#ifndef __GDI_MEMORY_PROFILE_2__
#define __MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__
#endif /*__GDI_MEMORY_PROFILE_2__*/
#endif /* __GUI_CONFIG_H__ */ 


