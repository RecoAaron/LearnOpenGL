#include "sdpch.h"

#include "GraphicsContext.h"

#include "SandEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace SandEngine {

    Scope<CGraphicsContext> CGraphicsContext::Create(void* window)
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::ERenderAPI::None:      SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::ERenderAPI::OpenGL:    return CreateScope<COpenGLContext>(static_cast<GLFWwindow*>(window));
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}