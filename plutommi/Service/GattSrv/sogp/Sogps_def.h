#ifndef __SOGPS_DEF_H__
#define __SOGPS_DEF_H__

//#ifdef MMI_SRV_BT_SOGPS_PROFILE 

#include "bt_mmi.h"
#include "stack_msgs.h"
#include "SogpCommon.h"
#include "SogpsSrv.h"
#include "GattServicesFactorySrv.h"
#include "GattSrv.h"
#include "GattsSrv.h"

typedef enum {
	SOGPS_OP_INIT = 0,
	SOGPS_OP_GET_SERVICE,
	SOGPS_OP_ADD_SERVICE,
	SOGPS_OP_DEL_SERVICE,
	SOGPS_OP_DEINIT,
}SOGPS_OP_CODE;

typedef struct {
    ListEntry             conn_node;
	void                 *conn_ctx;
	int                   conn_status;
	char                  bdaddr[BD_ADDR_SIZE];
}SogpsConnCntx;

typedef struct {
	void                 *reg_ctx;
	sogps_callback_t      *callback;
	SOGP_STATUS            state;
	bt_uuid_struct        uid;
	ListEntry             conn_list; 
	int                   op_flag;
	gatts_srvs_lst_struct srv_list;
}SogpsCntx;

#endif
