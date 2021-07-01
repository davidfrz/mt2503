# Define source file lists to SRC_LIST
SRC_LIST = drv\src\bf.c \
           drv\src\e_compass_sensor.c \
           drv\src\e_compass_main.c \
           drv\src\sim_msdc_test.c \
           drv\src\BC_drv.c \
           hal\system\fota\src\fue_emmc_adapt.c


ifneq ($(filter __CARD_DOWNLOAD__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += drv\src\cdl.c
endif

ifneq ($(filter __FOTA_DM__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += drv\src\fota_partial.c
endif

# If Separate Bin FOTA is disabled, move IRT to drv lib because system_ubin lib is not existed
# Don't care MoDIS because MoDIS will not build drv lib
ifeq ($(strip $(UPDATE_BINARY_FILE)),FALSE)
  SRC_LIST += drv\src\ubin_symbol_array.c
endif

#  Define include path lists to INC_DIR
INC_DIR = drv\include \
          interface\hal\connectivity\usb_driver \
          hal\connectivity\usb_driver\inc \
          hal\bluetooth\btif\include \
          hal\storage\flash\mtd\inc \
          hal\storage\flash\fdm\inc \
          hal\storage\mc\inc \
          usb\include \
          inc \
          sst\include \
          media\image\include \
          dp_engine\che \
          applib\misc\include \
          ssf\inc \
          vendor\hp_fota\UA \
          irda\inc \
          hal\mm_comm\inc \
          hal\mdp\include \
          hal\drv_def \
          interface\hal \
          interface\hal\mm_comm \
          interface\hal\video \
          interface\hal\system \
          hal\system\regbase\inc \
          hal\system\dma\inc \
          hal\system\counter\inc \
          hal\system\cache\inc \
          hal\peripheral\inc \
          plutommi\Service\Inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

           
