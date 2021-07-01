#ifndef __BAS_DEF_H__
#define __BAS_DEF_H__


#include "bt_mmi.h"
#include "stack_msgs.h"
#include "BasCommon.h"
#include "BasSrv.h"
#include "GattServicesFactorySrv.h"
#include "GattSrv.h"
#include "GattsSrv.h"

typedef enum {
	BAS_OP_INIT = 0,
	BAS_OP_GET_SERVICE,
	BAS_OP_ADD_SERVICE,
	BAS_OP_DEL_SERVICE,
	BAS_OP_DEINIT,
}BAS_OP_CODE;

typedef struct{
	ATT_HANDLE     handle;
	ATT_VALUE      dec_value;
	BOOL            is_dec_write;
}bas_dec_struct;

typedef struct {
    ListEntry             conn_node;
	void                  *conn_ctx;
	int                   conn_status;
	char                  bdaddr[BD_ADDR_SIZE];
	bas_dec_struct        dec;
}BasConnCntx;

typedef struct {
	void                  *reg_ctx;
	//bas_callback_t             *callback;
	BAS_STATUS            state;
	bt_uuid_struct        uid;
	ListEntry             conn_list; 
	int                   op_flag;
	gatts_srvs_lst_struct srv_list;
}BasCntx;

#endif
