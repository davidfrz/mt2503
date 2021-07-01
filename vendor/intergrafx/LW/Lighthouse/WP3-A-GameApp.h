//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP3-A
// File        : ����O��६ -- WP3-A-GameApp.h
// Description : �C���D�[�c
// Author      : Ray
// Create      : 2010-11-16
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP3_A_GAME_APP_H__
#define __WP3_A_GAME_APP_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"

#include "WP3-A-Name.h"
#include "CUtils.h"
#include "CNodeStatus.h"

#ifdef __cplusplus
extern "C" {
#endif

#define FISH_MIN	500
#define FISH_MAX	3000

struct _WP3_A
{
	IGU8	m_bGameActive;
	IGErr err;
	int iMouseX, iMouseY;
	long iRayTime;

	IGU32	m_GameTime;	//�q�i�J�{���}�l��, GameFlow & GameFlowDisplay �� fGameTime �O�q�@���C���}�l��
	IGU32	m_ElapsedTime;
	IGU8	m_TimeFactor;

	IGU8	m_Hour;
	IGU8	m_TimeMode; //������m�O�_�n�H�ɶ�����
	CTime	m_Time;

	CQueue	*m_Event;
	int			m_bLoadWorld;
	IGNode	*m_Ray, *m_Whale, *m_Bird, *m_Bird01;
	IGNode	*m_Path[COUNT_PATH];
	IGNode	*m_WhalePosition[COUNT_WHALE_POSITION];
	IGNode	*m_worldrotate;

	int		m_CurrentWhalePosition, m_CurrentBirdPath, m_CurrentBirdPath01;

	CArray	*m_AniInfo;
	
	igreal	m_Scale[3];

	int		m_HDegree, m_VDegree, m_DegreeInc;
	V3World *m_World;
};

extern struct _WP3_A WP3_A;

extern int  WP3_A_PrepareConfig(IGV3Config *pPC);
extern void WP3_A_InitArrayPool(void);
extern void WP3_A_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4);
extern void WP3_A_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2);
extern void WP3_A_ClearPendingEvents(void);
extern IGSysEvent *WP3_A_GetEvent(void);
extern void WP3_A_ScaleXYZ(float fNum);

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int WP3_A_OnStartup(void);

extern IGU32 WP3_A_GetElapsedTime(IGU32 _tick);
extern void WP3_A_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second);
extern int WP3_A_GetHour(void);

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
extern int WP3_A_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval);
 

/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void WP3_A_OnShutdown(int appId);


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
