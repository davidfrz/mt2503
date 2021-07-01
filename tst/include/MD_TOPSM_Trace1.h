#ifndef L1TRC_MD_TOPSM_1_DEF_H
#define L1TRC_MD_TOPSM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define MD_TOPSM_Str_Bool(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER)
	#define MD_TOPSM_TRC_CALIBRATION(v1, v2, v3) do {\
		if(MD_TOPSM_1_Trace_Filter[0]==1 && (MD_TOPSM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_MD_TOPSM_TRC_CALIBRATION((unsigned short)(v1), (long)(v2), (long)(v3));\
} while(0)
#else
	#define MD_TOPSM_TRC_CALIBRATION(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define MD_TOPSM_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3, v4) do {\
		if(MD_TOPSM_1_Trace_Filter[0]==1 && (MD_TOPSM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_MD_TOPSM_DBG_COCLK_UPDATE_FMRESULT((unsigned short)(v1), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
} while(0)
#else
	#define MD_TOPSM_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char MD_TOPSM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_MD_TOPSM_TRC_CALIBRATION(unsigned short v1, long v2, long v3);
void L1TRC_Send_MD_TOPSM_DBG_COCLK_UPDATE_FMRESULT(unsigned short v1, unsigned long v2, long v3, unsigned long v4);

void Set_MD_TOPSM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_MD_TOPSM_1()	(MD_TOPSM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_MD_TOPSM_1_MD_TOPSM_SM_H()	(ChkL1ModFltr_MD_TOPSM_1()&&((MD_TOPSM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_MD_TOPSM_TRC_CALIBRATION()	ChkL1ClsFltr_MD_TOPSM_1_MD_TOPSM_SM_H()
#define ChkL1MsgFltr_MD_TOPSM_DBG_COCLK_UPDATE_FMRESULT()	ChkL1ClsFltr_MD_TOPSM_1_MD_TOPSM_SM_H()


#endif
