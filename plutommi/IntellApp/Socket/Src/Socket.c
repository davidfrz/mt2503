#include "mmi_features.h"

#if defined(__MMI_INTELL_SOCKET__)

/*头文件*/
#include "Socket.h"
#include "cbm_consts.h"
#include "app2soc_struct.h"
#include "soc_api.h"
#include "DtcntSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "cbm_api.h"

/*常量定义*/

/*全局变量定义*/
static stu_socket_data g_socket_data={0x00}; /*socket 数据*/

/*函数声明*/
static void mmi_socket_release(void);
static void mmi_socket_get_soc_addr_msg(sockaddr_struct *soc_addr,kal_char *server_addr);
static void mmi_socket_soc_notify_handle(void* msg);


/*内部静态函数*/
MMI_BOOL mmi_socket_get_online(void)
{
    return g_socket_data.online;
}

void mmi_socket_set_online(MMI_BOOL status)
{
    g_socket_data.online = status;
}

/*********************************************
 * mmi_socket_soc_send_data
 * func: socket 发送信息
 * para: void
 * return: void
 *********************************************/
static S32 mmi_socket_soc_send_data(void)
{
    /*本地变量*/
    S32 send_bytes=0;

    /*函数方法体*/
    if(g_socket_data.soc_id<0 || 0==g_socket_data.send_data_size)
    {
        return 0;
    }

    send_bytes = soc_send(g_socket_data.soc_id,g_socket_data.send_data_buff,g_socket_data.send_data_size,0);

    if(send_bytes>0)
    {
        if(NULL != g_socket_data.callback) /*发送成功*/
        {
            g_socket_data.callback(SOC_SEND_SUCCESS,&g_socket_data);
        }
    }
    else if(SOC_WOULDBLOCK == send_bytes)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND,
        mmi_socket_soc_notify_handle,MMI_TRUE);
    }
    else
    {
        if(NULL != g_socket_data.callback)
        {
            g_socket_data.callback(SOC_COMMON_ERROR,&g_socket_data);
        }
    }
    return send_bytes;
}

/*********************************************
 * mmi_socket_soc_recv_data
 * func: socket 接收信息
 * para: void
 * return: void
 *********************************************/
static S32 mmi_socket_soc_recv_data(void)
{
    /*本地变量*/
    S32 recv_bytes =-1;
    U8 *recv_buff_ptr = NULL,*temp_buff=NULL,*p1=NULL,*p2=NULL;

    /*函数方法体*/
    memset(g_socket_data.recv_data_buff,0x00,SOC_RECV_BUFFER_SIZE);
    g_socket_data.recv_data_size=0;
    recv_bytes=soc_recv(g_socket_data.soc_id,g_socket_data.recv_data_buff,SOC_RECV_BUFFER_SIZE,0);
    if(recv_bytes>0)
    {
        g_socket_data.recv_data_size=recv_bytes;
        if(NULL != g_socket_data.callback)
        {
            g_socket_data.callback(SOC_RECV_SUCCESS,&g_socket_data);
        }
    }
    else
    {
        if(SOC_WOULDBLOCK == recv_bytes)/*-2的时候*/
        {
            mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND,mmi_socket_soc_notify_handle,MMI_TRUE);

        }
        else
        {
            if(NULL != g_socket_data.callback)
            {
                g_socket_data.callback(SOC_COMMON_ERROR,&g_socket_data);
            }
        }
    }
    return recv_bytes;
}

/*********************************************
 * mmi_socket_soc_motify_handle
 * func: 信号的回调函数
 * para: msg--信号的那个指针
 * return: void
 *********************************************/
