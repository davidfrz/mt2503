# Define source file lists to SRC_LIST
SRC_LIST = plutommi\MMI\Resource\ResThirdROMUtil.c \
           plutommi\Customer\CustResource\CustFontMapExt.c \
           plutommi\Customer\CustResource\CustFontResExt.c \
           plutommi\Customer\CustResource\CustENFBImgMap.c \
           plutommi\Customer\CustResource\CustAdoMap.c \
           plutommi\Customer\CustResource\CustAdoRes.c \
           plutommi\Customer\CustResource\CustAdoMapExt.c \
           plutommi\Customer\CustResource\CustAdoResExt.c \
           plutommi\Customer\CustResource\CustBinaryMap.c \
           plutommi\Customer\CustResource\CustBinaryRes.c \
           plutommi\Customer\CustResource\CustMenuRes.c \
           plutommi\Customer\CustResource\CustVenusAppIconData.c \
           plutommi\Customer\CustResource\CustVenusThemeData.c \
           plutommi\Customer\CustResource\mmi_rp_app_data.c \
           plutommi\Customer\CustResource\mmi_rp_native_app_package_data.c \
           plutommi\Customer\CustResource\mmi_rp_menu_misc_data.c \
           plutommi\Customer\CustResource\mmi_rp_file_type_table.c \
           plutommi\Customer\CustResource\mmi_rp_callback_mgr_table.c \
           plutommi\Customer\CustResource\mmi_cache_table.c \
           plutommi\Customer\CustResource\FontRes.c \
           plutommi\Customer\CustResource\FontData.c \
           plutommi\Customer\CustResource\FontType.c \
           plutommi\Customer\CustResource\ThemeRes.c \
           plutommi\Customer\CustResource\gui_wrapper.c \
           plutommi\Customer\CustResource\CustMiscData.c \
           plutommi\customer\CustResource\resource_audply_skins.c \
           plutommi\customer\CustResource\resource_audply_sub_skins.c \
           plutommi\customer\CustResource\resource_abrepeat_skins.c \
           plutommi\customer\CustResource\resource_mediaplayer_skins.c \
           plutommi\Customer\CustResource\resource_camera_skins.c \
           plutommi\Customer\CustResource\resource_video_skins.c \
           plutommi\Customer\CustResource\resource_vt_skins.c \
           plutommi\Customer\CustResource\resource_barcodereader_skins.c \
           plutommi\Customer\CustResource\resource_lang_pack_jtbl.c \
           plutommi\Customer\CustResource\resource_autogen_audio_jtbl.c \
           plutommi\Customer\CustResource\resource_world_clock_city.c \
           plutommi\Customer\CustResource\CustCoordinates.c \
           plutommi\MMI\Resource\StandaloneRes.c \
           plutommi\mmi\resource\populateres.c \
           plutommi\mmi\resource\readres.c \
           plutommi\mmi\resource\ReadThemeRes.c \
           plutommi\mmi\resource\ABMLoader.c \
           plutommi\mmi\resource\OTFRes.c \
           plutommi\mmi\resource\MemoryRes.c \
           plutommi\mmi\resource\CompressResUtil.c \
           plutommi\mmi\resource\ResCacheUtil.c \
           plutommi\mmi\resource\ResCache.c \
           plutommi\Customer\CustResource\resource_calc_coordinates.c \
           plutommi\Customer\CustResource\IMERes.c \
           plutommi\Customer\CustResource\resource_aud_eq_values.c \
           plutommi\Customer\CustResource\resource_langln_lk_skins.c \
           plutommi\Customer\CustResource\resource_camcorder_skins.c \
           plutommi\Customer\CustResource\resource_sndrec_skins.c \
           plutommi\Customer\CustResource\resource_bcr_skins.c \
           plutommi\Customer\CustResource\resource_ecompass.c \
           plutommi\Customer\CustResource\qwerty_lang_res.c

