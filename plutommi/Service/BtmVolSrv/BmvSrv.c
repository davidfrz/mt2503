//#ifdef MMI_SRV_BT_FMPL_PROFILE 
#ifdef __BT_GATTC_PROFILE__ 
#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "GattSrv.h"
#include "GattcSrv.h"
#include "BTcmSrvGprot.h"
#include "bmvsrvGprot.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "BLEsrvGprot.h"
#include "mmi_rp_srv_blecm_def.h"
#include "blesrvgprot.h" // srv_ble_cm_get_connected_dev_num
#include "mmi_media_app_trc.h"

typedef struct
{
    MMI_BOOL is_smatch;  // srv is match;
    GATT_SVC_UUID srv_id;// srv uuid ;
}srv_bms_info_struct;

typedef struct
{
    MMI_BOOL valid;
    MMI_BOOL need_reg;
    MMI_BOOL registered;
    MMI_BOOL descriptor;
    BOOL des_writed;
    U8 des_len;
    ATT_UUID char_uuid;
    ATT_UUID descr_uuid;
} srv_bmchar_info_struct;

typedef struct
{
    void *conn_cntx;
    U8 flag;                  /*0x01: used*/
    U8 dev_state; /*every device status*/
    U8 index;
    U8          is_exist;
    BD_ADDR     daddr;
    srv_bms_info_struct srv_info[2];
    srv_bmchar_info_struct char_info[2];
} srv_bm_dev_info_struct;

typedef enum
{
    BM_ADDRESS,
    BM_CONN_CNTX,
}srv_bm_query_type_enum;

typedef struct {
    void    *reg_ctx;
    U8       re_state;//  all status
    //U8       conn_state;
    //U8       search_state;
    //ATT_VALUE char_value;
    bt_uuid_struct        uid;  // app user id
    //char           daddr[BD_ADDR_SIZE]; // mutilink
    //ATT_UUID char_info;
    //GATT_SVC_UUID  svc_uuid; 
    //MMI_BOOL type; /* no use*/
    srv_bm_dev_info_struct bm_info[4];//device info  

}srv_btmusic_cntx_struct;

srv_btmusic_cntx_struct* srv_bm_vol_get_cur_state();

void bm_register_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);
void bm_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);
void bm_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status);

void bm_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                           gattc_char_struct *char_info, GATT_CHAR_PROPERTIES properties);
void bm_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                            gattc_char_struct *char_info);
void bm_connect (BD_ADDR * bd_addr);
void bm_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *svc_uuid);

mmi_ret bm_music_cm_disconnect_hdlr(mmi_event_struct *para);

void mmi_bt_event_notify_btmusic_client(U32 event, void* para); 

void bm_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src);

void bm_research_service_callback(gatt_conn_struct *conn, OS_STATUS status, BD_ADDR *bd_addr);


srv_bm_dev_info_struct* srv_bm_query_valid_info();

U8  g_bmv_uid[] = {
    0x01, 0x19, 0x1F, 0x49, 0xFF, 0xE5, 0x40, 0x56,
    0X87, 0x6B, 0x6D, 0xF1, 0xF1, 0xB1, 0x6E, 0x9D
};

static U8 BMV_SRV_UUID_128[] = {
    0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0x80,
    0x00, 0x10, 0x00, 0x00, 0x01, 0x19, 0x00, 0x00,
};

srv_btmusic_cntx_struct g_bt_music_cntx;
gattc_callback_struct g_bm_gatt_cb = {
    bm_register_callback,
    NULL,
    bm_connection_callback,
    NULL,
    NULL,
    bm_search_complete_callback,
    bm_search_result_callback,
    bm_get_characteristic_callback,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    bm_write_characteristic_callback,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    bm_research_service_callback,
    NULL,
};


void mmi_bt_music_client_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 event_mask;
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/	
    event_mask = SRV_BT_CM_EVENT_BLE_ACTIVATE |
                    SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;
    memset(&g_bt_music_cntx, 0x00, sizeof (srv_btmusic_cntx_struct));
    memcpy(g_bt_music_cntx.uid.uu, &g_bmv_uid, sizeof(bt_uuid_struct));
    srv_bt_cm_set_notify((srv_bt_cm_notifier)mmi_bt_event_notify_btmusic_client, event_mask, NULL);

    return; 
}


