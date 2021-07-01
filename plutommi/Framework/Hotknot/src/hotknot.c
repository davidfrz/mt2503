
#include"Gpiosrvgprot.h"
#include"mmi_frm_events_gprot.h"
//#include"wfd_lcd_adapter.h"
#include"MMIDataType.h"
#include"GT9xx_hotknot.h"

#ifdef __MTK_TARGET__
#define MAIN_LCD_ID 1
#define __debug_hotknot__

extern kal_bool force_lcd_sleep_in(kal_uint8 lcd_id);
extern void lcd_sleep_out(kal_uint8 lcd_id);

/*****************************************************************************
* FUNCTION
*  mmi_frm_hotknot_approach_handler
* DESCRIPTION
*  used to turn off LCM when hotknot approach
* PARAMETERS
*  void         
* RETURNS
*  None
*****************************************************************************/
static void mmi_frm_hotknot_approach_handler(void)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __debug_hotknot__
    		kal_prompt_trace(MOD_MMI, "[hotknot] enter approach handler");
    #endif
    srv_backlight_turn_off_ext();
    force_lcd_sleep_in(MAIN_LCD_ID);
	modify_hotknot_status(HOTKNOT_LCD_OFF_STATUS);
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_hotknot_send_done_handler
* DESCRIPTION
*  Use to turn on lcm when hotknot send done
* PARAMETERS
*  void         
* RETURNS
*  None
*****************************************************************************/
static void mmi_frm_hotknot_send_done_handler(void)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __debug_hotknot__
    		kal_prompt_trace(MOD_MMI, "[hotknot] enter send done handler");
    #endif
    lcd_sleep_out(MAIN_LCD_ID);
	//kal_sleep_task(50);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
	modify_hotknot_status(HOTKNOT_LCD_ON_AGAIN_STATUS);
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_hotknot_enable
* DESCRIPTION
*  Use to enable hotknot
* PARAMETERS
*  void         
* RETURNS
*  None
*****************************************************************************/
void mmi_frm_hotknot_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __debug_hotknot__
    		kal_prompt_trace(MOD_MMI, "[hotknot] enable hotknot");
    #endif
		touch_panel_hotknot_enable();
		mmi_frm_set_protocol_event_handler(MSG_ID_TOUCH_HOTKNOT_APPROACH,(PsIntFuncPtr)mmi_frm_hotknot_approach_handler,MMI_FALSE);
		mmi_frm_set_protocol_event_handler(MSG_ID_TOUCH_HOTKNOT_SEND_DONE,(PsIntFuncPtr)mmi_frm_hotknot_send_done_handler,MMI_FALSE);
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_hotknot_disable
* DESCRIPTION
*  Use to disable hotknot
* PARAMETERS
*  void         
* RETURNS
*  None
*****************************************************************************/
void mmi_frm_hotknot_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __debug_hotknot__
    		kal_prompt_trace(MOD_MMI, "[hotknot] disable hotknot");
    #endif
		touch_panel_hotknot_disable();
		mmi_frm_clear_protocol_event_handler(MSG_ID_TOUCH_HOTKNOT_APPROACH, (PsIntFuncPtr)NULL);
		mmi_frm_clear_protocol_event_handler(MSG_ID_TOUCH_HOTKNOT_SEND_DONE, (PsIntFuncPtr)NULL);
}

#else

/*****************************************************************************
* FUNCTION
*  mmi_frm_hotknot_enable
* DESCRIPTION
*  Use to enable hotknot
* PARAMETERS
*  void         
* RETURNS
*  None
*****************************************************************************/
void mmi_frm_hotknot_enable(void)
{
		//dummy function
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_hotknot_disable
* DESCRIPTION
*  Use to disable hotknot
* PARAMETERS
*  void         
* RETURNS
*  None
*****************************************************************************/
void mmi_frm_hotknot_disable(void)
{
		//dummy function
}
#endif