#pragma once

#include "ViewGLBase.h"

class ViewGLTest : public ViewGLBase, public Animation::IAnimationTarget
{
public:
	ViewGLTest(const CRect & size);

	void setThreaded(bool state) override;

	void platformOpenGLViewWillDestroy() override;

	void drawOpenGLThreaded() override;

	void drawOpenGL(const CRect& updateRect);

protected:
	virtual void animationStart(CView* view, IdStringPtr name)  override;
	virtual void animationTick(CView* view, IdStringPtr name, float pos) override;
	virtual void animationFinished(CView* view, IdStringPtr name, bool wasCanceled) override;

	float xRotation;
	float yRotation;
	float zRotation;

};