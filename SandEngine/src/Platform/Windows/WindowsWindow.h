#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: Windows 平台窗口实现
*************************************************/
#include "SandEngine/Core/Window.h"

#include <GLFW/glfw3.h>

namespace SandEngine {

    class CWindowsWindow : public CWindow
    {
    public:
        CWindowsWindow(const SWindowProps& props);
        virtual ~CWindowsWindow();

        /// 窗口进行更新
        void OnUpdate() override;

        /// 获取窗口的宽度
        uint32_t GetWidth() const override { return m_Data.m_nWidth; }
        /// 获取窗口的高度
        uint32_t GetHeight() const override { return m_Data.m_nHeight; }

        /// 设置窗口事件的回调函数
        void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

        /// 设置是否启用垂直同步
        void SetVSync(bool bEnable) override;
        /// 是否启用了垂直同步
        bool IsVSync() const override;

    private:
        /// 初始化窗口
        virtual void Init(const SWindowProps& props);

        /// 结束窗口进程
        virtual void Shutdown();

        struct SWindowData
        {
            /* 窗口的标题 */
            std::string m_strTitle;

            /* 窗口的宽度和高度 */
            uint32_t m_nWidth, m_nHeight;

            /* 窗口是否垂直同步 */
            bool m_bVSync;

            /* 窗口的回调函数 */
            EventCallbackFn EventCallback;
        };

        /* 窗口数据 */
        SWindowData m_Data;

        /* 窗口的指针 */
        GLFWwindow* m_pWindow;
    };
}