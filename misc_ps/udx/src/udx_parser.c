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
 *  udx_parser.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for UDX builder & parser.
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
/* Write your #include header file here */

#ifdef __UDX_SUPPORT__

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "app_buff_alloc.h"
#include "conversions.h"
#include "app_datetime.h"
#include "app_str.h"
#include "fat_fs.h"
#include "mmi2udx_struct.h"
#include "udx_parser.h"
#include "udx_msg_hdlr.h"
#include "OslMemory.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Write your #define here */

/* XML DTD ELEMENT for Header Information */
#define UDX_TAG_DATA_EXCHANGE_INFO      "DataExchangeInfo"
#define UDX_TAG_RECORD_INFO             "RecordInfo"
#define UDX_TAG_VCARD                   "vCard"
#define UDX_TAG_VCALENDAR               "vCalendar"
#define UDX_TAG_SMS                     "SMS"
#define UDX_TAG_MMS                     "MMS"
#define UDX_TAG_EMAIL                   "Email"
#define UDX_TAG_VENDOR_INFO             "VendorInfo"
#define UDX_TAG_DEVICE_INFO             "DeviceInfo"
#define UDX_TAG_UDX_VERSION             "UdxVersion"
#define UDX_TAG_USER_AGENT              "UserAgent"
#define UDX_TAG_USER_INFO               "UserInfo"
#define UDX_TAG_ENCODING                "Encoding"
#define UDX_TAG_FILE_SIZE               "FileSize"
#define UDX_TAG_DATE                    "Date"
#define UDX_TAG_LANGUAGE                "Language"
#define UDX_TAG_RECORD_OF_VCARD         "RecordOfvCard"
#define UDX_TAG_RECORD_OF_VCALENDAR     "RecordOfvCalendar"
#define UDX_TAG_RECORD_OF_SMS           "RecordOfSMS"
#define UDX_TAG_RECORD_OF_MMS           "RecordOfMMS"
#define UDX_TAG_RECORD_OF_EMAIL         "RecordOfEmail"
#define UDX_TAG_VCARD_VERSION           "vCardVersion"
#define UDX_TAG_VCARD_RECORD            "vCardRecord"
#define UDX_TAG_VCARD_LENGTH            "vCardLength"
#define UDX_TAG_VCALENDAR_VERSION       "vCalendarVersion"
#define UDX_TAG_VCALENDAR_RECORD        "vCalendarRecord"
#define UDX_TAG_VCALENDAR_LENGTH        "vCalendarLength"
#define UDX_TAG_SMS_VERSION             "SMSVersion"
#define UDX_TAG_SMS_RECORD              "SMSRecord"
#define UDX_TAG_SMS_LENGTH              "SMSLength"
#define UDX_TAG_MMS_VERSION             "MMSVersion"
#define UDX_TAG_MMS_RECORD              "MMSRecord"
#define UDX_TAG_MMS_LENGTH              "MMSLength"
#define UDX_TAG_EMAIL_VERSION           "EmailVersion"
#define UDX_TAG_EMAIL_RECORD            "EmailRecord"
#define UDX_TAG_EMAIL_LENGTH            "EmailLength"

/* XML DTD ELEMENT for vCard Data */
#define UDX_TAG_VCARD_INFO              "vCardInfo"
#define UDX_TAG_VCARD_SEQUENCE          "Sequence"
#define UDX_TAG_VCARD_FIELD             "vCardField"
#define UDX_TAG_VCARD_N                 "N"
#define UDX_TAG_VCARD_TEL_CELL          "TELCELL"
#define UDX_TAG_VCARD_TEL_WORK          "TELWORK"
#define UDX_TAG_VCARD_TEL_VOICE_WORK    "TELVOICEWORK"
#define UDX_TAG_VCARD_TEL_HOME          "TELHOME"
#define UDX_TAG_VCARD_TEL_VOICE_HOME    "TELVOICEHOME"
#define UDX_TAG_VCARD_TEL               "TEL"
#define UDX_TAG_VCARD_TEL_VOICE         "TELVOICE"
#define UDX_TAG_VCARD_TEL_VIDEO         "TELVIDEO"
#define UDX_TAG_VCARD_TEL_FAX           "TELFAX"
#define UDX_TAG_VCARD_TEL_CELL_WORK     "TELCELLWORK"
#define UDX_TAG_VCARD_TEL_CELL_HOME     "TELCELLHOME"
#define UDX_TAG_VCARD_TEL_FAX_WORK      "TELFAXWORK"
#define UDX_TAG_VCARD_TEL_FAX_HOME      "TELFAXHOME"
#define UDX_TAG_VCARD_TEL_VIDEO_WORK    "TELVIDEOWORK"
#define UDX_TAG_VCARD_TEL_VIDEO_HOME    "TELVIDEOHOME"
#define UDX_TAG_VCARD_TEL_VIDEO_CELL    "TELVIDEOCELL"
#define UDX_TAG_VCARD_ADR               "ADR"
#define UDX_TAG_VCARD_ADR_MAILBOX       "ADRMAILBOX"
#define UDX_TAG_VCARD_ADR_DETAIL        "ADRDETAIL"
#define UDX_TAG_VCARD_ADR_STREET        "ADRSTREET"
#define UDX_TAG_VCARD_ADR_CITY          "ADRCITY"
#define UDX_TAG_VCARD_ADR_PROVINCE      "ADRPROVINCE"
#define UDX_TAG_VCARD_ADR_POSTCODE      "ADRPOSTCODE"
#define UDX_TAG_VCARD_ADR_COUNTRY       "ADRCOUNTRY"
#define UDX_TAG_VCARD_ADR_HOME          "ADRHOME"
#define UDX_TAG_VCARD_ADR_HOME_MAILBOX  "ADRHOMEMAILBOX"
#define UDX_TAG_VCARD_ADR_HOME_DETAIL   "ADRHOMEDETAIL"
#define UDX_TAG_VCARD_ADR_HOME_STREET   "ADRHOMESTREET"
#define UDX_TAG_VCARD_ADR_HOME_CITY     "ADRHOMECITY"
#define UDX_TAG_VCARD_ADR_HOME_PROVINCE "ADRHOMEPROVINCE"
#define UDX_TAG_VCARD_ADR_HOME_POSTCODE "ADRHOMEPOSTCODE"
#define UDX_TAG_VCARD_ADR_HOME_COUNTRY  "ADRHOMECOUNTRY"
#define UDX_TAG_VCARD_ADR_WORK          "ADRWORK"
#define UDX_TAG_VCARD_ADR_WORK_MAILBOX  "ADRWORKMAILBOX"
#define UDX_TAG_VCARD_ADR_WORK_DETAIL   "ADRWORKDETAIL"
#define UDX_TAG_VCARD_ADR_WORK_STREET   "ADRWORKSTREET"
#define UDX_TAG_VCARD_ADR_WORK_CITY     "ADRWORKCITY"
#define UDX_TAG_VCARD_ADR_WORK_PROVINCE "ADRWORKPROVINCE"
#define UDX_TAG_VCARD_ADR_WORK_POSTCODE "ADRWORKPOSTCODE"
#define UDX_TAG_VCARD_ADR_WORK_COUNTRY  "ADRWORKCOUNTRY"
#define UDX_TAG_VCARD_URL               "URL"
#define UDX_TAG_VCARD_URL_HOME          "URLHOME"
#define UDX_TAG_VCARD_URL_WORK          "URLWORK"
#define UDX_TAG_VCARD_ORG_NAME          "ORGNAME"
#define UDX_TAG_VCARD_ORG_UNIT          "ORGUNIT"
#define UDX_TAG_VCARD_TITLE             "TITLE"
#define UDX_TAG_VCARD_BDAY              "BDAY"
#define UDX_TAG_VCARD_EMAIL             "EMAIL"
#define UDX_TAG_VCARD_EMAIL_HOME        "EMAILHOME"
#define UDX_TAG_VCARD_EMAIL_WORK        "EMAILWORK"
#define UDX_TAG_VCARD_EXTENTION         "EXTENTION"

/* XML DTD ELEMENT for vCalendar Data */
#define UDX_TAG_VCALENDAR_INFO          "vCalendarInfo"
#define UDX_TAG_VCALENDAR_SEQUENCE      "Sequence"
#define UDX_TAG_VCALENDAR_FIELD         "vCalendarField"
#define UDX_TAG_VCALENDAR_START_TIME    "STARTTIME"
#define UDX_TAG_VCALENDAR_STOP_TIME     "STOPTIME"
#define UDX_TAG_VCALENDAR_DESCRIPTION   "DESCRIPTION"
#define UDX_TAG_VCALENDAR_RECUR_TYPE    "RECURTYPE"
#define UDX_TAG_VCALENDAR_BODY          "BODY"
#define UDX_TAG_VCALENDAR_NOTIFY_TYPE   "NOTIFYTYPE"
#define UDX_TAG_VCALENDAR_RINGER_TYPE   "RINGERTYPE"
#define UDX_TAG_VCALENDAR_DURATION      "DURATION"
#define UDX_TAG_VCALENDAR_EXTENTION     "EXTENTION"

/* XML DTD ELEMENT for SMS Data */
#define UDX_TAG_SMS_INFO                "SMSInfo"
#define UDX_TAG_SMS_SEQUENCE            "Sequence"
#define UDX_TAG_SMS_FIELD               "SMSField"
#define UDX_TAG_SMS_ORIGNAL_ADDRESS     "Orignal_Address"
#define UDX_TAG_SMS_DESTINATION_ADDRESS "Destination_Address"
#define UDX_TAG_SMS_DATA                "Data"
#define UDX_TAG_SMS_TIME_STAMP          "TimeStamp"
#define UDX_TAG_SMS_MESSAGE_INFO        "MessageInfo"
#define UDX_TAG_SMS_MT_SMS              "MT_SMS"
#define UDX_TAG_SMS_MO_SMS              "MO_SMS"
#define UDX_TAG_SMS_DRAFT_SMS           "Draft_SMS"
#define UDX_TAG_SMS_DELIVERY_REPORT     "Delivery_Report"
#define UDX_TAG_SMS_EXTENTION           "EXTENTION"

/* XML DTD ELEMENT for MMS Data */
#define UDX_TAG_MMS_INFO                "MMSInfo"
#define UDX_TAG_MMS_SEQUENCE            "Sequence"
#define UDX_TAG_MMS_FIELD               "MMSField"
#define UDX_TAG_MMS_MMS_CONTENT         "MMSContent"
#define UDX_TAG_MMS_CONTENT_IN_MMS      "ContentInMMS"
#define UDX_TAG_MMS_MESSAGE_TYPE        "Message_Type"
#define UDX_TAG_MMS_MMS_VERSION         "MMS_Version"
#define UDX_TAG_MMS_MESSAGE_ID          "Message_ID"
#define UDX_TAG_MMS_SENDER_ADDRESS      "Sender_address"
#define UDX_TAG_MMS_RECIPIENT_ADDRESS   "Recipient_address"
#define UDX_TAG_MMS_MESSAGE_CLASS       "Message_class"
#define UDX_TAG_MMS_DATE_AND_TIME       "Date_and_time"
#define UDX_TAG_MMS_PRIORITY            "Priority"
#define UDX_TAG_MMS_SUBJECT             "Subject"
#define UDX_TAG_MMS_CHARSET             "charset"
#define UDX_TAG_MMS_CONTENT_TRANSFER_ENCODING   "Content-Transfer-Encoding"
#define UDX_TAG_MMS_CONTENT_LOCATION    "Content-Location"
#define UDX_TAG_MMS_DATA                "Data"
#define UDX_TAG_MMS_CONTENT_INFO        "ContentInfo"
#define UDX_TAG_MMS_TYPE                "Type"
#define UDX_TAG_MMS_START               "Start"
#define UDX_TAG_MMS_EXTENTION           "EXTENTION"

