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
 *   w32_dummy_gpsdrv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *  GPS Driver dummy functions for WIN32 environment
 *
 * Author:
 * -------
 * -------
 *
 ******************************************************************************/
#ifdef __GPS_SUPPORT__

#include "Mtk_gps_type.h"
#include "Mtk_type.h"
#include "mtk_gps.h"

mtk_int32 
mtk_gps_vrd_command(void *buff, const *str, int argu){return MTK_GPS_SUCCESS;}

mtk_gps_boot_status
mtk_gps_init(mtk_gps_start_type start_type, const mtk_init_cfg* default_cfg){return MNL_DSP_UART_INIT_ERR;}

mtk_int32
mtk_gps_update_gps_data(void){return MTK_GPS_ERROR;}

MTK_BEE_INT
MTK_BEE_Enable_Eph_Update(void){}

MTK_BEE_INT
MTK_BEE_Disable_Eph_Update(void){}

mtk_int32 
mtk_gps_nmea_input(const char* buffer, mtk_uint32 lenth){return MTK_GPS_SUCCESS;}

mtk_int32 
mtk_gps_set_AIC_mode(mtk_gps_aic_mode AIC_Enable){return MTK_GPS_SUCCESS;}


void
mtk_gps_uninit(void){}

mtk_int32
mtk_gps_set_param(mtk_gps_param key,const void * value){return MTK_GPS_SUCCESS;}

void
mtk_gps_time_change_notify(mtk_int32 i4RtcDiff){}

mtk_int32
mtk_gps_data_input(const char * buffer,mtk_uint32 length,mtk_uint32 * p_accepted_length){return MTK_GPS_SUCCESS;}

mtk_int32
mtk_gps_rtcm_input(const char * buffer,mtk_uint32 length){return MTK_GPS_SUCCESS;}

mtk_int32
mtk_gps_debug_config(mtk_gps_dbg_type DbgType,mtk_gps_dbg_level DbgLevel){return MTK_GPS_SUCCESS;}

MTK_BEE_VOID 
MTK_BEE_Shutdown(unsigned char fgEnableShutdown){}

MTK_BEE_VOID 
MTK_BEE_Init(void){}

MTK_BEE_INT
MTK_BEE_Set_File_Path(char szFilePath [ 256 ]){return 0;}

MTK_BEE_INT
MTK_BEE_Gen_Auto(short i2WeekNo,int i4Tow){return 1;}

mtk_int32
mtk_gps_set_time(mtk_uint16 weekno,double tow,float timeRMS){return MTK_GPS_SUCCESS;}

MTK_BEE_INT
MTK_BEE_Have_Enough_Eph(short i2WeekNo,int i4Tow){return 5;}

int
MTK_Bee_Receive_New_Eph_Ack(unsigned char SvId){return 0;}

MTK_BEE_VOID 
MTK_BEE_Proc_Eph(unsigned char u1SvId,unsigned int au4Word [ 24 ]){}

int
MTK_Bee_Get_New_Eph_Data(unsigned char * SvId,unsigned int EphData [ 24 ]){return 0;}

void
MTK_Bee_Receive_New_Eph_Host_Ready(void){}

int
MTK_Bee_Send_New_Eph(unsigned int * NewEphSv){return 0;}

void
MTK_Bee_Receive_End_Data(void){}

int
MTK_Bee_Receive_Bee_Data(char * BeeData){return 1;}

MTK_BEE_INT
MTK_BEE_Get_Data(unsigned char u1SvId,short i2WeekNo,int i4Tow,unsigned char BeeData [ 48 ]){return 1;}

int
MTK_Bee_Receive_Host_Info(int NumSv,unsigned char HostBeeInfo [ 32 ]){return 1;}

MTK_BEE_INT
MTK_BEE_Get_Available_Info(short i2WeekNo,int i4Tow,unsigned char BeeAvail [ 32 ]){return 1;}

void
MTK_Bee_Request_Data(unsigned char BeeReq [ 32 ]){}


int
mtk_gps_get_time(short* WeekNo, int* Tow){return 0;}

void
mtk_gps_debug_wrapper(int group){}

mtk_int32
mtk_gps_get_position(mtk_gps_position* pvt_data){return 0;}

mtk_int32
mtk_gps_get_lle_info(MTK_GPS_LLE_INFO_T *lle_info) {return 0;}

mtk_uint16 
mtk_gps_get_assistance_bitmap(void){return 0;}

void
epodownload_ssl_init_cntx(void){}

void 
epodownload_ssl_init(char *peer_cn){}

MTK_INT32 
epodownload_ssl_recv(MTK_INT8 s, void *buf, MTK_INT32 len, MTK_UINT8 flags){return 0;}

void 
epodownload_ssl_deinit(void){}

MTK_INT32 
epodownload_ssl_send_request (MTK_INT8 sock, MTK_INT32 epo_type){return 0;}

void 
epodownload_ssl_set_debug(MTK_INT32 need_debug){}

void 
epodownload_ssl_set_debug2(MTK_UINT8 *string){}

MTK_INT32
epodownload_ssl_get_state(void){return 0;}

void
epodownload_ssl_deinit_cntx(void){}

#endif

 

