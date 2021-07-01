#ifndef L1TRC_L1D_SEC_DEF_H
#define L1TRC_L1D_SEC_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_AFC_REASON_STR(v1)  (unsigned char)(v1+0)
#define L1D_Str_Bool(v1)  (unsigned char)(v1+15)
#define L1I_DCM_status_STR(v1)  (unsigned char)(v1+17)
#define L1D_Str_PM_Mode(v1)  (unsigned char)(v1+19)
#define L1D_ExecuteTime_Type(v1)  (unsigned char)(v1+24)
#define L1D_Debug_Type(v1)  (unsigned char)(v1+26)
#define L1D_Trc_Str_FCCh_Start_Type(v1)  (unsigned char)(v1+28)
#define L1D_Trc_Str_FH_CLK(v1)  (unsigned char)(v1+35)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER)
	#define L1I_Msg_AFC_Assert_Reason(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_Assert_Reason((unsigned char)(v1));\
} while(0)
#else
	#define L1I_Msg_AFC_Assert_Reason(v1)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_AFC_TQ_TIME(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_TQ_TIME((short)(v1), (short)(v2));\
} while(0)
#else
	#define L1I_Msg_AFC_TQ_TIME(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_AFC_Assert34(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_Assert34((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1I_Msg_AFC_Assert34(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_AFC_Tid_MisMatch(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_Tid_MisMatch((unsigned char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Msg_AFC_Tid_MisMatch(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1D_SB_Status_Extend(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1D_SB_Status_Extend((unsigned char)(v1), (short)(v2), (unsigned char)(v3), (short)(v4), (short)(v5), (char)(v6), (short)(v7), (short)(v8), (unsigned char)(v9), (unsigned char)(v10));\
} while(0)
#else
	#define L1D_SB_Status_Extend(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_HIGHSNR_BADBLOCK() do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_HIGHSNR_BADBLOCK();\
} while(0)
#else
	#define L1D_Trc_HIGHSNR_BADBLOCK()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_SP_flag(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_SP_flag((short)(v1));\
} while(0)
#else
	#define L1D_SP_flag(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_SP_flag_Fsig_no_data_tx(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_SP_flag_Fsig_no_data_tx((short)(v1));\
} while(0)
#else
	#define L1D_SP_flag_Fsig_no_data_tx(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_DCM_status(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1I_DCM_status((unsigned char)(v1));\
} while(0)
#else
	#define L1I_DCM_status(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_PCH_OK_AT_STATE(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1D_PCH_OK_AT_STATE((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1D_PCH_OK_AT_STATE(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_CCCH_OK_AT_STATE(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1D_CCCH_OK_AT_STATE((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1D_CCCH_OK_AT_STATE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_PCH_One_Burst_Enable(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_PCH_One_Burst_Enable((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1D_PCH_One_Burst_Enable(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_PCH_Null_Detect(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_PCH_Null_Detect((unsigned char)(v1));\
} while(0)
#else
	#define L1D_PCH_Null_Detect(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_PCH_Empty_Detect(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_PCH_Empty_Detect((unsigned char)(v1));\
} while(0)
#else
	#define L1D_PCH_Empty_Detect(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_PCH_Pattern(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1D_PCH_Pattern((unsigned char)(v1), (unsigned char)(v2), (unsigned short)(v3), (unsigned short)(v4), (unsigned short)(v5), (unsigned short)(v6), (unsigned short)(v7), (unsigned short)(v8));\
} while(0)
#else
	#define L1D_PCH_Pattern(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_TRC_PM(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1D_TRC_PM((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1D_TRC_PM(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_DP6TapEQStatus(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_DP6TapEQStatus((unsigned short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1D_Trc_DP6TapEQStatus(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_DSP_WATCH_DOG(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1D_DSP_WATCH_DOG((char)(v1), (short)(v2));\
} while(0)
#else
	#define L1D_DSP_WATCH_DOG(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_DSP_RX_FILTER(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1D_DSP_RX_FILTER((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1D_DSP_RX_FILTER(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_CD2nd_CRC_Pass(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_CD2nd_CRC_Pass((unsigned char)(v1), (char)(v2), (unsigned short)(v3));\
} while(0)
#else
	#define L1D_Trc_CD2nd_CRC_Pass(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_Tx_ARFCN_TA(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_Tx_ARFCN_TA((unsigned char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_Trc_Tx_ARFCN_TA(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_Timing_Check_Fail_v1(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_Timing_Check_Fail_v1((unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
} while(0)
#else
	#define L1D_Trc_Timing_Check_Fail_v1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_Timing_Check_Fail_v2(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_Timing_Check_Fail_v2((unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
} while(0)
#else
	#define L1D_Trc_Timing_Check_Fail_v2(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_Execute_Timing_Check(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_Execute_Timing_Check((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1D_Trc_Execute_Timing_Check(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_DSP_PM_Not_Done(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[4]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_DSP_PM_Not_Done((unsigned short)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_Trc_DSP_PM_Not_Done(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_AFC_DAC_Data(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_AFC_DAC_Data((char)(v1), (short)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1D_Trc_AFC_DAC_Data(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_MPLL_FH(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_MPLL_FH((unsigned char)(v1), (short)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (short)(v7), (unsigned long)(v8));\
} while(0)
#else
	#define L1D_Trc_MPLL_FH(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_LCD_Collision(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_LCD_Collision((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (short)(v4), (short)(v5), (short)(v6));\
} while(0)
#else
	#define L1D_Trc_LCD_Collision(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_FCCh_Start(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[4]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_FCCh_Start((unsigned char)(v1), (short)(v2), (unsigned char)(v3), (long)(v4));\
} while(0)
#else
	#define L1D_Trc_FCCh_Start(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_FCCh_Stop(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[4]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_FCCh_Stop((unsigned char)(v1), (short)(v2), (short)(v3), (char)(v4));\
} while(0)
#else
	#define L1D_Trc_FCCh_Stop(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_FB_False_Alarm(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[4]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_FB_False_Alarm((unsigned char)(v1), (short)(v2), (char)(v3), (short)(v4), (short)(v5), (short)(v6));\
} while(0)
#else
	#define L1D_Trc_FB_False_Alarm(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_TXPC(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_TXPC((unsigned char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_Trc_TXPC(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1D_SEC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Msg_AFC_Assert_Reason(unsigned char v1);
