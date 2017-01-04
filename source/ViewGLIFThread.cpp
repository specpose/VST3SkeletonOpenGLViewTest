#include "ViewGLIFThread.h"

ViewGLIFThread::ViewGLIFThread(ViewGLIF* openGLView)
	: FThread("OpenGLDrawThread")
	, viewglif(openGLView)
	, cancelDrawLoop(false)
{
	this->run();
}

ViewGLIFThread::~ViewGLIFThread() {
	cancelDrawLoop = true;
	this->waitDead(-1);
}

uint32 ViewGLIFThread::entry()
{
	while (cancelDrawLoop == false)
	{
		viewglif->drawOpenGLThreaded();
		FThreadSleep(16);
	}
	return 0;
}