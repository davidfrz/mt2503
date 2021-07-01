/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   mmu.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of Code and Data cache.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__ZIMAGE_SUPPORT__)

#include "kal_release.h"
#include "code_decompression.h"
#include "dcl.h"
#include "dcl_pw.h"
#if defined(__UPDATE_BINARY_FILE__) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
#include "custom_scatstruct.h"
#include "custom_ubin_irt.h"
#endif
#include "device.h"
#if defined(__TINY_SYS__)
#include "wdt_sw.h"
extern kal_uint8 pwm_saved_backlight_level;
extern kal_uint8 IRQ_Query_If_Special_Resume(void);
#endif

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(__IOT__)
#if defined(__UPDATE_BINARY_FILE__) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
unsigned int* p_mmi_symblo_addr = NULL;
#else
extern void MMICheckDiskDisplay_bootup(void);
#endif
#endif

kal_bool ZIMAGEImageLoaded = KAL_FALSE;


static void zimage_dispaly_logo(void)
{
#if defined(__MTK_TARGET__)
    DCL_HANDLE handle;
    PW_CTRL_GET_POWERON_REASON poweron_type;

    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(handle, PW_CMD_GET_POWERON_REASON,(DCL_CTRL_DATA_T *)&poweron_type);
    DclPW_Close(handle);

	#if defined(__TINY_SYS__)
	if(((1 == IRQ_Query_If_Special_Resume()) && (WARM_BOOT == AP_check_boot_up_source())) ||
		( poweron_type.powerOnReason != RTCPWRON &&
       	  poweron_type.powerOnReason != ABNRESET &&
          poweron_type.powerOnReason != UNKNOWN_PWRON))
	#else
    if(poweron_type.powerOnReason != RTCPWRON &&
       poweron_type.powerOnReason != ABNRESET &&
       poweron_type.powerOnReason != UNKNOWN_PWRON)
	#endif
    {
        handle=DclPW_Open(DCL_PW, FLAGS_NONE);
        DclPW_Control(handle,PW_CMD_POWERON,NULL);
        DclPW_Close(handle);
	#if defined(__TINY_SYS__)
        #if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(__IOT__)
        #if defined(__UPDATE_BINARY_FILE__) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
            p_mmi_symblo_addr = (unsigned int*)(custom_get_UPDATE_ROM_entry() + UBIN_SYMBOL_MMI_CHECK_DISPLY_BOOTUP*sizeof(void *));
            ((void (*)(void))(*p_mmi_symblo_addr))();
        #else
            MMICheckDiskDisplay_bootup();
        #endif
        #endif
  #endif
    }

#if !defined(__TINY_SYS__)
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(__IOT__)
#if defined(__UPDATE_BINARY_FILE__) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
	p_mmi_symblo_addr = (unsigned int*)(custom_get_UPDATE_ROM_entry() + UBIN_SYMBOL_MMI_CHECK_DISPLY_BOOTUP*sizeof(void *));
	((void (*)(void))(*p_mmi_symblo_addr))();
#else
    MMICheckDiskDisplay_bootup();
#endif
#endif
#endif

#if defined(__NEP_ZIMAGE_SUPPORT__)
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
	#if defined(__TINY_SYS__)
	if((1 == IRQ_Query_If_Special_Resume()) && (WARM_BOOT == AP_check_boot_up_source()))
    	custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, pwm_saved_backlight_level);
	else
	#endif
		custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
#endif
#endif /* __NEP_ZIMAGE_SUPPORT__ */

	#if defined(__TINY_SYS__)
	if(((1 == IRQ_Query_If_Special_Resume()) && (WARM_BOOT == AP_check_boot_up_source())) ||
		( poweron_type.powerOnReason != RTCPWRON &&
       	  poweron_type.powerOnReason != ABNRESET &&
          poweron_type.powerOnReason != UNKNOWN_PWRON))
	#else
    if(poweron_type.powerOnReason != RTCPWRON &&
       poweron_type.powerOnReason != ABNRESET &&
       poweron_type.powerOnReason != UNKNOWN_PWRON)
    #endif
    {
        //handle=DclPW_Open(DCL_PW, FLAGS_NONE);
        //DclPW_Control(handle,PW_CMD_POWERON,NULL);
        //DclPW_Close(handle);

#if !defined(__NEP_ZIMAGE_SUPPORT__)
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
		#if defined(__TINY_SYS__)
		if((1 == IRQ_Query_If_Special_Resume()) && (WARM_BOOT == AP_check_boot_up_source()))
        	custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, pwm_saved_backlight_level);
		else
		#endif
			custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
		
#endif
#endif /* __NEP_ZIMAGE_SUPPORT__ */
    }
#endif /* __MTK_TARGET__ */
}

static void zimage_progress_notify(kal_uint32 dec_size, kal_uint32 total_size)
{
#if defined(__MTK_TARGET__)
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) && !defined(__IOT__)
#if defined(__UPDATE_BINARY_FILE__) && !defined(__UPDATE_PKG_BT_ONLY__) && !defined(__UPDATE_PKG_SENSOR_ONLY__)
	p_mmi_symblo_addr = (unsigned int*)(custom_get_UPDATE_ROM_entry() + UBIN_SYMBOL_MMI_CHECK_DISPLY*sizeof(void *));
	((void (*)(void))(*p_mmi_symblo_addr))();
#else
	MMICheckDiskDisplay_bootup();
#endif
#endif
#endif /* __MTK_TARGET__ */
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
int ZImageDecompress(void)
{
#if defined(__MTK_TARGET__)
#define ZIMAGE_DECOMPRESS_LEN            (64*1024)

      zimage_dispaly_logo();

      ZImageDecompressHal(ZIMAGE_DECOMPRESS_LEN, zimage_progress_notify);

      ZIMAGEImageLoaded = KAL_TRUE;

#endif /* __MTK_TARGET__ */
      return 0;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


#endif /* __ZIMAGE_SUPPORT__ */
