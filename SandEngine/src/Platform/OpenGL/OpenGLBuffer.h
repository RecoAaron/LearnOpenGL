#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: OpenGL 实现图形渲染缓冲区
*************************************************/
#include "SandEngine/Renderer/Buffer.h"

namespace SandEngine {

    class COpenGLVertexBuffer : public CVertexBuffer
    {
    public:
        COpenGLVertexBuffer(uint32_t nSize);
        COpenGLVertexBuffer(float* pVertices, uint32_t nSize);
        virtual ~COpenGLVertexBuffer();

        /// 绑定 OpenGL VertexBuffer 对象
        virtual void Bind() const override;
        /// 取消绑定 OpenGL VertexBuffer 对象
        virtual void Unbind() const override;

        /// 设置 OpenGL VertexBuffer 数据
        virtual void SetData(const void* pData, uint32_t nSize) override;

        /// 获取 VertexBuffer 的 Layout
        virtual const CBufferLayout& GetLayout() const override { return m_Layout; }
        /// 设置 VertexBuffer 的 Layout
        virtual void SetLayout(const CBufferLayout& layout) override { m_Layout = layout; }
    private:
        /* VertexBuffer 的 ID */
        uint32_t m_nRendererID;

        /* VertexBuffer 的 Layout */
        CBufferLayout m_Layout;
    };

    class COpenGLIndexBuffer : public CIndexBuffer
    {
    public:
        COpenGLIndexBuffer(uint32_t* pIndices, uint32_t nCount);
        virtual ~COpenGLIndexBuffer();

        /// 绑定 OpenGL IndexBuffer 对象
        virtual void Bind() const override;
        /// 取消绑定 OpenGL IndexBuffer 对象
        virtual void Unbind() const override;

        /// 获取 IndexBuffer 的顶点个数
        virtual uint32_t GetCount() const override { return m_nCount; }
    private:
        /* IndexBuffer 的 ID */
        uint32_t m_nRendererID;
        /* IndexBuffer 的 顶点个数 */
        uint32_t m_nCount;
    };
}