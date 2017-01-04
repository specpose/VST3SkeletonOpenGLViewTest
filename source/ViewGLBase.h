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

#include "ViewGLIF.h"
#include "ViewGLIFThread.h"

using namespace VSTGUI;
using namespace Steinberg;

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
class ViewGLBase : public ViewGLIF
{
public:
	ViewGLBase(const CRect& size);

	void killThread();

	void setThreaded(bool state);

	virtual void drawOpenGL(const CRect& updateRect)=0;

protected:
	ViewGLIFThread<ViewGLIF>* thread;
};