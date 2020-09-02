#include "sdpch.h"

#include "Buffer.h"

#include "SandEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace SandEngine {

    Ref<CVertexBuffer> CVertexBuffer::Create(uint32_t nSize)
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::EAPI::None:    SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::EAPI::OpenGL:  return CreateRef<COpenGLVertexBuffer>(nSize);
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<CVertexBuffer> CVertexBuffer::Create(float* pVertices, uint32_t nSize)
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::EAPI::None:    SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::EAPI::OpenGL:  return CreateRef<COpenGLVertexBuffer>(pVertices, nSize);
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<CIndexBuffer> CIndexBuffer::Create(uint32_t* pIndices, uint32_t nCount)
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::EAPI::None:    SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::EAPI::OpenGL:  return CreateRef<COpenGLIndexBuffer>(pIndices, nCount);
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}