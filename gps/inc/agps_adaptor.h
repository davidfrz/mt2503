#ifndef _AGPS_ADAPTOR_
#define _AGPS_ADAPTOR_

#ifdef __AGPS_SUPPORT__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "stack_types.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "custom_util.h"
#include "stack_init.h"
#include "stack_ltlcom.h"
#include "intrCtrl.h"
#include "kal_trace.h"
#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"         /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "dcl.h"

#include "stack_msgs.h"
#include "app_ltlcom.h"     /* Task message communiction */
#include "stdlib.h"         /*math lib such as atof*/
#include "math.h"          /*math lib for log()*/
#include "stdio.h"         /*stdio lib*/
#include "kal_trace.h"      /* kal_trace() prototype */
#include "dcl.h"         /*rtc to get time*/
#include "gps_main.h"
#include "gps_struct.h"
#include "gps_trc.h"
#include "gps_uart_hdlr.h"
#include "gps_adaptor.h"
#include "mtk_gps_task.h"
#include "mtk_gps_type.h" 


#if defined(__AGPS_SUPPORT__)
#include "gps2lcsp_enum.h"
#include "gps2lcsp_struct.h"
#include "agps_struct.h"
#include "gps_agps_process.h"
#include "uagps_cp_gps_struct.h"
#endif

//#include "mdi_agps.h"
//#include "EngineerModeAGPSlogGprot.h"
#include "gps_common.h"
#include "string.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "tst_sap.h"
#include "epodownload.h"
#include "mtk_gps.h"

#include "supl2mmi_enums.h"
#include "supl2mmi_struct.h"
#include "cbm_api.h"
#include "custom_data_account.h"
#include "cbm_consts.h"
#include "app_str.h"


#include "wps_struct.h"
#include "kal_public_defs.h"
#include "cbm_api.h"
#include "wap_cmmn_utils.h"
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "stdlib.h"  
#include "kal_trace.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "ModeSwitchSrvGprot.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include <time.h>
#include "nvram_interface.h"
#include "nvram_data_items.h"
#include "tst_sap.h"

#include "agps_setting.h"
#include "nvram_interface.h"
#include "mmi_gps_nvram_def.h"

extern MMI_BOOL srv_sim_ctrl_get_home_plmn(mmi_sim_enum sim, CHAR *out_plmn_buffer, U32 buffer_size);


#define GPSADAPTOR_AGPS_MAX_PROFILE_NAME_LEN         64
#define GPSADAPTOR_AGPS_MAX_PROFILE_ADDR_LEN         64
#define GPSADAPTOR_AGPS_SUPL_OTA_HASH_LEN             16

#define GPSADAPTOR_AGPS_MAX_PLMN_LEN (6+1)
typedef enum
{
    GPSADAPTOR_AGPS_SIM_NONE = 0, /* No bit-wise operation for none case */
    GPSADAPTOR_AGPS_SIM1 = 0x0001,
    GPSADAPTOR_AGPS_SIM2 = 0x0002,
    GPSADAPTOR_AGPS_SIM3 = 0x0004,
    GPSADAPTOR_AGPS_SIM4 = 0x0008,
    GPSADAPTOR_AGPS_SIM_END_OF_ENUM
}gpsadaptor_agps_sim_enum;


typedef enum
{
    GPSADAPTOR_AGPS_STATE_TERMINATE,
    GPSADAPTOR_AGPS_STATE_START,
    GPSADAPTOR_AGPS_STATE_ACTIVITATE,
    GPSADAPTOR_AGPS_STATE_WAIT_CNF,
    GPSADAPTOR_AGPS_STATE_WORKING,
    GPSADAPTOR_AGPS_STATE_STAND_BY,
    GPSADAPTOR_AGPS_STATE_WAIT_POS,
    GPSADAPTOR_AGPS_STATE_ABORT,
    GPSADAPTOR_AGPS_STATE_SET_WORK_MODE,
    GPSADAPTOR_AGPS_STATE_GPS_INIT,
    GPSADAPTOR_AGPS_STATE_PUSH_WAIT,
    GPSADAPTOR_AGPS_STATE_NI_ERROR,
    GPSADAPTOR_AGPS_STATE_WAIT_RSP,
    GPSADAPTOR_AGPS_STATE_END
} gpsadaptor_agps_state_enum;

