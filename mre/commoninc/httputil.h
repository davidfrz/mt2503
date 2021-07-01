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
 * 
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef HTTPUTIL_H
#define HTTPUTIL_H

#include "vmswitch.h"

#if defined(__MRE_LIB_HTTP__)

#include "vmsys.h"
#include "vmhttp.h"
#include "vmstdlib.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HTTP_HEAD_BUFFER_LEN		(1024 * 4)

/**
 * Read HTTP head buffer
 */
struct http_head_buffer_t {
	int read_avail;									/* How many bytes can be read in the buffer */
	int read_pos;									/* Current reading position */
	unsigned char buffer[HTTP_HEAD_BUFFER_LEN];		/* Buffer */
};

/**
 * HTTP Queue��
 */
struct queue_item_t {	
	int active;					/* ����״̬��				*/
	http_session_t* session;		/* HTTP�Ự��				*/
	enum {CONNECTING, SENDING, RECV_STATUS_LINE, RECV_HEAD, RECV_BODY} state;	/* HTTP�Ự״̬��*/
	enum {VM_SOC_CONNECTED, VM_SOC_CAN_READ, VM_SOC_CAN_WRITE, VM_SOC_ERROR} soc_state;	/* �׽���״̬��	*/
	int dns_req_id;				/* DNS���������š�	*/
	int sent;						/* �ѷ����ֽ�����		*/
	int read;						/* ���յ��ֽ�����		*/
	vm_cache_t cache;			/* ���档*/
	enum {FIXED_LENGTH, CHUNKED} cnt_len_type;				/* HTTP��Ӧ�������͡�*/
	int chunk_len;				/* �鳤�ȡ�					*/
	int body_buf_len;			/* ��Ӧ�建�������ȡ�	*/
	struct http_head_buffer_t http_head_buffer;						/* HTTP��Ӧͷ��״̬�еĻ��塣*/
};
	
#define QUEUE_SIZE 3
	
#define SEND_NOTIFY(state, param) if (notify_callback != NULL) notify_callback(state, param)

/**
 * �ֽ�URL�ĸ������֡�
 */
int unpack_url(char* url, char* scheme, char* host, int* port, char* res, char* param);

/**
 * �ֽ�URL���������ֵ��������Ͷ˿ڡ�
 */
void unpack_host(char* url, char* host, int* port);

/**
 * �ֽ�HTTPͷ��
 */
int unpack_head(char* s, char* name, char* value);

/**
 * ��HTTP�Ự���봦����С�
 */
struct queue_item_t* enqueue(http_session_t* session);

/**
 * ����HTTP�Ự��
 */
int proc_session(struct queue_item_t* item);

/**
 * ����HTTP�Ự���С�
 */
void proc_queue(int tid);

/**
 * ����HTTP�Ự���еĸ���Ԫ�ء�
 */
void proc_queue_item(struct queue_item_t* item);

/**
 * ����HTTP����ͷ�����HTTP��HEAD���Ѿ�����ͬ����HEAD NAME����ô�µ�HEAD VALUE
 * ���滻���ϵ�HEAD VALUE��
 */
int add_http_request_head(http_session_t *session, char* name, char* value);

/**
 * ����HTTP����URL ��ԭ��URL�����µ�URL�滻
 */
int reset_http_request_line(http_session_t *session, VMCHAR* url);

/**
 * ����HTTP�����塣
 */
int set_http_request_body(http_session_t *session, int len, void* buf);

/**
 * ����DNS�����������ҵ���Ӧ�Ķ���Ԫ�ء�
 */
struct queue_item_t* get_item_by_dns_req_id(int dns_req_id);

/**
 * ����SOCKET��Ż����Ӧ�Ķ���Ԫ�ء�
 */
struct queue_item_t* get_item_by_soc_id(SOCKET_T soc_id);

#ifdef __cplusplus
}
#endif

#endif /* __MRE_LIB_HTTP__ */

#endif /* HTTPUTIL_H */
