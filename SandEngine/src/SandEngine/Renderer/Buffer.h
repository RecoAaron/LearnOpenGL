#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-01
 * Description: 图形渲染缓冲区抽象类
*************************************************/

namespace SandEngine {

    enum class EShaderDataType
    {
        /* 数据类型，决定缓冲区数据大小 */
        None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
    };

    /// 获取数据类型大小
    static uint32_t ShaderDataTypeSize(EShaderDataType type)
    {
        switch (type)
        {
        case EShaderDataType::Float:    return 4;           // float    4  字节
        case EShaderDataType::Float2:   return 4 * 2;       // float2   8  字节
        case EShaderDataType::Float3:   return 4 * 3;       // float3   12 字节
        case EShaderDataType::Float4:   return 4 * 4;       // float4   16 字节
        case EShaderDataType::Mat3:     return 4 * 3 * 3;   // mat3     36 字节
        case EShaderDataType::Mat4:     return 4 * 4 * 4;   // mat4     64 字节
        case EShaderDataType::Int:      return 4;           // int      4  字节
        case EShaderDataType::Int2:     return 4 * 2;       // int2     8  字节
        case EShaderDataType::Int3:     return 4 * 3;       // int3     12 字节
        case EShaderDataType::Int4:     return 4 * 4;       // int4     16 字节
        case EShaderDataType::Bool:     return 1;           // bool     1  字节
        }

        SE_CORE_ASSERT(false, "Unknown Shader Data Type!");
        return 0;
    }

    struct SBufferElement
    {
        /* 缓冲区名字 */
        std::string m_strName;

        /* 缓冲区数据类型 */
        EShaderDataType m_Type;

        /* 缓冲区数据大小 */
        uint32_t m_nSize;

        /* 缓冲区 offset */
        size_t m_nOffset;

        /* 是否归一化 */
        bool m_bNormalized;

        SBufferElement() = default;

        SBufferElement(EShaderDataType type, const std::string& strName, bool bNormalized = false)
            : m_strName(strName), m_Type(type), m_nSize(ShaderDataTypeSize(type)), m_nOffset(0), m_bNormalized(bNormalized)
        {

        }

        /// 缓冲区数据个数
        uint32_t GetComponentCount() const
        {
            switch (m_Type)
            {
            case EShaderDataType::Float:   return 1;
            case EShaderDataType::Float2:  return 2;
            case EShaderDataType::Float3:  return 3;
            case EShaderDataType::Float4:  return 4;
            case EShaderDataType::Mat3:    return 3; // 3* float3
            case EShaderDataType::Mat4:    return 4; // 4* float4
            case EShaderDataType::Int:     return 1;
            case EShaderDataType::Int2:    return 2;
            case EShaderDataType::Int3:    return 3;
            case EShaderDataType::Int4:    return 4;
            case EShaderDataType::Bool:    return 1;
            }

            SE_CORE_ASSERT(false, "Unknown Shader Data Type!");
            return 0;
        }
    };

    class CBufferLayout
    {
    public:
        CBufferLayout() {}
        virtual ~CBufferLayout() = default;

        CBufferLayout(const std::initializer_list<SBufferElement>& vecElements)
            : m_vecElements(vecElements)
        {
            CalculateOffsetsAndStride();
        }

        /// 获取缓冲区步长
        uint32_t GetStride() const { return m_nStride; }

        /// 获取缓冲区数据容器
        const std::vector<SBufferElement>& GetElements() const { return m_vecElements; }

        /// 获取迭代器开始对象
        std::vector<SBufferElement>::iterator begin() { return m_vecElements.begin(); }
        /// 获取迭代器结束对象
        std::vector<SBufferElement>::iterator end() { return m_vecElements.end(); }
        /// 获取常量迭代器开始对象
        std::vector<SBufferElement>::const_iterator begin() const { return m_vecElements.begin(); }
        /// 获取常量迭代器结束对象
        std::vector<SBufferElement>::const_iterator end() const { return m_vecElements.end(); }
    private:
        /// 计算缓冲区 offset 和步长
        void CalculateOffsetsAndStride()
        {
            size_t nOffset = 0;
            m_nStride = 0;
            for (auto& element : m_vecElements)
            {
                element.m_nOffset = nOffset;
                nOffset += element.m_nSize;
                m_nStride += element.m_nSize;
            }
        }
    private:
        /* 缓冲区数据容器 */
        std::vector<SBufferElement> m_vecElements;

        /* 缓冲区步长 */
        uint32_t m_nStride = 0;
    };

    class CVertexBuffer
    {
    public:
        virtual ~CVertexBuffer() = default;

        /// 绑定 VertexBuffer
        virtual void Bind() const = 0;
        /// 取消绑定 VertexBuffer
        virtual void Unbind() const = 0;

        /// 设置 VertexBuffer 的数据
        virtual void SetData(const void* pData, uint32_t nSize) = 0;

        /// 获取 VertexBuffer 的 Layout
        virtual const CBufferLayout& GetLayout() const = 0;
        /// 设置 VertexBuffer 的 Layout
        virtual void SetLayout(const CBufferLayout& layout) = 0;

        /// 创建 VertexBuffer 对象
        static Ref<CVertexBuffer> Create(uint32_t nSize);
        /// 创建 VertexBuffer 对象
        static Ref<CVertexBuffer> Create(float* pVertices, uint32_t nSize);
    };

    // Currently only supports 32-bit index buffers
    class CIndexBuffer
    {
    public:
        virtual ~CIndexBuffer() = default;

        /// 绑定 IndexBuffer
        virtual void Bind() const = 0;
        /// 取消绑定 IndexBuffer
        virtual void Unbind() const = 0;

        /// 获取 IndexBuffer 的顶点个数
        virtual uint32_t GetCount() const = 0;

        /// 创建 IndexBuffer 对象
        static Ref<CIndexBuffer> Create(uint32_t* pIndices, uint32_t nCount);
    };
}