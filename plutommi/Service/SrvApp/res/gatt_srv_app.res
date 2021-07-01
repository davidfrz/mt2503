#ifdef __BT_GATTS_PROFILE__
#ifdef __IOT__
#include "MMI_features.h"
<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_GATT_APP">

<!-----------------------------------------------------Event Resource Area----------------------------------------------------->

<!-- 
**************************************** String section ***************************************
-->


<!-- 
**************************************** Screen section ***************************************
-->

<!-----------------------------------------------------MMI timer------------------------------------------------------>
	  <TIMER id="FMP_SRV_APP_ALERT_TIMER"/>
	  <TIMER id="PXP_SRV_APP_ALERT_TIMER"/>
	  <TIMER id="BT_MODE_SWITCH_KEEP_ALIVE_TIMER"/>
	  <TIMER id="BT_MODE_SWITCH_CONN_CHECK_TIMER"/>
	  <TIMER id="BT_SCAN_ALIVE_TIMER"/>
	  <TIMER id="BT_MODE_SWITCH_DELAY_TIMER"/>
</APP>
#endif
#endif