void mmi_bt_event_notify_btmusic_client(U32 event, void* para)
{
    if (SRV_BT_CM_EVENT_BLE_ACTIVATE == event)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_GATT_CLIENT_ACTIV);
        srv_gattc_register(&g_bt_music_cntx.uid, &g_bm_gatt_cb);
        mmi_frm_cb_reg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, bm_music_cm_disconnect_hdlr, NULL); //listen CM disconnect req
    }
    // BT power off
    else if (SRV_BT_CM_EVENT_BEGIN_DEACTIVATE == event)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_GATT_CLIENT_DEACTIV);
        srv_gattc_deregister(g_bt_music_cntx.reg_ctx);
        mmi_frm_cb_dereg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, bm_music_cm_disconnect_hdlr, NULL); //listen CM disconnect req
    }

}

void bm_register_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_GATT_REGISTER);
    if(memcmp(app_uuid, &g_bt_music_cntx.uid, sizeof(bt_uuid_struct)) == 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_REG_ST, status);
        if (status == OS_STATUS_SUCCESS)
        {
            g_bt_music_cntx.reg_ctx = reg_ctx;
            g_bt_music_cntx.re_state = BMV_STATUS_ENABLE;
            srv_gattc_listen(reg_ctx, TRUE);
        }
        else
        {
            g_bt_music_cntx.re_state = BMV_STATUS_DISABLE;
        }
    }       
}

srv_bm_dev_info_struct* srv_bm_create_new_dev_info(void* con_cntx, BD_ADDR *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 i;
    srv_bm_dev_info_struct *dev_info = NULL ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < SRV_BMV_MAX_DEV; i++)
    {
        dev_info = &g_bt_music_cntx.bm_info[i];
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CEATE_DEV, dev_info->flag, i);
        if (dev_info->flag == 0)
        {
            dev_info->flag |=0x01;
            dev_info->conn_cntx = con_cntx;
            dev_info->index = i;
            memcpy(dev_info->daddr.addr, addr->addr, BD_ADDR_SIZE);
            dev_info->dev_state = 0;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CEATE_DEV_I);
            return dev_info;
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CEATE_DEV_I);
    return NULL;
}

srv_bm_dev_info_struct* srv_bm_query_dev_info(srv_bm_query_type_enum type ,void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    BD_ADDR *addr = NULL;
    srv_bm_dev_info_struct *dev_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr = (BD_ADDR*)para;
    for (i = 0; i< SRV_BMV_MAX_DEV; i++)
    {
        dev_p = &g_bt_music_cntx.bm_info[i];
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CEATE_QUERY_DEV_I, dev_p->daddr.addr[0]);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CEATE_QUERY_DEV_II, dev_p->daddr.addr[1]);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CEATE_QUERY_DEV_III, dev_p->daddr.addr[2]);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CEATE_QUERY_DEV_IV, dev_p->daddr.addr[3]);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CQ_FLAG, dev_p->flag);
        if (type == BM_ADDRESS && memcmp(&dev_p->daddr.addr, addr->addr, BD_ADDR_SIZE) == 0)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CQ_DEV_I, dev_p);
            return dev_p;

        }
        else if (type == BM_CONN_CNTX && dev_p->conn_cntx == para && dev_p->flag)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CQ_DEV_II, dev_p);
            return dev_p;
        }
    }
    return NULL;
}


void srv_bm_clear_dev_info(srv_bm_dev_info_struct *dev_info)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CLEAR_DEV, dev_info);
    memset(dev_info, 0x00, sizeof(srv_bm_dev_info_struct));
}


void bm_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{ 
    bt_uuid_struct filter_uuid;

    srv_bm_dev_info_struct *dev_info = NULL;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CONN_CB_S);
    memcpy(filter_uuid.uu, &BMV_SRV_UUID_128, 16); // need save  interface to set different service uuid
    dev_info = srv_bm_query_dev_info(BM_ADDRESS, bd_addr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CONN_CB_DEV, dev_info);
    if (conn->reg_ctx == g_bt_music_cntx.reg_ctx)
    {
        if (connected)
        {
            if (dev_info == NULL)
            {
                dev_info = srv_bm_create_new_dev_info(conn->conn_ctx, bd_addr);
            }
            if (dev_info)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CONN_CB_DEV_I, dev_info,dev_info->dev_state);
                dev_info->dev_state = BMV_STATUS_CONNECTED;
                if (SRV_BMV_MAX_DEV == srv_ble_cm_get_connected_dev_num())
                {
                    srv_gattc_listen(conn->reg_ctx, MMI_FALSE);
                }
                
                if (dev_info->dev_state!= BMV_STATUS_SEARCHING)
                {
                    srv_gattc_search_service(conn, &filter_uuid);
                    dev_info->dev_state = BMV_STATUS_SEARCHING;
                }
            }
        }
        else /*disconnect  clear addreess*/
        {            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_CONN_CB_DEV_II);
            if (dev_info)
            {
                srv_bm_clear_dev_info(dev_info);
            }
        }
    }       
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}


