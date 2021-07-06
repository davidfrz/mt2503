# Define include path lists to INC_DIR
INC_DIR = applib\inet\engine\include \
          applib\mem\include \
          applib\misc\include \
          drv\include \
          fmt\include \
          fs\fat\include \
          interface\hwdrv \
          interface\wifi \
          $(strip $(PS_FOLDER))\interfaces\local_inc \
          plutommi\customer\customerinc \
          plutommi\customer\customize \
          plutommi\customer\custresource \
          plutommi\mmi\asyncevents\asynceventsinc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\menuid \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\EventHandling\eventsinc \
          plutommi\Framework\History\historyinc \
          plutommi\Framework\MemManager\memmanagerinc \
          plutommi\Framework\NVRAMManager\nvrammanagerinc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\ThemeManager\thememanagerinc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\service\mdi\mdiinc \
          plutommi\Service\ImgEdtSrv \
          plutommi\mtkapp\mtkappinc \
          vendor\inputmethod\cstar\adaptation\include \
          vendor\inputmethod\t9\adaptation\include \
          venusmmi\app\pluto \
          blueangel\btcore\btstack\inc \
          drm\include \
          gps\inc \
          irda\inc \
          j2me\interface \
          j2me\jal\include \
          j2me\jal\include \
          media\image\include \
          media\rtp\inc \
          media\stream\include \
          media\mtv\src \
          media\mtv\include \
          usb\include \
          verno \
          wapadp\include \
          xmlp\include \
          vcard\include \
          plutommi\CUI\Inc \
          plutommi\CUI\InlineCui \
          plutommi\mmi\athandler\athandlerinc \
          plutommi\mmi\audio\audioinc \
          plutommi\Framework\BIDI\bidiinc \
          plutommi\mmi\browserapp\browser\browserinc \
          plutommi\mmi\browserapp\pushinbox\pushinboxinc \
          plutommi\MMI\CertificateManager\CertificateManagerMMIInc \
          security\certman\include \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\MMI\ConnectManagement\ConnectManagementInc \
          plutommi\mmi\cphs\cphsinc \
          plutommi\mmi\customerservice\customerserviceinc \
          plutommi\mmi\dataaccount\dataaccountinc \
          plutommi\mmi\datetime\datetimeinc \
          plutommi\Framework\DebugLevels\debuglevelinc \
          plutommi\mmi\dictionary\dictinc \
          plutommi\mmi\ebookreader\ebookinc \
          plutommi\mmi\emailapp\emailappinc \
          plutommi\service\ProvisioningSrv \
          plutommi\mmi\extra\extrainc \
          plutommi\mmi\funandgames\funandgamesinc \
          plutommi\mmi\gpio\gpioinc \
          plutommi\mmi\gsmcallapplication\commonfiles\commoninc \
          plutommi\mmi\gsmcallapplication\incomingcallmanagement\incominginc \
          plutommi\mmi\gsmcallapplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\help\helpinc \
          plutommi\mmi\idlescreen\idlescreeninc \
          plutommi\mmi\idlescreen\idlescreeninc\demoappinc \
          plutommi\MMI\Factory\FactoryInc \
          plutommi\MMI\Idle\IdleInc \
          plutommi\MMI\Dialer\DialerInc \
          plutommi\MMI\ScrLocker\ScrLockerInc \
          plutommi\MMI\ScrSaver\ScrSaverInc \
          plutommi\mmi\imps\impsinc \
          plutommi\Framework\IndicLanguages\indiclanguagesinc \
          plutommi\Framework\Languages\thai\thaiinc \
          plutommi\mmi\mainmenu\mainmenuinc \
          plutommi\mmi\messages \
          plutommi\CUI\SsoCui\SsoCuiInc \
          plutommi\MMI\SSOAPP\SSOAPPInc \
          plutommi\mmi\messages\messagesinc \
          plutommi\mmi\mobileservice\mobileserviceinc \
          plutommi\mmi\nitzhandler\nitzinc \
          plutommi\mmi\organizer\Organizerinc \
          plutommi\mmi\Organizer\IndianCalendar\IndianCalendarInc \
          plutommi\mmi\Organizer\Reminder \
          plutommi\mmi\phonebook\phonebookinc \
          plutommi\mmi\phonebook\core \
          plutommi\mmi\profiles\profilesinc \
          plutommi\mmi\resource\inc \
          plutommi\mmi\sat\satinc \
          plutommi\mmi\setting\settinginc \
          plutommi\mmi\SecuritySetting\SecSetInc \
          plutommi\mmi\smartmessage\smartmessageinc \
          plutommi\mmi\ucm\ucminc \
          plutommi\mmi\BT_UCM\UcmBTInc\
          plutommi\mmi\ctm\ctminc \
          plutommi\service\Inc \
          plutommi\service\UmSrv \
          plutommi\mmi\unifiedmessage\unifiedmessageinc \
          plutommi\Service\UcSrv \
          plutommi\mmi\unifiedcomposer\unifiedcomposerinc \
          venusmmi\app\pluto_variation\CubeApp \
          plutommi\mmi\CubeApp\CubeAppInc \
          plutommi\mmi\unifiedmms\mmsapp\mmsappinc \
          plutommi\Service\UmmsSrv \
          plutommi\mmi\voip\voipinc \
          plutommi\mmi\Organizer\HijriCalendar\HijriCalendarInc \
          plutommi\mtkapp\abrepeater\abrepeaterinc \
          plutommi\MtkApp\AGPSLog\AGPSLogInc \
          plutommi\mtkapp\audioplayer\audioplayerinc \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          plutommi\mtkapp\avatar\avatarinc \
          plutommi\mtkapp\barcodereader\barcodereaderinc \
          plutommi\mtkapp\bgsound\bgsoundinc \
          plutommi\mtkapp\camera\camerainc \
          plutommi\MtkApp\ImageView\ImageViewInc \
          plutommi\mtkapp\camcorder\camcorderinc \
          plutommi\mtkapp\centralconfigagent\centralconfigagentinc \
          plutommi\mtkapp\connectivity\connectivityinc \
          plutommi\mtkapp\connectivity\connectivityinc\btcommon \
          plutommi\mtkapp\connectivity\connectivityinc\btmtk \
          plutommi\Framework\CSBrowser\csbrowserinc \
          plutommi\mtkapp\DCD\DCDInc \
          plutommi\mtkapp\dlagent\dlagentinc \
          plutommi\mtkapp\dmuiapp\dmuiappinc \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\mtkapp\FactoryMode\FactoryModeInc \
          custom\common\hal \
          plutommi\mtkapp\filemgr\filemgrinc \
          plutommi\mtkapp\fmradio\fmradioinc \
          plutommi\mtkapp\fmschedulerec\fmschedulerecinc \
          plutommi\mtkapp\GPS\GPSInc \
          plutommi\mtkapp\javaagency\javaagencyinc \
          plutommi\mtkapp\mmiapi\include \
          plutommi\mtkapp\mobiletvplayer\mobiletvplayerinc \
          plutommi\MtkApp\MobileTVPlayer\MtvSMSInc \
          plutommi\mtkapp\dtvplayer\dtvplayerinc \
          plutommi\mtkapp\myfavorite\myfavoriteinc \
          plutommi\mtkapp\photoeditor\photoeditorinc \
          plutommi\mtkapp\pictbridge\pictbridgeinc \
          plutommi\mtkapp\rightsmgr\rightsmgrinc \
          plutommi\MtkApp\SoftwareTracer\SoftwareTracerInc \
          plutommi\mtkapp\soundrecorder\soundrecorderinc \
          plutommi\mtkapp\sndrec\sndrecinc \
          plutommi\mtkapp\answermachine\answermachineinc \
          plutommi\mtkapp\swflash\swflashinc \
          plutommi\mtkapp\syncml\syncmlinc \
          plutommi\mtkapp\video\videoinc \
          plutommi\mtkapp\vobjects\vobjectinc \
          plutommi\mtkapp\vrsd\vrsdinc \
          plutommi\mtkapp\vrsi\vrsiinc \
          plutommi\mtkapp\searchweb\searchwebinc \
          plutommi\vendorapp\devapp\devappinc \
          vendor\dict\gv\adaptation\inc \
          vendor\dict\motech\adaptation\inc \
          vendor\dict\trilogy\adaptation\inc \
          vendor\game_engine\brogent\adaptation \
          vendor\game_engine\brogent\game \
          vendor\game_engine\intergrafx\adaptation \
          vendor\game_engine\intergrafx\game \
          vendor\swflash\neomtel\adaptation\inc \
          vendor\wap\obigo_q05a\adaptation\integration\owl\include \
          vendor\wap\obigo_q05a\adaptation\modules\bam\include \
          vendor\wap\obigo_Q03C\v1_official\modules\bra\config \
          vendor\wap\obigo_Q03C\v1_official\modules\bra\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\bra\source \
          vendor\wap\obigo_Q03C\v1_official\modules\mea\intgr \
          vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\include \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\include \
          vendor\mobilevideo\adaption\MobileVideoInc\include_CM \
          vendor\mobilevideo\adaption\MobileVideoInc\include \
          plutommi\mmi\SIMProvAgent\SIMProvAgentInc \
          plutommi\mmi\UDX\UDXInc \
          vendor\qqim\adaptation\inc \
          plutommi\Service\ProvBoxSrv \
          plutommi\mmi\ProvisioningInbox\ProvBoxApp\ProvBoxAppInc \
          init\include \
          $(strip $(PS_FOLDER))\l4\include \
          venusmmi\vrt\interface \
          venusmmi\framework \
          venusmmi\framework\interface \
          venusmmi\visual \
          venusmmi\visual\interface \
          venusmmi\app\pluto_variation\interface \
          venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\test \
          venusmmi\app \
          venusmmi\app\pluto_variation \
          venusmmi\app\common\wallpaper \
          venusmmi\app\common\ncenter \
          venusmmi\app\common\interface\app \
          venusmmi\framework\ui_core\mvc \
          venusmmi\app\common\data \
          plutommi\mtkapp\MREAPP\MREAPPInc \
          plutommi\mtkapp\MSpace\MSpaceInc \
          plutommi\Service\MRESrv \
          plutommi\CUI\ToneSelectorCui \
          plutommi\Framework\LangModule\LangModuleInc \
          plutommi\MMI\Bootup\BootupInc \
          plutommi\MMI\NwInfo\NwInfoInc \
          plutommi\MMI\SimCtrl\SimCtrlInc \
          plutommi\MMI\Shutdown\ShutdownInc \
          plutommi\mmi\q03c_mms_V01_agent\q03c_mms_V01_agentinc \
          plutommi\Service\MediaCacheSrv \
          plutommi\Service\inc \
          plutommi\MtkApp\WgtMgrApp\WgtMgrAppInc \
          plutommi\MMI\CallSetting\CallSettingInc \
          plutommi\MMI\SupplementaryService\SsInc \
          vendor\opera\browser\adaptation\inc \
          plutommi\Service\NetSetSrv \
          plutommi\Service\ModeSwitchSrv \
          plutommi\Service\ProfilesSrv \
          plutommi\MMI\ShellApp\ShellAppInc \
          venusmmi\app\pluto_variation\ShellApp\base \
          venusmmi\app\pluto_variation\ShellApp\panel \
          venusmmi\app\pluto_variation\adapter\ShellApp\base \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel \
          plutommi\mmi\CallLog\CallLogInc \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\MsgViewer\
          venusmmi\app\pluto_variation\ShellApp\panel\HomeScreen \
          venusmmi\app\pluto_variation\adapter\MultiTouchTest \
          vendor\opera\browser\v1_official\opdev\include \
          operator\ORANGE\common\venusmmi\pluto_adapter\interface\res \
          operator\ORANGE\common\venusmmi\pluto_adapter\HomeScreen \
          operator\ORANGE\common\venusmmi\app\HomeScreen \
          operator\ORANGE\common\venusmmi \
          mmi_core\app\SupplementaryService \
          plutommi\mmi\SimSpace\SimSpaceInc \
          plutommi\CUI\SimSelCui \
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\SDK_Layer\SDK_Inc \
          plutommi\Framework\InputMethod\UI\UI_Inc \
          hal\storage\mc\inc \
          plutommi\mtkapp\Lemei\LemeiInc \
          plutommi\Service\Inc \
          plutommi\Service\UPPSrv \
          hal\video\custom \
          custom\video \
          interface\hal\display\common \
          interface\ps\enum \
          meta\cct \
          plutommi\Service\DmSRsrv \
          vendor\widget\google\adaptation \
          interface\nfc \
          plutommi\CUI\UseDetailCui \
          interface\hal\video_codec \
          custom\drv\measure\Inc \
          custom\common\hal_public \
          custom\codegen\$(strip $(BOARD_VER))\
          interface\hal\graphics \
          interface\hal\fmr \
          plutommi\Service\RightsMgr \
          plutommi\AppCore\SSC \
          venusmmi\app\pluto_variation\LauncherKey\widget\musicplayer \
          plutommi\AppCore\Ucm \
          plutommi\cui\ImageClipCui\ImageClipCuiInc \
          plutommi\Service\TcardSrv \
          plutommi\MtkApp\SafeMode\SafeModeInc \
          hal\system\dcmgr\inc \
          plutommi\Service\SmsSrv \
          plutommi\Service\SmsbtmapcSrv \
          plutommi\mmi\SmsbtmapcApp\SmsbtmapcAppInc \
          plutommi\MMI\BTNotification\BTNotificationInc \
          plutommi\MMI\BtRemoteCapture \
          plutommi\framework\hotknot\inc \
          plutommi\Service\DateTimeSrv