static void mmi_socket_soc_notify_handle(void* msg)
{
    /*本地变量*/
    app_soc_notify_ind_struct *soc_notify = (app_soc_notify_ind_struct*)msg;
    kal_int8 result = 0;
    /*函数方法体*/
    if(NULL==soc_notify)
    {
        return;
    }

    if(SOC_BEARER_FAIL == soc_notify->error_cause)
    {
        mmi_socket_release();
        return;
    }

    mmi_socket_set_online(MMI_TRUE);/*有数据发送-GPRS为激活状态*/
    
    /*收发数据*/
    switch(soc_notify->event_type)
    {
        case SOC_READ:
        {
            mmi_socket_soc_recv_data(); /*接收数据*/
            break;
        }
        case SOC_CONNECT:
        case SOC_WRITE:
        {
            mmi_socket_soc_send_data();/*发送数据*/
            break;
        }
        case SOC_CLOSE:
        {
            mmi_socket_release();
            break;
        }
        default:
        {
            break;
        }

    }
}

/*********************************************
 * mmi_socket_get_host_name_cb
 * func: socket通过dns得到当前服务器的ip地址的回调函数
 * para: msg--信号的那个指针
 * return: void
 *********************************************/
static void mmi_socket_get_host_name_cb(void *msg) /*注意对比示例代码*的位置*/
{
    /*本地变量*/
    kal_int32 result=0;
    app_soc_get_host_by_name_ind_struct* dns_ind=NULL;
    sockaddr_struct server_addr={0x00};

    /*函数方法体*/
    if(msg==NULL)
    {
        return;
    }
    dns_ind=(app_soc_get_host_by_name_ind_struct *)msg;
    mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND,(PsIntFuncPtr)mmi_socket_get_host_name_cb);
    
    mmi_socket_get_soc_addr_msg(&server_addr,NULL);
    if(dns_ind->result == KAL_TRUE)
    {
        memcpy((char *)&server_addr.addr,(char*)dns_ind->addr,dns_ind->addr_len);
        server_addr.addr_len=dns_ind->addr_len;
    }
    result=soc_connect(dns_ind->request_id,&server_addr);
    if(result==SOC_SUCCESS)/*直接发送数据*/
    {
        mmi_socket_soc_send_data();
        return;
    }
    else if(result==SOC_WOULDBLOCK)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND,
        mmi_socket_soc_notify_handle,MMI_TRUE);
        return;
    }
    else /*通信连接出现错误*/
    {
        if(NULL != g_socket_data.callback)
        {
            g_socket_data.callback(SOC_CONNECT_FAILED,&g_socket_data);
        }
        mmi_socket_release();
        return;
    }
}

/*********************************************
 * mmi_socket_get_account_id
 * func: 获取account_id
 * para: void
 * return: account_id
 *********************************************/
U32 mmi_socket_get_account_id(void)
{
    /*本地变量*/
    cbm_app_info_struct app_info={0x00};
    cbm_sim_id_enum sim=CBM_SIM_ID_TOTAL;

    /*函数方法体*/
    if(0 == g_socket_data.account_id)
    {
        switch(g_socket_data.sim_id)/*可按照有几张卡 写几次*/
        {
            case MMI_SIM1:
            {
                sim=CBM_SIM_ID_SIM1;
                break;
            }
            default:
            {
                return 0;
            }
        }

        app_info.app_icon_id=0;
        app_info.app_str_id=0;
        app_info.app_type=DTCNT_APPTYPE_BRW_HTTP|DTCNT_APPTYPE_MRE_WAP|DTCNT_APPTYPE_MRE_NET|DTCNT_APPTYPE_DEF;
        cbm_register_app_id_with_app_info(&app_info,(U8*)&g_socket_data.app_id);
        g_socket_data.account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID,
        sim,g_socket_data.app_id,MMI_FALSE);
    }
    return g_socket_data.account_id;
}

/*********************************************
 * mmi_socket_create
 * func: 创建socket
 * para: account_id
 * return: socket_id
 *********************************************/
