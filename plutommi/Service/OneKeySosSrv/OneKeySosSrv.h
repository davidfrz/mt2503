#ifndef SRV_ONE_KEY_SOS_PROT_H
#define SRV_ONE_KEY_SOS_PROT_H

#include "MMI_features.h"
#ifdef __MMI_ONE_KEY_SOS_SUPPORT__
#include "MMIDatatype.h"
#include "OneKeySosSrvGprot.h"
#include "mmi_frm_nvram_gprot.h" // DS_DOUBLE
#include "UcmSrvGprot.h" // srv_ucm_id_info_struct

#define SRV_OKSOS_MAX_USER (6)
#define SRV_OKSOS_REQ_DELAY_TIME (2000)

#define SRV_OKSOS_LOG(x)                            \
   {                                                    \
      MMI_TRACE(MMI_COMMON_TRC_G5_CALL, x);                 \
   }
#define SRV_OKSOS_LOG1(x, x1)                       \
   {                                                    \
      MMI_TRACE(MMI_COMMON_TRC_G5_CALL, x, x1);             \
   }
#define SRV_OKSOS_LOG2(x, x1, x2)                   \
   {                                                    \
      MMI_TRACE(MMI_COMMON_TRC_G5_CALL, x, x1, x2);         \
   }

#define SRV_OKSOS_LOG3(x, x1, x2, x3)               \
   {                                                    \
      MMI_TRACE(MMI_COMMON_TRC_G5_CALL, x, x1, x2, x3);     \
   }

#define srv_oksos_is_valid_index(idx) (idx < NVRAM_EF_OKSOS_INFO_TOTAL && (g_srv_oksos_p->data_info & (1 << idx)))

#define BT_NOTIFY_OKSOS_CMD "EXCD"
#define BT_NOTIFY_OKSOS_SENDER "onekeysos"
#define BT_NOTIFY_OKSOS_RECEIVER "mtk_onekeysos"

typedef enum
{
    SRV_OKSOS_PENDING_ON,
    SRV_OKSOS_PENDING_OFF
} srv_oksos_req_flag_enum;

typedef struct _oksos_node
{
    U32 delay_time;
    srv_oksos_new_req_struct* req_para;
    struct _oksos_node* prev;
    struct _oksos_node* next;
} srv_oksos_node_struct;

typedef struct
{
    srv_ucm_id_info_struct dialing_uid;
    srv_oksos_node_struct* pending_req[SRV_OKSOS_REQ_TYPE_TOTAL];
} srv_oksos_req_list_info;

typedef struct
{
    MMI_BOOL alloc;
    S32 srv_hd;
} srv_oksos_user_struct;

typedef struct
{
    srv_oksos_node_struct head;

} srv_oksos_act_cntx_struct;

typedef struct
{
    srv_oksos_node_struct req_list;
    srv_oksos_req_list_info req_info;

    U8  key_count;
    U8  key_mode;
    U8  nvram_info[DS_DOUBLE];

    U32 data_info;
    U32 data_count;
#ifdef __MMI_ONE_KEY_SOS_DATA_TRANS__
    srv_bt_cm_bt_addr bt_addr;
#endif /* __MMI_ONE_KEY_SOS_DATA_TRANS__ */
    srv_oksos_data_common_struct data[NVRAM_EF_OKSOS_INFO_TOTAL];
} srv_oksos_cntx_struct;

void srv_oksos_act_req(srv_oksos_act_req_struct* act_req);
srv_oksos_result_enum srv_oksos_act_dial_prmt(srv_oksos_act_req_struct* act_req);
srv_oksos_result_enum srv_oksos_act_prmt(srv_oksos_act_req_struct* act_req);
MMI_BOOL srv_oksos_act_is_same_call(srv_ucm_id_info_struct* src, srv_ucm_id_info_struct* dst);
void srv_oksos_act_cancel_req(void);
srv_oksos_result_enum srv_oksos_data_ctrl_req(srv_oksos_data_req_strcut* data_req);
void srv_oksos_data_load_req(srv_oksos_data_load_req_strcut* load_req);
void srv_oksos_key_set_count(U8 count);
MMI_BOOL srv_oksos_key_set_mode(U8 key, U8 mode);
void srv_oksos_transfer_req(srv_oksos_trans_cmd_req_struct* data_trans);
void srv_oksos_request_update_info(srv_oksos_req_flag_enum flag, srv_oksos_node_struct* req);
#endif /* __MMI_ONE_KEY_SOS_SUPPORT__ */
#endif /* SRV_ONE_KEY_SOS_PROT_H */
