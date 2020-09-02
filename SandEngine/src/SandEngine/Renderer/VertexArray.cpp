#include "sdpch.h"

#include "VertexArray.h"

#include "SandEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace SandEngine {

    SandEngine::Ref<SandEngine::CVertexArray> CVertexArray::Create()
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::EAPI::None:    SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::EAPI::OpenGL:  return CreateRef<COpenGLVertexArray>();
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}