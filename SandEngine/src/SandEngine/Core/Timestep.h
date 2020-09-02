#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-09-02
 * Description: 时间帧类
*************************************************/

namespace SandEngine {

    class CTimestep
    {
    public:
        CTimestep(float nTime = 0.0f)
            : m_nTime(nTime)
        {

        }

        /// 重写 float() 函数，直接返回秒数
        operator float() const { return m_nTime; }

        /// 获取秒数
        float GetSeconds() const { return m_nTime; }

        /// 获取毫秒数
        float GetMilliseconds() const { return m_nTime * 1000.0f; }

    private:
        /* 时间 */
        float m_nTime;
    };
}