void bm_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *svc_uuid)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bm_dev_info_struct *bm_dev = NULL;
    U16 ser_uuid = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_SEARCH_CB);
    bm_dev = srv_bm_query_dev_info(BM_CONN_CNTX, conn->conn_ctx);
    if (bm_dev)
    {
        ser_uuid = convert_array_to_uuid16(svc_uuid->uuid);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_SEARCH_CB_I, ser_uuid,bm_dev->srv_info[0].is_smatch);
        if (ser_uuid == BT_MS_CTRL_CHAR_SERVICE)
        {
            if(!bm_dev->srv_info[0].is_smatch)
            {
                bm_dev->srv_info[0].is_smatch = MMI_TRUE;
                memcpy(&(bm_dev->srv_info[0].srv_id), svc_uuid, sizeof (GATT_SVC_UUID));
            }
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_SEARCH_CB_II);
}


void bm_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    srv_bm_dev_info_struct * other_dev = NULL;

    srv_bm_dev_info_struct *bm_dev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_SEC_CB_S);
    bm_dev = srv_bm_query_dev_info(BM_CONN_CNTX, conn->conn_ctx);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_SEC_CB_I, status, bm_dev);
    if (bm_dev && status == OS_STATUS_SUCCESS)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_SEC_CB_II, bm_dev->srv_info[0].is_smatch);
        if (bm_dev->srv_info[0].is_smatch)
        {
            other_dev = srv_bm_query_valid_info();
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_SEC_CB_III, other_dev);
            if (other_dev == NULL)
            {
                bm_dev->is_exist = 1;
                srv_gattc_get_characteristic(conn, &(bm_dev->srv_info[0].srv_id), NULL);
            }
            else
            {
                srv_gattc_disconnect(conn, &bm_dev->daddr);
            }
        }
        else
        {
            srv_gattc_disconnect(conn, &bm_dev->daddr);/*not find service*/
        }
    }
}


void bm_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                           gattc_char_struct *char_info, GATT_CHAR_PROPERTIES properties)
{
    srv_bm_dev_info_struct *bm_info = NULL;

    srv_btmusic_cntx_struct*bm_cntx = srv_bm_vol_get_cur_state();

    U16  char_uuid= convert_array_to_uuid16(*char_info->char_uuid);
    U16  svc_uuid = convert_array_to_uuid16(char_info->svc_uuid->uuid);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_GET_CHAR);
    bm_info = srv_bm_query_dev_info(BM_CONN_CNTX, conn->conn_ctx);

    if (bm_info)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_GET_CHAR_I, bm_info->conn_cntx);
        if(bm_info->conn_cntx == conn->conn_ctx)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_GET_CHAR_II, status);
            if(status == OS_STATUS_SUCCESS)
            {
                 if (char_uuid  == BT_MS_CTRL_CHAR_UUID && 
                     svc_uuid == BT_MS_CTRL_CHAR_SERVICE)
                 {
                     MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_GET_CHAR_III);
                     memcpy(&(bm_info->char_info[0].char_uuid),  char_info->char_uuid, sizeof(ATT_UUID));
                     
                     bm_info->dev_state = BMV_GET_CHARA_SUCCESS;
                 }
            }
            else
            {
                bm_info->dev_state = BMV_GET_CHARA_FAILED;
            }
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_GET_CHAR_NE);
        }
    }
}


void bm_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                            gattc_char_struct *char_info)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_WC_CB, status);
}


