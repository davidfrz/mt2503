//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP4-A
// File        : WP4-A-GameApp.h
// Description : ����ܧΪ���६ -- �C���D�[�c
// Author      : Ray
// Create      : 2010-12-14
// Update      : 2011-02-15
//==============================================================================

#ifndef __WP4_A_GAME_APP_H__
#define __WP4_A_GAME_APP_H__

#include "GameDef.h"
#include "V3DataDef.h"
#include "IGScene.h"
#include "WP4-A-Name.h"
#include "CUtils.h"
#include "CNodeStatus.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TIME_MIN	10000
#define TIME_MAX	12000

struct _WP4_A
{
	IGErr err;
	IGU8	m_bGameActive;
	IGU32	m_GameTime;	//�q�i�J�{���}�l��, GameFlow & GameFlowDisplay �� fGameTime �O�q�@���C���}�l��
	IGU32	m_ElapsedTime;
	IGU8	m_TimeFactor;
	IGU8	m_Hour;
	IGU8	m_TimeMode; //������m�O�_�n�H�ɶ�����
	IGU32	m_AniTime[5];
	CQueue	*m_Event;
	EventStatus		m_TimeEvent;
	int					m_bLoadWorld;
	IGNode			*m_pObj[COUNT_OBJ];					//�����ҫ��`�I����, �]�N�@�Ӽҫ��i�ѱ���...-.,-
	CArray			*m_AniInfo;							//�����Ҧ��ʵe��T
	signed int				m_CurrentAni;						//�����ثe��������Ӱʵe
	signed int		m_PausedAni;						//�����ثe�w�g�Q�Ȱ����ʵe�s��, -1��ܪŭ�, ��L���X�N��n�Ѱ��Ȱ����٭�Ϊ��ʵe�s��
	signed int		m_CurrentAniTimePassed;				//�ثe�����񪺰ʵe, �ɶ��i��, -1��ܨS�ʵe, �i��O�R��, �i��O���b��LOOP
	//int				m_isCarState;						//�����ثe�ҫ������A, 0:�����H 1:��
	signed int		m_LoopDirection;					//�����ثeLoop�O���ۼ����٬O�˵ۼ���, 1:����, -1:�˼�
	int				m_isTouchMove;						//�����ثe�ϥΪ̬O�_���|�նi��touch move, 0:���i��, 1:���b�i��, ��touch up�ƥ� �i�歫�m
	int				m_isPauseAni;						//�����ثe�O�_�Ȱ��ʵe, 0:�Ȱ�, 1:���Ȱ�
	int				m_isTransformationable;				//�����ثe�O�_�i�H���J�ܧΰʵe, 0:���i 1:�i
	int				m_isLoop;							//�����ثe�O�_���b���m���A, 0:���O, 1=�O
	int		iMaxDeg1;//��t���׷�����(��)
	int		iMaxDeg2;//��t���׽w�ĭ�(��)
	int		iMinDeg1;//��t���׷�����(�k)
	int		iMinDeg2;//��t���׽w�ĭ�(�k)
	int		iMiddleDeg;//���Y����(���߭�)
	int		isRecovering;//�O�_���i������ɥ�, 1:���b�i��, 0:���i��

	unsigned int	m_PauseTime;						//�����ϥΪ̫��U�Ȱ��ɪ�[�C���ɶ�], �ΥH���ʵe��������򩵫�
	unsigned int	m_PauseAniTime;						//�����ϥΪ̫��U�Ȱ��ɪ��ʵe��������, �ΥH���ʵe���� & �Ѱ��Ȱ����~�򼽩�
	int				m_isGlassShow;						//�����O�_��ܬ����}�H���e��, 0:���, 1:���
	IGU32			m_RandomPlayAniTime;				//�����C���}�l���m���_�l�ɶ�, 0:��ܥثe���b���m���A
	int				m_HDegree, m_VDegree, m_DegreeInc;	//����\��, �ثe��������X��, �ثe��������X��, ���ਤ�׼W�q
	int				m_posZ, m_posInc;					//����camera_control, Z�b�y��, �y�мW�q
	int				m_ScaleInc;							//�Y�񪺼W�q, ��camera_control��
	igreal			m_Scale[ 3 ];						//XYZ�b���Y��q, ��camera_control��
	IGPoint			m_logMouse;							//�ƹ��y�и�T, ��T�Ȧs, �D�u�����ƹ��y��
	IGPoint			m_downMouse;						//�ƹ��y�и�T, ��T�Ȧs, �D�u�����ƹ��y��, �ΨӰO��touch down���y��
	int				m_isAutoRotate;						//�����ثe�O�_�i��۰ʱ���, 0:����, 1:��
	signed int		m_iDir;								//�����۰ʱ���Ҧ���ʪ���V, ���ȦV��, �t�ȦV�k
	int				m_isAutoScale;						//�����ثe�O�_�i��۰��Y�����Y�ܦX�A�����p, 0:����, 1:�۰�
	
};

extern struct _WP4_A WP4_A;

//extern int WP4_A_PrepareConfig(IGPlatformConfig *pPC);
extern int WP4_A_PrepareConfig(IGV3Config *pPC);
extern void WP4_A_InitArrayPool(void);
extern void WP4_A_AddDebugMessage(char *pFmt, long _p1, long _p2, long _p3, long _p4);
extern void WP4_A_PostEvent(IGU32 _Id, IGU32 _Time, IGU32 _Data1, IGU32 _Data2);
extern void WP4_A_ClearPendingEvents(void);
extern void WP4_A_Free(IGSysEvent *_this);
extern IGSysEvent *WP4_A_GetEvent(void);

//===
extern void WP4_A_initialValues(void);
extern void WP4_A_RandomAni(void);
extern void WP4_A_Transformation(void);
extern void WP4_A_HTouchMove(signed int _pixel);		//touch move, horizontal, Rotate
extern void WP4_A_VTouchMove(signed int _pixel);		//touch move, vertical, Scale
extern void WP4_A_translateZ(signed int iNum);
extern void WP4_A_ScaleXYZ(signed int iNum);
extern void WP4_A_TouchUp(void);
extern void WP4_A_ShowPic(IGTexture *pTex, int locX, int locY, int viewX, int viewY, int viewWidth, int viewHeight);
extern void WP4_A_SwitchAni(int iNum);
extern void WP4_A_PlayAni(void);
extern void WP4_A_PlayLoop(void);
extern void WP4_A_PauseAni(void);
extern void WP4_A_StopAni(void);
extern void WP4_A_EventAniEnd(int iNum);
extern void WP4_A_InputEvent(IGSysEvent *pSE);

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int WP4_A_OnStartup(void);

extern IGU32 WP4_A_GetElapsedTime(IGU32 _tick);
extern void WP4_A_SetLocalTime(IGU8 _hour, IGU8 _minute, IGU8 _second);
extern int WP4_A_GetHour(void);

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
extern int WP4_A_OnUpdate(unsigned char *_pFrameBuffer, IGU32 uFrameInterval);



/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void WP4_A_OnShutdown(int appId);


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
