#include "sdpch.h"

#include "Application.h"

#include "SandEngine/Events/ApplicationEvent.h"

namespace SandEngine {

    CApplication::CApplication()
    {
        
    }

    CApplication::~CApplication()
    {
        
    }

    void CApplication::Run()
    {
        SE::CWindowResizeEvent e(1280, 720);
        SE_LOG_INFO(e);
        while (true)
        {

        }
    }
}