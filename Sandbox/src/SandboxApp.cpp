#include <SandEngine.h>

class Sandbox : public SandEngine::CApplication
{
public:
    Sandbox()
    {
        
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