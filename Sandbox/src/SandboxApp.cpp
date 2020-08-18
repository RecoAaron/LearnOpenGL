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

/// �Զ��崴��Ӧ�ó���ķ���
SandEngine::CApplication* SandEngine::CreateApplication()
{
    return new Sandbox();
}