ifneq ($(filter __MMI_BT_DIALER_SUPPORT__ , $(strip $(MODULE_DEFS))),)
INC_DIR += plutommi\MtkApp\BTdialer\BTdialerInc
endif

ifneq ($(filter __MMI_LAUNCHER_APP_LIST__ , $(strip $(MODULE_DEFS))),)
INC_DIR += plutommi\MMI\AppList\AppListInc
endif
          
ifeq ($(filter __MTK_TARGET__ , $(strip $(MODULE_DEFS))),)
INC_DIR += MoDIS_VC9\MoDIS  # for w32_utility.h
endif
          
ifneq ($(filter __RF_DESENSE_TEST__, $(strip $(MODULE_DEFS))),)
  INC_DIR += BTMT\rf_desense\$(strip $(PLATFORM))
endif

ifneq ($(filter __SOCIAL_NETWORK_SUPPORT__ , $(strip $(MODULE_DEFS))),)              
   INC_DIR += plutommi\mmi\sns\snsinc
   INC_DIR += plutommi\cui\SnsCui
endif

ifneq ($(filter __MMI_VPP_UPGRADE__, $(strip $(MODULE_DEFS))),)
   INC_DIR += plutommi\MMI\Upgrade\UpgradeInc
endif

ifneq ($(filter __MMI_BLE_PXP_SUPPORT__ , $(strip $(MODULE_DEFS))),)
   INC_DIR += blueangel\btstd\common\inc
   INC_DIR += plutommi\Service\GattSrv
   INC_DIR += plutommi\Service\GattSrv\pxp 
   INC_DIR += plutommi\mmi\PxpApp\PxpAppInc
