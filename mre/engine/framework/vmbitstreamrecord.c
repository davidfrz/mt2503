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
*   vmbitstreamrecord.cpp 
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   BitstreamRecord implement file
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "vmswitch.h"
#include "MMI_features.h"

#ifdef __MRE_SAL_BITSTREAM__

#include "gdi_datatype.h"
#include "mdi_datatype.h"
#include "mdi_bitstream.h"
#include "vmsys.h"
#include "vmbitstream.h"
#include "vmlog.h"

vm_bitstream_audio_result_callback m_result_callback = NULL;
VMINT m_phandle = 0;

extern VMINT vm_sal_query_calling(void);

static void vm_bistream_record_callback_helper(VMINT handle, VMINT result)
{
	if (m_result_callback == NULL )
	{
		return;
	}

	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}
	m_result_callback(handle, result);
	vm_pmng_reset_ctx();
}


VMINT vm_bitstream_record_open(VMINT* handle_p,vm_bitstream_record_cfg_struct* cfg_p,vm_bitstream_audio_result_callback callback)
{
	VMINT ret = -500;
	
	if (vm_sal_query_calling() == TRUE)
		return MDI_RES_STREAM_REC_ERR_FAILED;
	
	m_phandle = vm_pmng_get_current_handle();
	m_result_callback = callback;
    if(cfg_p)
    {	
        if(VM_BITSTREAM_CODEC_TYPE_SILENT == cfg_p->codec_type)
        {
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_SILENT;
        }
		else if(VM_BITSTREAM_CODEC_TYPE_AMR == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_AMR;
		}
		else if(VM_BITSTREAM_CODEC_TYPE_AMRWB == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_AMRWB;
		}
		else if(VM_BITSTREAM_CODEC_TYPE_AAC == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_AAC;
		}
		else if(VM_BITSTREAM_CODEC_TYPE_DAF == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_DAF;
		}
		else if(VM_BITSTREAM_CODEC_TYPE_MP4A == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_MP4A;
		}
		else if(VM_BITSTREAM_CODEC_TYPE_MP4AG == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_MP4AG;
		}
		else if(VM_BITSTREAM_CODEC_TYPE_WAV == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_WAV;
		}
		else if(VM_BITSTREAM_CODEC_TYPE_ADPCM == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_ADPCM;
		}
		else if(VM_BITSTREAM_CODEC_TYPE_PCM == cfg_p->codec_type)
		{
			cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_PCM;
		}
		else
		{
			return ret;
		}



		if(VM_BITSTREAM_RECORD_QUALITY_LOW == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_QUALITY_LOW;
		}
		else if(VM_BITSTREAM_RECORD_QUALITY_MED == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_QUALITY_MED;
		}
		else if(VM_BITSTREAM_RECORD_QUALITY_HIGH == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_QUALITY_HIGH;
		}
		else if(VM_BITSTREAM_RECORD_QUALITY_BEST == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_QUALITY_BEST;
		}
		else if(VM_BITSTREAM_RECORD_AMR_4_75 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_4_75;
		}
		else if(VM_BITSTREAM_RECORD_AMR_5_15 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_5_15;
		}
		else if(VM_BITSTREAM_RECORD_AMR_5_9 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_5_9;
		}
		else if(VM_BITSTREAM_RECORD_AMR_6_7 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_6_7;
		}
		else if(VM_BITSTREAM_RECORD_AMR_7_4 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_7_4;
		}	
		else if(VM_BITSTREAM_RECORD_AMR_7_95 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_7_95;
		}
		else if(VM_BITSTREAM_RECORD_AMR_10_2 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_10_2;
		}
		else if(VM_BITSTREAM_RECORD_AMR_12_2 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_12_2;
		}
		else
		{
			return ret;
		}

	    ret = mdi_bitstream_record_open(handle_p,(mdi_bitstream_record_cfg_struct*)cfg_p,vm_bistream_record_callback_helper);
    }
    return ret;
}

VMINT vm_bitstream_record_close(VMINT handle)
{
	VMINT ret = mdi_bitstream_record_close( handle);
	return ret;
}

VMINT vm_bitstream_record_start(VMINT handle)
{
	VMINT ret;
	if (vm_sal_query_calling() == TRUE)
		return MDI_RES_STREAM_REC_ERR_FAILED;
	ret	=  mdi_bitstream_record_start( handle);
	return ret;
}

VMINT vm_bitstream_record_stop(VMINT handle)
{
	VMINT ret =  mdi_bitstream_record_stop(handle);
	return ret;
}

VMINT vm_bitstream_record_get(VMINT handle,vm_bitstream_record_get_type_enum get_type,void* data_p,VMUINT16* data_len_p)
{
	VMINT ret;
    mdi_bitstream_record_get_type_enum mdi_get_type;
	if(get_type ==VM_BITSTREAM_RECORD_GET_LENGTH )
	{
		mdi_get_type = MDI_BITSTREAM_RECORD_GET_LENGTH;
	}
	else if(get_type ==VM_BITSTREAM_RECORD_GET_DATA )
	{
		mdi_get_type = MDI_BITSTREAM_RECORD_GET_DATA;
	}
	else if(get_type == VM_BITSTREAM_RECORD_GET_STRENGTH)
	{
		mdi_get_type = MDI_BITSTREAM_RECORD_GET_STRENGTH;
	}
	else
	{
		return -500;
	}
	

	ret =  mdi_bitstream_record_get( handle, mdi_get_type,data_p, data_len_p);
	
	return ret;
} 

VMINT vm_bitstream_record_set(VMINT handle,vm_bitstream_record_set_type_enum set_type,void* data_p,VMUINT16 data_len)
{
	VMINT ret;
    mdi_bitstream_record_set_type_enum mdi_set_type;
	if(VM_BITSTREAM_RECORD_SET_PAUSE ==set_type )
	{
		mdi_set_type =MDI_BITSTREAM_RECORD_SET_PAUSE;
	}
	else if(VM_BITSTREAM_RECORD_SET_RESUME == set_type)
	{
		mdi_set_type =MDI_BITSTREAM_RECORD_SET_RESUME;
	}
	else if(VM_BITSTREAM_RECORD_SET_CB_THRESHOLD ==set_type)
	{
		mdi_set_type =MDI_BITSTREAM_RECORD_SET_CB_THRESHOLD;
	}
	else
	{
		return -500;
	}

	ret =  mdi_bitstream_record_set( handle, mdi_set_type, data_p, data_len);
	return ret;
}

#endif

