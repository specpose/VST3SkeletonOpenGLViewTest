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
class ViewGLIF : public COpenGLView, public Animation::IAnimationTarget
{
public:
	ViewGLIF(const CRect& size);

	void killThread();

	void setThreaded(bool state);

	void platformOpenGLViewCreated() override;

	void platformOpenGLViewWillDestroy() override;

	void platformOpenGLViewSizeChanged() override;

	void drawOpenGLThreaded();

	void drawOpenGL(const CRect& updateRect) override;

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

		void stop()
		{
			cancelDrawLoop = true;
		}

	protected:
		ViewGLIF* openGLView;
		volatile bool cancelDrawLoop;
	};

	virtual void animationStart(CView* view, IdStringPtr name)  override;
	virtual void animationTick(CView* view, IdStringPtr name, float pos) override;

	virtual void animationFinished(CView* view, IdStringPtr name, bool wasCanceled) override;

	float xRotation;
	float yRotation;
	float zRotation;

	bool useThread;
	Thread* thread;
};