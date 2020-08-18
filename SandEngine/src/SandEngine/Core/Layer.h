#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: Layer �㼶�����ࡣ
*************************************************/
#include "SandEngine/Core/Base.h"
#include "SandEngine/Events/Event.h"

namespace SandEngine {

    class CLayer
    {
    public:
        CLayer(const std::string& strName = "Layer");
        virtual ~CLayer() = default;

        /// �㼶����ʱ
        virtual void OnAttach() {}

        /// �㼶�뿪ʱ
        virtual void OnDetach() {}

        /// �㼶����ʱ
        virtual void OnUpdate() {}

        /// �㼶�¼�����
        virtual void OnEvent(CEvent& event) {}

        /// ��ȡ�㼶������
        const std::string& GetName() const { return m_strName; }

    protected:
        /* �㼶������ */
        std::string m_strName;
    };
}