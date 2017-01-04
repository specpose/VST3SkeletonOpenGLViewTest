#pragma once

#include "base/source/fthread.h"

using namespace Steinberg;

template<typename T> class ViewGLIFThread : public FThread
{
public:
	ViewGLIFThread(T* openGLView)
		//Thread(void (*draw_func)(void))
		: FThread("OpenGLDrawThread")
		, viewglif(openGLView)
		//, draw(draw_func)
		, cancelDrawLoop(false)
	{
		this->run();
	}
	~ViewGLIFThread() {
		cancelDrawLoop = true;
		this->waitDead(-1);
	}

	uint32 entry() override
	{
		while (cancelDrawLoop == false)
		{
			viewglif->drawOpenGLThreaded();
			//draw();
			FThreadSleep(16);
		}
		return 0;
	}

protected:
	T* viewglif;
	//void (*draw)(void);
	volatile bool cancelDrawLoop;
};