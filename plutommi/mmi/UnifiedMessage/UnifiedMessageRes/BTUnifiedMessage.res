/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#ifdef __UM_SUPPORT__
#include "custresdef.h"
#include "CustomCfg.h"

#if defined( __MMI_WEARABLE_DEVICE__) && defined(__MMI_BT_MAP_CLIENT__)

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_BT_UNIFIEDMESSAGE"
#if defined (__MMI_APP_MANAGER_SUPPORT__)
    package_name="native.mtk.btmessaging"
    name="STR_ID_BT_UM_MAIN_MENU_MESSAGES_TEXT"
    launch="mmi_um_entry_main_message_enter_bt_msg"
#endif /*defined (__MMI_APP_MANAGER_SUPPORT__)*/
> 
  
<!----------------- XML Begin ------------------------------------------------->

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_BT_UM_MAIN_MENU_MESSAGES_TEXT"/> 
    
    
<!----------------- XML END --------------------------------------------------->
</APP>
#endif /*defined( __MMI_WEARABLE_DEVICE__) && defined(__MMI_BT_MAP_CLIENT__)*/
#endif /* __UM_SUPPORT__ */