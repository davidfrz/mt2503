/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
*
* Filename:
* ---------
*  TimeSrv.c
*
* Project:
* -------- 
*  MAUI
*
* Description:
* ------------
*  Time sync extension
*
* Author:
* -------
 * -------
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "TimeSrvGprot.h"


#ifdef __TIME_SYNC_EXT__ 

#include "TimeSrv.h"
//#include "BLESrvGprot.h"


/*****************************************************************
 * Time sync ext Time Format SRV 
 *****************************************************************/
static U8 SRV_TIME_TF_UUID_16[] = {
    0x02, 0x19,
};

static U8 SRV_TIME_TF_UUID_128[] = {
    0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0x80,
    0x00, 0x10, 0x00, 0x00, 0x02, 0x19, 0x00, 0x00,
};

static U8 time_uuid[16] = {'T','I','M','E','_','E','X','T','\0', 0x00};

/* Global Variable */

static srv_time_dev_info_struct dev_info[SRV_TIME_MAX_LINK_NUM];
static srv_time_handle_struct time_handle[SRV_TIME_MAX_HD_NUM];
static srv_time_cntx_struct g_srv_time_cntx;


/* Static Function */

#define SRV_TIME_CHANGE_STATE(p, s)            ((p)->state = (s))
#define SRV_TIME_CHANGE_DEV_STATE(p, s)        ((p)->state = (s))


