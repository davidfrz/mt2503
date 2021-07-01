/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_WLAN">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
   

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SENDER id="EVT_ID_WLAN_IP_AVAILABLE_NOTI" hfile="WlanSrvIprot.h"/>
	  <TIMER id="SRV_WLAN_LAUNCH_WIFI_SRV"/>
	  <CACHEDATA type="double" id="NVRAM_WLAN_RECONN_PROF_ID" restore_flag="TRUE">    
    		<DEFAULT_VALUE> [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00] </DEFAULT_VALUE>    
        <DESCRIPTION> The prof id which will be used to connect to wifi AP when reboot. </DESCRIPTION>
        <FIELD min="0" max="0xffffffff"></FIELD>
    </CACHEDATA>
</APP>

