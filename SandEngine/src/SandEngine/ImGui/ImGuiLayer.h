#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: GUI 层级类
*************************************************/
#include "SandEngine/Core/Layer.h"

namespace SandEngine {

    class CImGuiLayer : public CLayer
    {
    public:
        CImGuiLayer();
        ~CImGuiLayer();

        /// 层级附加时
        virtual void OnAttach();

        /// 层级离开时
        virtual void OnDetach();

        /// 层级事件处理
        virtual void OnEvent(CEvent& event);

        /// 开始 ImGui 绘制
        void Begin();
        /// 结束 ImGui 绘制
        void End();

    private:
        float m_nTime = 0.0f;
    };
}