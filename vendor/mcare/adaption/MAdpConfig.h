#ifndef _madpconfig_h
#define _madpconfig_h

#ifdef __cplusplus   
extern "C"{   
#endif // __cplusplus

#include "MAdpType.h"


//[some features for customize]
//__CFG_YES__,__CFG_NO__
#ifdef __MCARE_OVERSEA__
#define MCR_REGION_OVERSEA  __CFG_YES__ 
#else
#define MCR_REGION_OVERSEA  __CFG_NO__ 
#endif

//MTK Version
#define MCR_MTK_VER			MTK_VER_1210

//////////////////////////////////////////////////////////////////////////
/////////////////////////�̻�ROM����////////////////////
//////////////////////////////////////////////////////////////////////////
//���ز�
#define MCR_USE_ROM_LOADEDLAYER		__CFG_TMZ__

//QB
#if MCR_REGION_OVERSEA == __CFG_YES__
#define MCR_USE_ROM_QQB				__CFG_TMC__
#else
#define MCR_USE_ROM_QQB				__CFG_NONE__
#endif

//QQ
#define MCR_USE_ROM_QQ				__CFG_NONE__



//////////////////////////////////////////////////////////////////////////
/////////////////////////�ڴ�����////////////////////
//////////////////////////////////////////////////////////////////////////
#if ((MCR_MTK_VER >= MTK_VER_1112) && (defined(__COSMOS_MMI_PACKAGE__))) //by purple

#if (MCR_MTK_VER >= MTK_VER_1210)
//���ڴ��ڴ����� - media��asm��static
#define MCR_MEM_MAIN			MCR_MEMTYPE_ASM

//���ı����ڴ��ڴ����� - media��asm��static��������ز������Լ������ڴ棩
#define MCR_MEM_KERNRESER		MCR_MEMTYPE_ASM

//Ӧ�ñ����ڴ��ڴ����� - media��asm��static(����QQ�һ��ڴ�)
#define MCR_MEM_APPRESER		MCR_MEMTYPE_ASM

#else
//���ڴ��ڴ����� - media��asm��static
#define MCR_MEM_MAIN			MCR_MEMTYPE_STATIC

//���ı����ڴ��ڴ����� - media��asm��static��������ز������Լ������ڴ棩
#define MCR_MEM_KERNRESER		MCR_MEMTYPE_STATIC

//Ӧ�ñ����ڴ��ڴ����� - media��asm��static(����QQ�һ��ڴ�)
#define MCR_MEM_APPRESER		MCR_MEMTYPE_STATIC
#endif

#else

#if (MCR_MTK_VER >= MTK_VER_1210)
//���ڴ��ڴ����� - media��asm��static
#define MCR_MEM_MAIN			MCR_MEMTYPE_ASM

//���ı����ڴ��ڴ����� - media��asm��static��������ز������Լ������ڴ棩
#define MCR_MEM_KERNRESER		MCR_MEMTYPE_ASM

//Ӧ�ñ����ڴ��ڴ����� - media��asm��static(����QQ�һ��ڴ�)
#define MCR_MEM_APPRESER		MCR_MEMTYPE_ASM

#else
//���ڴ��ڴ����� - media��asm��static
#define MCR_MEM_MAIN			MCR_MEMTYPE_MEDIA

//���ı����ڴ��ڴ����� - media��asm��static��������ز������Լ������ڴ棩
#define MCR_MEM_KERNRESER		MCR_MEMTYPE_MEDIA

//Ӧ�ñ����ڴ��ڴ����� - media��asm��static(����QQ�һ��ڴ�)
#define MCR_MEM_APPRESER		MCR_MEMTYPE_MEDIA
#endif

#endif


#ifdef MSHELL_DEBUG
#define MDEBUG_EXTRA_MEM_SIZE   (100*1024)
#else
#define MDEBUG_EXTRA_MEM_SIZE   (0)
#endif

#if MCR_REGION_OVERSEA == __CFG_YES__
#define MKERN_MEM_SIZE 	(60 * 1024 + MDEBUG_EXTRA_MEM_SIZE)
#else
#define MKERN_MEM_SIZE 	(100 * 1024 + MDEBUG_EXTRA_MEM_SIZE)
#endif

//////////////////////////////////////////////////////////////////////////
/////////////////////////��̬�ڴ�����////////////////////
//////////////////////////////////////////////////////////////////////////
#if MCR_MEM_MAIN == MCR_MEMTYPE_STATIC
#define MCR_MEM_MAIN_STATIC_SIZE			(800*1024)
#else
#define MCR_MEM_MAIN_STATIC_SIZE			(0)
#endif

#if MCR_MEM_KERNRESER == MCR_MEMTYPE_STATIC
#define MCR_MEM_KERN_STATIC_SIZE		    (MKERN_MEM_SIZE)
#else
#define MCR_MEM_KERN_STATIC_SIZE			(0)
#endif

#if MCR_MEM_APPRESER == MCR_MEMTYPE_STATIC
#define MCR_MEM_APP_STATIC_SIZE				(1024*100)
#else
#define MCR_MEM_APP_STATIC_SIZE				(0)
#endif

#define MCR_MEM_STATIC_TOTAL    (MCR_MEM_MAIN_STATIC_SIZE+MCR_MEM_KERN_STATIC_SIZE+MCR_MEM_APP_STATIC_SIZE)





//////////////////////////////////////////////////////////////////////////
/////////////////////////��������////////////////////
//////////////////////////////////////////////////////////////////////////
//�̻���汾��
#define MCR_FIRMVERSION_OVERSEA		("003.03.04.013075")//����汾

#define MCR_FIRMVERSION		("000.03.04.018483")//���ڰ汾

//����
#define MCR_VENDOR			("mediatec")//("HK")

//����
#define MCR_TERMINALTYPE    ("6255")//("hd101")

//porting id removed and add it to file MHelperFunc

//ƽ̨
#define MCR_PLATFORMID		PLATFORMID_MCARE_MTK6235


//��������
#define MCR_KEYTYPE			MKEYTYPE_NORMAL_KEYPAD

//��������
#define MCR_TOUCHTYPE		MTOUCHSCREEN_YES


//����洢����
#if defined(WIN32) || (MCR_PLATFORMID == PLATFORMID_MCARE_MTK6225) || (MCR_PLATFORMID == PLATFORMID_MCARE_MTK6252) 
#define MCR_STORAGE_TYPE    MCR_STORAGE_CARD
#else
#define MCR_STORAGE_TYPE    MCR_STORAGE_CARD
#endif

//mcare �ļ����Ƿ����أ�Ĭ������ 
#define IS_MCARE_FILE_HIDDEN __CFG_YES__

//��ʹ洢Ҫ��
#define MCR_FS_REQ           (1024 * 1024)


//ƽ̨Ram�ڴ� - ����������ֵ��Ҫ�޸�һ��
#define MCR_MEM_SIZE		 (1100 * 1024)


//3��4����wifi֧��;����ֻ�֧����Ӧ��Ŀ�����ʶΪ__CFG_YES__
#define MCR_SIM3_SUPPORT    __CFG_NO__
#define MCR_SIM4_SUPPORT    __CFG_NO__

#ifdef __WIFI_SUPPORT__
#define MCR_WIFI_SUPPORT    __CFG_YES__
#else
#define MCR_WIFI_SUPPORT    __CFG_NO__
#endif

//QQ����Ϣ�Ƿ������
#define MCR_BLACKLIGHT_TURNON   __CFG_YES__

#if MCR_MTK_VER >= MTK_VER_1032
#define _MCR_MMI_RESOURCE_XML_GEN_
#endif


//UI��ɫ����
//Mcareƽ̨����ɫ������Ŀǰ֧��3����ɫ:    UI_THEME_BLUE,UI_THEME_PINK,UI_THEME_BROWN
#define UI_SYS_THEME_COLOR   (UI_THEME_BLUE)


//#if MCR_MTK_VER >= MTK_VER_952
//#define USE_SYSTEM_ZLIB    //whether to use system zlib..prefer to use to reduce rom space
//#endif

#if ((MCR_MTK_VER >= MTK_VER_1112) && (defined(__COSMOS_MMI_PACKAGE__))) //by purple
#define MCR_CAMERA_SUPPORT      __CFG_NO__
#elif defined __MMI_CAMERA__ || defined __MMI_CAMCORDER__
#define MCR_CAMERA_SUPPORT      __CFG_YES__
#else
#define MCR_CAMERA_SUPPORT      __CFG_NO__
#endif
#define MCR_SUPPORT_WAP_BROWSER     __CFG_NO__

#if MCR_REGION_OVERSEA == __CFG_YES__
#define USE_SYSBRW_DTCNT   //whether to use system browser's data account profile instead

#define __MCR_LANG_ENGLISH__            __CFG_YES__
#define __MCR_LANG_HINDI__              __CFG_NO__
#define __MCR_LANG_VIETNAMESE__         __CFG_NO__
#define __MCR_LANG_INDONESIAN__         __CFG_NO__
#define __MCR_LANG_THAI__               __CFG_NO__

//#define USE_SPLASH_LOGO  //whether to put splash logo on when entering to mcare
#else
//#define USE_SYSBRW_DTCNT   //
#define USE_SPLASH_LOGO  //
#endif



#ifdef __cplusplus   
}   
#endif // __cplusplus
#endif // _madpconfig_h
