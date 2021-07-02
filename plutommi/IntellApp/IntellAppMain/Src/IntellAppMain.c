#if defined(__INTELL_MOB_TER_APP__)
#include "gui_themes.h"
void intellapp(void){
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

#endif