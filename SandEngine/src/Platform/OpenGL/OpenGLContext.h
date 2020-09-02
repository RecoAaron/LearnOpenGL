#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: OpenGL 实现图形渲染上下文
*************************************************/
#include "SandEngine/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace SandEngine {

    class COpenGLContext : public CGraphicsContext
    {
    public:
        COpenGLContext(GLFWwindow* pWindowHandle);

        /// 初始化 OpenGL
        virtual void Init() override;

        /// 交换缓冲区
        virtual void SwapBuffers() override;

    private:
        /* OpenGL 的窗口对象 */
        GLFWwindow* m_pWindowHandle;
    };
}