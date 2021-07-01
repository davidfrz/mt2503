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
 * xyssl_mem.c
 *
 * Project:
 * --------
 *   OpenSSL
 *
 * Description:
 * ------------
 *   This is file is used to adapt the memory related APIs in OpenSSL
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "stdlib.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "string.h"
#include "xyssl_mem.h"
#include "xyssl_log.h"
#include "msf_mem.h"
#include "stk_main.h"


/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_malloc
 * DESCRIPTION
 *  This function is to adapt the memory allocation function to kal system
 * PARAMETERS
 *  size        [IN]    request memory size need to allocate
 *  mod_name    [IN]    module name who tries to malloc
 *  line_no     [IN]    line number in the library while malloc
 * RETURNS
 *  ptr : allocated memory pointer from OPENSSL ADM
 *****************************************************************************/
void* xyssl_adp_malloc(kal_uint32 size, char *file, int line, ssl_context *ssl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(ssl->alloc != NULL)
		ptr = ssl->alloc(size,ssl->user_data);

	return ptr;
    
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_realloc
 * DESCRIPTION
 *  This function is to adapt the memory re-allocation function to kal system.
 *  DO NOT guarentee the memory data is initialized !!
 * PARAMETERS
 *  ptr         [IN]    pointer to the original block of memory
 *  new_size    [IN]    request memory size need to re-allocate
 *  mod_name    [IN]    module name who tries to malloc
 *  line_no     [IN]    line number in the library while malloc
 * RETURNS
 *  ptr : allocated memory pointer from OPENSSL ADM
 *****************************************************************************/
void* xyssl_adp_realloc(void *ptr, kal_uint32 new_size,ssl_context *ssl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *new_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check for special cases.  */
    if (!new_size)
      {
        xyssl_adp_free(ptr, __FILE__, __LINE__,ssl);
        return NULL;
      }
    if (!ptr)
    //  return XYSSL_ADP_MALLOC(new_size,ssl);

    /* handle normal re-alloc memory case */
    /* mutex protection for global ossl memory critical section start */
   // new_ptr = XYSSL_ADP_MALLOC(new_size,ssl);


    if (!new_ptr)
        ASSERT(0);
    
 #ifdef XYSSL_ENABLE_DEBUG
 #ifdef OBIGO_Q03C_BROWSER
	XYSSL_LOG_ERROR_MEM_ALLOC(new_size);	
#endif
 #endif
    /* mutex protection for global ossl memory critical section end */
    /* copy old data to new memory block */
    memmove(new_ptr, ptr, new_size);
    XYSSL_ADP_FREE(ptr,ssl);

    return new_ptr;
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_free
 * DESCRIPTION
 *  This function is to adapt the memory free function to kal system
 * PARAMETERS
 *  ptr         [IN]    pointer to the allocated memory
 * RETURNS
 *  void 
 *****************************************************************************/
void xyssl_adp_free(void *ptr,  char *file, int line,ssl_context *ssl)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(ssl->free)
		ssl->free(ptr,ssl->user_data);
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adpssl_set_dbg_cb
 * DESCRIPTION
 *  This function is to adapt the memory free function to kal system
 * PARAMETERS
 *  ptr         [IN]    pointer to the allocated memory
 * RETURNS
 *  void 
 *****************************************************************************/
void xyssl_adpssl_set_dbg_cb( void* param, int level, char *text)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//printf("String in xyssl_adpssl_set_dbg_cb: %s",text);
	//XYSSL_LOG_ERROR_GENERAL(text);
	kal_wap_trace(MOD_WPS, TRACE_GROUP_1, "XYSSL_LIB:%s",text);
}


