#pragma once

#include "ControllerBase.h"
#include "SubControllerGL.h"

//------------------------------------------------------------------------
class ControllerGL : public ControllerBase
{
public:
	Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) override;
	Steinberg::IPlugView* PLUGIN_API createView(Steinberg::FIDString name) override;
	IController* createSubController(const char* name, const IUIDescription* description, VST3Editor* editor) override;

	static Steinberg::FUnknown* createInstance(void*) { return (Steinberg::Vst::IEditController*)new ControllerGL; }
	static Steinberg::FUID cid;
};
