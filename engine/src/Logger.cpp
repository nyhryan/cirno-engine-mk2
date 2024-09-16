#include "Cirno/Logger.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include "spdlog/spdlog.h"

namespace Cirno
{

std::shared_ptr<spdlog::logger> Logger::s_InternalLogger;
std::shared_ptr<spdlog::logger> Logger::s_EngineLogger;

void Logger::Init()
{
    spdlog::set_pattern("[%T] %^[%n] [%L]%$: %v");

    s_InternalLogger = spdlog::stdout_color_mt("Internal");
    s_InternalLogger->set_level(spdlog::level::trace);

    s_EngineLogger = spdlog::stdout_color_mt("Engine");
    s_EngineLogger->set_level(spdlog::level::trace);
}

}  // namespace Cirno