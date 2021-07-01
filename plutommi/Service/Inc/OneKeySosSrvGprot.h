#ifndef SRV_ONE_KEY_SOS_GPROT_H
#define SRV_ONE_KEY_SOS_GPROT_H

#include "MMI_features.h"
#ifdef __MMI_ONE_KEY_SOS_SUPPORT__

#define __MMI_OKSOS_INTERNAL_ECC__

#include "MMIDataType.h"
#include "nvram_common_defs.h" // NVRAM_EF_OKSOS_INFO_TOTAL
#include "common_nvram_editor_data_item.h" // nvram_ef_oksos_info_struct

#ifdef __MMI_ONE_KEY_SOS_DATA_TRANS__
#include "custom_btcm_config.h" // srv_bt_cm_bt_addr
#endif /* __MMI_ONE_KEY_SOS_DATA_TRANS__ */

#define SRV_OKSOS_MAX_KEY_COUNT (NVRAM_EF_OKSOS_MAX_KEY_COUNT)
#define SRV_OKSOS_MAX_NUM_COUNT (NVRAM_EF_OKSOS_MAX_NUM_COUNT)
#define SRV_OKSOS_MAX_REC_COUNT (NVRAM_EF_OKSOS_INFO_TOTAL)
#define SRV_OKSOS_MAX_NUM_LEN (NVRAM_EF_OKSOS_MAX_NUM_LEN)
#define SRV_OKSOS_MAX_NAME_LEN (NVRAM_EF_OKSOS_MAX_NAME_LEN)

#define SRV_OKSOS_INVALIE_REC_ID 0xFFFF
#define SRV_OKSOS_MAX_WRITE_BUFF (512)
#define SRV_OKSOS_MAX_READ_CMD_LEN (20)

#define SRV_OKSOS_MODE_AUTO_LOOP (0)
#define SRV_OKSOS_MODE_MANUAL (1)

#define SRV_OKSOS_DEFAULT_LOOP_ATTEMPTS (3)

#define SRV_OKSOS_ERR_UNKNOWN_CMD        (0x01)
#define SRV_OKSOS_ERR_INVALID_IDX        (0x02)
#define SRV_OKSOS_ERR_INVALID_KEY_VALUE  (0x03)
#define SRV_OKSOS_ERR_INVALUE_VALUE_LEN  (0x04)
#define SRV_OKSOS_ERR_SOS_LIST_FULL      (0x05)
#define SRV_OKSOS_ERR_INVALID_PDU        (0x06)
#define SRV_OKSOS_ERR_UNKNOW_ERR         (0x07)

typedef enum
{
    SRV_OKSOS_RET_OK = 0,
    SRV_OKSOS_RET_INVALUE_PARA = 1,
    SRV_OKSOS_RET_EMPTY_NUM = 2,
    SRV_OKSOS_RET_EMPTY_LIST = 3,
    SRV_OKSOS_RET_INVALIE_TYPE = 4,
    SRV_OKSOS_RET_INVALID_NUM = 5,
    SRV_OKSOS_RET_INVALID_IDX = 6,
    SRV_OKSOS_RET_INVALID_KEY_VALUE = 7,
    SRV_OKSOS_RET_INVALID_KEY_COUNT = 8,
    SRV_OKSOS_RET_INVALID_MUL_LOAD = 9,
    SRV_OKSOS_RET_NO_REQ = 10,
    SRV_OKSOS_RET_SAVE_FAIL = 11,
    SRV_OKSOS_RET_LOAD_FAIL = 12,
    SRV_OKSOS_RET_PENDING = 13,
    SRV_OKSOS_RET_UNKNOWN = 14,
    SRV_OKSOS_RET_REC_NOT_FIND = 15,
    SRV_OKSOS_RET_REC_FULL = 16,
    SRV_OKSOS_RET_REC_EXIST = 17,
    SRV_OKSOS_RET_UCM_FAIL = 18,
    SRV_OKSOS_RET_UCM_RETRY = 19,
    SRV_OKSOS_RET_TRAN_INVALID_TYPE = 20,
    SRV_OKSOS_RET_TRAN_NO_VALUE = 21,
    SRV_OKSOS_RET_TRAN_NO_CONNECTION = 22,
    SRV_OKSOS_RET_KEY_SAME_COUNT = 23,
    SRV_OKSOS_RET_UCM_INTERCEPTED = 24,
    SRV_OKSOS_RET_SS_IGNORE = 25,
    SRV_OKSOS_RET_TOTAL
} srv_oksos_result_enum;


typedef enum
{
    SRV_OKSOS_TYPE_NONE = 0,
    SRV_OKSOS_TYPE_GSM_DIAL = 1,
    SRV_OKSOS_TYPE_TOTAL
} srv_oksos_type_enum;

typedef enum
{
    SRV_OKSOS_MODE_NONE,
    SRV_OKSOS_MODE_ALL,
    SRV_OKSOS_MODE_SELECTED,
    SRV_OKSOS_MODE_TOTAL
} srv_oksos_mode_enum;


typedef enum
{
    SRV_OKSOS_REQ_TYPE_NONE,
    SRV_OKSOS_REQ_TYPE_ACTION,
    SRV_OKSOS_REQ_TYPE_DATA_CTRL,
    SRV_OKSOS_REQ_TYPE_DATA_TRANS,
    SRV_OKSOS_REQ_TYPE_DATA_LOAD,
    SRV_OKSOS_REQ_TYPE_KEY_COUNT,
    SRV_OKSOS_REQ_TYPE_TOTAL
} srv_oksos_req_type;

typedef enum
{
    SRV_OKSOS_DREQ_TYPE_ADD,
    SRV_OKSOS_DREQ_TYPE_MODIFY,
    SRV_OKSOS_DREQ_TYPE_DELETE,
    SRV_OKSOS_DREQ_TYPE_TOTAL
} srv_oksos_data_req_type;

