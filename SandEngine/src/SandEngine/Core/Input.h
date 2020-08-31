#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-29
 * Description: 输入接口定义
*************************************************/
#include "SandEngine/Core/Base.h"

namespace SandEngine {

    class CInput
    {
    public:
        static bool IsKeyPressed(int keycode)
        {
            return s_pInstance->IsKeyPressedImpl(keycode);
        }

        static bool IsMouseButtonPressed(int button)
        {
            return s_pInstance->IsMouseButtonPressedImpl(button);
        }

        static float GetMouseX()
        {
            return s_pInstance->GetMouseXImpl();
        }

        static float GetMouseY()
        {
            return s_pInstance->GetMouseYImpl();
        }

        static std::pair<float, float> GetMousePosition()
        {
            return s_pInstance->GetMousePositionImpl();
        }

    protected:
        virtual bool IsKeyPressedImpl(int keycode) = 0;
        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;

    private:
        static CInput* s_pInstance;
    };
}