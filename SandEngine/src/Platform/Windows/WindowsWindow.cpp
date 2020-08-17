#include "sdpch.h"

#include "WindowsWindow.h"

namespace SE {

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

        m_pWindow = glfwCreateWindow((int)props.m_nWidth, (int)props.m_nHeight, m_Data.m_strTitle.c_str(), nullptr, nullptr);
        ++s_nGLFWWindowCount;

        glfwMakeContextCurrent(m_pWindow);
        glfwSetWindowUserPointer(m_pWindow, &m_Data);
        SetVSync(true);
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
        glfwSwapBuffers(m_pWindow);
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