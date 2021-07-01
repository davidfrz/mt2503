#ifndef __BT_DEMO_MODE_SWITCH_H__
#define __BT_DEMO_MODE_SWITCH_H__

/* ---------------------------------------------------------------------------
* define
* ------------------------------------------------------------------------ */
#define MODE_SWITCH_MAX_APP_NUM 5
#define MODE_SWITCH_WORKING_BUF_LEN 128

typedef S32 (*app_start_f)(void);
typedef S32 (*app_stop_f)(void);
typedef void (*app_reactive_f)(void);

typedef enum
{
    BT_MODE_CENTRAL,
    BT_MODE_PERIPHERAL,
    BT_MODE_COMMON_SERVER,
    BT_MODE_MAX
} mode_enum;

typedef enum
{
    BT_MODE_SWITCH_POWERON,
    BT_MODE_SWITCH_POWEROFF,
    BT_MODE_SWITCH_CHANGE_MODE,
    BT_MODE_SWITCH_REACTIVE,
    BT_MODE_SWITCH_CONNECTED,
    BT_MODE_TONE_MAX
} mode_switch_tone_enum;

typedef enum
{
    BT_POWER_NORMAL,
    BT_POWER_SAVE,
    BT_POWER_MAX
} bt_power_save_enum;


typedef struct mode_switch_cntx_struct
{
    mode_enum mode;
    mode_enum last_mode;
    app_start_f start_cb[MODE_SWITCH_MAX_APP_NUM][BT_MODE_MAX];
    app_stop_f stop_cb[MODE_SWITCH_MAX_APP_NUM][BT_MODE_MAX];
    app_reactive_f reactive_cb[MODE_SWITCH_MAX_APP_NUM][BT_MODE_MAX];
    bt_power_save_enum power_strategy;
    S32 alive_time;
    bt_power_save_enum power_strategy_update;
    S32 alive_time_update;
    S32 is_init;
    S8 is_mode_switching;
} mode_switch_cntx_struct;

/* ---------------------------------------------------------------------------
* global function
* ------------------------------------------------------------------------ */
extern void mode_switch_init(void);
extern S32 mode_switch_register_app(mode_enum mode, app_start_f app_start_cb, app_stop_f app_stop_cb, app_reactive_f reactive_cb);
extern S32 mode_switch_deregister_app(mode_enum mode, 
                                    app_start_f app_start_cb, 
                                    app_stop_f app_stop_cb, 
                                    app_reactive_f reactive_cb);

extern void srv_sogps_adp_init();
extern void srv_sogps_adp_deinit();
extern void pxp_srv_app_power_on_to_init(void);
extern void pxp_srv_power_on_to_deinit(void);
extern void gatt_client_start(void);
extern S32 gatt_client_stop(void);
extern void gatt_client_reactive_handler(void);
extern void mode_switch_paly_tone(mode_switch_tone_enum pattern);
extern void gatt_client_send_data_to_toy(char* str);

#endif //__BT_DEMO_MODE_SWITCH_H__

