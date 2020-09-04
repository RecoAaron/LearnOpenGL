#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: SandEngine 应用程序启动入口
*************************************************/

#ifdef SE_PLATFORM_WINDOWS /* Sand Engine 定义在 Windows 上 */

/* 由用户自定义创建 Application 的方式，在 main 中自动创建 */
extern SandEngine::CApplication* SandEngine::CreateApplication();

int main(int argc, char** argv)
{
    SandEngine::CLog::Init();

    SE_PROFILE_BEGIN_SESSION("Startup", "SandEngineProfile-Startup.json");
    auto app = SandEngine::CreateApplication();
    SE_PROFILE_END_SESSION();

    SE_PROFILE_BEGIN_SESSION("Runtime", "SandEngineProfile-Runtime.json");
    app->Run();
    SE_PROFILE_END_SESSION();

    SE_PROFILE_BEGIN_SESSION("Shutdown", "SandEngineProfile-Shutdown.json");
    delete app;
    SE_PROFILE_END_SESSION();

    return 0;
}

#endif