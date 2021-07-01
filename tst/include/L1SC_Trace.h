#ifndef L1TRC_L1SC_DEF_H
#define L1TRC_L1SC_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1SC_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1SC_Str_SCMODE(v1)  (unsigned char)(v1+2)
#define L1SC_Str_VMODE(v1)  (unsigned char)(v1+12)
#define L1C_Str_Identity(v1)  (unsigned char)(v1+14)
#define L1C_Str_TFI(v1)  (unsigned char)(v1+18)
#define L1C_Str_AMR_Status(v1)  (unsigned char)(v1+20)
#define L1C_Str_Loopback_Mode(v1)  (unsigned char)(v1+28)
#define L1C_Str_NC_Report(v1)  (unsigned char)(v1+37)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SC_Msg_FB(v1, v2, v3, v4) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SC_Msg_FB((unsigned char)(v1), (short)(v2), (unsigned char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1SC_Msg_FB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SC_Msg_FB_done(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SC_Msg_FB_done((unsigned char)(v1), (short)(v2), (unsigned char)(v3), (unsigned char)(v4), (short)(v5), (char)(v6), (unsigned char)(v7));\
} while(0)
#else
	#define L1SC_Msg_FB_done(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SC_Msg_FB_abort(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SC_Msg_FB_abort((unsigned char)(v1), (short)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1SC_Msg_FB_abort(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SC_Msg_SB(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1SC_Msg_SB((unsigned char)(v1), (short)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1SC_Msg_SB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SC_Msg_SB_done(v1, v2, v3, v4, v5) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1SC_Msg_SB_done((unsigned char)(v1), (short)(v2), (unsigned char)(v3), (short)(v4), (char)(v5));\
} while(0)
#else
	#define L1SC_Msg_SB_done(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SC_Msg_SB_abort(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1SC_Msg_SB_abort((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1SC_Msg_SB_abort(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SC_Msg_SI(v1, v2, v3, v4, v5) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1SC_Msg_SI((unsigned char)(v1), (short)(v2), (unsigned short)(v3), (unsigned char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1SC_Msg_SI(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SC_Msg_SI_done(v1, v2, v3, v4) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1SC_Msg_SI_done((unsigned char)(v1), (short)(v2), (unsigned char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1SC_Msg_SI_done(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SC_Msg_SI_abort(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1SC_Msg_SI_abort((unsigned char)(v1), (short)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1SC_Msg_SI_abort(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1SC_Msg_SCMODE(v1, v2, v3, v4, v5) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1SC_Msg_SCMODE((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1SC_Msg_SCMODE(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1SC_Msg_SCARFCN(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1SC_Msg_SCARFCN((unsigned char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1SC_Msg_SCARFCN(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1C_ReportGPRS_DL_CB_1(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_ReportGPRS_DL_CB_1((unsigned char)(v1), (unsigned long)(v2), (short)(v3));\
} while(0)
#else
	#define L1C_ReportGPRS_DL_CB_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_ReportGPRS_DL_CB_2(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_ReportGPRS_DL_CB_2((unsigned char)(v1), (unsigned long)(v2), (short)(v3));\
} while(0)
#else
	#define L1C_ReportGPRS_DL_CB_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_PUAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PUAN((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (char)(v5), (char)(v6), (char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10), (unsigned char)(v11), (unsigned char)(v12), (unsigned char)(v13), (unsigned char)(v14), (unsigned char)(v15));\
} while(0)
#else
	#define L1C_Trace_PUAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_PDAS(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDAS((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9));\
} while(0)
#else
	#define L1C_Trace_PDAS(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_PUAS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PUAS((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (char)(v10));\
} while(0)
#else
	#define L1C_Trace_PUAS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_PPR(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PPR((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9));\
} while(0)
#else
	#define L1C_Trace_PPR(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_PTR(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PTR((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (unsigned char)(v5), (char)(v6), (char)(v7), (char)(v8));\
} while(0)
#else
	#define L1C_Trace_PTR(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_PDCH_Release(v1, v2, v3, v4) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDCH_Release((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1C_Trace_PDCH_Release(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_Debug_UL_DL_CB(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Trace_Debug_UL_DL_CB((unsigned char)(v1), (char)(v2));\
} while(0)
#else
	#define L1C_Trace_Debug_UL_DL_CB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_FixAlloc_Transition(v1, v2, v3, v4) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_FixAlloc_Transition((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4));\
} while(0)
#else
	#define L1I_Trace_FixAlloc_Transition(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_RepeatAlloc(v1, v2, v3, v4) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_RepeatAlloc((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned long)(v4));\
} while(0)
#else
	#define L1I_Trace_RepeatAlloc(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_ReportRepeatAlloc(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_ReportRepeatAlloc((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1I_Trace_ReportRepeatAlloc(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_AllocBitMap(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_AllocBitMap((unsigned char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Trace_AllocBitMap(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_BitMapNo(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_BitMapNo((unsigned char)(v1), (char)(v2));\
} while(0)
#else
	#define L1I_Trace_BitMapNo(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_Loopback_Mode(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Trace_Loopback_Mode((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_Loopback_Mode(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_AMR_Status(v1, v2, v3, v4) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_AMR_Status((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4));\
} while(0)
#else
	#define L1C_Trace_AMR_Status(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_RATSCCH_DATA(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_RATSCCH_DATA((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_RATSCCH_DATA(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_NC_Report(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1C_Trace_NC_Report((unsigned char)(v1), (unsigned char)(v2), (short)(v3));\
} while(0)
#else
	#define L1C_Trace_NC_Report(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1SC_Msg_BSIC_Debug(v1, v2, v3, v4, v5, v6) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1SC_Msg_BSIC_Debug((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6));\
} while(0)
#else
	#define L1SC_Msg_BSIC_Debug(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1SC_Msg_BCCH_Debug(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1SC_Msg_BCCH_Debug((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6), (short)(v7));\
} while(0)
#else
	#define L1SC_Msg_BCCH_Debug(v1, v2, v3, v4, v5, v6, v7)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1SC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1SC_Msg_FB(unsigned char v1, short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1SC_Msg_FB_done(unsigned char v1, short v2, unsigned char v3, unsigned char v4, short v5, char v6, unsigned char v7);
