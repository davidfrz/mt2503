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
 *  ScreenRotationGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Exported interface for MMI screen rotation
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SCREEN_ROTATION_GPROT_H__
#define __SCREEN_ROTATION_GPROT_H__

/***************************************************************************** 
* Define
*****************************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef enum
{
    MMI_FRM_SCREEN_ROTATE_0,   /* Normal screen */
    MMI_FRM_SCREEN_ROTATE_90,  /* Rotate 90 clockwise */
    MMI_FRM_SCREEN_ROTATE_180, /* Rotate 180 */
    MMI_FRM_SCREEN_ROTATE_270, /* Rotate 270 clockwise */
/* DOM-NOT_FOR_SDK-BEGIN */ 
    MMI_FRM_SCREEN_ROTATE_MIRROR_0,
    MMI_FRM_SCREEN_ROTATE_MIRROR_90,
    MMI_FRM_SCREEN_ROTATE_MIRROR_180,
    MMI_FRM_SCREEN_ROTATE_MIRROR_270,
    MMI_FRM_SCREEN_ROTATE_MAX_TYPE
/* DOM-NOT_FOR_SDK-END */
} mmi_frm_screen_rotate_enum;

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_screen_rotate
 * DESCRIPTION
 *  Set current screen to rotate
 * PARAMETERS
 *   mmi_frm_screen_rotate_enum      : [IN ] (N/A) Rotate degree
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
  * void EntryScreen_52(void)
  * {
  * 
  *     U16 ItemIcons[3];
  *     U8 *guiBuffer;
  *     U8 *PopUpList[3];
  *     U16 ItemList[3];
  *     S32 index;
  * 
  *     if ( mmi_frm_scrn_enter(
  *         GRP_ID_CSB_ROOT, SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, MMI_FRM_UNKNOW_SCRN))
  *     {
  *				  mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
  *         for ( index = 0; index < 3; index++ )
  *         {
  *             ItemList[index] = (U16)(STR_ID_CSB_MENUITEM1_TEXT + index);
  *             PopUpList[index] = (PU8) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
  *             ItemIcons[index] = (U16) (IMG_GLOBAL_L1 + index);
  *         }
  * 
  *         ShowCategory52Screen(
  *             STR_ID_CSB_CATEGORY_TEXT,
  *             0,
  *             STR_ID_CSB_LSK_TEXT,
  *             0,
  *             STR_ID_CSB_RSK_TEXT,
  *             0,
  *             3,
  *             ItemList,
  *             ItemIcons,
  *             (U8 **) PopUpList,
  *             0,
  *             0,
  *             guiBuffer);
  * 
  *         csb_set_key_handlers();
  *     }
  * }
 * </code>
 *****************************************************************************/
extern void mmi_frm_screen_rotate(mmi_frm_screen_rotate_enum rotation);
/* DOM-NOT_FOR_SDK-BEGIN */ 
extern void mmi_frm_set_self_rotation_flag(mmi_frm_screen_rotate_enum rotation);

extern MMI_BOOL mmi_frm_is_previous_screen_width_height_swapped(void);
extern mmi_frm_screen_rotate_enum mmi_frm_get_previous_screen_rotate(void);
extern mmi_frm_screen_rotate_enum mmi_frm_get_real_prev_screen_rotate(void);

extern MMI_BOOL mmi_frm_is_screen_width_height_swapped(void);
extern mmi_frm_screen_rotate_enum mmi_frm_get_screen_rotate(void);
extern void mmi_frm_reset_screen_rotation(void);

extern void mmi_frm_enable_clear_rotated_screen(MMI_BOOL enable);



typedef enum
{
    EVT_ID_ORIENTATION_CHANGED = APP_AUTO_ROTATE_BASE,
    EVT_ID_AUTO_ROTATE_QUERY,
    EVT_ID_AUTO_ROTATE_END
}mmi_frm_auto_rotate_evt_type_enum;

typedef enum{
    MMI_FRM_AUTO_ROTATE_DEFAULT,
    MMI_FRM_AUTO_ROTATE_SSQ,
    MMI_FRM_AUTO_ROTATE_SENSOR,
    MMI_FRM_AUTO_ROTATE_END
}mmi_frm_auto_rotate_type_enum;

typedef struct{
    MMI_EVT_PARAM_HEADER	/* basic event header */
    mmi_frm_screen_rotate_enum old_degree;
    mmi_frm_screen_rotate_enum new_degree;			
    mmi_frm_auto_rotate_type_enum rotation_type;	
} mmi_frm_auto_rotate_evt_struct;

extern mmi_ret mmi_auto_rotate_ssq_handler(mmi_event_struct *evt);
extern void mmi_frm_auto_rotate(void);
extern mmi_frm_screen_rotate_enum  mmi_frm_auto_rotate_get_degree(mmi_frm_auto_rotate_type_enum rotate_type);
extern void mmi_frm_auto_rotate_begin(mmi_frm_auto_rotate_type_enum rotate_type);
extern void mmi_frm_auto_rotate_end(void);
extern MMI_BOOL mmi_frm_auto_rotate_is_run(void);

extern MMI_BOOL mmi_auto_rotate_on_modis_handler(U16 key_code);
#if defined (MOTION_SENSOR_SUPPORT) && defined(__COSMOS_MMI__)
extern MMI_BOOL mmi_get_ui_rotation_state_by_mcube_sensor(void);
extern void mmi_set_ui_rotation_state_by_mcube_sensor(MMI_BOOL is_on);
#endif
/* DOM-NOT_FOR_SDK-END */
#endif /* __SCREEN_ROTATION_GPROT_H__ */ 


