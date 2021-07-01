#ifndef L1TRC_L1C_GPRS_DEF_H
#define L1TRC_L1C_GPRS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1C_Str_GPRS_DL_CtrlMsg(v1)  (unsigned char)(v1+2)
#define L1C_Str_UplinkAccessMode(v1)  (unsigned char)(v1+58)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_ReportPBCCh(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPBCCh((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_ReportPBCCh(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_ReportNPBCCh(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1C_Trace_ReportNPBCCh((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_ReportNPBCCh(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_ReportPPCh(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPPCh((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Trace_ReportPPCh(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportPTCChDown(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPTCChDown((unsigned char)(v1), (unsigned char)(v2), (char)(v3));\
} while(0)
#else
	#define L1C_Trace_ReportPTCChDown(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_woRRBP_woFBI(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_woFBI((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1C_Trace_PDTChGood_woRRBP_woFBI(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_woRRBP_wFBI(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_wFBI((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1C_Trace_PDTChGood_woRRBP_wFBI(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_wRRBP_woFBI(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_woFBI((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6));\
} while(0)
#else
	#define L1C_Trace_PDTChGood_wRRBP_woFBI(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_wRRBP_wFBI(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_wFBI((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6));\
} while(0)
#else
	#define L1C_Trace_PDTChGood_wRRBP_wFBI(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_Ctrl(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_Ctrl((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1C_Trace_PDTChGood_Ctrl(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_Dummy_Ctrl(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_Dummy_Ctrl((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Trace_PDTChGood_Dummy_Ctrl(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportPDTChBad(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPDTChBad((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Trace_ReportPDTChBad(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_Trace_TBFStart((unsigned char)(v1), (unsigned long)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7));\
} while(0)
#else
	#define L1C_Trace_TBFStart(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_ReportIM(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_ReportIM((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_ReportIM(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_ReportIMPower(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_ReportIMPower((unsigned char)(v1), (char)(v2), (short)(v3));\
} while(0)
#else
	#define L1C_Trace_ReportIMPower(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_ReportPAGCh(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPAGCh((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_ReportPAGCh(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportSingleDL(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Trace_ReportSingleDL((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_ReportSingleDL(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportPACCh(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPACCh((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_ReportPACCh(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportPACCh_Ctrl(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPACCh_Ctrl((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_ReportPACCh_Ctrl(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupPBCCh(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPBCCh((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1C_Msg_SetupPBCCh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupPPCh(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPPCh((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4));\
} while(0)
#else
	#define L1C_Msg_SetupPPCh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartPAGCh(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_StartPAGCh((unsigned char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1C_Msg_StartPAGCh(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupPRACh(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPRACh((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4));\
} while(0)
#else
	#define L1C_Msg_SetupPRACh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_StartPollRespAB(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_StartPollRespAB((unsigned char)(v1), (long)(v2), (char)(v3));\
} while(0)
#else
	#define L1C_Msg_StartPollRespAB(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_StartPollRespNB(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_StartPollRespNB((unsigned char)(v1), (long)(v2), (char)(v3));\
} while(0)
#else
	#define L1C_Msg_StartPollRespNB(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_StartSingleULwoTBF(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_StartSingleULwoTBF((unsigned char)(v1), (long)(v2), (char)(v3));\
} while(0)
#else
	#define L1C_Msg_StartSingleULwoTBF(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_StartSingleDL(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_StartSingleDL((unsigned char)(v1), (long)(v2), (char)(v3), (char)(v4));\
} while(0)
#else
	#define L1C_Msg_StartSingleDL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_StartULTwoPhase(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_StartULTwoPhase((unsigned char)(v1), (long)(v2), (char)(v3), (char)(v4));\
} while(0)
#else
	#define L1C_Msg_StartULTwoPhase(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartIM(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_StartIM((unsigned char)(v1), (char)(v2));\
} while(0)
#else
	#define L1C_Msg_StartIM(v1, v2)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1C_GPRS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Trace_ReportPBCCh(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportNPBCCh(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportPPCh(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_ReportPTCChDown(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_woFBI(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_wFBI(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_woFBI(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5, char v6);
