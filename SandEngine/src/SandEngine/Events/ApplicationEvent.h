#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 应用程序事件处理类
*************************************************/
#include "SandEngine/Events/Event.h"

namespace SandEngine {

    class CWindowResizeEvent : public CEvent
    {
    public:
        CWindowResizeEvent(unsigned int nWidth, unsigned int nHeight)
            : m_nWidth(nWidth), m_nHeight(nHeight)
        {

        }

        /// 获取窗口的宽度
        inline unsigned int GetWidth() const { return m_nWidth; }
        /// 获取窗口的高度
        inline unsigned int GetHeight() const { return m_nHeight; }

        /// 重写输出函数，输出窗口的宽度和高度
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Window Resized:" << m_nWidth << ", " << m_nHeight;
            return ss.str();
        }

        /* 设置事件为：窗口缩放事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_WIN_RESIZE)

        /* 设置事件类型为：应用事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_APPLICATION)

    private:
        /* 窗口的宽度和高度 */
        unsigned int m_nWidth, m_nHeight;
    };


    class CWindowCloseEvent : public CEvent
    {
    public:
        CWindowCloseEvent()
        {

        }

        /* 设置事件为：窗口关闭事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_WIN_CLOSE)

        /* 设置事件类型为：应用事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_APPLICATION)
    };

    class CApplicationTickEvent : public CEvent
    {
    public:
        CApplicationTickEvent()
        {

        }

        /* 设置事件为：帧事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_APP_TICK)

        /* 设置事件类型为：应用事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_APPLICATION)
    };

    class CApplicationUpdateEvent : public CEvent
    {
    public:
        CApplicationUpdateEvent()
        {

        }

        /* 设置事件为：窗口关闭事件 */
        SE_EVENT_CLASS_TYPE(SE_ET_APP_UPDATE)

        /* 设置事件类型为：应用事件 */
        SE_EVENT_CLASS_CATEGORY(SE_EC_APPLICATION)
    };
}