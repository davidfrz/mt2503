/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef __BT_FEATURE_H
#define __BT_FEATURE_H
//#define __BT_MAUI_PLATFORM__
#if defined(__BTMODULE_MT6601__)
#define __BT_CHIP_VERSION_0__
#else
#define __BT_CHIP_VERSION_1__
#endif

//#define __ENABLE_NUM_COMPLETED_PKT_EVENT_TIMER__
#if defined(__BTMODULE_MT6616__)
/* Turn on or off MTK_STP_SUPPORTED compile option here */
#if !defined (__MT6616_NO_STP__) && !defined (BTMTK_ON_LINUX)
#define __MTK_STP_SUPPORTED__
#endif /*__MT6616_NO_STP__*/
//#define __MTK_STP_SUPPORTED__
#elif defined(__BTMODULE_MT6620__)
#define __MTK_STP_SUPPORTED__
#define __BT_COMBO_ESCO__
#elif defined(__BT_BTWIFI_COMBO_CHIP__)
#define __MTK_STP_SUPPORTED__
#define __BT_COMBO_ESCO__
#endif

#define __BT_VER_21__

#ifndef __BT_VER_30__
#define __BT_VER_30__
#endif

#ifdef __BT_4_0_BLE__
//#define __BT_LE_STANDALONE__  /* ToDo */

#ifdef __BT_LE_STANDALONE__
//#define __BT_4_0_PRIVACY__
//#ifdef __BT_4_0_PRIVACY__
//#define __BT_4_0_ENABLE_SET_PRIVACY__
//#define __BT_4_0_PRIVACY_RECON_ADDR__
//#endif
#else
#define __BT_4_0_PRIVACY__
#define __BT_4_0_ACTIVE_SCAN__
#endif
#define __GATT_SERVICE_CHANGED_CHARACTERISTIC_SUPPORT__ //GATT Server, Open 20150102
#define ATT_ERR_RESPONSE_HANDLE_PATCH //add error response handle patch for MAUI_03524153, 20141126
#define __GATTC_SERVICE_CHANGED_SUPPORT__ //GATT Client, 20141228
#define __GATT_MEM_USE_ADM__ //use ADM buffer instead of control buffer, 20140116
#define __GATTS_SERVICE_SECURITY_CHECK__ //20150308
#define __GATT_MULTI_CONNECT_IND_PATCH__ //[MAUI_03532384]handle multi-connected indicate from controller, 20150329
#define __GAP_MULTI_CONNECT_IND_PATCH__ //[MAUI_03532384]handle multi-connected indicate from controller, 20150331
#endif

#ifdef __BT_VER_21__
#define __BT_2_1_AUTO_FLUSH__
#define __BT_2_1_SUPERVISION_TIMEOUT_EVENT__
#define __BT_2_1_ENABLED__
#define __BT_2_1_SNIFF_SUBRATING__
#define __BT_2_1_ENTENDED_INQUIRY_RESPONSE__
#define __BT_2_1_SIMPLE_PAIRING__
#endif /* __BT_VER_21__ */

#ifdef __BT_VER_30__
#define __BT_2_1_AUTO_FLUSH__
#define __BT_2_1_SUPERVISION_TIMEOUT_EVENT__
#define __BT_2_1_ENABLED__
#define __BT_2_1_SNIFF_SUBRATING__
#define __BT_2_1_ENTENDED_INQUIRY_RESPONSE__
#define __BT_2_1_SIMPLE_PAIRING__
#define __BT_2_1_ERTM__
#define __BT_3_0_UNICAST__
#endif

#define __BT_2_1_BLOCK_DEVICE__

#ifdef __BT_3_0_HS__
#if 1
#define __BT_2_1_AUTO_FLUSH__
#define __BT_2_1_SUPERVISION_TIMEOUT_EVENT__
#define __BT_2_1_ENABLED__
#define __BT_2_1_SNIFF_SUBRATING__
#define __BT_2_1_ENTENDED_INQUIRY_RESPONSE__
#define __BT_2_1_SIMPLE_PAIRING__
#define __BT_2_1_ERTM__
#define __BT_3_0_UNICAST__
#endif
#define L2CAP_EXTENDED_FLOW_SPEC       XA_ENABLED
#define L2CAP_ENHANCED_SELECTED_REJECT   XA_DISABLED /* DISABLE for MP*/
#define __BT_AMP_PAL_MESSAGE
#ifdef __BT_OBEX_TUNING__
#define __BT_30_DEBUG__ XA_DISABLED
#else
#define __BT_30_DEBUG__ XA_ENABLED
#endif
#endif




#define __BT_30_HS_INFINITE_SENT__

#ifdef BTMTK_ON_MAUI
#ifdef __BT_HFG_PROFILE__
#define __HF_V15__
#define __HF_WBS__
#define __HFG_BLOCK_SIMULTANEOUS_CONNECTION__
#define __ENABLE_HFG_SDP_CACHE__
//#define USE_EXT_AT_PARSER
#endif

#define __SDAP_REQUEST_QUEUE__
#define __SDAP_MODIFIED_SEARCH_ALL__
#define __SDP_EXIT_SNIFF_MODE__

//#define  __MTK_BT_DUAL_PCM_SWITCH_SUPPORT__

//#define __INDEPENDENT_INQUIRY_FLOW__

#define __ENABLE_MANUFACTURE_INFO__
#define __ANTI_LOST_FEATURE__

#if BT_MAX_LINK_NUM == 2
#define __A2DP_MULTI_LINK_FEATURE__
#endif

#define _BDADDR7_
#define __ANDROID_L_MIGRATION__

#endif  /* BTMTK_ON_MAUI */


//#define __BT_MP_RELEASE__
#endif /* __BT_FEATURE_H */