/*****************************************************************************
* FUNCTION
*  srv_time_get_cntx
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_time_cntx_struct *srv_time_get_cntx() 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_time_cntx;
}


/*****************************************************************************
* FUNCTION
*  srv_time_alloc_dev
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_time_dev_info_struct *srv_time_alloc_dev() 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    for (i = 0; i < SRV_TIME_MAX_LINK_NUM; ++i)
    {
        if (!(srv_cntx_p->dev_info[i].flag & SRV_TIME_FLAG_USED))
        {
            dev = &srv_cntx_p->dev_info[i];
            srv_cntx_p->dev_info[i].flag |= SRV_TIME_FLAG_USED;
            srv_cntx_p->dev_info[i].index = i;
            break;
        }
    }

    return dev;
}


/*****************************************************************************
* FUNCTION
*  srv_time_free_dev
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_free_dev(srv_time_dev_info_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dev, 0x00, sizeof(srv_time_dev_info_struct));
}


/*****************************************************************************
* FUNCTION
*  srv_time_fsm
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_fsm(srv_time_dev_info_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = 0;
    srv_time_cntx_struct *srv_cntx_p = NULL;
    S32 i = 0;
    ATT_UUID *start_char = NULL;
    gatt_conn_struct conn;
    srv_time_char_info_struct *ch_info = NULL;
    S32 max_char = 0;
    gattc_char_struct ch;
    gattc_descr_struct write_req;
    ATT_VALUE value;
    U16 char_uuid16;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();
    state = dev->state;

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] fsm--state: %d\n", state);

    switch (state)
    {
        case SRV_TIME_STATE_GETTING_CHAR:
        {
            for (i = 0; i < SRV_TIME_MAX_CHAR; ++i)
            {
                if (!dev->char_info[i].valid)
                {
                    conn.reg_ctx = srv_cntx_p->reg_ctx;
                    conn.conn_ctx = dev->conn_ctx;

                    srv_gattc_get_characteristic(&conn, &dev->srv_info[0].srv_uuid, start_char);
                    break;
                }
                else
                {
                    //start_char = &dev->char_info[i].char_uuid;
                    start_char = dev->start_char;
                }
            }
            if (i == SRV_TIME_MAX_CHAR)
            {
                SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_REG_NOTIFY);
                srv_time_fsm(dev);
            }

            break;
        }

        case SRV_TIME_STATE_REG_NOTIFY:
        {
            max_char = SRV_TIME_MAX_CHAR;
            ch_info = dev->char_info;
            for (i = 0; i < max_char; ++i)
            {
                if (ch_info[i].valid && ch_info[i].need_reg && !ch_info[i].registered)
                {
                    ch.svc_uuid = &dev->srv_info[SRV_TIME_SRV_TF].srv_uuid;
                    ch.char_uuid = &ch_info[i].char_uuid;
                    srv_gattc_register_for_notification(srv_cntx_p->reg_ctx, &dev->bd_addr, &ch);
                    break;
                }
            }
            if (i == max_char)
            {
                SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_GET_DESCR);
                srv_time_fsm(dev);
            }

            break;
        }

        case SRV_TIME_STATE_GET_DESCR:
        {
            max_char = SRV_TIME_MAX_CHAR;
            ch_info = dev->char_info;
            for (i = 0; i < max_char; ++i)
            {
                if (ch_info[i].valid && ch_info[i].registered && !ch_info[i].descriptor)
                {
                    ch.svc_uuid = &dev->srv_info[0].srv_uuid;
                    ch.char_uuid = &ch_info[i].char_uuid;
                    conn.reg_ctx = srv_cntx_p->reg_ctx;
                    conn.conn_ctx = dev->conn_ctx;
                    srv_gattc_get_descriptor(&conn, &ch, NULL);
                    break;
                }
            }
            if (i == max_char)
            {
                SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_WRITE_DESCR);
                srv_time_fsm(dev);
            }

            break;
        }

        case SRV_TIME_STATE_WRITE_DESCR:
        {
            max_char = SRV_TIME_MAX_CHAR;
            ch_info = dev->char_info;
            for (i = 0; i < max_char; ++i)
            {
                if (ch_info[i].valid && ch_info[i].registered &&
                    ch_info[i].descriptor && !ch_info[i].des_writed)
                {
                    char_uuid16 = convert_array_to_uuid16(ch_info[i].char_uuid);
                    memset(&value, 0, sizeof(ATT_VALUE));
                    value.len = 2;
                    value.value[0] = 0x01;
                    value.value[1] = 0;
                    conn.reg_ctx = srv_cntx_p->reg_ctx;
                    conn.conn_ctx = dev->conn_ctx;
                    write_req.svc_uuid = &dev->srv_info[0].srv_uuid;
                    write_req.char_uuid = &ch_info[i].char_uuid;
                    write_req.descr_uuid = &ch_info[i].descr_uuid;
                    srv_gattc_write_descriptor(&conn, &write_req, &value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);
                    break;
                }
            }
            if (i == max_char)
            {
                SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_DONE);
                //*
                //SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_READ_CHAR);
                conn.reg_ctx = srv_cntx_p->reg_ctx;
                conn.conn_ctx = dev->conn_ctx;
                ch.svc_uuid = &dev->srv_info[SRV_TIME_SRV_TF].srv_uuid;
                ch.char_uuid = &dev->char_info[0].char_uuid;
                srv_gattc_read_characteristic(&conn, &ch, GATTC_AUTH_REQ_NONE);
                //*/
            }

            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_time_get_free_char
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_time_char_info_struct *srv_time_get_free_char(U8 type,
    srv_time_dev_info_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_char_info_struct *char_info = NULL;
    srv_time_char_info_struct *ch_info = NULL;
    S32 i = 0, max_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == SRV_TIME_SRV_TF)
    {
        max_char = SRV_TIME_MAX_CHAR;
        ch_info = dev->char_info;
    }

    for (i = 0; i < max_char; ++i)
    {
        if (!ch_info[i].valid)
        {
            char_info = &ch_info[i];

            break;
        }
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] get_free_char--type: %d, char: 0x%x\n",
        type, char_info);

    return char_info;
}


