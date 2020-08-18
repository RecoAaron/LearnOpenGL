#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: Ӧ�ó�����
*************************************************/
#include "SandEngine/Core/Base.h"
#include "SandEngine/Core/Window.h"
#include "SandEngine/Events/Event.h"
#include "SandEngine/Events/ApplicationEvent.h"
#include "SandEngine/Core/LayerStack.h"

namespace SandEngine {

    class SE_API CApplication
    {
    public:
        CApplication();
        virtual ~CApplication();

        void PushLayer(CLayer* pLayer);
        void PushOverlay(CLayer* pOverlay); 

        /// Ӧ�ó���ʼ����
        void Run();

        /// ����Ӧ�ó����¼�
        void OnEvent(CEvent& event);

        /* Ӧ�ó���ر��¼� */
        bool OnWindowClose(CWindowCloseEvent& event);

    private:
        /* ����ָ�� */
        Scope<CWindow> m_pWindow;

        /* ���ڲ㼶�洢ջ */
        CLayerStack m_layerStack;

        /* Ӧ�ó������б�־ */
        bool m_bRunning = true;
    };

    /// �Զ��崴��Ӧ�ó���ķ���
    CApplication* CreateApplication();
}