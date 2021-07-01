#ifndef __BAS_COMMON_H__
#define __BAS_COMMON_H__

#include "bt_mmi.h"
#include "bluetooth_gattc_struct.h"
#include "GattSrv.h"

/*
  *  Define the BAS enable status
  *  (Locator/Target)
  *
  */
typedef U8 BAS_STATUS;

#define BAS_STATUS_DISABLED      0
#define BAS_STATUS_ENABLING      1
#define BAS_STATUS_ENABLED       2
#define BAS_STATUS_DISABLING     3

/*
  *  Define the BAS current connection status
  *  (Locator/Target)
  *
  */
typedef U8 BAS_CONNECTION_STATUS;

#define BAS_STATUS_DISCONNECTED    0
#define BAS_STATUS_CONNECTING      1
#define BAS_STATUS_CONNECTED       2
#define BAS_STATUS_DISCONNECTING   3

/*
  *  Define the Battery service type
  *
  */
typedef U8 BAS_SERVICE_TYPE;

#define BAS_SERVICE_TYPE           0  
#define BAS_SERVICE_NUM            1

#define BAS_SERVICE    0x180F  //Battery Servic
#define BAS_LEVEL_CHAR_UUID      0x2A19  //battery Level (Characteristic)
#define BAS_CHAR_CONFIG_UUID      0x2902
#define BAS_CHAR_PRE_FMT_UUID      0x2904



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
