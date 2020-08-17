#include "sdpch.h"

#include "Window.h"

#ifdef SE_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.h"
#endif

namespace SE {

    Scope<CWindow> CWindow::Create(const SWindowProps& props /* = SWindowProps() */)
    {
    #ifdef SE_PLATFORM_WINDOWS
        return CreateScope<CWindowsWindow>(props);
    #else
        SE_CORE_ASSERT(false, "the platform is unknown!");
    #endif
    }
}