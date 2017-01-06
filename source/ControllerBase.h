#pragma once

#include "ControllerIF.h"
#include "pluginterfaces/base/ustring.h"

//------------------------------------------------------------------------
class ControllerBase : public ControllerIF
{
public:
	ControllerBase();
	virtual ~ControllerBase() {};

	virtual Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) override;
	virtual Steinberg::IPlugView* PLUGIN_API createView(Steinberg::FIDString name)=0;
	virtual void willClose(VST3Editor* editor) =0;
};