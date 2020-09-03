#pragma once

#include "SandEngine/Renderer/Texture.h"

#include <glad/glad.h>

namespace SandEngine {

    class COpenGLTexture2D : public CTexture2D
    {
    public:
        COpenGLTexture2D(uint32_t nWidth, uint32_t nHeight);
        COpenGLTexture2D(const std::string& strPath);
        virtual ~COpenGLTexture2D();

        /// 获取贴图的宽度
        virtual uint32_t GetWidth() const override { return m_nWidth; }

        /// 获取贴图的高度
        virtual uint32_t GetHeight() const override { return m_nHeight; }

        /// 获取贴图的 ID
        virtual uint32_t GetRendererID() const override { return m_nRendererID; }

        /// 设置贴图的数据
        virtual void SetData(void* pData, uint32_t nSize) override;

        /// 绑定该贴图
        virtual void Bind(uint32_t nSlot = 0) const override;

        /// 重写 == 比较运算符
        virtual bool operator==(const CTexture& other) const override
        {
            return m_nRendererID == ((COpenGLTexture2D&)other).m_nRendererID;
        }
    private:
        /* 贴图文件路径 */
        std::string m_strPath;

        /* 贴图的宽度和高度 */
        uint32_t m_nWidth, m_nHeight;

        /* 贴图的 ID */
        uint32_t m_nRendererID;

        /* 贴图的内置格式和数据格式 */
        GLenum m_nInternalFormat, m_nDataFormat;
    };
}