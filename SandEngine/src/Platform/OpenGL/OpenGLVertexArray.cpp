#include "sdpch.h"

#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace SandEngine {

    static GLenum ShaderDataTypeToOpenGLBaseType(EShaderDataType type)
    {
        switch (type)
        {
        case EShaderDataType::Float:    return GL_FLOAT;
        case EShaderDataType::Float2:   return GL_FLOAT;
        case EShaderDataType::Float3:   return GL_FLOAT;
        case EShaderDataType::Float4:   return GL_FLOAT;
        case EShaderDataType::Mat3:     return GL_FLOAT;
        case EShaderDataType::Mat4:     return GL_FLOAT;
        case EShaderDataType::Int:      return GL_INT;
        case EShaderDataType::Int2:     return GL_INT;
        case EShaderDataType::Int3:     return GL_INT;
        case EShaderDataType::Int4:     return GL_INT;
        case EShaderDataType::Bool:     return GL_BOOL;
        }

        SE_CORE_ASSERT(false, "Unknown Shader Data Type!");
        return 0;
    }

    COpenGLVertexArray::COpenGLVertexArray()
    {
        glCreateVertexArrays(1, &m_nRendererID);
    }

    COpenGLVertexArray::~COpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_nRendererID);
    }

    void COpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_nRendererID);
    }

    void COpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void COpenGLVertexArray::AddVertexBuffer(const Ref<CVertexBuffer>& pVertexBuffer)
    {
        SE_CORE_ASSERT(pVertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

        glBindVertexArray(m_nRendererID);
        pVertexBuffer->Bind();

        const auto& layout = pVertexBuffer->GetLayout();
        for (const auto& element : layout)
        {
            switch (element.m_Type)
            {
            case EShaderDataType::Float:
            case EShaderDataType::Float2:
            case EShaderDataType::Float3:
            case EShaderDataType::Float4:
            case EShaderDataType::Int:
            case EShaderDataType::Int2:
            case EShaderDataType::Int3:
            case EShaderDataType::Int4:
            case EShaderDataType::Bool:
            {
                glEnableVertexAttribArray(m_nVertexBufferIndex);
                glVertexAttribPointer(
                    m_nVertexBufferIndex, // VertexBuffer 索引
                    element.GetComponentCount(), // VertexBuffer 数据个数
                    ShaderDataTypeToOpenGLBaseType(element.m_Type), // VertexBuffer 单个数据大小
                    element.m_bNormalized ? GL_TRUE : GL_FALSE, // 是否归一化
                    layout.GetStride(), // VertexBuffer 数据步长
                    (const void*)element.m_nOffset); // VertexBuffer 的 offset
                ++m_nVertexBufferIndex;
                break;
            }
            case EShaderDataType::Mat3:
            case EShaderDataType::Mat4:
            {
                uint8_t nCount = element.GetComponentCount();
                for (uint8_t i = 0; i < nCount; ++i)
                {
                    glEnableVertexAttribArray(m_nVertexBufferIndex);
                    glVertexAttribPointer(
                        m_nVertexBufferIndex, // VertexBuffer 索引
                        nCount, // VertexBuffer 数据个数
                        ShaderDataTypeToOpenGLBaseType(element.m_Type), // VertexBuffer 单个数据大小
                        element.m_bNormalized ? GL_TRUE : GL_FALSE, // 是否归一化
                        layout.GetStride(), // VertexBuffer 数据步长
                        (const void*)(element.m_nOffset + sizeof(float) * nCount * i)); // VertexBuffer 的 offset
                }
                break;
            }
            }
        }
        glBindVertexArray(0);
    }

    void COpenGLVertexArray::SetIndexBuffer(const Ref<CIndexBuffer>& pIndexBuffer)
    {
        glBindVertexArray(m_nRendererID);
        pIndexBuffer->Bind();
        glBindVertexArray(0);

        m_pIndexBuffer = pIndexBuffer;
    }

}