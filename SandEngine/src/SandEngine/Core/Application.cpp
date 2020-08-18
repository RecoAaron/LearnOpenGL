#include "sdpch.h"

#include "Application.h"

#include "SandEngine/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace SandEngine {

    CApplication::CApplication()
    {
        m_pWindow = CWindow::Create(SWindowProps("Sand Engine Test"));
        m_pWindow->SetEventCallback(SE_BIND_EVENT_FN(OnEvent));
    }

    CApplication::~CApplication()
    {
        
    }

    void CApplication::PushLayer(CLayer* pLayer)
    {
        m_layerStack.PushLayer(pLayer);
        pLayer->OnAttach();
    }

    void CApplication::PushOverlay(CLayer* pOverlay)
    {
        m_layerStack.PushOverlay(pOverlay);
        pOverlay->OnAttach();
    }

    void CApplication::Run()
    {
        while (m_bRunning)
        {
            for (CLayer* pLayer : m_layerStack)
                pLayer->OnUpdate();

            glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_pWindow->OnUpdate();
        }
    }

    void CApplication::OnEvent(CEvent& event)
    {
        CEventDispatcher dispatcher(event);
        dispatcher.Dispatch<CWindowCloseEvent>(SE_BIND_EVENT_FN(CApplication::OnWindowClose));

        //SE_LOG_TRACE("{0}", event);

        for (auto it = m_layerStack.end(); it != m_layerStack.begin(); )
        {
            (*--it)->OnEvent(event);
            if (event.m_bHandled)
                break;
        }
    }

    bool CApplication::OnWindowClose(CWindowCloseEvent& event)
    {
        m_bRunning = false;
        return true;
    }
}