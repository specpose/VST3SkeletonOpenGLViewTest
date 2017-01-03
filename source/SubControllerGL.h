#pragma once

#include "vstgui/uidescription/delegationcontroller.h"
#include "vstgui/uidescription/uiattributes.h"
#include "ViewGLIF.h"

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
class SubControllerGL : public DelegationController
{
public:
	SubControllerGL(IController* baseController)
		: DelegationController(baseController)
		, openGLView(0)
	{}

	IControlListener* getControlListener(UTF8StringPtr name) override
	{
		if (strcmp(name, "threaded") == 0)
			return this;
		return controller->getControlListener(name);
	}

	CView* createView(const UIAttributes& attributes, const IUIDescription* description) override
	{
		const std::string* name = attributes.getAttributeValue("custom-view-name");
		if (name && *name == "OpenGLView")
		{
			openGLView = new ViewGLIF(CRect(0, 0, 0, 0));
			return openGLView;
		}
		return controller->createView(attributes, description);
	}

	void valueChanged(CControl* control) override
	{
		if (openGLView)
			openGLView->setThreaded(control->getValue() == control->getMax());
	}

protected:
	ViewGLIF* openGLView;
};