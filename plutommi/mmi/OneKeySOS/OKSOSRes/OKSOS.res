/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#ifdef __MMI_ONE_KEY_SOS_SUPPORT__
#include "custresdef.h"
#include "CustomCfg.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_OKSOS">

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
    <RECEIVER id="EVT_ID_SRV_OKSOS_DATA_CHANGE" proc="mmi_oksos_main_evt_hdlr"/>
    <!-- 
    ***************************************************************
    STRING Area
    ***************************************************************
    -->
    <STRING id="STR_ID_OKSOS_LIST_TITLE"/>
    <!-- 
    ***************************************************************
    IMAGE Area
    ***************************************************************
    -->
    <!-- 
    ***************************************************************
    SCREEN Area
    ***************************************************************
    -->
    <SCREEN id="GRP_ID_OKSOS_APP"/>
    <SCREEN id="SCR_ID_OKSOS_LIST"/>
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
#endif