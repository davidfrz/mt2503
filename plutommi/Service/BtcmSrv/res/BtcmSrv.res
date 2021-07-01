<?xml version="1.0" encoding="UTF-8"?>

#include "MMI_features.h" 

<APP id="SRV_BTCM">
#ifdef __MMI_BT_SUPPORT__
    <CACHEDATA type="byte" id="BT_BQB_TEST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> BQB TEST flag </DESCRIPTION>
    </CACHEDATA>
#ifdef __MMI_BT_APK_SMART_INSTALL_SUPPORT__
    <CACHEDATA type="short" id="NVRAM_BT_OPP_PUSHED_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00,0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Bluetooth Opp Smart Install flag </DESCRIPTION>
    </CACHEDATA>
#endif

    <TIMER id="BT_CMD_GUARD_TIMER"/>
    <TIMER id="BT_POWER_OFF_GUARD_TIMER"/>
    <TIMER id="BT_RELEASE_ALL_CON_GUARD_TIMER"/>
    <TIMER id="BT_TEMP_VISIBLE_TIMER"/>
    <TIMER id="BT_FTPC_BROWSE_FILES_FAILED_TIMER"/>

    <!-- Event registration -->
    <RECEIVER id="EVT_ID_SRV_SETTING_UART_SETTING_CHANGED" proc="srv_bt_cm_uart_hdlr" />
#ifdef __DM_LAWMO_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="srv_bt_cm_lawmo_lock_ind_hdlr" />
#endif
#ifdef __MMI_HFP_SUPPORT__
#ifndef __MMI_BTBOX_NOLCD__
    <RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="btaud_ucm_notify_hdlr" />
    <RECEIVER id="EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND" proc="btaud_speech_notify_hdlr" />
#endif /* __MMI_BTBOX_NOLCD__ */
#endif

/* For smart tracker flight  mode */
#if defined(__IOT__) && defined(__MMI_TELEPHONY_SUPPORT__)
    <CACHEDATA type="byte" id="SRV_BT_IOT_POWER_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Bt power record </DESCRIPTION>
    </CACHEDATA>

    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_SWITCH_OTHER_NOTIFY" proc="srv_bt_switch_flight_mode"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_bt_switch_flight_mode"/>
#endif /* __IOT__ */
#endif
</APP>

