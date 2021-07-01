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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  mmi2udx_struct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for the data struct of UDX messages.
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
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef MMI2UDX_STRUCT_H
#define MMI2UDX_STRUCT_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
/* Write your #include header file here */

#include "kal_general_types.h"
#include "app_ltlcom.h"

#ifdef __UDX_SUPPORT__

#include "custom_mmi_default_value.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Write your #define here */

#define MAX_UDX_VENDOR_INFO_LEN     (20)
#define MAX_UDX_DEVICE_INFO_LEN     (20)
#define MAX_UDX_VERSION_LEN         (10)
#define MAX_UDX_USER_AGENT_LEN      (20)
#define MAX_UDX_USER_INFO_LEN       ((MMI_PHB_NAME_FIELD_LENGTH * 2) + 1)   /* there is a space char between first name and last name */
#define MAX_UDX_ENCODING_LEN        (10)
#define MAX_UDX_DATE_LEN            (20)
#define MAX_UDX_LANGUAGE_LEN        (20)
#define MAX_UDX_PATH_LEN            (260)

#define UDX_SET_MASK(mask, i)       (mask) |= (0x01 << (i))
#define UDX_IS_SET_MASK(mask, i)    ((mask) & (0x01 << (i)))

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/* Write your typedef here (enum, struct, ...) */

typedef enum
{
    UDX_TYPE_VCARD = 0x01,
    UDX_TYPE_VCALENDAR = 0x02,
    UDX_TYPE_SMS = 0x04,
    UDX_TYPE_MMS = 0x08,
    UDX_TYPE_EMAIL = 0x10
} udx_type_enum;

typedef enum
{
    UDX_TAG_ID_VENDOR_INFO,
    UDX_TAG_ID_DEVICE_INFO,
    UDX_TAG_ID_UDX_VERSION,
    UDX_TAG_ID_USER_AGENT,
    UDX_TAG_ID_USER_INFO,
    UDX_TAG_ID_ENCODING,
    UDX_TAG_ID_FILE_SIZE,
    UDX_TAG_ID_DATE,
    UDX_TAG_ID_LANGUAGE,
    UDX_TAG_ID_VCARD_RECORD_INFO,
    UDX_TAG_ID_VCARD_VERSION,
    UDX_TAG_ID_VCARD_RECORD,
    UDX_TAG_ID_VCARD_LENGTH,
    UDX_TAG_ID_VCALENDAR_RECORD_INFO,
    UDX_TAG_ID_VCALENDAR_VERSION,
    UDX_TAG_ID_VCALENDAR_RECORD,
    UDX_TAG_ID_VCALENDAR_LENGTH,
    UDX_TAG_ID_SMS_RECORD_INFO,
    UDX_TAG_ID_SMS_VERSION,
    UDX_TAG_ID_SMS_RECORD,
    UDX_TAG_ID_SMS_LENGTH,
    UDX_TAG_ID_MMS_RECORD_INFO,
    UDX_TAG_ID_MMS_VERSION,
    UDX_TAG_ID_MMS_RECORD,
    UDX_TAG_ID_MMS_LENGTH,
    UDX_TAG_ID_EMAIL_RECORD_INFO,
    UDX_TAG_ID_EMAIL_VERSION,
    UDX_TAG_ID_EMAIL_RECORD,
    UDX_TAG_ID_EMAIL_LENGTH,
    UDX_TAG_ID_MAX
} udx_tag_id_enum;

typedef enum
{
    UDX_TAG_ID_VCARD_SEQUENCE,
    UDX_TAG_ID_VCARD_N,
    UDX_TAG_ID_VCARD_TEL_CELL,
    UDX_TAG_ID_VCARD_TEL_WORK,
    UDX_TAG_ID_VCARD_TEL_VOICE_WORK,
    UDX_TAG_ID_VCARD_TEL_HOME,
    UDX_TAG_ID_VCARD_TEL_VOICE_HOME,
    UDX_TAG_ID_VCARD_TEL_FAX,
    UDX_TAG_ID_VCARD_ADR_MAILBOX,
    UDX_TAG_ID_VCARD_ADR_DETAIL,
    UDX_TAG_ID_VCARD_ADR_STREET,
    UDX_TAG_ID_VCARD_ADR_CITY,
    UDX_TAG_ID_VCARD_ADR_PROVINCE,
    UDX_TAG_ID_VCARD_ADR_POSTCODE,
    UDX_TAG_ID_VCARD_ADR_COUNTRY,
    UDX_TAG_ID_VCARD_URL,
    UDX_TAG_ID_VCARD_ORG_NAME,
    UDX_TAG_ID_VCARD_TITLE,
    UDX_TAG_ID_VCARD_BDAY,
    UDX_TAG_ID_VCARD_EMAIL,
    UDX_TAG_ID_VCARD_EMAIL_HOME,
    UDX_TAG_ID_VCARD_MAX
} udx_tag_id_vcard_enum;

