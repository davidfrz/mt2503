#ifndef VMTHEME_H_
#define VMTHEME_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif


/* vmtheme return code */
typedef enum
{	
	VM_WALLPAPER_ERR_BASE_LAYER_EXIST = -4,	//���㻹����
	VM_WALLPAPER_MIBR_NOT_FORE,				//Ӧ���ں�̨״̬
	VM_WALLPAPER_ERR_UNSUPPORT_IMAGE_TYPE,  //��֧�ֵ� ͼƬ����
	VM_WALLPAPER_ERR_WRONG_PARAM,			//��������
	VM_WALLPAPER_SUCCEED					//0
}vm_theme_result;

/*
 * @�����ֻ���ǽֽ����ͨ���ֻ���������ǽֽ��
 * @����ǽֽ����Ϊǰ̨״̬����̨���е�״̬���øýӿ���Ч�� 
 * @ǽֽ�ĸ�ʽ��ʱֻ֧�� "BMP"��"GIF"��"JPG" ����ͼƬ��ʽ��
 * @���øýӿ�֮ǰ����Ҫɾ�����еĲ�
 * @param file_name	 ���ǽֽͼƬ��ȫ·�����Ϊ259�ַ�
 * @���׳�������ʧ�ܵĵط��� ͼƬ�Ĵ�С������ͼƬ�Ŀ�� 
 *
 * @return	����VM_WALLPAPER_SUCCEED��ʾ�����ɹ���
 * @return	����VM_WALLPAPER_ERR_WRONG_PARAM��ʾ·���ı����ʽ����ȷ����·��Ϊ�ջ����ļ������ڣ������ֻ�ϵͳ���ڴ治��
 * @return	����VM_WALLPAPER_ERR_UNSUPPORT_IMAGE_TYPE��֧�ֵ�ͼƬ����
 * @return	����VM_WALLPAPER_ERR_BASE_LAYER_EXIST���㻹���ڲ���������ǽֽ
 * @return	����VM_WALLPAPER_MIBR_NOT_FORE Ӧ�ô��ں�̨״̬ 
 */
VMINT vm_set_active_wallpaper(VMWCHAR* file_name);


#ifdef __cplusplus
}
#endif

#endif /* VMTHEME_H_ */
