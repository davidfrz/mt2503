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
 *  supl2mmi_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains SUPL task entry function.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SUPL2MMI_STRUCT_H
#define SUPL2MMI_STRUCT_H

#include "supl2mmi_enums.h"
#include "kal_general_types.h"

#define SUPL_MMI_MAX_REQ_LEN        50          /* Max length of requestor id */
#define SUPL_MMI_MAX_CLIENT_LEN     50          /* Max length of client name */
#define SUPL_MMI_MAX_ADDR_LEN       64          /* Max length of address */
#define SUPL_MMI_MAX_PUSH_SIZE      1024        /* Max length of push */
#define SUPL_MAX_SATELLITE_INFO     32          /* Max number of satellite information */

#define SUPL_USE_RRLP   (0x01)
#define SUPL_USE_RRC    (0x02)

/* The structre defines the SUPL notification. */
typedef struct
{
    supl_mmi_notify_enum    notify_type;                            /* Type of notification */
    supl_mmi_encoding_enum  encodeing_type;                         /* Type of encoding */
    kal_char                req_id[SUPL_MMI_MAX_REQ_LEN];           /* Requestor id */
    supl_mmi_id_enum        req_id_type;                            /* Type of requestor id*/
    kal_char                client_name[SUPL_MMI_MAX_CLIENT_LEN];   /* Client name */
    supl_mmi_id_enum        client_name_type;                       /* Type of Client name */
} supl_mmi_notify_struct;

/* This structure defines the notification result */
typedef struct
{
    supl_mmi_result_enum    result;             /* Result */
    supl_mmi_cause_enum     cause;              /* Cause */
} supl_mmi_notify_result_struct;

/* This structure defines the SUPL QOP */
typedef struct
{
    kal_uint8   horacc;                         /* horizontal accuracy */
    kal_bool    veracc_used;                    /* if vertical accuracy exist */
    kal_uint8   veracc;                         /* vertical accuracy */
    kal_bool    maxLocAge_used;                 /* if Maximun Location Age exist */
    kal_uint16  maxLocAge;                      /* Maximun Location Age */
    kal_bool    delay_used;                     /* if Delay exist */
    kal_uint8   delay;                          /* Delay */
} supl_mmi_qop_struct;

/* This structure defines the uncertainty.  Refer to [3GPP GAD]. */
typedef struct
{
    kal_uint8           semi_major;             /* semi major */
    kal_uint8           semi_minor;             /* semi minor */
    kal_uint8           major_axis;             /* major axis */
}supl_mmi_pos_uncert_struct;

/* This structure defines the altitude information.  Refer to [3GPP GAD]. */
typedef struct
{
    supl_mmi_direction_enum     direction;      /* direction */
    kal_uint16                  altitude;       /* altitude */
    kal_uint8                   uncertainty;    /* uncertainty */
} supl_mmi_alti_info_struct;

/* This structure defines the position estimation.  Refer to [3GPP GAD]. */
typedef struct
{
    supl_mmi_sign_enum          latitude_sign;                      /* Sign of latitude */
    kal_uint32                  latitude;                           /* Value of latitude */
    kal_int32                   longtude;                           /* Value of longtude */
    kal_bool                    uncertainty_used;                   /* If uncertainty is present */
    supl_mmi_pos_uncert_struct  uncertainty;                        /* Uncertianty */
    kal_bool                    confidence_used;                    /* If confidence is present */
    kal_uint8                   confidence;                         /* Confidence */
    kal_bool                    altitude_info_used;                 /* If altitude information is present */
    supl_mmi_alti_info_struct   altitude_info;                      /* Altitude information */
} supl_mmi_pos_estimate_struct;

/* This structure is used for those velocity datas with 1 data item */
typedef struct
{
    kal_uint8                   num_bits;       /* Number of bits */
    kal_uint8                   data[1];        /* Data */
} supl_mmi_velocity_data_1_struct;

/* This structure is used for those velocity datas with 2 data item */
typedef struct
{
    kal_uint8                   num_bits;       /* Number of bits */
    kal_uint8                   data[2];        /* Data */
} supl_mmi_velocity_data_2_struct;

/* This structure is used to define the horizontal velocity */
typedef struct
{
   supl_mmi_velocity_data_2_struct  bearing;    /* bearing */
   supl_mmi_velocity_data_2_struct  hor_speed;  /* horizontal speed */
} supl_mmi_h_velocity_struct;

/* This structure is used to define the horizontal and vertiacal velocity */
typedef struct
{
    supl_mmi_velocity_data_1_struct ver_direction;                  /* Vertical direction */
    supl_mmi_velocity_data_2_struct bearing;                        /* bearing */
    supl_mmi_velocity_data_2_struct hor_speed;                      /* Horizontal speed */
    supl_mmi_velocity_data_1_struct ver_speed;                      /* Vertical speed */
} supl_mmi_hv_velocity_struct;

