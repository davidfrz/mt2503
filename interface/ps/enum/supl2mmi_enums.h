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
 *  supl2mmi_enums.h
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

#ifndef SUPL2MMI_ENUMS_H
#define SUPL2MMI_ENUMS_H

#define SUPL_MMI_COMP_POSITION                  0x0001	/* SUPL component: POSITION */
#define SUPL_MMI_COMP_NOTIFY                    0x0002	/* SUPL component: NOTIFY */
#define SUPL_MMI_COMP_NOTIFY_RSP                0x0004	/* SUPL component: NOTIFY_RSP */
#define SUPL_MMI_COMP_QOP                       0x0008	/* SUPL component: QOP */
#define SUPL_MMI_COMP_FILTER                    0x0010	/* SUPL component: FILTER */
#define SUPL_MMI_COMP_SUPP_NWK_INFO             0x0011	/* SUPL component: SUPPORT NETWORK INFO */


#define SUPL_MMI_IF_POSITION_USED(valid)        (valid & SUPL_MMI_COMP_POSITION)         /* Used to check if the SUPL message contain POSITION component */
#define SUPL_MMI_IF_NOTIFY_USED(valid)          (valid & SUPL_MMI_COMP_NOTIFY)          /* Used to check if the SUPL message contain NOTIFY component */
#define SUPL_MMI_IF_NOTIFY_RSP_USED(valid)      (valid & SUPL_MMI_COMP_NOTIFY_RSP)      /* Used to check if the SUPL message contain NOTIFY_RSP component */
#define SUPL_MMI_IF_QOP_USED(valid)             (valid & SUPL_MMI_COMP_QOP)             /* Used to check if the SUPL message contain QOP component */
#define SUPL_MMI_IF_FILTER_USED(valid)          (valid & SUPL_MMI_COMP_FILTER)          /* Used to check if the SUPL message contain FILTER component */
#define SUPL_MMI_IF_SUPP_NWK_INFO_USED(valid)   (valid & SUPL_MMI_COMP_SUPP_NWK_INFO)   /* Used to check if the SUPL message contain SUPPORT NETWORK INFO component */

#define SUPL_MMI_USE_POSITION(valid)            (valid |= SUPL_MMI_COMP_POSITION)       /* Used to set the flag indicating SUPL component POSITION is used */
#define SUPL_MMI_USE_NOTIFY(valid)              (valid |= SUPL_MMI_COMP_NOTIFY)         /* Used to set the flag indicating SUPL component NOTIFY is used */
#define SUPL_MMI_USE_NOTIFY_RSP(valid)          (valid |= SUPL_MMI_COMP_NOTIFY_RSP)     /* Used to set the flag indicating SUPL component NOTIFY_RSP is used */
#define SUPL_MMI_USE_QOP(valid)                 (valid |= SUPL_MMI_COMP_QOP)            /* Used to set the flag indicating SUPL component QOP is used */
#define SUPL_MMI_USE_FILTER(valid)              (valid |= SUPL_MMI_COMP_FILTER)         /* Used to set the flag indicating SUPL component FILTER is used */
#define SUPL_MMI_USE_SUPP_NWK_INFO(valid)       (valid |= SUPL_MMI_COMP_SUPP_NWK_INFO)  /* Used to set the flag indicating SUPL component SUPPORT NETWORK INFO is used */

/* This enum is used to indicate the result. */
typedef enum
{
    SUPL_MMI_RESULT_OK,             /* Success */
    SUPL_MMI_RESULT_ERROR,          /* Error */
    SUPL_MMI_RESULT_NETWORK_ERROR,  /* Network fail */
    SUPL_MMI_RESULT_END
} supl_mmi_result_enum;

/* This enum is used to indicate the cause. */
typedef enum
{
    SUPL_MMI_CAUSE_NONE,
    SUPL_MMI_CAUSE_NETWORK_CREATE_FAIL,     /* Network Create Fail */
    SUPL_MMI_CAUSE_BAD_PUSH_CONTENT,        /* Incorrect PUSH content */
    SUPL_MMI_CAUSE_NOT_SUPPORTED,           /* Unsupported Operation */
    SUPL_MMI_CAUSE_REQ_NOT_ACCEPTED,        /* Requeset Not Accepted */
    SUPL_MMI_CAUSE_NO_RESOURCE,             /* No Resourcce to Handle new process */
    SUPL_MMI_CAUSE_NETWORK_DISCONN,         /* Network Connection is Down */
    SUPL_MMI_CAUSE_REMOTE_ABORT,            /* Remote Side Abort the Session (receive SUPL END) */
    SUPL_MMI_CAUSE_TIMER_EXPIRY,            /* Expect Message not Back During a Specific Time Interval */
    SUPL_MMI_CAUSE_REMOTE_MSG_ERROR,        /* Receive Incorrect Message Content */
    SUPL_MMI_CAUSE_USER_AGREE,              /* User agree on confirmation */
    SUPL_MMI_CAUSE_USER_DENY,               /* User deny on confirmation */
    SUPL_MMI_CAUSE_NO_POSITION,             /* Only for NO Position */
    SUPL_MMI_CAUSE_TLS_AUTH_FAIL,           /* TLS authentication fail */
    SUPL_MMI_CAUSE_END
} supl_mmi_cause_enum;

/* This enum is used to indicate the new status of SUPL. */
typedef enum
{
    SUPL_MMI_STATUS_TERMINATED,             /* Terminated */
    SUPL_MMI_STATUS_ACTIVATED,              /* Activated */
    SUPL_MMI_STATUS_STAND_BY,               /* Currently not used */
    SUPL_MMI_STATUS_END
} supl_mmi_status_enum;

