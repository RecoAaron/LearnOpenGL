#include "sdpch.h"
#include "WindowsInput.h"

#include "SandEngine/Core/Application.h"

#include <GLFW/glfw3.h>

namespace SandEngine {

    CInput* CInput::s_pInstance = new CWindowsInput();

    bool CWindowsInput::IsKeyPressedImpl(int keycode)
    {
        auto pWindow = static_cast<GLFWwindow*>(CApplication::GetInstance().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(pWindow, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool CWindowsInput::IsMouseButtonPressedImpl(int button)
    {
        auto pWindow = static_cast<GLFWwindow*>(CApplication::GetInstance().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(pWindow, button);
        return state == GLFW_PRESS;
    }

    float CWindowsInput::GetMouseXImpl()
    {
        auto [x, y] = GetMousePositionImpl();
        return x;
    }

    float CWindowsInput::GetMouseYImpl()
    {
        auto [x, y] = GetMousePositionImpl();
        return y;
    }
    std::pair<float, float> CWindowsInput::GetMousePositionImpl()
    {
        auto pWindow = static_cast<GLFWwindow*>(CApplication::GetInstance().GetWindow().GetNativeWindow());
        double nPosX, nPosY;
        glfwGetCursorPos(pWindow, &nPosX, &nPosY);
        return { (float)nPosX, (float)nPosY };
    }
}