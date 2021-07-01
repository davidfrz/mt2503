

#ifndef __GB_WG_PUBLIC_H__ 
#define __GB_WG_PUBLIC_H__

#include "GB_DataTypeDef.h"
#include "GB_Math.h"
#include "GB_EventFactory.h"
#include "GB_App.h"
#include "GB_WG_fun.h"


// ���ڵĸ����¼�
typedef enum _GBWINEVNENT_
{
	GBWINEVENT_NONE = 0,
		GBWINEVENT_UPGRADESTART,		// ͨ�ſ�ʼ
		GBWINEVENT_UPGRADEEND,			// ͨ�Ž���
		GBWINEVENT_POPUPCANDIDATEBOX,	// ������ѡ��
		GBWINEVENT_PACKUPCANDIDATEBOX,	// �����ѡ��
		GBWINEVENT_CLEARPENDOWN,		// ��д�����Ҫ����pendown����Ч�¼�
		GBWINEVENT_PACKUPPOPMENU,		// ����˵�
		GBWINEVENT_VKHIDE
}GBWINEVENT;

#endif //#ifndef __GB_WG_PUBLIC_H__ 