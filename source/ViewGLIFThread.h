#pragma once

#include "base/source/fthread.h"
#include "ViewGLIF.h"

using namespace Steinberg;

class ViewGLIFThread : public FThread
{
public:
	ViewGLIFThread(ViewGLIF* openGLView);
	~ViewGLIFThread();

	uint32 entry() override;

protected:
	ViewGLIF* viewglif;
	volatile bool cancelDrawLoop;
};