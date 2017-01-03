//-----------------------------------------------------------------------------
// VST Plug-Ins SDK
// VSTGUI: Graphical User Interface Framework for VST plugins
//
// Version 4.3
//
//-----------------------------------------------------------------------------
// VSTGUI LICENSE
// (c) 2015, Steinberg Media Technologies, All Rights Reserved
//-----------------------------------------------------------------------------
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
// 
//   * Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation 
//     and/or other materials provided with the distribution.
//   * Neither the name of the Steinberg Media Technologies nor the names of its
//     contributors may be used to endorse or promote products derived from this 
//     software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#include "public.sdk/source/vst/vst2wrapper/vst2wrapper.h"
#include "ProcessorIF.h"
//#include "ControllerBase.h"
#include "ControllerGL.h"
#include "public.sdk/source/main/pluginfactoryvst3.h"

using namespace VSTGUI;

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
BEGIN_FACTORY("VSTGUI", "", "", PFactoryInfo::kUnicode)

	DEF_CLASS2 (INLINE_UID_FROM_FUID(ProcessorIF::cid),
				PClassInfo::kManyInstances,
				kVstAudioEffectClass,
				"VSTGUI UIDescription OpenGLView Test",
				Vst::kDistributable,
				"Fx",
				"1.0.0",
				kVstVersionString,
				ProcessorIF::createInstance)
				
	DEF_CLASS2 (INLINE_UID_FROM_FUID(ControllerBase::cid),
				PClassInfo::kManyInstances,
				kVstComponentControllerClass,
				"VSTGUI UIDescription OpenGLView Test",
				Vst::kDistributable,
				"Fx",
				"1.0.0",
				kVstVersionString,
				ControllerGL::createInstance)

END_FACTORY

//------------------------------------------------------------------------
bool InitModule ()   
{
	return true; 
}

//------------------------------------------------------------------------
bool DeinitModule ()
{
	return true; 
}

//------------------------------------------------------------------------
::AudioEffect* createEffectInstance (::audioMasterCallback audioMaster)
{
	return Steinberg::Vst::Vst2Wrapper::create (GetPluginFactory (), ProcessorIF::cid, 0, audioMaster);
}
