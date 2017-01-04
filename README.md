This is a stripped down version of uidescription_test in VSTGUI for creating VST3 OpenGL plugins.

1. Clone this repository
2. Extract Steinberg VST Audio-Plugins SDK to folder "VST3 SDK" above repository
3. Delete folder "vstgui4" and clone steinbergmedia/vstgui in folder "VST3 SDK"
4. Rename folder "vstgui" in "VST3 SDK" to "vstgui4"

Start with implementing ViewGLBase. Change ViewGLTest to ViewGLYourImplementation in SubControllerGL. Create unique cids referred in factory.cpp before shipping your plugin.