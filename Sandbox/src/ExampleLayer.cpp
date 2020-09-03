#include "ExampleLayer.h"

ExampleLayer::ExampleLayer()
    : CLayer("Example Layer"), m_CameraController(1280.0f / 720.0f)
{
#pragma region 测试用的三角形

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
    m_VertexArray->Bind();
    m_VertexArray->AddVertexBuffer(vertexBuffer);

    uint32_t indices[3] = { 0, 1, 2 };
    SandEngine::Ref<SandEngine::CIndexBuffer> indexBuffer = SandEngine::CIndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
    m_VertexArray->SetIndexBuffer(indexBuffer);
    m_VertexArray->Unbind();

    m_ShaderLibrary.LoadShader("assets/shaders/Triangle.glsl");

#pragma endregion

#pragma region 纹理加载及shader文件测试

    m_SquareVertexArray = SandEngine::CVertexArray::Create();

    float squareVertices[5 * 4] = {
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    SandEngine::Ref<SandEngine::CVertexBuffer> squareVertexBuffer = SandEngine::CVertexBuffer::Create(squareVertices, sizeof(squareVertices));
    SandEngine::CBufferLayout squareLayout = {
        { SandEngine::EShaderDataType::Float3, "a_Position" },
        { SandEngine::EShaderDataType::Float2, "a_TexCoord" }
    };
    squareVertexBuffer->SetLayout(squareLayout);
    m_SquareVertexArray->Bind();
    m_SquareVertexArray->AddVertexBuffer(squareVertexBuffer);
    uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
    SandEngine::Ref<SandEngine::CIndexBuffer> squareIndexBuffer = SandEngine::CIndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
    m_SquareVertexArray->SetIndexBuffer(squareIndexBuffer);
    m_SquareVertexArray->Unbind();

    auto squareShader = m_ShaderLibrary.LoadShader("assets/shaders/Texture.glsl");
    m_SquareTexture = SandEngine::CTexture2D::Create("assets/textures/Checkerboard.png");
    squareShader->Bind();
    squareShader->SetInt("u_Texture", 0);
    squareShader->Unbind();

#pragma endregion
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

    SandEngine::CRenderer::Submit(m_ShaderLibrary.GetShader("Triangle"), m_VertexArray);
    m_SquareTexture->Bind();
    SandEngine::CRenderer::Submit(m_ShaderLibrary.GetShader("Texture"), m_SquareVertexArray);

    SandEngine::CRenderer::EndScene();
}

void ExampleLayer::OnImGuiRender()
{

}

void ExampleLayer::OnEvent(SandEngine::CEvent& event)
{
    m_CameraController.OnEvent(event);
}
