#ifndef __GB_SMD_VIEW_APP_H__
#define __GB_SMD_VIEW_APP_H__

#include "GB_SMD_View_List.h"
#include "GB_SMD_View_Screen.h"


extern "C" void GB_WG_Search_Net_Launch(void* args, U32 argSize);

class WinguoSMDBaseApp : public VfxApp
{
	VFX_DECLARE_CLASS(WinguoSMDBaseApp);

	// Override
public:
	virtual void onRun(void* args, VfxU32 argSize);	
};

#endif /*__GB_SMD_VIEW_APP_H__*/