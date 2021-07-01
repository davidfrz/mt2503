#include "mmi_features.h"
#ifdef __MMI_BLE_ANCS_SUPPORT__
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_BT_ANCS">
    <!--Include Area-->
    <!-----------------------------------------------Callback Manager Register------------------------------------------------------>
    <TIMER id="SRV_ANCS_DELAY_QUERY_TIMER"/>
    #ifdef __MMI_BLE_LOW_POWER__
    <TIMER id="SRV_ANCS_DELAY_RESET_INT_TIMER"/>
    #endif
    <RECEIVER id="SRV_LE_CM_EVENT_DISCONNECT_REQ" proc="srv_ancs_disconnect_hdlr"/>
</APP>
#endif