void L1TRC_Send_L1SC_Msg_FB_abort(unsigned char v1, short v2, unsigned char v3);
void L1TRC_Send_L1SC_Msg_SB(unsigned char v1, short v2, unsigned char v3);
void L1TRC_Send_L1SC_Msg_SB_done(unsigned char v1, short v2, unsigned char v3, short v4, char v5);
void L1TRC_Send_L1SC_Msg_SB_abort(unsigned char v1, short v2);
void L1TRC_Send_L1SC_Msg_SI(unsigned char v1, short v2, unsigned short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1SC_Msg_SI_done(unsigned char v1, short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1SC_Msg_SI_abort(unsigned char v1, short v2, unsigned char v3);
void L1TRC_Send_L1SC_Msg_SCMODE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1SC_Msg_SCARFCN(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1C_ReportGPRS_DL_CB_1(unsigned char v1, unsigned long v2, short v3);
void L1TRC_Send_L1C_ReportGPRS_DL_CB_2(unsigned char v1, unsigned long v2, short v3);
void L1TRC_Send_L1C_Trace_PUAN(unsigned char v1, char v2, char v3, char v4, char v5, char v6, char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12, unsigned char v13, unsigned char v14, unsigned char v15);
void L1TRC_Send_L1C_Trace_PDAS(unsigned char v1, char v2, char v3, char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_L1C_Trace_PUAS(unsigned char v1, char v2, char v3, char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, char v10);
void L1TRC_Send_L1C_Trace_PPR(unsigned char v1, char v2, char v3, char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_L1C_Trace_PTR(unsigned char v1, char v2, char v3, char v4, unsigned char v5, char v6, char v7, char v8);
void L1TRC_Send_L1C_Trace_PDCH_Release(unsigned char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_L1C_Trace_Debug_UL_DL_CB(unsigned char v1, char v2);
void L1TRC_Send_L1I_Trace_FixAlloc_Transition(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_L1I_Trace_RepeatAlloc(unsigned char v1, char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_L1I_Trace_ReportRepeatAlloc(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trace_AllocBitMap(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_BitMapNo(unsigned char v1, char v2);
void L1TRC_Send_L1C_Trace_Loopback_Mode(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_AMR_Status(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_L1C_Trace_RATSCCH_DATA(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_NC_Report(unsigned char v1, unsigned char v2, short v3);
void L1TRC_Send_L1SC_Msg_BSIC_Debug(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1SC_Msg_BCCH_Debug(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7);

void Set_L1SC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1SC()	(L1SC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1SC_FB_M()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1SC_SB_M()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1SC_SI_M()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1SC_SCMODE_H()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1SC_SCARFCN_H()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1SC_DL_Block_M()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1SC_DL_Block_H()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1SC_CB_Debug_M()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1SC_FIX_ALLOC_M()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1SC_BITMAP_NO_M()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1SC_AMR_M()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1SC_Loop_Mode_L()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1SC_DL_Ctrl_Block_L()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1SC_NC_Report_H()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1SC_BSIC_debug_L()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1SC_BCCH_debug_L()	(ChkL1ModFltr_L1SC()&&((L1SC_Trace_Filter[2]&0x80)!=0))
#define ChkL1MsgFltr_L1SC_Msg_FB()	ChkL1ClsFltr_L1SC_FB_M()
#define ChkL1MsgFltr_L1SC_Msg_FB_done()	ChkL1ClsFltr_L1SC_FB_M()
#define ChkL1MsgFltr_L1SC_Msg_FB_abort()	ChkL1ClsFltr_L1SC_FB_M()
#define ChkL1MsgFltr_L1SC_Msg_SB()	ChkL1ClsFltr_L1SC_SB_M()
#define ChkL1MsgFltr_L1SC_Msg_SB_done()	ChkL1ClsFltr_L1SC_SB_M()
#define ChkL1MsgFltr_L1SC_Msg_SB_abort()	ChkL1ClsFltr_L1SC_SB_M()
#define ChkL1MsgFltr_L1SC_Msg_SI()	ChkL1ClsFltr_L1SC_SI_M()
#define ChkL1MsgFltr_L1SC_Msg_SI_done()	ChkL1ClsFltr_L1SC_SI_M()
#define ChkL1MsgFltr_L1SC_Msg_SI_abort()	ChkL1ClsFltr_L1SC_SI_M()
#define ChkL1MsgFltr_L1SC_Msg_SCMODE()	ChkL1ClsFltr_L1SC_SCMODE_H()
#define ChkL1MsgFltr_L1SC_Msg_SCARFCN()	ChkL1ClsFltr_L1SC_SCARFCN_H()
#define ChkL1MsgFltr_L1C_ReportGPRS_DL_CB_1()	ChkL1ClsFltr_L1SC_DL_Block_H()
#define ChkL1MsgFltr_L1C_ReportGPRS_DL_CB_2()	ChkL1ClsFltr_L1SC_DL_Block_M()
#define ChkL1MsgFltr_L1C_Trace_PUAN()	ChkL1ClsFltr_L1SC_DL_Ctrl_Block_L()
#define ChkL1MsgFltr_L1C_Trace_PDAS()	ChkL1ClsFltr_L1SC_DL_Ctrl_Block_L()
#define ChkL1MsgFltr_L1C_Trace_PUAS()	ChkL1ClsFltr_L1SC_DL_Ctrl_Block_L()
#define ChkL1MsgFltr_L1C_Trace_PPR()	ChkL1ClsFltr_L1SC_DL_Ctrl_Block_L()
#define ChkL1MsgFltr_L1C_Trace_PTR()	ChkL1ClsFltr_L1SC_DL_Ctrl_Block_L()
#define ChkL1MsgFltr_L1C_Trace_PDCH_Release()	ChkL1ClsFltr_L1SC_DL_Ctrl_Block_L()
#define ChkL1MsgFltr_L1C_Trace_Debug_UL_DL_CB()	ChkL1ClsFltr_L1SC_CB_Debug_M()
#define ChkL1MsgFltr_L1I_Trace_FixAlloc_Transition()	ChkL1ClsFltr_L1SC_FIX_ALLOC_M()
#define ChkL1MsgFltr_L1I_Trace_RepeatAlloc()	ChkL1ClsFltr_L1SC_FIX_ALLOC_M()
#define ChkL1MsgFltr_L1I_Trace_ReportRepeatAlloc()	ChkL1ClsFltr_L1SC_FIX_ALLOC_M()
#define ChkL1MsgFltr_L1I_Trace_AllocBitMap()	ChkL1ClsFltr_L1SC_FIX_ALLOC_M()
#define ChkL1MsgFltr_L1I_Trace_BitMapNo()	ChkL1ClsFltr_L1SC_BITMAP_NO_M()
#define ChkL1MsgFltr_L1C_Trace_Loopback_Mode()	ChkL1ClsFltr_L1SC_Loop_Mode_L()
#define ChkL1MsgFltr_L1C_Trace_AMR_Status()	ChkL1ClsFltr_L1SC_AMR_M()
#define ChkL1MsgFltr_L1C_Trace_RATSCCH_DATA()	ChkL1ClsFltr_L1SC_AMR_M()
#define ChkL1MsgFltr_L1C_Trace_NC_Report()	ChkL1ClsFltr_L1SC_NC_Report_H()
#define ChkL1MsgFltr_L1SC_Msg_BSIC_Debug()	ChkL1ClsFltr_L1SC_BSIC_debug_L()
#define ChkL1MsgFltr_L1SC_Msg_BCCH_Debug()	ChkL1ClsFltr_L1SC_BCCH_debug_L()


#endif