ifeq ($(filter __POPULATE_NO_IMAGE_DATA__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=plutommi\Customer\CustResource\CustImgGroupDataRes_0.c \
           plutommi\Customer\CustResource\CustImgGroupDataRes_1.c \
           plutommi\Customer\CustResource\CustImgGroupDataRes_2.c \
           plutommi\Customer\CustResource\CustImgGroupDataRes_3.c \
           plutommi\Customer\CustResource\CustImgGroupMap.c \
           plutommi\Customer\CustResource\CustImgGroupRes.c \
           plutommi\Customer\CustResource\CustImgMap.c \
           plutommi\Customer\CustResource\CustImgRes.c \
           plutommi\Customer\CustResource\CustImgDataRes_0.c\
           plutommi\Customer\CustResource\CustImgDataRes_1.c\
           plutommi\Customer\CustResource\CustImgDataRes_2.c\
           plutommi\Customer\CustResource\CustImgDataRes_3.c\
           plutommi\Customer\CustResource\CustImgGroupSingleDataRes.c \
           plutommi\Customer\CustResource\CustImgGroup3rdROMMap.c \
           plutommi\Customer\CustResource\CustImgGroup3rdROMRes.c \
           plutommi\Customer\CustResource\CustImgGroupSingleData3rdROMRes.c \
           plutommi\Customer\CustResource\CustImgMapExt.c \
           plutommi\Customer\CustResource\CustImgResExt.c \
           plutommi\Customer\CustResource\resource_image_jtbl.c \
           plutommi\Customer\CustResource\mmi_rp_img_misc_data.c
endif

ifeq ($(filter __POPULATE_NO_STRING_DATA__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=plutommi\Customer\CustResource\CustStrMap.c \
           plutommi\Customer\CustResource\CustStrRes.c \
           plutommi\Customer\CustResource\CustStrSearchComp.c \
           plutommi\Customer\CustResource\CustStrResComp.c \
           plutommi\Customer\CustResource\CustStrMapComp.c 
endif         
           
ifneq ($(filter __PLUTO_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
    ifeq ($(filter __DISABLE_SHORTCUTS_IMPL__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Customer\CustResource\mmi_rp_menu_shortcut_data.c \
                    plutommi\Customer\CustResource\resource_shortcuts.c
    endif
endif

ifeq ($(filter __MMI_BTBOX_NOLCD__, $(strip $(MODULE_DEFS))),)
ifeq ($(filter __IOT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\customer\CustResource\resource_fmradio_skins.c \
           plutommi\customer\CustResource\resource_fmradio_sub_skins.c \
           plutommi\customer\CustResource\resource_fmschedulerec_skins.c
endif
endif
#  Define include path lists to INC_DIR
INC_DIR = applib\mem\include \
          applib\misc\include \
          drv\include \
          dp_engine\che\include \
          plutommi\mmi\asyncevents\AsyncEventsInc \
          plutommi\mmi\Audio\AudioInc \
          plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc \
          plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc \
          plutommi\Customer\custresource \
          plutommi\mmi\DateTime\DateTimeInc \
          plutommi\Framework\DebugLevels\debuglevelInc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\History\historyInc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\Framework\NVRAMManager\NVRAMManagerInc \
          plutommi\mmi\FunAndGames\FunAndGamesInc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\MMI\IdleScreen\IdleScreenInc\DemoAppInc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\MenuID \
          plutommi\mmi\MainMenu\MainMenuInc \
          plutommi\mmi\Messages\MessagesInc \
          plutommi\MMI\Messages \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\mmi\phonebook\PhonebookInc \
          plutommi\mmi\profiles\ProfilesInc \
          plutommi\mmi\Resource\Inc \
          plutommi\mmi\sat\satInc \
          plutommi\mmi\Setting\SettingInc \
          plutommi\AppCore\ssc \
          plutommi\MtkApp\MtkAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\MtkApp\SoundRecorder\SoundRecorderInc \
          plutommi\MtkApp\Sndrec\SndrecInc \
          plutommi\MtkApp\AudioPlayer\AudioPlayerInc \
          plutommi\MtkApp\ABRepeater\ABRepeaterInc \
          plutommi\Framework\CSBrowser\CSBrowserInc \
          plutommi\MtkApp\FMRadio\FMRadioInc \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          plutommi\MtkApp\MOT\MOTInc  \
          plutommi\MtkApp\FMScheduleRec\FMScheduleRecInc \
          plutommi\MtkApp\FileMgr\FileMgrInc \
          plutommi\MMI\gpio\gpioInc \
          plutommi\MMI\DataAccount\DataAccountInc \
          plutommi\MMI\Help\HelpInc \
          plutommi\MMI\Extra\ExtraInc \
          plutommi\MMI\Organizer\OrganizerInc \
          plutommi\mmi\Organizer\IndianCalendar\IndianCalendarInc \
          plutommi\mmi\ATHandler\ATHandlerInc \
          plutommi\mmi\NITZHandler\NITZInc \
          plutommi\Framework\CommonScreens\commonscreensInc \
          plutommi\mmi\CPHS\CPHSInc \
          plutommi\Customer\CustomerInc \
          plutommi\Customer\Customize \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\MtkApp\Camcorder\CamcorderInc \
          plutommi\MtkApp\Video\VideoInc \
          plutommi\Framework\GDI\GDIInc \
          plutommi\mtkapp\mmiapi\include \
          fmt\include \
          plutommi\MtkApp\vObjects\vObjectInc \
          plutommi\MtkApp\VRSD\VRSDInc \
          plutommi\MtkApp\PhotoEditor\PhotoEditorInc \
          plutommi\CUI\PhotoEditorCui \
          verno \
          plutommi\MtkApp\JavaAgency\JavaAgencyInc \
          plutommi\mmi\EbookReader\EbookInc \
          plutommi\mmi\Dictionary\DictInc \
          plutommi\MMI\VoIP\VoIPInc \
          plutommi\Service\Inc \
          plutommi\MMI\UnifiedMessage\UnifiedMessageInc \
          plutommi\Mtkapp\DLAgent\DLAgentInc \
          plutommi\mtkapp\RightsMgr\RightsMgrInc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\mmi\CertificateManager\CertificateManagerMMIInc \
          security\certman\include \
          plutommi\MMI\CubeApp\CubeAppInc \
          plutommi\service\MDI\MDIInc \
          plutommi\Service\ImgEdtSrv \
          plutommi\service\MRESrv \
          plutommi\CUI\Inc \
          plutommi\mmi\Bootup\BootupInc \
          plutommi\Service\UmmsSrv \
          plutommi\mmi\idle\idleinc \
          plutommi\mmi\ScrLocker\ScrLockerInc \
          plutommi\mmi\ScrSaver\ScrSaverInc \
          vendor\game_engine\brogent\adaptation \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\Cosmos\ucm \
          plutommi\mtkapp\barcodereader\barcodereaderinc \
          plutommi\Framework\GDI\GDIINC \
          vendor\game_engine\intergrafx\adaptation \
          plutommi\MtkApp\Avatar\AvatarInc \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\MtkApp\Camcorder\CamcorderInc \
          plutommi\service\MDI\MDIInc \
          plutommi\mmi\UnifiedMMS\MMSApp\MMSAppInc \
          plutommi\Service\UmmsSrv \
          custom\common\pluto_mmi \
          custom\common custom\common\hal custom\common\ps \
          plutommi\MMI\BrowserApp\Browser\BrowserInc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\MemManager\memmanagerinc \
          plutommi\Framework\DebugLevels\debuglevelinc \
          plutommi\mtkapp\mmiapi\include \
          plutommi\mtkapp\mtkappinc \
          plutommi\MtkApp\MobileTVPlayer\MobileTVPlayerInc \
          plutommi\MtkApp\DTVPlayer\DTVPlayerInc \
          plutommi\MtkApp\MobileTVPlayer\MtvSMSInc \
          plutommi\MtkApp\PhotoEditor\PhotoEditorInc \
          plutommi\mtkapp\ABRepeater\ABRepeaterInc \
          plutommi\mtkapp\connectivity\connectivityinc\btmtk \
          plutommi\mtkapp\connectivity\connectivityinc\btcommon \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          media\common\include \
          media\image\include \
          plutommi\mtkapp\filemgr\filemgrinc \
          fmt\include \
          plutommi\mmi\datetime\datetimeinc \
          vendor\wap\obigo_q03c\adaptation\integration\include \
          plutommi\Framework\InputMethod\inc \
          plutommi\customer\customerinc \
          plutommi\MMI\miscframework\miscframeworkinc \
          plutommi\mmi\inc\menuid \
          plutommi\mmi\audio\audioinc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\mmi\idlescreen\idlescreeninc \
          plutommi\mmi\profiles\profilesinc \
          plutommi\mmi\phonebook\phonebookinc \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          venusmmi\app\common\data \
          plutommi\mmi\Organizer\OrganizerInc \
          plutommi\mtkapp\Video\VideoInc \
          plutommi\service\inc \
          plutommi\mtkapp\MREAPP\MREAPPInc \
          plutommi\mtkapp\MSpace\MSpaceInc \
          plutommi\mmi\BrowserApp\Browser\BrowserInc \
          plutommi\Service\BrowserSrv \
          plutommi\MtkApp\WgtMgrApp\WgtMgrAppInc \
          vendor\opera\browser\adaptation\inc \
          plutommi\mmi\Setting\SettingInc \
          plutommi\mmi\emailapp\emailappinc \
          venusmmi\app\Cosmos\interface\app \
          hal\peripheral\inc \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          xmlp\include \
          vendor\InputMethod\Komoxo\inc \
          venusmmi\vrt\interface \
          venusmmi\framework \
          venusmmi\framework\interface \
          venusmmi\framework\mmi_core \
          venusmmi\framework\ui_core\base \
          venusmmi\framework\ui_core\mvc \
          venusmmi\framework\ui_core\pme \
          venusmmi\framework\xml \
          venusmmi\app \
          venusmmi\app\common \
          venusmmi\app\common\interface \
          venusmmi\app\common\interface\service \
          venusmmi\app\common\interface\app \
          venusmmi\app\common\clipboard \
          venusmmi\app\common\launcher \
          venusmmi\app\common\screen_lock \
          venusmmi\app\common\wallpaper \
          venusmmi\app\common\data \
          venusmmi\app\common\ime \
          venusmmi\app\common\ncenter \
          venusmmi\app\pluto_variation\ncenter \
          venusmmi\app\pluto_variation \
          venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\app\pluto_variation\adapter\interface\trc \
          venusmmi\app\pluto_variation\adapter\Framework \
          venusmmi\app\pluto_variation\adapter\GUI \
          venusmmi\app\pluto_variation\Launcher\Drawer \
          venusmmi\app\pluto_variation\LauncherKey\Mainmenu \
          venusmmi\test \
          venusmmi\visual \
          venusmmi\visual\interface \
          venusmmi\visual\cp \
          venusmmi\visual\cp\common \
          venusmmi\visual\cp\cosmos \
          venusmmi\visual\cp\fte \
          venusmmi\app\Cosmos\WidgetDelegator \
          venusmmi\app\Cosmos\Launcher \
          venusmmi\app\Cosmos\LauncherCosmos\MM \
          venusmmi\app\Cosmos\LauncherRobot\Mainmenu \
          venusmmi\app\Cosmos\ScreenLock \
          plutommi\Service\RightsMgr \
          venusmmi\app\Cosmos\LauncherMM \
          plutommi\CUI\MenuCui \
          plutommi\MtkApp\ImageView\ImageViewInc \
          plutommi\CUI\BookmarkCui \
          vendor\opera\browser\v1_official\opdev\include \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen \
          plutommi\MMI\ShellApp\ShellAppInc \
          plutommi\MMI\Idle\IdleInc \
          plutommi\MMI\AppList\AppListInc \
          venusmmi\app\pluto_variation\LauncherKey\widget\musicplayer \
          venusmmi\app\pluto_variation\LauncherKey\Home \
          plutommi\cui\ImageClipCui\ImageClipCuiInc \
          hal\system\init\inc

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif

ifneq ($(filter  __MMI_MEGAPHONE_SUPPORT__ , $(strip $(MODULE_DEFS))),)
INC_DIR += plutommi\mtkapp\Megaphone\MegaphoneInc
endif

ifneq ($(filter __TCPIP__, $(strip $(MODULE_DEFS))),)
    ifneq ($(filter __MMI_WLAN_FEATURES__, $(strip $(MODULE_DEFS))),)
		INC_DIR += plutommi\Service\DtcntSrv
			ifeq ($(filter __WIFI_SCAN_ONLY__, $(strip $(MODULE_DEFS))),)
				INC_DIR += plutommi\Service\WlanSrv
		endif
    endif
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P  \
            __EMS__ \
            SIM_APP_TOOLKIT \
            TETRIS_GAME_APP \
            CM_APPLICATION_ENABLE \
            MESSAGES_APPLICATION \
            __UCS2_ENCODING \
            CELLBROADCAST_APP \
            __CB__ \
            VM_SUPPORT \
            SHORTCUTS_APP \
            T9LANG_Chinese \
            T9LANG_English \
            EMS_LITTLE_ENDIAN \
            EMS_MEM_MANAGEMENT \
            T9ALPHABETIC \
            T9CHINESE
ifneq ($(filter __LINE_IN_SUPPORT__, $(strip $(MODULE_DEFS))),)
INC_DIR += plutommi\mtkapp\Linein\LineinInc
endif

ifneq ($(filter __KARAOKE_SUPPORT__, $(strip $(MODULE_DEFS))),)
INC_DIR += plutommi\mtkapp\Karaoke\KaraokeInc
endif

