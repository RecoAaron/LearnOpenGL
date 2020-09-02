#include <SandEngine.h>
#include <SandEngine/Core/StartPoint.h>

#include "ExampleLayer.h"

class Sandbox : public SandEngine::CApplication
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }
};

/// 自定义创建应用程序的方法
SandEngine::CApplication* SandEngine::CreateApplication()
{
    return new Sandbox();
}