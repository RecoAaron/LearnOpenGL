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

namespace SE {

    class SE_API CApplication
    {
    public:
        CApplication();
        virtual ~CApplication();

        /// Ӧ�ó���ʼ����
        void Run();

        /// ����Ӧ�ó����¼�
        void OnEvent(CEvent& event);

    private:
        /* ����ָ�� */
        Scope<CWindow> m_pWindow;
    };

    /// �Զ��崴��Ӧ�ó���ķ���
    CApplication* CreateApplication();
}