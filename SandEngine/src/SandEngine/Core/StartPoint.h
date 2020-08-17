#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: SandEngine 应用程序启动入口
*************************************************/

#ifdef SE_PLATFORM_WINDOWS /* Sand Engine 定义在 Windows 上 */

/* 由用户自定义创建 Application 的方式，在 main 中自动创建 */
extern SE::CApplication* SE::CreateApplication();

int main(int argc, char** argv)
{
    SE::CLog::Init();
    SE_LOG_TRACE_CORE("the logger core is logging!");
    int id = 123456;
    SE_LOG_INFO("application logging id : {0}", id);

    auto app = SE::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif