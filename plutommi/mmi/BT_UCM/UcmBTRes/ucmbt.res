/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include "CustomCfg.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_UCMBT">

    <!-- 
    ***************************************************************
    Include Area
    ***************************************************************
    -->
    <INCLUDE file="GlobalResDef.h"/>
    //<INCLUDE file="mmi_rp_app_ucm_def.h"/>
    <INCLUDE file="mmi_rp_app_ucmbt_def.h"/>

    <INCLUDE file="ConnectivityResDef.h"/>

    <INCLUDE file="mmi_rp_srv_editor_def.h"/> 

    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/> 

    <!-- 
    ***************************************************************
    Callback mgnt Area
    ***************************************************************
    -->

    <!-- 
    ***************************************************************
    NVRAM Area
    ***************************************************************
    -->

    <!-- 
    ***************************************************************
    TIMER Area
    ***************************************************************
    -->

    <TIMER id="UCM_NOTIFY_DURATION_TIMER_BT"/>
    <TIMER id="UCM_TONE_AFTER_VIBRATION_BT"/>
    <TIMER id="UCM_MO_PROCESSING_TIMER_BT"/>
    <TIMER id="UCM_FORCE_REFRESH_TIMER_BT"/>
    <TIMER id="UCM_VOL_BAR_SHOW_TIMER_BT"/>
    <TIMER id="UCM_VOL_STR_SHOW_TIMER_BT"/>
    <TIMER id="UCM_VOL_SET_DELAY_TIMER_BT"/>
#ifdef __MMI_FTE_SUPPORT__
    <TIMER id="UCM_FTE_AUTO_LOCK_TIMER_ID_BT"/>
#endif

    <!-- 
    ***************************************************************
    Callback mgnt Area
    ***************************************************************
    -->
#ifdef __MMI_BT_CALL_SUPPORT__
    <EVENT id="EVT_ID_UCM_BT_CALL_END" type="SENDER"/>
    <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_ucm_main_evt_hdlr_bt"/>
    <RECEIVER id="EVT_ID_GPIO_EXT_DEV_KEY_1" proc="mmi_ucm_main_evt_hdlr_bt"/>
    <RECEIVER id="EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN" proc="mmi_ucm_main_evt_hdlr_bt"/>
    <RECEIVER id="EVT_ID_SRV_UCM_BT_INDICATION" proc="mmi_ucm_ind_hdlr_bt"/>
    <RECEIVER id="EVT_ID_SRV_UCM_BT_ACTION_NOTIFY" proc="mmi_ucm_act_notify_hdlr_bt"/>
#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
    <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_ucm_main_evt_hdlr_bt"/>
#endif /* __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__ */
#ifdef __MMI_HF_BAT_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_CHARBAT_NOTIFY" proc="mmi_ucm_main_evt_hdlr_bt"/>
#endif /* __MMI_HF_BAT_SUPPORT__ */
#ifdef __MMI_WEARABLE_DEVICE__
    <RECEIVER id="EVT_ID_PRE_TOUCH_EVT_ROUTING" proc="mmi_ucm_main_evt_hdlr_bt"/>
#endif /* __MMI_WEARABLE_DEVICE__ */
#endif /* __MMI_BT_CALL_SUPPORT__ */

