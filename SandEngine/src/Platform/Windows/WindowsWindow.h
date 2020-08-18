#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: Windows ƽ̨����ʵ��
*************************************************/
#include "SandEngine/Core/Window.h"

#include <GLFW/glfw3.h>

namespace SandEngine {

    class CWindowsWindow : public CWindow
    {
    public:
        CWindowsWindow(const SWindowProps& props);
        virtual ~CWindowsWindow();

        /// ���ڽ��и���
        void OnUpdate() override;

        /// ��ȡ���ڵĿ��
        uint32_t GetWidth() const override { return m_Data.m_nWidth; }
        /// ��ȡ���ڵĸ߶�
        uint32_t GetHeight() const override { return m_Data.m_nHeight; }

        /// ���ô����¼��Ļص�����
        void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

        /// �����Ƿ����ô�ֱͬ��
        void SetVSync(bool bEnable) override;
        /// �Ƿ������˴�ֱͬ��
        bool IsVSync() const override;

    private:
        /// ��ʼ������
        virtual void Init(const SWindowProps& props);

        /// �������ڽ���
        virtual void Shutdown();

        struct SWindowData
        {
            /* ���ڵı��� */
            std::string m_strTitle;

            /* ���ڵĿ�Ⱥ͸߶� */
            uint32_t m_nWidth, m_nHeight;

            /* �����Ƿ�ֱͬ�� */
            bool m_bVSync;

            /* ���ڵĻص����� */
            EventCallbackFn EventCallback;
        };

        /* �������� */
        SWindowData m_Data;

        /* ���ڵ�ָ�� */
        GLFWwindow* m_pWindow;
    };
}