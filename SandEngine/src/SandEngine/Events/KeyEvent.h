#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 键盘事件处理类
*************************************************/
#include "SandEngine/Events/Event.h"
#include "SandEngine/Core/InputCode.h"

namespace SandEngine {

    class CKeyEvent : public CEvent
    {
    public:
        /// 获取按键的编码
        inline int GetKeyCode() const { return m_nKeyCode; }

        /* 设置事件类型为：键盘事件 | 输入事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_KEYBOARD | SE_EC_INPUT)

    protected:
        CKeyEvent(const KeyCode nKeycode)
            : m_nKeyCode(nKeycode)
        {

        }

        /* 按键的编码 */
        KeyCode m_nKeyCode;
    };

    class CKeyPressedEvent : public CKeyEvent
    {
    public:
        CKeyPressedEvent(const KeyCode nKeycode, int nRepeatCount)
            :CKeyEvent(nKeycode), m_nRepeatCount(nRepeatCount)
        {

        }

        /// 获取重复次数，超过0标识键长按
        inline int GetRepeatCount() const { return m_nRepeatCount; }

        /// 重写输出函数，输出按键的编码和重复次数
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key Pressed:" << m_nKeyCode << "(" << m_nRepeatCount << " repeats)";
            return ss.str();
        }

        /// 设置事件为：键按下事件
        SE_EVENT_CLASS_TYPE(SE_ET_KEY_PRESSED)
    
    private:
        /* 按键的重复次数 */
        int m_nRepeatCount;
    };

    class CKeyReleasedEvent : public CKeyEvent
    {
    public:
        CKeyReleasedEvent(const KeyCode nKeycode)
            : CKeyEvent(nKeycode)
        {

        }

        /// 重写输出函数，输出按键的编码
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key Released:" << m_nKeyCode;
            return ss.str();
        }

        /// 设置键按下事件为：键按下事件
        SE_EVENT_CLASS_TYPE(SE_ET_KEY_RELEASED)
    };

    class CKeyTypedEvent : public CKeyEvent
    {
    public:
        CKeyTypedEvent(const KeyCode keycode)
            : CKeyEvent(keycode)
        {

        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_nKeyCode;
            return ss.str();
        }

        SE_EVENT_CLASS_TYPE(SE_ET_KEY_TYPED)
    };
}