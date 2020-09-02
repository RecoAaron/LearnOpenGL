#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-02
 * Description: 图形渲染 VAO 抽象类
*************************************************/
#include "SandEngine/Renderer/Buffer.h"

namespace SandEngine {

    class CVertexArray
    {
    public:
        virtual ~CVertexArray() = default;

        /// 绑定 VertexArray 对象
        virtual void Bind() const = 0;
        /// 取消绑定 VertexArray 对象
        virtual void Unbind() const = 0;

        /// 为 VertexArray 添加 VertexBuffer 对象
        virtual void AddVertexBuffer(const Ref<CVertexBuffer>& pVertexBuffer) = 0;
        /// 为 VertexArray 设置 IndexBuffer 对象
        virtual void SetIndexBuffer(const Ref<CIndexBuffer>& pIndexBuffer) = 0;

        /// 获取存储 VertexBuffer 对象的容器
        virtual const std::vector<Ref<CVertexBuffer>>& GetVertexBuffers() const = 0;

        /// 获取 IndexBuffer 对象
        virtual const Ref<CIndexBuffer>& GetIndexBuffer() const = 0;

        /// 创建 VertexArray 对象
        static Ref<CVertexArray> Create();
    };
}