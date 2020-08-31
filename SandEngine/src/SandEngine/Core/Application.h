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
#include "SandEngine/ImGui/ImGuiLayer.h"

namespace SandEngine {

    class CApplication
    {
    public:
        CApplication(const std::string& name = "Sand Engine");
        virtual ~CApplication();

        /// ��ȡ����ָ��
        CWindow& GetWindow() { return *m_pWindow; }

        /// �������һ���㼶����
        void PushLayer(CLayer* pLayer);
        /// �������һ������㼶����
        void PushOverlay(CLayer* pOverlay); 

        /// Ӧ�ó���ʼ����
        void Run();

        /// ����Ӧ�ó����¼�
        void OnEvent(CEvent& event);

        /// Ӧ�ó���ر��¼�
        bool OnWindowClose(CWindowCloseEvent& event);

        /// ��ȡӦ�ó���������
        static CApplication& GetInstance() { return *s_pInstance; }

    private:
        /* ����ָ�� */
        Scope<CWindow> m_pWindow;

        /* ImGui �㼶���ղ㼶���ڵ��ú��� */
        CImGuiLayer* m_pImGuiLayer;

        /* ���ڲ㼶�洢ջ */
        CLayerStack m_LayerStack;

        /* Ӧ�ó������б�־ */
        bool m_bRunning = true;

    private:
        /* Ӧ�ó�����ָ�� */
        static CApplication* s_pInstance;
    };

    /// �Զ��崴��Ӧ�ó���ķ���
    CApplication* CreateApplication();
}