endif


ifneq ($(filter __MMI_BLE_ANP_SUPPORT__ , $(strip $(MODULE_DEFS))),)
   INC_DIR += blueangel\btstd\common\inc
   INC_DIR += plutommi\Service\GattSrv
   INC_DIR += plutommi\Service\GattSrv\Anpc
   INC_DIR += plutommi\mmi\AnpApp\AnpAppInc
endif

ifneq ($(filter __MMI_BLE_TIP_SUPPORT__ , $(strip $(MODULE_DEFS))),)
   INC_DIR += blueangel\btstd\common\inc
   INC_DIR += plutommi\Service\GattSrv
   INC_DIR += plutommi\Service\GattSrv\tip
   INC_DIR += plutommi\mmi\TipApp\TipAppInc
endif

ifneq ($(filter __MMI_ONE_KEY_SOS_SUPPORT__ , $(strip $(MODULE_DEFS))),)
   INC_DIR += plutommi\MMI\OneKeySOS\OKSOSInc
endif

ifneq ($(filter __MMI_BLE_FMP_SUPPORT__ , $(strip $(MODULE_DEFS))),)
   INC_DIR += blueangel\btstd\common\inc
   INC_DIR += plutommi\Service\GattSrv	
   INC_DIR += plutommi\Service\GattSrv\fmp
   INC_DIR += plutommi\mmi\FmpApp\FmpAppInc
