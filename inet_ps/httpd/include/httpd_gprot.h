/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * httpd_gprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 * .
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __HTTPD_GPORT_H__
#define __HTTPD_GPORT_H__
#include "kal_general_types.h"

/***************************************************************************** 
* Include
*****************************************************************************/

/***************************************************************************** 
*  Define
*****************************************************************************/
#define CGI_MAX_COMMAND_LINE_LEN 250
//typedef char VMWCHAR;
typedef enum
{
	HTTPSRV_ERR_NO_ERROR                    = 0,  //operator suceed
	HTTPSRV_ERR_STATE_ERROR                 = -1, //state of http is mess 
	HTTPSRV_ERR_GET_MEM_FAIL                = -2, //memory is not enough
	HTTPSRV_ERR_CONNECT_NETWORK_FAIL        = -3, //net work is not ready
	HTTPSRV_ERR_FD_INIT_FAIL                = -4, //file disciptor init fail
	HTTPSRV_ERR_GET_HOSTNAME_FAIL           = -5, //invalid host name
	HTTPSRV_ERR_SRV_INIT_FAIL               = -6, //server init fail
	HTTPSRV_ERR_ERROR_FD_NUMBER             = -7, //file diciptor abnormal
	HTTPSRV_ERR_OTHERS                      = -65535, // other errors
	HTTPSRV_ERR_CODE                        = -65536  //end mark.
}httpsrv_error_enum;

typedef struct cgi_app_param
{
    char command_line[CGI_MAX_COMMAND_LINE_LEN];
} cgi_app_param;

typedef struct cgi_launch_param
{
    kal_uint32 hc_handle; //http connection handler, actually, a pointer to hc
    cgi_app_param param; //used by app, this struct is fill with command line, which is comes from client
}cgi_launch_param;
/*****************************************************************************
* Local functions
*****************************************************************************/

/*****************************************************************************
* Extern function
*****************************************************************************/

//demo code
/*
void handle_sysevt(VMINT message, VMINT param) 
{
    switch (message) 
    {
        case VM_MSG_HTTPD:
            if(param != NULL)
            {
                httpd_cgi_app_demo(((struct vm_cgi_launch_param *)param)->hc_handle,((struct vm_cgi_launch_param *)param)->param.command_line);
            }
            break;
    }
}

int httpd_cgi_app_demo(kal_uint32 hc_handle, char* command_line)
{
    char* request_method;
    char* query_string;
    char* content_length;
    kal_int32 con_len;
    char* content_data;
    char output_buffer[256];
    if (command_line && command_line[0] != '\0')
    {
        ///TODO: parse command line, and do some thing you need, config setting according to command_line
    }

    request_method = inet_httpd_getenv(hc_handle,"REQUEST_METHOD");
    
    if (request_method && strcmp(request_method, "GET") == 0)
    {
        query_string = inet_httpd_getenv(hc_handle,"QUERY_STRING");
        ///TODO: parse query_string, and do some thing you need. for example, config setting according to query_string
    }
    else if (request_method && strcmp(request_method, "POST") == 0)
    {
        content_length = inet_httpd_getenv(hc_handle,"CONTENT_LENGTH");
        if (content_length && sscanf(content_length,"%ld",&con_len) == 1)
        {
            content_data = malloc(con_len + 1);
            if (content_data)
            {
                inet_httpd_read(hc_handle, content_data, con_len);
                ///TODO: parse content_data, and do some thing you need. for example, config setting according to content_data
                free(content_data);
            }
        }
    }

    //output the config result to client, let end user knows the config result.

    //write message header
    sprintf(output_buffer, "Content-Type:text/html\n\n");
    inet_httpd_write(hc_handle, output_buffer, strlen(output_buffer));
    sprintf(output_buffer, "<html>\n");
    inet_httpd_write(hc_handle, output_buffer, strlen(output_buffer));
    sprintf(output_buffer, "<head>\n<title>Response</title>\n</head>\n");
    inet_httpd_write(hc_handle, write_buffer, strlen(output_buffer));

    //write body.
    sprintf(output_buffer, "<body>\n");
    inet_httpd_write(hc_handle, output_buffer, strlen(output_buffer));
    sprintf(output_buffer, "<p>Dear, your configration be saved suceed.\n");
    inet_httpd_write(hc_handle, output_buffer, strlen(output_buffer));
    sprintf(output_buffer, "</body>\n</html>\n");
    inet_httpd_write(my_app_param.hc_handle, output_buffer, strlen(output_buffer));

    //please remember to give a notification to httpd when job is finished.
    inet_httpd_cgi_job_finish(hc_handle);
}
*/

