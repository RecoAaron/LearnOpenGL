#include "sdpch.h"

#include "OpenGLShader.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace  SandEngine {

    static GLenum ShaderTypeFromString(const std::string& strType)
    {
        if (strType == "vertex")
            return GL_VERTEX_SHADER;
        if (strType == "fragment" || strType == "pixel")
            return GL_FRAGMENT_SHADER;

        SE_CORE_ASSERT(false, "Unknown shader type!");
        return 0;
    }

    COpenGLShader::COpenGLShader(const std::string& strFilepath)
    {
        std::string strSource = this->ReadFile(strFilepath);
        auto shaderSources = this->PreProcess(strSource);
        this->Compile(shaderSources);

        // Extract name from filepath
        auto lastSlash = strFilepath.find_last_of("/\\");
        lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
        auto lastDot = strFilepath.rfind('.');
        auto count = lastDot == std::string::npos ? strFilepath.size() - lastSlash : lastDot - lastSlash;
        m_strName = strFilepath.substr(lastSlash, count);
    }

    COpenGLShader::COpenGLShader(const std::string& strName, const std::string& strVertexSrc, const std::string& strFragmentSrc)
        : m_strName(strName)
    {
        std::unordered_map<GLenum, std::string> sources;
        sources[GL_VERTEX_SHADER] = strVertexSrc;
        sources[GL_FRAGMENT_SHADER] = strFragmentSrc;
        this->Compile(sources);
    }

    COpenGLShader::~COpenGLShader()
    {
        glDeleteProgram(m_nRendererID);
    }

    void COpenGLShader::Bind() const
    {
        glUseProgram(m_nRendererID);
    }

    void COpenGLShader::Unbind() const
    {
        glUseProgram(0);
    }

    void COpenGLShader::SetInt(const std::string& strName, int nValue)
    {
        UploadUniformInt(strName, nValue);
    }

    void COpenGLShader::UploadUniformInt(const std::string& strName, int nValue)
    {
        GLint location = glGetUniformLocation(m_nRendererID, strName.c_str());
        glUniform1i(location, nValue);
    }

    void COpenGLShader::SetIntArray(const std::string& strName, int* pValues, uint32_t nCount)
    {
        UploadUniformIntArray(strName, pValues, nCount);
    }

    void COpenGLShader::UploadUniformIntArray(const std::string& strName, int* pValues, uint32_t nCount)
    {
        GLint location = glGetUniformLocation(m_nRendererID, strName.c_str());
        glUniform1iv(location, nCount, pValues);
    }

    void COpenGLShader::SetFloat(const std::string& strName, float nValue)
    {
        UploadUniformFloat(strName, nValue);
    }

    void COpenGLShader::UploadUniformFloat(const std::string& strName, float nValue)
    {
        GLint location = glGetUniformLocation(m_nRendererID, strName.c_str());
        glUniform1f(location, nValue);
    }

    void COpenGLShader::SetFloat2(const std::string& strName, const glm::vec2& vec2Value)
    {
        UploadUniformFloat2(strName, vec2Value);
    }

    void COpenGLShader::UploadUniformFloat2(const std::string& strName, const glm::vec2& vec2Value)
    {
        GLint location = glGetUniformLocation(m_nRendererID, strName.c_str());
        glUniform2f(location, vec2Value.x, vec2Value.y);
    }

    void COpenGLShader::SetFloat3(const std::string& strName, const glm::vec3& vec3Value)
    {
        UploadUniformFloat3(strName, vec3Value);
    }

    void COpenGLShader::UploadUniformFloat3(const std::string& strName, const glm::vec3& vec3Value)
    {
        GLint location = glGetUniformLocation(m_nRendererID, strName.c_str());
        glUniform3f(location, vec3Value.x, vec3Value.y, vec3Value.z);
    }

    void COpenGLShader::SetFloat4(const std::string& strName, const glm::vec4& vec4Value)
    {
        UploadUniformFloat4(strName, vec4Value);
    }

    void COpenGLShader::UploadUniformFloat4(const std::string& strName, const glm::vec4& vec4Value)
    {
        GLint location = glGetUniformLocation(m_nRendererID, strName.c_str());
        glUniform4f(location, vec4Value.x, vec4Value.y, vec4Value.z, vec4Value.w);
    }

    void COpenGLShader::SetMat3(const std::string& strName, const glm::mat3& mat3Value)
    {
        UploadUniformMat3(strName, mat3Value);
    }

    void COpenGLShader::UploadUniformMat3(const std::string& strName, const glm::mat3& mat3Value)
    {
		GLint location = glGetUniformLocation(m_nRendererID, strName.c_str());
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(mat3Value));
    }

    void COpenGLShader::SetMat4(const std::string& strName, const glm::mat4& mat4Value)
    {
        UploadUniformMat4(strName, mat4Value);
    }

    void COpenGLShader::UploadUniformMat4(const std::string& strName, const glm::mat4& mat4Value)
    {
		GLint location = glGetUniformLocation(m_nRendererID, strName.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat4Value));
    }

    const std::string& COpenGLShader::GetName() const
    {
        return m_strName;
    }

    std::string COpenGLShader::ReadFile(const std::string& strFilepath)
    {
        std::string strResult;
        std::ifstream in(strFilepath, std::ios::in | std::ios::binary); // ifstream closes itself due to RAII
        if (in)
        {
            in.seekg(0, std::ios::end);
            size_t nSize = in.tellg();
            if (nSize != -1)
            {
                strResult.resize(nSize);
                in.seekg(0, std::ios::beg);
                in.read(&strResult[0], nSize);
            }
            else
            {
                SE_LOG_ERROR_CORE("Could not read from file '{0}'!", strFilepath);
            }
        }
        else
        {
            SE_LOG_ERROR_CORE("Could not open file '{0}'!", strFilepath);
        }
        return strResult;
    }

    std::unordered_map<unsigned int, std::string> COpenGLShader::PreProcess(const std::string& strSource)
    {
        std::unordered_map<GLenum, std::string> shaderSources;

        const char* typeToken = "#type";
        size_t typeTokenLength = strlen(typeToken);
        size_t pos = strSource.find(typeToken, 0); // Start of shader type declaration line
        while (pos != std::string::npos)
        {
            size_t eol = strSource.find_first_of("\r\n", pos); // End of shader type declaration line
            SE_CORE_ASSERT(eol != std::string::npos, "Syntax error");
            size_t begin = pos + typeTokenLength + 1; // Start of shader type name (after "#type " keyword)
            std::string type = strSource.substr(begin, eol - begin);
            SE_CORE_ASSERT(ShaderTypeFromString(type), "Invalid shader type specified");

            size_t nextLinePos = strSource.find_first_not_of("\r\n", eol);// Start of shader code after shader type declaration line
            SE_CORE_ASSERT(nextLinePos != std::string::npos, "Syntax error");
            pos = strSource.find(typeToken, nextLinePos); // Start of next shader type declaration line

            shaderSources[ShaderTypeFromString(type)] = (pos == std::string::npos) ? strSource.substr(nextLinePos) : strSource.substr(nextLinePos, pos - nextLinePos);
        }
        return shaderSources;
    }

    void COpenGLShader::Compile(const std::unordered_map<unsigned int, std::string>& shaderSources)
    {
        GLuint program = glCreateProgram();
        SE_CORE_ASSERT(shaderSources.size() <= 2, "We only support 2 shaders for now");
        std::array<GLenum, 2> glShaderIDs;
        int glShaderIDIndex = 0;
        for (auto& kv : shaderSources)
        {
            GLenum type = kv.first;
            const std::string& source = kv.second;

            GLuint shader = glCreateShader(type);

            const GLchar* sourceCStr = source.c_str();
            glShaderSource(shader, 1, &sourceCStr, 0);

            glCompileShader(shader);

            GLint isCompiled = 0;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
            if (isCompiled == GL_FALSE)
            {
                GLint maxLength = 0;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

                std::vector<GLchar> infoLog(maxLength);
                glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

                glDeleteShader(shader);

                SE_LOG_ERROR_CORE("{0}", infoLog.data());
                SE_CORE_ASSERT(false, "Shader compilation failure!");
                break;
            }
            glAttachShader(program, shader);
            glShaderIDs[glShaderIDIndex++] = shader;
        }
        m_nRendererID = program;

        // Link program
        glLinkProgram(program);

        // Note the different functions here: glGetProgram* instead of glGetShader*.
        GLint isLinked = 0;
        glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

            // We don't need the program anymore.
            glDeleteProgram(program);

            for (auto id : glShaderIDs)
                glDeleteShader(id);

            SE_LOG_ERROR_CORE("{0}", infoLog.data());
            SE_CORE_ASSERT(false, "Shader link failure!");
            return;
        }

        for (auto id : glShaderIDs)
        {
            glDetachShader(program, id);
            glDeleteShader(id);
        }
    }
}