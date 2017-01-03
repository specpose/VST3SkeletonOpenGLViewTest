#pragma once

#include "ProcessorIF.h"
#include "ControllerGL.h"

//------------------------------------------------------------------------
class ProcessorGL : public ProcessorIF
{
public:
	ProcessorGL();

	static Steinberg::FUnknown* createInstance(void*) { return (Steinberg::Vst::IAudioProcessor*)new ProcessorGL; }
	static Steinberg::FUID cid;
};