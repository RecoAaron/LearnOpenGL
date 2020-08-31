#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: GUI �㼶��
*************************************************/
#include "SandEngine/Core/Layer.h"

namespace SandEngine {

    class CImGuiLayer : public CLayer
    {
    public:
        CImGuiLayer();
        ~CImGuiLayer();

        /// �㼶����ʱ
        virtual void OnAttach();

        /// �㼶�뿪ʱ
        virtual void OnDetach();

        /// �㼶�¼�����
        virtual void OnEvent(CEvent& event);

        /// ��ʼ ImGui ����
        void Begin();
        /// ���� ImGui ����
        void End();

    private:
        float m_nTime = 0.0f;
    };
}