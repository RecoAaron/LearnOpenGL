#include "sdpch.h"

#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace SandEngine {

    COrthographicCamera::COrthographicCamera(float nLeft, float nRight, float nBottom, float nTop)
        : m_mat4ProjectionMatrix(glm::ortho(nLeft, nRight, nBottom, nTop, -1.0f, 1.0f)), m_mat4ViewMatrix(1.0f)
    {
        SE_PROFILE_FUNCTION();

        m_mat4ViewProjectionMatrix = m_mat4ProjectionMatrix * m_mat4ViewMatrix;
    }

    void COrthographicCamera::SetProjection(float nLeft, float nRight, float nBottom, float nTop)
    {
        SE_PROFILE_FUNCTION();

        m_mat4ProjectionMatrix = glm::ortho(nLeft, nRight, nBottom, nTop, -1.0f, 1.0f);
        m_mat4ViewProjectionMatrix = m_mat4ProjectionMatrix * m_mat4ViewMatrix;
    }

    void COrthographicCamera::RecalculateViewMatrix()
    {
        SE_PROFILE_FUNCTION();

        glm::mat4 mat4Transform = glm::translate(glm::mat4(1.0f), m_vec3Position) *
            glm::rotate(glm::mat4(1.0f), glm::radians(m_nRotation), glm::vec3(0, 0, 1));

        m_mat4ViewMatrix = glm::inverse(mat4Transform);
        m_mat4ViewProjectionMatrix = m_mat4ProjectionMatrix * m_mat4ViewMatrix;
    }
}