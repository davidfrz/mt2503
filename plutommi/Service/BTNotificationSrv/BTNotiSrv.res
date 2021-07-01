#include "mmi_features.h"
#ifdef __MMI_BT_NOTI_SRV__
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_BT_NOTI">
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <!--Menu Item Area-->

    <!--Menu Tree Area-->


    <!------------------------------------------------------Other Resource---------------------------------------------------------->

    <!-----------------------------------------------Callback Manager Register------------------------------------------------------>
    <EVENT id="EVT_ID_SRV_BT_NOTI_NEW_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_DEL_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_ADD_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_CONNECTED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_DISCONNECTED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_REFRESH" type="SENDER"/>	
    <EVENT id="EVT_ID_SRV_BT_NOTI_POST_FSM" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_MISSED_CALL" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_NEW_SMS" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_SYNC_DEV" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_MAP_CONNECT_CNF" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_MAP_DISCONNECT_CNF" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_MAP_CMD_NOTIFY" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_BT_NOTI_CAP_CMD_NOTIFY" type="SENDER"/>

    <EVENT id="EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_BT_NOTI_UPDATE_TIME_NOTIFY" type="SENDER"/>
    


	<EVENT id="EVT_ID_SRV_BT_NOTI_MRE_INSTALL_NOTIFY" type="SENDER"/>

    /* for SOGP */
    <EVENT id="EVT_ID_SOGPS_CONNECT_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SOGPS_DISCONNECT_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SOGPS_READY_TO_READ" type="SENDER"/>
    <EVENT id="EVT_ID_SOGPS_READY_TO_WRITE" type="SENDER"/>   
    
        <EVENT id="EVT_ID_SRV_BT_NOTI_LISTMGR_REFRESH" type="SENDER"/>	 
    
    /* for BTD v3.0 */
    <TIMER id="TIMER_ID_BT_NOTI_WAIT_SYNC_CMD1"/>
    <TIMER id="TIMER_ID_BT_NOTI_WAIT_SYNC_CMD2"/>
    <TIMER id="TIMER_ID_BT_NOTI_WAIT_SYNC_CMD3"/>
    <TIMER id="TIMER_ID_BT_NOTI_WAIT_SYNC_CMD4"/>
    
    <TIMER id="TIMER_ID_BT_NOTI_RECEIVE_DATA_TIME_GAP1"/>
    <TIMER id="TIMER_ID_BT_NOTI_RECEIVE_DATA_TIME_GAP2"/>
    <TIMER id="TIMER_ID_BT_NOTI_RECEIVE_DATA_TIME_GAP3"/>
    <TIMER id="TIMER_ID_BT_NOTI_RECEIVE_DATA_TIME_GAP4"/>
    #if defined(__IOT__)

    <EVENT id="EVT_ID_SPPC_CONNECT_CNF" type="SENDER"/>
    <EVENT id="EVT_ID_SPPC_DISCONNECT_CNF" type="SENDER"/>	
	<EVENT id="EVT_ID_SPPC_READY_TO_READ" type="SENDER"/>
    <EVENT id="EVT_ID_SPPC_READY_TO_WRITE" type="SENDER"/>	
    
/*__MMI_BT_SPP_SERVER_MULTI_LINK_SUPPORT__*/
   <EVENT id="EVT_ID_SPPS_CONNECT_IND" type="SENDER"/>
   <EVENT id="EVT_ID_SPPS_DISCONNECT_CNF" type="SENDER"/>	
   <EVENT id="EVT_ID_SPPS_READY_TO_READ" type="SENDER"/>
   <EVENT id="EVT_ID_SPPS_READY_TO_WRITE" type="SENDER"/>	
   #endif
</APP>
#endif

