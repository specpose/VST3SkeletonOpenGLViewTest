#pragma once

#include "ControllerBase.h"
#include "SubControllerGL.h"

//------------------------------------------------------------------------
class ControllerGL : public ControllerBase
{
public:
	ControllerGL();
	~ControllerGL() {};

	Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) override;
	Steinberg::IPlugView* PLUGIN_API createView(Steinberg::FIDString name);
	IController* createSubController(const char* name, const IUIDescription* description, VST3Editor* editor) override;

	void willClose(VST3Editor* editor) {};

	static Steinberg::FUID cid;
};
