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

namespace SE {

    class SE_API CLog
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
#define SE_LOG_TRACE_CORE(...)  ::SE::CLog::GetCoreLogger()->trace(__VA_ARGS__)
/* ���� Logger ��� info ��Ϣ */
#define SE_LOG_INFO_CORE(...)   ::SE::CLog::GetCoreLogger()->info(__VA_ARGS__)
/* ���� Logger ��� warn ��Ϣ */
#define SE_LOG_WARN_CORE(...)   ::SE::CLog::GetCoreLogger()->warn(__VA_ARGS__)
/* ���� Logger ��� error ��Ϣ */
#define SE_LOG_ERROR_CORE(...)  ::SE::CLog::GetCoreLogger()->error(__VA_ARGS__)

/* Ӧ�ó��� Logger ��� trace ��Ϣ */
#define SE_LOG_TRACE(...)       ::SE::CLog::GetApplicationLogger()->trace(__VA_ARGS__)
/* Ӧ�ó��� Logger ��� info ��Ϣ */
#define SE_LOG_INFO(...)        ::SE::CLog::GetApplicationLogger()->info(__VA_ARGS__)
/* Ӧ�ó��� Logger ��� warn ��Ϣ */
#define SE_LOG_WARN(...)        ::SE::CLog::GetApplicationLogger()->warn(__VA_ARGS__)
/* Ӧ�ó��� Logger ��� error ��Ϣ */
#define SE_LOG_ERROR(...)       ::SE::CLog::GetApplicationLogger()->error(__VA_ARGS__)