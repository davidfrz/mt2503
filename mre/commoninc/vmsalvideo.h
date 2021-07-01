#ifndef _VM_SAL_VIDEO_H
#define _VM_SAL_VIDEO_H
#include "vmswitch.h"
#ifdef __MRE_SAL_VIDEO__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmvideo.h"

	#include "vmsys.h"

 /**
 *	����Ƶ�ļ�	
 *	@param filename			����·�����ļ�����
 *    @param open_result_callback	�ص�������
 *	@return 			
 *  		VM_VIDEO_SUCCESS : ���ļ��ɹ���
 *  		VM_VIDEO_ERR_DRM_PROHIBITED : ���ܴ���Ƶ�ļ���drm����ֹ��
 *  		VM_VIDEO_ERR_MEMORY_INSUFFICIENT : ���ܴ���Ƶ���ڴ治�㡣
 *  		VM_VIDEO_ERR_FILE_TOO_LARGE : ���ܴ���Ƶ���ļ�̫��
 *  		VM_VIDEO_ERR_FRAMERATE_TOO_HIGH : ���ܴ���Ƶ��֡��̫�ߡ�
 *		VM_VIDEO_ERR_INVALID_RESOULTION: ���ܴ���Ƶ��ֱ��ʲ��ԡ�
 *  		VM_VIDEO_ERR_OPEN_FILE_FAILED : ����ԭ���ܴ���Ƶ��
 */
 VMINT stub_video_open_file(
                    const VMWSTR filename,
                    vm_video_open_result_callback open_result_callback);


 /**
 *	�ر���Ƶ�ļ���	
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ر��ļ��ɹ���
 *  		VM_VIDEO_FAILED : �ر��ļ�ʧ�ܡ�
 */
 VMINT stub_video_close_file(void);


 /**
 *	ʹ��ָ���������ݴ���Ƶ��
 *    @param buffer	��Ƶ��������ָ�롣
 *    @param buffer_len	���泤�ȡ�
 *    @param info		�õ�����Ƶ��Ϣ�ṹ��
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �򿪳ɹ���
 *  		VM_VIDEO_ERR_MEMORY_INSUFFICIENT : û���㹻�ڴ��ʧ�ܡ�
 *  		VM_VIDEO_ERR_FRAMERATE_TOO_HIGH : ֡��̫�ߴ�ʧ�ܡ�
 *  		VM_VIDEO_ERR_OPEN_FILE_FAILED : ��ʧ�ܡ�
 */
  VMINT stub_video_open_buffer(
                    const VMUSTR buffer,
                    const VMUINT buffer_len,
                    vm_video_info_struct *info);
 
                    
 /**
 *	�ر���Ƶ�������ݣ���vm_video_open_buffer�ɶ�ʹ�á�
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ر��ļ��ɹ���
 *  		VM_VIDEO_FAILED : �ر��ļ�ʧ�ܡ�
 */
 VMINT stub_video_close_buffer(void);


 /**
 *	����Ƶ������ƽ̨����֧��3gp/mp4����
 *    ���Žӿ���Ҫ֪����ĵ���˳������뱣֤ʹ��ǰ�ѽ��й�vm_graphic_flush_layer������������ܻ�����
 *    @param player_layer_handle		���Ų�ľ��������ʹ�õ�һ�δ�����ʱ���صľ������
 *   @param base_layer_handle		���߲�ľ��������ʹ�õڶ��δ�����ʱ���صľ������
 *    @param repeat_count			�ظ����Ŵ�����0��ʾ�ظ����š�
 *    @param is_play_audio			�Ƿ񲥷���Ƶ��TRUE/FALSE ����
 *    @param audio_path			��Ƶ����·����ʹ��vmmm.h�ж��壬��VM_DEVICE_SPEAKER2����
 *    @param rotate				��ת�Ƕȣ��磺VM_VIDEO_LCD_ROTATE_0����
 *    @param play_finish_callback		�ص�������
 *	@return 			
 *  		VM_VIDEO_SUCCESS : ��ʼ���ųɹ���
 *  		VM_VIDEO_ERR_DRM_PROHIBITED :�����ְ�Ȩ���ܴ���Ƶ�ļ���
 *  		VM_VIDEO_PROGRESSIVE_FILE_NOT_ENOUGH : ���ݲ������������š�
 *  		VM_VIDEO_ERR_PLAY_FAILED : ����ʧ�ܡ�
 */
 VMINT stub_video_play(
                    VMUINT player_layer_handle,
                    VMUINT base_layer_handle,
                    VMUINT16 repeat_count, 
                    VMINT is_visual_update,
                    VMINT is_play_audio,
                    VMINT audio_path, 
                    VMUINT16 rotate, 
                    VMUINT16 play_speed,
                    vm_video_finish_callback play_finish_callback);


