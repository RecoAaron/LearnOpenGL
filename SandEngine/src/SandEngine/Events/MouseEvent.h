﻿#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 鼠标事件处理类
*************************************************/
#include "SandEngine/Events/Event.h"
#include "SandEngine/Core/InputCode.h"

namespace SandEngine {

    class CMouseMoveEvent : public CEvent
    {
    public:
        CMouseMoveEvent(const float nPosX, const float nPosY)
            : m_nMouseX(nPosX), m_nMouseY(nPosY)
        {

        }

        /// 获取鼠标的X坐标位置
        inline float GetPosX() const { return m_nMouseX; }
        /// 获取鼠标的Y坐标位置
        inline float GetPosY() const { return m_nMouseY; }

        /// 重写输出函数，输出鼠标的坐标信息
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Moved:" << m_nMouseX << ", " << m_nMouseY;
            return ss.str();
        }

        /* 设置事件为：鼠标移动事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_MOUSE_MOVED)

        /* 设置事件类型为：鼠标事件 | 输入事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)
    
    private:
        /* 鼠标的坐标位置 */
        float m_nMouseX, m_nMouseY;
    };

    class CMouseScrolledEvent : public CEvent
    {
    public:
        CMouseScrolledEvent(const float nXOffset, const float nYOffset)
            : m_nXOffset(nXOffset), m_nYOffset(nYOffset)
        {

        }

        /// 获取鼠标的X偏移
        inline float GetXOffset() const { return m_nXOffset; }
        /// 获取鼠标的Y偏移
        inline float GetYOffset() const { return m_nYOffset; }

        /// 重写输出函数，输出鼠标的偏移信息
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Scrolled:" << m_nXOffset << ", " << m_nYOffset;
            return ss.str();
    	}

        /* 设置事件为：鼠标移动事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_MOUSE_SCROLLED)

        /* 设置事件类型为：鼠标事件 | 输入事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)

    private:
        /* 鼠标的坐标偏移 */
        float m_nXOffset, m_nYOffset;
    };

    class CMouseButtonEvent : public CEvent
    {
    public:
        /// 获取鼠标按键值
        KeyCode GetMouseButton() const { return m_nButton; }

        /* 设置事件类型为：鼠标事件 | 输入事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_MOUSE | SE_EC_INPUT)
    
    protected:
        CMouseButtonEvent(const KeyCode nButton)
            : m_nButton(nButton)
        {

        }

        /* 鼠标按键值 */
        KeyCode m_nButton;
    };
    
    class CMouseButtonPressedEvent : public CMouseButtonEvent
    {
    public:
        CMouseButtonPressedEvent(const KeyCode nButton)
            : CMouseButtonEvent(nButton)
        {

        }

        /// 重写输出函数，输出鼠标按键的值
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Button Pressed:" << m_nButton;
            return ss.str();
        }

        /* 设置事件为：鼠标键按下事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_MBTN_PRESSED)
    };
    
    class CMouseButtonReleasedEvent : public CMouseButtonEvent
    {
    public:
        CMouseButtonReleasedEvent(const KeyCode nButton)
            : CMouseButtonEvent(nButton)
        {

        }

        /// 重写输出函数，输出鼠标按键的值
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Button Released:" << m_nButton;
            return ss.str();
        }

        /* 设置事件为：鼠标键松开事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_MBTN_RELEASED)
    };
}