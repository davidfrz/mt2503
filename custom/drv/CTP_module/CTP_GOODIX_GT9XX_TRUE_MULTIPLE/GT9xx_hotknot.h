#ifndef __GT9XX_HOTKNOT_H__
#define __GT9XX_HOTKNOT_H__

#ifdef __MTK_TARGET__

#define GUP_FW_INFO

#ifdef __TP_AUTO_UPDATE_FW__
#define GTP_AUTO_UPDATE 1	//update 开关
#else
#define GTP_AUTO_UPDATE 0	//update 开关
#endif

/*only work while GTP_AUTO_UPDATE is defined*/
#define GTP_HEADER_FW_UPDATE 1	//update with array ON:array  OFF:FS update
#define GTP_AUTO_UPDATE_CFG 0	//update config

#define GUP_REG_HW_INFO             0x4220
#define GUP_REG_FW_MSG              0x41E4
#define GUP_REG_PID_VID             0x8140

#define HN_REG_COMMAND				0x8040
#define HN_REG_COMMAND_CHECK		0x8046
#define HN_COMMAND_EXIT_MASTER		0x29


#define GUP_SEARCH_FILE_TIMES       5
#define UPDATE_FILE_PATH_1          L"e:\\_goodix_update_.bin"
#define UPDATE_FILE_PATH_2          L"c:\\_goodix_update_.bin"

#define CONFIG_FILE_PATH_1          L"e:\\_goodix_config_.cfg"
#define CONFIG_FILE_PATH_2          L"c:\\_goodix_config_.cfg"

#define FW_HEAD_LENGTH               14
#define FW_DOWNLOAD_LENGTH           0x4000
#define FW_SECTION_LENGTH            0x2000
#define FW_DSP_ISP_LENGTH            0x1000
#define FW_DSP_LENGTH                0x1000
#define FW_BOOT_LENGTH               0x800
#define FW_SS51_LENGTH               (4 * FW_SECTION_LENGTH)
#define FW_BOOT_ISP_LENGTH           0x800                     // 2k
#define FW_LINK_LENGTH               0x3000                    // 12k
#define FW_APP_CODE_LENGTH           (4 * FW_SECTION_LENGTH)   // 32k

#define FIRMWARE_LENGTH             (FW_SS51_LENGTH + FW_DSP_LENGTH + FW_BOOT_LENGTH + FW_DSP_ISP_LENGTH + FW_BOOT_ISP_LENGTH + FW_APP_CODE_LENGTH)

#define FW_HOTKNOT_LENGTH               0x3000
#define PACK_SIZE                    256
#define MAX_FRAME_CHECK_TIME         5


#define _bRW_MISCTL__SRAM_BANK       0x4048
#define _bRW_MISCTL__MEM_CD_EN       0x4049
#define _bRW_MISCTL__CACHE_EN        0x404B
#define _bRW_MISCTL__TMR0_EN         0x40B0
#define _rRW_MISCTL__SWRST_B0_       0x4180
#define _bWO_MISCTL__CPU_SWRST_PULSE 0x4184
#define _rRW_MISCTL__BOOTCTL_B0_     0x4190
#define _rRW_MISCTL__BOOT_OPT_B0_    0x4218
#define _rRW_MISCTL__BOOT_CTL_       0x5094

#define AUTO_SEARCH_BIN           0x01
#define AUTO_SEARCH_CFG           0x02
#define BIN_FILE_READY            0x80
#define CFG_FILE_READY            0x08
#define HEADER_FW_READY           0x01

#define FAIL    0
#define SUCCESS 1

#define MAIN_SYSTEM_PATH "/sdcard/goodix/_main_.bin"
#define HOTKNOT_SYSTEM_PATH "/sdcard/goodix/_hotknot_.bin"
#define FX_SYSTEM_PATH "/sdcard/goodix/_authorization_.bin"


// porting define start
#define GTP_INFO(fmt,arg...) kal_prompt_trace(MOD_TP_TASK, fmt,##arg);
#define GTP_ERROR(fmt,arg...) kal_prompt_trace(MOD_TP_TASK, fmt,##arg);
#define GTP_DEBUG(fmt,arg...) do{\
								if(GTP_DEBUG_ON)\
									kal_prompt_trace(MOD_TP_TASK, "[%d]"fmt, __LINE__, ##arg);\
									}while(0)
								
#define GTP_DEBUG_ARRAY(array, num) 

struct i2c_client
{
	kal_uint8 addr;
};
typedef kal_uint8 u8;
typedef kal_uint16 u16;
typedef kal_uint32 u32;
typedef kal_int32 s32;

typedef enum
{
	HOTKNOT_STATUS_NORMAL,
	HOTKNOT_LCD_OFF_STATUS,
	HOTKNOT_LCD_ON_AGAIN_STATUS
}HOTKNOT_STATUS_T;



#define GTP_ADDR_LENGTH 2

extern s32 gup_update_proc(void *dir);
extern void ctp_set_gpio(char data,char port);
extern void ctp_set_gpio2eint(char port);
extern void TP_MmiSendilm(module_type dest_id, msg_type msg_id, local_para_struct *data, sap_type sap_id);
extern kal_uint8 calculate_check_sum(kal_uint8* data,kal_uint8 len);
extern kal_bool gtp_hotknot_send(kal_uint8 *data, kal_uint8 length);
extern kal_bool gtp_hotknot_enter_master();
extern void combination_of_hotknotdata(void);
extern void Hotknot_polling_cb(void);
extern void touch_hotknot_init(void);
extern kal_bool touch_panel_hotknot_enable(void);
extern	kal_bool touch_panel_hotknot_disable(void);
extern void gtp_int_sync(s32 ms);
//extern void gtp_reset_guitar(struct i2c_client *client, s32 ms);
extern s32 gup_enter_update_mode(struct i2c_client *client);
extern void gup_leave_update_mode(void);
extern s32 gup_load_calibration1(void);
extern	void modify_hotknot_status(HOTKNOT_STATUS_T set_status);
extern void hotknot_recovery(void);
extern void hotknot_upload_frm_send(void);
extern void tp_hotknot_start_polling(void);

#endif

#endif
