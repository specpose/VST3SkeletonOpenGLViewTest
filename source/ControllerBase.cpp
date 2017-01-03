#include "ControllerBase.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

//FUID ControllerBase::cid(0xF0FF3C24, 0x3F2F4C94, 0x84F6B6AE, 0xEF7BF28B);

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
ControllerBase::ControllerBase()
{
}

//------------------------------------------------------------------------
tresult PLUGIN_API ControllerBase::initialize(FUnknown* context)
{
	tresult res = ControllerIF::initialize(context);
	return res;
}