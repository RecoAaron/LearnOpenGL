#include "sdpch.h"

#include "Shader.h"

#include "SandEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace SandEngine {

    SandEngine::Ref<SandEngine::CShader> CShader::Create(const std::string& strFilepath)
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::ERenderAPI::None:      SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::ERenderAPI::OpenGL:    return CreateRef<COpenGLShader>(strFilepath);
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    SandEngine::Ref<SandEngine::CShader> CShader::Create(const std::string& strName, const std::string& strVertexSrc, const std::string& strFragmentSrc)
    {
        switch (CRenderer::GetAPI())
        {
        case CRendererAPI::ERenderAPI::None:      SE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case CRendererAPI::ERenderAPI::OpenGL:    return CreateRef<COpenGLShader>(strName, strVertexSrc, strFragmentSrc);
        }

        SE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    void CShaderLibrary::AddShader(const std::string& strName, const Ref<CShader>& pShader)
    {
        SE_CORE_ASSERT(!ExistsShader(strName), "Shader already exists!");
        m_vecShaders[strName] = pShader;
    }

    void CShaderLibrary::AddShader(const Ref<CShader>& pShader)
    {
        auto& strName = pShader->GetName();
        AddShader(strName, pShader);
    }

    Ref<CShader> CShaderLibrary::LoadShader(const std::string& strFilepath)
    {
        auto pShader = CShader::Create(strFilepath);
        AddShader(pShader);
        return pShader;
    }

    Ref<CShader> CShaderLibrary::LoadShader(const std::string& strName, const std::string& strFilepath)
    {
        auto pShader = CShader::Create(strFilepath);
        AddShader(strName, pShader);
        return pShader;
    }

    Ref<CShader> CShaderLibrary::GetShader(const std::string& strName)
    {
        SE_CORE_ASSERT(ExistsShader(strName), "Shader not found!");
        return m_vecShaders[strName];
    }

    bool CShaderLibrary::ExistsShader(const std::string& strName) const
    {
        return m_vecShaders.find(strName) != m_vecShaders.end();
    }
}