typedef enum
{
    SRV_OKSOS_LOAD_TYPE_ONE,
    SRV_OKSOS_LOAD_TYPE_ALL
} srv_oksos_load_req_type;

#ifdef __MMI_ONE_KEY_SOS_DATA_TRANS__
typedef enum
{
    SRV_OKSOS_TRAN_CMD_ERR = 0x11, /* Error response*/
    SRV_OKSOS_TRAN_CMD_SOS_IND = 0x12, /* SOS support indication */
    SRV_OKSOS_TRAN_CMD_READ_REQ = 0x03, /* read request */
    SRV_OKSOS_TRAN_CMD_READ_RSP = 0x13, /* read response */
    SRV_OKSOS_TRAN_CMD_WRITE_REQ = 0x04, /* write request */
    SRV_OKSOS_TRAN_CMD_WRITE_RSP = 0x14, /* write response */
} srv_oksos_transfer_cmd_type;
#endif /* __MMI_ONE_KEY_SOS_DATA_TRANS__ */

typedef enum
{
    SRV_OKSOS_VFLAG_NONE = 0,
    SRV_OKSOS_VFLAG_NUM = 1,
    SRV_OKSOS_VFLAG_NAME = 2,
    SRV_OKSOS_VFLAG_MODE = 3,
    SRV_OKSOS_VFLAG_TIMES = 4,
    SRV_OKSOS_VFLAG_TOTAL,
} srv_oksos_value_flag;

typedef enum
{
    MMI_KEY_VALUE_NONE,
    MMI_KEY_VALUE_1,
    MMI_KEY_VALUE_2,
    MMI_KEY_VALUE_3,
    MMI_KEY_VALUE_TOTAL
} srv_oksos_key_value_enum;

typedef void (*srv_oksos_proc_func) (srv_oksos_result_enum result, void* param);

typedef nvram_ef_oksos_info_struct srv_oksos_data_common_struct;

typedef struct
{
    srv_oksos_type_enum type;
    U8 index;
    U8 key_value;
    U32 attempts;
} srv_oksos_act_req_struct;


typedef struct
{
    srv_oksos_data_req_type dreq_type;
    U32 value_flag;
    srv_oksos_data_common_struct para;
} srv_oksos_data_req_strcut;


typedef struct
{
    srv_oksos_load_req_type load_type;
    U16 data_index;
    U16 data_count; // for SRV_OKSOS_LOAD_TYPE_ALL
    srv_oksos_data_common_struct* output_p;
} srv_oksos_data_load_req_strcut;

#ifdef __MMI_ONE_KEY_SOS_DATA_TRANS__
typedef struct
{
    U8 cmd_label;
    U8 key_value;
    U8 num_index;
    U8 write_type;
    U32 value_flag;
    srv_oksos_transfer_cmd_type tran_type;
    srv_oksos_result_enum result;
    srv_oksos_transfer_cmd_type err_cmd;
    srv_bt_cm_bt_addr bt_addr;
} srv_oksos_trans_cmd_req_struct;
#endif /* __MMI_ONE_KEY_SOS_DATA_TRANS__ */

typedef struct
{
    U8  key;
    U8  index;
    U8  mode;
    U8  attempts;
    U16  number[NVRAM_EF_OKSOS_MAX_NUM_LEN+1]; // ucs2
    U16  name[NVRAM_EF_OKSOS_MAX_NAME_LEN+1]; // ucs2
} srv_oksos_data_info_struct;

typedef struct
{
    U8 key_value;
    U8 attempts;
    U8 mode;
    U8 used_num_count;
} srv_oksos_key_info_struct;

typedef struct
{
    srv_oksos_req_type type;
    union
    {
        srv_oksos_act_req_struct act;
        srv_oksos_data_req_strcut data;
        srv_oksos_data_load_req_strcut load;
    #ifdef __MMI_ONE_KEY_SOS_DATA_TRANS__
        srv_oksos_trans_cmd_req_struct transfer;
    #endif /* __MMI_ONE_KEY_SOS_DATA_TRANS__ */
        U8 key;
    }para;
    srv_oksos_proc_func proc_func;
} srv_oksos_new_req_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_oksos_data_req_type type;
} srv_oksos_data_change_notify_struct;

extern void srv_oksos_init(void);
extern void srv_oksos_init_para(srv_oksos_new_req_struct* para);
extern srv_oksos_result_enum srv_oksos_request_new(srv_oksos_new_req_struct* new_req);
extern srv_oksos_result_enum srv_oksos_request_permit(srv_oksos_new_req_struct* new_req);
extern void srv_oksos_request_cancel(srv_oksos_req_type type);
extern U32 srv_oksos_query_num_list(srv_oksos_key_value_enum key, U32 index[]);
extern MMI_BOOL srv_oksos_is_valid_number(U16* ucs2_num);
extern srv_oksos_result_enum srv_oksos_query_info(U32 index, srv_oksos_data_info_struct* info);
extern srv_oksos_result_enum srv_oksos_query_key_info(srv_oksos_key_value_enum key, srv_oksos_key_info_struct* key_info);
extern MMI_BOOL srv_oksos_is_action_valid(srv_oksos_key_value_enum key, srv_oksos_type_enum act);
#ifdef __MMI_OKSOS_INTERNAL_ECC__
extern void srv_oksos_request_internal_ecc(void);
#endif /* __MMI_OKSOS_INTERNAL_ECC__ */
extern U8 srv_oksos_ut_handle(U8 index, kal_uint8* string);
#endif /* __MMI_ONE_KEY_SOS_SUPPORT__ */
#endif /* SRV_ONE_KEY_SOS_GPROT_H */
