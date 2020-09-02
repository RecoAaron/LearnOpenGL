#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-29
 * Description: 输入接口定义
*************************************************/
#include "SandEngine/Core/InputCode.h"

#include <glm/glm.hpp>

namespace SandEngine {

    class CInput
    {
    public:
        /// 按键是否按下
        static bool IsKeyPressed(KeyCode keycode);

        /// 鼠标按键是否按下
        static bool IsMouseButtonPressed(KeyCode button);

        /// 获取鼠标的 X 坐标
        static float GetMouseX();
        /// 获取鼠标的 Y 坐标
        static float GetMouseY();
        /// 获取鼠标的坐标
        static glm::vec2 GetMousePosition();
    };
}