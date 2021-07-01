//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP1-A
// File        : WP1-A-GameApp.h
// Description : �t�ۯ�६ -- �C���D�[�c
// Author      : Ray
// Create      : 2010-11-02
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP1_A_GAME_APP_H__
#define __WP1_A_GAME_APP_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"
#include "IGGameObject.h"
#include "WP1-A-Status.h"
#include "WP1-A-Name.h"
#include "CUtils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define WIND_MIN	10000
#define WIND_MAX	15000

struct _WP1_A
{
	IGErr err;
	CArrayPool *pStatusArrayPool;
	NodeAniStatus *pStatusArray;

	int iMouseX;
	int iMouseY;
	long iTime;

	IGU8	m_bGameActive;

	IGU32	m_GameTime;	//�q�i�J�{���}�l��, GameFlow & GameFlowDisplay �� fGameTime �O�q�@���C���}�l��
	IGU32	m_ElapsedTime;
	IGU8	m_TimeFactor;

	IGU8	m_Hour;
	IGU8	m_TimeMode; //������m�O�_�n�H�ɶ�����
	CTime	m_Time;

	CQueue	*m_Event;

	WP1_A_Status	*m_WP;
	WP1_A_Status	*m_OBJ[COUNT_OBJ];
	WP1_A_Status	*m_OBJFlower[COUNT_FLOWER];
	IGNode			*m_Bird[COUNT_BIRD];
	IGNode			*m_Path[COUNT_PATH];
	IGGameObject	*m_GameObj[COUNT_OBJ];
	EventStatus		m_Wind;

	TimeStatus		m_FlowerR;
	TimeStatus		m_FlowerY;
	TimeStatus		m_FlowerC;

	int		m_CurrentLoop;

	CArray	*m_AniInfo;
	int		m_bLoadWorld;
	//IGNode	*m_Obj[COUNT_OBJ];
	float		m_HDegree, m_VDegree, m_DegreeInc;
	V3World		*m_World;

	int		iMaxDeg1;//��t���׷�����(��)
	int		iMaxDeg2;//��t���׽w�ĭ�(��)
	int		iMinDeg1;//��t���׷�����(�k)
	int		iMinDeg2;//��t���׽w�ĭ�(�k)
	int		iMiddleDeg;//���Y����(���߭�)
	int		isRecovering;//�O�_���i������ɥ�, 1:���b�i��, 0:���i��
};

extern struct _WP1_A WP1_A;

extern int  WP1_A_PrepareConfig(IGV3Config *pPC);
extern void WP1_A_InitArrayPool(void);
extern void WP1_A_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4);
extern void WP1_A_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2);
extern void WP1_A_ClearPendingEvents(void);
extern IGSysEvent *WP1_A_GetEvent(void);
extern void WP1_A_Wind(void);

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int WP1_A_OnStartup(void);

extern IGU32 WP1_A_GetElapsedTime(IGU32 _tick);
extern void WP1_A_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second);
extern int WP1_A_GetHour(void);

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
extern int WP1_A_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval);
 

/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void WP1_A_OnShutdown(int appId);


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
