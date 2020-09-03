#include "sdpch.h"
#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace SandEngine {

    CRendererAPI::ERenderAPI CRendererAPI::s_API = CRendererAPI::ERenderAPI::OpenGL;

    Scope<CRendererAPI> CRendererAPI::Create()
    {
        switch (s_API)
        {
        case CRendererAPI::ERenderAPI::None:      SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::ERenderAPI::OpenGL:    return CreateScope<COpenGLRendererAPI>();
        }
        SE_CORE_ASSERT(false, "Unknown Renderer API!");
        return nullptr;
    }

}