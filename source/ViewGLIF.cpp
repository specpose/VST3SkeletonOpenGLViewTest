#include "ViewGLIF.h"

#include "ViewGLIFThread.h"

ViewGLIF::ViewGLIF(const CRect & size) : COpenGLView(size), useThread(false)
{
}

void ViewGLIF::platformOpenGLViewCreated()
{
	getPlatformOpenGLView()->lockContext();
	getPlatformOpenGLView()->makeContextCurrent();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0, 0, 0, 0);

	getPlatformOpenGLView()->unlockContext();

	setThreaded(useThread);
}

void ViewGLIF::platformOpenGLViewWillDestroy()
{
	killThread();
}

void ViewGLIF::platformOpenGLViewSizeChanged()
{
	if (getPlatformOpenGLView())
	{
		getPlatformOpenGLView()->lockContext();
		getPlatformOpenGLView()->makeContextCurrent();

		CRect r(getViewSize());
		glViewport(0, 0, static_cast<GLsizei> (r.getWidth()), static_cast<GLsizei> (r.getHeight()));

		getPlatformOpenGLView()->unlockContext();
	}
}

void ViewGLIF::drawOpenGLThreaded()
{
	if (getPlatformOpenGLView())
	{
		getPlatformOpenGLView()->lockContext();
		getPlatformOpenGLView()->makeContextCurrent();

		drawOpenGL(getViewSize());

		getPlatformOpenGLView()->unlockContext();
	}
}

PixelFormat * ViewGLIF::getPixelFormat()
{
	static PixelFormat pixelFormat;
	pixelFormat.flags = PixelFormat::kAccelerated | PixelFormat::kMultiSample;
	pixelFormat.samples = 4;
	return &pixelFormat;
}
