#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 应用程序定义
*************************************************/
#include "SandEngine/Core/Window.h"
#include "SandEngine/Events/ApplicationEvent.h"
#include "SandEngine/Core/LayerStack.h"
#include "SandEngine/ImGui/ImGuiLayer.h"

namespace SandEngine {

    class CApplication
    {
    public:
        CApplication(const std::string& name = "Sand Engine");
        virtual ~CApplication();

        /// 获取窗口指针
        CWindow& GetWindow() { return *m_pWindow; }

        /// 窗口添加一个层级对象
        void PushLayer(CLayer* pLayer);
        /// 窗口添加一个顶层层级对象
        void PushOverlay(CLayer* pOverlay); 

        /// 应用程序开始运行
        void Run();

        /// 处理应用程序事件
        void OnEvent(CEvent& event);

        /// 应用程序关闭事件
        bool OnWindowClose(CWindowCloseEvent& event);

        /// 获取应用程序单例对象
        static CApplication& GetInstance() { return *s_pInstance; }

    private:
        /* 窗口指针 */
        Scope<CWindow> m_pWindow;

        /* ImGui 层级，空层级用于调用函数 */
        CImGuiLayer* m_pImGuiLayer;

        /* 窗口层级存储栈 */
        CLayerStack m_LayerStack;

        /* 应用程序运行标志 */
        bool m_bRunning = true;

    private:
        /* 应用程序单例指针 */
        static CApplication* s_pInstance;
    };

    /// 自定义创建应用程序的方法
    CApplication* CreateApplication();
}