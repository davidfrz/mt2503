#if defined(__INTELL_MOB_TER_APP__)
#include "gui_themes.h"
#include "mmi_rp_app_intell_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "IntellAppMain.h"
#include "mmi_cb_mgr_gprot.h"


void intellapp_exit(void){

}

void intellapp(void){


    //入屏函数
    mmi_frm_scrn_enter(GRP_ID_ROOT,SCR_ID_INTELL_APP,intellapp_exit,intellapp,MMI_FRM_FULL_SCRN);



    // 这句话是在控制台输出，不能在实机或者实际模拟器输出
    // printf("Hello World");
    


    // 在实机或者实际模拟器输出
    // U为unsigned 那些符号 同理 S为signed
    // 8为8位 被8整除为一个字节
    // U8即为一个字节变量 char
    // U16就是shrot U32就是int 
    // 当然可以用int 这么样直接定义 不过...怎么说呢 
    // mtk还有一套kal_xx 的定义方式 慢慢看吧
    U8 str_asc[]="Hello World",str_ucs2[32]={0x00};

    gui_set_text_color(UI_COLOR_BLACK);// 设置颜色
    gui_move_text_cursor(10,10);// 设置显示坐标（10,10）
    gui_set_font(&MMI_large_font);// 设置字体

    mmi_asc_to_ucs2((CHAR*)str_asc,(CHAR*)str_ucs2);

    // gui_print_text("Hello World");
    gui_print_text(str_ucs2);
    // 这种转码也可以在字符串前面加上一个L
    // gui_print_text(L"Hello World!");

    gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH,UI_DEVICE_HEIGHT); // 如果带有屏幕测试（实机），必须加上这句话，刷新屏幕

    
}
/*发送消息*/
void msg_send(void){
    stu_intell_msg_data evt={0x00};

    /*发送消息*/
    MMI_FRM_INIT_EVENT(&evt,EVT_ID_SRV_INTELLAPP_MSG_IND);
    evt.type=SRV_INTELLAPP_MSG_MSGSEND;/*消息类型*/
    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct*)&evt);
    /*某个处理函数*/
}
/*消息处理函数*/
mmi_ret mmi_intell_msg_proc(mmi_event_struct *evt)
{
    stu_intell_msg_data *event=(stu_intell_msg_data*)evt;

    if(EVT_ID_SRV_INTELLAPP_MSG_IND == evt->evt_id)
    {
        if(SRV_INTELLAPP_MSG_MSGSEND == event->type)/*处理这个东西的函数*/
        {
            //可以打印字符
            //可以干啥干啥的
            //就是说 当执行了SRV_INTELLAPP_MSG_MSGSEND
            //这里定义后续处理
            //类似于触发事件
        }
    }
}
#endif