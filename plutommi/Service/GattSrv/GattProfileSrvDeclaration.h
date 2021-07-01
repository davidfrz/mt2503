#ifndef __GATT_PROFILE_SRV_DECL_H__
#define __GATT_PROFILE_SRV_DECL_H__

#include "GattServicesFactorySrv.h"


static gatts_profile_srv_decl_struct g_anp_srv_decl[] =
{
    {TYPE_SERVICE, "00001811-0000-1000-8000-00805f9b34fb", TRUE, 0, 0},
    {TYPE_CHARACTERISTIC, "00002a47-0000-1000-8000-00805f9b34fb", FALSE, GATT_CHAR_PROP_READ, GATT_PERM_READ},
    {TYPE_CHARACTERISTIC, "2a46", FALSE, GATT_CHAR_PROP_NOTIFY, GATT_PERM_READ},
    {TYPE_DESCRIPTOR, "2902", FALSE, 0, (GATT_PERM_READ | GATT_PERM_WRITE)},
    {TYPE_CHARACTERISTIC, "2a48", FALSE, GATT_CHAR_PROP_READ, GATT_PERM_READ},
    {TYPE_CHARACTERISTIC, "2a45", FALSE, GATT_CHAR_PROP_NOTIFY, 0},
    {TYPE_DESCRIPTOR, "2902", FALSE, 0, (GATT_PERM_READ | GATT_PERM_WRITE)},
    {TYPE_CHARACTERISTIC, "2A44", FALSE, GATT_CHAR_PROP_WRITE, GATT_PERM_WRITE},
};

static gatts_profile_srv_decl_struct g_prx_srv_decl[] =
{
    {TYPE_SERVICE, "00001803-0000-1000-8000-00805f9b34fb", TRUE, 0, 0},
    {TYPE_CHARACTERISTIC, "00002A06-0000-1000-8000-00805f9b34fb", FALSE, (GATT_CHAR_PROP_WRITE|GATT_CHAR_PROP_READ), (GATT_PERM_READ | GATT_PERM_WRITE)},
    {TYPE_SERVICE, "00001804-0000-1000-8000-00805f9b34fb", TRUE, 0, 0},
    {TYPE_CHARACTERISTIC, "00002A07-0000-1000-8000-00805f9b34fb", FALSE, GATT_CHAR_PROP_READ, GATT_PERM_READ},
    {TYPE_SERVICE, "00001802-0000-1000-8000-00805f9b34fb", TRUE, 0, 0}, //IAS
    {TYPE_CHARACTERISTIC, "00002A06-0000-1000-8000-00805f9b34fb", FALSE, GATT_CHAR_PROP_WRITE_WO_RESPONSE, GATT_PERM_WRITE}, //Alert Level
#ifdef MMI_BLE_IAS_ALERT_STATUS_CHAR
    {TYPE_CHARACTERISTIC, "00002ABC-0000-1000-8000-00805f9b34fb", FALSE, GATT_CHAR_PROP_NOTIFY, GATT_PERM_READ}, //Alert Status
#endif
};

static gatts_profile_srv_decl_struct g_fmp_srv_decl[] =
{
    {TYPE_SERVICE, "00001802-0000-1000-8000-00805f9b34fb", TRUE, 0, 0},
    {TYPE_CHARACTERISTIC, "00002A06-0000-1000-8000-00805f9b34fb", FALSE, GATT_CHAR_PROP_WRITE_WO_RESPONSE, GATT_PERM_WRITE}, //Alert Level
#ifdef MMI_BLE_IAS_ALERT_STATUS_CHAR
    {TYPE_CHARACTERISTIC, "00002ABC-0000-1000-8000-00805f9b34fb", FALSE, GATT_CHAR_PROP_NOTIFY, GATT_PERM_READ}, //Alert Status
#endif
};

static gatts_profile_srv_decl_struct g_sogp_srv_decl[] =
{
    {TYPE_SERVICE, "000018A0-0000-1000-8000-00805f9b34fb", TRUE, 0, 0},
    {TYPE_CHARACTERISTIC, "00002AA0-0000-1000-8000-00805f9b34fb", FALSE, GATT_CHAR_PROP_READ | GATT_CHAR_PROP_INDICATE, GATT_PERM_READ},
    {TYPE_CHARACTERISTIC, "00002AA1-0000-1000-8000-00805f9b34fb", FALSE,  GATT_CHAR_PROP_WRITE, GATT_PERM_WRITE},
};
/*add for Pedometer begain*/
static gatts_profile_srv_decl_struct g_pedometer_srv_decl[] =
{
    {TYPE_SERVICE, "000018AA-0000-1000-8000-00805f9b34fb", TRUE, 0, 0},
    {TYPE_CHARACTERISTIC, "00002AAA-0000-1000-8000-00805f9b34fb", FALSE, (GATT_CHAR_PROP_WRITE | GATT_CHAR_PROP_INDICATE), GATT_PERM_WRITE},
};
/*add for Pedometer end*/

/*add for BAS begain*/
static gatts_profile_srv_decl_struct g_bas_srv_decl[] =
{
    {TYPE_SERVICE, "0000180F-0000-1000-8000-00805f9b34fb", TRUE, 0, 0},
    {TYPE_CHARACTERISTIC, "00002A19-0000-1000-8000-00805f9b34fb", FALSE, (GATT_CHAR_PROP_READ | GATT_CHAR_PROP_NOTIFY), GATT_PERM_READ},
    {TYPE_DESCRIPTOR, "00002902-0000-1000-8000-00805f9b34fb", FALSE, 0, (GATT_PERM_READ | GATT_PERM_WRITE)},
	{TYPE_DESCRIPTOR, "00002904-0000-1000-8000-00805f9b34fb", FALSE, 0, GATT_PERM_READ},
};
/*add for BAS end*/

extern const gatt_profile_decl_tbl  g_profile_decl_tbl[] =
{
	{PROFILE_ID_FINDME, g_fmp_srv_decl, sizeof(g_fmp_srv_decl)/sizeof(g_fmp_srv_decl[0])},
	{PROFILE_ID_PXP, g_prx_srv_decl, sizeof(g_prx_srv_decl)/sizeof(g_prx_srv_decl[0])},
    {PROFILE_ID_ANP, g_anp_srv_decl, sizeof(g_anp_srv_decl)/sizeof(g_anp_srv_decl[0])},
    {PROFILE_ID_SOGP, g_sogp_srv_decl, sizeof(g_sogp_srv_decl)/sizeof(g_sogp_srv_decl[0])},
/*add for Pedometer begain*/      
	{PROFILE_ID_PEDOMETER, g_pedometer_srv_decl, sizeof(g_pedometer_srv_decl)/sizeof(g_pedometer_srv_decl[0])},
/*add for Pedometer end*/
/*add for BAS begain*/      
	{PROFILE_ID_BAS, g_bas_srv_decl, sizeof(g_bas_srv_decl)/sizeof(g_bas_srv_decl[0])},
/*add for BAS end*/
};

#ifdef MMI_SRV_CHECK_SERVICE_UUID
#define MAX_PROFILE_CNT         (25)
#define DEFAULT_PROFILE_ID      (-1)
#define PROFILE_BASE_UUID       "00000000-0000-1000-8000-00805f9b34fb"
#endif


#endif
