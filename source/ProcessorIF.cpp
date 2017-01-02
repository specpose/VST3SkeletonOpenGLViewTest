#include "ProcessorIF.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

FUID ProcessorIF::cid(0x49BAF003, 0xB44D455E, 0x9CBDE54F, 0x7FF2CBA1);

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
ProcessorIF::ProcessorIF()
{
	setControllerClass(ControllerBase::cid);
}

//------------------------------------------------------------------------
tresult PLUGIN_API ProcessorIF::initialize(FUnknown* context)
{
	tresult res = AudioEffect::initialize(context);
	if (res == kResultTrue)
	{
		addAudioInput(USTRING("Audio Input"), SpeakerArr::kStereo);
		addAudioOutput(USTRING("Audio Output"), SpeakerArr::kStereo);
	}
	return res;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ProcessorIF::setBusArrangements(SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts)
{
	if (numIns != 1 || numOuts != 1)
		return kResultFalse;
	if (inputs[0] != outputs[0])
		return kResultFalse;
	return AudioEffect::setBusArrangements(inputs, numIns, outputs, numOuts);
}

//------------------------------------------------------------------------
tresult PLUGIN_API ProcessorIF::setProcessing(Steinberg::TBool state)
{
	return AudioEffect::setProcessing(state);
}

//------------------------------------------------------------------------
tresult PLUGIN_API ProcessorIF::process(ProcessData& data)
{
	for (int32 sample = 0; sample < data.numSamples; sample++)
	{
		for (int32 channel = 0; channel < data.inputs[0].numChannels; channel++)
		{
			float value = data.inputs[0].channelBuffers32[channel][sample];
			data.outputs[0].channelBuffers32[channel][sample] = value;
			value = std::abs(value);
		}
	}
	return kResultTrue;
}