typedef enum
{
    UDX_CODE_NO_ERROR,
    UDX_CODE_NEW_XML_ERROR,
    UDX_CODE_XML_FAIL_ERROR,
    UDX_CODE_ENCODING_ERROR,
    UDX_CODE_MISMATCH_ERROR,
    UDX_CODE_ATTRIBUTE_ERROR,
    UDX_CODE_ENTITY_ERROR,
    UDX_CODE_FILE_NOT_FOUND_ERROR,
    UDX_CODE_ROOT_DIR_FULL_ERROR,
    UDX_CODE_DISK_FULL_ERROR,
    UDX_CODE_XML_DOC_ERROR = 0x64,
    UDX_CODE_STAG_ERROR = 0xF0,
    UDX_CODE_ETAG_ERROR = 0xF1,
    UDX_CODE_DATA_ERROR = 0xF2,
    UDX_CODE_UNEXPECTED_ERROR = 0xFF
} udx_error_code_enum;

typedef enum
{
    UDX_STATE_IDLE,
    UDX_STATE_BUILD_BEGIN,
    UDX_STATE_BUILD_VCARD,
    UDX_STATE_BUILD_VCALENDAR,
    UDX_STATE_BUILD_SMS,
    UDX_STATE_BUILD_MMS,
    UDX_STATE_BUILD_EMAIL,
    UDX_STATE_BUILD_ABORT,
    UDX_STATE_BUILD_END,
    UDX_STATE_PARSE_HEADER,
    UDX_STATE_PARSE_BODY,
    UDX_STATE_PARSE_VCARD,
    UDX_STATE_PARSE_VCALENDAR,
    UDX_STATE_PARSE_SMS,
    UDX_STATE_PARSE_MMS,
    UDX_STATE_PARSE_EMAIL,
    UDX_STATE_PARSE_ABORT,
    UDX_STATE_PARSE_FINISH
} udx_state_enum;

typedef enum
{
    UDX_STEP_IDLE,
    UDX_STEP_DATA_EXCHANGE_INFO,
    UDX_STEP_RECORD_INFO,
    UDX_STEP_VCARD,
    UDX_STEP_VCALENDAR,
    UDX_STEP_SMS,
    UDX_STEP_MMS,
    UDX_STEP_EMAIL,
    UDX_STEP_RECORD_OF_VCARD,
    UDX_STEP_RECORD_OF_VCALENDAR,
    UDX_STEP_RECORD_OF_SMS,
    UDX_STEP_RECORD_OF_MMS,
    UDX_STEP_RECORD_OF_EMAIL,
    UDX_STEP_VCARD_INFO,
    UDX_STEP_VCARD_FIELD,
    UDX_STEP_MAX
} udx_step_enum;

