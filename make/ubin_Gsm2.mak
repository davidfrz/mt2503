# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY: FROMELF_UBIN LINK_UBIN LINK_UBIN_CHECK ubin ubin_checklist ubin_clean ubin_cleanall UBIN_POSTBUILD ubin_preflow

# *************************************************************************
#  Settings 
# *************************************************************************
UBIN_LINK_LOG := $(strip $(LOGDIR))\ubin_link.log
UBIN_LINKOPTION := $(strip $(LNKOPT)) $(strip $(UBIN_LNKOPT)) \
                --scatter $(UBIN_SCATTERFILE) \
                --output $(strip $(TARGDIR))\$(UBIN_PREFIX).elf \
                --symdefs $(strip $(TARGDIR))\$(UBIN_PREFIX).sym \
                --list $(strip $(TARGDIR))\$(UBIN_PREFIX).lis \
                --libpath $(DIR_ARMLIB) \
                $(strip $(MBIN_REMOVE_MULTI_DEF_SYMBOL_SYM))

ifeq ($(strip $(UPDATE_BINARY_PACKAGE)),SENSOR_ONLY)
  UBIN_LINKOPTION += --entry sensor_ubin_region_init
else
  ifeq ($(strip $(UPDATE_BINARY_PACKAGE)),BT_ONLY)
    UBIN_LINKOPTION += --entry bt_create
  else
    UBIN_LINKOPTION += --entry mmi_create
  endif
endif

ifneq ($(strip $(UBIN_COMPLIBLIST)),)
  UBIN_COMPLIBLIST := $(call sort,$(foreach comp,$(UBIN_COMPLIBLIST),$(comp).lib))
endif

ifneq ($(strip $(UBIN_LINKLIST)),)
  UBIN_LINKLIST := $(call sort,$(foreach comp,$(UBIN_LINKLIST),$(comp).lib))
endif
# *************************************************************************

ubin: ubin_clean ubin_preflow $(UBIN_BIN_FILE)
# *****************************************************************************************************
# TARGET: ubin_checklist
# *****************************************************************************************************
ubin_checklist:
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'ubin_cleanall START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@if not exist $(strip $(TARGDIR))\$(TARGNAME).sym \
		((echo ==============================================================) &\
		(echo Error: $(strip $(TARGDIR))\$(TARGNAME).sym does NOT exist.) & \
		(echo Now is ubin only mode BUILD_UBIN_ONLY=TRUE,) &\
		(echo please make sure you have been pass in full flow before turn on BUILD_UBIN_ONLY) &\
		(echo ==============================================================) &\
		(exit 1))

	@perl -e "print 'ubin_cleanall END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *****************************************************************************************************
# TARGET: ubin_cleanall
# *****************************************************************************************************
ubin_cleanall: ubin_clean
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'ubin_cleanall START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@echo Cleaning directories under $(strip $(PROJDIR)) ...


	@echo Cleaning directories under $(RULESDIR)
	@for /d %%i in ($(UBIN_COMPLIST)) do (if exist $(strip $(RULESDIR))\%%i.dep (del /q $(strip $(RULESDIR))\%%i.dep))

	@for /d %%i in ($(UBIN_COMPLIST)) do (if exist $(strip $(RULESDIR))\comp_dep\%%i.det del /q $(strip $(RULESDIR))\comp_dep\%%i.det)

	@for /d %%i in ($(UBIN_COMPLIST)) do (if exist $(strip $(OBJSDIR))\%%i \
		( \
			(echo Cleaning object files under %%i) && \
			(if exist $(strip $(OBJSDIR))\%%i\*.obj del /q $(strip $(OBJSDIR))\%%i\*.obj) && \
			(if exist $(strip $(OBJSDIR))\%%i\%%i.lib_bak del $(strip $(OBJSDIR))\%%i\%%i.lib_bak) \
		))
	@echo Cleaning lib files under $(COMPLIBDIR)
	@for /d %%i in ($(UBIN_COMPLIST)) do (if exist $(strip $(COMPLIBDIR))\%%i.lib (del /q $(strip $(COMPLIBDIR))\%%i.lib))

	@if not exist $(BUILDDIR) (md $(BUILDDIR))
	-@if not exist $(TARGDIR) (md $(TARGDIR))
	@if not exist $(COMPLOGDIR) (md $(COMPLOGDIR))
	@if not exist $(PROJDIR) (md $(PROJDIR))
	@if not exist $(RULESDIR) (md $(RULESDIR))
	@if not exist $(strip $(RULESDIR))\codegen_dep (md $(strip $(RULESDIR))\codegen_dep)
	@if not exist $(strip $(RULESDIR))\pregen_dep (md $(strip $(RULESDIR))\pregen_dep)
	@if not exist $(OBJSDIR) (md $(OBJSDIR))
	@if not exist $(strip $(COMPLIBDIR)) (md $(COMPLIBDIR))
	@if not exist $(strip $(RULESDIR))\comp_dep (md $(strip $(RULESDIR))\comp_dep)

	@perl -e "print 'ubin_cleanall END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *****************************************************************************************************
