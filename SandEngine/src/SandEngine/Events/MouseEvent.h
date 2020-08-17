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
        CMouseMoveEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y)
        {

        }

        /// ��ȡ����X����λ��
        inline float GetPosX() const { return m_MouseX; }
        /// ��ȡ����Y����λ��
        inline float GetPosY() const { return m_MouseY; }

        /// ��д����������������������Ϣ
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Moved:" << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        /* �����¼�Ϊ������ƶ��¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_MOUSE_MOVED)

        /* �����¼�����Ϊ������¼� | �����¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)
    
    private:
        /* ��������λ�� */
        float m_MouseX, m_MouseY;
    };

    class SE_API CMouseScrolledEvent : public CEvent
    {
    public:
        CMouseScrolledEvent(float xOffset, float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset)
        {

        }

        /// ��ȡ����Xƫ��
        inline float GetXOffset() const { return m_XOffset; }
        /// ��ȡ����Yƫ��
        inline float GetYOffset() const { return m_YOffset; }

        /// ��д����������������ƫ����Ϣ
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Scrolled:" << m_XOffset << ", " << m_YOffset;
            return ss.str();
    	}

        /* �����¼�Ϊ������ƶ��¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_MOUSE_SCROLLED)

        /* �����¼�����Ϊ������¼� | �����¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)

    private:
        /* ��������ƫ�� */
        float m_XOffset, m_YOffset;
    };

    class SE_API CMouseButtonEvent : public CEvent
    {
    public:
        /// ��ȡ��갴��ֵ
        inline int GetMouseButton() const { return m_Button; }

        /* �����¼�����Ϊ������¼� | �����¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)
    
    protected:
        CMouseButtonEvent(int button)
            : m_Button(button)
        {

        }

        /* ��갴��ֵ */
        int m_Button;
    };
    
    class SE_API CMouseButtonPressedEvent : public CMouseButtonEvent
    {
    public:
        CMouseButtonPressedEvent(int button)
            : CMouseButtonEvent(button)
        {

        }

        /// ��д��������������갴����ֵ
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Button Pressed:" << m_Button;
            return ss.str();
        }

        /* �����¼�Ϊ�����������¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_MBTN_PRESSED)
    };
    
    class SE_API CMouseButtonReleasedEvent : public CMouseButtonEvent
    {
    public:
        CMouseButtonReleasedEvent(int button)
            : CMouseButtonEvent(button)
        {

        }

        /// ��д��������������갴����ֵ
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "S3D_ET_MBTN_RELEASED:" << m_Button;
            return ss.str();
        }

        /* �����¼�Ϊ�������ɿ��¼� */
        SE_EVENT_CLASS_TYPE(SE_ET_MBTN_RELEASED)
    };
}