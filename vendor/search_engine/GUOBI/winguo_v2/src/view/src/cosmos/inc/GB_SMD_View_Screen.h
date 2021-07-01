#ifndef __GB_SMD_VIEW_SCREEN_H__
#define __GB_SMD_VIEW_SCREEN_H__

#include "GB_SMD_View_List.h"
#include "GB_SMD_View_Page.h"


class WinguoSMDBaseScreen : public VfxMainScr
{
	VFX_DECLARE_CLASS(WinguoSMDBaseScreen);

	// Override
public:
	virtual void on1stReady();

};

#endif /*__GB_SMD_VIEW_SCREEN_H__*/