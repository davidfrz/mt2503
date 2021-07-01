#ifndef MMI_OKSOS_GPROT_H
#define MMI_OKSOS_GPROT_H

#include "MMI_features.h"
#ifdef __MMI_ONE_KEY_SOS_SUPPORT__
#include "OneKeySOSSrvGprot.h"
extern void mmi_oksos_launch(srv_oksos_key_value_enum key);
extern void mmi_oksos_set_key_count(U8 count);
extern void mmi_oksos_dial_long_press_handler(S32 key);

#endif /* __MMI_ONE_KEY_SOS_SUPPORT__ */
#endif // MMI_OKSOS_GPROT_H