void srv_bt_music_volume_change(U8 cmd_type)
{   
    gatt_conn_struct conn;
    ATT_VALUE         char_value;
    gattc_char_struct char_info;
    srv_bm_dev_info_struct *bm_info = NULL;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_VOLUM_C, cmd_type);
    bm_info = srv_bm_query_valid_info();

    if (bm_info)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_VOLUM_C_I, bm_info->conn_cntx, g_bt_music_cntx.reg_ctx);
        conn.conn_ctx = bm_info->conn_cntx;
        conn.reg_ctx = g_bt_music_cntx.reg_ctx;
        char_value.value[0] = cmd_type;
        char_value.len = 1;
        char_info.char_uuid = &(bm_info->char_info[0].char_uuid);
        char_info.svc_uuid = &(bm_info->srv_info[0].srv_id);
        srv_gattc_write_characteristic(&conn, 
                    &char_info, 
                    &char_value,
                    GATTC_WRITE_TYPE_NO_RSP,
                    GATTC_AUTH_REQ_NONE);
    }
}


U8 srv_bm_vol_get_cur_search_vaule()
{
    U8 state = 0;
    srv_bm_dev_info_struct *dev_info = NULL;

    dev_info = srv_bm_query_valid_info();
    if (dev_info)
    {
        state = dev_info->dev_state;
    }

    return state;
}


srv_btmusic_cntx_struct* srv_bm_vol_get_cur_state()
{
    return &g_bt_music_cntx;
}


mmi_ret bm_music_cm_disconnect_hdlr(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gatt_conn_struct conn;
    srv_le_cm_evt_disconnect_struct *evt = (srv_le_cm_evt_disconnect_struct *)para;
    srv_btmusic_cntx_struct* bm_cntx = srv_bm_vol_get_cur_state();
    srv_bm_dev_info_struct *bm_dev = NULL;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_DIC);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->dev_addr)
    {
        BD_ADDR remote_addr;
        bm_get_bd_addr(&remote_addr, evt->dev_addr);
        bm_dev = srv_bm_query_dev_info(BM_ADDRESS, &remote_addr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_DIC_DEV, bm_dev);
        if (bm_dev)
        {
            conn.conn_ctx = bm_dev->conn_cntx;
            conn.reg_ctx = g_bt_music_cntx.reg_ctx;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_DIC_DEV_I, conn.conn_ctx, conn.reg_ctx);
            srv_gattc_disconnect(&conn,&remote_addr);
        }
    }

    return MMI_RET_OK;
}



void bm_research_service_callback(gatt_conn_struct *conn, OS_STATUS status, BD_ADDR *bd_addr)
{
    bt_uuid_struct filter_uuid;
    srv_bm_dev_info_struct *dev_info = NULL;
    srv_bm_dev_info_struct *other_dev = NULL;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_RES_CB, g_bt_music_cntx.reg_ctx, conn->reg_ctx);
    if (conn->reg_ctx == g_bt_music_cntx.reg_ctx)
    {
        if (status == OS_STATUS_SUCCESS)
        {        
            dev_info = srv_bm_query_dev_info(BM_ADDRESS, bd_addr);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_RES_CB_I, dev_info);
            if (dev_info!= NULL)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_RES_CB_II, dev_info->dev_state);
                if (dev_info->dev_state!= BMV_STATUS_SEARCHING)
                {
                    memcpy(filter_uuid.uu, &BMV_SRV_UUID_128, 16);
                    srv_gattc_search_service(conn, &filter_uuid);
                    dev_info->dev_state = BMV_STATUS_SEARCHING;
                }
            }
            else
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_RES_CB_III);
                other_dev = srv_bm_query_valid_info();
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_RES_CB_IV, other_dev);
                if (other_dev == NULL)
                {
                    srv_gattc_connect(conn->reg_ctx, bd_addr, MMI_TRUE);
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_RES_CB_V);
                    srv_gattc_disconnect(conn, bd_addr);
                }
            }
        }
    }
}


void bm_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((U8 *)&dst->addr[0], (U8 *)&src->lap, 3);
    dst->addr[3] = src->uap;
    memcpy((U8 *)&dst->addr[4], (U8 *)&src->nap, 2);
}


srv_bm_dev_info_struct* srv_bm_query_valid_info()
{
    U32 i;
    srv_bm_dev_info_struct *dev_info = NULL;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_QUERY_DEV);
    for (i = 0; i< SRV_BMV_MAX_DEV; i++)
    {
        dev_info = &g_bt_music_cntx.bm_info[i];
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_QUERY_DEV_I, dev_info->flag, i, dev_info->is_exist);
        if (dev_info->flag && dev_info->is_exist)
        {
            return dev_info;
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_QUERY_DEV_II);
    return NULL;
}

#endif
