#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-17
 * Description: 窗口抽象类
*************************************************/
#include "sdpch.h"

#include "SandEngine/Core/Base.h"
#include "SandEngine/Events/Event.h"

namespace SE {

    struct SWindowProps
    {
        /* 窗口的标题 */
        std::string m_strTitle;

        /* 窗口的宽度和高度 */
        uint32_t m_nWidth, m_nHeight;

        SWindowProps(const std::string& strTitle = "Sand Engine", uint32_t nWidth = 1280, uint32_t nHeight = 720)
            : m_strTitle(strTitle), m_nWidth(nWidth), m_nHeight(nHeight)
        {

        }
    };

    class SE_API CWindow
    {
    public:
        /* 窗口事件回调函数类型 void fun(CEvent& event) */
        using EventCallbackFn = std::function<void(CEvent&)>;

        virtual ~CWindow() = default;

        /// 窗口进行更新
        virtual void OnUpdate() = 0;

        /// 获取窗口的宽度
        virtual uint32_t GetWidth() const = 0;
        /// 获取窗口的高度
        virtual uint32_t GetHeight() const = 0;

        /// 设置窗口事件的回调函数
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

        /// 设置是否启用垂直同步
        virtual void SetVSync(bool bEnable) = 0;
        /// 是否启用了垂直同步
        virtual bool IsVSync() const = 0;

        /// 静态构造窗口函数，Scope = unique_ptr 防止内存泄漏
        static Scope<CWindow> Create(const SWindowProps& props = SWindowProps());
    };
}