#if defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_UCM_BT_BTBOX_NOLCD__)
    <TIMER id="UCM_DOUBLE_CLICK_TIMER"/>

    <EVENT id="EVT_UCM_BT_BTBOX_CALL_ANSWER" type="SENDER"/>
    <EVENT id="EVT_UCM_BT_BTBOX_CALL_SWAP" type="SENDER"/>
    <EVENT id="EVT_UCM_BT_BTBOX_CALL_END" type="SENDER"/>
    <EVENT id="EVT_UCM_BT_BTBOX_VOLUP" type="SENDER"/>
    <EVENT id="EVT_UCM_BT_BTBOX_VOLDOWN" type="SENDER"/>

    // Answer Event
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MT" grp_desc="incoming call" evt_id="EVT_UCM_BT_BTBOX_CALL_ANSWER" evt_desc="accept incoming call" key_code="KEY_2" key_type="KEY_EVENT_UP"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_INCALL" grp_desc="in call" evt_id="EVT_UCM_BT_BTBOX_CALL_ANSWER" evt_desc="accept incoming call" key_code="KEY_2" key_type="KEY_EVENT_UP"/>
        // Reconnect parts
  #ifdef __BTB_DEMO_SUPPORT__
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MO" grp_desc="incoming call" evt_id="EVT_UCM_BT_BTBOX_CALL_ANSWER" evt_desc="accept incoming call" key_code="KEY_2" key_type="KEY_EVENT_UP"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_CALL_END" grp_desc="in call" evt_id="EVT_UCM_BT_BTBOX_CALL_ANSWER" evt_desc="accept incoming call" key_code="KEY_2" key_type="KEY_EVENT_UP"/>
  #endif /* __BTB_DEMO_SUPPORT__ */
    // Swap Event
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_INCALL" grp_desc="in call" evt_id="EVT_UCM_BT_BTBOX_CALL_SWAP" evt_desc="swap call" key_code="KEY_1" key_type="KEY_EVENT_UP"/>
    // End Event
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MO" grp_desc="outgoing call" evt_id="EVT_UCM_BT_BTBOX_CALL_END" evt_desc="abort outgoing call" key_code="KEY_0" key_type="KEY_EVENT_UP"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MT" grp_desc="incoming call" evt_id="EVT_UCM_BT_BTBOX_CALL_END" evt_desc="end call" key_code="KEY_0" key_type="KEY_EVENT_UP"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_INCALL" grp_desc="in call" evt_id="EVT_UCM_BT_BTBOX_CALL_END" evt_desc="end call" key_code="KEY_0" key_type="KEY_EVENT_UP"/>
    // Volume Up
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MT" grp_desc="incoming call" evt_id="EVT_UCM_BT_BTBOX_VOLUP" evt_desc="volume up" key_code="KEY_0" key_type="KEY_EVENT_REPEAT"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MT" grp_desc="incoming call" evt_id="EVT_UCM_BT_BTBOX_VOLUP" evt_desc="volume up" key_code="KEY_0" key_type="KEY_EVENT_LONG_PRESS"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_INCALL" grp_desc="in call" evt_id="EVT_UCM_BT_BTBOX_VOLUP" evt_desc="volume up" key_code="KEY_0" key_type="KEY_EVENT_REPEAT"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_INCALL" grp_desc="in call" evt_id="EVT_UCM_BT_BTBOX_VOLUP" evt_desc="volume up" key_code="KEY_0" key_type="KEY_EVENT_LONG_PRESS"/>
    // Volume Down
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MT" grp_desc="incoming call" evt_id="EVT_UCM_BT_BTBOX_VOLDOWN" evt_desc="volume down" key_code="KEY_1" key_type="KEY_EVENT_REPEAT"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MT" grp_desc="incoming call" evt_id="EVT_UCM_BT_BTBOX_VOLDOWN" evt_desc="volume down" key_code="KEY_1" key_type="KEY_EVENT_LONG_PRESS"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_INCALL" grp_desc="in call" evt_id="EVT_UCM_BT_BTBOX_VOLDOWN" evt_desc="volume down" key_code="KEY_1" key_type="KEY_EVENT_REPEAT"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_INCALL" grp_desc="in call" evt_id="EVT_UCM_BT_BTBOX_VOLDOWN" evt_desc="volume down" key_code="KEY_1" key_type="KEY_EVENT_LONG_PRESS"/>
    // Anti Lost Cancel Event
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MO" grp_desc="stop reconnect" evt_id="EVT_BTB_RECONN_CANCEL" evt_desc="stop reconnect" key_code="KEY_2" key_type="KEY_EVENT_LONG_PRESS"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MT" grp_desc="stop reconnect" evt_id="EVT_BTB_RECONN_CANCEL" evt_desc="stop reconnect" key_code="KEY_2" key_type="KEY_EVENT_LONG_PRESS"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_INCALL" grp_desc="stop reconnect" evt_id="EVT_BTB_RECONN_CANCEL" evt_desc="stop reconnect" key_code="KEY_2" key_type="KEY_EVENT_LONG_PRESS"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_CALL_END" grp_desc="stop reconnect" evt_id="EVT_BTB_RECONN_CANCEL" evt_desc="stop reconnect" key_code="KEY_2" key_type="KEY_EVENT_LONG_PRESS"/>
  #ifdef __MMI_BTB_AT_KEY_SUPPORT__
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MO" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_CANCEL" evt_desc="start reconnect" key_code="KEY_STAR" key_type="KEY_EVENT_UP"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MT" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_CANCEL" evt_desc="start reconnect" key_code="KEY_STAR" key_type="KEY_EVENT_UP"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_INCALL" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_CANCEL" evt_desc="start reconnect" key_code="KEY_STAR" key_type="KEY_EVENT_UP"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_CALL_END" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_CANCEL" evt_desc="start reconnect" key_code="KEY_STAR" key_type="KEY_EVENT_UP"/>
  #endif /* __MMI_BTB_AT_KEY_SUPPORT__ */
    // Anti Lost Reconnect Event
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MO" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_RESTART" evt_desc="start reconnect" key_code="KEY_5" key_type="KEY_EVENT_UP"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_MT" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_RESTART" evt_desc="start reconnect" key_code="KEY_5" key_type="KEY_EVENT_UP"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_INCALL" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_RESTART" evt_desc="start reconnect" key_code="KEY_5" key_type="KEY_EVENT_UP"/>
    <INPUT_EVENT grp_id="GRP_ID_UCM_BT_CALL_END" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_RESTART" evt_desc="start reconnect" key_code="KEY_5" key_type="KEY_EVENT_UP"/>
