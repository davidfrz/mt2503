/***********************************************************************
  * ģ�����������ʵ�ֵĺ�������Щ�����ṩ�˹���ģ��
  * �������ڵĹ��ܡ���MRE�������ģ�鶼��������״̬��
  * ������״̬�ֱ��Ӧ:
  *
  * (1) INIT_STATE
  * ��MRE��û��������ʱ�����ģ�鴦�ڸ�״̬���ڸ�״̬��
  * ����ģ���ṩ�ķ����ǿ�ѡ��ġ�MRE�еĸ�������ģ���
  * �Բ��ṩ�κη���Ҳ����ѡ���ṩ���ֻ�ȫ���ķ���
  * ������ṩ�������ģ���ڱ�״̬��Ӧ�ò�������
  * ����ģ���ʵ�֣���Ϊ��INITAL_STATE�£�����ģ���ṩ��
  * ������û�б�֤�ġ�
  *
  * (2) RUNNING_STATE
  * ��ϵͳ����INIT_STATE�£���ģ���յ�EVT_MOD_INIT��Ϣ��ģ���
  * Ӧ�ù��ɵ�RUNNING_STATE�£�������ģ�鴦��FREEZING_STATE��ʱ��
  * �յ�EVT_MOD_ACTIVE��Ϣ����ôģ��Ҳ�ᴦ��RUNNING_STATE
  * ״̬�¡��ڸ�״̬�£�MRE�ڲ���ģ��Ӧ���ṩȫ���ķ����ܡ�
  *
  * (3) FREEZING_STATE
  * ��ģ���յ���EVT_MOD_ACTIVE��Ϣ��MREģ���Ӧ���л���FREEZING_STATE
  * ״̬���ڸ�״̬��ģ������ṩ�ķ����ǲ�ȷ���ģ�������֤�ġ�
  * Ӧ�ó������յ�MRE������INACTIVE��Ϣ��Ӧ���ٵ���MRE�κ�ģ���ṩ
  * ���κη�����Ϊ��Ӧ�ó����յ�����Ϣ�����е�ģ�鶼�Ѵ���
  * FREEZING_STATE���ˡ�ֱ��ģ���յ�EVT_MOD_ACTIVE������ģ��͹��ɵ�
  * RUNNING_STATE״̬���յ�EVT_MOD_RELEASE��Ϣ��ģ��͹��ɵ�INIT_STATE״̬
  * ���ˡ�
  *
  * copyright vogins.co
  * version 1.2.0
  *
  **********************************************************************/

#ifndef MODULE_H
#define MODULE_H
  #include "vmswitch.h"
#ifdef __MRE_CORE_BASE__

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  * MRE����ģ������������¼���
  */
typedef enum {EVT_MOD_INIT = 1, EVT_MOD_ACTIVE, EVT_MOD_INACTIVE, EVT_MOD_RELEASE} MRE_MOD_LIFECIRCLE_EVT;

/*
  * ����ģ�鴦���������͡�
  */
typedef VMINT (*MOD_EVT_PROCESS)(MRE_MOD_LIFECIRCLE_EVT);

/*
  * ע��ģ��ɹ���
  */
#define REG_MRE_MODULE_SUCCESS						0

/*
  * ������ϵͳ���ܽ��ܵ�����ģ����Ŀ��
  */
#define OVERFLOW_MAX_MODULE_NUM_ERROR			1

/*
  * ģ������ƺ��Ѿ�ע�ᵽϵͳ��ģ��������ͬ��
  */
#define MRE_MODULE_NAME_CONFLICT_ERROR			2

/*
  * ģ�������û��ָ���Ĵ���
  */
#define MRE_MODULE_NAME_NOT_EXISTS_ERROR			3

/**
 * ע��һ��MREģ�顣MRE�е�ÿ��ģ�鶼Ӧ�õ�������������Լ�ע�ᵽϵͳ�С�
 * �ڽ���MRE��������ǰ��MRE�������ᰴģ��ע���˳�����ΰ�ģ�����������
 * �¼�֪ͨ����ģ�顣��ǰ��ģ�鴦�����ķ���ֵֻ����ģ�鴦��EVT_MOD_INIT
 * ��ʱ����Ч������0����ʾ�ɹ������˸�����������Ϣ�����򷵻ش����롣��
 * ��һ��ģ���ڴ���EVT_MOD_INIT��ʱ�򷵻ش�����ôģ���������ᷢ�͸���
 * ����RUNNING_STATE״̬��ģ��EVT_MOD_RELEASE��Ϣ�������˳�MREϵͳ��
 * 
 * 
 * @param name			ģ������ƣ���ģ�����Ʊ�����ָ����ģ���������Ѿ�ע���ģ��������ͬ��
 *						��ô�������᷵�أ��ж��Ǵ�Сд���еġ�����ģ�����Ʊ���
 *						����ֵ�ģ�Ҳ����˵strlen(name)  > 0 ������TRUE��
 * @param process			ģ��ע�ᵽģ��������ϵ�ģ�����������ϵĴ�������		
 *
 * @return
 */
VMINT _vm_reg_module(VMSTR name, MOD_EVT_PROCESS process);

/**
 * ע�����е�ģ�顣
 */
VMINT _vm_reg_modules(void);

/**
 * ģ��������״̬���͡�
 */
typedef enum {
	MOD_STATUS_SHUTDOWN,
	MOD_STATUS_RUNNING,
	MOD_STATUS_PAUSE
} MRE_MOD_STATUS;

/**
 * �õ�ģ��������״̬��
 */
MRE_MOD_STATUS _vm_get_status(void);

/**
  * ֪ͨģ��������ڵ�ģ�����������¼���
  * 
  * 
  * @param event			��Ҫ֪ͨ��ģ������������¼���
  * 
  */
VMINT _vm_notify_modules(MRE_MOD_LIFECIRCLE_EVT event);


/**
  * ��ʼ��ģ��������õ�����Դ�������ڵ���_vm_setup_modules����
  * ǰ���á�
  */
void _vm_initizlize_module_manager(void);

/**
  * ����ģ��������õ�����Դ�������ڵ���_vm_cleanup_modules������
  * ���á�
  */
void _vm_destory_module_manager(void);

#ifdef __cplusplus
}
#endif

#endif
#endif

