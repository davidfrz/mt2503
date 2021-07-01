#ifndef __WLAN_RX_H__
#define __WLAN_RX_H__

/* Result enum */
typedef enum
{
    WLAN_RESULT_SUCCESS,
    WLAN_RESULT_WOULDBLOCK,
    WLAN_RESULT_TOTAL
} wlan_result_enum;

/* Struct */
typedef struct
{
    // Reserved struct
    void *para;
} wlan_init_req_struct;

typedef struct
{
    RXONLY_STATUS_ENUM state;
} wlan_init_cnf_struct;

typedef struct
{
    // Reserved struct
    void *para;
} wlan_deinit_req_struct;

typedef struct
{
    RXONLY_STATUS_ENUM state;
} wlan_deinit_cnf_struct;

typedef struct
{
    // Reserved struct
    void *para;
} wlan_scan_req_struct;

typedef struct
{
    RXONLY_STATUS_ENUM                   status;
    kal_uint8                            scan_ap_num;
    rxonly_scan_ap_info_struct           scan_ap[ RXONLY_MAX_SCAN_AP_NUM ];
} wlan_scan_cnf_struct;

/* Bootup */
// TODO: need to add in bootup file
void wlan_bootup(void);

/* Callback */
typedef void (*wlan_init_cb_func_ptr) (void *user_data, wlan_init_cnf_struct *cnf);
typedef void (*wlan_deinit_cb_func_ptr) (void *user_data, wlan_deinit_cnf_struct *cnf);
typedef void (*wlan_scan_cb_func_ptr) (void *user_data, wlan_scan_cnf_struct *cnf);

/* REQ */
wlan_result_enum wlan_init(wlan_init_req_struct *req, wlan_init_cb_func_ptr callback, void *user_data);
wlan_result_enum wlan_deinit(wlan_deinit_req_struct *req, wlan_deinit_cb_func_ptr callback, void *user_data);
wlan_result_enum wlan_scan(wlan_scan_req_struct *req, wlan_scan_cb_func_ptr callback, void *user_data);

/* CNF */
void wlan_init_cnf_hdlr(void *info);
void wlan_deinit_cnf_hdlr(void *info);
void wlan_scan_cnf_hdlr(void *info);

#endif /* __WLAN_RX_H__ */
