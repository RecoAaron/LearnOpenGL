#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: Layer 层级抽象类。
*************************************************/
#include "SandEngine/Core/Base.h"
#include "SandEngine/Events/Event.h"

namespace SandEngine {

    class CLayer
    {
    public:
        CLayer(const std::string& strName = "Layer");
        virtual ~CLayer() = default;

        /// 层级附加时
        virtual void OnAttach() {}

        /// 层级离开时
        virtual void OnDetach() {}

        /// 层级更新时
        virtual void OnUpdate() {}

        /// 层级事件处理
        virtual void OnEvent(CEvent& event) {}

        /// 获取层级的名字
        const std::string& GetName() const { return m_strName; }

    protected:
        /* 层级的名字 */
        std::string m_strName;
    };
}