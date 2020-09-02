#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: OpenGL 实现渲染API
*************************************************/
#include "SandEngine/Renderer/RendererAPI.h"

namespace SandEngine {

    class COpenGLRendererAPI : public CRendererAPI
    {
    public:
        /// 初始化 OpenGL API
        virtual void Init() override;

        /// 设置视锥体
        virtual void SetViewport(uint32_t x, uint32_t y, uint32_t nWidth, uint32_t nHeight) override;

        /// OpenGL 设置清空缓冲区的颜色
        virtual void SetClearColor(const glm::vec4& vec4Color) override;

        /// OpenGL 清空缓冲区
        virtual void Clear() override;

        /// 绘制 OpenGL Vertex Array 对象
        virtual void DrawIndexed(const Ref<CVertexArray>& pVertexArray, uint32_t nIndexCount = 0) override;
    };
}