typedef struct
{
    kal_uint8 vendor_info[(MAX_UDX_VENDOR_INFO_LEN + 1) * ENCODING_LENGTH];
    kal_uint8 device_info[(MAX_UDX_DEVICE_INFO_LEN + 1) * ENCODING_LENGTH];
    kal_uint8 udx_version[(MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH];
    kal_uint8 user_agent[(MAX_UDX_USER_AGENT_LEN + 1) * ENCODING_LENGTH];
    kal_uint8 user_info[(MAX_UDX_USER_INFO_LEN + 1) * ENCODING_LENGTH];
    kal_uint8 encoding[(MAX_UDX_ENCODING_LEN + 1) * ENCODING_LENGTH];
    kal_uint32 file_size;
    kal_uint8 date[(MAX_UDX_DATE_LEN + 1) * ENCODING_LENGTH];
    kal_uint8 language[(MAX_UDX_LANGUAGE_LEN + 1) * ENCODING_LENGTH];
    kal_uint8 vcard_version[(MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH];
    kal_uint16 vcard_record;
    kal_uint32 vcard_length;
    kal_uint8 vcalendar_version[(MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH];
    kal_uint16 vcalendar_record;
    kal_uint32 vcalendar_length;
    kal_uint8 sms_version[(MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH];
    kal_uint16 sms_record;
    kal_uint32 sms_length;
    kal_uint8 mms_version[(MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH];
    kal_uint16 mms_record;
    kal_uint32 mms_length;
    kal_uint8 email_version[(MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH];
    kal_uint16 email_record;
    kal_uint32 email_length;
} udx_header_info_struct;

typedef struct
{
    mmi_phb_num_type_enum type;                             
    kal_uint8 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1]; 
} udx_dynamic_number;

typedef struct
{
    kal_uint8 n[(MMI_PHB_NAME_FIELD_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 l_n[(MMI_PHB_NAME_FIELD_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 tel_cell[MMI_PHB_NUMBER_PLUS_LENGTH + 1];

    udx_dynamic_number dyn_num[MMI_PHB_OPT_NUM_COUNT];
/*
    kal_uint8 tel_work[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    kal_uint8 tel_home[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    kal_uint8 tel_fax[MMI_PHB_NUMBER_PLUS_LENGTH + 1];

    kal_uint8 tel_cell_work[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    kal_uint8 tel_cell_home[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    kal_uint8 tel_video[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    kal_uint8 tel_video_work[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    kal_uint8 tel_video_home[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    kal_uint8 tel_video_cell[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    kal_uint8 tel_fax_work[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    kal_uint8 tel_fax_home[MMI_PHB_NUMBER_LENGTH + 1 + 1];
*/
    kal_uint8 adr_mailbox[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_detail[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_street[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_city[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_province[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_postcode[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_country[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
/*
    kal_uint8 adr_home_mailbox[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_home_detail[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_home_street[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_home_city[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_home_province[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_home_postcode[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_home_country[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_work_mailbox[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_work_detail[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_work_street[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_work_city[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_work_province[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_work_postcode[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 adr_work_country[(MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH];
*/
    kal_uint8 url[MMI_PHB_URL_LENGTH + 1];
    kal_uint8 org_name[(MMI_PHB_COMPANY_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 title[(MMI_PHB_TITLE_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 bday[MMI_PHB_BDAY_LENGTH + 1];
    kal_uint8 email[MMI_PHB_EMAIL_LENGTH + 1];
    kal_uint8 email_home[MMI_PHB_EMAIL_LENGTH + 1];
/*
    kal_uint8 url_home[MMI_PHB_URL_LENGTH + 1];
    kal_uint8 url_work[MMI_PHB_URL_LENGTH + 1];
    kal_uint8 org_unit[(MMI_PHB_COMPANY_LENGTH + 1) * ENCODING_LENGTH];
    kal_uint8 email_home[MMI_PHB_EMAIL_LENGTH + 1];
    kal_uint8 email_work[MMI_PHB_EMAIL_LENGTH + 1];
*/
    kal_uint8 extention[1];
} udx_vcard_data_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 file_path[(MAX_UDX_PATH_LEN + 1) * ENCODING_LENGTH];
    kal_uint8 user_name[(MAX_UDX_USER_INFO_LEN + 1) * ENCODING_LENGTH];
    kal_uint8 date_format;
    kal_uint8 separator_format;
    kal_uint8 type_mask;
    kal_uint16 vcard_count;
    kal_uint16 vcalendar_count;
    kal_uint16 sms_count;
    kal_uint16 mms_count;
    kal_uint16 email_count;
} mmi_udx_build_header_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 error_code;
    kal_uint8 state;
} mmi_udx_build_header_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 data_type;
    kal_uint16 sequence;
    union
    {
        udx_vcard_data_struct vcard_data;
    } u;
} mmi_udx_build_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 error_code;
    kal_uint8 state;
} mmi_udx_build_data_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 error_code;
    kal_uint8 state;
} mmi_udx_build_end_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 error_code;
    kal_uint8 state;
} mmi_udx_build_abort_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 file_path[(MAX_UDX_PATH_LEN + 1) * ENCODING_LENGTH];
} mmi_udx_parse_header_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 error_code;
    kal_uint8 state;
    kal_uint32 valid_mask;
    udx_header_info_struct h_info;
} mmi_udx_parse_header_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 file_path[(MAX_UDX_PATH_LEN + 1) * ENCODING_LENGTH];
    kal_uint8 type_mask;
} mmi_udx_parse_body_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 error_code;
    kal_uint8 state;
} mmi_udx_parse_body_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool mem_full;
} mmi_udx_parse_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 error_code;
    kal_uint8 state;
    kal_uint32 valid_mask;
    kal_uint8 data_type;
    kal_uint16 sequence;
    union
    {
        udx_vcard_data_struct vcard_data;
    } u;
    kal_uint8 lost_count;
} mmi_udx_parse_data_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 error_code;
    kal_uint8 state;
} mmi_udx_parse_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 error_code;
    kal_uint8 state;
} mmi_udx_parse_abort_rsp_struct;

#endif /* __UDX_SUPPORT__ */

/***************************************************************************** 
 * Include 
 *****************************************************************************/
/* Write your #include header file here */

#ifdef __MULTI_VCARD_SUPPORT__

#include "vcard_lib.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Write your #define here */

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/* Write your typedef here (enum, struct, ...) */

typedef struct
{
    LOCAL_PARA_HDR
    VB_HANDLE vb;
    vcard_object_struct *object;
    vcard_builder_callback_type vb_callback;
    void *user_data;
} mmi_udx_build_vcard_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *handle;
    vcard_builder_callback_type vb_callback;
    kal_int32 error_code;
    void *user_data;
} mmi_udx_build_vcard_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    VP_HANDLE vp;
    vcard_parser_callback_type vp_callback;
    void *user_data;
} mmi_udx_parse_vcard_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *handle;
    vcard_parser_callback_type vp_callback;
    kal_int32 error_code;
    kal_uint16 percentage;
    vcard_object_struct *object;
    void *user_data;
} mmi_udx_parse_vcard_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    VP_HANDLE vp;
    vcard_parser_callback_ex_type vp_callback_ex;
    void *user_data;
} mmi_udx_read_vcard_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *handle;
    vcard_parser_callback_ex_type vp_callback_ex;
    kal_int32 error_code;
    kal_uint32 object_count;
    kal_int32 *object_offset_list;
    void *user_data;
} mmi_udx_read_vcard_rsp_struct;

#endif /* __MULTI_VCARD_SUPPORT__ */

#endif /* MMI2UDX_STRUCT_H */ 

