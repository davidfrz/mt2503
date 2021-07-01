#ifndef __VM_GSENSOR
#define __VM_GSENSOR
#include "vmswitch.h"
#include "vmsys.h"
#ifdef __MRE_SAL_CAMERA__
#ifdef __cplusplus
extern "C" {
#endif

/**
 * ���ٶȴ��о��������ơ�
 */
#define USE_SENSOR_NAME			"sensor:quality=acceleration;device=mobile;model=MMA7455L_MOBILE;location=inside"

/**
 * ���ٶȴ������Ĳ����ʵ����жȡ�
 */
#define MOTION_SENSITIVE 			"MOTION_SENSITIVE"

/**
 * ���ٶȴ�������һ���������ٶȵ�ʱ���ֵ��
 */
#define ONE_G_VALUE		(64)

/**
 * ���ٶȴ�������ǰ���ܸ�Ӧ�������������ٶȡ�
 */
#define SELECTED_G_LEVEL	(SENSOR_2G_LEVEL)

/**
 * MOTION_SENSITIVE��ص�ֵ��
 */
typedef enum 
{
	MOTION_SENSITIVE_LOW, 
	MOTION_SENSITIVE_NORMAL, 
	MOTION_SENSITIVE_HIGH
} VM_MOTION_SENSITIVE_ENUM;

/**
 * ���ٶȴ��������ܸ�Ӧ�ķ�Χ�����͡�
 */
typedef enum
{
	SENSOR_1G_LEVEL,
	SENSOR_2G_LEVEL,
	SENSOR_4G_LEVEL,
	SENSOR_8G_LEVEL
} VM_SELECTED_G_LEVEL;

/**
 * ���ٶȴ��о����������������͡�
 */
typedef struct g_sensor_data_t 
{
	VMINT x;		/**<��X���ϵļ��ٶȷ�����  */
	VMINT y;		/**<��Y���ϵļ��ٶȷ�����  */
	VMINT z;		/**<��Z���ϵļ��ٶȷ�����  */
}g_sensor_data_t;

#ifdef __cplusplus
}
#endif

#endif

#endif