# TARGET: ubin_clean
# *****************************************************************************************************
ubin_clean:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@if exist $(UBIN_LINK_LOG) (del /q $(UBIN_LINK_LOG))
	@if exist $(strip $(TARGDIR))\$(strip $(UBIN_PREFIX)).*  (del /q $(strip $(TARGDIR))\$(strip $(UBIN_PREFIX)).*)
	@if exist $(strip $(TARGDIR))\$(strip $(UBIN_PREFIX))\*  (rd /s /q $(strip $(TARGDIR))\$(strip $(UBIN_PREFIX)))
	@if exist $(strip $(TARGDIR))\$(strip $(UBIN_BIN_FILE))  (del /q $(strip $(TARGDIR))\$(strip $(UBIN_BIN_FILE)))
	@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin\NUL \
		(if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin\$(strip $(UBIN_BIN_FILE)) (del /q $(strip $(TARGDIR))\$(NEWTARGNAME).bin\$(strip $(UBIN_BIN_FILE))))

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *****************************************************************************************************
# TARGET: ubin_clean
# *****************************************************************************************************
ubin_preflow: 
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@echo CUSTOM_RELEASE = $(CUSTOM_RELEASE)
	@echo UBIN_LINKLIST = $(UBIN_LINKLIST)
	@echo UBIN_COMPLIBLIST = $(UBIN_COMPLIBLIST)

	@if not exist $(strip $(UBIN_DEBUG_DIR)) (md $(strip $(UBIN_DEBUG_DIR)))
	@if exist make\~ubinlibs.tmp (del make\~ubinlibs.tmp)
	
ifneq ($(strip $(UBIN_LINKLIST)),)
	@tools\strcmpex.exe def def e make\~ubinlklibs.tmp $(foreach comp,$(UBIN_LINKLIST), '$(CUS_MTK_LIB)\$(comp)')
	@perl tools\lnitem.pl make\~ubinlklibs.tmp
	@if exist make\~ubinlklibs.tmp (type make\~ubinlklibs.tmp >> make\~ubinlibs.tmp)
endif

ifneq ($(strip $(UBIN_COMPLIBLIST)),)
	@tools\strcmpex.exe def def e make\~ubincplibs.tmp $(foreach comp,$(UBIN_COMPLIBLIST), '$(COMPLIBDIR)\$(comp)')
	@perl tools\lnitem.pl make\~ubincplibs.tmp
	@if exist make\~ubincplibs.tmp (type make\~ubincplibs.tmp >> make\~ubinlibs.tmp)
endif
	
ifneq ($(strip $(UBIN_COMPOBJS)),)
	@if exist make\~libs.tmp (del /f /q make\~libs.tmp)
	@perl tools\echoLongString4.pl make\~libs.tmp $(UBIN_COMPOBJS)
	@if exist make\~libs.tmp (type make\~libs.tmp >> make\~ubinlibs.tmp)
