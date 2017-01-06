#pragma once

#include "public.sdk/source/vst/vstaudioeffect.h"
#include "ControllerGL.h"
#include "pluginterfaces/base/ustring.h"


//------------------------------------------------------------------------
class ProcessorIF : public Steinberg::Vst::AudioEffect
{
public:
	ProcessorIF();

	Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) override;
	Steinberg::tresult PLUGIN_API setBusArrangements(Steinberg::Vst::SpeakerArrangement* inputs, Steinberg::int32 numIns, Steinberg::Vst::SpeakerArrangement* outputs, Steinberg::int32 numOuts) override;
	Steinberg::tresult PLUGIN_API process(Steinberg::Vst::ProcessData& data) override;
	Steinberg::tresult PLUGIN_API setProcessing(Steinberg::TBool state) override;

	template<typename T> static FUnknown* createInstance(void* context) {
		return (Steinberg::Vst::IAudioProcessor*)new T;
	};
	static Steinberg::FUID cid;
};