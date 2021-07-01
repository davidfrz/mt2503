/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include "CustomCfg.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_BLOOD_PRESSURE"
	 package_name="native.mtk.bloodpressure"
     name="STR_ID_BP_APP_NAME"
     img="IMG_BP_MAIN_MENU_ICON"
     launch="mmi_blood_pressure_launch"
     hidden_in_mainmenu="false">

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
     <TIMER id="BP_COUNT_DOWN_TIMER"/>
     <TIMER id="BP_DETECT_OVER_TIMER"/>
    <!-- 
    ***************************************************************
    Callback mgnt Area
    ***************************************************************
    -->   
    #if defined( __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) && defined(__MMI_WEARABLE_DEVICE__)
    <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_blood_pressure_evt_hdlr"/>
		#endif
		
		<RECEIVER id="EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN" proc="mmi_blood_pressure_evt_hdlr"/>
		
    <RECEIVER id="EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE" proc="mmi_blood_pressure_evt_hdlr"/>
    <!-- 
    ***************************************************************
    STRING Area
    ***************************************************************
    -->
    <STRING id="STR_ID_BP_APP_NAME"/>
    <STRING id="STR_ID_BP_BLOOD_PRESSURE"/>
    <STRING id="STR_ID_BP_BT_CONNECTED"/>
    <STRING id="STR_ID_BP_BT_DISCONNECTED"/>
    <STRING id="STR_ID_BP_PROMPT"/>
    <STRING id="STR_ID_BP_COUNT_DOWN"/>
    <STRING id="STR_ID_BP_DETECT"/>
    <STRING id="STR_ID_BP_DETECT_FAIL"/>
    <!-- 
    ***************************************************************
    IMAGE Area
    ***************************************************************
    -->
    <IMAGE id="IMG_BP_MAIN_MENU_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\Smart_watch\\\\blood_pressure.png"</IMAGE>
    <!-- 
    ***************************************************************
    SCREEN Area
    ***************************************************************
    -->
    <SCREEN id="GRP_ID_BP_APP"/>
    <SCREEN id="SCR_ID_BP_MAIN"/>
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
    <MENU id="MAIN_MENU_BP_MENUID" type="APP_MAIN" str="STR_ID_BP_APP_NAME" img="IMG_BP_MAIN_MENU_ICON"
        shortcut="ON" shortcut_img="MAIN_MENU_BTNOTIFICATION_ICON" launch="mmi_blood_pressure_launch">    	
    </MENU>
 </APP>

