#pragma once

#include "base/source/fthread.h"

using namespace Steinberg;

template<typename T> class ViewGLIFThread : public FThread
{
public:
	ViewGLIFThread(T* openGLView);
	~ViewGLIFThread();

	uint32 entry() override;

protected:
	T* viewglif;
	volatile bool cancelDrawLoop;
};