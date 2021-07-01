#ifndef MMI_OKSOS_PROT_H
#define MMI_OKSOS_PROT_H

#include "MMI_features.h"
#ifdef __MMI_ONE_KEY_SOS_SUPPORT__
#include "OneKeySOSSrvGprot.h"

typedef struct
{
    srv_oksos_key_value_enum key;
} mmi_oksos_cntx_struct;

#endif /* __MMI_ONE_KEY_SOS_SUPPORT__ */
#endif // MMI_OKSOS_PROT_H
