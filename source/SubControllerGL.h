#pragma once

#include "vstgui/uidescription/delegationcontroller.h"
#include "vstgui/uidescription/uiattributes.h"
#include "vstgui/lib/controls/ccontrol.h"
#include "ViewGLTest.h"

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
class SubControllerGL : public DelegationController
{
public:
	SubControllerGL(IController* baseController);

	IControlListener* getControlListener(UTF8StringPtr name) override;

	CView* createView(const UIAttributes& attributes, const IUIDescription* description) override;

	void valueChanged(CControl* control) override;

protected:
	ViewGLTest* openGLView;
};