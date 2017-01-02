#include "ControllerBase.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

FUID ControllerBase::cid(0xF0FF3C24, 0x3F2F4C94, 0x84F6B6AE, 0xEF7BF28B);

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

//------------------------------------------------------------------------
IPlugView* PLUGIN_API ControllerBase::createView(FIDString name)
{
	if (strcmp(name, ViewType::kEditor) == 0)
	{
	}
	return 0;
}

//------------------------------------------------------------------------
CView* ControllerBase::createCustomView(UTF8StringPtr name, const UIAttributes& attributes, const IUIDescription* description, VST3Editor* editor)
{
	return 0;
}

//------------------------------------------------------------------------
CView* ControllerBase::verifyView(CView* view, const UIAttributes& attributes, const IUIDescription* description, VST3Editor* editor)
{
	CSegmentButton* button = dynamic_cast<CSegmentButton*>(view);
	if (button && button->getTag() == 20000)
	{
		StringListParameter* slp = dynamic_cast<StringListParameter*> (getParameterObject(20000));
		vstgui_assert(slp && button->getSegments().size() == static_cast<size_t> (slp->getInfo().stepCount + 1));
		for (uint32_t i = 0; i <= static_cast<uint32_t> (slp->getInfo().stepCount); i++)
		{
			String128 str = {};
			slp->toString(slp->toNormalized(i), str);
			Steinberg::String str2(str);
			str2.toMultiByte(kCP_Utf8);
			button->getSegments()[i].name = str2.text8();
		}
	}
	return view;
}

//------------------------------------------------------------------------
void ControllerBase::willClose(VST3Editor* editor)
{
}
