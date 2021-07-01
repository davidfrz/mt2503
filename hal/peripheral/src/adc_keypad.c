#include    "keypad.h"
#include 	"sw_keypad.h"
#include  	"us_timer.h"

#include 	"stack_common.h"
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"syscomp_config.h"
#include 	"drv_comm.h"
#include    "keypad_hw.h"
#include 	"drv_features.h"
#include    "keypad.h"
#include    "dcl.h"
#include    "gpt_sw.h"
#include    "intrCtrl.h"
#include    "kbd_table.h"

#include    "drv_trc.h"
#include 	"task_main_func.h"
#include 	"stack_config.h"
#include 	"kal_trace.h"
#include 	"stack_ltlcom.h"

#include 	"kal_general_types.h"
#include 	"kal_public_api.h"
#include 	"kal_public_defs.h"
#include    "eint.h"
#include    "cache_sw_int.h"
#include	"adc_keypad.h"

#ifdef DRV_KBD_ADC_KEYPAD
extern kbd_struct KBD;
extern const keypad_customize_function_struct *keypad_GetFunc(void);

#ifdef KBD_ADC_VIA_TP
extern kal_uint16  ts_read_adc(kal_uint16 pos,kal_bool IsPressure);
#define TS_CMD_ADDR_Y		  0x0010
#define TS_CMD_ADDR_YN		  0X0020
#define TS_CMD_ADDR_Z1		  0x0030
#define TS_CMD_ADDR_Z2		  0x0040
#define TS_CMD_ADDR_X		  0x0050
#define TS_CMD_ADDR_XN		  0X0060
#else

DCL_HANDLE adc_handler;
void kbd_adc_get_adc_value(kal_uint16 *adc)
{
   
	DCL_STATUS status;
	DCL_CTRL_DATA_T data;
	ADC_CTRL_GET_IMM_DATA_T *prADCGetData;
	prADCGetData=&(data.rADCGetImmData);
	prADCGetData->u1Channel = DCL_VCHARGER_ADC_CHANNEL;
	status = DclSADC_Control(adc_handler, ADC_CMD_GET_IMM_DATA,&data);	
	if(status != STATUS_OK)
			ASSERT(0);
	*adc = prADCGetData->d8AdcValue;	
}

#ifdef KBD_ADC_TEST
 extern int rand(void);
/*this is a dummy func, waiting for WY ready*/
void kbd_adc_get_adc_value(kal_uint16 *adc)
{	
  /*rand adc in [0,600] for test*/
  static kal_uint32 adc_tmp;
  kal_uint32 adc_tmp2,adc_flag;
  static kal_uint32 adc_cnt = 1;
  if(adc_cnt == 1)
  {
  	adc_tmp = 10+rand()%(590-10+1);
  }
    adc_cnt++;
  if(adc_cnt == sample_count)
	 adc_cnt = 1;
		
   adc_tmp2 = 0+rand()%(10-0+1);
   adc_flag = 0+rand()%(1-0+1); 
   if(adc_flag == 0) *adc = adc_tmp + adc_tmp2;
   else *adc = adc_tmp - adc_tmp2;
}
#endif

#endif


