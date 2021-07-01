/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include "CustomCfg.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_HEART_RATE"
	   package_name="native.mtk.heartrate"
     name="STR_ID_HR_APP_NAME"
     img="IMG_HEART_RATE_MAIN_MENU_ICON"
     launch="mmi_heart_rate_launch"
     hidden_in_mainmenu="false">

    <!-- 
    ***************************************************************
    Include Area
    ***************************************************************
    -->
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="MainMenuDef.h"/> 
    <!-- 
    ***************************************************************
    TIMER Area
    ***************************************************************
    -->
    <TIMER id="HR_SEND_DATA_TIMER"/>
    <!-- 
    ***************************************************************
    Callback mgnt Area
    ***************************************************************
    -->   
    #if defined( __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) && defined(__MMI_WEARABLE_DEVICE__)
    <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_heart_rate_evt_hdlr"/>
		#endif
		
		<RECEIVER id="EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN" proc="mmi_heart_rate_evt_hdlr"/>
		
    <RECEIVER id="EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE" proc="mmi_heart_rate_evt_hdlr"/>
    <!-- 
    ***************************************************************
    STRING Area
    ***************************************************************
    -->
    <STRING id="STR_ID_HR_APP_NAME"/>
    <STRING id="STR_ID_HR_HEART_RATE"/>
    <STRING id="STR_ID_HR_BT_CONNECTED"/>
    <STRING id="STR_ID_HR_BT_DISCONNECTED"/>
    <STRING id="STR_ID_HR_DETECT"/>
    
    <!-- 
    ***************************************************************
    IMAGE Area
    ***************************************************************
    -->
    <IMAGE id="IMG_HEART_RATE_MAIN_MENU_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\Smart_watch\\\\heart_rate.png"</IMAGE>
    <!-- 
    ***************************************************************
    SCREEN Area
    ***************************************************************
    -->
    <SCREEN id="GRP_ID_HR_APP"/>
    <SCREEN id="SCR_ID_HR_MAIN"/>
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
    <MENU id="MAIN_MENU_HEARTRATE_MENUID" type="APP_MAIN" str="STR_ID_HR_APP_NAME" img="IMG_HEART_RATE_MAIN_MENU_ICON"
        shortcut="ON" shortcut_img="IMG_HEART_RATE_MAIN_MENU_ICON" launch="mmi_heart_rate_launch">    	
    </MENU>
 </APP>

