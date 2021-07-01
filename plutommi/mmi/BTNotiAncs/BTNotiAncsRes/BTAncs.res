/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

#if defined(__MMI_ANCS_IOS8_SUPPORT__)
#include "custresdef.h"
#include "CustomCfg.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_ANCS">

    <!-- 
    ***************************************************************
    Include Area
    ***************************************************************
    -->
    <INCLUDE file="GlobalResDef.h"/>
    <!-- 
    ***************************************************************
    TIMER Area
    ***************************************************************
    -->
    // <TIMER id="UCM_NOTIFY_DURATION_TIMER_BT"/>
    <!-- 
    ***************************************************************
    Callback mgnt Area
    ***************************************************************
    -->
    <RECEIVER id="EVT_ID_SRV_ANCS_NOTI_IND" proc="mmi_bt_ancs_evt_hdlr"/>
    
    #ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
    <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_bt_ancs_evt_hdlr"/>
    #endif
    
    <RECEIVER id="EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN" proc="mmi_bt_ancs_evt_hdlr"/>
    
    #ifdef __MMI_HF_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_UCM_BT_INDICATION" proc="mmi_bt_ancs_evt_hdlr"/>
    #endif
    <!-- 
    ***************************************************************
    STRING Area
    ***************************************************************
    -->
    //<STRING id="STR_ID_ANCS_DEV_CON"/>
    //<STRING id="STR_ID_ANCS_DEV_DISCON"/>
    // <STRING id="STR_ID_UCM_BT_END_CONF"/>
    <STRING id="STR_ID_ANCS_ACCEPT"/>
    <STRING id="STR_ID_ANCS_REJECT"/>
    <STRING id="STR_ID_ANCS_INCOMING_CALL"/>
    <!-- 
    ***************************************************************
    IMAGE Area
    ***************************************************************
    -->
    // <IMAGE id="IMG_ID_UCM_BT_OUTGOING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\call_outing.png"</IMAGE>
    <IMAGE id="IMG_ID_ANCS_INCOMING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Incoming\\\\call_incoming.png"</IMAGE>
    <!-- 
    ***************************************************************
    SCREEN Area
    ***************************************************************
    -->
    <SCREEN id="GRP_ID_BT_ANCS_APP"/>
    <SCREEN id="SCR_ID_BT_ANCS_POPUP"/>
    //<SCREEN id="SCR_ID_BT_ANCS_DETAIL"/>
    //<SCREEN id="SCR_ID_BT_ANCS_LIST"/>
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
 </APP>

#endif /* __MMI_ANCS_IOS8_SUPPORT__ */