/*****************************************************************************
* FUNCTION
*  srv_time_get_dev
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_time_dev_info_struct *srv_time_get_dev(U8 type, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    S32 i = 0;
    BD_ADDR *bd_addr = NULL;
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    for (i = 0; i < SRV_TIME_MAX_LINK_NUM && (!dev); ++i)
    {
        if (srv_cntx_p->dev_info[i].flag & SRV_TIME_FLAG_USED)
        {
            switch (type)
            {
                case SRV_TIME_QUERY_BY_CONN:
                {
                    if (para == srv_cntx_p->dev_info[i].conn_ctx &&
                        (srv_cntx_p->dev_info[i].flag & SRV_TIME_FLAG_USED))
                    {
                        dev = &srv_cntx_p->dev_info[i];
                    }
                    break;
                }

                case SRV_TIME_QUERY_BY_ADDR:
                {
                    bd_addr = (BD_ADDR *)para;
                    if (!memcmp(bd_addr->addr, srv_cntx_p->dev_info[i].bd_addr.addr, BD_ADDR_SIZE))
                    {
                        dev = &srv_cntx_p->dev_info[i];
                    }
                    break;
                }

                case SRV_TIME_QUERY_BY_INDEX:
                {
                    index = (U8)para;
                    //if (srv_cntx_p->dev_info[i].index == index)
                    {
                        dev = &srv_cntx_p->dev_info[index];
                    }
                    break;
                }

                default:
                    break;
            }
        }
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] get_dev--type: %d, dev: 0x%x\n", type, dev);

    return dev;
}


/*****************************************************************************
* FUNCTION
*  srv_time_get_char_info
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_time_char_info_struct *srv_time_get_char_info(U8 type, 
    U8 query, void *para, srv_time_dev_info_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_char_info_struct *ch_info = NULL, *char_info = NULL;
    S32 i = 0, max_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    if (type == SRV_TIME_SRV_TF)
    {
        char_info = dev->char_info;
        max_char = SRV_TIME_MAX_CHAR;
    }

    for (i = 0; i < max_char && (!ch_info); ++i)
    {
        if (char_info[i].valid)
        {
            switch (query)
            {
                case SRV_TIME_QUERY_BY_CHAR_UUID:
                {
                    if (!memcmp(para, &char_info[i].char_uuid, sizeof(ATT_UUID)))
                    {
                        ch_info = &char_info[i];
                    }
                    break;
                }

                default:
                    break;
            }
        }
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] get_char_info--char: 0x%x\n", ch_info);

    return ch_info;
}

/*****************************************************************************
* FUNCTION
*  srv_time_cntx_init
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_cntx_init() 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    memset(srv_cntx_p, 0x00, sizeof(srv_time_cntx_struct));
    memset(dev_info, 0x00, sizeof(dev_info));
    memset(time_handle, 0x00, sizeof(time_handle));

    srv_cntx_p->dev_info = dev_info;

    /* init gattc callback */
    srv_cntx_p->gattc_cb.register_client_cb = srv_time_register_cb;
    srv_cntx_p->gattc_cb.connection_cb = srv_time_connect_cb;
    //srv_cntx_p->gattc_cb.connection_ext_cb = srv_time_connect_ext_cb;
    #ifdef SRV_TIME_UT
    srv_cntx_p->gattc_cb.scan_result_cb = srv_time_scan_result_cb; /* Test */
    #endif
    srv_cntx_p->gattc_cb.listen_cb = srv_time_listen_cb;
    srv_cntx_p->gattc_cb.search_result_cb = srv_time_search_service_result_cb;
    srv_cntx_p->gattc_cb.search_complete_cb = srv_time_search_service_complete_cb;
    srv_cntx_p->gattc_cb.get_characteristic_cb = srv_time_get_char_cb;
    srv_cntx_p->gattc_cb.read_characteristic_cb = srv_time_read_char_cb;
    srv_cntx_p->gattc_cb.write_characteristic_cb = srv_time_write_char_cb;
    srv_cntx_p->gattc_cb.register_for_notification_cb = srv_time_register_for_notification_cb;
    srv_cntx_p->gattc_cb.get_descriptor_cb = srv_time_get_descriptor_cb;
    srv_cntx_p->gattc_cb.read_descriptor_cb = srv_time_read_descriptor_cb;
    srv_cntx_p->gattc_cb.write_descriptor_cb = srv_time_write_descriptor_cb;
    srv_cntx_p->gattc_cb.notify_cb = srv_time_notify_cb;
    srv_cntx_p->gattc_cb.research_service_cb = srv_time_research_service_cb;
}


