# Define source file lists to SRC_LIST

ifneq ($(filter __SV5_ENABLED__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\GFH\public\ubin_GFH_body.c              
endif

SRC_LIST += drv\src\ubin_symbol_array.c

SRC_LIST += custom\system\$(strip $(BOARD_VER))\custom_ubconfig.c \
            hal\system\region\src\ubin_regioninit_ads.s
            
# Define include path lists to INC_DIR
INC_DIR = hal\system\GFH\public \
          hal\system\bootloader\inc \
          sss\interface\inc  \
          hal\system\cache\inc  \
          hal\system\init\inc \
          plutommi\Service\Inc \
          verno \
          custom\system\$(strip $(BOARD_VER))
ifneq ($(filter __UPDATE_PKG_SENSOR_ONLY__, $(strip $(MODULE_DEFS))),)
INC_DIR += sensor_subsys\fusion_algo\ppg_control\inc \
           sensor_subsys\fusion_algo\heart_rate\inc \
           sensor_subsys\fusion_algo\blood_pressure\inc
endif

ifeq ($(strip $(UPDATE_BINARY_FILE)),TRUE)
      COMP_DEFS += __UPDATE_BINARY_FILE__
endif
