#include "sdpch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace SandEngine {

    COpenGLContext::COpenGLContext(GLFWwindow* pWindowHandle)
        : m_pWindowHandle(pWindowHandle)
    {
        SE_CORE_ASSERT(pWindowHandle, "Window Handle is null!");
    }

    void COpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_pWindowHandle);
        int nStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        SE_CORE_ASSERT(nStatus, "Failed to initialize Glad!");

        SE_LOG_INFO_CORE("OpenGL Init Info:");
        SE_LOG_INFO_CORE("    Vendor  : {0}", glGetString(GL_VENDOR));
        SE_LOG_INFO_CORE("    Renderer: {0}", glGetString(GL_RENDERER));
        SE_LOG_INFO_CORE("    Version : {0}", glGetString(GL_VERSION));

        SE_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Sand Engine requires at least OpenGL version 4.5!");
    }

    void COpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_pWindowHandle);
    }
}