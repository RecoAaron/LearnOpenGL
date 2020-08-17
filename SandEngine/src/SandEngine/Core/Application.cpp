#include "sdpch.h"

#include "Application.h"

#include "SandEngine/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace SE {

    CApplication::CApplication()
    {
        
    }

    CApplication::~CApplication()
    {
        
    }

    void CApplication::Run()
    {
        m_pWindow = CWindow::Create(SWindowProps("Sand Engine Test"));
        while (true)
        {
            glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_pWindow->OnUpdate();
        }
    }
}