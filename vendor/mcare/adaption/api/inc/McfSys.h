#ifndef _mcfsys_h_
#define _mcfsys_h_

#include "McfCommon.h"

#define MCARE_SCREEN_BASE   (APP_TENCENT_MCARE_BASE)
#define MCARE_SCREEN_HOME   (APP_TENCENT_MCARE_BASE+1)
#define MCARE_SCREEN_EDITOR (APP_TENCENT_MCARE_BASE+2)    

typedef MVOID (*pfnFunc)(MVOID);
typedef MBYTE (*pfnDelFunc)(MVOID*);

//˵��������mcare UIǰ��Ҫִ�еĶ���������MTK���EntryNewScreen������ƽ̨�ɱ���inactive��resume����uiǰ��һЩ׼����ʵ�֡�
MINT McfSys_Init(pfnFunc inactiveFunc, pfnFunc deepInactiveFunc, pfnFunc resumeFunc, pfnFunc exitFunc);

//�̻�����á��˳�Mcare UI��Ҫ���õĺ�����
//nExitType �C �˳���־�������ϴε�λ�û����˳���idle��
MINT McfSys_DeInit(MINT nExitType);


//˵�����̻�����ã���̨�һ���Ҫִ�еĲ����� 
//nExitType �C �˳���־�������ϴε�λ�û����˳���idle��
MINT McfSys_Background(MINT nExitType);


//============================= �ⲿ���ú��� =====================================
//˵�����ɹ�����ƽ̨���ⲿ���ã��һ��ָ�ǰ��Ҫִ�еĲ�����
MINT McfSys_Foreground(MVOID);

//˵����ֱ�ӵ��ù̻����Suspend�ĵ�������������ƽ̨��suspend��Ϣ�ɵ��á�
MINT McfSys_Suspend(MVOID);

//˵����ֱ�ӵ��ùһ���Resume�ĵ�������������ƽ̨�յ�resume��Ϣ�ɵ���
MINT McfSys_Resume(MVOID);
//====================================================================

MVOID McfSys_InvalidateCpuCache(MBYTE *start, MUINT size);


#endif
