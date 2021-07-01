#include "MMIDataType.h"
#include "vmsys.h"
#include "vmpromng.h"
typedef struct
{
	VMINT not_exit;// 0:exit; 1:not exit
	VM_P_HANDLE pHandle;
}vm_frm_pen_move_exit;
#ifdef __MMI_WEARABLE_DEVICE__
vm_frm_set_not_exit_flag();
vm_frm_set_exit_flag();
#endif
void vm_frm_init(void);

mmi_id vm_frm_get_group_id(VM_P_HANDLE pHandle);

VMINT vm_frm_entry_app_screen(VM_P_HANDLE pHandle);

VMINT vm_frm_exit_app_screen(VM_P_HANDLE pHandle);

MMI_BOOL vm_frm_is_active(void);