endif

ifneq ($(filter __MMI_ANCS_IOS8_SUPPORT__ , $(strip $(MODULE_DEFS))),)
   INC_DIR += plutommi\mmi\BTNotiAncs\BTNotiAncsInc
endif

ifneq ($(filter __MMI_HEART_RATE_SUPPORT__ , $(strip $(MODULE_DEFS))),)
   INC_DIR += plutommi\mmi\HeartRateApp\HeartRateInc
endif

ifneq ($(filter __MMI_BLOOD_PRESSURE_SUPPORT__ , $(strip $(MODULE_DEFS))),)
   INC_DIR += plutommi\mmi\BloodPressureApp\BloodPressureInc
endif

ifneq ($(filter __INTELL_MOB_TER_APP__ , $(strip $(MODULE_DEFS))),)
   INC_DIR += plutommi\IntellApp\IntellAppMain\Inc
   SRC_LIST += plutommi\IntellApp\IntellAppMain\Src\IntellAppMain.c
   ifneq ($(filter _MMI_INTELL_SOCKET_,$(strip $(MODULE_DEFS))),) # 添加socket app应用
      INC_DIR += plutommi\IntellApp\Socket\Inc
      SRC_LIST += plutommi\IntellApp\Socket\Src\Socket.c
   endif

   ifneq ($(filter _MMI_INTELL_LOCATION_,$(strip $(MODULE_DEFS))),) # 添加GPS app应用
      INC_DIR += plutommi\IntellApp\Location\Inc
      SRC_LIST += plutommi\IntellApp\Location\Src\gps.c
   endif
endif

