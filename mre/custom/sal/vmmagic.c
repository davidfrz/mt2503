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

/*******************************************************************************
* Filename:
* ---------
*  
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
*
* Author:
* -------
*
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
 * removed!
*
 * removed!
 * removed!
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "mmi_features.h"
#include "vmswitch.h"
#include "vmmagic.h"
#include "vmmagic_internal.h"
#include "vmpromng.h"
#include "vmsys.h"
#include "MMITimer.h"
#include "vmmem.h"

extern VMINT mre_running;

#if !defined(__MRE_MAGIC_API_SAMPLE__)
VMINT vm_magic_wrapper_for_customer(VMINT index, void* param, void* reserve)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
        case 1000:
        {
            /* if param has info about callback and callback can handle info data */

            break;
        }
        case 1001:
        {
            /* if param has info about callback and callback only handle native handle */

            break;
        }
        case 1002:
        {
            /* if param has info about callback and callback  handle nothing */
 
            break;
        }
        case 1003:
        {
            break;
        }
        default:
        {
            break;
        }
    }
    return ret;
}

#else /* !defined(__MRE_MAGIC_API_SAMPLE__) */

typedef void (*FuncPtr1002) (void);
typedef void (*FuncPtr1001)(void);
typedef void (*FuncPtr1000)(VMUINT);
/* struct of customer define, customer can add other struct element */
typedef struct vm_magic_customer_t {
    /* the resource id when saving in resource */
    VMINT resid;
    FuncPtr1000 funcPtr;
    FuncPtr1001 funcPtr1001;
    VMUINT data;
}vm_magic_customer_t;

typedef struct vm_magic_1002_t{
    VMUINT timerid;
    VMUINT delay;
    FuncPtr1002 funcPtr;
}vm_magic_1002_t;

typedef struct vm_magic_1001_t{
    FuncPtr1001 funcPtr;
}vm_magic_1001_t;

typedef struct vm_magic_1000_t{
    VMUINT timerid;
    VMUINT delay;
    FuncPtr1000 funcPtr;
    VMUINT data;
}vm_magic_1000_t;


static VMINT vm_magic_1000_handle(void* data);
static VMINT vm_magic_1001_handle(void* data);
static VMINT vm_magic_1002_handle(void* data);


VMINT vm_magic_wrapper_for_customer(VMINT index, void* param, void* reserve)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (index)
    {
        case 1000:
        {
            /* if param has info about callback and callback can handle info data */
            vm_magic_1000_handle(param);
            break;
        }
        case 1001:
        {
            /* if param has info about callback and callback only handle native handle */
            vm_magic_1001_handle(param);
            break;
        }
        case 1002:
        {
            /* if param has info about callback and callback  handle nothing */
            vm_magic_1002_handle(param);
            break;
        }
        case 1003:
        {
            break;
        }
        default:
        {
            break;
        }
    }
    return ret;
}


void vm_magic_1000_cb(void* userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_magic_t *magic_p = NULL;
    vm_magic_customer_t *magic_customer_p = (vm_magic_customer_t *)userdata;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_magic_get_data_by_resid(magic_customer_p->resid, (void**)&magic_p);
    magic_customer_p = magic_p->pointer;
    //got the app_callback from magic_customer_p
    if (vm_pmng_set_ctx(magic_p->m_pHandle) == VM_PMNG_OP_OK)
    {
        if (mre_running == FALSE)
        {
            vm_pmng_reset_ctx();
            return;
        }
       if (magic_customer_p->funcPtr)
       {
           magic_customer_p->funcPtr(magic_customer_p->data);
       }
       vm_pmng_reset_ctx();
    }
    vm_magic_cancel(magic_customer_p->resid);
}


