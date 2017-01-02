#pragma once

#include "vstgui/plugin-bindings/vst3editor.h"

//------------------------------------------------------------------------
class ControllerIF : public Steinberg::Vst::EditController, public VST3EditorDelegate
{
public:
	Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) override;
	Steinberg::tresult beginEdit(Steinberg::Vst::ParamID tag) override;
	Steinberg::tresult performEdit(Steinberg::Vst::ParamID tag, Steinberg::Vst::ParamValue valueNormalized) override;
	Steinberg::tresult endEdit(Steinberg::Vst::ParamID tag) override;
	Steinberg::Vst::Parameter* getParameterObject(Steinberg::Vst::ParamID tag) override;

	bool isPrivateParameter(const Steinberg::Vst::ParamID paramID) override;
protected:
	Steinberg::Vst::ParameterContainer uiParameters;
};