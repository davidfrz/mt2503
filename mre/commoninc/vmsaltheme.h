#ifndef VMSALTHEME_H_
#define VMSALTHEME_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * (SAL �㺯��)
 * ��ָ�������������Ϊ��ǰ���⡣
 *
 * @param file_name 	Ҫ����Ϊ��ǰ����İ���(ע�⣺ֻ��file name������full path)��
 *
 * @return 			����TRUE ���óɹ�����������ʧ�ܡ�
 */
VMINT vm_sal_set_active_theme(VMUSTR file_name);


/**
 * (SAL �㺯��)
 * ��ָ����ͼƬ����Ϊ��ǰǽֽ��
 *
 * @param file_name 	Ҫ����Ϊ��ǰǽֽ���ļ�����
 *
 * @return 			����TRUE ���óɹ�����������ʧ�ܡ�
 */
VMINT vm_sal_set_active_wallpaper(VMUSTR file_name);

#ifdef __cplusplus
}
#endif

#endif /* VMSALTHEME_H_ */
