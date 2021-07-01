//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-B
// File        : WP3-B-GameApp.h
// Description : ����d�����६ -- �C���D�[�c
// Author      : Ray
// Create      : 2010-12-14
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP3_B_GAME_APP_H__
#define __WP3_B_GAME_APP_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"
#include "WP3-B-DogStatus.h"
#include "WP3-B-Name.h"
#include "CUtils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TIME_MIN	10000
#define TIME_MAX	12000

struct _WP3_B
{
	CArrayPool *pStatusArrayPool;
	NodeAniStatus *pStatusArray;
	float fDegree;
	int iAni;

	IGU8	m_bGameActive;

	IGU32	m_GameTime;	//�q�i�J�{���}�l��, GameFlow & GameFlowDisplay �� fGameTime �O�q�@���C���}�l��
	IGU32	m_ElapsedTime;
	IGU8	m_TimeFactor;

	IGU8	m_Hour;
	IGU8	m_TimeMode; //������m�O�_�n�H�ɶ�����

	IGU32	m_AniTime[5];

	CQueue	*m_Event;
	int		m_bLoadWorld;
	WP3_B_DogStatus	*m_WP;
	WP3_B_DogStatus	*m_OBJ[COUNT_OBJ];
	IGNode *Smile;
	int		m_CurrentLoop;
	int		m_CurrentAni;
	int		m_nowani;
	int active;
	CArray	*m_AniInfo;

	EventStatus		m_TimeEvent;
};

extern struct _WP3_B WP3_B;
extern int  WP3_B_PrepareConfig(IGV3Config *pPC);
extern void WP3_B_InitArrayPool(void);
extern void WP3_B_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4);
extern void WP3_B_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2);
extern void WP3_B_ClearPendingEvents(void);
extern IGSysEvent *WP3_B_GetEvent(void);
extern void WP3_B_Wind(void);

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int WP3_B_OnStartup(void);

extern IGU32 WP3_B_GetElapsedTime(IGU32 _tick);
extern void WP3_B_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second);
extern int WP3_B_GetHour(void);

/**
* Called when platform wants application to render & update itself
* * @param uFrameInterval
*   Time interval (integer, millisecond) between previous frame and this frame. 
* * @param uNumSysEvents
*   Number of system fired events captured by IGGame Framework since previous frame.
* * @param pSE
*   Pointer to the IGSysEvent structure provided by IGGame Framework
* @return
*   0 means application successfully update and render irslef, otherwize returns application dependent error code, 
*   IGGame Framework will then call IGGame_OnShutdown to terminate the application
* @see IGGame_OnShutdown
*/
extern int WP3_B_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval);
 

/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void WP3_B_OnShutdown(int appId);


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