/**
 *	 ֹͣ���š�
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ر��ļ��ɹ���
 *		VM_VIDEO_FAILED : ֹͣʧ�ܡ�
 */
 VMINT stub_video_stop(void);



 /**
 *	��λ��Ƶ��ָ��ʱ��㲢��ʾ��ʱ��㻭�档
 *    @param time		ʱ�� �����룩��
 *    @param player_layer_handle		���Ų�����
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
 VMINT stub_video_seek_and_getframe(VMUINT64 time, VMUINT player_layer_handle);


 /**
 *	ץͼ����Ϊָ�����ļ����ļ���ʽJPEG��
 *    @param player_layer_handle		���Ų�����
 *    @param file_name			������ļ���(UCS2)��.
 *	@return 			
 *  		VM_VIDEO_SUCCESS : ץͼ�ɹ���
 *  		VM_VIDEO_ERR_SNAPSHOT_DISK_FULL : ����������ץͼʧ�ܡ�
 *  		VM_VIDEO_ERR_SNAPSHOT_WRITE_PROTECTION : д������ץͼʧ�ܡ�
 * 		VM_VIDEO_ERR_SNAPSHOT_FAILED : ץͼʧ�ܡ�
 */
 VMINT stub_video_snapshot(VMUINT player_layer_handle, VMWSTR file_name);



 /**
 *	�������ȣ��رպ󲻱��档
 *    @param brightness			����ֵ����:VM_VIDEO_BRIGHTNESS_0 ����
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
 VMINT stub_video_set_brightness(VMUINT16 brightness);


 /**
 *	 ���öԱȶȣ��رպ󲻱��档
 *    @param contrast			����ֵ(��:VM_VIDEO_CONTRAST_0)��
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
 VMINT stub_video_set_contrast(VMUINT16 contrast);



 /**
 *	 �õ�Ŀǰ�Ĳ���ʱ�䡣
 *    @param cur_play_time			���ص�ǰ����ʱ�䡣
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
 VMINT stub_video_get_cur_play_time(VMUINT64 *cur_play_time); 

/**
 *	����URL ������ý����Ƶ(���ѵ��õ�MREAPP �е���̨���¿�SCREEN ����MTK ����Ƶ������)��
 *    @param url			Ҫ�򿪵���ƵURL��
 *
 *	@return
 *		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
VMINT vm_sal_video_play_stream_from_rtsp_link(VMWSTR url);

/**
 *	��sdp ��ʽ����ý����Ƶ(���ѵ��õ�MREAPP �е���̨���¿�SCREEN ����MTK ����Ƶ������)��
 *    @param filename		��sdp ��ʽ���ļ���
 *	@param is_short		�Ƿ�Ϊ8.3 ��ʽ�Ķ��ļ�����TUREΪ�ǣ�FALSEΪ��	
 *
 *	@return
 *		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
VMINT vm_sal_video_play_stream_from_sdp_file(VMWSTR filename, VMUCHAR is_short);


/*
* �������ֹ���
*/

/*
* ��������resume
*/


#ifdef __cplusplus
}
#endif

#endif

#endif
