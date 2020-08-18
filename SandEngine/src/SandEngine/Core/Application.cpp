#include "sdpch.h"

#include "Application.h"

#include "SandEngine/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace SE {

    CApplication::CApplication()
    {
        m_pWindow = CWindow::Create(SWindowProps("Sand Engine Test"));
        m_pWindow->SetEventCallback(SE_BIND_EVENT_FN(OnEvent));
    }

    CApplication::~CApplication()
    {
        
    }

    void CApplication::Run()
    {
        while (true)
        {
            glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_pWindow->OnUpdate();
        }
    }

    void CApplication::OnEvent(CEvent& event)
    {
        SE_LOG_INFO_CORE("{0}", event);
    }
}