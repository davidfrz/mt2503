#ifndef _ADC_KEYPAD_H
#define _ADC_KEYPAD_H

#include 	"kal_general_types.h"
#include 	"drv_features.h"
#include    "keypad.h"

extern void kbd_via_adc_init(void);
extern kal_uint32 kbd_via_adc_current_key_status;
extern void  kbd_via_adc_get_keys( kal_uint32* key);

#define KBD_VIA_ADC_EINT_NO 0x9
//#define KBD_ADC_VIA_TP 

#define KBD_VIA_ADC_POS_ROW 2
#define KBD_VIA_ADC_POS_COL 0
#define KBD_VIA_ADC_KEY_CNT 5
#define  sample_count 8

#endif












