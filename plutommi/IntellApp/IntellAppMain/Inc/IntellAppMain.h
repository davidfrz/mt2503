#ifndef __INTELLMOBTERAPP_H__
#define __INTELLMOBTERAPP_H__
#if defined(__INTELL_MOB_TER_APP__)
#include "MMIDataType.h"

/*消息资源id*/
typedef enum
{
    EVT_ID_SRV_INTELLAPP_MSG_IND=APP_INTELL_BASE
    EVT_ID_SRV_INTELLAPP_MSG_MAX
}srv_intell_msg_id;

/*消息类型*/
typedef enum
{
    SRV_INTELLAPP_MSG_NONE=0,
    SRV_INTELLAPP_MSG_MSGSEND,
    SRV_INTSLLAPP_MSG_MAX
}srv_intsll_msg_type;

/*消息数据*/
typedef struct
{
    MMI_EVT_PARAM_HEADER
    U8 type;
}stu_intell_msg_data;

extern void intellapp();
#endif
#endif

/* 在这里新增的函数首先先在MainMenu中进行头函数调用
在本头文件中使用extern引用我们定义的函数,并在主函数goto_main_menu中调用
或者在后台函数（我会在后面写gps的时候加上TnT
执行完后执行return
写到这里按理来说可以在模拟器控制台输出intellapp()中的printf内容
（我电脑是amd的，不能安装ADS，死在第一步，注意如果测试这个，一定要使用英特尔cpu） */