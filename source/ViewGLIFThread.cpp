#include "ViewGLIFThread.h"

#include "ViewGLIF.h"

template<typename T> ViewGLIFThread<T>::ViewGLIFThread(T* openGLView)
	: FThread("OpenGLDrawThread")
	, viewglif(openGLView)
	, cancelDrawLoop(false)
{
	this->run();
}
template ViewGLIFThread<ViewGLIF>::ViewGLIFThread(ViewGLIF* openGLView);

template<typename T> ViewGLIFThread<T>::~ViewGLIFThread() {
	cancelDrawLoop = true;
	this->waitDead(-1);
}
template ViewGLIFThread<ViewGLIF>::~ViewGLIFThread();

template<typename T> uint32 ViewGLIFThread<T>::entry()
{
	while (cancelDrawLoop == false)
	{
		viewglif->drawOpenGLThreaded();
		FThreadSleep(16);
	}
	return 0;
}
template uint32 ViewGLIFThread<ViewGLIF>::entry();