/* This enum is used to indicate the SLP mode. */
typedef enum
{
    SUPL_MMI_SLP_MODE_PROXY,                /* Proxy mode */
    SUPL_MMI_SLP_MODE_NON_PROXY,            /* Non-proxy mode */
    SUPL_MMI_SLP_MODE_END
} supl_mmi_slp_mode_enum;

/* This enum is used to indicate notification types. */
typedef enum
{
    SUPL_MMI_NOTIFY_NONE,                   /* No notification & no verification */
    SUPL_MMI_NOTIFY_ONLY,                   /* Notification Only */
    SUPL_MMI_NOTIFY_ALLOW_NO_ANSWER,        /* Notification and verification, Allow on no answer. (If no answer is received from the SET User, the SET will assume that user consent has been granted and will proceed) */
    SUPL_MMI_NOTIFY_DENY_NO_ANSWER,         /* Notification and verification, Deny on no answer. (If no answer is received from the SET User, the SET will assume that user consent has been denied and will abort) */
    SUPL_MMI_NOTIFY_PRIVACY,                /* Privacy-Override. (Is used for preventing notification and verification without leaving any traces of a performed position fix or position fix attempt in terms of log files etc. on the SET). */
    SUPL_MMI_NOTIFY_END
} supl_mmi_notify_enum;

/* This enum is used to indicate encoding types. */
typedef enum
{
    SUPL_MMI_ENCODING_NONE,                 /* No encoding specified */
    SUPL_MMI_ENCODING_UCS2,                 /* UCS2 encoding */
    SUPL_MMI_ENCODING_GSM_DEFAULT,          /* GSM default encoding */
    SUPL_MMI_ENCODING_UTF8,                 /* UTF-8 encoding */
    SUPL_MMI_ENCODING_END
} supl_mmi_encoding_enum;

/* This enum is used to indicate the RequesterID type. */
typedef enum
{
    SUPL_MMI_ID_NONE,                       /* None */
    SUPL_MMI_ID_LOGICAL_NAME,               /* Logical Name */
    SUPL_MMI_ID_MSISDN,                     /* MSISDN */
    SUPL_MMI_ID_EMAIL,                      /* E-mail address */
    SUPL_MMI_ID_URL,                        /* URL */
    SUPL_MMI_ID_SIP,                        /* SIP URL */
    SUPL_MMI_ID_IMS_ID,                     /* IMS public identity */
    SUPL_MMI_ID_MIN,                        /* MIN */
    SUPL_MMI_ID_MDN,                        /* MDN */
    SUPL_MMI_ID_END
} supl_mmi_id_enum;


/* This enum is used to indicate the position method type. */
typedef enum
{
    SUPL_MMI_POS_METHOD_SET_ASSIST,         /* A-GPS SET assisted only */
    SUPL_MMI_POS_METHOD_SET_BASE,           /* A-GPS SET based only */
    SUPL_MMI_POS_METHOD_SET_ASSIST_PREF,    /* A-GPS SET assisted preferred (A-GPS SET based is the fallback mode) */
    SUPL_MMI_POS_METHOD_SET_BASE_PREF,      /* A-GPS SET based preferred (A-GPS SET assisted is the fallback mode) */
    SUPL_MMI_POS_METHOD_AUTO,               /* Autonomous GPS */
    SUPL_MMI_POS_METHOD_NO_POSITION,        /* No position */
    SUPL_MMI_POS_METHOD_UNSUPPORTED,        /* Unsupported method (Defined in spec, but not supported) */
    SUPL_MMI_POS_METHOD_INVALID,            /* Invalid method (Not defined in spec) */
    SUPL_MMI_POS_METHOD_END
} supl_mmi_pos_method_enum;

/* This enum is used to indicate the sign. */
typedef enum
{
    SUPL_MMI_SIGN_NORTH,                    /* NORTH */
    SUPL_MMI_SIGN_SOUTH,                    /* SOUTH */
    SUPL_MMI_SIGN_END
} supl_mmi_sign_enum;

/* This enum is used to indicate the direction. */
typedef enum
{
    SUPL_MMI_DIRECTION_HEIGHT,              /* Height */
    SUPL_MMI_DIRECTION_DEPTH,               /* Depth */
    SUPL_MMI_DIRECTION_END
} supl_mmi_direction_enum;

/* This enum is used to indicate the velocity type. */
typedef enum
{
    SUPL_MMI_VELOCITY_HOR,                  /* Horizontal Velocity: Bearing & Horizontal speed*/
    SUPL_MMI_VELOCITY_HOR_AND_VER,          /* Horizontal and Vertical Velocity: Vertical Direction & Bearing & Horizontal speed & Vertical speed */
    SUPL_MMI_VELOCITY_HOR_UNCERT,           /* Horizontal Velocity Uncertainty: Bearing & Horizontal speed & Horizontal speed uncertainty */
    SUPL_MMI_VELOCITY_HOR_AND_VER_UNCERT,   /* Horizontal and Vertical Velocity Uncertainty: Vertical direction & Bearing & Horizontal speed & Vertical speed & Horizontal speed uncertainty & Vertical speed uncertainty */
    SUPL_MMI_VELOCITY_END
} supl_mmi_velocity_type_enum;

typedef enum
{
    SUPL_SIM_ID_SIM1,                       /* = 0 */
    SUPL_SIM_ID_SIM2,                       /* = 1 */
    SUPL_SIM_ID_SIM3,                       /* = 2 */
    SUPL_SIM_ID_SIM4,                       /* = 3 */    
    SUPL_SIM_ID_TOTAL
} supl_sim_id_enum;


#endif /* SUPL2MMI_ENUMS_H */


