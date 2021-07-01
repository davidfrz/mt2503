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
 * wgui_categories_ems.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for EMS category screens.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *********************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef __WGUI_CATEGORIES_EMS_H__
#define __WGUI_CATEGORIES_EMS_H__

//#ifndef UI_DISABLE_EMS_CATEGORY_SCREENS
//#define UI_DISABLE_EMS_CATEGORY_SCREENS 0
//#endif

//#if(!UI_DISABLE_EMS_CATEGORY_SCREENS)
    #include "MMIDataType.h"
    
    #include "gui_config.h"
/* <hExpand noExpand> DO NOT REMOVE THIS LINE */
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
    #include "wgui_categories.h"
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
/* </hExpand> DO NOT REMOVE THIS LINE */
    //#include "gui_ems.h"

//RHR
    #include "MMI_features.h"
    #include "ems.h"
    #include "kal_general_types.h"
    #include "gui_scrollbars.h"

#ifdef __MMI_WEARABLE_DEVICE__

#define __MMI_WEARABLE_DEVICE_LIST_INPUT__  //for PHB quick search input

#endif
#ifdef __MMI_MESSAGES_EMS__
    #define CAT_144_DATA_FILE_SIZE  1600


    extern void RedrawCategory143Screen(void);

    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        #define __MMI_CAT143_FTE__ 
    #endif
    
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <GROUP MISC>
 * FUNCTION
 *  ShowCategory143Screen
 * DESCRIPTION
 *  Displays the object list screen
 * 
 * <img name="wgui_cat143_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Icon displayed with the title
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon
 *   object_list                   : [IN ] (N/A) Array of items
 *   n_items                       : [IN ] (N/A) Number of items in the menu
 *   index                         : [IN ] (N/A) Default item to be highlighted (if there is no history)
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_143(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     EMSObject *object_list = NULL;
 *     EMSObject *object_list_1 = NULL;//061507 128x160 touch
 *     EMSObjData EMS_obj_data;
 *     S32 nItems = 0;
 *     S32 index = 0;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     EMS_obj_data.picture.bitsPerPixel = 1;
 *     EMS_obj_data.picture.hDim = 16;
 *     EMS_obj_data.picture.vDim = 16;
 *     EMS_obj_data.picture.pdu_length = 32;
 *     EMS_obj_data.picture.pdu = (U8*) (EMS_sample_picture_object_t + 8);
 * 
 *     object_list = (EMSObject*) gui_malloc(sizeof(EMSObject));
 *     object_list_1 = (EMSObject*) gui_malloc(sizeof(EMSObject));//061507 128x160 touch
 *     object_list->next = object_list_1;
 *     object_list->prev = NULL;
 *     object_list->data = &EMS_obj_data;
 *     object_list->OffsetToText = 0;
 *     object_list->PredefNo = 0;
 *     object_list->Type = EMS_TYPE_PIC;
 * 
 *     object_list_1->next = NULL;//061507 128x160 touch
 *     object_list_1->prev = object_list;
 *     object_list_1->data = &EMS_obj_data;
 *     object_list_1->OffsetToText = 0;
 *     object_list_1->PredefNo = 0;
 *     object_list_1->Type = EMS_TYPE_PIC;
 * 
 *     ShowCategory143Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         object_list,
 *         &nItems,
 *         &index,
 *         guiBuffer);
 * 
 *     SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
 *     SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
    extern void ShowCategory143Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    EMSObject *object_list,
                    S32 *n_items,
                    S32 *index,
                    U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  ExitCategory143Screen
 * DESCRIPTION
 *  Exits the object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void ExitCategory143Screen(void);


/*****************************************************************************
 * FUNCTION
 *  GetCategory143HistorySize
 * DESCRIPTION
 *  Gets the history buffer size for the object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
    extern S32 GetCategory143HistorySize(void);


/*****************************************************************************
 * FUNCTION
 *  GetCategory143History
 * DESCRIPTION
 *  Gets the history buffer for the object list screen
 * PARAMETERS
 *   history_buffer                : [IN ] (N/A) Is the buffer into which the history data is stored
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
    extern U8 *GetCategory143History(U8 *history_buffer);
/* DOM-NOT_FOR_SDK-BEGIN */


/*****************************************************************************
 * FUNCTION
 *  GetCategory143DataSize
 * DESCRIPTION
 *  get category 143 data size
 * PARAMETERS
 *  void
 * RETURNS
 *  size of 143 data
 *****************************************************************************/
    extern S32 GetCategory143DataSize(void);


/*****************************************************************************
 * FUNCTION
 *  GetCategory143DataType
 * DESCRIPTION
 *  get category 143 data type
 * PARAMETERS
 *  void
 * RETURNS
 *  data type of category 143
 *****************************************************************************/
    extern U8 *GetCategory143Data(U8 *data);


/*****************************************************************************
 * FUNCTION
 *  GetCategory143DataType
 * DESCRIPTION
 *  get category 143 data type
 * PARAMETERS
 *  void
 * RETURNS
 *  data type of category 143
 *****************************************************************************/
    extern U8 GetCategory143DataType(void);


/*****************************************************************************
 * FUNCTION
 *  GetEMSObjectPDUSize
 * DESCRIPTION
 *  get object PDU size
 * PARAMETERS
 *   data                          : [IN ] (N/A) data of obj
 *   size                          : [OUT] (N/A) size of obj 
 * RETURNS
 *  void
 *****************************************************************************/
    extern void GetEMSObjectPDUSize(U8 *data, S32 *size);


/*****************************************************************************
 * FUNCTION
 *  GetEMSPredefinedObjectPDUSize
 * DESCRIPTION
 *  get predefined object PDU size
 * PARAMETERS
 *   object_type                   : [IN ] (N/A) object type
 * RETURNS
 *  
 *****************************************************************************/
    extern S32 GetEMSPredefinedObjectPDUSize(U32 object_type);


/*****************************************************************************
 * FUNCTION
 *  InsertEMSObjectUIHeader
 * DESCRIPTION
 *  Insert object UI header
 * PARAMETERS
 *   object_type                   : [IN ] (N/A) object type
 *   object_size                   : [IN ] (N/A) object size
 *   source                        : [IN ] (N/A) object source data
 *   destination                   : [OUT] (N/A) object destination buffer
 * RETURNS
 *  void
 *****************************************************************************/
    extern void InsertEMSObjectUIHeader(U32 object_type, S32 object_size, U8 *source, U8 *destination);


/*****************************************************************************
 * FUNCTION
 *  RemoveEMSObjectUIHeader
 * DESCRIPTION
 *  remove object UI header
 * PARAMETERS
 *   object_type                   : [IN ] (N/A) object type
 *   source                        : [IN ] (N/A) object source data
 *   destination                   : [OUT] (N/A) object destination buffer
 * RETURNS
 *  void
 *****************************************************************************/
    extern void RemoveEMSObjectUIHeader(U32 object_type, U8 *source, U8 *destination);


/*****************************************************************************
 * FUNCTION
 *  CreateCategory143ObjectList
 * DESCRIPTION
 *  create 143 object list
 * PARAMETERS
 *   data                          : [IN ] (N/A) data of objects
 *   object_list                   : [OUT] (N/A) list of objects
 * RETURNS
 *  void
 *****************************************************************************/
    extern void CreateCategory143ObjectList(EMSData *data, EMSObject **object_list);


/*****************************************************************************
 * FUNCTION
 *  FreeCategory143ObjectList
 * DESCRIPTION
 *  free object list of category 143
 * PARAMETERS
 *   object_list                   : [IN ] (N/A) object list
 * RETURNS
 *  void
 *****************************************************************************/
    extern void FreeCategory143ObjectList(EMSObject **object_list);