/* XML DTD ELEMENT for Email Data */
#define UDX_TAG_EMAIL_INFO              "EmailInfo"
#define UDX_TAG_EMAIL_SEQUENCE          "Sequence"
#define UDX_TAG_EMAIL_FIELD             "EmailField"
#define UDX_TAG_EMAIL_EMAIL_CONTENT     "EmailContent"
#define UDX_TAG_EMAIL_RETURN_PATH       "Return-Path"
#define UDX_TAG_EMAIL_DELIVERED_TO      "Delivered-To"
#define UDX_TAG_EMAIL_RECEIVED          "Received"
#define UDX_TAG_EMAIL_DATE              "Date"
#define UDX_TAG_EMAIL_CC                "CC"
#define UDX_TAG_EMAIL_BCC               "BCC"
#define UDX_TAG_EMAIL_MESSAGE_ID        "Message-ID"
#define UDX_TAG_EMAIL_FROM              "From"
#define UDX_TAG_EMAIL_SUBJECT           "Subject"
#define UDX_TAG_EMAIL_TO                "To"
#define UDX_TAG_EMAIL_REPLY_TO          "Reply-to"
#define UDX_TAG_EMAIL_MIME_VERSION      "MIME-version"
#define UDX_TAG_EMAIL_CONTENT_TYPE      "Content-Type"
#define UDX_TAG_EMAIL_CONTENT_TRANSFER_ENCODING "Content-Transfer-Encoding"
#define UDX_TAG_EMAIL_CONTENT_DESCRIPTION   "Content-Description"
#define UDX_TAG_EMAIL_CONTENT_DISPOSITION   "Content-Disposition"
#define UDX_TAG_EMAIL_CONTENT_CONTENT_ID    "Content-ID"
#define UDX_TAG_EMAIL_CONTENT_CONTENT_TYPE  "Content-type"
#define UDX_TAG_EMAIL_CONTENT_CONTENT_CLASS "Content-class"
#define UDX_TAG_EMAIL_CHARSET           "charset"
#define UDX_TAG_EMAIL_DATA              "Data"
#define UDX_TAG_EMAIL_NAME              "Name"
#define UDX_TAG_EMAIL_FILENAME          "Filename"
#define UDX_TAG_EMAIL_EXTENTION         "EXTENTION"

/* XML Schema ELEMENT default */
#define UDX_DEFAULT_VENDOR_INFO         UDX_CUSTOM_VENDOR_INFO
#define UDX_DEFAULT_DEVICE_INFO         UDX_CUSTOM_DEVICE_INFO
#define UDX_DEFAULT_UDX_VERSION         UDX_CUSTOM_UDX_VERSION
#define UDX_DEFAULT_USER_AGENT          UDX_CUSTOM_USER_AGENT
#define UDX_DEFAULT_USER_INFO           UDX_CUSTOM_USER_INFO
#define UDX_DEFAULT_ENCODING            L"UTF-8"
#define UDX_DEFAULT_LANGUAGE            L"CHS"
#define UDX_DEFAULT_VCARD_VERSION       L"2.1"
#define UDX_DEFAULT_VCALENDAR_VERSION   L"1.0"

/* For XML DOC update */
#define UDX_XML_READ_BUF_SIZE   384
#define UDX_XML_TAG_LENGTH  32
#define UDX_XML_ERROR       -1
#define UDX_XML_SUCCESS     1

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Declare your local function here */

static kal_int32 udx_build_record_info(XG_HANDLE h, kal_uint8 *name, kal_uint8 date, kal_uint8 separator);
static kal_int32 udx_build_terminal_info(XG_HANDLE h);
static kal_int32 udx_build_user_info(XG_HANDLE h, kal_uint8 *name);
static kal_int32 udx_build_integrity_check_info(XG_HANDLE h, kal_uint8 date, kal_uint8 separator);
static kal_int32 udx_build_data_stat_info(XG_HANDLE h);

static kal_int32 udx_build_vcard_info(XG_HANDLE h, kal_uint16 seq, udx_vcard_data_struct *v_data);
static kal_int32 udx_build_vcard_field(XG_HANDLE h, udx_vcard_data_struct *v_data);
static kal_int32 udx_build_name_field(XG_HANDLE h, udx_vcard_data_struct *v_data);
static kal_int32 udx_build_number_field(XG_HANDLE h, udx_vcard_data_struct *v_data);
static kal_int32 udx_build_address_field(XG_HANDLE h, udx_vcard_data_struct *v_data);
static kal_int32 udx_build_other_field(XG_HANDLE h, udx_vcard_data_struct *v_data);

static void udx_add_delimiter(kal_char *str_out, kal_uint16 length);
static void udx_remove_delimiter(kal_char *str_out, kal_uint16 length);
static kal_bool udx_check_mandatory_field_is_valid(void);

static void udx_start_element_hdlr(void *data, const kal_char *el, const kal_char **attr, kal_int32 error);
static void udx_end_element_hdlr(void *data, const kal_char *el, kal_int32 error);
static void udx_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);

static void udx_vendor_info_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_device_info_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_udx_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_user_agent_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_user_info_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_encoding_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_file_size_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_date_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_language_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);

static void udx_vcard_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_record_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_length_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcalendar_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcalendar_record_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcalendar_length_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_sms_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_sms_record_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_sms_length_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_mms_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_mms_record_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_mms_length_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_email_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_email_record_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_email_length_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_sequence_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);

static void udx_vcard_n_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_tel_cell_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_tel_work_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_tel_home_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_tel_fax_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_adr_mailbox_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_adr_detail_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_adr_street_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_adr_city_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_adr_province_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_adr_postcode_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_adr_country_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_url_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_org_name_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_title_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_bday_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_email_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
static void udx_vcard_email_home_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);

/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */

static udx_build_cntx_struct g_udx_build_cntx;
static udx_parse_cntx_struct g_udx_parse_cntx;
static kal_uint8 g_udx_utf8_buf[MAX_UDX_TAG_BUFFER];
static FS_HANDLE g_udx_fs_handle;
static const udx_data_hdlr_entry_struct g_udx_data_hdlr_func_tbl[] =
{
    {UDX_TAG_VENDOR_INFO, udx_vendor_info_data_hdlr},
    {UDX_TAG_DEVICE_INFO, udx_device_info_data_hdlr},
    {UDX_TAG_UDX_VERSION, udx_udx_version_data_hdlr},
	{UDX_TAG_USER_AGENT, udx_user_agent_data_hdlr},
    {UDX_TAG_USER_INFO, udx_user_info_data_hdlr},
    {UDX_TAG_ENCODING, udx_encoding_data_hdlr},
    {UDX_TAG_FILE_SIZE, udx_file_size_data_hdlr},
    {UDX_TAG_DATE, udx_date_data_hdlr},
    {UDX_TAG_LANGUAGE, udx_language_data_hdlr},
	{UDX_TAG_RECORD_OF_VCARD, NULL},   
    {UDX_TAG_VCARD_VERSION, udx_vcard_version_data_hdlr},
    {UDX_TAG_VCARD_RECORD, udx_vcard_record_data_hdlr},
    {UDX_TAG_VCARD_LENGTH, udx_vcard_length_data_hdlr},
    {UDX_TAG_RECORD_OF_VCALENDAR, NULL}, 
    {UDX_TAG_VCALENDAR_VERSION, udx_vcalendar_version_data_hdlr},
    {UDX_TAG_VCALENDAR_RECORD, udx_vcalendar_record_data_hdlr},
    {UDX_TAG_VCALENDAR_LENGTH, udx_vcalendar_length_data_hdlr},
	{UDX_TAG_RECORD_OF_SMS, NULL}, 
    {UDX_TAG_SMS_VERSION, udx_sms_version_data_hdlr},
    {UDX_TAG_SMS_RECORD, udx_sms_record_data_hdlr},
    {UDX_TAG_SMS_LENGTH, udx_sms_length_data_hdlr},
	{UDX_TAG_RECORD_OF_MMS, NULL}, 
    {UDX_TAG_MMS_VERSION, udx_mms_version_data_hdlr},
    {UDX_TAG_MMS_RECORD, udx_mms_record_data_hdlr},
    {UDX_TAG_MMS_LENGTH, udx_mms_length_data_hdlr},
	{UDX_TAG_RECORD_OF_EMAIL, NULL}, 
    {UDX_TAG_EMAIL_VERSION, udx_email_version_data_hdlr},
    {UDX_TAG_EMAIL_RECORD, udx_email_record_data_hdlr},
    {UDX_TAG_EMAIL_LENGTH, udx_email_length_data_hdlr}
};
static const udx_data_hdlr_entry_struct g_udx_vcard_data_hdlr_func_tbl[] =
{
    {UDX_TAG_VCARD_SEQUENCE, udx_vcard_sequence_data_hdlr},
    {UDX_TAG_VCARD_N, udx_vcard_n_data_hdlr},
    {UDX_TAG_VCARD_TEL, udx_vcard_tel_cell_data_hdlr},
    {UDX_TAG_VCARD_TEL_WORK, udx_vcard_tel_work_data_hdlr},
    {UDX_TAG_VCARD_TEL_VOICE_WORK, udx_vcard_tel_work_data_hdlr},
    {UDX_TAG_VCARD_TEL_HOME, udx_vcard_tel_home_data_hdlr},
    {UDX_TAG_VCARD_TEL_VOICE_HOME, udx_vcard_tel_home_data_hdlr},
    {UDX_TAG_VCARD_TEL_FAX, udx_vcard_tel_fax_data_hdlr},
    {UDX_TAG_VCARD_ADR_MAILBOX, udx_vcard_adr_mailbox_data_hdlr},
    {UDX_TAG_VCARD_ADR_DETAIL, udx_vcard_adr_detail_data_hdlr},
    {UDX_TAG_VCARD_ADR_STREET, udx_vcard_adr_street_data_hdlr},
    {UDX_TAG_VCARD_ADR_CITY, udx_vcard_adr_city_data_hdlr},
    {UDX_TAG_VCARD_ADR_PROVINCE, udx_vcard_adr_province_data_hdlr},
    {UDX_TAG_VCARD_ADR_POSTCODE, udx_vcard_adr_postcode_data_hdlr},
    {UDX_TAG_VCARD_ADR_COUNTRY, udx_vcard_adr_country_data_hdlr},
    {UDX_TAG_VCARD_URL, udx_vcard_url_data_hdlr},
    {UDX_TAG_VCARD_ORG_NAME, udx_vcard_org_name_data_hdlr},
    {UDX_TAG_VCARD_TITLE, udx_vcard_title_data_hdlr},
    {UDX_TAG_VCARD_BDAY, udx_vcard_bday_data_hdlr},
    {UDX_TAG_VCARD_EMAIL, udx_vcard_email_data_hdlr},
    {UDX_TAG_VCARD_EMAIL_HOME, udx_vcard_email_home_data_hdlr}
};

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* Write your global variable here */
/* 
 * Global variable shall be declared in the XxxxProt.h (not XXXGprot.h),
 * it shall be accessible by files within the same module.
 */

kal_uint8 g_udx_error_code = UDX_CODE_NO_ERROR;
kal_uint8 g_udx_state = UDX_STATE_IDLE;
kal_uint8 g_udx_step = UDX_STEP_IDLE;
kal_uint32 g_udx_valid_mask = 0;
kal_uint8 g_udx_lost_count = 0;
kal_uint8 g_udx_dyn_num_count = 0;
udx_header_info_struct *udx_header_info_p;
udx_vcard_data_struct *udx_vcard_data_p;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
/* Write your local function here */
/*
 * Local function can only be called within this .C file, it shall be declared as static.
 */


#define LOCAL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  udx_read_text
 * DESCRIPTION
 *  This function is used to read the text
 * PARAMETERS
 *  fh              [IN]        File handler
 *  buffer          [?]         Buffer to store data
 *  start_pos       [IN]        The start position to read
 *  data_len        [IN]        The length of data to read
 *  read_len        [?]         The real read len
 * RETURNS
 *  kal_int8
 *****************************************************************************/
