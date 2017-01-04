#include "ViewGLBase.h"

#include "ViewGLIFThread.h"
#include "ViewGLBase.h"

ViewGLBase::ViewGLBase(const CRect & size) : ViewGLIF(size), thread(0)
{
}

void ViewGLBase::setThreaded(bool state)
{
	if (isAttached())
	{
		if (state == true && thread == 0)
		{
			thread = new ViewGLIFThread<ViewGLIF>(this);
		}
		else if (state == false)
		{
			killThread();
		}
	}
	useThread = state;
}

void ViewGLBase::killThread()
{
	if (thread) {
		delete thread;
		thread = 0;
	}
}