/*****************************************************************************
 * FUNCTION
 *  inet_httpd_start
 * DESCRIPTION
 * this is for lauch http server
 * PARAMETERS
 * port : [IN]
 * root_dir : [IN]
 * cgi_pattern : [IN]
 * RETURNS
 * httpsrv_error_enum
 *
 * Sample Code
 *      inet_httpd_start(80, "C:\\@httpsrv", "**.vxp");
 *****************************************************************************/
extern httpsrv_error_enum inet_httpd_start(kal_uint32 port, char* root_dir, char* cgi_pattern);

/*****************************************************************************
 * FUNCTION
 *  inet_httpd_stop
 * DESCRIPTION
 * this is for stop http server
 * PARAMETERS
 * RETURNS
 * httpsrv_error_enum
 *****************************************************************************/
 extern httpsrv_error_enum inet_httpd_stop(void);

/*****************************************************************************
 * FUNCTION
 *  inet_httpd_restart
 * DESCRIPTION
 * this is for restart http server
 * PARAMETERS
 * port : [IN]
 * root_dir : [IN]
 * cgi_pattern : [IN]
 * RETURNS
 * httpsrv_error_enum
 *
 * Sample Code
 *      inet_httpd_start(80, "C:\\@httpsrv", "**.vxp");
 *****************************************************************************/
extern httpsrv_error_enum inet_httpd_restart(kal_uint32 port, char* root_dir, char* cgi_pattern);

/*****************************************************************************
 * FUNCTION
 *  inet_httpd_cgi_launch_ret
 * DESCRIPTION
 * call this api to notify http server when cgi app is launch suceess or not.
 * PARAMETERS
 * hc_handle : [IN]
 * is_suceed : [IN]
 * RETURNS
 * void
 *****************************************************************************/
extern void inet_httpd_cgi_launch_ret(kal_uint32 hc_handle, kal_bool is_suceed);

/*****************************************************************************
 * FUNCTION
 *  inet_httpd_cgi_job_finish
 * DESCRIPTION
 * call this api to notify http server when cgi app finished the job.
 * PARAMETERS
 * RETURNS
 * void
 *****************************************************************************/
extern void inet_httpd_cgi_job_finish(kal_uint32 hc_handle);

/*****************************************************************************
 * FUNCTION
 *  inet_httpd_read
 * DESCRIPTION
 * this api is used to read the data which is comes from client, it is used to instead of stand I/O stream.
 * PARAMETERS
 * hc_handle : [IN]
 * buf : [IN/OUT]
 * buf_size : [IN]
 * RETURNS
 * kal_int32
 *
 * Sample Code
 *    int httpd_cgi_app_demo(kal_uint32 hc_handle, char* command_line)
 *    {
 *        char* content_length;
 *        kal_int32 con_len;
 *        content_length = inet_httpd_getenv(hc_handle,"CONTENT_LENGTH");
 *        if (content_length && sscanf(content_length,"%ld",&con_len) == 1)
 *        {
 *            content_data = malloc(con_len + 1);
 *            if (content_data)
 *            {
 *                inet_httpd_read(hc_handle, content_data, con_len);
 *                ///TODO: parse content_data, and do some thing you need. for example, config setting according to content_data
 *                free(content_data);
 *            }
 *        }
 *    }
 *****************************************************************************/
extern kal_int32 inet_httpd_read(kal_uint32 hc_handle, char* buf, kal_int32 buf_size);

