#ifndef _wrapper_inc_h_
#define _wrapper_inc_h_

#ifdef __cplusplus   
extern "C"{   
#endif // __cplusplus

#if defined( _TENCENT_MCARE_ADP_ ) 
//#include "platform_inc.h"
#endif

#include "McfAudio.h"
#include "McfBrowser.h"
#include "McfChset.h"
#include "McfCommon.h"
#include "McfDtcnt.h"
#include "McfEditor.h"
#include "McfFs.h"
#include "McfGdi.h"
#include "McfGZip.h"
#include "McfIdle.h"
#include "McfKey.h"
#include "McfMemory.h"
#include "McfMisc.h"
#include "McfPen.h"
#include "McfSim.h"
#include "McfSms.h"
#include "McfSocket.h"
#include "McfStdLib.h"
#include "McfSys.h"
#include "McfTelephone.h"
#include "McfTime.h"
#include "McfTimer.h"
#include "McfTrace.h"
#include "McfUcs2.h"
#include "McfUsb.h"
#include "McfVibrate.h"
#include "McfIdle.h"

#if ((MCR_MTK_VER ==MTK_VER_1144) && (defined  (__COSMOS_MMI_PACKAGE__))) //by rico 1144
#define NICK_NAME_LEN 25
typedef struct  
{	
	U32    dwUid;						//�����ߺ���
	U32    dwCode;						//ȺCode  �����Ⱥ��Ϣ ����ֶ���Ч
	U32    dwTime;						//����ʱ��
	U8    cType;						//��Ϣ����
	U8    cFlag;						//����������
	U16   wsName[NICK_NAME_LEN];		//�ǳ�
	U16   wsMsgLen;
	U16*  pwsMsg;						//��Ϣ����  
}stReadMsg;
//MMisc_DeliverMessage(10010000,MEVT_APP_SEND_MSG,msg,sizeof(stReadMsg));
//end
#endif

#ifdef __cplusplus   
}   
#endif // __cplusplus
#endif 
