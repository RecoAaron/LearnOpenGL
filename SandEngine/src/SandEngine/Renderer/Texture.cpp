#include "sdpch.h"

#include "Texture.h"

#include "SandEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace SandEngine {

    Ref<CTexture2D> CTexture2D::Create(uint32_t nWidth, uint32_t nHeight)
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::ERenderAPI::None:    SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::ERenderAPI::OpenGL:  return CreateRef<COpenGLTexture2D>(nWidth, nHeight);
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<CTexture2D> CTexture2D::Create(const std::string& strPath)
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::ERenderAPI::None:    SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::ERenderAPI::OpenGL:  return CreateRef<COpenGLTexture2D>(strPath);
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}