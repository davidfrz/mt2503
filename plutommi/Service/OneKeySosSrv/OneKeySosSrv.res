#include "mmi_features.h"
#ifdef __MMI_ONE_KEY_SOS_SUPPORT__
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_OKSOS">
    <!--Include Area-->
    <!-----------------------------------------------Callback Manager Register------------------------------------------------------>
    <EVENT id="EVT_ID_SRV_OKSOS_DATA_CHANGE" type="SENDER"/>
    <RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="srv_oksos_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_UCM_ACTION_NOTIFY" proc="srv_oksos_evt_hdlr"/>
#ifdef __MMI_ONE_KEY_SOS_DATA_TRANS__
    <RECEIVER id="EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE" proc="srv_oksos_transfer_connection_callback"/>
#endif /* __MMI_ONE_KEY_SOS_DATA_TRANS__ */

    <TIMER id="OKSOS_REQ_DELAY_TIMER"/>

    <!-- 
    ***************************************************************
    NVRAM Area
    ***************************************************************
    -->
    <CACHEDATA type="byte" id="NVRAM_SRV_OKSOS_KEY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Key count </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_SRV_OKSOS_NUM_INFO" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Used SOS Number Infomation </DESCRIPTION>
    </CACHEDATA>
</APP>
#endif
