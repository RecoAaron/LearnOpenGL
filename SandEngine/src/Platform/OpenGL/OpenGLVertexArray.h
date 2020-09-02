#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-02
 * Description: OpenGL 实现图形渲染 VAO
*************************************************/
#include "SandEngine/Renderer/VertexArray.h"

namespace SandEngine {

    class COpenGLVertexArray : public CVertexArray
    {
    public:
        COpenGLVertexArray();
        virtual ~COpenGLVertexArray();

        /// 绑定 OpenGL VertexArray 对象
        virtual void Bind() const override;
        // 取消绑定 OpenGL VertexArray 对象
        virtual void Unbind() const override;

        /// 为 VertexArray 添加 VertexBuffer 对象
        virtual void AddVertexBuffer(const Ref<CVertexBuffer>& pVertexBuffer) override;

        /// 为 VertexArray 设置 IndexBuffer 对象
        virtual void SetIndexBuffer(const Ref<CIndexBuffer>& pIndexBuffer) override;

        /// 获取存储 VertexBuffer 对象的容器
        virtual const std::vector<Ref<CVertexBuffer>>& GetVertexBuffers() const { return m_pVertexBuffers; }

        /// 获取 IndexBuffer 对象
        virtual const Ref<CIndexBuffer>& GetIndexBuffer() const { return m_pIndexBuffer; }
    private:
        /* VertexArray 对象 ID */
        uint32_t m_nRendererID;

        /* VertexBuffer 索引 */
        uint32_t m_nVertexBufferIndex = 0;

        /* 存储 VertexBuffer 对象的容器 */
        std::vector<Ref<CVertexBuffer>> m_pVertexBuffers;

        /* IndexBuffer 对象 */
        Ref<CIndexBuffer> m_pIndexBuffer;
    };
}