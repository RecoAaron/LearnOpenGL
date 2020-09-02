#include "sdpch.h"
#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace SandEngine {

    CRendererAPI::EAPI CRendererAPI::s_API = CRendererAPI::EAPI::OpenGL;

    Scope<CRendererAPI> CRendererAPI::Create()
    {
        switch (s_API)
        {
        case CRendererAPI::EAPI::None:      SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::EAPI::OpenGL:    return CreateScope<COpenGLRendererAPI>();
        }
        SE_CORE_ASSERT(false, "Unknown Renderer API!");
        return nullptr;
    }

}