#endif /* __MMI_BT_DIALER_SUPPORT__ && __MMI_UCM_BT_BTBOX_NOLCD__ */

    <!-- 
    ***************************************************************
    NOTIFY Area
    ***************************************************************
    -->
#if defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_UCM_BT_BTBOX_NOLCD__)
    // LED      mmi_input_event_led_enum    g_input_event_notify_led_info_tbl
    // VOICE
    // VIB      mmi_input_event_vib_enum    g_input_event_notify_vib_info_tbl
    <NOTIFY id="NOTIFY_UCM_BT_OUTGOING" desc="outgoing call"/>
    <NOTIFY id="NOTIFY_UCM_BT_INCOMING" desc="incoming call"/>
    <NOTIFY id="NOTIFY_UCM_BT_WAITING" desc="waiting call" vib="INPUT_EVENT_VIB_INDX_0"/>
    <NOTIFY id="NOTIFY_UCM_BT_ACTIVE" desc="call connected" led="INPUT_EVENT_LED_ID_7"/>
    <NOTIFY id="NOTIFY_UCM_BT_HELD" desc="call held"/>
    <NOTIFY id="NOTIFY_UCM_BT_END" desc="call end"/>
    <NOTIFY id="NOTIFY_UCM_BT_FAIL" desc="call fail" led="INPUT_EVENT_LED_ID_9"/>
    <NOTIFY id="NOTIFY_UCM_BT_VOLUP" desc="call volume increase" led="INPUT_EVENT_LED_ID_9"/>
    <NOTIFY id="NOTIFY_UCM_BT_VOLDOWN" desc="call volume decrease" led="INPUT_EVENT_LED_ID_9"/>
