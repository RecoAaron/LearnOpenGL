#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: OpenGL ʵ����ɫ������
*************************************************/
#include "SandEngine/Renderer/Shader.h"

namespace SandEngine {

    class COpenGLShader : public CShader
    {
    public:
        COpenGLShader(const std::string& strFilepath);
        COpenGLShader(const std::string& strName, const std::string& strVertexSrc, const std::string& strFragmentSrc);
        virtual ~COpenGLShader();

        /// ����ɫ��
        virtual void Bind() const override;
        /// ȡ������ɫ��
        virtual void Unbind() const override;

        /// ���� int ���͵� uniform
        virtual void SetInt(const std::string& strName, int nValue) override;
        void UploadUniformInt(const std::string& strName, int nValue);

        /// ���� int array ���͵� uniform
        virtual void SetIntArray(const std::string& strName, int* pValues, uint32_t nCount) override;
        void UploadUniformIntArray(const std::string& strName, int* pValues, uint32_t nCount);

        /// ���� float ���͵� uniform
        virtual void SetFloat(const std::string& strName, float nValue) override;
        void UploadUniformFloat(const std::string& strName, float nValue);

        /// ���� float2 ���͵� uniform
        virtual void SetFloat2(const std::string& strName, const glm::vec2& vec2Value) override;
        void UploadUniformFloat2(const std::string& strName, const glm::vec2& vec2Value);

        /// ���� float3 ���͵� uniform
        virtual void SetFloat3(const std::string& strName, const glm::vec3& vec3Value) override;
        void UploadUniformFloat3(const std::string& strName, const glm::vec3& vec3Value);

        /// ���� float4 ���͵� uniform
        virtual void SetFloat4(const std::string& strName, const glm::vec4& vec4Value) override;
        void UploadUniformFloat4(const std::string& strName, const glm::vec4& vec4Value);

        /// ���� Mat3 ���͵� uniform
        virtual void SetMat3(const std::string& strName, const glm::mat3& mat3Value) override;
        void UploadUniformMat3(const std::string& strName, const glm::mat3& mat3Value);

        /// ���� Mat4 ���͵� uniform
        virtual void SetMat4(const std::string& strName, const glm::mat4& mat4Value) override;
        void UploadUniformMat4(const std::string& strName, const glm::mat4& mat4Value);

        /// ��ȡ��ɫ��������
        virtual const std::string& GetName() const override;

    private:
        /// ��ȡ shader �ļ�
        std::string ReadFile(const std::string& strFilepath);

        /// ��ɫ��Ԥ����
        std::unordered_map<unsigned int, std::string> PreProcess(const std::string& strSource);

        /// ������ɫ��
        void Compile(const std::unordered_map<unsigned int, std::string>& shaderSources);

        /* ��ɫ��ID */
        uint32_t m_nRendererID;
        /* ��ɫ������ */
        std::string m_strName;
    };
}