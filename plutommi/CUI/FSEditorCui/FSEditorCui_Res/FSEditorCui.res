
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_FULLSCREEN_EDITOR" name = "STR_FULLSCREEN_EDITOR" hidden_in_mainmenu = "true">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

  <MEMORY  base="FSEditor_DATA_ASM_SIZE"  inc="..\\plutommi\\CUI\FSEditorCui\\FSEditorCui.h"/>
    <!------------------------------------------------------Other Resource---------------------------------------------------------->

</APP>

