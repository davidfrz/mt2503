
#include "mmi_features.h"

#if defined(__INTELL_MOB_TER_APP__) 
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_INTELL">
    <!-----Include Area------>
    <INCLUDE file="GlobalResDef.h,CustMenuRes.h,GlobalMenuItems.h"/>

    <!-----铃声资源-------->
    <AUDIO id="AUD_MY_MUSIC_ID" flag="MULTIBIN">CUST_ADO_PATH "\\\\IntellApp\\\\music.mp3"</AUDIO>

    <!-----定时器资源-------->
    <TIMER id="INTELLAPP_TIMER_ID"/>

    <!-----NV资源-------->
    <CACHEDATA type="byte" id="NVRAM_INTELLAPP_ID" restore_flag="TRUE">
        <DEFAULT_VALUE>[0X00]</DEFAULT_VALUE>
    </CACHEDATA>

    <!-----消息资源-------->
    <SENDER id="EVT_ID_SRV_INTELLAPP_MSG_IND" hfile="IntellAppMain.h"/>
    <RECEIVER id="EVT_ID_SRV_INTELLAPP_MSG_IND" proc="mmi_intell_msg_proc"/>

	<!-----屏幕资源-------->
    <SCREEN ID="SCR_ID_HELLO_WORLD"/>

</APP>

#endif 

