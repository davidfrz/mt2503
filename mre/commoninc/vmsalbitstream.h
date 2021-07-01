

#ifndef __VM_SAL_BITSTREAM__
#define __VM_SAL_BITSTREAM__
#include "vmswitch.h"
#ifdef __MRE_SAL_BITSTREAM__

#include "vmsys.h"
#include "vmbitstream.h"

/**
 * (SAL �㺯��)
 * ��bitstream ��ʽ����Ƶ��Դ��
 *
 * @param handle			�򿪵�bitstream �����
 * @param audio_type		��Ƶ��Դ�����͡�
 * @param result_callback	��Ƶ�ص�������
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_open(
	VMINT* handle,
	vm_bitstream_audio_cfg_struct *audio_type,
	vm_bitstream_audio_result_callback callback);

VMINT vm_sal_bitstream_audio_open_pcm(VMINT* handle, vm_bitstream_pcm_audio_cfg_struct *audio_type, vm_bitstream_audio_result_callback callback);

/**
 * (SAL �㺯��)
 * �ر���bitstream ��ʽ�򿪵���Ƶ�ļ���
 *
 * @param handle			��vm_bitstream_audio_open �򿪵�bitstream �����
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_close(VMINT handle);

/**
 * (SAL �㺯��)
 * ����bitstream �����ȡ��Ƶ����ṹ�塣
 *
 * @param handle			�򿪵�bitstream �����
 * @param status			�õ�����Ƶ����ṹ�塣
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_get_buffer_status(
	VMINT handle, 
	vm_bitstream_audio_buffer_status *status);

/**
 * (SAL �㺯��)
 * ��ָ����С����Ƶ����д����Ƶ�������ڣ���ͨ������used_size ��֤��ʵд�����ݴ�С��
 *
 * @param handle			�򿪵�bitstream �����
 * @param buffer			��д����Ƶ���������ڴ��ַָ�롣
 * @param buffer_size		Ҫд��Ļ�����ֽ�����
 * @param used_size		ʵ��д�뻺����ֽ�����
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_put_data(
	VMINT 	handle,
	VMUINT8 *buffer,
	VMUINT 	buffer_size,
	VMUINT	*written);

 /**
 * (SAL �㺯��)
 * ��ָ��ʱ�����Ƶ����д����Ƶ�������ڣ�������ݴ�С����������������ʧ�ܡ�
 *
 * @param handle			�򿪵�bitstream �����
 * @param buffer			��д����Ƶ������������ָ�롣
 * @param buffer_size		Ҫд��Ļ���Ĵ�С��
 * @param used_size		Ҫд�뻺�����Ƶʱ��(��λ������)��
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_put_frame(
	VMINT 	handle,
	VMUINT8 *buffer,
	VMUINT	buffer_size,
	VMUINT 	timestamp);

/**
 * (SAL �㺯��)
 * ��ʼ����BitStream Audio ��Ƶ��
 *
 * @param handle			Ҫ���ŵ�bitstream �����
 * @param para			������Ƶʱ�����ṹ�塣
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_start(
	VMINT handle,
	vm_bitstream_audio_start_param *para);

/**
 * (SAL �㺯��)
 * ֹͣ����BitStream Audio ��Ƶ��
 *
 * @param handle			Ҫֹͣ���ŵ�bitstream �����
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_stop(VMINT handle);

/**
 * (SAL �㺯��)
 * ��ȡ��ǰ����ʱ�䡣
 *
 * @param handle			Ҫ��ȡ����ʱ���bitstream �����
 * @param current_time		��õĵ�ǰ����ʱ��(��λ������)
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_get_play_time(
	VMINT handle,
	VMUINT* current_time);



VMINT stub_bitstream_audio_open(VMINT* handle, vm_bitstream_audio_cfg_struct *audio_type, vm_bitstream_audio_result_callback callback);
VMINT stub_bitstream_audio_close(VMINT handle);
VMINT stub_bitstream_audio_get_buffer_status(	 VMINT handle, vm_bitstream_audio_buffer_status *status);	 
VMINT stub_bitstream_audio_put_data(VMINT handle,VMUINT8* buffer,VMUINT buffer_size,VMUINT* written);
VMINT stub_bitstream_audio_put_frame(VMINT handle, VMUINT8* buffer, VMUINT buffer_size,VMUINT timestamp);
VMINT stub_bitstream_audio_start(VMINT handle,  vm_bitstream_audio_start_param  *para);
VMINT stub_bitstream_audio_stop(VMINT handle);
VMINT stub_bitstream_audio_get_play_time(VMINT handle, VMUINT* current_time);
#endif /* __VM_SAL_BITSTREAM__ */

#endif

