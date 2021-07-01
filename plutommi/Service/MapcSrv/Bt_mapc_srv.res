#include "MMI_features.h"
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)
<APP id="SRV_BT_MAPC">

    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
    
    <TIMER id="BT_MAC_SRV_TIMER_ID"/>
    <RECEIVER id="EVT_ID_SRV_BT_NOTI_MAP_CONNECT_CNF" proc="srv_bt_mapc_adp_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_BT_NOTI_MAP_DISCONNECT_CNF" proc="srv_bt_mapc_adp_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_BT_NOTI_MAP_CMD_NOTIFY" proc="srv_bt_mapc_adp_event_hdlr"/>
</APP>
#endif/*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
