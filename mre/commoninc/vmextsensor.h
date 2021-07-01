#ifndef __VM_EXTERNAL_SENSOR__
#define __VM_EXTERNAL_SENSOR__

#include "vmsys.h"
//#include "vmopt.h"

/**
 * @name MRE���Ĺ�������ݽṹ.
 * @{
 */
/**
 * �����ⲿ������, 0Ϊ�����ɹ�����Ϊ������.	
  */
typedef VMINT (*vm_start_ext_sensor_func)(void);
 /**
  * �ر��ⲿ������, 0Ϊ�����ɹ�����Ϊ������.	
  */
typedef VMINT (*vm_stop_ext_sensor_func)(void);
/**
  * ������ֵ���͵Ĵ�������ֵ, 0 Ϊ���óɹ�����Ϊ������. 
  */
typedef VMINT (*vm_set_ext_numeric_option_func)(const VMSTR control_name, VMINT opt_value);
/**
  * �����ַ����͵Ĵ�������ֵ, 0 Ϊ���óɹ����򷵻ش�����. 		
  */
typedef VMINT (*vm_set_ext_string_option_func)(const VMSTR control_name, VMSTR opt_value);
/**@} */

/**
 * MRE�����ⲿsensor�ӿڵĺ��Ĺ���ṹ.
 */
typedef struct vm_core_scb_t {
	VMCHAR sensor_name[100];							/**<������������,�����������������Ʊ��벻ͬ.
														�����淶��ο�vm_freescale_MMA7455L.h���USE_SENSOR_NAME 
														�궨��.															*/
	vm_start_ext_sensor_func start_ext_sensor;			/**<�����������ĺ���ָ��.									*/
	vm_stop_ext_sensor_func stop_ext_sensor;				/**<ֹͣ�������ĺ���ָ��.									*/
	vm_set_ext_numeric_option_func set_numeric_option;	/**<������ֵ���͵Ĵ�������ֵ.								*/
	vm_set_ext_string_option_func set_string_option;		/**<�����ַ����͵Ĵ�������ֵ.								*/
} vm_core_scb_t;

/**
 * @name vm_register_enternal_sensor�����ķ���ֵ.
 * @{
 */
 /**
  * ע���ⲿ�������ɹ�.
  */
#define VM_EXT_SENSOR_SUCCESS				(0)
/**
 * ������ע���ⲿ������������.
 */
#define VM_EXT_SENSOR_NOLIMIT				(-1)
/**
 * ����Ĳ���.
 */
#define VM_EXT_SENSOR_BADPARAM			(-2)
/**@} */

/**
 * ע���ⲿ�������ĺ��Ĺ���ṹ.
 * 
 * @param[out]				ext_handle �������������VM_EXT_SENSOR_SUCCESS, ��ô����
 *							��ext_handle������ָ�ĵ�ַд����.
 * @param[in] 				scb �ⲿ�������ĺ��Ĺ���ṹ.
 * @return					�Ƿ�ע��ɹ�����Ϊ������.
 * @retval					VM_EXT_SENSOR_SUCCESS ע��ɹ�.
 * @retval					VM_EXT_SENSOR_NOLIMIT ����MRE�������ⲿ�����������.
 * @retval					VM_EXT_SENSOR_BADPARAM ����Ĳ���.�����������ʵ��Ϊ
 *							NULL,��ô�ô����뽫�ᱻ����.
 */
VMINT vm_register_ext_sensor(VMINT* ext_handle, vm_core_scb_t* scb);

/**
 * �ⲿ�������õ�����֪ͨMRE.
 * 
 * @param[in]					ext_handle �������ľ��,�þ����vm_register_ext_sensor
 *							�����õ�.
 * @param[in]					data �ⲿ�������õ�������.
 * @param[in]					data_size ���ݵ��ֽ���.				
 */
void vm_notify_data_by_ext_sensor(VMINT ext_handle, void* data, VMUINT data_size);


#endif
