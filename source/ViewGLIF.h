#pragma once

#include "base/source/fobject.h"

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

#include "ViewGLIFThread.h"

using namespace VSTGUI;
using namespace Steinberg;

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
class ViewGLIF : public COpenGLView
{
public:
	ViewGLIF(const CRect& size);

	virtual void setThreaded(bool state) = 0;

	void platformOpenGLViewCreated() override;

	void platformOpenGLViewWillDestroy() override;

	void platformOpenGLViewSizeChanged() override;

	virtual void drawOpenGLThreaded();

	virtual void drawOpenGL(const CRect& updateRect)=0;

	PixelFormat* getPixelFormat() override;
protected:
	virtual void killThread() = 0;

	bool useThread;
};