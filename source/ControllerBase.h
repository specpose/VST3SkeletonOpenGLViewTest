#pragma once

#include "ControllerIF.h"
#include "pluginterfaces/base/ustring.h"

//------------------------------------------------------------------------
class ControllerBase : public ControllerIF
{
public:
	ControllerBase();

	Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) override;
	Steinberg::IPlugView* PLUGIN_API createView(Steinberg::FIDString name) override;
	void willClose(VST3Editor* editor) override;

	CView* createCustomView(UTF8StringPtr name, const UIAttributes& attributes, const IUIDescription* description, VST3Editor* editor) override;
	CView* verifyView(CView* view, const UIAttributes& attributes, const IUIDescription* description, VST3Editor* editor) override;

	static Steinberg::FUnknown* createInstance(void*) { return (Steinberg::Vst::IEditController*)new ControllerBase; }
	static Steinberg::FUID cid;
};