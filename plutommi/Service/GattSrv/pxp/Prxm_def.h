#ifndef __PRXM_DEF_H__
#define __PRXM_DEF_H__

//#ifdef MMI_SRV_BT_PRXM_PROFILE 

#include "bt_mmi.h"
#include "stack_msgs.h"
#include "PrxCommon.h"
#include "PrxmSrv.h"
#include "GattSrv.h"
#include "GattcSrv.h"

#define PRXM_OP_IDLE            0x00
#define PRXM_OP_WRITE_LLS_CHAR  0x01
#define PRXM_OP_READ_TPS_CHAR   0x02
#define PRXM_OP_WRITE_IAS_CHAR  0x04

typedef struct {
    ListEntry             conn_node;
	void                 *conn_ctx;
	int                   conn_status;
	BOOL                  start;
	int                   flag;
	char                  bdaddr[BD_ADDR_SIZE];
	PrxSrvInfo            srv_info[PRX_SERVICE_NUM];
}PrxmConnCntx;

typedef struct {
	void                 *reg_ctx;
	prxm_callback_t      *callback;
	PRX_STATUS            state;
	bt_uuid_struct        uid;
	ListEntry             conn_list;              
}PrxmCntx;

//#endif

#endif
