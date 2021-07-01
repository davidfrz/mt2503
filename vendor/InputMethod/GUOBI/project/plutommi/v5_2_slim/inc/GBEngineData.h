#ifndef __GBENGINE_DATA_H
#define __GBENGINE_DATA_H
#include "gbtype.h"
#include "gbdef.h"
#include "GBIMEDef.h"

/*
  * 	���������ļ�
  *
  *	�����ݸ��ݶ�Ӧ���ʿ������뷨�����ְ�ܼ��أ��������޸Ĺ���ģ��Ľű�
  */
// ��������
#ifdef GBIME_CFG_STATIC_DB // ʹ�þ�̬����
	#ifndef _C166
	#define _huge
	#endif //_C166

#ifdef GBIME_USE_GBK_DB
	extern const unsigned long prv_gbkDataArray[];
#else
	#ifdef __MMI_GB_SM_CHINESE__   //������������
		extern const unsigned long prv_scDataArray[];
	#endif

	#ifdef __MMI_GB_TR_CHINESE__  //������������
		extern const unsigned long prv_bpmf_dataArray[];
	#endif
#endif

#ifdef __MMI_GB_ENGLISH__  // Ӣ������
	extern const unsigned long prv_enDataArray[];
#endif

#ifdef  __MMI_GB_ARABIC__  // ������������
	extern const unsigned long prv_arDataArray[];
#endif

#ifdef  __MMI_GB_THAI__    //  ̩������
	extern const unsigned long prv_thDataArray[];
#endif

#ifdef  __MMI_GB_GREEK__  	// ϣ��������
	extern const unsigned long prv_elDataArray[];
#endif

#ifdef  __MMI_GB_TURKISH__ // ������������
	extern const unsigned long  prv_trDataArray[];
#endif

#ifdef  __MMI_GB_VIETNAMESE__ 	// Խ��������
	extern const unsigned long  prv_viDataArray[];
#endif

#ifdef  __MMI_GB_FRENCH__	 //��������
	extern const unsigned long  prv_frDataArray[];
#endif

#ifdef  __MMI_GB_RUSSIAN__	// ��������
	extern const unsigned long  prv_ruDataArray[];
#endif

#ifdef  __MMI_GB_KAZAKH__	// ����������
	extern const unsigned long  prv_kk_arDataArray[];
#endif

#ifdef  __MMI_GB_SPANISH__	// ������������
	extern const unsigned long  prv_esDataArray[];
#endif

#ifdef  __MMI_GB_PORTUGUESE__	// ������������
	extern const unsigned long  prv_ptDataArray[];
#endif

#ifdef  __MMI_GB_SA_SPANISH__	//���� ������������
	extern const unsigned long  prv_essDataArray[];
#endif

#ifdef  __MMI_GB_SA_PORTUGUESE__	//���� ������������
	extern const unsigned long  prv_ptsDataArray[];
#endif

#ifdef  __MMI_GB_GERMAN__	// ��������
	extern const unsigned long  prv_deDataArray[];
#endif

#ifdef  __MMI_GB_PERSIAN__	// ��˹������
	extern const unsigned long  prv_faDataArray[];
#endif

#ifdef  __MMI_GB_ITALIAN__	// �����������
	extern const unsigned long  prv_itDataArray[];
#endif

#ifdef  __MMI_GB_KOREAN__	// ��������
	extern const unsigned long  prv_korean_DataArray[];
#endif

#ifdef __MMI_GB_HINDI__		//ӡ��������
	extern const unsigned long  prv_hiDataArray[];
#endif

#ifdef __MMI_GB_BENGALI__		//�ϼ���������
	extern const unsigned long  prv_bnDataArray[];
#endif

#ifdef __MMI_GB_TAMIL__		//̩�׶�������
	extern const unsigned long  prv_tmDataArray[];
#endif


#ifdef __MMI_GB_MALAY__	//��������������
	extern const unsigned long  prv_msDataArray[];
#endif

#ifdef __MMI_GB_BULGARIAN__	//��������������
	extern const unsigned long  prv_bgDataArray[];
#endif

#ifdef __MMI_GB_INDONESIAN__	//ӡ��������������
	extern const unsigned long  prv_idDataArray[];
#endif

#ifdef  __MMI_GB_CROATIAN__		// ���޵�����
	extern const unsigned long  prv_hrDataArray[];
#endif

#ifdef  __MMI_GB_CZECH__		// �ݿ���
	extern const unsigned long prv_csDataArray[];
#endif

#ifdef  __MMI_GB_DANISH__		// ������
	extern const unsigned long  prv_daDataArray[];
#endif

