#pragma once

namespace SandEngine {

    class CTexture
    {
    public:
        virtual ~CTexture() = default;

        /// 获取贴图的宽度
        virtual uint32_t GetWidth() const = 0;

        /// 获取贴图的高度
        virtual uint32_t GetHeight() const = 0;

        /// 获取贴图的 ID
        virtual uint32_t GetRendererID() const = 0;

        /// 设置贴图的数据
        virtual void SetData(void* pData, uint32_t nSize) = 0;

        /// 绑定该贴图
        virtual void Bind(uint32_t nSlot = 0) const = 0;

        /// 重写 == 比较运算符
        virtual bool operator==(const CTexture& other) const = 0;
    };

    class CTexture2D : public CTexture
    {
    public:
        /// 创建一张 2D 贴图
        static Ref<CTexture2D> Create(uint32_t nWidth, uint32_t nHeight);

        /// 创建一张 2D 贴图
        static Ref<CTexture2D> Create(const std::string& strPath);
    };
}