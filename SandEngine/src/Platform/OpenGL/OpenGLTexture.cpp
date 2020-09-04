#include "sdpch.h"

#include "OpenGLTexture.h"

#include <stb_image.h>

namespace SandEngine {


    COpenGLTexture2D::COpenGLTexture2D(uint32_t nWidth, uint32_t nHeight)
        : m_nWidth(nWidth), m_nHeight(nHeight)
    {
        SE_PROFILE_FUNCTION();

        m_nInternalFormat = GL_RGBA8;
        m_nDataFormat = GL_RGBA;

        glCreateTextures(GL_TEXTURE_2D, 1, &m_nRendererID);
        glTextureStorage2D(m_nRendererID, 1, m_nInternalFormat, m_nWidth, m_nHeight);

        glTextureParameteri(m_nRendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_nRendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTextureParameteri(m_nRendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(m_nRendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    COpenGLTexture2D::COpenGLTexture2D(const std::string& strPath)
        : m_strPath(strPath)
    {
        SE_PROFILE_FUNCTION();

        // Use stb_image load texture
        int nWidth, nHeight, nChannels;
        stbi_set_flip_vertically_on_load(1);

        stbi_uc* pData = nullptr;
        {
            pData = stbi_load(strPath.c_str(), &nWidth, &nHeight, &nChannels, 0);
        }
        SE_CORE_ASSERT(pData, "Failed to load image!");
        m_nWidth = nWidth;
        m_nHeight = nHeight;

        GLenum nInternalFormat = 0, nDataFormat = 0;
        if (nChannels == 4)
        {
            nInternalFormat = GL_RGBA8;
            nDataFormat = GL_RGBA;
        }
        else if (nChannels == 3)
        {
            nInternalFormat = GL_RGB8;
            nDataFormat = GL_RGB;
        }

        m_nInternalFormat = nInternalFormat;
        m_nDataFormat = nDataFormat;

        SE_CORE_ASSERT(nInternalFormat & nDataFormat, "Format not supported!");

        glCreateTextures(GL_TEXTURE_2D, 1, &m_nRendererID);
        glTextureStorage2D(m_nRendererID, 1, m_nInternalFormat, m_nWidth, m_nHeight);

        glTextureParameteri(m_nRendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_nRendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTextureParameteri(m_nRendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(m_nRendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTextureSubImage2D(m_nRendererID, 0, 0, 0, m_nWidth, m_nHeight, m_nDataFormat, GL_UNSIGNED_BYTE, pData);

        stbi_image_free(pData);
    }

    COpenGLTexture2D::~COpenGLTexture2D()
    {
        SE_PROFILE_FUNCTION();

        glDeleteTextures(1, &m_nRendererID);
    }

    void COpenGLTexture2D::SetData(void* pData, uint32_t nSize)
    {
        SE_PROFILE_FUNCTION();

        uint32_t bpp = m_nDataFormat == GL_RGBA ? 4 : 3;
        SE_CORE_ASSERT(nSize == m_nWidth * m_nHeight * bpp, "Data must be entire texture!");
        glTextureSubImage2D(m_nRendererID, 0, 0, 0, m_nWidth, m_nHeight, m_nDataFormat, GL_UNSIGNED_BYTE, pData);
    }

    void COpenGLTexture2D::Bind(uint32_t nSlot /*= 0*/) const
    {
        SE_PROFILE_FUNCTION();

        glBindTextureUnit(nSlot, m_nRendererID);
    }

}