/* This structure is used to define the horizontal velocity uncertainty */
typedef struct
{
    supl_mmi_velocity_data_2_struct bearing;                        /* bearing */
    supl_mmi_velocity_data_2_struct hor_speed;                      /* Horizontal speed */
    supl_mmi_velocity_data_1_struct hor_speed_uncertainty;          /* Horizontal speed uncertainty */
} supl_mmi_h_velocity_uncert_struct;

/* This structure is used to define theh horizontal and vertical velocity uncertainty structure */
typedef struct
{
    supl_mmi_velocity_data_1_struct ver_direction;                  /* Vertical direction */
    supl_mmi_velocity_data_2_struct bearing;                        /* bearing */
    supl_mmi_velocity_data_2_struct hor_speed;                      /* Horizontal speed */
    supl_mmi_velocity_data_1_struct ver_speed;                      /* Vertical speed */
    supl_mmi_velocity_data_1_struct hor_speed_uncertainty;          /* Horizontal speed uncertainty */
    supl_mmi_velocity_data_1_struct ver_speed_uncertainty;          /* Vertical speed uncertainty */
} supl_mmi_hv_velocity_uncert_struct;

/* This union contain the four types of velocity structures */
typedef union
{
    supl_mmi_h_velocity_struct          hor_velocity;               /* Horizontal velocity */
    supl_mmi_hv_velocity_struct         hv_velocity;                /* Horizontal and vertical velocity */
    supl_mmi_h_velocity_uncert_struct   hor_uncertainty;            /* Horizontal velocity uncertianty */
    supl_mmi_hv_velocity_uncert_struct  hv_uncertainty;             /* Horizontal and vertical velocity uncertainty */
} supl_mmi_velocity_union;

/* This structure is used to define the velocity */
typedef struct
{
    supl_mmi_velocity_type_enum type;           /* Type of velocity */
    supl_mmi_velocity_union v;                  /* velocity */
} supl_mmi_velocity_struct;

/* This structure is used to define the position */ 
typedef struct
{
    kal_uint32                      time_stamp;                     /* Time stamp */
    kal_uint16                      week;                           /* Week information */
    supl_mmi_pos_estimate_struct    pos_estimate;                   /* Position */
    kal_bool                        velocity_used;                  /* If velocity is present */
    supl_mmi_velocity_struct        velocity;                       /* Velocity */
} supl_mmi_position_struct;

/* This structure is used to define satellite information */
typedef struct
{
    kal_uint8           sat_id;                 /* Satellite ID */
    kal_uint8           iODE;                   /* iODE */
} supl_mmi_satellite_info_struct;

/* This structure is used to define navigation model */
typedef struct
{
    kal_uint16                      gps_week;                       /* GPS week info. */
    kal_uint8                       gps_toe;                        /* GPS toe */
    kal_uint8                       nsat;                           /* Number of satellite */
    kal_uint8                       toe_limit;                      /* toe limit */
    kal_bool                        sat_info_used;                  /* If satellite info present */
    supl_mmi_satellite_info_struct  sat_info[SUPL_MAX_SATELLITE_INFO];/* Satellite information */
} supl_mmi_navigation_model_struct;

/* This structure is used to define the request of assistance data */
typedef struct
{
    kal_bool                            almanac;                    /* If alamanac needed */
    kal_bool                            utc_model;                  /* If utc model needed */
    kal_bool                            ionospheric_model;          /* If ionospheric model needed */
    kal_bool                            dgps_correction;            /* If dgps correction needed */
    kal_bool                            ref_location;               /* If reference location needed */
    kal_bool                            ref_time;                   /* If reference time needed */
    kal_bool                            acquisition_assist;         /* If acquisition assistence data needed */
    kal_bool                            realtime_integrity;         /* If realtime integrity needed */
    kal_bool                            navigation_model;           /* If navigation model needed */
    supl_mmi_navigation_model_struct    nav_model_data;             /* Navigation model data */
} supl_mmi_req_assist_data_struct;

/* PRIMITIVES */


/*
 * The structure for MSG_ID_SUPL_MMI_PUSH_REQ.
 * MMI uses this message to notify SUPL a incoming push (SUPL INIT).
 */
typedef struct
{
    kal_uint8           ref_count;                                  /* reference count */
    kal_uint16          msg_len;                                    /* message length */    
    kal_uint16          req_id;                                     /* Request id */
    kal_uint32          nwk_account_id;                             /* Network account id used to create SUPL connection */
    supl_sim_id_enum    sim_id;                                     /* sim id */    
    kal_char            slp_addr[SUPL_MMI_MAX_ADDR_LEN];            /* SLP address */
    kal_uint16          slp_port;                                   /* SLP port */
    kal_bool            use_tls;                                    /* TLS setting */
    kal_uint8           payload_capability;                         /* Payload capability, e.g., RRLP, RRC, Both */    
    kal_uint8           ut_timer_value;                             /* timeout value for UT1, UT2, and UT3 */
    
    kal_uint16          len;                                        /* The length of push data */
    char                data[SUPL_MMI_MAX_PUSH_SIZE];               /* Push Data */
} supl_mmi_push_req_struct;

