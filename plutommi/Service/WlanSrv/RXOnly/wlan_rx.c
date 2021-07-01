#include "rxonly_wndrv_mmi_msg.h"
#include "stack_msgs.h"
#include "mmi_frm_queue_gprot.h"
#include "wlan_rx.h"
#include "EventsGprot.h"

/*****************************************************************************
 * FUNCTION
 *  wlan_init
 * DESCRIPTION
 *  The function is used to init the WLAN.
 * PARAMETERS
 *  callback    :   [IN]    callback function to notify applications the init operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURN VALUES
 *  WLAN_RESULT_WOULDBLOCK    : waiting callback
 *****************************************************************************/
wlan_result_enum wlan_init(wlan_init_req_struct *req, wlan_init_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rxonly_wndrv_mmi_init_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = OslAllocDataPtr(rxonly_wndrv_mmi_init_req_struct);
    p->init_cb = (rxonly_wndrv_mmi_callback_func_ptr)callback;
    p->init_userdata = (rxonly_wndrv_mmi_user_data_ptr)user_data;

    mmi_frm_send_ilm(MOD_WNDRV, MSG_ID_RXONLY_WNDRV_MMI_INIT_REQ, (oslParaType *)p, NULL);

    return WLAN_RESULT_WOULDBLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  wlan_init_cnf_hdlr
 * DESCRIPTION
 *  Response for wlan init
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void wlan_init_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rxonly_wndrv_mmi_init_cnf_struct *cnf = (rxonly_wndrv_mmi_init_cnf_struct *)info;
    wlan_init_cnf_struct package_cnf;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    package_cnf.state = cnf->status;
    cnf->init_cb(cnf->init_userdata, &package_cnf);
}

/*****************************************************************************
 * FUNCTION
 *  wlan_deinit
 * DESCRIPTION
 *  The function is used to deinit the WLAN.
 * PARAMETERS
 *  callback    :   [IN]    callback function to notify applications the init operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURN VALUES
 *  WLAN_RESULT_WOULDBLOCK    : waiting callback
 *****************************************************************************/
wlan_result_enum wlan_deinit(wlan_deinit_req_struct *req, wlan_deinit_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rxonly_wndrv_mmi_deinit_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = OslAllocDataPtr(rxonly_wndrv_mmi_deinit_req_struct);
    p->deinit_cb = (rxonly_wndrv_mmi_callback_func_ptr)callback;
    p->deinit_userdata = (rxonly_wndrv_mmi_user_data_ptr)user_data;

    mmi_frm_send_ilm(MOD_WNDRV, MSG_ID_RXONLY_WNDRV_MMI_DEINIT_REQ, (oslParaType *)p, NULL);

    return WLAN_RESULT_WOULDBLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  wlan_deinit_cnf_hdlr
 * DESCRIPTION
 *  Response for wlan deinit
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void wlan_deinit_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rxonly_wndrv_mmi_deinit_cnf_struct *cnf = (rxonly_wndrv_mmi_deinit_cnf_struct *)info;
    wlan_deinit_cnf_struct package_cnf;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    package_cnf.state = cnf->status;
    cnf->deinit_cb(cnf->deinit_userdata, &package_cnf);
}

/*****************************************************************************
 * FUNCTION
 *  wlan_scan
 * DESCRIPTION
 *  The function is used to scan.
 * PARAMETERS
 *  callback    :   [IN]    callback function to notify applications the init operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURN VALUES
 *  WLAN_RESULT_WOULDBLOCK    : waiting callback
 *****************************************************************************/
wlan_result_enum wlan_scan(wlan_scan_req_struct *req, wlan_scan_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rxonly_wndrv_mmi_scan_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = OslAllocDataPtr(rxonly_wndrv_mmi_scan_req_struct);
    p->scan_cb = (rxonly_wndrv_mmi_callback_func_ptr)callback;
    p->scan_userdata = (rxonly_wndrv_mmi_user_data_ptr)user_data;

    mmi_frm_send_ilm(MOD_WNDRV, MSG_ID_RXONLY_WNDRV_MMI_SCAN_REQ, (oslParaType *)p, NULL);

    return WLAN_RESULT_WOULDBLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  wlan_scan_cnf_hdlr
 * DESCRIPTION
 *  Response for scan
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void wlan_scan_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rxonly_wndrv_mmi_scan_ind_struct *cnf = (rxonly_wndrv_mmi_scan_ind_struct *)info;   
    wlan_scan_cnf_struct package_cnf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    package_cnf.status = cnf->status;
    package_cnf.scan_ap_num = cnf->scan_ap_num;
    memcpy(package_cnf.scan_ap, cnf->scan_ap, RXONLY_MAX_SCAN_AP_NUM * sizeof(rxonly_scan_ap_info_struct));
    
    cnf->scan_cb(cnf->scan_userdata, &package_cnf);
}


void wlan_bootup(void)
{    
    SetProtocolEventHandler(wlan_init_cnf_hdlr, MSG_ID_RXONLY_WNDRV_MMI_INIT_CNF);
    SetProtocolEventHandler(wlan_deinit_cnf_hdlr, MSG_ID_RXONLY_WNDRV_MMI_DEINIT_CNF);
    SetProtocolEventHandler(wlan_scan_cnf_hdlr, MSG_ID_RXONLY_WNDRV_MMI_SCAN_IND);  
}
