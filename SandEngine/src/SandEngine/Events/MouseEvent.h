#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 鼠标事件处理类
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

        /// 获取鼠标的X坐标位置
        inline float GetPosX() const { return m_MouseX; }
        /// 获取鼠标的Y坐标位置
        inline float GetPosY() const { return m_MouseY; }

        /// 重写输出函数，输出鼠标的坐标信息
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Moved:" << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        /* 设置事件为：鼠标移动事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_MOUSE_MOVED)

        /* 设置事件类型为：鼠标事件 | 输入事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)
    
    private:
        /* 鼠标的坐标位置 */
        float m_MouseX, m_MouseY;
    };

    class SE_API CMouseScrolledEvent : public CEvent
    {
    public:
        CMouseScrolledEvent(float xOffset, float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset)
        {

        }

        /// 获取鼠标的X偏移
        inline float GetXOffset() const { return m_XOffset; }
        /// 获取鼠标的Y偏移
        inline float GetYOffset() const { return m_YOffset; }

        /// 重写输出函数，输出鼠标的偏移信息
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Scrolled:" << m_XOffset << ", " << m_YOffset;
            return ss.str();
    	}

        /* 设置事件为：鼠标移动事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_MOUSE_SCROLLED)

        /* 设置事件类型为：鼠标事件 | 输入事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)

    private:
        /* 鼠标的坐标偏移 */
        float m_XOffset, m_YOffset;
    };

    class SE_API CMouseButtonEvent : public CEvent
    {
    public:
        /// 获取鼠标按键值
        inline int GetMouseButton() const { return m_Button; }

        /* 设置事件类型为：鼠标事件 | 输入事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)
    
    protected:
        CMouseButtonEvent(int button)
            : m_Button(button)
        {

        }

        /* 鼠标按键值 */
        int m_Button;
    };
    
    class SE_API CMouseButtonPressedEvent : public CMouseButtonEvent
    {
    public:
        CMouseButtonPressedEvent(int button)
            : CMouseButtonEvent(button)
        {

        }

        /// 重写输出函数，输出鼠标按键的值
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Button Pressed:" << m_Button;
            return ss.str();
        }

        /* 设置事件为：鼠标键按下事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_MBTN_PRESSED)
    };
    
    class SE_API CMouseButtonReleasedEvent : public CMouseButtonEvent
    {
    public:
        CMouseButtonReleasedEvent(int button)
            : CMouseButtonEvent(button)
        {

        }

        /// 重写输出函数，输出鼠标按键的值
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "S3D_ET_MBTN_RELEASED:" << m_Button;
            return ss.str();
        }

        /* 设置事件为：鼠标键松开事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_MBTN_RELEASED)
    };
}