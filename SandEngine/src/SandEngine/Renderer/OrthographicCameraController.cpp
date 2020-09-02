#include "sdpch.h"

#include "OrthographicCameraController.h"

#include "SandEngine/Core/Input.h"
#include "SandEngine/Core/InputCode.h"

namespace SandEngine {

    COrthographicCameraController::COrthographicCameraController(float nAspectRatio, bool bRotation /* = false */)
        : m_nAspectRatio(nAspectRatio), m_Camera(-nAspectRatio * m_nZoomLevel, nAspectRatio* m_nZoomLevel, -m_nZoomLevel, m_nZoomLevel), m_bRotation(bRotation)
    {

    }

    void COrthographicCameraController::OnUpdate(CTimestep& time)
    {
        glm::vec3 vec3CameraPosition = m_Camera.GetPosition();
        float nCameraRotation = m_Camera.GetRotation();

        if (CInput::IsKeyPressed(InputCode::SE_KEY_A))
        {
            vec3CameraPosition.x -= cos(glm::radians(nCameraRotation)) * m_nCameraTranslationSpeed * time;
            vec3CameraPosition.y -= sin(glm::radians(nCameraRotation)) * m_nCameraTranslationSpeed * time;
        }
        else if (CInput::IsKeyPressed(InputCode::SE_KEY_D))
        {
            vec3CameraPosition.x += cos(glm::radians(nCameraRotation)) * m_nCameraTranslationSpeed * time;
            vec3CameraPosition.y += sin(glm::radians(nCameraRotation)) * m_nCameraTranslationSpeed * time;
        }

        if (CInput::IsKeyPressed(InputCode::SE_KEY_W))
        {
            vec3CameraPosition.x += -sin(glm::radians(nCameraRotation)) * m_nCameraTranslationSpeed * time;
            vec3CameraPosition.y += cos(glm::radians(nCameraRotation)) * m_nCameraTranslationSpeed * time;
        }
        else if (CInput::IsKeyPressed(InputCode::SE_KEY_S))
        {
            vec3CameraPosition.x -= -sin(glm::radians(nCameraRotation)) * m_nCameraTranslationSpeed * time;
            vec3CameraPosition.y -= cos(glm::radians(nCameraRotation)) * m_nCameraTranslationSpeed * time;
        }

        if (m_bRotation)
        {
            if (CInput::IsKeyPressed(InputCode::SE_KEY_Q))
                nCameraRotation += m_nCameraRotationSpeed * time;
            if (CInput::IsKeyPressed(InputCode::SE_KEY_E))
                nCameraRotation -= m_nCameraRotationSpeed * time;

            if (nCameraRotation > 180.0f)
                nCameraRotation -= 360.0f;
            else if (nCameraRotation <= -180.0f)
                nCameraRotation += 360.0f;

            m_Camera.SetRotation(nCameraRotation);
        }

        m_Camera.SetPosition(vec3CameraPosition);

        m_nCameraTranslationSpeed = m_nZoomLevel;
    }

    void COrthographicCameraController::OnEvent(CEvent& event)
    {
        CEventDispatcher dispatcher(event);
        dispatcher.Dispatch<CMouseScrolledEvent>(SE_BIND_EVENT_FN(COrthographicCameraController::OnMouseScrolled));
        dispatcher.Dispatch<CWindowResizedEvent>(SE_BIND_EVENT_FN(COrthographicCameraController::OnWindowResized));
    }

    void COrthographicCameraController::OnResize(float nWidth, float nHeight)
    {
        m_nAspectRatio = nWidth / nHeight;
        m_Camera.SetProjection(-m_nAspectRatio * m_nZoomLevel, m_nAspectRatio * m_nZoomLevel, -m_nZoomLevel, m_nZoomLevel);
    }

    bool COrthographicCameraController::OnMouseScrolled(CMouseScrolledEvent& event)
    {
        m_nZoomLevel -= event.GetYOffset() * 0.25f;
        m_nZoomLevel = std::max(m_nZoomLevel, 0.25f);
        m_Camera.SetProjection(-m_nAspectRatio * m_nZoomLevel, m_nAspectRatio * m_nZoomLevel, -m_nZoomLevel, m_nZoomLevel);
        return false;
    }

    bool COrthographicCameraController::OnWindowResized(CWindowResizedEvent& event)
    {
        OnResize((float)event.GetWidth(), (float)event.GetHeight());
        return false;
    }

}