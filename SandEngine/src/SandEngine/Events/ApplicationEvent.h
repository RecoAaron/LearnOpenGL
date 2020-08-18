#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: Ӧ�ó����¼�������
*************************************************/
#include "SandEngine/Events/Event.h"

namespace SandEngine {

    class SE_API CWindowResizeEvent : public CEvent
    {
    public:
        CWindowResizeEvent(unsigned int nWidth, unsigned int nHeight)
            : m_nWidth(nWidth), m_nHeight(nHeight)
        {

        }

        /// ��ȡ���ڵĿ��
        inline unsigned int GetWidth() const { return m_nWidth; }
        /// ��ȡ���ڵĸ߶�
        inline unsigned int GetHeight() const { return m_nHeight; }

        /// ��д���������������ڵĿ�Ⱥ͸߶�
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Window Resized:" << m_nWidth << ", " << m_nHeight;
            return ss.str();
        }

        /* �����¼�Ϊ�����������¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_WIN_RESIZE)

        /* �����¼�����Ϊ��Ӧ���¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_APPLICATION)

    private:
        /* ���ڵĿ�Ⱥ͸߶� */
        unsigned int m_nWidth, m_nHeight;
    };


    class SE_API CWindowCloseEvent : public CEvent
    {
    public:
        CWindowCloseEvent()
        {

        }

        /* �����¼�Ϊ�����ڹر��¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_WIN_CLOSE)

        /* �����¼�����Ϊ��Ӧ���¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_APPLICATION)
    };

    class SE_API CApplicationTickEvent : public CEvent
    {
    public:
        CApplicationTickEvent()
        {

        }

        /* �����¼�Ϊ��֡�¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_APP_TICK)

        /* �����¼�����Ϊ��Ӧ���¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_APPLICATION)
    };

    class SE_API CApplicationUpdateEvent : public CEvent
    {
    public:
        CApplicationUpdateEvent()
        {

        }

        /* �����¼�Ϊ�����ڹر��¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_APP_UPDATE)

        /* �����¼�����Ϊ��Ӧ���¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_APPLICATION)
    };
}