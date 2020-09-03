#pragma once
#include <SandEngine.h>

class ExampleLayer : public SandEngine::CLayer
{
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(SandEngine::CTimestep& time) override;
    virtual void OnImGuiRender() override;
    void OnEvent(SandEngine::CEvent& event) override;
private:
    SandEngine::CShaderLibrary m_ShaderLibrary;

    SandEngine::Ref<SandEngine::CVertexArray> m_VertexArray;
    SandEngine::Ref<SandEngine::CVertexArray> m_SquareVertexArray;
    SandEngine::Ref<SandEngine::CTexture2D> m_SquareTexture;

    SandEngine::COrthographicCameraController m_CameraController;
};