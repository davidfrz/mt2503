#ifndef __DRV_FEATURES_GPIO_H__
#define __DRV_FEATURES_GPIO_H__

#include "drv_features_chip_select.h"

/****************** GPIO Feature Option List ************************
*	[H] means hardware feature option.  [S] means software feature option.
*1. 
*
*****************************************************************/

/**************** GPIO Feature Option******************/
#if defined(DRV_GPIO_6205_SERIES)
   #define DRV_GPIO_REG_AS_6205
   #define DRV_GPIO_6205_FUNC
#elif defined(DRV_GPIO_6205B_SERIES)
   #define DRV_GPIO_REG_AS_6205B
   #define DRV_GPIO_6205B_FUNC
#elif defined(DRV_GPIO_6208_SERIES)
   #define DRV_GPIO_REG_AS_6208
   #define DRV_GPIO_6208_FUNC
#elif defined(DRV_GPIO_6218_SERIES)
   #define DRV_GPIO_REG_AS_6218
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_DISCONT
#elif defined(DRV_GPIO_6218B_SERIES)
   #define DRV_GPIO_REG_AS_6218B
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_DISCONT
#elif defined(DRV_GPIO_6219_SERIES)
   #define DRV_GPIO_REG_AS_6219
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_DISCONT
#elif defined(DRV_GPIO_6225_SERIES)
   #define DRV_GPIO_REG_AS_6225
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_DISCONT
#elif defined(DRV_GPIO_6227_SERIES)
   #define DRV_GPIO_REG_AS_6227
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_MODE8_SPECIAL_POS
#elif defined(DRV_GPIO_6228_SERIES)
   #define DRV_GPIO_REG_AS_6228
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
#elif defined(DRV_GPIO_6223_SERIES)
   #define DRV_GPIO_REG_AS_6223
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_DISCONT
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_DEBUG_MODE
   #define DRV_GPIO_CLK_OUT
#elif defined(DRV_GPIO_6238_SERIES)
   #define DRV_GPIO_REG_AS_6238
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
   #define DRV_GPIO_TM_DIR
#elif defined(DRV_GPIO_6235_SERIES)
   #define DRV_GPIO_REG_AS_6235
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
#elif defined(DRV_GPIO_6236_SERIES)
   #define DRV_GPIO_REG_AS_6236
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
#elif defined(DRV_GPIO_6268T_SERIES)
   #define DRV_GPIO_REG_AS_6268T
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
#elif defined(DRV_GPIO_6268A_SERIES)
   #define DRV_GPIO_REG_AS_6268A
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
#elif defined(DRV_GPIO_6268_SERIES)
   #define DRV_GPIO_REG_AS_6268
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
#elif defined(DRV_GPIO_6270A_SERIES)
   #define DRV_GPIO_REG_AS_6270A
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
#elif defined(DRV_GPIO_TK6516_SERIES)
   #define DRV_GPIO_REG_AS_TK6516
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_PULL_SEL
#elif defined(DRV_GPIO_6253T_SERIES)
   #define DRV_GPIO_REG_AS_6253T
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
   #define DRV_GPIO_TM_DIR
#elif defined(DRV_GPIO_6253_SERIES)
   #define DRV_GPIO_REG_AS_6253T
   #define DRV_GPIO_6253_MODE11_DEFAULT
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
   #define DRV_GPIO_TM_DIR
#elif defined(DRV_GPIO_6255_SERIES)
   #define DRV_GPIO_REG_AS_6255
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT2
   #define DRV_GPIO_PULL_SEL
   #define DRV_GPIO_MODE_4BITS
   #define DRV_GPIO_BUS_LATENCY     //modified by dongming for MT6255 bus latency
#elif defined(DRV_GPIO_6276_SERIES)
   #define DRV_GPIO_REG_AS_6276
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT2
   #define DRV_GPIO_PULL_SEL
   #define DRV_GPIO_CLK_FROM_1
   #if defined(MT6276_S01)
   #define DRV_GPIO_MODE_3BITS
   #endif
#elif defined(DRV_GPIO_6251_SERIES)
   #define DRV_GPIO_REG_AS_6251
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
   #define DRV_GPIO_MODE_4BITS
#elif defined(DRV_GPIO_6253E_SERIES)
   #define DRV_GPIO_REG_AS_6253E
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
   #define DRV_GPIO_TM_DIR
#elif defined(DRV_GPIO_6253E_SERIES_1)
   #define DRV_GPIO_REG_AS_6253E_1
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
   #define DRV_GPIO_TM_DIR
   #define GPIO_MODE_32BIT_LENGTH 
   #define DRV_GPIO_MODE_4BITS 
#elif defined(DRV_GPIO_6573_SERIES)
   #define DRV_GPIO_OFF
#elif defined(DRV_GPIO_6256_SERIES)
   #define DRV_GPIO_REG_AS_6256
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT2
   #define DRV_GPIO_PULL_SEL
   #define DRV_GPIO_MODE_4BITS
   #define DRV_GPIO_BUS_LATENCY   //modified by dongming for MT6255 bus latency
#elif defined(DRV_GPIO_6250_SERIES)
   #define DRV_GPIO_REG_AS_6250
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT2
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
   #define DRV_GPIO_MODE_4BITS
   #define DRV_GPIO_6250_SPECIAL_SET_REG  // for PULLSEL,PULLEN  sw mapping in MT6250
  #define  GPIO_MODE_32BIT_LENGTH
#else
   #define DRV_GPIO_NEW_SW_ARCHI

#endif


#if !defined(DRV_GPIO_OFF)
	#define DRV_GPIO_FULL_FUNC
#endif	
/**************** GPIO Feature End******************/

#endif