typedef enum
{
    GPSADAPTOR_AGPS_START_MODE_NI,
    GPSADAPTOR_AGPS_START_MODE_SI,
    GPSADAPTOR_AGPS_START_MODE_NORMAL,
    GPSADAPTOR_AGPS_START_MODE_END
} gpsadaptor_agps_start_mode_enum;
typedef enum
{
    GPSADAPTOR_AGPS_WORK_MODE_MA,
    GPSADAPTOR_AGPS_WORK_MODE_MB,
    GPSADAPTOR_AGPS_WORK_MODE_NORMAL,
    GPSADAPTOR_AGPS_WORK_NO_WORK,
    GPSADAPTOR_AGPS_WORK_MODE_END
} gpsadaptor_agps_work_mode_enum;
typedef enum
{
    GPSADAPTOR_AGPS_UP_MOLR_PREF_MB = 0,
    GPSADAPTOR_AGPS_UP_MOLR_PREF_MA,
    GPSADAPTOR_AGPS_UP_MOLR_PREF_NONE,
    GPSADAPTOR_AGPS_UP_MOLR_MB_ONLY,
    GPSADAPTOR_AGPS_UP_MOLR_MA_ONLY,
    GPSADAPTOR_AGPS_UP_MOLR_END
} gpsadaptor_agps_up_molr_enum;
typedef enum
{
    GPSADAPTOR_GPS_PARSER_P_VERSION = 0,
    GPSADAPTOR_GPS_PARSER_P_GPS_MODE_SWITCH_OK,
    GPSADAPTOR_GPS_PARSER_P_SYSTEM_START_OK,
    GPSADAPTOR_GPS_PARSER_P_INTERNAL_VERSION,
    GPSADAPTOR_GPS_PARSER_P_GPS_FIXED,
    GPSADAPTOR_GPS_PARSER_P_GPS_FIXED_AND_TIME_OK,
    GPSADAPTOR_GPS_PARSER_P_END
} gpsadaptor_gps_parser_p_info_enum;
typedef enum
{
    GPSADAPTOR_AGPS_RESULT_SUCCESS = 0,
    GPSADAPTOR_AGPS_ALLOC_MEMORY_FAILURE=1,
    GPSADAPTOR_AGPS_NETWORK_ACCOUNT_FAILURE=2,
    GPSADAPTOR_AGPS_HAVE_TERMINATED=3,
    GPSADAPTOR_AGPS_BEING_ABORT=4,
    GPSADAPTOR_AGPS_GET_MCCMNC=5,
    GPSADAPTOR_AGPS_STATE_MACHINE_WRONG=6,
    GPSADAPTOR_AGPS_RESULT_END
} gpsadaptor_agps_result_enum;
typedef enum
{
    GPSADAPTOR_AGPS_SETTING_PREFER_SIM_NO1 = 0,
    GPSADAPTOR_AGPS_SETTING_PREFER_SIM_NO2,
    GPSADAPTOR_AGPS_SETTING_PREFER_SIM_NO3,
    GPSADAPTOR_AGPS_SETTING_PREFER_SIM_NO4,
    GPSADAPTOR_AGPS_SETTING_PREFER_SIM_NO5,
    GPSADAPTOR_AGPS_SETTING_PERFER_SIM_END,
    GPSADAPTOR_AGPS_SETTING_PREFER_SIM_ALWAYS_ASK
} gpsadaptor_agps_setting_prefer_sim_enum;
typedef enum
{
    GPSADAPTOR_AGPS_UP_PAYLOAD_BOTH = 0,
    GPSADAPTOR_AGPS_UP_PAYLOAD_RRLP,
    GPSADAPTOR_AGPS_UP_PAYLOAD_RRC,
    GPSADAPTOR_AGPS_UP_PAYLOAD_END
} gpsadaptor_agps_up_payload_enum;


