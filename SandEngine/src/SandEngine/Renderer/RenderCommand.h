#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: 渲染 API 调用对象
*************************************************/
#include "SandEngine/Renderer/RendererAPI.h"

namespace SandEngine {

    class CRenderCommand
    {
    public:
        /// 初始化 API 接口
        static void Init()
        {
            s_pRendererAPI->Init();
        }

        /// 设置视锥体
        static void SetViewport(uint32_t x, uint32_t y, uint32_t nWidth, uint32_t nHeight)
        {
            s_pRendererAPI->SetViewport(x, y, nWidth, nHeight);
        }

        /// 调用设置清空缓冲区的颜色 API
        static void SetClearColor(const glm::vec4& color)
        {
            s_pRendererAPI->SetClearColor(color);
        }

        /// 调用清空缓冲区 API
        static void Clear()
        {
            s_pRendererAPI->Clear();
        }

        static void DrawIndexed(const Ref<CVertexArray>& vertexArray, uint32_t count = 0)
        {
            s_pRendererAPI->DrawIndexed(vertexArray, count);
        }
    private:
        /* 渲染 API 对象 */
        static Scope<CRendererAPI> s_pRendererAPI;
    };
}