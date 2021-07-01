#ifndef L1TRC_L1D_EDGE_DEF_H
#define L1TRC_L1D_EDGE_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1D_Str_FBM_PROC(v1)  (unsigned char)(v1+0)
#define L1D_Str_RTTI(v1)  (unsigned char)(v1+8)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_DelayCD(v1) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_DelayCD((short)(v1));\
} while(0)
#else
	#define L1D_Trc_DelayCD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_PTCCH_CD_TOGETHER() do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_PTCCH_CD_TOGETHER();\
} while(0)
#else
	#define L1D_Trc_PTCCH_CD_TOGETHER()
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_USF_Status(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_USF_Status((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1D_Trc_USF_Status(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1D_USF_Modtype(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x20)!=0 )\
			L1TRC_Send_L1D_USF_Modtype((char)(v1), (short)(v2), (short)(v3), (char)(v4));\
} while(0)
#else
	#define L1D_USF_Modtype(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1D_USF_3R_Status(v1, v2, v3) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x20)!=0 )\
			L1TRC_Send_L1D_USF_3R_Status((unsigned long)(v1), (unsigned short)(v2), (unsigned short)(v3));\
} while(0)
#else
	#define L1D_USF_3R_Status(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_DSP_Mod_type(v1, v2) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1D_DSP_Mod_type((unsigned short)(v1), (short)(v2));\
} while(0)
#else
	#define L1D_DSP_Mod_type(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_DSP_REPORT_D_VALUE(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x40)!=0 )\
			L1TRC_Send_L1D_DSP_REPORT_D_VALUE((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6));\
} while(0)
#else
	#define L1D_DSP_REPORT_D_VALUE(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_DSP_SRB_MACHINE(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1D_DSP_SRB_MACHINE((short)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5));\
} while(0)
#else
	#define L1D_DSP_SRB_MACHINE(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_USF_Dummy_Detect(v1) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_USF_Dummy_Detect((short)(v1));\
} while(0)
#else
	#define L1D_USF_Dummy_Detect(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_TX_AFC_Dac(v1, v2, v3) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x80)!=0 )\
			L1TRC_Send_L1D_TX_AFC_Dac((unsigned char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_TX_AFC_Dac(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_IGain_Update(v1, v2) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_IGain_Update((long)(v1), (long)(v2));\
} while(0)
#else
	#define L1D_IGain_Update(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_IGain_NewGain(v1) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_IGain_NewGain((short)(v1));\
} while(0)
#else
	#define L1D_IGain_NewGain(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Rxiq_Phase_Update(v1, v2) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_Rxiq_Phase_Update((long)(v1), (long)(v2));\
} while(0)
#else
	#define L1D_Rxiq_Phase_Update(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Rxiq_NewPhase(v1) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_Rxiq_NewPhase((short)(v1));\
} while(0)
#else
	#define L1D_Rxiq_NewPhase(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_CTIRQ_PRE_EQ(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[4]&0x01)!=0 )\
			L1TRC_Send_L1D_CTIRQ_PRE_EQ((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (unsigned short)(v5));\
} while(0)
#else
	#define L1D_CTIRQ_PRE_EQ(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1D_CTIRQ_POST_EQ(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[4]&0x01)!=0 )\
			L1TRC_Send_L1D_CTIRQ_POST_EQ((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (unsigned short)(v5));\
} while(0)
#else
	#define L1D_CTIRQ_POST_EQ(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1D_6229_FB_power(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[4]&0x02)!=0 )\
			L1TRC_Send_L1D_6229_FB_power((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6), (short)(v7));\
} while(0)
#else
	#define L1D_6229_FB_power(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER)
	#define L1D_TX_info(v1, v2) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[4]&0x04)!=0 )\
			L1TRC_Send_L1D_TX_info((short)(v1), (short)(v2));\
} while(0)
#else
	#define L1D_TX_info(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_Trc_RX_DC_Offset(v1, v2, v3) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_RX_DC_Offset((unsigned char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_Trc_RX_DC_Offset(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_EDGE_USF(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_EDGE_USF((unsigned char)(v1), (short)(v2), (char)(v3), (short)(v4));\
} while(0)
#else
	#define L1D_Trc_EDGE_USF(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_SAIC_SNR(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[4]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_SAIC_SNR((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (short)(v5), (short)(v6), (short)(v7), (short)(v8));\
} while(0)
#else
	#define L1D_Trc_SAIC_SNR(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_SAIC_FOE(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[4]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_SAIC_FOE((unsigned char)(v1), (char)(v2), (short)(v3), (short)(v4), (short)(v5), (unsigned char)(v6));\
} while(0)
#else
	#define L1D_Trc_SAIC_FOE(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_SAIC_FWBW_SNR(v1, v2, v3) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_SAIC_FWBW_SNR((unsigned char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_Trc_SAIC_FWBW_SNR(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_Static_Detect(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[4]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_Static_Detect((char)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6), (short)(v7), (char)(v8));\
} while(0)
#else
	#define L1D_Trc_Static_Detect(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_FWBW_DCOC(v1, v2, v3) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_FWBW_DCOC((char)(v1), (char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1D_Trc_FWBW_DCOC(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_Step_DC_tmp(v1, v2) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_Step_DC_tmp((unsigned long)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1D_Trc_Step_DC_tmp(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_NSFT_TRACE_GetSBFail(v1) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1D_NSFT_TRACE_GetSBFail((short)(v1));\
} while(0)
#else
	#define L1D_NSFT_TRACE_GetSBFail(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_Trc_PCH_Report() do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_PCH_Report();\
} while(0)
#else
	#define L1D_Trc_PCH_Report()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_FANR_ULTBF_Info(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1D_FANR_ULTBF_Info((short)(v1), (short)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1D_FANR_ULTBF_Info(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_RTTI_ULTBF_Info(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1D_RTTI_ULTBF_Info((short)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned short)(v4), (unsigned short)(v5));\
} while(0)
#else
	#define L1D_RTTI_ULTBF_Info(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_RTTI_DLTBF_Info(v1, v2, v3) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1D_RTTI_DLTBF_Info((short)(v1), (unsigned char)(v2), (unsigned short)(v3));\
} while(0)
#else
	#define L1D_RTTI_DLTBF_Info(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_FANR_Rx_Info(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1D_FANR_Rx_Info((char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1D_FANR_Rx_Info(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_RTTI_Slot_Info(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1D_RTTI_Slot_Info((unsigned short)(v1), (short)(v2), (unsigned short)(v3), (short)(v4), (short)(v5), (unsigned short)(v6));\
} while(0)
#else
	#define L1D_RTTI_Slot_Info(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_RTTI_Header_Info(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1D_RTTI_Header_Info((short)(v1), (unsigned short)(v2), (unsigned short)(v3), (unsigned short)(v4), (unsigned short)(v5));\
} while(0)
#else
	#define L1D_RTTI_Header_Info(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_RTTI_FANR_TRC_DEBUG(v1, v2, v3) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1D_RTTI_FANR_TRC_DEBUG((unsigned short)(v1), (long)(v2), (long)(v3));\
} while(0)
#else
	#define L1D_RTTI_FANR_TRC_DEBUG(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1D_EDGE_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1D_Trc_DelayCD(short v1);
