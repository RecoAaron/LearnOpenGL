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
    auto app = SandEngine::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif