/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrSaverFactory.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the factory of the screen saver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_SCREEN_SAVER__)
#include "MMIDataType.h"
#include "ScrSaverFactory.h"
#include "ScrSaverGprot.h"
#include "ScrSaverClock.h"
#include "ScrSaverObject.h"
#include "ScrSaverTime.h"
#include "ScrSaverMedia.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "ScrSaverTheme.h"
#include "mmi_frm_mem_gprot.h"


/****************************************************************************
 * Global context
 ****************************************************************************/
const static mmi_factory_cfg_struct g_mmi_ssv_cfg_tbl[] =
{
#if defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__)
    MMI_FACTORY_CFG_ADD(
        MMI_SCR_SAVER_TYPE_CLOCK,
        sizeof(mmi_ssv_clock_struct),
        mmi_ssv_clock_on_want_to_run,
        mmi_ssv_clock_on_init,
        mmi_ssv_obj_on_deinit),
#endif /* defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__) */

#if 0 //lhm: __MMI_THEMES_V2_SUPPORT__ phase out
#if defined(__MMI_THEMES_V2_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_THEMES_V2_SUPPORT__) */
#endif //if 0

#if defined(__MMI_LCD_PARTIAL_ON__)
    MMI_FACTORY_CFG_ADD(
        MMI_SCR_SAVER_TYPE_TIME,
        sizeof(mmi_ssv_time_struct),
        mmi_ssv_time_on_want_to_run,
        mmi_ssv_time_on_init,
        mmi_ssv_obj_on_deinit),
#endif /* defined(__MMI_LCD_PARTIAL_ON__) */

    MMI_FACTORY_CFG_ADD(
        MMI_SCR_SAVER_TYPE_MEDIA,
        sizeof(mmi_ssv_media_struct),
        mmi_ssv_obj_on_want_to_run,
        mmi_ssv_media_on_init,
        mmi_ssv_obj_on_deinit),

    MMI_FACTORY_CFG_END()
};


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_get_cfg_table
 * DESCRIPTION
 *  This function gets the scr saver configure table.
 * PARAMETERS
 *  void
 * RETURNS
 *  Idle type.
 *****************************************************************************/
const mmi_factory_cfg_struct *mmi_ssv_get_cfg_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_ssv_cfg_tbl;
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_buffer_malloc
 * DESCRIPTION
 *  This function is used to allocate ssv buffer
 * 
 * PARAMETERS
 *  size        : [IN]  buffer size
 * RETURNS
 *  the address of Idle buffer
 *****************************************************************************/
void *mmi_ssv_buffer_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_malloc(size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_buffer_free
 * DESCRIPTION
 *  This function is used to free ssv buffer
 * 
 * PARAMETERS
 *  p        : [IN]  the buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_ssv_buffer_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mfree(p);
}
#endif /* defined(__MMI_SCREEN_SAVER__) */
