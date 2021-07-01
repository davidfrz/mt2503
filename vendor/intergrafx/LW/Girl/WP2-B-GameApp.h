//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP2-B
// File        : WP2-B-GameApp.h
// Description : ����k�k�Į६ -- �C���D�[�c
// Author      : Ray
// Create      : 2010-09-20
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP2_B_GAME_APP_H__
#define __WP2_B_GAME_APP_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"
#include "WP2-B-GirlStatus.h"
#include "WP2-B-Name.h"
#include "CUtils.h"
#include "V3Retained.h"

#ifdef __cplusplus
extern "C" {
#endif


struct _WP2_B
{
	int iMouseX, iMouseY;
	
	CArrayPool *pStatusArrayPool;
	NodeAniStatus *pStatusArray;

	V3Retained *rr;
	IGErr err;

	IGU8	m_bGameActive;

	IGU32	m_GameTime;	//�q�i�J�{���}�l��, GameFlow & GameFlowDisplay �� fGameTime �O�q�@���C���}�l��
	IGU32	m_ElapsedTime;
	IGU8	m_TimeFactor;

	IGU8	m_Hour;
	IGU8	m_TimeMode; //������m�O�_�n�H�ɶ�����

	CQueue	*m_Event;

	WP2_B_GirlStatus	*m_WP;
	int		m_CurrentLoop;
	int		m_CurrentAni;
	int		anispeed;
	IGGameObject *m_GameObj[COUNT_OBJ];
	int		screenW;
	int		screenH;
	IGNode	*m_Obj[COUNT_OBJ];
	IGNode	*m_Bone[COUNT_BONE];
	CArray	*m_AniInfo;
	int		m_bLoadWorld;
	int		m_HDegree, m_VDegree, m_DegreeInc;

	V3World *m_World;

	int		iMaxDeg1;//��t���׷�����(��)
	int		iMaxDeg2;//��t���׽w�ĭ�(��)
	int		iMinDeg1;//��t���׷�����(�k)
	int		iMinDeg2;//��t���׽w�ĭ�(�k)
	int		iMiddleDeg;//���Y����(���߭�)
	int		isRecovering;//�O�_���i������ɥ�, 1:���b�i��, 0:���i��
};

extern struct _WP2_B WP2_B;
extern int  WP2_B_PrepareConfig(IGV3Config *pPC);
extern void WP2_B_InitArrayPool(void);
extern void WP2_B_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4);
extern void WP2_B_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2);
extern void WP2_B_ClearPendingEvents(void);
extern IGSysEvent *WP2_B_GetEvent(void);
extern void WP2_B_IO_EventHandler(IGSysEvent *pSE);

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int WP2_B_OnStartup(void);

extern IGU32 WP2_B_GetElapsedTime(IGU32 _tick);
extern void WP2_B_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second);
extern int WP2_B_GetHour(void);

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
extern int WP2_B_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval);
 

/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void WP2_B_OnShutdown(int appId);


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
