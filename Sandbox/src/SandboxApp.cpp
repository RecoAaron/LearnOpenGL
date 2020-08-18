#include <SandEngine.h>

using namespace SandEngine;

class ExampleLayer : public CLayer
{
public:
    ExampleLayer()
        : CLayer("Example")
    {

    }

private:
    void OnUpdate() override
    {
        SE_LOG_INFO("ExampleLayer::OnUpdate");
    }

    void OnEvent(CEvent& event) override
    {
        SE_LOG_TRACE("{0}", event);
    }
};

class Sandbox : public CApplication
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