static kal_uint16 kbd_via_adc_get_adc(void)
{
   kal_uint16 sample[sample_count]= {0};
   kal_uint16 i,j,adc_temp;

	for (i=0; i<sample_count; i++)
	{
#ifdef KBD_ADC_VIA_TP  /*From TP*/
	  sample[i]= ts_read_adc(TS_CMD_ADDR_X,0);
      sample[i]= sample[i]>>2;
#else  /*From ADC*/
	 kbd_adc_get_adc_value(&sample[i]);
#endif
	}
	for (i=0; i<sample_count-1; i++)
	{
		for(j=0; j<sample_count-i-1;j++)
		{
			if(sample[j]>sample[j+1])
			{
				adc_temp = sample[j];
				sample[j] = sample[j+1];
				sample[j+1] = adc_temp;
			}
		}
	}
	adc_temp = (sample[2]+sample[3]+sample[4]+sample[5])>>2;
	return adc_temp;
}
void  kbd_via_adc_get_keys( kal_uint32* key)
{
	kal_uint32 i;
	kal_uint16 adc;
	const keypad_customize_function_struct *keypadCustomFunc = NULL;
    const keypad_struct *keypad_comm_def = NULL;
	adc = kbd_via_adc_get_adc();
    if((0 <= adc) && (adc <= 9))		   i = 0;	
	else if((10 <= adc) && (adc <= 29))	   i = 1;   
	else if((30 <= adc) && (adc <= 56))	   i = 2;   
	else if((57 <= adc) && (adc <= 90))	   i = 3;   
	else if((91 <= adc) && (adc <= 122))   i = 4; 
	else if((123 <= adc) && (adc <= 152))  i = 5; 
	else if((153 <= adc) && (adc <= 187))  i = 6; 
	else if((188 <= adc) && (adc <= 228))  i = 7; 
	else if((229 <= adc) && (adc <= 269))  i = 8; 
	else if((270 <= adc) && (adc <= 312))  i = 9; 
	else if((313 <= adc) && (adc <= 354))  i = 10;
	else if((355 <= adc) && (adc <= 395))  i = 11;
	else if((396 <= adc) && (adc <= 435))  i = 12;
	else if((436 <= adc) && (adc <= 477))  i = 13;
	else if((478 <= adc) && (adc <= 517))  i = 14;
	else if((518 <= adc) && (adc <= 600))  i = 16;
	else i= 0xFF; /*release*/

	if(i==0xff) /*key release*/
	{
		*key = 0xffffffff;
	}
	else /*key press*/
	{
		*key &= ~(kal_uint32)(1<<i);
#ifndef __UBL__
		if(keypad_comm_def == NULL)
		{
			keypadCustomFunc=keypad_GetFunc();
			keypad_comm_def = keypadCustomFunc->keypad_Get_Data();
		}
		kal_prompt_trace(MOD_DRVKBD, "kbd via adc,	i=	%d	adc=	%d	keys=	%d", i,adc,keypad_comm_def->keypad[32+i]);
#endif
	}
 	
}
#ifndef __UBL__
static kal_bool polarity = KAL_FALSE;
kal_uint32 kbd_via_adc_current_key_status;
void KBD_VIA_ADC_EINT_HISR(void)
{      
	kal_uint16 adc_value;
	kal_uint32 key_status_temp = 0xFFFFFFFF;
	 polarity = ~polarity;  /*reverse EINT polarity*/ 
    if(polarity) /*key press state*/ 
        EINT_Set_Polarity(KBD_VIA_ADC_EINT_NO, KAL_TRUE);
    else          /*key release state*/
        EINT_Set_Polarity(KBD_VIA_ADC_EINT_NO, KAL_FALSE);
	kbd_via_adc_get_keys(&key_status_temp);
	if (kbd_via_adc_current_key_status != key_status_temp)
	{
		kbd_via_adc_current_key_status = key_status_temp;
		kal_set_eg_events(KBD.event,KBD_STATUS_CHANGE_EVENT,KAL_OR);  /*send event to task*/
	}
	

}
#ifdef KBD_ADC_TEST
kal_uint32 kbd_via_adc_polling_timer;
void kbd_via_adc_polling_timer_cb(void *parameter)
{

	 kal_uint32 timer = 8;
	 sw_kbd_set_timer(kbd_via_adc_polling_timer,kbd_via_adc_polling_timer_cb,timer); 
	 EINT_SetSWRegister(KBD_VIA_ADC_EINT_NO);

}
#endif
void kbd_via_adc_init(void)
{
	/*get dcl adc handle*/
	adc_handler= DclSADC_Open(DCL_ADC, 0);
	EINT_Registration(KBD_VIA_ADC_EINT_NO,KAL_TRUE,KAL_FALSE,KBD_VIA_ADC_EINT_HISR, KAL_TRUE);
	EINT_Set_Sensitivity(KBD_VIA_ADC_EINT_NO, LEVEL_SENSITIVE);
	EINT_Set_Polarity(KBD_VIA_ADC_EINT_NO, KAL_FALSE);
	EINT_Set_HW_Debounce(KBD_VIA_ADC_EINT_NO, 20);/* debounce 20ms*/

	#ifdef KBD_ADC_TEST
	kbd_via_adc_polling_timer=DclSGPT_Open(DCL_GPT_CB,0);
	sw_kbd_set_timer(kbd_via_adc_polling_timer,kbd_via_adc_polling_timer_cb,200); 
	#endif	
}
#endif
#endif
