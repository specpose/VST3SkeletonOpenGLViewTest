#pragma once

#include "base/source/fobject.h"
#include "base/source/fthread.h"

#if MAC
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#elif WINDOWS
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include "vstgui4/vstgui/lib/copenglview.h"
#include "vstgui4/vstgui/lib/animation/ianimationtarget.h"
#include "vstgui4/vstgui/lib/animation/timingfunctions.h"

using namespace VSTGUI;
using namespace Steinberg;

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
class ViewGLIF : public COpenGLView
{
public:
	ViewGLIF(const CRect& size);

	virtual void setThreaded(bool state);

	void platformOpenGLViewCreated() override;

	void platformOpenGLViewWillDestroy() override;

	void platformOpenGLViewSizeChanged() override;

	virtual void drawOpenGLThreaded();

	virtual void drawOpenGL(const CRect& updateRect)=0;

	PixelFormat* getPixelFormat() override;
protected:

	class Thread : public FThread
	{
	public:
		Thread(ViewGLIF* openGLView)
			: FThread("OpenGLDrawThread")
			, openGLView(openGLView)
			, cancelDrawLoop(false)
		{
			this->run();
		}
		~Thread() {
			cancelDrawLoop = true;
			this->waitDead(-1);
		}

		uint32 entry() override
		{
			while (cancelDrawLoop == false)
			{
				openGLView->drawOpenGLThreaded();
				FThreadSleep(16);
			}
			return 0;
		}

	protected:
		ViewGLIF* openGLView;
		volatile bool cancelDrawLoop;
	};

	
	bool useThread;
	Thread* thread;
};