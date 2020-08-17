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

/// 自定义创建应用程序的方法
SE::CApplication* SE::CreateApplication()
{
    return new Sandbox();
}