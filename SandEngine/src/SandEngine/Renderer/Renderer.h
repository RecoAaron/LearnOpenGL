#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: 渲染抽象对象，确定 API 接口
*************************************************/
#include "SandEngine/Renderer/RenderCommand.h"
#include "SandEngine/Renderer/Shader.h"

namespace SandEngine {

    class CRenderer
    {
    public:
        /// 初始化 Renderer
        static void Init();

        /// 结束 Renderer
        static void Shutdown();

        /// 获取 API 类型
        static CRendererAPI::EAPI GetAPI() { return CRendererAPI::GetAPI(); }
    };
}