#include <SandEngine.h>

class Sandbox : public SE::CApplication
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
SE::CApplication* SE::CreateApplication()
{
    return new Sandbox();
}