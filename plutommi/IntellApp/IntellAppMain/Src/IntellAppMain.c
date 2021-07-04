#if defined(__INTELL_MOB_TER_APP__)
#include "gui_themes.h"
#include "mmi_rp_app_intell_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "IntellAppMain.h"
#include "mmi_cb_mgr_gprot.h"
#include "nvram_user_defs.h"
#include "SmsSrvGprot.h"
#include "Socket.h"

/*下面所有的成块函数都可以直接放在mainmenu.c 中的 
goto_main_menu中运行，当然要用一个集成SetKey*/


/*定时器*/
void mmi_intell_timer_handle(void)
{
    /*这个块中添加你想要的定时完成的代码*/

}

void mmi_send_sms_callback(srv_sms_callback_struct* callback_data)
{
    kal_prompt_trace(MOD_XDM,"--%d(%d)--%s--",__LINE__,callback_data->result,__FILE__);

}
/*发送短信 调用这个函数*/
void mmi_intell_send_sms(void)
{
    srv_sms_send_ucs2_text_msg(L"hello world",L"13087850311",SRV_SMS_SIM_1,mmi_send_sms_callback,NULL);
}




/*存储简单数据-NVRAM*/
/*把这个函数放在想记录的地方*/
void mmi_intell_nvram(void){
    S16 error = 0;
    U8 simple_nvram = 0;
    stu_intell_nvram nvram_date={0x00};
    
    ReadValue(NVRAM_INTELLAPP_ID,&simple_nvram,DS_BYTE,&error);/*读NV*/
    simple_nvram += 1;
    WriteValue(NVRAM_INTELLAPP_ID,&simple_nvram,DS_BYTE,&error);/*写NV*/

    /*复杂结构读写*/
    ReadRecord(NVRAM_EF_INTELL_LID,1,&nvram_date,NVRAM_EF_INTELL_SIZE,%error);
    nvram_date.xxx_count += 1;
    WriteRecord(NVRAM_EF_INTELL_LID,1,&nvram_date,NVRAM_EF_INTELL_SIZE,%error);


}


/*创建删除文件夹*/
void mtk_intell_filemanager(void){
    WCHAR path[64]={0x00},file_name[64]={0x00};
    FS_HANDLE file_handle = NULL;
    U32 write_size=0,read_size=0;
    U8 file_content[128]={0x00};

    kai_wsprintf((WCHAR*)path,"%c:\\%w",SRV_FMGR_PUBLIC_DRV,L"newDir");
    FS_CreateDir(path);/*创建文件夹*/
    FS_RemoveDir(path);/*删除文件夹*/

    kai_wsprintf((WCHAR*)file_name,"%c:\\intell_file.txt",SRV_FMGR_PUBLIC_DRV);
    file_handle=FS_OPEN(file_name,FS_READ_WRITE|FS_CREATE);/*打开文件夹*/

    sprintf((char*)file_content,"mtk intell filemanager")/*在txt中要写入的话*/
    FS_Write(file_handle,file_content,strlen(file_content),&write_size)/*写文件*/

    memset(file_content,0x00,sizeof(file_content));
    /*改变文件指针位置*/
    FS_Seek(file_handle,0,FS_FILE_BEGIN);/*这样是指向文件开头，把begin改为end，就是追加内容了*/
    FS_Read(file_handle,file_content,sizeof(file_content),&read_size);/*读文件*/

    FS_Close(file_handle);/*关闭文件*/
}

/*播放音乐，铃声*/
void mmi_intell_audio_play(void){
    /*----------------------------------*/
    /*本地变量                          */
    /*----------------------------------*/
    mdi_result play_result=MDI_AUDIO_FAIL;
    U32 audio_len=0;
    U8 *audio_data=NULL,audio_type=0;


    /*----------------------------------*/
    /*代码方法体                          */
    /*----------------------------------*/
    audio_data = get_audio(AUD_MY_MUSIC_ID,&audio_type,&audio_len);
    play_result = mdi_audio_play_string_with_vol_path(
        (void*)audio_data,
        audio_len,
        audio_type,
        DEVICE_AUDIO_PLAY_ONCE,
        NULL,
        NULL,
        MDI_AUD_VOL_MUTE(MDI_AUD_VOL_6),
        MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER_BOTH)
    );
}

void intellapp_exit(void){
    mdi_audio_stop_all();
    gui_cancel_timer(mmi_intell_timer handle);

    /*对应一直调用定时器*/
    if(MMI_TRUE==IsMyTimerExist(INTELLAPP_TIMER_ID))/* 判断定时器状态*/
    {
        StopTimer(INTELLAPP_TIMER_ID);/* 停止定时器 */
    }
}

void intellapp(void){


    //入屏函数
    mmi_frm_scrn_enter(GRP_ID_ROOT,SCR_ID_INTELL_APP,intellapp_exit,intellapp,MMI_FRM_FULL_SCRN);

    gui_start_timer(5000,mmi_intell_timer_handle); /*这个是只调用一次*/
    /*5秒钟之后操作这个定义的函数*/
    /*加一句让它停止的按键*/

    // 这句话是在控制台输出，不能在实机或者实际模拟器输出
    // printf("Hello World");
    
    /*播放背景音乐*/
    //mmi_intell_audio_play();

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

    /*这里可以控制按键来实现发送短信*/

    /*定时器放在函数最后，可以一直调用*/
    StartTimer(INTELLAPP_TIMER_ID,500,mmi_intell_timer_handle)/*每隔0.5秒调用一次*/

    
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