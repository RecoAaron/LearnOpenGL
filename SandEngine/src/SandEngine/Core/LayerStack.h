#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: Layer ջ�����ࡣ
*************************************************/
#include "SandEngine/Core/Base.h"
#include "SandEngine/Core/Layer.h"

namespace SandEngine {

    class SE_API CLayerStack
    {
    public:
        CLayerStack();
        ~CLayerStack();

        /// ջ����һ���㼶����
        void PushLayer(CLayer* pLayer);

        /// ջ�Ƴ�һ���㼶����
        void PopLayer(CLayer* pLayer);

        /// ջ����һ������㼶����
        void PushOverlay(CLayer* pOverlay);

        /// ջ�Ƴ�һ������㼶����
        void PopOverlay(CLayer* pOverlay);

        /// ����ջ����ײ�
        std::vector<CLayer*>::iterator begin() { return m_vecLayers.begin(); }
        /// ����ջ�����
        std::vector<CLayer*>::iterator end() { return m_vecLayers.end(); }

    private:
        /* �㼶�洢��ջ */
        std::vector<CLayer*> m_vecLayers;

        /* �㼶�ֽ�㣬ǰ��������ͨ�㼶���󲿷��Ƕ���㼶 */
        uint32_t m_nLayerInsertIndex;
    };
}