/*****************************************************************************
* FUNCTION
*  srv_time_register_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_register_cb(void *reg_ctx, OS_STATUS status,
    bt_uuid_struct *app_uuid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    if (OS_STATUS_SUCCESS == status)
    {
        srv_cntx_p->reg_ctx = reg_ctx;
        SRV_TIME_CHANGE_STATE(srv_cntx_p, SRV_TIME_STATE_LISTENING);
        srv_gattc_listen(reg_ctx, TRUE);
        ret = 1;
    }
    else
    {
        SRV_TIME_CHANGE_STATE(srv_cntx_p, SRV_TIME_STATE_IDLE);
        srv_gattc_deregister(reg_ctx);
        ret = -1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] register_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_scan_result_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_scan_result_cb(void *reg_ctx, BD_ADDR *bd_addr,
    S32 rssi, U8 eir_len, U8 *eir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    //U8 srv_addr[BD_ADDR_SIZE] = {0xca, 0xe5, 0x73, 0x6f, 0x1c, 0xc7};
    // iPhone
    U8 srv_addr[BD_ADDR_SIZE] = {0xf9, 0x22, 0x0d, 0x56, 0x42, 0xc9};
    U8 srv[] = "Glucose";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    if (srv_cntx_p->reg_ctx == reg_ctx && 
        ((memcmp(srv_addr, bd_addr->addr, BD_ADDR_SIZE) == 0) || 
        (memcmp(srv, eir + 11, 7) == 0)))
    {
        srv_gattc_scan(reg_ctx, FALSE);

        srv_gattc_connect(reg_ctx, bd_addr, TRUE);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_time_listen_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_listen_cb(void *reg_ctx, OS_STATUS status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    if (OS_STATUS_SUCCESS == status)
    {
        SRV_TIME_CHANGE_STATE(srv_cntx_p, SRV_TIME_STATE_READY);

        ret = 1;
        #ifdef SRV_TIME_UT
        /* Test */
        srv_gattc_scan(reg_ctx, TRUE);
        #endif
    }
    else
    {
        SRV_TIME_CHANGE_STATE(srv_cntx_p, SRV_TIME_STATE_IDLE);
        ret = -1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] listen_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_connect_ext_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_connect_cb(gatt_conn_struct *conn,
    BOOL connected, BD_ADDR *bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    bt_uuid_struct att_uuid;
    S32 i = 0;
    U8 index = 0;
    srv_time_char_info_struct *ch_info = NULL;
    S32 max_char = 0;
    gattc_char_struct ch;
    srv_time_evt_struct evt = {0};
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    if (conn->reg_ctx == srv_cntx_p->reg_ctx)
    {
        if (connected)
        {
            /* compare addr */
            if (!memcmp(bd_addr->addr, srv_cntx_p->bd_addr.addr, BD_ADDR_SIZE))
            {
                dev = srv_time_get_dev(SRV_TIME_QUERY_BY_ADDR, bd_addr);
                if (dev)
                {
                    index = dev->index;
                 //if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
                    srv_gattc_listen(conn->reg_ctx, FALSE);
                    ret = 1;
                }
                else
                {
                    dev = srv_time_alloc_dev();
                    index = dev->index;
                    SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_CONNECTING);
                    memcpy(&dev->bd_addr, bd_addr, sizeof(BD_ADDR));
                    dev->conn_ctx = conn->conn_ctx;
     
                    //if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
                    srv_gattc_listen(conn->reg_ctx, FALSE);
                    SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_SEARCHING);
                    memcpy(att_uuid.uu, SRV_TIME_TF_UUID_128, 16);
                    srv_gattc_search_service(conn, &att_uuid);
                    ret = 2;

                    evt.evt = SRV_TIME_EVT_CONNECT;
                    if (srv_cntx_p->cb)
                    {
                        srv_cntx_p->cb(&evt);
                    }
                }
            }
            else
            {
                ret = -2;
                srv_gattc_disconnect(conn, bd_addr);
            }
        }
        else
        {
            dev = srv_time_get_dev(SRV_TIME_QUERY_BY_ADDR, bd_addr);
            ret = 3;
            if (dev)
            {
                max_char = SRV_TIME_MAX_CHAR;
                ch_info = dev->char_info;
                for (i = 0; i < max_char; ++i)
                {
                    if (ch_info[i].registered)
                    {
                        ch.svc_uuid = &dev->srv_info[SRV_TIME_SRV_TF].srv_uuid;
                        ch.char_uuid = &ch_info[i].char_uuid;
                        srv_gattc_deregister_for_notification(srv_cntx_p->reg_ctx,
                            &dev->bd_addr, &ch);
                        ch_info[i].registered = MMI_FALSE;
                    }
                }

                index = dev->index;
                srv_time_free_dev(dev);
                ret = 4;
                evt.evt = SRV_TIME_EVT_DISCONNECT;
                if (srv_cntx_p->cb)
                {
                    srv_cntx_p->cb(&evt);
                }
            }
        }
    }
    else
    {
        ret = -1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] connect_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_search_service_result_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_search_service_result_cb(gatt_conn_struct *conn,
    GATT_SVC_UUID *uuid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    U16 srv_uuid16 = 0;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_CONN, conn->conn_ctx);

    if (dev)
    {
        srv_uuid16 = convert_array_to_uuid16(uuid->uuid);

        ret = 1;
        if (TIME_SRV_TF_UUID == srv_uuid16)
        {
            dev->flag |= SRV_TIME_FLAG_TF;
            dev->srv_info[SRV_TIME_SRV_TF].valid = MMI_TRUE;
            memcpy(&dev->srv_info[SRV_TIME_SRV_TF].srv_uuid,
                uuid, sizeof(GATT_SVC_UUID));
            ret = 2;
        }
    }
    else
    {
        ret = -1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] search_service_result_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_search_service_complete_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_search_service_complete_cb(
    gatt_conn_struct *conn, OS_STATUS status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    S32 i = 0;
    S32 ret = 0;
    srv_time_evt_struct evt = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();
    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_CONN, conn->conn_ctx);

    if (dev && status == OS_STATUS_SUCCESS)
    {
        if (dev->flag & SRV_TIME_FLAG_TF)
        {
            SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_GETTING_CHAR);

            srv_time_fsm(dev);
            ret = 1;

            evt.evt = SRV_TIME_EVT_TF_SEARCH;
            if (srv_cntx_p->cb)
            {
                ret = 3;
                srv_cntx_p->cb(&evt);
            }
        }
        else
        {
            srv_gattc_disconnect(conn, &dev->bd_addr);
            ret = 2;
        }
    }
    else
    {
        ret = -1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] search_service_complete_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_get_char_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_get_char_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_char_struct *chr,
    GATT_CHAR_PROPERTIES properties)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    U16 char_uuid16 = 0;
    gatt_conn_struct gattc_conn;
    S32 i = 0;
    srv_time_char_info_struct *char_info;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();
    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_CONN, conn->conn_ctx);

    if (dev && status == OS_STATUS_SUCCESS)
    {
        char_uuid16 = convert_array_to_uuid16(*(chr->char_uuid));

        ret = 2;
        if (TIME_TF_CHAR_UUID == char_uuid16) 
        {
            char_info = srv_time_get_free_char(SRV_TIME_SRV_TF, dev);
            memset(char_info, 0x00, sizeof(srv_time_char_info_struct));
            char_info->valid = MMI_TRUE;
            char_info->need_reg = MMI_TRUE;
            char_info->registered = MMI_FALSE;
            memcpy(&char_info->char_uuid, chr->char_uuid, sizeof(ATT_UUID));
            ret = 3;
        }
        else
        {
            ret = 4;
        }

        dev->start_char = chr->char_uuid;
        srv_time_fsm(dev);
    }
    else if (dev)
    {
        SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_REG_NOTIFY);
        srv_time_fsm(dev);
        ret = 1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] get_char_cb--ret: %d, uuid: 0x%x\n",
        ret, char_uuid16);
}


