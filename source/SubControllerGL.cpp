#include "SubControllerGL.h"

SubControllerGL::SubControllerGL(IController * baseController)
	: DelegationController(baseController)
	, openGLView(0)
{}

IControlListener * SubControllerGL::getControlListener(UTF8StringPtr name)
{
	if (strcmp(name, "threaded") == 0)
		return this;
	return controller->getControlListener(name);
}

CView * SubControllerGL::createView(const UIAttributes & attributes, const IUIDescription * description)
{
	const std::string* name = attributes.getAttributeValue("custom-view-name");
	if (name && *name == "OpenGLView")
	{
		openGLView = new ViewGLTest(CRect(0, 0, 0, 0));
		return openGLView;
	}
	return controller->createView(attributes, description);
}

void SubControllerGL::valueChanged(CControl * control)
{
	if (openGLView)
		openGLView->setThreaded(control->getValue() == control->getMax());
}