﻿#include "sdpch.h"

#include "Application.h"

#include "SandEngine/Events/ApplicationEvent.h"
#include "SandEngine/Renderer/Renderer.h"

namespace SandEngine {

    CApplication* CApplication::s_pInstance = nullptr;

    CApplication::CApplication(const std::string& name /* = "Sand Engine" */)
    {
        SE_CORE_ASSERT(!s_pInstance, "Application already exists!");
        s_pInstance = this;
        m_pWindow = CWindow::Create(SWindowProps(name));
        m_pWindow->SetEventCallback(SE_BIND_EVENT_FN(OnEvent));

        CRenderer::Init();

        m_pImGuiLayer = new CImGuiLayer();
        PushOverlay(m_pImGuiLayer);
    }

    CApplication::~CApplication()
    {
        CRenderer::Shutdown();
    }

    void CApplication::PushLayer(CLayer* pLayer)
    {
        m_LayerStack.PushLayer(pLayer);
        pLayer->OnAttach();
    }

    void CApplication::PushOverlay(CLayer* pOverlay)
    {
        m_LayerStack.PushOverlay(pOverlay);
        pOverlay->OnAttach();
    }

    void CApplication::Run()
    {
        while (m_bRunning)
        {
            float nTime = m_pWindow->GetWindowTime();
            CTimestep timestep = nTime - m_nLastFrameTime;
            m_nLastFrameTime = nTime;

            if (!m_bMinimized)
            {
                // 所有层级进行更新
                {
                    for (CLayer* pLayer : m_LayerStack)
                        pLayer->OnUpdate(timestep);
                }

                // 所有层级进行 ImGui 绘制操作
                m_pImGuiLayer->Begin();
                {
                    for (CLayer* layer : m_LayerStack)
                        layer->OnImGuiRender();
                }
                m_pImGuiLayer->End();
            }
            
            m_pWindow->OnUpdate();
        }
    }

    void CApplication::OnEvent(CEvent& event)
    {
        CEventDispatcher dispatcher(event);
        dispatcher.Dispatch<CWindowCloseEvent>(SE_BIND_EVENT_FN(CApplication::OnWindowClose));
        dispatcher.Dispatch<CWindowResizedEvent>(SE_BIND_EVENT_FN(CApplication::OnWindowResize));

        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
        {
            if (event.m_bHandled)
                break;
            (*it)->OnEvent(event);
        }
    }

    bool CApplication::OnWindowClose(CWindowCloseEvent& event)
    {
        m_bRunning = false;
        return true;
    }

    bool CApplication::OnWindowResize(CWindowResizedEvent& event)
    {
        if (event.GetWidth() == 0 || event.GetHeight() == 0)
        {
            m_bMinimized = true;
            return false;
        }

        m_bMinimized = false;
        CRenderer::OnWindowResize(event.GetWidth(), event.GetHeight());
        return false;
    }
}