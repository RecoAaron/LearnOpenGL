#include "sdpch.h"

#include "Shader.h"

#include "SandEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace SandEngine {

    SandEngine::Ref<SandEngine::CShader> CShader::Create(const std::string& strFilepath)
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::EAPI::None:      SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::EAPI::OpenGL:    return CreateRef<COpenGLShader>(strFilepath);
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    SandEngine::Ref<SandEngine::CShader> CShader::Create(const std::string& strName, const std::string& strVertexSrc, const std::string& strFragmentSrc)
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::EAPI::None:      SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::EAPI::OpenGL:    return CreateRef<COpenGLShader>(strName, strVertexSrc, strFragmentSrc);
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}