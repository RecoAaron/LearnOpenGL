#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-17
 * Description: ���ڳ�����
*************************************************/
#include "sdpch.h"

#include "SandEngine/Core/Base.h"
#include "SandEngine/Events/Event.h"

namespace SE {

    struct SWindowProps
    {
        /* ���ڵı��� */
        std::string m_strTitle;

        /* ���ڵĿ�Ⱥ͸߶� */
        uint32_t m_nWidth, m_nHeight;

        SWindowProps(const std::string& strTitle = "Sand Engine", uint32_t nWidth = 1280, uint32_t nHeight = 720)
            : m_strTitle(strTitle), m_nWidth(nWidth), m_nHeight(nHeight)
        {

        }
    };

    class SE_API CWindow
    {
    public:
        /* �����¼��ص��������� void fun(CEvent& event) */
        using EventCallbackFn = std::function<void(CEvent&)>;

        virtual ~CWindow() = default;

        /// ���ڽ��и���
        virtual void OnUpdate() = 0;

        /// ��ȡ���ڵĿ��
        virtual uint32_t GetWidth() const = 0;
        /// ��ȡ���ڵĸ߶�
        virtual uint32_t GetHeight() const = 0;

        /// ���ô����¼��Ļص�����
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

        /// �����Ƿ����ô�ֱͬ��
        virtual void SetVSync(bool bEnable) = 0;
        /// �Ƿ������˴�ֱͬ��
        virtual bool IsVSync() const = 0;

        /// ��̬���촰�ں�����Scope = unique_ptr ��ֹ�ڴ�й©
        static Scope<CWindow> Create(const SWindowProps& props = SWindowProps());
    };
}