#include "vmswitch.h"
#ifdef __MRE_SAL_SETTINGS__

#include "vmsettings_sdk.h"

                                            
#else // __MRE_SAL_SETTINGS__

#define vm_settings_set_tone (void*)NULL
#define vm_settings_set_wallpaper (void*)NULL
#define vm_is_bt_call_allowed (void*)NULL
#define vm_switch_bt_call (void*)NULL

#endif // __MRE_SAL_SETTINGS__