static kal_int8 mmi_socket_create(const U32 account_id)
{
    /*本地变量*/
    U8 socket_opt = 1;
    kal_int8 soc_id = -1;
    /*函数方法体*/
    soc_id = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_MMI, account_id);
    if (soc_id < 0)
    {
        return SOC_INVAILD_ID;
    }
    socket_opt = KAL_TRUE;
    if (soc_setsockopt(soc_id, SOC_NBIO, &socket_opt, sizeof(socket_opt)) < 0)
    {
        return SOC_SET_OPT_ERROR;
    }
    socket_opt = SOC_READ | SOC_WRITE | SOC_CONNECT | SOC_CLOSE;
    if (soc_setsockopt(soc_id, SOC_ASYNC, &socket_opt, sizeof(socket_opt)) < 0)
    {
        return SOC_SET_OPT_ERROR;
    }
    return soc_id;
}

/*********************************************
 * mmi_socket_release
 * func: 释放socket
 * para: void
 * return: void
 *********************************************/
static void mmi_socket_release(void)
{
    /*本地变量*/

    /*函数方法体*/
    mmi_socket_set_online(MMI_FALSE);
    if(NULL != g_socket_data.callback)
    {
        g_socket_data.callback(SOC_CONNECT_RELEASE, &g_socket_data);
    }
    if(g_socket_data.soc_id >= 0)
    {
        soc_close(g_socket_data.soc_id); 
        g_socket_data.soc_id = -1;
        
    }   
    memset(g_socket_data.send_data_buff, 0x00, SOC_SEND_BUFFER_SIZE); 
    g_socket_data.send_data_size = 0;

    memset(g_socket_data.recv_data_buff, 0x00, SOC_RECV_BUFFER_SIZE); 
    g_socket_data.recv_data_size = 0;

}

/*********************************************
 * mmi_socket_get_soc_addr_msg
 * func: 获取服务器信息
 * para: soc_addr--服务器地址信息
 *       server_addr--服务器域名
 * return: MMI_FALSE/MMI_TRUE
 *********************************************/
static void mmi_socket_get_soc_addr_msg(sockaddr_struct *soc_addr, kal_char *server_addr)
{
    /*本地变量*/
    S16 error = 0;

    /*函数方法体*/
    if (NULL == soc_addr && NULL==server_addr)
    {
        return;
    }
    if(NULL != soc_addr)
    {
        soc_addr->sock_type = SOC_SOCK_STREAM;
        soc_addr->port = NETWORK_DEFAULT_SERVER_PORT;
    }
    if(NULL != server_addr)
    {
        strcpy((char*)server_addr, (char *)NETWORK_DEFAULT_SERVER_ADDR);
    }

    soc_addr->addr_len = 0x04;  //soc_htonl()
    /* 
      htonl()--"Host to Network Long"
      ntohl()--"Network to Host Long"
      htons()--"Host to Network Short"
      ntohs()--"Network to Host Short"
    */
    return;

}

/*********************************************
 * mmi_socket_set_send_content
 * func: 设置socket发送数据
 * para: send_data--发送数据的内容
 *       data_bytes--发送数据的字节个数
 * return: MMI_FALSE/MMI_TRUE
 *********************************************/
static MMI_BOOL mmi_socket_set_send_content(void *send_data, U32 data_bytes)
{
    /*本地变量*/

    /*函数方法体*/
    if(NULL==send_data || 0==data_bytes || data_bytes > SOC_SEND_BUFFER_SIZE) 
    {
        return MMI_FALSE;
    }
    memset(g_socket_data.send_data_buff, 0x00, SOC_SEND_BUFFER_SIZE); 
    memcpy(g_sockel_data.send_data_buff, send_data, data_bytes); 
    g_socket_data.send_data_size = data_bytes;

    return MMI_TRUE;

}

/*********************************************
 * mmi_socket_set_callback
 * func: 设置网络连接的回调函数
 * para: soc_cb--网络连接的回调函数
 * return: void
 *********************************************/
void mmi_socket_set_callback(soc_net_cb soc_cb)
{
    g_socket_data.callback = soc_cb;
}

/*********************************************
 * mmi_socket_send_data
 * func: 连接网络，与服务器进行数据交互
 * para: sim_id--联网的sim卡
 *       send_data--发送数据的内容
 *       data_bytes--发送数据的字节个数
 * return: enum_soc_state
 *********************************************/
