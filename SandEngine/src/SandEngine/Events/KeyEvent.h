#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: �����¼�������
*************************************************/
#include "SandEngine/Events/Event.h"

namespace SE {

    class SE_API CKeyEvent : public CEvent
    {
    public:
        /// ��ȡ�����ı���
        inline int GetKeyCode() const { return m_KeyCode; }

        /* �����¼�����Ϊ�������¼� | �����¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_KEYBOARD | SE_EC_INPUT)

    protected:
        CKeyEvent(int keycode)
            : m_KeyCode(keycode)
        {

        }

        /* �����ı��� */
        int m_KeyCode;
    };

    class SE_API CKeyPressedEvent : public CKeyEvent
    {
    public:
        CKeyPressedEvent(int keycode, int repeatCount)
            :CKeyEvent(keycode), m_RepeatCount(repeatCount)
        {

        }

        /// ��ȡ�ظ�����������0��ʶ������
        inline int GetRepeatCount() const { return m_RepeatCount; }

        /// ��д�����������������ı�����ظ�����
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key Pressed:" << m_KeyCode << "(" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        /// �����¼�Ϊ���������¼�
        SE_EVENT_CLASS_TYPE(SE_ET_KEY_PRESSED)
    
    private:
        /* �������ظ����� */
    	int m_RepeatCount;
    };

    class S3D_API CKeyReleasedEvent : public CKeyEvent
    {
    public:
        CKeyReleasedEvent(int keycode)
            : CKeyEvent(keycode)
        {

        }

        /// ��д�����������������ı���
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key Released:" << m_KeyCode;
            return ss.str();
        }

        /// ���ü������¼�Ϊ���������¼�
        S3D_EVENT_CLASS_TYPE(SE_ET_KEY_RELEASED)
    };
}