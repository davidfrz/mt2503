#ifndef __GB_WG_LACINF_H_BY_FOR_GETLAC_ZHANGWEI_JERRY_20110831__
#define __GB_WG_LACINF_H_BY_FOR_GETLAC_ZHANGWEI_JERRY_20110831__

#include "GB_DataTypeDef.h"

// ����ר��
//#define __GB_WG_LACINF_DEBUG__

// ��ȡ��վ��Ϣ
typedef enum __GB_WG_LACINF_STATE__
{
	GB_WG_LACINF_STATE_NONE = 0,
		GB_WG_LACINF_STATE_SUCCESS,	// ��ȡ�ɹ�
		GB_WG_LACINF_STATE_FAILURE,	// ��ȡʧ��
		GB_WG_LACINF_STATE_END		
}GB_WG_LACINF_STATE;

typedef GB_VOID (*GB_WG_LACINF_FUNCALLBACK)(GB_WG_LACINF_STATE state,GB_CHAR* cell_id,GB_VOID* pUser);

// ��ȡ״̬
//GB_WG_LACINF_STATE GB_WG_GetLacState(GB_VOID);
// ����״̬
//GB_VOID GB_WG_SetLacState(GB_WG_LACINF_STATE state);
// ȡ�û�վ��Ϣ
GB_CHAR* GB_WG_Get_Cell_id(GB_VOID);
// ������ȡ��վ��Ϣ����Ϣ
//GB_VOID GB_WG_Get_Cell_Msg(GB_VOID);
GB_VOID GB_WG_Get_Cell(GB_WG_LACINF_FUNCALLBACK pLacFunCallback,GB_VOID* pUser);


#endif