/*****************************************************************************
 * FUNCTION
 *  inet_httpd_write
 * DESCRIPTION
 * this api is used to write the data to client, it is used to instead of stand I/O stream.
 * PARAMETERS
 * hc_handle : [IN]
 * buf : [IN]
 * buf_size : [IN]
 * RETURNS
 * kal_int32
 * 
 *Sample Code
 *    char output_buffer[256];
 *    sprintf(output_buffer, "Content-Type:text/html\n\n");
 *    inet_httpd_write(hc_handle, output_buffer, strlen(output_buffer));

 *****************************************************************************/
extern kal_int32 inet_httpd_write(kal_uint32 hc_handle, char* buf, kal_int32 content_size);

/*****************************************************************************
 * FUNCTION
 *  inet_httpd_getenv
 * DESCRIPTION
 * this api is get enviroment varible, it's same as other plateform in CGI.
 * PARAMETERS
 * hc_handle : [IN]
 * name : [IN]
 * RETURNS
 * char*
 *
 * Sample Code
 *    int httpd_cgi_app_demo(kal_uint32 hc_handle, char* command_line)
 *    {
 *        char* content_length;
 *        kal_int32 con_len;
 *        content_length = inet_httpd_getenv(hc_handle,"CONTENT_LENGTH");
 *        if (content_length && sscanf(content_length,"%ld",&con_len) == 1)
 *        {
 *            content_data = malloc(con_len + 1);
 *            if (content_data)
 *            {
 *                inet_httpd_read(hc_handle, content_data, con_len);
 *                ///TODO: parse content_data, and do some thing you need. for example, config setting according to content_data
 *                free(content_data);
 *            }
 *        }
 *    }
 *****************************************************************************/
extern char* inet_httpd_getenv(kal_uint32 hc_handle, char* name);


//void vm_httpd_start_mre_app(WCHAR *filepath, cgi_launch_param *httpd_para);
//void vm_httpd_stop_mre_app(WCHAR *filepath, kal_uint32 httpd_handle);

/*****************************************************************************
 * FUNCTION
 *  vm_inet_httpd_enable_ssl
 * DESCRIPTION
 * this api can enable httpd for SSL. Then it can support https.
 * PARAMETERS
 * port : [IN] https port
 * cer_dir : [IN] The directory for https server certificate files. You must be include "httpd_ca.cer" / "httpd_server.cer" / "httpd_server.key". Total three files and can't change names.
 * peer_CN: [IN] The name of client certificate which one https server need verify. Example "HTTPD_CLIENT".
 * server_key_passwd : [IN] Pass word of "httpd_server.key" file. Your private key file need a password for protection.
 * RETURNS
 * void
 *
 * Sample Code
 *   vm_inet_httpd_enable_ssl(443, E:/https, HTTPD_CLIENT, 1234);
 *   vm_inet_httpd_start(80, E:/httpd, **.vxp);
 *
 * Important
 *  1. Must start http server after enable ssl. Https server must run with http server.
 *  2. Push your https html into http server source path. Emxaple "E:/httpd". 
 *      If some html files can't be get by http server, you can push them into "E:/httpd/https". We will protect the files of "(httpd sourcepath)/https".
 *      Example: 
 *         input : http://127.0.0.1/user/index.html output: index.html
 *         input : https://127.0.0.1/user/index.html output: index.html
 *         input : http://127.0.0.1/https/index.html output: 403 forbidden
 *         input : https://127.0.0.1/user/index.html output: index.html
 *  3. Support base64 and binary certificate file provide by openssl.exe or certificate authority. 
 *      Don't support cermake.exe certificate file. This is xyssl open source limitation.
 *          
 *****************************************************************************/
extern void inet_httpd_enable_ssl(kal_uint32 port, char* cer_dir, char *peer_cn, char *server_key_passwd);


/*****************************************************************************
 * FUNCTION
 *  inet_httpd_disable_ssl
 * DESCRIPTION
 * this api can disable httpd for SSL. Then it can't support https.
 * PARAMETERS
 * 
 * RETURNS
 * 
 * Sample Code
 *    vm_inet_httpd_stop();
 *    vm_inet_httpd_disable_ssl();
 *****************************************************************************/
extern void inet_httpd_disable_ssl();

/*****************************************************************************
* Local variables
*****************************************************************************/

/*****************************************************************************
* Global variables
*****************************************************************************/

/*****************************************************************************
*  Functions
*****************************************************************************/

#endif
