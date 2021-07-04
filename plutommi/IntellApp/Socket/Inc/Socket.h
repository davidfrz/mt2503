#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "MMI_features.h"

#if defined(__MMI_INTELL_SOCKET__)

/*头文件*/

#include "soc_api.h"
#include "MMIDataType.h"
#include "gui.h"
#include "nvram_user_defs.h"
#include "ssl_api.h"

/*宏定义*/

#define NETWORK_DEFAULT_SERVER_ADDR "192.168.0.174"
#define NETWORK_DEFAULT_SERVER_PORT 8080

#define HTTP_GET_DATA_FORMAT  "GET %s%s HTTP/1.1\r\nHost:%s:%d\r\nAccept:*/*\r\nConnection:close\r\nUser-Agent:%s\r\n\r\n"
#define HTTP_POST_DATA_FORMAT "POST %s HTTP/1.1\r\nHost:%s:%d\r\nAccept:*/*\r\nConnection:close\r\nUser-Agent:%s\r\nContent-Length:%d\r\n\r\n%s"
#define SOC_SEND_BUFFER_SIZE       (512)
#define SOC_RECV_BUFFER_SIZE       (512)

/*数据类型*/

/*socket 执行状态*/
typedef enum{
    SOC_SUCCESS_STATE_START = 0,
    SOC_CREATE_SUCCESS,
    SOC_CONNECT_SUCCESS,
    SOC_SEND_SUCCESS,
    SOC_RECV_SUCCESS,
    SOC_CONNECT_RELEASE,

    SOC_ERROR_STATE_START = SOC_SUCCESS_STATE_START,
    SOC_COMMON_ERROR = -1
    SOC_INVAILD_ID = -2,
    SOC_SET_OPT_ERROR = -3,
    SOC_GET_HOST_ERROR = -4, /*域名解析错误*/
    SOC_CONNECT_FAILED = -5, /*服务器连接错误*/
}enum_soc_state;

typedef void (*soc_net_cb)(enum_soc_state state,void *soc_data);

/*数据内容定义结构体*/
typedef struct __stu_network_soc{
    kal_int8 soc_id;
    mmi_sim_enum sim_id;
    soc_net_cb callback;
    MMI_BOOL online;
    U32 account_id;
    U32 app_id;

    U8 send_data_buff[SOC_SEND_BUFFER_SIZE];
    U32 send_data_size;
    U8 recv_data_buff[SOC_RECV_BUFFER_SIZE];
    U32 recv_data_size;
}stu_socket_data;


/*函数声明*/
/*********************************************
 * mmi_socket_set_callback
 * func: 设置连接的回调函数
 * para: soc_cb
 * return: void
 *********************************************/
extern void mmi_socket_set_callback(soc_net_cb soc_cb);

/*********************************************
 * mmi_socket_send_data
 * func: 联网，与服务器进行通信
 * para: sim_id--    联网的sim卡
 *       send_data-- 发送的数据内容
 *       data_bytes--发送的内容的字节个数
 * return: enum_soc_state 枚举
 *********************************************/
extern enum_soc_state mmi_socket_send_data(mmi_sim_enum sim_id, void *send_data, U32 data_bytes);

/*********************************************
 * socket_socket_init
 * func: 初始化g_socket_data
 * para: void
 * return: void
 *********************************************/
extern void socket_socket_init(void);

#endif
#endif /*__SOCKET_H__*/