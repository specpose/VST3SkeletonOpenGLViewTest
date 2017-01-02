#include "ControllerIF.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
tresult PLUGIN_API ControllerIF::initialize(FUnknown* context)
{
	tresult res = EditController::initialize(context);
	return res;
}

//------------------------------------------------------------------------
Parameter* ControllerIF::getParameterObject(ParamID tag)
{
	Parameter* param = EditController::getParameterObject(tag);
	if (param == 0)
	{
		param = uiParameters.getParameter(tag);
	}
	return param;
}

// make sure that our UI only parameters doesn't call the following three EditController methods: beginEdit, endEdit, performEdit
//------------------------------------------------------------------------
tresult ControllerIF::beginEdit(ParamID tag)
{
	if (EditController::getParameterObject(tag))
		return EditController::beginEdit(tag);
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult ControllerIF::performEdit(ParamID tag, ParamValue valueNormalized)
{
	if (EditController::getParameterObject(tag))
		return EditController::performEdit(tag, valueNormalized);
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult ControllerIF::endEdit(ParamID tag)
{
	if (EditController::getParameterObject(tag))
		return EditController::endEdit(tag);
	return kResultFalse;
}

//------------------------------------------------------------------------
bool ControllerIF::isPrivateParameter(const Steinberg::Vst::ParamID paramID)
{
	return uiParameters.getParameter(paramID) != 0 ? true : false;
}