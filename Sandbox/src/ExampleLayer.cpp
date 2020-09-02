#include "ExampleLayer.h"

ExampleLayer::ExampleLayer()
    : CLayer("Example Layer"), m_CameraController(1280.0f / 720.0f)
{
    m_VertexArray = SandEngine::CVertexArray::Create();

    float vertices[3 * 7] = {
        -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
         0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
         0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
    };

    SandEngine::Ref<SandEngine::CVertexBuffer> vertexBuffer = SandEngine::CVertexBuffer::Create(vertices, sizeof(vertices));
    SandEngine::CBufferLayout layout = {
        { SandEngine::EShaderDataType::Float3, "a_Position" },
        { SandEngine::EShaderDataType::Float4, "a_Color" }
    };
    vertexBuffer->SetLayout(layout);
    m_VertexArray->AddVertexBuffer(vertexBuffer);

    uint32_t indices[3] = { 0, 1, 2 };
    SandEngine::Ref<SandEngine::CIndexBuffer> indexBuffer = SandEngine::CIndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
    m_VertexArray->SetIndexBuffer(indexBuffer);

    std::string vertexSrc = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec3 v_Position;
            out vec4 v_Color;

            void main()
            {
                v_Position = a_Position;
                v_Color = a_Color;
                gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
            }
        )";

    std::string fragmentSrc = R"(
            #version 330 core
            
            layout(location = 0) out vec4 color;

            in vec3 v_Position;
            in vec4 v_Color;

            void main()
            {
                color = vec4(v_Position * 0.5 + 0.5, 1.0);
            }
        )";

    m_Shader = SandEngine::CShader::Create("VertexPosColor", vertexSrc, fragmentSrc);
}

void ExampleLayer::OnAttach()
{

}

void ExampleLayer::OnDetach()
{

}

void ExampleLayer::OnUpdate(SandEngine::CTimestep& time)
{
    m_CameraController.OnUpdate(time);

    SandEngine::CRenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
    SandEngine::CRenderCommand::Clear();

    SandEngine::CRenderer::BeginScene(m_CameraController.GetCamera());

    SandEngine::CRenderer::Submit(m_Shader, m_VertexArray);

    SandEngine::CRenderer::EndScene();
}

void ExampleLayer::OnImGuiRender()
{

}

void ExampleLayer::OnEvent(SandEngine::CEvent& event)
{
    m_CameraController.OnEvent(event);
}
