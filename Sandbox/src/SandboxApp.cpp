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

/// 自定义创建应用程序的方法
SandEngine::CApplication* SandEngine::CreateApplication()
{
    return new Sandbox();
}