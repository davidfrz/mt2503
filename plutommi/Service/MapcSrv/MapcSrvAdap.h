#ifndef __MAPC_SRV_ADAP_H__
#define __MAPC_SRV_ADAP_H__

#include "BtcmSrvGprot.h"
#ifdef __MMI_BT_MAP_CLIENT__
#include "MapSrvGprot.h"
#include "Bluetooth_map_struct.h"
#include "MapcSrv.h"

#define SRV_MAPC_ADP_MAX_CMD_LENGTH 40
#define MAP_MAX_HANDLE_STR_UCS2_LEN (BT_MAP_MAX_HANDLE_STR_LEN *2)
#define BT_MAP_ADAP_RECV_MESSAGE_FILE "z:\\@map\\pmr%d.vcf"
typedef enum
{
    SRV_MAPC_ADP_IDLE,
    
    SRV_MAPC_ADP_CONNECTING,
    SRV_MAPC_ADP_FOLDER_SETTING,
    SRV_MAPC_ADP_LIST_SIZE_GETTING,
    SRV_MAPC_ADP_LIST_GETTING,
    SRV_MAPC_ADP_MSG_GETTING,
    SRV_MAPC_ADP_MSG_STATUS_SETTING,
    SRV_MAPC_ADP_MSG_PUSHING,
}srv_mapc_adp_option_state;

typedef enum
{
    SRV_MAPC_ADP_CMD_SET_FOLDER = 1,
    SRV_MAPC_ADP_CMD_GET_LIST_SIZE,
    SRV_MAPC_ADP_CMD_GET_LISTING,
    SRV_MAPC_ADP_CMD_GET_MSG,
    SRV_MAPC_ADP_CMD_SET_STATUS,
    SRV_MAPC_ADP_CMD_PUSH_MSG,
    SRV_MAPC_ADP_CMD_EVENT_REPORT,
    SRV_MAPC_ADP_CMD_CONNECT,
    SRV_MAPC_ADP_CMD_DISCONNECT,
    SRV_MAPC_ADP_CMD_END
}srv_mapc_adp_cmd_type;


typedef struct
{
    srv_mapc_adp_option_state adp_state;
    MMI_BOOL is_spp_connected;
    MMI_BOOL is_map_by_spp_connected;
	MMI_BOOL is_bad_state;
    MapcAdpConnCallback conn_callback;
    char cmd[SRV_MAPC_ADP_MAX_CMD_LENGTH];	
}srv_mapc_adp_cntx_struct;


typedef struct
{
    srv_btmapc_folder_flag_enum flag;
    char* folder_name;
}srv_mapc_adp_set_folder_req_struct;

typedef struct
{
    char cmd_type[3];
    char para_num[3];
    char flag[3];
    char folder_name[BT_MAP_MAX_FOLDER_NAME_LEN + 2];
}srv_mapc_adp_set_folder_cmd;

typedef struct
{
    char cmd_type[3];
    char para_num[3];
    char list_size[4]; //support sync. sms max count is 100
    char offset[3];
    char max_sub_len[3];
    char folder_name[BT_MAP_MAX_FOLDER_NAME_LEN + 2];
}srv_mapc_adp_get_list_cmd;

typedef struct
{
    char cmd_type[3];
    char para_num[3];
    char handle[MAP_MAX_HANDLE_STR_UCS2_LEN + 2];
}srv_mapc_adp_get_msg_cmd;

typedef struct
{
    char cmd_type[3];
}srv_mapc_adp_push_msg_cmd;

typedef struct
{
    char cmd_type[3];
    char para_num[3];
    char status[3];
    char handle[MAP_MAX_HANDLE_STR_UCS2_LEN + 2];
}srv_mapc_adp_set_status_cmd;

typedef struct
{
    char cmd_type[3];
    char para_num[3];
}srv_mapc_adp_map_conn_cmd;


typedef void (*MapcAdpCallback) (void *);


#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
extern void srv_bt_mapc_adp_set_callback(MapcAdpCallback callback, srv_mapc_adp_cmd_type cmdType);

extern void srv_bt_mapc_adp_set_folder_req(U8 cntx_index, bt_mapc_set_folder_req_struct *req_data);
extern void srv_bt_mapc_adp_get_listing_req(U8 cntx_index, bt_mapc_get_message_listing_req_struct *req_data);
extern void srv_bt_mapc_adp_get_list_size_req(U8 cntx_index, bt_mapc_get_message_listing_size_req_struct *req_data);
extern void srv_bt_mapc_adp_get_msg_req(U8 cntx_index, bt_mapc_get_message_req_struct *req_data);
extern void srv_bt_mapc_adp_push_msg_req(U8 cntx_index, bt_mapc_push_message_req_struct *req_data);
extern void srv_bt_mapc_adp_set_status_req(U8 cntx_index, bt_mapc_set_message_status_req_struct *req_data);
#endif/*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
#endif /*__MMI_BT_MAP_CLIENT__*/
#endif /*__MAPC_SRV_ADAP_H__*/
