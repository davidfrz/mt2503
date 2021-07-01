#######################################################################
# Variable
#######################################################################
UBIN_DEBUG_DIR := $(strip $(TARGDIR))\UBIN_DEBUG
MBIN_REMOVE_MULTI_DEF_SYMBOL_SYM := $(strip $(UBIN_DEBUG_DIR))\mbin_remove_multi_def_symbol.sym
MBIN_KEEP_UBIN_SYMBOL_LIST := $(strip $(UBIN_DEBUG_DIR))\mbin_keep_ubin_sym.list
MBIN_WITH_ALLLIB_LIS := $(strip $(UBIN_DEBUG_DIR))\mbin_with_all_libs.lis

#######################################################################
# Linker options
#######################################################################
UBIN_LNKOPT := 
UBIN_LNKOPT += $(strip $(COMPLIBDIR))\system_ubin.lib(ubin_GFH_body.obj)
UBIN_LNKOPT += --keep g_ubin_gfh

#######################################################################
# COMP_TRACE_DEFS/COM_DEFS/COMPLIST
#######################################################################
UBIN_COMPOBJS := 
#UBIN_COMPOBJS += vendor\inputmethod\CStar\free_slim_0k\lib\kmxime_arm7_rvct.a
#UBIN_COMPOBJS += mre\lib\mrecorervct.lib
#UBIN_COMPOBJS += ttl\lib\ttl.lib

UBIN_COMPLIST := ubinverno
UBIN_COMPLIST += system_ubin

# MMI
UBIN_MMI_COMPLIST += applib
UBIN_MMI_COMPLIST += applib_asn1
UBIN_MMI_COMPLIST += btnotification_conn
UBIN_MMI_COMPLIST += conn_app
UBIN_MMI_COMPLIST += cstar
UBIN_MMI_COMPLIST += gdi
UBIN_MMI_COMPLIST += gdi_arm
UBIN_MMI_COMPLIST += gdi_g2d
UBIN_MMI_COMPLIST += inet_app
UBIN_MMI_COMPLIST += mcsv
UBIN_MMI_COMPLIST += media_app
UBIN_MMI_COMPLIST += mmi_app
UBIN_MMI_COMPLIST += mmi_core
UBIN_MMI_COMPLIST += mmi_device_control
UBIN_MMI_COMPLIST += mmi_framework
UBIN_MMI_COMPLIST += mmi_service
UBIN_MMI_COMPLIST += mmiresource
UBIN_MMI_COMPLIST += mre_custom
UBIN_MMI_COMPLIST += mre_engine
UBIN_MMI_COMPLIST += vendorapp

# BT
UBIN_BT_COMPLIST += btadp
UBIN_BT_COMPLIST += btdrv
UBIN_BT_COMPLIST += btdrv_common
UBIN_BT_COMPLIST += btprofiles
UBIN_BT_COMPLIST += btstack

# Sensor algorithm
UBIN_SENSOR_COMPLIST += sensor_algo
UBIN_SENSOR_COMPOBJS += sensor_subsys\fusion_algo\blood_pressure\lib_core\libbp.lib
UBIN_SENSOR_COMPOBJS += sensor_subsys\fusion_algo\common\lib_core\libcommon.lib
UBIN_SENSOR_COMPOBJS += sensor_subsys\fusion_algo\heart_rate\lib_core\libhr.lib
UBIN_SENSOR_COMPOBJS += sensor_subsys\fusion_algo\ppg_control\lib_core\libppgctrl.lib

ifdef UPDATE_BINARY_PACKAGE
  # MMI_ONLY
  ifeq ($(strip $(UPDATE_BINARY_PACKAGE)),MMI_ONLY)
    UBIN_COMPLIST += $(UBIN_MMI_COMPLIST)
    UBIN_LNKOPT += $(strip $(COMPLIBDIR))\mmi_framework.lib(taskinit.obj)
  endif
  # BT_ONLY
  ifeq ($(strip $(UPDATE_BINARY_PACKAGE)),BT_ONLY)
    UBIN_COMPLIST += $(UBIN_BT_COMPLIST)
    UBIN_LNKOPT += $(strip $(COMPLIBDIR))\btadp.lib(bt_main.obj)
  endif
  # MMI_BT
  ifeq ($(strip $(UPDATE_BINARY_PACKAGE)),MMI_BT)
    UBIN_COMPLIST += $(UBIN_BT_COMPLIST) $(UBIN_MMI_COMPLIST)
    UBIN_LNKOPT += $(strip $(COMPLIBDIR))\mmi_framework.lib(taskinit.obj)
  endif
  # SNESOR_ONLY
  ifeq ($(strip $(UPDATE_BINARY_PACKAGE)),SENSOR_ONLY)
    UBIN_COMPLIST += $(UBIN_SENSOR_COMPLIST)
    UBIN_COMPOBJS += $(UBIN_SENSOR_COMPOBJS)
    UBIN_LNKOPT += $(strip $(COMPLIBDIR))\sensor_algo.lib(sensor_ubin_region_init.obj)
  endif
endif

########################################################################
## Setting
########################################################################
UBIN_COMPLIST_TEMP := $(filter $(UBIN_COMPLIST),$(COMPLIST))
UBIN_COMPLIST := $(call sort, $(UBIN_COMPLIST_TEMP))
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  UBIN_LINKLIST := $(filter $(UBIN_COMPLIST),$(CUS_REL_MTK_COMP))
  UBIN_COMPLIST := $(call sort, $(filter $(UBIN_COMPLIST),$(CUS_REL_SRC_COMP)))
else
  UBIN_LINKLIST := 
endif
UBIN_COMPLIBLIST := $(UBIN_COMPLIST)
