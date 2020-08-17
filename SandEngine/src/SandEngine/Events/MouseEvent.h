#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: ����¼�������
*************************************************/
#include "SandEngine/Events/Event.h"

namespace SE {

    class SE_API CMouseMoveEvent : public CEvent
    {
    public:
        CMouseMoveEvent(float nPosX, float nPosY)
            : m_nMouseX(nPosX), m_nMouseY(nPosY)
        {

        }

        /// ��ȡ����X����λ��
        inline float GetPosX() const { return m_nMouseX; }
        /// ��ȡ����Y����λ��
        inline float GetPosY() const { return m_nMouseY; }

        /// ��д����������������������Ϣ
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Moved:" << m_nMouseX << ", " << m_nMouseY;
            return ss.str();
        }

        /* �����¼�Ϊ������ƶ��¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_MOUSE_MOVED)

        /* �����¼�����Ϊ������¼� | �����¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)
    
    private:
        /* ��������λ�� */
        float m_nMouseX, m_nMouseY;
    };

    class SE_API CMouseScrolledEvent : public CEvent
    {
    public:
        CMouseScrolledEvent(float nXOffset, float nYOffset)
            : m_nXOffset(nXOffset), m_nYOffset(nYOffset)
        {

        }

        /// ��ȡ����Xƫ��
        inline float GetXOffset() const { return m_nXOffset; }
        /// ��ȡ����Yƫ��
        inline float GetYOffset() const { return m_nYOffset; }

        /// ��д����������������ƫ����Ϣ
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Scrolled:" << m_nXOffset << ", " << m_nYOffset;
            return ss.str();
    	}

        /* �����¼�Ϊ������ƶ��¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_MOUSE_SCROLLED)

        /* �����¼�����Ϊ������¼� | �����¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)

    private:
        /* ��������ƫ�� */
        float m_nXOffset, m_nYOffset;
    };

    class SE_API CMouseButtonEvent : public CEvent
    {
    public:
        /// ��ȡ��갴��ֵ
        inline int GetMouseButton() const { return m_nButton; }

        /* �����¼�����Ϊ������¼� | �����¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)
    
    protected:
        CMouseButtonEvent(int nButton)
            : m_nButton(nButton)
        {

        }

        /* ��갴��ֵ */
        int m_nButton;
    };
    
    class SE_API CMouseButtonPressedEvent : public CMouseButtonEvent
    {
    public:
        CMouseButtonPressedEvent(int nButton)
            : CMouseButtonEvent(nButton)
        {

        }

        /// ��д��������������갴����ֵ
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Button Pressed:" << m_nButton;
            return ss.str();
        }

        /* �����¼�Ϊ�����������¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_MBTN_PRESSED)
    };
    
    class SE_API CMouseButtonReleasedEvent : public CMouseButtonEvent
    {
    public:
        CMouseButtonReleasedEvent(int nButton)
            : CMouseButtonEvent(nButton)
        {

        }

        /// ��д��������������갴����ֵ
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "S3D_ET_MBTN_RELEASED:" << m_nButton;
            return ss.str();
        }

        /* �����¼�Ϊ�������ɿ��¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_MBTN_RELEASED)
    };
}