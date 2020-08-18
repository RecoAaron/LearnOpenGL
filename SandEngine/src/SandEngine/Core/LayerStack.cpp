#include "sdpch.h"

#include "LayerStack.h"

namespace SandEngine {

    CLayerStack::CLayerStack()
        : m_nLayerInsertIndex(0)
    {

    }

    CLayerStack::~CLayerStack()
    {
        for (CLayer* pLayer : m_vecLayers)
        {
            pLayer->OnDetach();
            delete pLayer;
        }
    }

    void CLayerStack::PushLayer(CLayer* pLayer)
    {
        m_vecLayers.emplace(m_vecLayers.begin() + m_nLayerInsertIndex, pLayer);
        ++m_nLayerInsertIndex;
    }

    void CLayerStack::PopLayer(CLayer* pLayer)
    {
        auto it = std::find(m_vecLayers.begin(), m_vecLayers.begin() + m_nLayerInsertIndex, pLayer);
        if (it != m_vecLayers.begin() + m_nLayerInsertIndex)
        {
            pLayer->OnDetach();
            m_vecLayers.erase(it);
            --m_nLayerInsertIndex;
        }
    }

    void CLayerStack::PushOverlay(CLayer* pOverlay)
    {
        m_vecLayers.emplace_back(pOverlay);
    }

    void CLayerStack::PopOverlay(CLayer* pOverlay)
    {
        auto it = std::find(m_vecLayers.begin() + m_nLayerInsertIndex, m_vecLayers.end(), pOverlay);
        if (it != m_vecLayers.end())
        {
            pOverlay->OnDetach();
            m_vecLayers.erase(it);
        }
    }
}