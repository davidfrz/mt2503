/*Needed header files of the compile option in XML files */
#include "mmi_features.h"

#ifdef __MMI_UI_TIME_PICKER__

#include "CustResDef.h"

#define IMG_TYPE ".png"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id="APP_UIFRAMEWORK">
	<INCLUDE file="GlobalResDef.h"/>
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <STRING id="STR_ID_PICKER_YEAR"/>
    <STRING id="STR_ID_PICKER_MONTH"/>
    <STRING id="STR_ID_PICKER_DAY"/>
    <STRING id="STR_ID_PICKER_HOUR"/>
    <STRING id="STR_ID_PICKER_MINUTE"/>
    <!--End String Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Image Resource Area-->
    <IMAGE id="IMG_ID_PICKER_0">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\0"IMG_TYPE</IMAGE> 
    <IMAGE id="IMG_ID_PICKER_1">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\1"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_2">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\2"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_3">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\3"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_4">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\4"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_5">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\5"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_6">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\6"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_7">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\7"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_8">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\8"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_9">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\9"IMG_TYPE</IMAGE>
    
    <IMAGE id="IMG_ID_PICKER_0_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\0_down"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_1_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\1_down"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_2_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\2_down"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_3_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\3_down"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_4_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\4_down"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_5_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\5_down"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_6_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\6_down"IMG_TYPE</IMAGE> 
    <IMAGE id="IMG_ID_PICKER_7_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\7_down"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_8_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\8_down"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_9_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\9_down"IMG_TYPE</IMAGE>
    #ifdef __MMI_WEARABLE_DEVICE__    
    <IMAGE id="IMG_ID_TIME_0">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_0"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_TIME_1">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_1"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_TIME_2">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_2"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_TIME_3">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_3"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_TIME_4">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_4"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_TIME_5">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_5"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_TIME_6">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_6"IMG_TYPE</IMAGE> 
    <IMAGE id="IMG_ID_TIME_7">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_7"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_TIME_8">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_8"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_TIME_9">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_9"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_AM">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_AM"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_AM_UNSEL">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_AM_unsel"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PM">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_PM"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PM_UNSEL">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_PM_unsel"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_COLON">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Time_Colon"IMG_TYPE</IMAGE>
    #endif /*__MMI_WEARABLE_DEVICE__*/
    
    <IMAGE id="IMG_ID_PICKER_NUM_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\num_bg"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_NUM_DOWN_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\num_down_bg"IMG_TYPE</IMAGE>
    
    <IMAGE id="IMG_ID_PICKER_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\BG.9slice"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_LEFT_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Left"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_RIGHT_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Right"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_FIELD_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Front_White.9slice"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_SHADOW_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Shadow_Down.9slice"IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_PICKER_SHADOW_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Picker\\\\Shadow_Up.9slice"IMG_TYPE</IMAGE>
    <!--End Image Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

	
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    

    <!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Tree Area-->
	<!--End Menu Tree Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Screen ID Area-->
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

#endif  //__MMI_UI_TIME_PICKER__
