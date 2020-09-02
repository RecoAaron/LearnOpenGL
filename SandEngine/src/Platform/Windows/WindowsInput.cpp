#include "sdpch.h"

#include "SandEngine/Core/Input.h"
#include "SandEngine/Core/Application.h"

#include <GLFW/glfw3.h>

namespace SandEngine {

    bool CInput::IsKeyPressed(KeyCode keycode)
    {
        auto* pWindow = static_cast<GLFWwindow*>(CApplication::GetInstance().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(pWindow, static_cast<int32_t>(keycode));
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool CInput::IsMouseButtonPressed(KeyCode button)
    {
        auto* pWindow = static_cast<GLFWwindow*>(CApplication::GetInstance().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(pWindow, static_cast<int32_t>(button));
        return state == GLFW_PRESS;
    }

    float CInput::GetMouseX()
    {
        return GetMousePosition().x;
    }

    float CInput::GetMouseY()
    {
        return GetMousePosition().y;
    }

    glm::vec2 CInput::GetMousePosition()
    {
        auto pWindow = static_cast<GLFWwindow*>(CApplication::GetInstance().GetWindow().GetNativeWindow());
        double nPosX, nPosY;
        glfwGetCursorPos(pWindow, &nPosX, &nPosY);
        return { (float)nPosX, (float)nPosY };
    }
}