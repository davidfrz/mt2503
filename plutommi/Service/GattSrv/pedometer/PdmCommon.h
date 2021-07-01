#ifndef __PDMS_COMMON_H__
#define __PDMS_COMMON_H__

#include "bt_mmi.h"
#include "bluetooth_gattc_struct.h"
#include "GattSrv.h"

/*
  *  Define the Pedometer enable status
  *  (Locator/Target)
  *
  */
typedef U8 PDMS_STATUS;

#define PDMS_STATUS_DISABLED      0
#define PDMS_STATUS_ENABLING      1
#define PDMS_STATUS_ENABLED       2
#define PDMS_STATUS_DISABLING     3

/*
  *  Define the Pedometer current connection status
  *  (Locator/Target)
  *
  */
typedef U8 PDMS_CONNECTION_STATUS;

#define PDMS_STATUS_DISCONNECTED    0
#define PDMS_STATUS_CONNECTING      1
#define PDMS_STATUS_CONNECTED       2
#define PDMS_STATUS_DISCONNECTING   3

/*
  *  Define the Pedometer service type
  *
  */
typedef U8 PDMS_SERVICE_TYPE;

#define PDMS_SERVICE_TYPE           0  //PDMS Service, 0x18AA
#define PDMS_SERVICE_NUM            1  //PDMS Service Number

#define PDMS_SERVICE    0x18AA  //pedometer Service, 0x18AA
#define PDMS_CHAR_UUID      0x2AAA  //Pedometer Characteristic, 0x2AAA

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif
