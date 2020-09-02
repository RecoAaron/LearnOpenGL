#include "sdpch.h"

#include "Renderer.h"

namespace SandEngine {

    Scope<CRenderer::SSceneData> CRenderer::s_pSceneData = CreateScope<CRenderer::SSceneData>();

    void CRenderer::Init()
    {
        CRenderCommand::Init();
    }

    void CRenderer::Shutdown()
    {

    }

    void CRenderer::OnWindowResize(uint32_t nWidth, uint32_t nHeight)
    {
        CRenderCommand::SetViewport(0, 0, nWidth, nHeight);
    }

    void CRenderer::BeginScene(COrthographicCamera& camera)
    {
        s_pSceneData->m_mat4ViewProjectionMatrix = camera.GetViewProjectionMatrix();
    }

    void CRenderer::EndScene()
    {

    }

    void CRenderer::Submit(const Ref<CShader>& pShader, const Ref<CVertexArray>& pVertexArray, const glm::mat4& mat4Transform)
    {
        pShader->Bind();
        pShader->SetMat4("u_ViewProjection", s_pSceneData->m_mat4ViewProjectionMatrix);
        pShader->SetMat4("u_Transform", mat4Transform);

        pVertexArray->Bind();
        CRenderCommand::DrawIndexed(pVertexArray);
    }
}