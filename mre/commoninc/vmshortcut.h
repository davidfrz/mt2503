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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _VM_SHORTCUT_
#define	_VM_SHORTCUT_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/**
 *	ͨ�������ȫ·�����ļ�������ȡVXP�ļ��е�icon��Ϣ��
 *	������Ҫ�������Ρ�
 *	��һ�ε��ã����ò���icon_ptrΪNULL��������iconͼ�����ݵĳ��ȡ�
 *	�ڶ��ε��ã�ͨ������icon_ptr����icon��ͼ������
 *
 *	@param vxp_filename VXP�ļ����ļ�������ȫ·��
 *	@param icon_ptr			���ͼ�����ݿռ���׵�ַָ��
 *	@param size					���ͼ�����ݿռ�Ĵ�С
 *
 *	@return  ͼ��������Ҫ�洢�ռ�Ĵ�С�������һ�ε��÷���Ϊ0�������ȡͼ����Ϣʧ�ܡ�
 */
VMINT vm_get_appicon( VMWSTR vxp_filename, VMSTR icon_ptr, VMINT size);

/**
 *	ͨ�������ȫ·�����ļ�������ȡVXP�ļ��е�appid��Ϣ��
 *
 *	@param vxp_filename VXP�ļ����ļ�������ȫ·��
 *
 *	@return  ����VXP�ļ��е�appid���������0�������ȡʧ�ܡ�
 */
VMINT vm_get_appid(VMWSTR vxp_filename);


/**
 *	��֤Ӧ�ó����Ƿ���Ч
 *
 *	@param vxp_filename VXP�ļ����ļ�������ȫ·��
 *
 *	@return  Ӧ�ó�����֤ͨ��,����0, ���򷵻ظ����Ĵ����롣�ο�vmcerter.h
 */
VMINT vm_app_is_valid(VMWSTR vxp_filename);


#ifdef __cplusplus
}
#endif

#endif
