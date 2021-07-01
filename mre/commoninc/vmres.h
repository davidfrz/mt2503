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
 * ������Դ�����ߡ�MREӦ�ó������Դ����ִ���ļ���ʽ��ͬ������ڲ�ͬ��λ�ã�����
 * ELF��ʽ�Ŀ�ִ���ļ�����Դ����ͼ�������������һ���ض���SECTION�ڣ�.vmres����
 * ����PE��ʽ��WIN32ִ���ļ�����Դ�ļ��������ִ���ļ���β�����������ʵ��ϸ����
 * ϵͳʵ�֣�Ӧ�ò�ֻ��Ҫ������Ӧ�ӿں����Ϳ��������Դ����Ͷ�������
 *
 * WIN32 PE��ʽ�ļ������ʽ��
 *
 *   +-----------------------------+
 *   | PE Executable File(.exe)    |
 *   +-----------------------------+
 *   | MRE Resource Section.       |
 *   +-----------------------------+
 *   | Resource Head.              |
 *   +-----------------------------+
 *
 *   Resource Head��һ���ṹ�壬������ÿ����Ա��������4�ֽڶ��롣
 *     struct vm_pe_res_head_t {
 *         char sign[6];		// "VMRES\xF9"
 *         int  offset;			// �������Դ�����ļ��е�ƫ����������ͷ��ʼ���ֽڵ�λ��
 *         int  size;           // �������Դ���С���ֽڵ�λ��
 *         char reserved[8];	// �����ֶΣ�ȫ����0��
 *     };
 *
 * ARM ELF��ʽ�ļ������ʽ��
 *
 *   +-----------------------------+
 *   | ELF Executable File(.axf)   |
 *   +-----------------------------+
 *   | MRE Resource Section.       |
 *   | Inserted as .VM_RES         |
 *   +-----------------------------+
 *
 *   ��ELF��ʽ����Դ��section����ʽ�����ļ�����˲���Ҫ���ӵ���Դͷ��
 *
 * ��Դ��������ƽ̨����һ����ʽ��
 *
 *   +-----------------------------+
 *   | Resource Descriptor Array   |
 *   +-----------------------------+
 *   | Resource Body.              |
 *   +-----------------------------+
 *
 *   Resource descriptor array��һ���ṹ���飬��Ա��������4�ֽڶ��롣
 *     struct _vm_res_desc_t {
 *         char* name;			// ��Դ���ơ�
 *         int   offset;        // ��Դ���ļ�ͷ��ʼ��ƫ�������ֽڵ�λ��
 *         int   size;          // ��Դ��С���ֽڵ�λ��
 *     };
 *     ������һ��size����0�Ľṹ�������Ҳ����˵resource descriptor array
 *     �ĸ����ܱ���Դ�ļ�������һ��
 *
 * $Author: guangyu.tang $
 * $Date: 2009/03/06 01:38:48 $
 *
 ****************************************************************************/

#ifndef VMRES_H
#define VMRES_H

#include "vmswitch.h"

#ifdef __MRE_LIB_APPRES__

#include "vmres_sdk.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
 * ����Դд���ִ���ļ��У�Ŀǰϵͳ����ʶ����ļ���׺����.axf(ELF)��.exe(WIN32 PE)��
 * 
 * @param filename		Ҫд����Դ�Ŀ�ִ���ļ���������������·����
 * @param res_fns		Ҫ�������Դ�ļ����б�����������·����
 * @param fn_count		��Դ�ļ���������
 *
 * @return				����0��ʾ����ɹ������򷵻ش����롣
 */
VMINT vm_pack_resource(VMWSTR filename, VMWSTR *res_fns, VMINT fn_count);

VMINT vm_get_res_header(void);	

#ifdef __cplusplus
}
#endif


#endif /* __MRE_LIB_APPRES__ */

#endif /* VMRES_H */
