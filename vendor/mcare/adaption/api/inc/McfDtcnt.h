#ifndef _mcfdtcnt_h_
#define _mcfdtcnt_h_

#include "McfCommon.h"

//ÿ��ƽ̨��ʵ�ֵĺ���
MBOOL McfDtcnt_OpenNetworkBearer(McfDtcntInfo *pDataAcct);
MBOOL McfDtcnt_CloseNetworkBearer(McfDtcntInfo *pDataAcct);
MINT McfDtcnt_IsNetworkReady(MVOID);
MBOOL McfDtcnt_GetApnInfo(MApnInfo *pApnInfo,MINT simId);


//�ڲ�ʹ�ú���������ƽ̨����Ҫʵ��
McfDtcntInfo *McfDtcnt_GetDataAcctInfo(MVOID);
MBOOL McfDtcnt_HoldNetworkBearer(McfDtcntInfo *pDataAcct);

MINT McfDtcnt_EntrySelection(MVOID *pParam);
MINT McfDtcnt_GetProxyInfo(MCHAR *pProxy,MINT nLen,MUSHORT *pPort);

#endif