/*****************************************************************************
* FUNCTION
*  srv_time_read_char_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_read_char_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_char_struct *chr, ATT_VALUE *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    U16 char_uuid16;
    S32 ret = 0;
    srv_time_evt_struct evt = {0};
    srv_time_tf_struct tf = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();
    char_uuid16 = convert_array_to_uuid16(*(chr->char_uuid));
    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_CONN, conn->conn_ctx);
    if (dev && TIME_TF_CHAR_UUID == char_uuid16)
    {
        SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_DONE);
        ret = 1;
        evt.evt = SRV_TIME_EVT_TF_RCB;
        evt.para = (void *)(&tf);
        tf.tf = value->value[0];
        if (srv_cntx_p->cb)
        {
            srv_cntx_p->cb(&evt);
            ret = 2;
        }
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] read_char_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_write_char_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_write_char_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_char_struct *ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] write_char_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_register_for_notification_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_register_for_notification_cb(void *reg_ctx,
    OS_STATUS status, BD_ADDR *bd_addr, gattc_char_struct *char_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    srv_time_char_info_struct *chr = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();
    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_ADDR, bd_addr);

    if (dev && status == OS_STATUS_SUCCESS)
    {
        chr = srv_time_get_char_info(SRV_TIME_SRV_TF, 
                SRV_TIME_QUERY_BY_CHAR_UUID, char_info->char_uuid, dev);

        chr->registered = MMI_TRUE;
        srv_time_fsm(dev);

        ret = 1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] register_for_notification_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_get_descriptor_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_get_descriptor_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_descr_struct *descr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    srv_time_char_info_struct *ch_info = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();
    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_CONN, conn->conn_ctx);

    if (dev && status == OS_STATUS_SUCCESS)
    {
        ch_info = srv_time_get_char_info(SRV_TIME_SRV_TF, 
            SRV_TIME_QUERY_BY_CHAR_UUID, descr_info->char_uuid, dev);

        ch_info->descriptor = MMI_TRUE;
        memcpy(&ch_info->descr_uuid, descr_info->descr_uuid, sizeof(ATT_UUID));
        srv_time_fsm(dev);

        ret = 1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] get_descriptor_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_read_descriptor_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_read_descriptor_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_descr_struct *descr_info, ATT_VALUE *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] read_descriptor_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_write_descriptor_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_write_descriptor_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_descr_struct *descr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    srv_time_char_info_struct *ch_info = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();
    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_CONN, conn->conn_ctx);

    if (dev && status == OS_STATUS_SUCCESS)
    {
        ch_info = srv_time_get_char_info(SRV_TIME_SRV_TF,
            SRV_TIME_QUERY_BY_CHAR_UUID, descr_info->char_uuid, dev);

        ch_info->des_writed = MMI_TRUE;
        srv_time_fsm(dev);

        ret = 1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] write_descriptor_cb--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_notify_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_notify_cb(gatt_conn_struct *conn,
    BD_ADDR *bd_addr, gattc_char_struct *char_info,ATT_VALUE *value,
    BOOL is_notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    U16 char_uuid16 = 0;
    S32 ret = 0;
    srv_time_evt_struct evt = {0};
    srv_time_tf_struct tf = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    char_uuid16 = convert_array_to_uuid16(*(char_info->char_uuid));

    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_CONN, conn->conn_ctx);

    if (dev)
    {
        ret = 2;
        if (TIME_TF_CHAR_UUID == char_uuid16)
        {
            SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_DONE);
            ret = 3;
            evt.evt = SRV_TIME_EVT_TF_NOTI;
            evt.para = (void *)(&tf);
            tf.tf = value->value[0];
            if (srv_cntx_p->cb)
            {
                ret = 4;
                srv_cntx_p->cb(&evt);
            }
        }
    }
    else
    {
        ret = -1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] notify_cb--ret: %d\n", ret);    
}


/*****************************************************************************
* FUNCTION
*  srv_time_check_para
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static S32 srv_time_check_para(U8 type, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    S32 i = 0;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] check_para--type: %d, ret: %d\n", type, ret);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_time_research_service_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_research_service_cb(gatt_conn_struct *conn,
    OS_STATUS status, BD_ADDR *bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    S32 ret = 0;
    bt_uuid_struct att_uuid = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_ADDR, bd_addr);

    /*
    if (srv_cntx_p->reg_ctx == conn->reg_ctx)
    {
        if (dev)
        {
            SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_SEARCHING);
            memcpy(att_uuid.uu, SRV_TIME_TF_UUID_128, 16);
            srv_gattc_search_service(conn, &att_uuid);
            ret = 1;
        }
        else
        {
            srv_gattc_connect(srv_cntx_p->reg_ctx, bd_addr, TRUE);
            ret = 2;
        }
    }
    else
    {
        ret = -1;
    }
    //*/
    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] research_service_cb--ret: %d\n", ret);
}


