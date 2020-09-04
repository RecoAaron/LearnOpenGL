#include "sdpch.h"

#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace SandEngine {

    COpenGLVertexBuffer::COpenGLVertexBuffer(uint32_t nSize)
    {
        SE_PROFILE_FUNCTION();

        glCreateBuffers(1, &m_nRendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_nRendererID);
        glBufferData(GL_ARRAY_BUFFER, nSize, nullptr, GL_DYNAMIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    COpenGLVertexBuffer::COpenGLVertexBuffer(float* pVertices, uint32_t nSize)
    {
        SE_PROFILE_FUNCTION();

        glCreateBuffers(1, &m_nRendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_nRendererID);
        glBufferData(GL_ARRAY_BUFFER, nSize, pVertices, GL_STATIC_DRAW);
    }

    COpenGLVertexBuffer::~COpenGLVertexBuffer()
    {
        SE_PROFILE_FUNCTION();

        glDeleteBuffers(1, &m_nRendererID);
    }

    void COpenGLVertexBuffer::Bind() const
    {
        SE_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, m_nRendererID);
    }

    void COpenGLVertexBuffer::Unbind() const
    {
        SE_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void COpenGLVertexBuffer::SetData(const void* pData, uint32_t nSize)
    {
        SE_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, m_nRendererID);
        glBufferSubData(GL_ARRAY_BUFFER, 0, nSize, pData);
    }

    COpenGLIndexBuffer::COpenGLIndexBuffer(uint32_t* pIndices, uint32_t nCount)
        : m_nCount(nCount)
    {
        SE_PROFILE_FUNCTION();

        glCreateBuffers(1, &m_nRendererID);
        // GL_ELEMENT_ARRAY_BUFFER is not valid without an actively bound VAO
        // Binding with GL_ARRAY_BUFFER allows the data to be loaded regardless of VAO state. 
        glBindBuffer(GL_ARRAY_BUFFER, m_nRendererID);
        glBufferData(GL_ARRAY_BUFFER, nCount * sizeof(uint32_t), pIndices, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    COpenGLIndexBuffer::~COpenGLIndexBuffer()
    {
        SE_PROFILE_FUNCTION();

        glDeleteBuffers(1, &m_nRendererID);
    }

    void COpenGLIndexBuffer::Bind() const
    {
        SE_PROFILE_FUNCTION();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_nRendererID);
    }

    void COpenGLIndexBuffer::Unbind() const
    {
        SE_PROFILE_FUNCTION();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}