#ifdef  __MMI_GB_DUTCH__		// ������
	extern const unsigned long  prv_nlDataArray[];
#endif

#ifdef  __MMI_GB_ESTONIAN__		// ��ɳ������
	extern const unsigned long  prv_etDataArray[];
#endif

#ifdef  __MMI_GB_HUNGARIAN__	// ��������
	extern const unsigned long  prv_huDataArray[];
#endif

#ifdef  __MMI_GB_LATVIAN__		// ����ά����
	extern const unsigned long  prv_lvDataArray[];
#endif

#ifdef  __MMI_GB_LITHUANIAN__	// ��������
	extern const unsigned long  prv_ltDataArray[];
#endif

#ifdef  __MMI_GB_NORWEGIAN__	// Ų����
	extern const unsigned long  prv_noDataArray[];
#endif

#ifdef  __MMI_GB_POLISH__		// ������
	extern const unsigned long  prv_psDataArray[];
#endif

#ifdef  __MMI_GB_PUNJABI__		// ��������
	extern const unsigned long  prv_paDataArray[];
#endif

#ifdef  __MMI_GB_ROMANIAN__		// ����������
	extern const unsigned long  prv_roDataArray[];
#endif

#ifdef  __MMI_GB_SERBIAN__		// ����ά����
	extern const unsigned long  prv_srDataArray[];
#endif

#ifdef  __MMI_GB_SLOVAK__		// ˹ŵ������
	extern const unsigned long  prv_skDataArray[];
#endif

#ifdef  __MMI_GB_SWAHILI__		// ˹��������
	extern const unsigned long  prv_swDataArray[];
#endif

#ifdef  __MMI_GB_SWEDISH__		// �����
	extern const unsigned long  prv_svDataArray[];
#endif

#ifdef  __MMI_GB_FILIPINO__		// ���ɱ���
	extern const unsigned long  prv_phDataArray[];
#endif

#ifdef  __MMI_GB_URDU__			// �ڶ�����
	extern const unsigned long  prv_urDataArray[];
#endif

#ifdef  __MMI_GB_HEBREW__		// ϣ������
	extern const unsigned long  prv_heDataArray[];
#endif

#ifdef  __MMI_GB_UKRAINIAN__		// �ڿ�����
	extern const unsigned long  prv_ukDataArray[];
#endif

#ifdef  __MMI_GB_TELUGU__		// ̩¬����
	extern const unsigned long  prv_teDataArray[];
#endif

#ifdef  __MMI_GB_FINNISH__		// ������
	extern const unsigned long  prv_fiDataArray[];
#endif

#ifdef  __MMI_GB_SLOVENIAN__	// ˹ŵ��������
	extern const unsigned long  prv_slDataArray[];
#endif

#ifdef  __MMI_GB_ALBANIAN__		// ������������
	extern const unsigned long  prv_sqDataArray[];
#endif

#ifdef  __MMI_GB_ICELANDIC__		// ������
	extern const unsigned long  prv_isDataArray[];
#endif

#ifdef  __MMI_GB_GUJARATI__		// �ż�������
	extern const unsigned long  prv_guDataArray[];
#endif

#ifdef  __MMI_GB_AZERBAIJANI__	// �����ݽ���
	extern const unsigned long  prv_azDataArray[];
#endif

#ifdef  __MMI_GB_MACEDONIAN__	// �������
	extern const unsigned long  prv_mkDataArray[];
#endif

#ifdef  __MMI_GB_MARATHI__		// ��������
	extern const unsigned long  prv_mrDataArray[];
#endif

#ifdef  __MMI_GB_AFRIKAANS__	// �Ϸ���(������)
	extern const unsigned long  prv_afDataArray[];
#endif

#ifdef  __MMI_GB_BASQUE__		// ��˹����
	extern const unsigned long  prv_euDataArray[];
#endif
//other language database....

/*
  *....................��������������������ݣ��ɲο��ϴ���
  *
  */
#endif // GBIME_CFG_STATIC_DB

/*!
 * \brief ��ȡ��UDB����ָ��
 * \return 
 */
GBLPCVOID GBEngineData_GetMasterUDBData(void);

/*!
 * \brief ��ȡ��UDB����ָ��
 * \return 
 */
GBLPCVOID GBEngineData_GetSlaveUDBData(void);

/*!
 * \brief ��ȡ��UDB���ݴ�С
 * \return 
 */
unsigned long GBEngineData_GetMasterUDBDataSize(void);

/*!
 * \brief ��ȡ��UDB���ݴ�С
 * \return 
 */
unsigned long GBEngineData_GetSlaveUDBDataSize(void);

#endif //__GBENGINE_DATA_H