/*Needed header files of the compile option in XML files */
#include "mmi_features.h"

#if (defined(__MMI_BTD_BOX_UI_STYLE__)||defined(__MMI_WEARABLE_DEVICE_SETTING__)||defined(__MMI_WEARABLE_DEVICE_ALARM__))

#include "CustResDef.h"

#define IMG_TYPE ".png"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id="APP_UIFRAMEWORK">
	<INCLUDE file="GlobalResDef.h"/>
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <STRING id="STR_ID_BTBOX_PICKER_SET_YEAR"/>
    <STRING id="STR_ID_BTBOX_PICKER_SET_MONTH_AND_DAY"/>
    <STRING id="STR_ID_BTBOX_PICKER_SET_TIME"/>
    <STRING id="STR_ID_BTBOX_PICKER_SET_MONTH"/>
    <STRING id="STR_ID_BTBOX_PICKER_SET_DAY"/>
    <STRING id="STR_ID_BTBOX_PICKER_SET_HOUR"/>
    <STRING id="STR_ID_BTBOX_PICKER_SET_MINUTE"/>
    <!--End String Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Image Resource Area-->
    <!--End Image Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

	
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <MENUITEM id="MENU_ID_BTBOX_PICKER_PREV" str="STR_ID_BTBOX_PICKER_SET_MONTH"/>
    <MENUITEM id="MENU_ID_BTBOX_PICKER_NEXT" str="STR_ID_BTBOX_PICKER_SET_DAY"/>
    <MENUITEM id="MENU_ID_BTBOX_PICKER_SAVE" str="STR_GLOBAL_SAVE"/>
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    

    <!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Tree Area-->
    <MENU id="MENU_ID_BTBOX_PICKER_OPTION_MENU" parent="0" type="OPTION" str="STR_GLOBAL_OPTIONS">
    	<MENUITEM_ID>MENU_ID_BTBOX_PICKER_PREV</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_BTBOX_PICKER_NEXT</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_BTBOX_PICKER_SAVE</MENUITEM_ID>
    </MENU>
	<!--End Menu Tree Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Screen ID Area-->
    <SCREEN id = "GRP_ID_BTBOX_PICKER_OPTION"/>
    <SCREEN id = "GRP_ID_BTBOX_PICKER"/>
    
    <SCREEN id = "SCR_ID_BTBOX_PICKER"/>
    <!--End Screen ID Area-->
	<!--------------------------------------------------------------------------------------------------------------------->

    
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Receiving Evt ID -->
	<!--End Receiving Evt ID -->
	<!--------------------------------------------------------------------------------------------------------------------->

    
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Sending Evt ID -->
	<!--End Sending Evt ID -->
	<!--------------------------------------------------------------------------------------------------------------------->
	
	
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--NVRAM LID -->
	<!--End NVRAM LID -->
	<!--------------------------------------------------------------------------------------------------------------------->
</APP>

#endif  // __MMI_BTD_BOX_UI_STYLE__
