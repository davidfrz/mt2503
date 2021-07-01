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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   kmp.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   kmp related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*---------------TCPIP_MSG_CODE_BEGIN---------------------------*/    
#ifdef __BUILD_DOM__
/***********************************
* <GROUP  Messages>        
*
* ike sap primitive
 ********************************/
typedef enum {
#endif


    MSG_ID_APP_KMP_INIT_REQ = MSG_ID_KMP_CODE_BEGIN,  /*initiate kmp request

                                                                                                      Direction: MOD_MMI->MOD_KMP_APP
                                                                                                      Local parameter: app_kmp_init_req_struct
                                                                                                      Peer buffer: null
                                                                                                    */

    MSG_ID_APP_KMP_INIT_CNF,   /*initiate confrim

                                                          Direction: MOD_KMP_APP->MOD_MMI
                                                          Local parameter: app_kmp_init_cnf_struct
                                                          Peer buffer: null
                                                       */    
    MSG_ID_APP_KMP_ALG_REQ,  /*algorithm request

                                                        Direction:MOD_MMI->MOD_KMP_APP
                                                        Local parameter: app_kmp_alg_req_struct
                                                        Peer buffer: null
                                                     */
    MSG_ID_APP_KMP_ALG_CNF,  /*algorithm confirm

                                                        Direction: MOD_KMP_APP->MOD_MMI
                                                        Local parameter: app_kmp_alg_cnf_struct
                                                        Peer buffer: null
                                                     */    
    MSG_ID_APP_KMP_ADDR_REQ,  /*address request

                                                          Direction: MOD_MMI->MOD_KMP_APP
                                                          Local parameter: app_kmp_addr_req_struct
                                                          Peer buffer: null
                                                       */    
    MSG_ID_APP_KMP_ADDR_CNF,   /*address confirm

                                                            Direction: MOD_KMP_APP->MOD_MMI
                                                            Local parameter: app_kmp_addr_cnf_struct
                                                            Peer buffer: null
                                                          */    
    MSG_ID_APP_KMP_ACTIVE_REQ,  /*active request

                                                              Direction:MOD_MMI->MOD_KMP_APP
                                                              Local parameter: app_kmp_active_req_struct
                                                              Peer buffer: null
                                                           */    
    MSG_ID_APP_KMP_ACTIVE_CNF,  /*active confirm

                                                              Direction:MOD_KMP_APP->MOD_MMI
                                                              Local parameter: app_kmp_active_cnf_struct
                                                              Peer buffer: xxx
                                                           */    
    MSG_ID_APP_KMP_POLICY_ADD_REQ,  /*policy address request

                                                                       Direction:MOD_MMI->MOD_KMP_APP
                                                                       Local parameter: app_kmp_policy_add_req_struct
                                                                       Peer buffer: null
                                                                    */    
    MSG_ID_APP_KMP_POLICY_ADD_CNF,  /*policy address confirm

                                                                      Direction:MOD_KMP_APP->MOD_MMI
                                                                      Local parameter: app_kmp_policy_add_cnf_struct
                                                                      Peer buffer: null
                                                                    */    
    MSG_ID_APP_KMP_POLICY_DEL_REQ,  /*policy delete request

                                                                      Direction:MOD_MMI->MOD_KMP_APP
                                                                      Local parameter: app_kmp_policy_del_req_struct
                                                                      Peer buffer: null
                                                                    */    
    MSG_ID_APP_KMP_POLICY_DEL_CNF,  /*policy delete confirm

                                                                      Direction:MOD_KMP_APP->MOD_MMI
                                                                      Local parameter: app_kmp_policy_del_cnf_struct
                                                                      Peer buffer: null
                                                                    */
    MSG_ID_APP_KMP_DEACTIVE_REQ,  /*policy deactive request

                                                                Direction:MOD_MMI->MOD_KMP_APP
                                                                Local parameter: app_kmp_deactive_req_struct
                                                                Peer buffer: null
                                                              */    
    MSG_ID_APP_KMP_DEACTIVE_CNF,    /*policy deactive confirm

                                                                    Direction:MOD_KMP_APP->MOD_MMI
                                                                    Local parameter: app_kmp_deactive_cnf_struct
                                                                    Peer buffer: null
                                                                  */   
                                
    MSG_ID_IKE_TCPIP_WRITE_REQ,  /*ike write data to tcpip

                                                               Direction:MOD_KMP_APP->MOD_TCPIP
                                                               Local parameter: ike_tcpip_write_req_strut
                                                               Peer buffer: null
                                                             */    
    MSG_ID_IKE_TCPIP_READ_REQ,  /*ike read data from tcpip

                                                              Direction:MOD_KMP_APP->MOD_TCPIP
                                                              Local parameter: ike_tcpip_read_req_struct
                                                              Peer buffer: null
                                                            */    
    MSG_ID_TCPIP_IKE_SEND_DATA_REQ,  /*tcpip send data to tcpip

                                                                       Direction:MOD_KMP_APP->MOD_TCPIP
                                                                       Local parameter: tcpip_ike_data_ind_struct
                                                                       Peer buffer: null
                                                                     */
/* DOM-NOT_FOR_SDK-BEGIN */                                        
    MSG_ID_IKE_SEND_TEST_REQ,  /*not used*/
                               /*description

                                 Direction:xxx
                                 Local parameter:xxx
                                 Peer buffer: xxx
                               */
    MSG_ID_IKE_SETTING_OK_REQ,  /*internal use*/
                                /*description

                                  Direction:xxx
                                  Local parameter:xxx
                                  Peer buffer: xxx
                                */    
/* DOM-NOT_FOR_SDK-END */
        		
    MSG_ID_KMP_CODE_END = MSG_ID_IKE_SETTING_OK_REQ,  /*end of enum*/
        		
    #ifdef __BUILD_DOM__
} kmp_sap_enum;
#endif
/*---------------TCPIP_MSG_CODE_END---------------------------*/

