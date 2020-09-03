#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: 渲染抽象对象，确定 API 接口
*************************************************/
#include "SandEngine/Renderer/RenderCommand.h"
#include "SandEngine/Renderer/OrthographicCamera.h"
#include "SandEngine/Renderer/Shader.h"

namespace SandEngine {

    class CRenderer
    {
    public:
        /// 初始化 Renderer
        static void Init();

        /// 结束 Renderer
        static void Shutdown();

        /// 窗体缩放时，需要设置视锥体
        static void OnWindowResize(uint32_t nWidth, uint32_t nHeight);

        /// 开始绘制场景
        static void BeginScene(COrthographicCamera& camera);

        /// 结束场景绘制
        static void EndScene();

        /// 获取 API 类型
        static CRendererAPI::ERenderAPI GetAPI() { return CRendererAPI::GetAPI(); }

        /// 使用着色器渲染
        static void Submit(const Ref<CShader>& pShader, const Ref<CVertexArray>& pVertexArray, const glm::mat4& mat4Transform = glm::mat4(1.0f));

    private:
        struct SSceneData
        {
            glm::mat4 m_mat4ViewProjectionMatrix;
        };

        static Scope<SSceneData> s_pSceneData;
    };
}