static VMINT vm_magic_1000_handle(void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT resid;
    vm_magic_t *magic_p = NULL;
    vm_magic_customer_t *magic_customer_p = NULL;
    vm_magic_1000_t* magic_customer_data = (vm_magic_1000_t*)data;
    VM_P_HANDLE phandle = vm_pmng_get_current_handle();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (phandle < 0)
    {
        return -1;
    }    
    magic_p = (vm_magic_t*)_vm_kernel_malloc(sizeof(vm_magic_t));
    magic_customer_p = (vm_magic_customer_t*)_vm_kernel_malloc(sizeof(vm_magic_customer_t));
    magic_p->pointer = magic_customer_p;
    magic_p->m_pHandle = phandle;
    resid = vm_magic_save_data(magic_p);
    magic_customer_p->resid = resid;
    magic_customer_p->funcPtr = magic_customer_data->funcPtr;
    magic_customer_p->data = magic_customer_data->data;
    StartNonAlignTimerEx(magic_customer_data->timerid, magic_customer_data->delay, vm_magic_1000_cb, magic_customer_p);

    return 0;
}

static VM_P_HANDLE g_phandle_1001 = -1;
VMINT vm_magic_1001_cb(VMINT native_handle)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_magic_customer_t *magic_customer_p = NULL;
    vm_magic_t *magic_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    vm_magic_get_data_by_native_handle(native_handle, (void**)&magic_p, g_phandle_1001);
    magic_customer_p = magic_p->pointer;
    //got the app_callback from magic_customer_p
    
    if (vm_pmng_set_ctx(magic_p->m_pHandle) == VM_PMNG_OP_OK)
    {
        if (mre_running == FALSE)
        {
            vm_pmng_reset_ctx();
            return -1;
        }
       if (magic_customer_p->funcPtr1001)
       {
           magic_customer_p->funcPtr1001();
       }
       vm_pmng_reset_ctx();
    }
    vm_magic_cancel(magic_customer_p->resid);
    return 0;
}


static VMINT native_handle = 0;
static void mmi_magic_1001_timer_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_magic_1001_cb(native_handle);
    native_handle = 0;
}
static VMINT mmi_magic_1001_native_func(FuncPtr1001 funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT16 timer_id = 0;
    VMINT delay_timer = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(native_handle == 0)
    {
        native_handle = 2000; 
        timer_id = 0xabcd+4;
        delay_timer = 4000;
    }
    StartTimer(timer_id, delay_timer, mmi_magic_1001_timer_cb);
    return native_handle;
}

static VMINT vm_magic_1001_handle(void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT native_handle = 0;
    VMINT resid;
    vm_magic_t *magic_p = NULL;
    vm_magic_customer_t *magic_customer_p = NULL;
    vm_magic_1001_t* magic_customer_data = (vm_magic_1001_t*)data;
    VM_P_HANDLE phandle = vm_pmng_get_current_handle();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phandle < 0)
    {
        return -1;
    }
    g_phandle_1001 = phandle;
    magic_p = (vm_magic_t*)_vm_kernel_malloc(sizeof(vm_magic_t));
    magic_customer_p = (vm_magic_customer_t*)_vm_kernel_malloc(sizeof(vm_magic_customer_t));
    magic_p->pointer = magic_customer_p;
    magic_p->m_pHandle = phandle;
    ///prepare data structure -> got the pointer
    magic_customer_p->funcPtr1001 = magic_customer_data->funcPtr;
    native_handle = mmi_magic_1001_native_func(mmi_magic_1001_native_func);
    magic_p->native_handle = native_handle;
    resid = vm_magic_save_data(magic_p);
    magic_customer_p->resid = resid;
    return 0;
}

static FuncPtr1002 g_callback_1002 = NULL;
static VM_P_HANDLE g_phandle_1002 = -1;
void vm_magic_1002_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_pmng_set_ctx(g_phandle_1002) == VM_PMNG_OP_OK)
    {
        if (mre_running == FALSE)
        {
            vm_pmng_reset_ctx();
            return;
        }
       if(g_callback_1002)
       {
           g_callback_1002();
       }
       vm_pmng_reset_ctx();
    }
    g_callback_1002 = NULL;
    g_phandle_1002 = -1;
}


static VMINT vm_magic_1002_handle(void* data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_magic_1002_t* info_data = (vm_magic_1002_t*)data;
     VM_P_HANDLE g_phandle = vm_pmng_get_current_handle();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_callback_1002 = info_data->funcPtr;
    g_phandle_1002 = g_phandle;
    StartTimer(info_data->timerid, info_data->delay, vm_magic_1002_cb);

    return 0;
}
#endif /* !defined(__MRE_MAGIC_API_SAMPLE__) */

