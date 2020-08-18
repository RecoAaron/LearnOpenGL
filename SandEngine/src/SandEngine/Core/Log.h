#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: ���� Log �����ʽ��ʹ�� spdlog �⡣
*************************************************/
#include "SandEngine/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace SandEngine {

    class CLog
    {
    public:
        /// ��ʼ������ Logger �������ʽ
        static void Init();

        /// ��ȡ���� Logger ����
        static Ref<spdlog::logger>& GetCoreLogger() { return s_pLoggerCore; }
        /// ��ȡӦ�ó���� Logger ����
        static Ref<spdlog::logger>& GetApplicationLogger() { return s_pLoggerApplication; }

    private:
        /* ���� Logger �����ָ�� */
        static Ref<spdlog::logger> s_pLoggerCore;
        /* Ӧ�ó��� Logger �����ָ�� */
        static Ref<spdlog::logger> s_pLoggerApplication;
    };
}

/* ���� Logger ��� trace ��Ϣ */
#define SE_LOG_TRACE_CORE(...)  ::SandEngine::CLog::GetCoreLogger()->trace(__VA_ARGS__)
/* ���� Logger ��� info ��Ϣ */
#define SE_LOG_INFO_CORE(...)   ::SandEngine::CLog::GetCoreLogger()->info(__VA_ARGS__)
/* ���� Logger ��� warn ��Ϣ */
#define SE_LOG_WARN_CORE(...)   ::SandEngine::CLog::GetCoreLogger()->warn(__VA_ARGS__)
/* ���� Logger ��� error ��Ϣ */
#define SE_LOG_ERROR_CORE(...)  ::SandEngine::CLog::GetCoreLogger()->error(__VA_ARGS__)

/* Ӧ�ó��� Logger ��� trace ��Ϣ */
#define SE_LOG_TRACE(...)       ::SandEngine::CLog::GetApplicationLogger()->trace(__VA_ARGS__)
/* Ӧ�ó��� Logger ��� info ��Ϣ */
#define SE_LOG_INFO(...)        ::SandEngine::CLog::GetApplicationLogger()->info(__VA_ARGS__)
/* Ӧ�ó��� Logger ��� warn ��Ϣ */
#define SE_LOG_WARN(...)        ::SandEngine::CLog::GetApplicationLogger()->warn(__VA_ARGS__)
/* Ӧ�ó��� Logger ��� error ��Ϣ */
#define SE_LOG_ERROR(...)       ::SandEngine::CLog::GetApplicationLogger()->error(__VA_ARGS__)