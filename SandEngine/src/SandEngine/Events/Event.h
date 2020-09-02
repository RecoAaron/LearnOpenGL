#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 事件处理抽象类
*************************************************/
#include "sdpch.h"

namespace SandEngine {

    enum class EEventType
    {
        SE_ET_NONE = 0,         // NULL

        /* 窗口事件 */
        SE_ET_WIN_CLOSE,        // 窗口关闭事件
        SE_ET_WIN_RESIZE,       // 窗口缩放事件

        /* 应用程序事件 */
        SE_ET_APP_TICK,        // 帧事件
        SE_ET_APP_UPDATE,      // 更新事件 

        /* 键盘事件 */
        SE_ET_KEY_PRESSED,     // 键按下事件
        SE_ET_KEY_RELEASED,    // 键松开事件
        SE_ET_KEY_TYPED,       // 按键事件

        /* 鼠标事件 */
        SE_ET_MOUSE_MOVED,     // 鼠标移动事件
        SE_ET_MOUSE_SCROLLED,  // 鼠标滚轮事件
        SE_ET_MBTN_PRESSED,    // 鼠标键按下事件
        SE_ET_MBTN_RELEASED,   // 鼠标键松开事件
        SE_ET_MBTN_TYPED,      // 鼠标按键事件
    };

    enum EEventCategory
    {
        SE_EC_NONE              = 0,             // NULL
        SE_EC_APPLICATION       = SE_BIT(0),     // 应用事件（0）
        SE_EC_INPUT             = SE_BIT(1),     // 输入事件（1）
        SE_EC_KEYBOARD          = SE_BIT(2),     // 键盘事件（2）
        SE_EC_MOUSE             = SE_BIT(3),     // 鼠标事件（3）
        SE_EC_MOUSE_BTN         = SE_BIT(4)      // 鼠标按键事件（4）
    };

/* 创建默认的方法 */
#define SE_EVENT_CLASS_TYPE(type) static EEventType GetStaticType() { return EEventType::##type; } \
    virtual EEventType GetEventType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; }

/* 创建获取事件标识位的方法 */
#define SE_EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


    class CEvent
    {
    public:
        virtual ~CEvent() = default;

        /// 获取事件的类型
        virtual EEventType GetEventType() const = 0;

        /// 获取事件的名称
        virtual const char* GetName() const = 0;

        /// 获取事件类型的标识位
        virtual int GetCategoryFlags() const = 0;

        /// 字符串输出
        virtual std::string ToString() const { return GetName(); }
        
        /// 判断是否是某一种事件类型
        bool IsInCategory(EEventCategory category)
        {
            return GetCategoryFlags() & category;
        }

        /* 事件是否处理完毕 */
        bool m_bHandled = false;
    };

    class CEventDispatcher
    {
    public:
        CEventDispatcher(CEvent& event)
            : m_Event(event)
        {

        }

        /// 事件处理模板
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
        /* 处理的事件 */
        CEvent& m_Event;
    };

    /// 定义事件的流操作符号函数
    inline std::ostream& operator<<(std::ostream& os, const CEvent& e)
    {
        return os << e.ToString();
    }
}