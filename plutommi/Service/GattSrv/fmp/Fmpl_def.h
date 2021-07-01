#ifndef __FMPL_DEF_H__
#define __FMPL_DEF_H__

#include "bt_mmi.h"
#include "stack_msgs.h"
#include "FmpCommon.h"
#include "FmplSrv.h"
#include "GattSrv.h"
#include "GattcSrv.h"

#define FMPL_OP_IDLE            0x00
#define FMPL_OP_WRITE_IAS_CHAR  0x01

typedef struct {
    ListEntry             conn_node;
	void                 *conn_ctx;
	int                   conn_status;
	BOOL                  start;
	int                   flag;
	char                  bdaddr[BD_ADDR_SIZE];
	FmpSrvInfo            srv_info;
}FmplConnCntx;

typedef struct {
	void                 *reg_ctx;
	fmpl_callback_t      *callback;
	FMP_STATUS            state;
	bt_uuid_struct        uid;
	ListEntry             conn_list;              
}FmplCntx;

#endif
