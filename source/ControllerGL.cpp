#include "ControllerGL.h"

Steinberg::FUID ControllerGL::cid(0xC66B5286, 0x2E334055, 0xB42A6288, 0x9BE0DCE7);

using namespace Steinberg;
using namespace Steinberg::Vst;

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
Steinberg::tresult PLUGIN_API ControllerGL::initialize(Steinberg::FUnknown* context)
{
	tresult res = ControllerBase::initialize(context);
	if (res == kResultTrue)
	{
	}
	return res;
}

//------------------------------------------------------------------------
Steinberg::IPlugView* PLUGIN_API ControllerGL::createView(Steinberg::FIDString name)
{
	if (strcmp(name, ViewType::kEditor) == 0)
	{
		return new VST3Editor(this, "view", "OpenGLViewTest.uidesc");
	}
	return 0;
}

//------------------------------------------------------------------------
IController* ControllerGL::createSubController(const char* name, const IUIDescription* description, VST3Editor* editor)
{
	if (strcmp(name, "OpenGLViewController") == 0)
		return new SubControllerGL(editor);
	return 0;
}