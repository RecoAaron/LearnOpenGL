#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: �����¼�������
*************************************************/
#include "SandEngine/Events/Event.h"

namespace SandEngine {

    class SE_API CKeyEvent : public CEvent
    {
    public:
        /// ��ȡ�����ı���
        inline int GetKeyCode() const { return m_nKeyCode; }

        /* �����¼�����Ϊ�������¼� | �����¼� */
        SE_EVENT_CLASS_CATEGORY(SE_EC_KEYBOARD | SE_EC_INPUT)

    protected:
        CKeyEvent(int nKeycode)
            : m_nKeyCode(nKeycode)
        {

        }

        /* �����ı��� */
        int m_nKeyCode;
    };

    class SE_API CKeyPressedEvent : public CKeyEvent
    {
    public:
        CKeyPressedEvent(int nKeycode, int nRepeatCount)
            :CKeyEvent(nKeycode), m_nRepeatCount(nRepeatCount)
        {

        }

        /// ��ȡ�ظ�����������0��ʶ������
        inline int GetRepeatCount() const { return m_nRepeatCount; }

        /// ��д�����������������ı�����ظ�����
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key Pressed:" << m_nKeyCode << "(" << m_nRepeatCount << " repeats)";
            return ss.str();
        }

        /// �����¼�Ϊ���������¼�
        SE_EVENT_CLASS_TYPE(SE_ET_KEY_PRESSED)
    
    private:
        /* �������ظ����� */
        int m_nRepeatCount;
    };

    class SE_API CKeyReleasedEvent : public CKeyEvent
    {
    public:
        CKeyReleasedEvent(int nKeycode)
            : CKeyEvent(nKeycode)
        {

        }

        /// ��д�����������������ı���
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key Released:" << m_nKeyCode;
            return ss.str();
        }

        /// ���ü������¼�Ϊ���������¼�
        SE_EVENT_CLASS_TYPE(SE_ET_KEY_RELEASED)
    };
}