void L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_wFBI(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5, char v6);
void L1TRC_Send_L1C_Trace_PDTChGood_Ctrl(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Trace_PDTChGood_Dummy_Ctrl(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_ReportPDTChBad(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_TBFStart(unsigned char v1, unsigned long v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_L1C_Trace_ReportIM(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportIMPower(unsigned char v1, char v2, short v3);
void L1TRC_Send_L1C_Trace_ReportPAGCh(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportSingleDL(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportPACCh(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportPACCh_Ctrl(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_SetupPBCCh(unsigned char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_L1C_Msg_SetupPPCh(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_StartPAGCh(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_SetupPRACh(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_StartPollRespAB(unsigned char v1, long v2, char v3);
void L1TRC_Send_L1C_Msg_StartPollRespNB(unsigned char v1, long v2, char v3);
void L1TRC_Send_L1C_Msg_StartSingleULwoTBF(unsigned char v1, long v2, char v3);
void L1TRC_Send_L1C_Msg_StartSingleDL(unsigned char v1, long v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_StartULTwoPhase(unsigned char v1, long v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_StartIM(unsigned char v1, char v2);

void Set_L1C_GPRS_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1C_GPRS()	(L1C_GPRS_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1C_GPRS_ReportPBCCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportNPBCCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportPPCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportPTCCh_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GPRS_L1T_TBFStart_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportPAGCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportSingleDL_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportULTwoPhase_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GPRS_SetupPBCCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GPRS_SetupPPCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartPAGCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GPRS_SetupPRACh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartPollResp_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartSingleUL_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartSingleDL_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartULTwoPhase_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartIM_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportIM_L()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[3]&0x04)!=0))
#define ChkL1MsgFltr_L1C_Trace_ReportPBCCh()	ChkL1ClsFltr_L1C_GPRS_ReportPBCCh_M()
#define ChkL1MsgFltr_L1C_Trace_ReportNPBCCh()	ChkL1ClsFltr_L1C_GPRS_ReportNPBCCh_M()
#define ChkL1MsgFltr_L1C_Trace_ReportPPCh()	ChkL1ClsFltr_L1C_GPRS_ReportPPCh_M()
#define ChkL1MsgFltr_L1C_Trace_ReportPTCChDown()	ChkL1ClsFltr_L1C_GPRS_ReportPTCCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_woRRBP_woFBI()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_woRRBP_wFBI()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_wRRBP_woFBI()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_wRRBP_wFBI()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_Ctrl()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_Dummy_Ctrl()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_ReportPDTChBad()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_TBFStart()	ChkL1ClsFltr_L1C_GPRS_L1T_TBFStart_M()
#define ChkL1MsgFltr_L1C_Trace_ReportIM()	ChkL1ClsFltr_L1C_GPRS_ReportIM_L()
#define ChkL1MsgFltr_L1C_Trace_ReportIMPower()	ChkL1ClsFltr_L1C_GPRS_ReportIM_L()
#define ChkL1MsgFltr_L1C_Trace_ReportPAGCh()	ChkL1ClsFltr_L1C_GPRS_ReportPAGCh_M()
#define ChkL1MsgFltr_L1C_Trace_ReportSingleDL()	ChkL1ClsFltr_L1C_GPRS_ReportSingleDL_H()
#define ChkL1MsgFltr_L1C_Trace_ReportPACCh()	ChkL1ClsFltr_L1C_GPRS_ReportULTwoPhase_H()
#define ChkL1MsgFltr_L1C_Trace_ReportPACCh_Ctrl()	ChkL1ClsFltr_L1C_GPRS_ReportULTwoPhase_H()
#define ChkL1MsgFltr_L1C_Msg_SetupPBCCh()	ChkL1ClsFltr_L1C_GPRS_SetupPBCCh_M()
#define ChkL1MsgFltr_L1C_Msg_SetupPPCh()	ChkL1ClsFltr_L1C_GPRS_SetupPPCh_M()
#define ChkL1MsgFltr_L1C_Msg_StartPAGCh()	ChkL1ClsFltr_L1C_GPRS_StartPAGCh_M()
#define ChkL1MsgFltr_L1C_Msg_SetupPRACh()	ChkL1ClsFltr_L1C_GPRS_SetupPRACh_M()
#define ChkL1MsgFltr_L1C_Msg_StartPollRespAB()	ChkL1ClsFltr_L1C_GPRS_StartPollResp_H()
#define ChkL1MsgFltr_L1C_Msg_StartPollRespNB()	ChkL1ClsFltr_L1C_GPRS_StartPollResp_H()
#define ChkL1MsgFltr_L1C_Msg_StartSingleULwoTBF()	ChkL1ClsFltr_L1C_GPRS_StartSingleUL_H()
#define ChkL1MsgFltr_L1C_Msg_StartSingleDL()	ChkL1ClsFltr_L1C_GPRS_StartSingleDL_H()
#define ChkL1MsgFltr_L1C_Msg_StartULTwoPhase()	ChkL1ClsFltr_L1C_GPRS_StartULTwoPhase_H()
#define ChkL1MsgFltr_L1C_Msg_StartIM()	ChkL1ClsFltr_L1C_GPRS_StartIM_M()


#endif
