#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 应用程序定义
*************************************************/
#include "SandEngine/Core/Base.h"
#include "SandEngine/Core/Window.h"
#include "SandEngine/Events/Event.h"
#include "SandEngine/Events/ApplicationEvent.h"
#include "SandEngine/Core/LayerStack.h"

namespace SandEngine {

    class SE_API CApplication
    {
    public:
        CApplication();
        virtual ~CApplication();

        void PushLayer(CLayer* pLayer);
        void PushOverlay(CLayer* pOverlay); 

        /// 应用程序开始运行
        void Run();

        /// 处理应用程序事件
        void OnEvent(CEvent& event);

        /* 应用程序关闭事件 */
        bool OnWindowClose(CWindowCloseEvent& event);

    private:
        /* 窗口指针 */
        Scope<CWindow> m_pWindow;

        /* 窗口层级存储栈 */
        CLayerStack m_layerStack;

        /* 应用程序运行标志 */
        bool m_bRunning = true;
    };

    /// 自定义创建应用程序的方法
    CApplication* CreateApplication();
}