#endif /* __MMI_BT_DIALER_SUPPORT__ && __MMI_UCM_BT_BTBOX_NOLCD__ */

    <!-- 
    ***************************************************************
    STRING Area
    ***************************************************************
    -->

    <STRING id="STR_ID_UCM_BT_CALLING"/>
    <STRING id="STR_ID_UCM_BT_REJECT"/>
    <STRING id="STR_ID_UCM_BT_ANSWER"/>
    <STRING id="STR_ID_UCM_BT_RETRIEVE"/>
    <STRING id="STR_ID_UCM_BT_END_CALL"/>
    <STRING id="STR_ID_UCM_BT_UNMUTE"/>
    <STRING id="STR_ID_UCM_BT_HAND_HELD"/>
    <STRING id="STR_ID_UCM_BT_HAND_FREE"/>
    <STRING id="STR_ID_UCM_BT_ACTIVE"/>
    <STRING id="STR_ID_UCM_BT_PAIRED_HOLD"/>
    <STRING id="STR_ID_UCM_BT_CALL_ENDED"/>
    <STRING id="STR_ID_UCM_BT_PROCESSING"/>
    <STRING id="STR_ID_UCM_BT_CALL_WILL_BE_ENDED"/>
    <STRING id="STR_ID_UCM_CONN_BT_FIRST"/>
    <STRING id="STR_ID_UCM_BT_CONF_CALL"/>
    <STRING id="STR_ID_UCM_BT_REPLACE"/>
    <STRING id="STR_ID_UCM_BT_NO_RESPONSE"/>
    <STRING id="STR_ID_UCM_BT_CALL_FAILED"/>

#ifndef __MMI_WEARABLE_DEVICE__
    <STRING id="STR_ID_UCM_BT_END_CONF"/>
    <STRING id="STR_ID_UCM_BT_HOLD"/>
    <STRING id="STR_ID_UCM_BT_SWAP"/>
    <STRING id="STR_ID_UCM_BT_END_SINGLE"/>
    <STRING id="STR_ID_UCM_BT_END_ALL"/>
    <STRING id="STR_ID_UCM_BT_DTMF"/>
    <STRING id="STR_ID_UCM_BT_SWITCH_AUDIO_PATH"/>
#else
    <STRING id="STR_ID_UCM_BT_UNHOLD"/>
    <STRING id="STR_ID_UCM_BT_STATE_HELD"/>
    <STRING id="STR_ID_UCM_BT_REJECT_THE_CALL"/>
    <STRING id="STR_ID_UCM_BT_END_THE_CALL"/>
    <STRING id="STR_ID_UCM_BT_RECONN_CNF"/>
    <STRING id="STR_ID_UCM_BT_ACCEPTING"/>
    <STRING id="STR_ID_UCM_BT_ENDING"/>
    <STRING id="STR_ID_UCM_BT_SWAPPING"/>
    <STRING id="STR_ID_UCM_BT_UNHOLDING"/>
    <STRING id="STR_ID_UCM_BT_REJECTING"/>
#endif /* __MMI_WEARABLE_DEVICE__ */

#ifndef __MMI_GSM_CALL_SUPPORT__
    <STRING id="STR_ID_UCM_CALL_SELECT"/>
    <STRING id="STR_ID_UCM_FROM_BT_CALL"/>
    <STRING id="STR_ID_UCM_VOICE_INCOMING"/>
#endif /* __MMI_GSM_CALL_SUPPORT__ */

#ifdef __MMI_UCM_BT_CALL_RECORDER__
    <STRING id="STR_ID_UCM_BT_CALL_RECODE"/>
    <STRING id="STR_ID_UCM_BT_CALL_UNRECODE"/>
    <STRING id="STR_ID_UCM_RECORDING"/>
#endif /*__MMI_UCM_BT_CALL_RECORDER__*/
#ifndef __MMI_GSM_CALL_SUPPORT__
#ifdef __MMI_FTE_SUPPORT__
    <STRING id="STR_ID_UCM_TOUCH_TO_UNLOCK"/>
#endif /* __MMI_FTE_SUPPORT__ */
#endif
    <!-- 
    ***************************************************************
    IMAGE Area
    ***************************************************************
    -->
 
#if defined (__MMI_BT_CALL_SUPPORT__)

#if defined (__MMI_FTE_SUPPORT__)
#ifdef __MMI_WEARABLE_DEVICE__
    <IMAGE id="IMG_ID_UCM_BT_OUTGOING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\call_outing.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_BT_INCOMING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Incoming\\\\call_incoming.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_BT_IN_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Incoming\\\\call_incall.png"</IMAGE>
#else
    <IMAGE id="IMG_ID_UCM_BT_OUTGOING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\BT_NET.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_BT_INCOMING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\BT_NET.png"</IMAGE>
