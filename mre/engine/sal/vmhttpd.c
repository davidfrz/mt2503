/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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

/*******************************************************************************
 * Filename:
 * ---------
 * vmhttpd.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  mre app and http task communicate 
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
 
 * removed!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
*******************************************************************************/
#include "mmi_features.h"
#include "vmswitch.h"
#ifdef __IOT__
#include "vmsys.h"
#include "httpd_gprot.h"
#include "vmhttpd.h"

vm_httpsrv_error_enum vm_inet_httpd_start(VMUINT32 port, VMINT8* root_dir, VMINT8* cgi_pattern)
{	
	#ifdef __INET_HTTPD__
	return inet_httpd_start(port, root_dir, cgi_pattern);
	#else
	return 0;
	#endif
}
vm_httpsrv_error_enum vm_inet_httpd_stop(void)
{
	#ifdef __INET_HTTPD__
	return inet_httpd_stop();
	#else
	return 0;
	#endif
}
vm_httpsrv_error_enum vm_inet_httpd_restart(VMUINT32 port, VMINT8* root_dir, VMINT8* cgi_pattern)
{
	#ifdef __INET_HTTPD__
	return inet_httpd_restart(port, root_dir, cgi_pattern);
	#else
	return 0;
	#endif
}
void vm_inet_httpd_cgi_job_finish(VMUINT32 hc_handle)
{
	#ifdef __INET_HTTPD__
    inet_httpd_cgi_job_finish(hc_handle);
	  return;
	  #else
	  return;
	  #endif
}
VMINT32 vm_inet_httpd_read(VMUINT32 hc_handle, VMINT8* buf, VMINT32 buf_size)
{
	#ifdef __INET_HTTPD__
	  return inet_httpd_read(hc_handle, buf, buf_size);
	#else
	  return 0;
	#endif
}
VMINT32 vm_inet_httpd_write(VMUINT32 hc_handle, VMINT8* buf, VMINT32 content_size)
{
	#ifdef __INET_HTTPD__
	  return inet_httpd_write(hc_handle, buf, content_size);
	#else
	  return 0;
	#endif
}
VMINT8* vm_inet_httpd_getenv(VMUINT32 hc_handle, VMINT8* name)
{
	#ifdef __INET_HTTPD__
	  return inet_httpd_getenv(hc_handle, name);
	#else
	  return 0;
  #endif
}
void vm_inet_httpd_enable_ssl(VMUINT32 port, VMINT8* cer_dir, VMINT8* peer_cn, VMINT8* server_key_passwd)
{
	#ifdef __INET_HTTPS__
	  inet_httpd_enable_ssl(port, cer_dir,peer_cn,server_key_passwd);
	  return;
	#else
	  return;
  #endif
}
void vm_inet_httpd_disable_ssl()
{	
	#ifdef __INET_HTTPS__
	  inet_httpd_disable_ssl();
	  return;
	#else
	  return;
  #endif
}

#endif/*__IOT__*/