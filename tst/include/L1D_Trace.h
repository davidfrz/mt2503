#ifndef L1TRC_L1D_PRI_DEF_H
#define L1TRC_L1D_PRI_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1C_Str_SM_Handler(v1)  (unsigned char)(v1+2)
#define L1D_Str_CCH(v1)  (unsigned char)(v1+6)
#define L1D_Str_AGPS(v1)  (unsigned char)(v1+9)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_DPTCHS0FLAGS(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_DPTCHS0FLAGS((unsigned short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1D_Trc_DPTCHS0FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_DPCCFLAG(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_DPCCFLAG((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1D_Trc_DPCCFLAG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_DPNB(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_DPNB((char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1D_Trc_DPNB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_DPGSMMODE(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_DPGSMMODE((unsigned short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1D_Trc_DPGSMMODE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_DPTXWIN0PROC(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_DPTXWIN0PROC((unsigned short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1D_Trc_DPTXWIN0PROC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_DPRXWIN0PROC(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_DPRXWIN0PROC((unsigned short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1D_Trc_DPRXWIN0PROC(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_D2CStopUL() do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_D2CStopUL();\
} while(0)
#else
	#define L1D_Trc_D2CStopUL()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_D2CFBFound() do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_D2CFBFound();\
} while(0)
#else
	#define L1D_Trc_D2CFBFound()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_SHARED2MCTL(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_SHARED2MCTL((unsigned short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1D_Trc_SHARED2MCTL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_SetChannelCmd(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_SetChannelCmd((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1D_Trc_SetChannelCmd(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_ReportPeriod(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_ReportPeriod((char)(v1), (char)(v2));\
} while(0)
#else
	#define L1D_Trc_ReportPeriod(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_FCChStage(v1) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_FCChStage((char)(v1));\
} while(0)
#else
	#define L1D_Trc_FCChStage(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_CipherCmd(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_CipherCmd((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1D_Trc_CipherCmd(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_CipherKey(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_CipherKey((unsigned short)(v1), (unsigned short)(v2), (unsigned short)(v3), (unsigned short)(v4), (unsigned short)(v5), (unsigned short)(v6));\
} while(0)
#else
	#define L1D_Trc_CipherKey(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_PDNCON2(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_PDNCON2((unsigned short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1D_Trc_PDNCON2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_BCCR(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_BCCR((unsigned short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1D_Trc_BCCR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_EVENA1(v1, v2, v3) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_EVENA1((unsigned char)(v1), (unsigned short)(v2), (unsigned short)(v3));\
} while(0)
#else
	#define L1D_Trc_EVENA1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_USF(v1, v2, v3, v4) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_USF((unsigned char)(v1), (short)(v2), (char)(v3), (short)(v4));\
} while(0)
#else
	#define L1D_Trc_USF(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_APC_VOLTTEMP(v1, v2, v3) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_APC_VOLTTEMP((char)(v1), (long)(v2), (long)(v3));\
} while(0)
#else
	#define L1D_Trc_APC_VOLTTEMP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_CCH_UL(v1) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_CCH_UL((unsigned char)(v1));\
} while(0)
#else
	#define L1D_Trc_CCH_UL(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_CCH_UL_DATA(v1, v2, v3, v4, v5) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_CCH_UL_DATA((unsigned char)(v1), (unsigned char)(v2), (unsigned short)(v3), (unsigned short)(v4), (unsigned short)(v5));\
} while(0)
#else
	#define L1D_Trc_CCH_UL_DATA(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_MaxTime(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_MaxTime((char)(v1), (short)(v2));\
} while(0)
#else
	#define L1D_Trc_MaxTime(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_DurMargin(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_DurMargin((short)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6));\
} while(0)
#else
	#define L1D_Trc_DurMargin(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1_Trace_sm1(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1_Trace_sm1((unsigned long)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1_Trace_sm1(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1_Trace_sm2(v1, v2, v3, v4, v5) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1_Trace_sm2((char)(v1), (char)(v2), (unsigned short)(v3), (unsigned short)(v4), (char)(v5));\
} while(0)
#else
	#define L1_Trace_sm2(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1_Trace_sm3(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1_Trace_sm3((unsigned char)(v1), (unsigned short)(v2), (unsigned short)(v3), (unsigned char)(v4), (short)(v5), (short)(v6));\
} while(0)
#else
	#define L1_Trace_sm3(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1_Trace_sm4(v1) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1_Trace_sm4((unsigned long)(v1));\
} while(0)
#else
	#define L1_Trace_sm4(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1_Trace_sm5(v1, v2, v3, v4, v5) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1_Trace_sm5((unsigned char)(v1), (unsigned long)(v2), (short)(v3), (unsigned long)(v4), (unsigned long)(v5));\
} while(0)
#else
	#define L1_Trace_sm5(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trace_FMResult(v1, v2, v3, v4) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1D_Trace_FMResult((unsigned char)(v1), (unsigned char)(v2), (unsigned long)(v3), (unsigned long)(v4));\
} while(0)
#else
	#define L1D_Trace_FMResult(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_AGPS_LCT_COUNTING(v1, v2, v3) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1D_AGPS_LCT_COUNTING((unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
} while(0)
#else
	#define L1D_AGPS_LCT_COUNTING(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_AGPS_REPORT(v1, v2, v3, v4) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1D_AGPS_REPORT((unsigned char)(v1), (char)(v2), (unsigned long)(v3), (unsigned long)(v4));\
} while(0)
#else
	#define L1D_AGPS_REPORT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_AGPS_FRC_PARAM(v1, v2, v3) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1D_AGPS_FRC_PARAM((unsigned long)(v1), (char)(v2), (unsigned long)(v3));\
} while(0)
#else
	#define L1D_AGPS_FRC_PARAM(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1D_PRI_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1D_Trc_DPTCHS0FLAGS(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_DPCCFLAG(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1D_Trc_DPNB(char v1, unsigned char v2);
