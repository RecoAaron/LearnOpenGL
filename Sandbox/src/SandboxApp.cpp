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

/// �Զ��崴��Ӧ�ó���ķ���
SandEngine::CApplication* SandEngine::CreateApplication()
{
    return new Sandbox();
}