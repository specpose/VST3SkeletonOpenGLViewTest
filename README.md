This is a stripped down version of uidescription_test in VSTGUI for creating VST3 OpenGL plugins.

1. Clone this repository
2. Extract VST3 SDK into folder "VST3 SDK" above repository
3. Delete folder vstgui4 and clone steinbergmedia/vstgui in folder "VST3 SDK"

Start with implementing ViewGLIF. Change ViewGLTest to ViewGLYourImplementation in ViewGLTest.h. Create unique cids referred in factory.cpp before deploying your plugin.