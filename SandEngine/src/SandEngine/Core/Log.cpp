#include "sdpch.h"

#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace SandEngine {

    /* static 成员对象在类外部进行初始化*/
    Ref<spdlog::logger> CLog::s_pLoggerCore;
    Ref<spdlog::logger> CLog::s_pLoggerApplication;

    void CLog::Init()
    {
        std::vector < spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("SandEngine.log", true));

        logSinks[0]->set_pattern("%^[%T] %n: %v%$");
        logSinks[1]->set_pattern("[%T] [%l] %n: %v");

        s_pLoggerCore = std::make_shared<spdlog::logger>("SandEngine", begin(logSinks), end(logSinks));
        spdlog::register_logger(s_pLoggerCore);
        s_pLoggerCore->set_level(spdlog::level::trace);
        s_pLoggerCore->flush_on(spdlog::level::trace);

        s_pLoggerApplication = std::make_shared<spdlog::logger>("Application", begin(logSinks), end(logSinks));
        spdlog::register_logger(s_pLoggerApplication);
        s_pLoggerApplication->set_level(spdlog::level::trace);
        s_pLoggerApplication->flush_on(spdlog::level::trace);
    }
}