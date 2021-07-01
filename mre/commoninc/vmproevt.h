#ifndef	_VM_PRO_EVT_
#define _VM_PRO_EVT_

#include "vmswitch.h"

#ifdef __MRE_CORE_BASE__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"


/**
 * ���̹������������¼�����Ϣ�� 
 * 
 * @param[in]					vmKeyCode �����ļ�ֵ��
 * @param[in]					vmKeyEvent �������¼���
 * @return					�Ƿ��н��̴�����¼���
 * @retval					TRUE �н��̴����˸��¼���
 * @retval					FALSE û�н��̴�����¼���
 */
VMINT vm_pmng_deal_key_event(VMINT vmKeyCode, VMINT vmKeyEvent);

/**
 * ���̹���������ʴ��¼�����Ϣ��
 * 
 * @param[in]					vmPenEvent �ʴ��¼���
 * @param[in]					x X����ֵ��
 * @param[in]					y Y����ֵ��
 * @return					�Ƿ��н��̴�����¼���
 * @retval					TRUE �н��̴����˸��¼���
 * @retval					FALSE û�н��̴�����¼���
 */
VMINT vm_pmng_deal_pen_event(VMINT vmPenEvent, VMINT x, VMINT y);

/**
 * ���̹����������T�����¼���
 *  
 * @param[out]				���˳��Ľ��̸�����
 * @return					�������еĽ��̸�����
 */
VMUINT vm_pmng_deal_card_plug_out_event(VMUINT* exitProcessNum);

#ifdef __cplusplus
}
#endif 
#endif

#endif
