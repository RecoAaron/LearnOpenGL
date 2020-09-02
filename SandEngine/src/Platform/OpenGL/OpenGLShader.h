#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: OpenGL 实现着色器对象
*************************************************/
#include "SandEngine/Renderer/Shader.h"

namespace SandEngine {

    class COpenGLShader : public CShader
    {
    public:
        COpenGLShader(const std::string& strFilepath);
        COpenGLShader(const std::string& strName, const std::string& strVertexSrc, const std::string& strFragmentSrc);
        virtual ~COpenGLShader();

        /// 绑定着色器
        virtual void Bind() const override;
        /// 取消绑定着色器
        virtual void Unbind() const override;

        /// 设置 int 类型的 uniform
        virtual void SetInt(const std::string& strName, int nValue) override;
        void UploadUniformInt(const std::string& strName, int nValue);

        /// 设置 int array 类型的 uniform
        virtual void SetIntArray(const std::string& strName, int* pValues, uint32_t nCount) override;
        void UploadUniformIntArray(const std::string& strName, int* pValues, uint32_t nCount);

        /// 设置 float 类型的 uniform
        virtual void SetFloat(const std::string& strName, float nValue) override;
        void UploadUniformFloat(const std::string& strName, float nValue);

        /// 设置 float2 类型的 uniform
        virtual void SetFloat2(const std::string& strName, const glm::vec2& vec2Value) override;
        void UploadUniformFloat2(const std::string& strName, const glm::vec2& vec2Value);

        /// 设置 float3 类型的 uniform
        virtual void SetFloat3(const std::string& strName, const glm::vec3& vec3Value) override;
        void UploadUniformFloat3(const std::string& strName, const glm::vec3& vec3Value);

        /// 设置 float4 类型的 uniform
        virtual void SetFloat4(const std::string& strName, const glm::vec4& vec4Value) override;
        void UploadUniformFloat4(const std::string& strName, const glm::vec4& vec4Value);

        /// 设置 Mat3 类型的 uniform
        virtual void SetMat3(const std::string& strName, const glm::mat3& mat3Value) override;
        void UploadUniformMat3(const std::string& strName, const glm::mat3& mat3Value);

        /// 设置 Mat4 类型的 uniform
        virtual void SetMat4(const std::string& strName, const glm::mat4& mat4Value) override;
        void UploadUniformMat4(const std::string& strName, const glm::mat4& mat4Value);

        /// 获取着色器的名称
        virtual const std::string& GetName() const override;

    private:
        /// 读取 shader 文件
        std::string ReadFile(const std::string& strFilepath);

        /// 着色器预处理
        std::unordered_map<unsigned int, std::string> PreProcess(const std::string& strSource);

        /// 编译着色器
        void Compile(const std::unordered_map<unsigned int, std::string>& shaderSources);

        /* 着色器ID */
        uint32_t m_nRendererID;
        /* 着色器名称 */
        std::string m_strName;
    };
}