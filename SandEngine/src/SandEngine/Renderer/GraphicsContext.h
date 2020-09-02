#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: 图形渲染接口，上下文抽象类
*************************************************/

namespace SandEngine {

    class CGraphicsContext
    {
    public:
        virtual ~CGraphicsContext() = default;

        /// 初始化上下文
        virtual void Init() = 0;

        /// 交换缓冲区
        virtual void SwapBuffers() = 0;

        /// 创建上下文对象
        static Scope<CGraphicsContext> Create(void* pWindow);
    };
}