/* Extern Function */

/*****************************************************************************
* FUNCTION
*  srv_time_init
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
void srv_time_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    if (srv_cntx_p->init)
    {
        ret = -1;
    }
    else
    {
        srv_time_cntx_init();
        srv_cntx_p->init = MMI_TRUE;

        // Register for GATT client.
        memcpy(srv_cntx_p->uuid.uu, time_uuid, 16);
        SRV_TIME_CHANGE_STATE(srv_cntx_p, SRV_TIME_STATE_REGISTERING);
        srv_gattc_register(&srv_cntx_p->uuid, &srv_cntx_p->gattc_cb);
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] init--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_deinit
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
void srv_time_deinit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    S32 i = 0, j = 0;
    srv_time_char_info_struct *ch_info = NULL;
    S32 max_char = 0;
    gattc_char_struct ch;
    srv_time_dev_info_struct *dev = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    if (!srv_cntx_p->init)
    {
        ret = -1;
    }
    else
    {
        srv_cntx_p->init = MMI_FALSE;
    #if 1
        for (i = 0; i < SRV_TIME_MAX_LINK_NUM; ++i)
        {
            if (srv_cntx_p->dev_info[i].flag & SRV_TIME_FLAG_USED)
            {
                dev = &srv_cntx_p->dev_info[i];
                max_char = SRV_TIME_MAX_CHAR;
                ch_info = dev->char_info;
                for (j = 0; j < max_char; ++j)
                {
                    if (ch_info[j].registered)
                    {
                        ch.svc_uuid = &dev->srv_info[0].srv_uuid;
                        ch.char_uuid = &ch_info[j].char_uuid;
                        srv_gattc_deregister_for_notification(srv_cntx_p->reg_ctx,
                            &dev->bd_addr, &ch);
                        ch_info[j].registered = MMI_FALSE;
                    }
                }
            }
        }
    #endif
        memset(srv_cntx_p->bd_addr.addr, 0x00, BD_ADDR_SIZE);
        memset(dev_info, 0x00, sizeof(dev_info));
        memset(time_handle, 0x00, sizeof(time_handle));
        // Deregister for GATT client.
        srv_gattc_deregister(srv_cntx_p->reg_ctx);
        //memset(srv_cntx_p, 0x00, sizeof(srv_time_cntx_struct));
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] deinit--ret: %d\n", ret);
}


/*****************************************************************************
* FUNCTION
*  srv_time_connect
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
void srv_time_connect(BD_ADDR *bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    srv_gattc_connect(srv_cntx_p->reg_ctx, bd_addr, TRUE);
}


/*****************************************************************************
* FUNCTION
*  srv_time_connect
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
void srv_time_disconnect(BD_ADDR *bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    gatt_conn_struct conn;
    srv_time_dev_info_struct *dev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_ADDR, bd_addr);
    if (dev)
    {
        conn.reg_ctx = srv_cntx_p->reg_ctx;
        conn.conn_ctx = dev->conn_ctx;

        srv_gattc_disconnect(&conn, bd_addr);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_time_get_addr
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
S32 srv_time_get_addr(U8 index, BD_ADDR *bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_dev_info_struct *dev = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();
    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_INDEX, (void *)index);

    if (dev)
    {
        memcpy(bd_addr->addr, dev->bd_addr.addr, BD_ADDR_SIZE);
    }
    else
    {
        ret = -1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] get_addr--ret: %d\n", ret);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_time_register
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
SRV_TIME_HANDLE srv_time_register(srv_time_reg_struct *reg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_handle_struct *hd = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    srv_time_init();

    hd = time_handle;
    /* time format */
    srv_cntx_p->cb = (srv_time_evt_cb)(reg->func_cb);
    memcpy(srv_cntx_p->bd_addr.addr, reg->bd_addr.addr, BD_ADDR_SIZE);

    return (SRV_TIME_HANDLE) hd;
}