#endif
#elif defined (__MMI_MAINLCD_128X128__)
    <IMAGE id="IMG_ID_UCM_BT_OUTGOING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\BT_NET.jpg"</IMAGE>
    <IMAGE id="IMG_ID_UCM_BT_INCOMING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Incoming\\\\BT_INCOM.jpg"</IMAGE>
#ifdef __MMI_WEARABLE_DEVICE__
    <IMAGE id="IMG_ID_UCM_BT_IN_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Incoming\\\\call_incall.png"</IMAGE>
#endif
#else
    <IMAGE id="IMG_ID_UCM_BT_OUTGOING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\BT_NET.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_BT_INCOMING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\BT_NET.png"</IMAGE>
#ifdef __MMI_WEARABLE_DEVICE__
    <IMAGE id="IMG_ID_UCM_BT_IN_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Incoming\\\\call_incall.png"</IMAGE>
#endif
#endif /* __MMI_FTE_SUPPORT__ */
#ifndef __MMI_GSM_CALL_SUPPORT__
#if defined (__MMI_WEARABLE_DEVICE__)
    <IMAGE id="IMG_ID_UCM_BT_CALL_STATE_HOLD">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\call_hold.png"</IMAGE>
#elif defined (__FTE_NON_SLIM_RES__)  
    <IMAGE id="IMG_ID_UCM_CALL_STATE_ACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_ACT.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_CALL_STATE_HOLD">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_HOLD.png"</IMAGE>
#else
    <IMAGE id="IMG_ID_UCM_CALL_STATE_ACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_ACT.bmp"</IMAGE>
    <IMAGE id="IMG_ID_UCM_CALL_STATE_HOLD">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_HOLD.bmp"</IMAGE>
#endif /* __FTE_NON_SLIM_RES__ */
#ifndef __MMI_WEARABLE_DEVICE__
#ifdef __MMI_BTD_BOX_UI_STYLE__
    <IMAGE id="IMG_ID_UCM_LOCK_ICON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_LOCK_ICON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock_down.png"</IMAGE>
#elif defined (__SLIM_UCM__)
    <IMAGE id="IMG_ID_UCM_LOCK_ICON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock_s.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_LOCK_ICON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock_down_s.png"</IMAGE>
#else
    <IMAGE id="IMG_ID_UCM_LOCK_ICON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_LOCK_ICON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock_down.png"</IMAGE>
#endif /* __SLIM_UCM__ */
#endif /* __MMI_WEARABLE_DEVICE__ */
#endif /* __MMI_GSM_CALL_SUPPORT__ */

#if defined(__MMI_GSM_CALL_SUPPORT__) && defined(__MMI_WEARABLE_DEVICE__)
    <IMAGE id="IMG_ID_UCM_BT_CALL_STATE_HOLD">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\call_hold.png"</IMAGE>
#endif /* __MMI_WEARABLE_DEVICE__ && __MMI_GSM_CALL_SUPPORT__*/
#endif /* __MMI_BT_CALL_SUPPORT__ */

    <!-- 
    ***************************************************************
    SCREEN Area
    ***************************************************************
    -->
    <SCREEN id="GRP_ID_UCM_BT_PRE_MO"/>
    <SCREEN id="GRP_ID_UCM_BT_MO"/>
    <SCREEN id="GRP_ID_UCM_BT_MT"/>
    <SCREEN id="GRP_ID_UCM_BT_INCALL"/>
    <SCREEN id="GRP_ID_UCM_BT_CALL_END"/>
    <SCREEN id="GRP_ID_UCM_BT_DEV_NOTI"/>
#ifndef __MMI_GSM_CALL_SUPPORT__
    <SCREEN id="GRP_ID_UCM_MO_SELECT"/>
#endif /* __MMI_GSM_CALL_SUPPORT__ */
#ifdef __MMI_WEARABLE_DEVICE__
    <SCREEN id="GRP_ID_UCM_BT_HW_CNF"/>
    <SCREEN id="GRP_ID_UCM_SGL_CONN_CNF"/>
