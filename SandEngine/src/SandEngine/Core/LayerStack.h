#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: Layer 栈管理类。
*************************************************/
#include "SandEngine/Core/Base.h"
#include "SandEngine/Core/Layer.h"

namespace SandEngine {

    class SE_API CLayerStack
    {
    public:
        CLayerStack();
        ~CLayerStack();

        /// 栈推入一个层级对象
        void PushLayer(CLayer* pLayer);

        /// 栈推出一个层级对象
        void PopLayer(CLayer* pLayer);

        /// 栈推入一个顶层层级对象
        void PushOverlay(CLayer* pOverlay);

        /// 栈推出一个顶层层级对象
        void PopOverlay(CLayer* pOverlay);

        /// 返回栈的最底层
        std::vector<CLayer*>::iterator begin() { return m_vecLayers.begin(); }
        /// 返回栈的最顶层
        std::vector<CLayer*>::iterator end() { return m_vecLayers.end(); }

    private:
        /* 层级存储的栈 */
        std::vector<CLayer*> m_vecLayers;

        /* 层级分界点，前部分是普通层级，后部分是顶层层级 */
        uint32_t m_nLayerInsertIndex;
    };
}