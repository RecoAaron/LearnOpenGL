#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-02
 * Description: 摄像机抽象类
*************************************************/
#include <glm/glm.hpp>

namespace SandEngine {

    class CCamera
    {
    public:
        CCamera() = default;
        CCamera(const glm::mat4& projection)
            : m_mat4Projection(projection) {}

        virtual ~CCamera() = default;

        const glm::mat4& GetProjection() const { return m_mat4Projection; }
    protected:
        glm::mat4 m_mat4Projection = glm::mat4(1.0f);
    };
}