#endif
 
    <SCREEN id="SCR_ID_UCM_BT_OUTGOING"/>
    <SCREEN id="SCR_ID_UCM_BT_INCOMING"/>
    <SCREEN id="SCR_ID_UCM_BT_IN_CALL"/>
    <SCREEN id="SCR_ID_UCM_BT_CALL_END"/>
    <SCREEN id="SCR_ID_UCM_BT_PROCESSING"/>
    <SCREEN id="SCR_ID_UCM_BT_DUMMY"/>
    <SCREEN id="SCR_ID_UCM_BT_DIALLING"/>
    <SCREEN id="SCR_ID_UCM_END_AND_ACCEPT_CONFIRM"/>
    <SCREEN id="SCR_ID_UCM_BT_DTMF_EDITOR"/>
    <SCREEN id="SCR_ID_UCM_BT_DEV_NOTIFY"/>
#ifdef __MMI_WEARABLE_DEVICE__
    <SCREEN id="SCR_ID_UCM_BT_HW_CNF"/>
    <SCREEN id="SCR_ID_UCM_SGL_CONN_CNF"/>
#endif
   
    <!-- 
    ***************************************************************
    EVENT Area
    ***************************************************************
     -->
    <!-- 
    ***************************************************************
    MENU Area
    ***************************************************************
    -->
#ifndef __MMI_WEARABLE_DEVICE__
   <MENU id="MENU_ID_UCM_BT_INCALL_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">                             
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_HOLD</MENUITEM_ID>                       
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_RETRIEVE</MENUITEM_ID>                              
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_SWAP</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_DTMF</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_MUTE</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_UNMUTE</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_END_SINGLE</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_END_CONF</MENUITEM_ID>                  
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_END_ALL</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_SWITCH_AUDIO_PATH</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_BQB_TEST_HOLD</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_BQB_TEST_END</MENUITEM_ID>
                            #ifdef __MMI_UCM_BT_CALL_RECORDER__
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_RECODE</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_BT_INCALL_OPTION_UNRECODE</MENUITEM_ID>
                            #endif /*__MMI_UCM_BT_CALL_RECORDER__*/
   </MENU>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_HOLD" str="STR_ID_UCM_BT_HOLD"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_RETRIEVE" str="STR_ID_UCM_BT_RETRIEVE"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_SWAP" str="STR_ID_UCM_BT_SWAP"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_DTMF" str="STR_ID_UCM_BT_DTMF"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_MUTE" str="STR_GLOBAL_MUTE"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_UNMUTE" str="STR_ID_UCM_BT_UNMUTE"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_END_SINGLE" str="STR_ID_UCM_BT_END_SINGLE"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_END_CONF" str="STR_ID_UCM_BT_END_CONF"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_END_ALL" str="STR_ID_UCM_BT_END_ALL"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_SWITCH_AUDIO_PATH" str="STR_ID_UCM_BT_SWITCH_AUDIO_PATH"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_BQB_TEST_HOLD" str="STR_GLOBAL_MODE"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_BQB_TEST_END" str="STR_GLOBAL_NORMAL"/>
   #ifdef __MMI_UCM_BT_CALL_RECORDER__
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_RECODE" str="STR_ID_UCM_BT_CALL_RECODE"/>
   <MENUITEM id="MENU_ID_UCM_BT_INCALL_OPTION_UNRECODE" str="STR_ID_UCM_BT_CALL_UNRECODE"/>
   #endif /*__MMI_UCM_BT_CALL_RECORDER__*/
#endif /*  __MMI_WEARABLE_DEVICE__ */

#ifndef __MMI_GSM_CALL_SUPPORT__
    <MENU id="MENU_ID_UCM_CALL_SELECT" type="APP_SUB" str="STR_ID_UCM_CALL_SELECT">
        <MENUITEM_ID>MENU_ID_UCM_FROM_BT_CALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UCM_FROM_BT_CALL2</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_UCM_FROM_BT_CALL" str="STR_ID_UCM_FROM_BT_CALL"/>
    <MENUITEM id="MENU_ID_UCM_FROM_BT_CALL2" str="STR_ID_UCM_FROM_BT_CALL"/>
#endif /* __MMI_GSM_CALL_SUPPORT__ */

 </APP>
