# Define source file lists to SRC_LIST

ifneq ($(filter __CUSTOM_GPS_FEATURE_SWITCH__, $(strip $(MODULE_DEFS))),)
SRC_LIST = gps\src\gps_init.c \
           gps\src\gps_inject_msg.c \
           gps\src\gps_main.c \
           gps\src\gps_sm.c \
           gps\src\gps_uart.c \
           gps\src\gps_auth.c \
           gps\src\gps_modem.c 
endif

ifneq ($(filter __GPS_ADAPTOR_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += gps\src\gps_adaptor.c \
					gps\src\epodownload.c 
endif

ifneq ($(filter __GPS_ADAPTOR_SUPPORT__, $(strip $(MODULE_DEFS))),)
ifneq ($(filter __AGPS_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += gps\src\agps_adaptor.c \
			gps\src\agps_setting.c
endif
endif

ifneq ($(filter __CUSTOM_GPS_FEATURE_SWITCH__, $(strip $(MODULE_DEFS))),)
ifneq ($(filter __TCPIP__, $(strip $(MODULE_DEFS))),)
SRC_LIST += wapadp\src\wap_cmmn_utils.c
endif
endif
#  Define include path lists to INC_DIR
INC_DIR = gps\inc \
          gps\mnl\include \
          gps\mnl\MNL_OIL \
          plutommi\service\mdi\mdiinc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\DebugLevels\DebugLevelInc \
          applib\misc\include \
          plutommi\MtkApp\AGPSLog\AGPSLogInc \
          interface\hal\peripheral

ifneq ($(filter __GPS_ADAPTOR_SUPPORT__, $(strip $(MODULE_DEFS))),)
INC_DIR += wapadp\include 
endif
# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