void L1TRC_Send_L1I_Msg_AFC_TQ_TIME(short v1, short v2);
void L1TRC_Send_L1I_Msg_AFC_Assert34(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Msg_AFC_Tid_MisMatch(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1D_SB_Status_Extend(unsigned char v1, short v2, unsigned char v3, short v4, short v5, char v6, short v7, short v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_L1D_Trc_HIGHSNR_BADBLOCK(void);
void L1TRC_Send_L1D_SP_flag(short v1);
void L1TRC_Send_L1D_SP_flag_Fsig_no_data_tx(short v1);
void L1TRC_Send_L1I_DCM_status(unsigned char v1);
void L1TRC_Send_L1D_PCH_OK_AT_STATE(unsigned char v1, short v2);
void L1TRC_Send_L1D_CCCH_OK_AT_STATE(unsigned char v1, short v2);
void L1TRC_Send_L1D_PCH_One_Burst_Enable(unsigned char v1, short v2);
void L1TRC_Send_L1D_PCH_Null_Detect(unsigned char v1);
void L1TRC_Send_L1D_PCH_Empty_Detect(unsigned char v1);
void L1TRC_Send_L1D_PCH_Pattern(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8);
void L1TRC_Send_L1D_TRC_PM(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1D_Trc_DP6TapEQStatus(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_DSP_WATCH_DOG(char v1, short v2);
void L1TRC_Send_L1D_DSP_RX_FILTER(unsigned char v1, short v2);
void L1TRC_Send_L1D_Trc_CD2nd_CRC_Pass(unsigned char v1, char v2, unsigned short v3);
void L1TRC_Send_L1D_Trc_Tx_ARFCN_TA(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_Timing_Check_Fail_v1(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1D_Trc_Timing_Check_Fail_v2(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L1D_Trc_Execute_Timing_Check(unsigned char v1, short v2);
void L1TRC_Send_L1D_Trc_DSP_PM_Not_Done(unsigned short v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_AFC_DAC_Data(char v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_Trc_MPLL_FH(unsigned char v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, short v7, unsigned long v8);
void L1TRC_Send_L1D_Trc_LCD_Collision(unsigned char v1, unsigned char v2, unsigned char v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_Trc_FCCh_Start(unsigned char v1, short v2, unsigned char v3, long v4);
void L1TRC_Send_L1D_Trc_FCCh_Stop(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_L1D_Trc_FB_False_Alarm(unsigned char v1, short v2, char v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_Trc_TXPC(unsigned char v1, short v2, short v3);

void Set_L1D_SEC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1D_SEC()	(L1D_SEC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1D_SEC_AFCdebug_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_SB_Extend_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_GPRS_State_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1D_SEC_SP_flag_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1D_SEC_DCM_debug_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_PCH_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_PM_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_DSP_COMMON2_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_DSP_FILTER_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_CD_2nd_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1D_SEC_Tx_ARFCN_TA_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1D_SEC_FB_Search_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_Timing_Check_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1D_SEC_PM_DONE_CHECK_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1D_SEC_AFC_DAC_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_MPLL_FH_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_TXPC_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1D_SEC_AFCdebug_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_SB_Extend_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_PCH_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_DSP_FILTER_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_CD_2nd_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_L1D_SEC_Tx_ARFCN_TA_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_Timing_Check_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_L1D_SEC_PM_DONE_CHECK_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_L1D_SEC_FB_Search_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[4]&0x02)!=0))
#define ChkL1MsgFltr_L1I_Msg_AFC_Assert_Reason()	ChkL1ClsFltr_L1D_SEC_AFCdebug_H()
#define ChkL1MsgFltr_L1I_Msg_AFC_TQ_TIME()	ChkL1ClsFltr_L1D_SEC_AFCdebug_H()
#define ChkL1MsgFltr_L1I_Msg_AFC_Assert34()	ChkL1ClsFltr_L1D_SEC_AFCdebug_H()
#define ChkL1MsgFltr_L1I_Msg_AFC_Tid_MisMatch()	ChkL1ClsFltr_L1D_SEC_AFCdebug_H()
#define ChkL1MsgFltr_L1D_SB_Status_Extend()	ChkL1ClsFltr_L1D_SEC_L1D_SB_Extend_H()
#define ChkL1MsgFltr_L1D_Trc_HIGHSNR_BADBLOCK()	ChkL1ClsFltr_L1D_SEC_L1D_GPRS_State_L()
#define ChkL1MsgFltr_L1D_SP_flag()	ChkL1ClsFltr_L1D_SEC_SP_flag_L()
#define ChkL1MsgFltr_L1D_SP_flag_Fsig_no_data_tx()	ChkL1ClsFltr_L1D_SEC_SP_flag_L()
#define ChkL1MsgFltr_L1I_DCM_status()	ChkL1ClsFltr_L1D_SEC_DCM_debug_L()
#define ChkL1MsgFltr_L1D_PCH_OK_AT_STATE()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_H()
#define ChkL1MsgFltr_L1D_CCCH_OK_AT_STATE()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_H()
#define ChkL1MsgFltr_L1D_PCH_One_Burst_Enable()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_M()
#define ChkL1MsgFltr_L1D_PCH_Null_Detect()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_M()
#define ChkL1MsgFltr_L1D_PCH_Empty_Detect()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_M()
#define ChkL1MsgFltr_L1D_PCH_Pattern()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_H()
#define ChkL1MsgFltr_L1D_TRC_PM()	ChkL1ClsFltr_L1D_SEC_L1D_PM_M()
#define ChkL1MsgFltr_L1D_Trc_DP6TapEQStatus()	ChkL1ClsFltr_L1D_SEC_L1D_DSP_COMMON2_L()
#define ChkL1MsgFltr_L1D_DSP_WATCH_DOG()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_H()
#define ChkL1MsgFltr_L1D_DSP_RX_FILTER()	ChkL1ClsFltr_L1D_SEC_L1D_DSP_FILTER_H()
#define ChkL1MsgFltr_L1D_Trc_CD2nd_CRC_Pass()	ChkL1ClsFltr_L1D_SEC_L1D_CD_2nd_H()
#define ChkL1MsgFltr_L1D_Trc_Tx_ARFCN_TA()	ChkL1ClsFltr_L1D_SEC_Tx_ARFCN_TA_H()
#define ChkL1MsgFltr_L1D_Trc_Timing_Check_Fail_v1()	ChkL1ClsFltr_L1D_SEC_L1D_Timing_Check_H()
#define ChkL1MsgFltr_L1D_Trc_Timing_Check_Fail_v2()	ChkL1ClsFltr_L1D_SEC_L1D_Timing_Check_H()
#define ChkL1MsgFltr_L1D_Trc_Execute_Timing_Check()	ChkL1ClsFltr_L1D_SEC_L1D_Timing_Check_H()
#define ChkL1MsgFltr_L1D_Trc_DSP_PM_Not_Done()	ChkL1ClsFltr_L1D_SEC_PM_DONE_CHECK_H()
#define ChkL1MsgFltr_L1D_Trc_AFC_DAC_Data()	ChkL1ClsFltr_L1D_SEC_AFC_DAC_L()
#define ChkL1MsgFltr_L1D_Trc_MPLL_FH()	ChkL1ClsFltr_L1D_SEC_L1D_MPLL_FH_L()
#define ChkL1MsgFltr_L1D_Trc_LCD_Collision()	ChkL1ClsFltr_L1D_SEC_L1D_MPLL_FH_L()
#define ChkL1MsgFltr_L1D_Trc_FCCh_Start()	ChkL1ClsFltr_L1D_SEC_FB_Search_H()
#define ChkL1MsgFltr_L1D_Trc_FCCh_Stop()	ChkL1ClsFltr_L1D_SEC_FB_Search_H()
#define ChkL1MsgFltr_L1D_Trc_FB_False_Alarm()	ChkL1ClsFltr_L1D_SEC_FB_Search_H()
#define ChkL1MsgFltr_L1D_Trc_TXPC()	ChkL1ClsFltr_L1D_SEC_L1D_TXPC_L()


#endif
