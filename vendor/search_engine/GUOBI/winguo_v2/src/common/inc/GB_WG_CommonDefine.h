
#ifndef __GB_WG_COMMONDEFINE_H__
#define __GB_WG_COMMONDEFINE_H__

#include "GB_WG_CommonConfig.h"
#include "GB_WG_DataTypeDef.h"

// �绰������ģʽ
typedef enum  
{
	e_GB_WG_SMD_PHONE_NORMAL, // ����
	e_GB_WG_SMD_PHONE_WIFI,		// wifi
	e_GB_WG_PHONE_MODE_VAIN,   // ��Ч��
	e_GB_WG_PHONE_MODE_NOSIM,  // ��SIM��
	e_GB_WG_PHONE_MODE_FLIGHT, // ����ģʽ
	e_GB_WG_PHONE_MODE_ENCRYPT,  //ͨѶ¼����
	e_GB_WG_PHONE_MODE_USB,    // usbģʽ
}GB_WG_Phone_Mode;


typedef GB_VOID (*GB_WG_FuncPtr)(GB_VOID);

#define EmumToFlag(n) (1<<n)

#define GB_WG_SEARCH_WEB_MAX_INPUT_LEN (25)

#endif // __GB_WG_COMMONDEFINE_H__