static kal_int8 udx_read_text(
                    FS_HANDLE fh,
                    kal_char *buffer,
                    kal_int32 start_pos,
                    kal_uint32 data_len,
                    kal_uint32 *read_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_Seek(fh, start_pos, FS_FILE_BEGIN) < FS_NO_ERROR)
    {
        return UDX_XML_ERROR;
    }

    if (FS_Read(fh, buffer, data_len, read_len) < FS_NO_ERROR)
    {
        return UDX_XML_ERROR;
    }

    return UDX_XML_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  udx_search_tag
 * DESCRIPTION
 *  This function is used to search the tag
 * PARAMETERS
 *  fh              [IN]        File handler
 *  tag_name        [?]         Tag to search
 *  start_pos       [IN]        The start position to search
 *  tag_type        [IN]        Tag type: start or end tag
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_search_tag(
                    FS_HANDLE fh,
                    kal_char *tag_name,
                    kal_int32 start_pos,
                    kal_uint8 tag_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char buffer[UDX_XML_READ_BUF_SIZE], name[UDX_XML_TAG_LENGTH];
    kal_char *temp1, *temp2, *temp;
    kal_int32 find_pos, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    find_pos = start_pos;

    temp1 = NULL;
    while (udx_read_text(fh, buffer, find_pos, UDX_XML_READ_BUF_SIZE - 1, (kal_uint32*) &len) == UDX_XML_SUCCESS)
    {
        buffer[len] = '\0';
        if (len == 0)
        {
            break;
        }

        temp = buffer;
        while (*temp != '\0')
        {
            if (*temp == '<')
            {
                temp1 = temp;
            }
            temp++;
        }

        if (tag_type == START_TAG_TYPE)
        {
            sprintf(name, "%c%s%c", '<', tag_name, '>');

            temp2 = strstr(buffer, name);

            if (temp2 != NULL)
            {
                find_pos += temp2 - buffer;
                return find_pos;
            }
        }
        else
        {
            sprintf(name, "%s%s%c", "</", tag_name, '>');

            temp2 = strstr(buffer, name);

            if (temp2 != NULL)
            {
                find_pos += temp2 - buffer;
                return find_pos;
            }
        }

        if (temp1 != NULL)
        {
            find_pos += temp1 - buffer;
        }
        else
        {
            find_pos += len;
        }
        temp1 = NULL;
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  udx_update_element
 * DESCRIPTION
 *  This function is used to update the element
 * PARAMETERS
 *  fh          [IN]        File handler
 *  tag_name    [?]         Tag to update
 *  value       [?]         The new value of tag
 * RETURNS
 *  kal_int8
 *****************************************************************************/
static kal_int8 udx_update_element(FS_HANDLE fh, kal_char *tag_name, kal_char *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 update_pos, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fh < FS_NO_ERROR || tag_name == NULL)
    {
        return UDX_XML_ERROR;
    }

    update_pos = udx_search_tag(fh, tag_name, 0, START_TAG_TYPE);
    if (update_pos < 0)
    {
        return UDX_XML_ERROR;
    }

    update_pos += (strlen(tag_name) + 2);   /* 2 indicates '<>' */

    if (FS_Seek(fh, update_pos, FS_FILE_BEGIN) < FS_NO_ERROR)
    {
        return UDX_XML_ERROR;
    }

    if (FS_Write(fh, value, strlen(value), (kal_uint32*) &len) < FS_NO_ERROR)
    {
        return UDX_XML_ERROR;
    }

    return UDX_XML_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  udx_length_element_calc
 * DESCRIPTION
 *  This function is used to calculate the length of element
 * PARAMETERS
 *  fh          [IN]        File handle
 *  tag_name    [IN]        Tag to calculate
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_length_element_calc(FS_HANDLE fh, kal_char *tag_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 start_pos, end_pos, ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fh < FS_NO_ERROR)
    {
        return -1;
    }

    /* Calculate the whole file fize */
    if (tag_name == NULL)
    {
        ret = FS_Seek(fh, 0, FS_FILE_END);
        if (ret < FS_NO_ERROR)
        {
            return -1;
        }

        return ret;
    }

    start_pos = udx_search_tag(fh, tag_name, 0, START_TAG_TYPE);
    if (start_pos < 0)
    {
        return -1;
    }

    end_pos = udx_search_tag(fh, tag_name, start_pos + strlen(tag_name) + 1, END_TAG_TYPE);
    if (end_pos < 0)
    {
        return -1;
    }

    return (end_pos - start_pos + strlen(tag_name) + 3);    /* 3 indicates '</>' */
}


/*****************************************************************************
 * FUNCTION
 *  udx_set_xml_handler
 * DESCRIPTION
 *  This function is used to set xml handler
 * PARAMETERS
 *  h       [IN]        xml handler
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_set_xml_handler(XG_HANDLE h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_build_cntx.xml_hdlr = h;
}


/*****************************************************************************
 * FUNCTION
 *  udx_get_xml_handler
 * DESCRIPTION
 *  This function is used to get xml handler
 * PARAMETERS
 *  void
 * RETURNS
 *  XG_HANDLE
 *****************************************************************************/
static XG_HANDLE udx_get_xml_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_udx_build_cntx.xml_hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  udx_set_record_count
 * DESCRIPTION
 *  This function is used to set record count
 * PARAMETERS
 *  mask                [IN]        
 *  vcard_count         [IN]        
 *  vcalendar_count     [IN]        
 *  sms_count           [IN]        
 *  mms_count           [IN]        
 *  email_count         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_set_record_count(
                kal_uint8 mask,
                kal_uint16 vcard_count,
                kal_uint16 vcalendar_count,
                kal_uint16 sms_count,
                kal_uint16 mms_count,
                kal_uint16 email_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mask & UDX_TYPE_VCARD) == UDX_TYPE_VCARD)
    {
        g_udx_build_cntx.record_of_vcard = vcard_count;
    }
    else
    {
        g_udx_build_cntx.record_of_vcard = 0;
    }

    if ((mask & UDX_TYPE_VCALENDAR) == UDX_TYPE_VCALENDAR)
    {
        g_udx_build_cntx.record_of_vcalendar = vcalendar_count;
    }
    else
    {
        g_udx_build_cntx.record_of_vcalendar = 0;
    }

    if ((mask & UDX_TYPE_SMS) == UDX_TYPE_SMS)
    {
        g_udx_build_cntx.record_of_sms = sms_count;
    }
    else
    {
        g_udx_build_cntx.record_of_sms = 0;
    }

    if ((mask & UDX_TYPE_MMS) == UDX_TYPE_MMS)
    {
        g_udx_build_cntx.record_of_mms = mms_count;
    }
    else
    {
        g_udx_build_cntx.record_of_mms = 0;
    }

    if ((mask & UDX_TYPE_EMAIL) == UDX_TYPE_EMAIL)
    {
        g_udx_build_cntx.record_of_email = email_count;
    }
    else
    {
        g_udx_build_cntx.record_of_email = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  udx_get_vcard_count
 * DESCRIPTION
 *  This function is used to get vcard count
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint16
 *****************************************************************************/
static kal_uint16 udx_get_vcard_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_udx_build_cntx.record_of_vcard;
}


/*****************************************************************************
 * FUNCTION
 *  udx_get_vcalendar_count
 * DESCRIPTION
 *  This function is used to get vcalendar count
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint16
 *****************************************************************************/
static kal_uint16 udx_get_vcalendar_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_udx_build_cntx.record_of_vcalendar;
}


/*****************************************************************************
 * FUNCTION
 *  udx_get_sms_count
 * DESCRIPTION
 *  This function is used to get sms count
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint16
 *****************************************************************************/
static kal_uint16 udx_get_sms_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_udx_build_cntx.record_of_sms;
}


/*****************************************************************************
 * FUNCTION
 *  udx_get_mms_count
 * DESCRIPTION
 *  This function is used to get mms count
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint16
 *****************************************************************************/
static kal_uint16 udx_get_mms_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_udx_build_cntx.record_of_mms;
}


/*****************************************************************************
 * FUNCTION
 *  udx_get_email_count
 * DESCRIPTION
 *  This function is used to get email count
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint16
 *****************************************************************************/
