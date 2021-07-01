/*! @file
********************************************************************************
<PRE>
ģ����       : 
�ļ���       : GB_WinStack.h 
����ļ�     : 
�ļ�ʵ�ֹ��� : ����ջ�����㴰��״̬�ķ���
����         : Knight
�汾         : 1.0
--------------------------------------------------------------------------------
��ע         : 
--------------------------------------------------------------------------------
�޸ļ�¼ : 
*******************************************************************************/


#ifndef GB_WG_APP_DEFINE_FOR_PLATFORM_KNIGHTNIU_2010_01_10_H
#define GB_WG_APP_DEFINE_FOR_PLATFORM_KNIGHTNIU_2010_01_10_H

#include "GB_DataTypeDef.h"
#include "GB_EventFactory.h"

/////////////////////////////////
typedef struct _SysApp{
	////
	////
	GB_INT classId;///
}SysApp;


////��Ϣ
typedef struct
{
	GB_INT	msg_ID;
	GB_VOID *parma;
}GB_WG_msg_sturct;

// ��ڵĺ���ָ��
typedef GB_VOID (*GB_WG_ENTRYFUN)(GB_VOID);

SysApp * GB_WG_GetSysApp();


GB_VOID  GB_WG_Msg_Handle(GB_WG_msg_sturct *local_para);

// add by zhangwei-jerry
extern GB_VOID GB_WG_APP_SetEntryFun(GB_WG_ENTRYFUN pFun);
extern GB_WG_ENTRYFUN GB_WG_APP_GetEntryFun(GB_VOID);

//////////////////////////////////
// ����ʱ��ʼ��
extern GB_VOID GB_WG_BootupInit(GB_VOID);

GB_VOID GB_WG_Init(GB_VOID);
GB_VOID GB_WG_Entry_Win(GB_VOID);
GB_VOID GB_WG_Exit_Win(GB_VOID);
GB_VOID GB_WG_FreeWin(GB_VOID);  //������ȫ���ͷ�
GB_VOID GB_WG_WinguoSearchScreen(GB_VOID); // ֱ�ӽ���winguo��������

GB_BOOL GB_WG_HandleKey_Win(GBKeyEvent keyEvent, GBKeyValue keyValue);
GB_BOOL GB_WG_HandlePen_Win(GBPenEvent penEvent,GB_INT xPos,GB_INT yPos);
GB_VOID GB_WG_DrawScreen(GB_Rect *rect);

GB_VOID GB_WG_Save_account(GB_ULONG account,GB_INT apn,GB_INT selSim,GB_BYTE* imsi);

//GB_UINT GBGetWinguoVerificationCode(GB_UINT inWinguoVerify);

//GB_ULONG GB_WG_GetAccount();

//////////////////



#endif