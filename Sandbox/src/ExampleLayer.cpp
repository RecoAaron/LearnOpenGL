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
                color = v_Color;
            }
        )";

    m_Shader = SandEngine::CShader::Create("VertexPosColor", vertexSrc, fragmentSrc);

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
    m_SquareVertexArray->AddVertexBuffer(squareVertexBuffer);
    uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
    SandEngine::Ref<SandEngine::CIndexBuffer> squareIndexBuffer = SandEngine::CIndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
    m_SquareVertexArray->SetIndexBuffer(squareIndexBuffer);
    m_SquareShader = SandEngine::CShader::Create("assets/shaders/Texture.glsl");
    m_SquareTexture = SandEngine::CTexture2D::Create("assets/textures/Checkerboard.png");
    m_SquareShader->Bind();
    m_SquareShader->SetInt("u_Texture", 0);
    m_SquareShader->Unbind();

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

    SandEngine::CRenderer::Submit(m_Shader, m_VertexArray);
    m_SquareTexture->Bind();
    SandEngine::CRenderer::Submit(m_SquareShader, m_SquareVertexArray);

    SandEngine::CRenderer::EndScene();
}

void ExampleLayer::OnImGuiRender()
{

}

void ExampleLayer::OnEvent(SandEngine::CEvent& event)
{
    m_CameraController.OnEvent(event);
}
