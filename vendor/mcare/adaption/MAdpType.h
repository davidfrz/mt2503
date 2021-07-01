#ifndef _madptype_h
#define _madptype_h

#ifdef __cplusplus   
extern "C"{   
#endif // __cplusplus


#include "McfCommon.h"


/*=================�ڴ�����=================*/
//�ڴ����ͣ���ƽ̨�����ṩ�������ڴ��ȡ��ʽ����ͬƽ̨
//������ͬ����MTK����med/asm/static��ʽ������ƽ̨���ܾ�û��
#define MCR_MEMTYPE_MEDIA		(1)
#define MCR_MEMTYPE_ASM			(2)
#define MCR_MEMTYPE_STATIC		(3)


//�ڴ�����//ȷ�ϸñ�ʶ�ں�̨û�����κι�������������������
/*================�ڴ��ʶ================*/
#define MEMTYPE_STATIC					(1<<0)
#define MEMTYPE_ASM						(1<<1)
#define MEMTYPE_MEDIA					(1<<2)
#define MEMTYPE_NORMAL					(1<<3)
#define MEMTYPE_UNKNOWN					(0)


/*================ƽ̨��ʶ================*/
//ƽ̨��ʶ��ƽ̨���η��䣬
//Ҫ�Ͳ�Ʒ�����ֵ�Ӳ���汾����չIDͬ��
//�������µı�ʶ��غ�ϵͳȷ�ϣ��������������
//MTK [0,49]
#define PLATFORMID_MCARE_MTK6223		(0)
#define PLATFORMID_MCARE_MTK6225		(1)
#define PLATFORMID_MCARE_MTK6226		(2)
#define PLATFORMID_MCARE_MTK6228		(3)
#define PLATFORMID_MCARE_MTK6235		(4)
#define PLATFORMID_MCARE_MTK6253		(5)
#define PLATFORMID_MCARE_MTK6236		(6)
#define PLATFORMID_MCARE_MTK6268		(7)
#define PLATFORMID_MCARE_MTK6238		(8)
#define PLATFORMID_MCARE_MTK6252		(9)
#define PLATFORMID_MCARE_MTK6276		(10)
//SPREADTRUM [50,79]
#define PLATFORMID_SPREADTRUM           (50)
//MSTAR [80,109]
#define PLATFORMID_MSTAR                (80)
//BREW  [110,129]
#define PLATFORMID_BREW                 (110)
//LEADCORE [130,159]
#define PLATFORMID_LEADCORE             (130)


/*================ѡ���Ӧ��MTKƽ̨================*/
#define MTK_VER_652     652
#define MTK_VER_812		812
#define MTK_VER_816		816
#define MTK_VER_828		828
#define MTK_VER_832     832
#define MTK_VER_840		840
#define MTK_VER_852		852
#define MTK_VER_912		912
#define MTK_VER_916		916
#define MTK_VER_932		932
#define MTK_VER_936		936
#define MTK_VER_952		952
#define MTK_VER_1012	1012
#define MTK_VER_1032	1032
#define MTK_VER_1108	1108
#define MTK_VER_1112	1112
#define MTK_VER_1132	1132
#define MTK_VER_1144      1144
#define MTK_VER_1210      1210

/*================�洢λ��================*/
#define MCR_STORAGE_CARD				(0)//removealbe card
#define MCR_STORAGE_PUBLIC				(1)//public phone storage,accessable and visible
#define MCR_STORAGE_PRIVATE				(2)//private phone storage,maybe accessable but not visible
#define MCR_STORAGE_RESERVE				(3)//other


#define __CFG_NO__      (0)
#define __CFG_YES__     (1)

#define __CFG_NONE__    (0)
#define __CFG_TMC__     (1)
#define __CFG_TMZ__     (2)




#ifdef __cplusplus   
}   
#endif // __cplusplus
#endif // _madptype_h
