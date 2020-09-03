#include "sdpch.h"

#include "WindowsWindow.h"

#include "SandEngine/Events/ApplicationEvent.h"
#include "SandEngine/Events/KeyEvent.h"
#include "SandEngine/Events/MouseEvent.h"
#include "SandEngine/Renderer/Renderer.h"

#include <glad/glad.h>

namespace SandEngine {

    static uint8_t s_nGLFWWindowCount = 0;

    static void GLFWErrorCallback(int nError, const char* strDescription)
    {
        SE_LOG_ERROR_CORE("GLFW Error [{0}]: {1}", nError, strDescription);
    }

    CWindowsWindow::CWindowsWindow(const SWindowProps& props)
    {
        Init(props);
    }

    CWindowsWindow::~CWindowsWindow()
    {
        Shutdown();
    }

    void CWindowsWindow::Init(const SWindowProps& props)
    {
        m_Data.m_strTitle = props.m_strTitle;
        m_Data.m_nWidth = props.m_nWidth;
        m_Data.m_nHeight = props.m_nHeight;

        SE_LOG_INFO_CORE("Creating window {0}({1}, {2})", props.m_strTitle, props.m_nWidth, props.m_nHeight);

        if (s_nGLFWWindowCount == 0)
        {
            int nSuccess = glfwInit();
            SE_CORE_ASSERT(nSuccess, "Counld not initialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);
        }

        { // init renderer and glfw
        #if defined(SE_DEBUG)
            if (CRenderer::GetAPI() == CRendererAPI::ERenderAPI::OpenGL)
                glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
        #endif
            m_pWindow = glfwCreateWindow((int)props.m_nWidth, (int)props.m_nHeight, m_Data.m_strTitle.c_str(), nullptr, nullptr);
            ++s_nGLFWWindowCount;
        }

        m_pContext = CGraphicsContext::Create(m_pWindow);
        m_pContext->Init();

        glfwSetWindowUserPointer(m_pWindow, &m_Data);
        SetVSync(true);

        // 绑定 GLFW 回调函数处理事件
        /* Window Resize Event */
        glfwSetWindowSizeCallback(m_pWindow, [](GLFWwindow* pWindow, int nWidth, int nHeight)
            {
                SWindowData& data = *(SWindowData*)glfwGetWindowUserPointer(pWindow);
                data.m_nWidth = nWidth;
                data.m_nHeight = nHeight;

                data.EventCallback(CWindowResizedEvent(nWidth, nHeight));
            });
        /* Window Close Event */
        glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* pWindow)
            {
                SWindowData& data = *(SWindowData*)glfwGetWindowUserPointer(pWindow);

                data.EventCallback(CWindowCloseEvent());
            });
        /* Key Pressed Event, Key Released Event */
        glfwSetKeyCallback(m_pWindow, [](GLFWwindow* pWindow, int nKey, int nScancode, int nAction, int nMods)
            {
                SWindowData& data = *(SWindowData*)glfwGetWindowUserPointer(pWindow);

                switch (nAction)
                {
                case GLFW_PRESS:
                {
                    data.EventCallback(CKeyPressedEvent(nKey, 0));
                }
                break;
                case GLFW_RELEASE:
                {
                    data.EventCallback(CKeyReleasedEvent(nKey));
                }
                break;
                case GLFW_REPEAT:
                {
                    data.EventCallback(CKeyPressedEvent(nKey, 1));
                }
                break;
                }
            });
        /* Key Typed Event */
        glfwSetCharCallback(m_pWindow, [](GLFWwindow* pWindow, unsigned int nKeycode)
            {
                SWindowData& data = *(SWindowData*)glfwGetWindowUserPointer(pWindow);

                data.EventCallback(CKeyTypedEvent(nKeycode));
            });
        /* Mouse Pressed Event, Mouse Released Event */
        glfwSetMouseButtonCallback(m_pWindow, [](GLFWwindow* pWindow, int nButton, int nAction, int nMods)
            {
                SWindowData& data = *(SWindowData*)glfwGetWindowUserPointer(pWindow);

                switch (nAction)
                {
                case GLFW_PRESS:
                {
                    data.EventCallback(CMouseButtonPressedEvent(nButton));
                    break;
                }
                case GLFW_RELEASE:
                {
                    data.EventCallback(CMouseButtonReleasedEvent(nButton));
                    break;
                }
                }
            });
        /* Mouse Scrolled Event */
        glfwSetScrollCallback(m_pWindow, [](GLFWwindow* pWindow, double nXOffset, double nYOffset)
            {
                SWindowData& data = *(SWindowData*)glfwGetWindowUserPointer(pWindow);

                data.EventCallback(CMouseScrolledEvent((float)nXOffset, (float)nYOffset));
            });
        /* Mouse Moved Event */
        glfwSetCursorPosCallback(m_pWindow, [](GLFWwindow* pWindow, double nPosX, double nPosY)
            {
                SWindowData& data = *(SWindowData*)glfwGetWindowUserPointer(pWindow);

                data.EventCallback(CMouseMoveEvent((float)nPosX, (float)nPosY));
            });
    }

    void CWindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_pWindow);
        --s_nGLFWWindowCount;

        if (s_nGLFWWindowCount == 0)
        {
            glfwTerminate();
        }
    }

    void CWindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        m_pContext->SwapBuffers();
    }

    float CWindowsWindow::GetWindowTime()
    {
        return glfwGetTime();
    }

    void CWindowsWindow::SetVSync(bool bEnable)
    {
        if (bEnable)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.m_bVSync = bEnable;
    }

    bool CWindowsWindow::IsVSync() const
    {
        return m_Data.m_bVSync;
    }
}