static kal_uint16 udx_get_email_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_udx_build_cntx.record_of_email;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_start_tag
 * DESCRIPTION
 *  This function is used to build start tag
 * PARAMETERS
 *  h       [IN]        
 *  tag     [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_start_tag(XG_HANDLE h, kal_char *tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = xml_generate_stag(h, tag, NULL, 0);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_end_tag
 * DESCRIPTION
 *  This function is used to build end tag
 * PARAMETERS
 *  h       [IN]        
 *  tag     [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_end_tag(XG_HANDLE h, kal_char *tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = xml_generate_etag(h, tag);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_empty_element
 * DESCRIPTION
 *  This function is used to build empty element
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_empty_element(XG_HANDLE h, kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = xml_generate_stag(h, el, NULL, 0);
    if (result < 0)
    {
        return result;
    }
    result = xml_generate_etag(h, el);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_xml_element
 * DESCRIPTION
 *  This function is used to build xml element
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 *  data        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_xml_element(XG_HANDLE h, kal_char *el, kal_char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (xml_generate_stag(h, el, NULL, 0) < 0)
    {
        return -1;
    } */
    result = xml_generate_inline_element(h, el, data, strlen(data));
    if (result < 0)
    {
        return result;
    }
    /* if (xml_generate_data(h, data, strlen(data)) < 0)
    {
        return -1;
    }
    if (xml_generate_etag(h, el) < 0)
    {
        return -1;
    } */

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_alpha_element
 * DESCRIPTION
 *  This function is used to build alpha element
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 *  data        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_alpha_element(XG_HANDLE h, kal_char *el, kal_char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(data) > 0)
    {
        result = udx_build_xml_element(h, el, data);
        if (result < 0)
        {
            return result;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_n_element
 * DESCRIPTION
 *  This function is used to build <N> element
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 *  data        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_n_element(XG_HANDLE h, kal_char *el, kal_char *data, kal_char *data2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_char *temp_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_buffer = (kal_char*)OslMalloc(MAX_UDX_TAG_BUFFER);
    memset(temp_buffer, 0, MAX_UDX_TAG_BUFFER);

    memset(g_udx_utf8_buf, 0, MAX_UDX_TAG_BUFFER);
    
    /* last_name */
    if (app_ucs2_strlen((kal_int8*) data) > 0)
    {
        mmi_chset_convert(
            MMI_CHSET_UCS2,
            MMI_CHSET_UTF8,
            (char*) data,
            (char*) temp_buffer,
            MAX_UDX_TAG_BUFFER);
        
        udx_add_delimiter((kal_char*) temp_buffer, (kal_uint16) strlen((kal_char*) temp_buffer));
        
        strcpy((kal_char*)g_udx_utf8_buf, temp_buffer);
    }

    strcat((kal_char*)g_udx_utf8_buf, ";");

    /* name */
    if (app_ucs2_strlen((kal_int8*) data2) > 0)
    {
        mmi_chset_convert(
            MMI_CHSET_UCS2,
            MMI_CHSET_UTF8,
            (char*) data2,
            (char*) temp_buffer,
            MAX_UDX_TAG_BUFFER);
        
        udx_add_delimiter((kal_char*) temp_buffer, (kal_uint16) strlen((kal_char*) temp_buffer));

        strcat((kal_char*)g_udx_utf8_buf, temp_buffer);
    }

    if (temp_buffer != NULL)
    {
        OslMfree(temp_buffer);
    }
    
    result = udx_build_xml_element(h, el, (kal_char*) g_udx_utf8_buf);
    if (result < 0)
    {
        return result;
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_tel_element
 * DESCRIPTION
 *  This function is used to build <TEL> element
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 *  data        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_tel_element(XG_HANDLE h, kal_char *el, kal_char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(data) > 0)
    {
        result = udx_build_xml_element(h, el, data);
        if (result < 0)
        {
            return result;
        }
    }
    else
    {
        result = udx_build_empty_element(h, el);
        if (result < 0)
        {
            return result;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_bday_element
 * DESCRIPTION
 *  This function is used to build bday element
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 *  data        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_bday_element(XG_HANDLE h, kal_char *el, kal_char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(data) == 0 || strncmp(data, "00000000", 8) == 0)
    {
        return 0;
    }

    result = udx_build_xml_element(h, el, data);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_ucs2_element
 * DESCRIPTION
 *  This function is used to build ucs2 element, convert to utf8 first
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 *  data        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_ucs2_element(XG_HANDLE h, kal_char *el, kal_char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_ucs2_strlen((kal_int8*) data) > 0)
    {
        mmi_chset_convert(
            MMI_CHSET_UCS2,
            MMI_CHSET_UTF8,
            (char*) data,
            (char*) g_udx_utf8_buf,
            MAX_UDX_TAG_BUFFER);
        result = udx_build_xml_element(h, el, (kal_char*) g_udx_utf8_buf);
        if (result < 0)
        {
            return result;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_escape_element
 * DESCRIPTION
 *  This function is used to build escape element, add delimiter first
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 *  data        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_escape_element(XG_HANDLE h, kal_char *el, kal_char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_ucs2_strlen((kal_int8*) data) > 0)
    {
        mmi_chset_convert(
            MMI_CHSET_UCS2,
            MMI_CHSET_UTF8,
            (char*) data,
            (char*) g_udx_utf8_buf,
            MAX_UDX_TAG_BUFFER);
        udx_add_delimiter((kal_char*) g_udx_utf8_buf, (kal_uint16) strlen((kal_char*) g_udx_utf8_buf));
        result = udx_build_xml_element(h, el, (kal_char*) g_udx_utf8_buf);
        if (result < 0)
        {
            return result;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_numeric_element
 * DESCRIPTION
 *  This function is used to build numeric element
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 *  digit       [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_numeric_element(XG_HANDLE h, kal_char *el, kal_int32 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char data[12];
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (xml_generate_stag(h, el, NULL, 0) < 0)
    {
        return -1;
    } */
    sprintf(data, "%d", digit);
    result = udx_build_xml_element(h, el, data);
    if (result < 0)
    {
        return result;
    }
    /* if (xml_generate_data(h, data, strlen(data)) < 0)
    {
        return -1;
    }
    if (xml_generate_etag(h, el) < 0)
    {
        return -1;
    } */

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_date_element
 * DESCRIPTION
 *  This function is used to build date element
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 *  date        [IN]        
 *  separator   [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_date_element(XG_HANDLE h, kal_char *el, kal_uint8 date, kal_uint8 separator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;
    kal_char data[12];
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (xml_generate_stag(h, el, NULL, 0) < 0)
    {
        return -1;
    } */

    applib_dt_get_date_time(&time);

    switch (separator)
    {
        case 0:
            separator = '.';
            break;

        case 1:
            separator = ':';
            break;

        case 2:
            separator = '/';
            break;

        case 3:
            separator = '-';
            break;

        default:
            separator = '.';
            break;
    }

    switch (date)
    {
        case 0: /* day, month, year */
            sprintf(data, "%02d%c%02d%c%04d", time.nDay, separator, time.nMonth, separator, time.nYear);
            break;

        case 1: /* month, day, year */
            sprintf(data, "%02d%c%02d%c%04d", time.nMonth, separator, time.nDay, separator, time.nYear);
            break;

        case 2: /* year, month, day */
        default:
            sprintf(data, "%04d%c%02d%c%02d", time.nYear, separator, time.nMonth, separator, time.nDay);
            break;
    }

    result = udx_build_xml_element(h, el, data);
    if (result < 0)
    {
        return result;
    }

    /* if (xml_generate_data(h, data, strlen(data)) < 0)
    {
        return -1;
    }
    if (xml_generate_etag(h, el) < 0)
    {
        return -1;
    } */

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_recalc_element
 * DESCRIPTION
 *  This function is used to build recalc element who needs to be recalculated size
 * PARAMETERS
 *  h           [IN]        
 *  el          [?]         
 *  digit       [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_recalc_element(XG_HANDLE h, kal_char *el, kal_int32 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char data[12];
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (xml_generate_stag(h, el, NULL, 0) < 0)
    {
        return -1;
    } */
    sprintf(data, "%-10d", digit);
    result = udx_build_xml_element(h, el, data);
    if (result < 0)
    {
        return result;
    }
    /* if (xml_generate_data(h, data, strlen(data)) < 0)
    {
        return -1;
    }
    if (xml_generate_etag(h, el) < 0)
    {
        return -1;
    } */

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_record_info
 * DESCRIPTION
 *  This function is used to build record info
 * PARAMETERS
 *  h           [IN]        
 *  name        [?]         
 *  date        [IN]        
 *  separator   [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_record_info(XG_HANDLE h, kal_uint8 *name, kal_uint8 date, kal_uint8 separator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = udx_build_start_tag(h, UDX_TAG_RECORD_INFO);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_terminal_info(h);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_user_info(h, name);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_integrity_check_info(h, date, separator);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_data_stat_info(h);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_end_tag(h, UDX_TAG_RECORD_INFO);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_terminal_info
 * DESCRIPTION
 *  This function is used to build terminal info
 * PARAMETERS
 *  h       [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_terminal_info(XG_HANDLE h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = udx_build_ucs2_element(h, UDX_TAG_VENDOR_INFO, (kal_char*) UDX_DEFAULT_VENDOR_INFO);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_ucs2_element(h, UDX_TAG_DEVICE_INFO, (kal_char*) UDX_DEFAULT_DEVICE_INFO);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_ucs2_element(h, UDX_TAG_UDX_VERSION, (kal_char*) UDX_DEFAULT_UDX_VERSION);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_ucs2_element(h, UDX_TAG_USER_AGENT, (kal_char*) UDX_DEFAULT_USER_AGENT);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_user_info
 * DESCRIPTION
 *  This function is used to build user info
 * PARAMETERS
 *  h           [IN]        
 *  name        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_user_info(XG_HANDLE h, kal_uint8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_ucs2_strlen((kal_int8*) name) == 0)
    {
        result = udx_build_ucs2_element(h, UDX_TAG_USER_INFO, (kal_char*) UDX_DEFAULT_USER_INFO);
        if (result < 0)
        {
            return result;
        }
    }
    else
    {
        result = udx_build_ucs2_element(h, UDX_TAG_USER_INFO, (kal_char*) name);
        if (result < 0)
        {
            return result;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_integrity_check_info
 * DESCRIPTION
 *  This function is used to build integrity check info
 * PARAMETERS
 *  h           [IN]        
 *  date        [IN]        
 *  separator   [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_integrity_check_info(XG_HANDLE h, kal_uint8 date, kal_uint8 separator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = udx_build_ucs2_element(h, UDX_TAG_ENCODING, (kal_char*) UDX_DEFAULT_ENCODING);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_recalc_element(h, UDX_TAG_FILE_SIZE, 0);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_date_element(h, UDX_TAG_DATE, date, separator);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_ucs2_element(h, UDX_TAG_LANGUAGE, (kal_char*) UDX_DEFAULT_LANGUAGE);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_data_stat_info
 * DESCRIPTION
 *  This function is used to build data stat info
 * PARAMETERS
 *  h       [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_data_stat_info(XG_HANDLE h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = udx_build_start_tag(h, UDX_TAG_RECORD_OF_VCARD);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_ucs2_element(h, UDX_TAG_VCARD_VERSION, (kal_char*) UDX_DEFAULT_VCARD_VERSION);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_numeric_element(h, UDX_TAG_VCARD_RECORD, udx_get_vcard_count());
    if (result < 0)
    {
        return result;
    }
    result = udx_build_recalc_element(h, UDX_TAG_VCARD_LENGTH, 0);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_end_tag(h, UDX_TAG_RECORD_OF_VCARD);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_empty_element(h, UDX_TAG_RECORD_OF_VCALENDAR);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_empty_element(h, UDX_TAG_RECORD_OF_SMS);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_empty_element(h, UDX_TAG_RECORD_OF_MMS);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_empty_element(h, UDX_TAG_RECORD_OF_EMAIL);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_vcard_info
 * DESCRIPTION
 *  This function is used to build vcard info
 * PARAMETERS
 *  h           [IN]        
 *  seq         [IN]        
 *  v_data      [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_vcard_info(XG_HANDLE h, kal_uint16 seq, udx_vcard_data_struct *v_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = udx_build_start_tag(h, UDX_TAG_VCARD_INFO);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_numeric_element(h, UDX_TAG_VCARD_SEQUENCE, seq);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_vcard_field(h, v_data);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_end_tag(h, UDX_TAG_VCARD_INFO);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_vcard_field
 * DESCRIPTION
 *  This function is used to build vcard field
 * PARAMETERS
 *  h           [IN]        
 *  v_data      [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_vcard_field(XG_HANDLE h, udx_vcard_data_struct *v_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = udx_build_start_tag(h, UDX_TAG_VCARD_FIELD);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_name_field(h, v_data);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_number_field(h, v_data);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_address_field(h, v_data);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_other_field(h, v_data);
    if (result < 0)
    {
        return result;
    }

    result = udx_build_end_tag(h, UDX_TAG_VCARD_FIELD);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_name_field
 * DESCRIPTION
 *  This function is used to build name field
 * PARAMETERS
 *  h           [IN]        
 *  v_data      [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_name_field(XG_HANDLE h, udx_vcard_data_struct *v_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = udx_build_n_element(h, UDX_TAG_VCARD_N, (kal_char*)v_data->l_n, (kal_char*)v_data->n);
    if (result < 0)
    {
        return result;
    }
    /* if (udx_build_tel_element(h, UDX_TAG_VCARD_TEL, (kal_char*) v_data->tel_cell) < 0)
    {
        return -1;
    } */

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_number_field
 * DESCRIPTION
 *  This function is used to build number field
 * PARAMETERS
 *  h           [IN]        
 *  v_data      [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_number_field(XG_HANDLE h, udx_vcard_data_struct *v_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_int8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* tel_cell is mandatory field, others are optional */
    result = udx_build_tel_element(h, UDX_TAG_VCARD_TEL, (kal_char*) v_data->tel_cell);
    if (result < 0)
    {
        return result;
    }

    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        switch(v_data->dyn_num[i].type)
        {
            case MMI_PHB_NUM_TYPE_MOBILE:
				result = udx_build_alpha_element(h, UDX_TAG_VCARD_TEL, (kal_char*) v_data->dyn_num[i].number);
                if (result < 0)
                {
                    return result;
                }
                break;
                
            case MMI_PHB_NUM_TYPE_HOME:
                result = udx_build_alpha_element(h, UDX_TAG_VCARD_TEL_HOME, (kal_char*) v_data->dyn_num[i].number);
                if (result < 0)
                {
                    return result;
                }
                break;
            case MMI_PHB_NUM_TYPE_OFFICE:
                result = udx_build_alpha_element(h, UDX_TAG_VCARD_TEL_WORK, (kal_char*) v_data->dyn_num[i].number);
                if (result < 0)
                {
                    return result;
                }
                break;
            case MMI_PHB_NUM_TYPE_FAX:
                result = udx_build_alpha_element(h, UDX_TAG_VCARD_TEL_FAX, (kal_char*) v_data->dyn_num[i].number);
                if (result < 0)
                {
                    return result;
                }
                break;
            default:
                break;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_address_field
 * DESCRIPTION
 *  This function is used to build address field
 * PARAMETERS
 *  h           [IN]        
 *  v_data      [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_address_field(XG_HANDLE h, udx_vcard_data_struct *v_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = udx_build_escape_element(h, UDX_TAG_VCARD_ADR_MAILBOX, (kal_char*) v_data->adr_mailbox);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_escape_element(h, UDX_TAG_VCARD_ADR_DETAIL, (kal_char*) v_data->adr_detail);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_escape_element(h, UDX_TAG_VCARD_ADR_STREET, (kal_char*) v_data->adr_street);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_escape_element(h, UDX_TAG_VCARD_ADR_CITY, (kal_char*) v_data->adr_city);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_escape_element(h, UDX_TAG_VCARD_ADR_PROVINCE, (kal_char*) v_data->adr_province);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_escape_element(h, UDX_TAG_VCARD_ADR_POSTCODE, (kal_char*) v_data->adr_postcode);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_escape_element(h, UDX_TAG_VCARD_ADR_COUNTRY, (kal_char*) v_data->adr_country);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_other_field
 * DESCRIPTION
 *  This function is used to build other field
 * PARAMETERS
 *  h           [IN]        
 *  v_data      [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_build_other_field(XG_HANDLE h, udx_vcard_data_struct *v_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = udx_build_alpha_element(h, UDX_TAG_VCARD_URL, (kal_char*) v_data->url);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_escape_element(h, UDX_TAG_VCARD_ORG_NAME, (kal_char*) v_data->org_name);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_escape_element(h, UDX_TAG_VCARD_TITLE, (kal_char*) v_data->title);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_bday_element(h, UDX_TAG_VCARD_BDAY, (kal_char*) v_data->bday);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_alpha_element(h, UDX_TAG_VCARD_EMAIL, (kal_char*) v_data->email);
    if (result < 0)
    {
        return result;
    }
    result = udx_build_alpha_element(h, UDX_TAG_VCARD_EMAIL_HOME, (kal_char*) v_data->email_home);
    if (result < 0)
    {
        return result;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_save_xml_parser
 * DESCRIPTION
 *  This function is used to save xml parser
 * PARAMETERS
 *  par     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_save_xml_parser(XML_PARSER_STRUCT *par)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_parse_cntx.xml_parser = par;
}


/*****************************************************************************
 * FUNCTION
 *  udx_load_xml_parser
 * DESCRIPTION
 *  This function is used to load xml parser
 * PARAMETERS
 *  void
 * RETURNS
 *  XML_PARSER_STRUCT *
 *****************************************************************************/
static XML_PARSER_STRUCT *udx_load_xml_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_udx_parse_cntx.xml_parser;
}


/*****************************************************************************
 * FUNCTION
 *  udx_register_parser_mode
 * DESCRIPTION
 *  This function is used to set parser mode
 * PARAMETERS
 *  h_only      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_register_parser_mode(kal_bool h_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_parse_cntx.header_only = h_only;
}


/*****************************************************************************
 * FUNCTION
 *  udx_is_header_only
 * DESCRIPTION
 *  This function is used to get parser mode
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool udx_is_header_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_udx_parse_cntx.header_only;
}


/*****************************************************************************
 * FUNCTION
 *  udx_set_type_mask
 * DESCRIPTION
 *  This function is used to set type mask
 * PARAMETERS
 *  mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_set_type_mask(kal_uint8 mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_parse_cntx.type_mask = mask;
}


/*****************************************************************************
 * FUNCTION
 *  udx_check_mandatory_field
 * DESCRIPTION
 *  Check mandatory field
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool udx_check_mandatory_field_is_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for check mandatory field, if nothing, parse will fail */
    if ((g_udx_valid_mask == 0) ||
        !UDX_IS_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VENDOR_INFO)  ||
        !UDX_IS_SET_MASK(g_udx_valid_mask,UDX_TAG_ID_DEVICE_INFO)   ||
        !UDX_IS_SET_MASK(g_udx_valid_mask,UDX_TAG_ID_UDX_VERSION)   ||
        !UDX_IS_SET_MASK(g_udx_valid_mask,UDX_TAG_ID_USER_AGENT)   ||
        !UDX_IS_SET_MASK(g_udx_valid_mask,UDX_TAG_ID_VCARD_RECORD_INFO)   ||
        !UDX_IS_SET_MASK(g_udx_valid_mask,UDX_TAG_ID_VCALENDAR_RECORD_INFO)   ||
        !UDX_IS_SET_MASK(g_udx_valid_mask,UDX_TAG_ID_SMS_RECORD_INFO)   ||
        !UDX_IS_SET_MASK(g_udx_valid_mask,UDX_TAG_ID_MMS_RECORD_INFO)   ||
        !UDX_IS_SET_MASK(g_udx_valid_mask,UDX_TAG_ID_EMAIL_RECORD_INFO)   
        )
    {   
        return KAL_FALSE;
    }
    
    return KAL_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  udx_atoi
 * DESCRIPTION
 *  This function is used to convert data to integer
 * PARAMETERS
 *  data        [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 udx_atoi(const kal_char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 c;        /* current char */
    kal_int32 total;    /* current total */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* skip whitespace */
    while (isspace((int)(unsigned char)*data))
    {
        ++data;
    }

    c = (int)(unsigned char)*data++;
    if (c == '-')
    {
        return 0;
    }
    else if (c == '+')
    {
        c = (int)(unsigned char)*data++;    /* skip sign */
    }

    total = 0;

    while (isdigit(c))
    {
        total = 10 * total + (c - '0');     /* accumulate digit */
        if (total > 65535)
        {
            return 0;
        }
        c = (int)(unsigned char)*data++;    /* get next char */
    }

    return total;
}


/*****************************************************************************
 * FUNCTION
 *  udx_convert_utf8_to_ucs2
 * DESCRIPTION
 *  This function is used to convert utf8 to ucs2
 * PARAMETERS
 *  src_buff    [IN]        
 *  dest_buff   [?]         
 *  src_size    [IN]        
 *  dest_size   [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_convert_utf8_to_ucs2(
                const kal_char *src_buff,
                kal_uint8 *dest_buff,
                kal_int32 src_size,
                kal_int32 dest_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    kal_char *buffer;
    kal_uint32 data_len, read_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_size == 0)
    {
        fh = FS_Open((kal_uint16*) src_buff, FS_READ_ONLY);
        if (fh < FS_NO_ERROR)
        {
            return;
        }

        data_len = (kal_uint32) dest_size;
        buffer = (kal_char*) OslMalloc(data_len);
        if (FS_Read(fh, buffer, data_len, &read_len) < FS_NO_ERROR)
        {
            FS_Close(fh);
            OslMfree(buffer);
            return;
        }

        mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*) buffer, (char*) dest_buff, dest_size);

        FS_Close(fh);
        OslMfree(buffer);
    }
    else
    {
        mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*) src_buff, (char*) dest_buff, dest_size);
    }
}


/*****************************************************************************
 * FUNCTION
 *  udx_convert_escape_to_ucs2
 * DESCRIPTION
 *  This function is used to convert utf8 to ucs2, remove delimiter first
 * PARAMETERS
 *  src_buff    [IN]        
 *  dest_buff   [?]         
 *  src_size    [IN]        
 *  dest_size   [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_convert_escape_to_ucs2(
                const kal_char *src_buff,
                kal_uint8 *dest_buff,
                kal_int32 src_size,
                kal_int32 dest_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_remove_delimiter((kal_char*) src_buff, MAX_UDX_TAG_BUFFER);
    udx_convert_utf8_to_ucs2(src_buff, dest_buff, src_size, dest_size);
    //mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*) src_buff, (char*) dest_buff, dest_size);
}


/*****************************************************************************
 * FUNCTION
 *  udx_convert_parse_error
 * DESCRIPTION
 *  This function is used to convert xml error code
 * PARAMETERS
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_convert_parse_error(kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error)
    {
        case XML_ERROR_MISMATCH_TAG:
        case XML_ERROR_MISMATCH_DOCTYPENAME_ROOTNAME:
            g_udx_error_code = UDX_CODE_MISMATCH_ERROR;
            break;

        case XML_ERROR_INVALID_ATTRIBUTE:
        case XML_ERROR_DUPLICATE_ATTRIBUTE:
            g_udx_error_code = UDX_CODE_ATTRIBUTE_ERROR;
            break;

        case XML_ERROR_ENTITY_DEFINITION:
        case XML_ERROR_UNDEFINED_ENTITY:
            g_udx_error_code = UDX_CODE_ENTITY_ERROR;
            break;

        default:
            g_udx_error_code = UDX_CODE_XML_FAIL_ERROR;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  udx_convert_gen_error
 * DESCRIPTION
 *  This function is used to convert xml error code
 * PARAMETERS
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_convert_gen_error(kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error)
    {
        case XG_E_FILE_NOT_FOUND:
            g_udx_error_code = UDX_CODE_FILE_NOT_FOUND_ERROR;
            break;

        case XG_E_LACK_DISK:
            g_udx_error_code = UDX_CODE_DISK_FULL_ERROR;
            break;

        default:
            g_udx_error_code = UDX_CODE_XML_FAIL_ERROR;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  udx_add_delimiter
 * DESCRIPTION
 *  This function is used to add ';' & '\\' delimiter
 * PARAMETERS
 *  str_out     [?]         
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_add_delimiter(kal_char *str_out, kal_uint16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i, j, delimiter;
    kal_char *temp_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    delimiter = 0;
    while (i < length)
    {
        if (str_out[i] == ';' || str_out[i] == '\\')
        {
            delimiter++;
        }
        i++;
    }

    if (delimiter > 0)
    {
        /* Add ';' & '\\' delimiter */
        temp_buff = OslMalloc(length + delimiter + 1);

        i = 0;
        j = 0;
        while (i < length)
        {
            if (str_out[i] == ';' || str_out[i] == '\\')
            {
                temp_buff[j] = '\\';
                j++;
            }
            temp_buff[j] = str_out[i];
            i++;
            j++;
        }
        temp_buff[j] = '\0';

        memcpy(str_out, temp_buff, strlen(temp_buff));
        str_out[j] = '\0';

        OslMfree(temp_buff);
    }
}


/*****************************************************************************
 * FUNCTION
 *  udx_remove_delimiter
 * DESCRIPTION
 *  This function is used to remove ';' & '\\' delimiter
 * PARAMETERS
 *  str_out     [?]         
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_remove_delimiter(kal_char *str_out, kal_uint16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (i < length)
    {
        if (str_out[i] == '\0')
        {
            return;
        }

        /* Remove ';' & '\\' delimiter */
        if (str_out[i] == '\\' && (str_out[i + 1] == ';' || str_out[i + 1] == '\\'))
        {
            for (j = i; j < length && str_out[j] != '\0'; j++)
            {
                /* Shift forward */
                str_out[j] = str_out[j + 1];
            }
            str_out[j] = '\0';
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  udx_start_element_hdlr
 * DESCRIPTION
 *  This function is used to register start element hdlr
 * PARAMETERS
 *  data        [?]         
 *  el          [IN]        
 *  attr        [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_start_element_hdlr(void *data, const kal_char *el, const kal_char **attr, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *parser;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parser = udx_load_xml_parser();

    if (el == NULL || error != XML_NO_ERROR)
    {
        xml_stop_parse(parser);
        udx_convert_parse_error(error);
        return;
    }

    switch (g_udx_step)
    {
        case UDX_STEP_IDLE:
            if (strcmp(el, UDX_TAG_DATA_EXCHANGE_INFO) == 0)
            {
                g_udx_step = UDX_STEP_DATA_EXCHANGE_INFO;
                return;
            }
            break;

        case UDX_STEP_DATA_EXCHANGE_INFO:
            if (strcmp(el, UDX_TAG_RECORD_INFO) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_INFO;
                return;
            }

            if (!udx_is_header_only() && strcmp(el, UDX_TAG_VCARD) == 0)
            {
                g_udx_parse_cntx.vcard_sequence = 0;
                g_udx_step = UDX_STEP_VCARD;
                return;
            }

            if ((!udx_is_header_only()) &&
                (strcmp(el, UDX_TAG_VCALENDAR) == 0 ||
                 strcmp(el, UDX_TAG_SMS) == 0 ||
                 strcmp(el, UDX_TAG_MMS) == 0 ||
                 strcmp(el, UDX_TAG_EMAIL) == 0))
            {
                /* This is begin of vcalendar data */
                /* This is begin of sms data */
                /* This is begin of mms data */
                /* This is begin of email data */
                /* Not supported now, so we regard it as the end. */
                udx_parse_finish_ind(KAL_FALSE);

                /* Close XML parser, and free its memory. */
                xml_close_parser(parser);
                udx_parse_close();
                return;
            }
            break;

        case UDX_STEP_RECORD_INFO:
            if (strcmp(el, UDX_TAG_RECORD_OF_VCARD) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_OF_VCARD;
                UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_RECORD_INFO);
                return;
            }

            if (strcmp(el, UDX_TAG_RECORD_OF_VCALENDAR) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_OF_VCALENDAR;
                UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCALENDAR_RECORD_INFO);
                return;
            }

            if (strcmp(el, UDX_TAG_RECORD_OF_SMS) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_OF_SMS;
                UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_SMS_RECORD_INFO);
                return;
            }

            if (strcmp(el, UDX_TAG_RECORD_OF_MMS) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_OF_MMS;
                UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_MMS_RECORD_INFO);
                return;
            }

            if (strcmp(el, UDX_TAG_RECORD_OF_EMAIL) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_OF_EMAIL;
                UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_EMAIL_RECORD_INFO);
                return;
            }

            for (i = UDX_TAG_ID_VENDOR_INFO; i <= UDX_TAG_ID_LANGUAGE; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    return;
                }
            }
            break;

        case UDX_STEP_VCARD:
            if (strcmp(el, UDX_TAG_VCARD_INFO) == 0)
            {
                g_udx_step = UDX_STEP_VCARD_INFO;
                return;
            }
            break;

        case UDX_STEP_VCALENDAR:
            ASSERT(0);
            break;

        case UDX_STEP_SMS:
            ASSERT(0);
            break;

        case UDX_STEP_MMS:
            ASSERT(0);
            break;

        case UDX_STEP_EMAIL:
            ASSERT(0);
            break;

        case UDX_STEP_RECORD_OF_VCARD:
            for (i = UDX_TAG_ID_VCARD_VERSION; i <= UDX_TAG_ID_VCARD_LENGTH; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    return;
                }
            }
            break;

        case UDX_STEP_RECORD_OF_VCALENDAR:
            for (i = UDX_TAG_ID_VCALENDAR_VERSION; i <= UDX_TAG_ID_VCALENDAR_LENGTH; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    return;
                }
            }
            break;

        case UDX_STEP_RECORD_OF_SMS:
            for (i = UDX_TAG_ID_SMS_VERSION; i <= UDX_TAG_ID_SMS_LENGTH; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    return;
                }
            }
            break;

        case UDX_STEP_RECORD_OF_MMS:
            for (i = UDX_TAG_ID_MMS_VERSION; i <= UDX_TAG_ID_MMS_LENGTH; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    return;
                }
            }
            break;

        case UDX_STEP_RECORD_OF_EMAIL:
            for (i = UDX_TAG_ID_EMAIL_VERSION; i <= UDX_TAG_ID_EMAIL_LENGTH; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    return;
                }
            }
            break;

        case UDX_STEP_VCARD_INFO:
            if (strcmp(el, UDX_TAG_VCARD_FIELD) == 0)
            {
                g_udx_step = UDX_STEP_VCARD_FIELD;
                return;
            }

            if (strcmp(el, g_udx_vcard_data_hdlr_func_tbl[UDX_TAG_ID_VCARD_SEQUENCE].tag) == 0)
            {
                return;
            }
            break;

        case UDX_STEP_VCARD_FIELD:
            if (g_udx_lost_count == 0xFF)
            {
                /* We just care at most 0xFF unknown fields */
                return;
            }

            for (i = UDX_TAG_ID_VCARD_N; i <= UDX_TAG_ID_VCARD_EMAIL_HOME; i++)
            {
                if (strcmp(el, g_udx_vcard_data_hdlr_func_tbl[i].tag) == 0)
                {
                    return;
                }
            }
            g_udx_lost_count++;
            return;

        default:
            ASSERT(0);
    }

    xml_stop_parse(parser);
    g_udx_error_code = UDX_CODE_STAG_ERROR;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  udx_end_element_hdlr
 * DESCRIPTION
 *  This function is used to register end element hdlr
 * PARAMETERS
 *  data        [?]         
 *  el          [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_end_element_hdlr(void *data, const kal_char *el, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *parser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parser = udx_load_xml_parser();

    if (el == NULL || error != XML_NO_ERROR)
    {
        xml_stop_parse(parser);
        udx_convert_parse_error(error);
        return;
    }

    switch (g_udx_step)
    {
        case UDX_STEP_IDLE:
            break;

        case UDX_STEP_DATA_EXCHANGE_INFO:
            if (strcmp(el, UDX_TAG_DATA_EXCHANGE_INFO) == 0)
            {
                /* This is end of entire udx file */
                udx_parse_finish_ind(KAL_FALSE);

                /* Close XML parser, and free its memory. */
                xml_close_parser(parser);
                udx_parse_close();

                g_udx_step = UDX_STEP_IDLE;
                return;
            }
            return;

        case UDX_STEP_RECORD_INFO:
            if (strcmp(el, UDX_TAG_RECORD_INFO) == 0)
            {
                /* Pause XML parser, and notify header info to MMI. */
                xml_pause_parse(parser);

                g_udx_step = UDX_STEP_DATA_EXCHANGE_INFO;
                return;
            }
            return;

        case UDX_STEP_VCARD:
            if (strcmp(el, UDX_TAG_VCARD) == 0)
            {
                g_udx_step = UDX_STEP_DATA_EXCHANGE_INFO;
                return;
            }
            return;

        case UDX_STEP_VCALENDAR:
            ASSERT(0);
            break;

        case UDX_STEP_SMS:
            ASSERT(0);
            break;

        case UDX_STEP_MMS:
            ASSERT(0);
            break;

        case UDX_STEP_EMAIL:
            ASSERT(0);
            break;

        case UDX_STEP_RECORD_OF_VCARD:
            if (strcmp(el, UDX_TAG_RECORD_OF_VCARD) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_INFO;
                return;
            }
            return;

        case UDX_STEP_RECORD_OF_VCALENDAR:
            if (strcmp(el, UDX_TAG_RECORD_OF_VCALENDAR) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_INFO;
                return;
            }
            return;

        case UDX_STEP_RECORD_OF_SMS:
            if (strcmp(el, UDX_TAG_RECORD_OF_SMS) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_INFO;
                return;
            }
            return;

        case UDX_STEP_RECORD_OF_MMS:
            if (strcmp(el, UDX_TAG_RECORD_OF_MMS) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_INFO;
                return;
            }
            return;

        case UDX_STEP_RECORD_OF_EMAIL:
            if (strcmp(el, UDX_TAG_RECORD_OF_EMAIL) == 0)
            {
                g_udx_step = UDX_STEP_RECORD_INFO;
                return;
            }
            return;

        case UDX_STEP_VCARD_INFO:
            if (strcmp(el, UDX_TAG_VCARD) == 0)
            {
                g_udx_step = UDX_STEP_DATA_EXCHANGE_INFO;
                return;
            }
            return;

        case UDX_STEP_VCARD_FIELD:
            if (strcmp(el, UDX_TAG_VCARD_INFO) == 0)
            {
                if (g_udx_parse_cntx.vcard_sequence > g_udx_parse_cntx.record_of_vcard)
                {
                    /* Not supported now, so we regard it as the end. */
                    udx_parse_finish_ind(KAL_FALSE);

                    /* Close XML parser, and free its memory. */
                    xml_close_parser(parser);
                    udx_parse_close();
                    return;
                }

                /* <N>, <TEL> should be mandatory fields, if it is absent, just treat it as invalid data. */
                //if (!UDX_IS_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_N) ||
                //    !UDX_IS_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_TEL_CELL))
                //{
                //    g_udx_valid_mask = 0;
                //    memset(udx_vcard_data_p, 0, sizeof(udx_vcard_data_struct));
                //}

                /* PS should notify vcard data (including invalid data) to MMI */
                if (1)
                {
                    /* Pause XML parser, and notify vcard data to MMI. */
                    xml_pause_parse(parser);
                    udx_parse_data_rsp(UDX_TYPE_VCARD, g_udx_parse_cntx.vcard_sequence);
                }

                g_udx_step = UDX_STEP_VCARD;
                return;
            }
            return;

        default:
            ASSERT(0);
    }

    xml_stop_parse(parser);
    g_udx_error_code = UDX_CODE_ETAG_ERROR;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  udx_data_hdlr
 * DESCRIPTION
 *  This function is used to register data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *parser;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parser = udx_load_xml_parser();

    if (el == NULL || error != XML_NO_ERROR || data == NULL || len < 0)
    {
        xml_stop_parse(parser);
        udx_convert_parse_error(error);
        return;
    }

    switch (g_udx_step)
    {
        case UDX_STEP_IDLE:
            break;

        case UDX_STEP_DATA_EXCHANGE_INFO:
            break;

        case UDX_STEP_RECORD_INFO:
            for (i = UDX_TAG_ID_VENDOR_INFO; i <= UDX_TAG_ID_LANGUAGE; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    /* For parse body, it is not neccessary to parse header again */
                    if (!udx_is_header_only())
                    {
                        return;
                    }
                    
                    /* For some fields are repetitive, If the field once is parsed, recover it with the last one */

                    g_udx_data_hdlr_func_tbl[i].data_hdlr(resv, el, data, len, error);
                    return;
                }
            }
            break;

        case UDX_STEP_VCARD:
            break;

        case UDX_STEP_VCALENDAR:
            ASSERT(0);
            break;

        case UDX_STEP_SMS:
            ASSERT(0);
            break;

        case UDX_STEP_MMS:
            ASSERT(0);
            break;

        case UDX_STEP_EMAIL:
            ASSERT(0);
            break;

        case UDX_STEP_RECORD_OF_VCARD:
            for (i = UDX_TAG_ID_VCARD_VERSION; i <= UDX_TAG_ID_VCARD_LENGTH; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    if (!udx_is_header_only())
                    {
                        return;
                    }

                    g_udx_data_hdlr_func_tbl[i].data_hdlr(resv, el, data, len, error);
                    return;
                }
            }
            break;

        case UDX_STEP_RECORD_OF_VCALENDAR:
            for (i = UDX_TAG_ID_VCALENDAR_VERSION; i <= UDX_TAG_ID_VCALENDAR_LENGTH; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    if (!udx_is_header_only())
                    {
                        return;
                    }

                    g_udx_data_hdlr_func_tbl[i].data_hdlr(resv, el, data, len, error);
                    return;
                }
            }
            break;

        case UDX_STEP_RECORD_OF_SMS:
            for (i = UDX_TAG_ID_SMS_VERSION; i <= UDX_TAG_ID_SMS_LENGTH; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    if (!udx_is_header_only())
                    {
                        return;
                    }

                    g_udx_data_hdlr_func_tbl[i].data_hdlr(resv, el, data, len, error);
                    return;
                }
            }
            break;

        case UDX_STEP_RECORD_OF_MMS:
            for (i = UDX_TAG_ID_MMS_VERSION; i <= UDX_TAG_ID_MMS_LENGTH; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    if (!udx_is_header_only())
                    {
                        return;
                    }
                    g_udx_data_hdlr_func_tbl[i].data_hdlr(resv, el, data, len, error);
                    return;
                }
            }
            break;

        case UDX_STEP_RECORD_OF_EMAIL:
            for (i = UDX_TAG_ID_EMAIL_VERSION; i <= UDX_TAG_ID_EMAIL_LENGTH; i++)
            {
                if (strcmp(el, g_udx_data_hdlr_func_tbl[i].tag) == 0)
                {
                    if (!udx_is_header_only())
                    {
                        return;
                    }
                    g_udx_data_hdlr_func_tbl[i].data_hdlr(resv, el, data, len, error);
                    return;
                }
            }
            break;

        case UDX_STEP_VCARD_INFO:
            if (strcmp(el, g_udx_vcard_data_hdlr_func_tbl[UDX_TAG_ID_VCARD_SEQUENCE].tag) == 0)
            {
                g_udx_vcard_data_hdlr_func_tbl[UDX_TAG_ID_VCARD_SEQUENCE].data_hdlr(resv, el, data, len, error);
                return;
            }
            break;

        case UDX_STEP_VCARD_FIELD:
            for (i = UDX_TAG_ID_VCARD_N; i <= UDX_TAG_ID_VCARD_EMAIL_HOME; i++)
            {
                if (strcmp(el, g_udx_vcard_data_hdlr_func_tbl[i].tag) == 0)
                {
                    g_udx_vcard_data_hdlr_func_tbl[i].data_hdlr(resv, el, data, len, error);
                    return;
                }
            }
            /* Unknown tag, should be ignored. */
            return;

        default:
            ASSERT(0);
    }

    //xml_stop_parse(parser);
    //g_udx_error_code = UDX_CODE_DATA_ERROR;
    //return;
}


/*****************************************************************************
 * FUNCTION
 *  udx_vendor_info_data_hdlr
 * DESCRIPTION
 *  This function is used to register vendor info data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vendor_info_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->vendor_info,
        len,
        (MAX_UDX_VENDOR_INFO_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VENDOR_INFO);
}


/*****************************************************************************
 * FUNCTION
 *  udx_device_info_data_hdlr
 * DESCRIPTION
 *  This function is used to register device info data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_device_info_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->device_info,
        len,
        (MAX_UDX_DEVICE_INFO_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_DEVICE_INFO);
}


/*****************************************************************************
 * FUNCTION
 *  udx_udx_version_data_hdlr
 * DESCRIPTION
 *  This function is used to register udx version data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_udx_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->udx_version,
        len,
        (MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_UDX_VERSION);
}


/*****************************************************************************
 * FUNCTION
 *  udx_user_agent_data_hdlr
 * DESCRIPTION
 *  This function is used to register user agent data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_user_agent_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->user_agent,
        len,
        (MAX_UDX_USER_AGENT_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_USER_AGENT);
}


/*****************************************************************************
 * FUNCTION
 *  udx_user_info_data_hdlr
 * DESCRIPTION
 *  This function is used to register user info data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_user_info_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->user_info,
        len,
        (MAX_UDX_USER_INFO_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_USER_INFO);
}


/*****************************************************************************
 * FUNCTION
 *  udx_encoding_data_hdlr
 * DESCRIPTION
 *  This function is used to register encoding data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_encoding_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->encoding,
        len,
        (MAX_UDX_ENCODING_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_ENCODING);
}


/*****************************************************************************
 * FUNCTION
 *  udx_file_size_data_hdlr
 * DESCRIPTION
 *  This function is used to register file size data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_file_size_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->file_size = (kal_uint32) atoi(data);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_FILE_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  udx_date_data_hdlr
 * DESCRIPTION
 *  This function is used to register date data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_date_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->date,
        len,
        (MAX_UDX_DATE_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_DATE);
}


/*****************************************************************************
 * FUNCTION
 *  udx_language_data_hdlr
 * DESCRIPTION
 *  This function is used to register language data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_language_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->language,
        len,
        (MAX_UDX_LANGUAGE_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_LANGUAGE);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_version_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard version data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->vcard_version,
        len,
        (MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_VERSION);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_record_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard record data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_record_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->vcard_record = (kal_uint16) udx_atoi(data);
    g_udx_parse_cntx.record_of_vcard = udx_header_info_p->vcard_record;
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_RECORD);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_length_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard length data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_length_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->vcard_length = (kal_uint32) atoi(data);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcalendar_version_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcalendar version data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcalendar_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->vcalendar_version,
        len,
        (MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCALENDAR_VERSION);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcalendar_record_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcalendar record data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcalendar_record_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->vcalendar_record = (kal_uint16) udx_atoi(data);
    g_udx_parse_cntx.record_of_vcalendar = udx_header_info_p->vcalendar_record;
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCALENDAR_RECORD);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcalendar_length_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcalendar length data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcalendar_length_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->vcalendar_length = (kal_uint32) atoi(data);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCALENDAR_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  udx_sms_version_data_hdlr
 * DESCRIPTION
 *  This function is used to register sms version data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_sms_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->sms_version,
        len,
        (MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_SMS_VERSION);
}


/*****************************************************************************
 * FUNCTION
 *  udx_sms_record_data_hdlr
 * DESCRIPTION
 *  This function is used to register sms record data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_sms_record_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->sms_record = (kal_uint16) udx_atoi(data);
    g_udx_parse_cntx.record_of_sms = udx_header_info_p->sms_record;
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_SMS_RECORD);
}


/*****************************************************************************
 * FUNCTION
 *  udx_sms_length_data_hdlr
 * DESCRIPTION
 *  This function is used to register sms length data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_sms_length_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->sms_length = (kal_uint32) atoi(data);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_SMS_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  udx_mms_version_data_hdlr
 * DESCRIPTION
 *  This function is used to register mms version data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_mms_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->mms_version,
        len,
        (MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_MMS_VERSION);
}


/*****************************************************************************
 * FUNCTION
 *  udx_mms_record_data_hdlr
 * DESCRIPTION
 *  This function is used to register mms record data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_mms_record_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->mms_record = (kal_uint16) udx_atoi(data);
    g_udx_parse_cntx.record_of_mms = udx_header_info_p->mms_record;
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_MMS_RECORD);
}


/*****************************************************************************
 * FUNCTION
 *  udx_mms_length_data_hdlr
 * DESCRIPTION
 *  This function is used to register mms length data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_mms_length_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->mms_length = (kal_uint32) atoi(data);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_MMS_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  udx_email_version_data_hdlr
 * DESCRIPTION
 *  This function is used to register email version data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_email_version_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_utf8_to_ucs2(
        data,
        udx_header_info_p->email_version,
        len,
        (MAX_UDX_VERSION_LEN + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_EMAIL_VERSION);
}


/*****************************************************************************
 * FUNCTION
 *  udx_email_record_data_hdlr
 * DESCRIPTION
 *  This function is used to register email record data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_email_record_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->email_record = (kal_uint16) udx_atoi(data);
    g_udx_parse_cntx.record_of_email = udx_header_info_p->email_record;
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_EMAIL_RECORD);
}


/*****************************************************************************
 * FUNCTION
 *  udx_email_length_data_hdlr
 * DESCRIPTION
 *  This function is used to register email length data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_email_length_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_header_info_p->email_length = (kal_uint32) atoi(data);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_EMAIL_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_sequence_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard sequence data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_sequence_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //g_udx_parse_cntx.vcard_sequence = (kal_uint16) atoi(data);
    g_udx_parse_cntx.vcard_sequence++;
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_SEQUENCE);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_n_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard n data hdlr
 * PARAMETERS
 * data         [IN]    data buffer
 * len          [IN]    data length, not buffer length
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_parse_name_data(kal_char *src_data, kal_int16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *data_ptr = NULL;
    kal_char *temp_buf = NULL;
    kal_char *dest_ptr = NULL;
    kal_uint8 name_part = 0;
    kal_int16 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/           
    data_ptr = src_data;
    
    if (!data_ptr || !data_ptr[0])
    {
        return;
    }
    
    temp_buf = (kal_char*)OslMalloc(len + 1);
    
    while(*data_ptr)
    {
        switch (name_part)
        {
            /* last name */
            case 0:
                dest_ptr = (kal_char*)udx_vcard_data_p->l_n;
                break;
                
            /* family name */
            case 1:
                dest_ptr = (kal_char*)udx_vcard_data_p->n;
                break;

            default:
                OslMfree(temp_buf);
                return;                                                                            
        }

        /* get the char data befor ';' */
        i = 0;
        while ((*data_ptr != ';') && (*data_ptr != '\0'))
        {
            if ((*data_ptr == '\\') && (*(data_ptr + 1) == ';' || *(data_ptr + 1) == '\\'))
            {
                data_ptr++;
            }
            if (i < len)
            {
                temp_buf[i++] = *data_ptr;
            }
            data_ptr++;
        }
        temp_buf[i] = '\0';

        /* convert and copy to destination buffer*/
        if (dest_ptr)
        {
            mmi_chset_convert(
                MMI_CHSET_UTF8,
                MMI_CHSET_UCS2,
                (char*)temp_buf,
                (char*)dest_ptr,
                (MMI_PHB_NAME_FIELD_LENGTH + 1) * ENCODING_LENGTH);
        }
        
        if (*data_ptr == ';')
        {
            name_part++;
            data_ptr++;
        }
    }

    OslMfree(temp_buf);
}

/*****************************************************************************
 * FUNCTION
 *  udx_vcard_n_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard n data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_n_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    kal_uint32 read_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_N);
    
    /* data is too long, need file to store, data is file path*/
    if (len == 0)
    {
        fh = FS_Open((kal_uint16*) data, FS_READ_ONLY);
        if (fh < FS_NO_ERROR)
        {
            return;
        }
        memset(g_udx_utf8_buf, 0, MAX_UDX_TAG_BUFFER);
        
        if (FS_Read(fh, g_udx_utf8_buf, (MAX_UDX_TAG_BUFFER - 1), &read_len) < FS_NO_ERROR)
        {
            FS_Close(fh);
            return;
        }
        FS_Close(fh);
        
        udx_vcard_parse_name_data((kal_char*)g_udx_utf8_buf, (MAX_UDX_TAG_BUFFER - 1));
    }
    else
    {
        udx_vcard_parse_name_data((kal_char*)data, (kal_int16)len);
    }
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_tel_cell_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard tel/cell data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_tel_cell_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 copy_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > 0 && data[0] == '+')
    {
        copy_len = ((len > (MMI_PHB_NUMBER_LENGTH + 1)) ? (MMI_PHB_NUMBER_LENGTH + 1) : len);
    }
    else
    {
        copy_len = ((len > MMI_PHB_NUMBER_LENGTH) ? MMI_PHB_NUMBER_LENGTH : len);
    }

	/* other <TEL> will be stored in dyn_num */
	if (UDX_IS_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_TEL_CELL) && g_udx_dyn_num_count != MMI_PHB_OPT_NUM_COUNT)
    {
		udx_vcard_data_p->dyn_num[g_udx_dyn_num_count].type = MMI_PHB_NUM_TYPE_MOBILE;
		memcpy(udx_vcard_data_p->dyn_num[g_udx_dyn_num_count].number, data, copy_len);
		udx_vcard_data_p->dyn_num[g_udx_dyn_num_count++].number[copy_len] = 0;
		return;
    }

	/* act the first <TEL> as tel_cell */
    memcpy(udx_vcard_data_p->tel_cell, data, copy_len);
    udx_vcard_data_p->tel_cell[copy_len] = 0;
    
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_TEL_CELL);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_tel_work_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard tel/work data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_tel_work_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 copy_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_udx_dyn_num_count == MMI_PHB_OPT_NUM_COUNT)
    {
        return;
    }
    
    if (len > 0 && data[0] == '+')
    {
        copy_len = ((len > (MMI_PHB_NUMBER_LENGTH + 1)) ? (MMI_PHB_NUMBER_LENGTH + 1) : len);
    }
    else
    {
        copy_len = ((len > MMI_PHB_NUMBER_LENGTH) ? MMI_PHB_NUMBER_LENGTH : len);
    }
    
    udx_vcard_data_p->dyn_num[g_udx_dyn_num_count].type = MMI_PHB_NUM_TYPE_OFFICE;
    memcpy(udx_vcard_data_p->dyn_num[g_udx_dyn_num_count].number, data, copy_len);
    udx_vcard_data_p->dyn_num[g_udx_dyn_num_count++].number[copy_len] = 0;
    
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_TEL_WORK);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_tel_home_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard tel/home data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_tel_home_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 copy_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_udx_dyn_num_count == MMI_PHB_OPT_NUM_COUNT)
    {
        return;
    }
    
    if (len > 0 && data[0] == '+')
    {
        copy_len = ((len > (MMI_PHB_NUMBER_LENGTH + 1)) ? (MMI_PHB_NUMBER_LENGTH + 1) : len);
    }
    else
    {
        copy_len = ((len > MMI_PHB_NUMBER_LENGTH) ? MMI_PHB_NUMBER_LENGTH : len);
    }
    
    udx_vcard_data_p->dyn_num[g_udx_dyn_num_count].type = MMI_PHB_NUM_TYPE_HOME;
    memcpy(udx_vcard_data_p->dyn_num[g_udx_dyn_num_count].number, data, copy_len);
    udx_vcard_data_p->dyn_num[g_udx_dyn_num_count++].number[copy_len] = 0;
    
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_TEL_HOME);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_tel_fax_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard tel/fax data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_tel_fax_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 copy_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_udx_dyn_num_count == MMI_PHB_OPT_NUM_COUNT)
    {
        return;
    }
    
    if (len > 0 && data[0] == '+')
    {
        copy_len = ((len > (MMI_PHB_NUMBER_LENGTH + 1)) ? (MMI_PHB_NUMBER_LENGTH + 1) : len);
    }
    else
    {
        copy_len = ((len > MMI_PHB_NUMBER_LENGTH) ? MMI_PHB_NUMBER_LENGTH : len);
    }

    udx_vcard_data_p->dyn_num[g_udx_dyn_num_count].type = MMI_PHB_NUM_TYPE_FAX;
    memcpy(udx_vcard_data_p->dyn_num[g_udx_dyn_num_count].number, data, copy_len);
    udx_vcard_data_p->dyn_num[g_udx_dyn_num_count++].number[copy_len] = 0;
    
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_TEL_FAX);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_adr_mailbox_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard adr/mailbox data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_adr_mailbox_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_escape_to_ucs2(
        data,
        udx_vcard_data_p->adr_mailbox,
        len,
        (MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_ADR_MAILBOX);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_adr_detail_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard adr/detail data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_adr_detail_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_escape_to_ucs2(
        data,
        udx_vcard_data_p->adr_detail,
        len,
        (MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_ADR_DETAIL);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_adr_street_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard adr/street data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_adr_street_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_escape_to_ucs2(
        data,
        udx_vcard_data_p->adr_street,
        len,
        (MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_ADR_STREET);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_adr_city_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard adr/city data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_adr_city_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_escape_to_ucs2(
        data,
        udx_vcard_data_p->adr_city,
        len,
        (MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_ADR_CITY);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_adr_province_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard adr/province data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_adr_province_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_escape_to_ucs2(
        data,
        udx_vcard_data_p->adr_province,
        len,
        (MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_ADR_PROVINCE);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_adr_postcode_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard adr/postcode data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_adr_postcode_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_escape_to_ucs2(
        data,
        udx_vcard_data_p->adr_postcode,
        len,
        (MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_ADR_POSTCODE);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_adr_country_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard adr/country data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_adr_country_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_escape_to_ucs2(
        data,
        udx_vcard_data_p->adr_country,
        len,
        (MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_ADR_COUNTRY);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_url_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard url data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_url_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 copy_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_len = ((len > MMI_PHB_URL_LENGTH) ? MMI_PHB_URL_LENGTH : len);
    memcpy(udx_vcard_data_p->url, data, copy_len);
    udx_vcard_data_p->url[copy_len] = 0;
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_URL);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_org_name_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard org/name data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_org_name_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_escape_to_ucs2(
        data,
        udx_vcard_data_p->org_name,
        len,
        (MMI_PHB_COMPANY_LENGTH + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_ORG_NAME);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_title_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard title data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_title_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    udx_convert_escape_to_ucs2(
        data,
        udx_vcard_data_p->title,
        len,
        (MMI_PHB_TITLE_LENGTH + 1) * ENCODING_LENGTH);
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_TITLE);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_bday_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard bday data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_bday_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 copy_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_len = ((len > MMI_PHB_BDAY_LENGTH) ? MMI_PHB_BDAY_LENGTH : len);
    memcpy(udx_vcard_data_p->bday, data, copy_len);
    udx_vcard_data_p->bday[copy_len] = 0;
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_BDAY);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_email_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard email data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_email_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 copy_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_len = ((len > MMI_PHB_EMAIL_LENGTH) ? MMI_PHB_EMAIL_LENGTH : len);
    memcpy(udx_vcard_data_p->email, data, copy_len);
    udx_vcard_data_p->email[copy_len] = 0;
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_EMAIL);
}


/*****************************************************************************
 * FUNCTION
 *  udx_vcard_email_home_data_hdlr
 * DESCRIPTION
 *  This function is used to register vcard email home data hdlr
 * PARAMETERS
 *  resv        [?]         
 *  el          [IN]        
 *  data        [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_vcard_email_home_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 copy_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_len = ((len > MMI_PHB_EMAIL_LENGTH) ? MMI_PHB_EMAIL_LENGTH : len);
    memcpy(udx_vcard_data_p->email_home, data, copy_len);
    udx_vcard_data_p->email_home[copy_len] = 0;
    UDX_SET_MASK(g_udx_valid_mask, UDX_TAG_ID_VCARD_EMAIL_HOME);
}

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
/* Write your global function here */
/* 
 * Global function shall be declared in XxxProt.h or XxxGprot.h.
 */


#define GLOBAL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  udx_build_header_info
 * DESCRIPTION
 *  This function is used to build header info
 * PARAMETERS
 *  b_req       [?]     
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 udx_build_header_info(mmi_udx_build_header_req_struct *b_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XG_HANDLE xml_hdlr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_state = UDX_STATE_BUILD_BEGIN;
    g_udx_error_code = UDX_CODE_NO_ERROR;

    udx_set_record_count(
        b_req->type_mask,
        b_req->vcard_count,
        b_req->vcalendar_count,
        b_req->sms_count,
        b_req->mms_count,
        b_req->email_count);

    g_udx_fs_handle = FS_Open((kal_uint16*) b_req->file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (g_udx_fs_handle == FS_ROOT_DIR_FULL)
    {
        g_udx_error_code = UDX_CODE_ROOT_DIR_FULL_ERROR;
        return -1;
    }
    else if (g_udx_fs_handle == FS_DISK_FULL)
    {
        g_udx_error_code = UDX_CODE_DISK_FULL_ERROR;
        return -1;
    }

    xml_hdlr = xml_new_generator_file(g_udx_fs_handle);
    if (xml_hdlr < 0)
    {
        g_udx_error_code = UDX_CODE_NEW_XML_ERROR;
        return -1;
    }

    udx_set_xml_handler(xml_hdlr);

    result = xml_generate_xmldecl(xml_hdlr, 0, XML_ENCODING_UTF8);
    if (result < 0)
    {
        udx_convert_gen_error(result);
        goto EXIT_HINFO;
    }

    result = udx_build_start_tag(xml_hdlr, UDX_TAG_DATA_EXCHANGE_INFO);
    if (result < 0)
    {
        udx_convert_gen_error(result);
        goto EXIT_HINFO;
    }

    result = udx_build_record_info(xml_hdlr, b_req->user_name, b_req->date_format, b_req->separator_format);
    if (result < 0)
    {
        udx_convert_gen_error(result);
        goto EXIT_HINFO;
    }

    return 0;

  EXIT_HINFO:
    xml_close_generator(xml_hdlr);
    FS_Close(g_udx_fs_handle);
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_vcard_data
 * DESCRIPTION
 *  This function is used to build vcard data
 * PARAMETERS
 *  d_req       [?]     
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 udx_build_vcard_data(mmi_udx_build_data_req_struct *d_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XG_HANDLE xml_hdlr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_state = UDX_STATE_BUILD_VCARD;
    g_udx_error_code = UDX_CODE_NO_ERROR;

    xml_hdlr = udx_get_xml_handler();

    if (d_req->sequence == 1)
    {
        result = udx_build_start_tag(xml_hdlr, UDX_TAG_VCARD);
        if (result < 0)
        {
            udx_convert_gen_error(result);
            goto EXIT_VDATA;
        }
    }

    if (d_req->sequence > 0)
    {
        result = udx_build_vcard_info(xml_hdlr, d_req->sequence, &(d_req->u.vcard_data));
        if (result < 0)
        {
            udx_convert_gen_error(result);
            goto EXIT_VDATA;
        }
    }

    if (d_req->sequence == udx_get_vcard_count())
    {
        result = udx_build_end_tag(xml_hdlr, UDX_TAG_VCARD);
        if (result < 0)
        {
            udx_convert_gen_error(result);
            goto EXIT_VDATA;
        }

        /* If there is no vcalendar, sms, mms or email build request, just write end tag
           and close XML generator. */
        if (udx_get_vcalendar_count() == 0 &&
            udx_get_sms_count() == 0 &&
            udx_get_mms_count() == 0 &&
            udx_get_email_count() == 0)
        {
            result = udx_build_end_tag(xml_hdlr, UDX_TAG_DATA_EXCHANGE_INFO);
            if (result < 0)
            {
                udx_convert_gen_error(result);
                goto EXIT_VDATA;
            }
            return 0;
        }
        else
        {
            /* Not supported now */
            ASSERT(0);
        }
    }

    return 0;

  EXIT_VDATA:
    xml_close_generator(xml_hdlr);
    FS_Close(g_udx_fs_handle);
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  udx_rebuild_header_info
 * DESCRIPTION
 *  This function is used to rebuild header info
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 udx_rebuild_header_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XG_HANDLE xml_hdlr;
    kal_int32 file_size, vcard_length;
    kal_char data[12];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_state = UDX_STATE_BUILD_END;
    g_udx_error_code = UDX_CODE_NO_ERROR;

    xml_hdlr = udx_get_xml_handler();

    /* Close XML generator first, and then close FS handle. */
    xml_close_generator(xml_hdlr);

    file_size = udx_length_element_calc(g_udx_fs_handle, NULL);
    vcard_length = udx_length_element_calc(g_udx_fs_handle, UDX_TAG_VCARD);

    sprintf(data, "%d", file_size);
    udx_update_element(g_udx_fs_handle, UDX_TAG_FILE_SIZE, data);
    sprintf(data, "%d", vcard_length);
    udx_update_element(g_udx_fs_handle, UDX_TAG_VCARD_LENGTH, data);

    FS_Close(g_udx_fs_handle);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_abort
 * DESCRIPTION
 *  This function is used to abort to build
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 udx_build_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XG_HANDLE xml_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_state = UDX_STATE_BUILD_ABORT;
    g_udx_error_code = UDX_CODE_NO_ERROR;

    xml_hdlr = udx_get_xml_handler();

    /* Close XML generator, and let MMI delete this .udx file. */
    xml_close_generator(xml_hdlr);

    FS_Close(g_udx_fs_handle);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_header_info
 * DESCRIPTION
 *  This function is used to parse header info
 * PARAMETERS
 *  h_req       [?]     
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 udx_parse_header_info(mmi_udx_parse_header_req_struct *h_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *parser;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_state = UDX_STATE_PARSE_HEADER;
    g_udx_error_code = UDX_CODE_NO_ERROR;
    g_udx_step = UDX_STEP_IDLE;

    udx_register_parser_mode(KAL_TRUE);

    parser = get_ctrl_buffer(sizeof(XML_PARSER_STRUCT));
    if (parser == NULL)
    {
        g_udx_error_code = UDX_CODE_UNEXPECTED_ERROR;
        return -1;
    }

    udx_save_xml_parser(parser);

    if (xml_new_parser(parser) < 0)
    {
        udx_parse_close();
        g_udx_error_code = UDX_CODE_NEW_XML_ERROR;
        return -1;
    }

    xml_register_element_handler(parser, udx_start_element_hdlr, udx_end_element_hdlr);
    xml_register_data_handler(parser, udx_data_hdlr);

    result = xml_parse(parser, (kal_wchar*) h_req->file_path);
    if (result < 0)
    {
        xml_close_parser(parser);
        udx_parse_close();
        if (result == XML_RESULT_FILE_NOT_FOUND)
        {
            g_udx_error_code = UDX_CODE_FILE_NOT_FOUND_ERROR;
        }
        else
        {
            g_udx_error_code = UDX_CODE_XML_FAIL_ERROR;
        }
        return -1;
    }

    if (!udx_check_mandatory_field_is_valid())
    {
        xml_close_parser(parser);
        udx_parse_close();
        g_udx_error_code = UDX_CODE_XML_FAIL_ERROR;
        return -1;
    }

    /* Close XML parser, and free its memory. */
    xml_close_parser(parser);
    udx_parse_close();

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_body_data
 * DESCRIPTION
 *  This function is used to parse body data
 * PARAMETERS
 *  b_req       [?]     
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 udx_parse_body_data(mmi_udx_parse_body_req_struct *b_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *parser;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_state = UDX_STATE_PARSE_BODY;
    g_udx_error_code = UDX_CODE_NO_ERROR;
    g_udx_step = UDX_STEP_IDLE;
	g_udx_valid_mask = 0;
	g_udx_dyn_num_count = 0;
	
    udx_register_parser_mode(KAL_FALSE);
    udx_set_type_mask(b_req->type_mask);

    parser = get_ctrl_buffer(sizeof(XML_PARSER_STRUCT));
    if (parser == NULL)
    {
        g_udx_error_code = UDX_CODE_UNEXPECTED_ERROR;
        return -1;
    }

    udx_save_xml_parser(parser);

    if (xml_new_parser(parser) < 0)
    {
        udx_parse_close();
        
        g_udx_error_code = UDX_CODE_NEW_XML_ERROR;
        return -1;
    }

    xml_register_element_handler(parser, udx_start_element_hdlr, udx_end_element_hdlr);
    xml_register_data_handler(parser, udx_data_hdlr);

    result = xml_parse(parser, (kal_wchar*) b_req->file_path);
    if (result < 0)
    {
        xml_close_parser(parser);
        
        udx_parse_close();
        
        if (result == XML_RESULT_FILE_NOT_FOUND)
        {
            g_udx_error_code = UDX_CODE_FILE_NOT_FOUND_ERROR;
        }
        else
        {
            g_udx_error_code = UDX_CODE_XML_FAIL_ERROR;
        }
        return -1;
    }

    if (g_udx_valid_mask == 0)
    {
        xml_close_parser(parser);
        
        udx_parse_close();
        
        g_udx_error_code = UDX_CODE_XML_FAIL_ERROR;
        return -1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_resume
 * DESCRIPTION
 *  This function is used to resume to parse
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 udx_parse_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *parser;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_state = UDX_STATE_PARSE_VCARD;
    g_udx_error_code = UDX_CODE_NO_ERROR;

    parser = udx_load_xml_parser();

    /* Resume XML parser, and continue to parse vcard data. */
    result = xml_resume_parse(parser);
    if (result < 0)
    {
        xml_close_parser(parser);
        
        udx_parse_close();
        
        if (result == XML_RESULT_FILE_NOT_FOUND)
        {
            g_udx_error_code = UDX_CODE_FILE_NOT_FOUND_ERROR;
        }
        else
        {
            g_udx_error_code = UDX_CODE_XML_FAIL_ERROR;
        }
        return -1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_abort
 * DESCRIPTION
 *  This function is used to abort to parse
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 udx_parse_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *parser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_state = UDX_STATE_PARSE_ABORT;
    g_udx_error_code = UDX_CODE_NO_ERROR;

    parser = udx_load_xml_parser();

    /* Close XML parser, and free its memory. */
    xml_close_parser(parser);
    udx_parse_close();

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_close
 * DESCRIPTION
 *  This function is used to close xml parser
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
void udx_parse_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *parser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parser = udx_load_xml_parser();

    /* Close XML parser, and free its memory. */
    xml_close_parser(parser);
    if (parser != NULL)
    {
        free_ctrl_buffer(parser);
        g_udx_parse_cntx.xml_parser = NULL;
    }
}

#endif /* __UDX_SUPPORT__ */

