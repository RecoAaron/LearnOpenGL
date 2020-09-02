#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-02
 * Description: 正交投影摄像机类
*************************************************/
#include <glm/glm.hpp>

namespace SandEngine {

    class COrthographicCamera
    {
    public:
        COrthographicCamera(float nLeft, float nRight, float nBottom, float nTop);

        /// 设置正交投影矩阵
        void SetProjection(float nLeft, float nRight, float nBottom, float nTop);

        /// 获取相机位置
        const glm::vec3& GetPosition() const { return m_vec3Position; }
        /// 设置相机位置
        void SetPosition(const glm::vec3& vec3Position) { m_vec3Position = vec3Position; RecalculateViewMatrix(); }

        /// 获取相机旋转
        float GetRotation() const { return m_nRotation; }
        /// 设置相机旋转
        void SetRotation(float nRotation) { m_nRotation = nRotation; RecalculateViewMatrix(); }

        /// 获取投影矩阵
        const glm::mat4& GetProjectionMatrix() const { return m_mat4ProjectionMatrix; }
        /// 获取观察矩阵
        const glm::mat4& GetViewMatrix() const { return m_mat4ViewMatrix; }
        /// 获取投影观察矩阵
        const glm::mat4& GetViewProjectionMatrix() const { return m_mat4ViewProjectionMatrix; }

    private:
        /// 重新计算矩阵
        void RecalculateViewMatrix();

    private:
        /* 相机的投影矩阵 */
        glm::mat4 m_mat4ProjectionMatrix;
        /* 相机的观察矩阵 */
        glm::mat4 m_mat4ViewMatrix;
        /* 相机的投影观察矩阵 */
        glm::mat4 m_mat4ViewProjectionMatrix;

        /* 相机的坐标位置 */
        glm::vec3 m_vec3Position = { 0.0f, 0.0f, 0.0f };
        /* 相机的旋转角度 */
        float m_nRotation = 0.0f;
    };
}