enum_soc_state mmi_socket_send_data(mmi_sim_enum sim_id, void *send_data, U32 data_bytes)
{
    /*本地变量*/
    sockaddr_struct soc_addr = {0x00};
    kal_bool ip_validity = KAL_FALSE;
    S32 result = 0;
    kal_char server_addr[128]={0x00};

    /*函数方法体*/
    if(NULL==send_data || 0 == data_bytes)
    {
        retum SOC_COMMON_ERROR;
    }

    g_socket_data.sim_id = sim_id;

    if(g_socket_data.soc_id >= 0) /*soc id 没有被释放，直接发送数据*/
    {
        if(MMI_FALSE == mmi_socket_set_send_content(send_data, data_bytes))
        /*准备要发送的数据*/
        {
            return SOC_CONNECT_SUCCESS;
        }
        result = mmi_socket_soc_send_data();
        
        if(result < 0)
        {
            mmi_socket_release();
        }
        else
        {
            return SOC_CONNECT_SUCCESS;
        }
    } 

    mmi_socket_get_soc_addr_msg(&soc_addr, server_addr);

    g_socket_data.account_id = mmi_socket_get_account_id(); /*第 1 步： 获取 account id*/ 
    g_socket_data.soc_id=mmi_socket_create(g_socket_data.account_id ); /*第 2 步：创建 socket id*/ 

    if(g_socket_data.soc_id < 0)
    {
        if(NULL != g_socket_data.callback)
        {
            g_socket_data.callback(SOC_COMMON_ERROR, &g_socket_data);
        }
        mmi_socket_release();
        return SOC_INVAILD_ID;
    }

    if(MMI_FALSE == mmi_socket_set_send_content(send_data, data_bytes))/* 准备要发送的数据 */  
    {
        return SOC_CONNECT_SUCCESS;
    }

    /*第3部：建立连接*/
    if(soc_ip_check(server_addr, soc_addr.addr, &ip_validity)==KAL_FALSE || KAL_FALSE==ip_validity)
    {
        result = soc_gethostbyname(KAL_FALSE, MOD_MMI, g_socket_data.soc_id, server_addr,
         (kal_uint8*) soc_addr.addr, (kal_uint8 *)&soc_addr.addr_len, 0, g_socket_data.account_id);
        if(SOC_SUCCESS != result)
        {
            if (result == SOC_WOULDBLOCK)
            {
                mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, 
                (PsIntFuncPtr)mmi_socket_get_host_name_cb, TRUE);
                return SOC_CREATE_SUCCESS;
            }
            else/*连接出错，释放socket*/
            {
                if(NULL != g_socket_data.callback)
                {
                    g_socket_data.callback(SOC_COMMON_ERROR, &g_socket_data);
                }
                mmi_socket_release();
                return SOC_GET_HOST_ERROR;
            }
        }
    }
    result = soc_connect(g_socket_data.soc_id, &soc_addr);/*连接网络*/ 
    if(result==SOC_SUCCESS)/*连接成功或已经连接，就直接发送数据*/
    {
        mmi_socket_soc_send_data();
        return SOC_CONNECT_SUCCESS;
    }
    else if (SOC_WOULDBLOCK == result)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, mmi_socket_soc_notify_handle, MMI_TRUE);
        return SOC_CONNECT_SUCCESS;
    }
    else 
    {
        if(NULL != g_socket_data.caliback)/*连接出错，释放 socket*/
        {
            g_socket_data.callback(SOC_COMMON_ERROR, &g_socket_data);
        }
        mmi_socket_release();
    }
    return SOC_CONNECT_FAILED;

}

/*********************************************
 * socket_socket_init
 * func: 初始化g_socket_data数组
 * para: void
 * return: void
 *********************************************/
void socket_socket_init(void)
{

    memset(&g_socket_data, 0x00, sizeof(g_socket_data)); 
    g_socket_data.soc_id = -1;
    g_socket_data.sim_id =	1;

}

#endif