typedef struct
{
    kal_int8 name[GPSADAPTOR_AGPS_MAX_PROFILE_NAME_LEN];
    kal_int8 addr[GPSADAPTOR_AGPS_MAX_PROFILE_ADDR_LEN];
    kal_uint32 port;
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    kal_uint8 nap_id[GPSADAPTOR_AGPS_SUPL_OTA_HASH_LEN];
    kal_uint8 provurl[GPSADAPTOR_AGPS_SUPL_OTA_HASH_LEN];
#endif
}gpsadaptor_agps_profile_struct;

typedef struct{
        kal_uint8 payload;
        kal_uint8 molr_prefer;
        kal_bool  use_tls;
        kal_uint16 ut_timer;
}gpsadaptor_agps_up_setting_struct;

typedef struct
{
    kal_uint8   horacc;                         /* horizontal accuracy */
    kal_bool    veracc_used;                    /* if vertical accuracy exist */
    kal_uint8   veracc;                         /* vertical accuracy */
    kal_bool    maxLocAge_used;                 /* if Maximun Location Age exist */
    kal_uint16  maxLocAge;                      /* Maximun Location Age */
    kal_bool    delay_used;                     /* if Delay exist */
    kal_uint8   delay;                          /* Delay */
} gpsadaptor_agps_qop_struct;


typedef struct 
{
    kal_uint32  latitude;         /*latitude */
    kal_bool    sign_latitude;    /* true: SOUTH, false: NORTH */
    kal_int32   longtitude;       /* N2, encoded longtitude with 2's complement */
    kal_bool    sign_altitude;    /* true: DEPTH, false: HEIGHT */
    kal_uint16  altitude;         /* no encoding, unit in meter */
    kal_uint16  unc_major;        /* K1, encoded r1 */
    kal_uint16  unc_minor;        /* K2, encoded r2 */
    kal_uint16  unc_bear;         /* N3, encoded a = 2N3, Bearing of semi-major axis (degrees)*/
    kal_uint16  unc_vert;         /* K3, encode r3, vertical uncertain */
    kal_uint8   confidence;       /* %, The confidence by which the position of a target 
                                  entity is known to be within the shape description, 
                                  expressed as a percentage. [0 ~ 100] (%)*/
    kal_int32   h_speed;          /*horizontal speed*/
    kal_uint16  bearing;          /*Direction of the horizontal speed*/
    kal_uint32  gps_week;
    kal_uint32  tow;
} gpsadaptor_agps_set_pos_struct;


typedef struct
{
	kal_int8 req_id;
	kal_uint8 app_id;
	kal_uint32 data_account;

    gpsadaptor_agps_state_enum state;
	kal_bool agps_on_off;
	gpsadaptor_agps_start_mode_enum start_mode;
	gpsadaptor_agps_work_mode_enum work_mode;
	kal_bool need_retry;
	kal_bool is_retrying;
	gpsadaptor_agps_setting_prefer_sim_enum sim;
	#ifdef __IOT_CUSTOMIZE__
	kal_bool   agps_supl_enable;
	kal_int8   agps_supl_name[64];
    kal_uint32 agps_supl_port;
    kal_bool   agps_tls_en;
	kal_uint32 account_id;
	#endif
	void (*gps_uart_p_callback)(gpsadaptor_gps_parser_p_info_enum type);
	gpsadaptor_agps_qop_struct qop;
}gpsadaptor_agps_manager_context_struct;


#ifdef __IOT_CUSTOMIZE__

void agps_adaptor_set_config(MMI_BOOL supl_en, 
                        U8 *supl_name,
                        U16 supl_port,
                        MMI_BOOL use_tls);

kal_bool agps_adaptor_get_supl_enable(void);

kal_uint8 agps_adaptor_get_supl_name_lens(void);

void agps_adaptor_get_supl_name(U8 *supl_name);

kal_uint16 agps_adaptor_get_supl_port(void);

kal_bool agps_adaptor_get_supl_use_tls(void);

void agps_adaptor_set_accout_id(kal_uint32 account_id);
#endif

#endif

#endif
