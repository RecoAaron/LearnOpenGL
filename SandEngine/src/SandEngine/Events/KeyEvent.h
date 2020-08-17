#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 键盘事件处理类
*************************************************/
#include "SandEngine/Events/Event.h"

namespace SE {

    class SE_API CKeyEvent : public CEvent
    {
    public:
        /// 获取按键的编码
        inline int GetKeyCode() const { return m_KeyCode; }

        /* 设置事件类型为：键盘事件 | 输入事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_KEYBOARD | SE_EC_INPUT)

    protected:
        CKeyEvent(int keycode)
            : m_KeyCode(keycode)
        {

        }

        /* 按键的编码 */
        int m_KeyCode;
    };

    class SE_API CKeyPressedEvent : public CKeyEvent
    {
    public:
        CKeyPressedEvent(int keycode, int repeatCount)
            :CKeyEvent(keycode), m_RepeatCount(repeatCount)
        {

        }

        /// 获取重复次数，超过0标识键长按
        inline int GetRepeatCount() const { return m_RepeatCount; }

        /// 重写输出函数，输出按键的编码和重复次数
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key Pressed:" << m_KeyCode << "(" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        /// 设置事件为：键按下事件
        SE_EVENT_CLASS_TYPE(SE_ET_KEY_PRESSED)
    
    private:
        /* 按键的重复次数 */
    	int m_RepeatCount;
    };

    class S3D_API CKeyReleasedEvent : public CKeyEvent
    {
    public:
        CKeyReleasedEvent(int keycode)
            : CKeyEvent(keycode)
        {

        }

        /// 重写输出函数，输出按键的编码
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key Released:" << m_KeyCode;
            return ss.str();
        }

        /// 设置键按下事件为：键按下事件
        S3D_EVENT_CLASS_TYPE(SE_ET_KEY_RELEASED)
    };
}