#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-02
 * Description: 正交投影摄像机控制类
*************************************************/
#include "SandEngine/Renderer/OrthographicCamera.h"
#include "SandEngine/Core/Timestep.h"
#include "SandEngine/Events/ApplicationEvent.h"
#include "SandEngine/Events/MouseEvent.h"

namespace SandEngine {

    class COrthographicCameraController
    {
    public:
        COrthographicCameraController(float nAspectRatio, bool bRotation = false);

        void OnUpdate(CTimestep& time);

        void OnEvent(CEvent& event);

        void OnResize(float nWidth, float nHeight);

        COrthographicCamera& GetCamera() { return m_Camera; }

        float GetZoomLevel() const { return m_nZoomLevel; }
        void SetZoomLevel(float nLevel) { m_nZoomLevel = nLevel; }

    private:
        bool OnMouseScrolled(CMouseScrolledEvent& event);
        bool OnWindowResized(CWindowResizedEvent& event);

        float m_nAspectRatio;
        float m_nZoomLevel = 1.0f;
        COrthographicCamera m_Camera;

        bool m_bRotation;

        float m_nCameraTranslationSpeed = 5.0f, m_nCameraRotationSpeed = 180.0f;
    };
}