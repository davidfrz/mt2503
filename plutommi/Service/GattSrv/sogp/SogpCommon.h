#ifndef __SOGP_COMMON_H__
#define __SOGP_COMMON_H__

#include "bt_mmi.h"
#include "bluetooth_gattc_struct.h"
#include "GattSrv.h"

/*
  *  Define the Find Me enable status
  *  (Locator/Target)
  *
  */
typedef U8 SOGP_STATUS;

#define SOGP_STATUS_DISABLED      0
#define SOGP_STATUS_ENABLING      1
#define SOGP_STATUS_ENABLED       2
#define SOGP_STATUS_DISABLING     3

/*
  *  Define the Find Me current connection status
  *  (Locator/Target)
  *
  */
typedef U8 SOGP_CONNECTION_STATUS;

#define SOGP_STATUS_DISCONNECTED    0
#define SOGP_STATUS_CONNECTING      1
#define SOGP_STATUS_CONNECTED       2
#define SOGP_STATUS_DISCONNECTING   3

/*
  *  Define the Find Me alert level
  *
  */
typedef U8 SOGP_ALERT_LEVEL_TYPE;

#define SOGP_ALERT_LEVEL_NO         0
#define SOGP_ALERT_LEVEL_MILD       1
#define SOGP_ALERT_LEVEL_HIGH       2

/*
  *  Define the Find Me service type
  *
  */
typedef U8 SOGP_SERVICE_TYPE;

#define IAS_SERVICE_TYPE           0  //Immediate Alert Service, 0x1802
#define SOGP_SERVICE_NUM            1  //Proximity Service Number

#define SOGP_SERVICE    0x18A0  //Immediate Alert Service, 0x1802
#define DATA_TO_READ_UUID      0x2AA0  //Alert Level Characteristic, 0x2A06
#define DATA_TO_WRITE_UUID      0x2AA1  //Alert Level Characteristic, 0x2A06


typedef struct {
	ListEntry      char_node;
	ATT_UUID       char_uuid;
}SOGPCharList;

typedef struct {
	ListEntry      svc_node;
	GATT_SVC_UUID  svc_uuid;
	ListEntry      char_list;
}SOGPSvcList;

typedef struct {
	BOOL                  isSupported;
	ListEntry             svc_list;
	ATT_VALUE             char_value;
}SOGPSrvInfo;

#endif