void L1TRC_Send_L1D_Trc_PTCCH_CD_TOGETHER(void);
void L1TRC_Send_L1D_Trc_USF_Status(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_USF_Modtype(char v1, short v2, short v3, char v4);
void L1TRC_Send_L1D_USF_3R_Status(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1D_DSP_Mod_type(unsigned short v1, short v2);
void L1TRC_Send_L1D_DSP_REPORT_D_VALUE(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_DSP_SRB_MACHINE(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_L1D_USF_Dummy_Detect(short v1);
void L1TRC_Send_L1D_TX_AFC_Dac(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1D_IGain_Update(long v1, long v2);
void L1TRC_Send_L1D_IGain_NewGain(short v1);
void L1TRC_Send_L1D_Rxiq_Phase_Update(long v1, long v2);
void L1TRC_Send_L1D_Rxiq_NewPhase(short v1);
void L1TRC_Send_L1D_CTIRQ_PRE_EQ(unsigned char v1, char v2, char v3, char v4, unsigned short v5);
void L1TRC_Send_L1D_CTIRQ_POST_EQ(unsigned char v1, char v2, char v3, char v4, unsigned short v5);
void L1TRC_Send_L1D_6229_FB_power(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_L1D_TX_info(short v1, short v2);
void L1TRC_Send_L1D_Trc_RX_DC_Offset(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_EDGE_USF(unsigned char v1, short v2, char v3, short v4);
void L1TRC_Send_L1D_Trc_SAIC_SNR(unsigned char v1, char v2, char v3, char v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_L1D_Trc_SAIC_FOE(unsigned char v1, char v2, short v3, short v4, short v5, unsigned char v6);
void L1TRC_Send_L1D_Trc_SAIC_FWBW_SNR(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_Static_Detect(char v1, short v2, short v3, short v4, short v5, short v6, short v7, char v8);
void L1TRC_Send_L1D_Trc_FWBW_DCOC(char v1, char v2, unsigned char v3);
void L1TRC_Send_L1D_Trc_Step_DC_tmp(unsigned long v1, unsigned char v2);
void L1TRC_Send_L1D_NSFT_TRACE_GetSBFail(short v1);
void L1TRC_Send_L1D_Trc_PCH_Report(void);
void L1TRC_Send_L1D_FANR_ULTBF_Info(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_RTTI_ULTBF_Info(short v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_L1D_RTTI_DLTBF_Info(short v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_L1D_FANR_Rx_Info(char v1, char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1D_RTTI_Slot_Info(unsigned short v1, short v2, unsigned short v3, short v4, short v5, unsigned short v6);
void L1TRC_Send_L1D_RTTI_Header_Info(short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_L1D_RTTI_FANR_TRC_DEBUG(unsigned short v1, long v2, long v3);

void Set_L1D_EDGE_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1D_EDGE()	(L1D_EDGE_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1D_EDGE_L1D_EDGE_State_L()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_USF_Status_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_DSP_Modtype_L()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_DSP_Dvalue_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_TEST_SRB_L()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_USF_DEBUG_L()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_TX_AFC_DAC_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_IGain_Compen_L()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_IQ_Phase_Compen_L()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_NBRES_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_6229_FB_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_TX_MODULATION_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_RX_DC_Offset_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_EDGE_USF_L()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_SNR_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_FOE_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_FWBW_SNR_L()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_StaticDet_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_AM_Suppression_L()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_NSFT_H()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_RTTI_FANR_M()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_USF_Status_H()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_DSP_Dvalue_H()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_TX_AFC_DAC_H()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_NBRES_H()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_6229_FB_H()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_TX_MODULATION_H()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_SNR_H()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_FOE_H()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[4]&0x10)!=0))
#define ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_StaticDet_H()	(ChkL1ModFltr_L1D_EDGE()&&((L1D_EDGE_Trace_Filter[4]&0x20)!=0))
#define ChkL1MsgFltr_L1D_Trc_DelayCD()	ChkL1ClsFltr_L1D_EDGE_L1D_EDGE_State_L()
#define ChkL1MsgFltr_L1D_Trc_PTCCH_CD_TOGETHER()	ChkL1ClsFltr_L1D_EDGE_L1D_EDGE_State_L()
#define ChkL1MsgFltr_L1D_Trc_USF_Status()	ChkL1ClsFltr_L1D_EDGE_L1D_USF_Status_H()
#define ChkL1MsgFltr_L1D_USF_Modtype()	ChkL1ClsFltr_L1D_EDGE_L1D_USF_Status_H()
#define ChkL1MsgFltr_L1D_USF_3R_Status()	ChkL1ClsFltr_L1D_EDGE_L1D_USF_Status_H()
#define ChkL1MsgFltr_L1D_DSP_Mod_type()	ChkL1ClsFltr_L1D_EDGE_L1D_DSP_Modtype_L()
#define ChkL1MsgFltr_L1D_DSP_REPORT_D_VALUE()	ChkL1ClsFltr_L1D_EDGE_L1D_DSP_Dvalue_H()
#define ChkL1MsgFltr_L1D_DSP_SRB_MACHINE()	ChkL1ClsFltr_L1D_EDGE_L1D_TEST_SRB_L()
#define ChkL1MsgFltr_L1D_USF_Dummy_Detect()	ChkL1ClsFltr_L1D_EDGE_L1D_USF_DEBUG_L()
#define ChkL1MsgFltr_L1D_TX_AFC_Dac()	ChkL1ClsFltr_L1D_EDGE_L1D_TX_AFC_DAC_H()
#define ChkL1MsgFltr_L1D_IGain_Update()	ChkL1ClsFltr_L1D_EDGE_L1D_IGain_Compen_L()
#define ChkL1MsgFltr_L1D_IGain_NewGain()	ChkL1ClsFltr_L1D_EDGE_L1D_IGain_Compen_L()
#define ChkL1MsgFltr_L1D_Rxiq_Phase_Update()	ChkL1ClsFltr_L1D_EDGE_L1D_IQ_Phase_Compen_L()
#define ChkL1MsgFltr_L1D_Rxiq_NewPhase()	ChkL1ClsFltr_L1D_EDGE_L1D_IQ_Phase_Compen_L()
#define ChkL1MsgFltr_L1D_CTIRQ_PRE_EQ()	ChkL1ClsFltr_L1D_EDGE_L1D_NBRES_H()
#define ChkL1MsgFltr_L1D_CTIRQ_POST_EQ()	ChkL1ClsFltr_L1D_EDGE_L1D_NBRES_H()
#define ChkL1MsgFltr_L1D_6229_FB_power()	ChkL1ClsFltr_L1D_EDGE_L1D_6229_FB_H()
#define ChkL1MsgFltr_L1D_TX_info()	ChkL1ClsFltr_L1D_EDGE_L1D_TX_MODULATION_H()
#define ChkL1MsgFltr_L1D_Trc_RX_DC_Offset()	ChkL1ClsFltr_L1D_EDGE_L1D_RX_DC_Offset_M()
#define ChkL1MsgFltr_L1D_Trc_EDGE_USF()	ChkL1ClsFltr_L1D_EDGE_L1D_EDGE_USF_L()
#define ChkL1MsgFltr_L1D_Trc_SAIC_SNR()	ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_SNR_H()
#define ChkL1MsgFltr_L1D_Trc_SAIC_FOE()	ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_FOE_H()
#define ChkL1MsgFltr_L1D_Trc_SAIC_FWBW_SNR()	ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_FWBW_SNR_L()
#define ChkL1MsgFltr_L1D_Trc_Static_Detect()	ChkL1ClsFltr_L1D_EDGE_L1D_SAIC_StaticDet_H()
#define ChkL1MsgFltr_L1D_Trc_FWBW_DCOC()	ChkL1ClsFltr_L1D_EDGE_L1D_AM_Suppression_L()
#define ChkL1MsgFltr_L1D_Trc_Step_DC_tmp()	ChkL1ClsFltr_L1D_EDGE_L1D_AM_Suppression_L()
#define ChkL1MsgFltr_L1D_NSFT_TRACE_GetSBFail()	ChkL1ClsFltr_L1D_EDGE_L1D_NSFT_H()
#define ChkL1MsgFltr_L1D_Trc_PCH_Report()	ChkL1ClsFltr_L1D_EDGE_L1D_USF_Status_M()
#define ChkL1MsgFltr_L1D_FANR_ULTBF_Info()	ChkL1ClsFltr_L1D_EDGE_L1D_RTTI_FANR_M()
#define ChkL1MsgFltr_L1D_RTTI_ULTBF_Info()	ChkL1ClsFltr_L1D_EDGE_L1D_RTTI_FANR_M()
#define ChkL1MsgFltr_L1D_RTTI_DLTBF_Info()	ChkL1ClsFltr_L1D_EDGE_L1D_RTTI_FANR_M()
#define ChkL1MsgFltr_L1D_FANR_Rx_Info()	ChkL1ClsFltr_L1D_EDGE_L1D_RTTI_FANR_M()
#define ChkL1MsgFltr_L1D_RTTI_Slot_Info()	ChkL1ClsFltr_L1D_EDGE_L1D_RTTI_FANR_M()
#define ChkL1MsgFltr_L1D_RTTI_Header_Info()	ChkL1ClsFltr_L1D_EDGE_L1D_RTTI_FANR_M()
#define ChkL1MsgFltr_L1D_RTTI_FANR_TRC_DEBUG()	ChkL1ClsFltr_L1D_EDGE_L1D_RTTI_FANR_M()


#endif