/*****************************************************************************
* FUNCTION
*  srv_time_deregister
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
S32 srv_time_deregister(SRV_TIME_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_handle_struct *hd = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    srv_time_deinit();

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_time_read_tf
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
S32 srv_time_read_tf(SRV_TIME_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_cntx_struct *srv_cntx_p = NULL;
    srv_time_handle_struct *hd = NULL;
    S32 ret = 0;
    gattc_char_struct ch;
    gatt_conn_struct conn;
    srv_time_dev_info_struct *dev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_time_get_cntx();

    dev = srv_time_get_dev(SRV_TIME_QUERY_BY_ADDR, &srv_cntx_p->bd_addr);

    if (dev && dev->state == SRV_TIME_STATE_DONE)
    {
        SRV_TIME_CHANGE_DEV_STATE(dev, SRV_TIME_STATE_READ_CHAR);
        conn.reg_ctx = srv_cntx_p->reg_ctx;
        conn.conn_ctx = dev->conn_ctx;
        ch.svc_uuid = &dev->srv_info[SRV_TIME_SRV_TF].srv_uuid;
        ch.char_uuid = &dev->char_info[0].char_uuid;
        srv_gattc_read_characteristic(&conn, &ch, GATTC_AUTH_REQ_NONE);
        ret = 1;
    }
    else
    {
        ret = -1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] read_tf--ret: %d\n", ret);

    return ret;
}

#endif /* __TIME_SYNC_EXT__ */