void L1TRC_Send_L1D_Trc_DPGSMMODE(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_DPTXWIN0PROC(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_DPRXWIN0PROC(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_D2CStopUL(void);
void L1TRC_Send_L1D_Trc_D2CFBFound(void);
void L1TRC_Send_L1D_Trc_SHARED2MCTL(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_SetChannelCmd(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1D_Trc_ReportPeriod(char v1, char v2);
void L1TRC_Send_L1D_Trc_FCChStage(char v1);
void L1TRC_Send_L1D_Trc_CipherCmd(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1D_Trc_CipherKey(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_L1D_Trc_PDNCON2(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_BCCR(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_EVENA1(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1D_Trc_USF(unsigned char v1, short v2, char v3, short v4);
void L1TRC_Send_L1D_Trc_APC_VOLTTEMP(char v1, long v2, long v3);
void L1TRC_Send_L1D_Trc_CCH_UL(unsigned char v1);
void L1TRC_Send_L1D_Trc_CCH_UL_DATA(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_L1D_Trc_MaxTime(char v1, short v2);
void L1TRC_Send_L1D_Trc_DurMargin(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1_Trace_sm1(unsigned long v1, unsigned short v2);
void L1TRC_Send_L1_Trace_sm2(char v1, char v2, unsigned short v3, unsigned short v4, char v5);
void L1TRC_Send_L1_Trace_sm3(unsigned char v1, unsigned short v2, unsigned short v3, unsigned char v4, short v5, short v6);
void L1TRC_Send_L1_Trace_sm4(unsigned long v1);
void L1TRC_Send_L1_Trace_sm5(unsigned char v1, unsigned long v2, short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_L1D_Trace_FMResult(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1D_AGPS_LCT_COUNTING(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L1D_AGPS_REPORT(unsigned char v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1D_AGPS_FRC_PARAM(unsigned long v1, char v2, unsigned long v3);

void Set_L1D_PRI_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1D_PRI()	(L1D_PRI_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1D_PRI_L1D_DSP_COMMON_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_DSP_PROC_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_DSP_INT_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_DSP_INT_H()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_GET_CMD_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_FB_STAGE_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_CIPHER_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_UL_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_UL_CCH_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_UL_CCH_DATA_M()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_UL_CCH_DATA_H()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_MAX_TIME_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_MARGIN_H()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1D_PRI_SleepMode_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1D_PRI_FMCalibration_M()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_USF_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_APC_VOLTTEMP_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1D_PRI_L1D_AGPS_L()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1D_PRI_FMCalibration_H()	(ChkL1ModFltr_L1D_PRI()&&((L1D_PRI_Trace_Filter[3]&0x04)!=0))
#define ChkL1MsgFltr_L1D_Trc_DPTCHS0FLAGS()	ChkL1ClsFltr_L1D_PRI_L1D_DSP_COMMON_L()
#define ChkL1MsgFltr_L1D_Trc_DPCCFLAG()	ChkL1ClsFltr_L1D_PRI_L1D_DSP_COMMON_L()
#define ChkL1MsgFltr_L1D_Trc_DPNB()	ChkL1ClsFltr_L1D_PRI_L1D_DSP_COMMON_L()
#define ChkL1MsgFltr_L1D_Trc_DPGSMMODE()	ChkL1ClsFltr_L1D_PRI_L1D_DSP_PROC_L()
#define ChkL1MsgFltr_L1D_Trc_DPTXWIN0PROC()	ChkL1ClsFltr_L1D_PRI_L1D_DSP_PROC_L()
#define ChkL1MsgFltr_L1D_Trc_DPRXWIN0PROC()	ChkL1ClsFltr_L1D_PRI_L1D_DSP_PROC_L()
#define ChkL1MsgFltr_L1D_Trc_D2CStopUL()	ChkL1ClsFltr_L1D_PRI_L1D_DSP_INT_H()
#define ChkL1MsgFltr_L1D_Trc_D2CFBFound()	ChkL1ClsFltr_L1D_PRI_L1D_DSP_INT_L()
#define ChkL1MsgFltr_L1D_Trc_SHARED2MCTL()	ChkL1ClsFltr_L1D_PRI_L1D_DSP_INT_L()
#define ChkL1MsgFltr_L1D_Trc_SetChannelCmd()	ChkL1ClsFltr_L1D_PRI_L1D_GET_CMD_L()
#define ChkL1MsgFltr_L1D_Trc_ReportPeriod()	ChkL1ClsFltr_L1D_PRI_L1D_GET_CMD_L()
#define ChkL1MsgFltr_L1D_Trc_FCChStage()	ChkL1ClsFltr_L1D_PRI_L1D_FB_STAGE_L()
#define ChkL1MsgFltr_L1D_Trc_CipherCmd()	ChkL1ClsFltr_L1D_PRI_L1D_CIPHER_L()
#define ChkL1MsgFltr_L1D_Trc_CipherKey()	ChkL1ClsFltr_L1D_PRI_L1D_CIPHER_L()
#define ChkL1MsgFltr_L1D_Trc_PDNCON2()	ChkL1ClsFltr_L1D_PRI_L1D_CIPHER_L()
#define ChkL1MsgFltr_L1D_Trc_BCCR()	ChkL1ClsFltr_L1D_PRI_L1D_CIPHER_L()
#define ChkL1MsgFltr_L1D_Trc_EVENA1()	ChkL1ClsFltr_L1D_PRI_L1D_UL_L()
#define ChkL1MsgFltr_L1D_Trc_USF()	ChkL1ClsFltr_L1D_PRI_L1D_USF_L()
#define ChkL1MsgFltr_L1D_Trc_APC_VOLTTEMP()	ChkL1ClsFltr_L1D_PRI_L1D_APC_VOLTTEMP_L()
#define ChkL1MsgFltr_L1D_Trc_CCH_UL()	ChkL1ClsFltr_L1D_PRI_L1D_UL_CCH_L()
#define ChkL1MsgFltr_L1D_Trc_CCH_UL_DATA()	ChkL1ClsFltr_L1D_PRI_L1D_UL_CCH_DATA_H()
#define ChkL1MsgFltr_L1D_Trc_MaxTime()	ChkL1ClsFltr_L1D_PRI_L1D_MAX_TIME_L()
#define ChkL1MsgFltr_L1D_Trc_DurMargin()	ChkL1ClsFltr_L1D_PRI_L1D_MARGIN_H()
#define ChkL1MsgFltr_L1_Trace_sm1()	ChkL1ClsFltr_L1D_PRI_SleepMode_L()
#define ChkL1MsgFltr_L1_Trace_sm2()	ChkL1ClsFltr_L1D_PRI_SleepMode_L()
#define ChkL1MsgFltr_L1_Trace_sm3()	ChkL1ClsFltr_L1D_PRI_SleepMode_L()
#define ChkL1MsgFltr_L1_Trace_sm4()	ChkL1ClsFltr_L1D_PRI_SleepMode_L()
#define ChkL1MsgFltr_L1_Trace_sm5()	ChkL1ClsFltr_L1D_PRI_SleepMode_L()
#define ChkL1MsgFltr_L1D_Trace_FMResult()	ChkL1ClsFltr_L1D_PRI_FMCalibration_H()
#define ChkL1MsgFltr_L1D_AGPS_LCT_COUNTING()	ChkL1ClsFltr_L1D_PRI_L1D_AGPS_L()
#define ChkL1MsgFltr_L1D_AGPS_REPORT()	ChkL1ClsFltr_L1D_PRI_L1D_AGPS_L()
#define ChkL1MsgFltr_L1D_AGPS_FRC_PARAM()	ChkL1ClsFltr_L1D_PRI_L1D_AGPS_L()


#endif
