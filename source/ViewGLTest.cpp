#include "ViewGLTest.h"

ViewGLTest::ViewGLTest(const CRect & size) : ViewGLIF(size)
{
}

void ViewGLTest::setThreaded(bool state)
{
	if (isAttached())
	{
		xRotation = yRotation = zRotation = 0.f;
		if (state == true && thread == 0)
		{
			thread = new Thread(this);
			thread->run();
		}
		else if (state == false)
		{
			if (thread) {
				delete thread;
				thread = 0;
			}
			remember();
			addAnimation("XRotation", this, new Animation::RepeatTimingFunction(new Animation::LinearTimingFunction(4000), -1, false));
			remember();
			addAnimation("YRotation", this, new Animation::RepeatTimingFunction(new Animation::LinearTimingFunction(6000), -1, false));
			remember();
			addAnimation("ZRotation", this, new Animation::RepeatTimingFunction(new Animation::LinearTimingFunction(8000), -1, false));
		}
	}
	useThread = state;
}

void ViewGLTest::platformOpenGLViewWillDestroy()
{
	if (thread) {
		delete thread;
		thread = 0;
	}
	removeAllAnimations();
}

void ViewGLTest::drawOpenGLThreaded()
{
	if (getPlatformOpenGLView())
	{
		xRotation += 1.f;
		if (xRotation >= 360.f)
			xRotation = 0.f;
		yRotation += 1.f;
		if (yRotation >= 360.f)
			yRotation = 0.f;
		zRotation += 1.f;
		if (zRotation >= 360.f)
			zRotation = 0.f;
		getPlatformOpenGLView()->lockContext();
		getPlatformOpenGLView()->makeContextCurrent();

		drawOpenGL(getViewSize());

		getPlatformOpenGLView()->unlockContext();
	}
}

void ViewGLTest::drawOpenGL(const CRect & updateRect) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glScaled(0.5, 0.5, 0.2);
	glRotated(xRotation, 1, 0, 0);
	glRotated(yRotation, 0, 1, 0);
	glRotated(zRotation, 0, 0, 1);

	glBegin(GL_TRIANGLES);

	glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glColor4f(1.0f, 1.0f, 0.0f, 0.5f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor4f(0.5f, 0.5f, 0.5f, 0.9f);
	glVertex3f(-1.f, -1.f, 1.f);
	glVertex3f(1.f, -1.f, 1.f);
	glVertex3f(1.f, -1.f, -1.f);
	glVertex3f(-1.f, -1.f, -1.f);
	glEnd();

	glFlush();

	getPlatformOpenGLView()->swapBuffers();
}

void ViewGLTest::animationStart(CView * view, IdStringPtr name)
{
}

void ViewGLTest::animationTick(CView * view, IdStringPtr name, float pos)
{
	if (thread == 0)
	{
		if (strcmp(name, "XRotation") == 0)
			xRotation = pos * 360.f;
		else if (strcmp(name, "ZRotation") == 0)
			zRotation = pos * 360.f;
		else if (strcmp(name, "YRotation") == 0)
			yRotation = pos * 360.f;
		invalid();
	}
}

void ViewGLTest::animationFinished(CView * view, IdStringPtr name, bool wasCanceled)
{
}
