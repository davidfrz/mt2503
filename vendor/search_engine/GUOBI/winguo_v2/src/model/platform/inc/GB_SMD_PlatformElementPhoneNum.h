
#ifndef __GB_SMD_PLATFORMELEMENTPHONENUM_H__
#define __GB_SMD_PLATFORMELEMENTPHONENUM_H__

#include "GB_WG_DataTypeDef.h"

enum __GBMD_PhoneBook_IndexType__
{
	GBMD_Numtype_Name,
	GBMD_Numtype_Phone,
	GBMD_Numtype_homeNumber,
	GBMD_Numtype_officeNumber,
	GBMD_Numtype_faxNumber,
	GBMD_Numtype_emailAddress, 
	GBMD_Numtype_Count
};

// ��ȡ�绰����ͼ��
extern GB_INT GB_SMD_Platform_GetPhoneNumIcon(GB_U16 index_type, GB_U32 index, GB_PU8 *img_buff_p);

// ��ȡָ��phone ID��type�ĵ绰����
extern GB_INT GB_SMD_Platform_GetPhoneNumByIndex(GB_U16 type, GB_U32 store_index, GB_U16*pNumber, GB_U16 nBuffLen);

// ��ȡָ��phone ID��type�ĵ绰�������
extern GB_INT GB_SMD_Platform_GetPhoneNumCountByIndex(GB_U16 nType, GB_U32 store_index);

// ��ȡָ��phone ID����ϵ������
extern GB_INT GB_SMD_Platform_GetPhoneBookName(GB_U32 store_index, GB_U16*pNameBuff, GB_U16 nBuffLen);

// ƽ̨����ӵ绰������������
extern GB_VOID GB_SMD_Platform_AddPhoneList(GB_VOID);

#endif // __GB_SMD_PLATFORMELEMENTPHONENUM_H__