endif

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *****************************************************************************************************
# TARGET: $(UBIN_BIN_FILE)
# *****************************************************************************************************
ifeq ($(strip $(BUILD_UBIN_ONLY)),TRUE)
$(UBIN_BIN_FILE): LINK_UBIN FROMELF_UBIN UBIN_POSTBUILD
else
$(UBIN_BIN_FILE): LINK_UBIN LINK_UBIN_CHECK FROMELF_UBIN UBIN_POSTBUILD
endif
LINK_UBIN:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@echo Linking update binary ...
	@perl tools\time.pl -n
	@echo $(UBIN_LINKOPTION) > make\~libs.tmp

	@if exist make\~ubinlibs.tmp (type make\~ubinlibs.tmp >> make\~libs.tmp)

	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(UBIN_COMPOBJS))
	@if exist make\~sortedLibs.tmp (copy /y make\~sortedLibs.tmp $(strip $(COMPLOGDIR))\link_option_ubin.log >nul)
	@copy /y make\~sortedLibs.tmp make\ubin_sortedLibs.keep

	@perl tools\remove_mbin_symbol.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(MBIN_REMOVE_MULTI_DEF_SYMBOL_SYM))>$(strip $(COMPLOGDIR))\remove_mbin_symbol.log 2>&1 & \
		(if ERRORLEVEL 1 (echo Error in remove_mbin_symbol.pl. Please check $(strip $(COMPLOGDIR))\remove_mbin_symbol.log & exit 1))

	@($(LINK) $(VIA) make\~sortedLibs.tmp >> $(UBIN_LINK_LOG) 2>&1) & \
	(if ERRORLEVEL 1 \
				(echo Error: link failed! Please check $(UBIN_LINK_LOG))& \
				(if exist $(UBIN_LINK_LOG)  (copy /Y $(UBIN_LINK_LOG) $(strip $(UBIN_DEBUG_DIR))\ubin_link.log.error >NUL)) & \
				(if exist $(strip $(TARGDIR))\$(UBIN_PREFIX).elf (del /q $(strip $(TARGDIR))\$(UBIN_PREFIX).elf)))

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *****************************************************************************************************
# TARGET: LINK_UBIN_CHECK
# *****************************************************************************************************
LINK_UBIN_CHECK: gen_infomakelog gencompbld
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@if exist $(strip $(MBIN_WITH_ALLLIB_LIS))       (del /q $(strip $(MBIN_WITH_ALLLIB_LIS)))
	@if exist $(strip $(MBIN_KEEP_UBIN_SYMBOL_LIST)) (del /q $(strip $(MBIN_KEEP_UBIN_SYMBOL_LIST)))
	@if exist $(strip $(TARGDIR))\$(TARGNAME).elf (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).elf)
	@if exist $(strip $(TARGDIR))\$(TARGNAME).sym (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).sym)
	@if exist $(strip $(TARGDIR))\$(TARGNAME).lis (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).lis)

	@tools\make.exe -fmake\Gsm2.mak -r -R UPDATE_BINARY_FILE_DUMMY_BUILD=TRUE system_ubin_stripped & \
		(if ERRORLEVEL 1 echo Error: generate system_ubin_stripped failed & exit 1)

	@if exist AAPMC.log (del /q AAPMC.log)
	@tools\make.exe -fmake\Gsm2.mak -r -R MBIN_WITH_ALL_LIBS=TRUE LINK_BIN_FILE LINK_BIN_FILE_CHECK & \
		(if ERRORLEVEL 1 echo Error: MBIN_WITH_ALL_LIBS link error & exit 1)
	@if not exist $(strip $(TARGDIR))\$(TARGNAME).elf (echo Error: MBIN_WITH_ALL_LIBS link error & exit 1)
	@copy /y "$(strip $(TARGDIR))\$(LIS_FILE)" "$(strip $(MBIN_WITH_ALLLIB_LIS))" >NUL
	@if exist $(LOG) (copy /y "$(LOG)" "$(strip $(UBIN_DEBUG_DIR))\mbin_with_all_lib_link.log" >NUL)

	@tools\IOTFota\keep_sym_gen.exe $(strip $(MBIN_WITH_ALLLIB_LIS)) $(INFOMAKELOG) $(strip $(UBIN_DEBUG_DIR))\ubin_link.log.error $(strip $(COMPLOGDIR)) & \
		(if ERRORLEVEL 1 (echo Error in tools\IOTFota\keep_sym_gen.exe. Please check $(strip $(COMPLOGDIR))\keep_sym_gen.log & exit 1))
	@copy /y "$(strip $(COMPLOGDIR))\ubin_keep_sym.txt" "$(strip $(MBIN_KEEP_UBIN_SYMBOL_LIST))" >NUL

	@if exist $(strip $(TARGDIR))\$(TARGNAME).elf (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).elf)
	@if exist $(strip $(TARGDIR))\$(TARGNAME).sym (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).sym)
	@if exist $(strip $(TARGDIR))\$(TARGNAME).lis (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).lis)

	@tools\make.exe -fmake\Gsm2.mak -r -R system_ubin_recover & \
		(if ERRORLEVEL 1 echo Error: generate system_ubin_recover failed & exit 1)

	@if exist AAPMC.log (del /q AAPMC.log)
	@tools\make.exe -fmake\Gsm2.mak -r -R cleanbin LINK POSTBUILD_CHECK  & \
		(if ERRORLEVEL 1 (echo Error: MBIN link error) & (exit 1))
	@tools\make.exe -fmake\Gsm2.mak -r -R ubin_clean ubin_preflow LINK_UBIN & \
		(if ERRORLEVEL 1 (echo Error: UBIN link error) & (exit 1))

	
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *****************************************************************************************************
# TARGET: FROMELF_UBIN
# *****************************************************************************************************
FROMELF_UBIN:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@echo Creating binary file $(UBIN_BIN_FILE)
	@if not exist $(strip $(TARGDIR))\$(UBIN_PREFIX).elf \
		(echo Error: $(strip $(TARGDIR))\$(UBIN_PREFIX).elf does not exist! Please check link error for update binary. & exit 1)

	$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(UBIN_PREFIX).elf $(BIN_FORMAT) --output $(strip $(TARGDIR))\$(UBIN_BIN_FILE)
	@if not exist $(strip $(TARGDIR))\$(UBIN_BIN_FILE) \
		(echo Error: $(strip $(TARGDIR))\$(UBIN_BIN_FILE) does not exist! Please check link error for update binary. & exit 1)

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *****************************************************************************************************
# TARGET: UBIN_POSTBUILD
# *****************************************************************************************************
UBIN_POSTBUILD:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@echo UBIN POSTBUILD begin...

