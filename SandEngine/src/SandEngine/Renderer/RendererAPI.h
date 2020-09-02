#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: 图形渲染接口API抽象对象
*************************************************/
#include <glm/glm.hpp>

#include "SandEngine/Renderer/VertexArray.h"

namespace SandEngine {

    class CRendererAPI
    {
    public:
        enum class EAPI
        {
            None    = 0, 
            OpenGL  = 1
        };

        virtual ~CRendererAPI() = default;

        /// 初始化 API
        virtual void Init() = 0;

        /// 设置视锥体
        virtual void SetViewport(uint32_t x, uint32_t y, uint32_t nWidth, uint32_t nHeight) = 0;

        /// 设置清空缓冲区的颜色
        virtual void SetClearColor(const glm::vec4 & vec4Color) = 0;

        /// 清空缓冲区
        virtual void Clear() = 0;

        /// 绘制 Vertex Array 对象
        virtual void DrawIndexed(const Ref<CVertexArray>& pVertexArray, uint32_t nIndexCount = 0) = 0;

        /// 获取 API
        static EAPI GetAPI() { return s_API; }

        /// 创建 API 对象
        static Scope<CRendererAPI> Create();

    private:
        /* API 对象 */
        static EAPI s_API;
    };
}