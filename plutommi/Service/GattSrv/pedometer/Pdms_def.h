#ifndef __PDMS_DEF_H__
#define __PDMS_DEF_H__

//#ifdef MMI_SRV_BT_SOGPS_PROFILE 

#include "bt_mmi.h"
#include "stack_msgs.h"
#include "PdmCommon.h"
#include "PdmsSrv.h"
#include "GattServicesFactorySrv.h"
#include "GattSrv.h"
#include "GattsSrv.h"

typedef enum {
	PDMS_OP_INIT = 0,
	PDMS_OP_GET_SERVICE,
	PDMS_OP_ADD_SERVICE,
	PDMS_OP_DEL_SERVICE,
	PDMS_OP_DEINIT,
}PDMS_OP_CODE;

typedef struct {
    ListEntry             conn_node;
	void                 *conn_ctx;
	int                   conn_status;
	char                  bdaddr[BD_ADDR_SIZE];
}PdmsConnCntx;

typedef struct {
	void                 *reg_ctx;
	pdms_callback_t      *callback;
	PDMS_STATUS           state;
	bt_uuid_struct        uid;
	ListEntry             conn_list; 
	int                   op_flag;
	gatts_srvs_lst_struct srv_list;
}PdmsCntx;

#endif