/*
 * The structure for MSG_ID_SUPL_MMI_STATUS_IND.
 * SUPL uses this message to notify MMI the new status.
 * If the push contains correct SUPL INIT, SUPL will use this message to notify the start of a SUPL session.
 */
typedef struct
{
    kal_uint8                   ref_count;                          /* reference count */
    kal_uint16                  msg_len;                            /* message length */
    kal_uint32                  obj_valid;                          /* The bit-wise flgs to indicate which compoents are present */
    kal_uint16                  req_id;                             /* Request id */
    supl_mmi_status_enum        status;                             /* SUPL Status */
    supl_mmi_result_enum        result;                             /* Result */
    supl_mmi_cause_enum         cause;                              /* Cause */
    supl_mmi_pos_method_enum    pos_method;                         /* Position method */
    supl_mmi_slp_mode_enum      slp_mode;                           /* SLP mode(Proxy or Non-Proxy) */
    supl_mmi_qop_struct         qop;                                /* QOP */
    supl_mmi_notify_struct      notify;                             /* Notification & Verification */
    supl_mmi_position_struct    position;                           /* Position */
} supl_mmi_status_ind_struct;


/*
 * The structure for MSG_ID_SUPL_MMI_STATUS_RSP.
 * MMI uses this message to notify SUPL the result of STATUS_IND.
 */
typedef struct
{
    kal_uint8                       ref_count;                      /* reference count */
    kal_uint16                      msg_len;                        /* message length */
    kal_uint32                      obj_valid;                      /* The bit-wise flgs to indicate which compoents are present */
    kal_uint16                      req_id;                         /* Request id */
    kal_uint32                      nwk_account_id;                 /* Network account id used to create SUPL connection */
    supl_mmi_position_struct        pos;                            /* Position */
    supl_mmi_req_assist_data_struct filter;                         /* Filter */
    supl_mmi_notify_result_struct   notify_rsp;                     /* Notification response */
} supl_mmi_status_rsp_struct;

/*
 * The structure for MSG_ID_SUPL_MMI_START_REQ.
 * MMI uses this message to request starting a SUPL SET initiated session.
 */
typedef struct
{
    kal_uint8                       ref_count;                      /* reference count */
    kal_uint16                      msg_len;                        /* message length */
    kal_uint16                      req_id;                         /* Request id */
    kal_uint32                      nwk_account_id;                 /* Network account id used to create SUPL connection */
    supl_sim_id_enum                sim_id;                         /* sim id */
    kal_char                        slp_addr[SUPL_MMI_MAX_ADDR_LEN];/* SLP address */
    kal_uint16                      slp_port;                       /* SLP port */
    kal_bool                        use_tls;                        /* TLS setting */
    kal_uint8                       payload_capability;             /* Payload capability, e.g., RRLP, RRC, Both */   
    kal_uint8                       ut_timer_value;                 /* timeout value for UT1, UT2, and UT3 */
    
    supl_mmi_pos_method_enum        pos_method;                     /* Position method */
    supl_mmi_qop_struct             qop;                            /* QOP */
    supl_mmi_req_assist_data_struct filter;                         /* Filter */
} supl_mmi_start_req_struct;

/*
 * The structure for MSG_ID_SUPL_MMI_ABORT_REQ.
 * MMI uses this message to request aborting a SUPL SET initiated session.
 */
typedef struct
{
    kal_uint8                   ref_count;                          /* reference count */
    kal_uint16                  msg_len;                            /* message length */
    kal_uint16                  req_id;                             /* Request id */
} supl_mmi_abort_req_struct;

/*
 * The structure for MSG_ID_SUPL_MMI_ABORT_CNF.
 * SUPL uses this message to notify the result of aborting.
 */
typedef struct
{
    kal_uint8                   ref_count;                          /* reference count */
    kal_uint16                  msg_len;                            /* message length */
    kal_uint16                  req_id;                             /* Request id */
} supl_mmi_abort_cnf_struct;

/*
 * The structure for MSG_ID_SUPL_MMI_NOTIFY_IND.
 * SUPL uses this message to notify an notification or verification coming.
 */
typedef struct
{
    kal_uint8               ref_count;                              /* reference count */
    kal_uint16              msg_len;                                /* message length */
    kal_uint16              req_id;                                 /* Request id */
    supl_mmi_notify_struct  notify;                                 /* Notification and verification */
} supl_mmi_notify_ind_struct;

/*
 * The structure for MSG_ID_SUPL_MMI_NOTIFY_RSP.
 * MMI uses this message to notify the response of an notification or verification.
 */
typedef struct
{
    kal_uint8                   ref_count;                          /* reference count */
    kal_uint16                  msg_len;                            /* message length */
    kal_uint16                  req_id;                             /* Request id */
    supl_mmi_notify_result_struct  notify_rsp;                      /* The response of notification & verification */
} supl_mmi_notify_rsp_struct;

#endif /* SUPL2APP_STRUCT_H */

