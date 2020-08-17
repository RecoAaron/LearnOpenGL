#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 定义 Log 输出方式，使用 spdlog 库。
*************************************************/
#include "SandEngine/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace SE {

    class SE_API CLog
    {
    public:
        /// 初始化设置 Logger 的输出样式
        static void Init();

        /// 获取核心 Logger 对象
        static Ref<spdlog::logger>& GetCoreLogger() { return s_pLoggerCore; }
        /// 获取应用程序的 Logger 对象
        static Ref<spdlog::logger>& GetApplicationLogger() { return s_pLoggerApplication; }

    private:
        /* 核心 Logger 对象的指针 */
        static Ref<spdlog::logger> s_pLoggerCore;
        /* 应用程序 Logger 对象的指针 */
        static Ref<spdlog::logger> s_pLoggerApplication;
    };
}

/* 核心 Logger 输出 trace 信息 */
#define SE_LOG_TRACE_CORE(...)  ::SE::CLog::GetCoreLogger()->trace(__VA_ARGS__)
/* 核心 Logger 输出 info 信息 */
#define SE_LOG_INFO_CORE(...)   ::SE::CLog::GetCoreLogger()->info(__VA_ARGS__)
/* 核心 Logger 输出 warn 信息 */
#define SE_LOG_WARN_CORE(...)   ::SE::CLog::GetCoreLogger()->warn(__VA_ARGS__)
/* 核心 Logger 输出 error 信息 */
#define SE_LOG_ERROR_CORE(...)  ::SE::CLog::GetCoreLogger()->error(__VA_ARGS__)

/* 应用程序 Logger 输出 trace 信息 */
#define SE_LOG_TRACE(...)       ::SE::CLog::GetApplicationLogger()->trace(__VA_ARGS__)
/* 应用程序 Logger 输出 info 信息 */
#define SE_LOG_INFO(...)        ::SE::CLog::GetApplicationLogger()->info(__VA_ARGS__)
/* 应用程序 Logger 输出 warn 信息 */
#define SE_LOG_WARN(...)        ::SE::CLog::GetApplicationLogger()->warn(__VA_ARGS__)
/* 应用程序 Logger 输出 error 信息 */
#define SE_LOG_ERROR(...)       ::SE::CLog::GetApplicationLogger()->error(__VA_ARGS__)