#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: Windows ƽ̨����ӿ�ʵ��
*************************************************/
#include "SandEngine/Core/Input.h"

namespace SandEngine {

    class CWindowsInput : public CInput
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
    };
}