# gfh_process
ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
	@if not exist make\~gfh_cfg.tmp (tools\make.exe -fmake\gsm2.mak -r -R gen_gfh_cfg)
	@echo $(strip $(TARGDIR))\$(strip $(UBIN_BIN_FILE))> make\~gfh_files.tmp
	@perl tools\gfh_process.pl make\~gfh_files.tmp make\~gfh_cfg.tmp $(strip $(THE_MF)) $(strip $(GFH_PROCESS_TYPE))> $(strip $(COMPLOGDIR))\gfh_process_ubin.log 2>&1 & \
	(if ERRORLEVEL 1 (echo Error: Failed in gfh_process.pl. Please check $(strip $(COMPLOGDIR))\gfh_process_ubin.log & exit 1))
endif

# copy UBIN to bin folder
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(if exist $(strip $(TARGDIR))\$(strip $(UBIN_BIN_FILE)) \
			copy /y $(strip $(TARGDIR))\$(strip $(UBIN_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(UBIN_BIN_FILE)) >NUL) \
	else \
		if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
			(if exist $(strip $(TARGDIR))\$(strip $(UBIN_BIN_FILE)) \
				copy /y $(strip $(TARGDIR))\$(strip $(UBIN_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(UBIN_BIN_FILE)) >NUL) \
		else \
			(echo Error: $(strip $(TARGDIR))\$(strip $(BIN_FILE)) does not exist! Please check link error for mbin. & exit 1)


	@echo UBIN POSTBUILD end...
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *****************************************************************************************************
# TARGET: UBIN_POSTBUILD
# *****************************************************************************************************
system_ubin_recover system_ubin_stripped:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@if exist $(strip $(OBJSDIR))\system_ubin\*.obj (del $(strip $(OBJSDIR))\system_ubin\*.obj)
	@if exist $(COMPLIBDIR)\system_ubin.lib (del $(COMPLIBDIR)\system_ubin.lib)
	@tools\make.exe -fmake\Gsm2.mak -r -R XGC_AND_NOT_BOOTLOADER=FALSE system_ubin.lib & \
		(if ERRORLEVEL 1 echo Error: $@ failed & exit 1)

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

