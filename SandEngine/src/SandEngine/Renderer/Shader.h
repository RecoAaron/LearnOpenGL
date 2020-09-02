#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: 着色器抽象对象
*************************************************/
#include <string>
#include <unordered_map>

#include <glm/glm.hpp>

namespace SandEngine {

    class CShader
    {
    public:
        ~CShader() = default;

        /// 绑定着色器
        virtual void Bind() const = 0;
        /// 取消绑定着色器
        virtual void Unbind() const = 0;

        /// 设置 int 类型的 uniform
        virtual void SetInt(const std::string& strName, int nValue) = 0;
        /// 设置 int array 类型的 uniform
        virtual void SetIntArray(const std::string& strName, int* pValues, uint32_t nCount) = 0;
        /// 设置 float 类型的 uniform
        virtual void SetFloat(const std::string& strName, float nValue) = 0;
        /// 设置 float2 类型的 uniform
        virtual void SetFloat2(const std::string& strName, const glm::vec2& vec2Value) = 0;
        /// 设置 float3 类型的 uniform
        virtual void SetFloat3(const std::string& strName, const glm::vec3& vec3Value) = 0;
        /// 设置 float4 类型的 uniform
        virtual void SetFloat4(const std::string& strName, const glm::vec4& vec4Value) = 0;
        /// 设置 Mat3 类型的 uniform
        virtual void SetMat3(const std::string& strName, const glm::mat3& mat3Value) = 0;
        /// 设置 Mat4 类型的 uniform
        virtual void SetMat4(const std::string& strName, const glm::mat4& mat4Value) = 0;

        /// 获取着色器的名称
        virtual const std::string& GetName() const = 0;

        /// 创建着色器，单个文件包含所有类型
        static Ref<CShader> Create(const std::string& strFilepath);
        /// 创建着色器，顶点着色器文件和片段着色器文件
        static Ref<CShader> Create(const std::string& strName, const std::string& strVertexSrc, const std::string& strFragmentSrc);
    };
}