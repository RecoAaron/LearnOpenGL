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

namespace SE {

    class SE_API CApplication
    {
    public:
        CApplication();
        virtual ~CApplication();

        /// 应用程序开始运行
        void Run();

        /// 处理应用程序事件
        void OnEvent(CEvent& event);

    private:
        /* 窗口指针 */
        Scope<CWindow> m_pWindow;
    };

    /// 自定义创建应用程序的方法
    CApplication* CreateApplication();
}