#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: �¼����������
*************************************************/
#include "sdpch.h"

#include "SandEngine/Core/Base.h"

namespace SandEngine {

    enum class EEventType
    {
        SE_ET_NONE = 0,         // NULL

        /* �����¼� */
        SE_ET_WIN_CLOSE,        // ���ڹر��¼�
        SE_ET_WIN_RESIZE,       // ���������¼�

        /* Ӧ�ó����¼� */
        SE_ET_APP_TICK,        // ֡�¼�
        SE_ET_APP_UPDATE,      // �����¼�

        /* �����¼� */
        SE_ET_KEY_PRESSED,     // �������¼�
        SE_ET_KEY_RELEASED,    // ���ɿ��¼�
        SE_ET_KEY_TYPED,       // �����¼�

        /* ����¼� */
        SE_ET_MOUSE_MOVED,     // ����ƶ��¼�
        SE_ET_MOUSE_SCROLLED,  // �������¼�
        SE_ET_MBTN_PRESSED,    // ���������¼�
        SE_ET_MBTN_RELEASED,   // �����ɿ��¼�
        SE_ET_MBTN_TYPED,      // ��갴���¼�
    };

    enum EEventCategory
    {
        SE_EC_NONE              = 0,             // NULL
        SE_EC_APPLICATION       = SE_BIT(0),     // Ӧ���¼���0��
        SE_EC_INPUT             = SE_BIT(1),     // �����¼���1��
        SE_EC_KEYBOARD          = SE_BIT(2),     // �����¼���2��
        SE_EC_MOUSE             = SE_BIT(3),     // ����¼���3��
        SE_EC_MOUSE_BTN         = SE_BIT(4)      // ��갴���¼���4��
    };

/* ����Ĭ�ϵķ��� */
#define SE_EVENT_CLASS_TYPE(type) static EEventType GetStaticType() { return EEventType::##type; } \
    virtual EEventType GetEventType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; }

/* ������ȡ�¼���ʶλ�ķ��� */
#define SE_EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


    class SE_API CEvent
    {
    public:
        virtual ~CEvent() = default;

        /// ��ȡ�¼�������
        virtual EEventType GetEventType() const = 0;

        /// ��ȡ�¼�������
        virtual const char* GetName() const = 0;

        /// ��ȡ�¼����͵ı�ʶλ
        virtual int GetCategoryFlags() const = 0;

        /// �ַ������
        virtual std::string ToString() const { return GetName(); }
        
        /// �ж��Ƿ���ĳһ���¼�����
        bool IsInCategory(EEventCategory category)
        {
            return GetCategoryFlags() & category;
        }

        /* �¼��Ƿ������ */
        bool m_bHandled = false;
    };

    class CEventDispatcher
    {
    public:
        CEventDispatcher(CEvent& event)
            : m_Event(event)
        {

        }

        /// �¼�����ģ��
        template<typename T, typename F>
        bool Dispatch(const F& func) 
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_bHandled = func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }
    
    private:
        /* ������¼� */
        CEvent& m_Event;
    };

    /// �����¼������������ź���
    inline std::ostream& operator<<(std::ostream& os, const CEvent& e)
    {
        return os << e.ToString();
    }
}