/* DOM-NOT_FOR_SDK-BEGIN */
    extern void RedrawCategory144Screen(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * <GROUP MISC>
 * FUNCTION
 *  ShowCategory144Screen
 * DESCRIPTION
 *  Displays the object list screen
 * 
 * <img name="wgui_cat144_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Icon shown with the title
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   object_type                   : [IN ] (N/A) Object type
 *   n_items                       : [IN ] (N/A) itmes count
 *   object_titles                 : [IN ] (C144_1) String list of object title
 *   predefined_objects            : [IN ] (N/A) Predefined object file path
 *   is_short_name                 : [IN ] (N/A) Is short file name
 *   userdefined_objects           : [IN ] (N/A) User defined object list
 *   index                         : [IN ] (N/A) Index list
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_144(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     U16 Iconlist[2];//061507 128x160 touch
 *     U8 *itemlist[2];
 *     S32 currObjectHiliteIndex = 0;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     itemlist[0] = (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT);
 *     Iconlist[0] = IMG_GLOBAL_L1;//061507 128x160 touch
 *     itemlist[1] = (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT);
 *     Iconlist[1] = IMG_GLOBAL_L1;
 * 
 *     ShowCategory144Screen(
 *         (U8*) GetString(STR_ID_CSB_MENUITEM1_TEXT),
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         1,
 *         2,//061507 128x160 touch
 *         NULL,
 *         Iconlist,
 *         FALSE,
 *         NULL,
 *         (PS32) & currObjectHiliteIndex,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
    extern void ShowCategory144Screen(
                    U8 *title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U32 object_type,
                    S32 n_items,
                    U8 **object_titles,
                    U16 *predefined_objects,
                    MMI_BOOL is_short_name,
                    U8 **userdefined_objects,
                    S32 *index,
                    U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  ExitCategory144Screen
 * DESCRIPTION
 *  Exits the object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void ExitCategory144Screen(void);


/*****************************************************************************
 * FUNCTION
 *  GetCategory144HistorySize
 * DESCRIPTION
 *  Gets the history buffer size for the object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
    extern S32 GetCategory144HistorySize(void);


/*****************************************************************************
 * FUNCTION
 *  GetCategory144History
 * DESCRIPTION
 *  Gets the history buffer for the object list screen
 * PARAMETERS
 *   history_buffer                : [IN ] (N/A) Is the buffer into which the history data is stored
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
    extern U8 *GetCategory144History(U8 *history_buffer);
    void RegisterCategory144ObjectLoader(U8 *(*f) (S32 index));
#endif /* __MMI_MESSAGES_EMS__ */



/*****************************************************************************
 * FUNCTION
 *  EMSObjectStopPlayBack
 * DESCRIPTION
 *  stop object play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void EMSObjectStopPlayBack(void);


/*****************************************************************************
 * FUNCTION
 *  EMSObjectPlayback
 * DESCRIPTION
 *  start object play
 * PARAMETERS
 *   object_type                   : [IN ] (N/A) Object type
 *   data                          : [IN ] (N/A) Object data
 *   index                         : [IN ] (N/A) Object index
 * RETURNS
 *  EMSTATUS EMS function status
 *****************************************************************************/
    extern EMSTATUS EMSObjectPlayback(U32 object_type, U8 *data, S32 index);

    /* Call before EMSPack  */
    extern void EMS_ConvertAsciiEncodingToGSM7BitDefault(EMSData *data);
    extern void EMS_ConvertAsciiEncodingToGSM7BitDefaultWithExtended(EMSData *data);

    /* Call after EMSUnpack */
    extern void EMS_ConvertGSM7BitDefaultEncodingToAscii(EMSData *data);
    extern void EMS_ConvertGSM7BitDefaultEncodingToAsciiWithExtended(EMSData *data);

    extern MMI_BOOL is_EMS_inputbox_in_view_mode(void);
#define CAT145_BLACK_TITLE 0x00000000
#define CAT145_BLUE_TITLE  0x00000001
#define CAT145_RED_TITLE   0x00000002
#define CAT145_GREEN_TITLE 0x00000003



/*****************************************************************************
 * FUNCTION
 *  RedrawCategory145Screen
 * DESCRIPTION
 *  Redraws the Delivery report screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void RedrawCategory145Screen(void);
/* DOM-NOT_FOR_SDK-END */

#ifdef __MMI_BT_DIALER_SUPPORT__

extern void set_cat145_show_number(U8* buffer);

extern void set_cat145_show_number_finish(void);

extern void set_cat145_show_image_finish(void);

extern void set_cat145_show_image_file_path(U8* image_path);

extern void set_cat145_show_image_file_data(U8* image_data,U8 image_type,S32 image_size);

extern void set_cat145_show_image_data_finish(void);
extern void ShowBTNotiCategory145Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 message_icon,
        U8 *message_title,
        U8 *message,
        U32 flags,
        U8 *history_buffer);

#endif

#if defined( __MMI_WEARABLE_DEVICE__)&&defined(__MMI_TOUCH_SCREEN__)//MMI_WEARABLE_TOUCH_EDITOR_SCREEN  
#define __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__
//#define __BT145_SUPPORT_LIST_BUTTONS_WITH_MULTILINE_EDITOR__
typedef struct
{
    U8  status; // 0 : up ; 1:down
    S32 x;
    S32 y;
    S32 w; //for show image
    S32 h; //for show image
    S32 w_pen_gap; //for check pen event
    S32 h_pen_gap; //for check pen event
    U16 normal_up_icon;
    U16 normal_down_icon;      
    UI_string_type label;
    
} wgui_BT145_footer_button_struct;
typedef void(*wgui_BT145_footer_button_handler) (void);

#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__



typedef enum {
    MMI_BT145_PAGE_MODE_APP_NAME_AND_CONTENT_TEXT_AND_NO_BUTTON, 
    MMI_BT145_PAGE_MODE_ONLY_CONTENT_TEXT,
    MMI_BT145_PAGE_MODE_ONLY_BUTTON,
    MMI_BT145_PAGE_MODE_ERROR,
} BT145_page_mode_type;



typedef struct
{   
    BT145_page_mode_type mode_type;
    U8 page_count;
    U8 current_page_index;
    MMI_BOOL is_page_mode;
    
} wgui_BT145_page_mode_struct;

  #define BT145_MAX_PAGE 4
  #define BT145_ERROR_PAGE (BT145_MAX_PAGE + 1)

//define button count
  #define FOOTER_BUTTTON_MAX 16  // in page mode need support more buttons
#else
//define button count
  #define FOOTER_BUTTTON_MAX 2
#endif

#define FOOTER_BUTTTON_ERROR_COUNT (FOOTER_BUTTTON_MAX+1)

//for show button  
//#if 1// defined (__MMI_MAINLCD_240X240__)
#ifdef __MMI_MAINLCD_240X240__

    // head area----------------------
    #define BT145_HEAD_FONT_SIZE (20)

    #define BT145_HEAD_ICON_SIZE (40)

    #define BT145_HEAD_TOP_MARGIN (10)
    #define BT145_HEAD_LEFT_MARGIN (10) 
    #define BT145_HEAD_RIGHT_MARGIN (10) 
    #define BT145_HEAD_LEFT_GAP_APP_NAME_AND_ICON (5) 
    #define BT145_HEAD_GAP_TITLE_AND_ICON (15)

    #define BT145_HEAD_ICON_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_ICON_Y (BT145_HEAD_TOP_MARGIN)

    #define BT145_HEAD_APP_NAME_X (BT145_HEAD_LEFT_MARGIN+BT145_HEAD_ICON_SIZE+BT145_HEAD_LEFT_GAP_APP_NAME_AND_ICON)  
    #define BT145_HEAD_APP_NAME_Y (BT145_HEAD_TOP_MARGIN)
    #define BT145_HEAD_APP_NAME_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_APP_NAME_X - BT145_HEAD_RIGHT_MARGIN - 1 )

    #define BT145_HEAD_TIME_X (BT145_HEAD_APP_NAME_X)  
    #define BT145_HEAD_TIME_Y (BT145_HEAD_APP_NAME_Y + BT145_HEAD_FONT_SIZE + 6)  
    #define BT145_HEAD_TIME_MAX_LENGTH (BT145_HEAD_APP_NAME_MAX_LENGTH)

    #define BT145_HEAD_TITLE_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_TITLE_Y (BT145_HEAD_ICON_Y + BT145_HEAD_ICON_SIZE+BT145_HEAD_GAP_TITLE_AND_ICON)  
    #define BT145_HEAD_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_TITLE_X - BT145_HEAD_RIGHT_MARGIN -1)


    #define G_145_BT_HEAD_HIGHT (BT145_HEAD_TITLE_Y+BT145_HEAD_FONT_SIZE)
      //message app head info
    #define BT145_HEAD_MESSAGE_APP_ICON_SIZE (20)  

    #define BT145_HEAD_MESSAGE_APP_NAME_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_MESSAGE_APP_NAME_Y (BT145_HEAD_TOP_MARGIN)
    #define BT145_HEAD_MESSAGE_APP_NAME_MAX_LENTH (LCD_WIDTH - BT145_HEAD_LEFT_MARGIN - BT145_HEAD_RIGHT_MARGIN -1)

    #define BT145_HEAD_MESSAGE_APP_ICON_X (LCD_WIDTH - BT145_HEAD_RIGHT_MARGIN - (BT145_HEAD_MESSAGE_APP_ICON_SIZE*2))  
    #define BT145_HEAD_MESSAGE_APP_ICON_Y (BT145_HEAD_MESSAGE_APP_NAME_Y + BT145_HEAD_MESSAGE_APP_ICON_SIZE +6)  


    #define BT145_HEAD_MESSAGE_APP_TIME_X (BT145_HEAD_MESSAGE_APP_NAME_X)  
    #define BT145_HEAD_MESSAGE_APP_TIME_Y (BT145_HEAD_MESSAGE_APP_ICON_Y + 6)  
    #define BT145_HEAD_MESSAGE_APP_TIME_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_LEFT_MARGIN-(LCD_WIDTH - BT145_HEAD_MESSAGE_APP_ICON_X))
    #define G_145_BT_HEAD_MESSAGE_APP_HIGHT (BT145_HEAD_MESSAGE_APP_TIME_Y + BT145_HEAD_FONT_SIZE)

    // foot area-----------------------    
    #define BT145_FOOT_TOP_MARGIN (10) 
#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__

    #define BT145_FOOTER_ICON_SIZE (200)    
    #define BT145_FOOTER_ICON_X (20)  
    #define BT145_FOOTER_ICON_Y (BT145_FOOT_TOP_MARGIN)

    #define BT145_FOOTER_BX_W  (LCD_WIDTH)
    #define BT145_FOOTER_BX_H  (MMI_SW_BUTTON_BAR_HEIGHT)//(40)
    
    #define BT145_FOOTER_BX_X (0)
    #define BT145_FOOTER_BX_Y (BT145_FOOT_TOP_MARGIN )    



    #define BT145_PAGE_INDICATOR_W (LCD_WIDTH)
    #define BT145_PAGE_INDICATOR_H (21)
    #define BT145_PAGE_INDICATOR_X (0)  
    #define BT145_PAGE_INDICATOR_Y (LCD_HEIGHT - BT145_PAGE_INDICATOR_H-1)   

    #define BT145_PAGE_INDICATOR_ICON_W  (5)
    #define BT145_PAGE_INDICATOR_ICON_H  (5)


    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_X  (110)
    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y  (227)
    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_X_GAP    (9)

    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_START_X  (103)
    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_START_Y  BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y   
    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_X_GAP    (9)

    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_START_X  (96)
    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_START_Y  BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y
    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_X_GAP    (9)

    
    #define BT145_PAGE_INDICATOR_Y (LCD_HEIGHT - BT145_PAGE_INDICATOR_H-1)   


    
#endif
    // for 2 button style
    #define BT145_FOOTER_B0_W  (120) 
    #define BT145_FOOTER_B0_H  (MMI_SW_BUTTON_BAR_HEIGHT)      
    #define BT145_FOOTER_B1_W  (BT145_FOOTER_B0_W)
    #define BT145_FOOTER_B1_H  (BT145_FOOTER_B0_H)

    #define BT145_FOOTER_B0_X (0)
    #define BT145_FOOTER_B0_Y (BT145_FOOT_TOP_MARGIN)
    #define BT145_FOOTER_B1_X (BT145_FOOTER_B0_X+BT145_FOOTER_B0_W)
    #define BT145_FOOTER_B1_Y (BT145_FOOTER_B0_Y)


    // for 1 button style
    #define BT145_FOOTER_B2_W  (LCD_WIDTH)
    #define BT145_FOOTER_B2_H  (MMI_SW_BUTTON_BAR_HEIGHT)
    
    #define BT145_FOOTER_B2_X (0)
    #define BT145_FOOTER_B2_Y (BT145_FOOTER_B0_Y)    

    #define BT145_W_GAP  (0)  //for check pen event 
    #define BT145_H_GAP  (0)  //for check pen event   

    #define  G_145_BT_FOOT_HIGHT (BT145_FOOT_TOP_MARGIN +BT145_FOOTER_B0_H)
#elif defined (__MMI_MAINLCD_240X320__)
    // head area----------------------
    #define BT145_HEAD_FONT_SIZE (20)

    #define BT145_HEAD_ICON_SIZE (40)

    #define BT145_HEAD_TOP_MARGIN (10)
    #define BT145_HEAD_LEFT_MARGIN (10) 
    #define BT145_HEAD_RIGHT_MARGIN (10) 
    #define BT145_HEAD_LEFT_GAP_APP_NAME_AND_ICON (5) 
    #define BT145_HEAD_GAP_TITLE_AND_ICON (15)

    #define BT145_HEAD_ICON_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_ICON_Y (BT145_HEAD_TOP_MARGIN)

    #define BT145_HEAD_APP_NAME_X (BT145_HEAD_LEFT_MARGIN+BT145_HEAD_ICON_SIZE+BT145_HEAD_LEFT_GAP_APP_NAME_AND_ICON)  
    #define BT145_HEAD_APP_NAME_Y (BT145_HEAD_TOP_MARGIN)
    #define BT145_HEAD_APP_NAME_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_APP_NAME_X - BT145_HEAD_RIGHT_MARGIN - 1 )

    #define BT145_HEAD_TIME_X (BT145_HEAD_APP_NAME_X)  
    #define BT145_HEAD_TIME_Y (BT145_HEAD_APP_NAME_Y + BT145_HEAD_FONT_SIZE + 6)  
    #define BT145_HEAD_TIME_MAX_LENGTH (BT145_HEAD_APP_NAME_MAX_LENGTH)

    #define BT145_HEAD_TITLE_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_TITLE_Y (BT145_HEAD_ICON_Y + BT145_HEAD_ICON_SIZE+BT145_HEAD_GAP_TITLE_AND_ICON)  
    #define BT145_HEAD_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_TITLE_X - BT145_HEAD_RIGHT_MARGIN -1)


    #define G_145_BT_HEAD_HIGHT (BT145_HEAD_TITLE_Y+BT145_HEAD_FONT_SIZE)
      //message app head info
    #define BT145_HEAD_MESSAGE_APP_ICON_SIZE (20)  

    #define BT145_HEAD_MESSAGE_APP_NAME_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_MESSAGE_APP_NAME_Y (BT145_HEAD_TOP_MARGIN)
    #define BT145_HEAD_MESSAGE_APP_NAME_MAX_LENTH (LCD_WIDTH - BT145_HEAD_LEFT_MARGIN - BT145_HEAD_RIGHT_MARGIN -1)

    #define BT145_HEAD_MESSAGE_APP_ICON_X (LCD_WIDTH - BT145_HEAD_RIGHT_MARGIN - (BT145_HEAD_MESSAGE_APP_ICON_SIZE*2))  
    #define BT145_HEAD_MESSAGE_APP_ICON_Y (BT145_HEAD_MESSAGE_APP_NAME_Y + BT145_HEAD_MESSAGE_APP_ICON_SIZE +6)  


    #define BT145_HEAD_MESSAGE_APP_TIME_X (BT145_HEAD_MESSAGE_APP_NAME_X)  
    #define BT145_HEAD_MESSAGE_APP_TIME_Y (BT145_HEAD_MESSAGE_APP_ICON_Y + 6)  
    #define BT145_HEAD_MESSAGE_APP_TIME_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_LEFT_MARGIN-(LCD_WIDTH - BT145_HEAD_MESSAGE_APP_ICON_X))
    #define G_145_BT_HEAD_MESSAGE_APP_HIGHT (BT145_HEAD_MESSAGE_APP_TIME_Y + BT145_HEAD_FONT_SIZE)

    // foot area-----------------------    
    #define BT145_FOOT_TOP_MARGIN (10) 
#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__

    #define BT145_FOOTER_ICON_SIZE (200)    
    #define BT145_FOOTER_ICON_X (20)  
    #define BT145_FOOTER_ICON_Y (BT145_FOOT_TOP_MARGIN)

    #define BT145_FOOTER_BX_W  (LCD_WIDTH)
    #define BT145_FOOTER_BX_H  (MMI_SW_BUTTON_BAR_HEIGHT)//(40)
    
    #define BT145_FOOTER_BX_X (0)
    #define BT145_FOOTER_BX_Y (BT145_FOOT_TOP_MARGIN )    



    #define BT145_PAGE_INDICATOR_W (LCD_WIDTH)
    #define BT145_PAGE_INDICATOR_H (21)
    #define BT145_PAGE_INDICATOR_X (0)  
    #define BT145_PAGE_INDICATOR_Y (LCD_HEIGHT - BT145_PAGE_INDICATOR_H-1)   

    #define BT145_PAGE_INDICATOR_ICON_W  (5)
    #define BT145_PAGE_INDICATOR_ICON_H  (5)


    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_X  (110)
    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y  (227+80)
    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_X_GAP    (9)

    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_START_X  (103)
    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_START_Y  BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y   
    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_X_GAP    (9)

    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_START_X  (96)
    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_START_Y  BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y
    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_X_GAP    (9)

    
    #define BT145_PAGE_INDICATOR_Y (LCD_HEIGHT - BT145_PAGE_INDICATOR_H-1)   


    
#endif
    // for 2 button style
    #define BT145_FOOTER_B0_W  (120) 
    #define BT145_FOOTER_B0_H  (MMI_SW_BUTTON_BAR_HEIGHT)      
    #define BT145_FOOTER_B1_W  (BT145_FOOTER_B0_W)
    #define BT145_FOOTER_B1_H  (BT145_FOOTER_B0_H)

    #define BT145_FOOTER_B0_X (0)
    #define BT145_FOOTER_B0_Y (BT145_FOOT_TOP_MARGIN)
    #define BT145_FOOTER_B1_X (BT145_FOOTER_B0_X+BT145_FOOTER_B0_W)
    #define BT145_FOOTER_B1_Y (BT145_FOOTER_B0_Y)


    // for 1 button style
    #define BT145_FOOTER_B2_W  (LCD_WIDTH)
    #define BT145_FOOTER_B2_H  (MMI_SW_BUTTON_BAR_HEIGHT)
    
    #define BT145_FOOTER_B2_X (0)
    #define BT145_FOOTER_B2_Y (BT145_FOOTER_B0_Y)    

    #define BT145_W_GAP  (0)  //for check pen event 
    #define BT145_H_GAP  (0)  //for check pen event   

    #define  G_145_BT_FOOT_HIGHT (BT145_FOOT_TOP_MARGIN +BT145_FOOTER_B0_H)

#elif defined (__MMI_MAINLCD_320X320__)
			// head area----------------------

    #define BT145_HEAD_FONT_SIZE (20)

    #define BT145_HEAD_ICON_SIZE (40)

    #define BT145_HEAD_TOP_MARGIN (10)
    #define BT145_HEAD_LEFT_MARGIN (10) 
    #define BT145_HEAD_RIGHT_MARGIN (10) 
    #define BT145_HEAD_LEFT_GAP_APP_NAME_AND_ICON (5) 
    #define BT145_HEAD_GAP_TITLE_AND_ICON (15)

    #define BT145_HEAD_ICON_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_ICON_Y (BT145_HEAD_TOP_MARGIN)

    #define BT145_HEAD_APP_NAME_X (BT145_HEAD_LEFT_MARGIN+BT145_HEAD_ICON_SIZE+BT145_HEAD_LEFT_GAP_APP_NAME_AND_ICON)  
    #define BT145_HEAD_APP_NAME_Y (BT145_HEAD_TOP_MARGIN)
    #define BT145_HEAD_APP_NAME_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_APP_NAME_X - BT145_HEAD_RIGHT_MARGIN - 1 )

    #define BT145_HEAD_TIME_X (BT145_HEAD_APP_NAME_X)  
    #define BT145_HEAD_TIME_Y (BT145_HEAD_APP_NAME_Y + BT145_HEAD_FONT_SIZE + 6)  
    #define BT145_HEAD_TIME_MAX_LENGTH (BT145_HEAD_APP_NAME_MAX_LENGTH)

    #define BT145_HEAD_TITLE_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_TITLE_Y (BT145_HEAD_ICON_Y + BT145_HEAD_ICON_SIZE+BT145_HEAD_GAP_TITLE_AND_ICON)  
    #define BT145_HEAD_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_TITLE_X - BT145_HEAD_RIGHT_MARGIN -1)


    #define G_145_BT_HEAD_HIGHT (BT145_HEAD_TITLE_Y+BT145_HEAD_FONT_SIZE)
      //message app head info
    #define BT145_HEAD_MESSAGE_APP_ICON_SIZE (20)  

    #define BT145_HEAD_MESSAGE_APP_NAME_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_MESSAGE_APP_NAME_Y (BT145_HEAD_TOP_MARGIN)
    #define BT145_HEAD_MESSAGE_APP_NAME_MAX_LENTH (LCD_WIDTH - BT145_HEAD_LEFT_MARGIN - BT145_HEAD_RIGHT_MARGIN -1)

    #define BT145_HEAD_MESSAGE_APP_ICON_X (LCD_WIDTH - BT145_HEAD_RIGHT_MARGIN - (BT145_HEAD_MESSAGE_APP_ICON_SIZE*2))  
    #define BT145_HEAD_MESSAGE_APP_ICON_Y (BT145_HEAD_MESSAGE_APP_NAME_Y + BT145_HEAD_MESSAGE_APP_ICON_SIZE +6)  


    #define BT145_HEAD_MESSAGE_APP_TIME_X (BT145_HEAD_MESSAGE_APP_NAME_X)  
    #define BT145_HEAD_MESSAGE_APP_TIME_Y (BT145_HEAD_MESSAGE_APP_ICON_Y + 6)  
    #define BT145_HEAD_MESSAGE_APP_TIME_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_LEFT_MARGIN-(LCD_WIDTH - BT145_HEAD_MESSAGE_APP_ICON_X))
    #define G_145_BT_HEAD_MESSAGE_APP_HIGHT (BT145_HEAD_MESSAGE_APP_TIME_Y + BT145_HEAD_FONT_SIZE)

    // foot area-----------------------    
    #define BT145_FOOT_TOP_MARGIN (10) 
#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__

    #define BT145_FOOTER_ICON_SIZE (200)    
    #define BT145_FOOTER_ICON_X (20)  
    #define BT145_FOOTER_ICON_Y (BT145_FOOT_TOP_MARGIN)

    #define BT145_FOOTER_BX_W  (LCD_WIDTH)
    #define BT145_FOOTER_BX_H  (MMI_SW_BUTTON_BAR_HEIGHT)//(40)
    
    #define BT145_FOOTER_BX_X (0)
    #define BT145_FOOTER_BX_Y (BT145_FOOT_TOP_MARGIN )    



    #define BT145_PAGE_INDICATOR_W (LCD_WIDTH)
    #define BT145_PAGE_INDICATOR_H (21)
    #define BT145_PAGE_INDICATOR_X (0)  
    #define BT145_PAGE_INDICATOR_Y (LCD_HEIGHT - BT145_PAGE_INDICATOR_H-1)   

    #define BT145_PAGE_INDICATOR_ICON_W  (5)
    #define BT145_PAGE_INDICATOR_ICON_H  (5)


    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_X  (110+40)
    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y  (227+80)
    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_X_GAP    (9)

    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_START_X  (103+40)
    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_START_Y  BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y   
    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_X_GAP    (9)

    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_START_X  (96+40)
    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_START_Y  BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y
    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_X_GAP    (9)

    
    #define BT145_PAGE_INDICATOR_Y (LCD_HEIGHT - BT145_PAGE_INDICATOR_H-1)   


    
#endif
    // for 2 button style
    #define BT145_FOOTER_B0_W  (160) 
    #define BT145_FOOTER_B0_H  (MMI_SW_BUTTON_BAR_HEIGHT)      
    #define BT145_FOOTER_B1_W  (BT145_FOOTER_B0_W)
    #define BT145_FOOTER_B1_H  (BT145_FOOTER_B0_H)

    #define BT145_FOOTER_B0_X (0)
    #define BT145_FOOTER_B0_Y (BT145_FOOT_TOP_MARGIN)
    #define BT145_FOOTER_B1_X (BT145_FOOTER_B0_X+BT145_FOOTER_B0_W)
    #define BT145_FOOTER_B1_Y (BT145_FOOTER_B0_Y)


    // for 1 button style
    #define BT145_FOOTER_B2_W  (LCD_WIDTH)
    #define BT145_FOOTER_B2_H  (MMI_SW_BUTTON_BAR_HEIGHT)
    
    #define BT145_FOOTER_B2_X (0)
    #define BT145_FOOTER_B2_Y (BT145_FOOTER_B0_Y)    

    #define BT145_W_GAP  (0)  //for check pen event 
    #define BT145_H_GAP  (0)  //for check pen event   

    #define  G_145_BT_FOOT_HIGHT (BT145_FOOT_TOP_MARGIN +BT145_FOOTER_B0_H)


#else   /*__MMI_MAINLCD_240X240__*/


    // head area----------------------
    #define BT145_HEAD_FONT_SIZE (20)

    #define BT145_HEAD_ICON_SIZE (40)

    #define BT145_HEAD_TOP_MARGIN (10)
    #define BT145_HEAD_LEFT_MARGIN (10) 
    #define BT145_HEAD_RIGHT_MARGIN (10) 
    #define BT145_HEAD_LEFT_GAP_APP_NAME_AND_ICON (5) 
    #define BT145_HEAD_GAP_TITLE_AND_ICON (15)

    #define BT145_HEAD_ICON_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_ICON_Y (BT145_HEAD_TOP_MARGIN)

    #define BT145_HEAD_APP_NAME_X (BT145_HEAD_LEFT_MARGIN+BT145_HEAD_ICON_SIZE+BT145_HEAD_LEFT_GAP_APP_NAME_AND_ICON)  
    #define BT145_HEAD_APP_NAME_Y (BT145_HEAD_TOP_MARGIN)
    #define BT145_HEAD_APP_NAME_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_APP_NAME_X - BT145_HEAD_RIGHT_MARGIN - 1 )

    #define BT145_HEAD_TIME_X (BT145_HEAD_APP_NAME_X)  
    #define BT145_HEAD_TIME_Y (BT145_HEAD_APP_NAME_Y + BT145_HEAD_FONT_SIZE + 6)  
    #define BT145_HEAD_TIME_MAX_LENGTH (BT145_HEAD_APP_NAME_MAX_LENGTH)

    #define BT145_HEAD_TITLE_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_TITLE_Y (BT145_HEAD_ICON_Y + BT145_HEAD_ICON_SIZE+BT145_HEAD_GAP_TITLE_AND_ICON)  
    #define BT145_HEAD_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_TITLE_X - BT145_HEAD_RIGHT_MARGIN -1)


    #define G_145_BT_HEAD_HIGHT (BT145_HEAD_TITLE_Y+BT145_HEAD_FONT_SIZE)
      //message app head info
    #define BT145_HEAD_MESSAGE_APP_ICON_SIZE (20)  

    #define BT145_HEAD_MESSAGE_APP_NAME_X (BT145_HEAD_LEFT_MARGIN)  
    #define BT145_HEAD_MESSAGE_APP_NAME_Y (BT145_HEAD_TOP_MARGIN)
    #define BT145_HEAD_MESSAGE_APP_NAME_MAX_LENTH (LCD_WIDTH - BT145_HEAD_LEFT_MARGIN - BT145_HEAD_RIGHT_MARGIN -1)

    #define BT145_HEAD_MESSAGE_APP_ICON_X (LCD_WIDTH - BT145_HEAD_RIGHT_MARGIN - (BT145_HEAD_MESSAGE_APP_ICON_SIZE*2))  
    #define BT145_HEAD_MESSAGE_APP_ICON_Y (BT145_HEAD_MESSAGE_APP_NAME_Y + BT145_HEAD_MESSAGE_APP_ICON_SIZE +6)  


    #define BT145_HEAD_MESSAGE_APP_TIME_X (BT145_HEAD_MESSAGE_APP_NAME_X)  
    #define BT145_HEAD_MESSAGE_APP_TIME_Y (BT145_HEAD_MESSAGE_APP_ICON_Y + 6)  
    #define BT145_HEAD_MESSAGE_APP_TIME_MAX_LENGTH (LCD_WIDTH - BT145_HEAD_LEFT_MARGIN-(LCD_WIDTH - BT145_HEAD_MESSAGE_APP_ICON_X))
    #define G_145_BT_HEAD_MESSAGE_APP_HIGHT (BT145_HEAD_MESSAGE_APP_TIME_Y + BT145_HEAD_FONT_SIZE)

    // foot area-----------------------    
    #define BT145_FOOT_TOP_MARGIN (10) 
#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__

    #define BT145_FOOTER_ICON_SIZE (200)    
    #define BT145_FOOTER_ICON_X (20)  
    #define BT145_FOOTER_ICON_Y (BT145_FOOT_TOP_MARGIN)

    #define BT145_FOOTER_BX_W  (LCD_WIDTH)
    #define BT145_FOOTER_BX_H  (MMI_SW_BUTTON_BAR_HEIGHT)//(40)
    
    #define BT145_FOOTER_BX_X (0)
    #define BT145_FOOTER_BX_Y (BT145_FOOT_TOP_MARGIN )    



    #define BT145_PAGE_INDICATOR_W (LCD_WIDTH)
    #define BT145_PAGE_INDICATOR_H (21)
    #define BT145_PAGE_INDICATOR_X (0)  
    #define BT145_PAGE_INDICATOR_Y (LCD_HEIGHT - BT145_PAGE_INDICATOR_H-1)   

    #define BT145_PAGE_INDICATOR_ICON_W  (5)
    #define BT145_PAGE_INDICATOR_ICON_H  (5)


    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_X  (110)
    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y  (227)
    #define BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_X_GAP    (9)

    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_START_X  (103)
    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_START_Y  BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y   
    #define BT145_PAGE_INDICATOR_ICON_FOR_3_PAGE_X_GAP    (9)

    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_START_X  (96)
    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_START_Y  BT145_PAGE_INDICATOR_ICON_FOR_2_PAGE_START_Y
    #define BT145_PAGE_INDICATOR_ICON_FOR_4_PAGE_X_GAP    (9)

    
    #define BT145_PAGE_INDICATOR_Y (LCD_HEIGHT - BT145_PAGE_INDICATOR_H-1)   


    
#endif
    // for 2 button style
    #define BT145_FOOTER_B0_W  (120) 
    #define BT145_FOOTER_B0_H  (MMI_SW_BUTTON_BAR_HEIGHT)      
    #define BT145_FOOTER_B1_W  (BT145_FOOTER_B0_W)
    #define BT145_FOOTER_B1_H  (BT145_FOOTER_B0_H)

    #define BT145_FOOTER_B0_X (0)
    #define BT145_FOOTER_B0_Y (BT145_FOOT_TOP_MARGIN)
    #define BT145_FOOTER_B1_X (BT145_FOOTER_B0_X+BT145_FOOTER_B0_W)
    #define BT145_FOOTER_B1_Y (BT145_FOOTER_B0_Y)


    // for 1 button style
    #define BT145_FOOTER_B2_W  (LCD_WIDTH)
    #define BT145_FOOTER_B2_H  (MMI_SW_BUTTON_BAR_HEIGHT)
    
    #define BT145_FOOTER_B2_X (0)
    #define BT145_FOOTER_B2_Y (BT145_FOOTER_B0_Y)    

    #define BT145_W_GAP  (0)  //for check pen event 
    #define BT145_H_GAP  (0)  //for check pen event   

    #define  G_145_BT_FOOT_HIGHT (BT145_FOOT_TOP_MARGIN +BT145_FOOTER_B0_H)

#endif /*__MMI_MAINLCD_240X240__*/

#ifdef __BT145_FOOTER_SUPPORT_BUTTONS_AND_PAGE__

extern void wgui_BTcat145_set_page_mode_sse_no_change_footer(MMI_BOOL set_flag);
/*****************************************************************************
 * FUNCTION
 *  set_cat145_page_mode_data
 * DESCRIPTION
 *  set  page count and cuttent page id  
 * PARAMETERS
 *  page_count    [IN]  page count
 *  current_page_index  [IN]  current page index , value start from 0 
 *  mode_type     [IN]  current page mode  
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_BTcat145_set_page_mode_data(U8 page_count ,U8 current_page_index,BT145_page_mode_type mode_type);

/*****************************************************************************
 * FUNCTION
 *  set_cat145_footer_area_show_button_count
 * DESCRIPTION
 *  set button count 
 * PARAMETERS
 *   
 *  button_count  [IN] button count
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_BTcat145_set_footer_area_show_button_count(U8 button_count);


/*****************************************************************************
 * FUNCTION
 *  wgui_BTcat145_footer_area_show_button_lable
 * DESCRIPTION
 *  set button lable by button index 
 * PARAMETERS
 *  label         [IN] button label  
 *  button_index  [IN] button index  
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_BTcat145_set_footer_area_show_button_lable(UI_string_type label,U8 button_index);
/*****************************************************************************
 * FUNCTION
 *  wgui_BTcat145_show_page_indicator
 * DESCRIPTION
 *  show page indicator
 * PARAMETERS
 *  page_count         [IN] page count  
 *  current_page_index [IN] page index  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_BTcat145_show_page_indicator(U8 page_count ,U8 current_page_index);

#endif

extern void wgui_BTcat145_footer_area_register_controlled_callback(void (*handler) (void),U8 button_index);

extern void wgui_BTcat145_footer_area_set_disable_button(MMI_BOOL button_flag);
extern void wgui_BTcat145_footer_area_set_no_show_button(MMI_BOOL button_flag);

extern void ShowBTNotiCategory145Screen_WEARABLE_DEVICE(
            U8 *title,
            U16 title_icon,
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            U16 message_icon,
            U8 *message_title,
            U8 *message,
            U32 flags,
            U8 *history_buffer,
            U8 *time);

#endif /*__MMI_WEARABLE_DEVICE__*/

#ifdef __BT145_SUPPORT_LIST_BUTTONS_WITH_MULTILINE_EDITOR__


#define LIST_ITEM_BUTTTON_MAX 20
#define LIST_ITEM_FOOTER_BUTTTON_MAX 10
#define LIST_ITEM_HEADER_BUTTTON_MAX 1
#define BT145_LIST_ITEM_HEAD_ONE_LINE_MIX_BUTTON  1
#define LIST_ITEM_HEAD_BUTTTON_ERROR_INDEX LIST_ITEM_BUTTTON_MAX



typedef struct
{
    U8  status; // 0 : up ; 1:down
    S32 x;
    S32 y;
    S32 w; //for show image
    S32 h; //for show image
    S32 w_pen_gap; //for check pen event
    S32 h_pen_gap; //for check pen event    
    
} wgui_BT145_list_item_head_button_struct;


typedef enum {
    MMI_BT145_LIST_ITEM_STSTUS_SHORT_MODE, 
    MMI_BT145_LIST_ITEM_STSTUS_DETAIL_MODE,
    MMI_BT145_LIST_ITEM_STSTUS_MAIX
} BT145_list_item_status;



typedef struct
{
    U8 index;
    U8 *title;
    U16 message_icon;
    U8 *message_title;
    U8 *message;
    U32 flags;
    U8 *time;
    U8  footer_buttons ;
    U8  footer_area_highlight_button;
    U8  header_buttons ;
    U8  header_area_highlight_button;    
    U8* header_area_show_image_path ;
    PU8 header_area_show_image_data ;
    UI_string_type  header_button_lable[LIST_ITEM_HEADER_BUTTTON_MAX];
    UI_string_type  footer_button_lable[LIST_ITEM_FOOTER_BUTTTON_MAX];     
    S32 header_height;
    S32 header_short_mode_height;
    S32 footer_height;
    S32 editor_height;
    S32 header_area_start_y ;
    S32 footer_area_start_y ;
    wgui_BT145_footer_button_struct  header_area_button [LIST_ITEM_HEADER_BUTTTON_MAX];
    wgui_BT145_footer_button_struct  footer_area_button [LIST_ITEM_FOOTER_BUTTTON_MAX];
    wgui_BT145_footer_button_handler footer_area_button_handler[LIST_ITEM_FOOTER_BUTTTON_MAX]; 
    wgui_BT145_footer_button_handler header_area_button_handler[LIST_ITEM_HEADER_BUTTTON_MAX];
    //U32 flags;
} show_btnoti_category145screen_item;


typedef void(*wgui_BT145_list_item_head_button_handler) (S32 index);






//#if 1// defined (__MMI_MAINLCD_240X240__)
#ifdef __MMI_MAINLCD_240X240__
#define BT145_LIST_ITEM_HEAD_H_LINE_PIX 1  //horizontal line width
#define BT145_LIST_ITEM_HEAD_GAP  0

#define BT145_LIST_ITEM_FOOT_TOP_MARGIN (10) 


#define BT145_LIST_ITEM_W_GAP  (0)  //for check pen event 
#define BT145_LIST_ITEM_H_GAP  (0)  //for check pen event 

// head area----------------------
#define BT145_LIST_ITEM_HEAD_FONT_SIZE (20)

#define BT145_LIST_ITEM_HEAD_ICON_SIZE (40)

#define BT145_LIST_ITEM_HEAD_TOP_MARGIN (10)
#define BT145_LIST_ITEM_HEAD_LEFT_MARGIN (10) 
#define BT145_LIST_ITEM_HEAD_RIGHT_MARGIN (10) 
#define BT145_LIST_ITEM_HEAD_LEFT_GAP_APP_NAME_AND_ICON (5) 
#define BT145_LIST_ITEM_HEAD_GAP_TITLE_AND_ICON (15)

#define BT145_LIST_ITEM_HEAD_ICON_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN)  
#define BT145_LIST_ITEM_HEAD_ICON_Y (BT145_LIST_ITEM_HEAD_TOP_MARGIN)

#define BT145_LIST_ITEM_HEAD_APP_NAME_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN+BT145_LIST_ITEM_HEAD_ICON_SIZE+BT145_LIST_ITEM_HEAD_LEFT_GAP_APP_NAME_AND_ICON)  
#define BT145_LIST_ITEM_HEAD_APP_NAME_Y (BT145_LIST_ITEM_HEAD_TOP_MARGIN)
#define BT145_LIST_ITEM_HEAD_APP_NAME_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_APP_NAME_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN - 1 )

#define BT145_LIST_ITEM_HEAD_TIME_X (BT145_LIST_ITEM_HEAD_APP_NAME_X)  
#define BT145_LIST_ITEM_HEAD_TIME_Y (BT145_LIST_ITEM_HEAD_APP_NAME_Y + BT145_LIST_ITEM_HEAD_FONT_SIZE + 6)  
#define BT145_LIST_ITEM_HEAD_TIME_MAX_LENGTH (BT145_LIST_ITEM_HEAD_APP_NAME_MAX_LENGTH)

#define BT145_LIST_ITEM_HEAD_TITLE_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN)  
#define BT145_LIST_ITEM_HEAD_TITLE_Y (BT145_LIST_ITEM_HEAD_ICON_Y + BT145_LIST_ITEM_HEAD_ICON_SIZE+BT145_LIST_ITEM_HEAD_GAP_TITLE_AND_ICON)  
#define BT145_LIST_ITEM_HEAD_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_TITLE_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN -1)

#define BT145_LIST_ITEM_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_TITLE_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN -1)

#define G_145_LIST_ITEM__HEAD_HIGHT (BT145_LIST_ITEM_HEAD_TITLE_Y+BT145_LIST_ITEM_HEAD_FONT_SIZE)


//footer area

//#define BT145_LIST_ITEM_FOOTER_ICON_SIZE (200)    
//#define BT145_LIST_ITEM_FOOTER_ICON_X (20)  
//#define BT145_LIST_ITEM_FOOTER_ICON_Y (BT145_LIST_ITEM_FOOT_TOP_MARGIN)

#define BT145_LIST_ITEM_FOOTER_BX_W  (LCD_WIDTH)
#define BT145_LIST_ITEM_FOOTER_BX_H  (40)

#define BT145_LIST_ITEM_FOOTER_BX_X (0)
#define BT145_LIST_ITEM_FOOTER_BX_Y (BT145_LIST_ITEM_FOOT_TOP_MARGIN ) 

#elif defined (__MMI_MAINLCD_240X320__)

    #define BT145_LIST_ITEM_HEAD_H_LINE_PIX 1  //horizontal line width
    #define BT145_LIST_ITEM_HEAD_GAP  0

    #define BT145_LIST_ITEM_FOOT_TOP_MARGIN (10) 


    #define BT145_LIST_ITEM_W_GAP  (0)  //for check pen event 
    #define BT145_LIST_ITEM_H_GAP  (0)  //for check pen event 

    // head area----------------------
    #define BT145_LIST_ITEM_HEAD_FONT_SIZE (20)

    #define BT145_LIST_ITEM_HEAD_ICON_SIZE (40)

    #define BT145_LIST_ITEM_HEAD_TOP_MARGIN (10)
    #define BT145_LIST_ITEM_HEAD_LEFT_MARGIN (10) 
    #define BT145_LIST_ITEM_HEAD_RIGHT_MARGIN (10) 
    #define BT145_LIST_ITEM_HEAD_LEFT_GAP_APP_NAME_AND_ICON (5) 
    #define BT145_LIST_ITEM_HEAD_GAP_TITLE_AND_ICON (15)

    #define BT145_LIST_ITEM_HEAD_ICON_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN)  
    #define BT145_LIST_ITEM_HEAD_ICON_Y (BT145_LIST_ITEM_HEAD_TOP_MARGIN)

    #define BT145_LIST_ITEM_HEAD_APP_NAME_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN+BT145_LIST_ITEM_HEAD_ICON_SIZE+BT145_LIST_ITEM_HEAD_LEFT_GAP_APP_NAME_AND_ICON)  
    #define BT145_LIST_ITEM_HEAD_APP_NAME_Y (BT145_LIST_ITEM_HEAD_TOP_MARGIN)
    #define BT145_LIST_ITEM_HEAD_APP_NAME_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_APP_NAME_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN - 1 )

    #define BT145_LIST_ITEM_HEAD_TIME_X (BT145_LIST_ITEM_HEAD_APP_NAME_X)  
    #define BT145_LIST_ITEM_HEAD_TIME_Y (BT145_LIST_ITEM_HEAD_APP_NAME_Y + BT145_LIST_ITEM_HEAD_FONT_SIZE + 6)  
    #define BT145_LIST_ITEM_HEAD_TIME_MAX_LENGTH (BT145_LIST_ITEM_HEAD_APP_NAME_MAX_LENGTH)

    #define BT145_LIST_ITEM_HEAD_TITLE_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN)  
    #define BT145_LIST_ITEM_HEAD_TITLE_Y (BT145_LIST_ITEM_HEAD_ICON_Y + BT145_LIST_ITEM_HEAD_ICON_SIZE+BT145_LIST_ITEM_HEAD_GAP_TITLE_AND_ICON)  
    #define BT145_LIST_ITEM_HEAD_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_TITLE_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN -1)

    #define BT145_LIST_ITEM_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_TITLE_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN -1)

    #define G_145_LIST_ITEM__HEAD_HIGHT (BT145_LIST_ITEM_HEAD_TITLE_Y+BT145_LIST_ITEM_HEAD_FONT_SIZE)


    //footer area

    //#define BT145_LIST_ITEM_FOOTER_ICON_SIZE (200)    
    //#define BT145_LIST_ITEM_FOOTER_ICON_X (20)  
    //#define BT145_LIST_ITEM_FOOTER_ICON_Y (BT145_LIST_ITEM_FOOT_TOP_MARGIN)

    #define BT145_LIST_ITEM_FOOTER_BX_W  (LCD_WIDTH)
    #define BT145_LIST_ITEM_FOOTER_BX_H  (40)

    #define BT145_LIST_ITEM_FOOTER_BX_X (0)
    #define BT145_LIST_ITEM_FOOTER_BX_Y (BT145_LIST_ITEM_FOOT_TOP_MARGIN ) 

#elif defined (__MMI_MAINLCD_320X320__)
    #define BT145_LIST_ITEM_HEAD_H_LINE_PIX 1  //horizontal line width
    #define BT145_LIST_ITEM_HEAD_GAP  0

    #define BT145_LIST_ITEM_FOOT_TOP_MARGIN (10) 


    #define BT145_LIST_ITEM_W_GAP  (0)  //for check pen event 
    #define BT145_LIST_ITEM_H_GAP  (0)  //for check pen event 

    // head area----------------------
    #define BT145_LIST_ITEM_HEAD_FONT_SIZE (20)

    #define BT145_LIST_ITEM_HEAD_ICON_SIZE (40)

    #define BT145_LIST_ITEM_HEAD_TOP_MARGIN (10)
    #define BT145_LIST_ITEM_HEAD_LEFT_MARGIN (10) 
    #define BT145_LIST_ITEM_HEAD_RIGHT_MARGIN (10) 
    #define BT145_LIST_ITEM_HEAD_LEFT_GAP_APP_NAME_AND_ICON (5) 
    #define BT145_LIST_ITEM_HEAD_GAP_TITLE_AND_ICON (15)

    #define BT145_LIST_ITEM_HEAD_ICON_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN)  
    #define BT145_LIST_ITEM_HEAD_ICON_Y (BT145_LIST_ITEM_HEAD_TOP_MARGIN)

    #define BT145_LIST_ITEM_HEAD_APP_NAME_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN+BT145_LIST_ITEM_HEAD_ICON_SIZE+BT145_LIST_ITEM_HEAD_LEFT_GAP_APP_NAME_AND_ICON)  
    #define BT145_LIST_ITEM_HEAD_APP_NAME_Y (BT145_LIST_ITEM_HEAD_TOP_MARGIN)
    #define BT145_LIST_ITEM_HEAD_APP_NAME_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_APP_NAME_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN - 1 )

    #define BT145_LIST_ITEM_HEAD_TIME_X (BT145_LIST_ITEM_HEAD_APP_NAME_X)  
    #define BT145_LIST_ITEM_HEAD_TIME_Y (BT145_LIST_ITEM_HEAD_APP_NAME_Y + BT145_LIST_ITEM_HEAD_FONT_SIZE + 6)  
    #define BT145_LIST_ITEM_HEAD_TIME_MAX_LENGTH (BT145_LIST_ITEM_HEAD_APP_NAME_MAX_LENGTH)

    #define BT145_LIST_ITEM_HEAD_TITLE_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN)  
    #define BT145_LIST_ITEM_HEAD_TITLE_Y (BT145_LIST_ITEM_HEAD_ICON_Y + BT145_LIST_ITEM_HEAD_ICON_SIZE+BT145_LIST_ITEM_HEAD_GAP_TITLE_AND_ICON)  
    #define BT145_LIST_ITEM_HEAD_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_TITLE_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN -1)

    #define BT145_LIST_ITEM_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_TITLE_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN -1)

    #define G_145_LIST_ITEM__HEAD_HIGHT (BT145_LIST_ITEM_HEAD_TITLE_Y+BT145_LIST_ITEM_HEAD_FONT_SIZE)


    //footer area

    //#define BT145_LIST_ITEM_FOOTER_ICON_SIZE (200)    
    //#define BT145_LIST_ITEM_FOOTER_ICON_X (20)  
    //#define BT145_LIST_ITEM_FOOTER_ICON_Y (BT145_LIST_ITEM_FOOT_TOP_MARGIN)

    #define BT145_LIST_ITEM_FOOTER_BX_W  (LCD_WIDTH)
    #define BT145_LIST_ITEM_FOOTER_BX_H  (40)

    #define BT145_LIST_ITEM_FOOTER_BX_X (0)
    #define BT145_LIST_ITEM_FOOTER_BX_Y (BT145_LIST_ITEM_FOOT_TOP_MARGIN )  


#else /*__MMI_MAINLCD_240X240__*/

    #define BT145_LIST_ITEM_HEAD_H_LINE_PIX 1  //horizontal line width
    #define BT145_LIST_ITEM_HEAD_GAP  0

    #define BT145_LIST_ITEM_FOOT_TOP_MARGIN (10) 


    #define BT145_LIST_ITEM_W_GAP  (0)  //for check pen event 
    #define BT145_LIST_ITEM_H_GAP  (0)  //for check pen event 

    // head area----------------------
    #define BT145_LIST_ITEM_HEAD_FONT_SIZE (20)

    #define BT145_LIST_ITEM_HEAD_ICON_SIZE (40)

    #define BT145_LIST_ITEM_HEAD_TOP_MARGIN (10)
    #define BT145_LIST_ITEM_HEAD_LEFT_MARGIN (10) 
    #define BT145_LIST_ITEM_HEAD_RIGHT_MARGIN (10) 
    #define BT145_LIST_ITEM_HEAD_LEFT_GAP_APP_NAME_AND_ICON (5) 
    #define BT145_LIST_ITEM_HEAD_GAP_TITLE_AND_ICON (15)

    #define BT145_LIST_ITEM_HEAD_ICON_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN)  
    #define BT145_LIST_ITEM_HEAD_ICON_Y (BT145_LIST_ITEM_HEAD_TOP_MARGIN)

    #define BT145_LIST_ITEM_HEAD_APP_NAME_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN+BT145_LIST_ITEM_HEAD_ICON_SIZE+BT145_LIST_ITEM_HEAD_LEFT_GAP_APP_NAME_AND_ICON)  
    #define BT145_LIST_ITEM_HEAD_APP_NAME_Y (BT145_LIST_ITEM_HEAD_TOP_MARGIN)
    #define BT145_LIST_ITEM_HEAD_APP_NAME_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_APP_NAME_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN - 1 )

    #define BT145_LIST_ITEM_HEAD_TIME_X (BT145_LIST_ITEM_HEAD_APP_NAME_X)  
    #define BT145_LIST_ITEM_HEAD_TIME_Y (BT145_LIST_ITEM_HEAD_APP_NAME_Y + BT145_LIST_ITEM_HEAD_FONT_SIZE + 6)  
    #define BT145_LIST_ITEM_HEAD_TIME_MAX_LENGTH (BT145_LIST_ITEM_HEAD_APP_NAME_MAX_LENGTH)

    #define BT145_LIST_ITEM_HEAD_TITLE_X (BT145_LIST_ITEM_HEAD_LEFT_MARGIN)  
    #define BT145_LIST_ITEM_HEAD_TITLE_Y (BT145_LIST_ITEM_HEAD_ICON_Y + BT145_LIST_ITEM_HEAD_ICON_SIZE+BT145_LIST_ITEM_HEAD_GAP_TITLE_AND_ICON)  
    #define BT145_LIST_ITEM_HEAD_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_TITLE_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN -1)

    #define BT145_LIST_ITEM_TITLE_MAX_LENGTH (LCD_WIDTH - BT145_LIST_ITEM_HEAD_TITLE_X - BT145_LIST_ITEM_HEAD_RIGHT_MARGIN -1)

    #define G_145_LIST_ITEM__HEAD_HIGHT (BT145_LIST_ITEM_HEAD_TITLE_Y+BT145_LIST_ITEM_HEAD_FONT_SIZE)


    //footer area

    //#define BT145_LIST_ITEM_FOOTER_ICON_SIZE (200)    
    //#define BT145_LIST_ITEM_FOOTER_ICON_X (20)  
    //#define BT145_LIST_ITEM_FOOTER_ICON_Y (BT145_LIST_ITEM_FOOT_TOP_MARGIN)

    #define BT145_LIST_ITEM_FOOTER_BX_W  (LCD_WIDTH)
    #define BT145_LIST_ITEM_FOOTER_BX_H  (40)

    #define BT145_LIST_ITEM_FOOTER_BX_X (0)
    #define BT145_LIST_ITEM_FOOTER_BX_Y (BT145_LIST_ITEM_FOOT_TOP_MARGIN )   

#endif


extern void wgui_BTcat145_list_item_data_ini(show_btnoti_category145screen_item * item_p,
    U8* header_image_path,
    PU8 header_image_data,   
    U8 *title,
    U8 *message_title,
    U8 *message,
    U8 *time,
    U8 footer_area_buttons,
    U8 header_area_buttons,
    U32 flags);


extern  show_btnoti_category145screen_item  *wgui_BTcat145_list_item_get_data_item( U8 index);


extern void ShowBTNotiCategory145Screen_list_item_WEARABLE_DEVICE(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 message_icon,
        U8 *message_title,
        U8 *message,
        U32 flags,
        U8 *history_buffer,
        U8 *time,
        U16 item_count);


extern void wgui_BTcat145_list_item_data_footer_area_set_button_handler(show_btnoti_category145screen_item * item_p,void (*handler) (void),U8 button_index);

extern void wgui_BTcat145_list_item_data_footer_area_set_button_lable(show_btnoti_category145screen_item * item_p,UI_string_type label,U8 button_index);

extern void wgui_BTcat145_list_item_data_header_area_set_button_lable_in_short_mode(show_btnoti_category145screen_item * item_p,UI_string_type label,U8 button_index);

extern void wgui_BTcat145_list_item_data_header_area_set_button_handler_in_short_mode(show_btnoti_category145screen_item * item_p,void (*handler) (void),U8 button_index);



#endif /*__BT145_SUPPORT_LIST_BUTTONS_WITH_MULTILINE_EDITOR__*/



#ifdef __MMI_WEARABLE_DEVICE_LIST_INPUT__
//////////
typedef struct
{
    U8  status; // 0 : up ; 1:down
    S32 x;
    S32 y;
    S32 w; //for show image
    S32 h; //for show image
    S32 w_pen_gap; //for check pen event
    S32 h_pen_gap; //for check pen event    
    UI_string_type label;
    
} wgui_BT145_list_input_head_button_struct;

typedef void(*wgui_BT145_list_input_head_button_handler) (S32 index);

//define button count
  #define LIST_INPUT_HEAD_BUTTTON_MAX 27 

  #define LIST_INPUT_HEAD_BUTTTON_ERROR_INDEX LIST_INPUT_HEAD_BUTTTON_MAX
//for show button  
#ifdef __MMI_MAINLCD_240X240__

    // head area----------------------
    #define BT145_LIST_INPUT_HEAD_GAP  0

    #define BT145_LIST_INPUT_HEAD_ONE_LINE_MIX_BUTTON 3

    #define BT145_LIST_INPUT_HEAD_H_LINE_PIX 1  //horizontal line width

   
    #define BT145_LIST_INPUT_HEAD_V_LINE_PIX 1  //vertical line width
    
    // for 2 button style
    #define BT145_LIST_INPUT_HEAD_B0_W  (79)  //button W 
    #define BT145_LIST_INPUT_HEAD_B0_H  (60)  //button H    
    #define BT145_LIST_INPUT_HEAD_B1_W  (80)  //button W
    #define BT145_LIST_INPUT_HEAD_B1_H  (BT145_LIST_INPUT_HEAD_B0_H)  //button H
#elif defined (__MMI_MAINLCD_240X320__)
    // head area----------------------
    #define BT145_LIST_INPUT_HEAD_GAP  0

    #define BT145_LIST_INPUT_HEAD_ONE_LINE_MIX_BUTTON 3

    #define BT145_LIST_INPUT_HEAD_H_LINE_PIX 1	//horizontal line width


    #define BT145_LIST_INPUT_HEAD_V_LINE_PIX 1	//vertical line width

    // for 2 button style
    #define BT145_LIST_INPUT_HEAD_B0_W	(79)  //button W 
    #define BT145_LIST_INPUT_HEAD_B0_H	(60)  //button H	
    #define BT145_LIST_INPUT_HEAD_B1_W	(80)  //button W
    #define BT145_LIST_INPUT_HEAD_B1_H	(BT145_LIST_INPUT_HEAD_B0_H)  //button H

#elif defined (__MMI_MAINLCD_320X320__)

  // head area----------------------
  #define BT145_LIST_INPUT_HEAD_GAP  0

  #define BT145_LIST_INPUT_HEAD_ONE_LINE_MIX_BUTTON 3

  #define BT145_LIST_INPUT_HEAD_H_LINE_PIX 1  //horizontal line width

  #define BT145_LIST_INPUT_HEAD_V_LINE_PIX 1  //vertical line width
  
  // for 2 button style
  #define BT145_LIST_INPUT_HEAD_B0_W  (79+27)	//button W 
  #define BT145_LIST_INPUT_HEAD_B0_H  (60+20)	//button H	  
  #define BT145_LIST_INPUT_HEAD_B1_W  (80+27)	//button W
  #define BT145_LIST_INPUT_HEAD_B1_H  (BT145_LIST_INPUT_HEAD_B0_H)	//button H

//	#define BT_145_LIST_INPUT_BT_HEAD_HIGHT ((LIST_INPUT_HEAD_BUTTTON_MAX/BT145_LIST_INPUT_HEAD_ONE_LINE_MIX_BUTTON)*(BT145_LIST_INPUT_HEAD_B0_H+1))
#else /*__MMI_MAINLCD_240X240__*/

    // head area----------------------
    #define BT145_LIST_INPUT_HEAD_GAP  0

    #define BT145_LIST_INPUT_HEAD_ONE_LINE_MIX_BUTTON 3

    #define BT145_LIST_INPUT_HEAD_H_LINE_PIX 1  //horizontal line width

    #define BT145_LIST_INPUT_HEAD_V_LINE_PIX 1  //vertical line width
    
    // for 2 button style
    #define BT145_LIST_INPUT_HEAD_B0_W  (79)  //button W 
    #define BT145_LIST_INPUT_HEAD_B0_H  (60)  //button H    
    #define BT145_LIST_INPUT_HEAD_B1_W  (80)  //button W
    #define BT145_LIST_INPUT_HEAD_B1_H  (BT145_LIST_INPUT_HEAD_B0_H)  //button H
  //  #define BT_145_LIST_INPUT_BT_HEAD_HIGHT ((LIST_INPUT_HEAD_BUTTTON_MAX/BT145_LIST_INPUT_HEAD_ONE_LINE_MIX_BUTTON)*(BT145_LIST_INPUT_HEAD_B0_H+1))
    
#endif
extern void wgui_BTcat145_list_input_head_area_register_controlled_callback(void (*handler)(S32 index));

extern void ShowBTNotiCategory145Screen_list_input_WEARABLE_DEVICE(
            U8 *title,
            U16 title_icon,
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            U8 **list_item,
            U16 item_count,
            U8 *history_buffer
            );
 
#endif /*__MMI_WEARABLE_DEVICE_LIST_INPUT__*/
/*****************************************************************************
 * <GROUP MISC>
 * FUNCTION
 *  ShowCategory145Screen
 * DESCRIPTION
 *  Displays the Delivery report screen
 * 
 * <img name="wgui_cat145_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Icon displayed with the title
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon
 *   message_icon                  : [IN ] (N/A) Icon displayed with the message
 *   message_title                 : [IN ] (C145_1) Colored text that appears above the message
 *   message                       : [IN ] (UNLIM) Message
 *   flags                         : [IN ] (N/A) Flags
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_145(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category145");
 *     mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "Message");
 * 
 *     ShowCategory145Screen(
 *         ((U8*) GetString(STR_ID_CSB_CATEGORY_TEXT)),
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         IMG_GLOBAL_L1,
 *         (U8*) g_buffer,
 *         g_buffer1,
 *         0,
 *         guiBuffer);
 *     
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
    extern void ShowCategory145Screen(
                    U8 *title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 message_icon,
                    U8 *message_title,
                    U8 *message,
                    U32 flags,
                    U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  ExitCategory145Screen
 * DESCRIPTION
 *  Exits the Delivery report screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void ExitCategory145Screen(void);

#ifdef __MMI_SMALL_IMAGE_SELECTOR_SCREEN__
#define UI_SMALL_IMAGE_SELECTOR_SHOW_VERTICAL_SCROLLBAR     0x00000001
#define UI_SMALL_IMAGE_SELECTOR_SHOW_HORIZONTAL_SCROLLBAR   0x00000002
#define MAX_IMAGE_SELECTOR_COL (6)
#define MAX_IMAGE_SELECTOR_ROW (4)
    extern void gui_enable_small_image_selector(void);
    extern void gui_disable_small_image_selector(void);
    extern BOOL gui_is_small_image_selector_set(void);
    extern void gui_enable_fixed_list_line_draw(void);


/*****************************************************************************
 * FUNCTION
 *  redraw_small_image_selector_images
 * DESCRIPTION
 *  redraw function for the small image selector screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void redraw_small_image_selector_images(void);


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_goto_previous_row
 * DESCRIPTION
 *  Calculates the previous row
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void small_image_selector_goto_previous_row(void);


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_goto_next_row
 * DESCRIPTION
 *  Calculates the next row
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void small_image_selector_goto_next_row(void);


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_compute_row_col
 * DESCRIPTION
 *  Calculates the row and column number of the image in the list
 * PARAMETERS
 *   index                         : [IN ] (N/A) index to calculates
 *   row                           : [OUT] (N/A) row of index
 *   col                           : [OUT] (N/A) col of index
 * RETURNS
 *  void
 *****************************************************************************/
    extern void small_image_selector_compute_row_col(S32 index, S32 *row, S32 *col);


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_compute_next_row_image_index
 * DESCRIPTION
 *  Calculates the actual index of the image in the list
 * PARAMETERS
 *   index                         : [IN ] (N/A) index of next row
 * RETURNS
 *  S32
 *****************************************************************************/
    extern S32 small_image_selector_compute_next_row_image_index(S32 index);


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_compute_previous_row_image_index
 * DESCRIPTION
 *  Calculates the actual index of the image in the list
 * PARAMETERS
 *   index                         : [IN ] (N/A) index of previous row
 * RETURNS
 *  S32
 *****************************************************************************/
    extern S32 small_image_selector_compute_previous_row_image_index(S32 index);


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_key_handler
 * DESCRIPTION
 *  Executes the function depending upon the key pressed
 * PARAMETERS
 *   vkey_code                     : [IN ] (N/A) virtual key code
 *   key_state                     : [IN ] (N/A) key state
 * RETURNS
 *  void
 *****************************************************************************/
    extern void small_image_selector_key_handler(S32 vkey_code, S32 key_state);


/*****************************************************************************
 * FUNCTION
 *  ExitSmallImageSelectorScreen
 * DESCRIPTION
 *  Exit the small image selector screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void ExitSmallImageSelectorScreen(void);


/*****************************************************************************
 * FUNCTION
 *  RedrawSmallImageSelectorScreen
 * DESCRIPTION
 *  Redraws the image selector screen for the small screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void RedrawSmallImageSelectorScreen(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * <GROUP MISC>
 * FUNCTION
 *  ShowImageSelectorScreen
 * DESCRIPTION
 *  Show image selector screen
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Icon shown with the title
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   object_type                   : [IN ] (N/A) Object type
 *   n_items                       : [IN ] (N/A) itmes count
 *   object_titles                 : [IN ] (TITLE) String list of object title
 *   predefined_objects            : [IN ] (N/A) Predefined object file path
 *   userdefined_objects           : [IN ] (N/A) User defined object list
 *   index                         : [IN ] (N/A) Index list
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 *****************************************************************************/
    extern void ShowImageSelectorScreen(
                    S8 *title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U32 object_type,
                    S32 n_items,
                    U8 **object_titles,
                    U16 *predefined_objects,
                    U8 **userdefined_objects,
                    S32 *index,
                    U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
    typedef struct _small_image_selector
    {
        S32 x, y;
        S32 width, height;
        S32 n_columns;
        S32 n_rows;
        S32 n_images;
        S32 first_displayed_column;
        S32 first_displayed_row;
        S32 first_displayed_image;
        S32 displayed_columns;
        S32 displayed_rows;
        S32 highlighted_column;
        S32 highlighted_row;
        S32 highlighted_image;
        S32 image_width;
        S32 image_height;
        vertical_scrollbar vbar;
        horizontal_scrollbar hbar;
        U32 flags;
        S32 h_gap;
        S32 v_gap;
    } small_image_selector_struct;
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_configure_current_display
 * DESCRIPTION
 *  function used to configure the current items to be displayed on the small screen
 *  calculates the first item to be displayed
 * PARAMETERS
 *   s                             : [IN ] (N/A) Small image sleector structure
 *   new_highlighted_image         : [IN ] (N/A) New highlighted image
 * RETURNS
 *  void
 *****************************************************************************/
    extern void small_image_selector_configure_current_display(
                    small_image_selector_struct *s,
                    S32 new_highlighted_image);


/*****************************************************************************
 * FUNCTION
 *  associate_small_image_selector
 * DESCRIPTION
 *  function used to initialize the small image selector structure
 * PARAMETERS
 *   s                             : [IN ] (N/A) Small image sleector structure
 * RETURNS
 *  void
 *****************************************************************************/
    extern void associate_small_image_selector(small_image_selector_struct *s);


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_auto_calculate
 * DESCRIPTION
 *  Function used to auto calculate the no. of rows and columns depending upon the display area.
 * PARAMETERS
 *   s                             : [IN ] (N/A) Small image sleector structure
 * RETURNS
 *  void
 *****************************************************************************/
    extern void small_image_selector_auto_calculate(small_image_selector_struct *s);


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_auto_configure
 * DESCRIPTION
 *  Function used to auto configure the no. of rows and columns to be displayed depending upon the display area.
 * PARAMETERS
 *   s                             : [IN ] (N/A) Small image sleector structure
 * RETURNS
 *  void
 *****************************************************************************/
    extern void small_image_selector_auto_configure(small_image_selector_struct *s);


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_set_up
 * DESCRIPTION
 *  set up function for small image selector
 * PARAMETERS
 *   s                             : [IN ] (N/A) Small image sleector structure
 *   n_images                      : [IN ] (N/A) Total no. of images
 * RETURNS
 *  void
 *****************************************************************************/
    extern void small_image_selector_set_up(small_image_selector_struct *s, S32 n_images);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  GetCategory146History
 * DESCRIPTION
 *  Gets the history buffer for the object list screen
 * PARAMETERS
 *   history_buffer                : [IN ] (N/A) Is the buffer into which the history data is stored
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
    extern U8 *GetCategory146History(U8 *history_buffer);
#endif /* __MMI_SMALL_IMAGE_SELECTOR_SCREEN__ */ 

//#endif /* (!UI_DISABLE_EMS_CATEGORY_SCREENS) */ 
#endif /* __WGUI_CATEGORIES_EMS_H__ */ 
/* DOM-NOT_FOR_SDK-END */


