#pragma once
#include <SandEngine.h>

class ExampleLayer : public SandEngine::CLayer
{
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate() override;
    virtual void OnImGuiRender() override;
    void OnEvent(SandEngine::CEvent& e) override;
private:
    SandEngine::Ref<SandEngine::CShader> m_Shader;
    SandEngine::Ref<SandEngine::CVertexArray> m_VertexArray;
};